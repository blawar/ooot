#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_OWL_Z_EN_OWL_C
#include "actor_common.h"
/*
 * File: z_en_owl.c
 * Overlay: ovl_En_Owl
 * Description: Owl
 */

#include "z_en_owl.h"
#include "objects/object_owl/object_owl.h"
#include "scenes/overworld/spot06/spot06_scene.h"
#include "scenes/overworld/spot16/spot16_scene.h"
#include "vt.h"
#include "z_kankyo.h"
#include "def/code_800EC960.h"
#include "def/code_800F9280.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include <port/options.h>

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnOwl_Init(Actor* thisx, GlobalContext* globalCtx);
void EnOwl_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnOwl_Update(Actor* thisx, GlobalContext* globalCtx);
void EnOwl_Draw(Actor* thisx, GlobalContext* globalCtx);
void EnOwl_ChangeMode(EnOwl* pthis, EnOwlActionFunc, OwlFunc, SkelAnime*, AnimationHeader*, f32);
void EnOwl_WaitDefault(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACC540(EnOwl* pthis);
void EnOwl_WaitOutsideKokiri(EnOwl* pthis, GlobalContext* globalCtx);
void EnOwl_WaitHyruleCastle(EnOwl* pthis, GlobalContext* globalCtx);
void EnOwl_WaitKakariko(EnOwl* pthis, GlobalContext* globalCtx);
void EnOwl_WaitGerudo(EnOwl* pthis, GlobalContext* globalCtx);
void EnOwl_WaitLakeHylia(EnOwl* pthis, GlobalContext* globalCtx);
void EnOwl_WaitZoraRiver(EnOwl* pthis, GlobalContext* globalCtx);
void EnOwl_WaitHyliaShortcut(EnOwl* pthis, GlobalContext* globalCtx);
void EnOwl_WaitDeathMountainShortcut(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACB3E0(EnOwl* pthis, GlobalContext* globalCtx);
void EnOwl_WaitLWPreSaria(EnOwl* pthis, GlobalContext* globalCtx);
void EnOwl_WaitLWPostSaria(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACD4D4(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACD130(EnOwl* pthis, GlobalContext* globalCtx, s32 arg2);
void func_80ACBAB8(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACD2CC(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACAA54(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACAC6C(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACADF0(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACAF74(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACC30C(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACB4FC(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACB680(EnOwl* pthis, GlobalContext* globalCtx);
void func_80ACC460(EnOwl* pthis);
void func_80ACBEA0(EnOwl*, GlobalContext*);

typedef enum {
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
} EnOwlType;

typedef enum {
    /* 0x00 */ OWL_REPEAT,
    /* 0x01 */ OWL_OK
} EnOwlMessageChoice;

ActorInit En_Owl_InitVars = {
    ACTOR_EN_OWL,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_OWL,
    sizeof(EnOwl),
    (ActorFunc)EnOwl_Init,
    (ActorFunc)EnOwl_Destroy,
    (ActorFunc)EnOwl_Update,
    (ActorFunc)EnOwl_Draw,
};

static ColliderCylinderInit sOwlCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_ENEMY,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 30, 40, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 25, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2400, ICHAIN_STOP),
};

void EnOwl_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnOwl* pthis = (EnOwl*)thisx;
    ColliderCylinder* collider;
    s32 owlType;
    s32 switchFlag;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0, ActorShadow_DrawCircle, 36.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gOwlFlyingSkel, &gOwlFlyAnim, pthis->jointTable, pthis->morphTable,
                       21);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime2, &gOwlPerchingSkel, &gOwlPerchAnim, pthis->jointTable2,
                       pthis->morphTable2, 16);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sOwlCylinderInit);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->actor.minVelocityY = -10.0f;
    pthis->actor.targetArrowOffset = 500.0f;
    EnOwl_ChangeMode(pthis, EnOwl_WaitDefault, func_80ACC540, &pthis->skelAnime2, &gOwlPerchAnim, 0.0f);
    pthis->actionFlags = pthis->unk_406 = pthis->unk_409 = 0;
    pthis->unk_405 = 4;
    pthis->unk_404 = pthis->unk_407 = 0;
    pthis->unk_408 = 4;
    owlType = (pthis->actor.params & 0xFC0) >> 6;
    switchFlag = (pthis->actor.params & 0x3F);
    if (pthis->actor.params == 0xFFF) {
        owlType = OWL_OUTSIDE_KOKIRI;
        switchFlag = 0x20;
    }
    // "conversation owl %4x no = %d, sv = %d"
    osSyncPrintf(VT_FGCOL(CYAN) " 会話フクロウ %4x no = %d, sv = %d\n" VT_RST, pthis->actor.params, owlType, switchFlag);

    if ((owlType != OWL_DEFAULT) && (switchFlag < 0x20) && Flags_GetSwitch(globalCtx, switchFlag)) {
        osSyncPrintf("savebitでフクロウ退避\n"); // "Save owl with savebit"
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->unk_3EE = 0;
    pthis->unk_400 = pthis->actor.world.rot.y;

    switch (owlType) {
        case OWL_DEFAULT:
            pthis->actionFunc = EnOwl_WaitDefault;
            pthis->actor.uncullZoneForward = 4000.0f;
            pthis->unk_40A = 0;
            break;
        case OWL_OUTSIDE_KOKIRI:
            pthis->actionFunc = EnOwl_WaitOutsideKokiri;
            break;
        case OWL_HYRULE_CASTLE:
            pthis->actionFlags |= 2;
            pthis->unk_3EE = 0x20;
            pthis->actionFunc = EnOwl_WaitHyruleCastle;
            break;
        case OWL_KAKARIKO:
            if (gSaveContext.eventChkInf[4] & 1) {
                // has zelda's letter
                osSyncPrintf("フクロウ退避\n"); // "Owl evacuation"
                Actor_Kill(&pthis->actor);
                return;
            }

            pthis->actionFunc = EnOwl_WaitKakariko;
            break;
        case OWL_HYLIA_GERUDO:
            if (gSaveContext.eventChkInf[4] & 8) {
                // has ocarina of time
                osSyncPrintf("フクロウ退避\n"); // "Owl evacuation"
                Actor_Kill(&pthis->actor);
                return;
            }
            pthis->actionFunc = EnOwl_WaitGerudo;
            break;
        case OWL_LAKE_HYLIA:
            pthis->actionFunc = EnOwl_WaitLakeHylia;
            break;
        case OWL_ZORA_RIVER:
            if ((gSaveContext.eventChkInf[3] & 0x200) || !(gSaveContext.eventChkInf[4] & 1)) {
                // opened zora's domain or has zelda's letter
                osSyncPrintf("フクロウ退避\n"); // "Owl evacuation"
                Actor_Kill(&pthis->actor);
                return;
            }

            pthis->actionFunc = EnOwl_WaitZoraRiver;
            break;
        case OWL_HYLIA_SHORTCUT:
            pthis->actionFunc = EnOwl_WaitHyliaShortcut;
            Flags_UnsetSwitch(globalCtx, 0x23);
            return;
        case OWL_DEATH_MOUNTAIN:
            pthis->actionFunc = EnOwl_WaitDeathMountainShortcut;
            break;
        case OWL_DEATH_MOUNTAIN2:
            pthis->actionFunc = EnOwl_WaitDeathMountainShortcut;
            break;
        case OWL_DESSERT_COLOSSUS:
            pthis->actionFunc = func_80ACB3E0;
            break;
        case OWL_LOST_WOODS_PRESARIA:
            if (!CHECK_QUEST_ITEM(QUEST_SONG_LULLABY)) {
                osSyncPrintf("フクロウ退避\n"); // "Owl evacuation"
                Actor_Kill(&pthis->actor);
                return;
            }
            pthis->actionFunc = EnOwl_WaitLWPreSaria;
            break;
        case OWL_LOST_WOODS_POSTSARIA:
            if (!CHECK_QUEST_ITEM(QUEST_SONG_SARIA)) {
                osSyncPrintf("フクロウ退避\n"); // "Owl evacuation"
                Actor_Kill(&pthis->actor);
                return;
            }
            pthis->actionFunc = EnOwl_WaitLWPostSaria;
            break;
        default:
            // Outside kokiri forest
            osSyncPrintf(VT_FGCOL(CYAN));
            osSyncPrintf("no = %d  \n", owlType);
            // "Unfinished owl unfinished owl unfinished owl"
            osSyncPrintf("未完成のフクロウ未完成のフクロウ未完成のフクロウ\n");
            osSyncPrintf(VT_RST);
            pthis->actionFlags |= 2;
            pthis->unk_3EE = 0x20;
            pthis->actionFunc = EnOwl_WaitOutsideKokiri;
            break;
    }
}

void EnOwl_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnOwl* pthis = (EnOwl*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

/**
 * Rotates pthis to the player instance
 */
void EnOwl_LookAtLink(EnOwl* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y =
        Math_Vec3f_Yaw(&pthis->actor.world.pos, &player->actor.world.pos);
}

/**
 * Checks if link is within `targetDist` units, initalize the camera for the owl.
 * returns 0 if the link is not within `targetDistance`, returns 1 once link is within
 * the distance, and the camera has been initalized.
 */
s32 EnOwl_CheckInitTalk(EnOwl* pthis, GlobalContext* globalCtx, u16 textId, f32 targetDist, u16 flags) {
    s32 timer;
    f32 distCheck;

    if (oot::config().game().blindOwl()) return false;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (pthis->actor.params == 0xFFF) {
            pthis->actionFlags |= 0x40;
            timer = -100;
        } else {
            if (Rand_ZeroOne() < 0.5f) {
                timer = (flags & 1) ? -97 : -99;
                pthis->actionFlags |= 0x40;
            } else {
                timer = (flags & 1) ? -96 : -98;
                pthis->actionFlags &= ~0x40;
            }
        }
        pthis->cameraIdx = OnePointCutscene_Init(globalCtx, 8700, timer, &pthis->actor, MAIN_CAM);
        return true;
    } else {
        pthis->actor.textId = textId;
        distCheck = (flags & 2) ? 200.0f : 1000.0f;
        if (pthis->actor.xzDistToPlayer < targetDist) {
            pthis->actor.flags |= ACTOR_FLAG_16;
            func_8002F1C4(&pthis->actor, globalCtx, targetDist, distCheck, 0);
        }
        return false;
    }
}

s32 func_80ACA558(EnOwl* pthis, GlobalContext* globalCtx, u16 textId) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        return true;
    } else {
        pthis->actor.textId = textId;
        if (pthis->actor.xzDistToPlayer < 120.0f) {
            func_8002F1C4(&pthis->actor, globalCtx, 350.0f, 1000.0f, 0);
        }
        return false;
    }
}

void func_80ACA5C8(EnOwl* pthis) {
    EnOwl_ChangeMode(pthis, func_80ACBEA0, func_80ACC540, &pthis->skelAnime, &gOwlUnfoldWingsAnim, 0.0f);
    pthis->eyeTexIndex = 0;
    pthis->blinkTimer = Rand_S16Offset(60, 60);
}

void func_80ACA62C(EnOwl* pthis, GlobalContext* globalCtx) {
    s32 switchFlag = pthis->actor.params & 0x3F;

    if (switchFlag < 0x20) {
        Flags_SetSwitch(globalCtx, switchFlag);
        osSyncPrintf(VT_FGCOL(CYAN) " Actor_Environment_sw = %d\n" VT_RST, Flags_GetSwitch(globalCtx, switchFlag));
    }
    func_80ACA5C8(pthis);
}

void func_80ACA690(EnOwl* pthis, GlobalContext* globalCtx) {
    if ((pthis->unk_3EE & 0x3F) == 0) {
        func_80ACA62C(pthis, globalCtx);
    }
}

void func_80ACA6C0(EnOwl* pthis) {
    if (Rand_CenteredFloat(1.0f) < 0.0f) {
        pthis->actionFlags |= 0x20;
    } else {
        pthis->actionFlags &= ~0x20;
    }
}

void func_80ACA71C(EnOwl* pthis) {
    func_80ACA6C0(pthis);
    pthis->unk_3F2 = 0;
    pthis->actionFlags |= 0x10;
    pthis->unk_408 = 4;
    pthis->unk_404 = 0;
    pthis->unk_406 = 0;
    pthis->unk_405 = 4;
    pthis->unk_407 = pthis->unk_3F2;
}

void func_80ACA76C(EnOwl* pthis, GlobalContext* globalCtx) {
    func_8002DF54(globalCtx, &pthis->actor, 8);

    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_FANFARE << 24 | 0xFF);
        func_80ACA62C(pthis, globalCtx);
        pthis->actor.flags &= ~ACTOR_FLAG_16;
    }
}

void func_80ACA7E0(EnOwl* pthis, GlobalContext* globalCtx) {
    func_8002DF54(globalCtx, &pthis->actor, 8);

    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_FANFARE << 24 | 0xFF);
        if ((pthis->unk_3EE & 0x3F) == 0) {
            func_80ACA62C(pthis, globalCtx);
        } else {
            pthis->actionFlags &= ~2;
            func_80ACA71C(pthis);
            pthis->actionFunc = func_80ACA690;
        }
        pthis->actor.flags &= ~ACTOR_FLAG_16;
    }
}

void EnOwl_ConfirmKokiriMessage(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case OWL_REPEAT:
                Message_ContinueTextbox(globalCtx, 0x2065);
                break;
            case OWL_OK:
                Message_ContinueTextbox(globalCtx, 0x2067);
                pthis->actionFunc = func_80ACA76C;
                break;
        }
    }
}

