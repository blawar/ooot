#pragma once
#define Z_BG_SST_FLOOR_H

#include "global.h"
#include "ultra64.h"

struct BgSstFloor;

struct BgSstFloor
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x014C */ s16 drumPhase;
	/* 0x0166 */ s16 drumAmp;
	/* 0x0168 */ s16 drumHeight;
};

enum BgSstFloorParams
{
	/* 0 */ BONGOFLOOR_REST,
	/* 1 */ BONGOFLOOR_HIT
};
