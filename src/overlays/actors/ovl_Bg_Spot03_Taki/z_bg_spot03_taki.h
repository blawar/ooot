#pragma once
#define Z_BG_SPOT03_TAKI_H

#include "ultra64.h"
#include "global.h"

enum BgSpot03TakiState {
    WATERFALL_CLOSED,
    WATERFALL_OPENING_IDLE,
    WATERFALL_OPENING_ANIMATED,
    WATERFALL_OPENED,
    WATERFALL_CLOSING
};

struct BgSpot03Taki;

typedef void (*BgSpot03TakiActionFunc)(struct BgSpot03Taki*, GlobalContext*);


struct BgSpot03Taki {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgSpot03TakiActionFunc actionFunc;
    /* 0x0168 */ Timer timer;
    /* 0x016A */ u8 state;
    /* 0x016C */ u16 switchFlag;
    /* 0x0170 */ f32 openingAlpha;
    /* 0x0174 */ u8 bufferIndex;
}; 