void EnOwl_WaitOutsideKokiri(EnOwl* pthis, GlobalContext* globalCtx) {
    EnOwl_LookAtLink(pthis, globalCtx);

    if (EnOwl_CheckInitTalk(pthis, globalCtx, 0x2064, 360.0f, 0)) {
        // Sets BGM
        Audio_PlayFanfare(NA_BGM_OWL);

        pthis->actionFunc = EnOwl_ConfirmKokiriMessage;
        // spoke to owl by lost woods
        gSaveContext.eventChkInf[6] |= 0x8000;
    }
}

void func_80ACA998(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case OWL_REPEAT:
                Message_ContinueTextbox(globalCtx, 0x2069);
                pthis->actionFunc = func_80ACAA54;
                break;
            case OWL_OK:
                Message_ContinueTextbox(globalCtx, 0x206B);
                pthis->actionFunc = func_80ACA7E0;
                break;
        }
        pthis->actionFlags &= ~2;
        func_80ACA71C(pthis);
    }
}

void func_80ACAA54(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x206A);
        pthis->actionFunc = func_80ACA998;
        pthis->actionFlags |= 2;
        func_80ACA71C(pthis);
    }
}

void func_80ACAAC0(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x2069);
        pthis->actionFunc = func_80ACAA54;
        pthis->actionFlags &= ~2;
        func_80ACA71C(pthis);
    }
}

