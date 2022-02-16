#pragma once
#define Z_BG_MORI_HASHIRA4_H

#include "ultra64.h"
#include "global.h"

struct BgMoriHashira4;

typedef void (*BgMoriHashira4ActionFunc)(struct BgMoriHashira4*, GlobalContext*);


struct BgMoriHashira4 {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgMoriHashira4ActionFunc actionFunc;
    /* 0x0168 */ s32 moriTexObjIndex;
    /* 0x016C */ s8 switchFlag;
    /* 0x0170 */ s16 gateTimer;
}; 


