#pragma once
#define Z_DOOR_TOKI_H

#include "global.h"
#include "ultra64.h"

struct DoorToki;

struct DoorToki
{
	/* 0x0000 */ DynaPolyActor dyna;
	/* 0x0164 */ char unk_164[0x4];
};
