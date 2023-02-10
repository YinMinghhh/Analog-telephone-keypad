#include "FSM.h"

Timer keyboard_CoolDown;
FSM_STATES  curr_state = Enter_number;
FSM_STATES  last_state = Default;

void FSM_OPERATION() {
    uint8 i = 0x00;
    for(; i < FSM_CAP_OF_ACTIONS; i++) {
        if (curr_state == FSM_actions[i].work_mode) {
            if (last_state != curr_state) {
                FSM_actions[i].init();
                last_state = curr_state;
            }
            _FSM_act_GLOABLE_loop();
            FSM_actions[i].loop();
            _FSM_MODE_TRANS_();
            break;
        }
    }
}

void _FSM_MODE_TRANS_() {
    uint8 i = 0x00;
    for(; i < FSM_CAP_OF_TRANSITION; i++) {
        if (curr_state == FSM_transition[i].start_sate) {
            if (FSM_transition[i].check()) {
                curr_state = FSM_transition[i].next_state;
                break;
            }
        }
    }
}

/***
 * @brief   有限状态机全局初始化
 * @param   time1   键盘冷却时间, 默认 100 ms 即可
 * @param   time2   等待重拨的时间, 题目要求 60000 ms
 * @param   time3   拨号最长等待时间
 * @date    2023-02-10
*/
void _FSM_act_GLOABLE_init(uint32 time1, uint32 time2, uint32 time3)
{
    Timer_init(&keyboard_CoolDown, time1);
    Timer_init(&Redail_Cool_down, time2);
    Timer_init(&Dail_Wait_time, time3);
}

/***
 * @brief   有限状态机全局动作
 * @date    2023-02-10
*/
void _FSM_act_GLOABLE_loop()
{
    KeyBoard_4x4_scan(&key_board);
    _nop_();_nop_();_nop_();_nop_();
    _nop_();_nop_();_nop_();_nop_();
}
