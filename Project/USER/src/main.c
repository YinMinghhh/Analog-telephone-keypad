/***
 * @file    main.c
 * @brief   ��ų������
 * @author  zxy
 * @date    2023-01-17
*/

#include "modules.h"



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


