#pragma once
#define Z_BG_HIDAN_FSLIFT_H

#include "global.h"
#include "ultra64.h"

struct BgHidanFslift;

typedef void (*BgHidanFsliftActionFunc)(struct BgHidanFslift*, GlobalContext*);

struct BgHidanFslift
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgHidanFsliftActionFunc actionFunc;
	/* 0x0168 */ Timer timer;
	/* 0x016A */ s16 unk_16A;
};
