#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BOM_BOWL_MAN_Z_EN_BOM_BOWL_MAN_C
#include "actor_common.h"
#include "z_en_bom_bowl_man.h"
#include "vt.h"
#include "overlays/actors/ovl_En_Syateki_Niw/z_en_syateki_niw.h"
#include "overlays/actors/ovl_En_Ex_Item/z_en_ex_item.h"
#include "objects/object_bg/object_bg.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_27)


void EnBomBowlMan_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlMan_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBomBowlMan_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlMan_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlMan_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnBomBowMan_SetupWaitAsleep(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_WaitAsleep(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_TalkAsleep(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_WakeUp(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_BlinkAwake(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_CheckBeatenDC(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_WaitNotBeatenDC(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_TalkNotBeatenDC(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_SetupRunGame(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_RunGame(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowlMan_HandlePlayChoice(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void func_809C41FC(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_SetupChooseShowPrize(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowMan_ChooseShowPrize(EnBomBowlMan* pthis, GlobalContext* globalCtx);
void EnBomBowlMan_BeginPlayGame(EnBomBowlMan* pthis, GlobalContext* globalCtx);

static f32 cuccoColliderDims_39[][3] = { { 16.0f, 46.0f, 0.0f }, { 36.0f, 56.0f, 0.0f } };

static Vec3f cuccoSpawnPos_39[] = { { 60, -60, -430 }, { 0, -120, -620 } };

static f32 cuccoScales_39[] = { 0.01f, 0.03f };

static void* eyeTextures_60[] = { gChuGirlEyeOpenTex, gChuGirlEyeHalfTex, gChuGirlEyeClosedTex };


ActorInit En_Bom_Bowl_Man_InitVars = {
    ACTOR_EN_BOM_BOWL_MAN,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_BG,
    sizeof(EnBomBowlMan),
    (ActorFunc)EnBomBowlMan_Init,
    (ActorFunc)EnBomBowlMan_Destroy,
    (ActorFunc)EnBomBowlMan_Update,
    (ActorFunc)EnBomBowlMan_Draw,
    (ActorFunc)EnBomBowlMan_Reset,
};

void EnBomBowlMan_Init(Actor* thisx, GlobalContext* globalCtx2) {
    EnBomBowlMan* pthis = (EnBomBowlMan*)thisx;
    EnSyatekiNiw* cucco;
    s32 i;
    GlobalContext* globalCtx = globalCtx2;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gChuGirlSkel, &gChuGirlNoddingOffAnim, pthis->jointTable,
                       pthis->morphTable, 11);
    // "☆ Man, my shoulders hurt~ ☆"
    osSyncPrintf(VT_FGCOL(GREEN) "☆ もー 肩こっちゃうよねぇ〜 \t\t ☆ \n" VT_RST);
    // "☆ Isn't there some sort of job that will pay better and be more relaxing? ☆ %d"
    osSyncPrintf(VT_FGCOL(GREEN) "☆ もっとラクしてもうかるバイトないかしら？ ☆ %d\n" VT_RST,
                 globalCtx->bombchuBowlingStatus);
    pthis->posCopy = pthis->actor.world.pos;
    pthis->actor.shape.yOffset = -60.0f;
    Actor_SetScale(&pthis->actor, 0.013f);

    for (i = 0; i < 2; i++) {
        cucco = (EnSyatekiNiw*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_SYATEKI_NIW, cuccoSpawnPos_39[i].x,
                                           cuccoSpawnPos_39[i].y, cuccoSpawnPos_39[i].z, 0, 0, 0, 1);

        if (cucco != NULL) {
            cucco->unk_2F4 = cuccoScales_39[i];
            cucco->collider.dim.radius = (s16)cuccoColliderDims_39[i][0];
            cucco->collider.dim.height = (s16)cuccoColliderDims_39[i][1];
        }
    }

    pthis->prizeSelect = (s16)Rand_ZeroFloat(4.99f);
    pthis->actor.targetMode = 1;
    pthis->actionFunc = EnBomBowMan_SetupWaitAsleep;
}

void EnBomBowlMan_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnBomBowMan_SetupWaitAsleep(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    pthis->frameCount = (f32)Animation_GetLastFrame(&gChuGirlNoddingOffAnim);
    Animation_Change(&pthis->skelAnime, &gChuGirlNoddingOffAnim, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_LOOP, -10.0f);
    pthis->actor.textId = 0xC0;
    pthis->dialogState = TEXT_STATE_EVENT;
    pthis->actionFunc = EnBomBowMan_WaitAsleep;
}

void EnBomBowMan_WaitAsleep(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;

    SkelAnime_Update(&pthis->skelAnime);

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnBomBowMan_TalkAsleep;
    } else {
        yawDiff = ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y));

        if (!(pthis->actor.xzDistToPlayer > 120.0f) && (yawDiff < 0x4300)) {
            func_8002F2CC(&pthis->actor, globalCtx, 120.0f);
        }
    }
}

void EnBomBowMan_TalkAsleep(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if ((Message_GetState(&globalCtx->msgCtx) == pthis->dialogState) && Message_ShouldAdvance(globalCtx)) {
        globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
        pthis->actionFunc = EnBomBowMan_WakeUp;
    }
}

void EnBomBowMan_WakeUp(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    pthis->frameCount = (f32)Animation_GetLastFrame(&gChuGirlWakeUpAnim);
    Animation_Change(&pthis->skelAnime, &gChuGirlWakeUpAnim, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_ONCE, -10.0f);
    pthis->eyeMode = CHU_GIRL_EYES_OPEN_SLOWLY;
    pthis->actionFunc = EnBomBowMan_BlinkAwake;
}

void EnBomBowMan_BlinkAwake(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    f32 frameCount = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    if (frameCount == 30.0f) {
        pthis->dialogState = TEXT_STATE_EVENT;

        // Check for beaten Dodongo's Cavern
        if ((gSaveContext.eventChkInf[2] & 0x20) || BREG(2)) {
            pthis->actor.textId = 0xBF;
        } else {
            pthis->actor.textId = 0x7058;
        }
    }
    Message_ContinueTextbox(globalCtx, pthis->actor.textId);

    if ((pthis->eyeTextureIndex == 0) && (pthis->eyeMode == CHU_GIRL_EYES_BLINK_RAPIDLY) && (pthis->blinkTimer == 0)) {
        // Blink twice, then move on
        pthis->eyeTextureIndex = 2;
        pthis->blinkCount++;
        if (pthis->blinkCount >= 3) {
            pthis->actionFunc = EnBomBowMan_CheckBeatenDC;
        }
    }
}

void EnBomBowMan_CheckBeatenDC(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if ((Message_GetState(&globalCtx->msgCtx) == pthis->dialogState) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->frameCount = (f32)Animation_GetLastFrame(&gChuGirlLeanOverCounterAnim);
        Animation_Change(&pthis->skelAnime, &gChuGirlLeanOverCounterAnim, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_LOOP,
                         -10.0f);
        pthis->eyeMode = CHU_GIRL_EYES_AWAKE;
        pthis->blinkTimer = (s16)Rand_ZeroFloat(60.0f) + 20;

        // Check for beaten Dodongo's Cavern
        if (!((gSaveContext.eventChkInf[2] & 0x20) || BREG(2))) {
            pthis->actionFunc = EnBomBowMan_WaitNotBeatenDC;
        } else {
            pthis->actor.textId = 0x18;
            pthis->dialogState = TEXT_STATE_CHOICE;
            Message_ContinueTextbox(globalCtx, pthis->actor.textId);
            pthis->actionFunc = EnBomBowlMan_HandlePlayChoice;
        }
    }
}

void EnBomBowMan_WaitNotBeatenDC(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnBomBowMan_TalkNotBeatenDC;
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, 120.0f);
    }
}

void EnBomBowMan_TalkNotBeatenDC(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if ((Message_GetState(&globalCtx->msgCtx) == pthis->dialogState) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = EnBomBowMan_WaitNotBeatenDC;
    }
}

void EnBomBowMan_SetupRunGame(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->minigamePlayStatus == 0) {
        if (!pthis->startedPlaying) {
            pthis->actor.textId = 0x18;
        } else {
            pthis->actor.textId = 0x1A;
        }

        pthis->dialogState = TEXT_STATE_CHOICE;
    } else {
        pthis->actor.textId = 0x19;
        pthis->dialogState = TEXT_STATE_EVENT;
    }

    pthis->actionFunc = EnBomBowMan_RunGame;
}

void EnBomBowMan_RunGame(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;

    SkelAnime_Update(&pthis->skelAnime);

    if (BREG(3)) {
        osSyncPrintf(VT_FGCOL(RED) "☆ game_play->bomchu_game_flag ☆ %d\n" VT_RST, globalCtx->bombchuBowlingStatus);
        // "HOW'S THE FIRST WALL DOING?"
        osSyncPrintf(VT_FGCOL(RED) "☆ 壁１の状態どう？ ☆ %d\n" VT_RST, pthis->wallStatus[0]);
        // "HOW'S THE SECOND WALL DOING?"
        osSyncPrintf(VT_FGCOL(RED) "☆ 壁２の状態どう？ ☆ %d\n" VT_RST, pthis->wallStatus[1]);
        // "HOLE INFORMATION"
        osSyncPrintf(VT_FGCOL(RED) "☆ 穴情報\t     ☆ %d\n" VT_RST, pthis->bowlPit->status);
        osSyncPrintf("\n\n");
    }

    pthis->gameResult = 0;

    if (pthis->bowlPit != NULL) {
        if ((pthis->wallStatus[0] != 1) && (pthis->wallStatus[1] != 1) && (pthis->bowlPit->status == 2)) {
            pthis->gameResult = 1; // Won
            pthis->bowlPit->status = 0;
            // "Center HIT!"
            osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 中央ＨＩＴ！！！！ ☆☆☆☆☆ \n" VT_RST);
        }

        if ((globalCtx->bombchuBowlingStatus == -1) &&
            (globalCtx->actorCtx.actorLists[ACTORCAT_EXPLOSIVE].length == 0) && (pthis->bowlPit->status == 0) &&
            (pthis->wallStatus[0] != 1) && (pthis->wallStatus[1] != 1)) {
            pthis->gameResult = 2; // Lost
            // "Bombchu lost"
            osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ ボムチュウ消化 ☆☆☆☆☆ \n" VT_RST);
        }
    }

    if (pthis->gameResult != 0) { // won or lost
        pthis->actor.textId = 0x1A;
        pthis->dialogState = TEXT_STATE_CHOICE;
        pthis->minigamePlayStatus = 0;

        if ((pthis->exItem != NULL) && (pthis->exItem->actor.update != NULL)) {
            pthis->exItem->killItem = true;
            pthis->exItem = NULL;
        }

        globalCtx->bombchuBowlingStatus = 0;
        pthis->playingAgain = true;
        Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);

        if (pthis->gameResult == 2) {
            func_8002DF54(globalCtx, NULL, 8);
        }
        pthis->actionFunc = EnBomBowlMan_HandlePlayChoice;
    } else {
        if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
            if (pthis->minigamePlayStatus == 0) {
                pthis->actionFunc = EnBomBowlMan_HandlePlayChoice;
            } else {
                pthis->actionFunc = func_809C41FC;
            }
        } else {
            yawDiff = ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y));

            if (!(pthis->actor.xzDistToPlayer > 120.0f) && (yawDiff < 0x4300)) {
                func_8002F2CC(&pthis->actor, globalCtx, 120.0f);
            }
        }
    }
}

void EnBomBowlMan_HandlePlayChoice(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if ((Message_GetState(&globalCtx->msgCtx) == pthis->dialogState) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);

        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // Yes
                if (gSaveContext.rupees >= 30) {
                    Rupees_ChangeBy(-30);
                    pthis->minigamePlayStatus = 1;
                    pthis->wallStatus[0] = pthis->wallStatus[1] = 0;
                    globalCtx->bombchuBowlingStatus = 10;
                    Flags_SetSwitch(globalCtx, 0x38);

                    if (!pthis->startedPlaying && !pthis->playingAgain) {
                        pthis->actor.textId = 0x19;
                        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                        pthis->dialogState = TEXT_STATE_EVENT;
                        pthis->actionFunc = func_809C41FC;
                    } else {
                        pthis->actor.textId = 0x1B;
                        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                        pthis->dialogState = TEXT_STATE_EVENT;
                        OnePointCutscene_Init(globalCtx, 8010, -99, NULL, MAIN_CAM);
                        func_8002DF54(globalCtx, NULL, 8);
                        pthis->actionFunc = EnBomBowMan_SetupChooseShowPrize;
                    }
                } else {
                    pthis->playingAgain = false;
                    pthis->actor.textId = 0x85;
                    Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                    pthis->dialogState = TEXT_STATE_EVENT;
                    pthis->actionFunc = func_809C41FC;
                }
                break;

            case 1: // No
                pthis->playingAgain = false;
                pthis->actor.textId = 0x2D;
                Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                pthis->dialogState = TEXT_STATE_EVENT;
                pthis->actionFunc = func_809C41FC;
        }
    }
}

