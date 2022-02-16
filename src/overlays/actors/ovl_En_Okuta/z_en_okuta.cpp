#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_OKUTA_Z_EN_OKUTA_C
#include "actor_common.h"
#include "z_en_okuta.h"
#include "objects/object_okuta/object_okuta.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnOkuta_Init(Actor* thisx, GlobalContext* globalCtx);
void EnOkuta_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnOkuta_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnOkuta_Update(Actor* thisx, GlobalContext* globalCtx);
void EnOkuta_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnOkuta_SetupWaitToAppear(EnOkuta* pthis);
void EnOkuta_WaitToAppear(EnOkuta* pthis, GlobalContext* globalCtx);
void EnOkuta_Appear(EnOkuta* pthis, GlobalContext* globalCtx);
void EnOkuta_Hide(EnOkuta* pthis, GlobalContext* globalCtx);
void EnOkuta_WaitToShoot(EnOkuta* pthis, GlobalContext* globalCtx);
void EnOkuta_Shoot(EnOkuta* pthis, GlobalContext* globalCtx);
void EnOkuta_WaitToDie(EnOkuta* pthis, GlobalContext* globalCtx);
void EnOkuta_Die(EnOkuta* pthis, GlobalContext* globalCtx);
void EnOkuta_Freeze(EnOkuta* pthis, GlobalContext* globalCtx);
void EnOkuta_ProjectileFly(EnOkuta* pthis, GlobalContext* globalCtx);

static Vec3f accel_41 = { 0.0f, 0.0f, 0.0f };

static Color_RGBA8 primColor_41 = { 255, 255, 255, 255 };

static Color_RGBA8 envColor_41 = { 150, 150, 150, 255 };

static Vec3f accel_59 = { 0.0f, -0.5f, 0.0f };

static Color_RGBA8 primColor_59 = { 255, 255, 255, 255 };

static Color_RGBA8 envColor_59 = { 150, 150, 150, 0 };


ActorInit En_Okuta_InitVars = {
    ACTOR_EN_OKUTA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_OKUTA,
    sizeof(EnOkuta),
    (ActorFunc)EnOkuta_Init,
    (ActorFunc)EnOkuta_Destroy,
    (ActorFunc)EnOkuta_Update,
    (ActorFunc)EnOkuta_Draw,
    (ActorFunc)EnOkuta_Reset,
};

