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
    THIS->enable_last = 0;
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
 * @brief   (内部调用)数码管上显示一个数字
 * @date    2023-01-18
 * @note    不要在定时器中断里调用
 *          可以在main函数的循环里用
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
 * @brief   号码盘上增加一个数字
 * @date    2023-01-18
 *          可以在main函数的循环里用
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
 * @brief   号码盘上删除一个数字
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
 * @brief   拨号功能, 不满八位不予拨号
 * @date    2023-01-22
*/
uint8 DyDigiTube_4x2_Dail(DyDigiTube_4x2 *const THIS) {
    uint8 i = 0x00;
    if(!THIS->_full) {
        printf("Not Correct.\r\n");
        return 0;
    }
    if(!THIS->enable_last) {
        THIS->enable_last = 1;
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
        THIS->last_nu[i] = THIS->display[i];
    }
    printf("\r\n");
    return 1;
}

/***
 * @brief   挂断功能(清除号码盘上的数字)
 * @date    2023-01-22
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

/***
 * @brief   重拨按钮功能
 * @date    2023-02-10
*/
uint8 DyDigiTube_4x2_Redail(DyDigiTube_4x2 *const THIS) {
    uint8 i = 0x00;
    if(!THIS->enable_last) {
        printf("Fail to redail.\r\n");
        return 0;
    }
    for(; i < 0x08; i++) {
        DyDigiTube_4x2_push(THIS, THIS->last_nu[i]);
    }
    DyDigiTube_4x2_Dail(THIS);
    return 1;
}