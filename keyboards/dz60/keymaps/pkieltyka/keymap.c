#include QMK_KEYBOARD_H
#include "dz60.h"

// Macros
#define ______ 				KC_TRNS
#define KC_SUPERL 		MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI

// Tap Dance Definitions
//#define TAPPING_TOGGLE 2

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for super, double tap for fn layer
  [0]  = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_F) //MO(2))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	// layer-0
	LAYOUT_directional(
		KC_GESC, 	KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5, 		KC_6, 		KC_7, 		KC_8, 		KC_9, 					KC_0, 		KC_MINS, 		KC_EQL, 	KC_BSPC, 		KC_BSPC,
		KC_TAB,		KC_Q,			KC_W,			KC_E,			KC_R,			KC_T,			KC_Y,			KC_U,			KC_I,			KC_O,						KC_P,			KC_LBRC,		KC_RBRC,	KC_BSLS,
		KC_HYPR,	KC_A,			KC_S,			KC_D,			KC_F,			KC_G,			KC_H,			KC_J,			KC_K,			KC_L,						KC_SCLN,	KC_QUOT,		KC_ENT,
		KC_LSFT,	KC_Z,			KC_X,			KC_C,			KC_V,			KC_B,			KC_N,			KC_M,			KC_COMM,	KC_DOT,					KC_SLSH,	KC_PGUP,		KC_UP,		KC_PGDN,
		KC_LCTL,	KC_LALT,	KC_RCTL,						KC_NO,		KC_SPC,							KC_NO,							TD(0),					KC_RCTL,	KC_LEFT,		KC_DOWN, 	KC_RGHT
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


