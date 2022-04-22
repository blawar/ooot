#pragma once
#define Z_BG_TOKI_HIKARI_H

#include "ultra64.h"
#include "global.h"

struct BgTokiHikari;

typedef void (*BgTokiHikariActionFunc)(struct BgTokiHikari*, GlobalContext*);


struct BgTokiHikari {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ f32 unk_14C;
    /* 0x0150 */ BgTokiHikariActionFunc actionFunc; 
}; 


