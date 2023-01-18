#ifndef _DYNAMIC_DIGITAL_TUBE_H_
#define _DYNAMIC_DIGITAL_TUBE_H_

#include "KeyBoard.h"

#define DDT_DP_PORT	P0

/***
 * @brief   单位数码管显示枚举体
*/
typedef enum {
    zero = 0,   // 0
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,       // 9

    asterisk,   // *, 序号10
    pound,      // #, 序号11

    puls,       // -, 序号12, 代表暂时没有数字
} Display;

/***
 * @brief   一个 由 两个 四位动态数码管 组成的集合 的对象
*/
typedef struct {
    Display display[8];
    uint8   enable;
} DyDigiTube_4x2;

uint8 DyDigiTube_4x2_init(DyDigiTube_4x2 *const THIS);
void DyDigiTube_4x2_PutNum(DyDigiTube_4x2 *const THIS);


#endif // !_DYNAMIC_DIGITAL_TUBE_H_
