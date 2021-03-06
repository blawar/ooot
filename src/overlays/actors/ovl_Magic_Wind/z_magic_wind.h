#pragma once
#define Z_MAGIC_WIND_H

#include "global.h"
#include "ultra64.h"

struct MagicWind;

typedef void (*MagicWindFunc)(MagicWind* pthis, GlobalContext* globalCtx);

struct MagicWind
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnimeCurve skelCurve;
	/* 0x016C */ Timer timer;
	/* 0x0170 */ MagicWindFunc actionFunc;
};
