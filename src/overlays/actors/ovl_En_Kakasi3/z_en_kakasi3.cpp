#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_KAKASI3_Z_EN_KAKASI3_C
#include "actor_common.h"
/*
 * File: z_en_kakasi3.c
 * Overlay: ovl_En_Kakasi3
 * Description: Bonooru the Scarecrow
 */

#include "z_en_kakasi3.h"
#include "vt.h"
#include "objects/object_ka/object_ka.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_25)

void EnKakasi3_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKakasi3_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnKakasi3_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKakasi3_Update(Actor* thisx, GlobalContext* globalCtx);
void EnKakasi3_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A911F0(EnKakasi3* pthis, GlobalContext* globalCtx);
void func_80A91284(EnKakasi3* pthis, GlobalContext* globalCtx);
void func_80A91348(EnKakasi3* pthis, GlobalContext* globalCtx);
void func_80A915B8(EnKakasi3* pthis, GlobalContext* globalCtx);
void func_80A91620(EnKakasi3* pthis, GlobalContext* globalCtx);
void func_80A91760(EnKakasi3* pthis, GlobalContext* globalCtx);
void func_80A917FC(EnKakasi3* pthis, GlobalContext* globalCtx);
void func_80A9187C(EnKakasi3* pthis, GlobalContext* globalCtx);
void func_80A918E4(EnKakasi3* pthis, GlobalContext* globalCtx);
void func_80A91A90(EnKakasi3* pthis, GlobalContext* globalCtx);

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 20, 70, 0, { 0, 0, 0 } },
};

ActorInit En_Kakasi3_InitVars = {
    ACTOR_EN_KAKASI3,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_KA,
    sizeof(EnKakasi3),
    (ActorFunc)EnKakasi3_Init,
    (ActorFunc)EnKakasi3_Destroy,
    (ActorFunc)EnKakasi3_Update,
    (ActorFunc)EnKakasi3_Draw,
    (ActorFunc)EnKakasi3_Reset,
};

void EnKakasi3_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi3* pthis = (EnKakasi3*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
    //! @bug SkelAnime_Free is not called
}

void EnKakasi3_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi3* pthis = (EnKakasi3*)thisx;

    osSyncPrintf("\n\n");
    // "Obonur" -- Related to the name of the scarecrow (Bonooru)
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ おーボヌール ☆☆☆☆☆ \n" VT_RST);
    pthis->actor.targetMode = 6;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_ka_Skel_0065B0, &object_ka_Anim_000214, NULL, NULL, 0);
    pthis->actor.flags |= ACTOR_FLAG_10;
    pthis->rot = pthis->actor.world.rot;
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actionFunc = func_80A911F0;
}

void func_80A90E28(EnKakasi3* pthis) {
    pthis->unk_1A4 = 0;
    pthis->skelAnime.playSpeed = 0.0f;
    pthis->unk_1AA = pthis->unk_1AE = 0x0;

    Math_ApproachZeroF(&pthis->skelAnime.curFrame, 0.5f, 1.0f);
    Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->rot.x, 5, 0x2710, 0);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->rot.y, 5, 0x2710, 0);
    Math_SmoothStepToS(&pthis->actor.shape.rot.z, pthis->rot.z, 5, 0x2710, 0);
}

