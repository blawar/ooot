#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ATTACK_NIW_Z_EN_ATTACK_NIW_C
#include "actor_common.h"
/*
 * File: z_en_attack_niw.c
 * Overlay: ovl_En_Attack_Niw
 * Description: Attacking Cucco, not solid
 */

#include "z_en_attack_niw.h"
#include "objects/object_niw/object_niw.h"
#include "overlays/actors/ovl_En_Niw/z_en_niw.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

void EnAttackNiw_Init(Actor* thisx, GlobalContext* globalCtx);
void EnAttackNiw_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnAttackNiw_Update(Actor* thisx, GlobalContext* globalCtx);
void EnAttackNiw_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809B5670(EnAttackNiw* pthis, GlobalContext* globalCtx);
void func_809B5C18(EnAttackNiw* pthis, GlobalContext* globalCtx);
void func_809B59B0(EnAttackNiw* pthis, GlobalContext* globalCtx);

ActorInit En_Attack_Niw_InitVars = {
    ACTOR_EN_ATTACK_NIW,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_NIW,
    sizeof(EnAttackNiw),
    (ActorFunc)EnAttackNiw_Init,
    (ActorFunc)EnAttackNiw_Destroy,
    (ActorFunc)EnAttackNiw_Update,
    (ActorFunc)EnAttackNiw_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 1, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -2000, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 0, ICHAIN_STOP),
};

void EnAttackNiw_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnAttackNiw* pthis = (EnAttackNiw*)thisx;
    s32 pad;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gCuccoSkel, &gCuccoAnim, pthis->jointTable, pthis->morphTable, 16);
    if (pthis->actor.params < 0) {
        pthis->actor.params = 0;
    }
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.gravity = 0.0f;
    pthis->unk_298.x = Rand_CenteredFloat(100.0f);
    pthis->unk_298.y = Rand_CenteredFloat(10.0f);
    pthis->unk_298.z = Rand_CenteredFloat(100.0f);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y = (Rand_ZeroOne() - 0.5f) * 60000.0f;
    pthis->actionFunc = func_809B5670;
}

void EnAttackNiw_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnAttackNiw* pthis = (EnAttackNiw*)thisx;
    EnNiw* cucco = (EnNiw*)pthis->actor.parent;

    if (pthis->actor.parent != NULL) {
        if ((cucco->actor.update != NULL) && (cucco->unk_296 > 0)) {
            cucco->unk_296--;
        }
    }
}

