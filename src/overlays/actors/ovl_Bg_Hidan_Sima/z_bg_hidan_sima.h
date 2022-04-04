#pragma once
#define Z_BG_HIDAN_SIMA_H

#include "ultra64.h"
#include "global.h"

struct BgHidanSima;

typedef void (*BgHidanSimaActionFunc)(struct BgHidanSima*, GlobalContext*);


struct BgHidanSima {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgHidanSimaActionFunc actionFunc;
    /* 0x0168 */ Timer timer;
    /* 0x016C */ ColliderJntSph collider;
    /* 0x018C */ ColliderJntSphElement elements[2];
}; 


