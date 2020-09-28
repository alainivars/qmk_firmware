# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#

# QMK settings, all HF_ setting are specific Highfeature
# Options             size    notOpt   -flto
# Mouse and extra
MOUSEKEY_ENABLE = yes       # (+4700) (+1630) Mouse keys
EXTRAKEY_ENABLE = yes       # (+ 450) (+ 366) Audio control and System control
UNICODE_ENABLE = no			# (+ 592) (+ 406) Unicode
# Connection
BLUETOOTH_ENABLE = no       # (+ 296) (+ 404) Enable Bluetooth with the Adafruit EZ-Key HID
# Audio
MIDI_ENABLE = no			# (+2352) MIDI controls
AUDIO_ENABLE = no			# (+5262) Audio output on port C6
# Led
OLED_DRIVER_ENABLE = yes	# (+1906) (+1678) Enable the OLED Driver
BACKLIGHT_ENABLE = no       # (+1004) Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no		# (+1946) Enable WS2812 RGB underlight.
SLEEP_LED_ENABLE = no		# (+  96) (+  30) Breathing sleep LED during USB suspend
# One hand
SWAP_HANDS_ENABLE = no      # Enable one-hand typing


SECRETS_ENABLE = yes		# to include or not the secrets sorry for NO_SECRETS I do not like the double negation


HF_DEBUG_FIRMWARE = no		# if we want to debug the firmware
ifeq ($(strip $(DEBUG_FIRMWARE)),yes)
	# Options             size    notOpt   -flto
	BOOTMAGIC_ENABLE = full    	# (+1000) (+ 740) Disable Boot Magic (https://beta.docs.qmk.fm/features/feature_bootmagic)
	CONSOLE_ENABLE = yes        # (+2416) (+2376) Console for debug
	COMMAND_ENABLE = no         # (+4908) (+1202) Commands for debug and configuration
	NKRO_ENABLE = no			# (+ 574) (+ 416) USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
	# Internal features
	TAP_DANCE_ENABLE = no 		# Enable Tap Dance.
else
	# Options             size    notOpt   -flto
	BOOTMAGIC_ENABLE = no     	# (+1000) (+ 740) Disable Boot Magic (https://beta.docs.qmk.fm/features/feature_bootmagic)
	CONSOLE_ENABLE = no			# (+2416) (+2376) Console for debug
	COMMAND_ENABLE = yes		# (+4908) (+1202) Commands for debug and configuration
	NKRO_ENABLE = no			# (+ 574) (+ 416) USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
	# Internal features
	TAP_DANCE_ENABLE = yes 		# Enable Tap Dance.
endif

# Use it always except it have place and strange behaviours
Link_Time_Optimization = yes	# if firmware size over limit, try this option
ifeq ($(strip $(Link_Time_Optimization)),yes)
    EXTRAFLAGS += -flto -DUSE_Link_Time_Optimization
endif

SRC += highfeature.c \
       process_records.c \
       tap_dances.c \
       oled.c

ifeq ($(strip $(SECRETS_ENABLE)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
endif