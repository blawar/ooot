#pragma once
#define Z_BG_HIDAN_SYOKU_H

#include "ultra64.h"
#include "global.h"

struct BgHidanSyoku;

typedef void (*BgHidanSyokuActionFunc)(struct BgHidanSyoku*, GlobalContext*);


struct BgHidanSyoku {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgHidanSyokuActionFunc actionFunc;
    /* 0x0168 */ s16 unk_168;
    /* 0x016A */ Timer timer;
}; 


