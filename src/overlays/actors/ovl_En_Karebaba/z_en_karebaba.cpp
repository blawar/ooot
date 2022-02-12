#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_KAREBABA_Z_EN_KAREBABA_C
#include "actor_common.h"
/**
 * File: z_en_karebaba.c
 * Overlay: ovl_En_Karebaba
 * Description: Withered Deku Baba
 */

#include "z_en_karebaba.h"
#include "objects/object_dekubaba/object_dekubaba.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_eff_ss_dead.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnKarebaba_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKarebaba_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKarebaba_Update(Actor* thisx, GlobalContext* globalCtx);
void EnKarebaba_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnKarebaba_SetupGrow(EnKarebaba* pthis);
void EnKarebaba_SetupIdle(EnKarebaba* pthis);
void EnKarebaba_Grow(EnKarebaba* pthis, GlobalContext* globalCtx);
void EnKarebaba_Idle(EnKarebaba* pthis, GlobalContext* globalCtx);
void EnKarebaba_Awaken(EnKarebaba* pthis, GlobalContext* globalCtx);
void EnKarebaba_Spin(EnKarebaba* pthis, GlobalContext* globalCtx);
void EnKarebaba_Dying(EnKarebaba* pthis, GlobalContext* globalCtx);
void EnKarebaba_DeadItemDrop(EnKarebaba* pthis, GlobalContext* globalCtx);
void EnKarebaba_Retract(EnKarebaba* pthis, GlobalContext* globalCtx);
void EnKarebaba_Dead(EnKarebaba* pthis, GlobalContext* globalCtx);
void EnKarebaba_Regrow(EnKarebaba* pthis, GlobalContext* globalCtx);
void EnKarebaba_Upright(EnKarebaba* pthis, GlobalContext* globalCtx);

ActorInit En_Karebaba_InitVars = {
    ACTOR_EN_KAREBABA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DEKUBABA,
    sizeof(EnKarebaba),
    (ActorFunc)EnKarebaba_Init,
    (ActorFunc)EnKarebaba_Destroy,
    (ActorFunc)EnKarebaba_Update,
    (ActorFunc)EnKarebaba_Draw,
};

static ColliderCylinderInit sBodyColliderInit = {
    {
        COLTYPE_HARD,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 7, 25, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sHeadColliderInit = {
    {
        COLTYPE_HARD,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_HARD,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 4, 25, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColCheckInfoInit = { 1, 15, 80, MASS_HEAVY };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 2500, ICHAIN_CONTINUE),
    ICHAIN_U8(targetMode, 1, ICHAIN_CONTINUE),
    ICHAIN_S8(naviEnemyId, 0x09, ICHAIN_STOP),
};

void EnKarebaba_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnKarebaba* pthis = (EnKarebaba*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 22.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gDekuBabaSkel, &gDekuBabaFastChompAnim, pthis->jointTable,
                   pthis->morphTable, 8);
    Collider_InitCylinder(globalCtx, &pthis->bodyCollider);
    Collider_SetCylinder(globalCtx, &pthis->bodyCollider, &pthis->actor, &sBodyColliderInit);
    Collider_UpdateCylinder(&pthis->actor, &pthis->bodyCollider);
    Collider_InitCylinder(globalCtx, &pthis->headCollider);
    Collider_SetCylinder(globalCtx, &pthis->headCollider, &pthis->actor, &sHeadColliderInit);
    Collider_UpdateCylinder(&pthis->actor, &pthis->headCollider);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, DamageTable_Get(1), &sColCheckInfoInit);

    pthis->boundFloor = NULL;

    if (pthis->actor.params == 0) {
        EnKarebaba_SetupGrow(pthis);
    } else {
        EnKarebaba_SetupIdle(pthis);
    }
}

void EnKarebaba_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnKarebaba* pthis = (EnKarebaba*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->bodyCollider);
    Collider_DestroyCylinder(globalCtx, &pthis->headCollider);
}

