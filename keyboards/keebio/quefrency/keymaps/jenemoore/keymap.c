#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layer {
    _BASE,
    META,
    PLUS,
    MOD
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
	UPDIR,
	GOHOME,
	RTARW,
	LTARW
};

// define macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
		switch (keycode) {
				case UPDIR:
						if (record->event.pressed) {
								// when key UPDIR is pressed
								SEND_STRING("../"SS_TAP(X_ENT));
						} else {
								// when keycode is released
						}
						break;

				case GOHOME: 
						if (record->event.pressed) {
								SEND_STRING("cd ~"SS_TAP(X_ENT));
						} else {
						}
						break;

				case RTARW:
						if (record->event.pressed) {
								SEND_STRING("->");
						} else {
						}
						break;

				case LTARW:
						if (record->event.pressed) {
								SEND_STRING("<-");
						} else {
						}
						break;
		}	
		return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65(
    KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX,  KC_BSPC, KC_MUTE,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_END,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,  QK_REP,
    CW_TOGG, KC_LGUI, OSL(PLUS), KC_LALT, LT(META,KC_SPC),           XXXXXXX, KC_SPC,  KC_RALT, MO(META), XXXXXXX, KC_LEFT, LT(MOD,KC_DOWN), KC_RGHT
  ),

  [META] = LAYOUT_65(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,  KC_DEL, _______,
    _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, GOHOME, KC_PGDN,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, UPDIR, QK_AREP,
    KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [PLUS] = LAYOUT_65(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_LCBR,   KC_RCBR,  KC_F11,  KC_F12,  XXXXXXX,  KC_DEL, _______,
    _______, _______, _______, _______,   _______, _______, _______, KC_AMPR, _______, _______, KC_PERCENT, _______, _______, _______, KC_PGUP,
    _______, _______, KC_DLR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN,
    _______, _______, _______, _______, _______, _______, KC_HASH, _______, _______, _______, _______, _______, _______, QK_AREP,
    KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______, _______, LTARW, _______, RTARW
  ),

  [MOD] = LAYOUT_65(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,  _______, _______,
    RGB_TOG, RGB_MOD, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOTLOADER,
    _______, _______, RGB_SAI, _______, _______, _______, RGB_HUI, _______, _______, _______, _______, _______, _______, QK_DEBUG_TOGGLE,
    _______, _______, _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, QK_REBOOT
  )

};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[] [NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
  [META] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
  [PLUS] = { ENCODER_CCW_CW(KC_WWW_BACK, KC_WWW_FORWARD) },
  [MOD] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) }
};
#endif


//bool encoder_update_user(uint8_t index, bool clockwise) {
//    if (index == 1) {
//        if (clockwise) {
//            tap_code(KC_PGDN);
//        } else {
//            tap_code(KC_PGUP);
//        }
//    }
//    else if (index == 0) {
//        if (clockwise) {
//            tap_code(KC_VOLU);
//        } else {
//            tap_code(KC_VOLD);
//        }
//    }
//    return false;
//}
