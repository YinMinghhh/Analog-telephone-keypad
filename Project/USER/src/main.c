#include "TIM.h"



/***
 * @brief   �������
 * @author  zxy
 * @date    2023-01-17
*/
void main(){
    board_init();           // ���ӳ�ʼ�����ر����ж�
	pit_timer_ms(TIM_0, 5); // ��ʱ��0�жϳ�ʼ��
    EnableGlobalIRQ();      // �����ж�

	while(1){			
        ;
	}		
}

