#pragma once
#define Z_BG_JYA_GOROIWA_H

#include "global.h"
#include "ultra64.h"

struct BgJyaGoroiwa;

typedef void (*BgJyaGoroiwaFunc)(struct BgJyaGoroiwa*, GlobalContext*);

struct BgJyaGoroiwa
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ BgJyaGoroiwaFunc actionFunc;
	/* 0x0150 */ ColliderJntSph collider;
	/* 0x0170 */ ColliderJntSphElement colliderItem;
	/* 0x01B0 */ f32 speedFactor;
	/* 0x01B4 */ s16 hasHit;
	/* 0x01B6 */ Timer waitTimer;
	/* 0x01B8 */ f32 yOffsetSpeed;
};
