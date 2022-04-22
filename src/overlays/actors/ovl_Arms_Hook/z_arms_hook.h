#pragma once
#define Z_ARMS_HOOK_H

#include "ultra64.h"
#include "global.h"
#include "z64actor.h"
#include "z64bgcheck.h"
#include "z64player.h"

struct ArmsHook;

typedef void (*ArmsHookActionFunc)(struct ArmsHook*, struct GlobalContext*);


struct ArmsHook {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderQuad collider;
    /* 0x01CC */ WeaponInfo hookInfo;
    /* 0x01E8 */ Vec3f unk_1E8;
    /* 0x01F4 */ Vec3f unk_1F4;
    /* 0x0200 */ Actor* grabbed;
    /* 0x0204 */ Vec3f grabbedDistDiff;
    /* 0x0210 */ Timer timer;
    /* 0x0214 */ ArmsHookActionFunc actionFunc;
}; 


