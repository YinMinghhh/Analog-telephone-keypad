#include "FSM.h"

Timer Redail_Cool_down;
Timer Dail_Wait_time;

FSM_TRANSITION code FSM_transition[FSM_CAP_OF_TRANSITION] = {
    {Enter_number,  _FSM_tra_Enter_DailW, Dail_wait     },
    {Dail_wait,     _FSM_tra_DailW_PutTh, Put_through   },
    {Dail_wait,     _FSM_tra_DailW_Enter, Enter_number  },
    {Dail_wait,     _FSM_tra_DailW_RedaW, Redail_wait   },
    {Put_through,   _FSM_tra_PutTh_Enter, Enter_number  },
    {Redail_wait,   _FSM_tra_RedaW_Enter, Enter_number  },
    {Redail_wait,   _FSM_tra_RedaW_PutTh, Put_through   },
    {Redail_wait,   _FSM_tra_RedaW_DailW, Dail_wait     },
};

/***
 * @brief   号码输入 转 等待接通
 * @date    2023-02-10
*/
uint8 _FSM_tra_Enter_DailW() {
    if (key_board.button_na == Dail) {
        if (dy_digital_tube._full == 1) {
            DyDigiTube_4x2_Dail(&dy_digital_tube);
            return 1;
        }   
    }
    return 0;
}

/***
 * @brief   等待接通 转 正在通话
 * @date    2023-02-10
*/
uint8 _FSM_tra_DailW_PutTh() {
    if (uart_receive == 0x01) { // Put_Through
        uart_receive = 0xFF;
        return 1;
    }
    return 0;
}

/***
 * @brief   等待接通 转 号码输入
 * @date    2023-02-10
*/
uint8 _FSM_tra_DailW_Enter() {
    if (key_board.button_na == Hang) {
        printf("你挂断电话.\r\n");
        DyDigiTube_4x2_Hang(&dy_digital_tube);
        return 1;
    }
    return 0;
}

/***
 * @brief   正在通话 转 号码输入
 * @date    2023-02-10
*/
uint8 _FSM_tra_PutTh_Enter() {
    if (uart_receive == 0x00) {
        printf("对方已挂断.\r\n");
        DyDigiTube_4x2_Hang(&dy_digital_tube);
        return 1;
    }
    else if (key_board.button_na == Hang) {
        printf("你已经挂断.\r\n");
        DyDigiTube_4x2_Hang(&dy_digital_tube);
        return 1;
    }

    return 0;
}


/***
 * @brief   等待接通 转 等待重拨
 * @date    2023-02-10
*/
uint8 _FSM_tra_DailW_RedaW() 
{
    if (uart_receive == 0x00) {
        printf("被对方拒绝!\r\n");
        uart_receive = 0xFF;
        return 1;
    }
    else if (Timer_judge(&Dail_Wait_time))
    {
        printf("对方未应答!\r\n");
        return 1;
    }
    return 0;
}

/***
 * @brief   等待重拨 转 号码输入
 * @date    2023-02-10
*/
uint8 _FSM_tra_RedaW_Enter() 
{
    if (key_board.button_na == Hang) {
        DyDigiTube_4x2_Hang(&dy_digital_tube);
        printf("你取消了重播计划!\r\n");
        return 1;
    }
    return 0;
}

/***
 * @brief   等待重拨 转 正在通话
 * @date    2023-02-10
*/
uint8 _FSM_tra_RedaW_PutTh() 
{
    if (uart_receive == 0x01) {
        uart_receive = 0xFF;
        return 1;
    }
		return 0;
}

/***
 * @brief   等待重拨 转 等待接通
 * @date    2023-02-10
*/
uint8 _FSM_tra_RedaW_DailW()
{
    if (key_board.button_na == Redial)
    {
        printf("正在重拨...\r\n");
        return 1;
    }
    else if (Timer_judge(&Redail_Cool_down)) {
        printf("正在重拨...\r\n");
        return 1;
    }
    return 0;
}


