#pragma once
#define Z_BG_HAKA_H

#include "ultra64.h"
#include "global.h"

struct BgHaka;

typedef void (*BgHakaActionFunc)(struct BgHaka*, GlobalContext*);


struct BgHaka {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgHakaActionFunc actionFunc;
}; 


