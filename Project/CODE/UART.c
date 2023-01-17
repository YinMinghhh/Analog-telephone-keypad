#include "UART.h"

/***
 * @brief	串口通讯初始化, 默认波特率2400
 * @date	2023-01-17
*/
void UartInit(void)		//2400bps@12.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF3;			//设置定时初始值
	TH1 = 0xF3;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时

	ES  = 1;			// 允许UART中断
}

/***
 * @brief	向串口发送一个字节
 * @date	2023-01-17
*/
void SendByte(uint8 dat){
	SBUF = dat;
	while(!TI);
	TI = 0;
}

/***
 * @brief	串口层面上的 putchar()
 * @date	2023-01-17
*/
int8 putchar(int8 dat){
	SendByte(dat);
	return dat;
}
