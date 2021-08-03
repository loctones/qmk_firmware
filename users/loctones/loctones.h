#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"
#include "process_keycode\process_tap_dance.h"
/*
From QMK MSYS and within the git repo: qmk compile
From Shell: c/code/qmk: ./mdloader_windows.exe --first --download .\qmk_firmware\massdrop_alt_loctones.bin
*/

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif
#ifdef HOME_ROW_MODS
    //#define IGNORE_MOD_TAP_INTERRUPT // For some reason this needs to be defined in setup.h.
    #define TAPPING_TERM 150
    //NOT #define PERMISSIVE_HOLD  // Permissive hold may cause problems with swift rolls that are within the tapping term
#else
    #define TAPPING_TERM 100
    #define PERMISSIVE_HOLD  // Permissive hold may cause problems with swift rolls that are within the tapping term
#endif

#define MACRO_TIMER 5  // Only used for secrets, right now, as far as I can tell

// Layer Names
enum loc_layers {
    LYR_QWERTY = 0,
    LYR_MASSDROP_FN = 1,
    LYR_LOC = 2,
};

enum iris_layers {
    //LYR_QWERTY = 0,
    LYR_NAV = 1,     // Navigation
    LYR_SYMBOLS, // Symbols
    LYR_ADJUST   // Keyboard/others
};

// Layer Select Underglow configuration
#define LYR_QWERTY_COLOR         RGB_OFF  // No underlighing by default
#define LYR_MASSDROP_FN_COLOR    132, 63, 202  // Desaturated Purple
#define LYR_LOC_COLOR            50, 220, 101  // Desaturated spring green

#define LYR_QWERTY_COLOR_HSV 0, 0, 0
#define UNDERGLOW_VAL 220
#define LYR_NAV_COLOR_HSV 155, 200, UNDERGLOW_VAL // Blue
#define LYR_SYMBOLS_COLOR_HSV 90, 200, UNDERGLOW_VAL  // Green
#define LYR_ADJUST_COLOR_HSV 222, 200, UNDERGLOW_VAL  // Pin

// Layer state change colors
void layer_select_underglow(uint32_t state);

#ifdef TAP_DANCE_ENABLE
// Tap dance keycodes
enum td_keycodes {
    TD_2CBR,  // Curly brace: 1 for left, 2 tap for:
    TD_2PRN,  // Parenthesis: 1 for left, 2 tap for right
    TD_2BRC,  // Square brace: 1 for left, 2 tap for right
    TD_2GT    // Less than, greater than: 1 for LT, 2 tap for GT
};
/*
// Tap dance states
enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t; 
*/

// Tapdance aliases
#define Z_UNDO TD_Z_UNDO
#define X_CUTT TD_X_CUT
#define C_COPY TD_C_COPY
#define V_PSTE TD_V_PASTE
#endif // TAP_DANCE_ENABLE

// Custom keys
#define SPC_LOC LT(LYR_LOC, KC_SPACE)  // _LOC layer when held, space when tapped
#define CTL_BS LCTL(KC_BSPACE)  // Ctrl + Backspace, for deleting whole words
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  // Mod-tap: LCTL when held, Esc when tapped
#define CTL_LAR MT(MOD_RCTL, KC_LEFT) // Mod-tap: RCTL when held, left arrow when tapped
#define SFT_CAP MT(MOD_LSFT, KC_CAPSLOCK) // Mod-tap: Left shift when held, caps lock when tapped
#define SFT_ENT MT(MOD_RSFT, KC_ENT) // Mod-tap: Right shift when held, enter when tapped.

#ifdef HOME_ROW_MODS
// Home Row Mod custom keys
// GASC configuration
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
#define GUI_SCLN LGUI_T(KC_SCLN)
#define ALT_L LALT_T(KC_L)
#define CTL_K LCTL_T(KC_K)
#define SFT_J LSFT_T(KC_J)
#endif // #ifdef HOME_ROW_MODS


// Secrets
enum secret_strings {
  KC_SECRET_1 = SAFE_RANGE,
  KC_SECRET_2,
  KC_SECRET_3,
  KC_SECRET_4,
  KC_SECRET_5,
  END_SECRET_SAFE_RANGE
};

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#endif