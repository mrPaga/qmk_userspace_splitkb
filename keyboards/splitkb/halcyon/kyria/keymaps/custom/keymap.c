// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SYM,
    _NAV,
    _NUM,
    _FUN,
    _INV,
};

// Layer switch
#define MO_NAV MO(_NAV)
#define MO_NUM MO(_NUM)
#define MO_INV MO(_INV)
#define OSL_FUN OSL(_FUN)

#define TG_NUM TG(_NUM)

#define SYM_SPC LT(_SYM, KC_SPC)

// Home-row mod
#define T_CTL_A LCTL_T(KC_A)
#define T_GUI_R LGUI_T(KC_R)
#define T_SFT_S LSFT_T(KC_S)
#define T_ALT_T LALT_T(KC_T)

#define T_ALT_N RALT_T(KC_N)
#define T_SFT_E RSFT_T(KC_E)
#define T_GUI_I RGUI_T(KC_I)
#define T_CTL_O RCTL_T(KC_O)

// Window specific keys
#define L_DESK LCG(KC_LEFT)
#define R_DESK LCG(KC_RGHT)
#define N_WIN LALT(KC_TAB)
#define P_WIN LSA(KC_TAB)
// #define TSK_VIEW LGUI(KC_TAB)
#define D_MENU LAG(KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Esc   |Ctrl/A| GUI/R|Shft/S| Alt/T|   G  |                              |   M  | Alt/N|Shft/E| GUI/I|Ctrl/O|  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LDesk  |   Z  |   X  |   C  |   D  |   V  |RMouse|   ↑  |  |   ←  | TNum |   K  |   H  | ,  < | . >  | /  ? | RDesk  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | MInv | MNum | MSym/| Bksp |   ↓  |  |   →  | Enter| MSym/| MNav |LMouse|
 *                        |      |      | Space|      |      |  |      |      | Space|      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_BASE] = LAYOUT_split_3x6_5_hlc(
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                            KC_J,    KC_L,    KC_U,   KC_Y , KC_SCLN, KC_BSLS,
       KC_ESC, T_CTL_A, T_GUI_R, T_SFT_S, T_ALT_T,    KC_G,                                            KC_M, T_ALT_N, T_SFT_E, T_GUI_I, T_CTL_O, KC_QUOT,
       L_DESK,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, MS_BTN2,   KC_UP,     KC_LEFT,  TG_NUM,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  R_DESK,
                                  MO_INV,  MO_NUM, SYM_SPC, KC_BSPC, KC_DOWN,     KC_RGHT,  KC_ENT, SYM_SPC,  MO_NAV, MS_BTN1,
      KC_MUTE,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                           KC_MUTE,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

/*
 * Sym Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  `   |CW Tog|      |      |      |                              |      |  =   |  {   |  }   |  -   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CapsLk |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | PWindow|   ~  |      |      |      |      |      |      |  |      |      |      |  +   |  [   |  ]   |  _   | NWindow|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  Del |      |  |      |  Ins |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYM] = LAYOUT_split_3x6_5_hlc(
      _______,  KC_GRV, CW_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX,  KC_EQL, KC_LBRC, KC_RBRC, KC_MINS, XXXXXXX,
      KC_CAPS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
        P_WIN, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     _______, _______, XXXXXXX, KC_PLUS, KC_LCBR, KC_RCBR, KC_UNDS,   N_WIN,
                                  D_MENU, _______, _______,  KC_DEL, _______,     _______,  KC_INS, _______, _______, _______,
      _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |   ↑  |      | PrtSc|      |                              |      |      |      |      |      |  Sleep |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   ←  |   ↓  |   →  |      |      |                              |      |  Alt | Shift|  GUI | Ctrl |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |M Play| PgUp |  | Home |      |      |      |M Prev|M Next|M Play|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | DMenu|      |      |      | PgDn |  |  End |      |      |      |VolMut|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NAV] = LAYOUT_split_3x6_5_hlc(
      _______, XXXXXXX,   KC_UP, XXXXXXX, KC_PSCR, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,                                         XXXXXXX, KC_RALT, KC_RSFT, KC_RGUI, KC_RCTL, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_PGUP,     KC_HOME, _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, _______,
                                 _______, _______,  KC_SPC, _______, KC_PGDN,     KC_END,S(KC_INS), _______, _______, KC_MUTE,
      _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______
    ),

/*
 * Num Layer: Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |   7  |   8  |   9  |      |                              |   /  |   7  |   8  |   9  |   -  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |   4  |   5  |   6  |      |                              |   *  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |   1  |   2  |   3  | OFun |      |      |  |      | TNum | OFun |   1  |   2  |   3  |   .  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |   0  |      |      |  |      |      |   0  |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NUM] = LAYOUT_split_3x6_5_hlc(
      _______, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,                                         KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, XXXXXXX,
      XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,                                         KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS, XXXXXXX,
      _______, XXXXXXX,    KC_1,    KC_2,    KC_3, OSL_FUN, XXXXXXX, _______,     _______, _______, OSL_FUN,    KC_1,    KC_2,    KC_3, KC_DOT, _______,
                                 XXXXXXX, _______,    KC_0, KC_BSPC, _______,     _______,  KC_ENT,    KC_0, _______, XXXXXXX,
      _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F7  |  F8  |  F9  |  F10 |      |                              |      |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F4  |  F5  |  F6  |  F11 |      |                              |      |  F4  |  F5  |  F6  |  F11 |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F12 |      |      |      |  |      |      |      |  F1  |  F2  |  F3  |  F12 |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_FUN] = LAYOUT_split_3x6_5_hlc(
      XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                         XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
      XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                                         XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11, XXXXXXX,
      XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX,
                                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______
    ),

/*
 * Inverse Layer: Invert left-right
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   \ |  |   J  |   L  |   U  |   Y  | ;  : |                              |   Q  |   W  |   F  |   P  |   B  |  Tab   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   ' "  |   M  |   N  |   E  |   I  |   O  |                              |   A  |   R  |   S  |   T  |   G  |  Esc   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  RDesk |   K  |   H  | ,  < | . >  | /  ? |LMouse|   →  |  |   ↑  |      |   Z  |   X  |   C  |   D  |   V  | LDesk  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | Space| Enter|   ←  |  |   ↓  | Bksp | Space|      |RMouse|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_INV] = LAYOUT_split_3x6_5_hlc(
      KC_BSLS,    KC_J,    KC_L,    KC_U,   KC_Y , KC_SCLN,                                            KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,  KC_TAB,
      KC_QUOT,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,                                            KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  KC_ESC,
       R_DESK,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, MS_BTN1, KC_RGHT,       KC_UP, XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  L_DESK,
                                  MO_INV, XXXXXXX,  KC_SPC,  KC_ENT, KC_LEFT,     KC_DOWN, KC_BSPC,  KC_SPC, XXXXXXX, MS_BTN2,
      _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______
    ),



// /*
//  * Halcyon Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//      _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
//                                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______
//     ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR),  ENCODER_CCW_CW(MS_WHLL, MS_WHLR),  ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },
    [_SYM] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [_NAV] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [_NUM] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),  ENCODER_CCW_CW(XXXXXXX, XXXXXXX),  ENCODER_CCW_CW(XXXXXXX, XXXXXXX),  ENCODER_CCW_CW(XXXXXXX, XXXXXXX)  },
    [_FUN] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),  ENCODER_CCW_CW(XXXXXXX, XXXXXXX),  ENCODER_CCW_CW(XXXXXXX, XXXXXXX),  ENCODER_CCW_CW(XXXXXXX, XXXXXXX)  },
    [_INV] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(MS_WHLL, MS_WHLR),  ENCODER_CCW_CW(MS_WHLL, MS_WHLR)  },
};
#endif


// RGB MATRIX
// ,-----------------------------.                         ,------------------------------.
// |  25 | 26 | 27 | 28 | 29 | 30 |                        | 56 | 57 | 58 | 59 | 60 | 61  |
// |-----+----+----+----+----+----|                        |----+----+----+----+----+-----|
// |  19 | 20 | 21 | 22 | 23 | 24 |                        | 50 | 51 | 52 | 53 | 54 | 55  |
// |-----+----+----+----+----+----+---------.    ,---------+----+----+----+----+----+-----|
// |  11 | 13 | 14 | 15 | 16 | 17 | 18 |  7 |    | 37 | 42 | 44 | 45 | 46 | 47 | 48 | 49  |
// `---------------+----+----+----+----+----|    |----+----+----+----+----+---------------'
//                 |  6 |  8 |  9 | 12 | 10 |    | 39 | 40 | 43 | 41 | 38 |
//                 `------------------------'    `------------------------'
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        switch(layer) {
            case _SYM:
                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];
                        if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, RGB_ORANGE);
                        } else {
                            rgb_matrix_set_color(index, RGB_OFF);
                        }
                    }
                }
                break;
            case _NAV:
                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];

                        // if (index >= led_min && index < led_max && index != NO_LED){
                        //     if (index == 7 || index == 37){
                        //         rgb_matrix_set_color(index, RGB_RED);
                        //     }
                        //     else if (index == 6 || index == 38){
                        //         rgb_matrix_set_color(index, RGB_PINK);
                        //     }
                        //     else if (index == 8 || index == 41){
                        //         rgb_matrix_set_color(index, RGB_BLUE);
                        //     }
                        //     else if (index == 10 || index == 39){
                        //         rgb_matrix_set_color(index, RGB_GREEN);
                        //     }
                        //     else if (index == 12 || index == 19 || index == 40 || index == 55){
                        //         rgb_matrix_set_color(index, RGB_WHITE);
                        //     }
                        //     else if (index == 18 || index == 42){
                        //         rgb_matrix_set_color(index, RGB_YELLOW);
                        //     }
                        //     else if (keymap_key_to_keycode(layer, (keypos_t){col,row}) <= KC_TRNS) {
                        //         rgb_matrix_set_color(index, RGB_OFF);
                        //     }
                        //
                        // }
                        if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, RGB_AZURE);
                        } else {
                            rgb_matrix_set_color(index, RGB_OFF);
                        }
                    }
                }
                break;
            case _NUM:
                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];
                        if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, RGB_WHITE);
                        } else {
                            rgb_matrix_set_color(index, RGB_OFF);
                        }
                    }
                }
                break;
            case _FUN:
                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];
                        if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, RGB_RED);
                        } else {
                            rgb_matrix_set_color(index, RGB_OFF);
                        }
                    }
                }
                break;
            case _INV:
                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];
                        if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, RGB_YELLOW);
                        } else {
                            rgb_matrix_set_color(index, RGB_OFF);
                        }
                    }
                }
                break;
            default:
                break;
        }
    }
    return false;
}
