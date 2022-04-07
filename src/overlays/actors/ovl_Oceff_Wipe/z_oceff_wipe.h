#pragma once
#define Z_OCEFF_WIPE_H

#include "ultra64.h"
#include "global.h"

enum OceffWipeType {
    /* 0x00 */ OCEFF_WIPE_ZL,
    /* 0x01 */ OCEFF_WIPE_SOT
};

struct OceffWipe;


struct OceffWipe {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ Timer timer;
}; 


