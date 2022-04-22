#pragma once
#define Z_BG_MORI_BIGST_H

#include "ultra64.h"
#include "global.h"

struct BgMoriBigst;

typedef void (*BgMoriBigstActionFunc)(struct BgMoriBigst*, GlobalContext*);


struct BgMoriBigst {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgMoriBigstActionFunc actionFunc;
    /* 0x0168 */ s16 waitTimer;
    /* 0x016A */ s32 moriTexObjIndex;
}; 


