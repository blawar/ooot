#pragma once
#define Z_BG_MORI_RAKKATENJO_H

#include "global.h"
#include "ultra64.h"

struct BgMoriRakkatenjo;

typedef void (*BgMoriRakkatenjoActionFunction)(struct BgMoriRakkatenjo*, GlobalContext*);

struct BgMoriRakkatenjo
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgMoriRakkatenjoActionFunction actionFunc;
	/* 0x0168 */ TimerS32 timer;
	/* 0x016C */ s32 bounceCount;
	/* 0x0170 */ s32 fallCount;
	/* 0x0174 */ s32 moriTexObjIndex;
};
