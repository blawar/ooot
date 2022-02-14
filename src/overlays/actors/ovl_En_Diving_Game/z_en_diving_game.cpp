#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DIVING_GAME_Z_EN_DIVING_GAME_C
#include "actor_common.h"
/*
 * File: z_en_diving_game.c
 * Overlay: ovl_En_Diving_Game
 * Description: Diving minigame
 */

#include "z_en_diving_game.h"
#include "overlays/actors/ovl_En_Ex_Ruppy/z_en_ex_ruppy.h"
#include "objects/object_zo/object_zo.h"
#include "vt.h"
#include "def/code_800EC960.h"
#include "def/code_800FD970.h"
#include "def/graph.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnDivingGame_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDivingGame_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDivingGame_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDivingGame_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809EDCB0(EnDivingGame* pthis, GlobalContext* globalCtx);
void EnDivingGame_Talk(EnDivingGame* pthis, GlobalContext* globalCtx);
void EnDivingGame_HandlePlayChoice(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EE048(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EE0FC(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EE194(EnDivingGame* pthis, GlobalContext* globalCtx);
void EnDivingGame_SetupRupeeThrow(EnDivingGame* pthis, GlobalContext* globalCtx);
void EnDivingGame_RupeeThrow(EnDivingGame* pthis, GlobalContext* globalCtx);
void EnDivingGame_SetupUnderwaterViewCs(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EE780(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EE800(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EE8F0(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EE96C(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EEA00(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EEA90(EnDivingGame* pthis, GlobalContext* globalCtx);
void func_809EEAF8(EnDivingGame* pthis, GlobalContext* globalCtx);

ActorInit En_Diving_Game_InitVars = {
    ACTOR_EN_DIVING_GAME,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZO,
    sizeof(EnDivingGame),
    (ActorFunc)EnDivingGame_Init,
    (ActorFunc)EnDivingGame_Destroy,
    (ActorFunc)EnDivingGame_Update,
    (ActorFunc)EnDivingGame_Draw,
};

// used to ensure there's only one instance of pthis actor.
static u8 D_809EF0B0 = false;

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 10, 10, 0, { 0, 0, 0 } },
};

static void* sEyeTextures[] = {
    gZoraEyeOpenTex,
    gZoraEyeHalfTex,
    gZoraEyeClosedTex,
};

void EnDivingGame_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDivingGame* pthis = (EnDivingGame*)thisx;

    pthis->actor.gravity = -3.0f;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gZoraSkel, &gZoraIdleAnim, pthis->jointTable, pthis->morphTable, 20);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 素もぐりＧＯ ☆☆☆☆☆ \n" VT_RST);
    pthis->actor.room = -1;
    pthis->actor.scale.x = 0.01f;
    pthis->actor.scale.y = 0.012999999f;
    pthis->actor.scale.z = 0.0139999995f;
    if (D_809EF0B0) {
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ もういてる原 ☆☆☆☆☆ \n" VT_RST);
        pthis->unk_31F = 1;
        Actor_Kill(&pthis->actor);
    } else {
        D_809EF0B0 = true;
        pthis->actor.targetMode = 0;
        pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
        pthis->actionFunc = func_809EDCB0;
    }
}

void EnDivingGame_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDivingGame* pthis = (EnDivingGame*)thisx;

    if (pthis->unk_31F == 0) {
        gSaveContext.timer1State = 0;
    }
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnDivingGame_SpawnRuppy(EnDivingGame* pthis, GlobalContext* globalCtx) {
    EnExRuppy* rupee;
    Vec3f rupeePos;

    rupeePos.x = (Rand_ZeroOne() - 0.5f) * 30.0f + pthis->actor.world.pos.x;
    rupeePos.y = (Rand_ZeroOne() - 0.5f) * 20.0f + (pthis->actor.world.pos.y + 30.0f);
    rupeePos.z = (Rand_ZeroOne() - 0.5f) * 20.0f + pthis->actor.world.pos.z;
    rupee = (EnExRuppy*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_EX_RUPPY, rupeePos.x,
                                           rupeePos.y, rupeePos.z, 0, (s16)Rand_CenteredFloat(3500.0f) - 1000,
                                           pthis->rupeesLeftToThrow, 0);
    if (rupee != NULL) {
        rupee->actor.speedXZ = 12.0f;
        rupee->actor.velocity.y = 6.0f;
    }
}

s32 EnDivingGame_HasMinigameFinished(EnDivingGame* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.timer1State == 10 && !Gameplay_InCsMode(globalCtx)) {
        // Failed.
        gSaveContext.timer1State = 0;
        func_800F5B58();
        func_80078884(NA_SE_SY_FOUND);
        pthis->actor.textId = 0x71AD;
        Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
        pthis->unk_292 = TEXT_STATE_EVENT;
        pthis->allRupeesThrown = pthis->state = pthis->phase = pthis->unk_2A2 = pthis->grabbedRupeesCounter = 0;
        func_8002DF54(globalCtx, NULL, 8);
        pthis->actionFunc = func_809EE048;
        return true;
    } else {
        s32 rupeesNeeded = 5;

        if (gSaveContext.eventChkInf[3] & 0x100) {
            rupeesNeeded = 10;
        }
        if (pthis->grabbedRupeesCounter >= rupeesNeeded) {
            // Won.
            gSaveContext.timer1State = 0;
            pthis->allRupeesThrown = pthis->state = pthis->phase = pthis->unk_2A2 = pthis->grabbedRupeesCounter = 0;
            if (!(gSaveContext.eventChkInf[3] & 0x100)) {
                pthis->actor.textId = 0x4055;
            } else {
                pthis->actor.textId = 0x405D;
                if (pthis->extraWinCount < 100) {
                    pthis->extraWinCount++;
                }
            }
            Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
            pthis->unk_292 = TEXT_STATE_EVENT;
            func_800F5B58();
            Audio_PlayFanfare(NA_BGM_SMALL_ITEM_GET);
            func_8002DF54(globalCtx, NULL, 8);
            if (!(gSaveContext.eventChkInf[3] & 0x100)) {
                pthis->actionFunc = func_809EE96C;
            } else {
                pthis->actionFunc = func_809EE048;
            }
            return true;
        }
    }
    return false;
}

// EnDivingGame_FinishMinigame ? // Reset probably
void func_809EDCB0(EnDivingGame* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gZoraIdleAnim);

    Animation_Change(&pthis->skelAnime, &gZoraIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    pthis->notPlayingMinigame = true;
    pthis->actionFunc = EnDivingGame_Talk;
}

void EnDivingGame_Talk(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->state != ENDIVINGGAME_STATE_PLAYING || !EnDivingGame_HasMinigameFinished(pthis, globalCtx)) {
        if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
            if (pthis->unk_292 != TEXT_STATE_DONE) {
                switch (pthis->state) {
                    case ENDIVINGGAME_STATE_NOTPLAYING:
                        func_8002DF54(globalCtx, NULL, 8);
                        pthis->actionFunc = EnDivingGame_HandlePlayChoice;
                        break;
                    case ENDIVINGGAME_STATE_AWARDPRIZE:
                        pthis->actionFunc = func_809EEA00;
                        break;
                    case ENDIVINGGAME_STATE_PLAYING:
                        pthis->actionFunc = func_809EE8F0;
                        break;
                }
            }
        } else {
            if (Text_GetFaceReaction(globalCtx, 0x1D) != 0) {
                pthis->actor.textId = Text_GetFaceReaction(globalCtx, 0x1D);
                pthis->unk_292 = TEXT_STATE_DONE;
            } else {
                switch (pthis->state) {
                    case ENDIVINGGAME_STATE_NOTPLAYING:
                        pthis->unk_292 = TEXT_STATE_CHOICE;
                        if (!(gSaveContext.eventChkInf[3] & 0x100)) {
                            pthis->actor.textId = 0x4053;
                            pthis->phase = ENDIVINGGAME_PHASE_1;
                        } else {
                            pthis->actor.textId = 0x405C;
                            pthis->phase = ENDIVINGGAME_PHASE_2;
                        }
                        break;
                    case ENDIVINGGAME_STATE_AWARDPRIZE:
                        pthis->actor.textId = 0x4056;
                        pthis->unk_292 = TEXT_STATE_EVENT;
                        break;
                    case ENDIVINGGAME_STATE_PLAYING:
                        pthis->actor.textId = 0x405B;
                        pthis->unk_292 = TEXT_STATE_EVENT;
                        break;
                }
            }
            func_8002F2CC(&pthis->actor, globalCtx, 80.0f);
        }
    }
}

void EnDivingGame_HandlePlayChoice(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_292 == Message_GetState(&globalCtx->msgCtx) &&
        Message_ShouldAdvance(globalCtx)) { // Did player selected an answer?
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // Yes
                if (gSaveContext.rupees >= 20) {
                    Rupees_ChangeBy(-20);
                    pthis->actor.textId = 0x4054;
                } else {
                    pthis->actor.textId = 0x85;
                    pthis->allRupeesThrown = pthis->state = pthis->phase = pthis->unk_2A2 = pthis->grabbedRupeesCounter = 0;
                }
                break;
            case 1: // No
                pthis->actor.textId = 0x2D;
                pthis->allRupeesThrown = pthis->state = pthis->phase = pthis->unk_2A2 = pthis->grabbedRupeesCounter = 0;
                break;
        }
        if (!(gSaveContext.eventChkInf[3] & 0x100) || pthis->actor.textId == 0x85 || pthis->actor.textId == 0x2D) {
            Message_ContinueTextbox(globalCtx, pthis->actor.textId);
            pthis->unk_292 = TEXT_STATE_EVENT;
            pthis->actionFunc = func_809EE048;
        } else {
            globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
            func_8002DF54(globalCtx, NULL, 8);
            pthis->actionFunc = func_809EE0FC;
        }
    }
}

