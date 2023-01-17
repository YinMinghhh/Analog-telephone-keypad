#include "board.h"

int32 sys_clk = 24000000;



/***
 * @brief	���ӳ�ʼ��
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
 * @brief	ʧ�����ж�
 * @date	2023-01-17
*/
void DisableGlobalIRQ(void){
	EA = 0;
}

/***
 * @brief	ʹ�����ж�
 * @date	2023-01-17
*/
void EnableGlobalIRQ(void){
	EA = 1;
}

