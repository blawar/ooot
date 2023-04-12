#pragma once
#define Z_BG_BOMBWALL_H

#include "global.h"
#include "ultra64.h"

struct BgBombwall;

typedef void (*BgBombwallActionFunc)(struct BgBombwall*, GlobalContext*);

struct BgBombwall
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ ColliderTris collider;
	/* 0x0184 */ ColliderTrisElement colliderItems[3];
	/* 0x0298 */ BgBombwallActionFunc actionFunc;
	/* 0x029C */ Gfx* dList;
	/* 0x02A0 */ TimerS16 animTimer;
	/* 0x02A2 */ u8 unk_2A2;
};
