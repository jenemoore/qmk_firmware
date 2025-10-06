// Copyright 2022 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layer {
    _BASE,
    META,
    PLUS,
    MOD
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_MPLY,   KC_CALC,      KC_GRV,        KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_6,          KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,     XXXXXXX,    KC_BSPC,       KC_HOME,
    KC_F3,   KC_F4,      KC_TAB,        KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,          KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,                   KC_PGUP,
    KC_F5,   CW_TOGG,    LCTL_T(KC_ESC),KC_A,    KC_S,     KC_D,     KC_F,     KC_G,                    KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,    KC_QUOT,    KC_ENT,                    KC_PGDN,
    KC_F7,   KC_F8,      KC_LSFT,       KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,                    KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,    KC_UP,                     MO(META),
    KC_F9,   KC_F10,     KC_LGUI,     MO(META),MO(MOD),  KC_LALT,  KC_SPC,                            XXXXXXX, KC_SPC,   MO(PLUS),KC_MEH, XXXXXXX,    KC_LEFT,    KC_DOWN,                   KC_RGHT
  ),
  [META] = LAYOUT_65_with_macro(
    _______, _______,          _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,             KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, KC_DEL,        _______,
    LALT(KC_1), LALT(KC_2),    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,   KC_HOME,
    LALT(KC_3), LALT(KC_4),    _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,     KC_END,
    LALT(KC_5), LALT(KC_6),    _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,     LALT(KC_9),
    LALT(KC_7), LALT(KC_8),    KC_TRNS, KC_TRNS, KC_TRNS, _______, _______,       XXXXXXX, _______,  KC_TRNS, KC_TRNS, XXXXXXX, _______, _______,                  LALT(KC_0)
  ),
  [PLUS] = LAYOUT_65_with_macro(
    _______, _______,        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, XXXXXXX, _______,   _______,
    LSA(KC_1), LSA(KC_2),    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,            _______,
    LSA(KC_3), LSA(KC_4),    _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,              _______,
    LSA(KC_5), LSA(KC_6),    _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,              LSA(KC_9),
    LSA(KC_7), LSA(KC_8),    KC_TRNS, KC_TRNS, KC_TRNS, _______, _______,             XXXXXXX, _______, KC_TRNS, KC_TRNS, XXXXXXX, _______, _______,                      LSA(KC_0)
  ),
  [MOD] = LAYOUT_65_with_macro(
    RGB_TOG, _______,    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, XXXXXXX, _______,   VK_TOGG,
    _______, _______,    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,            _______,
    _______, _______,    _______, _______, RGB_SAI, RGB_SAD, _______, _______,            RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______,              _______,
    _______, _______,    _______, _______, _______, _______, RGB_VAI, RGB_VAD,            _______, _______, _______, _______, _______, _______, _______,              _______,
    _______, _______,    KC_TRNS, KC_TRNS, KC_TRNS, _______, _______,             XXXXXXX, _______, KC_TRNS, KC_TRNS, XXXXXXX, _______, _______,                      _______
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[] [NUM_ENCODERS] [2] = {
          // first encoder                  // second encoder
  [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
  [META] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
  [PLUS] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_WWW_BACK, KC_WWW_FORWARD) },
  [MOD] = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_SPD, RGB_SPI) }
};
#endif

//bool encoder_update_user(uint8_t index, bool clockwise) {
//    if (index == 0) {
//        if (clockwise) {
//            tap_code(KC_PGDN);
//        } else {
//            tap_code(KC_PGUP);
//        }
//    }
//    else if (index == 1) {
//        if (clockwise) {
//            tap_code(KC_VOLU);
//        } else {
//            tap_code(KC_VOLD);
//        }
//    }
//    return false;
//}
