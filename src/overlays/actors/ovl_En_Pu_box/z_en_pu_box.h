#pragma once
#define Z_EN_PU_BOX_H

#include "global.h"
#include "ultra64.h"

struct EnPubox;

struct EnPubox
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ u32 unk_164;
};