void EnKarebaba_ResetCollider(EnKarebaba* pthis) {
    pthis->bodyCollider.dim.radius = 7;
    pthis->bodyCollider.dim.height = 25;
    pthis->bodyCollider.base.colType = COLTYPE_HARD;
    pthis->bodyCollider.base.acFlags |= AC_HARD;
    pthis->bodyCollider.info.bumper.dmgFlags = ~0x00300000;
    pthis->headCollider.dim.height = 25;
}

void EnKarebaba_SetupGrow(EnKarebaba* pthis) {
    Actor_SetScale(&pthis->actor, 0.0f);
    pthis->actor.shape.rot.x = -0x4000;
    pthis->actionFunc = EnKarebaba_Grow;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + 14.0f;
}

void EnKarebaba_SetupIdle(EnKarebaba* pthis) {
    Actor_SetScale(&pthis->actor, 0.005f);
    pthis->actor.shape.rot.x = -0x4000;
    pthis->actionFunc = EnKarebaba_Idle;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + 14.0f;
}

void EnKarebaba_SetupAwaken(EnKarebaba* pthis) {
    Animation_Change(&pthis->skelAnime, &gDekuBabaFastChompAnim, 4.0f, 0.0f,
                     Animation_GetLastFrame(&gDekuBabaFastChompAnim), ANIMMODE_LOOP, -3.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DUMMY482);
    pthis->actionFunc = EnKarebaba_Awaken;
}

void EnKarebaba_SetupUpright(EnKarebaba* pthis) {
    if (pthis->actionFunc != EnKarebaba_Spin) {
        Actor_SetScale(&pthis->actor, 0.01f);
        pthis->bodyCollider.base.colType = COLTYPE_HIT6;
        pthis->bodyCollider.base.acFlags &= ~AC_HARD;
        pthis->bodyCollider.info.bumper.dmgFlags = !LINK_IS_ADULT ? 0x07C00710 : 0x0FC00710;
        pthis->bodyCollider.dim.radius = 15;
        pthis->bodyCollider.dim.height = 80;
        pthis->headCollider.dim.height = 80;
    }

    pthis->actor.params = 40;
    pthis->actionFunc = EnKarebaba_Upright;
}

void EnKarebaba_SetupSpin(EnKarebaba* pthis) {
    pthis->actor.params = 40;
    pthis->actionFunc = EnKarebaba_Spin;
}

void EnKarebaba_SetupDying(EnKarebaba* pthis) {
    pthis->actor.params = 0;
    pthis->actor.gravity = -0.8f;
    pthis->actor.velocity.y = 4.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x8000;
    pthis->actor.speedXZ = 3.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_JR_DEAD);
    pthis->actor.flags |= ACTOR_FLAG_4 | ACTOR_FLAG_5;
    pthis->actionFunc = EnKarebaba_Dying;
}

void EnKarebaba_SetupDeadItemDrop(EnKarebaba* pthis, GlobalContext* globalCtx) {
    Actor_SetScale(&pthis->actor, 0.03f);
    pthis->actor.shape.rot.x -= 0x4000;
    pthis->actor.shape.yOffset = 1000.0f;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.shape.shadowScale = 3.0f;
    Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_MISC);
    pthis->actor.params = 200;
    pthis->actor.flags &= ~ACTOR_FLAG_5;
    pthis->actionFunc = EnKarebaba_DeadItemDrop;
}

void EnKarebaba_SetupRetract(EnKarebaba* pthis) {
    Animation_Change(&pthis->skelAnime, &gDekuBabaFastChompAnim, -3.0f, Animation_GetLastFrame(&gDekuBabaFastChompAnim),
                     0.0f, ANIMMODE_ONCE, -3.0f);
    EnKarebaba_ResetCollider(pthis);
    pthis->actionFunc = EnKarebaba_Retract;
}

void EnKarebaba_SetupDead(EnKarebaba* pthis) {
    Animation_Change(&pthis->skelAnime, &gDekuBabaFastChompAnim, 0.0f, 0.0f, 0.0f, ANIMMODE_ONCE, 0.0f);
    EnKarebaba_ResetCollider(pthis);
    pthis->actor.shape.rot.x = -0x4000;
    pthis->actor.params = 200;
    pthis->actor.parent = NULL;
    pthis->actor.shape.shadowScale = 0.0f;
    Math_Vec3f_Copy(&pthis->actor.world.pos, &pthis->actor.home.pos);
    pthis->actionFunc = EnKarebaba_Dead;
}

