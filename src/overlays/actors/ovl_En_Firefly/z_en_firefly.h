#pragma once
#define Z_EN_FIREFLY_H

#include "ultra64.h"
#include "global.h"

struct EnFirefly;

typedef void (*EnFireflyActionFunc)(struct EnFirefly*, GlobalContext*);



enum KeeseAuraType {
    /* 0 */ KEESE_AURA_NONE,
    /* 1 */ KEESE_AURA_FIRE,
    /* 2 */ KEESE_AURA_ICE
};
struct EnFirefly {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ Vec3f bodyPartsPos[3];
    /* 0x0170 */ SkelAnime skelAnime;
    /* 0x01B4 */ EnFireflyActionFunc actionFunc;
    /* 0x01B8 */ u8 auraType;
    /* 0x01B9 */ u8 onFire;
    /* 0x01BA */ Timer timer;
    /* 0x01BC */ s16 targetPitch;
    /* 0x01BE */ Vec3s jointTable[28];
    /* 0x0266 */ Vec3s morphTable[28];
    /* 0x0310 */ f32 maxAltitude;
    /* 0x0314 */ ColliderJntSph collider;
    /* 0x0344 */ ColliderJntSphElement colliderItems[1];
}; 

enum KeeseType {
    /* 0 */ KEESE_FIRE_FLY,
    /* 1 */ KEESE_FIRE_PERCH,
    /* 2 */ KEESE_NORMAL_FLY,
    /* 3 */ KEESE_NORMAL_PERCH,
    /* 4 */ KEESE_ICE_FLY
};


