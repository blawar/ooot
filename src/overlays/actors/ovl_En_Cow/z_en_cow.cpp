#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_COW_Z_EN_COW_C
#include "actor_common.h"
/*
 * File: z_en_cow.c
 * Overlay: ovl_En_Cow
 * Description: Cow
 */

#include "z_en_cow.h"
#include "objects/object_cow/object_cow.h"
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

void EnCow_Init(Actor* thisx, GlobalContext* globalCtx);
void EnCow_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnCow_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnCow_Update(Actor* thisx, GlobalContext* globalCtx);
void EnCow_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_809DFE98(Actor* thisx, GlobalContext* globalCtx);
void func_809E0070(Actor* thisx, GlobalContext* globalCtx);

void func_809DF494(EnCow* pthis, GlobalContext* globalCtx);
void func_809DF6BC(EnCow* pthis, GlobalContext* globalCtx);
void func_809DF778(EnCow* pthis, GlobalContext* globalCtx);
void func_809DF7D8(EnCow* pthis, GlobalContext* globalCtx);
void func_809DF870(EnCow* pthis, GlobalContext* globalCtx);
void func_809DF8FC(EnCow* pthis, GlobalContext* globalCtx);
void func_809DF96C(EnCow* pthis, GlobalContext* globalCtx);
void func_809DFA84(EnCow* pthis, GlobalContext* globalCtx);

ActorInit En_Cow_InitVars = {
    ACTOR_EN_COW,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_COW,
    sizeof(EnCow),
    (ActorFunc)EnCow_Init,
    (ActorFunc)EnCow_Destroy,
    (ActorFunc)EnCow_Update,
    (ActorFunc)EnCow_Draw,
    (ActorFunc)EnCow_Reset,
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

static Vec3f D_809E010C = { 0.0f, -1300.0f, 1100.0f };

void func_809DEE00(Vec3f* vec, s16 rotY) {
    f32 xCalc;
    f32 rotCalcTemp;

    rotCalcTemp = Math_CosS(rotY);
    xCalc = (Math_SinS(rotY) * vec->z) + (rotCalcTemp * vec->x);
    rotCalcTemp = Math_SinS(rotY);
    vec->z = (Math_CosS(rotY) * vec->z) + (-rotCalcTemp * vec->x);
    vec->x = xCalc;
}

void func_809DEE9C(EnCow* pthis) {
    Vec3f vec;

    vec.y = 0.0f;
    vec.x = 0.0f;
    vec.z = 30.0f;
    func_809DEE00(&vec, pthis->actor.shape.rot.y);
    pthis->colliders[0].dim.pos.x = pthis->actor.world.pos.x + vec.x;
    pthis->colliders[0].dim.pos.y = pthis->actor.world.pos.y;
    pthis->colliders[0].dim.pos.z = pthis->actor.world.pos.z + vec.z;

    vec.x = 0.0f;
    vec.y = 0.0f;
    vec.z = -20.0f;
    func_809DEE00(&vec, pthis->actor.shape.rot.y);
    pthis->colliders[1].dim.pos.x = pthis->actor.world.pos.x + vec.x;
    pthis->colliders[1].dim.pos.y = pthis->actor.world.pos.y;
    pthis->colliders[1].dim.pos.z = pthis->actor.world.pos.z + vec.z;
}

void func_809DEF94(EnCow* pthis) {
    Vec3f vec;

    VEC_SET(vec, 0.0f, 57.0f, -36.0f);

    func_809DEE00(&vec, pthis->actor.shape.rot.y);
    pthis->actor.world.pos.x += vec.x;
    pthis->actor.world.pos.y += vec.y;
    pthis->actor.world.pos.z += vec.z;
}

void EnCow_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnCow* pthis = (EnCow*)thisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 72.0f);
    switch (pthis->actor.params) {
        case 0:
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gCowBodySkel, NULL, pthis->jointTable, pthis->morphTable, 6);
            Animation_PlayLoop(&pthis->skelAnime, &gCowBodyChewAnim);
            Collider_InitCylinder(globalCtx, &pthis->colliders[0]);
            Collider_SetCylinder(globalCtx, &pthis->colliders[0], &pthis->actor, &sCylinderInit);
            Collider_InitCylinder(globalCtx, &pthis->colliders[1]);
            Collider_SetCylinder(globalCtx, &pthis->colliders[1], &pthis->actor, &sCylinderInit);
            func_809DEE9C(pthis);
            pthis->actionFunc = func_809DF96C;
            if (globalCtx->sceneNum == SCENE_LINK_HOME) {
                if (!LINK_IS_ADULT) {
                    Actor_Kill(&pthis->actor);
                    return;
                }
                if (!(gSaveContext.eventChkInf[1] & 0x4000)) {
                    Actor_Kill(&pthis->actor);
                    return;
                }
            }
            Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_COW, pthis->actor.world.pos.x,
                               pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, pthis->actor.shape.rot.y, 0, 1);
            pthis->unk_278 = Rand_ZeroFloat(1000.0f) + 40.0f;
            pthis->unk_27A = 0;
            pthis->actor.targetMode = 6;
            DREG(53) = 0;
            break;
        case 1:
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gCowTailSkel, NULL, pthis->jointTable, pthis->morphTable, 6);
            Animation_PlayLoop(&pthis->skelAnime, &gCowTailIdleAnim);
            pthis->actor.update = func_809DFE98;
            pthis->actor.draw = func_809E0070;
            pthis->actionFunc = func_809DFA84;
            func_809DEF94(pthis);
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->unk_278 = ((u32)(Rand_ZeroFloat(1000.0f)) & 0xFFFF) + 40.0f;
            break;
    }
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->unk_276 = 0;
}

