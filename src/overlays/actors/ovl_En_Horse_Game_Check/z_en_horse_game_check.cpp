#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HORSE_GAME_CHECK_Z_EN_HORSE_GAME_CHECK_C
#include "actor_common.h"
/*
 * File: z_en_horse_game_check.c
 * Overlay: ovl_En_Horse_Game_Check
 * Description: Horseback Minigames
 */

#include "z_en_horse_game_check.h"
#include "overlays/actors/ovl_En_Horse/z_en_horse.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"
#include "def/logutils.h"
#include "def/sys_math3d.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"

#define FLAGS ACTOR_FLAG_4

#define AT_FINISH_LINE(actor)                                                                                     \
    (Math3D_PointInSquare2D(sFinishLine[0], sFinishLine[1], sFinishLine[2], sFinishLine[3], (actor)->world.pos.x, \
                            (actor)->world.pos.z))
#define AT_RANCH_EXIT(actor)                                                                                  \
    (Math3D_PointInSquare2D(sRanchExit[0], sRanchExit[1], sRanchExit[2], sRanchExit[3], (actor)->world.pos.x, \
                            (actor)->world.pos.z))

#define INGORACE_PLAYER_MOVE (1 << 0)
#define INGORACE_SET_TIMER (1 << 1)
#define INGORACE_INGO_MOVE (1 << 2)


#define MALONRACE_PLAYER_MOVE (1 << 0)
#define MALONRACE_SET_TIMER (1 << 1)
#define MALONRACE_SECOND_LAP (1 << 2)
#define MALONRACE_BROKE_RULE (1 << 3)
#define MALONRACE_START_SFX (1 << 4)
#define MALONRACE_PLAYER_START (1 << 5)
#define MALONRACE_PLAYER_ON_MARK (1 << 6)


void EnHorseGameCheck_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHorseGameCheck_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnHorseGameCheck_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHorseGameCheck_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHorseGameCheck_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Horse_Game_Check_InitVars = {
    ACTOR_EN_HORSE_GAME_CHECK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnHorseGameCheck),
    (ActorFunc)EnHorseGameCheck_Init,
    (ActorFunc)EnHorseGameCheck_Destroy,
    (ActorFunc)EnHorseGameCheck_Update,
    (ActorFunc)EnHorseGameCheck_Draw,
    (ActorFunc)EnHorseGameCheck_Reset,
};

static Vec3f sIngoRaceCheckpoints[] = {
    { 1700.0f, 1.0f, -540.0f },
    { 117.0f, 1.0f, 488.0f },
    { -1700.0f, 1.0f, -540.0f },
};

static f32 sFinishLine[4] = { -200.0f, 80.0f, -2300.0f, -1470.0f };

static f32 sRanchExit[4] = { 800.0f, 1000.0f, -2900.0f, -2700.0f };

static Vec3f sUnusedZeroVec = { 0.0f, 0.0f, 0.0f };

static Vec3f sFencePos[] = {
    { 820.0f, -44.0f, -1655.0f }, { 1497.0f, -21.0f, -1198.0f },  { 1655.0f, -44.0f, -396.0f },
    { 1291.0f, -44.0f, 205.0f },  { 379.0f, -21.0f, 455.0f },     { -95.0f, -21.0f, 455.0f },
    { -939.0f, 1.0f, 455.0f },    { -1644.0f, -21.0f, -1035.0f },
};

s32 EnHorseGameCheck_InitIngoRace(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    EnHorseGameCheckIngoRace* pthis = (EnHorseGameCheckIngoRace*)base;
    s32 i;

    pthis->base.type = HORSEGAME_INGO_RACE;
    pthis->startFlags = 0;
    for (i = 0; i < 3; i++) {
        pthis->playerCheck[i] = 0;
    }
    pthis->ingoHorse =
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_HORSE, -250.0f, 1.0f, -1650.0f, 0, 0x4000, 0, 0x8003);

    if (pthis->ingoHorse == NULL) {
        LogUtils_HungupThread("../z_en_horse_game_check.c", 385);
    }
    pthis->startTimer = 0;
    pthis->finishTimer = 0;
    pthis->result = INGORACE_NO_RESULT;
    pthis->playerFinish = 0;
    pthis->ingoFinish = 0;

    return true;
}

