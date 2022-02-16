#pragma once
#define Z_EN_MM2_H

#include "ultra64.h"
#include "global.h"

struct EnMm2;

typedef void (*EnMm2ActionFunc)(struct EnMm2*, GlobalContext*);


enum RunningManAnimIndex {
    /* 0 */ RM2_ANIM_RUN,
    /* 1 */ RM2_ANIM_SIT,
    /* 2 */ RM2_ANIM_SIT_WAIT,
    /* 3 */ RM2_ANIM_STAND,
    /* 4 */ RM2_ANIM_SPRINT,
    /* 5 */ RM2_ANIM_EXCITED, // plays when talking to him with bunny hood on
    /* 6 */ RM2_ANIM_HAPPY    // plays when you sell him the bunny hood
};


enum RunningManMouthTex {
    /* 0 */ RM2_MOUTH_CLOSED,
    /* 1 */ RM2_MOUTH_OPEN
};


struct EnMm2AnimEntry {
    /* 0x00 */ AnimationHeader* animation;
    /* 0x04 */ f32 playSpeed;
    /* 0x08 */ u8 mode;
    /* 0x0C */ f32 morphFrames;
};
struct EnMm2 {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnMm2ActionFunc actionFunc;
    /* 0x0194 */ ColliderCylinder collider;
    /* 0x01E0 */ s32 mouthTexIndex;
    /* 0x01E4 */ char unk_1E4[0x4];
    /* 0x01E8 */ Vec3s unk_1E8;
    /* 0x01EE */ Vec3s unk_1EE;
    /* 0x01F4 */ u16 unk_1F4;
    /* 0x01F6 */ s16 unk_1F6;
    /* 0x01F8 */ s32 previousAnimation;
    /* 0x01FC */ Vec3s jointTable[16];
    /* 0x025C */ Vec3s morphTable[16];
}; 


