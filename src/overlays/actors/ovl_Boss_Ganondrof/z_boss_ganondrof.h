#pragma once
#define Z_BOSS_GANONDROF_H

#include "global.h"
#include "ultra64.h"

struct BossGanondrof;

typedef void (*BossGanondrofActionFunc)(struct BossGanondrof*, GlobalContext*);

#define GND_REAL_BOSS 1
#define GND_FAKE_BOSS 10

#define GND_BOSSROOM_CENTER_X 14.0f
#define GND_BOSSROOM_CENTER_Y -33.0f
#define GND_BOSSROOM_CENTER_Z -3315.0f

enum BossGanondrofFlyMode
{
	/* 0 */ GND_FLY_PAINTING,
	/* 1 */ GND_FLY_NEUTRAL,
	/* 2 */ GND_FLY_VOLLEY,
	/* 3 */ GND_FLY_RETURN,
	/* 4 */ GND_FLY_CHARGE
};

enum BossGanondrofEyeState
{
	/* 0 */ GND_EYESTATE_NONE,
	/* 1 */ GND_EYESTATE_FADE,
	/* 2 */ GND_EYESTATE_BRIGHTEN
};

enum BossGanondrofF32Var
{
	/*  0 */ GND_FLOAT_SPEED,
	/*  1 */ GND_END_FRAME,
	/*  2 */ GND_EYE_BRIGHTNESS,
	/*  3 */ GND_CAMERA_ZOOM,
	/*  4 */ GND_CAMERA_ANGLE,
	/*  5 */ GND_EYE_ALPHA,
	/* 13 */ GND_FLOAT_COUNT = 13
};

enum BossGanondrofDeathState
{
	/* 0 */ NOT_DEAD,
	/* 1 */ DEATH_START,
	/* 2 */ DEATH_THROES,
	/* 3 */ DEATH_WARP,
	/* 4 */ DEATH_SCREAM,
	/* 5 */ DEATH_DISINTEGRATE,
	/* 6 */ DEATH_FINISH
};

enum BossGanondrofThrowAction
{
	/* 0 */ THROW_NORMAL,
	/* 1 */ THROW_SLOW
};

enum BossGanondrofStunnedAction
{
	/* 0 */ STUNNED_FALL,
	/* 1 */ STUNNED_GROUND
};

enum BossGanondrofChargeAction
{
	/* 0 */ CHARGE_WINDUP,
	/* 1 */ CHARGE_START,
	/* 2 */ CHARGE_ATTACK,
	/* 3 */ CHARGE_FINISH
};

enum BossGanondrofDeathAction
{
	/* 0 */ DEATH_SPASM,
	/* 1 */ DEATH_LIMP,
	/* 2 */ DEATH_HUNCHED
};
struct BossGanondrof
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ BossGanondrofActionFunc actionFunc;
	Timer GND_VARIANCE_TIMER;
	s16 GND_US_1;
	s16 GND_US_2;
	s16 GND_US_3;
	Timer GND_UNKTIMER_1;
	Timer GND_UNKTIMER_2;
	Timer GND_INVINC_TIMER;
	s16 GND_ACTION_STATE;
	s16 GND_THROW_FRAME;
	s16 GND_THROW_COUNT;
	s16 GND_MASK_OFF;
	s16 GND_EYE_STATE;
	Rotation GND_PARTICLE_ANGLE;
	s16 GND_BODY_DECAY_INDEX;
	s16 GND_BODY_DECAY_FLAG;
	s16 GND_LIMB_DECAY_INDEX;
	Timer GND_DEATH_ENV_TIMER;
	Timer GND_DEATH_SFX_TIMER;
	/* 0x01BC */ Timer timers[5];
	/* 0x01C6 */ u8 killActor;
	/* 0x01C7 */ u8 returnCount;
	/* 0x01C8 */ TimerU8 shockTimer;
	/* 0x01C9 */ u8 flyMode;
	/* 0x01CA */ u8 returnSuccess;
	/* 0x01CC */ f32 fwork[GND_FLOAT_COUNT];
	/* 0x0200 */ Vec3f spearTip;
	/* 0x020C */ Vec3f targetPos;
	/* 0x0218 */ Vec3f bodyPartsPos[27]; // only 25 used
	/* 0x035C */ s16 deathCamera;
	/* 0x035E */ s16 deathState;
	/* 0x0360 */ Vec3f cameraEye;
	/* 0x036C */ Vec3f cameraAt;
	/* 0x0378 */ Vec3f cameraEyeVel;
	/* 0x0384 */ Vec3f cameraAtVel;
	/* 0x0390 */ Vec3f cameraNextEye;
	/* 0x039C */ Vec3f cameraEyeMaxVel;
	/* 0x03A8 */ Vec3f cameraNextAt;
	/* 0x03B4 */ Vec3f cameraAtMaxVel;
	/* 0x03C0 */ f32 cameraSpeedMod;
	/* 0x03C4 */ f32 cameraAccel;
	/* 0x03C8 */ f32 legRotY;
	/* 0x03CC */ f32 legRotZ;
	/* 0x03D0 */ f32 legSplitY;
	/* 0x03D4 */ f32 armRotY;
	/* 0x03D8 */ f32 armRotZ;
	/* 0x03DC */ f32 rideRotZ[30]; // possibly only 25 used
	/* 0x0454 */ f32 rideRotY[30]; // possibly only 25 used
	/* 0x04CC */ LightNode* lightNode;
	/* 0x04D0 */ LightInfo lightInfo;
	/* 0x04E0 */ ColliderCylinder colliderBody;
	/* 0x052C */ ColliderCylinder colliderSpear;
};