void func_809C41FC(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((Message_GetState(&globalCtx->msgCtx) == pthis->dialogState) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);

        if (((pthis->actor.textId == 0x2D) || (pthis->actor.textId == 0x85)) && Flags_GetSwitch(globalCtx, 0x38)) {
            Flags_UnsetSwitch(globalCtx, 0x38);
        }

        if (pthis->minigamePlayStatus == 1) {
            pthis->actor.textId = 0x1B;
            Message_ContinueTextbox(globalCtx, pthis->actor.textId);
            pthis->dialogState = TEXT_STATE_EVENT;
            OnePointCutscene_Init(globalCtx, 8010, -99, NULL, MAIN_CAM);
            func_8002DF54(globalCtx, NULL, 8);
            pthis->actionFunc = EnBomBowMan_SetupChooseShowPrize;
        } else {
            if (pthis->gameResult == 2) {
                func_8002DF54(globalCtx, NULL, 7);
            }
            pthis->actionFunc = EnBomBowMan_SetupRunGame;
        }
    }
}

void EnBomBowMan_SetupChooseShowPrize(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    Vec3f accel = { 0.0f, 0.1f, 0.0f };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;

    SkelAnime_Update(&pthis->skelAnime);

    if ((Message_GetState(&globalCtx->msgCtx) == pthis->dialogState) && Message_ShouldAdvance(globalCtx)) {
        pos.x = 148.0f;
        pos.y = 40.0f;
        pos.z = 300.0f;
        EffectSsBomb2_SpawnLayered(globalCtx, &pos, &velocity, &accel, 50, 15);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_GOODS_APPEAR);
        pthis->prizeRevealTimer = 10;
        pthis->actionFunc = EnBomBowMan_ChooseShowPrize;
    }
}

