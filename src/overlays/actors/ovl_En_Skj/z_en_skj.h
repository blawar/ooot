#pragma once
#define Z_EN_SKJ_H

#include "ultra64.h"
#include "global.h"

struct EnSkj;

typedef void (*EnSkjActionFunc)(struct EnSkj*, GlobalContext*);


enum SkullKidAnim {
    /* 0 */ SKJ_ANIM_BACKFLIP,
    /* 1 */ SKJ_ANIM_SHOOT_NEEDLE,
    /* 2 */ SKJ_ANIM_PLAY_FLUTE,
    /* 3 */ SKJ_ANIM_DIE,
    /* 4 */ SKJ_ANIM_HIT,
    /* 5 */ SKJ_ANIM_LAND,
    /* 6 */ SKJ_ANIM_LOOK_LEFT_RIGHT,
    /* 7 */ SKJ_ANIM_FIGHTING_STANCE,
    /* 8 */ SKJ_ANIM_WALK_TO_PLAYER,
    /* 9 */ SKJ_ANIM_WAIT
};


enum SkullKidStumpSide {
    /* 0 */ SKULL_KID_LEFT,
    /* 1 */ SKULL_KID_RIGHT
};


enum SkullKidOcarinaGameState {
    /* 0 */ SKULL_KID_OCRAINA_WAIT,
    /* 1 */ SKULL_KID_OCARINA_PLAY_NOTES,
    /* 2 */ SKULL_KID_OCARINA_LEAVE_GAME
};


enum SkullKidAction {
    /* 00 */ SKJ_ACTION_FADE,
    /* 01 */ SKJ_ACTION_WAIT_TO_SHOOT_NEEDLE,
    /* 02 */ SKJ_ACTION_SARIA_SONG_IDLE,
    /* 03 */ SKJ_ACTION_WAIT_FOR_DEATH_ANIM,
    /* 04 */ SKJ_ACTION_PICK_NEXT_FIHGT_ACTION,
    /* 05 */ SKJ_ACTION_WAIT_FOR_LAND_ANIM,
    /* 06 */ SKJ_ACTION_RESET_FIGHT,
    /* 07 */ SKJ_ACTION_FIGHT,
    /* 08 */ SKJ_ACTION_NEEDLE_RECOVER,
    /* 09 */ SKJ_ACTION_SPAWN_DEATH_EFFECT,
    /* 10 */ SKJ_ACTION_SARIA_SONG_WAIT_IN_RANGE,
    /* 11 */ SKJ_ACTION_SARIA_SONG_WAIT_FOR_SONG,
    /* 12 */ SKJ_ACTION_SARIA_SONG_AFTER_SONG,
    /* 13 */ SKJ_ACTION_SARIA_TALK,
    /* 14 */ SKJ_ACTION_UNK14,
    /* 15 */ SKJ_ACTION_SARIA_SONG_CHANGE_MODE,
    /* 16 */ SKJ_ACTION_SARIA_SONG_START_TRADE,
    /* 17 */ SKJ_ACTION_SARIA_SONG_WAIT_FOR_LANDING,
    /* 18 */ SKJ_ACTION_SARIA_SONG_WAIT_FOR_LANDING_ANIM,
    /* 19 */ SKJ_ACTION_SARIA_SONG_WALK_TO_PLAYER,
    /* 20 */ SKJ_ACTION_SARIA_SONG_ASK_FOR_MASK,
    /* 21 */ SKJ_ACTION_SARIA_SONG_TAKE_MASK,
    /* 22 */ SKJ_ACTION_SARIA_SONG_WAIT_MASK_TEXT,
    /* 23 */ SKJ_ACTION_SARIA_SONG_WRONG_SONG,
    /* 24 */ SKJ_ACTION_SARIA_SONG_WAIT_FOR_TEXT,
    /* 25 */ SKJ_ACTION_OCARINA_GAME_WAIT_FOR_PLAYER,
    /* 26 */ SKJ_ACTION_OCARINA_GAME_IDLE,
    /* 27 */ SKJ_ACTION_OCARINA_GAME_PLAY,
    /* 28 */ SKJ_ACTION_OCARINA_GAME_LEAVE
};


struct unkSkjStruct {
    u8 unk0;
    EnSkj* skullkid;
};


struct SkullkidAnimationEntry {
    AnimationHeader* animation;
    u8 mode;
    f32 morphFrames;
};
struct EnSkj {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ Vec3s jointTable[19];
    /* 0x0202 */ Vec3s morphTable[19];
    /* 0x0274 */ EnSkjActionFunc actionFunc;
    /* 0x0278 */ ColliderCylinder collider;
    /* 0x02C4 */ u16 textId;
    /* 0x02C6 */ s16 timer;
    /* 0x02C8 */ s16 unk_2C8;
    /* 0x02CA */ s16 multiuseTimer;
    /* 0x02CC */ s16 needleShootTimer;
    /* 0x02CE */ s16 dodgeResetTimer;
    /* 0x02D0 */ u8 animIndex;
    /* 0x02D1 */ u8 action;
    /* 0x02D2 */ u8 backfilpFlag;
    /* 0x02D3 */ u8 unk_2D3; // Is set to zero when walking to trade for skull mask and set to 1 when dying
    /* 0x02D4 */ u8 needlesToShoot;
    /* 0x02D5 */ u8 hitsUntilDodge; // Upon reaching zero will always backflip to avoid stun lock
    /* 0x02D6 */ u8 unk_2D6;
    /* 0x02D7 */ u8 playerInRange;
    /* 0x02D8 */ u8 minigameState; // Upon reaching zero stops and does another action
    /* 0x02DC */ u32 alpha;
    /* 0x02E0 */ Vec3f center;
    /* 0x02EC */ f32 unk_2EC;
    /* 0x02F0 */ f32 unk_2F0;
    /* 0x02F4 */ Vec3f posCopy;
}; 


