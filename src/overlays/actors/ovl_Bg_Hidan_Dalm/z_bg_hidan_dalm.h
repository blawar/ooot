#pragma once
#define Z_BG_HIDAN_DALM_H

#include "global.h"
#include "ultra64.h"

struct BgHidanDalm;

typedef void (*BgHidanDalmActionFunc)(struct BgHidanDalm*, GlobalContext*);

struct BgHidanDalm
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgHidanDalmActionFunc actionFunc;
	/* 0x0168 */ u8 switchFlag;
	/* 0x016C */ ColliderTris collider;
	/* 0x018C */ ColliderTrisElement colliderItems[4];
};