void func_80A90EBC(EnKakasi3* pthis, GlobalContext* globalCtx, s32 arg) {
    s16 currentFrame;
    s16 ocarinaNote = globalCtx->msgCtx.lastOcaNoteIdx;

    if (arg != 0) {
        if (pthis->unk_19C[3] == 0) {
            pthis->unk_19C[3] = (s16)Rand_ZeroFloat(10.99f) + 30;
            pthis->unk_1A6 = (s16)Rand_ZeroFloat(4.99f);
        }

        pthis->unk_19A = (s16)Rand_ZeroFloat(2.99f) + 5;
        ocarinaNote = pthis->unk_1A6;
    }
    switch (ocarinaNote) {
        case OCARINA_NOTE_A:
            pthis->unk_19A++;
            if (pthis->unk_1A4 == 0) {
                pthis->unk_1A4 = 1;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_KAKASHI_ROLL);
            }
            break;
        case OCARINA_NOTE_C_DOWN:
            pthis->unk_19A++;
            pthis->unk_1B8 = 1.0f;
            break;
        case OCARINA_NOTE_C_RIGHT:
            pthis->unk_19A++;
            if (pthis->unk_1AE == 0x0) {
                pthis->unk_1AE = 0x1388;
            }
            break;
        case OCARINA_NOTE_C_LEFT:
            pthis->unk_19A++;
            if (pthis->unk_1AA == 0x0) {
                pthis->unk_1AA = 0x1388;
            }
            break;
        case OCARINA_NOTE_C_UP:
            pthis->unk_19A++;
            pthis->unk_1B8 = 2.0f;
            break;
    }

    if (pthis->unk_19A > 8) {
        pthis->unk_19A = 8;
    }

    if (pthis->unk_19A != 0) {
        pthis->actor.gravity = -1.0f;
        if (pthis->unk_19A == 8 && (pthis->actor.bgCheckFlags & 1)) {
            pthis->actor.velocity.y = 3.0f;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_KAKASHI_JUMP);
        }
        Math_ApproachF(&pthis->skelAnime.playSpeed, pthis->unk_1B8, 0.1f, 0.2f);
        Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->unk_1AA, 0x5, 0x3E8, 0);
        Math_SmoothStepToS(&pthis->actor.shape.rot.z, pthis->unk_1AE, 0x5, 0x3E8, 0);

        if (pthis->unk_1AA != 0x0 && fabsf(pthis->actor.shape.rot.x - pthis->unk_1AA) < 50.0f) {
            pthis->unk_1AA *= -1.0f;
        }
        if (pthis->unk_1AE != 0x0 && fabsf(pthis->actor.shape.rot.z - pthis->unk_1AE) < 50.0f) {
            pthis->unk_1AE *= -1.0f;
        }

        if (pthis->unk_1A4 != 0) {
            pthis->actor.shape.rot.y += 0x1000;
            if (pthis->actor.shape.rot.y == 0) {
                pthis->unk_1A4 = 0;
            }
        }
        currentFrame = pthis->skelAnime.curFrame;
        if (currentFrame == 11 || currentFrame == 17) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_KAKASHI_SWING);
        }
        SkelAnime_Update(&pthis->skelAnime);
    }
}

void func_80A911F0(EnKakasi3* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&object_ka_Anim_000214);

    Animation_Change(&pthis->skelAnime, &object_ka_Anim_000214, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = func_80A91284;
}

void func_80A91284(EnKakasi3* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    pthis->actor.textId = 0x40A1;
    pthis->dialogState = TEXT_STATE_DONE;
    pthis->unk_19A = 0;

    if (!LINK_IS_ADULT) {
        pthis->unk_194 = false;
        if (gSaveContext.scarecrowSpawnSongSet) {
            pthis->actor.textId = 0x40A0;
            pthis->dialogState = TEXT_STATE_EVENT;
            pthis->unk_1A8 = 1;
        }
    } else {
        pthis->unk_194 = true;
        if (gSaveContext.scarecrowSpawnSongSet) {
            if (pthis->unk_195) {
                pthis->actor.textId = 0x40A2;
            } else {
                pthis->actor.textId = 0x40A3;
            }
        }
    }
    pthis->actionFunc = func_80A91348;
}