void func_809B5268(EnAttackNiw* pthis, GlobalContext* globalCtx, s16 arg2) {
    if (pthis->unk_254 == 0) {
        if (arg2 == 0) {
            pthis->unk_264 = 0.0f;
        } else {
            pthis->unk_264 = -10000.0f;
        }
        pthis->unk_28E++;
        pthis->unk_254 = 3;
        if ((pthis->unk_28E & 1) == 0) {
            pthis->unk_264 = 0.0f;
            if (arg2 == 0) {
                pthis->unk_254 = Rand_ZeroFloat(30.0f);
            }
        }
    }

    if (pthis->unk_258 == 0) {
        pthis->unk_292++;
        pthis->unk_292 &= 1;
        switch (arg2) {
            case 0:
                pthis->unk_26C = 0.0f;
                pthis->unk_268 = 0.0f;
                break;
            case 1:
                pthis->unk_258 = 3;
                pthis->unk_26C = 7000.0f;
                pthis->unk_268 = 7000.0f;
                if (pthis->unk_292 == 0) {
                    pthis->unk_26C = 0.0f;
                    pthis->unk_268 = 0.0f;
                }
                break;
            case 2:
                pthis->unk_258 = 2;
                pthis->unk_268 = pthis->unk_26C = -10000.0f;
                pthis->unk_280 = pthis->unk_278 = 25000.0f;
                pthis->unk_284 = pthis->unk_27C = 6000.0f;
                if (pthis->unk_292 == 0) {
                    pthis->unk_278 = 8000.0f;
                    pthis->unk_280 = 8000.0f;
                }
                break;
            case 3:
                pthis->unk_258 = 2;
                pthis->unk_278 = 10000.0f;
                pthis->unk_280 = 10000.0f;
                if (pthis->unk_292 == 0) {
                    pthis->unk_278 = 3000.0f;
                    pthis->unk_280 = 3000.0f;
                }
                break;
            case 4:
                pthis->unk_254 = pthis->unk_256 = 5;
                break;
            case 5:
                pthis->unk_258 = 5;
                pthis->unk_278 = 14000.0f;
                pthis->unk_280 = 14000.0f;
                if (pthis->unk_292 == 0) {
                    pthis->unk_278 = 10000.0f;
                    pthis->unk_280 = 10000.0f;
                }
                break;
        }
    }

    if (pthis->unk_288 != pthis->unk_2C0) {
        Math_ApproachF(&pthis->unk_2C0, pthis->unk_288, 0.5f, 4000.0f);
    }
    if (pthis->unk_264 != pthis->unk_2BC) {
        Math_ApproachF(&pthis->unk_2BC, pthis->unk_264, 0.5f, 4000.0f);
    }
    if (pthis->unk_26C != pthis->unk_2A4.x) {
        Math_ApproachF(&pthis->unk_2A4.x, pthis->unk_26C, 0.8f, 7000.0f);
    }
    if (pthis->unk_280 != pthis->unk_2A4.y) {
        Math_ApproachF(&pthis->unk_2A4.y, pthis->unk_280, 0.8f, 7000.0f);
    }
    if (pthis->unk_284 != pthis->unk_2A4.z) {
        Math_ApproachF(&pthis->unk_2A4.z, pthis->unk_284, 0.8f, 7000.0f);
    }
    if (pthis->unk_268 != pthis->unk_2B0.x) {
        Math_ApproachF(&pthis->unk_2B0.x, pthis->unk_268, 0.8f, 7000.0f);
    }
    if (pthis->unk_278 != pthis->unk_2B0.y) {
        Math_ApproachF(&pthis->unk_2B0.y, pthis->unk_278, 0.8f, 7000.0f);
    }
    if (pthis->unk_27C != pthis->unk_2B0.z) {
        Math_ApproachF(&pthis->unk_2B0.z, pthis->unk_27C, 0.8f, 7000.0f);
    }
}

s32 func_809B55EC(EnAttackNiw* pthis, GlobalContext* globalCtx) {
    s16 sp1E;
    s16 sp1C;

    Actor_SetFocus(&pthis->actor, pthis->unk_2E4);
    Actor_GetScreenPos(globalCtx, &pthis->actor, &sp1E, &sp1C);
    if ((pthis->actor.projectedPos.z < -20.0f) || (sp1E < 0) || (sp1E > SCREEN_WIDTH) || (sp1C < 0) ||
        (sp1C > SCREEN_HEIGHT)) {
        return 0;
    } else {
        return 1;
    }
}

