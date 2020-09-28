#pragma once
#include "highfeature.h"

enum custom_tapdances{
  TD_LBRC_BACK = 0,
  TD_RBRC_FWD,
};

#define T_LBRC TD(TD_LBRC_BACK)   // Tap for [, double tap for back browser
#define T_RBRC TD(TD_RBRC_FWD)    // Tap for ], double tap for forward browser

#define T_ESC  KC_ESCAPE
#define T_TAB  KC_TAB
#define T_GRV  KC_GRAVE
#define T_GUI  KC_LGUI
#define T_W    KC_W
#define T_Q    KC_Q
