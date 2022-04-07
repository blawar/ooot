#pragma once
#define Z_EN_SKJNEEDLE_H

#include "ultra64.h"
#include "global.h"

struct EnSkjneedle;


struct EnSkjneedle {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ char unk_14C[0x48];
    /* 0x0194 */ ColliderCylinder collider;
    /* 0x01E0 */ Timer unusedTimer1;
    /* 0x01E2 */ Timer killTimer;
    /* 0x01E4 */ char unk_1E4[4];
}; 