void func_809B5670(EnAttackNiw* pthis, GlobalContext* globalCtx) {
    s16 sp4E;
    s16 sp4C;
    f32 tmpf1;
    f32 tmpf2;
    f32 tmpf3;
    Vec3f sp34;

    pthis->actor.speedXZ = 10.0f;

    tmpf1 = (pthis->unk_298.x + globalCtx->view.lookAt.x) - globalCtx->view.eye.x;
    tmpf2 = (pthis->unk_298.y + globalCtx->view.lookAt.y) - globalCtx->view.eye.y;
    tmpf3 = (pthis->unk_298.z + globalCtx->view.lookAt.z) - globalCtx->view.eye.z;

    sp34.x = globalCtx->view.lookAt.x + tmpf1;
    sp34.y = globalCtx->view.lookAt.y + tmpf2;
    sp34.z = globalCtx->view.lookAt.z + tmpf3;

    pthis->unk_2D4 = Math_Vec3f_Yaw(&pthis->actor.world.pos, &sp34);
    pthis->unk_2D0 = Math_Vec3f_Pitch(&pthis->actor.world.pos, &sp34) * -1.0f;

    Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_2D4, 5, pthis->unk_2DC, 0);
    Math_SmoothStepToS(&pthis->actor.world.rot.x, pthis->unk_2D0, 5, pthis->unk_2DC, 0);
    Math_ApproachF(&pthis->unk_2DC, 5000.0f, 1.0f, 100.0f);

    Actor_SetFocus(&pthis->actor, pthis->unk_2E4);
    Actor_GetScreenPos(globalCtx, &pthis->actor, &sp4E, &sp4C);

    if (pthis->actor.bgCheckFlags & 8) {
        pthis->unk_2D4 = pthis->actor.yawTowardsPlayer;
        pthis->unk_2D0 = pthis->actor.world.rot.x - 3000.0f;
        pthis->unk_2DC = 0.0f;
        pthis->unk_284 = 0.0f;
        pthis->unk_27C = 0.0f;
        pthis->unk_254 = pthis->unk_256 = pthis->unk_258 = pthis->unk_25A = 0;
        pthis->unk_25C = 0x64;
        pthis->actor.gravity = -0.2f;
        pthis->unk_2E0 = 5.0f;
        pthis->unk_288 = 0.0f;
        pthis->actionFunc = func_809B59B0;
    } else if (((pthis->actor.projectedPos.z > 0.0f) && (fabsf(sp34.x - pthis->actor.world.pos.x) < 50.0f) &&
                (fabsf(sp34.y - pthis->actor.world.pos.y) < 50.0f) &&
                (fabsf(sp34.z - pthis->actor.world.pos.z) < 50.0f)) ||
               (pthis->actor.bgCheckFlags & 1)) {

        pthis->unk_2D4 = pthis->actor.yawTowardsPlayer;
        pthis->unk_2D0 = pthis->actor.world.rot.x - 2000.0f;
        pthis->unk_2DC = 0.0f;
        pthis->unk_27C = 0.0f;
        pthis->unk_284 = 0.0f;
        pthis->unk_254 = pthis->unk_256 = pthis->unk_258 = pthis->unk_25A = 0;
        pthis->actor.gravity = -0.2f;
        pthis->unk_2E0 = 5.0f;
        pthis->unk_288 = 0.0f;
        pthis->actionFunc = func_809B59B0;
    } else {
        pthis->unk_254 = 10;
        pthis->unk_264 = -10000.0f;
        pthis->unk_288 = -3000.0f;
        func_809B5268(pthis, globalCtx, 2);
    }
}

void func_809B59B0(EnAttackNiw* pthis, GlobalContext* globalCtx) {
    if (!func_809B55EC(pthis, globalCtx)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->actor.bgCheckFlags & 1) {
        if (pthis->unk_25A == 0) {
            pthis->unk_25A = 3;
            pthis->actor.velocity.y = 3.5f;
        }
        if (pthis->actor.gravity != -2.0f) {
            pthis->unk_280 = pthis->unk_278 = 14000.0f;
            pthis->unk_2D0 = pthis->unk_26C = pthis->unk_268 = pthis->unk_284 = pthis->unk_27C = 0.0f;
            pthis->unk_2D4 = pthis->actor.yawTowardsPlayer;
            pthis->unk_262 = 0x32;
            pthis->unk_25C = 0x64;
            pthis->actor.gravity = -2.0f;
        }
    }
    if (pthis->unk_25C == 0x32) {
        pthis->unk_2D4 = Rand_CenteredFloat(200.0f) + pthis->actor.yawTowardsPlayer;
    }
    Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_2D4, 2, pthis->unk_2DC, 0);
    Math_SmoothStepToS(&pthis->actor.world.rot.x, pthis->unk_2D0, 2, pthis->unk_2DC, 0);
    Math_ApproachF(&pthis->unk_2DC, 10000.0f, 1.0f, 1000.0f);
    Math_ApproachF(&pthis->actor.speedXZ, pthis->unk_2E0, 0.9f, 1.0f);
    if ((pthis->actor.gravity == -2.0f) && (pthis->unk_262 == 0) &&
        ((pthis->actor.bgCheckFlags & 8) || (pthis->unk_25C == 0))) {
        pthis->unk_2E0 = 0.0f;
        pthis->actor.gravity = 0.0f;
        pthis->unk_2DC = 0.0f;
        pthis->unk_2D0 = pthis->actor.world.rot.x - 5000.0f;
        pthis->actionFunc = func_809B5C18;
    } else if (pthis->actor.bgCheckFlags & 1) {
        func_809B5268(pthis, globalCtx, 5);
    } else {
        func_809B5268(pthis, globalCtx, 2);
    }
}

