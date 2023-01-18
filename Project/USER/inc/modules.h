#ifndef _MODULES_H
#define _MODULES_H 

#include "TIM.h"
#include "UART.h"
#include "KeyBoard.h"
#include "DyDigiTube.h"

extern KeyBoard_4x4 key_board;
extern DyDigiTube_4x2 dy_digital_tube;

void modules_init();






#endif // !_MODULES_H
