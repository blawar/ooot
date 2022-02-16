#pragma once
#define Z_OBJ_LIFT_H

#include "ultra64.h"
#include "global.h"

struct ObjLift;

typedef void (*ObjLiftActionFunc)(struct ObjLift*, GlobalContext*);



struct ObjLiftFramgentScale {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 z;
};
struct ObjLift {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ ObjLiftActionFunc actionFunc;
    /* 0x0168 */ Vec3s unk168;
    /* 0x016E */ s16 timer;
}; 


