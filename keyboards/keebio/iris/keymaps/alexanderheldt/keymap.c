// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define TAPPING_TERM 200

#define _QWERTY 0
#define _SYM 1
#define _WM 2
#define _CTR 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYM,
  WM,
  CTR,
};

//Tap Dance Declarations
enum {
  TD_WS_1 = 0,
  TD_WS_2,
  TD_WS_3,
  TD_WS_4,
  TD_WS_5,
  TD_WS_6,
  TD_WS_7,
  TD_WS_8,
  TD_WS_9,
  TD_WS_0,
};

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  //Tap once for SUPER+n, twice for SUPER+SHIFT+n
  [TD_WS_1]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_1), LSG(KC_1)),
  [TD_WS_2]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_2), LSG(KC_2)),
  [TD_WS_3]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_3), LSG(KC_3)),
  [TD_WS_4]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_4), LSG(KC_4)),
  [TD_WS_5]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_5), LSG(KC_5)),
  [TD_WS_6]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_6), LSG(KC_6)),
  [TD_WS_7]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_7), LSG(KC_7)),
  [TD_WS_8]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_8), LSG(KC_8)),
  [TD_WS_9]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_9), LSG(KC_9)),
  [TD_WS_0]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_0), LSG(KC_0)),
};

#define WS_1 TD(TD_WS_1)
#define WS_2 TD(TD_WS_2)
#define WS_3 TD(TD_WS_3)
#define WS_4 TD(TD_WS_4)
#define WS_5 TD(TD_WS_5)
#define WS_6 TD(TD_WS_6)
#define WS_7 TD(TD_WS_7)
#define WS_8 TD(TD_WS_8)
#define WS_9 TD(TD_WS_9)
#define WS_0 TD(TD_WS_0)
#define WS_L RGUI(KC_H)
#define WS_D RGUI(KC_J)
#define WS_U RGUI(KC_K)
#define WS_R RGUI(KC_L)
#define WM_LOCK LGUI(KC_X)	// closes active window in WM
#define WM_CLOSE LGUI(KC_ESC)	// locks screen

#define HR_A LGUI_T(KC_A)
#define HR_S LALT_T(KC_S)
#define HR_D LSFT_T(KC_D)
#define HR_F LCTL_T(KC_F)
#define HR_G LT(_SYM, KC_G)
#define HR_H LT(_SYM, KC_H)
#define HR_J RCTL_T(KC_J)
#define HR_K RSFT_T(KC_K)
#define HR_L LALT_T(KC_L)
#define HR_O RGUI_T(SE_ODIA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  HR_A,    HR_S,    HR_D,    HR_F,    HR_G,                               HR_H,    HR_J,    HR_K,    HR_L,    HR_O,    SE_ADIA,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(_WM),          MO(_WM), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────
                                    MO(_CTR), KC_BSPC, KC_ENT,                   KC_ENT,  KC_SPC,   _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     SE_QUES, SE_EXLM, SE_AT,   SE_LCBR, SE_RCBR, SE_EQL,                             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SE_PLUS, SE_HASH, SE_DLR,  SE_LPRN, SE_RPRN, SE_GRV,                             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SE_MINS, SE_AMPR, SE_PIPE, SE_LBRC, SE_RBRC, SE_ACUT,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SE_CIRC, SE_PERC, SE_TILD, SE_LABK, SE_RABK, SE_ASTR, _______,          _______, SE_QUOT, SE_DQUO, SE_SCLN, SE_COLN, SE_BSLS, SE_SLSH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_WM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     WM_LOCK, WS_1,    WS_2,    WS_3,    WS_4,    WS_5,                               WS_6,    WS_7,    WS_8,    WS_9,    WS_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     WM_CLOSE, _______, _______, _______, _______, _______,                           WS_L,    WS_D,    WS_U,    WS_R,     _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, LGUI(KC_ENT), LGUI(KC_SPC),       RGUI(KC_SPC), RGUI(KC_ENT), _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_CTR] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,            KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

