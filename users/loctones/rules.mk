# Note that <user>/rules.mk is included in the build AFTER the keymap rules.mk.
# This allows <user>/rules.mk to handle features that may or may not be available in each keyboard.

# Remember that features should be enabled in the keayboard's rules.mk file

INTROSPECTION_KEYMAP_C += loctones.c

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif