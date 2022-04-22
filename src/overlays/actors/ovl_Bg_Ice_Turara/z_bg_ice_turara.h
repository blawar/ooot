#pragma once
#define Z_BG_ICE_TURARA_H

#include "global.h"
#include "ultra64.h"

struct BgIceTurara;

typedef void (*BgIceTuraraActionFunc)(struct BgIceTurara*, GlobalContext*);

enum BgIceTuraraType
{
	/* 0 */ TURARA_STALAGMITE,
	/* 1 */ TURARA_STALACTITE,
	/* 2 */ TURARA_STALACTITE_REGROW
};

struct BgIceTurara
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgIceTuraraActionFunc actionFunc;
	/* 0x0168 */ Timer shiverTimer;
	/* 0x016C */ ColliderCylinder collider;
};
