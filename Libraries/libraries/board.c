/***
 * @file    board.c
 * @author  zxy
 * @date    2023-01-17
*/

#include "board.h"

int32 code sys_clk = 24000000;

/***
 * @brief	板子初始化
 * 
 * @version	1.0
 * @date	2023-01-17
*/
void board_init(void){
	AUXR = 0;
	SCON = 0;
	TMOD = 0;
	DisableGlobalIRQ();
}

/***
 * @brief	失能总中断
 * @date	2023-01-17
*/
void DisableGlobalIRQ(void){
	EA = 0;
}

/***
 * @brief	使能总中断
 * @date	2023-01-17
*/
void EnableGlobalIRQ(void){
	EA = 1;
}

/***
 * @brief	使能看门狗
*/
void EnableWDT(void) {
	WDT_CONTR = 0x34;
}
