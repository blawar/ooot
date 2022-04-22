#pragma once
#define Z_BG_MIZU_UZU_H

#include "global.h"
#include "ultra64.h"

struct BgMizuUzu;

typedef void (*BgMizuUzuActionFunc)(struct BgMizuUzu*, GlobalContext*);

struct BgMizuUzu
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgMizuUzuActionFunc actionFunc;
};
