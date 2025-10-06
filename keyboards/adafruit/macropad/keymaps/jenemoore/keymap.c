/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
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


/* Layers:
 * 0 - numpad
 * 1 - cli
 * 2 - assign case
 * 3 - close case
 * 4 - documentation
 * 5 - 
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
                    TO(0),
      KC_0,   KC_DOT, KC_ENT,
      KC_7,   KC_8, KC_9,
      KC_4,   KC_5, KC_6,
      KC_1,   KC_2, KC_3
  ),
  [1] = LAYOUT(
                        _______,
      CK_TOGG, AU_TOGG, _______,
      _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
  ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [1] = { ENCODER_CCW_CW(_______, _______) },
};
#endif


#ifdef OLED_ENABLE
bool oled_task_user(void) {
		// change display based on layer
		oled_write_P(PSTR("Layer: "), false;

		switch (get_highest_layer(layer_state)) {
				case 0:
						oled_write_P(PSTR("Numpad\n"), false);
						break;
				case 1: 
						oled_write_P(PSTR("CLI\n"), false);
						break;
				case 2: 
						oled_write_P(PSTR("Assign case\n"), false);
						break;
				case 3: 
						oled_write_P(PSTR("Close case\n"), false);
						break;
				case 4:
						oled_write_P(PSTR("Documentation\n"), false);
						break;
				default:
						oled_write_P(PSTR("Undefined\n"), false);
		}
#endif
