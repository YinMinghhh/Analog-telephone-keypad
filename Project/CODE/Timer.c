#include "Timer.h"

vuint32 SYStim = 0;

uint8 Timer_init(Timer *const THIS, uint32 dur){
    THIS->last_time = SYStim;
    THIS->duration = dur;
    return 0;
}

uint8 Timer_judge(Timer *const THIS){
    if(SYStim - THIS->last_time >= THIS->duration) {
        THIS->last_time = SYStim;
        THIS->valid = 1;
    }
    else if(THIS->valid){
        THIS->valid = 0;
    }
    return THIS->valid;
}

