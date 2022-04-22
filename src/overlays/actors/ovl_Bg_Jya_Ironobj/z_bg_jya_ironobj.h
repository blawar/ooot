#pragma once
#define Z_BG_JYA_IRONOBJ_H

#include "ultra64.h"
#include "global.h"

struct BgJyaIronobj;

typedef void (*BgJyaIronobjActionFunc)(struct BgJyaIronobj*, GlobalContext*);


struct BgJyaIronobj {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgJyaIronobjActionFunc actionFunc;
    /* 0x0168 */ ColliderCylinder colCylinder;
}; 


