#pragma once
#define Z_EN_KO_H

#include "ultra64.h"
#include "global.h"

struct EnKo;

typedef void (*EnKoActionFunc)(struct EnKo*, GlobalContext*);



struct EnKoHead {
    /* 0x0 */ s16 objectId;
    /* 0x4 */ Gfx* dList;
    /* 0x8 */ void** eyeTextures;
};


struct EnKoSkeleton {
    /* 0x0 */ s16 objectId;
    /* 0x4 */ FlexSkeletonHeader* flexSkeletonHeader;
};


struct EnKoModelInfo {
    /* 0x0 */ u8 headId;
    /* 0x1 */ u8 bodyId;
    /* 0x4 */ Color_RGBA8 tunicColor;
    /* 0x8 */ u8 legsId;
    /* 0xC */ Color_RGBA8 bootsColor;
};
 

enum KokiriGender {
    /* 0 */ KO_BOY,
    /* 1 */ KO_GIRL,
    /* 2 */ KO_FADO
};


struct EnKoInteractInfo {
    /* 0x0 */ s8 targetMode;
    /* 0x4 */ f32 lookDist; // extended by collider radius
    /* 0x8 */ f32 appearDist;
};
struct EnKo {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnKoActionFunc actionFunc;
    /* 0x0194 */ s32 headObjectBankIdx;
    /* 0x0198 */ s32 bodyObjectBankIdx;
    /* 0x019C */ s32 legsObjectBankIdx;
    /* 0x01A0 */ s32 osAnimeBankIndex;
    /* 0x01A4 */ ColliderCylinder collider;
    /* 0x01E4 */ Path* path;
    /* 0x01F0 */ struct_80034A14_arg1 unk_1E8;
    /* 0x021C */ u8 unk_210; // block trade quest sfx
    /* 0x021E */ s16 forestQuestState;
    /* 0x0220 */ s16 blinkTimer;
    /* 0x0222 */ s16 eyeTextureIndex;
    /* 0x0224 */ f32 appearDist;
    /* 0x0228 */ f32 lookDist; // distance to start looking at player
    /* 0x022C */ f32 modelAlpha;
    /* 0x0230 */ Vec3s jointTable[16];
    /* 0x0290 */ Vec3s morphTable[16];
    /* 0x02F0 */ s16 unk_2E4[16];
    /* 0x0310 */ s16 unk_304[16];
}; 

enum KokiriChildren {
    ENKO_TYPE_CHILD_0,
    ENKO_TYPE_CHILD_1,
    ENKO_TYPE_CHILD_2,
    ENKO_TYPE_CHILD_3,
    ENKO_TYPE_CHILD_4,
    ENKO_TYPE_CHILD_5, // Shop Awning
    ENKO_TYPE_CHILD_6,
    ENKO_TYPE_CHILD_7,
    ENKO_TYPE_CHILD_8,
    ENKO_TYPE_CHILD_9,
    ENKO_TYPE_CHILD_10,
    ENKO_TYPE_CHILD_11,
    ENKO_TYPE_CHILD_FADO,
    ENKO_TYPE_CHILD_MAX
};

enum KokiriForestQuestState {
    ENKO_FQS_CHILD_START,
    ENKO_FQS_CHILD_STONE,
    ENKO_FQS_CHILD_SARIA,
    ENKO_FQS_ADULT_ENEMY,
    ENKO_FQS_ADULT_SAVED
};