// Waits for the message to close
void func_809EE048(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_292 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx)) {
        if (pthis->phase == ENDIVINGGAME_PHASE_ENDED) {
            Message_CloseTextbox(globalCtx);
            func_8002DF54(globalCtx, NULL, 7);
            pthis->actionFunc = func_809EDCB0;
        } else {
            globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
            func_8002DF54(globalCtx, NULL, 8);
            pthis->actionFunc = func_809EE0FC;
        }
    }
}

// another "start minigame" step
void func_809EE0FC(EnDivingGame* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gZoraThrowRupeesAnim);

    Animation_Change(&pthis->skelAnime, &gZoraThrowRupeesAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_ONCE, -10.0f);
    pthis->notPlayingMinigame = false;
    pthis->actionFunc = func_809EE194;
}

// Wait a bit before start throwing the rupees.
void func_809EE194(EnDivingGame* pthis, GlobalContext* globalCtx) {
    f32 currentFrame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    if (currentFrame >= 15.0f) {
        pthis->actionFunc = EnDivingGame_SetupRupeeThrow;
    }
}

void EnDivingGame_SetupRupeeThrow(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    pthis->subCamId = Gameplay_CreateSubCamera(globalCtx);
    Gameplay_ChangeCameraStatus(globalCtx, 0, CAM_STAT_WAIT);
    Gameplay_ChangeCameraStatus(globalCtx, pthis->subCamId, CAM_STAT_ACTIVE);
    pthis->spawnRuppyTimer = 10;
    pthis->unk_2F4.x = -210.0f;
    pthis->unk_2F4.y = -80.0f;
    pthis->unk_2F4.z = -1020.0f;
    pthis->unk_2D0.x = -280.0f;
    pthis->unk_2D0.y = -20.0f;
    pthis->unk_2D0.z = -240.0f;
    if (!(gSaveContext.eventChkInf[3] & 0x100)) {
        pthis->rupeesLeftToThrow = 5;
    } else {
        pthis->rupeesLeftToThrow = 10;
    }
    pthis->unk_2DC.x = pthis->unk_2DC.y = pthis->unk_2DC.z = pthis->unk_300.x = pthis->unk_300.y = pthis->unk_300.z = 0.1f;
    pthis->camLookAt.x = globalCtx->view.lookAt.x;
    pthis->camLookAt.y = globalCtx->view.lookAt.y;
    pthis->camLookAt.z = globalCtx->view.lookAt.z;
    pthis->camEye.x = globalCtx->view.eye.x;
    pthis->camEye.y = globalCtx->view.eye.y + 80.0f;
    pthis->camEye.z = globalCtx->view.eye.z + 250.0f;
    pthis->unk_2E8.x = fabsf(pthis->camEye.x - pthis->unk_2D0.x) * 0.04f;
    pthis->unk_2E8.y = fabsf(pthis->camEye.y - pthis->unk_2D0.y) * 0.04f;
    pthis->unk_2E8.z = fabsf(pthis->camEye.z - pthis->unk_2D0.z) * 0.04f;
    pthis->unk_30C.x = fabsf(pthis->camLookAt.x - pthis->unk_2F4.x) * 0.04f;
    pthis->unk_30C.y = fabsf(pthis->camLookAt.y - pthis->unk_2F4.y) * 0.04f;
    pthis->unk_30C.z = fabsf(pthis->camLookAt.z - pthis->unk_2F4.z) * 0.04f;
    Gameplay_CameraSetAtEye(globalCtx, pthis->subCamId, &pthis->camLookAt, &pthis->camEye);
    Gameplay_CameraSetFov(globalCtx, pthis->subCamId, globalCtx->mainCamera.fov);
    pthis->csCameraTimer = 60;
    pthis->actionFunc = EnDivingGame_RupeeThrow;
    pthis->unk_318 = 0.0f;
}

