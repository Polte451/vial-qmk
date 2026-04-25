VIA_ENABLE = yes
VIAL_ENABLE = yes
VIALRGB_ENABLE = yes
ENCODER_MAP_ENABLE = yes

VPATH += keyboards/keychron/common
SRC += keychron_common.c backlit_indicator.c

# Enable layer 4
OPT_DEFS += -DDYNAMIC_KEYMAP_LAYER_COUNT=5

RGB_MATRIX_ENABLE = yes
