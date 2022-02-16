#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_M_FIRE1_Z_EN_M_FIRE1_C
#include "actor_common.h"
/*
 * File: z_en_m_fire1.c
 * Overlay: ovl_En_M_Fire1
 * Description: Deku Nut Hitbox
 */

#include "z_en_m_fire1.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"

#define FLAGS 0

void EnMFire1_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMFire1_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnMFire1_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMFire1_Update(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_M_Fire1_InitVars = {
    ACTOR_EN_M_FIRE1,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnMFire1),
    (ActorFunc)EnMFire1_Init,
    (ActorFunc)EnMFire1_Destroy,
    (ActorFunc)EnMFire1_Update,
    NULL,
    (ActorFunc)EnMFire1_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_PLAYER,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000001, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { 200, 200, 0, { 0 } },
};

void EnMFire1_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMFire1* pthis = (EnMFire1*)thisx;
    s32 pad;

    if (pthis->actor.params < 0) {
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ITEMACTION);
    }

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
}

void EnMFire1_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMFire1* pthis = (EnMFire1*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnMFire1_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMFire1* pthis = (EnMFire1*)thisx;
    s32 pad;

    if (Math_StepToF(&pthis->timer, 1.0f, 0.2f)) {
        Actor_Kill(&pthis->actor);
    } else {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void EnMFire1_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_M_Fire1_InitVars = {
        ACTOR_EN_M_FIRE1,
        ACTORCAT_MISC,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnMFire1),
        (ActorFunc)EnMFire1_Init,
        (ActorFunc)EnMFire1_Destroy,
        (ActorFunc)EnMFire1_Update,
        NULL,
        (ActorFunc)EnMFire1_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_PLAYER,
            AC_NONE,
            OC1_NONE,
            OC2_TYPE_PLAYER,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK2,
            { 0x00000001, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 200, 200, 0, { 0 } },
    };

}
