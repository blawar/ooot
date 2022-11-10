#pragma once
#define Z_OBJECT_KANKYO_H

#include "global.h"
#include "ultra64.h"

struct ObjectKankyo;

typedef void (*ObjectKankyoActionFunc)(struct ObjectKankyo*, GlobalContext*);

struct ObjectKankyoEffect
{
	/* 0x00 */ u8 state;
	/* 0x04 */ VecCounterF pos; // relative to base
	/* 0x10 */ VecCounterF prevPos;
	/* 0x1C */ VecCounterF base;
	/* 0x28 */ VecCounterF dirPhase; // input to sin/cos for movement direction
	/* 0x34 */ f32 speed;
	/* 0x38 */ f32 targetSpeed;
	/* 0x3C */ TimerU16 alphaTimer;
	/* 0x3E */ TimerU16 angle;
	/* 0x40 */ TimerU8 alpha;
	/* 0x44 */ f32 size;
	/* 0x48 */ u16 angleVel;
	/* 0x4A */ u16 flightRadius;
	/* 0x4C */ f32 amplitude;
	/* 0x50 */ TimerU16 timer;
};

struct ObjectKankyo
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ObjectKankyoEffect effects[64];
	/* 0x164C */ Vec3f prevEyePos;
	/* 0x1658 */ s32 requiredObjBankIndex;
	/* 0x1659 */ s32 requiredObjectLoaded;
	/* 0x165C */ ObjectKankyoActionFunc actionFunc;
};
