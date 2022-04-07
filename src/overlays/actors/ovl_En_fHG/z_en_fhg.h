#pragma once
#define Z_EN_FHG_H

#include "ultra64.h"
#include "global.h"
#include "z64actor.h"

struct EnfHG;

typedef void (*EnfHGActionFunc)(struct EnfHG*, struct GlobalContext*);

enum EnfHGSignal {
    /*  0 */ FHG_NO_SIGNAL,
    /*  1 */ FHG_RAISE_SPEAR,
    /*  2 */ FHG_REAR,
    /*  3 */ FHG_LIGHTNING,
    /*  4 */ FHG_RESET,
    /*  5 */ FHG_RIDE,
    /* 10 */ FHG_SPUR = 10,
    /* 11 */ FHG_FINISH,
    /* -1 */ FHG_START_FIGHT = 255
};


struct EnfHGPainting {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ s16 yRot;
};
 

enum EnfHGIntroState {
    /*  0 */ INTRO_WAIT,
    /*  1 */ INTRO_START,
    /*  2 */ INTRO_FENCE,
    /*  3 */ INTRO_BACK,
    /*  4 */ INTRO_REVEAL,
    /*  5 */ INTRO_CUT,
    /*  6 */ INTRO_LAUGH,
    /*  7 */ INTRO_TITLE,
    /*  8 */ INTRO_RETREAT,
    /*  9 */ INTRO_FINISH,
    /* 15 */ INTRO_READY = 15
};
struct EnfHG {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ u8 bossGndSignal;
    /* 0x014D */ u8 bossGndInPainting;
    /* 0x014E */ u8 killActor;
    /* 0x014F */ u8 fhgFireKillWarp;
    /* 0x0150 */ Vec3f cameraEye;
    /* 0x015C */ Vec3f cameraAt;
    /* 0x0168 */ Vec3f cameraEyeVel;
    /* 0x0174 */ Vec3f cameraAtVel;
    /* 0x0180 */ Vec3f hoofSfxPos;
    /* 0x018C */ Vec3f inPaintingPos;
    /* 0x0198 */ f32 inPaintingVelX;
    /* 0x019C */ f32 inPaintingVelZ;
    /* 0x0198 */ f32 damageSpeedMod;
    /* 0x01A4 */ f32 approachRate;
    /* 0x01A8 */ f32 cameraSpeedMod;
    /* 0x01AC */ f32 cameraPanZ;
    /* 0x01B0 */ char unk_1B0[0x10];
    /* 0x01C0 */ Timer gallopTimer;
    /* 0x01C2 */ s16 curPainting;
    /* 0x01C4 */ s16 targetPainting;
    /* 0x01C6 */ s16 turnTarget;
    /* 0x01C8 */ s16 spawnedWarp;
    /* 0x01CA */ s16 cutsceneState;
    /* 0x01CC */ s16 cutsceneCamera;
    /* 0x01CE */ char unk_1CE[6];
    /* 0x01D4 */ Timer timers[5];
    /* 0x01DE */ Timer hitTimer;
    /* 0x01E0 */ s16 turnRot;
    /* 0x01E2 */ char unk_1E2[6];
    /* 0x01E8 */ f32 warpColorFilterR;
    /* 0x01EC */ f32 warpColorFilterG;
    /* 0x01F0 */ f32 warpColorFilterB;
    /* 0x01F4 */ f32 warpColorFilterUnk1;
    /* 0x01F8 */ f32 warpColorFilterUnk2;
    /* 0x01FC */ EnfHGActionFunc actionFunc;
    /* 0x0200 */ char unk_200[4];
    /* 0x0204 */ PSkinAwb skin;
}; 


