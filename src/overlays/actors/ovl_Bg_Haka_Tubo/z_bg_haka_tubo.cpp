#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HAKA_TUBO_Z_BG_HAKA_TUBO_C
#include "actor_common.h"
/*
 * File: z_bg_haka_tubo.c
 * Overlay: ovl_Bg_Haka_Tubo
 * Description: Shadow Temple Giant Skull Jar
 */

#include "z_bg_haka_tubo.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_haka_objects/object_haka_objects.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void BgHakaTubo_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTubo_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgHakaTubo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTubo_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTubo_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgHakaTubo_Idle(BgHakaTubo* pthis, GlobalContext* globalCtx);
void BgHakaTubo_DropCollectible(BgHakaTubo* pthis, GlobalContext* globalCtx);

static Vec3f sZeroVector_34 = { 0.0f, 0.0f, 0.0f };


ActorInit Bg_Haka_Tubo_InitVars = {
    ACTOR_BG_HAKA_TUBO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA_OBJECTS,
    sizeof(BgHakaTubo),
    (ActorFunc)BgHakaTubo_Init,
    (ActorFunc)BgHakaTubo_Destroy,
    (ActorFunc)BgHakaTubo_Update,
    (ActorFunc)BgHakaTubo_Draw,
    (ActorFunc)BgHakaTubo_Reset,
};

static ColliderCylinderInit sPotColliderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000008, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 25, 60, 30, { 0, 0, 0 } },
};

static ColliderCylinderInit sFlamesColliderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x20000000, 0x01, 0x04 },
        { 0x00000008, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 60, 45, 235, { 0, 0, 0 } },
};

static s32 sPotsDestroyed = 0;

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHakaTubo_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaTubo* pthis = (BgHakaTubo*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK3);
    CollisionHeader_GetVirtual(&object_haka_objects_Col_0108B8, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    Collider_InitCylinder(globalCtx, &pthis->potCollider);
    Collider_SetCylinder(globalCtx, &pthis->potCollider, &pthis->dyna.actor, &sPotColliderInit);
    Collider_InitCylinder(globalCtx, &pthis->flamesCollider);
    Collider_SetCylinder(globalCtx, &pthis->flamesCollider, &pthis->dyna.actor, &sFlamesColliderInit);
    pthis->fireScroll = Rand_ZeroOne() * 15.0f;
    sPotsDestroyed = 0;
    pthis->actionFunc = BgHakaTubo_Idle;
}

void BgHakaTubo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaTubo* pthis = (BgHakaTubo*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyCylinder(globalCtx, &pthis->potCollider);
    Collider_DestroyCylinder(globalCtx, &pthis->flamesCollider);
}

void BgHakaTubo_Idle(BgHakaTubo* pthis, GlobalContext* globalCtx) {
    Vec3f pos;

    if (pthis->dyna.actor.room == 12) { // 3 spinning pots room in Shadow Temple
        pthis->dyna.actor.shape.rot.y += 0x180;
        pthis->dyna.actor.world.pos.x = Math_SinS(pthis->dyna.actor.shape.rot.y - 0x4000) * 145.0f + -5559.0f;
        pthis->dyna.actor.world.pos.z = Math_CosS(pthis->dyna.actor.shape.rot.y - 0x4000) * 145.0f + -1587.0f;
    }
    // Colliding with flame circle
    if (pthis->flamesCollider.base.atFlags & AT_HIT) {
        pthis->flamesCollider.base.atFlags &= ~AT_HIT;
        func_8002F71C(globalCtx, &pthis->dyna.actor, 5.0f, pthis->dyna.actor.yawTowardsPlayer, 5.0f);
    }
    // Colliding with hitbox inside the pot
    if (pthis->potCollider.base.acFlags & AC_HIT) {
        pthis->potCollider.base.acFlags &= ~AC_HIT;
        // If the colliding actor is within a 50 unit radius and 50 unit height cylinder centered
        // on the actor's position, break the pot
        if (Actor_WorldDistXZToPoint(&pthis->dyna.actor, &pthis->potCollider.base.ac->world.pos) < 50.0f &&
            (pthis->potCollider.base.ac->world.pos.y - pthis->dyna.actor.world.pos.y) < 50.0f) {
            pos.x = pthis->dyna.actor.world.pos.x;
            pos.z = pthis->dyna.actor.world.pos.z;
            pos.y = pthis->dyna.actor.world.pos.y + 80.0f;
            EffectSsBomb2_SpawnLayered(globalCtx, &pos, &sZeroVector_34, &sZeroVector_34, 100, 45);
            Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 50, NA_SE_EV_BOX_BREAK);
            EffectSsHahen_SpawnBurst(globalCtx, &pos, 20.0f, 0, 350, 100, 50, OBJECT_HAKA_OBJECTS, 40,
                                     gEffFragments2DL);
            pthis->dropTimer = 5;
            pthis->dyna.actor.draw = NULL;
            Actor_SetScale(&pthis->dyna.actor, 0.0f);
            pthis->actionFunc = BgHakaTubo_DropCollectible;
        }
    } else {
        Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->flamesCollider);
        Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->potCollider);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->potCollider.base);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->flamesCollider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->flamesCollider.base);
    }
}

