#include "modules.h"


KeyBoard_4x4 key_board;
DyDigiTube_4x2 dy_digital_tube;

// Timer same_key_timer;
// Timer diff_key_timer;

/***
 * @brief   外设初始化
 * @date    2023-01-17
*/
void modules_init(){
    pit_timer_ms(TIM_0, 10);    // 定时器0中断初始化
    UartInit();                 // 串口通讯初始化
    printf("SYSclk:12M\r\nTIM0_PIT:10ms\r\nUART_BAUD:2400\r\n");    // 打印基本信息
    // Timer_init(&same_key_timer, 500);
    FSM_init(100);
    KeyBoard_4x4_init(&key_board);
    DyDigiTube_4x2_init(&dy_digital_tube);
}
