#pragma once
#define Z_EN_AROW_TRAP_H

#include "ultra64.h"
#include "global.h"
#include "z64.h"

struct EnArowTrap;


struct EnArowTrap {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ u32 unk_14C;
    /* 0x0150 */ u32 attackTimer;
}; 


