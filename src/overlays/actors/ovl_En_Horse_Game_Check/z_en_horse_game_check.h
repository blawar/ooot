#pragma once
#define Z_EN_HORSE_GAME_CHECK_H

#include "ultra64.h"
#include "global.h"

struct EnHorseGameCheckBase;

typedef s32 (*EnHorseGameCheckFunc)(struct EnHorseGameCheckBase* pthis, GlobalContext* globalCtx);

struct EnHorseGameCheckBase {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ s32 type;
}; 


enum HorseGameIngoRaceResult {
    /* 0 */ INGORACE_NO_RESULT,
    /* 1 */ INGORACE_PLAYER_WIN,
    /* 2 */ INGORACE_INGO_WIN,
    /* 3 */ INGORACE_TIME_UP
};

enum HorseGameMalonRaceResult {
    /* 0 */ MALONRACE_NO_RESULT,
    /* 1 */ MALONRACE_SUCCESS,
    /* 2 */ MALONRACE_TIME_UP,
    /* 3 */ MALONRACE_UNUSED,
    /* 4 */ MALONRACE_FAILURE
};
struct EnHorseGameCheckIngoRace {

    /* 0x0000 */ EnHorseGameCheckBase base;
    /* 0x0150 */ s32 startFlags;
    /* 0x0154 */ s32 playerCheck[3];
    /* 0x0160 */ s32 ingoCheck[3];
    /* 0x016C */ Actor* ingoHorse;
    /* 0x0170 */ s32 startTimer;
    /* 0x0174 */ s32 result;
    /* 0x0178 */ s32 finishTimer;
    /* 0x017C */ s32 playerFinish;
    /* 0x0180 */ s32 ingoFinish;
}; 

struct EnHorseGameCheckGerudoArchery {
    /* 0x0000 */ EnHorseGameCheckBase base;
    /* 0x0150 */ s32 unk_150;
    /* 0x0154 */ u32 startTimer;
}; 

struct EnHorseGameCheck3 {
    /* 0x0000 */ EnHorseGameCheckBase base;
    /* 0x0150 */ s32 unk_150;
}; 

struct EnHorseGameCheckMalonRace {
    /* 0x0000 */ EnHorseGameCheckBase base;
    /* 0x0150 */ s32 startTimer;
    /* 0x0154 */ s32 raceFlags;
    /* 0x0158 */ s32 fenceCheck[16];
    /* 0x0198 */ s32 finishTimer;
    /* 0x019C */ s32 result;
    /* 0x01A0 */ s32 lapCount;
}; 

union EnHorseGameCheck {
    EnHorseGameCheckIngoRace ingo;
    EnHorseGameCheckGerudoArchery gerudo;
    EnHorseGameCheck3 type3;
    EnHorseGameCheckMalonRace malon;
}; 

enum EnHorseGameCheckType {
    /* 0 */ HORSEGAME_NONE,
    /* 1 */ HORSEGAME_INGO_RACE,
    /* 2 */ HORSEGAME_GERUDO_ARCHERY,
    /* 3 */ HORSEGAME_TYPE3,
    /* 4 */ HORSEGAME_MALON_RACE
};


