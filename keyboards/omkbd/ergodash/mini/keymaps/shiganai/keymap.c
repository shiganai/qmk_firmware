#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY,
    _NUMBR,
    _FNCTN,
    _ADJUST,
    _MacQWERTY,
    _MacNUMBR,
    _MacFNCTN,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  ADJUST,
  Tg_IME,
  KC_WLC,   //Windows-Like Control. Basically work as LGUI(Command). When arrow button pressed, work as Ctrl.
  MC_LEFT,	//Left arrow working with KC_WLC
  MC_RGHT,	//Right arrow working with KC_WLC
  MC_UP,	  //Up arrow working with KC_WLC
  MC_DOWN,	//Down arrow working with KC_WLC
};

#define EISU LALT(KC_GRV)

#define NUMBR MO(_NUMBR)
#define FNCTN MO(_FNCTN)
#define SwMac DF(_MacQWERTY)	//Toggle on Mac QWERTY
#define SwWin DF(_QWERTY)	//Toggle on Win QWERTY
#define McNUM MO(_MacNUMBR)	//Toggle on Mac Number
#define McFUN MO(_MacFNCTN)	//Toggle on Mac Function

#define MC_HOME LGUI(KC_LEFT)	//Home for Mac
#define MC_END LGUI(KC_RGHT)	//End for Mac
#define MC_PGUP LGUI(KC_UP)	//PageUP for Mac
#define MC_PGDN LGUI(KC_DOWN)	//PageDown for Mac


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   /  |                    |   =  |   H  |   J  |   K  |   L  |   ;  |  '   |
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
   * |   ~  |   1  |   2  |   3  |   4  |   5  |   ?  |                    |   =  |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | CAPSL|                    |Delete|   N  |   M  |   ,  |   .  |PageUp| Bksp |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt |Tg_IME|||||||| Fnctn| Space|   -  |||||||| Shift| Enter| Numbr|||||||| Menu | Home |PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_NUMBR] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_QUES,                        KC_EQL , KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_DQUO,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_CAPS,                        KC_DEL , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_PGUP, KC_BSPC,
    KC_LCTL, KC_LGUI, KC_LALT, EISU,             FNCTN,   KC_SPC ,KC_MINS,        KC_RSFT,KC_ENT , NUMBR,            KC_APP , KC_HOME, KC_PGDN, KC_END
  ),

  /* Fnctn
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | SwMac|   F1 |   F2 |   F3 |   F4 |   F5 |   ?  |                    |   =  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 | CAPSL|                    |Delete|   N  |   M  |   ,  |   .  |PageUp| Bksp |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  F11 |  F12 | SwWin|||||||| Fnctn| Space|   -  |||||||| Shift| Enter| Numbr|||||||| Menu | Home |PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_FNCTN] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    SwMac,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_QUES,                        KC_EQL , KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_DQUO,
    KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_CAPS,                        KC_DEL , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_PGUP, KC_BSPC,
    KC_LCTL, KC_F11 , KC_F12,  SwWin,            FNCTN,   KC_SPC ,KC_MINS,        KC_RSFT,KC_ENT , NUMBR,            KC_APP , KC_HOME, KC_PGDN, KC_END
    ),

  /* MacQWERTY	
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   /  |                    |   =  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | CAPSL|                    |Delete|   N  |   M  |   ,  |   .  |  Up  | Bksp |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt |Tg_IME|||||||| Fnctn| Space|   -  |||||||| Shift| Enter| Numbr|||||||| Menu | Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_MacQWERTY] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_SLSH,                        KC_EQL , KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_CAPS,                        KC_DEL , KC_N,    KC_M,    KC_COMM, KC_DOT,  MC_UP  , KC_BSPC,
    KC_WLC , KC_LCTL, KC_LALT, Tg_IME,           McFUN,   KC_SPC, KC_MINS,        KC_RSFT,KC_ENT , McNUM,            KC_APP , MC_LEFT, MC_DOWN, MC_RGHT
  ),
  
  // NOTE: Need to duplicate Number and Function layers for Mac because the original ones won't be activated via _MacBase layer.

  /* MacNumbr
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ~  |   1  |   2  |   3  |   4  |   5  |   ?  |                    |   =  |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | CAPSL|                    |Delete|   N  |   M  |   ,  |   .  |PageUp| Bksp |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt |Tg_IME|||||||| Fnctn| Space|   -  |||||||| Shift| Enter| Numbr|||||||| Menu | Home |PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_MacNUMBR] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_QUES,                        KC_EQL , KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_DQUO,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_CAPS,                        KC_DEL , KC_N,    KC_M,    KC_COMM, KC_DOT,  MC_PGUP, KC_BSPC,
    KC_LGUI, KC_LCTL, KC_LALT, Tg_IME,           McFUN,   KC_SPC ,KC_MINS,        KC_RSFT,KC_ENT , McNUM,            KC_APP , MC_HOME, MC_PGDN, MC_END
  ),

  /* MacFnctn
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | SwMac|   F1 |   F2 |   F3 |   F4 |   F5 |   ?  |                    |   =  |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 | CAPSL|                    |Delete|   N  |   M  |   ,  |   .  |PageUp| Bksp |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  F11 |  F12 | SwWin|||||||| Fnctn| Space|   -  |||||||| Shift| Enter| Numbr|||||||| Menu | Home |PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_MacFNCTN] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    SwMac,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_QUES,                        KC_EQL , KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_DQUO,
    KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_CAPS,                        KC_DEL , KC_N,    KC_M,    KC_COMM, KC_DOT,  MC_PGUP, KC_BSPC,
    KC_LCTL, KC_F11 , KC_F12,  SwWin,            McFUN,   KC_SPC ,KC_MINS,        KC_RSFT,KC_ENT , McNUM,            KC_APP , MC_HOME, MC_PGDN, MC_END
    ),
};

static bool IME = false;

static bool WLC = false;
#define default_WLC KC_LGUI
#define RLarrow_special_WLC KC_LALT

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    
    // For Mac IME
    case Tg_IME:
      if (record->event.pressed) {
        if (IME) {
          register_code(KC_LNG1);
        } else {
          register_code(KC_LNG2);
        }
        
      } else {
        if (IME) {
          unregister_code(KC_LNG1);
        } else {
          unregister_code(KC_LNG2);
        }
        IME = !IME;
      }
      return false;
      break;
  
    // For Mac Arrow Key Customize
    case KC_WLC:
      if (record->event.pressed) {
        // Turn on WLC flag so that MC_LEFT and MC_RGHT is aware of which action to take.
        // Also turn on Command(LGUI) as default_WLC
      	WLC = true;
        register_code(default_WLC);
      } else {
        WLC = false;
        unregister_code(default_WLC);
      }
      return false;
      break;
      
    case MC_LEFT:
      if (record->event.pressed) {
        if (WLC) {
          unregister_code(default_WLC);
          register_code(RLarrow_special_WLC);
        }
        register_code(KC_LEFT);
      } else {
        unregister_code(KC_LEFT);
        if (WLC) {
          unregister_code(RLarrow_special_WLC);
          register_code(default_WLC);
        }
      }
      return false;
      break;
      
    case MC_RGHT:
      if (record->event.pressed) {
        if (WLC) {
          unregister_code(default_WLC);
          register_code(RLarrow_special_WLC);
        }
        register_code(KC_RGHT);
      } else {
        unregister_code(KC_RGHT);
        if (WLC) {
          unregister_code(RLarrow_special_WLC);
          register_code(default_WLC);
        }
      }
      return false;
      break;
      
    case MC_UP:
      if (record->event.pressed) {
        if (WLC) {
          unregister_code(default_WLC);
        }
        register_code(KC_UP);
      } else {
        unregister_code(KC_UP);
        if (WLC) {
          register_code(default_WLC);
        }
      }
      return false;
      break;
      
    case MC_DOWN:
      if (record->event.pressed) {
        if (WLC) {
          unregister_code(default_WLC);
        }
        register_code(KC_DOWN);
      } else {
        unregister_code(KC_DOWN);
        if (WLC) {
          register_code(default_WLC);
        }
      }
      return false;
      break;
  }
  return true;
}
