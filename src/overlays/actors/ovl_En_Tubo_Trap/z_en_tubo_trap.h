#pragma once
#define Z_EN_TUBO_TRAP_H

#include "ultra64.h"
#include "global.h"

struct EnTuboTrap;

typedef void (*EnTuboTrapActionFunc)(struct EnTuboTrap*, GlobalContext*);


struct EnTuboTrap {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnTuboTrapActionFunc actionFunc;
    /* 0x0150 */ f32 targetY;
    /* 0x0154 */ Vec3f originPos;
    /* 0x0160 */ ColliderCylinder collider;
}; 


