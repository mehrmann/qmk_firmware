/* Copyright 2019 codybender
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_ortho_5x4(
		KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC,
    	KC_P7,   KC_P8,   KC_P9,   KC_PMNS,          
    	KC_P4,   KC_P5,   KC_P6,   KC_PPLS, 
    	KC_P1,   KC_P2,   KC_P3,   KC_NO,  
    	KC_NO,   KC_P0,   KC_PDOT, KC_PENT  
	),
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        DDRD |= (1 << 5);
        PORTD &= ~(1 << 5);
    } else {
        DDRD |= (1 << 5);
        PORTD |= (1 << 5);
    }
    DDRB |= (1 << 0);
    PORTB |= (1 << 0);
}
