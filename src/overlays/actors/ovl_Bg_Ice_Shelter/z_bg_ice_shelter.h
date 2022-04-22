#pragma once
#define Z_BG_ICE_SHELTER_H

#include "global.h"
#include "ultra64.h"

struct BgIceShelter;

typedef void (*BgIceShelterActionFunc)(struct BgIceShelter*, GlobalContext*);

struct BgIceShelter
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgIceShelterActionFunc actionFunc;
	/* 0x0168 */ ColliderCylinder cylinder1;
	/* 0x01B4 */ ColliderCylinder cylinder2;
	/* 0x0200 */ s16 alpha;
};
