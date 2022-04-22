#pragma once
#define Z_BG_PUSHBOX_H

#include "global.h"
#include "ultra64.h"

struct BgPushbox;

typedef void (*BgPushboxActionFunc)(struct BgPushbox*, GlobalContext*);

struct BgPushbox
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgPushboxActionFunc actionFunc;
};
