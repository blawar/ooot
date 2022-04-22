#pragma once
#define Z_EN_PART_H

#include "global.h"
#include "ultra64.h"

struct EnPart;

typedef void (*EnPartActionFunc)(struct EnPart*, GlobalContext*);

struct EnPart
{
	/* 0x000 */ Actor actor;
	/* 0x14C */ u8 action;
	/* 0x14E */ Timer timer;
	/* 0x150 */ Gfx* displayList;
	/* 0x154 */ f32 rotZ;
	/* 0x158 */ f32 rotZSpeed;
};
