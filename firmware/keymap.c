/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


#define KEYMAP(                                                 \
                                                                \
    l50,l51,l52,l53,l54,l55,l56,            r56,r55,r54,r53,r52,r51,r50,    \
    l40,l41,l42,l43,l44,l45,l46,            r46,r45,r44,r43,r42,r41,r40,    \
    l30,l31,l32,l33,l34,l35,                    r35,r34,r33,r32,r31,r30,    \
    l20,l21,l22,l23,l24,l25,l26,            r26,r25,r24,r23,r22,r21,r20,    \
    l10,l11,l12,l13,l14,                            r14,r13,r12,r11,r10,    \
                            l16,l06,    r06,r16,                            \
                                l04,    r04,                                \
                        l03,l02,l01,    r01,r02,r03                         \
) \
   /* matrix positions */ \
   { \
    {KC_##l50, KC_##l51, KC_##l52, KC_##l53, KC_##l54, KC_##l55, KC_##l56}, \
    {KC_##l40, KC_##l41, KC_##l42, KC_##l43, KC_##l44, KC_##l45, KC_##l46}, \
    {KC_##l30, KC_##l31, KC_##l32, KC_##l33, KC_##l34, KC_##l35, KC_NO}, \
    {KC_##l20, KC_##l21, KC_##l22, KC_##l23, KC_##l24, KC_##l25, KC_##l26}, \
    {KC_##l10, KC_##l11, KC_##l12, KC_##l13, KC_##l14, KC_NO,    KC_##r16}, \
    {KC_NO,    KC_##l01, KC_##l02, KC_##l03, KC_##l04, KC_NO,    KC_##l06}, \
\
    {KC_##r50, KC_##r51, KC_##r52, KC_##r53, KC_##r54, KC_##r55, KC_##r56}, \
    {KC_##r40, KC_##r41, KC_##r42, KC_##r43, KC_##r44, KC_##r45, KC_##r46}, \
    {KC_##r30, KC_##r31, KC_##r32, KC_##r33, KC_##r34, KC_##r35, KC_NO}, \
    {KC_##r20, KC_##r21, KC_##r22, KC_##r23, KC_##r24, KC_##r25, KC_##r26}, \
    {KC_##r10, KC_##r11, KC_##r12, KC_##r13, KC_##r14, KC_NO,    KC_##r16}, \
    {KC_NO,    KC_##r01, KC_##r02, KC_##r03, KC_##r04, KC_NO,    KC_##r06} \
   }

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* layer 0 : default */
   KEYMAP(
    /* ,--------------------------------------------------.           ,--------------------------------------------------. */
    /* |        |  1 ! |  2 @ |  3 # |  4 $ |  5 % |      |           |      |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |        | */
          ESC   ,   1  ,   2  ,   3  ,   4  ,   5  ,   NO ,              NO  ,   6  ,   7  ,   8  ,   9  ,   0  ,    NO  ,
    /* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------| */
    /* |        |  q Q |  w W |  e E |  r R |  t T |      |           |      |  y Y |  u U |  i I |  o O |  p P |        | */
          TAB   ,   Q  ,   W  ,   E  ,   R  ,   T  ,  FN0 ,              FN0 ,   Y  ,   U  ,   I  ,   O  ,   P  ,   BSLS ,
    /* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------| */
    /* |        |  a A |  s S |  d D |  f F |  g G |------|           |------|  h H |  j J |  k K |  l L |  ; : |   ' "  | */
         LCTL   ,   A  ,   S  ,   D  ,   F  ,   G  ,                             H  ,   J  ,   K  ,   L  , SCLN ,   QUOT ,
    /* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------| */
    /* |        | z Z  |  x X |  c C |  v V |  b B |      |           |      |  n N |  m M |  , < |  . > |  / ? |        | */
          LSFT  ,   Z  ,   X  ,   C  ,   V  ,   B  , LGUI ,             RGUI ,   N  ,   M  , COMM , DOT  , SLSH ,  RSFT  ,
    /* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------' */
    /*   |      |      |      |      |      |                                       |  - _ |  = + |  [ { |  ] } | PASTE|   */
           GRV  , LALT ,  NO  ,  NO  , FN1  ,                                         MINS ,  EQL , LBRC , RBRC , FN2  ,
    /*   `----------------------------------'                                       `----------------------------------'   */
    /*                                        ,-------------.       ,-------------.                                        */
    /*                                        |      |      |       |      |      |                                        */
                                                DEL  , INS  ,          NO  ,  NO  ,
    /*                                 ,------|------|------|       |------+------+------.                                 */
    /*                                 |      |      |      |       |      |      |      |                                 */
                                                        END ,         PGUP ,
    /*                                 |      |      |------|       |------|      |      |                                 */
    /*                                 |      |      |      |       |      |      |      |                                 */
                                         SPC  , BSPC , HOME ,         PGDN , TAB  , ENT
    /*                                 `--------------------'       `--------------------'                                 */
   ),

   /* layer 1 : function and symbol keys */
   KEYMAP(
    /* ,--------------------------------------------------.           ,--------------------------------------------------. */
    /* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        | */
          TRNS  ,  F1  ,  F2  ,  F3  ,  F4  ,  F5  ,  F6  ,              F7  ,  F8  ,  F9  ,  F8  ,  F10 ,  F11 ,  F12   ,
    /* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------| */
    /* |        |      |      |  [   |  ]   |      |      |           |      |      |      |      |      |      |        | */
          TRNS  , TRNS , TRNS , LBRC , RBRC , TRNS , TRNS ,             TRNS , TRNS ,  P7  ,  P8  ,  P9  , PAST ,   TRNS ,
    /* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------| */
    /* |        |      |      |  (   |  )   |      |------|           |------|      |      |      |      |      |        | */
          TRNS  , TRNS , TRNS ,  FN8 ,  FN9 , TRNS ,                           TRNS ,  P4  ,  P5  ,  P6  , PPLS ,   TRNS ,
    /* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------| */
    /* |        |      |      |  {   |  }   |      |      |           |      |      |      |      |      |      |        | */
          TRNS  , TRNS , TRNS , FN10 , FN11 , TRNS , TRNS ,             TRNS , TRNS ,  P1  ,  P2  ,  P3  , PSLS ,   TRNS ,
    /* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------' */
    /*   |      |      |      |  <   |  >   |                                       |      |      |      |      |      |   */
          TRNS  , TRNS , TRNS , FN12 , FN13 ,                                         TRNS , PDOT ,  P0  , TRNS ,   TRNS ,
    /*   `----------------------------------'                                       `----------------------------------'   */
    /*                                        ,-------------.       ,-------------.                                        */
    /*                                        |      |      |       |      |      |                                        */
                                                TRNS , TRNS ,         TRNS , TRNS ,
    /*                                 ,------|------|------|       |------+------+------.                                 */
    /*                                 |      |      |      |       |      |      |      |                                 */
                                                       TRNS ,         TRNS ,
    /*                                 |      |      |------|       |------|      |      |                                 */
    /*                                 |      |      |      |       |      |      |      |                                 */
                                         TRNS , TRNS , TRNS ,         TRNS , TRNS , TRNS
    /*                                 `--------------------'       `--------------------'                                 */
    /**/
   ),

   /* layer 3 : arrows */
   KEYMAP(
    /* ,--------------------------------------------------.           ,--------------------------------------------------. */
    /* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        | */
          TRNS  , TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,             TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------| */
    /* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        | */
          TRNS  , TRNS ,  UP  , TRNS , TRNS , TRNS , TRNS ,             TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------| */
    /* |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        | */
          TRNS  , LEFT , DOWN , RGHT , TRNS , TRNS ,                           TRNS , TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------| */
    /* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        | */
          TRNS  , TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,             TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------' */
    /*   |      |      |      |      |      |                                       |      |      |      |      |      |   */
          TRNS  , TRNS , TRNS , TRNS , TRNS ,                                         TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /*   `----------------------------------'                                       `----------------------------------'   */
    /*                                        ,-------------.       ,-------------.                                        */
    /*                                        |      |      |       |      |      |                                        */
                                                TRNS , TRNS ,         TRNS , TRNS ,
    /*                                 ,------|------|------|       |------+------+------.                                 */
    /*                                 |      |      |      |       |      |      |      |                                 */
                                                       TRNS ,         TRNS ,
    /*                                 |      |      |------|       |------|      |      |                                 */
    /*                                 |      |      |      |       |      |      |      |                                 */
                                         TRNS , TRNS , TRNS ,         TRNS , TRNS , TRNS
    /*                                 `--------------------'       `--------------------'                                 */
   ),
#if 0
   KEYMAP(
    /* ,--------------------------------------------------.           ,--------------------------------------------------. */
    /* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        | */
          TRNS  , TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,             TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------| */
    /* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        | */
          TRNS  , TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,             TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------| */
    /* |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        | */
          TRNS  , TRNS , TRNS , TRNS , TRNS , TRNS ,                           TRNS , TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------| */
    /* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        | */
          TRNS  , TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,             TRNS , TRNS , TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------' */
    /*   |      |      |      |      |      |                                       |      |      |      |      |      |   */
          TRNS  , TRNS , TRNS , TRNS , TRNS ,                                         TRNS , TRNS , TRNS , TRNS ,   TRNS ,
    /*   `----------------------------------'                                       `----------------------------------'   */
    /*                                        ,-------------.       ,-------------.                                        */
    /*                                        |      |      |       |      |      |                                        */
                                                TRNS , TRNS ,         TRNS , TRNS ,
    /*                                 ,------|------|------|       |------+------+------.                                 */
    /*                                 |      |      |      |       |      |      |      |                                 */
                                                       TRNS ,         TRNS ,
    /*                                 |      |      |------|       |------|      |      |                                 */
    /*                                 |      |      |      |       |      |      |      |                                 */
                                         TRNS , TRNS , TRNS ,         TRNS , TRNS , TRNS
    /*                                 `--------------------'       `--------------------'                                 */
   ),
#endif
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
   [0] = ACTION_LAYER_MOMENTARY(1),  // FN0 - switch to Layer1
   [1] = ACTION_LAYER_MOMENTARY(2),  // FN1 - switch to Layer2
   [2] = ACTION_MODS_KEY(MOD_LSFT, KC_INSERT),

   [8]  = ACTION_MODS_KEY(MOD_LSFT, KC_9),
   [9]  = ACTION_MODS_KEY(MOD_LSFT, KC_0),
   [10] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
   [11] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
   [12] = ACTION_MODS_KEY(MOD_LSFT, KC_COMMA),
   [13] = ACTION_MODS_KEY(MOD_LSFT, KC_DOT),
};



#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    if (layer < KEYMAPS_SIZE) {
        return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
    } else {
        // fall back to layer 0
        return pgm_read_byte(&keymaps[0][(key.row)][(key.col)]);
    }
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    action_t action;
    if (FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    } else {
        action.code = ACTION_NO;
    }
    return action;
}
