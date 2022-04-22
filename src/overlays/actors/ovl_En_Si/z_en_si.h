#pragma once
#define Z_EN_SI_H

#include "global.h"
#include "ultra64.h"

struct EnSi;

typedef void (*EnSiActionFunc)(struct EnSi*, GlobalContext*);

struct EnSi
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnSiActionFunc actionFunc;
	/* 0x0150 */ ColliderCylinder collider;
	/* 0x019C */ u8 unk_19C;
};