static Vec3f sPrizePosOffset[] = {
    { 0.0f, 22.0f, 0.0f }, { 0.0f, 22.0f, 0.0f }, { 0.0f, 8.0f, 0.0f }, { 0.0f, 9.0f, 0.0f }, { 0.0f, -2.0f, 0.0f },
};

static s16 sPrizeRot[] = { 0x4268, 0x4268, -0x03E8, 0x0000, 0x4268, 0x0000 };

void EnBomBowMan_ChooseShowPrize(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    s16 prizeTemp;
    s32 pad;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->prizeRevealTimer == 0) {
        switch (pthis->prizeSelect) {
            case 0:
                prizeTemp = EXITEM_BOMB_BAG_BOWLING;
                if (gSaveContext.itemGetInf[1] & 2) {
                    prizeTemp = EXITEM_PURPLE_RUPEE_BOWLING;
                }
                break;
            case 1:
                prizeTemp = EXITEM_PURPLE_RUPEE_BOWLING;
                break;
            case 2:
                prizeTemp = EXITEM_BOMBCHUS_BOWLING;
                break;
            case 3:
                prizeTemp = EXITEM_HEART_PIECE_BOWLING;
                if (gSaveContext.itemGetInf[1] & 4) {
                    prizeTemp = EXITEM_PURPLE_RUPEE_BOWLING;
                }
                break;
            case 4:
                prizeTemp = EXITEM_BOMBS_BOWLING;
                break;
        }

        pthis->prizeIndex = prizeTemp;

        if (BREG(7)) {
            pthis->prizeIndex = BREG(7) - 1;
        }

        pthis->exItem = (EnExItem*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_EX_ITEM,
                                                     sPrizePosOffset[pthis->prizeIndex].x + 148.0f,
                                                     sPrizePosOffset[pthis->prizeIndex].y + 40.0f,
                                                     sPrizePosOffset[pthis->prizeIndex].z + 300.0f, 0,
                                                     sPrizeRot[pthis->prizeIndex], 0, pthis->prizeIndex + EXITEM_COUNTER);

        if (!pthis->startedPlaying) {
            pthis->bowlPit = (EnBomBowlPit*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx,
                                                              ACTOR_EN_BOM_BOWL_PIT, 0.0f, 90.0f, -860.0f, 0, 0, 0, 0);
            if (pthis->bowlPit != NULL) {
                pthis->bowlPit->prizeIndex = pthis->prizeIndex;
            }
        } else {
            pthis->bowlPit->prizeIndex = pthis->prizeIndex;
        }

        pthis->bowlPit->start = 1;
        pthis->minigamePlayStatus = 2;
        pthis->actor.textId = 0x405A;
        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
        pthis->dialogState = TEXT_STATE_EVENT;

        // Cycle through prizes in order
        pthis->prizeSelect++;
        if (pthis->prizeSelect >= 5) {
            pthis->prizeSelect = 0;
        }
        pthis->actionFunc = EnBomBowlMan_BeginPlayGame;
    }
}

