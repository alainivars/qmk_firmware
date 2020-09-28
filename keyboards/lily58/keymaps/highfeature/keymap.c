/* Copyright 2019 @highfeature
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
#include "highfeature.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  |super | Ctrl | /Space  /       \Enter \  |BackSP| Del  |  ->  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_QWERTY] = LAYOUT_wrapper( \
	_________________NUM_LEFT___________________,               _________________NUM_RIGHT__________________,  \
	_________________QWERTY_L1__________________,               _________________QWERTY_R1__________________,  \
	_________________QWERTY_L2__________________,               _________________QWERTY_R2__________________,  \
	_________________QWERTY_L3__________________, _CENTER_TOP_, _________________QWERTY_R3__________________,  \
                      ________MOD_LEFT_________,_CENTER_BOTTOM_, ________MOD_RIGHT________ \
	),

#if HF_DVORAK_ENABLED
/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  |super | Ctrl | /Space  /       \Enter \  |BackSP| Del  |  ->  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_DVORAK] = LAYOUT_wrapper( \
	_________________NUM_LEFT___________________,               _________________NUM_RIGHT__________________,  \
	_________________DVORAK_L1__________________,               _________________DVORAK_R1__________________,  \
	_________________DVORAK_L2__________________,               _________________DVORAK_R2__________________,  \
	_________________DVORAK_L3__________________, _CENTER_TOP_, _________________DVORAK_R3__________________,  \
                      ________MOD_LEFT_________, _CENTER_BOTTOM_, ________MOD_RIGHT________ \
	),
#endif

#if HF_COLEMAK_ENABLED
/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  |super | Ctrl | /Space  /       \Enter \  |BackSP| Del  |  ->  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
	[_COLEMAK] = LAYOUT_wrapper( \
	_________________NUM_LEFT___________________,               _________________NUM_RIGHT__________________,  \
	_________________COLEMAK_L1_________________,               _________________COLEMAK_R1_________________,  \
	_________________COLEMAK_L2_________________,               _________________COLEMAK_R2_________________,  \
	_________________COLEMAK_L3_________________, _CENTER_TOP_, _________________COLEMAK_R3_________________,  \
                      ________MOD_LEFT_________, _CENTER_BOTTOM_, ________MOD_RIGHT________ \
	),
#endif

/* LOWER
 * ,------------------------------------------.                    ,-------------------------------------------.
 * | F11  |  F1  |  F2  |  F3   |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10  | F12   |
 * |------+------+------+-------+------+------|                    |------+------+------+------+-------+-------|
 * |      |      |      |KC_BRIU| Play | Mute |                    | PgUp | Home |  End |      |       |       |
 * |------+------+------+-------+------+------|                    |------+------+------+------+-------+-------|
 * |K_LOCK|      |      |KC_BRID| Next |VolUp |-------.    ,-------| PgDn | Left | Down |  Up  | Right |       |
 * |------+------+------+-------+------+------|       |    |       |------+------+------+------+-------+-------|
 * |M_SHFT|      |      |       | Prev |VolDn |-------|    |-------|      |      |M_SpDn|M_SpUp|       |       |
 * `------------------------------------------/       /     \      \------------------------------------------'
 *                    |      |      |      | /       /       \      \  |      |M_CODE|M_PYNV|
 *                    |      |      |      |/       /         \      \ |      |      |      |
 *                    `----------------------------'           '------''--------------------'
 */
    [_LOWER] = LAYOUT_wrapper( \
	_________________FUNC_LEFT__________________,                 _________________FUNC_RIGHT_________________, \
	_________________MEDIA_1____________________,                 ___________________NAV_1____________________, \
	_________________MEDIA_2____________________,                 ___________________NAV_2____________________, \
	_________________MEDIA_3____________________,  __T2________,  ___________________NAV_3____________________, \
	                           _________T4______________,  __T2________, M_CODE,  __T1___ \
	),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |K_CSCN|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | WH_U | MS_1 | MS_2 | MS_3 | MS_4 | MS_5 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| WH_D | MS_L | MS_D | MS_U | MS_R |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |M_XXX1|M_XXX2|M_XXX3|M_XXX4|M_XXX5|-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_RAISE] = LAYOUT_wrapper( \
    _________N4______________,   K_CSCN, __N1___,                 ________________N6__________________________, \
    ________________N6__________________________,                 _________________MOUSE_1____________________, \
    ________________N6__________________________,                 _________________MOUSE_2____________________, \
    _________________SECRET_1___________________,  __N2________,  ________________N6__________________________,\
                             _________N4______________,      _________N4______________ \
    ),

/* ADJUST
 * ,------------------------------------------.                    ,-----------------------------------------.
 * |EEP_RST|      |      |      |      |      |                    |      |      |      |COLMAK|DVORAK|QWERTY|
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | M_MAKE|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | M_VRSN|      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | M_FLSH|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `------------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
#if HF_DVORAK_ENABLED
    #if HF_COLEMAK_ENABLED
    [_ADJUST] = LAYOUT_wrapper( \
    EEP_RST, _____________N5___________________,                 _____N3______________, COLEMAK,  DVORAK,  QWERTY, \
    M_MAKE,  _____________N5___________________,                 ________________N6__________________________, \
    M_VRSN,  _____________N5___________________,                 ________________N6__________________________, \
    M_FLSH,  _____________N5___________________,  __N2________,  ________________N6__________________________,\
                            _________N4______________,      _________N4______________ \
  ),
    #else
    [_ADJUST] = LAYOUT_wrapper( \
    EEP_RST, _____________N5___________________,                 _____N3______________, __N1___,  DVORAK,  QWERTY, \
    M_MAKE,  _____________N5___________________,                 ________________N6__________________________, \
    M_VRSN,  _____________N5___________________,                 ________________N6__________________________, \
    M_FLSH,  _____________N5___________________,  __N2________,  ________________N6__________________________,\
                            _________N4______________,      _________N4______________ \
  ),
    #endif
#else
    #if HF_COLEMAK_ENABLED
    [_ADJUST] = LAYOUT_wrapper( \
    EEP_RST, _____________N5___________________,                 _____N3______________, COLEMAK,  __N1___, QWERTY, \
    M_MAKE,  _____________N5___________________,                 ________________N6__________________________, \
    M_VRSN,  _____________N5___________________,                 ________________N6__________________________, \
    M_FLSH,  _____________N5___________________,  __N2________,  ________________N6__________________________,\
                            _________N4______________,      _________N4______________ \
  ),
    #else
    [_ADJUST] = LAYOUT_wrapper( \
    EEP_RST, _____________N5___________________,                 _____N3______________, __N1___,  __N1___, QWERTY, \
    M_MAKE,  _____________N5___________________,                 ________________N6__________________________, \
    M_VRSN,  _____________N5___________________,                 ________________N6__________________________, \
    M_FLSH,  _____________N5___________________,  __N2________,  ________________N6__________________________,\
                            _________N4______________,      _________N4______________ \
  ),
    #endif
#endif

};
