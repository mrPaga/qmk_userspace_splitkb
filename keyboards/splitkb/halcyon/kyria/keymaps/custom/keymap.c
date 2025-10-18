// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define TAPPING_TERM 190
#define QUICK_TAP_TERM 120

#define ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define RGBLIGHT_HUE_STEP 42
#define RGBLIGHT_SAT_STEP 210
#define RGBLIGHT_VAL_STEP 255

enum layers {
    // _QWERTY = 0,
    // _DVORAK,
    // _COLEMAK_DH,
    _BASE = 0,
    _SYM,
    _NAV,
    _NUM,
    _FUN,
    // _ADJUST,
    _INV,
};

// Aliases for readability
// #define QWERTY   DF(_QWERTY)
// #define COLEMAK DF(_BASE)
// #define DVORAK   DF(_DVORAK)

#define MO_NAV MO(_NAV)
#define MO_NUM MO(_NUM)
#define MO_INV MO(_INV)
#define OSL_FUN OSL(_FUN)

#define TG_NUM TG(_NUM)

#define SYM_SPC LT(_SYM, KC_SPC)

// #define ADJUST   MO(_ADJUST)

#define CTL_A LCTL_T(KC_A)
#define GUI_R LGUI_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define ALT_T LALT_T(KC_T)

#define ALT_N RALT_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define GUI_I RGUI_T(KC_I)
#define CTL_O RCTL_T(KC_O)

#define L_DESK LCG(KC_LEFT)
#define R_DESK LCG(KC_RGHT)
#define N_WIN LALT(KC_TAB)
#define P_WIN LSA(KC_TAB)
// #define TSK_VIEW LGUI(KC_TAB)
#define D_MENU LAG(KC_SPC)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

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
 * | LDesk  |   Z  |   X  |   C  |   D  |   V  |RMouse|   ↑  |  |   →  | TNum |   K  |   H  | ,  < | . >  | /  ? | RDesk  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | MInv | MNum | MSym/| Bksp |   ↓  |  |   ←  | Enter| MSym/| MNav |LMouse|
 *                        |      |      | Space|      |      |  |      |      | Space|      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_BASE] = LAYOUT_split_3x6_5_hlc(
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                            KC_J,    KC_L,    KC_U,   KC_Y , KC_SCLN, KC_BSLS,
       KC_ESC,   CTL_A,   GUI_R,   SFT_S,   ALT_T,    KC_G,                                            KC_M,   ALT_N,   SFT_E,   GUI_I,   CTL_O,CTL_QUOT,
       L_DESK,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, MS_BTN2,   KC_UP,     KC_RGHT,  TG_NUM,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  R_DESK,
                                  MO_INV,  MO_NUM, SYM_SPC, KC_BSPC, KC_DOWN,     KC_LEFT,  KC_ENT, SYM_SPC,  MO_NAV, MS_BTN1,
      KC_MUTE,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                           KC_MUTE,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

/*
 * Sym Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  `   |CW Tog|      |      |      |                              |      |  =   |  [   |  ]   |  -   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CapsLk |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  (   |  )   |  *   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | PWindow|   ~  |      |      |      |      |      |      |  |      |      |      |  +   |  {   |  }   |  _   | NWindow|
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
      KC_CAPS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                         KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, XXXXXXX,
        P_WIN, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     _______, _______, XXXXXXX, KC_PLUS, KC_LCBR, KC_RCBR, KC_UNDS,   N_WIN,
                                 _______, _______, _______,  KC_DEL, _______,     _______,  KC_INS, _______, _______, _______,
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
                                  D_MENU, _______,  KC_SPC, _______, KC_PGDN,     KC_END,S(KC_INS), _______, _______, KC_MUTE,
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
      _______, XXXXXXX,    KC_1,    KC_2,    KC_3, OSL_FUN, XXXXXXX,   KC_UP,     KC_RGHT, _______, OSL_FUN,    KC_1,    KC_2,    KC_3, KC_DOT, _______,
                                 XXXXXXX, _______,    KC_0, KC_BSPC, KC_DOWN,     KC_LEFT,  KC_ENT,    KC_0, _______, XXXXXXX,
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
                                  MO_INV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
     CTL_QUOT,    KC_M,   ALT_N,   SFT_E,   GUI_I,   CTL_O,                                           CTL_A,   GUI_R,   SFT_S,   ALT_T,    KC_G,  KC_ESC,
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



// /*
//  * Base Layer: QWERTY
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
//  *                        |      |      | Enter|      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_QWERTY] = LAYOUT_split_3x6_5_hlc(
//      KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
//      CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
//      KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
//                                 ADJUST , KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP,
//      KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
//     ),
//
// /*
//  * Base Layer: Dvorak
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |  Tab   | '   | , <  | . >  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  Bksp  |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |Ctrl/Esc|   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |Ctrl/- _|
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * | LShift | ; :  |   Q  |   J  |   K  |   X  | [ {  |CapsLk|  |F-keys|  ] } |   B  |   M  |   W  |   V  |   Z  | RShift |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
//  *                        |      |      | Enter|      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_DVORAK] = LAYOUT_split_3x6_5_hlc(
//      KC_TAB  ,KC_QUOTE,KC_COMM,  KC_DOT,   KC_P ,   KC_Y ,                                        KC_F,   KC_G ,  KC_C ,   KC_R ,  KC_L , KC_BSPC,
//      CTL_ESC , KC_A ,  KC_O   ,  KC_E  ,   KC_U ,   KC_I ,                                        KC_D,   KC_H ,  KC_T ,   KC_N ,  KC_S , CTL_MINS,
//      KC_LSFT ,KC_SCLN, KC_Q   ,  KC_J  ,   KC_K ,   KC_X , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_B,   KC_M ,  KC_W ,   KC_V ,  KC_Z , KC_RSFT,
//                                  ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP,
//      KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
//     ),
//
// /*
//  * Adjust Layer: Default layer settings, RGB
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_ADJUST] = LAYOUT_split_3x6_5_hlc(
//       _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, DVORAK , _______, _______,                                    RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, _______,
//       _______, _______, _______, COLEMAK, _______, _______,_______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, _______,
//                                  _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,
//      _______, _______,  _______, _______, _______,                                                      _______, _______, _______, _______, _______
//     ),

