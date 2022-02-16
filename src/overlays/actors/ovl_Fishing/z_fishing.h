#pragma once
#define Z_FISHING_H

#include "ultra64.h"
#include "global.h"

struct Fishing;



struct FishingFishInit {
    /* 0x00 */ u8 unk_00;
    /* 0x02 */ Vec3s pos;
    /* 0x08 */ u8 unk_08;
    /* 0x0C */ f32 unk_0C;
};

enum FishingEffectType {
    /* 0x00 */ FS_EFF_NONE,
    /* 0x01 */ FS_EFF_RIPPLE,
    /* 0x02 */ FS_EFF_DUST_SPLASH,
    /* 0x03 */ FS_EFF_WATER_DUST,
    /* 0x04 */ FS_EFF_BUBBLE,
    /* 0x05 */ FS_EFF_RAIN_DROP,
    /* 0x06 */ FS_EFF_OWNER_HAT,
    /* 0x07 */ FS_EFF_RAIN_RIPPLE,
    /* 0x08 */ FS_EFF_RAIN_SPLASH
};


struct FishingEffect {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f vel;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ u8 type;
    /* 0x25 */ u8 timer;
    /* 0x26 */ char unk_26[0x04];
    /* 0x2A */ s16 alpha;
    /* 0x2C */ s16 unk_2C;
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
};

enum FishingPropType {
    /* 0x00 */ FS_PROP_NONE,
    /* 0x01 */ FS_PROP_REED,
    /* 0x02 */ FS_PROP_LILY_PAD,
    /* 0x03 */ FS_PROP_ROCK,
    /* 0x04 */ FS_PROP_WOOD_POST,
    /* 0x23 */ FS_PROP_INIT_STOP = 0x23
};


struct FishingPropInit {
    /* 0x00 */ u8 type;
    /* 0x02 */ Vec3s pos;
};
 

struct FishingProp {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 rotX;
    /* 0x10 */ f32 rotY;
    /* 0x14 */ f32 reedAngle;
    /* 0x18 */ Vec3f projectedPos;
    /* 0x24 */ f32 scale;
    /* 0x28 */ s16 lilyPadAngle;
    /* 0x2C */ f32 lilyPadOffset;
    /* 0x30 */ u8 type;
    /* 0x32 */ s16 timer;
    /* 0x34 */ u8 shouldDraw;
    /* 0x38 */ f32 drawDistance;
};
 

enum FishingGroupFishType {
    /* 0x00 */ FS_GROUP_FISH_NONE,
    /* 0x01 */ FS_GROUP_FISH_NORMAL
};

struct FishingGroupFish {
    /* 0x00 */ u8 type;
    /* 0x02 */ s16 timer;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ Vec3f projectedPos;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ u8 shouldDraw;
};
struct Fishing {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ char unk_14C[0x004];
    /* 0x0150 */ u8 unk_150;
    /* 0x0151 */ u8 unk_151;
    /* 0x0152 */ u8 unk_152;
    /* 0x0154 */ s16 unk_154;
    /* 0x0156 */ u8 unk_156;
    /* 0x0157 */ u8 unk_157;
    /* 0x0158 */ s16 unk_158;
    /* 0x015A */ s16 unk_15A;
    /* 0x015C */ s16 unk_15C;
    /* 0x015E */ s16 unk_15E;
    /* 0x0160 */ s16 unk_160;
    /* 0x0162 */ s16 unk_162;
    /* 0x0164 */ s16 unk_164;
    /* 0x0166 */ s16 unk_166;
    /* 0x0168 */ s16 unk_168;
    /* 0x016A */ s16 unk_16A;
    /* 0x016C */ s16 unk_16C;
    /* 0x016E */ s16 unk_16E;
    /* 0x0170 */ s16 unk_170;
    /* 0x0172 */ s16 unk_172;
    /* 0x0174 */ s16 unk_174;
    /* 0x0176 */ s16 unk_176;
    /* 0x0178 */ s16 unk_178;
    /* 0x017A */ s16 unk_17A[4];
    /* 0x0184 */ f32 unk_184;
    /* 0x0188 */ f32 unk_188;
    /* 0x018C */ f32 unk_18C;
    /* 0x0190 */ f32 unk_190;
    /* 0x0194 */ f32 unk_194;
    /* 0x0198 */ f32 unk_198;
    /* 0x019C */ f32 unk_19C;
    /* 0x01A0 */ s16 unk_1A0;
    /* 0x01A2 */ s16 unk_1A2;
    /* 0x01A4 */ s16 unk_1A4;
    /* 0x01A8 */ f32 unk_1A8;
    /* 0x01AC */ f32 unk_1AC;
    /* 0x01B0 */ f32 unk_1B0;
    /* 0x01B4 */ Vec3f unk_1B4;
    /* 0x01C0 */ Vec3f fishMouthPos;
    /* 0x01CC */ s16 unk_1CC[3];
    /* 0x01D2 */ u8 unk_1D2;
    /* 0x01D3 */ u8 unk_1D3;
    /* 0x01D4 */ u8 unk_1D4;
    /* 0x01D5 */ u8 unk_1D5;
    /* 0x01D8 */ SkelAnime skelAnime;
    /* 0x021C */ LightNode* lightNode;
    /* 0x0220 */ LightInfo lightInfo;
    /* 0x0230 */ ColliderJntSph collider;
    /* 0x0250 */ ColliderJntSphElement colliderElements[12];
}; 


