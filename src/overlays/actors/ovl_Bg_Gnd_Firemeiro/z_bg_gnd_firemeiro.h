#pragma once
#define Z_BG_GND_FIREMEIRO_H

#include "global.h"
#include "ultra64.h"

struct BgGndFiremeiro;

typedef void (*BgGndFiremeiroActionFunc)(struct BgGndFiremeiro*, GlobalContext*);

struct BgGndFiremeiro
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ Vec3f initPos;
	/* 0x0170 */ u16 timer;
	/* 0x0174 */ BgGndFiremeiroActionFunc actionFunc;
};
