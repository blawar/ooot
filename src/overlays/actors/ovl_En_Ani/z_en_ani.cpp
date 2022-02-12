#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ANI_Z_EN_ANI_C
#include "actor_common.h"
/*
 * File: z_en_ani.c
 * Overlay: ovl_En_Ani
 * Description: Kakariko Roof Guy
 */

#include "z_en_ani.h"
#include "objects/object_ani/object_ani.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnAni_Init(Actor* thisx, GlobalContext* globalCtx);
void EnAni_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnAni_Update(Actor* thisx, GlobalContext* globalCtx);
void EnAni_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 EnAni_SetText(EnAni* pthis, GlobalContext* globalCtx, u16 textId);
void func_809B04F0(EnAni* pthis, GlobalContext* globalCtx);
void func_809B0524(EnAni* pthis, GlobalContext* globalCtx);
void func_809B0558(EnAni* pthis, GlobalContext* globalCtx);
void func_809B05F0(EnAni* pthis, GlobalContext* globalCtx);
void func_809B064C(EnAni* pthis, GlobalContext* globalCtx);
void func_809B07F8(EnAni* pthis, GlobalContext* globalCtx);
void func_809B0988(EnAni* pthis, GlobalContext* globalCtx);
void func_809B0994(EnAni* pthis, GlobalContext* globalCtx);
void func_809B0A28(EnAni* pthis, GlobalContext* globalCtx);
void func_809B0A6C(EnAni* pthis, GlobalContext* globalCtx);

ActorInit En_Ani_InitVars = {
    ACTOR_EN_ANI,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ANI,
    sizeof(EnAni),
    (ActorFunc)EnAni_Init,
    (ActorFunc)EnAni_Destroy,
    (ActorFunc)EnAni_Update,
    (ActorFunc)EnAni_Draw,
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
    { 30, 40, 0, { 0 } },
};

void EnAni_SetupAction(EnAni* pthis, EnAniActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 850, ICHAIN_STOP),
};

void EnAni_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnAni* pthis = (EnAni*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, -2800.0f, ActorShadow_DrawCircle, 36.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gRoofManSkel, &gRoofManIdleAnim, pthis->jointTable,
                       pthis->morphTable, 0x10);
    Animation_PlayOnce(&pthis->skelAnime, &gRoofManIdleAnim);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    if (!LINK_IS_ADULT) {
        EnAni_SetupAction(pthis, func_809B064C);
    } else {
        EnAni_SetupAction(pthis, func_809B07F8);
    }
    pthis->unk_2AA = 0;
    pthis->unk_2A8 = 0;
    pthis->actor.minVelocityY = -1.0f;
    pthis->actor.velocity.y = -1.0f;
}

void EnAni_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnAni* pthis = (EnAni*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 EnAni_SetText(EnAni* pthis, GlobalContext* globalCtx, u16 textId) {
    pthis->actor.textId = textId;
    pthis->unk_2A8 |= 1;
    func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
    return 0;
}

void func_809B04F0(EnAni* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        EnAni_SetupAction(pthis, func_809B064C);
    }
}

void func_809B0524(EnAni* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        EnAni_SetupAction(pthis, func_809B07F8);
    }
}

void func_809B0558(EnAni* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        if (!LINK_IS_ADULT) {
            EnAni_SetupAction(pthis, func_809B04F0);
        } else {
            EnAni_SetupAction(pthis, func_809B0524);
        }
        gSaveContext.itemGetInf[1] |= 0x20;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_HEART_PIECE, 10000.0f, 200.0f);
    }
}

void func_809B05F0(EnAni* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        EnAni_SetupAction(pthis, func_809B0558);
    }
    func_8002F434(&pthis->actor, globalCtx, GI_HEART_PIECE, 10000.0f, 200.0f);
}

void func_809B064C(EnAni* pthis, GlobalContext* globalCtx) {
    u16 textId;
    s16 yawDiff;
    u16 textId2;

    textId2 = Text_GetFaceReaction(globalCtx, 0xA);
    textId = textId2 & 0xFFFF;

    if (!textId) {}

    if (textId2 == 0) {
        textId = !IS_DAY ? 0x5051 : 0x5050;
    }

    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (pthis->actor.textId == 0x5056) {
            EnAni_SetupAction(pthis, func_809B04F0);
        } else if (pthis->actor.textId == 0x5055) {
            EnAni_SetupAction(pthis, func_809B05F0);
        } else {
            EnAni_SetupAction(pthis, func_809B04F0);
        }
    } else if (yawDiff >= -0x36AF && yawDiff < 0 && pthis->actor.xzDistToPlayer < 150.0f &&
               -80.0f < pthis->actor.yDistToPlayer) {
        if (gSaveContext.itemGetInf[1] & 0x20) {
            EnAni_SetText(pthis, globalCtx, 0x5056);
        } else {
            EnAni_SetText(pthis, globalCtx, 0x5055);
        }
    } else if (yawDiff >= -0x3E7 && yawDiff < 0x36B0 && pthis->actor.xzDistToPlayer < 350.0f) {
        EnAni_SetText(pthis, globalCtx, textId);
    }
}

