#include "loctones.h"

#ifdef RGBMATRIX_ENABLE //ALT uses RGBMATRIX, Iris does not
#include "rgb_matrix.h"
#endif // #ifdef RGBMATRIX_ENABLE
#ifdef RGBLIGHT_LAYERS
#include "rgblight.h"
#endif // #ifdef RGBLIGHT_LAYERS

#ifdef TAP_DANCE_ENABLE
// Tap Dance definitions , using simple definitions
tap_dance_action_t tap_dance_actions[] = {
    // Braces, single tap for left, double tap for right
    [TD_2CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_2PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_2BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_2GT] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT)    // LT and GT brackets with double tap
};
#endif // TAP_DANCE_ENABLE

// Combo stuff
const uint16_t PROGMEM copy_combo[] = {CTL_D, KC_E, COMBO_END};  // DE for copy (vertical)
const uint16_t PROGMEM paste_combo[] = {SFT_F, KC_R, COMBO_END};  // FR for paste (vertical)
const uint16_t PROGMEM cut_combo[] = {ALT_S, KC_W, COMBO_END};  // SW for cut (vertical)
const uint16_t PROGMEM esc_combo[] = {SFT_J, CTL_K, COMBO_END};  // JK combo for use with my home row mods setup
const uint16_t PROGMEM caps_word_combo[] = {LSFT_ENT, RSFT_ENT, COMBO_END};  // Combo to trigger caps word
// const uint16_t PROGMEM ent_combo[] = {KC_H, KC_N, COMBO_END};  // HN vertical combo for Enter.

// Enums for these are in loctones.h
combo_t key_combos[] = {
    [CUT_COMBO] = COMBO(cut_combo, LCTL(KC_X)),
    [COPY_COMBO] = COMBO(copy_combo, LCTL(KC_C)),
    [PASTE_COMBO] = COMBO(paste_combo, LCTL(KC_V)),
    [ESC_COMBO] = COMBO(esc_combo, KC_ESC),
    [CAPS_COMBO] = COMBO_ACTION(caps_word_combo),  // This will be used to trigger caps word, search for "CAPS_COMBO" (currently in the keymap)
//    COMBO(ent_combo, KC_ENT),

};



