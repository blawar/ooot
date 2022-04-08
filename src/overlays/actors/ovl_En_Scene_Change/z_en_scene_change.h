#pragma once
#define Z_ITEM_SCENE_CHANGE_H

#include "global.h"
#include "ultra64.h"

struct EnSceneChange;

typedef void (*EnSceneChangeActionFunc)(struct EnSceneChange*, GlobalContext*);

struct EnSceneChange
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnSceneChangeActionFunc actionFunc;
};
