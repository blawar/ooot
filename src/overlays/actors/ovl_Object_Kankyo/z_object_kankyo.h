#pragma once
#define Z_OBJECT_KANKYO_H

#include "global.h"
#include "ultra64.h"

struct ObjectKankyo;

typedef void (*ObjectKankyoActionFunc)(struct ObjectKankyo*, GlobalContext*);

struct ObjectKankyoEffect
{
	/* 0x00 */ u8 state;
	/* 0x04 */ VecPos pos; // relative to base
	/* 0x10 */ Vec3f prevPos;
	/* 0x1C */ Vec3f base;
	/* 0x28 */ Vec3f dirPhase; // input to sin/cos for movement direction
	/* 0x34 */ f32 speed;
	/* 0x38 */ f32 targetSpeed;
	/* 0x3C */ Timer alphaTimer;
	/* 0x3E */ u16 angle;
	/* 0x40 */ u8 alpha;
	/* 0x44 */ f32 size;
	/* 0x48 */ u16 angleVel;
	/* 0x4A */ u16 flightRadius;
	/* 0x4C */ f32 amplitude;
	/* 0x50 */ Timer timer;
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
