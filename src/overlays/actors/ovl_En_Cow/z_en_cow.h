#pragma once
#define Z_EN_COW_H

#include "global.h"
#include "ultra64.h"

struct EnCow;

typedef void (*EnCowActionFunc)(struct EnCow*, GlobalContext*);

struct EnCow
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ColliderCylinder colliders[2];
	/* 0x01E4 */ SkelAnime skelAnime;
	/* 0x0228 */ Vec3s jointTable[6];
	/* 0x024C */ Vec3s morphTable[6];
	/* 0x0270 */ Vec3s someRot;
	/* 0x0276 */ u16 unk_276;
	/* 0x0278 */ TimerU16 mooTimer;
	/* 0x027A */ TimerU16 breathingTimer;
	/* 0x027C */ EnCowActionFunc actionFunc;
};
