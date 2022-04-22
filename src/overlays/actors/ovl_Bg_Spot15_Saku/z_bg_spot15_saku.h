#pragma once
#define Z_BG_SPOT15_SAKU_H

#include "global.h"
#include "ultra64.h"

struct BgSpot15Saku;

typedef void (*BgSpot15SakuActionFunc)(struct BgSpot15Saku*, GlobalContext*);

struct BgSpot15Saku
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgSpot15SakuActionFunc actionFunc;
	/* 0x0168 */ u64 unk_168;
	/* 0x0170 */ Vec3f unk_170;
	/* 0x017C */ Timer timer;
};
