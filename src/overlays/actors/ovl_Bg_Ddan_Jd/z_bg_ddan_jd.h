#pragma once
#define Z_BG_DDAN_JD_H

#include "ultra64.h"
#include "global.h"

struct BgDdanJd;

typedef void (*BgDdanJdActionFunc)(struct BgDdanJd*, GlobalContext*);



enum BgDdanJdState {
    /* 0 */ STATE_GO_BOTTOM,
    /* 1 */ STATE_GO_MIDDLE_FROM_BOTTOM,
    /* 2 */ STATE_GO_MIDDLE_FROM_TOP,
    /* 3 */ STATE_GO_TOP
};
struct BgDdanJd {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgDdanJdActionFunc actionFunc;
    /* 0x0168 */ u8 state;
    /* 0x0169 */ u8 ySpeed; // also differentiates between normal and shortcut platform behavior
    /* 0x016A */ s16 idleTimer;
    /* 0x016C */ f32 targetY;
}; 


