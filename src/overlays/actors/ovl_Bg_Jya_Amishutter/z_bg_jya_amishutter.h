#pragma once
#define Z_BG_JYA_AMISHUTTER_H

#include "global.h"
#include "ultra64.h"

struct BgJyaAmishutter;

typedef void (*BgJyaAmishutterActionFunc)(struct BgJyaAmishutter*);

struct BgJyaAmishutter
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgJyaAmishutterActionFunc actionFunc;
};
