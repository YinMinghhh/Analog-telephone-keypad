#include "UART.h"
#include <stdlib.h>

sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit LED3 = P2^2;
sbit LED4 = P2^3;

void TM0_Isr() interrupt 1 {
	static uint16 i = 0;
	i += 10;
	if(i == 1000){
		i = 0;
		LED1 = !LED1;
		SendByte('F');
	}
}

void UART1_Routine(void) interrupt 4 {
    uint8 res;
    RI = 0;
	res = SBUF;	//存储接收到的数据

	LED2 = !LED2;
	
	SBUF = res;	//将接收到的数据放入到发送寄存器
	while(!TI);		//等待发送数据完成
	TI=0;			//清除发送完成标志位		
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
