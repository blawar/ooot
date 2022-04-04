#pragma once
#define Z_EN_WALL_TUBO_H

#include "ultra64.h"
#include "global.h"
#include "overlays/actors/ovl_En_Bom_Bowl_Man/z_en_bom_bowl_man.h"

struct EnWallTubo;

typedef void (*EnWallTuboActionFunc)(struct EnWallTubo*, GlobalContext*);


struct EnWallTubo {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnWallTuboActionFunc actionFunc;
    /* 0x0150 */ Timer timer;
    /* 0x0154 */ Vec3f explosionCenter;
    /* 0x0160 */ EnBomBowlMan* chuGirl;
    /* 0x0164 */ Vec3f unk_164;
}; 