s32 EnHorseGameCheck_DestroyIngoRace(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    return true;
}

void EnHorseGameCheck_FinishIngoRace(EnHorseGameCheckIngoRace* pthis, GlobalContext* globalCtx) {
    gSaveContext.cutsceneIndex = 0;
    if (pthis->result == INGORACE_PLAYER_WIN) {
        globalCtx->nextEntranceIndex = 0x4CE;
        if (gSaveContext.eventInf[0] & 0x40) {
            gSaveContext.eventInf[0] = (gSaveContext.eventInf[0] & ~0xF) | 6;
            gSaveContext.eventInf[0] = (gSaveContext.eventInf[0] & ~0x8000) | 0x8000;
            globalCtx->fadeTransition = 3;
            Environment_ForcePlaySequence(NA_BGM_INGO);
        } else {
            gSaveContext.eventInf[0] = (gSaveContext.eventInf[0] & ~0xF) | 4;
            gSaveContext.eventInf[0] = (gSaveContext.eventInf[0] & ~0x8000) | 0x8000;
            Environment_ForcePlaySequence(NA_BGM_INGO);
            globalCtx->fadeTransition = 0x2E;
        }
    } else {
        globalCtx->nextEntranceIndex = 0x558;
        gSaveContext.eventInf[0] = (gSaveContext.eventInf[0] & ~0xF) | 3;
        globalCtx->fadeTransition = 0x20;
        gSaveContext.eventInf[0] = (gSaveContext.eventInf[0] & ~0x8000) | 0x8000;
    }
    DREG(25) = 0;
    globalCtx->sceneLoadFlag = 0x14;
    gSaveContext.timer1State = 0;
}

s32 EnHorseGameCheck_UpdateIngoRace(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    EnHorseGameCheckIngoRace* pthis = (EnHorseGameCheckIngoRace*)base;
    Player* player = GET_PLAYER(globalCtx);
    s32 i;
    EnHorse* ingoHorse;
    EnHorse* horse;

    if ((pthis->startTimer > 50) && !(pthis->startFlags & INGORACE_SET_TIMER)) {
        pthis->startFlags |= INGORACE_SET_TIMER;
        func_80088B34(0);
    } else if ((pthis->startTimer > 80) && (player->rideActor != NULL) && !(pthis->startFlags & INGORACE_PLAYER_MOVE)) {
        pthis->startFlags |= INGORACE_PLAYER_MOVE;
        horse = (EnHorse*)player->rideActor;
        horse->inRace = 1;
    } else if ((pthis->startTimer > 81) && !(pthis->startFlags & INGORACE_INGO_MOVE)) {
        ingoHorse = (EnHorse*)pthis->ingoHorse;

        ingoHorse->inRace = 1;
        pthis->startFlags |= INGORACE_INGO_MOVE;
        Audio_PlaySoundGeneral(NA_SE_SY_START_SHOT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    }

    pthis->startTimer++;

    for (i = 0; i < 3; i++) {
        if ((player->rideActor != NULL) &&
            (Math3D_Vec3f_DistXYZ(&sIngoRaceCheckpoints[i], &player->rideActor->world.pos) < 400.0f)) {
            if ((i > 0) && (pthis->playerCheck[i - 1] == 1)) {
                pthis->playerCheck[i] = 1;
            } else if (i == 0) {
                pthis->playerCheck[i] = 1;
            }
        }
        if (Math3D_Vec3f_DistXYZ(&sIngoRaceCheckpoints[i], &pthis->ingoHorse->world.pos) < 400.0f) {
            if ((i > 0) && (pthis->ingoCheck[i - 1] == 1)) {
                pthis->ingoCheck[i] = 1;
            } else if (i == 0) {
                pthis->ingoCheck[i] = 1;
            }
        }
    }

    if (pthis->result == INGORACE_NO_RESULT) {
        Player* player2 = player;

        if ((player2->rideActor != NULL) && (pthis->playerCheck[2] == 1) && AT_FINISH_LINE(player2->rideActor)) {
            pthis->playerFinish++;
            if (pthis->playerFinish > 0) {
                pthis->result = INGORACE_PLAYER_WIN;
                pthis->finishTimer = 55;
                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_HORSE_GOAL);
                Audio_PlaySoundGeneral(NA_SE_SY_START_SHOT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            }
            for (i = 0; i < 3; i++) {
                pthis->playerCheck[i] = 0;
            }
        }
        if ((pthis->ingoHorse != NULL) && (pthis->ingoCheck[2] == 1) && AT_FINISH_LINE(pthis->ingoHorse)) {
            pthis->ingoFinish++;
            if (pthis->ingoFinish > 0) {
                ingoHorse = (EnHorse*)pthis->ingoHorse;

                pthis->result = INGORACE_INGO_WIN;
                pthis->finishTimer = 70;
                ingoHorse->stateFlags |= ENHORSE_INGO_WON;
                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_HORSE_GOAL);
                Audio_PlaySoundGeneral(NA_SE_SY_START_SHOT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            }
            for (i = 0; i < 3; i++) {
                pthis->ingoCheck[i] = 0;
            }
        }
        if (((player2->rideActor != NULL) && AT_RANCH_EXIT(player2->rideActor)) || AT_RANCH_EXIT(&player2->actor)) {
            Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_HORSE_GOAL);
            pthis->result = INGORACE_INGO_WIN;
            pthis->finishTimer = 20;
        }
        if ((gSaveContext.timer1Value >= 180) && (pthis->startFlags & 2)) {
            Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_HORSE_GOAL);
            pthis->result = INGORACE_TIME_UP;
            pthis->finishTimer = 20;
        }
    } else {
        if (pthis->finishTimer > 0) {
            pthis->finishTimer--;
        } else {
            EnHorseGameCheck_FinishIngoRace(pthis, globalCtx);
        }
    }
    return true;
}

