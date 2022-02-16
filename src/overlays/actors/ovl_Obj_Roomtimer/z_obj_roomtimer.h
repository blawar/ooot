#pragma once
#define Z_OBJ_ROOMTIMER_H

#include "ultra64.h"
#include "global.h"
#include "z64.h"

struct ObjRoomtimer;

typedef void (*ObjRoomtimerActionFunc)(struct ObjRoomtimer*, GlobalContext*);


struct ObjRoomtimer {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ObjRoomtimerActionFunc actionFunc;
    /* 0x0150 */ u32 switchFlag;
}; 


