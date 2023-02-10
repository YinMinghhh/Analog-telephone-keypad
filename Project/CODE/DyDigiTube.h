#ifndef _DYNAMIC_DIGITAL_TUBE_H_
#define _DYNAMIC_DIGITAL_TUBE_H_

#include "KeyBoard.h"
#include "cvector.h"

#define DDT_DP_PORT	P0

/***
 * @brief   单位数码管显示枚举体
*/
typedef enum {
    DDT_zero = 0,   // 0
    DDT_one,
    DDT_two,
    DDT_three,
    DDT_four,
    DDT_five,
    DDT_six,
    DDT_seven,
    DDT_eight,
    DDT_nine,       // 9

    DDT_asterisk,   // *, 序号10
    DDT_pound,      // #, 序号11

    DDT_minus,       // -, 序号12, 代表暂时没有数字
} Display;

/***
 * @brief   一个 由 两个 四位动态数码管 组成的集合 的对象
*/
typedef struct {
    Display display[8];
    Display last_nu[8];
    uint8   enable_last;
    // cvector display = cvector_create(sizeof(Display));
    uint8   _full;
    uint8   _emtp;
    uint8   enable;
} DyDigiTube_4x2;

uint8   DyDigiTube_4x2_init(DyDigiTube_4x2 *const THIS);
void    DyDigiTube_4x2_PutNum(DyDigiTube_4x2 *const THIS);
void    DyDigiTube_4x2_push(DyDigiTube_4x2 *const THIS, uint8 num);
void    DyDigiTube_4x2_popb(DyDigiTube_4x2 *const THIS);
void    DyDigiTube_4x2_Dail(DyDigiTube_4x2 *const THIS);
void    DyDigiTube_4x2_Hang(DyDigiTube_4x2 *const THIS);
void    DyDigiTube_4x2_Redail(DyDigiTube_4x2 *const THIS);

#endif // !_DYNAMIC_DIGITAL_TUBE_H_