s32 EnHorseGameCheck_InitGerudoArchery(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    EnHorseGameCheckGerudoArchery* pthis = (EnHorseGameCheckGerudoArchery*)base;

    pthis->base.type = HORSEGAME_GERUDO_ARCHERY;
    pthis->unk_150 = 0;
    pthis->startTimer = 0;
    return true;
}

s32 EnHorseGameCheck_DestroyGerudoArchery(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    return true;
}

s32 EnHorseGameCheck_UpdateGerudoArchery(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    EnHorseGameCheckGerudoArchery* pthis = (EnHorseGameCheckGerudoArchery*)base;
    Player* player = GET_PLAYER(globalCtx);
    EnHorse* horse = (EnHorse*)player->rideActor;

    if (horse == NULL) {
        return true;
    }

    if (pthis->startTimer > 90) {
        if (globalCtx) {}
        horse->hbaStarted = 1;
    }
    pthis->startTimer++;
    return true;
}

s32 EnHorseGameCheck_InitType3(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    EnHorseGameCheck3* pthis = (EnHorseGameCheck3*)base;

    pthis->base.type = HORSEGAME_TYPE3;
    pthis->unk_150 = 0;
    return true;
}

s32 EnHorseGameCheck_DestroyType3(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    return true;
}

s32 EnHorseGameCheck_UpdateType3(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    return true;
}

s32 EnHorseGameCheck_InitMalonRace(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    EnHorseGameCheckMalonRace* pthis = (EnHorseGameCheckMalonRace*)base;
    s32 i;

    pthis->base.type = HORSEGAME_MALON_RACE;
    pthis->raceFlags = 0;
    pthis->finishTimer = 0;
    pthis->result = MALONRACE_NO_RESULT;
    for (i = 0; i < 16; i++) {
        pthis->fenceCheck[i] = 0;
    }
    pthis->lapCount = 0;
    return true;
}

s32 EnHorseGameCheck_DestroyMalonRace(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    return true;
}

void EnHorseGameCheck_FinishMalonRace(EnHorseGameCheckMalonRace* pthis, GlobalContext* globalCtx) {
    if ((pthis->result == MALONRACE_SUCCESS) || (pthis->result == MALONRACE_TIME_UP)) {
        gSaveContext.cutsceneIndex = 0;
        globalCtx->nextEntranceIndex = 0x4CE;
        globalCtx->fadeTransition = 0x2E;
        globalCtx->sceneLoadFlag = 0x14;
    } else if (pthis->result == MALONRACE_FAILURE) {
        gSaveContext.timer1Value = 240;
        gSaveContext.timer1State = 0xF;
        gSaveContext.cutsceneIndex = 0;
        globalCtx->nextEntranceIndex = 0x4CE;
        globalCtx->fadeTransition = 0x2E;
        globalCtx->sceneLoadFlag = 0x14;
    } else {
        // "not supported"
        osSyncPrintf("En_HGC_Spot20_Ta_end():対応せず\n");
        gSaveContext.cutsceneIndex = 0;
        globalCtx->nextEntranceIndex = 0x157;
        globalCtx->fadeTransition = 0x2E;
        globalCtx->sceneLoadFlag = 0x14;
    }
}

