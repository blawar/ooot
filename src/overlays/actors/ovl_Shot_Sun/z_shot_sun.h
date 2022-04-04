#pragma once
#define Z_SHOT_SUN_H

#include "ultra64.h"
#include "global.h"

struct ShotSun;

typedef void (*ShotSunActionFunc)(struct ShotSun*, GlobalContext*);


struct ShotSun {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderCylinder collider;
    /* 0x0198 */ ShotSunActionFunc actionFunc;
    /* 0x019C */ Vec3s hitboxPos;
    /* 0x01A2 */ Timer timer; // Frames until fairy spawns
    /* 0x01A4 */ u8 unk_1A4;
}; 