// Throws rupee when pthis->spawnRuppyTimer == 0
void EnDivingGame_RupeeThrow(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (func_800C0DB4(globalCtx, &pthis->actor.projectedPos)) {
        Audio_SetExtraFilter(0);
    }
    if (pthis->subCamId != 0) {
        Math_ApproachF(&pthis->camEye.x, pthis->unk_2D0.x, pthis->unk_2DC.x, pthis->unk_2E8.x * pthis->unk_318);
        Math_ApproachF(&pthis->camEye.z, pthis->unk_2D0.z, pthis->unk_2DC.z, pthis->unk_2E8.z * pthis->unk_318);
        Math_ApproachF(&pthis->camLookAt.x, pthis->unk_2F4.x, pthis->unk_300.x, pthis->unk_30C.x * pthis->unk_318);
        Math_ApproachF(&pthis->camLookAt.y, pthis->unk_2F4.y, pthis->unk_300.y, pthis->unk_30C.y * pthis->unk_318);
        Math_ApproachF(&pthis->camLookAt.z, pthis->unk_2F4.z, pthis->unk_300.z, pthis->unk_30C.z * pthis->unk_318);
        Math_ApproachF(&pthis->unk_318, 1.0f, 1.0f, 0.02f);
    }
    Gameplay_CameraSetAtEye(globalCtx, pthis->subCamId, &pthis->camLookAt, &pthis->camEye);
    if (!pthis->allRupeesThrown && pthis->spawnRuppyTimer == 0) {
        pthis->spawnRuppyTimer = 5;
        EnDivingGame_SpawnRuppy(pthis, globalCtx);
        pthis->rupeesLeftToThrow--;
        if (!(gSaveContext.eventChkInf[3] & 0x100)) {
            pthis->unk_296 = 30;
        } else {
            pthis->unk_296 = 5;
        }
        if (pthis->rupeesLeftToThrow <= 0) {
            pthis->rupeesLeftToThrow = 0;
            pthis->allRupeesThrown = true;
        }
    }
    if (pthis->csCameraTimer == 0 ||
        ((fabsf(pthis->camEye.x - pthis->unk_2D0.x) < 2.0f) && (fabsf(pthis->camEye.y - pthis->unk_2D0.y) < 2.0f) &&
         (fabsf(pthis->camEye.z - pthis->unk_2D0.z) < 2.0f) && (fabsf(pthis->camLookAt.x - pthis->unk_2F4.x) < 2.0f) &&
         (fabsf(pthis->camLookAt.y - pthis->unk_2F4.y) < 2.0f) && (fabsf(pthis->camLookAt.z - pthis->unk_2F4.z) < 2.0f))) {
        if (pthis->unk_2A2 != 0) {
            pthis->csCameraTimer = 70;
            pthis->unk_2A2 = 2;
            pthis->actionFunc = func_809EE780;
        } else {
            pthis->actionFunc = EnDivingGame_SetupUnderwaterViewCs;
        }
    }
}

