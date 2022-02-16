#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SYATEKI_MAN_Z_EN_SYATEKI_MAN_C
#include "actor_common.h"
#include "z_en_syateki_man.h"
#include "vt.h"
#include "overlays/actors/ovl_En_Syateki_Itm/z_en_syateki_itm.h"
#include "objects/object_ossan/object_ossan.h"
#include "def/code_800F9280.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_parameter.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_27)


void EnSyatekiMan_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSyatekiMan_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnSyatekiMan_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSyatekiMan_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSyatekiMan_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnSyatekiMan_Start(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_SetupIdle(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_Idle(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_Talk(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_StopTalk(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_StartGame(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_WaitForGame(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_EndGame(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_GivePrize(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_FinishPrize(EnSyatekiMan* pthis, GlobalContext* globalCtx);
void EnSyatekiMan_RestartGame(EnSyatekiMan* pthis, GlobalContext* globalCtx);

void EnSyatekiMan_BlinkWait(EnSyatekiMan* pthis);
void EnSyatekiMan_Blink(EnSyatekiMan* pthis);

void EnSyatekiMan_SetBgm(void);

ActorInit En_Syateki_Man_InitVars = {
    ACTOR_EN_SYATEKI_MAN,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_OSSAN,
    sizeof(EnSyatekiMan),
    (ActorFunc)EnSyatekiMan_Init,
    (ActorFunc)EnSyatekiMan_Destroy,
    (ActorFunc)EnSyatekiMan_Update,
    (ActorFunc)EnSyatekiMan_Draw,
    (ActorFunc)EnSyatekiMan_Reset,
};

static u16 sBgmList[] = {
    NA_BGM_GENERAL_SFX,
    NA_BGM_NATURE_AMBIENCE,
    NA_BGM_FIELD_LOGIC,
    NA_BGM_DUNGEON,
    NA_BGM_KAKARIKO_ADULT,
    NA_BGM_FIELD_LOGIC,
    NA_BGM_KAKARIKO_ADULT,
    NA_BGM_ENEMY,
    NA_BGM_ENEMY,
    NA_BGM_ENEMY | 0x800,
    NA_BGM_BOSS,
    NA_BGM_INSIDE_DEKU_TREE,
    NA_BGM_MARKET,
    NA_BGM_TITLE,
    NA_BGM_LINK_HOUSE,
    NA_BGM_GAME_OVER,
    NA_BGM_BOSS_CLEAR,
    NA_BGM_ITEM_GET | 0x900,
    NA_BGM_OPENING_GANON,
    NA_BGM_HEART_GET | 0x900,
    NA_BGM_OCA_LIGHT,
    NA_BGM_JABU_JABU,
    NA_BGM_KAKARIKO_KID,
    NA_BGM_GREAT_FAIRY,
    NA_BGM_ZELDA_THEME,
    NA_BGM_FIRE_TEMPLE,
    NA_BGM_OPEN_TRE_BOX | 0x900,
    NA_BGM_FOREST_TEMPLE,
    NA_BGM_COURTYARD,
    NA_BGM_GANON_TOWER,
    NA_BGM_LONLON,
    NA_BGM_GORON_CITY,
    NA_BGM_SPIRITUAL_STONE,
    NA_BGM_OCA_BOLERO,
    NA_BGM_OCA_MINUET,
    NA_BGM_OCA_SERENADE,
    NA_BGM_OCA_REQUIEM,
    NA_BGM_OCA_NOCTURNE,
    NA_BGM_MINI_BOSS,
    NA_BGM_SMALL_ITEM_GET,
    NA_BGM_TEMPLE_OF_TIME,
    NA_BGM_EVENT_CLEAR,
    NA_BGM_KOKIRI,
    NA_BGM_OCA_FAIRY_GET,
    NA_BGM_SARIA_THEME,
    NA_BGM_SPIRIT_TEMPLE,
    NA_BGM_HORSE,
    NA_BGM_HORSE_GOAL,
    NA_BGM_INGO,
    NA_BGM_MEDALLION_GET,
    NA_BGM_OCA_SARIA,
    NA_BGM_OCA_EPONA,
    NA_BGM_OCA_ZELDA,
    NA_BGM_OCA_SUNS,
    NA_BGM_OCA_TIME,
    NA_BGM_OCA_STORM,
    NA_BGM_NAVI_OPENING,
    NA_BGM_DEKU_TREE_CS,
    NA_BGM_WINDMILL,
    NA_BGM_HYRULE_CS,
    NA_BGM_MINI_GAME,
    NA_BGM_SHEIK,
    NA_BGM_ZORA_DOMAIN,
    NA_BGM_APPEAR,
    NA_BGM_ADULT_LINK,
    NA_BGM_MASTER_SWORD,
    NA_BGM_INTRO_GANON,
    NA_BGM_SHOP,
    NA_BGM_CHAMBER_OF_SAGES,
    NA_BGM_FILE_SELECT,
    NA_BGM_ICE_CAVERN,
    NA_BGM_DOOR_OF_TIME,
    NA_BGM_OWL,
    NA_BGM_SHADOW_TEMPLE,
    NA_BGM_WATER_TEMPLE,
    NA_BGM_BRIDGE_TO_GANONS,
    NA_BGM_VARIOUS_SFX,
    NA_BGM_OCARINA_OF_TIME,
    NA_BGM_OCARINA_OF_TIME,
    NA_BGM_GERUDO_VALLEY,
    NA_BGM_POTION_SHOP,
    NA_BGM_KOTAKE_KOUME,
    NA_BGM_VARIOUS_SFX,
    NA_BGM_ESCAPE,
    NA_BGM_UNDERGROUND,
    NA_BGM_GANONDORF_BOSS,
    NA_BGM_GANON_BOSS,
    NA_BGM_END_DEMO,
};

static s16 sTextIds[] = { 0x2B, 0x2E, 0xC8, 0x2D };

static s16 sTextBoxCount[] = { TEXT_STATE_CHOICE, TEXT_STATE_EVENT, TEXT_STATE_EVENT, TEXT_STATE_EVENT };

void EnSyatekiMan_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnSyatekiMan* pthis = (EnSyatekiMan*)thisx;

    osSyncPrintf("\n\n");
    // "Old man appeared!! Muhohohohohohohon"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 親父登場！！むほほほほほほほーん ☆☆☆☆☆ \n" VT_RST);
    pthis->actor.targetMode = 1;
    Actor_SetScale(&pthis->actor, 0.01f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gObjectOssanSkel, &gObjectOssanAnim_000338, pthis->jointTable,
                       pthis->morphTable, 9);
    if (!LINK_IS_ADULT) {
        pthis->headRot.z = 20;
    }
    pthis->blinkTimer = 20;
    pthis->eyeState = 0;
    pthis->blinkFunc = EnSyatekiMan_BlinkWait;
    pthis->actor.colChkInfo.cylRadius = 100;
    pthis->actionFunc = EnSyatekiMan_Start;
}

void EnSyatekiMan_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnSyatekiMan_Start(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    f32 lastFrame = Animation_GetLastFrame(&gObjectOssanAnim_000338);

    Animation_Change(&pthis->skelAnime, &gObjectOssanAnim_000338, 1.0f, 0.0f, (s16)lastFrame, ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = EnSyatekiMan_SetupIdle;
}

void EnSyatekiMan_SetupIdle(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    if (pthis->gameResult == SYATEKI_RESULT_REFUSE) {
        pthis->textIdx = SYATEKI_TEXT_REFUSE;
    }

    pthis->actor.textId = sTextIds[pthis->textIdx];
    pthis->numTextBox = sTextBoxCount[pthis->textIdx];
    pthis->actionFunc = EnSyatekiMan_Idle;
}

void EnSyatekiMan_Idle(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnSyatekiMan_Talk;
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
    }
}

void EnSyatekiMan_Talk(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    s16 nextState = 0;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->cameraHold) {
        globalCtx->shootingGalleryStatus = -2;
    }
    if ((pthis->numTextBox == Message_GetState(&globalCtx->msgCtx)) && Message_ShouldAdvance(globalCtx)) {
        if (pthis->textIdx == SYATEKI_TEXT_CHOICE) {
            switch (globalCtx->msgCtx.choiceIndex) {
                case 0:
                    if (gSaveContext.rupees >= 20) {
                        Rupees_ChangeBy(-20);
                        pthis->textIdx = SYATEKI_TEXT_START_GAME;
                        nextState = 1;
                    } else {
                        pthis->textIdx = SYATEKI_TEXT_NO_RUPEES;
                        nextState = 2;
                    }
                    pthis->actor.textId = sTextIds[pthis->textIdx];
                    pthis->numTextBox = sTextBoxCount[pthis->textIdx];
                    break;
                case 1:
                    pthis->actor.textId = sTextIds[SYATEKI_TEXT_REFUSE];
                    pthis->numTextBox = sTextBoxCount[SYATEKI_TEXT_REFUSE];
                    nextState = 2;
                    break;
            }
            Message_ContinueTextbox(globalCtx, pthis->actor.textId);
        } else {
            Message_CloseTextbox(globalCtx);
        }
        switch (nextState) {
            case 0:
                pthis->actionFunc = EnSyatekiMan_SetupIdle;
                break;
            case 1:
                pthis->actionFunc = EnSyatekiMan_StartGame;
                break;
            case 2:
                pthis->actionFunc = EnSyatekiMan_StopTalk;
                break;
        }
    }
}

void EnSyatekiMan_StopTalk(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->cameraHold) {
        globalCtx->shootingGalleryStatus = -2;
    }
    if ((pthis->numTextBox == Message_GetState(&globalCtx->msgCtx)) && Message_ShouldAdvance(globalCtx)) {
        if (pthis->cameraHold) {
            OnePointCutscene_EndCutscene(globalCtx, pthis->csCam);
            pthis->csCam = SUBCAM_NONE;
            pthis->cameraHold = false;
        }
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = EnSyatekiMan_SetupIdle;
    }
}

void EnSyatekiMan_StartGame(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    EnSyatekiItm* gallery;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->cameraHold) {
        globalCtx->shootingGalleryStatus = -2;
    }
    if ((pthis->numTextBox == Message_GetState(&globalCtx->msgCtx)) && Message_ShouldAdvance(globalCtx)) {
        if (pthis->cameraHold) {
            OnePointCutscene_EndCutscene(globalCtx, pthis->csCam);
            pthis->csCam = SUBCAM_NONE;
            pthis->cameraHold = false;
        }
        Message_CloseTextbox(globalCtx);
        gallery = ((EnSyatekiItm*)pthis->actor.parent);
        if (gallery->actor.update != NULL) {
            gallery->signal = ENSYATEKI_START;
            pthis->actionFunc = EnSyatekiMan_WaitForGame;
        }
    }
}

void EnSyatekiMan_WaitForGame(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    EnSyatekiItm* gallery;

    SkelAnime_Update(&pthis->skelAnime);
    if (1) {}
    gallery = ((EnSyatekiItm*)pthis->actor.parent);
    if ((gallery->actor.update != NULL) && (gallery->signal == ENSYATEKI_END)) {
        pthis->csCam = OnePointCutscene_Init(globalCtx, 8002, -99, &pthis->actor, MAIN_CAM);
        switch (gallery->hitCount) {
            case 10:
                pthis->gameResult = SYATEKI_RESULT_WINNER;
                pthis->actor.textId = 0x71AF;
                break;
            case 8:
            case 9:
                pthis->gameResult = SYATEKI_RESULT_ALMOST;
                pthis->actor.textId = 0x71AE;
                break;
            default:
                pthis->gameResult = SYATEKI_RESULT_FAILURE;
                pthis->actor.textId = 0x71AD;
                if (globalCtx->shootingGalleryStatus == 15 + 1) {
                    pthis->gameResult = SYATEKI_RESULT_REFUSE;
                    pthis->actor.textId = 0x2D;
                }
                break;
        }
        globalCtx->shootingGalleryStatus = -2;
        Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
        pthis->actionFunc = EnSyatekiMan_EndGame;
    }
}

void EnSyatekiMan_EndGame(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    EnSyatekiItm* gallery;

    SkelAnime_Update(&pthis->skelAnime);
    if ((pthis->numTextBox == Message_GetState(&globalCtx->msgCtx)) && Message_ShouldAdvance(globalCtx)) {
        if (pthis->gameResult != SYATEKI_RESULT_FAILURE) {
            OnePointCutscene_EndCutscene(globalCtx, pthis->csCam);
            pthis->csCam = SUBCAM_NONE;
        }
        Message_CloseTextbox(globalCtx);
        gallery = ((EnSyatekiItm*)pthis->actor.parent);
        if (gallery->actor.update != NULL) {
            gallery->signal = ENSYATEKI_RESULTS;
            pthis->textIdx = 0;
            switch (pthis->gameResult) {
                case SYATEKI_RESULT_WINNER:
                    pthis->tempGallery = pthis->actor.parent;
                    pthis->actor.parent = NULL;
                    if (!LINK_IS_ADULT) {
                        if (!(gSaveContext.itemGetInf[0] & 0x2000)) {
                            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ Equip_Pachinko ☆☆☆☆☆ %d\n" VT_RST,
                                         CUR_UPG_VALUE(UPG_BULLET_BAG));
                            if (CUR_UPG_VALUE(UPG_BULLET_BAG) == 1) {
                                pthis->getItemId = GI_BULLET_BAG_40;
                            } else {
                                pthis->getItemId = GI_BULLET_BAG_50;
                            }
                        } else {
                            pthis->getItemId = GI_RUPEE_PURPLE;
                        }
                    } else {
                        if (!(gSaveContext.itemGetInf[0] & 0x4000)) {
                            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ Equip_Bow ☆☆☆☆☆ %d\n" VT_RST,
                                         CUR_UPG_VALUE(UPG_QUIVER));
                            switch (CUR_UPG_VALUE(UPG_QUIVER)) {
                                case 0:
                                    pthis->getItemId = GI_RUPEE_PURPLE;
                                    break;
                                case 1:
                                    pthis->getItemId = GI_QUIVER_40;
                                    break;
                                case 2:
                                    pthis->getItemId = GI_QUIVER_50;
                                    break;
                            }
                        } else {
                            pthis->getItemId = GI_RUPEE_PURPLE;
                        }
                    }
                    func_8002F434(&pthis->actor, globalCtx, pthis->getItemId, 2000.0f, 1000.0f);
                    pthis->actionFunc = EnSyatekiMan_GivePrize;
                    break;
                case SYATEKI_RESULT_ALMOST:
                    pthis->timer = 20;
                    func_8008EF44(globalCtx, 15);
                    pthis->actionFunc = EnSyatekiMan_RestartGame;
                    break;
                default:
                    if (pthis->gameResult == SYATEKI_RESULT_REFUSE) {
                        pthis->actionFunc = EnSyatekiMan_SetupIdle;
                    } else {
                        pthis->cameraHold = true;
                        pthis->actor.textId = sTextIds[pthis->textIdx];
                        pthis->numTextBox = sTextBoxCount[pthis->textIdx];
                        Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
                        pthis->actionFunc = EnSyatekiMan_Talk;
                    }
                    break;
            }
        }
    }
}

void EnSyatekiMan_GivePrize(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnSyatekiMan_FinishPrize;
    } else {
        func_8002F434(&pthis->actor, globalCtx, pthis->getItemId, 2000.0f, 1000.0f);
    }
}

void EnSyatekiMan_FinishPrize(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        // "Successful completion"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 正常終了 ☆☆☆☆☆ \n" VT_RST);
        if (!LINK_IS_ADULT) {
            gSaveContext.itemGetInf[0] |= 0x2000;
        } else if ((pthis->getItemId == GI_QUIVER_40) || (pthis->getItemId == GI_QUIVER_50)) {
            gSaveContext.itemGetInf[0] |= 0x4000;
        }
        pthis->gameResult = SYATEKI_RESULT_NONE;
        pthis->actor.parent = pthis->tempGallery;
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actionFunc = EnSyatekiMan_SetupIdle;
    }
}

void EnSyatekiMan_RestartGame(EnSyatekiMan* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer == 0) {
        EnSyatekiItm* gallery = ((EnSyatekiItm*)pthis->actor.parent);

        if (gallery->actor.update != NULL) {
            gallery->signal = ENSYATEKI_START;
            pthis->gameResult = SYATEKI_RESULT_NONE;
            pthis->actionFunc = EnSyatekiMan_WaitForGame;
            // "Let's try again! Baby!"
            osSyncPrintf(VT_FGCOL(BLUE) "再挑戦だぜ！ベイビー！" VT_RST "\n", pthis);
        }
    }
}

