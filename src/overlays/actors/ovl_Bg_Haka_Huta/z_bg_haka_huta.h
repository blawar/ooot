#pragma once
#define Z_BG_HAKA_HUTA_H

#include "global.h"
#include "ultra64.h"

struct BgHakaHuta;

typedef void (*BgHakaHutaActionFunc)(struct BgHakaHuta*, GlobalContext*);

struct BgHakaHuta
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgHakaHutaActionFunc actionFunc;
	/* 0x0168 */ s16 counter;
	/* 0x016A */ s16 unk_16A;
};
