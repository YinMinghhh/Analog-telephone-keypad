#include "FSM.h"

Timer CoolDown;

void FSM_init(uint32 time){
    Timer_init(&CoolDown, time);
}

void FSM_service(DyDigiTube_4x2 *const THIS, KeyBoard_4x4 *const KeyBoard){
    KeyBoard_4x4_scan(KeyBoard);
    _nop_();_nop_();_nop_();_nop_();
    _nop_();_nop_();_nop_();_nop_();
    
    if (Timer_judge(&CoolDown)) {
        switch (KeyBoard->button_na) {
            case zero:  DyDigiTube_4x2_push(THIS, DDT_zero);    break;
            case one:   DyDigiTube_4x2_push(THIS, DDT_one);     break;
            case two:   DyDigiTube_4x2_push(THIS, DDT_two);     break;
            case three: DyDigiTube_4x2_push(THIS, DDT_three);   break;
            case four:  DyDigiTube_4x2_push(THIS, DDT_four);    break;
            case five:  DyDigiTube_4x2_push(THIS, DDT_five);    break;
            case six:   DyDigiTube_4x2_push(THIS, DDT_six);     break;
            case seven: DyDigiTube_4x2_push(THIS, DDT_seven);   break;
            case eight: DyDigiTube_4x2_push(THIS, DDT_eight);   break;
            case nine:  DyDigiTube_4x2_push(THIS, DDT_nine);    break;

            case Backspace: DyDigiTube_4x2_popb(THIS);          break;

            case Dail:  DyDigiTube_4x2_Dail(THIS);              break;
            case Hang:  DyDigiTube_4x2_Hang(THIS);              break;
            default:
                break;
        }
    }
    
    
}