void EnBomBowlMan_BeginPlayGame(EnBomBowlMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if ((Message_GetState(&globalCtx->msgCtx) == pthis->dialogState) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        func_8005B1A4(GET_ACTIVE_CAM(globalCtx));
        pthis->startedPlaying = true;

        if (BREG(2)) {
            BREG(2) = 0;
        }

        // "Wow"
        osSyncPrintf(VT_FGCOL(YELLOW) "☆ わー ☆ %d\n" VT_RST, globalCtx->bombchuBowlingStatus);
        func_8002DF54(globalCtx, NULL, 7);
        pthis->actionFunc = EnBomBowMan_SetupRunGame;
    }
}

void EnBomBowlMan_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnBomBowlMan* pthis = (EnBomBowlMan*)thisx;

    pthis->timer++;
    pthis->actor.focus.pos.y = 60.0f;
    Actor_SetFocus(&pthis->actor, 60.0f);

    switch (pthis->eyeMode) {
        case CHU_GIRL_EYES_ASLEEP:
            pthis->eyeTextureIndex = 2;
            break;
        case CHU_GIRL_EYES_OPEN_SLOWLY:
            if (pthis->eyeTextureIndex > 0) {
                pthis->eyeTextureIndex--;
            } else {
                pthis->blinkTimer = 30;
                pthis->eyeMode = CHU_GIRL_EYES_BLINK_RAPIDLY;
            }
            break;
        case CHU_GIRL_EYES_BLINK_RAPIDLY:
            if ((pthis->blinkTimer == 0) && (pthis->eyeTextureIndex > 0)) {
                pthis->eyeTextureIndex--;
            }
            break;
        default:
            if (pthis->blinkTimer == 0) {
                pthis->eyeTextureIndex++;
                if (pthis->eyeTextureIndex >= 3) {
                    pthis->eyeTextureIndex = 0;
                    pthis->blinkTimer = (s16)Rand_ZeroFloat(60.0f) + 20;
                }
            }

            func_80038290(globalCtx, &pthis->actor, &pthis->unk_218, &pthis->unk_224, pthis->actor.focus.pos);
            break;
    }

    DECR(pthis->prizeRevealTimer);
    DECR(pthis->blinkTimer);

    pthis->actionFunc(pthis, globalCtx);
}

s32 EnBomBowlMan_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                  void* thisx) {
    EnBomBowlMan* pthis = (EnBomBowlMan*)thisx;

    if (limbIndex == 4) { // head
        rot->x += pthis->unk_218.y;
        rot->z += pthis->unk_218.z;
    }

    return false;
}

void EnBomBowlMan_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnBomBowlMan* pthis = (EnBomBowlMan*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_bom_bowl_man.c", 907);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures_60[pthis->eyeTextureIndex]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnBomBowlMan_OverrideLimbDraw, NULL, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_bom_bowl_man.c", 923);
}

void EnBomBowlMan_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Bom_Bowl_Man_InitVars = {
        ACTOR_EN_BOM_BOWL_MAN,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_BG,
        sizeof(EnBomBowlMan),
        (ActorFunc)EnBomBowlMan_Init,
        (ActorFunc)EnBomBowlMan_Destroy,
        (ActorFunc)EnBomBowlMan_Update,
        (ActorFunc)EnBomBowlMan_Draw,
        (ActorFunc)EnBomBowlMan_Reset,
    };

}
