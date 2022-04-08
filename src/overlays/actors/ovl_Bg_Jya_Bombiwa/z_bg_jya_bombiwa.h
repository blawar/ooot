#pragma once
#define Z_BG_JYA_BOMBIWA_H

#include "global.h"
#include "ultra64.h"

struct BgJyaBombiwa;

struct BgJyaBombiwa
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ s32 unk_164;
	/* 0x0168 */ ColliderJntSph collider;
	/* 0x0188 */ ColliderJntSphElement colliderItems[1];
};
