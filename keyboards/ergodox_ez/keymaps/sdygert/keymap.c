// Copyright 2025 Seth Dygert sdygert@gmail.com

#include QMK_KEYBOARD_H
#include "version.h"

static void tap_code_with_leds(uint16_t keycode);

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    GAME,  // games
    BLNK,  // blank template
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    k
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    | 1/F1 | 2/F2 | 3/F3 | 4/F4 | 5/F5 |DMREC1|           |      | 6/F6 | 7/F7 | 8/F8 | 9/F9 | 0/F10| -/F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |DMPLY1|           |  L1  |   Y  |   U  |   I  |   O  |   P  | \/F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|      |           |  L2  |------+------+------+------+------+--------|
 * | LShft  |Z/Ctrl|X/Alt |C/Shft|V/Meh |   B  |      |           |      |   N  |M/Meh |,/Shft|./Alt |//Ctrl| RShft  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   =  |  [   |  ]   | Left | Right|                                       |  Up  | Down |      | Caps | PntScr |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Alt  | LGui |       | Alt  |  Esc   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|      |------|       |------|  Tab   |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_GRV,   LT(0,KC_1),     LT(0,KC_2),     LT(0,KC_3),     LT(0,KC_4),     LT(0,KC_5),     DM_REC1,              KC_NO,    LT(0,KC_6),     LT(0,KC_7),     LT(0,KC_8),     LT(0,KC_9),        LT(0,KC_0),        LT(0,KC_MINS),
  KC_DEL,   KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           DM_PLY1,              TG(1),    KC_Y,           KC_U,           KC_I,           KC_O,              KC_P,              LT(0,KC_BSLS),
  KC_BSPC,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,              LT(2,KC_SCLN),     GUI_T(KC_QUOT),
  KC_LSFT,  CTL_T(KC_Z),    ALT_T(KC_X),    SFT_T(KC_C),    MEH_T(KC_V),    KC_B,           KC_NO,                TG(2),    KC_N,           MEH_T(KC_M),    SFT_T(KC_COMM), ALT_T(KC_DOT),     CTL_T(KC_SLSH),    KC_RSFT,
  KC_EQL,   KC_LBRC,        KC_RBRC,        KC_LEFT,        KC_RGHT,                                                        KC_UP,          KC_DOWN,        KC_NO,          KC_CAPS,           KC_PSCR,
                                                                            KC_LALT,        KC_LGUI,              KC_LALT,  KC_ESC,
                                                                                            KC_HOME,              KC_PGUP,
                                                            KC_SPC,         KC_NO,          KC_END,               KC_PGDN,  KC_TAB,         KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |  Up  |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |   =  |      |      |      |                                       |   0  |    . |   -  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,               KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_0,    KC_DOT,  KC_MINS, KC_EQL,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      | Mclk |      |      |      |           |      | Copy | Paste| BkSp |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |      |      |           |      | Play | MsSp0| MsSp1| MsSp2|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| MsWlL| MsWlD| MsWhU| MsWhR|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Ctrl | Alt  |Shift | Meh  |      |      |           |      | Del  | Meh  |Shift | Alt  | Ctrl |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       | Mute |VolDn |VolUp |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------| Lclk | Rclk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, LCTL(KC_C), LCTL(KC_V),   KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,     KC_TRNS, KC_MPLY,    KC_ACL0,      KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                       KC_WH_L,    KC_WH_D,      KC_WH_U, KC_WH_R, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_LCTL, KC_LALT, KC_LSFT, KC_MEH,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_DEL,     KC_MEH,       KC_RSFT, KC_RALT, KC_RCTL, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                            KC_MUTE,      KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_BTN1, KC_BTN2, KC_TRNS,     KC_TRNS, KC_BTN1,    KC_BTN2
),
/* Keymap 3: Games Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[GAME] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_M,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Blank Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BLNK] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
};

// clang-format on

void tap_code_with_leds(uint16_t keycode)
{
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    tap_code(keycode);
    wait_ms(50);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case LT(0,KC_1):
                // https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md#intercepting-mod-taps=
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F1);
                    return false;
                }
                return true;
            case LT(0,KC_2):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F2);
                    return false;
                }
                return true;
            case LT(0,KC_3):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F3);
                    return false;
                }
                return true;
            case LT(0,KC_4):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F4);
                    return false;
                }
                return true;
            case LT(0,KC_5):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F5);
                    return false;
                }
                return true;
            case LT(0,KC_6):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F6);
                    return false;
                }
                return true;
            case LT(0,KC_7):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F7);
                    return false;
                }
                return true;
            case LT(0,KC_8):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F8);
                    return false;
                }
                return true;
            case LT(0,KC_9):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F9);
                    return false;
                }
                return true;
            case LT(0,KC_0):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F10);
                    return false;
                }
                return true;
            case LT(0,KC_MINS):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F11);
                    return false;
                }
                return true;
            case LT(0,KC_BSLS):
                if (!record->tap.count && record->event.pressed) {
                    tap_code_with_leds(KC_F12);
                    return false;
                }
                return true;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};
