#pragma once
#define Z_BG_SPOT01_IDOMIZU_H

#include "ultra64.h"
#include "global.h"

struct BgSpot01Idomizu;

typedef void (*BgSpot01IdomizuActionFunc)(struct BgSpot01Idomizu*, GlobalContext*);


struct BgSpot01Idomizu {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ BgSpot01IdomizuActionFunc actionFunc;
    /* 0x0150 */ f32 waterHeight;
    /* 0x0154 */ char unk_154[0x4];
}; 


