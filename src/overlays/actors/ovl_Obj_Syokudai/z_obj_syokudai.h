#pragma once
#define Z_OBJ_SYOKUDAI_H

#include "ultra64.h"
#include "global.h"

struct ObjSyokudai;


struct ObjSyokudai {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderCylinder colliderStand;
    /* 0x0198 */ ColliderCylinder colliderFlame;
    /* 0x01E4 */ s16 litTimer;
    /* 0x01E6 */ u8 flameTexScroll;
    /* 0x01E8 */ LightNode* lightNode;
    /* 0x01EC */ LightInfo lightInfo;
}; 


