#pragma once
#define Z_DOOR_KILLER_H

#include "ultra64.h"
#include "global.h"

/*
 * Associated switch flag: (params >> 8) & 0x3F
 * ((params >> 8) & 0x3F) == 0x3F means no switch flag is checked / set
*/

struct DoorKillerTextureEntry {
    /* 0x00 */ s16 objectId;
    /* 0x04 */ void* texture;
}; 

struct DoorKiller;

typedef void (*DoorKillerActionFunc)(struct DoorKiller*, GlobalContext*);


enum DoorKillerBehaviour {
    /* 0 */ DOOR_KILLER_DOOR,
    /* 1 */ DOOR_KILLER_RUBBLE_PIECE_1,
    /* 2 */ DOOR_KILLER_RUBBLE_PIECE_2,
    /* 3 */ DOOR_KILLER_RUBBLE_PIECE_3,
    /* 4 */ DOOR_KILLER_RUBBLE_PIECE_4
};
struct DoorKiller {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ u8 animStyle; // Must be at same offset as animStyle in EnDoor due to the cast in func_80839800
    /* 0x0191 */ u8 playerIsOpening; // Must be at same offset as playerIsOpening in EnDoor
    /* 0x0192 */ Vec3s jointTable[9];
    /* 0x01C8 */ ColliderCylinder colliderCylinder;
    /* 0x0214 */ void* texture;
    /* 0x0218 */ u16 hasHitPlayerOrGround;
    /* 0x021A */ u16 timer;
    /* 0x021C */ s32 doorObjBankIndex;
    /* 0x021D */ u8 textureEntryIndex;
    /* 0x0220 */ ColliderJntSph colliderJntSph;
    /* 0x0240 */ ColliderJntSphElement colliderJntSphItems[1];
    /* 0x0280 */ DoorKillerActionFunc actionFunc;
}; 


