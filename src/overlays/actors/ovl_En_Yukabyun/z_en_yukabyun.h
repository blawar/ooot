#pragma once
#define Z_EN_YUKABYUN_H

#include "global.h"
#include "ultra64.h"

struct EnYukabyun;

typedef void (*EnYukabyunActionFunc)(struct EnYukabyun*, GlobalContext*);

struct EnYukabyun
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnYukabyunActionFunc actionfunc;
	/* 0x0150 */ s16 unk_150;
	/* 0x0152 */ u8 unk_152;
	/* 0x0154 */ ColliderCylinder collider;
};
