#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HS_Z_EN_HS_C
#include "actor_common.h"
/*
 * File: z_en_hs.c
 * Overlay: ovl_En_Hs
 * Description: Carpenter's Son
 */

#include "z_en_hs.h"
#include "vt.h"
#include "objects/object_hs/object_hs.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnHs_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHs_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHs_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHs_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A6E9AC(EnHs* pthis, GlobalContext* globalCtx);
void func_80A6E6B0(EnHs* pthis, GlobalContext* globalCtx);

ActorInit En_Hs_InitVars = {
    ACTOR_EN_HS,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_HS,
    sizeof(EnHs),
    (ActorFunc)EnHs_Init,
    (ActorFunc)EnHs_Destroy,
    (ActorFunc)EnHs_Update,
    (ActorFunc)EnHs_Draw,
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
    { 40, 40, 0, { 0, 0, 0 } },
};

void func_80A6E3A0(EnHs* pthis, EnHsActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnHs_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHs* pthis = (EnHs*)thisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 36.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_hs_Skel_006260, &object_hs_Anim_0005C0, pthis->jointTable,
                       pthis->morphTable, 16);
    Animation_PlayLoop(&pthis->skelAnime, &object_hs_Anim_0005C0);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    Actor_SetScale(&pthis->actor, 0.01f);

    if (!LINK_IS_ADULT) {
        pthis->actor.params = 0;
    } else {
        pthis->actor.params = 1;
    }

    if (pthis->actor.params == 1) {
        // "chicken shop (adult era)"
        osSyncPrintf(VT_FGCOL(CYAN) " ヒヨコの店(大人の時) \n" VT_RST);
        func_80A6E3A0(pthis, func_80A6E9AC);
        if (gSaveContext.itemGetInf[3] & 1) {
            // "chicken shop closed"
            osSyncPrintf(VT_FGCOL(CYAN) " ヒヨコ屋閉店 \n" VT_RST);
            Actor_Kill(&pthis->actor);
        }
    } else {
        // "chicken shop (child era)"
        osSyncPrintf(VT_FGCOL(CYAN) " ヒヨコの店(子人の時) \n" VT_RST);
        func_80A6E3A0(pthis, func_80A6E9AC);
    }

    pthis->unk_2A8 = 0;
    pthis->actor.targetMode = 6;
}

void EnHs_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHs* pthis = (EnHs*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 func_80A6E53C(EnHs* pthis, GlobalContext* globalCtx, u16 textId, EnHsActionFunc actionFunc) {
    s16 yawDiff;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        func_80A6E3A0(pthis, actionFunc);
        return 1;
    }

    pthis->actor.textId = textId;
    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    if ((ABS(yawDiff) <= 0x2150) && (pthis->actor.xzDistToPlayer < 100.0f)) {
        pthis->unk_2A8 |= 1;
        func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
    }

    return 0;
}

void func_80A6E5EC(EnHs* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        func_80A6E3A0(pthis, func_80A6E6B0);
    }

    pthis->unk_2A8 |= 1;
}

void func_80A6E630(EnHs* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        func_80088AA0(180);
        func_80A6E3A0(pthis, func_80A6E6B0);
        gSaveContext.eventInf[1] &= ~1;
    }

    pthis->unk_2A8 |= 1;
}

void func_80A6E6B0(EnHs* pthis, GlobalContext* globalCtx) {
    func_80A6E53C(pthis, globalCtx, 0x10B6, func_80A6E5EC);
}

void func_80A6E6D8(EnHs* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        func_80A6E3A0(pthis, func_80A6E9AC);
    }
}

void func_80A6E70C(EnHs* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        func_80A6E3A0(pthis, func_80A6E9AC);
    }
}

void func_80A6E740(EnHs* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        func_80A6E3A0(pthis, func_80A6E630);
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_ODD_MUSHROOM, 10000.0f, 50.0f);
    }

    pthis->unk_2A8 |= 1;
}