s32 EnHorseGameCheck_UpdateMalonRace(EnHorseGameCheckBase* base, GlobalContext* globalCtx) {
    EnHorseGameCheckMalonRace* pthis = (EnHorseGameCheckMalonRace*)base;
    s32 i;
    Player* player = GET_PLAYER(globalCtx);
    EnHorse* horse;

    if (!(pthis->raceFlags & MALONRACE_PLAYER_ON_MARK) && AT_FINISH_LINE(player->rideActor)) {
        pthis->raceFlags |= MALONRACE_PLAYER_ON_MARK;
    } else if ((pthis->raceFlags & MALONRACE_PLAYER_ON_MARK) && !(pthis->raceFlags & MALONRACE_PLAYER_START) &&
               !AT_FINISH_LINE(player->rideActor)) {
        pthis->raceFlags |= MALONRACE_PLAYER_START;
    }
    if ((pthis->startTimer > 50) && !(pthis->raceFlags & MALONRACE_SET_TIMER)) {
        pthis->raceFlags |= MALONRACE_SET_TIMER;
        func_80088B34(0);
    } else if ((pthis->startTimer > 80) && (player->rideActor != NULL) && !(pthis->raceFlags & MALONRACE_PLAYER_MOVE)) {
        pthis->raceFlags |= MALONRACE_PLAYER_MOVE;
        horse = (EnHorse*)player->rideActor;

        horse->inRace = 1;
    } else if ((pthis->startTimer > 81) && !(pthis->raceFlags & MALONRACE_START_SFX)) {
        pthis->raceFlags |= MALONRACE_START_SFX;
        Audio_PlaySoundGeneral(NA_SE_SY_START_SHOT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    }

    pthis->startTimer++;
    if (pthis->result == MALONRACE_NO_RESULT) {
        Player* player2 = player;
        f32 dist;

        for (i = 0; i < 16; i++) {
            if ((pthis->lapCount == 0) && (i >= 8)) {
                break;
            }
            dist = Math_Vec3f_DistXZ(&sFencePos[i % 8], &player2->rideActor->world.pos);
            if ((player->rideActor != NULL) && (dist < 250.0f)) {
                horse = (EnHorse*)player2->rideActor;

                if (horse->stateFlags & ENHORSE_JUMPING) {
                    if ((i > 0) && (pthis->fenceCheck[i - 1] == 1)) {
                        pthis->fenceCheck[i] = 1;
                    } else if (i == 0) {
                        pthis->fenceCheck[i] = 1;
                    }

                    if ((pthis->fenceCheck[i - 1] == 0) && !(pthis->raceFlags & MALONRACE_BROKE_RULE)) {
                        pthis->raceFlags |= MALONRACE_BROKE_RULE;
                        Message_StartTextbox(globalCtx, 0x208C, NULL);
                        pthis->result = 4;
                        pthis->finishTimer = 30;
                    }
                }
            }
        }
        if ((player2->rideActor != NULL) && (pthis->raceFlags & MALONRACE_PLAYER_START) &&
            AT_FINISH_LINE(player2->rideActor)) {
            if ((pthis->lapCount == 1) && (pthis->fenceCheck[15] == 0) && (player2->rideActor->prevPos.x < -200.0f)) {
                pthis->raceFlags |= MALONRACE_BROKE_RULE;
                Message_StartTextbox(globalCtx, 0x208C, NULL);
                pthis->result = MALONRACE_FAILURE;
                pthis->finishTimer = 30;
            } else if (pthis->fenceCheck[15] == 1) {
                pthis->lapCount = 2;
                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_HORSE_GOAL);
                Audio_PlaySoundGeneral(NA_SE_SY_START_SHOT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
                pthis->result = MALONRACE_SUCCESS;
                pthis->finishTimer = 70;
                gSaveContext.timer1State = 0xF;
            } else if ((pthis->fenceCheck[7] == 1) && !(pthis->raceFlags & MALONRACE_SECOND_LAP)) {
                pthis->lapCount = 1;
                pthis->raceFlags |= MALONRACE_SECOND_LAP;
                Message_StartTextbox(globalCtx, 0x208D, NULL);
            } else if (pthis->fenceCheck[7] == 0) {
                pthis->raceFlags |= MALONRACE_BROKE_RULE;
                Message_StartTextbox(globalCtx, 0x208C, NULL);
                pthis->result = MALONRACE_FAILURE;
                pthis->finishTimer = 30;
            } else if (player2->rideActor->prevPos.x > 80.0f) {
                pthis->raceFlags |= MALONRACE_BROKE_RULE;
                Message_StartTextbox(globalCtx, 0x208C, NULL);
                pthis->result = MALONRACE_FAILURE;
                pthis->finishTimer = 30;
            }
        }
        if ((gSaveContext.timer1Value >= 180) && (pthis->raceFlags & MALONRACE_SET_TIMER)) {
            gSaveContext.timer1Value = 240;
            pthis->result = MALONRACE_TIME_UP;
            pthis->finishTimer = 30;
            gSaveContext.timer1State = 0;
        }
    } else {
        if (pthis->finishTimer > 0) {
            pthis->finishTimer--;
        } else {
            EnHorseGameCheck_FinishMalonRace(pthis, globalCtx);
        }
    }
    return true;
}

static EnHorseGameCheckFunc sInitFuncs[] = {
    NULL,
    EnHorseGameCheck_InitIngoRace,
    EnHorseGameCheck_InitGerudoArchery,
    EnHorseGameCheck_InitType3,
    EnHorseGameCheck_InitMalonRace,
};

static EnHorseGameCheckFunc sDestroyFuncs[] = {
    NULL,
    EnHorseGameCheck_DestroyIngoRace,
    EnHorseGameCheck_DestroyGerudoArchery,
    EnHorseGameCheck_DestroyType3,
    EnHorseGameCheck_DestroyMalonRace,
};

static EnHorseGameCheckFunc sUpdateFuncs[] = {
    NULL,
    EnHorseGameCheck_UpdateIngoRace,
    EnHorseGameCheck_UpdateGerudoArchery,
    EnHorseGameCheck_UpdateType3,
    EnHorseGameCheck_UpdateMalonRace,
};

void EnHorseGameCheck_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnHorseGameCheckBase* pthis = (EnHorseGameCheckBase*)thisx;

    if ((globalCtx->sceneNum == SCENE_SPOT20) && (Flags_GetEventChkInf(0x18) || DREG(1))) {
        pthis->actor.params = HORSEGAME_MALON_RACE;
    }
    if (sInitFuncs[pthis->actor.params] != NULL) {
        sInitFuncs[pthis->actor.params](pthis, globalCtx);
    }
}

void EnHorseGameCheck_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnHorseGameCheckBase* pthis = (EnHorseGameCheckBase*)thisx;

    if (sDestroyFuncs[pthis->actor.params] != NULL) {
        sDestroyFuncs[pthis->actor.params](pthis, globalCtx);
    }
}

void EnHorseGameCheck_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnHorseGameCheckBase* pthis = (EnHorseGameCheckBase*)thisx;

    if (sUpdateFuncs[pthis->type] != NULL) {
        sUpdateFuncs[pthis->type](pthis, globalCtx);
    }
}

void EnHorseGameCheck_Draw(Actor* thisx, GlobalContext* globalCtx) {
}

void EnHorseGameCheck_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Horse_Game_Check_InitVars = {
        ACTOR_EN_HORSE_GAME_CHECK,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnHorseGameCheck),
        (ActorFunc)EnHorseGameCheck_Init,
        (ActorFunc)EnHorseGameCheck_Destroy,
        (ActorFunc)EnHorseGameCheck_Update,
        (ActorFunc)EnHorseGameCheck_Draw,
        (ActorFunc)EnHorseGameCheck_Reset,
    };

    sUnusedZeroVec = { 0.0f, 0.0f, 0.0f };

}
