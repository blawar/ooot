#pragma once
#define Z_BG_SPOT12_GATE_H

#include "ultra64.h"
#include "global.h"

struct BgSpot12Gate;

typedef void (*BgSpot12GateActionFunc)(struct BgSpot12Gate*, GlobalContext*);


struct BgSpot12Gate {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgSpot12GateActionFunc actionFunc;
    /* 0x0168 */ s16 unk_168;
}; 


