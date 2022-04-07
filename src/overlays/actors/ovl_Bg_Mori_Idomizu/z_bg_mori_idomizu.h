#pragma once
#define Z_BG_MORI_IDOMIZU_H

#include "ultra64.h"
#include "global.h"

struct BgMoriIdomizu;

typedef void (*BgMoriIdomizuActionFunc)(struct BgMoriIdomizu*, GlobalContext*);


struct BgMoriIdomizu {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ BgMoriIdomizuActionFunc actionFunc;
    /* 0x0150 */ f32 targetWaterLevel;
    /* 0x0154 */ s32 prevSwitchFlagSet;
    /* 0x0158 */ s16 isLoaded;
    /* 0x015A */ Timer drainTimer;
    /* 0x015C */ s32 moriTexObjIndex;
}; 


