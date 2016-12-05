#----------------------------------------------------------------------------
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make coff = Convert ELF to AVR COFF.
#
# make extcoff = Convert ELF to AVR Extended COFF.
#
# make program = Download the hex file to the device.
#                Please customize your programmer settings(PROGRAM_CMD)
#
# make teensy = Download the hex file to the device, using teensy_loader_cli.
#               (must have teensy_loader_cli installed).
#
# make dfu = Download the hex file to the device, using dfu-programmer (must
#            have dfu-programmer installed).
#
# make flip = Download the hex file to the device, using Atmel FLIP (must
#             have Atmel FLIP installed).
#
# make dfu-ee = Download the eeprom file to the device, using dfu-programmer
#               (must have dfu-programmer installed).
#
# make flip-ee = Download the eeprom file to the device, using Atmel FLIP
#                (must have Atmel FLIP installed).
#
# make debug = Start either simulavr or avarice as specified for debugging, 
#              with avr-gdb or avr-insight as the front end for debugging.
#
# make filename.s = Just compile filename.c into the assembler code only.
#
# make filename.i = Create a preprocessed source file for use in submitting
#                   bug reports to the GCC project.
#
# To rebuild project do "make clean" then "make all".
#----------------------------------------------------------------------------

# Target file name (without extension).
TARGET = normkey

# Directory common source filess exist
TMK_DIR = ./tmk_core

# Directory keyboard dependent files exist
TARGET_DIR = .

# project specific files
SRC =	keymap.c \
	matrix.c \
	led.c

CONFIG_H = config.h


# MCU name
MCU = atmega32u4


# Processor frequency.
#     This will define a symbol, F_CPU, in all source code files equal to the
#     processor frequency in Hz. You can then use this symbol in your source code to
#     calculate timings. Do NOT tack on a 'UL' at the end, this will be done
#     automatically to create a 32-bit value in your source code.
#
#     This will be an integer division of F_USB below, as it is sourced by
#     F_USB after it has run through any CPU prescalers. Note that this value
#     does not *change* the processor frequency - it should merely be updated to
#     reflect the processor speed set externally so that the code can use accurate
#     software delays.
F_CPU = 16000000


# Build Options
#   comment out to disable the options.
#
#MOUSEKEY_ENABLE = no	# Mouse keys
#PS2_MOUSE_ENABLE = yes	# PS/2 mouse(TrackPoint) support
#EXTRAKEY_ENABLE = yes	# Audio control and System control
#NKRO_ENABLE = yes	# USB Nkey Rollover



#---------------- Programming Options --------------------------
PROGRAM_CMD = teensy_loader_cli -mmcu=$(MCU) -w -v $(TARGET).hex



# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)

include $(TMK_DIR)/protocol/pjrc.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk
