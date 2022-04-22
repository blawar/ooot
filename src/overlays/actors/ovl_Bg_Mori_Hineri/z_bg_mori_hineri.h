#pragma once
#define Z_BG_MORI_HINERI_H

#include "ultra64.h"
#include "global.h"

struct BgMoriHineri;

typedef void (*BgMoriHineriActionFunc)(struct BgMoriHineri*, GlobalContext*);


struct BgMoriHineri {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgMoriHineriActionFunc actionFunc;
    /* 0x0168 */ s32 moriHineriObjIdx;
    /* 0x016C */ s32 moriTexObjIdx;
    /* 0x0170 */ s32 boxObjIdx;
    /* 0x0174 */ s8 switchFlag;
}; 