void func_80A91348(EnKakasi3* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    func_80A90E28(pthis);
    SkelAnime_Update(&pthis->skelAnime);
    pthis->camId = SUBCAM_NONE;
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (!pthis->unk_194) {
            if (pthis->unk_1A8 == 0) {
                pthis->actionFunc = func_80A91284;
            } else {
                pthis->actionFunc = func_80A91760;
            }
        } else {
            pthis->actionFunc = func_80A91284;
        }
    } else {
        s16 angleTowardsLink = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

        if (!(pthis->actor.xzDistToPlayer > 120.0f)) {
            s16 absAngleTowardsLink = ABS(angleTowardsLink);

            if (absAngleTowardsLink < 0x4300) {
                if (!pthis->unk_194) {

                    if (player->stateFlags2 & 0x1000000) {
                        pthis->camId = OnePointCutscene_Init(globalCtx, 2260, -99, &pthis->actor, MAIN_CAM);
                        globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
                        pthis->dialogState = TEXT_STATE_EVENT;
                        pthis->unk_1B8 = 0.0f;
                        Message_StartTextbox(globalCtx, 0x40A4, NULL);
                        player->stateFlags2 |= 0x800000;
                        pthis->actionFunc = func_80A915B8;
                        return;
                    }
                    if (pthis->actor.xzDistToPlayer < 80.0f) {
                        player->stateFlags2 |= 0x800000;
                    }
                } else if (gSaveContext.scarecrowSpawnSongSet && !pthis->unk_195) {

                    if (player->stateFlags2 & 0x1000000) {
                        pthis->camId = OnePointCutscene_Init(globalCtx, 2260, -99, &pthis->actor, MAIN_CAM);
                        globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
                        pthis->dialogState = TEXT_STATE_EVENT;
                        pthis->unk_1B8 = 0.0f;
                        Message_StartTextbox(globalCtx, 0x40A8, NULL);
                        player->stateFlags2 |= 0x800000;
                        pthis->actionFunc = func_80A9187C;
                        return;
                    }
                    if (pthis->actor.xzDistToPlayer < 80.0f) {
                        player->stateFlags2 |= 0x800000;
                    }
                }
                func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
            }
        }
    }
}

void func_80A915B8(EnKakasi3* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        func_8010BD58(globalCtx, OCARINA_ACTION_SCARECROW_RECORDING);
        pthis->actionFunc = func_80A91620;
    }
}

void func_80A91620(EnKakasi3* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04 ||
         (globalCtx->msgCtx.ocarinaMode >= OCARINA_MODE_05 && globalCtx->msgCtx.ocarinaMode < OCARINA_MODE_0B)) &&
        (globalCtx->msgCtx.msgMode == MSGMODE_NONE)) {

        OnePointCutscene_EndCutscene(globalCtx, pthis->camId);
        if (globalCtx->cameraPtrs[pthis->camId] == NULL) {
            pthis->camId = SUBCAM_NONE;
        }
        if (pthis->camId != SUBCAM_NONE) {
            func_8005B1A4(globalCtx->cameraPtrs[pthis->camId]);
        }
        pthis->actionFunc = func_80A911F0;
        return;
    }

    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03 && globalCtx->msgCtx.msgMode == MSGMODE_NONE) {
        pthis->dialogState = TEXT_STATE_EVENT;
        Message_StartTextbox(globalCtx, 0x40A5, NULL);
        func_8002DF54(globalCtx, NULL, 8);
        pthis->actionFunc = func_80A91A90;
        return;
    }

    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_01) {
        func_80A90EBC(pthis, globalCtx, 0);
        player->stateFlags2 |= 0x800000;
    }
}

void func_80A91760(EnKakasi3* pthis, GlobalContext* globalCtx) {

    func_80A90E28(pthis);
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->dialogState == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx)) {
        globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
        func_8010BD58(globalCtx, OCARINA_ACTION_SCARECROW_PLAYBACK);
        pthis->actionFunc = func_80A917FC;
        pthis->camId = OnePointCutscene_Init(globalCtx, 2280, -99, &pthis->actor, MAIN_CAM);
    }
}

void func_80A917FC(EnKakasi3* pthis, GlobalContext* globalCtx) {

    if (globalCtx->msgCtx.ocarinaMode != OCARINA_MODE_0F) {
        func_80A90EBC(pthis, globalCtx, 1);
    } else {
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
        Message_CloseTextbox(globalCtx);
        OnePointCutscene_EndCutscene(globalCtx, pthis->camId);
        pthis->actionFunc = func_80A911F0;
    }
}

void func_80A9187C(EnKakasi3* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        func_8010BD58(globalCtx, OCARINA_ACTION_CHECK_SCARECROW);
        pthis->actionFunc = func_80A918E4;
    }
}

