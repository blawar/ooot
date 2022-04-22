#pragma once
#define Z_BG_ICE_SHUTTER_H

#include "global.h"
#include "ultra64.h"

struct BgIceShutter;

typedef void (*BgIceShutterActionFunc)(struct BgIceShutter*, GlobalContext*);

struct BgIceShutter
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgIceShutterActionFunc actionFunc;
};
