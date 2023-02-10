#ifndef _FSM_H_
#define _FSM_H_

#include "KeyBoard.h"
#include "DyDigiTube.h"
#include "Timer.h"
#include "modules.h"
#include "isr.h"

#define	FSM_CAP_OF_TRANSITION	0x08
#define	FSM_CAP_OF_ACTIONS		0x04

// ==================================================

typedef enum {
    Enter_number = 0,   // 输入号码阶段
    Dail_wait,          // 等待接通阶段
    Put_through,        // 正在通话阶段
    Redail_wait,        // 等待重拨阶段
    
    Default,            // 异常
} FSM_STATES;

typedef struct {
    FSM_STATES  start_sate;
    uint8       (*check)(void);
    FSM_STATES  next_state;
} FSM_TRANSITION;

typedef struct {
    FSM_STATES  work_mode;
    void        (* init)(void);
    void        (* loop)(void);
} FSM_ACTIONS;

// ==================================================

extern Timer keyboard_CoolDown;
extern Timer Dail_Wait_time;
extern Timer Redail_Cool_down;

void FSM_OPERATION();
void _FSM_MODE_TRANS_(); 

// ==================================================

extern FSM_TRANSITION code FSM_transition[FSM_CAP_OF_TRANSITION];
uint8 _FSM_tra_Enter_DailW();
uint8 _FSM_tra_DailW_PutTh();
uint8 _FSM_tra_DailW_Enter();
uint8 _FSM_tra_PutTh_Enter();
uint8 _FSM_tra_DailW_RedaW();
uint8 _FSM_tra_RedaW_Enter();
uint8 _FSM_tra_RedaW_PutTh();
uint8 _FSM_tra_RedaW_DailW();




// ==================================================

extern FSM_ACTIONS code FSM_actions[FSM_CAP_OF_ACTIONS];

void _FSM_act_GLOABLE_init(uint32 time1, uint32 time2, uint32 time3);
void _FSM_act_GLOABLE_loop();

void _FSM_act_Enter_init();
void _FSM_act_Enter_loop();
void _FSM_act_DailW_init();
void _FSM_act_DailW_loop();
void _FSM_act_PutTh_init();
void _FSM_act_PutTh_loop();
void _FSM_act_RedaW_init();
void _FSM_act_RedaW_loop();

#endif // !_FSM_H_
