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
    #define TAPPING_TERM 140 // This is for the Iris only. The ALT requires a larger term due to the heavy keys
#else
    #define TAPPING_TERM 140
    // AAB: Permissive hold screws up key rolls with home row mods
    // #define PERMISSIVE_HOLD  // Permissive hold may cause problems with swift rolls that are within the tapping term.
#endif

#define MACRO_TIMER 5  // Only used for secrets, right now, as far as I can tell

// Layer Names
enum loc_layers {
    LYR_DROP_QWERTY = 0,
    LYR_MASSDROP_FN = 1,
    LYR_LOC = 2
};

enum iris_layers {
    LYR_QWERTY = 0,
    LYR_NAV = 1,     // Navigation
    LYR_SYMBOLS = 2, // Symbols
    LYR_ADJUST = 3,  // Keyboard/others
    LYR_NUMPAD = 4,  // Nummpad
};

// Layer Select Underglow configuration
#define LYR_QWERTY_COLOR         RGB_OFF  // No underlighing by default
#define LYR_MASSDROP_FN_COLOR    132, 63, 202  // Desaturated Purple
#define LYR_LOC_COLOR            50, 220, 101  // Desaturated spring green

#define LYR_QWERTY_COLOR_HSV 0, 0, 0
#define UNDERGLOW_VAL 220
#define LYR_NAV_COLOR_HSV 155, 200, UNDERGLOW_VAL // Blue
#define LYR_SYMBOLS_COLOR_HSV 90, 200, UNDERGLOW_VAL  // Green
#define LYR_ADJUST_COLOR_HSV 222, 200, UNDERGLOW_VAL  // Purple
#define LYR_NUMPAD_COLOR_HSV 201, 250, UNDERGLOW_VAL  // Pink

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
#define CTL_BS LCTL(KC_BSPC)  // Ctrl + Backspace, for deleting whole words
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  // Mod-tap: LCTL when held, Esc when tapped
#define CTL_LAR MT(MOD_RCTL, KC_LEFT) // Mod-tap: RCTL when held, left arrow when tapped
#define SFT_CAP MT(MOD_LSFT, KC_CAPSLOCK) // Mod-tap: Left shift when held, caps lock when tapped
#define SFT_ENT MT(MOD_RSFT, KC_ENT) // Mod-tap: Right shift when held, enter when tapped.
#define BSP_NMP LT(LYR_NUMPAD, KC_BSPC) // Layer Tap: NUMPAD layer when held, backspace when tapped
#define TGL_NMP TG(LYR_NUMPAD) // Toggle the NUMPAD layer

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
// GASC with numbers on the home row
#define GUI_1 LGUI_T(KC_1)
#define ALT_2 LALT_T(KC_2)
#define CTL_3 LCTL_T(KC_3)
#define SFT_4 LSFT_T(KC_4)
#define GUI_0 LGUI_T(KC_0)
#define ALT_9 LALT_T(KC_9)
#define CTL_8 LCTL_T(KC_8)
#define SFT_7 LSFT_T(KC_7)

// GASC with my Iris symbols
// NOTE: Shifted characters don't work with Mod-Tap, so I have these disabled, for now
// GUI/WIN on left currently unused
// #define ALT_LPRN LGUI_T(KC_LEFT_PAREN) // ALT and Left Paren
// #define CTL_RPRN LCTL_T(KC_RIGHT_PAREN) // CTL and Right Paren
// #define SFT_MINS LSFT_T(KC_MINS) // Shift and Minus
// GUI on right currently unused in symbol layer
// #define ALT_RCBR LALT_T(KC_RIGHT_CURLY_BRACE) // ALT and Right Curly bracket
// #define CTL_LCBR LCTL_T(KC_LEFT_CURLY_BRACE) // CTL and Left Curly bracket
// Shift on the right currently unused in symbol layer
#endif // #ifdef HOME_ROW_MODS

// Combos


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