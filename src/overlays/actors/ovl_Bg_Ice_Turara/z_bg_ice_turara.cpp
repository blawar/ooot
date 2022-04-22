#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_ICE_TURARA_Z_BG_ICE_TURARA_C
#include "actor_common.h"
/*
 * File: z_bg_ice_turara.c
 * Overlay: ovl_Bg_Ice_Turara
 * Description: Icicles
 */

#include "z_bg_ice_turara.h"
#include "objects/object_ice_objects/object_ice_objects.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/random.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"

#define FLAGS 0

void BgIceTurara_Init(Actor* thisx, GlobalContext* globalCtx);
void BgIceTurara_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgIceTurara_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgIceTurara_Update(Actor* thisx, GlobalContext* globalCtx);
void BgIceTurara_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgIceTurara_Stalagmite(BgIceTurara* pthis, GlobalContext* globalCtx);
void BgIceTurara_Wait(BgIceTurara* pthis, GlobalContext* globalCtx);
void BgIceTurara_Shiver(BgIceTurara* pthis, GlobalContext* globalCtx);
void BgIceTurara_Fall(BgIceTurara* pthis, GlobalContext* globalCtx);
void BgIceTurara_Regrow(BgIceTurara* pthis, GlobalContext* globalCtx);

static Vec3f accel_31 = { 0.0f, -1.0f, 0.0f };

static Color_RGBA8 primColor_31 = { 170, 255, 255, 255 };

static Color_RGBA8 envColor_31 = { 0, 50, 100, 255 };


static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x04 },
        { 0x4FC007CA, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 13, 120, 0, { 0, 0, 0 } },
};

ActorInit Bg_Ice_Turara_InitVars = {
    ACTOR_BG_ICE_TURARA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_ICE_OBJECTS,
    sizeof(BgIceTurara),
    (ActorFunc)BgIceTurara_Init,
    (ActorFunc)BgIceTurara_Destroy,
    (ActorFunc)BgIceTurara_Update,
    (ActorFunc)BgIceTurara_Draw,
    (ActorFunc)BgIceTurara_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 600, ICHAIN_CONTINUE),
    ICHAIN_F32(gravity, -3, ICHAIN_CONTINUE),
    ICHAIN_F32(minVelocityY, -30, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgIceTurara_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgIceTurara* pthis = (BgIceTurara*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&object_ice_objects_Col_002594, &colHeader);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->dyna.actor, &sCylinderInit);
    Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->collider);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (pthis->dyna.actor.params == TURARA_STALAGMITE) {
        pthis->actionFunc = BgIceTurara_Stalagmite;
    } else {
        pthis->dyna.actor.shape.rot.x = -0x8000;
        pthis->dyna.actor.shape.yOffset = 1200.0f;
        pthis->actionFunc = BgIceTurara_Wait;
    }
}

void BgIceTurara_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgIceTurara* pthis = (BgIceTurara*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void BgIceTurara_Break(BgIceTurara* pthis, GlobalContext* globalCtx, f32 arg2) {
    Vec3f vel;
    Vec3f pos;
    s32 j;
    s32 i;

    Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 30, NA_SE_EV_ICE_BROKEN);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 10; j++) {
            pos.x = pthis->dyna.actor.world.pos.x + Rand_CenteredFloat(8.0f);
            pos.y = pthis->dyna.actor.world.pos.y + (Rand_ZeroOne() * arg2) + (i * arg2);
            pos.z = pthis->dyna.actor.world.pos.z + Rand_CenteredFloat(8.0f);

            vel.x = Rand_CenteredFloat(7.0f);
            vel.z = Rand_CenteredFloat(7.0f);
            vel.y = (Rand_ZeroOne() * 4.0f) + 8.0f;

            EffectSsEnIce_Spawn(globalCtx, &pos, (Rand_ZeroOne() * 0.2f) + 0.1f, &vel, &accel_31, &primColor_31, &envColor_31,
                                30);
        }
    }
}

