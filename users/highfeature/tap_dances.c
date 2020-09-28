#ifdef TAP_DANCE_ENABLE
#include "highfeature.h"

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_BACK]    = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LGUI(KC_LBRC)),
  [TD_RBRC_FWD]     = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LGUI(KC_RBRC)),
};
#endif