// Called just before changing the camera to focus the underwater rupees.
void EnDivingGame_SetupUnderwaterViewCs(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_296 == 0) {
        pthis->unk_2A2 = 1;
        pthis->csCameraTimer = 100;
        pthis->actionFunc = EnDivingGame_RupeeThrow;
        pthis->camLookAt.x = pthis->unk_2F4.x = -210.0f;
        pthis->camLookAt.y = pthis->unk_2F4.y = -80.0f;
        pthis->camLookAt.z = pthis->unk_2F4.z = -1020.0f;
        pthis->camEye.x = pthis->unk_2D0.x = -280.0f;
        pthis->camEye.y = pthis->unk_2D0.y = -20.0f;
        pthis->camEye.z = pthis->unk_2D0.z = -240.0f;
    }
}

// EnDivingGame_SayStartAndWait ?
void func_809EE780(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->csCameraTimer == 0) {
        Gameplay_ClearCamera(globalCtx, pthis->subCamId);
        Gameplay_ChangeCameraStatus(globalCtx, 0, CAM_STAT_ACTIVE);
        pthis->actor.textId = 0x405A;
        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
        pthis->unk_292 = TEXT_STATE_EVENT;
        pthis->actionFunc = func_809EE800;
    }
}

// EnDivingGame_TalkDuringMinigame
void func_809EE800(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_292 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        if (!(gSaveContext.eventChkInf[3] & 0x100)) {
            func_80088B34(BREG(2) + 50);
        } else {
            func_80088B34(BREG(2) + 50);
        }
        func_800F5ACC(NA_BGM_MINI_GAME_2);
        func_8002DF54(globalCtx, NULL, 7);
        pthis->actor.textId = 0x405B;
        pthis->unk_292 = TEXT_STATE_EVENT;
        pthis->state = ENDIVINGGAME_STATE_PLAYING;
        pthis->actionFunc = EnDivingGame_Talk;
    }
}

