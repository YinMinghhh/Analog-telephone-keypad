#ifndef __BOARD_H
#define __BOARD_H
#include "common.h"

#define FeedDog WDT_CONTR=0x34

extern int32 sys_clk;

void board_init(void);
void DisableGlobalIRQ(void);
void EnableGlobalIRQ(void);
void EnableWDT(void);

#endif

