/*
 * HHKB Layout
 */
#include "keymap_common.h"
#include "avr/xprintf.h"
#include "mousekey.h"
#include "wait.h"
#include <stdlib.h>


#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |LY1|
     * `-----------------------------------------------------------'
     *       |Alt|Gui  |         Space         |Gui  |Alt|
     *       `-------------------------------------------'
     */
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,   \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,       \
           LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,             \
           LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN10,             \
                LALT,LGUI,          SPC,                RGUI,RALT),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Quit| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow| LY3  |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |LY2|
     *       `-------------------------------------------'
     */
    KEYMAP(FN13, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,   \
           CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS, UP, TRNS, BSPC,      \
           TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT,            \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,FN9,TRNS,            \
                TRNS,TRNS,          TRNS,               TRNS,FN8),

    /* Layer 2: Mouse mode
     * ,-----------------------------------------------------------.
     * |Quit|   |   |   |   |   |   |   |   |   |   |   |   |   |  |
     * |-----------------------------------------------------------|
     * |     |UL |   |   |   |   |W_L|W_D|W_U|W_R|UR |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |SLO|MED|FAS|LEF|DOW|UP |RIG|   |   |        |
     * |-----------------------------------------------------------|
     * |        |DL |   |   |   |   |   |B_1|B_2|B_3|DR | LY3  |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |LY2|
     *       `-------------------------------------------'
     */
    KEYMAP(FN13,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
           TRNS,FN18,TRNS,TRNS,TRNS,TRNS,MS_WH_LEFT,MS_WH_DOWN,MS_WH_UP,MS_WH_RIGHT,FN19, TRNS, TRNS, TRNS,      \
           TRNS,TRNS,TRNS,MS_ACCEL0,MS_ACCEL1,MS_ACCEL2,MS_LEFT,MS_DOWN,MS_UP,MS_RIGHT,TRNS,TRNS,TRNS,            \
           TRNS,FN20,TRNS,TRNS,TRNS,TRNS,TRNS,MS_BTN1,MS_BTN2, MS_BTN3,FN21,FN9,TRNS,            \
                TRNS,TRNS,          TRNS,               TRNS,FN8),

    /* Layer 3: Macro mode
     * ,-----------------------------------------------------------.
     * |Quit|   | @ |   |   |   |   |   |   |   |   |   |   |   |  |
     * |-----------------------------------------------------------|
     * |PLAY |REC|   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |PLAYONCE|
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   | LY3  |FN |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |LY2|
     *       `-------------------------------------------'
     */
    KEYMAP(FN13,NO,FN14,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,   \
           FN16,FN15,NO,NO,NO,NO,NO,NO,NO,NO,NO, NO, NO, NO,      \
           NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,FN17,            \
           NO,NO,NO,NO,NO,NO,NO,NO,NO, NO,NO,FN9,TRNS,            \
                NO,NO,          NO,               NO,FN8),
};


enum macro_id {
  EMAIL,
};

enum function_id {
  RECORD,
  PLAY,
  PLAYONCE,
  MOUSE_LEFTTOP,
  MOUSE_RIGHTTOP,
  MOUSE_LEFTDOWN,
  MOUSE_RIGHTDOWN,
};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0]  = ACTION_LAYER_MOMENTARY(1),
    [1]  = ACTION_LAYER_MOMENTARY(2),
    [2]  = ACTION_LAYER_MOMENTARY(3),
    [3]  = ACTION_LAYER_MOMENTARY(4),
    [4]  = ACTION_LAYER_MOMENTARY(5),
    [5]  = ACTION_LAYER_MOMENTARY(6),
    [6]  = ACTION_LAYER_MOMENTARY(7),
    [7]  = ACTION_LAYER_TOGGLE(1),
    [8]  = ACTION_LAYER_ON(2, ON_PRESS),
    [9]  = ACTION_LAYER_ON(3, ON_PRESS),
    [10] = ACTION_LAYER_TAP_TOGGLE(1),
    [11] = ACTION_LAYER_TAP_TOGGLE(2),
    [12] = ACTION_LAYER_TAP_TOGGLE(3),
    [13] = ACTION_LAYER_SET_CLEAR(0),
    [14] = ACTION_MACRO(EMAIL),
    [15] = ACTION_FUNCTION(RECORD),
    [16] = ACTION_FUNCTION(PLAY),
    [17] = ACTION_FUNCTION(PLAYONCE),
    [18] = ACTION_FUNCTION(MOUSE_LEFTTOP),
    [19] = ACTION_FUNCTION(MOUSE_RIGHTTOP),
    [20] = ACTION_FUNCTION(MOUSE_LEFTDOWN),
    [21] = ACTION_FUNCTION(MOUSE_RIGHTDOWN),
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case EMAIL:
      return (record -> event.pressed ?
          MACRO(I(0), SM(), CM(), T(S), T(T), T(O), T(N), T(E), T(K), T(Y), T(X), ST(2), T(G), T(M), T(A), T(I), T(L), T(DOT), T(C), T(O), T(M), RM(), END) :
          MACRO_NONE);
      break;
  }
  return MACRO_NONE;
}

static packed_report **records = NULL;
static uint8_t record_size = 0;

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  uint8_t i;
  switch (id) {
    case RECORD:
      if (!record->event.pressed) {
        break;
      }
      if (records) {
        while (record_size) {
          free(records[--record_size]);
        }
        free(records);
      }
      if (records = get_records()) {
        record_size = get_record_size();
        end_recording();
        xprintf("Got %u records\n", record_size);
      } else {
        start_recording();
        xprintf("Start recording...\n");
      }
      layer_clear();
      break;
    case PLAYONCE:
    case PLAY:
      if (!record->event.pressed) {
        break;
      }
      if (records) {
        play_records(records, record_size);
      }
      if (id == PLAYONCE) {
        layer_clear();
      }
      break;
    case MOUSE_LEFTTOP:
      for (i = 0; i < 10; i++) {
        mousekey_move(0, -MOUSEKEY_MOVE_MAX);
        wait_ms(1);
      }
      for (i = 0; i < 30; i++) {
        mousekey_move(-MOUSEKEY_MOVE_MAX, 0);
        wait_ms(1);
      }
      break;
    case MOUSE_RIGHTTOP:
      for (i = 0; i < 10; i++) {
        mousekey_move(0, -MOUSEKEY_MOVE_MAX);
        wait_ms(1);
      }
      for (i = 0; i < 30; i++) {
        mousekey_move(MOUSEKEY_MOVE_MAX, 0);
        wait_ms(1);
      }
      break;
    case MOUSE_LEFTDOWN:
      for (i = 0; i < 10; i++) {
        mousekey_move(0, MOUSEKEY_MOVE_MAX);
        wait_ms(1);
      }
      for (i = 0; i < 30; i++) {
        mousekey_move(-MOUSEKEY_MOVE_MAX, 0);
        wait_ms(1);
      }
      break;
    case MOUSE_RIGHTDOWN:
      for (i = 0; i < 10; i++) {
        mousekey_move(0, MOUSEKEY_MOVE_MAX);
        wait_ms(1);
      }
      for (i = 0; i < 30; i++) {
        mousekey_move(MOUSEKEY_MOVE_MAX, 0);
        wait_ms(1);
      }
      break;
  }
}
