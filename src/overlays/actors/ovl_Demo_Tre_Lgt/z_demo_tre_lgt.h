#pragma once
#define Z_DEMO_TRE_LGT_H

#include "ultra64.h"
#include "global.h"

struct DemoTreLgt;

typedef void (*DemoTreLgtActionFunc)(struct DemoTreLgt*, GlobalContext*);



struct DemoTreLgtInfo {
    /* 0x00 */ f32 startFrame;
    /* 0x04 */ f32 endFrame;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
};
struct DemoTreLgt {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnimeCurve skelCurve;
    /* 0x016C */ s32 action;
    /* 0x0170 */ u32 unk_170; // some sort of alpha
    /* 0x0174 */ u32 unk_174; // another sort of alpha
    /* 0x0178 */ u8 status;
}; 

enum DemoTreLgtAction {
    /* 0x00 */ DEMO_TRE_LGT_ACTION_WAIT, // wait until animation is needed
    /* 0x01 */ DEMO_TRE_LGT_ACTION_ANIMATE
};


