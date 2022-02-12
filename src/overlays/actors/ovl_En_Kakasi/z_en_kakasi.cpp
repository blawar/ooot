#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_KAKASI_Z_EN_KAKASI_C
#include "actor_common.h"
/*
 * File: z_en_kakasi.c
 * Overlay: ovl_En_Kakasi
 * Description: Pierre the Scarecrow
 */

#include "z_en_kakasi.h"
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

void EnKakasi_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKakasi_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKakasi_Update(Actor* thisx, GlobalContext* globalCtx);
void EnKakasi_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A8F660(EnKakasi* pthis, GlobalContext* globalCtx);
void func_80A8F75C(EnKakasi* pthis, GlobalContext* globalCtx);
void func_80A8F8D0(EnKakasi* pthis, GlobalContext* globalCtx);
void func_80A8F9C8(EnKakasi* pthis, GlobalContext* globalCtx);
void func_80A8FBB8(EnKakasi* pthis, GlobalContext* globalCtx);
void func_80A8FAA4(EnKakasi* pthis, GlobalContext* globalCtx);

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
        TOUCH_NONE,
        BUMP_NONE | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 20, 70, 0, { 0, 0, 0 } },
};

ActorInit En_Kakasi_InitVars = {
    ACTOR_EN_KAKASI,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_KA,
    sizeof(EnKakasi),
    (ActorFunc)EnKakasi_Init,
    (ActorFunc)EnKakasi_Destroy,
    (ActorFunc)EnKakasi_Update,
    (ActorFunc)EnKakasi_Draw,
};

void EnKakasi_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi* pthis = (EnKakasi*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
    //! @bug SkelAnime_Free is not called
}

void EnKakasi_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi* pthis = (EnKakasi*)thisx;

    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ Ｌｅｔ’ｓ ＤＡＮＣＥ！ ☆☆☆☆☆ %f\n" VT_RST, pthis->actor.world.pos.y);

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.targetMode = 6;
    SkelAnime_InitFlex(globalCtx, &pthis->skelanime, &object_ka_Skel_0065B0, &object_ka_Anim_000214, NULL, NULL, 0);

    pthis->rot = pthis->actor.world.rot;
    pthis->actor.flags |= ACTOR_FLAG_10;
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;

    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actionFunc = func_80A8F660;
}

void func_80A8F28C(EnKakasi* pthis) {
    pthis->unk_1A4 = 0;
    pthis->skelanime.playSpeed = 0.0f;
    pthis->unk_1A8 = pthis->unk_1AC = 0;

    Math_ApproachZeroF(&pthis->skelanime.curFrame, 0.5f, 1.0f);
    Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->rot.x, 5, 0x2710, 0);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->rot.y, 5, 0x2710, 0);
    Math_SmoothStepToS(&pthis->actor.shape.rot.z, pthis->rot.z, 5, 0x2710, 0);
}

void func_80A8F320(EnKakasi* pthis, GlobalContext* globalCtx, s16 arg) {
    s16 ocarinaNote = globalCtx->msgCtx.lastOcaNoteIdx;
    s16 currentFrame;

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
            if (pthis->unk_1AC == 0) {
                pthis->unk_1AC = 0x1388;
            }
            break;
        case OCARINA_NOTE_C_LEFT:
            pthis->unk_19A++;
            if (pthis->unk_1A8 == 0) {
                pthis->unk_1A8 = 0x1388;
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
        Math_ApproachF(&pthis->skelanime.playSpeed, pthis->unk_1B8, 0.1f, 0.2f);
        Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->unk_1A8, 5, 0x3E8, 0);
        Math_SmoothStepToS(&pthis->actor.shape.rot.z, pthis->unk_1AC, 5, 0x3E8, 0);

        if (pthis->unk_1A8 != 0 && fabsf(pthis->actor.shape.rot.x - pthis->unk_1A8) < 50.0f) {
            pthis->unk_1A8 *= -1.0f;
        }
        if (pthis->unk_1AC != 0 && fabsf(pthis->actor.shape.rot.z - pthis->unk_1AC) < 50.0f) {
            pthis->unk_1AC *= -1.0f;
        }

        if (pthis->unk_1A4 != 0) {
            pthis->actor.shape.rot.y += 0x1000;
            if (pthis->actor.shape.rot.y == 0) {
                pthis->unk_1A4 = 0;
            }
        }
        currentFrame = pthis->skelanime.curFrame;
        if (currentFrame == 11 || currentFrame == 17) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_KAKASHI_SWING);
        }
        SkelAnime_Update(&pthis->skelanime);
    }
}

void func_80A8F660(EnKakasi* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&object_ka_Anim_000214);

    Animation_Change(&pthis->skelanime, &object_ka_Anim_000214, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);

    pthis->actor.textId = 0x4076;
    pthis->unk_196 = TEXT_STATE_DONE;
    if (!LINK_IS_ADULT) {
        pthis->unk_194 = false;
        if (gSaveContext.scarecrowCustomSongSet) {
            pthis->actor.textId = 0x407A;
            pthis->unk_196 = TEXT_STATE_EVENT;
        }
    } else {
        pthis->unk_194 = true;
        if (gSaveContext.scarecrowCustomSongSet) {
            pthis->actor.textId = 0x4079;
            pthis->unk_196 = TEXT_STATE_EVENT;
        }
    }
    pthis->actionFunc = func_80A8F75C;
}

