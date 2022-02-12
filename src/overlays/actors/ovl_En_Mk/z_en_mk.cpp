#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MK_Z_EN_MK_C
#include "actor_common.h"
/*
 * File: z_en_mk.c
 * Overlay: ovl_En_Mk
 * Description: Lakeside Professor
 */

#include "z_en_mk.h"
#include "objects/object_mk/object_mk.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnMk_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMk_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMk_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMk_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnMk_Wait(EnMk* pthis, GlobalContext* globalCtx);

ActorInit En_Mk_InitVars = {
    ACTOR_EN_MK,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MK,
    sizeof(EnMk),
    (ActorFunc)EnMk_Init,
    (ActorFunc)EnMk_Destroy,
    (ActorFunc)EnMk_Update,
    (ActorFunc)EnMk_Draw,
};

static ColliderCylinderInit sCylinderInit = {
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

void EnMk_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMk* pthis = (EnMk*)thisx;
    s32 swimFlag;

    pthis->actor.minVelocityY = -4.0f;
    pthis->actor.gravity = -1.0f;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 36.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_mk_Skel_005DF0, &object_mk_Anim_000D88, pthis->jointTable,
                       pthis->morphTable, 13);
    Animation_PlayLoop(&pthis->skelAnime, &object_mk_Anim_000D88);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.colChkInfo.mass = 0xFF;
    Actor_SetScale(&pthis->actor, 0.01f);

    pthis->actionFunc = EnMk_Wait;
    pthis->flags = 0;
    pthis->swimFlag = 0;
    pthis->actor.targetMode = 6;

    if (gSaveContext.itemGetInf[1] & 1) {
        pthis->flags |= 4;
    }
}

void EnMk_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMk* pthis = (EnMk*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AACA40(EnMk* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        pthis->actionFunc = EnMk_Wait;
    }

    pthis->flags |= 1;
}

void func_80AACA94(EnMk* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx) != 0) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = func_80AACA40;
        func_80088AA0(240);
        gSaveContext.eventInf[1] &= ~1;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_EYEDROPS, 10000.0f, 50.0f);
    }
}

void func_80AACB14(EnMk* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_80AACA94;
        func_8002F434(&pthis->actor, globalCtx, GI_EYEDROPS, 10000.0f, 50.0f);
    }
}

void func_80AACB6C(EnMk* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_80AACB14;
    }

    pthis->flags |= 1;
}

void func_80AACBAC(EnMk* pthis, GlobalContext* globalCtx) {
    if (pthis->timer > 0) {
        pthis->timer--;
        pthis->actor.shape.rot.y -= 0x800;
    } else {
        pthis->actionFunc = func_80AACB6C;
        Message_ContinueTextbox(globalCtx, 0x4030);
    }
}

void func_80AACC04(EnMk* pthis, GlobalContext* globalCtx) {
    if (pthis->timer > 0) {
        pthis->timer--;
    } else {
        pthis->timer = 16;
        pthis->actionFunc = func_80AACBAC;
        Animation_Change(&pthis->skelAnime, &object_mk_Anim_000D88, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_mk_Anim_000D88), ANIMMODE_LOOP, -4.0f);
        pthis->flags &= ~2;
    }
}

void func_80AACCA0(EnMk* pthis, GlobalContext* globalCtx) {
    if (pthis->timer > 0) {
        pthis->timer--;
        pthis->actor.shape.rot.y += 0x800;
    } else {
        pthis->timer = 120;
        pthis->actionFunc = func_80AACC04;
        Animation_Change(&pthis->skelAnime, &object_mk_Anim_000724, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_mk_Anim_000724), ANIMMODE_LOOP, -4.0f);
        pthis->flags &= ~2;
    }
}

void func_80AACD48(EnMk* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = func_80AACCA0;
        globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
        player->exchangeItemId = EXCH_ITEM_NONE;
        pthis->timer = 16;
        Animation_Change(&pthis->skelAnime, &object_mk_Anim_000D88, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_mk_Anim_000D88), ANIMMODE_LOOP, -4.0f);
        pthis->flags &= ~2;
    }

    pthis->flags |= 1;
}

void func_80AACE2C(EnMk* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x4001);
        Animation_Change(&pthis->skelAnime, &object_mk_Anim_000AC0, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_mk_Anim_000AC0), ANIMMODE_ONCE, -4.0f);
        pthis->flags &= ~2;
        pthis->actionFunc = func_80AACD48;
    }

    pthis->flags |= 1;
}

void func_80AACEE8(EnMk* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x4000);
        Animation_Change(&pthis->skelAnime, &object_mk_Anim_000AC0, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_mk_Anim_000AC0), ANIMMODE_LOOP, -4.0f);
        pthis->flags &= ~2;
        pthis->actionFunc = func_80AACE2C;
    }

    pthis->flags |= 1;
}

void func_80AACFA0(EnMk* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = func_80AACA40;
        gSaveContext.itemGetInf[1] |= 1;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_HEART_PIECE, 10000.0f, 50.0f);
    }
}

