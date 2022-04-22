#pragma once
#define Z_EN_AM_H

#include "ultra64.h"
#include "global.h"

struct EnAm;

typedef void (*EnAmActionFunc)(struct EnAm*, GlobalContext*);



enum ArmosBehavior {
    /* 00 */ AM_BEHAVIOR_NONE,
    /* 01 */ AM_BEHAVIOR_DAMAGED,
    /* 03 */ AM_BEHAVIOR_DO_NOTHING = 3,
    /* 05 */ AM_BEHAVIOR_5 = 5, // checked but never set
    /* 06 */ AM_BEHAVIOR_STUNNED,
    /* 07 */ AM_BEHAVIOR_GO_HOME,
    /* 08 */ AM_BEHAVIOR_RICOCHET,
    /* 10 */ AM_BEHAVIOR_AGGRO = 10
};


enum ArmosDamageEffect {
    /* 00 */ AM_DMGEFF_NONE, // used by anything that cant kill the armos
    /* 01 */ AM_DMGEFF_NUT,
    /* 06 */ AM_DMGEFF_STUN = 6, // doesnt include deku nuts
    /* 13 */ AM_DMGEFF_ICE = 13,
    /* 14 */ AM_DMGEFF_MAGIC_FIRE_LIGHT,
    /* 15 */ AM_DMGEFF_KILL // any damage source that can kill the armos (and isnt a special case)
};
struct EnAm {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ SkelAnime skelAnime;
    /* 0x01A8 */ s32 behavior;
    /* 0x01AC */ Vec3s jointTable[14];
    /* 0x0200 */ Vec3s morphTable[14];
    /* 0x0254 */ EnAmActionFunc actionFunc;
    /* 0x0258 */ s16 unk_258;
    /* 0x025A */ s16 cooldownTimer;
    /* 0x025C */ s16 attackTimer; // start going back home after reaching 0
    /* 0x025E */ s16 iceTimer;
    /* 0x0260 */ s16 deathTimer; // explode after reaching 0
    /* 0x0262 */ s16 panicSpinRot; // used when panicking before death
    /* 0x0264 */ s16 unk_264;
    /* 0x0266 */ u8 textureBlend; // 0 = statue textures; 255 = enemy textures
    /* 0x0267 */ u8 damageEffect;
    /* 0x0267 */ Vec3f shakeOrigin; // center point to shake around when waking up
    /* 0x0274 */ ColliderCylinder hurtCollider;
    /* 0x02C0 */ ColliderCylinder blockCollider;
    /* 0x030C */ ColliderQuad hitCollider;
}; 

enum ArmosType {
    /* 0 */ ARMOS_STATUE,
    /* 1 */ ARMOS_ENEMY
};


