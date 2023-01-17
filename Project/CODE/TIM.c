
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

//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器初始化作为外部计数
//  @param      tim_n           选择模块
//  @return     void
//  @since      v1.0
//  Sample usage:               ctimer_count_init(CTIM0_P34);		//初始化定时器0，外部输入为P3.4引脚
//  @note                       串口1使用定时器1作为波特率发生器，
//								串口2使用定时器2作为波特率发生器，
//								串口3使用定时器3作为波特率发生器，
//								串口4使用定时器4作为波特率发生器，
//                              STC16F仅有定时器0-定时器4，这5个定时器。
//								编码器采集数据也需要定时器作为外部计数。
//-------------------------------------------------------------------------------------------------------------------
void ctimer_count_init(CTIMN_enum tim_n)
{
	switch(tim_n)
	{
		case CTIM0_P34:
		{
			TL0 = 0; 
			TH0 = 0; 
			TMOD |= 0x04; //外部计数模式
			TR0 = 1; //启动定时器
			break;
		}
		
		case CTIM1_P35:
		{
			TL1 = 0x00;
			TH1 = 0x00;
			TMOD |= 0x40; // 外部计数模式
			TR1 = 1; // 启动定时器
			break;
		}
	}	
} 
