#include "UART.h"

void UartInit(void)		//2400bps@12.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF3;			//设置定时初始值
	TH1 = 0xF3;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
}


void SendByte(uint8 dat){
	SBUF = dat;
	while(!TI);
	TI = 0;
}
