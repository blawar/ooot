#pragma once
#define Z_OBJ_MAKEOSHIHIKI_H

#include "ultra64.h"
#include "global.h"

struct ObjMakeoshihiki;



struct BlockConfig {
    /* 0x00 */ Vec3f posVecs[3];
    /* 0x24 */ u8 unk_24[3];
    /* 0x27 */ u8 color;
    /* 0x28 */ u8 type;
    /* 0x2A */ s16 rotY;
};
struct ObjMakeoshihiki {

    /* 0x0000 */ Actor actor;
}; 


