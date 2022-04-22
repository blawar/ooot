#pragma once
#define Z_BG_HIDAN_RSEKIZOU_H

#include "global.h"
#include "ultra64.h"

struct BgHidanRsekizou;

struct BgHidanRsekizou
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ s16 bendFrame;
	/* 0x0166 */ s16 burnFrame;
	/* 0x0168 */ ColliderJntSph collider;
	/* 0x0188 */ ColliderJntSphElement colliderItems[6];
};
