/***
 * @file    TIM.h
 * @author  zxy
 * @date    2023-01-17
*/

#ifndef _TIM_H_
#define _TIM_H_

#include "board.h"


//此枚举定义不允许用户修改
typedef enum    // 枚举ADC通道
{
    CTIM0_P34=0,    
	CTIM1_P35,    	
}CTIMN_enum;


/***
 * @enum    TIMN_enum
 * @brief   定时器枚举体
 * @date    2023-01-17
*/
typedef enum
{
    TIM_0,    
    TIM_1,    	
}TIMN_enum;


void pit_timer_ms(TIMN_enum tim_n, uint16 time_ms);


#endif // !_TIM_H_
