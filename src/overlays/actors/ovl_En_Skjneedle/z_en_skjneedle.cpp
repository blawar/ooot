#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SKJNEEDLE_Z_EN_SKJNEEDLE_C
#include "actor_common.h"
/*
 * File: z_en_skjneedle.c
 * Overlay: ovl_En_Skjneedle
 * Description: Skullkid Needle Attack
 */

#include "z_en_skjneedle.h"
#include "objects/object_skj/object_skj.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_9)

void EnSkjneedle_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSkjneedle_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSkjneedle_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSkjneedle_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 EnSkjNeedle_CollisionCheck(EnSkjneedle* pthis);

ActorInit En_Skjneedle_InitVars = {
    ACTOR_EN_SKJNEEDLE,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SKJ,
    sizeof(EnSkjneedle),
    (ActorFunc)EnSkjneedle_Init,
    (ActorFunc)EnSkjneedle_Destroy,
    (ActorFunc)EnSkjneedle_Update,
    (ActorFunc)EnSkjneedle_Draw,
};

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_HIT1,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 10, 4, -2, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 30, ICHAIN_STOP),
};

void EnSkjneedle_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnSkjneedle* pthis = (EnSkjneedle*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    ActorShape_Init(&pthis->actor.shape, 0, ActorShadow_DrawCircle, 20.0f);
    thisx->flags &= ~ACTOR_FLAG_0;
    Actor_SetScale(&pthis->actor, 0.01f);
}

void EnSkjneedle_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnSkjneedle* pthis = (EnSkjneedle*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 EnSkjNeedle_CollisionCheck(EnSkjneedle* pthis) {
    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        return 1;
    }
    return 0;
}

void EnSkjneedle_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnSkjneedle* pthis = (EnSkjneedle*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    pthis->unusedTimer1++;
    if (pthis->killTimer != 0) {
        pthis->killTimer--;
    }
    if (EnSkjNeedle_CollisionCheck(pthis) || pthis->killTimer == 0) {
        Actor_Kill(&pthis->actor);
    } else {
        Actor_SetScale(&pthis->actor, 0.01f);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 20.0f, 7);
    }
}

void EnSkjneedle_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_skj_needle.c", 200);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_skj_needle.c", 205),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gSKJNeedleDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_skj_needle.c", 210);
}
