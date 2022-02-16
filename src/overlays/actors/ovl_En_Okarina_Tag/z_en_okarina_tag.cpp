#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_OKARINA_TAG_Z_EN_OKARINA_TAG_C
#include "actor_common.h"
/*
 * File: z_en_okarina_tag.c
 * Overlay: ovl_En_Okarina_Tag
 * Description: Music Staff (Ocarina) spot
 */

#include "z_en_okarina_tag.h"
#include "scenes/misc/hakaana_ouke/hakaana_ouke_scene.h"
#include "scenes/overworld/spot02/spot02_scene.h"
#include "vt.h"
#include "def/code_800EC960.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_25)

void EnOkarinaTag_Init(Actor* thisx, GlobalContext* globalCtx);
void EnOkarinaTag_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnOkarinaTag_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnOkarinaTag_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80ABEF2C(EnOkarinaTag* pthis, GlobalContext* globalCtx);
void func_80ABF708(EnOkarinaTag* pthis, GlobalContext* globalCtx);
void func_80ABF28C(EnOkarinaTag* pthis, GlobalContext* globalCtx);
void func_80ABF0CC(EnOkarinaTag* pthis, GlobalContext* globalCtx);
void func_80ABF4C8(EnOkarinaTag* pthis, GlobalContext* globalCtx);
void func_80ABF7CC(EnOkarinaTag* pthis, GlobalContext* globalCtx);

ActorInit En_Okarina_Tag_InitVars = {
    ACTOR_EN_OKARINA_TAG,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnOkarinaTag),
    (ActorFunc)EnOkarinaTag_Init,
    (ActorFunc)EnOkarinaTag_Destroy,
    (ActorFunc)EnOkarinaTag_Update,
    NULL,
    (ActorFunc)EnOkarinaTag_Reset,
};

extern CutsceneData D_80ABF9D0[];
extern CutsceneData D_80ABFB40[];

void EnOkarinaTag_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnOkarinaTag_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnOkarinaTag* pthis = (EnOkarinaTag*)thisx;

    osSyncPrintf("\n\n");
    // "Ocarina tag outbreak"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ オカリナタグ発生 ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.params);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->type = (pthis->actor.params >> 0xA) & 0x3F;
    pthis->ocarinaSong = (pthis->actor.params >> 6) & 0xF;
    pthis->switchFlag = pthis->actor.params & 0x3F;
    if (pthis->switchFlag == 0x3F) {
        pthis->switchFlag = -1;
    }
    if (pthis->ocarinaSong == 0xF) {
        pthis->ocarinaSong = 0;
        pthis->unk_158 = 1;
    }
    pthis->actor.targetMode = 1;
    if (pthis->actor.world.rot.z > 0) {
        pthis->interactRange = pthis->actor.world.rot.z * 40.0f;
    }

    // "Save information"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ セーブ情報\t ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
    // "Type index"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 種類インデックス ☆☆☆☆☆ %d\n" VT_RST, pthis->type);
    // "Correct answer information"
    osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 正解情報\t ☆☆☆☆☆ %d\n" VT_RST, pthis->ocarinaSong);
    // "Range information"
    osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 範囲情報\t ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.world.rot.z);
    // "Processing range information"
    osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 処理範囲情報\t ☆☆☆☆☆ %f\n" VT_RST, pthis->interactRange);
    // "Hit?"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 当り？\t\t ☆☆☆☆☆ %d\n" VT_RST, pthis->unk_158);
    osSyncPrintf("\n\n");

    if ((pthis->switchFlag >= 0) && (Flags_GetSwitch(globalCtx, pthis->switchFlag))) {
        Actor_Kill(&pthis->actor);
    } else {
        switch (pthis->type) {
            case 7:
                pthis->actionFunc = func_80ABEF2C;
                break;
            case 2:
                if (LINK_IS_ADULT) {
                    Actor_Kill(&pthis->actor);
                    break;
                }
            case 1:
            case 4:
            case 6:
                pthis->actionFunc = func_80ABF28C;
                break;
            case 5:
                pthis->actor.textId = 0x5021;
                pthis->actionFunc = func_80ABF708;
                break;
            default:
                Actor_Kill(&pthis->actor);
                break;
        }
    }
}