void BgHakaTubo_DropCollectible(BgHakaTubo* pthis, GlobalContext* globalCtx) {
    EnItem00* collectible;
    f32 rnd;
    Vec3f spawnPos;
    s32 i;
    s32 collectibleParams;

    pthis->dropTimer--;
    if (pthis->dropTimer == 0) { // Creates a delay between destroying the pot and dropping the collectible
        spawnPos.x = pthis->dyna.actor.world.pos.x;
        spawnPos.y = pthis->dyna.actor.world.pos.y + 200.0f;
        spawnPos.z = pthis->dyna.actor.world.pos.z;
        if (pthis->dyna.actor.room == 12) { // 3 spinning pots room in Shadow Temple
            rnd = Rand_ZeroOne();
            sPotsDestroyed++;
            if (sPotsDestroyed == 3) {
                // All 3 pots destroyed
                collectibleParams = -1;
                Common_PlaySfx(NA_SE_SY_CORRECT_CHIME);
                // Drop rupees
                for (i = 0; i < 9; i++) {
                    collectible = Item_DropCollectible(globalCtx, &spawnPos, i % 3);
                    if (collectible != NULL) {
                        collectible->actor.velocity.y = 15.0f;
                        collectible->actor.world.rot.y = pthis->dyna.actor.shape.rot.y + (i * 0x1C71);
                    }
                }
            } else if (rnd < 0.2f) {
                // Unlucky, no reward and spawn keese
                collectibleParams = -1;
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_FIREFLY, pthis->dyna.actor.world.pos.x,
                            pthis->dyna.actor.world.pos.y + 80.0f, pthis->dyna.actor.world.pos.z, 0,
                            pthis->dyna.actor.shape.rot.y, 0, 2);
                Common_PlaySfx(NA_SE_SY_ERROR);
            } else {
                // Random rewards
                if (rnd < 0.4f) {
                    collectibleParams = ITEM00_BOMBS_A;
                } else if (rnd < 0.6f) {
                    collectibleParams = ITEM00_MAGIC_LARGE;
                } else if (rnd < 0.8f) {
                    collectibleParams = ITEM00_MAGIC_SMALL;
                } else {
                    collectibleParams = ITEM00_ARROWS_SMALL;
                }
                Common_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
            }
        } else if (Flags_GetCollectible(globalCtx, pthis->dyna.actor.params) != 0) {
            // If small key already collected, drop recovery heart instead
            collectibleParams = ITEM00_HEART;
            Common_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
        } else {
            // Drops a small key and sets a collect flag
            collectibleParams = ((pthis->dyna.actor.params & 0x3F) << 8) | ITEM00_SMALL_KEY;
            Common_PlaySfx(NA_SE_SY_CORRECT_CHIME);
        }
        if (collectibleParams != -1) {
            collectible = Item_DropCollectible(globalCtx, &spawnPos, collectibleParams);
            if (collectible != NULL) {
                collectible->actor.velocity.y = 15.0f;
                collectible->actor.world.rot.y = pthis->dyna.actor.shape.rot.y;
            }
        }
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgHakaTubo_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaTubo* pthis = (BgHakaTubo*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    pthis->fireScroll++;
}

void BgHakaTubo_DrawFlameCircle(BgHakaTubo* pthis, GlobalContext* globalCtx) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_tubo.c", 476);

    func_80093D84(globalCtx->state.gfxCtx);
    Matrix_Translate(pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y + 235.0f, pthis->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateY(pthis->dyna.actor.shape.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_Scale(0.07f, 0.04f, 0.07f, MTXMODE_APPLY);
    if (1) {}
    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 0, 170, 255, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 255, 255);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, pthis->fireScroll & 127, 0, 32, 64, 1, 0,
                                (pthis->fireScroll * -15) & 0xFF, 32, 64));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_tubo.c", 497),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gEffFireCircleDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_tubo.c", 501);
}

void BgHakaTubo_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaTubo* pthis = (BgHakaTubo*)thisx;

    Gfx_DrawDListOpa(globalCtx, object_haka_objects_DL_00FE40);
    BgHakaTubo_DrawFlameCircle(pthis, globalCtx);
}

void BgHakaTubo_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sZeroVector_34 = { 0.0f, 0.0f, 0.0f };

    Bg_Haka_Tubo_InitVars = {
        ACTOR_BG_HAKA_TUBO,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_HAKA_OBJECTS,
        sizeof(BgHakaTubo),
        (ActorFunc)BgHakaTubo_Init,
        (ActorFunc)BgHakaTubo_Destroy,
        (ActorFunc)BgHakaTubo_Update,
        (ActorFunc)BgHakaTubo_Draw,
        (ActorFunc)BgHakaTubo_Reset,
    };

    sPotColliderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000008, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 25, 60, 30, { 0, 0, 0 } },
    };

    sFlamesColliderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_NONE,
            OC1_ON | OC1_TYPE_PLAYER,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x20000000, 0x01, 0x04 },
            { 0x00000008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 60, 45, 235, { 0, 0, 0 } },
    };

    sPotsDestroyed = 0;

}
