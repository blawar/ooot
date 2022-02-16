#pragma once
#define Z_BG_BREAKWALL_H

#include "ultra64.h"
#include "global.h"

struct BgBreakwall;

typedef void (*BgBreakwallActionFunc)(struct BgBreakwall*, GlobalContext*);


struct BombableWallInfo {
    /* 0x00 */ CollisionHeader* colHeader;
    /* 0x04 */ Gfx* dList;
    /* 0x08 */ s8 colType;
};
struct BgBreakwall {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ Gfx* bombableWallDList;
    /* 0x0168 */ s8 colType;
    /* 0x0169 */ s32 bankIndex;
    /* 0x016C */ ColliderQuad collider;
    /* 0x01EC */ BgBreakwallActionFunc actionFunc;
}; 

enum BombableWallType {
    /* 0 */ BWALL_DC_ENTRANCE,  // When exploded it will play the Dodongo's Cavern intro cutscene
    /* 1 */ BWALL_WALL,         // Used a lot in Dodongo's Cavern and other places
    /* 2 */ BWALL_KD_FLOOR,     // Used in the King Dodongo boss room
    /* 3 */ BWALL_KD_LAVA_COVER // Spawned after the KD fight in order to cover the lava floor to disable damage
};


