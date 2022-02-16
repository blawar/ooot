#pragma once
#define Z_BG_SPOT06_OBJECTS_H

#include "ultra64.h"
#include "global.h"

struct BgSpot06Objects;

typedef void (*BgSpot06ObjectsActionFunc)(struct BgSpot06Objects*, GlobalContext*);


enum LakeHyliaObjectsType {
    /* 0x0 */ LHO_WATER_TEMPLE_ENTRACE_GATE,
    /* 0x1 */ LHO_WATER_TEMPLE_ENTRANCE_LOCK,
    /* 0x2 */ LHO_WATER_PLANE,
    /* 0x3 */ LHO_ICE_BLOCK
};


enum LakeHyliaWaterBoxIndices {
    /* 0x0 */ LHWB_GERUDO_VALLEY_RIVER_UPPER, // entrance from Gerudo Valley
    /* 0x1 */ LHWB_GERUDO_VALLEY_RIVER_LOWER, // river flowing from Gerudo Valley
    /* 0x2 */ LHWB_MAIN_1,                    // main water box
    /* 0x3 */ LHWB_MAIN_2                     // extension of main water box
};
struct BgSpot06Objects {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgSpot06ObjectsActionFunc actionFunc;
    /* 0x0168 */ s16 switchFlag;
    /* 0x016A */ s16 timer;
    /* 0x016C */ f32 lakeHyliaWaterLevel;
    /* 0x0170 */ ColliderJntSph collider;
    /* 0x0190 */ ColliderJntSphElement colliderItem[1];
}; 


