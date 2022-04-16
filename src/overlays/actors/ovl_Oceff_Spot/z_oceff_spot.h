#pragma once
#define Z_OCEFF_SPOT_H

#include "global.h"
#include "ultra64.h"

struct OceffSpot;

typedef void (*OceffSpotActionFunc)(struct OceffSpot*, GlobalContext*);

struct OceffSpot
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ LightNode* lightNode1;
	/* 0x0150 */ LightInfo lightInfo1;
	/* 0x0160 */ LightNode* lightNode2;
	/* 0x0164 */ LightInfo lightInfo2;
	/* 0x0174 */ f32 unk_174;
	/* 0x0178 */ TimerU16 timer;
	/* 0x017C */ OceffSpotActionFunc actionFunc;
};
