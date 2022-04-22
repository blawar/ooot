#pragma once
#define Z_EN_FHG_FIRE_H

#include "global.h"
#include "ultra64.h"

struct EnFhgFire;

typedef void (*EnFhgFireUpdateFunc)(struct EnFhgFire*, GlobalContext*);

enum FhgFireParam
{
	/*   1 */ FHGFIRE_LIGHTNING_STRIKE = 1,
	/*  35 */ FHGFIRE_LIGHTNING_SHOCK = 35,
	/*  36 */ FHGFIRE_LIGHTNING_BURST,
	/*  38 */ FHGFIRE_SPEAR_LIGHT = 38,
	/*  39 */ FHGFIRE_WARP_EMERGE,
	/*  40 */ FHGFIRE_WARP_RETREAT,
	/*  41 */ FHGFIRE_WARP_DEATH,
	/*  50 */ FHGFIRE_ENERGY_BALL = 50,
	/* 100 */ FHGFIRE_LIGHTNING_TRAIL = 100
};

enum FhgLightMode
{
	/* 0 */ FHGFIRE_LIGHT_GREEN,
	/* 1 */ FHGFIRE_LIGHT_BLUE,
	/* 2 */ FHGFIRE_LIGHT_REFLECT
};

enum FhgFireS16Var
{
	/*  0 */ FHGFIRE_TIMER,
	/*  1 */ FHGFIRE_FX_TIMER,
	/*  2 */ FHGFIRE_US_2,
	/*  3 */ FHGFIRE_VARIANCE_TIMER,
	/*  4 */ FHGFIRE_FIRE_MODE,
	/*  5 */ FHGFIRE_RETURN_COUNT,
	/*  6 */ FHGFIRE_KILL_TIMER,
	/*  7 */ FHGFIRE_SHORT_COUNT
};

enum FhgFireF32Var
{
	/*  0 */ FHGFIRE_ALPHA,
	/*  1 */ FHGFIRE_UF_1,
	/*  2 */ FHGFIRE_UF_2,
	/*  3 */ FHGFIRE_SCALE,
	/*  4 */ FHGFIRE_UF_4,
	/*  5 */ FHGFIRE_WARP_TEX_1_X,
	/*  6 */ FHGFIRE_WARP_TEX_1_Y,
	/*  7 */ FHGFIRE_WARP_TEX_2_X,
	/*  8 */ FHGFIRE_WARP_TEX_2_Y,
	/*  9 */ FHGFIRE_WARP_TEX_SPEED,
	/* 10 */ FHGFIRE_WARP_ALPHA,
	/* 11 */ FHGFIRE_BURST_SCALE,
	/* 15 */ FHGFIRE_FLOAT_COUNT = 15
};

enum StrikeMode
{
	/*  0 */ STRIKE_INIT,
	/* 10 */ STRIKE_BURST = 10,
	/* 11 */ STRIKE_TRAILS
};

enum TrailMode
{
	/* 0 */ TRAIL_INIT,
	/* 1 */ TRAIL_APPEAR,
	/* 2 */ TRAIL_DISSIPATE
};

enum BallKillMode
{
	/* 0 */ BALL_FIZZLE,
	/* 1 */ BALL_BURST,
	/* 2 */ BALL_IMPACT
};
struct EnFhgFire
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnFhgFireUpdateFunc updateFunc;
	/* 0x0150 */ s16 work[FHGFIRE_SHORT_COUNT];
	/* 0x0160 */ f32 fwork[FHGFIRE_FLOAT_COUNT];
	/* 0x019C */ LightNode* lightNode;
	/* 0x01A0 */ LightInfo lightInfo;
	/* 0x01B0 */ ColliderCylinder collider;
	/* 0x01FC */ u8 lensFlareOn;
	/* 0x01FE */ Timer lensFlareTimer;
	/* 0x0200 */ f32 lensFlareScale;
};
