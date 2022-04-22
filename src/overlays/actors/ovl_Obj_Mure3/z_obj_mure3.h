#pragma once
#define Z_OBJ_MURE3_H

#include "global.h"
#include "ultra64.h"

struct ObjMure3;

typedef void (*ObjMure3ActionFunc)(struct ObjMure3*, GlobalContext*);
typedef void (*ObjMure3SpawnFunc)(struct ObjMure3*, GlobalContext*);

struct ObjMure3
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ObjMure3ActionFunc actionFunc;
	/* 0x0150 */ EnItem00* unk_150[7];
	/* 0x016C */ u16 unk_16C;
};
