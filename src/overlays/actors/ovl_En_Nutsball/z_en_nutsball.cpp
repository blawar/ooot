#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_NUTSBALL_Z_EN_NUTSBALL_C
#include "actor_common.h"
/*
 * File: z_en_nutsball.c
 * Overlay: ovl_En_Nutsball
 * Description: Projectile fired by deku scrubs
 */

#include "z_en_nutsball.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "objects/object_dekunuts/object_dekunuts.h"
#include "objects/object_hintnuts/object_hintnuts.h"
#include "objects/object_shopnuts/object_shopnuts.h"
#include "objects/object_dns/object_dns.h"
#include "objects/object_dnk/object_dnk.h"
#include "def/code_8006BA00.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS ACTOR_FLAG_4

void EnNutsball_Init(Actor* thisx, GlobalContext* globalCtx);
void EnNutsball_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnNutsball_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnNutsball_Update(Actor* thisx, GlobalContext* globalCtx);
void EnNutsball_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80ABBB34(EnNutsball* pthis, GlobalContext* globalCtx);
void func_80ABBBA8(EnNutsball* pthis, GlobalContext* globalCtx);

ActorInit En_Nutsball_InitVars = {
    ACTOR_EN_NUTSBALL,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnNutsball),
    (ActorFunc)EnNutsball_Init,
    (ActorFunc)EnNutsball_Destroy,
    (ActorFunc)EnNutsball_Update,
    (ActorFunc)NULL,
    (ActorFunc)EnNutsball_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_WOOD,
        BUMP_ON,
        OCELEM_ON,
    },
    { 13, 13, 0, { 0 } },
};

static s16 sObjectIDs[] = {
    OBJECT_DEKUNUTS, OBJECT_HINTNUTS, OBJECT_SHOPNUTS, OBJECT_DNS, OBJECT_DNK,
};

static Gfx* sDLists[] = {
    gDekuNutsDekuNutDL, gHintNutsNutDL, gBusinessScrubDekuNutDL, gDntJijiNutDL, gDntStageNutDL,
};

void EnNutsball_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnNutsball* pthis = (EnNutsball*)thisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 400.0f, ActorShadow_DrawCircle, 13.0f);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->objBankIndex = Object_GetIndex(&globalCtx->objectCtx, sObjectIDs[pthis->actor.params]);

    if (pthis->objBankIndex < 0) {
        Actor_Kill(&pthis->actor);
    } else {
        pthis->actionFunc = func_80ABBB34;
    }
}

void EnNutsball_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnNutsball* pthis = (EnNutsball*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80ABBB34(EnNutsball* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex)) {
        pthis->actor.objBankIndex = pthis->objBankIndex;
        pthis->actor.draw = EnNutsball_Draw;
        pthis->actor.shape.rot.y = 0;
        pthis->timer = 30;
        pthis->actionFunc = func_80ABBBA8;
        pthis->actor.speedXZ = 10.0f;
    }
}

void func_80ABBBA8(EnNutsball* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3s sp4C;
    Vec3f sp40;

    pthis->timer--;

    if (pthis->timer == 0) {
        pthis->actor.gravity = -1.0f;
    }

    pthis->actor.home.rot.z += 0x2AA8;

    if ((pthis->actor.bgCheckFlags & 8) || (pthis->actor.bgCheckFlags & 1) || (pthis->collider.base.atFlags & AT_HIT) ||
        (pthis->collider.base.acFlags & AC_HIT) || (pthis->collider.base.ocFlags1 & OC1_HIT)) {
        // Checking if the player is using a shield that reflects projectiles
        // And if so, reflects the projectile on impact
        if ((player->currentShield == PLAYER_SHIELD_DEKU) ||
            ((player->currentShield == PLAYER_SHIELD_HYLIAN) && LINK_IS_ADULT)) {
            if ((pthis->collider.base.atFlags & AT_HIT) && (pthis->collider.base.atFlags & AT_TYPE_ENEMY) &&
                (pthis->collider.base.atFlags & AT_BOUNCED)) {
                pthis->collider.base.atFlags &= ~AT_TYPE_ENEMY & ~AT_BOUNCED & ~AT_HIT;
                pthis->collider.base.atFlags |= AT_TYPE_PLAYER;

                pthis->collider.info.toucher.dmgFlags = 2;
                Matrix_MtxFToYXZRotS(&player->shieldMf, &sp4C, 0);
                pthis->actor.world.rot.y = sp4C.y + 0x8000;
                pthis->timer = 30;
                return;
            }
        }

        sp40.x = pthis->actor.world.pos.x;
        sp40.y = pthis->actor.world.pos.y + 4;
        sp40.z = pthis->actor.world.pos.z;

        EffectSsHahen_SpawnBurst(globalCtx, &sp40, 6.0f, 0, 7, 3, 15, HAHEN_OBJECT_DEFAULT, 10, NULL);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EN_OCTAROCK_ROCK);
        Actor_Kill(&pthis->actor);
    } else {
        if (pthis->timer == -300) {
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnNutsball_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnNutsball* pthis = (EnNutsball*)thisx;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;

    if (!(player->stateFlags1 & 0x300000C0) || (pthis->actionFunc == func_80ABBB34)) {
        pthis->actionFunc(pthis, globalCtx);

        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10, sCylinderInit.dim.radius, sCylinderInit.dim.height, 5);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

        pthis->actor.flags |= ACTOR_FLAG_24;

        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void EnNutsball_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_nutsball.c", 327);

    func_80093D18(globalCtx->state.gfxCtx);
    Matrix_Mult(&globalCtx->billboardMtxF, MTXMODE_APPLY);
    Matrix_RotateZ(thisx->home.rot.z * 9.58738e-05f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_nutsball.c", 333),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDLists[thisx->params]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_nutsball.c", 337);
}

void EnNutsball_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Nutsball_InitVars = {
        ACTOR_EN_NUTSBALL,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnNutsball),
        (ActorFunc)EnNutsball_Init,
        (ActorFunc)EnNutsball_Destroy,
        (ActorFunc)EnNutsball_Update,
        (ActorFunc)NULL,
        (ActorFunc)EnNutsball_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_WOOD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 13, 13, 0, { 0 } },
    };

}
