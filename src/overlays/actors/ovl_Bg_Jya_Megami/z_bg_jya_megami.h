#pragma once
#define Z_BG_JYA_MEGAMI_H

#include "ultra64.h"
#include "global.h"

struct BgJyaMegami;

typedef void (*BgJyaMegamiActionFunc)(struct BgJyaMegami*, GlobalContext*);

struct BgJyaMegamiPiece {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f vel;
    /* 0x18 */ s16 rotVelX;
    /* 0x1A */ s16 rotVelY;
}; 



struct BgJyaMegamiPieceInit {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ f32 velX;
    /* 0x10 */ s16 rotVelX;
    /* 0x12 */ s16 rotVelY;
    /* 0x14 */ s16 delay;
};
struct BgJyaMegami {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgJyaMegamiActionFunc actionFunc;
    /* 0x0168 */ ColliderJntSph collider;
    /* 0x0188 */ ColliderJntSphElement colliderItem;
    /* 0x01C8 */ s16 lightTimer;
    /* 0x01CA */ s16 explosionTimer;
    /* 0x01CC */ s16 crumbleIndex;
    /* 0x01D0 */ BgJyaMegamiPiece pieces[13];
}; 


