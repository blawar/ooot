#pragma once
#define Z_EN_NUTSBALL_H

#include "global.h"
#include "ultra64.h"

struct EnNutsball;

typedef void (*EnNutsballActionFunc)(struct EnNutsball*, GlobalContext*);

struct EnNutsball
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnNutsballActionFunc actionFunc;
	/* 0x0150 */ s32 objBankIndex;
	/* 0x0152 */ Timer timer;
	/* 0x0154 */ ColliderCylinder collider;
};
