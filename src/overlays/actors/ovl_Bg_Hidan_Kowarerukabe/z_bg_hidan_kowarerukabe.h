#pragma once
#define Z_BG_HIDAN_KOWARERUKABE_H

#include "ultra64.h"
#include "global.h"

struct BgHidanKowarerukabe;


enum FireTempleBombableObjectsType {
    /* 0 */ CRACKED_STONE_FLOOR,
    /* 1 */ BOMBABLE_WALL,
    /* 2 */ LARGE_BOMBABLE_WALL
};
struct BgHidanKowarerukabe {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ ColliderJntSph collider;
    /* 0x0184 */ ColliderJntSphElement colliderItems[1];
}; 


