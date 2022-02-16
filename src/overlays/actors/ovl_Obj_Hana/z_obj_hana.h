#pragma once
#define Z_OBJ_HANA_H

#include "ultra64.h"
#include "global.h"

struct ObjHana;



struct HanaParams {
    /* 0x00 */ Gfx* dList;
    /* 0x04 */ f32 scale;
    /* 0x08 */ f32 yOffset;
    /* 0x0C */ s16 radius;
    /* 0x0E */ s16 height;
};
struct ObjHana {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderCylinder collider;
}; 


