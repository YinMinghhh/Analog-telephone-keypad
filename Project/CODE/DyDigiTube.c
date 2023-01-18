#include "DyDigiTube.h"

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

// 共阴极数码管
static const uint8 DISPLAY[12] = {
    0x3F,0x06,0x5B,0x4F,0x66,   // 0 ~ 4
    0x6D,0x7D,0x07,0x7F,0x6F,   // 5 ~ 9
    0x77,0x73,                  // A -> *, P -> #
    0x40, };                    // -

uint8 DyDigiTube_4x2_init(DyDigiTube_4x2 *const THIS){
    THIS->enable = 1;
    memset(THIS->display, sizeof(Display)*8, puls);
    return 0;
}

void DyDigiTube_4x2_PutNum(DyDigiTube_4x2 *const THIS) {
    uint8 i = 0x00;
    while(i++ < 0x08){
        LSA = i & 0x01;
        LSB = i & 0x02;
        LSC = i & 0x04;
        DDT_DP_PORT = DISPLAY[THIS->display[i]];
        _nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();
        DDT_DP_PORT = 0x00;
    }
    
}

void DyDigiTube_4x2_push(DyDigiTube_4x2 *const THIS, uint8 num){
    ;
}

