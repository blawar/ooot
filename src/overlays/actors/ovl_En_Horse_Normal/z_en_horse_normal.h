#pragma once
#define Z_EN_HORSE_NORMAL_H

#include "ultra64.h"
#include "global.h"

struct EnHorseNormal;

typedef void (*EnHorseNormalActionFunc)(struct EnHorseNormal*, GlobalContext*);


struct EnHorseNormalUnkStruct1 {
    Vec3s pos;
    u8 unk_06; // pthis may be a s16 if the always-0 following byte is actually not padding
};


struct EnHorseNormalUnkStruct2 {
    s32 len;
    EnHorseNormalUnkStruct1* items;
};


enum EnHorseNormalAction {
    /* 0x00 */ HORSE_CYCLE_ANIMATIONS,
    /* 0x01 */ HORSE_WANDER,
    /* 0x02 */ HORSE_WAIT,
    /* 0x03 */ HORSE_WAIT_CLONE,
    /* 0x04 */ HORSE_FOLLOW_PATH
};
struct EnHorseNormal {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ s32 action;
    /* 0x0150 */ s32 animationIdx;
    /* 0x0154 */ PSkinAwb skin;
    /* 0x01E4 */ u16 unk_1E4;
    /* 0x01E8 */ Vec3f unk_1E8;
    /* 0x01F4 */ Vec3f unk_1F4;
    /* 0x0200 */ s32 unk_200;
    /* 0x0204 */ Vec3f unk_204;
    /* 0x0210 */ char unk_210[0x08];
    /* 0x0218 */ f32 unk_218;
    /* 0x021C */ s16 unk_21C;
    /* 0x021E */ s16 unk_21E;
    /* 0x0220 */ f32 unk_220;
    /* 0x0224 */ char unk_224[0x04];
    /* 0x0228 */ ColliderCylinder bodyCollider;
    /* 0x0274 */ ColliderJntSph headCollider;
    /* 0x0294 */ ColliderJntSphElement headElements[1];
    /* 0x02D4 */ ColliderCylinder cloneCollider;
    /* 0x0320 */ char unk_320[0x04];
    /* 0x0324 */ s32 waypoint;
}; 


