#pragma once
#define Z_BG_SPOT00_HANEBASI_H

#include "ultra64.h"
#include "global.h"

struct BgSpot00Hanebasi;

typedef void (*BgSpot00HanebasiActionFunc)(struct BgSpot00Hanebasi*, GlobalContext*);


enum DrawbridgeType {
    /* -1 */ DT_DRAWBRIDGE = -1,
    /*  0 */ DT_CHAIN_1,
    /*  1 */ DT_CHAIN_2
};
struct BgSpot00Hanebasi {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgSpot00HanebasiActionFunc actionFunc;
    /* 0x0168 */ s16 destAngle;
    /* 0x016C */ LightNode* lightNode;
    /* 0x0170 */ LightInfo lightInfo;
}; 


