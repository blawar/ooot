#pragma once
#define Z_MAGIC_FIRE_H

#include "ultra64.h"
#include "global.h"

struct MagicFire;



enum MagicFireAction {
    /* 0x00 */ DF_ACTION_INITIALIZE,
    /* 0x01 */ DF_ACTION_EXPAND_SLOWLY,
    /* 0x02 */ DF_ACTION_STOP_EXPANDING,
    /* 0x03 */ DF_ACTION_EXPAND_QUICKLY
};


enum MagicFireScreenTint {
    /* 0x00 */ DF_SCREEN_TINT_NONE,
    /* 0x01 */ DF_SCREEN_TINT_FADE_IN,
    /* 0x02 */ DF_SCREEN_TINT_MAINTAIN,
    /* 0x03 */ DF_SCREEN_TINT_FADE_OUT,
    /* 0x04 */ DF_SCREEN_TINT_FINISHED
};
struct MagicFire {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderCylinder collider;
    /* 0x0198 */ f32 alphaMultiplier;
    /* 0x019C */ f32 screenTintIntensity;
    /* 0x01A0 */ f32 scalingSpeed;
    /* 0x01A4 */ s16 action;
    /* 0x01A6 */ s16 screenTintBehaviour;
    /* 0x01A8 */ s16 actionTimer;
    /* 0x01AA */ s16 screenTintBehaviourTimer;
}; 


