#pragma once
#define Z_BG_GND_SOULMEIRO_H

#include "global.h"
#include "ultra64.h"

struct BgGndSoulmeiro;

typedef void (*BgGndSoulmeiroActionFunc)(struct BgGndSoulmeiro*, GlobalContext*);

struct BgGndSoulmeiro
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ColliderCylinder collider;
	/* 0x0198 */ u16 unk_198;
	/* 0x019C */ BgGndSoulmeiroActionFunc actionFunc;
};
