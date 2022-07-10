#pragma once
#define Z_EN_BX_H

#include "global.h"
#include "ultra64.h"

struct EnBx;

struct EnBx
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ TimerS16 unk_14C;
	/* 0x014E */ TimerS16 unk_14E;
	/* 0x0150 */ char unk_150[0x4];
	/* 0x0154 */ Vec3f unk_154[4];
	/* 0x0184 */ Vec3f unk_184[4];
	/* 0x01B4 */ Vec3s unk_1B4[4];
	/* 0x01CC */ ColliderCylinder collider;
	/* 0x0218 */ ColliderQuad colliderQuad;
};
