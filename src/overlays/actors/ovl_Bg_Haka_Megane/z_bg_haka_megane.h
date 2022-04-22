#pragma once
#define Z_BG_HAKA_MEGANE_H

#include "global.h"
#include "ultra64.h"

struct BgHakaMegane;

typedef void (*BgHakaMeganeActionFunc)(struct BgHakaMegane*, GlobalContext*);

struct BgHakaMegane
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgHakaMeganeActionFunc actionFunc;
	/* 0x0168 */ char unk_168[0x1];
	/* 0x0169 */ s32 objBankIndex;
	/* 0x016A */ char unk_16A[0x2];
};
