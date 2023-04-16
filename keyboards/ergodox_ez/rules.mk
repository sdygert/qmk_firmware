# If you have Left LEDs (see
# https://geekhack.org/index.php?topic=22780.msg873819#msg873819 for
# details), include the following define:
# OPT_DEFS += -DLEFT_LEDS

ORYX_ENABLE = yes

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no   # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = yes  # Mouse keys
EXTRAKEY_ENABLE  = yes  # Audio control and System control
CONSOLE_ENABLE   = no   # Console for debug
COMMAND_ENABLE   = no   # Commands for debug and configuration
CUSTOM_MATRIX    = lite # Custom matrix file for the ErgoDox EZ
NKRO_ENABLE      = yes  # Enable N-Key Rollover
UNICODE_ENABLE   = no   # Unicode
SWAP_HANDS_ENABLE= no   # Allow swapping hands of keyboard

KEY_LOCK_ENABLE = yes   # Enable Key Lock
CAPS_WORD_ENABLE= yes	# Enable Caps Word https://docs.qmk.fm/#/feature_caps_word
TAP_DANCE_ENABLE= yes	# Enable tap dance https://docs.qmk.fm/#/feature_tap_dance
TRI_LAYER_ENABLE= yes   # Enable tri layer https://docs.qmk.fm/#/feature_tri_layer

RGB_MATRIX_ENABLE = no # Enable Glow
RGB_MATRIX_DRIVER = IS31FL3731
DEBOUNCE_TYPE = sym_eager_pr

# project specific files
SRC += matrix.c \
	   led_i2c.c
QUANTUM_LIB_SRC += i2c_master.c

# Disable unsupported hardware
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no

MOUSE_SHARED_EP = no

DEFAULT_FOLDER = ergodox_ez/base
