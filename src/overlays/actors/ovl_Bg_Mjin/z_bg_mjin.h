#pragma once
#define Z_BG_MJIN_H

#include "global.h"
#include "ultra64.h"

struct BgMjin;

typedef void (*BgMjinActionFunc)(struct BgMjin*, GlobalContext*);

struct BgMjin
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ s32 objBankIndex;
	/* 0x0168 */ BgMjinActionFunc actionFunc;
};
