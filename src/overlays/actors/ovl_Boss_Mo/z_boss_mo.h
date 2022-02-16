#pragma once
#define Z_BOSS_MO_H

#include "ultra64.h"
#include "global.h"

struct BossMo;

typedef void (*BossMoActionFunc)(struct BossMo*, GlobalContext*);

enum BossMoTentS16Var {
    /* 0 */ MO_TENT_ACTION_STATE,
    /* 1 */ MO_TENT_MOVE_TIMER,
    /* 2 */ MO_TENT_VAR_TIMER,
    /* 3 */ MO_TENT_UNK_TIMER,
    /* 4 */ MO_TENT_INVINC_TIMER,
    /* 5 */ MO_TENT_BASE_TEX1_X,
    /* 6 */ MO_TENT_BASE_TEX1_Y,
    /* 7 */ MO_TENT_BASE_TEX2_X,
    /* 8 */ MO_TENT_BASE_TEX2_Y,
    /* 9 */ MO_TENT_SHORT_MAX
};

enum BossMoCoreS16Var {
    /* 0 */ MO_CORE_ACTION_STATE,
    /* 1 */ MO_CORE_MOVE_TIMER,
    /* 2 */ MO_CORE_VAR_TIMER,
    /* 3 */ MO_CORE_DMG_FLASH_TIMER,
    /* 4 */ MO_CORE_INVINC_TIMER,
    /* 5 */ MO_CORE_SHORT_5,
    /* 6 */ MO_CORE_POS_IN_TENT,
    /* 7 */ MO_CORE_DRAW_SHADOW,
    /* 8 */ MO_CORE_WAIT_IN_WATER,
    /* 9 */ MO_CORE_SHORT_MAX
};

enum BossMoTentF32Var {
    /* 0 */ MO_TENT_SWING_LAG_X,
    /* 1 */ MO_TENT_SWING_SIZE_X,
    /* 2 */ MO_TENT_SWING_RATE_X,
    /* 3 */ MO_TENT_SWING_LAG_Z,
    /* 4 */ MO_TENT_SWING_SIZE_Z,
    /* 5 */ MO_TENT_SWING_RATE_Z,
    /* 6 */ MO_TENT_MAX_STRETCH,
    /* 7 */ MO_TENT_FLOAT_MAX
};

enum BossMoCoreF32Var {
    /* 0 */ MO_CORE_INTRO_WATER_ALPHA,
    /* 1 */ MO_CORE_FLOAT_MAX
};

#define MO_SHORT_MAX MAX((s32)MO_TENT_SHORT_MAX, (s32)MO_CORE_SHORT_MAX)
#define MO_FLOAT_MAX MAX((s32)MO_TENT_FLOAT_MAX, (s32)MO_CORE_FLOAT_MAX)


struct BossMoEffect {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f vel;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ u8 type;
    /* 0x25 */ u8 timer;
    /* 0x26 */ u8 stopTimer;
    /* 0x28 */ s16 unk_28; // unused?
    /* 0x2A */ s16 alpha;
    /* 0x2C */ s16 rippleMode;
    /* 0x2E */ s16 maxAlpha;
    /* 0x30 */ f32 scale;
    /* 0x30 */ f32 fwork[2];
    /* 0x3C */ Vec3f* targetPos;
};


enum BossMoEffectType {
    /* 0 */ MO_FX_NONE,
    /* 1 */ MO_FX_SMALL_RIPPLE,
    /* 2 */ MO_FX_BIG_RIPPLE,
    /* 3 */ MO_FX_DROPLET,
    /* 4 */ MO_FX_SPLASH,
    /* 5 */ MO_FX_SPLASH_TRAIL,
    /* 6 */ MO_FX_WET_SPOT,
    /* 7 */ MO_FX_BUBBLE
};


enum BossMoTentState {
    /*   0 */ MO_TENT_READY,
    /*   1 */ MO_TENT_SWING,
    /*   2 */ MO_TENT_ATTACK,
    /*   3 */ MO_TENT_CURL,
    /*   4 */ MO_TENT_GRAB,
    /*   5 */ MO_TENT_SHAKE,
    /*  10 */ MO_TENT_WAIT = 10,
    /*  11 */ MO_TENT_SPAWN,
    /* 100 */ MO_TENT_CUT = 100,
    /* 101 */ MO_TENT_RETREAT,
    /* 102 */ MO_TENT_DESPAWN,
    /* 200 */ MO_TENT_DEATH_START = 200,
    /* 201 */ MO_TENT_DEATH_1,
    /* 202 */ MO_TENT_DEATH_2,
    /* 203 */ MO_TENT_DEATH_3,
    /* 205 */ MO_TENT_DEATH_5 = 205,
    /* 206 */ MO_TENT_DEATH_6
};


enum BossMoCoreState {
    /* -11 */ MO_CORE_UNUSED = -11,
    /*   0 */ MO_CORE_MOVE = 0,
    /*   1 */ MO_CORE_MAKE_TENT,
    /*   2 */ MO_CORE_UNDERWATER,
    /*   5 */ MO_CORE_STUNNED = 5,
    /*  10 */ MO_CORE_ATTACK = 10,
    /*  11 */ MO_CORE_RETREAT,
    /*  20 */ MO_CORE_INTRO_WAIT = 20,
    /*  21 */ MO_CORE_INTRO_REVEAL
};


