/***
 * @file    main.c
 * @brief   存放程序入口
 * @author  zxy
 * @date    2023-01-17
*/

#include "modules.h"



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
    EnableWDT();            // 使能看门狗
    EnableGlobalIRQ();      // 打开总中断

    // DyDigiTube_4x2_push(&dy_digital_tube, 1);
    LOOP:
        DyDigiTube_4x2_PutNum(&dy_digital_tube);
    goto LOOP;
}


