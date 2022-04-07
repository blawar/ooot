#pragma once
#define Z_EN_SHOPNUTS_H

#include "ultra64.h"
#include "global.h"

struct EnShopnuts;

typedef void (*EnShopnutsActionFunc)(struct EnShopnuts*, GlobalContext*);


struct EnShopnuts {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnShopnutsActionFunc actionFunc;
    /* 0x0194 */ Timer animFlagAndTimer; // 0x1000 bit denotes that projectile has been thrown
    /* 0x0196 */ Vec3s jointTable[18];
    /* 0x0202 */ Vec3s morphTable[18];
    /* 0x0270 */ ColliderCylinder collider;
}; 


