#ifndef _FSM_H_
#define _FSM_H_

#include "KeyBoard.h"
#include "DyDigiTube.h"
#include "Timer.h"

typedef enum {
    Enter_number = 0,   // 输入号码阶段
    Dail_wait,          // 等待接通阶段
    Put_through,        // 正在通话阶段
} FSM_STATES;

extern Timer CoolDown;

uint8   FSM_init(uint32 time);
void    FSM_service(DyDigiTube_4x2 *const THIS, KeyBoard_4x4 *const KeyBoard);






#endif // !_FSM_H_


