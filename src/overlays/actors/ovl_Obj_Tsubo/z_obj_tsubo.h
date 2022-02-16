#pragma once
#define Z_OBJ_TSUBO_H

#include "ultra64.h"
#include "global.h"

struct ObjTsubo;

typedef void (*ObjTsuboActionFunc)(struct ObjTsubo*, GlobalContext*);


struct ObjTsubo {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ObjTsuboActionFunc actionFunc;
    /* 0x0150 */ ColliderCylinder collider;
    /* 0x019C */ s32 objTsuboBankIndex;
}; 


