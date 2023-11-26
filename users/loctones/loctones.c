
#include "loctones.h"

#ifdef RGBMATRIX_ENABLE //ALT uses RGBMATRIX, Iris does not
#include "rgb_matrix.h"
#endif // #ifdef RGBMATRIX_ENABLE
#ifdef RGBLIGHT_LAYERS
#include "rgblight.h"
#endif // #ifdef RGBLIGHT_LAYERS

// Combos
// JK as escape
// const uint16_t PROGMEM esc_combo[] =


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


#ifdef RGBMATRIX_ENABLE
// RGB Matrix code - Including Layer-Selection Underglow
extern led_config_t g_led_config;
// Set all LEDs with the given flag set to the color indicated.
void set_rgb_color_with_flags(uint8_t led_selection_flag, uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], led_selection_flag)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    // Set underglow to indicate the current layer
    switch (get_highest_layer(layer_state)) {
        case LYR_LOC:
            set_rgb_color_with_flags(LED_FLAG_UNDERGLOW, LYR_LOC_COLOR);
            break;
        case LYR_MASSDROP_FN:
            set_rgb_color_with_flags(LED_FLAG_UNDERGLOW, LYR_MASSDROP_FN_COLOR);
            break;
        default:
            set_rgb_color_with_flags(LED_FLAG_UNDERGLOW, LYR_QWERTY_COLOR);
            break;
    }
}
#endif //#ifdef RGBMATRIX_ENABLE

