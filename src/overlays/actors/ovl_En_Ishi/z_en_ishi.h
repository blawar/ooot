#pragma once
#define Z_EN_ISHI_H

#include "ultra64.h"
#include "global.h"

enum EnIshiType {
    /* 0x00 */ ROCK_SMALL,
    /* 0x01 */ ROCK_LARGE
};

struct EnIshi;

typedef void (*EnIshiActionFunc)(struct EnIshi*, GlobalContext*);
typedef void (*EnIshiEffectSpawnFunc)(struct EnIshi*, GlobalContext*);
typedef void (*EnIshiDrawFunc)(struct EnIshi*, GlobalContext*);


struct EnIshi {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnIshiActionFunc actionFunc;
    /* 0x0150 */ ColliderCylinder collider;
}; 


