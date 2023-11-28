#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D, KC_UP,
        KC_1, KC_2, KC_3, KC_4, KC_DOWN
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

//#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise){
    keypos_t key;
    if(index==0){
        if(clockwise){
            key.row=4,key.col=0;
        }else{
            key.row=9,key.col=0;
        }
        tap_code(keymap_key_to_keycode(layer_switch_get_layer(key),key));
    }
    return false;
};
//#endif
