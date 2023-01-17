#ifndef _TIM_H_
#define _TIM_H_

#include "board.h"

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
