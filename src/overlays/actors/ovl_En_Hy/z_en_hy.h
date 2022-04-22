#pragma once
#define Z_EN_HY_H

#include "ultra64.h"
#include "global.h"

enum EnHyType {
    /*  0 */ ENHY_TYPE_AOB,
    /*  1 */ ENHY_TYPE_COB,
    /*  2 */ ENHY_TYPE_AHG_2,
    /*  3 */ ENHY_TYPE_BOJ_3,
    /*  4 */ ENHY_TYPE_AHG_4,
    /*  5 */ ENHY_TYPE_BOJ_5,
    /*  6 */ ENHY_TYPE_BBA,
    /*  7 */ ENHY_TYPE_BJI_7,
    /*  8 */ ENHY_TYPE_CNE_8,
    /*  9 */ ENHY_TYPE_BOJ_9,
    /* 10 */ ENHY_TYPE_BOJ_10,
    /* 11 */ ENHY_TYPE_CNE_11,
    /* 12 */ ENHY_TYPE_BOJ_12,
    /* 13 */ ENHY_TYPE_AHG_13,
    /* 14 */ ENHY_TYPE_BOJ_14,
    /* 15 */ ENHY_TYPE_BJI_15,
    /* 16 */ ENHY_TYPE_BOJ_16,
    /* 17 */ ENHY_TYPE_AHG_17,
    /* 18 */ ENHY_TYPE_BOB_18,
    /* 19 */ ENHY_TYPE_BJI_19,
    /* 20 */ ENHY_TYPE_AHG_20,
    /* 21 */ ENHY_TYPE_MAX
};

struct EnHy;

typedef void (*EnHyActionFunc)(struct EnHy*, GlobalContext*);



struct EnHyHeadInfo {
    /* 0x00 */ s16 objectId;
    /* 0x04 */ Gfx* headDList;
    /* 0x08 */ void** eyeTextures;
};
 

enum EnHyHeadIndex {
    /*  0 */ ENHY_HEAD_AOB,
    /*  1 */ ENHY_HEAD_BOB,
    /*  2 */ ENHY_HEAD_BOJ_2,
    /*  3 */ ENHY_HEAD_BOJ_3,
    /*  4 */ ENHY_HEAD_BOJ_4,
    /*  5 */ ENHY_HEAD_BOJ_5,
    /*  6 */ ENHY_HEAD_BOJ_6,
    /*  7 */ ENHY_HEAD_AHG_7,
    /*  8 */ ENHY_HEAD_AHG_8,
    /*  9 */ ENHY_HEAD_AHG_9,
    /* 10 */ ENHY_HEAD_BBA,
    /* 11 */ ENHY_HEAD_CNE_11,
    /* 12 */ ENHY_HEAD_CNE_12,
    /* 13 */ ENHY_HEAD_BJI_13,
    /* 14 */ ENHY_HEAD_BJI_14,
    /* 15 */ ENHY_HEAD_COB
};


struct EnHySkeletonInfo {
    /* 0x00 */ s16 objectId;
    /* 0x04 */ FlexSkeletonHeader* skeleton;
};
 

enum EnHySkeletonIndex {
    /* 0 */ ENHY_SKEL_AOB,
    /* 1 */ ENHY_SKEL_BOB,
    /* 2 */ ENHY_SKEL_BOJ,
    /* 3 */ ENHY_SKEL_AHG,
    /* 4 */ ENHY_SKEL_BBA,
    /* 5 */ ENHY_SKEL_CNE,
    /* 6 */ ENHY_SKEL_BJI,
    /* 7 */ ENHY_SKEL_COB
};


