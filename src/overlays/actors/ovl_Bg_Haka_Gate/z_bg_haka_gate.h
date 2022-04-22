#pragma once
#define Z_BG_HAKA_GATE_H

#include "global.h"
#include "ultra64.h"

struct BgHakaGate;

typedef void (*BgHakaGateActionFunc)(struct BgHakaGate*, GlobalContext*);

struct BgHakaGate
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ BgHakaGateActionFunc actionFunc;
	/* 0x0168 */ u8 switchFlag;
	/* 0x016A */ s16 actionVar1;
	/* 0x016C */ s16 actionVar2;
	/* 0x016E */ s16 actionVar3;
	/* 0x0170 */ s16 actionVar4;
	/* 0x0172 */ s16 actionVar5;
};

enum BgHakaGateType
{
	BGHAKAGATE_STATUE,
	BGHAKAGATE_FLOOR,
	BGHAKAGATE_GATE,
	BGHAKAGATE_SKULL
};
