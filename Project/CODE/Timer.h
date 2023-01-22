#ifndef _TIMER_H_
#define _TIMER_H_

#include "common.h"

extern vuint32 SYStim;

typedef struct {
    vuint32  last_time;
    uint32  duration;
    uint8   valid;
    uint8   enable;
} Timer;

uint8   Timer_init (Timer *const THIS, uint32 dur);
uint8   Timer_judge(Timer *const THIS);

#endif // !_TIMER_H_
