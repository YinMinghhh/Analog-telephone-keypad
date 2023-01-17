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
    void modules_init();
    sys_clk = 12000000;
    board_init();           // 基本寄存器初始化并关闭总中断
    modules_init();         // 外设初始化
    EnableGlobalIRQ();      // 打开总中断

    while(1){
        ;
    }
}

/***
 * @brief   外设初始化
 * @date    2023-01-17
*/
void modules_init(){
    pit_timer_ms(TIM_0, 10);    // 定时器0中断初始化
    UartInit();                 // 串口通讯初始化
    printf("SYSclk:12M\r\nTIM0_PIT:10ms\r\nUART_BAUD:2400\r\n");    // 打印基本信息
}
