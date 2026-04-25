/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// --- Custom LED mode
// Custom keycode: TOGGLE_LAYER_LEDS

#include QMK_KEYBOARD_H
#include "rgb_matrix.h"

static bool layer_led_mode = true; // enabled as default

enum custom_keycodes {
    TOGGLE_LAYER_LEDS = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == TOGGLE_LAYER_LEDS && record->event.pressed) {
        layer_led_mode = !layer_led_mode;
    }
    return true;
}

// --- Custom LED mode

// Add layer 4

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    LAYER_4,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FILE LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_92_iso(
          KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,      KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,       KC_F12,    KC_PSCR,    TD(3),     KC_MUTE,
          KC_F13,   TD(1),    KC_1,     KC_2,       KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,      KC_EQL,    KC_BSPC,                KC_INS,
          KC_F14,   KC_TAB,   KC_Q,     KC_W,       KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,      KC_RBRC,                           KC_DEL,
          KC_F15,   KC_RCTL,  KC_A,     KC_S,       KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,      KC_NUHS,    KC_ENT,                 TD(2),
          KC_F16,   KC_LSFT,  KC_NUBS,  KC_Z,       KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                 KC_RSFT,    KC_UP,
          KC_F20,   KC_LCTL,  KC_LWIN,  KC_LALT,    MO(LAYER_4),        TD(0),                         KC_SPC,             KC_RALT,  LT(4,KC_APP),  KC_RCTL,  KC_LEFT,    KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_92_iso(
TOGGLE_LAYER_LEDS,  _______,  _______,  _______,    _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,       _______,  _______,  _______,
    QK_BOOTLOADER,  _______,  _______,  _______,    _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______, QK_BOOTLOADER,            _______,
          _______,  _______,  _______,  _______,    _______,  _______,  _______,   KC_F8,    KC_PGUP,  KC_UP,    KC_PGDN,  KC_BSPC,  _______,    _______,                           _______,
          _______,  _______,  _______,  _______,    _______,  _______,  _______,   _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,   _______,    _______,       _______,            _______,
          _______,  _______,  _______,  _______,    _______,  _______,  _______,   _______,  KC_HOME,  KC_END,   KC_TAB,   _______,  _______,                   _______,  _______,
          _______,  _______,  _______,  _______,    _______,            _______,                       _______,            _______,  _______,    _______,       _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_92_iso(
          KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,      KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,        KC_INS,   KC_DEL,   KC_MUTE,
          _______,  KC_GRV,   KC_1,     KC_2,       KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,        KC_BSPC,            KC_PGUP,
          _______,  KC_TAB,   KC_Q,     KC_W,       KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                           KC_PGDN,
          _______,  KC_CAPS,  KC_A,     KC_S,       KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,       KC_ENT,             KC_HOME,
          _______,  KC_LSFT,  KC_NUBS,  KC_Z,       KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                   KC_RSFT,  KC_UP,
          _______,  KC_LCTL,  KC_LWIN,  KC_LALT,    MO(LAYER_4),        KC_SPC,                        KC_SPC,             KC_RALT,  MO(WIN_FN), KC_RCTL,       KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_92_iso(
TOGGLE_LAYER_LEDS,  _______,  KC_BRID,  KC_BRIU,    KC_TASK,  KC_FILE,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,       _______,  _______,  RGB_TOG,
    QK_BOOTLOADER,  _______,  _______,  _______,    _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______, QK_BOOTLOADER,            _______,
          _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,    RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,                           _______,
          _______,  _______,  RGB_RMOD, RGB_VAD,    RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,    _______,       _______,            _______,
          _______,  _______,  _______,  _______,    _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,                   _______,  _______, 
          _______,  _______,  _______,  _______,    _______,            _______,                       _______,            _______,  _______,    _______,       _______,  _______,  _______),

    [LAYER_4] = LAYOUT_92_iso(
TOGGLE_LAYER_LEDS,  _______,  KC_BRID,  KC_BRIU,    KC_TASK,  KC_FILE,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,       _______,  _______,  KC_SLEP,
    QK_BOOTLOADER,  _______,  _______,  _______,    _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,       _______,            _______,
          _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,    RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  MS_BTN1,  MS_UP,    MS_BTN2,  _______,  _______,    _______,                           _______,
          _______,  KC_CAPS,  RGB_RMOD, RGB_VAD,    RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  MS_LEFT,  MS_DOWN,  MS_RGHT,  MS_BTN3,  _______,    _______,       _______,            _______,
          _______,  _______,  _______,  _______,    _______,  _______,  _______,   _______,  MS_WHLD,  MS_WHLU,  KC_HOME,  KC_F6,    KC_F3,                     _______,  KC_MUTE,
          _______,  _______,  _______,  _______,    _______,            _______,                       _______,            _______,  _______,    _______,       KC_MPLY,  KC_MPRV,  KC_MNXT),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [LAYER_4]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif // ENCODER_MAP_ENABLE



// Active layer indicator LED
// - By default enabled
// - Indicate active layer with white LED-light on key
// -- Layer 1: M2 / F14
// -- Layer 3: M4 / F16
// -- Layer 4: M1 / F13
// - When Caps Lock enabled, white backlight on Caps Lock key
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    static bool prev_layer_led_mode = false;
    
    // Detect transition from layer_led_mode → normal mode
    if (prev_layer_led_mode != layer_led_mode) {
        prev_layer_led_mode = layer_led_mode;
        if (!layer_led_mode) {
            rgb_matrix_reload_from_eeprom(); // flush stale black values from right side
        }
    }
    
    if (!layer_led_mode) return false;
    uint8_t layer = get_highest_layer(layer_state);

    if (layer == 1) {
        rgb_matrix_set_color(15, 255, 255, 255);
        // LED 9, 1!, D10 PCB
        // LED 15, M2 / F14, D16 PCB 
    } else if (layer == 3) {
        rgb_matrix_set_color(29, 255, 255, 255);
        // LED 11, 3#, D12 PCB
        // LED 29, M4 / F16, D30 PCB
    } else if (layer == 4) {
        rgb_matrix_set_color(7, 255, 255, 255);
        // LED 12, 4¤, D13 PCB
        // LED 7, M1 / F13, D8 PCB

    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(23, 255, 255, 255);
    }

    return false;
}

