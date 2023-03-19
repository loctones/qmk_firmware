/*
Copyright 2019 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define SPLIT_HAND_PIN D5

#define BACKLIGHT_DEFAULT_LEVEL 3

//AAB: Rebase on 11/7. I think these are not needed and can be deleted
// #define RGBLIGHT_DEFAULT_VAL 128
// #define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_MODE_STATIC_LIGHT)

//AAB-define for HRM configuration
// Some configuration is in loctones.h
#define HOME_ROW_MODS
// These need to be defined here:
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM_PER_KEY // Term overrides in the Iris keymap
//#define TAPPING_FORCE_HOLD // Only enable if needed, as this will disable auto-repeat for mod-tap, or use TAPPING_FORCE_HOLD_PER_KEY, if needed.

//AAB: Enable Lighting layers
#define RGBLIGHT_LAYERS

// AAB: CAPS_WORD_ENABLE
#define CAPS_WORD_ENABLE


