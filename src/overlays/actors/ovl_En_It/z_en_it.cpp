#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_IT_Z_EN_IT_C
#include "actor_common.h"
/*
 * File: z_en_it.c
 * Overlay: ovl_En_It
 * Description: Dampe's Minigame digging spot hitboxes
 */

#include "z_en_it.h"
#include "def/z_collision_check.h"

#define FLAGS 0

void EnIt_Init(Actor* thisx, GlobalContext* globalCtx);
void EnIt_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnIt_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnIt_Update(Actor* thisx, GlobalContext* globalCtx);

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_NO_PUSH,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 40, 10, 0, { 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

ActorInit En_It_InitVars = {
    ACTOR_EN_IT,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnIt),
    (ActorFunc)EnIt_Init,
    (ActorFunc)EnIt_Destroy,
    (ActorFunc)EnIt_Update,
    (ActorFunc)NULL,
    (ActorFunc)EnIt_Reset,
};

void EnIt_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnIt* pthis = (EnIt*)thisx;

    pthis->actor.params = 0x0D05;
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, 0, &sColChkInfoInit);
}

void EnIt_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnIt* pthis = (EnIt*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnIt_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnIt* pthis = (EnIt*)thisx;
    s32 pad;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnIt_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_NO_PUSH,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 40, 10, 0, { 0 } },
    };

    sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

    En_It_InitVars = {
        ACTOR_EN_IT,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnIt),
        (ActorFunc)EnIt_Init,
        (ActorFunc)EnIt_Destroy,
        (ActorFunc)EnIt_Update,
        (ActorFunc)NULL,
        (ActorFunc)EnIt_Reset,
    };

}
