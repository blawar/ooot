#pragma once
#define Z_OBJ_HSBLOCK_H

#include "ultra64.h"
#include "global.h"

struct ObjHsblock;

typedef void (*ObjHsblockActionFunc)(struct ObjHsblock*, GlobalContext*);


struct ObjHsblock {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ ObjHsblockActionFunc actionFunc;
}; 


