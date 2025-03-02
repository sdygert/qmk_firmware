# If you have Left LEDs (see
# https://geekhack.org/index.php?topic=22780.msg873819#msg873819 for
# details), include the following define:
# OPT_DEFS += -DLEFT_LEDS

ORYX_ENABLE = yes

CONSOLE_ENABLE   = no   # Console for debug
COMMAND_ENABLE   = no   # Commands for debug and configuration
CUSTOM_MATRIX    = lite # Custom matrix file for the ErgoDox EZ
UNICODE_ENABLE   = no   # Unicode
SWAP_HANDS_ENABLE= no   # Allow swapping hands of keyboard

KEY_LOCK_ENABLE = yes   # Enable Key Lock
CAPS_WORD_ENABLE= no	# Enable Caps Word https://docs.qmk.fm/#/feature_caps_word

RGB_MATRIX_ENABLE = no # Enable Glow
# RGB_MATRIX_DRIVER = IS31FL3731
# DEBOUNCE_TYPE = sym_eager_pr

# project specific files
SRC += matrix.c
I2C_DRIVER_REQUIRED = yes

# Disable unsupported hardware
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no

MOUSE_SHARED_EP = no

# https://docs.qmk.fm/#/feature_dynamic_macros
DYNAMIC_MACRO_ENABLE = yes
