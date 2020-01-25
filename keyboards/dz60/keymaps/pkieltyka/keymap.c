#include QMK_KEYBOARD_H
#include "dz60.h"

// Macros
#define ______ 					KC_TRNS
#define _FN_LAYER				2 // number where fn layer exists

// Tap Dance Definitions
typedef enum {
  SINGLE_TAP  = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP  = 3
} td_state_t;

static td_state_t td_state;

enum {
  FN_DANCE_LAYR = 0     // Our custom tap dance key; add any other tap dance keys to this enum 
};

// Function associated with all tap dances
int cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

//
// Keymaps
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	// layer-0
	LAYOUT_directional(
		KC_GESC, 	KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5, 		KC_6, 		KC_7, 		KC_8, 		KC_9, 							KC_0, 		KC_MINS, 		KC_EQL, 	KC_BSPC, 		KC_BSPC,
		KC_TAB,		KC_Q,			KC_W,			KC_E,			KC_R,			KC_T,			KC_Y,			KC_U,			KC_I,			KC_O,								KC_P,			KC_LBRC,		KC_RBRC,	KC_BSLS,
		KC_LGUI,	KC_A,			KC_S,			KC_D,			KC_F,			KC_G,			KC_H,			KC_J,			KC_K,			KC_L,								KC_SCLN,	KC_QUOT,		KC_ENT,
		KC_LSFT,	KC_Z,			KC_X,			KC_C,			KC_V,			KC_B,			KC_N,			KC_M,			KC_COMM,	KC_DOT,							KC_SLSH,	KC_PGUP,		KC_UP,		KC_PGDN,
		KC_LCTL,	KC_LALT,	KC_RCTL,						KC_NO,		KC_SPC,							KC_NO,							TD(FN_DANCE_LAYR),	KC_RCTL,	KC_LEFT,		KC_DOWN, 	KC_RGHT
	),
	
	// layout-1 -- macos
	LAYOUT_directional(
		______, 	______, 	______, 	______, 	______, 	______, 	______, 	______, 		______, 	______, 	______, 	______, 	______, 	______, 		______,
		______,		______,		______,		______,		______,		______,		______,		______,			______,		______,		______,		______,		______,		______,
		______,		______,		______,		______,		______,		______,		______,		______,			______,		______,		______,		______,		______,
		______,		______,		______,		______,		______,		______,		______,		______,			______,		______,		______,		______,		______,		______,
		______,		______,		KC_LCMD,						KC_NO,		______,							KC_NO,								______,		______,		______,		______, 	______
	),

	// layer-2 -- fn keys
	LAYOUT_directional(
		______, 	KC_F1, 		KC_F2, 		KC_F3, 		KC_F4, 		KC_F5, 		KC_F6, 		KC_F7, 		KC_F8, 		KC_F9, 			KC_F10, 	KC_F11, 	KC_F12, 	______, 		KC_DEL,
		______,		TO(0),		TO(1),		______,		______,		______,		______,		______,		______,		______,			______,		______,		______,		______,
		______,		______,		______,		______,		______,		______,		______,		______,		______,		______,			______,		______,		______,
		______,		______,		______,		______,		______,		______,		______,		______,		______,		______,			______,		______,		______,		______,
		______,		______,		______,							KC_NO,		______,							KC_NO,							______,			______,		______,		______, 	______
	)

};


// Determine the current tap dance state
int cur_dance(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD; 
    }
  }
	if (state->count == 2) {
    return DOUBLE_TAP;
  } else {
    return 8;
  }
}

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP: 
      register_code16(KC_LGUI);
      break;
    case SINGLE_HOLD: 
      register_code16(KC_LGUI);
      break;
    case DOUBLE_TAP: 
      layer_on(_FN_LAYER);
      break;
  }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
	switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_LGUI);
      break;
    case SINGLE_HOLD:
			unregister_code16(KC_LGUI);
      break;
    case DOUBLE_TAP:
			layer_off(_FN_LAYER);
      break;
  }
  td_state = 0;
}

//Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
  [FN_DANCE_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 200)
};
