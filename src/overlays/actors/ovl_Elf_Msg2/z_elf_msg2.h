#pragma once
#define Z_ELF_MSG2_H

#include "ultra64.h"
#include "global.h"

struct ElfMsg2;

typedef void (*ElfMsg2ActionFunc)(struct ElfMsg2*, GlobalContext*);


struct ElfMsg2 {

    /* 0x0000 */ Actor              actor;
    /* 0x014C */ ElfMsg2ActionFunc  actionFunc;
}; 


