/***
 * @file    Keyboard.h
 * @author  zxy
 * @date    2023-01-17
*/

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "common.h"

#define key_4x4_pin P1
// #define enumToStr(NAME)  "\""#NAME"\""
// #define bit uint8

typedef enum {
    zero = 0,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,

    asterisk,
    pound,

    Dail,
    Hang,
    Backspace,
    Redial,

    DEFAULT,
} ButtonName;

typedef struct {
    uint8   _key_save_read_data;

    uint8   _count;
    uint8   _flag;

    ButtonName  button_na;
    uint8   enable;
} KeyBoard_4x4;

void    KeyBoard_4x4_init(KeyBoard_4x4 *const THIS);
uint8  _KeyBoard_4x4_read(KeyBoard_4x4 *const THIS);
ButtonName  KeyBoard_4x4_scan(KeyBoard_4x4 *const THIS);




#endif // !_KEYBOARD_H_