void func_80AAD014(EnMk* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_80AACFA0;
        func_8002F434(&pthis->actor, globalCtx, GI_HEART_PIECE, 10000.0f, 50.0f);
    }

    pthis->flags |= 1;
}

void EnMk_Wait(EnMk* pthis, GlobalContext* globalCtx) {
    s16 angle;
    s32 swimFlag;
    Player* player = GET_PLAYER(globalCtx);
    s32 playerExchangeItem;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        playerExchangeItem = func_8002F368(globalCtx);

        if (pthis->actor.textId != 0x4018) {
            player->actor.textId = pthis->actor.textId;
            pthis->actionFunc = func_80AACA40;
        } else {
            if (INV_CONTENT(ITEM_ODD_MUSHROOM) == ITEM_EYEDROPS) {
                player->actor.textId = 0x4032;
                pthis->actionFunc = func_80AACA40;
            } else {
                switch (playerExchangeItem) {
                    case EXCH_ITEM_NONE:
                        if (pthis->swimFlag >= 8) {
                            if (gSaveContext.itemGetInf[1] & 1) {
                                player->actor.textId = 0x4075;
                                pthis->actionFunc = func_80AACA40;
                            } else {
                                player->actor.textId = 0x4074;
                                pthis->actionFunc = func_80AAD014;
                                pthis->swimFlag = 0;
                            }
                        } else {
                            if (pthis->swimFlag == 0) {
                                player->actor.textId = 0x4018;
                                pthis->actionFunc = func_80AACA40;
                            } else {
                                player->actor.textId = 0x406C + pthis->swimFlag;
                                pthis->actionFunc = func_80AACA40;
                            }
                        }
                        break;
                    case EXCH_ITEM_FROG:
                        player->actor.textId = 0x4019;
                        pthis->actionFunc = func_80AACEE8;
                        Animation_Change(&pthis->skelAnime, &object_mk_Anim_000368, 1.0f, 0.0f,
                                         Animation_GetLastFrame(&object_mk_Anim_000368), ANIMMODE_ONCE, -4.0f);
                        pthis->flags &= ~2;
                        gSaveContext.timer2State = 0;
                        func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
                        break;
                    default:
                        player->actor.textId = 0x4018;
                        pthis->actionFunc = func_80AACA40;
                        break;
                }
            }
        }
    } else {
        pthis->actor.textId = Text_GetFaceReaction(globalCtx, 0x1A);

        if (pthis->actor.textId == 0) {
            pthis->actor.textId = 0x4018;
        }

        angle = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

        if ((ABS(angle) < 0x2151) && (pthis->actor.xzDistToPlayer < 100.0f)) {
            func_8002F298(&pthis->actor, globalCtx, 100.0f, EXCH_ITEM_FROG);
            pthis->flags |= 1;
        }
    }
}

void EnMk_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMk* pthis = (EnMk*)thisx;
    s32 pad;
    Vec3s vec;
    Player* player;
    s16 swimFlag;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);

    if ((!(pthis->flags & 2)) && (SkelAnime_Update(&pthis->skelAnime))) {
        pthis->flags |= 2;
    }

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->flags & 1) {
        func_80038290(globalCtx, &pthis->actor, &pthis->headRotation, &vec, pthis->actor.focus.pos);
    } else {
        Math_SmoothStepToS(&pthis->headRotation.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->headRotation.y, 0, 6, 6200, 100);
    }

    player = GET_PLAYER(globalCtx);

    if (pthis->flags & 8) {
        if (!(player->stateFlags2 & 0x400)) {
            pthis->flags &= ~8;
        }
    } else {
        if (player->currentBoots == PLAYER_BOOTS_IRON) {
            pthis->flags |= 8;
        } else if (player->stateFlags2 & 0x400) {
            swimFlag = player->actor.yDistToWater;

            if (swimFlag > 0) {
                if (swimFlag >= 320) {
                    if (swimFlag >= 355) {
                        swimFlag = 8;
                    } else {
                        swimFlag = 7;
                    }
                } else if (swimFlag < 80) {
                    swimFlag = 1;
                } else {
                    swimFlag *= 0.025f;
                }

                if (pthis->swimFlag < swimFlag) {
                    pthis->swimFlag = swimFlag;

                    if ((!(pthis->flags & 4)) && (pthis->swimFlag >= 8)) {
                        pthis->flags |= 4;
                        func_80078884(NA_SE_SY_CORRECT_CHIME);
                    }
                }
            }
        }
    }
}

s32 EnMk_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnMk* pthis = (EnMk*)thisx;

    if (limbIndex == 11) {
        rot->y -= pthis->headRotation.y;
        rot->z += pthis->headRotation.x;
    }

    return false;
}

void EnMk_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    static Vec3f D_80AAD64C = { 1000.0f, -100.0f, 0.0f };
    EnMk* pthis = (EnMk*)thisx;

    if (limbIndex == 11) {
        Matrix_MultVec3f(&D_80AAD64C, &pthis->actor.focus.pos);
    }
}

void EnMk_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnMk* pthis = (EnMk*)thisx;

    func_800943C8(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnMk_OverrideLimbDraw, EnMk_PostLimbDraw, &pthis->actor);
}