void EnOwl_WaitHyruleCastle(EnOwl* pthis, GlobalContext* globalCtx) {
    EnOwl_LookAtLink(pthis, globalCtx);

    if (EnOwl_CheckInitTalk(pthis, globalCtx, 0x2068, 540.0f, 0)) {
        Audio_PlayFanfare(NA_BGM_OWL);
        pthis->actionFunc = func_80ACAAC0;
    }
}

void func_80ACAB88(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case OWL_REPEAT:
                // obtained zelda's letter
                if (gSaveContext.eventChkInf[4] & 1) {
                    Message_ContinueTextbox(globalCtx, 0x206D);
                } else {
                    Message_ContinueTextbox(globalCtx, 0x206C);
                }
                pthis->actionFunc = func_80ACAC6C;
                break;
            case OWL_OK:
                Message_ContinueTextbox(globalCtx, 0x206E);
                pthis->actionFunc = func_80ACA7E0;
                break;
        }

        pthis->actionFlags &= ~2;
        func_80ACA71C(pthis);
    }
}

void func_80ACAC6C(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x206A);
        pthis->actionFunc = func_80ACAB88;
        pthis->actionFlags |= 2;
        func_80ACA71C(pthis);
    }
}

void EnOwl_WaitKakariko(EnOwl* pthis, GlobalContext* globalCtx) {
    EnOwl_LookAtLink(pthis, globalCtx);

    if (EnOwl_CheckInitTalk(pthis, globalCtx, 0x206C, 480.0f, 0)) {
        Audio_PlayFanfare(NA_BGM_OWL);
        pthis->actionFunc = func_80ACAC6C;
    }
}

void func_80ACAD34(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case OWL_REPEAT:
                Message_ContinueTextbox(globalCtx, 0x206F);
                pthis->actionFunc = func_80ACADF0;
                break;
            case OWL_OK:
                Message_ContinueTextbox(globalCtx, 0x2070);
                pthis->actionFunc = func_80ACA7E0;
                break;
        }

        pthis->actionFlags &= ~2;
        func_80ACA71C(pthis);
    }
}

void func_80ACADF0(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x206A);
        pthis->actionFunc = func_80ACAD34;
        pthis->actionFlags |= 2;
        func_80ACA71C(pthis);
    }
}

void EnOwl_WaitGerudo(EnOwl* pthis, GlobalContext* globalCtx) {
    EnOwl_LookAtLink(pthis, globalCtx);

    if (EnOwl_CheckInitTalk(pthis, globalCtx, 0x206F, 360.0f, 0)) {
        Audio_PlayFanfare(NA_BGM_OWL);
        pthis->actionFunc = func_80ACADF0;
    }
}

void func_80ACAEB8(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case OWL_REPEAT:
                Message_ContinueTextbox(globalCtx, 0x2071);
                pthis->actionFunc = func_80ACAF74;
                break;
            case OWL_OK:
                Message_ContinueTextbox(globalCtx, 0x2072);
                pthis->actionFunc = func_80ACA7E0;
                break;
        }

        pthis->actionFlags &= ~2;
        func_80ACA71C(pthis);
    }
}

void func_80ACAF74(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x206A);
        pthis->actionFunc = func_80ACAEB8;
        pthis->actionFlags |= 2;
        func_80ACA71C(pthis);
    }
}

void EnOwl_WaitLakeHylia(EnOwl* pthis, GlobalContext* globalCtx) {
    EnOwl_LookAtLink(pthis, globalCtx);

    if (EnOwl_CheckInitTalk(pthis, globalCtx, 0x2071, 360.0f, 0)) {
        Audio_PlayFanfare(NA_BGM_OWL);
        pthis->actionFunc = func_80ACAF74;
    }
}

void func_80ACB03C(EnOwl* pthis, GlobalContext* globalCtx) {
    func_8002DF54(globalCtx, &pthis->actor, 8);

    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_FANFARE << 24 | 0xFF);
        func_80ACA62C(pthis, globalCtx);
        pthis->actor.flags &= ~ACTOR_FLAG_16;
    }
}

