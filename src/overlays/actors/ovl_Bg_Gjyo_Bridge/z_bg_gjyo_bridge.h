#pragma once
#define Z_BG_GJYO_BRIDGE_H

#include "ultra64.h"
#include "global.h"

struct BgGjyoBridge;

typedef void (*BgGjyoBridgeActionFunc)(struct BgGjyoBridge*, GlobalContext*);


struct BgGjyoBridge {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgGjyoBridgeActionFunc actionFunc;
}; 