enum BossMoCsState {
    /*   0 */ MO_BATTLE,
    /*   1 */ MO_INTRO_WAIT,
    /*   2 */ MO_INTRO_START,
    /*   3 */ MO_INTRO_SWIM,
    /*   4 */ MO_INTRO_REVEAL,
    /*   5 */ MO_INTRO_FINISH,
    /* 100 */ MO_DEATH_START = 100,
    /* 101 */ MO_DEATH_DRAIN_WATER_1,
    /* 102 */ MO_DEATH_DRAIN_WATER_2,
    /* 103 */ MO_DEATH_CEILING,
    /* 104 */ MO_DEATH_DROPLET,
    /* 105 */ MO_DEATH_FINISH,
    /* 150 */ MO_DEATH_MO_CORE_BURST = 150
};
struct BossMo {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ Actor* otherTent;
    /* 0x0150 */ BossMoActionFunc actionFunc;
    /* 0x0154 */ u8 tent2KillTimer;
    /* 0x0155 */ u8 hitCount;
    /* 0x0156 */ u8 tentSpawnPos;
    /* 0x0158 */ s16 work[MO_SHORT_MAX];
    /* 0x016A */ s16 widthIndex;
    /* 0x016C */ s16 pulsePhase;
    /* 0x016E */ s16 xSwing;
    /* 0x0170 */ s16 zSwing;
    /* 0x0172 */ s16 cutIndex;
    /* 0x0174 */ s16 meltIndex;
    /* 0x0176 */ s16 linkToLeft;
    /* 0x0178 */ s16 mashCounter;
    /* 0x017A */ s16 noBubbles;
    /* 0x017C */ s16 sfxTimer;
    /* 0x017E */ s16 timers[5];
    /* 0x0188 */ f32 fwork[MO_FLOAT_MAX];
    /* 0x01A4 */ f32 baseAlpha;
    /* 0x01A8 */ f32 cutScale;
    /* 0x01AC */ f32 waterTex1x;
    /* 0x01B0 */ f32 waterTex1y;
    /* 0x01B4 */ f32 waterTex2x;
    /* 0x01B8 */ f32 waterTex2y;
    /* 0x01BC */ f32 waterLevel;
    /* 0x01C0 */ f32 flattenRate;
    /* 0x01C4 */ f32 waterTexAlpha;
    /* 0x01C8 */ f32 waterLevelMod;
    /* 0x01CC */ s16 baseBubblesTimer;
    /* 0x01CE */ s16 attackAngleMod;
    /* 0x01D0 */ u8 unk_1D0; // unused?
    /* 0x01D1 */ u8 drawActor;
    /* 0x01D2 */ u8 linkHitTimer;
    /* 0x01D4 */ Vec3f targetPos;
    /* 0x01E0 */ f32 tentRippleSize;
    /* 0x01E4 */ PosRot grabPosRot;
    /* 0x01F8 */ f32 tentWidth[300];
    /* 0x06A8 */ Vec3f tentStretch[41];
    /* 0x0894 */ Vec3f tentScale[41];
    /* 0x0A80 */ Vec3f tentRipple[41];
    /* 0x0C6C */ Vec3s tentRot[41];
    /* 0x0D64 */ f32 tentMaxAngle;
    /* 0x0D68 */ f32 tentSpeed;
    /* 0x0D6C */ f32 tentPulse;
    /* 0x0D70 */ Vec3f tentPos[41];
    /* 0x0F5C */ f32 cameraZoom;
    /* 0x0F60 */ s16 csState;
    /* 0x0F62 */ s16 csCamera;
    /* 0x0F64 */ s16 targetIndex;
    /* 0x0F68 */ Vec3f cameraEye;
    /* 0x0F74 */ Vec3f cameraAt;
    /* 0x0F80 */ Vec3f cameraUp;
    /* 0x0F8C */ char unk_F8C[0x18];
    /* 0x0FA4 */ Vec3f cameraEyeVel;
    /* 0x0FB0 */ Vec3f cameraAtVel;
    /* 0x0FBC */ Vec3f cameraNextEye;
    /* 0x0FC8 */ Vec3f cameraEyeMaxVel;
    /* 0x0FD4 */ Vec3f cameraNextAt;
    /* 0x0FE0 */ Vec3f cameraAtMaxVel;
    /* 0x0FEC */ f32 cameraSpeedMod;
    /* 0x0FF0 */ f32 cameraAccel;
    /* 0x0FF4 */ char unk_FF4[8];
    /* 0x0FFC */ f32 cameraDist;
    /* 0x1000 */ f32 cameraSpeed;
    /* 0x1004 */ f32 cameraYaw;
    /* 0x1008 */ f32 cameraYawRate;
    /* 0x100C */ f32 cameraYawShake;
    /* 0x1010 */ Vec3f tentTipPos;
    /* 0x101C */ ColliderJntSph tentCollider;
    /* 0x103C */ ColliderJntSphElement tentElements[19];
    /* 0x14FC */ ColliderCylinder coreCollider;
    /* 0x1548 */ char unk_1548[0x44];
}; 

#define BOSSMO_CORE -1
#define BOSSMO_TENTACLE 100