void EnSyatekiMan_BlinkWait(EnSyatekiMan* pthis) {
    s16 decrBlinkTimer = pthis->blinkTimer - 1;

    if (decrBlinkTimer != 0) {
        pthis->blinkTimer = decrBlinkTimer;
    } else {
        pthis->blinkFunc = EnSyatekiMan_Blink;
    }
}

void EnSyatekiMan_Blink(EnSyatekiMan* pthis) {
    s16 decrBlinkTimer = pthis->blinkTimer - 1;

    if (decrBlinkTimer != 0) {
        pthis->blinkTimer = decrBlinkTimer;
    } else {
        s16 nextEyeState = pthis->eyeState + 1;

        if (nextEyeState >= 3) {
            pthis->eyeState = 0;
            pthis->blinkTimer = 20 + (s32)(Rand_ZeroOne() * 60.0f);
            pthis->blinkFunc = EnSyatekiMan_BlinkWait;
        } else {
            pthis->eyeState = nextEyeState;
            pthis->blinkTimer = 1;
        }
    }
}

void EnSyatekiMan_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnSyatekiMan* pthis = (EnSyatekiMan*)thisx;

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    pthis->actionFunc(pthis, globalCtx);
    EnSyatekiMan_SetBgm();
    pthis->blinkFunc(pthis);
    pthis->actor.focus.pos.y = 70.0f;
    Actor_SetFocus(&pthis->actor, 70.0f);
    func_80038290(globalCtx, &pthis->actor, &pthis->headRot, &pthis->bodyRot, pthis->actor.focus.pos);
}