void EnKarebaba_SetupRegrow(EnKarebaba* pthis) {
    pthis->actor.shape.yOffset = 0.0f;
    pthis->actor.shape.shadowScale = 22.0f;
    pthis->headCollider.dim.radius = sHeadColliderInit.dim.radius;
    Actor_SetScale(&pthis->actor, 0.0f);
    pthis->actionFunc = EnKarebaba_Regrow;
}

void EnKarebaba_Grow(EnKarebaba* pthis, GlobalContext* globalCtx) {
    f32 scale;

    pthis->actor.params++;
    scale = pthis->actor.params * 0.05f;
    Actor_SetScale(&pthis->actor, 0.005f * scale);
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + (14.0f * scale);
    if (pthis->actor.params == 20) {
        EnKarebaba_SetupIdle(pthis);
    }
}

void EnKarebaba_Idle(EnKarebaba* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.xzDistToPlayer < 200.0f && fabsf(pthis->actor.yDistToPlayer) < 30.0f) {
        EnKarebaba_SetupAwaken(pthis);
    }
}

void EnKarebaba_Awaken(EnKarebaba* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToF(&pthis->actor.scale.x, 0.01f, 0.0005f);
    pthis->actor.scale.y = pthis->actor.scale.z = pthis->actor.scale.x;
    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 60.0f, 5.0f)) {
        EnKarebaba_SetupUpright(pthis);
    }
    pthis->actor.shape.rot.y += 0x1999;
    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.home.pos, 3.0f, 0, 12, 5, 1, HAHEN_OBJECT_DEFAULT, 10, NULL);
}

void EnKarebaba_Upright(EnKarebaba* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.params != 0) {
        pthis->actor.params--;
    }

    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 12.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_JR_MOUTH);
    }

    if (pthis->bodyCollider.base.acFlags & AC_HIT) {
        EnKarebaba_SetupDying(pthis);
        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
    } else if (Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) > 240.0f) {
        EnKarebaba_SetupRetract(pthis);
    } else if (pthis->actor.params == 0) {
        EnKarebaba_SetupSpin(pthis);
    }
}

void EnKarebaba_Spin(EnKarebaba* pthis, GlobalContext* globalCtx) {
    s32 value;
    f32 cos60;

    if (pthis->actor.params != 0) {
        pthis->actor.params--;
    }

    SkelAnime_Update(&pthis->skelAnime);

    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 12.0f)) {
        if (1) {} // Here for matching purposes only.

        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_JR_MOUTH);
    }

    value = 20 - pthis->actor.params;
    value = 20 - ABS(value);

    if (value > 10) {
        value = 10;
    }

    pthis->headCollider.dim.radius = sHeadColliderInit.dim.radius + (value * 2);
    pthis->actor.shape.rot.x = 0xC000 - (value * 0x100);
    pthis->actor.shape.rot.y += value * 0x2C0;
    pthis->actor.world.pos.y = (Math_SinS(pthis->actor.shape.rot.x) * -60.0f) + pthis->actor.home.pos.y;

    cos60 = Math_CosS(pthis->actor.shape.rot.x) * 60.0f;

    pthis->actor.world.pos.x = (Math_SinS(pthis->actor.shape.rot.y) * cos60) + pthis->actor.home.pos.x;
    pthis->actor.world.pos.z = (Math_CosS(pthis->actor.shape.rot.y) * cos60) + pthis->actor.home.pos.z;

    if (pthis->bodyCollider.base.acFlags & AC_HIT) {
        EnKarebaba_SetupDying(pthis);
        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
    } else if (pthis->actor.params == 0) {
        EnKarebaba_SetupUpright(pthis);
    }
}