void EnOwl_WaitZoraRiver(EnOwl* pthis, GlobalContext* globalCtx) {
    u16 textId;

    EnOwl_LookAtLink(pthis, globalCtx);

    if (CHECK_QUEST_ITEM(QUEST_SONG_SARIA)) {
        if (CHECK_QUEST_ITEM(QUEST_SONG_LULLABY)) {
            textId = 0x4031;
        } else {
            textId = 0x4017;
        }
    } else {
        textId = 0x4002;
    }

    if (EnOwl_CheckInitTalk(pthis, globalCtx, textId, 360.0f, 0)) {
        Audio_PlayFanfare(NA_BGM_OWL);
        pthis->actionFunc = func_80ACB03C;
    }
}

void func_80ACB148(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_FANFARE << 24 | 0xFF);
        func_80ACA5C8(pthis);
        pthis->actionFunc = func_80ACC30C;
        Flags_SetSwitch(globalCtx, 0x23);
    }
}

void EnOwl_WaitHyliaShortcut(EnOwl* pthis, GlobalContext* globalCtx) {
    u16 textId = (gSaveContext.infTable[25] & 0x20) ? 0x4004 : 0x4003;

    // Spoke to Owl in Lake Hylia
    EnOwl_LookAtLink(pthis, globalCtx);
    if (func_80ACA558(pthis, globalCtx, textId)) {
        gSaveContext.infTable[25] |= 0x20;
        Audio_PlayFanfare(NA_BGM_OWL);
        pthis->actionFunc = func_80ACB148;
    }
}

void func_80ACB22C(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_FANFARE << 24 | 0xFF);
        func_80ACA5C8(pthis);
        pthis->actionFunc = func_80ACC30C;
    }
}

void func_80ACB274(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_FANFARE << 24 | 0xFF);
        pthis->actionFunc = EnOwl_WaitDeathMountainShortcut;
    }
}

void EnOwl_WaitDeathMountainShortcut(EnOwl* pthis, GlobalContext* globalCtx) {
    EnOwl_LookAtLink(pthis, globalCtx);

    if (!gSaveContext.magicAcquired) {
        if (func_80ACA558(pthis, globalCtx, 0x3062)) {
            Audio_PlayFanfare(NA_BGM_OWL);
            pthis->actionFunc = func_80ACB274;
            return;
        }
    } else {
        if (func_80ACA558(pthis, globalCtx, 0x3063)) {
            Audio_PlayFanfare(NA_BGM_OWL);
            pthis->actionFunc = func_80ACB22C;
        }
    }
}

void func_80ACB344(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case OWL_REPEAT:
                Message_ContinueTextbox(globalCtx, 0x607A);
                break;
            case OWL_OK:
                Message_ContinueTextbox(globalCtx, 0x607C);
                pthis->actionFunc = func_80ACA7E0;
                break;
        }
    }
}

void func_80ACB3E0(EnOwl* pthis, GlobalContext* globalCtx) {
    EnOwl_LookAtLink(pthis, globalCtx);

    if (EnOwl_CheckInitTalk(pthis, globalCtx, 0x6079, 360.0f, 2)) {
        Audio_PlayFanfare(NA_BGM_OWL);
        pthis->actionFunc = func_80ACB344;
    }
}

void func_80ACB440(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case OWL_REPEAT:
                Message_ContinueTextbox(globalCtx, 0x10C1);
                pthis->actionFunc = func_80ACB4FC;
                break;
            case OWL_OK:
                Message_ContinueTextbox(globalCtx, 0x10C3);
                pthis->actionFunc = func_80ACA7E0;
        }

        pthis->actionFlags &= ~2;
        func_80ACA71C(pthis);
    }
}

void func_80ACB4FC(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x10C2);
        pthis->actionFunc = func_80ACB440;
        pthis->actionFlags |= 2;
        func_80ACA71C(pthis);
    }
}

void EnOwl_WaitLWPreSaria(EnOwl* pthis, GlobalContext* globalCtx) {
    EnOwl_LookAtLink(pthis, globalCtx);

    if (EnOwl_CheckInitTalk(pthis, globalCtx, 0x10C0, 190.0f, 0)) {
        Audio_PlayFanfare(NA_BGM_OWL);
        pthis->actionFunc = func_80ACB4FC;
    }
}

void func_80ACB5C4(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case OWL_REPEAT:
                Message_ContinueTextbox(globalCtx, 0x10C5);
                pthis->actionFunc = func_80ACB680;
                break;
            case OWL_OK:
                Message_ContinueTextbox(globalCtx, 0x10C7);
                pthis->actionFunc = func_80ACA7E0;
                break;
        }

        pthis->actionFlags &= ~2;
        func_80ACA71C(pthis);
    }
}

void func_80ACB680(EnOwl* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x10C6);
        pthis->actionFunc = func_80ACB5C4;
        pthis->actionFlags |= 2;
        func_80ACA71C(pthis);
    }
}

void EnOwl_WaitLWPostSaria(EnOwl* pthis, GlobalContext* globalCtx) {
    EnOwl_LookAtLink(pthis, globalCtx);

    if (EnOwl_CheckInitTalk(pthis, globalCtx, 0x10C4, 360.0f, 0)) {
        Audio_PlayFanfare(NA_BGM_OWL);
        pthis->actionFunc = func_80ACB680;
    }
}

void func_80ACB748(EnOwl* pthis, GlobalContext* globalCtx) {
    static Vec3f D_80ACD62C = { 0.0f, 0.0f, 0.0f };
    f32 dist;
    f32 weight;
    s32 owlType = (pthis->actor.params & 0xFC0) >> 6;

    dist = Math3D_Vec3f_DistXYZ(&pthis->eye, &globalCtx->view.eye) / 45.0f;
    pthis->eye.x = globalCtx->view.eye.x;
    pthis->eye.y = globalCtx->view.eye.y;
    pthis->eye.z = globalCtx->view.eye.z;

    weight = dist;
    if (weight > 1.0f) {
        weight = 1.0f;
    }

    switch (owlType) {
        case 7:
            func_800F436C(&D_80ACD62C, NA_SE_EV_FLYING_AIR - SFX_FLAG, weight * 2.0f);
            if ((globalCtx->csCtx.frames > 324) ||
                ((globalCtx->csCtx.frames >= 142 && (globalCtx->csCtx.frames <= 266)))) {
                func_800F4414(&D_80ACD62C, NA_SE_EN_OWL_FLUTTER, weight * 2.0f);
            }
            if (globalCtx->csCtx.frames == 85) {
                func_800F436C(&D_80ACD62C, NA_SE_EV_PASS_AIR, weight * 2.0f);
            }
            break;
        case 8:
        case 9:
            func_800F436C(&D_80ACD62C, NA_SE_EV_FLYING_AIR - SFX_FLAG, weight * 2.0f);
            if ((globalCtx->csCtx.frames >= 420) || ((globalCtx->csCtx.frames > 0xC1 && (globalCtx->csCtx.frames <= 280))))
	    {
                func_800F4414(&D_80ACD62C, NA_SE_EN_OWL_FLUTTER, weight * 2.0f);
            }
            if (globalCtx->csCtx.frames == 217) {
                func_800F436C(&D_80ACD62C, NA_SE_EV_PASS_AIR, weight * 2.0f);
            }
            break;
    }
}

