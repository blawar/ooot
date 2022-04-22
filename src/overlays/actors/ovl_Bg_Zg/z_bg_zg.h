#pragma once
#define Z_BG_ZG_H

#include "global.h"
#include "ultra64.h"

struct BgZg;

typedef void (*BgZgActionFunc)(struct BgZg*, GlobalContext*);
typedef void (*BgZgDrawFunc)(struct BgZg*, GlobalContext*);

struct BgZg
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ s32 action;
	/* 0x0168 */ s32 drawConfig;
};