void func_80ABEF2C(EnOkarinaTag* pthis, GlobalContext* globalCtx) {
    Player* player;
    u16 ocarinaSong;

    player = GET_PLAYER(globalCtx);
    pthis->unk_15A++;
    if ((pthis->switchFlag >= 0) && (Flags_GetSwitch(globalCtx, pthis->switchFlag))) {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    } else {
        if ((pthis->ocarinaSong != 6) || (gSaveContext.scarecrowSpawnSongSet)) {
            if (player->stateFlags2 & 0x1000000) {
                // "North! ! ! ! !"
                osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ 北！！！！！ ☆☆☆☆☆ %f\n" VT_RST, pthis->actor.xzDistToPlayer);
            }
            if ((pthis->actor.xzDistToPlayer < (90.0f + pthis->interactRange)) &&
                (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < 80.0f)) {
                if (player->stateFlags2 & 0x2000000) {
                    ocarinaSong = pthis->ocarinaSong;
                    if (ocarinaSong == 6) {
                        ocarinaSong = 0xA;
                    }
                    player->stateFlags2 |= 0x800000;
                    func_8010BD58(globalCtx, ocarinaSong + OCARINA_ACTION_CHECK_SARIA);
                    pthis->actionFunc = func_80ABF0CC;
                } else if ((pthis->actor.xzDistToPlayer < (50.0f + pthis->interactRange) &&
                            ((fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < 40.0f)))) {
                    pthis->unk_15A = 0;
                    player->unk_6A8 = &pthis->actor;
                }
            }
        }
    }
}

void func_80ABF0CC(EnOkarinaTag* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04) {
        pthis->actionFunc = func_80ABEF2C;
    } else {
        if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03) {
            if (pthis->switchFlag >= 0) {
                Flags_SetSwitch(globalCtx, pthis->switchFlag);
            }
            if (globalCtx->sceneNum == SCENE_MIZUSIN) {
                globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
            }
            if ((globalCtx->sceneNum != SCENE_DAIYOUSEI_IZUMI) && (globalCtx->sceneNum != SCENE_YOUSEI_IZUMI_YOKO)) {
                globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
            }
            func_80078884(NA_SE_SY_CORRECT_CHIME);
            pthis->actionFunc = func_80ABEF2C;
            return;
        }
        if (pthis->unk_158 != 0) {
            if ((globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_05) ||
                (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_06) ||
                (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_07) ||
                (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_08) ||
                (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_09) ||
                (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_0A) ||
                (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_0D)) {
                if (pthis->switchFlag >= 0) {
                    Flags_SetSwitch(globalCtx, pthis->switchFlag);
                }
                globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
                func_80078884(NA_SE_SY_CORRECT_CHIME);
                pthis->actionFunc = func_80ABEF2C;
                return;
            }
        }
        if ((globalCtx->msgCtx.ocarinaMode >= OCARINA_MODE_05) && (globalCtx->msgCtx.ocarinaMode < OCARINA_MODE_0E)) {
            globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
            pthis->actionFunc = func_80ABEF2C;
        } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_01) {
            player->stateFlags2 |= 0x800000;
        }
    }
}

void func_80ABF28C(EnOkarinaTag* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_15A++;
    if ((pthis->ocarinaSong != 6) || (gSaveContext.scarecrowSpawnSongSet)) {
        if ((pthis->switchFlag >= 0) && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
            pthis->actor.flags &= ~ACTOR_FLAG_0;
        } else if (((pthis->type != 4) || !(gSaveContext.eventChkInf[4] & 0x800)) &&
                   ((pthis->type != 6) || !(gSaveContext.eventChkInf[1] & 0x2000)) &&
                   (pthis->actor.xzDistToPlayer < (90.0f + pthis->interactRange)) &&
                   (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < 80.0f)) {
            if (player->stateFlags2 & 0x1000000) {
                switch (pthis->type) {
                    case 1:
                        func_8010BD58(globalCtx, OCARINA_ACTION_CHECK_LULLABY);
                        break;
                    case 2:
                        func_8010BD58(globalCtx, OCARINA_ACTION_CHECK_STORMS);
                        break;
                    case 4:
                        func_8010BD58(globalCtx, OCARINA_ACTION_CHECK_TIME);
                        break;
                    case 6:
                        func_8010BD58(globalCtx, OCARINA_ACTION_CHECK_LULLABY);
                        break;
                    default:
                        // "Ocarina Invisible-kun demo start check error source"
                        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ オカリナ透明君デモ開始チェックエラー原 ☆☆☆☆☆ %d\n" VT_RST,
                                     pthis->type);
                        Actor_Kill(&pthis->actor);
                        break;
                }
                player->stateFlags2 |= 0x800000;
                pthis->actionFunc = func_80ABF4C8;
            } else if ((pthis->actor.xzDistToPlayer < (50.0f + pthis->interactRange)) &&
                       (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < 40.0f)) {
                pthis->unk_15A = 0;
                player->stateFlags2 |= 0x800000;
            }
        }
    }
}