void BgIceTurara_Stalagmite(BgIceTurara* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        BgIceTurara_Break(pthis, globalCtx, 50.0f);
        Actor_Kill(&pthis->dyna.actor);
        return;
    }
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void BgIceTurara_Wait(BgIceTurara* pthis, GlobalContext* globalCtx) {
    if (pthis->dyna.actor.xzDistToPlayer < 60.0f) {
        pthis->shiverTimer = 10;
        pthis->actionFunc = BgIceTurara_Shiver;
    }
}

void BgIceTurara_Shiver(BgIceTurara* pthis, GlobalContext* globalCtx) {
    s16 phi_v0_3;
    s16 phi_v0_2;
    f32 sp28;

    if (pthis->shiverTimer != 0) {
        pthis->shiverTimer--;
    }
    if (!(pthis->shiverTimer % 4)) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_ICE_SWING);
    }
    if (pthis->shiverTimer == 0) {
        pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x;
        pthis->dyna.actor.world.pos.z = pthis->dyna.actor.home.pos.z;
        Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->collider);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        pthis->actionFunc = BgIceTurara_Fall;
    } else {
        sp28 = Rand_ZeroOne();
        phi_v0_2 = (Rand_ZeroOne() < 0.5f ? -1 : 1);
        pthis->dyna.actor.world.pos.x = (phi_v0_2 * ((0.5f * sp28) + 0.5f)) + pthis->dyna.actor.home.pos.x;
        sp28 = Rand_ZeroOne();
        phi_v0_3 = (Rand_ZeroOne() < 0.5f ? -1 : 1);
        pthis->dyna.actor.world.pos.z = (phi_v0_3 * ((0.5f * sp28) + 0.5f)) + pthis->dyna.actor.home.pos.z;
    }
}

void BgIceTurara_Fall(BgIceTurara* pthis, GlobalContext* globalCtx) {
    if ((pthis->collider.base.atFlags & AT_HIT) || (pthis->dyna.actor.bgCheckFlags & 1)) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        pthis->dyna.actor.bgCheckFlags &= ~1;
        if (pthis->dyna.actor.world.pos.y < pthis->dyna.actor.floorHeight) {
            pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
        }
        BgIceTurara_Break(pthis, globalCtx, 40.0f);
        if (pthis->dyna.actor.params == TURARA_STALACTITE_REGROW) {
            pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + 120.0f;
            func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
            pthis->actionFunc = BgIceTurara_Regrow;
        } else {
            Actor_Kill(&pthis->dyna.actor);
            return;
        }
    } else {
        Actor_MoveForward(&pthis->dyna.actor);
        pthis->dyna.actor.world.pos.y += 40.0f;
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 0.0f, 0.0f, 0.0f, 4);
        pthis->dyna.actor.world.pos.y -= 40.0f;
        Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->collider);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void BgIceTurara_Regrow(BgIceTurara* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 1.0f)) {
        pthis->actionFunc = BgIceTurara_Wait;
        pthis->dyna.actor.velocity.y = 0.0f;
    }
}

void BgIceTurara_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgIceTurara* pthis = (BgIceTurara*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgIceTurara_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, object_ice_objects_DL_0023D0);
}

void BgIceTurara_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    accel_31 = { 0.0f, -1.0f, 0.0f };

    primColor_31 = { 170, 255, 255, 255 };

    envColor_31 = { 0, 50, 100, 255 };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x04 },
            { 0x4FC007CA, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 13, 120, 0, { 0, 0, 0 } },
    };

    Bg_Ice_Turara_InitVars = {
        ACTOR_BG_ICE_TURARA,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_ICE_OBJECTS,
        sizeof(BgIceTurara),
        (ActorFunc)BgIceTurara_Init,
        (ActorFunc)BgIceTurara_Destroy,
        (ActorFunc)BgIceTurara_Update,
        (ActorFunc)BgIceTurara_Draw,
        (ActorFunc)BgIceTurara_Reset,
    };

}
