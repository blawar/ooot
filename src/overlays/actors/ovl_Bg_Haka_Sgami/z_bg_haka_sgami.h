#pragma once
#define Z_BG_HAKA_SGAMI_H

#include "ultra64.h"
#include "global.h"

struct BgHakaSgami;

typedef void (*BgHakaSgamiActionFunc)(struct BgHakaSgami*, GlobalContext*);


enum SpinningScytheTrapMode {
    /* 0 */ SCYTHE_TRAP_SHADOW_TEMPLE,
    /* 1 */ SCYTHE_TRAP_SHADOW_TEMPLE_INVISIBLE,
    /* 2 */ SCYTHE_TRAP_ICE_CAVERN
};
struct BgHakaSgami {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ BgHakaSgamiActionFunc actionFunc;
    /* 0x0150 */ s32 requiredObjBankIndex;
    /* 0x0151 */ s8 unk_151;
    /* 0x0152 */ Timer timer;
    /* 0x0154 */ s32 blureEffectIndex[2];
    /* 0x015C */ ColliderCylinder colliderScytheCenter;
    /* 0x01A8 */ ColliderTris colliderScythe;
    /* 0x01C8 */ ColliderTrisElement colliderScytheItems[4];
}; 