void func_80ACB904(EnOwl* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE && (globalCtx->csCtx.npcActions[7] != NULL)) {
        if (pthis->unk_40A != globalCtx->csCtx.npcActions[7]->action) {
            func_80ACD130(pthis, globalCtx, 7);
            func_80ACBAB8(pthis, globalCtx);
        }
        func_80ACD2CC(pthis, globalCtx);
    }

    if (pthis->actionFlags & 0x80) {
        func_80ACB748(pthis, globalCtx);
    }
}

void func_80ACB994(EnOwl* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE && (globalCtx->csCtx.npcActions[7] != NULL)) {
        if (pthis->unk_40A != globalCtx->csCtx.npcActions[7]->action) {
            func_80ACD130(pthis, globalCtx, 7);
            func_80ACBAB8(pthis, globalCtx);
        }
        func_80ACD4D4(pthis, globalCtx);
    }

    if (pthis->actionFlags & 0x80) {
        func_80ACB748(pthis, globalCtx);
    }
}

void EnOwl_WaitDefault(EnOwl* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE && (globalCtx->csCtx.npcActions[7] != NULL)) {
        if (pthis->unk_40A != globalCtx->csCtx.npcActions[7]->action) {
            pthis->actionFlags |= 4;
            func_80ACD130(pthis, globalCtx, 7);
            func_80ACBAB8(pthis, globalCtx);
        } else {
            pthis->actor.world.rot.z = globalCtx->csCtx.npcActions[7]->urot.y;
        }
    }

    if (pthis->actionFlags & 0x80) {
        func_80ACB748(pthis, globalCtx);
    }
}

void func_80ACBAB8(EnOwl* pthis, GlobalContext* globalCtx) {
    switch (globalCtx->csCtx.npcActions[7]->action - 1) {
        case 0:
            EnOwl_ChangeMode(pthis, func_80ACB904, func_80ACC540, &pthis->skelAnime, &gOwlFlyAnim, 0.0f);
            break;
        case 1:
            pthis->actor.draw = EnOwl_Draw;
            EnOwl_ChangeMode(pthis, EnOwl_WaitDefault, func_80ACC540, &pthis->skelAnime, &gOwlPerchAnim, 0.0f);
            break;
        case 2:
            pthis->actor.draw = EnOwl_Draw;
            EnOwl_ChangeMode(pthis, func_80ACB994, func_80ACC540, &pthis->skelAnime, &gOwlFlyAnim, 0.0f);
            break;
        case 3:
            pthis->actor.draw = NULL;
            pthis->actionFunc = EnOwl_WaitDefault;
            break;
        case 4:
            Actor_Kill(&pthis->actor);
            break;
    }

    pthis->unk_40A = globalCtx->csCtx.npcActions[7]->action;
}

void func_80ACBC0C(EnOwl* pthis, GlobalContext* globalCtx) {
    pthis->actor.flags |= ACTOR_FLAG_5;

    if (pthis->actor.xzDistToPlayer > 6000.0f && !(pthis->actionFlags & 0x80)) {
        Actor_Kill(&pthis->actor);
    }

    Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_400, 2, 0x80, 0x40);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (pthis->actor.speedXZ < 16.0f) {
        pthis->actor.speedXZ += 0.5f;
    }

    if ((pthis->unk_3F8 + 1000.0f) < pthis->actor.world.pos.y) {
        if (pthis->actor.velocity.y > 0.0f) {
            pthis->actor.velocity.y -= 0.4f;
        }
    } else if (pthis->actor.velocity.y < 4.0f) {
        pthis->actor.velocity.y += 0.2f;
    }

    pthis->actionFlags |= 8;
}

void func_80ACBD4C(EnOwl* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.curFrame > 10.0f) {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_400, 2, 0x400, 0x40);
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    }

    if (pthis->skelAnime.curFrame > 45.0f) {
        pthis->actor.velocity.y = 2.0f;
        pthis->actor.gravity = 0.0f;
        pthis->actor.speedXZ = 8.0f;
    } else if (pthis->skelAnime.curFrame > 17.0f) {
        pthis->actor.velocity.y = 6.0f;
        pthis->actor.gravity = 0.0f;
        pthis->actor.speedXZ = 4.0f;
    }

    if (pthis->actionFlags & 1) {
        EnOwl_ChangeMode(pthis, func_80ACBC0C, func_80ACC460, &pthis->skelAnime, &gOwlFlyAnim, 0.0f);
        pthis->unk_3FE = 6;
        if (pthis->actionFlags & 0x40) {
            pthis->unk_400 += 0x2000;
        } else {
            pthis->unk_400 -= 0x2000;
        }
    }

    pthis->actionFlags |= 8;
}

void func_80ACBEA0(EnOwl* pthis, GlobalContext* GlobalContext) {
    if (pthis->actionFlags & 1) {
        pthis->unk_3FE = 3;
        EnOwl_ChangeMode(pthis, func_80ACBD4C, func_80ACC540, &pthis->skelAnime, &gOwlTakeoffAnim, 0.0f);
        pthis->unk_3F8 = pthis->actor.world.pos.y;
        pthis->actor.velocity.y = 2.0f;
        if (pthis->actionFlags & 0x40) {
            pthis->unk_400 = pthis->actor.world.rot.y + 0x4000;
        } else {
            pthis->unk_400 = pthis->actor.world.rot.y - 0x4000;
        }
    }

    pthis->actionFlags |= 8;
}

