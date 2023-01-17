#ifndef _UART_H_
#define _UART_H_

#include "board.h"
#include "TIM.h"

void UartInit(void);
void SendByte(uint8 dat);

#endif // !_UART_H_
