#pragma once
#define Z_EN_M_FIRE1_H

#include "ultra64.h"
#include "global.h"

struct EnMFire1;


struct EnMFire1 {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderCylinder collider;
    /* 0x0198 */ f32 timer;
}; 