void func_809EE8F0(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((pthis->unk_292 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx))) {
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = EnDivingGame_Talk;
    } else {
        EnDivingGame_HasMinigameFinished(pthis, globalCtx);
    }
}

// EnDivingGame_SayCongratsAndWait ? // EnDivingGame_PlayerWonPhase1
void func_809EE96C(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((pthis->unk_292 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx))) {
        Message_CloseTextbox(globalCtx);
        func_8002DF54(globalCtx, NULL, 7);
        pthis->actor.textId = 0x4056;
        pthis->unk_292 = TEXT_STATE_EVENT;
        pthis->state = ENDIVINGGAME_STATE_AWARDPRIZE;
        pthis->actionFunc = EnDivingGame_Talk;
    }
}

void func_809EEA00(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((pthis->unk_292 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx))) {
        Message_CloseTextbox(globalCtx);
        pthis->actor.parent = NULL;
        func_8002F434(&pthis->actor, globalCtx, GI_SCALE_SILVER, 90.0f, 10.0f);
        pthis->actionFunc = func_809EEA90;
    }
}

void func_809EEA90(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_809EEAF8;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_SCALE_SILVER, 90.0f, 10.0f);
    }
}

// Award the scale?
void func_809EEAF8(EnDivingGame* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        // "Successful completion"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 正常終了 ☆☆☆☆☆ \n" VT_RST);
        pthis->allRupeesThrown = pthis->state = pthis->phase = pthis->unk_2A2 = pthis->grabbedRupeesCounter = 0;
        gSaveContext.eventChkInf[3] |= 0x100;
        pthis->actionFunc = func_809EDCB0;
    }
}

