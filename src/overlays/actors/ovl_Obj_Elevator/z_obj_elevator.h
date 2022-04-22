#pragma once
#define Z_OBJ_ELEVATOR_H

#include "global.h"
#include "ultra64.h"

struct ObjElevator;

typedef void (*ObjElevatorActionFunc)(struct ObjElevator*, GlobalContext*);

struct ObjElevator
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ ObjElevatorActionFunc actionFunc;
	/* 0x0168 */ f32 unk_168;
	/* 0x016C */ f32 unk_16C;
	/* 0x0170 */ u8 unk_170;
};
