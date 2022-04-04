#pragma once
#define Z_OCEFF_WIPE4_H

#include "ultra64.h"
#include "global.h"

enum OceffWipe4Type {
    /* 0x00 */ OCEFF_WIPE4_SCARECROWS,
    /* 0x01 */ OCEFF_WIPE4_UNUSED
};

struct OceffWipe4;


struct OceffWipe4 {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ Timer timer;
}; 


