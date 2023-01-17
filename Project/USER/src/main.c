#include "TIM.h"
#include "UART.h"
#include <stdio.h>

/***
 * @brief   程序入口
 * @author  zxy
 * @date    2023-01-17
 * 
 * @note    1.CPU外部晶振12MHz
 * @note    2.烧录时选择12T不加倍
 * @note    3.定时器0中断周期10ms
 * @note    4.串口通讯UART波特率2400
*/
void main(){
    sys_clk = 12000000;
    board_init();           // 板子初始化并关闭总中断
    pit_timer_ms(TIM_0, 10); // 定时器0中断初始化
    UartInit();
    printf("SYSclk:12M\r\nTIM0_PIT:10ms\r\nUART_BAUD:2400\r\n");

    EnableGlobalIRQ();      // 打开总中断

    while(1){
        ;
    }
}

