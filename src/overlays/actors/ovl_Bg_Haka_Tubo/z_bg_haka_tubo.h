#pragma once
#define Z_BG_HAKA_TUBO_H

#include "global.h"
#include "ultra64.h"

struct BgHakaTubo;

typedef void (*BgHakaTuboActionFunc)(struct BgHakaTubo*, GlobalContext*);

struct BgHakaTubo
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgHakaTuboActionFunc actionFunc;
	/* 0x0168 */ Timer dropTimer;
	/* 0x016A */ s16 fireScroll;
	/* 0x016C */ ColliderCylinder potCollider;
	/* 0x01B8 */ ColliderCylinder flamesCollider;
};
