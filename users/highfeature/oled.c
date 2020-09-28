#include QMK_KEYBOARD_H
#include <stdio.h>
#include "highfeature.h"

#ifdef OLED_DRIVER_ENABLE

static uint32_t oled_timer = 0;

void keyboard_post_init_user(void) {
  wait_ms(2000);
  oled_init(OLED_ROTATION_0);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_0;
  }
  return OLED_ROTATION_180;
}

bool process_record_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer = timer_read32();
    }
    return true;
}

void render_default_layer_state(void) {
  oled_write_P(PSTR("Layout: "), false);
  switch (biton32(default_layer_state)) {
#if HF_COLEMAK_ENABLED
      case _COLEMAK:
        oled_write_P(PSTR("Colemak"), false);
        break;
#endif
#if HF_DVORAK_ENABLED
      case _DVORAK:
        oled_write_P(PSTR("Dvorak"), false);
        break;
#endif
      case _QWERTY:
        oled_write_P(PSTR("Qwerty"), false);
        break;
      default:
        oled_write_ln_P(PSTR("Undefined"), false);
  }
}

void render_layer_state(void) {
    oled_write_P(PSTR("\nLayer:"), false);
    oled_write_P(PSTR(" LOW"), layer_state_is(_LOWER));
    oled_write_P(PSTR(" RAI"), layer_state_is(_RAISE));
    oled_write_P(PSTR(" ADJ"), layer_state_is(_ADJUST));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("\nMods: "), false);
    oled_write_P(PSTR("SHF "), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("CTL "), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("ALT "), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

void render_status(void){
  render_default_layer_state();
  oled_write_P(PSTR("\n"), false);
  render_layer_state();
  render_mod_status(get_mods()|get_oneshot_mods());
}

//static void render_logo(void) {
////  static const char PROGMEM qmk_logo[] = {
////      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
////      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
////      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
////      0};
//    static const char PROGMEM qmk_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//    };
//
//  oled_write_P(qmk_logo, false);
//}

void oled_task_user(void) {
//    if (timer_elapsed32(oled_timer) > 30000) {
//        oled_off();
//        return;
//    }

//    if (is_keyboard_master()) {
        render_status();
//    } else {
//        render_logo();
//        oled_write_P(PSTR("\n"), false);
//        oled_scroll_left();
//    }
}

#endif
