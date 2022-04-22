#pragma once
#define Z_BG_TOKI_SWD_H

#include "global.h"
#include "ultra64.h"

struct BgTokiSwd;

typedef void (*BgTokiSwdActionFunc)(struct BgTokiSwd*, GlobalContext*);

struct BgTokiSwd
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ BgTokiSwdActionFunc actionFunc;
	/* 0x0150 */ ColliderCylinder collider;
};
