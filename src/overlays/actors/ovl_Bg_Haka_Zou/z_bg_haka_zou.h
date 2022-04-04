#pragma once
#define Z_BG_HAKA_ZOU_H

#include "ultra64.h"
#include "global.h"

struct BgHakaZou;

typedef void (*BgHakaZouActionFunc)(struct BgHakaZou*, GlobalContext*);


enum ShadowTempleAssetsType {
    /* 0x0 */ STA_GIANT_BIRD_STATUE,
    /* 0x1 */ STA_BOMBABLE_SKULL_WALL,
    /* 0x2 */ STA_BOMBABLE_RUBBLE,
    /* 0x3 */ STA_UNKNOWN
};
struct BgHakaZou {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgHakaZouActionFunc actionFunc;
    /* 0x0168 */ s32 requiredObjBankIndex;
    /* 0x0169 */ u8 switchFlag;
    /* 0x016A */ Timer timer;
    /* 0x016C */ ColliderCylinder collider;
}; 