void EnKarebaba_Dying(EnKarebaba* pthis, GlobalContext* globalCtx) {
    static Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    s32 i;
    Vec3f position;
    Vec3f rotation;

    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.1f);

    if (pthis->actor.params == 0) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x4800, 0x71C);
        EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 3.0f, 0, 12, 5, 1, HAHEN_OBJECT_DEFAULT, 10, NULL);

        if (pthis->actor.scale.x > 0.005f && ((pthis->actor.bgCheckFlags & 2) || (pthis->actor.bgCheckFlags & 8))) {
            pthis->actor.scale.x = pthis->actor.scale.y = pthis->actor.scale.z = 0.0f;
            pthis->actor.speedXZ = 0.0f;
            pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
            EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 3.0f, 0, 12, 5, 15, HAHEN_OBJECT_DEFAULT, 10,
                                     NULL);
        }

        if (pthis->actor.bgCheckFlags & 2) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
            pthis->actor.params = 1;
        }
    } else if (pthis->actor.params == 1) {
        Math_Vec3f_Copy(&position, &pthis->actor.world.pos);
        rotation.z = Math_SinS(pthis->actor.shape.rot.x) * 20.0f;
        rotation.x = -20.0f * Math_CosS(pthis->actor.shape.rot.x) * Math_SinS(pthis->actor.shape.rot.y);
        rotation.y = -20.0f * Math_CosS(pthis->actor.shape.rot.x) * Math_CosS(pthis->actor.shape.rot.y);

        for (i = 0; i < 4; i++) {
            func_800286CC(globalCtx, &position, &zeroVec, &zeroVec, 500, 50);
            position.x += rotation.x;
            position.y += rotation.z;
            position.z += rotation.y;
        }

        func_800286CC(globalCtx, &pthis->actor.home.pos, &zeroVec, &zeroVec, 500, 100);
        EnKarebaba_SetupDeadItemDrop(pthis, globalCtx);
    }
}

void EnKarebaba_DeadItemDrop(EnKarebaba* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.params != 0) {
        pthis->actor.params--;
    }

    if (Actor_HasParent(&pthis->actor, globalCtx) || pthis->actor.params == 0) {
        EnKarebaba_SetupDead(pthis);
    } else {
        func_8002F554(&pthis->actor, globalCtx, GI_STICKS_1);
    }
}

void EnKarebaba_Retract(EnKarebaba* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToF(&pthis->actor.scale.x, 0.005f, 0.0005f);
    pthis->actor.scale.y = pthis->actor.scale.z = pthis->actor.scale.x;

    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 14.0f, 5.0f)) {
        EnKarebaba_SetupIdle(pthis);
    }

    pthis->actor.shape.rot.y += 0x1999;
    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.home.pos, 3.0f, 0, 12, 5, 1, HAHEN_OBJECT_DEFAULT, 10, NULL);
}

void EnKarebaba_Dead(EnKarebaba* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.params != 0) {
        pthis->actor.params--;
    }
    if (pthis->actor.params == 0) {
        EnKarebaba_SetupRegrow(pthis);
    }
}

void EnKarebaba_Regrow(EnKarebaba* pthis, GlobalContext* globalCtx) {
    f32 scaleFactor;

    pthis->actor.params++;
    scaleFactor = pthis->actor.params * 0.05f;
    Actor_SetScale(&pthis->actor, 0.005f * scaleFactor);
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + (14.0f * scaleFactor);

    if (pthis->actor.params == 20) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_2;
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ENEMY);
        EnKarebaba_SetupIdle(pthis);
    }
}