void func_809B5C18(EnAttackNiw* pthis, GlobalContext* globalCtx) {
    if (!func_809B55EC(pthis, globalCtx)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    Math_SmoothStepToS(&pthis->actor.world.rot.x, pthis->unk_2D0, 5, pthis->unk_2DC, 0);
    Math_ApproachF(&pthis->unk_2DC, 5000.0f, 1.0f, 100.0f);
    Math_ApproachF(&pthis->actor.velocity.y, 5.0f, 0.3f, 1.0f);
    func_809B5268(pthis, globalCtx, 2);
}

void EnAttackNiw_Update(Actor* thisx, GlobalContext* globalCtx) {
    f32 tmpf1;
    EnAttackNiw* pthis = (EnAttackNiw*)thisx;
    EnNiw* cucco;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    Vec3f sp30;
    GlobalContext* globalCtx2 = globalCtx;

    pthis->unk_28C++;
    if (pthis->unk_254 != 0) {
        pthis->unk_254--;
    }
    if (pthis->unk_258 != 0) {
        pthis->unk_258--;
    }
    if (pthis->unk_25A != 0) {
        pthis->unk_25A--;
    }
    if (pthis->unk_25E != 0) {
        pthis->unk_25E--;
    }
    if (pthis->unk_260 != 0) {
        pthis->unk_260--;
    }
    if (pthis->unk_25C != 0) {
        pthis->unk_25C--;
    }
    if (pthis->unk_262 != 0) {
        pthis->unk_262--;
    }

    pthis->actor.shape.rot = pthis->actor.world.rot;
    pthis->actor.shape.shadowScale = 15.0f;
    pthis->actionFunc(pthis, globalCtx2);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 60.0f, 0x1D);

    if (pthis->actionFunc == func_809B5670) {
        func_8002D97C(&pthis->actor);
    } else {
        Actor_MoveForward(&pthis->actor);
    }

    if (pthis->actor.floorHeight <= BGCHECK_Y_MIN) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if ((pthis->actor.bgCheckFlags & 0x20) && (pthis->actionFunc != func_809B5C18)) {
        Math_Vec3f_Copy(&sp30, &pthis->actor.world.pos);
        sp30.y += pthis->actor.yDistToWater;
        EffectSsGSplash_Spawn(globalCtx, &sp30, 0, 0, 0, 0x190);
        pthis->unk_2DC = 0.0f;
        pthis->actor.gravity = 0.0f;
        pthis->unk_2E0 = 0.0f;
        pthis->unk_2D0 = pthis->actor.world.rot.x - 5000.0f;
        pthis->actionFunc = func_809B5C18;
        return;
    }

    tmpf1 = 20.0f;
    if (pthis->actor.xyzDistToPlayerSq < SQ(tmpf1)) {
        cucco = (EnNiw*)pthis->actor.parent;
        if ((pthis->actor.parent->update != NULL) && (pthis->actor.parent != NULL) && (cucco != NULL) &&
            (cucco->timer9 == 0) && (player->invincibilityTimer == 0)) {
            func_8002F6D4(globalCtx, &pthis->actor, 2.0f, pthis->actor.world.rot.y, 0.0f, 0x10);
            cucco->timer9 = 0x46;
        }
    }
    if (pthis->unk_25E == 0) {
        pthis->unk_25E = 30;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_A);
    }
    if (pthis->unk_260 == 0) {
        pthis->unk_260 = 7;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_WAKEUP);
    }
}

s32 func_809B5F98(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnAttackNiw* pthis = (EnAttackNiw*)thisx;
    Vec3f sp0 = { 0.0f, 0.0f, 0.0f };

    if (limbIndex == 13) {
        rot->y += (s16)pthis->unk_2BC;
    }
    if (limbIndex == 15) {
        rot->z += (s16)pthis->unk_2C0;
    }
    if (limbIndex == 11) {
        rot->x += (s16)pthis->unk_2B0.z;
        rot->y += (s16)pthis->unk_2B0.y;
        rot->z += (s16)pthis->unk_2B0.x;
    }
    if (limbIndex == 7) {
        rot->x += (s16)pthis->unk_2A4.z;
        rot->y += (s16)pthis->unk_2A4.y;
        rot->z += (s16)pthis->unk_2A4.x;
    }
    return 0;
}

void EnAttackNiw_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnAttackNiw* pthis = (EnAttackNiw*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          func_809B5F98, NULL, pthis);
}