void EnCow_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnCow* pthis = (EnCow*)thisx;

    if (pthis->actor.params == 0) {
        Collider_DestroyCylinder(globalCtx, &pthis->colliders[0]);
        Collider_DestroyCylinder(globalCtx, &pthis->colliders[1]);
    }
}

void func_809DF494(EnCow* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_278 > 0) {
        pthis->unk_278 -= 1;
    } else {
        pthis->unk_278 = Rand_ZeroFloat(500.0f) + 40.0f;
        Animation_Change(&pthis->skelAnime, &gCowBodyChewAnim, 1.0f, pthis->skelAnime.curFrame,
                         Animation_GetLastFrame(&gCowBodyChewAnim), ANIMMODE_ONCE, 1.0f);
    }

    if ((pthis->actor.xzDistToPlayer < 150.0f) && (!(pthis->unk_276 & 2))) {
        pthis->unk_276 |= 2;
        if (pthis->skelAnime.animation == &gCowBodyChewAnim) {
            pthis->unk_278 = 0;
        }
    }

    pthis->unk_27A += 1;
    if (pthis->unk_27A >= 0x31) {
        pthis->unk_27A = 0;
    }

    // (1.0f / 100.0f) instead of 0.01f below is necessary so 0.01f doesn't get reused mistakenly
    if (pthis->unk_27A < 0x20) {
        pthis->actor.scale.x = ((Math_SinS(pthis->unk_27A << 0xA) * (1.0f / 100.0f)) + 1.0f) * 0.01f;
    } else {
        pthis->actor.scale.x = 0.01f;
    }

    if (pthis->unk_27A >= 0x11) {
        pthis->actor.scale.y = ((Math_SinS((pthis->unk_27A << 0xA) - 0x4000) * (1.0f / 100.0f)) + 1.0f) * 0.01f;
    } else {
        pthis->actor.scale.y = 0.01f;
    }
}

void func_809DF6BC(EnCow* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = func_809DF96C;
    }
}

void func_809DF730(EnCow* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        pthis->actionFunc = func_809DF96C;
    }
}

void func_809DF778(EnCow* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = func_809DF730;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_MILK, 10000.0f, 100.0f);
    }
}

void func_809DF7D8(EnCow* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = func_809DF778;
        func_8002F434(&pthis->actor, globalCtx, GI_MILK, 10000.0f, 100.0f);
    }
}

void func_809DF870(EnCow* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        if (Inventory_HasEmptyBottle()) {
            Message_ContinueTextbox(globalCtx, 0x2007);
            pthis->actionFunc = func_809DF7D8;
        } else {
            Message_ContinueTextbox(globalCtx, 0x2013);
            pthis->actionFunc = func_809DF6BC;
        }
    }
}

void func_809DF8FC(EnCow* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_809DF870;
    } else {
        pthis->actor.flags |= ACTOR_FLAG_16;
        func_8002F2CC(&pthis->actor, globalCtx, 170.0f);
        pthis->actor.textId = 0x2006;
    }
    func_809DF494(pthis, globalCtx);
}

void func_809DF96C(EnCow* pthis, GlobalContext* globalCtx) {
    if ((globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_00) || (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04)) {
        if (DREG(53) != 0) {
            if (pthis->unk_276 & 4) {
                pthis->unk_276 &= ~0x4;
                DREG(53) = 0;
            } else {
                if ((pthis->actor.xzDistToPlayer < 150.0f) &&
                    (ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) < 0x61A8)) {
                    DREG(53) = 0;
                    pthis->actionFunc = func_809DF8FC;
                    pthis->actor.flags |= ACTOR_FLAG_16;
                    func_8002F2CC(&pthis->actor, globalCtx, 170.0f);
                    pthis->actor.textId = 0x2006;
                } else {
                    pthis->unk_276 |= 4;
                }
            }
        } else {
            pthis->unk_276 &= ~0x4;
        }
    }
    func_809DF494(pthis, globalCtx);
}

