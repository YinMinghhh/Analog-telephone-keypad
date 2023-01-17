#include "TIM.h"
#include "UART.h"
#include <stdio.h>

/***
 * @brief   �������
 * @author  zxy
 * @date    2023-01-17
 * 
 * @note    1.CPU�ⲿ����12MHz
 * @note    2.��¼ʱѡ��12T���ӱ�
 * @note    3.��ʱ��0�ж�����10ms
 * @note    4.����ͨѶUART������2400
*/
void main(){
    void modules_init();
    sys_clk = 12000000;
    board_init();           // �����Ĵ�����ʼ�����ر����ж�
    modules_init();         // �����ʼ��
    EnableGlobalIRQ();      // �����ж�

    while(1){
        ;
    }
}

/***
 * @brief   �����ʼ��
 * @date    2023-01-17
*/
void modules_init(){
    pit_timer_ms(TIM_0, 10);    // ��ʱ��0�жϳ�ʼ��
    UartInit();                 // ����ͨѶ��ʼ��
    printf("SYSclk:12M\r\nTIM0_PIT:10ms\r\nUART_BAUD:2400\r\n");    // ��ӡ������Ϣ
}
