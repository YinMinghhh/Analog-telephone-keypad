#ifndef __BOARD_H
#define __BOARD_H
#include "common.h"

extern int32 sys_clk;

void board_init(void);
void DisableGlobalIRQ(void);
void EnableGlobalIRQ(void);

#endif

