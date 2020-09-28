#pragma once
#include "highfeature.h"

enum custom_keycodes {
  // Layer Macros
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  // Custom Macros
  M_PYNV,
  M_SHFT,
  M_MAKE,
  M_MALL,
  M_FLSH,
  M_VRSN,
  M_CODE,
  M_TERM,
  M_SpDn,
  M_SpUp,
  // Secret Macros
  M_XXX1,
  M_XXX2,
  M_XXX3,
  M_XXX4,
  M_XXX5,
};

#ifdef SSD1306OLED
    // from keyboard/lily58/lib/keylogger.c
    void set_keylog(uint16_t keycode, keyrecord_t *record);
#endif

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
