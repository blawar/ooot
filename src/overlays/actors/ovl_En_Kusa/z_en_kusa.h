#pragma once
#define Z_EN_KUSA_H

#include "ultra64.h"
#include "global.h"

struct EnKusa;

typedef void (*EnKusaActionFunc)(struct EnKusa*, GlobalContext*);

enum EnKusaType {
    /* 0 */ ENKUSA_TYPE_0,
    /* 1 */ ENKUSA_TYPE_1,
    /* 2 */ ENKUSA_TYPE_2
};


struct EnKusa {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnKusaActionFunc actionFunc;
    /* 0x0150 */ ColliderCylinder collider;
    /* 0x019C */ s16 timer;
    /* 0x019E */ s32 objBankIndex;
}; 


