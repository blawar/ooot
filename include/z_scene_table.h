#pragma once

struct EntranceInfo {
    /* 0x00 */ s8 scene;
    /* 0x01 */ s8 spawn;
    /* 0x02 */ u16 field;
}; // size = 0x4

extern EntranceInfo gEntranceTable[1556];
extern SceneTableEntry gSceneTable[SCENE_ID_MAX];

