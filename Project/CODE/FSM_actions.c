#include "FSM.h"


FSM_ACTIONS code FSM_actions[FSM_CAP_OF_ACTIONS] = {
    {Enter_number,  _FSM_act_Enter_init, _FSM_act_Enter_loop},
    {Dail_wait,     _FSM_act_DailW_init, _FSM_act_DailW_loop},
    {Put_through,   _FSM_act_PutTh_init, _FSM_act_PutTh_loop},
    {Redail_wait,   _FSM_act_RedaW_init, _FSM_act_RedaW_loop},
};



/***
 * @brief   号码输入模式初始化
 * @date    2023-02-10
*/
void _FSM_act_Enter_init() {
    printf("现在可以输入号码:\r\n");
    return ;
}

/***
 * @brief  号码输入模式行为 
 * @date    2023-02-10
*/
void _FSM_act_Enter_loop() {
    if (Timer_judge(&keyboard_CoolDown)) {
        switch (key_board.button_na) {
            case zero:  DyDigiTube_4x2_push(&dy_digital_tube, DDT_zero);    break;
            case one:   DyDigiTube_4x2_push(&dy_digital_tube, DDT_one);     break;
            case two:   DyDigiTube_4x2_push(&dy_digital_tube, DDT_two);     break;
            case three: DyDigiTube_4x2_push(&dy_digital_tube, DDT_three);   break;
            case four:  DyDigiTube_4x2_push(&dy_digital_tube, DDT_four);    break;
            case five:  DyDigiTube_4x2_push(&dy_digital_tube, DDT_five);    break;
            case six:   DyDigiTube_4x2_push(&dy_digital_tube, DDT_six);     break;
            case seven: DyDigiTube_4x2_push(&dy_digital_tube, DDT_seven);   break;
            case eight: DyDigiTube_4x2_push(&dy_digital_tube, DDT_eight);   break;
            case nine:  DyDigiTube_4x2_push(&dy_digital_tube, DDT_nine);    break;

            case Backspace: DyDigiTube_4x2_popb(&dy_digital_tube);          break;

            case Hang:  DyDigiTube_4x2_Hang(&dy_digital_tube);              break;
            case Redial:DyDigiTube_4x2_Redail(&dy_digital_tube);            break;
            default:
                break;
        }
    }
    return ;
 
}

/***
 * @brief   等待接通模式初始化
 * @date    2023-02-10
*/
void _FSM_act_DailW_init() {
    Timer_reset(&Dail_Wait_time);
    printf("等待对方接受...\r\n");
    return ;
}

/***
 * @brief   等待接通模式行为
 * @date    2023-02-10
*/
void _FSM_act_DailW_loop() {
    return ;
}

/***
 * @brief   正在通话模式初始化
 * @date    2023-02-10
*/
void _FSM_act_PutTh_init() {
    printf("接通成功, 正在通话!\r\n");
    return ;
}

/***
 * @brief   正在通话模式行为
 * @date    2023-02-10
*/
void _FSM_act_PutTh_loop() {
    return ;
}

/***
 * @brief   等待重拨模式初始化
 * @date    2023-02-10
*/
void _FSM_act_RedaW_init()
{
    Timer_reset(&Redail_Cool_down);
    printf("接通失败, 将在 1 分钟后尝试重拨.\r\n按挂断键取消重拨计划. 按重拨键立即重拨.\r\n");
}

/***
 * @brief   等待重拨模式行为
 * @date    2023-02-10
*/
void _FSM_act_RedaW_loop()
{
    if (Timer_judge(&Redail_Cool_down)) 
    {
        DyDigiTube_4x2_Redail(&dy_digital_tube);
    }
}