void EnKarebaba_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnKarebaba* pthis = (EnKarebaba*)thisx;
    f32 height;

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->actionFunc != EnKarebaba_Dead) {
        if (pthis->actionFunc == EnKarebaba_Dying) {
            Actor_MoveForward(&pthis->actor);
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 15.0f, 10.0f, 5);
        } else {
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
            if (pthis->boundFloor == NULL) {
                pthis->boundFloor = pthis->actor.floorPoly;
            }
        }
        if (pthis->actionFunc != EnKarebaba_Dying && pthis->actionFunc != EnKarebaba_DeadItemDrop) {
            if (pthis->actionFunc != EnKarebaba_Regrow && pthis->actionFunc != EnKarebaba_Grow) {
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->headCollider.base);
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
            }
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->headCollider.base);
            Actor_SetFocus(&pthis->actor, (pthis->actor.scale.x * 10.0f) / 0.01f);
            height = pthis->actor.home.pos.y + 40.0f;
            pthis->actor.focus.pos.x = pthis->actor.home.pos.x;
            pthis->actor.focus.pos.y = CLAMP_MAX(pthis->actor.focus.pos.y, height);
            pthis->actor.focus.pos.z = pthis->actor.home.pos.z;
        }
    }
}

void EnKarebaba_DrawBaseShadow(EnKarebaba* pthis, GlobalContext* globalCtx) {
    MtxF mf;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_karebaba.c", 1013);

    func_80094044(globalCtx->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, 255);
    func_80038A28(pthis->boundFloor, pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z, &mf);
    Matrix_Mult(&mf, MTXMODE_NEW);
    Matrix_Scale(0.15f, 1.0f, 0.15f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_karebaba.c", 1029),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gCircleShadowDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_karebaba.c", 1034);
}

void EnKarebaba_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Color_RGBA8 black = { 0, 0, 0, 0 };
    static Gfx* stemDLists[] = { gDekuBabaStemTopDL, gDekuBabaStemMiddleDL, gDekuBabaStemBaseDL };
    static Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    EnKarebaba* pthis = (EnKarebaba*)thisx;
    s32 i;
    s32 stemSections;
    f32 scale;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_karebaba.c", 1056);

    func_80093D18(globalCtx->state.gfxCtx);

    if (pthis->actionFunc == EnKarebaba_DeadItemDrop) {
        if (pthis->actor.params > 40 || (pthis->actor.params & 1)) {
            Matrix_Translate(0.0f, 0.0f, 200.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_karebaba.c", 1066),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gDekuBabaStickDropDL);
        }
    } else if (pthis->actionFunc != EnKarebaba_Dead) {
        func_80026230(globalCtx, &black, 1, 2);
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL, NULL, NULL);
        Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);

        if ((pthis->actionFunc == EnKarebaba_Regrow) || (pthis->actionFunc == EnKarebaba_Grow)) {
            scale = pthis->actor.params * 0.0005f;
        } else {
            scale = 0.01f;
        }

        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
        Matrix_RotateZYX(pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);

        if (pthis->actionFunc == EnKarebaba_Dying) {
            stemSections = 2;
        } else {
            stemSections = 3;
        }

        for (i = 0; i < stemSections; i++) {
            Matrix_Translate(0.0f, 0.0f, -2000.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_karebaba.c", 1116),
                      G_MTX_LOAD | G_MTX_NOPUSH | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, stemDLists[i]);

            if (i == 0 && pthis->actionFunc == EnKarebaba_Dying) {
                Matrix_MultVec3f(&zeroVec, &pthis->actor.focus.pos);
            }
        }

        func_80026608(globalCtx);
    }

    func_80026230(globalCtx, &black, 1, 2);
    Matrix_Translate(pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z, MTXMODE_NEW);

    if (pthis->actionFunc != EnKarebaba_Grow) {
        scale = 0.01f;
    }

    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    Matrix_RotateY(pthis->actor.home.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_karebaba.c", 1144),
              G_MTX_LOAD | G_MTX_NOPUSH | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gDekuBabaBaseLeavesDL);

    if (pthis->actionFunc == EnKarebaba_Dying) {
        Matrix_RotateZYX(-0x4000, (s16)(pthis->actor.shape.rot.y - pthis->actor.home.rot.y), 0, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_karebaba.c", 1155),
                  G_MTX_LOAD | G_MTX_NOPUSH | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gDekuBabaStemBaseDL);
    }

    func_80026608(globalCtx);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_karebaba.c", 1163);

    if (pthis->boundFloor != NULL) {
        EnKarebaba_DrawBaseShadow(pthis, globalCtx);
    }
}
