SRC += loctones.c

TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
# For Caps Word, #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD in config.h for each keymap

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif