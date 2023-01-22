#ifndef _FSM_H_
#define _FSM_H_

#include "KeyBoard.h"
#include "DyDigiTube.h"
#include "Timer.h"

// typedef struct {
//     ButtonName  last_button;
// } KeyBoardCooldown;

// uint8 KeyBoardCooldown_init(KeyBoardCooldown *const THIS);

extern Timer CoolDown;

void    FSM_init(uint32 time);
void    FSM_service(DyDigiTube_4x2 *const THIS, KeyBoard_4x4 *const KeyBoard);






#endif // !_FSM_H_


