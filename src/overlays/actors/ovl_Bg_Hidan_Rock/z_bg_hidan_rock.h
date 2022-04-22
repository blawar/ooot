#pragma once
#define Z_BG_HIDAN_ROCK_H

#include "global.h"
#include "ultra64.h"

struct BgHidanRock;

typedef void (*BgHidanRockActionFunc)(struct BgHidanRock*, GlobalContext*);

struct BgHidanRock
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgHidanRockActionFunc actionFunc;
	/* 0x0168 */ u8 type;
	/* 0x0169 */ u8 unk_169;
	/* 0x016A */ Timer timer;
	/* 0x016C */ f32 unk_16C;
	/* 0x0170 */ Vec3f unk_170;
	/* 0x017C */ ColliderCylinder collider;
};