void func_809DFA84(EnCow* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_278 > 0) {
        pthis->unk_278--;
    } else {
        pthis->unk_278 = Rand_ZeroFloat(200.0f) + 40.0f;
        Animation_Change(&pthis->skelAnime, &gCowTailIdleAnim, 1.0f, pthis->skelAnime.curFrame,
                         Animation_GetLastFrame(&gCowTailIdleAnim), ANIMMODE_ONCE, 1.0f);
    }

    if ((pthis->actor.xzDistToPlayer < 150.0f) &&
        (ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) >= 0x61A9) && (!(pthis->unk_276 & 2))) {
        pthis->unk_276 |= 2;
        if (pthis->skelAnime.animation == &gCowTailIdleAnim) {
            pthis->unk_278 = 0;
        }
    }
}

void EnCow_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnCow* pthis = (EnCow*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    s16 targetX;
    s16 targetY;
    Player* player = GET_PLAYER(globalCtx);

    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliders[0].base);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliders[1].base);
    Actor_MoveForward(thisx);
    Actor_UpdateBgCheckInfo(globalCtx, thisx, 0.0f, 0.0f, 0.0f, 4);
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        if (pthis->skelAnime.animation == &gCowBodyChewAnim) {
            Audio_PlayActorSound2(thisx, NA_SE_EV_COW_CRY);
            Animation_Change(&pthis->skelAnime, &gCowBodyMoveHeadAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gCowBodyMoveHeadAnim), ANIMMODE_ONCE, 1.0f);
        } else {
            Animation_Change(&pthis->skelAnime, &gCowBodyChewAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gCowBodyChewAnim),
                             ANIMMODE_LOOP, 1.0f);
        }
    }
    pthis->actionFunc(pthis, globalCtx);
    if ((thisx->xzDistToPlayer < 150.0f) &&
        (ABS(Math_Vec3f_Yaw(&thisx->world.pos, &player->actor.world.pos)) < 0xC000)) {
        targetX = Math_Vec3f_Pitch(&thisx->focus.pos, &player->actor.focus.pos);
        targetY = Math_Vec3f_Yaw(&thisx->focus.pos, &player->actor.focus.pos) - thisx->shape.rot.y;

        if (targetX > 0x1000) {
            targetX = 0x1000;
        } else if (targetX < -0x1000) {
            targetX = -0x1000;
        }

        if (targetY > 0x2500) {
            targetY = 0x2500;
        } else if (targetY < -0x2500) {
            targetY = -0x2500;
        }

    } else {
        targetY = 0;
        targetX = 0;
    }
    Math_SmoothStepToS(&pthis->someRot.x, targetX, 0xA, 0xC8, 0xA);
    Math_SmoothStepToS(&pthis->someRot.y, targetY, 0xA, 0xC8, 0xA);
}

void func_809DFE98(Actor* thisx, GlobalContext* globalCtx) {
    EnCow* pthis = (EnCow*)thisx;
    s32 pad;

    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        if (pthis->skelAnime.animation == &gCowTailIdleAnim) {
            Animation_Change(&pthis->skelAnime, &gCowTailSwishAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gCowTailSwishAnim), ANIMMODE_ONCE, 1.0f);
        } else {
            Animation_Change(&pthis->skelAnime, &gCowTailIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gCowTailIdleAnim),
                             ANIMMODE_LOOP, 1.0f);
        }
    }
    pthis->actionFunc(pthis, globalCtx);
}

s32 EnCow_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnCow* pthis = (EnCow*)thisx;

    if (limbIndex == 2) {
        rot->y += pthis->someRot.y;
        rot->x += pthis->someRot.x;
    }
    if (limbIndex == 5) {
        *dList = NULL;
    }
    return false;
}

void EnCow_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnCow* pthis = (EnCow*)thisx;

    if (limbIndex == 2) {
        Matrix_MultVec3f(&D_809E010C, &pthis->actor.focus.pos);
    }
}

void EnCow_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnCow* pthis = (EnCow*)thisx;

    func_800943C8(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnCow_OverrideLimbDraw, EnCow_PostLimbDraw, pthis);
}

void func_809E0070(Actor* thisx, GlobalContext* globalCtx) {
    EnCow* pthis = (EnCow*)thisx;

    func_800943C8(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, pthis);
}

void EnCow_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Cow_InitVars = {
        ACTOR_EN_COW,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_COW,
        sizeof(EnCow),
        (ActorFunc)EnCow_Init,
        (ActorFunc)EnCow_Destroy,
        (ActorFunc)EnCow_Update,
        (ActorFunc)EnCow_Draw,
        (ActorFunc)EnCow_Reset,
    };

    sCylinderInit = {
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

    D_809E010C = { 0.0f, -1300.0f, 1100.0f };

}
