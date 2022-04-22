#pragma once
#define Z_BG_JYA_1FLIFT_H

#include "ultra64.h"
#include "global.h"

struct BgJya1flift;

typedef void (*BgJya1fliftActionFunc)(struct BgJya1flift*, GlobalContext*);


struct BgJya1flift {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ ColliderCylinder collider;
    /* 0x01B0 */ BgJya1fliftActionFunc actionFunc;
    /* 0x01B4 */ s16 moveDelay;
    /* 0x01B6 */ u8 isMovingDown;
    /* 0x01B7 */ u8 hasInitialized;
    /* 0x01B8 */ u8 isLinkRiding;
}; 


