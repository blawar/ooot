#pragma once
#define Z_OBJ_KIBAKO_H

#include "global.h"
#include "ultra64.h"

struct ObjKibako;

typedef void (*ObjKibakoActionFunc)(struct ObjKibako*, GlobalContext*);

struct ObjKibako
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ObjKibakoActionFunc actionFunc;
	/* 0x0150 */ ColliderCylinder collider;
};
