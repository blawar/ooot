#pragma once
#define Z_BG_MORI_HASHIGO_H

#include "global.h"
#include "ultra64.h"

struct BgMoriHashigo;

typedef void (*BgMoriHashigoActionFunc)(struct BgMoriHashigo*, GlobalContext*);

struct BgMoriHashigo
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ ColliderJntSph collider;
	/* 0x0184 */ ColliderJntSphElement colliderItems[1];
	/* 0x01C4 */ BgMoriHashigoActionFunc actionFunc;
	/* 0x01C8 */ Timer hitTimer;
	/* 0x01CA */ s16 bounceCounter;
	/* 0x01CC */ s32 moriTexObjIndex;
};

enum HasigoType
{
	/* -1 */ HASHIGO_CLASP = -1,
	/*  0  */ HASHIGO_LADDER
};
