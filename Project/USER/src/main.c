#include "TIM.h"
#include "UART.h"


/***
 * @brief   �������
 * @author  zxy
 * @date    2023-01-17
*/
void main(){
    sys_clk = 24000000;
    board_init();           // ���ӳ�ʼ�����ر����ж�
    pit_timer_ms(TIM_0, 10); // ��ʱ��0�жϳ�ʼ��

    UartInit();
    // UartInit();

    EnableGlobalIRQ();      // �����ж�

    while(1){
        ;
    }
}