s32 EnSyatekiMan_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                  void* thisx) {
    EnSyatekiMan* pthis = (EnSyatekiMan*)thisx;
    s32 turnDirection;

    if (limbIndex == 1) {
        rot->x += pthis->bodyRot.y;
    }
    if (limbIndex == 8) {
        *dList = gObjectOssanEnSyatekiManDL_007E28;
        turnDirection = 1;
        if (pthis->gameResult == SYATEKI_RESULT_REFUSE) {
            turnDirection = -1;
        }
        rot->x += pthis->headRot.y * turnDirection;
        rot->z += pthis->headRot.z;
    }
    return 0;
}

void EnSyatekiMan_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnSyatekiMan* pthis = (EnSyatekiMan*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnSyatekiMan_OverrideLimbDraw, NULL, pthis);
}

void EnSyatekiMan_SetBgm(void) {
    if (BREG(80)) {
        BREG(80) = false;
        Audio_QueueSeqCmd(sBgmList[BREG(81)]);
    }
}

void EnSyatekiMan_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Syateki_Man_InitVars = {
        ACTOR_EN_SYATEKI_MAN,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_OSSAN,
        sizeof(EnSyatekiMan),
        (ActorFunc)EnSyatekiMan_Init,
        (ActorFunc)EnSyatekiMan_Destroy,
        (ActorFunc)EnSyatekiMan_Update,
        (ActorFunc)EnSyatekiMan_Draw,
        (ActorFunc)EnSyatekiMan_Reset,
    };

}
