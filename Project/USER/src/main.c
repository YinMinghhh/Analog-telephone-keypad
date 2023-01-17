#include "TIM.h"
#include "UART.h"


/***
 * @brief   程序入口
 * @author  zxy
 * @date    2023-01-17
*/
void main(){
    sys_clk = 24000000;
    board_init();           // 板子初始化并关闭总中断
    pit_timer_ms(TIM_0, 10); // 定时器0中断初始化

    UartInit();
    // UartInit();

    EnableGlobalIRQ();      // 打开总中断

    while(1){
        ;
    }
}

