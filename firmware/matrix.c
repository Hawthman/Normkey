/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <i2cmaster.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

static matrix_row_t read_cols(uint8_t device);
static void select_row(uint8_t device, uint8_t row);


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

#define IODIRA 0x00
#define IODIRB 0x01
#define GPPUA 0x0C
#define GPPUB 0x0D
#define GPIOA  0x12
#define GPIOB  0x13

#define DEVICE1 0x40
#define DEVICE2 0x42

#define TWI_FREQ 400000

static void configure_device(uint8_t device) {
  i2c_start_wait(device | I2C_WRITE);
  i2c_write(IODIRA);
  i2c_write(0x00);
  i2c_stop();

  i2c_start_wait(device | I2C_WRITE);
  i2c_write(GPPUB);
  i2c_write(0xff);
  i2c_stop();
}

void matrix_init(void)
{
    debug_enable = true;
    debug_matrix = true;
    debug_mouse = true;

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }

    // i2c setup
    i2c_init();
    TWBR = ((F_CPU / TWI_FREQ) - 16) / 2;

    configure_device(DEVICE1);
    configure_device(DEVICE2);
}

bool was_changed = false;

uint8_t matrix_scan(void)
{
    was_changed = false;
    const int rows_per_side = MATRIX_ROWS / 2;
    for (uint8_t i = 0; i < rows_per_side; i++) {
        select_row(DEVICE1, i);
        select_row(DEVICE2, i);

        matrix_row_t c1 = read_cols(DEVICE1);
        matrix_row_t c2 = read_cols(DEVICE2);

        was_changed = was_changed || (matrix[0*rows_per_side + i] != c1) || (matrix[1*rows_per_side + i] != c2);
        matrix[0*rows_per_side + i] = c1;
        matrix[1*rows_per_side + i] = c2;
    }

    return 1;
}

bool matrix_is_modified(void)
{
    /* FIXME */
    return was_changed;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

static matrix_row_t read_cols(uint8_t device)
{
    i2c_start_wait(device | I2C_WRITE);
    i2c_write(GPIOB);
    i2c_rep_start(device | I2C_READ);
    uint8_t ret = i2c_readNak();
    i2c_stop();

    return ~ret;
}

static void select_row(uint8_t device, uint8_t row)
{
    i2c_start_wait(device | I2C_WRITE);
    i2c_write(GPIOA);
    i2c_write((uint8_t)~(1 << row));
    i2c_stop();
}
