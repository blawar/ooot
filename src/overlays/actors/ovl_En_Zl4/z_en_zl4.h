#pragma once
#define Z_EN_ZL4_H

#include "ultra64.h"
#include "global.h"

struct EnZl4;

typedef void (*EnZl4ActionFunc)(struct EnZl4*, GlobalContext*);
typedef void (*EnZl4DrawFunc)(struct EnZl4*, GlobalContext*);


enum EnZl4CutsceneState {
    /* 0 */ ZL4_CS_WAIT,
    /* 1 */ ZL4_CS_START,
    /* 2 */ ZL4_CS_MEET,
    /* 3 */ ZL4_CS_STONE,
    /* 4 */ ZL4_CS_NAMES,
    /* 5 */ ZL4_CS_LEGEND,
    /* 6 */ ZL4_CS_WINDOW,
    /* 7 */ ZL4_CS_GANON,
    /* 8 */ ZL4_CS_PLAN
};


enum EnZl4EyeExpression {
    /* 0 */ ZL4_EYES_NEUTRAL,
    /* 1 */ ZL4_EYES_SHUT,
    /* 2 */ ZL4_EYES_LOOK_LEFT,
    /* 3 */ ZL4_EYES_LOOK_RIGHT,
    /* 4 */ ZL4_EYES_WIDE,
    /* 5 */ ZL4_EYES_SQUINT,
    /* 6 */ ZL4_EYES_OPEN
};


enum EnZl4MouthExpression {
    /* 0 */ ZL4_MOUTH_NEUTRAL,
    /* 1 */ ZL4_MOUTH_HAPPY,
    /* 2 */ ZL4_MOUTH_WORRIED,
    /* 3 */ ZL4_MOUTH_SURPRISED
};


enum EnZl4EyeState {
    /* 0 */ ZL4_EYE_OPEN,
    /* 1 */ ZL4_EYE_BLINK,
    /* 2 */ ZL4_EYE_SHUT,
    /* 3 */ ZL4_EYE_WIDE,
    /* 4 */ ZL4_EYE_SQUINT,
    /* 5 */ ZL4_EYE_LOOK_OUT,
    /* 6 */ ZL4_EYE_LOOK_IN
};


enum EnZl4Animation {
    /*  0 */ ZL4_ANIM_0,
    /*  1 */ ZL4_ANIM_1,
    /*  2 */ ZL4_ANIM_2,
    /*  3 */ ZL4_ANIM_3,
    /*  4 */ ZL4_ANIM_4,
    /*  5 */ ZL4_ANIM_5,
    /*  6 */ ZL4_ANIM_6,
    /*  7 */ ZL4_ANIM_7,
    /*  8 */ ZL4_ANIM_8,
    /*  9 */ ZL4_ANIM_9,
    /* 10 */ ZL4_ANIM_10,
    /* 11 */ ZL4_ANIM_11,
    /* 12 */ ZL4_ANIM_12,
    /* 13 */ ZL4_ANIM_13,
    /* 14 */ ZL4_ANIM_14,
    /* 15 */ ZL4_ANIM_15,
    /* 16 */ ZL4_ANIM_16,
    /* 17 */ ZL4_ANIM_17,
    /* 18 */ ZL4_ANIM_18,
    /* 19 */ ZL4_ANIM_19,
    /* 20 */ ZL4_ANIM_20,
    /* 21 */ ZL4_ANIM_21,
    /* 22 */ ZL4_ANIM_22,
    /* 23 */ ZL4_ANIM_23,
    /* 24 */ ZL4_ANIM_24,
    /* 25 */ ZL4_ANIM_25,
    /* 26 */ ZL4_ANIM_26,
    /* 27 */ ZL4_ANIM_27,
    /* 28 */ ZL4_ANIM_28,
    /* 29 */ ZL4_ANIM_29,
    /* 30 */ ZL4_ANIM_30,
    /* 31 */ ZL4_ANIM_31,
    /* 32 */ ZL4_ANIM_32,
    /* 33 */ ZL4_ANIM_33
};
struct EnZl4 {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnZl4ActionFunc actionFunc;
    /* 0x0194 */ ColliderCylinder collider;
    /* 0x01E0 */ struct_80034A14_arg1 unk_1E0;
    /* 0x0208 */ u8 talkState;
    /* 0x0209 */ u8 csState;
    /* 0x020A */ u8 leftEyeState;
    /* 0x020B */ u8 rightEyeState;
    /* 0x020C */ u8 mouthState;
    /* 0x020D */ u8 eyeExpression;
    /* 0x020E */ u8 mouthExpression;
    /* 0x020F */ u8 unk_20F;
    /* 0x0210 */ s16 blinkTimer;
    /* 0x0212 */ s16 talkTimer1;
    /* 0x0214 */ s16 talkTimer2;
    /* 0x0216 */ s16 lastAction;
    /* 0x0218 */ Vec3s jointTable[18];
    /* 0x0284 */ Vec3s morphTable[18];
}; 


