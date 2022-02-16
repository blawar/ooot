#pragma once
#define Z_EN_ZO_H

#include "ultra64.h"
#include "global.h"

struct EnZo;

struct EnZoEffect {
    /* 0x00 */ u8 type;
    /* 0x04 */ f32 scale;
    /* 0x08 */ f32 targetScale;
    /* 0x0C */ Color_RGBA8 color;
    /* 0x10 */ u32 pad;
    /* 0x14 */ Vec3f pos;
    /* 0x20 */ Vec3f vel;
    /* 0x2C */ Vec3f vec; // Usage specific
}; 

typedef void (*EnZoActionFunc)(struct EnZo*, GlobalContext*);


enum EnZoEffectType {
    /* 0 */ ENZO_EFFECT_NONE,
    /* 1 */ ENZO_EFFECT_RIPPLE,
    /* 2 */ ENZO_EFFECT_SPLASH,
    /* 3 */ ENZO_EFFECT_BUBBLE
};
struct EnZo {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnZoActionFunc actionFunc;
    /* 0x0194 */ struct_80034A14_arg1 unk_194;
    /* 0x01BC */ ColliderCylinder collider;
    /* 0x0208 */ u8 canSpeak;
    /* 0x020A */ Vec3s jointTable[20];
    /* 0x0282 */ Vec3s morphTable[20];
    /* 0x02FC */ EnZoEffect effects[15];
    /* 0x0644 */ f32 dialogRadius;
    /* 0x0648 */ f32 alpha;
    /* 0x064C */ s16 unk_64C;
    /* 0x064E */ Timer rippleTimer;
    /* 0x0650 */ Timer timeToDive;
    /* 0x0652 */ Timer blinkTimer;
    /* 0x0654 */ s16 eyeTexture;
    /* 0x0656 */ s16 unk_656[20];
    /* 0x067E */ s16 unk_67E[20];
}; 


