#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_CAPS,    KC_Q,      KC_W,       KC_E,       KC_R,       KC_T,      KC_ENT,      KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_TAB,     KC_A,      KC_S,       KC_D,       KC_F,       KC_G,                   KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
        KC_LSFT,    KC_Z,      KC_X,       KC_C,       KC_V,       KC_B,                   KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_UP,      KC_RSFT,
    LCTL_T(KC_ESC), KC_LGUI,   KC_LALT,  LT(2,KC_SPC), LT(1,KC_SPC),    KC_A,    KC_B,  LT(3,KC_SPC),  KC_RCTL,             KC_LEFT,    KC_DOWN,    KC_RGHT,     
        KC_UP,     KC_DOWN
    ),
    [1] = LAYOUT(
        KC_GRV,     KC_PGUP,    KC_UP,      KC_PGDN,    KC_HOME,    KC_TRNS,  KC_ENT,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL,
        KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_END,     KC_TRNS,               KC_F11,     KC_F12,     KC_TRNS,    KC_TRNS,    RGB_TOG,    KC_SCROLL_LOCK,
        KC_TRNS,    KC_BSPC,    KC_DEL,     KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_ENT,     KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_ENT,                 KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_VOLU,    KC_VOLD
    ),
    [2] = LAYOUT(
        KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,     KC_ENT,      KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_QUOT,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_SLSH,               KC_MINS,    KC_EQL,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_RALT,                KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS
    ),
    [3] = LAYOUT(
        KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,     KC_ENT,     KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_F11,     KC_F12,     KC_TRNS,    KC_TRNS,    RGB_TOG,    KC_SCROLL_LOCK,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_SLSH,               KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS
    )
};

//#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise){
    keypos_t key;
    if(index==0){
        if(clockwise){
            key.row=9,key.col=0;
        }else{
            key.row=9,key.col=1;
        }
        tap_code(keymap_key_to_keycode(layer_switch_get_layer(key),key));
    }
    return false;
};
//#endif

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
    0b11111110,
    0b11111101,
    0b11111011,
    0b11110111,
    0b11101111,
    0b11011111,
    0b10111111,
    0b01111111,
};