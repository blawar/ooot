#pragma once
#define Z_EN_ANUBICE_TAG_H

#include "global.h"
#include "overlays/actors/ovl_En_Anubice/z_en_anubice.h"
#include "ultra64.h"

struct EnAnubiceTag;

typedef void (*EnAnubiceTagActionFunc)(struct EnAnubiceTag*, GlobalContext*);

struct EnAnubiceTag
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnAnubiceTagActionFunc actionFunc;
	/* 0x0150 */ EnAnubice* anubis;
	/* 0x0154 */ f32 triggerRange;
};