void func_80A918E4(EnKakasi3* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (BREG(3) != 0) {
        // "No way!"
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ まさか！ ☆☆☆☆☆ %d\n" VT_RST, globalCtx->msgCtx.ocarinaMode);
    }
    if ((globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04 ||
         (globalCtx->msgCtx.ocarinaMode >= OCARINA_MODE_05 && globalCtx->msgCtx.ocarinaMode < OCARINA_MODE_0B)) &&
        globalCtx->msgCtx.msgMode == MSGMODE_NONE) {

        Message_StartTextbox(globalCtx, 0x40A6, NULL);
        pthis->dialogState = TEXT_STATE_EVENT;
        OnePointCutscene_EndCutscene(globalCtx, pthis->camId);
        pthis->camId = SUBCAM_NONE;
        func_8002DF54(globalCtx, NULL, 8);
        pthis->actionFunc = func_80A91A90;
        return;
    }

    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03 && globalCtx->msgCtx.msgMode == MSGMODE_NONE) {
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
        if (BREG(3) != 0) {
            osSyncPrintf("\n\n");
            // "With pthis, other guys are OK! That's it!"
            osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ これで、他の奴もＯＫ！だ！ ☆☆☆☆☆ %d\n" VT_RST,
                         globalCtx->msgCtx.ocarinaMode);
        }
        pthis->unk_195 = true;
        Message_StartTextbox(globalCtx, 0x40A7, NULL);
        pthis->dialogState = TEXT_STATE_EVENT;
        func_8002DF54(globalCtx, NULL, 8);
        pthis->actionFunc = func_80A91A90;
        return;
    }

    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_01) {
        func_80A90EBC(pthis, globalCtx, 0);
        player->stateFlags2 |= 0x800000;
    }
}

void func_80A91A90(EnKakasi3* pthis, GlobalContext* globalCtx) {
    func_80A90E28(pthis);
    SkelAnime_Update(&pthis->skelAnime);
    func_8002DF54(globalCtx, NULL, 8);

    if (pthis->dialogState == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx)) {
        if (pthis->unk_195) {
            if (!(gSaveContext.eventChkInf[9] & 0x1000)) {
                gSaveContext.eventChkInf[9] |= 0x1000;
            }
        }
        if (globalCtx->cameraPtrs[pthis->camId] == NULL) {
            pthis->camId = SUBCAM_NONE;
        }
        if (pthis->camId != SUBCAM_NONE) {
            func_8005B1A4(globalCtx->cameraPtrs[pthis->camId]);
        }
        Message_CloseTextbox(globalCtx);
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
        func_8002DF54(globalCtx, NULL, 7);
        pthis->actionFunc = func_80A911F0;
    }
}

void EnKakasi3_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi3* pthis = (EnKakasi3*)thisx;
    s32 pad;
    s32 i;

    if (BREG(2) != 0) {
        osSyncPrintf("\n\n");
        // "flag!"
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ フラグ！ ☆☆☆☆☆ %d\n" VT_RST, gSaveContext.scarecrowSpawnSongSet);
    }

    pthis->unk_198++;
    pthis->actor.world.rot = pthis->actor.shape.rot;
    for (i = 0; i < ARRAY_COUNT(pthis->unk_19C); i++) {
        if (pthis->unk_19C[i] != 0) {
            pthis->unk_19C[i]--;
        }
    }

    Actor_SetFocus(&pthis->actor, 60.0f);
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 28);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnKakasi3_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi3* pthis = (EnKakasi3*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, pthis);
}

void EnKakasi3_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 20, 70, 0, { 0, 0, 0 } },
    };

    En_Kakasi3_InitVars = {
        ACTOR_EN_KAKASI3,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_KA,
        sizeof(EnKakasi3),
        (ActorFunc)EnKakasi3_Init,
        (ActorFunc)EnKakasi3_Destroy,
        (ActorFunc)EnKakasi3_Update,
        (ActorFunc)EnKakasi3_Draw,
        (ActorFunc)EnKakasi3_Reset,
    };

}
