#pragma once
#define Z_DEMO_SA_H

#include "ultra64.h"
#include "global.h"

struct DemoSa;

typedef void (*DemoSaActionFunc)(struct DemoSa*, GlobalContext*);
typedef void (*DemoSaDrawFunc)(struct DemoSa*, GlobalContext*);



enum SariaEyeState {
    /* 0 */ SARIA_EYE_OPEN,
    /* 1 */ SARIA_EYE_HALF,
    /* 2 */ SARIA_EYE_CLOSED,
    /* 3 */ SARIA_EYE_SUPRISED,
    /* 4 */ SARIA_EYE_SAD
};


enum SariaMouthState {
    /* 0 */ SARIA_MOUTH_CLOSED2,
    /* 1 */ SARIA_MOUTH_SUPRISED,
    /* 2 */ SARIA_MOUTH_CLOSED,
    /* 3 */ SARIA_MOUTH_SMILING_OPEN,
    /* 4 */ SARIA_MOUTH_FROWNING
};
struct DemoSa {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ s16 eyeIndex;
    /* 0x0192 */ s16 blinkTimer;
    /* 0x0194 */ s16 mouthIndex;
    /* 0x0198 */ s32 action;
    /* 0x019C */ s32 drawConfig;
    /* 0x01A0 */ f32 unk_1A0;
    /* 0x01A4 */ s32 alpha;
    /* 0x01A8 */ s32 unk_1A8;
    /* 0x01AC */ s32 unk_1AC;
    /* 0x01B0 */ s32 unk_1B0;
}; 


