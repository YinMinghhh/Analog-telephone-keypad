#include "DyDigiTube.h"

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

// 共阴极数码管
static const uint8 code DISPLAY[13] = {
    0x3F,0x06,0x5B,0x4F,0x66,   // 0 ~ 4
    0x6D,0x7D,0x07,0x7F,0x6F,   // 5 ~ 9
    0x77,0x73,                  // A -> *, P -> #
    0x40, };                    // -

/***
 * @date    2023-01-18
*/
uint8 DyDigiTube_4x2_init(DyDigiTube_4x2 *const THIS){
    uint8 i = 0x00;
    THIS->enable = 1;
    THIS->_full  = 0;
    THIS->_emtp  = 1;
    // memset(THIS->display, sizeof(Display)*8, DDT_minus);
    for (i = 0; i < 8; i++){
        THIS->display[i] = DDT_minus;
    }
    
    return 0;
}

/***
 * @date    2023-01-18
 * @note    不要在定时器中断里调用
*/
void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

/***
 * @date    2023-01-18
 * @note    不要在定时器中断里调用
*/
void DyDigiTube_4x2_PutNum(DyDigiTube_4x2 *const THIS) {
    uint8 i = 0x00;
    for(i = 0x00; i < 0x08; i++){
        LSA = i & 0x01;
        LSB = i & 0x02;
        LSC = i & 0x04;
        DDT_DP_PORT = DISPLAY[THIS->display[i]];
        Delay1ms();
        DDT_DP_PORT = 0x00;
    }
    
}

/***
 * @date    2023-01-18
*/
void DyDigiTube_4x2_push(DyDigiTube_4x2 *const THIS, Display num){
    uint8 i = 0x00;
    THIS->_emtp = 0;
    if(THIS->_full) return ;
    for(; i < 0x08; i++){
        if(THIS->display[i] == DDT_minus){
            THIS->display[i] = num;
            break;
        }
    }
    if (i >= 0x07){
        THIS->_full = 1;
    }
    return ;
}

/***
 * @date    2023-01-22
*/
void DyDigiTube_4x2_popb(DyDigiTube_4x2 *const THIS) {
    uint8 i = 0x08;
    THIS->_full = 0;
    if(THIS->_emtp) return ;
    for(; i > 0x00; i--){
        if(THIS->display[i-1] != DDT_minus) {
            THIS->display[i-1] = DDT_minus;
            break;
        }
    }
    if(i == 0x00) {
        THIS->_emtp = 1;
    }
    return ;
}

/***
 * @date   2023-01-22
*/
void DyDigiTube_4x2_Dail(DyDigiTube_4x2 *const THIS) {
    uint8 i = 0x00;
    if(!THIS->_full) {
        printf("Not Correct.\r\n");
        return ;
    }
    for(; i < 0x08; i++){
        switch (THIS->display[i])
        {
        case DDT_zero:  putchar('0'); break;
        case DDT_one:   putchar('1'); break;
        case DDT_two:   putchar('2'); break;
        case DDT_three: putchar('3'); break;
        case DDT_four:  putchar('4'); break;
        case DDT_five:  putchar('5'); break;
        case DDT_six:   putchar('6'); break;
        case DDT_seven: putchar('7'); break;
        case DDT_eight: putchar('8'); break;
        case DDT_nine:  putchar('9'); break;
        
        default:
            break;
        }
    }
    printf("\r\n");
    return ;
}

/***
 * @date   2023-01-22
*/
void DyDigiTube_4x2_Hang(DyDigiTube_4x2 *const THIS) {
    uint8 i = 0x00;
    THIS->_full = 0;
    THIS->_emtp = 1;
    for(; i < 0x08; i++){
        THIS->display[i] = DDT_minus;
    }
    return ;
}
