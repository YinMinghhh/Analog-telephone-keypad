/***
 * @file    TIM.c
 * @author  zxy
 * @date    2023-01-17
*/

#include "TIM.h"

/***
 * @brief   定时器中断 初始化
 * @param   tim_n   定时器通道
 * @param   time_ms 中断周期, 单位ms
 * @date    2023-01-17
 * Sample Uasge : 
 *      pit_timer_ms(TIM_0, 5); // 初始化定时器0中断, 5ms运行一次
*/
void pit_timer_ms(TIMN_enum tim_n, uint16 time_ms)
{
	uint16 temp;
	temp = (uint16)65536 - (uint16)(sys_clk / (12 * (1000 / time_ms)));
	
	if(TIM_0 == tim_n)
	{
		TMOD |= 0x00; 	// 模式 0
		TL0 = temp; 	
		TH0 = temp >> 8;
		TR0 = 1; 		// 启动定时器
		ET0 = 1; 		// 使能定时器中断
	}
	else if(TIM_1 == tim_n)
	{
		TMOD |= 0x00; // 模式 0
		TL1 = temp; 	
		TH1 = temp >> 8;
		TR1 = 1; // 启动定时器
		ET1 = 1; // 使能定时器中断
	}
}
