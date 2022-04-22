#pragma once
#define Z_BG_GND_ICEBLOCK_H

#include "ultra64.h"
#include "global.h"

struct BgGndIceblock;

typedef void (*BgGndIceblockActionFunc)(struct BgGndIceblock*, GlobalContext*);


enum BgGndIceblockAction {
    /* 0 */ GNDICE_IDLE,
    /* 1 */ GNDICE_FALL,
    /* 2 */ GNDICE_HOLE
};
struct BgGndIceblock {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgGndIceblockActionFunc actionFunc;
    /* 0x0168 */ Vec3f targetPos;
}; 


