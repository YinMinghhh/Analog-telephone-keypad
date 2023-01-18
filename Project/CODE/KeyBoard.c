/***
 * @file    KeBoard.c
 * @author  zxy
 * @date    2023-01-17
*/

#include "KeyBoard.h"

/***
 * @brief   |KeyBoard_4x4对象|
 *          初始化
 * @date    2023-01-18
*/
uint8 KeyBoard_4x4_init(KeyBoard_4x4 *const THIS) {
    THIS->_count = 0x01;
    THIS->_flag  = 1;
    THIS->button_na = DEFAULT;
    THIS->enable = 1;

    printf("KeyBoard_4x4_init_%d\r\n", THIS->_count);
    return 0;
}

/***
 * @brief   |KeyBoard_4x4对象|
 *          内部调用
 * @date    2013-01-18
*/
uint8 _KeyBoard_4x4_read(KeyBoard_4x4 *const THIS) {
    THIS->_key_save_read_data  = 0x00; // 清除数据, 0表示没有按键被按下
    key_4x4_pin = 0xF0;             // 检测高四位, 找出列号
    _nop_();_nop_();_nop_();_nop_();
    THIS->_key_save_read_data  = key_4x4_pin ^ 0xF0;    // 保留高四位数据, 如果有被按下的置1

    key_4x4_pin = 0x0F;             // 检测低四位, 找出行号
    _nop_();_nop_();_nop_();_nop_();
    THIS->_key_save_read_data += key_4x4_pin ^ 0x0F;    // 加上低四位数据, 给出被按下键的坐标
    return THIS->_key_save_read_data;
}

/***
 * @brief   |KeyBoard_4x4对象|
 *          扫描键盘
 *          并给出被按下的按键状态, 
 *          或者给出没有按键被按下的说明
 * @date    2023-01-18
*/
ButtonName KeyBoard_4x4_scan(KeyBoard_4x4 *const THIS) {
    if((_KeyBoard_4x4_read(THIS)) && THIS->_flag) {   // 有按键被按下 且 允许处理. 
    // 不要更换 && 左右内容的顺序, 以保证即使_flag为0时read函数仍会被执行. 
        if(++THIS->_count > 1) {    // 计数消抖
            switch(THIS->_key_save_read_data) { 
                // 按键处理, 从_key_save_read_data映射到实际
                case 0x11:  THIS->button_na = one;  break;
                case 0x21:  THIS->button_na = two;  break;
                case 0x41:  THIS->button_na = three;    break;
                case 0x81:  THIS->button_na = Dail; break;

                case 0x12:  THIS->button_na = four; break;
                case 0x22:  THIS->button_na = five; break;
                case 0x42:  THIS->button_na = six;  break;
                case 0x82:  THIS->button_na = Hang; break;

                case 0x14:  THIS->button_na = seven;    break;
                case 0x24:  THIS->button_na = eight;    break;
                case 0x44:  THIS->button_na = nine; break;
                case 0x84:  THIS->button_na = Backspace;    break;

                case 0x18:  THIS->button_na = asterisk; break;
                case 0x28:  THIS->button_na = zero; break;
                case 0x48:  THIS->button_na = pound;    break;
                case 0x88:  THIS->button_na = Redial;   break;

                default:    THIS->button_na = DEFAULT;  break;
            }
            THIS->_flag  = 0;   // 禁止再次进入按键处理
            THIS->_count = 0;   // 计数清零
        }
    }
    if (!THIS->_key_save_read_data) {   // 没有按键被按下
        THIS->_flag  = 1;       // 允许下次进入按键处理
        THIS->_count = 0;       // 计数清零
    }
    return  THIS->button_na;
}