void EnDivingGame_Update(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnDivingGame* pthis = (EnDivingGame*)thisx;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f pos;

    if (pthis->csCameraTimer != 0) {
        pthis->csCameraTimer--;
    }
    if (pthis->unk_296 != 0) {
        pthis->unk_296--;
    }
    if (pthis->eyeTimer != 0) {
        pthis->eyeTimer--;
    }
    if (pthis->spawnRuppyTimer != 0) {
        pthis->spawnRuppyTimer--;
    }

    if (1) {}

    if (gSaveContext.timer1Value == 10) {
        func_800F5918();
    }
    if (pthis->eyeTimer == 0) {
        pthis->eyeTimer = 2;
        pthis->eyeTexIndex++;
        if (pthis->eyeTexIndex >= 3) {
            pthis->eyeTexIndex = 0;
            pthis->eyeTimer = (s16)Rand_ZeroFloat(60.0f) + 20;
        }
    }
    pthis->actionFunc(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, 80.0f);
    pthis->unk_324.unk_18 = player->actor.world.pos;
    pthis->unk_324.unk_18.y = player->actor.world.pos.y;
    func_80034A14(&pthis->actor, &pthis->unk_324, 2, 4);
    pthis->vec_284 = pthis->unk_324.unk_08;
    pthis->vec_28A = pthis->unk_324.unk_0E;
    if ((globalCtx->gameplayFrames % 16) == 0) {
        pos = pthis->actor.world.pos;
        pos.y += 20.0f;
        EffectSsGRipple_Spawn(globalCtx, &pos, 100, 500, 30);
    }
    pthis->unk_290++;
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 60.0f, 29);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

Gfx* EnDivingGame_EmptyDList(GraphicsContext* gfxCtx) {
    Gfx* displayList = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx));

    gSPEndDisplayList(displayList);
    return displayList;
}

s32 EnDivingGame_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                  void* thisx) {
    EnDivingGame* pthis = (EnDivingGame*)thisx;
    s32 pad;

    if (limbIndex == 6) {
        rot->x += pthis->vec_28A.y;
    }

    if (limbIndex == 15) {
        rot->x += pthis->vec_284.y;
        rot->z += pthis->vec_284.z;
    }

    if (pthis->notPlayingMinigame && (limbIndex == 8 || limbIndex == 9 || limbIndex == 12)) {
        rot->y += Math_SinS((globalCtx->state.frames * (limbIndex * 50 + 0x814)).toS16()) * 200.0f;
	    rot->z += Math_CosS((globalCtx->state.frames * (limbIndex * 50 + 0x940)).toS16()) * 200.0f;
    }

    return 0;
}

void EnDivingGame_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDivingGame* pthis = (EnDivingGame*)thisx;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_diving_game.c", 1212);
    func_80093D18(globalCtx->state.gfxCtx);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, EnDivingGame_EmptyDList(globalCtx->state.gfxCtx));
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures[pthis->eyeTexIndex]));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnDivingGame_OverrideLimbDraw, NULL, pthis);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_diving_game.c", 1232);
}
