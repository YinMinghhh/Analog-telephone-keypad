/***
 * @file    isr.c
 * @brief	存放所有中断服务函数
 * @author  zxy
 * @date    2023-01-17
*/

#include "isr.h"
#include "board.h"
#include "modules.h"
#include "FSM.h"

uint8 uart_receive = 0xFF;

void TM0_Isr() interrupt 1 {
	// putchar('H');
	if((SYStim += 5) < 4294967000) {	// 约238小时
		FeedDog;
	}// 4294967295
	if (SYStim % 200 == 0) {
		if (uart_receive != 0xFF) {
			uart_receive = 0xFF;
		}
	}
	FSM_OPERATION();
}

/***
 * @brief	只负责接收数据
 * @date	2023-01-17
*/
void UART1_Routine(void) interrupt 4 {
    uint8 res;
    if(RI){	// receive
		RI = 0;
		res = SBUF;
	}
	// putchar(res);
	uart_receive = res;
}

//void INT0_Routine(void) interrupt 0
//void TM0_Rountine(void) interrupt 1
//void INT1_Routine(void) interrupt 2
//void TM1_Rountine(void) interrupt 3
//void UART1_Routine(void) interrupt 4
//void ADC_Routine(void) interrupt 5
//void LVD_Routine(void) interrupt 6
//void PCA_Routine(void) interrupt 7
//void UART2_Routine(void) interrupt 8
//void SPI_Routine(void) interrupt 9
//void INT2_Routine(void) interrupt 10
//void INT3_Routine(void) interrupt 11
//void TM2_Routine(void) interrupt 12
//void INT4_Routine(void) interrupt 16
//void UART3_Routine(void) interrupt 17
//void UART4_Routine(void) interrupt 18
//void TM3_Routine(void) interrupt 19
//void TM4_Routine(void) interrupt 20
//void CMP_Routine(void) interrupt 21
//void PWM0_Routine(void) interrupt 22
//void PWM0FD_Routine(void) interrupt 23
//void I2C_Routine(void) interrupt 24
//void PWM1_Routine(void) interrupt 28
//void PWM2_Routine(void) interrupt 29
//void PWM3_Routine(void) interrupt 30
//void PWM4_Routine(void) interrupt 31
//void PWM5_Routine(void) interrupt 32
//void PWM2FD_Routine(void) interrupt 33
//void PWM4FD_Routine(void) interrupt 34
//void TKSU_Routine(void) interrupt 35
