#pragma once
#define Z_EN_TP_H

#include "ultra64.h"
#include "global.h"

struct EnTp;

typedef void (*EnTpActionFunc)(struct EnTp*, GlobalContext*);



enum TailpasaranAction {
    /* 0 */ TAILPASARAN_ACTION_FRAGMENT_FADE,
    /* 1 */ TAILPASARAN_ACTION_DIE,
    /* 2 */ TAILPASARAN_ACTION_TAIL_FOLLOWHEAD,
    /* 4 */ TAILPASARAN_ACTION_HEAD_WAIT = 4,
    /* 7 */ TAILPASARAN_ACTION_HEAD_APPROACHPLAYER = 7,
    /* 8 */ TAILPASARAN_ACTION_HEAD_TAKEOFF,
    /* 9 */ TAILPASARAN_ACTION_HEAD_BURROWRETURNHOME
};


enum TailpasaranDamageEffect {
    /* 00 */ TAILPASARAN_DMGEFF_NONE,
    /* 01 */ TAILPASARAN_DMGEFF_DEKUNUT,
    /* 14 */ TAILPASARAN_DMGEFF_SHOCKING = 14, // Kills the Tailpasaran but shocks Player
    /* 15 */ TAILPASARAN_DMGEFF_INSULATING     // Kills the Tailpasaran and does not shock Player
};
struct EnTp {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ s32 actionIndex;
    /* 0x0150 */ s32 unk_150; // Some kind of state indicator
    /* 0x0154 */ EnTpActionFunc actionFunc;
    /* 0x0158 */ u8 damageEffect; // Used to propagate the effect to the other segments' actors
    /* 0x015A */ s16 timer;
    /* 0x015C */ s16 unk_15C; // Multipurpose, used to change the horizontal position of tail segments 
    /* 0x015E */ s16 alpha; // The dying types fade away
    /* 0x0160 */ s16 red;
    /* 0x0162 */ s16 kiraSpawnTimer;
    /* 0x0164 */ s16 unk_164; // Used once, never set to nonzero
    /* 0x0168 */ f32 heightPhase;
    /* 0x016C */ f32 horizontalVariation;
    /* 0x0170 */ f32 extraHeightVariation;
    /* 0x0174 */ ColliderJntSph collider;
    /* 0x0194 */ ColliderJntSphElement colliderItems[1];
    /* 0x01D4 */ struct EnTp* head;
}; 

enum EnTpType {
    /* -1 */ TAILPASARAN_HEAD = -1, // Used when scenes spawn them: code only cares about < 0
    /*  0 */ TAILPASARAN_TAIL,
    /* 10 */ TAILPASARAN_FRAGMENT = 10,
    /* 11 */ TAILPASARAN_TAIL_DYING,
    /* 12 */ TAILPASARAN_HEAD_DYING
};


