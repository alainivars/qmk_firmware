#include "highfeature.h"

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

#ifdef OLED_DRIVER_ENABLE
__attribute__((weak))
bool process_record_oled(uint16_t keycode, keyrecord_t *record) { return true; }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Sends workon to activate 'utils2devops' environment
    case M_PYNV:
      if (record->event.pressed) {
        SEND_STRING("workon utils2devops" SS_TAP(X_ENTER));
      }
      break;

    // Sends GUI + alt + shift to a keycode to activate shiftit. See: https://github.com/fikovnik/ShiftIt
    case M_SHFT:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
      }
      break;

    // Sends QMK make command to compile keyboard
    case M_MAKE:
     if (record->event.pressed) {
        SEND_STRING("rm -f *.hex && make clean && qmk compile -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
      }
      break;

    // Sends QMK make command with the correct bootloader
    case M_FLSH:
      if (!record->event.pressed) {
        SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP
//          #if  (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
//            ":dfu "
//          #elif defined(BOOTLOADER_CATERINA)
//            ":avrdude "
//          #endif
          SS_TAP(X_ENTER)
        );
        // Send reset_keyboard command instead of pressing reset button
//        #if  (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
//        reset_keyboard();
//        #endif
      }
      break;

    // Sends QMK version
    case M_VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
      }
      break;

    // Opens Visual Studio Code on current directory
    case M_CODE:
      if (record->event.pressed) {
        SEND_STRING("code .\n");
      }
      break;

#if OS_MAC_ENABLED
    // Opens Terminal
    case M_TERM:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI));
        wait_ms(250);
        SEND_STRING("terminal\n");
      }
      break;
#endif

    // BEGIN: Layer macros
#if HF_COLEMAK_ENABLED
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      break;
#endif

#if HF_DVORAK_ENABLED
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      break;
#endif

    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    // END: Layer macros
  }

  return process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
         #ifdef OLED_DRIVER_ENABLE
         && process_record_oled(keycode, record)
         #endif
         ; // Close return
}