void func_80ACBF50(EnOwl* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_400, 2, 0x384, 0x258);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (pthis->actionFlags & 1) {
        EnOwl_ChangeMode(pthis, func_80ACBC0C, func_80ACC460, &pthis->skelAnime, &gOwlFlyAnim, 0.0f);
        pthis->unk_3FE = 6;
        pthis->actor.velocity.y = 2.0f;
        pthis->actor.gravity = 0.0f;
        pthis->actor.speedXZ = 4.0f;
    }
    pthis->actionFlags |= 8;
}

void func_80ACC00C(EnOwl* pthis, GlobalContext* globalCtx) {
    s32 owlType;
    s32 temp_v0;
    s32 temp_v0_2;

    Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_400, 2, 0x384, 0x258);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (pthis->actor.xzDistToPlayer < 50.0f) {
        if (!Gameplay_InCsMode(globalCtx)) {
            owlType = (pthis->actor.params & 0xFC0) >> 6;
            osSyncPrintf(VT_FGCOL(CYAN));
            osSyncPrintf("%dのフクロウ\n", owlType); // "%d owl"
            osSyncPrintf(VT_RST);
            switch (owlType) {
                case 7:
                    osSyncPrintf(VT_FGCOL(CYAN));
                    osSyncPrintf("SPOT 06 の デモがはしった\n"); // "Demo of SPOT 06 has been completed"
                    osSyncPrintf(VT_RST);
                    globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gLakeHyliaOwlCs);
                    pthis->actor.draw = NULL;
                    break;
                case 8:
                case 9:
                    globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gDMTOwlCs);
                    pthis->actor.draw = NULL;
                    break;
                default:
                    ASSERT(0, "0", "../z_en_owl.c", 1693);
                    break;
            }

            func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
            gSaveContext.cutsceneTrigger = 1;
            func_800F44EC(0x14, 0xA);
            pthis->actionFunc = EnOwl_WaitDefault;
            pthis->unk_40A = 0;
            pthis->actionFlags |= 0x80;
            gTimeIncrement = 0;
        }
    }

    if (pthis->skelAnime.curFrame >= 37.0f) {
        if (pthis->unk_3FE > 0) {
            pthis->skelAnime.curFrame = 21.0f;
            pthis->unk_3FE--;
        } else {
            pthis->actionFunc = func_80ACBF50;
        }
    }

    pthis->actionFlags |= 8;
}

void func_80ACC23C(EnOwl* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.curFrame < 20.0f) {
        pthis->actor.speedXZ = 1.5f;
    } else {
        pthis->actor.speedXZ = 0.0f;
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_400, 2, 0x384, 0x258);
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    }

    if (pthis->skelAnime.curFrame >= 37.0f) {
        pthis->skelAnime.curFrame = 21.0f;
        pthis->actionFunc = func_80ACC00C;
        pthis->unk_3FE = 5;
        pthis->actor.velocity.y = 0.0f;
        pthis->actor.gravity = 0.0f;
        pthis->actor.speedXZ = 0.0f;
    }

    pthis->actionFlags |= 8;
}

void func_80ACC30C(EnOwl* pthis, GlobalContext* globalCtx) {
    if (pthis->actionFlags & 1) {
        pthis->unk_3FE = 3;
        EnOwl_ChangeMode(pthis, func_80ACC23C, func_80ACC540, &pthis->skelAnime, &gOwlTakeoffAnim, 0.0f);
        pthis->unk_3F8 = pthis->actor.world.pos.y;
        pthis->actor.velocity.y = 0.2f;
    }

    pthis->actionFlags |= 8;
}

void func_80ACC390(EnOwl* pthis) {
    SkelAnime_Update(pthis->curSkelAnime);

    if (pthis->unk_3FE > 0) {
        pthis->unk_3FE--;
        pthis->actor.shape.rot.z = Math_SinS(pthis->unk_3FE * 0x333) * 1000.0f;
    } else {
        pthis->unk_410 = func_80ACC460;
        pthis->unk_3FE = 6;
        Animation_Change(pthis->curSkelAnime, &gOwlFlyAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gOwlFlyAnim), 2, 5.0f);
    }
}

void func_80ACC460(EnOwl* pthis) {
    if (SkelAnime_Update(pthis->curSkelAnime)) {
        if (pthis->unk_3FE > 0) {
            pthis->unk_3FE--;
            Animation_Change(pthis->curSkelAnime, (AnimationHeader*)pthis->curSkelAnime->animation, 1.0f, 0.0f,
                             Animation_GetLastFrame(pthis->curSkelAnime->animation), ANIMMODE_ONCE, 0.0f);
        } else {
            pthis->unk_3FE = 0xA0;
            pthis->unk_410 = func_80ACC390;
            Animation_Change(pthis->curSkelAnime, &gOwlGlideAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gOwlGlideAnim), 0,
                             5.0f);
        }
    }
}

void func_80ACC540(EnOwl* pthis) {
    if (SkelAnime_Update(pthis->curSkelAnime)) {
	    Animation_Change(pthis->curSkelAnime, (AnimationHeader*)pthis->curSkelAnime->animation, 1.0f, 0.0f,
                         Animation_GetLastFrame(pthis->curSkelAnime->animation), ANIMMODE_ONCE, 0.0f);
        pthis->actionFlags |= 1;
    } else {
        pthis->actionFlags &= ~1;
    }
}

s32 func_80ACC5CC(EnOwl* pthis) {
    s32 phi_v1 = (pthis->actionFlags & 2) ? 0x20 : 0;

    if (phi_v1 == (pthis->unk_3EE & 0x3F)) {
        return true;
    } else {
        if (pthis->actionFlags & 0x20) {
            pthis->unk_3EE += 4;
        } else {
            pthis->unk_3EE -= 4;
        }

        return false;
    }
}

s32 func_80ACC624(EnOwl* pthis, GlobalContext* globalCtx) {
    s32 switchFlag = (pthis->actor.params & 0xFC0) >> 6;

    if (globalCtx->sceneNum != SCENE_SPOT11) {
        return true;
    } else if (switchFlag == 0xA) {
        return true;
    } else if (globalCtx->csCtx.frames >= 300 && globalCtx->csCtx.frames <= 430) {
        return true;
    } else if (globalCtx->csCtx.frames >= 1080 && globalCtx->csCtx.frames <= 1170) {
        return true;
    } else {
        return false;
    }
}

