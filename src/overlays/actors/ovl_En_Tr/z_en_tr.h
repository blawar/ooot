#pragma once
#define Z_EN_TR_H

#include "global.h"
#include "ultra64.h"

struct EnTr;

typedef void (*EnTrActionFunc)(struct EnTr*, GlobalContext*);

struct EnTr
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ Vec3s jointTable[27];
	/* 0x0232 */ Vec3s morphTable[27];
	/* 0x02D4 */ s16 unk_2D4;
	/* 0x02D6 */ TimerU16 timer; // Also used as an angle
	/* 0x02D8 */ s16 actionIndex;
	/* 0x02DC */ EnTrActionFunc actionFunc;
	/* 0x02E0 */ s16 eyeIndex;
	/* 0x02E2 */ Timer blinkTimer;
	/* 0x02E4 */ AnimationHeader* animation;
};

enum TwinrovaType
{
	/* 0 */ TR_KOUME,
	/* 1 */ TR_KOTAKE
};