void func_80ABF4C8(EnOkarinaTag* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04) {
        pthis->actionFunc = func_80ABF28C;
    } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03) {
        func_80078884(NA_SE_SY_CORRECT_CHIME);
        if (pthis->switchFlag >= 0) {
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
        }
        switch (pthis->type) {
            case 1:
                Flags_SetSwitch(globalCtx, pthis->switchFlag);
                gSaveContext.eventChkInf[3] |= 0x200;
                break;
            case 2:
                globalCtx->csCtx.segment = D_80ABF9D0;
                gSaveContext.cutsceneTrigger = 1;
                func_800F574C(1.18921f, 0x5A);
                break;
            case 4:
                globalCtx->csCtx.segment = D_80ABFB40;
                gSaveContext.cutsceneTrigger = 1;
                break;
            case 6:
                globalCtx->csCtx.segment = LINK_IS_ADULT ? SEGMENTED_TO_VIRTUAL(&spot02_scene_Cs_003C80)
                                                         : SEGMENTED_TO_VIRTUAL(&spot02_scene_Cs_005020);
                gSaveContext.cutsceneTrigger = 1;
                gSaveContext.eventChkInf[1] |= 0x2000;
                func_80078884(NA_SE_SY_CORRECT_CHIME);
                break;
            default:
                break;
        }
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
        pthis->actionFunc = func_80ABF28C;
    } else {
        if (globalCtx->msgCtx.ocarinaMode >= OCARINA_MODE_05) {
            if (globalCtx->msgCtx.ocarinaMode < OCARINA_MODE_0E) {
                globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
                pthis->actionFunc = func_80ABF28C;
                return;
            }
        }
        if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_01) {
            player->stateFlags2 |= 0x800000;
        }
    }
}

void func_80ABF708(EnOkarinaTag* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;
    s16 yawDiffNew;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_80ABF7CC;
    } else {
        yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y;
        pthis->unk_15A++;
        if (!(pthis->actor.xzDistToPlayer > 120.0f)) {
            if (CHECK_QUEST_ITEM(QUEST_SONG_SUN)) {
                pthis->actor.textId = 0x5021;
            }
            yawDiffNew = ABS(yawDiff);
            if (yawDiffNew < 0x4300) {
                pthis->unk_15A = 0;
                func_8002F2CC(&pthis->actor, globalCtx, 70.0f);
            }
        }
    }
}

void func_80ABF7CC(EnOkarinaTag* pthis, GlobalContext* globalCtx) {
    // "Open sesame sesame!"
    osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 開けゴマゴマゴマ！ ☆☆☆☆☆ %d\n" VT_RST, Message_GetState(&globalCtx->msgCtx));

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        if (!CHECK_QUEST_ITEM(QUEST_SONG_SUN)) {
            globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(&gSunSongGraveSunSongTeachCs);
            gSaveContext.cutsceneTrigger = 1;
        }
        pthis->actionFunc = func_80ABF708;
    }
}

void EnOkarinaTag_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnOkarinaTag* pthis = (EnOkarinaTag*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void EnOkarinaTag_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Okarina_Tag_InitVars = {
        ACTOR_EN_OKARINA_TAG,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnOkarinaTag),
        (ActorFunc)EnOkarinaTag_Init,
        (ActorFunc)EnOkarinaTag_Destroy,
        (ActorFunc)EnOkarinaTag_Update,
        NULL,
        (ActorFunc)EnOkarinaTag_Reset,
    };

}
