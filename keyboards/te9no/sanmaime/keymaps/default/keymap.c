#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ ~ │BS │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐ └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
     * │ Tab │ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ ; │ ' │ Enter  │
     * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┬───┤
     * │ Shift │ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ / │ S │ ↑ │L1 │
     * ├────┬──┴─┬─┴──┬┴───┴┬──┴──┬┘  ┌┴───┴┬──┴─┬─┴──┬┴───┼───┼───┼───┤
     * │Ctrl│GUI │Alt │ Spc │ Spc │   │ Spc │Spc │Alt │menu│ ← │ ↓ │ → │
     * └────┴────┴────┴─────┴─────┘   └─────┴────┴────┴────┴───┴───┴───┘
     * Push: 上:↑ 下:↓    左:← 右:→            左:PgDn Push:Home 右:PgUp
     */
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_ESC,  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,               KC_SPC,  KC_RALT, KC_APP,  KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT,
        KC_W,    KC_UP,   KC_DOWN,          KC_LEFT, KC_RGHT,                                                  KC_PGDN, KC_HOME, KC_PGUP
    )
};

//#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise){
    keypos_t key;
    if(index==0){
        if(clockwise){
            key.row=5,key.col=1;
        }else{
            key.row=5,key.col=2;
        }
        tap_code(keymap_key_to_keycode(layer_switch_get_layer(key),key));
    }
    if(index==1){
        if(clockwise){
            key.row=5,key.col=3;
        }else{
            key.row=5,key.col=4;
        }
        tap_code(keymap_key_to_keycode(layer_switch_get_layer(key),key));
    }
    if(index==2){
        if(clockwise){
            key.row=11,key.col=5;
        }else{
            key.row=11,key.col=7;
        }
        tap_code(keymap_key_to_keycode(layer_switch_get_layer(key),key));
    }
    return false;
};
//#endif
