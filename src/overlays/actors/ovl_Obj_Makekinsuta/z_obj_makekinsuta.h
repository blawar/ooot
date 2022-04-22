#pragma once
#define Z_OBJ_MAKEKINSUTA_H

#include "ultra64.h"
#include "global.h"

struct ObjMakekinsuta;

typedef void (*ObjMakekinsutaActionFunc)(struct ObjMakekinsuta*, GlobalContext*);


struct ObjMakekinsuta {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ObjMakekinsutaActionFunc actionFunc;
    /* 0x150  */ s16 timer;
    /* 0x152  */ s16 unk_152;
}; 


