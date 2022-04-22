#pragma once
#define Z_EN_IT_H

#include "global.h"
#include "ultra64.h"

struct EnIt;

struct EnIt
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ u32 unk_14C;
	/* 0x0150 */ ColliderCylinder collider;
};
