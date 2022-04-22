#pragma once
#define Z_BG_SPOT11_OASIS_H

#include "global.h"
#include "ultra64.h"

struct BgSpot11Oasis;

typedef void (*BgSpot11OasisActionFunc)(struct BgSpot11Oasis*, GlobalContext*);

struct BgSpot11Oasis
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ BgSpot11OasisActionFunc actionFunc;
	/* 0x0150 */ u8 unk_150;
	/* 0x0151 */ u8 unk_151;
};
