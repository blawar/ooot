#pragma once
#define Z_BG_SPOT18_SHUTTER_H

#include "global.h"
#include "ultra64.h"

struct BgSpot18Shutter;

typedef void (*BgSpot18ShutterActionFunc)(struct BgSpot18Shutter*, GlobalContext*);

struct BgSpot18Shutter
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgSpot18ShutterActionFunc actionFunc;
};
