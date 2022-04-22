#pragma once
#define Z_BG_SPOT08_BAKUDANKABE_H

#include "ultra64.h"
#include "global.h"

struct BgSpot08Bakudankabe;


struct BgSpot08Bakudankabe {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ ColliderJntSph collider;
    /* 0x0184 */ ColliderJntSphElement colliderItems[3];
}; 


