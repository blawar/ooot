#pragma once
#define Z_BG_YDAN_MARUTA_H

#include "ultra64.h"
#include "global.h"

struct BgYdanMaruta;

typedef void (*BgYdanMarutaActionFunc)(struct BgYdanMaruta*, GlobalContext*);


struct BgYdanMaruta {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgYdanMarutaActionFunc actionFunc;
    /* 0x0168 */ u8 switchFlag;
    /* 0x016A */ s16 unk_16A;
    /* 0x016C */ ColliderTris collider;
    /* 0x018C */ ColliderTrisElement elements[2];
}; 