void func_809B07F8(EnAni* pthis, GlobalContext* globalCtx) {
    s16 pad;
    s16 yawDiff;
    u16 textId;

    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (pthis->actor.textId == 0x5056) {
            EnAni_SetupAction(pthis, func_809B0524);
        } else if (pthis->actor.textId == 0x5055) {
            EnAni_SetupAction(pthis, func_809B05F0);
        } else {
            EnAni_SetupAction(pthis, func_809B0524);
        }
    } else if (yawDiff > -0x36B0 && yawDiff < 0 && pthis->actor.xzDistToPlayer < 150.0f &&
               -80.0f < pthis->actor.yDistToPlayer) {
        if (gSaveContext.itemGetInf[1] & 0x20) {
            EnAni_SetText(pthis, globalCtx, 0x5056);
        } else {
            EnAni_SetText(pthis, globalCtx, 0x5055);
        }
    } else if (yawDiff > -0x3E8 && yawDiff < 0x36B0 && pthis->actor.xzDistToPlayer < 350.0f) {
        if (!(gSaveContext.eventChkInf[2] & 0x8000)) {
            textId = 0x5052;
        } else {
            textId = (gSaveContext.itemGetInf[1] & 0x20) ? 0x5054 : 0x5053;
        }
        EnAni_SetText(pthis, globalCtx, textId);
    }
}

void func_809B0988(EnAni* pthis, GlobalContext* globalCtx) {
}

void func_809B0994(EnAni* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.npcActions[0]->action == 4) {
        Animation_Change(&pthis->skelAnime, &gRoofManGettingUpAfterKnockbackAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gRoofManGettingUpAfterKnockbackAnim), ANIMMODE_ONCE, -4.0f);
        pthis->unk_2AA++;
        pthis->actor.shape.shadowDraw = ActorShadow_DrawCircle;
    }
}

void func_809B0A28(EnAni* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->unk_2AA++;
    }
}

void func_809B0A6C(EnAni* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->skelAnime.curFrame = 0.0f;
    }
    if (globalCtx->csCtx.npcActions[0]->action == 2) {
        Animation_Change(&pthis->skelAnime, &gRoofManKnockbackAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gRoofManKnockbackAnim), ANIMMODE_ONCE, 0.0f);
        pthis->actor.shape.shadowDraw = NULL;
        pthis->unk_2AA++;
    }
}

void EnAni_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnAni* pthis = (EnAni*)thisx;
    s32 pad[2];

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    if ((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[0] != NULL)) {
        switch (pthis->unk_2AA) {
            case 0:
                func_809B0A6C(pthis, globalCtx);
                break;
            case 1:
                func_809B0A28(pthis, globalCtx);
                break;
            case 2:
                func_809B0994(pthis, globalCtx);
                break;
            case 3:
                func_809B0A28(pthis, globalCtx);
                break;
            case 4:
                func_809B0988(pthis, globalCtx);
                break;
        }

        if (globalCtx->csCtx.frames == 100) {
            func_800788CC(NA_SE_IT_EARTHQUAKE);
        }
    } else {
        if (SkelAnime_Update(&pthis->skelAnime) != 0) {
            pthis->skelAnime.curFrame = 0.0f;
        }
        pthis->actionFunc(pthis, globalCtx);
    }

    if (pthis->unk_2A8 & 1) {
        func_80038290(globalCtx, &pthis->actor, &pthis->unk_29C, &pthis->unk_2A2, pthis->actor.focus.pos);
        pthis->unk_2A2.z = 0;
        pthis->unk_2A2.y = pthis->unk_2A2.z;
        pthis->unk_2A2.x = pthis->unk_2A2.z;
    } else {
        Math_SmoothStepToS(&pthis->unk_29C.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_29C.y, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_2A2.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_2A2.y, 0, 6, 6200, 100);
    }

    if (DECR(pthis->blinkTimer) == 0) {
        pthis->blinkTimer = Rand_S16Offset(60, 60);
    }
    pthis->eyeIndex = pthis->blinkTimer;
    if (pthis->eyeIndex >= 3) {
        pthis->eyeIndex = 0;
    }
}

s32 EnAni_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnAni* pthis = (EnAni*)thisx;

    if (limbIndex == 15) {
        rot->x += pthis->unk_29C.y;
        rot->z += pthis->unk_29C.x;
    }
    return false;
}

void EnAni_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    static Vec3f sMultVec = { 800.0f, 500.0f, 0.0f };
    EnAni* pthis = (EnAni*)thisx;

    if (limbIndex == 15) {
        Matrix_MultVec3f(&sMultVec, &pthis->actor.focus.pos);
    }
}

void EnAni_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* eyeTextures[] = {
        gRoofManEyeOpenTex,
        gRoofManEyeHalfTex,
        gRoofManEyeClosedTex,
    };
    EnAni* pthis = (EnAni*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ani.c", 719);

    func_800943C8(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->eyeIndex]));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnAni_OverrideLimbDraw, EnAni_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ani.c", 736);
}
