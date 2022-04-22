#pragma once
#define Z_BG_VB_SIMA_H

#include "global.h"
#include "ultra64.h"

struct BgVbSima;

enum BgVbSimaSignal
{
	/* 0 */ VBSIMA_STAND,
	/* 1 */ VBSIMA_COLLAPSE,
	/* 2 */ VBSIMA_KILL
};

struct BgVbSima
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ char unk_164[0x10];
	/* 0x0174 */ Timer shakeTimer;
	/* 0x0176 */ char unk_176[6];
};
