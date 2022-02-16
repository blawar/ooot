#pragma once
#define Z_DOOR_SHUTTER_H

#include "ultra64.h"
#include "global.h"

/**
 * Actor Parameters
 * 
 * |                  |         |
 * | Transition Index | Type    | Switch Flag
 * |------------------|---------|-------------
 * | 0 0 0 0 0 0      | 0 0 0 0 | 0 0 0 0 0 0 
 * | 6                | 4       | 6
 * |
 * 
 * Transition Index     1111110000000000    Set by the actor engine when the door is spawned
 * Type                 0000001111000000
 * Switch Flag          0000000000111111
 * 
 */

enum DoorShutterType {
    /* 0x00 */ SHUTTER,
    /* 0x01 */ SHUTTER_FRONT_CLEAR,
    /* 0x02 */ SHUTTER_FRONT_SWITCH,
    /* 0x03 */ SHUTTER_BACK_LOCKED,
    /* 0x04 */ SHUTTER_PG_BARS,
    /* 0x05 */ SHUTTER_BOSS,
    /* 0x06 */ SHUTTER_GOHMA_BLOCK,
    /* 0x07 */ SHUTTER_FRONT_SWITCH_BACK_CLEAR,
    /* 0x08 */ SHUTTER_8,
    /* 0x09 */ SHUTTER_9,
    /* 0x0A */ SHUTTER_A,
    /* 0x0B */ SHUTTER_KEY_LOCKED,
    /* 0x0C */ SHUTTER_C,
    /* 0x0D */ SHUTTER_D,
    /* 0x0E */ SHUTTER_E,
    /* 0x0F */ SHUTTER_F
};

struct DoorShutter;

typedef void (*DoorShutterActionFunc)(struct DoorShutter*, GlobalContext*);



struct ShutterObjectInfo {
    s16 objectId;
    u8 index1;
    u8 index2;
};


struct ShutterInfo {
    /* 0x0000 */ Gfx* a;
    /* 0x0004 */ Gfx* b;
    /* 0x0008 */ u8 c;
    /* 0x0009 */ u8 translateZ;
    /* 0x000A */ u8 e;
    /* 0x000B */ u8 f;
};


struct ShutterSceneInfo {
    s16 sceneNum;
    u8 index;
};


struct BossDoorInfo {
    s16 dungeonScene;
    s16 bossScene;
    u8 index;
};
struct DoorShutter {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ s16 unk_164;
    /* 0x0166 */ s16 unk_166;
    /* 0x0168 */ s16 unk_168;
    /* 0x016A */ u8 doorType;
    /* 0x016B */ u8 unk_16B;
    /* 0x016C */ u8 unk_16C;
    /* 0x016D */ s32 requiredObjBankIndex;
    /* 0x016E */ s8 unk_16E;
    /* 0x016F */ s8 unk_16F;
    /* 0x0170 */ f32 unk_170;
    /* 0x0174 */ DoorShutterActionFunc actionFunc;
}; 


