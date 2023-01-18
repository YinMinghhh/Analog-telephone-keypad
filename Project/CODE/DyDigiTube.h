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

    DDT_puls,       // -, 序号12, 代表暂时没有数字
} Display;

/***
 * @brief   一个 由 两个 四位动态数码管 组成的集合 的对象
*/
typedef struct {
    Display display[8];
    // cvector display = cvector_create(sizeof(Display));
    uint8   _full;
    uint8   enable;
} DyDigiTube_4x2;

uint8 DyDigiTube_4x2_init(DyDigiTube_4x2 *const THIS);
void DyDigiTube_4x2_PutNum(DyDigiTube_4x2 *const THIS);
void DyDigiTube_4x2_push(DyDigiTube_4x2 *const THIS, uint8 num);
void DyDigiTube_4x2_service(DyDigiTube_4x2 *const THIS, KeyBoard_4x4 *const KeyBoard);


#endif // !_DYNAMIC_DIGITAL_TUBE_H_
