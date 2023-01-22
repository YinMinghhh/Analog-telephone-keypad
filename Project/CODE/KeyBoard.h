/***
 * @file    Keyboard.h
 * @author  zxy
 * @date    2023-01-17
*/

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "common.h"
#include "Timer.h"

/***
 * P0 ~ P7 依次连接 H1 ~ H4, L1 ~ L4
 * 详见工程 README.md 文档内的 "矩阵键盘配置"
*/
#define key_4x4_pin P1

/***
 * @enum    ButtonName
 * @brief   按钮名枚举体
 * @date    2023-01-18
*/
typedef enum {
    zero = 0,   // 0
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,       // 9

    asterisk,   // *
    pound,      // #

    Dail,       // 拨号(好像座机电话没有拨号键?)
    Hang,       // 挂断
    Backspace,  // 退格(好像座机也没有退格?)
    Redial,     // 重拨(重拨上一次的电话, 如果有记录的话)

    NONE,       // 没有按键被按下

    DEFAULT,    // 意外情况
} ButtonName;

/***
 * @struct  KeyBoard_4x4
 * @brief   一个 4x4 大小的矩阵键盘对象
 * @date    2023-01-18
*/
typedef struct {
    uint8   _key_save_read_data;
    uint8   _count;     // 用于计数消抖
    uint8   _flag;      // 用于防止重入
    ButtonName  _last_button;

    ButtonName  button_na;  // 按键状态
    uint8   enable;     // 初始化时置为1
} KeyBoard_4x4;

uint8   KeyBoard_4x4_init(KeyBoard_4x4 *const THIS);
uint8  _KeyBoard_4x4_read(KeyBoard_4x4 *const THIS);
ButtonName  KeyBoard_4x4_scan(KeyBoard_4x4 *const THIS);




#endif // !_KEYBOARD_H_