void func_80A6E7BC(EnHs* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0:
                func_80A6E3A0(pthis, func_80A6E740);
                func_8002F434(&pthis->actor, globalCtx, GI_ODD_MUSHROOM, 10000.0f, 50.0f);
                break;
            case 1:
                Message_ContinueTextbox(globalCtx, 0x10B4);
                func_80A6E3A0(pthis, func_80A6E70C);
                break;
        }

        Animation_Change(&pthis->skelAnime, &object_hs_Anim_0005C0, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_hs_Anim_0005C0), ANIMMODE_LOOP, 8.0f);
    }

    pthis->unk_2A8 |= 1;
}

void func_80A6E8CC(EnHs* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x10B3);
        func_80A6E3A0(pthis, func_80A6E7BC);
        Animation_Change(&pthis->skelAnime, &object_hs_Anim_000528, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_hs_Anim_000528), ANIMMODE_LOOP, 8.0f);
    }

    if (pthis->unk_2AA > 0) {
        pthis->unk_2AA--;
        if (pthis->unk_2AA == 0) {
            func_8002F7DC(&player->actor, NA_SE_EV_CHICKEN_CRY_M);
        }
    }

    pthis->unk_2A8 |= 1;
}

void func_80A6E9AC(EnHs* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 yawDiff;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (func_8002F368(globalCtx) == 7) {
            player->actor.textId = 0x10B2;
            func_80A6E3A0(pthis, func_80A6E8CC);
            Animation_Change(&pthis->skelAnime, &object_hs_Anim_000304, 1.0f, 0.0f,
                             Animation_GetLastFrame(&object_hs_Anim_000304), ANIMMODE_LOOP, 8.0f);
            pthis->unk_2AA = 40;
            func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
        } else {
            player->actor.textId = 0x10B1;
            func_80A6E3A0(pthis, func_80A6E6D8);
        }
    } else {
        yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
        pthis->actor.textId = 0x10B1;
        if ((ABS(yawDiff) <= 0x2150) && (pthis->actor.xzDistToPlayer < 100.0f)) {
            func_8002F298(&pthis->actor, globalCtx, 100.0f, 7);
        }
    }
}

void EnHs_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHs* pthis = (EnHs*)thisx;
    s32 pad;

    Collider_UpdateCylinder(thisx, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->skelAnime.curFrame = 0.0f;
    }

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->unk_2A8 & 1) {
        func_80038290(globalCtx, &pthis->actor, &pthis->unk_29C, &pthis->unk_2A2, pthis->actor.focus.pos);
        pthis->unk_2A8 &= ~1;
    } else {
        Math_SmoothStepToS(&pthis->unk_29C.x, 12800, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_29C.y, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_2A2.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_2A2.y, 0, 6, 6200, 100);
    }
}

s32 EnHs_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnHs* pthis = (EnHs*)thisx;

    switch (limbIndex) {
        case 9:
            rot->x += pthis->unk_29C.y;
            rot->z += pthis->unk_29C.x;
            break;
        case 10:
            *dList = NULL;
            return false;
        case 11:
            *dList = NULL;
            return false;
        case 12:
            if (pthis->actor.params == 1) {
                *dList = NULL;
                return false;
            }
            break;
        case 13:
            if (pthis->actor.params == 1) {
                *dList = NULL;
                return false;
            }
            break;
    }
    return false;
}

void EnHs_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    static Vec3f D_80A6EDFC = { 300.0f, 1000.0f, 0.0f };
    EnHs* pthis = (EnHs*)thisx;

    if (limbIndex == 9) {
        Matrix_MultVec3f(&D_80A6EDFC, &pthis->actor.focus.pos);
    }
}

void EnHs_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHs* pthis = (EnHs*)thisx;

    func_800943C8(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnHs_OverrideLimbDraw, EnHs_PostLimbDraw, pthis);
}