void EnOwl_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnOwl* pthis = (EnOwl*)thisx;
    s16 phi_a1;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 10.0f, 5);
    pthis->unk_410(pthis);
    pthis->actionFlags &= ~8;
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->actor.update == NULL) {
        // "Owl disappears"
        osSyncPrintf("フクロウ消滅!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        return;
    }

    if (!(pthis->actionFlags & 0x80) && func_80ACC624(pthis, globalCtx)) {
        if ((pthis->skelAnime.animation == &gOwlTakeoffAnim &&
             (pthis->skelAnime.curFrame == 2.0f || pthis->skelAnime.curFrame == 9.0f ||
              pthis->skelAnime.curFrame == 23.0f || pthis->skelAnime.curFrame == 40.0f ||
              pthis->skelAnime.curFrame == 58.0f)) ||
            (pthis->skelAnime.animation == &gOwlFlyAnim && pthis->skelAnime.curFrame == 4.0f)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OWL_FLUTTER);
        }
    }

    if (pthis->actor.draw != NULL) {
        Actor_MoveForward(&pthis->actor);
    }

    if (pthis->actionFlags & 2) {
        pthis->eyeTexIndex = 2;
    } else {
        if (DECR(pthis->blinkTimer) == 0) {
            pthis->blinkTimer = Rand_S16Offset(60, 60);
        }

        pthis->eyeTexIndex = pthis->blinkTimer;

        if (pthis->eyeTexIndex >= 3) {
            pthis->eyeTexIndex = 0;
        }
    }

    if (!(pthis->actionFlags & 8)) {
        phi_a1 = 0;
        if (pthis->actionFlags & 0x10) {
            switch (pthis->unk_404) {
                case 0:
                    pthis->unk_404 = 1;
                    pthis->unk_405 = 6;
                    break;
                case 1:
                    pthis->unk_405--;

                    if (pthis->unk_405 != 0) {
                        phi_a1 = Math_CosS(pthis->unk_405 * 8192) * 4096.0f;
                    } else {
                        if (pthis->actionFlags & 2) {
                            pthis->unk_3EE = 0;
                        } else {
                            pthis->unk_3EE = 0x20;
                        }

                        if (pthis->actionFlags & 0x20) {
                            pthis->unk_3EE -= 4;
                        } else {
                            pthis->unk_3EE += 4;
                        }
                        pthis->unk_404++;
                    }

                    if (pthis->actionFlags & 0x20) {
                        phi_a1 = -phi_a1;
                    }
                    break;
                case 2:
                    if (func_80ACC5CC(pthis)) {
                        pthis->actionFlags &= ~0x10;
                        pthis->unk_406 = (s32)Rand_ZeroFloat(20.0f) + 0x3C;
                        pthis->unk_404 = 0;
                        func_80ACA6C0(pthis);
                    }
                    break;
                default:
                    break;
            }
        } else {
            if (pthis->unk_406 > 0) {
                pthis->unk_406--;
            } else {
                if (pthis->unk_404 == 0) {
                    if (Rand_ZeroOne() < 0.3f) {
                        pthis->unk_404 = 4;
                        pthis->unk_405 = 0xC;
                    } else {
                        pthis->unk_404 = 1;
                        pthis->unk_405 = 4;
                    }
                }

                pthis->unk_405--;

                switch (pthis->unk_404) {
                    case 1:
                        phi_a1 = Math_SinS((-pthis->unk_405 * 4096) + 0x4000) * 5000.0f;
                        if (pthis->unk_405 <= 0) {
                            pthis->unk_405 = (s32)(Rand_ZeroFloat(15.0f) + 5.0f);
                            pthis->unk_404 = 2;
                        }
                        break;
                    case 2:
                        phi_a1 = 0x1388;
                        if (pthis->unk_405 <= 0) {
                            pthis->unk_404 = 3;
                            pthis->unk_405 = 4;
                        }
                        break;
                    case 3:
                        phi_a1 = Math_SinS(pthis->unk_405 * 4096) * 5000.0f;
                        if (pthis->unk_405 <= 0) {
                            pthis->unk_406 = (s32)Rand_ZeroFloat(20.0f) + 0x3C;
                            pthis->unk_404 = 0;
                            func_80ACA6C0(pthis);
                        }
                        break;
                    case 4:
                        phi_a1 = Math_SinS(pthis->unk_405 * 8192) * 5000.0f;
                        if (pthis->unk_405 <= 0) {
                            pthis->unk_406 = (s32)Rand_ZeroFloat(20.0f) + 0x3C;
                            pthis->unk_404 = 0;
                            func_80ACA6C0(pthis);
                        }
                        break;
                    default:
                        break;
                }

                if (pthis->actionFlags & 0x20) {
                    phi_a1 = -phi_a1;
                }
            }

            if (pthis->unk_409 > 0) {
                pthis->unk_409--;
            } else {
                pthis->unk_408--;
                switch (pthis->unk_407) {
                    case 0:
                        pthis->unk_3F2 = (-pthis->unk_408 * 0x5DC) + 0x1770;
                        if (pthis->unk_408 <= 0) {
                            pthis->unk_407 = 1;
                            pthis->unk_408 = (s32)(Rand_ZeroFloat(15.0f) + 5.0f);
                        }
                        break;
                    case 1:
                        pthis->unk_3F2 = 0x1770;
                        if (pthis->unk_408 <= 0) {
                            pthis->unk_407 = 2;
                            pthis->unk_408 = 4;
                        }
                        break;
                    case 2:
                        pthis->unk_3F2 = pthis->unk_408 * 0x5DC;
                        if (pthis->unk_408 <= 0) {
                            pthis->unk_407 = 0;
                            pthis->unk_408 = 4;
                            pthis->unk_409 = (s32)Rand_ZeroFloat(40.0f) + 0xA0;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        if (phi_a1) {}
        pthis->unk_3F0 = (u16)((pthis->unk_3EE << 2) << 8) + phi_a1;
        pthis->unk_3EC = ABS(pthis->unk_3F0) >> 3;
    } else {
        pthis->unk_3F2 = 0;
        if (pthis->actionFlags & 2) {
            pthis->unk_3F0 = -0x8000;
        } else {
            pthis->unk_3F0 = 0;
        }

        pthis->unk_3EC = ABS(pthis->unk_3F0) >> 3;
    }
}

s32 EnOwl_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** gfx, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnOwl* pthis = (EnOwl*)thisx;

    switch (limbIndex) {
        case 3:
            rot->x += pthis->unk_3F0;
            rot->z += pthis->unk_3EC;
            rot->z -= pthis->unk_3F2;
            break;
        case 2:
            rot->z += pthis->unk_3F2;
            break;
        case 4:
            if (!(pthis->actionFlags & 8)) {
                rot->y -= (s16)(pthis->unk_3EC * 1.5f);
            }
            break;
        case 5:
            if (!(pthis->actionFlags & 8)) {
                rot->y += (s16)(pthis->unk_3EC * 1.5f);
            }
            break;
        default:
            break;
    }
    return false;
}

void EnOwl_PostLimbUpdate(GlobalContext* globalCtx, s32 limbIndex, Gfx** gfx, Vec3s* rot, void* thisx) {
    EnOwl* pthis = (EnOwl*)thisx;
    Vec3f vec;

    vec.z = 0.0f;
    if (pthis->actionFlags & 2) {
        vec.x = 700.0f;
        vec.y = 400.0f;
    } else {
        vec.y = 0.0f;
        vec.x = 1400.0f;
    }
    if (limbIndex == 3) {
        Matrix_MultVec3f(&vec, &pthis->actor.focus.pos);
    }
}

void EnOwl_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* eyeTextures[] = { gObjOwlEyeOpenTex, gObjOwlEyeHalfTex, gObjOwlEyeClosedTex };
    EnOwl* pthis = (EnOwl*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_owl.c", 2247);

    func_800943C8(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 8, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->eyeTexIndex]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->curSkelAnime->skeleton, pthis->curSkelAnime->jointTable,
                          pthis->curSkelAnime->dListCount, EnOwl_OverrideLimbDraw, EnOwl_PostLimbUpdate, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_owl.c", 2264);
}

void EnOwl_ChangeMode(EnOwl* pthis, EnOwlActionFunc actionFunc, OwlFunc arg2, SkelAnime* skelAnime,
                      AnimationHeader* animation, f32 morphFrames) {
    pthis->curSkelAnime = skelAnime;
    Animation_Change(pthis->curSkelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_ONCE,
                     morphFrames);
    pthis->actionFunc = actionFunc;
    pthis->unk_410 = arg2;
}

void func_80ACD130(EnOwl* pthis, GlobalContext* globalCtx, s32 idx) {
    Vec3f startPos;

    startPos.x = globalCtx->csCtx.npcActions[idx]->startPos.x;
    startPos.y = globalCtx->csCtx.npcActions[idx]->startPos.y;
    startPos.z = globalCtx->csCtx.npcActions[idx]->startPos.z;
    pthis->actor.world.pos = startPos;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y = globalCtx->csCtx.npcActions[idx]->rot.y;
    pthis->actor.shape.rot.z = globalCtx->csCtx.npcActions[idx]->urot.z;
}

f32 func_80ACD1C4(GlobalContext* globalCtx, s32 idx) {
	f32 ret = Environment_LerpWeight(globalCtx->csCtx.npcActions[idx]->endFrame, globalCtx->csCtx.npcActions[idx]->startFrame, globalCtx->csCtx.frames);

    ret = CLAMP_MAX(ret, 1.0f);
    return ret;
}

void func_80ACD220(EnOwl* pthis, Vec3f* arg1, f32 arg2) {
    Vec3f rpy;

    rpy.x = (arg1->x - pthis->actor.world.pos.x) * arg2;
    rpy.y = (arg1->y - pthis->actor.world.pos.y) * arg2;
    rpy.z = (arg1->z - pthis->actor.world.pos.z) * arg2;

    Math_StepToF(&pthis->actor.velocity.y, rpy.y, 1.0f);
    pthis->actor.speedXZ = sqrtf(SQ(rpy.x) + SQ(rpy.z));
    pthis->actor.world.rot.y = Math_Vec3f_Yaw(&pthis->actor.world.pos, arg1);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void func_80ACD2CC(EnOwl* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    s32 angle;
    f32 t = func_80ACD1C4(globalCtx, 7);

    pos.x = globalCtx->csCtx.npcActions[7]->startPos.x;
    pos.y = globalCtx->csCtx.npcActions[7]->startPos.y;
    pos.z = globalCtx->csCtx.npcActions[7]->startPos.z;
    angle = (s16)globalCtx->csCtx.npcActions[7]->rot.y - pthis->actor.world.rot.z;
    if (angle < 0) {
        angle += 0x10000;
    }
    angle = (s16)((t * angle) + pthis->actor.world.rot.z);
    angle = (u16)angle;
    if (pthis->actionFlags & 4) {
        f32 phi_f2 = globalCtx->csCtx.npcActions[7]->urot.x;

        phi_f2 *= 10.0f * (360.0f / 0x10000);
        if (phi_f2 < 0.0f) {
            phi_f2 += 360.0f;
        }
        pos.x -= Math_SinS(angle) * phi_f2;
        pos.z += Math_CosS(angle) * phi_f2;
        pthis->unk_3F8 = phi_f2;
        pthis->actor.world.pos = pos;
        pthis->actor.draw = EnOwl_Draw;
        pthis->actionFlags &= ~4;
        pthis->actor.speedXZ = 0.0f;
    } else {
        pos.x -= Math_SinS(angle) * pthis->unk_3F8;
        pos.z += Math_CosS(angle) * pthis->unk_3F8;
        func_80ACD220(pthis, &pos, 1.0f);
    }
}

void func_80ACD4D4(EnOwl* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f endPosf;
    f32 temp_ret = func_80ACD1C4(globalCtx, 7);

    pos.x = globalCtx->csCtx.npcActions[7]->startPos.x;
    pos.y = globalCtx->csCtx.npcActions[7]->startPos.y;
    pos.z = globalCtx->csCtx.npcActions[7]->startPos.z;
    endPosf.x = globalCtx->csCtx.npcActions[7]->endPos.x;
    endPosf.y = globalCtx->csCtx.npcActions[7]->endPos.y;
    endPosf.z = globalCtx->csCtx.npcActions[7]->endPos.z;
    pos.x = (endPosf.x - pos.x) * temp_ret + pos.x;
    pos.y = (endPosf.y - pos.y) * temp_ret + pos.y;
    pos.z = (endPosf.z - pos.z) * temp_ret + pos.z;
    func_80ACD220(pthis, &pos, 1.0f);
}
