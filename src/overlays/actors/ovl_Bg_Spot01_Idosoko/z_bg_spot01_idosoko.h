#pragma once
#define Z_BG_SPOT01_IDOSOKO_H

#include "ultra64.h"
#include "global.h"

struct BgSpot01Idosoko;

typedef void (*BgSpot01IdosokoActionFunc)(struct BgSpot01Idosoko*, GlobalContext*);


struct BgSpot01Idosoko {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgSpot01IdosokoActionFunc actionFunc;
}; 


