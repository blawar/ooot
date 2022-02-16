#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_YUKABYUN_Z_EN_YUKABYUN_C
#include "actor_common.h"
/*
 * File: z_en_yukabyun.c
 * Overlay: ovl_En_Yukabyun
 * Description: Flying floor tile
 */

#include "z_en_yukabyun.h"
#include "objects/object_yukabyun/object_yukabyun.h"
#include "def/code_8006BA00.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void EnYukabyun_Init(Actor* thisx, GlobalContext* globalCtx);
void EnYukabyun_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnYukabyun_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnYukabyun_Update(Actor* thisx, GlobalContext* globalCtx);
void EnYukabyun_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B43A94(EnYukabyun* pthis, GlobalContext* globalCtx);
void func_80B43AD4(EnYukabyun* pthis, GlobalContext* globalCtx);
void func_80B43B6C(EnYukabyun* pthis, GlobalContext* globalCtx);

ActorInit En_Yukabyun_InitVars = {
    ACTOR_EN_YUKABYUN,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_YUKABYUN,
    sizeof(EnYukabyun),
    (ActorFunc)EnYukabyun_Init,
    (ActorFunc)EnYukabyun_Destroy,
    (ActorFunc)EnYukabyun_Update,
    (ActorFunc)EnYukabyun_Draw,
    (ActorFunc)EnYukabyun_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_NO_PUSH | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x04 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_HARD,
        BUMP_ON,
        OCELEM_ON,
    },
    { 28, 8, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F(scale, 1, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 16, ICHAIN_STOP),
};

static void* D_80B43F64[] = { gFloorTileEnemyTopTex, gFloorTileEnemyBottomTex };

void EnYukabyun_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnYukabyun* pthis = (EnYukabyun*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.4f);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.params++;
    pthis->unk_152 = 0;
    pthis->unk_150 = (u8)(pthis->actor.params) * 0xA + 0x14;
    pthis->actionfunc = func_80B43A94;
}

void EnYukabyun_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnYukabyun* pthis = (EnYukabyun*)thisx;
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80B43A94(EnYukabyun* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_150 != 0) {
        pthis->unk_150--;
    }
    if (pthis->unk_150 == 0) {
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_12;
        pthis->actionfunc = func_80B43AD4;
    }
}

void func_80B43AD4(EnYukabyun* pthis, GlobalContext* globalCtx) {
    pthis->unk_150 += 0xA0;
    pthis->actor.shape.rot.y += pthis->unk_150;
    if (pthis->unk_150 >= 0x2000) {
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actor.speedXZ = 10.0f;
        pthis->actionfunc = func_80B43B6C;
    }
    Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 30.0f, 1.0f);
    func_8002F974(&pthis->actor, NA_SE_EN_YUKABYUN_FLY - SFX_FLAG);
}

void func_80B43B6C(EnYukabyun* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.rot.y += pthis->unk_150;
    if (pthis->actor.xzDistToPlayer > 5000.0f) {
        Actor_Kill(&pthis->actor);
        return;
    }
    func_8002F974(&pthis->actor, NA_SE_EN_YUKABYUN_FLY - SFX_FLAG);
}

void EnYukabyun_Break(EnYukabyun* pthis, GlobalContext* globalCtx) {
    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 8.0f, 0, 1300, 300, 15, OBJECT_YUKABYUN, 10,
                             gFloorTileEnemyFragmentDL);
    Actor_Kill(&pthis->actor);
}

void EnYukabyun_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnYukabyun* pthis = (EnYukabyun*)thisx;
    s32 pad;

    if (((pthis->collider.base.atFlags & AT_HIT) || (pthis->collider.base.acFlags & AC_HIT) ||
         ((pthis->collider.base.ocFlags1 & OC1_HIT) && !(pthis->collider.base.oc->id == ACTOR_EN_YUKABYUN))) ||
        ((pthis->actionfunc == func_80B43B6C) && (pthis->actor.bgCheckFlags & 8))) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        pthis->collider.base.acFlags &= ~AC_HIT;
        pthis->collider.base.ocFlags1 &= ~OC1_HIT;
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 30, NA_SE_EN_OCTAROCK_ROCK);
        pthis->actionfunc = EnYukabyun_Break;
    }

    pthis->actionfunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);

    if (!(pthis->actionfunc == func_80B43A94 || pthis->actionfunc == EnYukabyun_Break)) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 20.0f, 8.0f, 5);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

        pthis->actor.flags |= ACTOR_FLAG_24;

        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
    Actor_SetFocus(&pthis->actor, 4.0f);
}

void EnYukabyun_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnYukabyun* pthis = (EnYukabyun*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_yukabyun.c", 366);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(D_80B43F64[pthis->unk_152]));
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_yukabyun.c", 373),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gFloorTileEnemyDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_yukabyun.c", 378);
}

void EnYukabyun_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Yukabyun_InitVars = {
        ACTOR_EN_YUKABYUN,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_YUKABYUN,
        sizeof(EnYukabyun),
        (ActorFunc)EnYukabyun_Init,
        (ActorFunc)EnYukabyun_Destroy,
        (ActorFunc)EnYukabyun_Update,
        (ActorFunc)EnYukabyun_Draw,
        (ActorFunc)EnYukabyun_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_NO_PUSH | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x04 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 28, 8, 0, { 0, 0, 0 } },
    };

}
