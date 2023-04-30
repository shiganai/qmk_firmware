#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY,
    _NUMBR,
    _FNCTN,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBR,
  FNCTN,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   /  |                    |   =  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | CAPSL|                    |Delete|   N  |   M  |   ,  |   .  |  Up  | Bksp |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Fnctn| Space|   -  |||||||| Shift| Enter| Numbr|||||||| Menu | Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_SLSH,                        KC_EQL , KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_CAPS,                        KC_DEL , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP  , KC_BSPC,
    KC_LCTL, KC_LGUI, KC_LALT, EISU,             FNCTN,   KC_SPC ,KC_MINS,        KC_RSFT,KC_ENT , NUMBR,            KC_APP , KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Numbr
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ~  |   1  |   2  |   3  |   4  |   5  |   ?  |                    |   =  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | CAPSL|                    |Delete|   N  |   M  |   ,  |   .  |PageUp| Bksp |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Numbr| Space|   -  |||||||| Shift| Enter| Fnctn|||||||| Menu | Home |PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_NUMBR] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_QUES,                        KC_EQL , KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_CAPS,                        KC_DEL , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_PGUP, KC_BSPC,
    KC_LCTL, KC_LGUI, KC_LALT, EISU,             NUMBR,   KC_SPC ,KC_MINS,        KC_RSFT,KC_ENT , FNCTN,            KC_APP , KC_HOME, KC_PGDN, KC_END
  ),

  /* Fnctn
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   ?  |                    |   =  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 | CAPSL|                    |Delete|   N  |   M  |   ,  |   .  |PageUp| Bksp |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  F11 |  F12 | EISU |||||||| Numbr| Space|   -  |||||||| Shift| Enter| Fnctn|||||||| Menu | Home |PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_FNCTN] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_QUES,                        KC_EQL , KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_CAPS,                        KC_DEL , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_PGUP, KC_BSPC,
    KC_LCTL, KC_F11 , KC_F12,  EISU,             NUMBR,   KC_SPC ,KC_MINS,        KC_RSFT,KC_ENT , FNCTN,            KC_APP , KC_HOME, KC_PGDN, KC_END
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, QK_BOOT  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
    _______, _______, BL_TOGG, BL_BRTG, BL_UP  , BL_DOWN,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NUMBR:
      if (record->event.pressed) {
        layer_on(_NUMBR);
        update_tri_layer(_NUMBR, _FNCTN, _ADJUST);
      } else {
        layer_off(_NUMBR);
        update_tri_layer(_NUMBR, _FNCTN, _ADJUST);
      }
      return false;
      break;
    case FNCTN:
      if (record->event.pressed) {
        layer_on(_FNCTN);
        update_tri_layer(_NUMBR, _FNCTN, _ADJUST);
      } else {
        layer_off(_FNCTN);
        update_tri_layer(_NUMBR, _FNCTN, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
