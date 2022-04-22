#pragma once
#define Z_EN_HOLL_H

#include "global.h"
#include "ultra64.h"

struct EnHoll;

typedef void (*EnHollActionFunc)(struct EnHoll*, GlobalContext*);

struct EnHoll
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ s16 planeAlpha;
	/* 0x014E */ u8 side;
	/* 0x014F */ u8 unk_14F;
	/* 0x0150 */ EnHollActionFunc actionFunc;
};
