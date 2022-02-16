#pragma once
#define Z_BG_MJIN_H

#include "ultra64.h"
#include "global.h"

struct BgMjin;

typedef void (*BgMjinActionFunc)(struct BgMjin*, GlobalContext*);


struct BgMjin {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ s32 objBankIndex;
    /* 0x0168 */ BgMjinActionFunc actionFunc;
}; 