void func_80A8F75C(EnKakasi* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    func_80A8F28C(pthis);
    SkelAnime_Update(&pthis->skelanime);
    pthis->camId = SUBCAM_NONE;
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (pthis->unk_196 == TEXT_STATE_EVENT) {
            pthis->actionFunc = func_80A8F9C8;
        } else {
            pthis->actionFunc = func_80A8F660;
        }
    } else {
        s16 yawTowardsPlayer = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

        if (!(pthis->actor.xzDistToPlayer > 120.0f)) {
            s16 absyawTowardsPlayer = ABS(yawTowardsPlayer);

            if (absyawTowardsPlayer < 0x4300) {
                if (!pthis->unk_194) {
                    if (player->stateFlags2 & 0x1000000) {
                        pthis->camId = OnePointCutscene_Init(globalCtx, 2260, -99, &pthis->actor, MAIN_CAM);

                        func_8010BD58(globalCtx, OCARINA_ACTION_SCARECROW_LONG_RECORDING);
                        pthis->unk_19A = 0;
                        pthis->unk_1B8 = 0.0;
                        player->stateFlags2 |= 0x800000;
                        pthis->actionFunc = func_80A8F8D0;
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

void func_80A8F8D0(EnKakasi* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04 && globalCtx->msgCtx.msgMode == MSGMODE_NONE) {
        // "end?"
        osSyncPrintf(VT_FGCOL(BLUE) "☆☆☆☆☆ 終り？ ☆☆☆☆☆ \n" VT_RST);

        if (pthis->unk_19A != 0) {
            Message_CloseTextbox(globalCtx);
            pthis->actor.textId = 0x4077;
            pthis->unk_196 = TEXT_STATE_EVENT;
            Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
            pthis->actionFunc = func_80A8F9C8;
        } else {
            OnePointCutscene_EndCutscene(globalCtx, pthis->camId);
            pthis->camId = SUBCAM_NONE;
            pthis->actionFunc = func_80A8F660;
        }
    } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_01) {
        func_80A8F320(pthis, globalCtx, 0);
        player->stateFlags2 |= 0x800000;
    }
}

void func_80A8F9C8(EnKakasi* pthis, GlobalContext* globalCtx) {
    func_80A8F28C(pthis);
    SkelAnime_Update(&pthis->skelanime);
    func_8002DF54(globalCtx, NULL, 8);

    if (pthis->unk_196 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx)) {

        if (pthis->camId != SUBCAM_NONE) {
            func_8005B1A4(globalCtx->cameraPtrs[pthis->camId]);
        }
        pthis->camId = OnePointCutscene_Init(globalCtx, 2270, -99, &pthis->actor, MAIN_CAM);
        globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
        func_8002DF54(globalCtx, NULL, 8);
        func_8010BD58(globalCtx, OCARINA_ACTION_SCARECROW_LONG_PLAYBACK);
        pthis->actionFunc = func_80A8FAA4;
    }
}

void func_80A8FAA4(EnKakasi* pthis, GlobalContext* globalCtx) {
    if (globalCtx->msgCtx.ocarinaMode != OCARINA_MODE_0F) {
        func_80A8F320(pthis, globalCtx, 1);
        return;
    }

    osSyncPrintf("game_play->message.msg_mode=%d\n", globalCtx->msgCtx.msgMode);

    if (globalCtx->msgCtx.msgMode == MSGMODE_NONE) {
        if (pthis->unk_194) {
            pthis->actor.textId = 0x4077;
            pthis->unk_196 = TEXT_STATE_EVENT;
            Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
        } else {
            pthis->actor.textId = 0x4078;
            pthis->unk_196 = TEXT_STATE_EVENT;
            Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
        }
        pthis->actionFunc = func_80A8FBB8;
        OnePointCutscene_EndCutscene(globalCtx, pthis->camId);
        pthis->camId = SUBCAM_NONE;
        pthis->camId = OnePointCutscene_Init(globalCtx, 2260, -99, &pthis->actor, MAIN_CAM);
        func_8005B1A4(globalCtx->cameraPtrs[pthis->camId]);
    }
}

void func_80A8FBB8(EnKakasi* pthis, GlobalContext* globalCtx) {
    func_80A8F28C(pthis);
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->unk_196 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx)) {
        func_8005B1A4(globalCtx->cameraPtrs[pthis->camId]);
        Message_CloseTextbox(globalCtx);
        func_8002DF54(globalCtx, NULL, 7);
        pthis->actionFunc = func_80A8F660;
    }
}

void EnKakasi_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi* pthis = (EnKakasi*)thisx;
    s32 pad;
    s32 i;

    pthis->unk_198++;
    pthis->actor.world.rot = pthis->actor.shape.rot;
    for (i = 0; i < ARRAY_COUNT(pthis->unk_19C); i++) {
        if (pthis->unk_19C[i] != 0) {
            pthis->unk_19C[i]--;
        }
    }

    pthis->height = 60.0f;
    Actor_SetFocus(&pthis->actor, pthis->height);
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 28);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnKakasi_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi* pthis = (EnKakasi*)thisx;

    if (BREG(3) != 0) {
        osSyncPrintf("\n\n");
        // "flag!"
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ フラグ！ ☆☆☆☆☆ %d\n" VT_RST, gSaveContext.scarecrowCustomSongSet);
    }
    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable, pthis->skelanime.dListCount,
                          NULL, NULL, pthis);
}
