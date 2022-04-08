#pragma once
#define Z_BG_SPOT16_DOUGHNUT_H

#include "global.h"
#include "ultra64.h"

struct BgSpot16Doughnut;

struct BgSpot16Doughnut
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ u16 fireFlag;
	/* 0x014E */ char pad[0x02];
	/* 0x0150 */ u8 envColorAlpha;
};
