/* Copyright 2019 @highfeature
 * inspired by ninjonas
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
#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "process_records.h"
#ifdef TAP_DANCE_ENABLE
    #include "tap_dances.h"
#else
    #define T_ESC  KC_ESCAPE
    #define T_LBRC KC_LBRACKET
    #define T_RBRC KC_RBRACKET
    #define T_TAB  KC_TAB
    #define T_GRV  KC_GRAVE
    #define T_GUI  KC_LGUI
    #define T_W    KC_W
    #define T_Q    KC_Q
#endif
#if defined(KEYBOARD_lily58_rev1) & defined(PROTOCOL_LUFA)
    #include "lufa.h"
    #include "split_util.h"
#endif
#ifdef SSD1306OLED
    #include "ssd1306.h"
#endif

//
// Enable/disable part
//
// for secret sending
#define MACRO_TIMER 3
//// For Layer
#define HF_COLEMAK_ENABLED      1
#define HF_DVORAK_ENABLED       0
//// For OS type (ie for shorkeys)
#define OS_MAC_ENABLED          0
#define OS_POPOS_20_04_ENABLED  1

// Define layers
enum layers {
    _QWERTY = 0,
#if HF_DVORAK_ENABLED
    _DVORAK,
#endif
#if HF_COLEMAK_ENABLED
    _COLEMAK,
#endif
    _LOWER,
    _RAISE,
    _ADJUST
};

// Shortcut Keys
#if OS_MAC_ENABLED
    #define K_LOCK LGUI(LCTL(KC_Q)) // Locks screen
    #define K_CSCN LGUI(LCTL(LSFT(KC_4))) // Copy a portion of the screen to the clipboard
    #define M_SpUp 0
    #define M_SpDn 0
#endif
#if OS_POPOS_20_04_ENABLED
    #define K_LOCK LGUI(KC_ESC) // Locks screen
    #define K_CSCN 0
    #define M_SpUp LGUI(LCTL(KC_UP)) // Workspace Up
    #define M_SpDn LGUI(LCTL(KC_DOWN)) // Workspace Down
#endif

// Layer Keys
#define L_LOWER MO(_LOWER)
#define L_RAISE MO(_RAISE)
#define LT_LOW LT(_LOWER, KC_ENT)
#define LT_RAI LT(_RAISE, KC_SPC)

// Layout blocks
#define __N1___                                      XXXXXXX
#define __N2________                                 XXXXXXX, XXXXXXX
#define _____N3______________                        XXXXXXX, XXXXXXX, XXXXXXX
#define _________N4______________                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _____________N5___________________           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ________________N6__________________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __T1___                                      _______
#define __T2________                                 _______, _______
#define _____T3______________                        _______, _______, _______
#define _________T4______________                    _______, _______, _______, _______
#define _____________T5___________________           _______, _______, _______, _______, _______
#define ________________T6__________________________ _______, _______, _______, _______, _______, _______

#define _________________NUM_LEFT___________________ T_GRV, KC_1, KC_2, KC_3, KC_4, KC_5
#define _________________NUM_RIGHT__________________ KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS

#define _________________QWERTY_L1__________________ T_ESC, T_Q, T_W, KC_E, KC_R, KC_T
#define _________________QWERTY_L2__________________ T_TAB, KC_A, KC_S, KC_D, KC_F, KC_G
#define _________________QWERTY_L3__________________ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B

#define _________________QWERTY_R1__________________ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS
#define _________________QWERTY_R2__________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT
#define _________________QWERTY_R3__________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL

#define _________________DVORAK_L1__________________ T_ESC, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y
#define _________________DVORAK_L2__________________ T_TAB, KC_A, KC_O, KC_E, KC_U, KC_I
#define _________________DVORAK_L3__________________ KC_LSFT, KC_SCLN, T_Q, KC_J, KC_K, KC_X
#define _________________DVORAK_R1__________________ KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSLS
#define _________________DVORAK_R2__________________ KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH
#define _________________DVORAK_R3__________________ KC_B, KC_M, T_W, KC_V, KC_Z, KC_EQL

#define _________________COLEMAK_L1_________________ T_ESC, T_Q, T_W, KC_F, KC_P, KC_G
#define _________________COLEMAK_L2_________________ T_TAB, KC_A, KC_R, KC_S, KC_T, KC_D
#define _________________COLEMAK_L3_________________ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B
#define _________________COLEMAK_R1_________________ KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS
#define _________________COLEMAK_R2_________________ KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT
#define _________________COLEMAK_R3_________________ KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL

#define _________________FUNC_LEFT__________________ KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define _________________FUNC_RIGHT_________________ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12

#define _________________MEDIA_1____________________ _____T3______________, KC_BRIU, KC_MPLY, KC_MUTE
#define _________________MEDIA_2____________________ K_LOCK, __T2________, KC_BRID, KC_MFFD, KC__VOLUP
#define _________________MEDIA_3____________________ M_SHFT, _____T3______________, KC_MRWD, KC__VOLDOWN

#define _________________MOUSE_1____________________ KC_WH_U, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5
#define _________________MOUSE_2____________________ KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, __T1___

#define ___________________NAV_1____________________ KC_PGUP, KC_HOME, KC_END, _____T3______________
#define ___________________NAV_2____________________ KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, __T1___
#define ___________________NAV_3____________________ __T1___, M_TERM, __T1___, __T1___, M_PYNV, __T1___

#define _________________SECRET_1___________________  __T1___, M_XXX1, M_XXX2, M_XXX3, M_XXX4, M_XXX5

#define ________MOD_LEFT_________   KC_LALT, T_GUI, KC_LCTL
#define ________MOD_RIGHT________   KC_BSPC, KC_DEL, KC_RGHT
#define _____MOD_RIGHT_LOWER_____   __T2________, M_CODE, __T1___

#define _CENTER_TOP_                T_LBRC, T_RBRC
#define _CENTER_BOTTOM_             LT_RAI, LT_LOW

// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