enum EnHyAnimationIndex {
    /*  0 */ ENHY_ANIM_0,
    /*  1 */ ENHY_ANIM_1,
    /*  2 */ ENHY_ANIM_2,
    /*  3 */ ENHY_ANIM_3,
    /*  4 */ ENHY_ANIM_4,
    /*  5 */ ENHY_ANIM_5,
    /*  6 */ ENHY_ANIM_6,
    /*  7 */ ENHY_ANIM_7,
    /*  8 */ ENHY_ANIM_8,
    /*  9 */ ENHY_ANIM_9,
    /* 10 */ ENHY_ANIM_10,
    /* 11 */ ENHY_ANIM_11,
    /* 12 */ ENHY_ANIM_12,
    /* 13 */ ENHY_ANIM_13,
    /* 14 */ ENHY_ANIM_14,
    /* 15 */ ENHY_ANIM_15,
    /* 16 */ ENHY_ANIM_16,
    /* 17 */ ENHY_ANIM_17,
    /* 18 */ ENHY_ANIM_18,
    /* 19 */ ENHY_ANIM_19,
    /* 20 */ ENHY_ANIM_20,
    /* 21 */ ENHY_ANIM_21,
    /* 22 */ ENHY_ANIM_22,
    /* 23 */ ENHY_ANIM_23,
    /* 24 */ ENHY_ANIM_24,
    /* 25 */ ENHY_ANIM_25,
    /* 26 */ ENHY_ANIM_26
};


struct EnHyModelInfo {
    /* 0x00 */ u8 headInfoIndex;  // EnHyHeadIndex
    /* 0x01 */ u8 skelInfoIndex2; // EnHySkeletonIndex, see EnHy#objBankIndexSkel2
    /* 0x02 */ Color_RGBA8 envColorSeg8;
    /* 0x06 */ u8 skelInfoIndex1; // EnHySkeletonIndex, see EnHy#objBankIndexSkel1
    /* 0x07 */ Color_RGBA8 envColorSeg9;
    /* 0x0B */ u8 animInfoIndex; // EnHyAnimationIndex
};


struct EnHyColliderInfo {
    /* 0x00 */ Vec3s offset;
    /* 0x06 */ s16 radius;
    /* 0x08 */ s16 height;
};


struct EnHyInit1Info {
    /* 0x00 */ u8 unkPresetIndex;
    /* 0x04 */ f32 unkValueChild;
    /* 0x08 */ f32 unkValueAdult;
};


struct EnHyInit2Info {
    /* 0x00 */ f32 shadowScale;
    /* 0x04 */ Vec3f modelOffset;
    /* 0x10 */ f32 scale;
    /* 0x14 */ s8 targetMode;
    /* 0x18 */ f32 unkRange;
};
struct EnHy {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnHyActionFunc actionFunc;
    /* 0x0194 */ char unk_194; // unused
    /* 0x0195 */ u8 pathReverse;
    /* 0x0196 */ s32 objBankIndexHead;
    /* 0x0197 */ s32 objBankIndexSkel2; // 7 < limb < 15 (upper part?) (always same as objBankIndexSkel1)
    /* 0x0198 */ s32 objBankIndexSkel1; // sets the object used when drawing the skeleton for limb <= 7 (lower part?)
    /* 0x0199 */ s32 objBankIndexOsAnime;
    /* 0x019C */ ColliderCylinder collider;
    /* 0x01E8 */ struct_80034A14_arg1 unk_1E8;
    /* 0x0210 */ Path* path;
    /* 0x0214 */ s8 waypoint;
    /* 0x0215 */ s8 unk_215;
    /* 0x0216 */ char unk_216[2]; // unused
    /* 0x0218 */ s16 curEyeIndex;
    /* 0x021A */ s16 nextEyeIndexTimer;
    /* 0x021C */ s16 unk_21C[16]; // bodyWiggleY ?
    /* 0x023C */ s16 unk_23C[16]; // bodyWiggleZ ?
    /* 0x025C */ f32 unkRange;
    /* 0x0260 */ s32 unkGetItemId;
    /* 0x0264 */ Vec3f modelOffset;
    /* 0x0270 */ Vec3s jointTable[16];
    /* 0x02D0 */ Vec3s morphTable[16];
    /* 0x0330 */ u16 unk_330;
}; 


