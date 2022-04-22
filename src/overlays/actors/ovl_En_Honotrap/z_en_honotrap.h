#pragma once
#define Z_EN_HONOTRAP_H

#include "global.h"
#include "ultra64.h"

struct EnHonotrap;

typedef void (*EnHonotrapActionFunc)(struct EnHonotrap*, GlobalContext*);

typedef union
{
	struct
	{
		ColliderTris tris;
		ColliderTrisElement elements[2];
	};
	ColliderCylinder cyl;
} EnHonotrapCollider;

enum EnHonotrapEyeState
{
	/* 0 */ HONOTRAP_EYE_OPEN,
	/* 1 */ HONOTRAP_EYE_HALF,
	/* 2 */ HONOTRAP_EYE_CLOSE,
	/* 3 */ HONOTRAP_EYE_SHUT
};
struct EnHonotrap
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnHonotrapActionFunc actionFunc;
	/* 0x0150 */ EnHonotrapCollider collider;
	/* 0x0228 */ Timer timer;
	/* 0x022A */ s16 eyeState;
	/* 0x022C */ Vec3f targetPos;
	/* 0x0238 */ f32 speedMod;
	/* 0x023C */ s16 bobPhase;
	/* 0x023E */ s16 flameScroll;
	/* 0x0240 */ u8 colChkFlags;
};

enum EnHonotrapType
{
	HONOTRAP_EYE,
	HONOTRAP_FLAME_MOVE,
	HONOTRAP_FLAME_DROP
};
