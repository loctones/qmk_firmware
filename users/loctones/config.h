// Configuration items should be placed in this file.
// This will be processed like the config.h file in the keymap folder
// This handled separately from loctones.h
// loctones.h won't be added in time to add settings, and adding loctones.h in this file will cause compile issues.

#define TAPPING_TERM 140

#define MACRO_TIMER 5  // Only used for secrets, right now, as far as I can tell

// Combo stuff
// Define COMBO_ENABLE = yes in the respective keyboards' rules.mk file
#ifdef COMBO_ENABLE
#define COMBO_MUST_TAP_PER_COMBO  // Require some combos to be taps only, like Escape
#endif  // COMBO_ENABLE

// If using Caps word, enable it by holding both shifts
// I ended up using a combo to enable caps word. See loctones.c for combo definition