static ColliderCylinderInit sProjectileColliderInit = {
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
        TOUCH_ON | TOUCH_SFX_HARD,
        BUMP_ON,
        OCELEM_ON,
    },
    { 13, 20, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sOctorockColliderInit = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 40, -30, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 1, 15, 60, 100 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(1, 0x0),
    /* Normal arrow  */ DMG_ENTRY(2, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(2, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(2, 0x0),
    /* Ice arrow     */ DMG_ENTRY(4, 0x3),
    /* Light arrow   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
    /* Giant spin    */ DMG_ENTRY(4, 0x0),
    /* Master spin   */ DMG_ENTRY(2, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
    /* Giant jump    */ DMG_ENTRY(8, 0x0),
    /* Master jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x42, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 6500, ICHAIN_STOP),
};

void EnOkuta_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnOkuta* pthis = (EnOkuta*)thisx;
    s32 pad;
    WaterBox* outWaterBox;
    f32 ySurface;
    s32 sp30;

    Actor_ProcessInitChain(thisx, sInitChain);
    pthis->numShots = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;
    if (thisx->params == 0) {
        SkelAnime_Init(globalCtx, &pthis->skelAnime, &gOctorokSkel, &gOctorokAppearAnim, pthis->jointTable,
                       pthis->morphTable, 38);
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sOctorockColliderInit);
        CollisionCheck_SetInfo(&thisx->colChkInfo, &sDamageTable, &sColChkInfoInit);
        if ((pthis->numShots == 0xFF) || (pthis->numShots == 0)) {
            pthis->numShots = 1;
        }
        thisx->floorHeight =
            BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &thisx->floorPoly, &sp30, thisx, &thisx->world.pos);
        //! @bug calls WaterBox_GetSurfaceImpl directly
        if (!WaterBox_GetSurfaceImpl(globalCtx, &globalCtx->colCtx, thisx->world.pos.x, thisx->world.pos.z, &ySurface,
                                     &outWaterBox) ||
            (ySurface <= thisx->floorHeight)) {
            Actor_Kill(thisx);
        } else {
            thisx->home.pos.y = ySurface;
        }
        EnOkuta_SetupWaitToAppear(pthis);
    } else {
        ActorShape_Init(&thisx->shape, 1100.0f, ActorShadow_DrawCircle, 18.0f);
        thisx->flags &= ~ACTOR_FLAG_0;
        thisx->flags |= ACTOR_FLAG_4;
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sProjectileColliderInit);
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, thisx, ACTORCAT_PROP);
        pthis->timer = 30;
        thisx->shape.rot.y = 0;
        pthis->actionFunc = EnOkuta_ProjectileFly;
        thisx->speedXZ = 10.0f;
    }
}

void EnOkuta_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnOkuta* pthis = (EnOkuta*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnOkuta_SpawnBubbles(EnOkuta* pthis, GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i < 10; i++) {
        EffectSsBubble_Spawn(globalCtx, &pthis->actor.world.pos, -10.0f, 10.0f, 30.0f, 0.25f);
    }
}

void EnOkuta_SpawnDust(Vec3f* pos, Vec3f* velocity, s16 scaleStep, GlobalContext* globalCtx) {

    func_8002829C(globalCtx, pos, velocity, &accel_41, &primColor_41, &envColor_41, 0x190, scaleStep);
}

void EnOkuta_SpawnSplash(EnOkuta* pthis, GlobalContext* globalCtx) {
    EffectSsGSplash_Spawn(globalCtx, &pthis->actor.home.pos, NULL, NULL, 0, 1300);
}

void EnOkuta_SpawnRipple(EnOkuta* pthis, GlobalContext* globalCtx) {
    Vec3f pos;

    pos.x = pthis->actor.world.pos.x;
    pos.y = pthis->actor.home.pos.y;
    pos.z = pthis->actor.world.pos.z;
    if ((globalCtx->gameplayFrames % 7) == 0 &&
        ((pthis->actionFunc != EnOkuta_Shoot) || ((pthis->actor.world.pos.y - pthis->actor.home.pos.y) < 50.0f))) {
        EffectSsGRipple_Spawn(globalCtx, &pos, 250, 650, 0);
    }
}

void EnOkuta_SetupWaitToAppear(EnOkuta* pthis) {
    pthis->actor.draw = NULL;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionFunc = EnOkuta_WaitToAppear;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y;
}

void EnOkuta_SetupAppear(EnOkuta* pthis, GlobalContext* globalCtx) {
    pthis->actor.draw = EnOkuta_Draw;
    pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    pthis->actor.flags |= ACTOR_FLAG_0;
    Animation_PlayOnce(&pthis->skelAnime, &gOctorokAppearAnim);
    EnOkuta_SpawnBubbles(pthis, globalCtx);
    pthis->actionFunc = EnOkuta_Appear;
}

void EnOkuta_SetupHide(EnOkuta* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gOctorokHideAnim);
    pthis->actionFunc = EnOkuta_Hide;
}

void EnOkuta_SetupWaitToShoot(EnOkuta* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gOctorokFloatAnim);
    pthis->timer = (pthis->actionFunc == EnOkuta_Shoot) ? 2 : 0;
    pthis->actionFunc = EnOkuta_WaitToShoot;
}

void EnOkuta_SetupShoot(EnOkuta* pthis, GlobalContext* globalCtx) {
    Animation_PlayOnce(&pthis->skelAnime, &gOctorokShootAnim);
    if (pthis->actionFunc != EnOkuta_Shoot) {
        pthis->timer = pthis->numShots;
    }
    pthis->jumpHeight = pthis->actor.yDistToPlayer + 20.0f;
    pthis->jumpHeight = CLAMP_MIN(pthis->jumpHeight, 10.0f);
    if (pthis->jumpHeight > 50.0f) {
        EnOkuta_SpawnSplash(pthis, globalCtx);
    }
    if (pthis->jumpHeight > 50.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_JUMP);
    }
    pthis->actionFunc = EnOkuta_Shoot;
}

void EnOkuta_SetupWaitToDie(EnOkuta* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gOctorokHitAnim, -5.0f);
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0xB);
    pthis->collider.base.acFlags &= ~AC_HIT;
    Actor_SetScale(&pthis->actor, 0.01f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_DEAD1);
    pthis->actionFunc = EnOkuta_WaitToDie;
}

void EnOkuta_SetupDie(EnOkuta* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gOctorokDieAnim, -3.0f);
    pthis->timer = 0;
    pthis->actionFunc = EnOkuta_Die;
}

void EnOkuta_SetupFreeze(EnOkuta* pthis) {
    pthis->timer = 80;
    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 0x50);
    pthis->actionFunc = EnOkuta_Freeze;
}

void EnOkuta_SpawnProjectile(EnOkuta* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f velocity;
    f32 sin = Math_SinS(pthis->actor.shape.rot.y);
    f32 cos = Math_CosS(pthis->actor.shape.rot.y);

    pos.x = pthis->actor.world.pos.x + (25.0f * sin);
    pos.y = pthis->actor.world.pos.y - 6.0f;
    pos.z = pthis->actor.world.pos.z + (25.0f * cos);
    if (Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_OKUTA, pos.x, pos.y, pos.z, pthis->actor.shape.rot.x,
                    pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, 0x10) != NULL) {
        pos.x = pthis->actor.world.pos.x + (40.0f * sin);
        pos.z = pthis->actor.world.pos.z + (40.0f * cos);
        pos.y = pthis->actor.world.pos.y;
        velocity.x = 1.5f * sin;
        velocity.y = 0.0f;
        velocity.z = 1.5f * cos;
        EnOkuta_SpawnDust(&pos, &velocity, 20, globalCtx);
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_THROW);
}

void EnOkuta_WaitToAppear(EnOkuta* pthis, GlobalContext* globalCtx) {
    pthis->actor.world.pos.y = pthis->actor.home.pos.y;
    if ((pthis->actor.xzDistToPlayer < 480.0f) && (pthis->actor.xzDistToPlayer > 200.0f)) {
        EnOkuta_SetupAppear(pthis, globalCtx);
    }
}

void EnOkuta_Appear(EnOkuta* pthis, GlobalContext* globalCtx) {
    s32 pad;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.xzDistToPlayer < 160.0f) {
            EnOkuta_SetupHide(pthis);
        } else {
            EnOkuta_SetupWaitToShoot(pthis);
        }
    } else if (pthis->skelAnime.curFrame <= 4.0f) {
        Actor_SetScale(&pthis->actor, pthis->skelAnime.curFrame * 0.25f * 0.01f);
    } else if (Animation_OnFrame(&pthis->skelAnime, 5.0f)) {
        Actor_SetScale(&pthis->actor, 0.01f);
    }
    if (Animation_OnFrame(&pthis->skelAnime, 2.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_JUMP);
    }
    if (Animation_OnFrame(&pthis->skelAnime, 12.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_LAND);
    }
    if (Animation_OnFrame(&pthis->skelAnime, 3.0f) || Animation_OnFrame(&pthis->skelAnime, 15.0f)) {
        EnOkuta_SpawnSplash(pthis, globalCtx);
    }
}

void EnOkuta_Hide(EnOkuta* pthis, GlobalContext* globalCtx) {
    s32 pad;

    Math_ApproachF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.5f, 30.0f);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_BUBLE);
        EnOkuta_SpawnBubbles(pthis, globalCtx);
        EnOkuta_SetupWaitToAppear(pthis);
    } else if (pthis->skelAnime.curFrame >= 4.0f) {
        Actor_SetScale(&pthis->actor, (6.0f - pthis->skelAnime.curFrame) * 0.5f * 0.01f);
    }
    if (Animation_OnFrame(&pthis->skelAnime, 2.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_SINK);
    }
    if (Animation_OnFrame(&pthis->skelAnime, 4.0f)) {
        EnOkuta_SpawnSplash(pthis, globalCtx);
    }
}

void EnOkuta_WaitToShoot(EnOkuta* pthis, GlobalContext* globalCtx) {
    s16 temp_v0_2;
    s32 phi_v1;

    pthis->actor.world.pos.y = pthis->actor.home.pos.y;
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }
    }
    if (Animation_OnFrame(&pthis->skelAnime, 0.5f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_FLOAT);
    }
    if (pthis->actor.xzDistToPlayer < 160.0f || pthis->actor.xzDistToPlayer > 560.0f) {
        EnOkuta_SetupHide(pthis);
    } else {
        temp_v0_2 = Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x71C, 0x38E);
        phi_v1 = ABS(temp_v0_2);
        if ((phi_v1 < 0x38E) && (pthis->timer == 0) && (pthis->actor.yDistToPlayer < 200.0f)) {
            EnOkuta_SetupShoot(pthis, globalCtx);
        }
    }
}

void EnOkuta_Shoot(EnOkuta* pthis, GlobalContext* globalCtx) {
    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x71C);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }
        if (pthis->timer == 0) {
            EnOkuta_SetupWaitToShoot(pthis);
        } else {
            EnOkuta_SetupShoot(pthis, globalCtx);
        }
    } else {
        f32 curFrame = pthis->skelAnime.curFrame;

        if (curFrame < 13.0f) {
            pthis->actor.world.pos.y = (sinf((0.08333f * M_PI) * curFrame) * pthis->jumpHeight) + pthis->actor.home.pos.y;
        }
        if (Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
            EnOkuta_SpawnProjectile(pthis, globalCtx);
        }
        if ((pthis->jumpHeight > 50.0f) && Animation_OnFrame(&pthis->skelAnime, 13.0f)) {
            EnOkuta_SpawnSplash(pthis, globalCtx);
        }
        if ((pthis->jumpHeight > 50.0f) && Animation_OnFrame(&pthis->skelAnime, 13.0f)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_LAND);
        }
    }
    if (pthis->actor.xzDistToPlayer < 160.0f) {
        EnOkuta_SetupHide(pthis);
    }
}

void EnOkuta_WaitToDie(EnOkuta* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnOkuta_SetupDie(pthis);
    }
    Math_ApproachF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.5f, 5.0f);
}

void EnOkuta_Die(EnOkuta* pthis, GlobalContext* globalCtx) {
    Vec3f velocity;
    Vec3f pos;
    s32 i;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->timer++;
    }
    Math_ApproachF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.5f, 5.0f);
    if (pthis->timer == 5) {
        pos.x = pthis->actor.world.pos.x;
        pos.y = pthis->actor.world.pos.y + 40.0f;
        pos.z = pthis->actor.world.pos.z;
        velocity.x = 0.0f;
        velocity.y = -0.5f;
        velocity.z = 0.0f;
        EnOkuta_SpawnDust(&pos, &velocity, -0x14, globalCtx);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_DEAD2);
    }
    if (Animation_OnFrame(&pthis->skelAnime, 15.0f)) {
        EnOkuta_SpawnSplash(pthis, globalCtx);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_LAND);
    }
    if (pthis->timer < 3) {
        Actor_SetScale(&pthis->actor, ((pthis->timer * 0.25f) + 1.0f) * 0.01f);
    } else if (pthis->timer < 6) {
        Actor_SetScale(&pthis->actor, (1.5f - ((pthis->timer - 2) * 0.2333f)) * 0.01f);
    } else if (pthis->timer < 11) {
        Actor_SetScale(&pthis->actor, (((pthis->timer - 5) * 0.04f) + 0.8f) * 0.01f);
    } else {
        if (Math_StepToF(&pthis->actor.scale.x, 0.0f, 0.0005f)) {
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 30, NA_SE_EN_OCTAROCK_BUBLE);
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x70);
            for (i = 0; i < 20; i++) {
                velocity.x = (Rand_ZeroOne() - 0.5f) * 7.0f;
                velocity.y = Rand_ZeroOne() * 7.0f;
                velocity.z = (Rand_ZeroOne() - 0.5f) * 7.0f;
                EffectSsDtBubble_SpawnCustomColor(globalCtx, &pthis->actor.world.pos, &velocity, &accel_59, &primColor_59,
                                                  &envColor_59, Rand_S16Offset(100, 50), 25, 0);
            }
            Actor_Kill(&pthis->actor);
        }
        pthis->actor.scale.y = pthis->actor.scale.z = pthis->actor.scale.x;
    }
}

void EnOkuta_Freeze(EnOkuta* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    s16 temp_v1;

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        EnOkuta_SetupDie(pthis);
    }
    if ((pthis->timer >= 64) && (pthis->timer & 1)) {
        temp_v1 = (pthis->timer - 64) >> 1;
        pos.y = (pthis->actor.world.pos.y - 32.0f) + (8.0f * (8 - temp_v1));
        pos.x = pthis->actor.world.pos.x + ((temp_v1 & 2) ? 10.0f : -10.0f);
        pos.z = pthis->actor.world.pos.z + ((temp_v1 & 1) ? 10.0f : -10.0f);
        EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &pos, 150, 150, 150, 250, 235, 245, 255,
                                       (Rand_ZeroOne() * 0.2f) + 1.9f);
    }
    Math_ApproachF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.5f, 5.0f);
}

void EnOkuta_ProjectileFly(EnOkuta* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Player* player = GET_PLAYER(globalCtx);
    Vec3s sp40;

    pthis->timer--;
    if (pthis->timer == 0) {
        pthis->actor.gravity = -1.0f;
    }
    pthis->actor.home.rot.z += 0x1554;
    if (pthis->actor.bgCheckFlags & 0x20) {
        pthis->actor.gravity = -1.0f;
        pthis->actor.speedXZ -= 0.1f;
        pthis->actor.speedXZ = CLAMP_MIN(pthis->actor.speedXZ, 1.0f);
    }
    if ((pthis->actor.bgCheckFlags & 8) || (pthis->actor.bgCheckFlags & 1) || (pthis->collider.base.atFlags & AT_HIT) ||
        pthis->collider.base.acFlags & AC_HIT || pthis->collider.base.ocFlags1 & OC1_HIT ||
        pthis->actor.floorHeight == BGCHECK_Y_MIN) {
        if ((player->currentShield == PLAYER_SHIELD_DEKU ||
             (player->currentShield == PLAYER_SHIELD_HYLIAN && LINK_IS_ADULT)) &&
            pthis->collider.base.atFlags & AT_HIT && pthis->collider.base.atFlags & AT_TYPE_ENEMY &&
            pthis->collider.base.atFlags & AT_BOUNCED) {
            pthis->collider.base.atFlags &= ~(AT_HIT | AT_BOUNCED | AT_TYPE_ENEMY);
            pthis->collider.base.atFlags |= AT_TYPE_PLAYER;
            pthis->collider.info.toucher.dmgFlags = 2;
            Matrix_MtxFToYXZRotS(&player->shieldMf, &sp40, 0);
            pthis->actor.world.rot.y = sp40.y + 0x8000;
            pthis->timer = 30;
        } else {
            pos.x = pthis->actor.world.pos.x;
            pos.y = pthis->actor.world.pos.y + 11.0f;
            pos.z = pthis->actor.world.pos.z;
            EffectSsHahen_SpawnBurst(globalCtx, &pos, 6.0f, 0, 1, 2, 15, 7, 10, gOctorokProjectileDL);
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EN_OCTAROCK_ROCK);
            Actor_Kill(&pthis->actor);
        }
    } else if (pthis->timer == -300) {
        Actor_Kill(&pthis->actor);
    }
}

void EnOkuta_UpdateHeadScale(EnOkuta* pthis) {
    f32 curFrame = pthis->skelAnime.curFrame;

    if (pthis->actionFunc == EnOkuta_Appear) {
        if (curFrame < 8.0f) {
            pthis->headScale.x = pthis->headScale.y = pthis->headScale.z = 1.0f;
        } else if (curFrame < 10.0f) {
            pthis->headScale.x = pthis->headScale.z = 1.0f;
            pthis->headScale.y = ((curFrame - 7.0f) * 0.4f) + 1.0f;
        } else if (curFrame < 14.0f) {
            pthis->headScale.x = pthis->headScale.z = ((curFrame - 9.0f) * 0.075f) + 1.0f;
            pthis->headScale.y = 1.8f - ((curFrame - 9.0f) * 0.25f);
        } else {
            pthis->headScale.x = pthis->headScale.z = 1.3f - ((curFrame - 13.0f) * 0.05f);
            pthis->headScale.y = ((curFrame - 13.0f) * 0.0333f) + 0.8f;
        }
    } else if (pthis->actionFunc == EnOkuta_Hide) {
        if (curFrame < 3.0f) {
            pthis->headScale.y = 1.0f;
        } else if (curFrame < 4.0f) {
            pthis->headScale.y = (curFrame - 2.0f) + 1.0f;
        } else {
            pthis->headScale.y = 2.0f - ((curFrame - 3.0f) * 0.333f);
        }
        pthis->headScale.x = pthis->headScale.z = 1.0f;
    } else if (pthis->actionFunc == EnOkuta_Shoot) {
        if (curFrame < 5.0f) {
            pthis->headScale.x = pthis->headScale.y = pthis->headScale.z = (curFrame * 0.125f) + 1.0f;
        } else if (curFrame < 7.0f) {
            pthis->headScale.x = pthis->headScale.y = pthis->headScale.z = 1.5f - ((curFrame - 4.0f) * 0.35f);
        } else if (curFrame < 17.0f) {
            pthis->headScale.x = pthis->headScale.z = ((curFrame - 6.0f) * 0.05f) + 0.8f;
            pthis->headScale.y = 0.8f;
        } else {
            pthis->headScale.x = pthis->headScale.z = 1.3f - ((curFrame - 16.0f) * 0.1f);
            pthis->headScale.y = ((curFrame - 16.0f) * 0.0666f) + 0.8f;
        }
    } else if (pthis->actionFunc == EnOkuta_WaitToShoot) {
        pthis->headScale.x = pthis->headScale.z = 1.0f;
        pthis->headScale.y = (sinf((M_PI / 16) * curFrame) * 0.2f) + 1.0f;
    } else {
        pthis->headScale.x = pthis->headScale.y = pthis->headScale.z = 1.0f;
    }
}

void EnOkuta_ColliderCheck(EnOkuta* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);
        if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
            Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
            pthis->actor.colChkInfo.health = 0;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            if (pthis->actor.colChkInfo.damageEffect == 3) {
                EnOkuta_SetupFreeze(pthis);
            } else {
                EnOkuta_SetupWaitToDie(pthis);
            }
        }
    }
}

void EnOkuta_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnOkuta* pthis = (EnOkuta*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    Player* player = GET_PLAYER(globalCtx);
    WaterBox* outWaterBox;
    f32 ySurface;
    Vec3f sp38;
    s32 sp34;

    if (!(player->stateFlags1 & 0x300000C0)) {
        if (pthis->actor.params == 0) {
            EnOkuta_ColliderCheck(pthis, globalCtx);
            if (!WaterBox_GetSurfaceImpl(globalCtx, &globalCtx->colCtx, pthis->actor.world.pos.x,
                                         pthis->actor.world.pos.z, &ySurface, &outWaterBox) ||
                (ySurface < pthis->actor.floorHeight)) {
                if (pthis->actor.colChkInfo.health != 0) {
                    Actor_Kill(&pthis->actor);
                    return;
                }
            } else {
                pthis->actor.home.pos.y = ySurface;
            }
        }
        pthis->actionFunc(pthis, globalCtx);
        if (pthis->actor.params == 0) {
            EnOkuta_UpdateHeadScale(pthis);
            pthis->collider.dim.height =
                (((sOctorockColliderInit.dim.height * pthis->headScale.y) - pthis->collider.dim.yShift) *
                 pthis->actor.scale.y * 100.0f);
        } else {
            sp34 = false;
            Actor_MoveForward(&pthis->actor);
            Math_Vec3f_Copy(&sp38, &pthis->actor.world.pos);
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 15.0f, 30.0f, 5);
            if ((pthis->actor.bgCheckFlags & 8) &&
                SurfaceType_IsIgnoredByProjectiles(&globalCtx->colCtx, pthis->actor.wallPoly, pthis->actor.wallBgId)) {
                sp34 = true;
                pthis->actor.bgCheckFlags &= ~8;
            }
            if ((pthis->actor.bgCheckFlags & 1) &&
                SurfaceType_IsIgnoredByProjectiles(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId)) {
                sp34 = true;
                pthis->actor.bgCheckFlags &= ~1;
            }
            if (sp34 && !(pthis->actor.bgCheckFlags & 9)) {
                Math_Vec3f_Copy(&pthis->actor.world.pos, &sp38);
            }
        }
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        if ((pthis->actionFunc == EnOkuta_Appear) || (pthis->actionFunc == EnOkuta_Hide)) {
            pthis->collider.dim.pos.y = pthis->actor.world.pos.y + (pthis->skelAnime.jointTable->y * pthis->actor.scale.y);
            pthis->collider.dim.radius = sOctorockColliderInit.dim.radius * pthis->actor.scale.x * 100.0f;
        }
        if (pthis->actor.params == 0x10) {
            pthis->actor.flags |= ACTOR_FLAG_24;
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        if (pthis->actionFunc != EnOkuta_WaitToAppear) {
            if ((pthis->actionFunc != EnOkuta_Die) && (pthis->actionFunc != EnOkuta_WaitToDie) &&
                (pthis->actionFunc != EnOkuta_Freeze)) {
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        Actor_SetFocus(&pthis->actor, 15.0f);
        if ((pthis->actor.params == 0) && (pthis->actor.draw != NULL)) {
            EnOkuta_SpawnRipple(pthis, globalCtx);
        }
    }
}

s32 EnOkuta_GetSnoutScale(EnOkuta* pthis, f32 curFrame, Vec3f* scale) {
    if (pthis->actionFunc == EnOkuta_WaitToShoot) {
        scale->x = scale->z = 1.0f;
        scale->y = (sinf((M_PI / 16) * curFrame) * 0.4f) + 1.0f;
    } else if (pthis->actionFunc == EnOkuta_Shoot) {
        if (curFrame < 5.0f) {
            scale->x = 1.0f;
            scale->y = scale->z = (curFrame * 0.25f) + 1.0f;
        } else if (curFrame < 7.0f) {
            scale->x = (curFrame - 4.0f) * 0.5f + 1.0f;
            scale->y = scale->z = 2.0f - (curFrame - 4.0f) * 0.5f;
        } else {
            scale->x = 2.0f - ((curFrame - 6.0f) * 0.0769f);
            scale->y = scale->z = 1.0f;
        }
    } else if (pthis->actionFunc == EnOkuta_Die) {
        if (curFrame >= 35.0f || curFrame < 25.0f) {
            return false;
        }
        if (curFrame < 27.0f) {
            scale->x = 1.0f;
            scale->y = scale->z = ((curFrame - 24.0f) * 0.5f) + 1.0f;
        } else if (curFrame < 30.0f) {
            scale->x = (curFrame - 26.0f) * 0.333f + 1.0f;
            scale->y = scale->z = 2.0f - (curFrame - 26.0f) * 0.333f;
        } else {
            scale->x = 2.0f - ((curFrame - 29.0f) * 0.2f);
            scale->y = scale->z = 1.0f;
        }
    } else {
        return false;
    }

    return true;
}

s32 EnOkuta_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                             void* thisx) {
    EnOkuta* pthis = (EnOkuta*)thisx;
    f32 curFrame = pthis->skelAnime.curFrame;
    Vec3f scale;
    s32 doScale = false;

    if (pthis->actionFunc == EnOkuta_Die) {
        curFrame += pthis->timer;
    }
    if (limbIndex == 5) {
        if ((pthis->headScale.x != 1.0f) || (pthis->headScale.y != 1.0f) || (pthis->headScale.z != 1.0f)) {
            scale = pthis->headScale;
            doScale = true;
        }
    } else if (limbIndex == 8) {
        doScale = EnOkuta_GetSnoutScale(pthis, curFrame, &scale);
    }
    if (doScale) {
        Matrix_Scale(scale.x, scale.y, scale.z, MTXMODE_APPLY);
    }
    return false;
}

void EnOkuta_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnOkuta* pthis = (EnOkuta*)thisx;
    s32 pad;

    func_80093D18(globalCtx->state.gfxCtx);

    if (pthis->actor.params == 0) {
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnOkuta_OverrideLimbDraw,
                          NULL, pthis);
    } else {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_okuta.c", 1653);

        Matrix_Mult(&globalCtx->billboardMtxF, MTXMODE_APPLY);
        Matrix_RotateZ(pthis->actor.home.rot.z * (M_PI / 0x8000), MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_okuta.c", 1657),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gOctorokProjectileDL);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_okuta.c", 1662);
    }
}

void EnOkuta_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    accel_41 = { 0.0f, 0.0f, 0.0f };

    primColor_41 = { 255, 255, 255, 255 };

    envColor_41 = { 150, 150, 150, 255 };

    accel_59 = { 0.0f, -0.5f, 0.0f };

    primColor_59 = { 255, 255, 255, 255 };

    envColor_59 = { 150, 150, 150, 0 };

    En_Okuta_InitVars = {
        ACTOR_EN_OKUTA,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_OKUTA,
        sizeof(EnOkuta),
        (ActorFunc)EnOkuta_Init,
        (ActorFunc)EnOkuta_Destroy,
        (ActorFunc)EnOkuta_Update,
        (ActorFunc)EnOkuta_Draw,
        (ActorFunc)EnOkuta_Reset,
    };

    sProjectileColliderInit = {
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
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 13, 20, 0, { 0, 0, 0 } },
    };

    sOctorockColliderInit = {
        {
            COLTYPE_HIT0,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK1,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 20, 40, -30, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 1, 15, 60, 100 };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, 0x0),
        /* Deku stick    */ DMG_ENTRY(2, 0x0),
        /* Slingshot     */ DMG_ENTRY(1, 0x0),
        /* Explosive     */ DMG_ENTRY(2, 0x0),
        /* Boomerang     */ DMG_ENTRY(1, 0x0),
        /* Normal arrow  */ DMG_ENTRY(2, 0x0),
        /* Hammer swing  */ DMG_ENTRY(2, 0x0),
        /* Hookshot      */ DMG_ENTRY(2, 0x0),
        /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
        /* Master sword  */ DMG_ENTRY(2, 0x0),
        /* Giant's Knife */ DMG_ENTRY(4, 0x0),
        /* Fire arrow    */ DMG_ENTRY(2, 0x0),
        /* Ice arrow     */ DMG_ENTRY(4, 0x3),
        /* Light arrow   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
        /* Fire magic    */ DMG_ENTRY(0, 0x0),
        /* Ice magic     */ DMG_ENTRY(0, 0x0),
        /* Light magic   */ DMG_ENTRY(0, 0x0),
        /* Shield        */ DMG_ENTRY(0, 0x0),
        /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
        /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
        /* Giant spin    */ DMG_ENTRY(4, 0x0),
        /* Master spin   */ DMG_ENTRY(2, 0x0),
        /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
        /* Giant jump    */ DMG_ENTRY(8, 0x0),
        /* Master jump   */ DMG_ENTRY(4, 0x0),
        /* Unknown 1     */ DMG_ENTRY(0, 0x0),
        /* Unblockable   */ DMG_ENTRY(0, 0x0),
        /* Hammer jump   */ DMG_ENTRY(4, 0x0),
        /* Unknown 2     */ DMG_ENTRY(0, 0x0),
    };

}
