#pragma once
#define Z_EN_OWL_H

#include "ultra64.h"
#include "global.h"

struct EnOwl;

typedef void (*EnOwlActionFunc)(struct EnOwl*, GlobalContext*);
typedef void (*OwlFunc)(struct EnOwl*);



enum EnOwlType {
    /* 0x00 */ OWL_DEFAULT,
    /* 0x01 */ OWL_OUTSIDE_KOKIRI,
    /* 0x02 */ OWL_HYRULE_CASTLE,
    /* 0x03 */ OWL_KAKARIKO,
    /* 0x04 */ OWL_HYLIA_GERUDO,
    /* 0x05 */ OWL_LAKE_HYLIA,
    /* 0x06 */ OWL_ZORA_RIVER,
    /* 0x07 */ OWL_HYLIA_SHORTCUT,
    /* 0x08 */ OWL_DEATH_MOUNTAIN,
    /* 0x09 */ OWL_DEATH_MOUNTAIN2,
    /* 0x0A */ OWL_DESSERT_COLOSSUS,
    /* 0x0B */ OWL_LOST_WOODS_PRESARIA,
    /* 0x0C */ OWL_LOST_WOODS_POSTSARIA
};


enum EnOwlMessageChoice {
    /* 0x00 */ OWL_REPEAT,
    /* 0x01 */ OWL_OK
};
struct EnOwl {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderCylinder collider;
    /* 0x0198 */ SkelAnime skelAnime;
    /* 0x01DC */ Vec3s jointTable[21];
    /* 0x025A */ Vec3s morphTable[21];
    /* 0x02D8 */ SkelAnime skelAnime2;
    /* 0x031C */ Vec3s jointTable2[16];
    /* 0x037C */ Vec3s morphTable2[16];
    /* 0x03DC */ SkelAnime* curSkelAnime;
    /* 0x03E0 */ Vec3f eye;
    /* 0x03EC */ s16 unk_3EC;
    /* 0x03EE */ s16 unk_3EE;
    /* 0x03F0 */ s16 unk_3F0;
    /* 0x03F2 */ s16 unk_3F2;
    /* 0x03F4 */ s16 eyeTexIndex;
    /* 0x03F6 */ s16 blinkTimer;
    /* 0x03F8 */ f32 unk_3F8;
    /* 0x03FC */ u16 actionFlags;
    /* 0x03FE */ u16 unk_3FE;
    /* 0x0400 */ s16 unk_400;
    /* 0x0402 */ s16 cameraIdx;
    /* 0x0404 */ u8 unk_404;
    /* 0x0405 */ u8 unk_405;
    /* 0x0406 */ u8 unk_406;
    /* 0x0407 */ u8 unk_407;
    /* 0x0408 */ u8 unk_408;
    /* 0x0409 */ u8 unk_409;
    /* 0x040A */ u8 unk_40A;
    /* 0x040B */ u8 unk_40B;
    /* 0x040C */ EnOwlActionFunc actionFunc;
    /* 0x0410 */ OwlFunc unk_410;
}; 


