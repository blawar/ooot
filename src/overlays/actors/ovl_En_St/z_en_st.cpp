#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ST_Z_EN_ST_C
#include "actor_common.h"
/*
 * File: z_en_st.c
 * Overlay: ovl_En_St
 * Description: Skulltula (normal, big, invisible)
 */

#include "z_en_st.h"
#include "framerate.h"
#include "objects/object_st/object_st.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnSt_Init(Actor* pthisx, GlobalContext* globalCtx);
void EnSt_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void EnSt_Update(Actor* pthisx, GlobalContext* globalCtx);
void EnSt_Draw(Actor* pthisx, GlobalContext* globalCtx);
void EnSt_ReturnToCeiling(EnSt* pthis, GlobalContext* globalCtx);
void EnSt_MoveToGround(EnSt* pthis, GlobalContext* globalCtx);
void EnSt_StartOnCeilingOrGround(EnSt* pthis, GlobalContext* globalCtx);
void EnSt_WaitOnGround(EnSt* pthis, GlobalContext* globalCtx);
void EnSt_Die(EnSt* pthis, GlobalContext* globalCtx);
void EnSt_BounceAround(EnSt* pthis, GlobalContext* globalCtx);
void EnSt_FinishBouncing(EnSt* pthis, GlobalContext* globalCtx);

#include "overlays/ovl_En_St/ovl_En_St.cpp"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_eff_blure.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

ActorInit En_St_InitVars = {
    ACTOR_EN_ST,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_ST,
    sizeof(EnSt),
    (ActorFunc)EnSt_Init,
    (ActorFunc)EnSt_Destroy,
    (ActorFunc)EnSt_Update,
    (ActorFunc)EnSt_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT6,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 32, 50, -24, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInit = { 2, 0, 0, 0, MASS_IMMOVABLE };

static ColliderCylinderInit sCylinderInit2 = {
    {
        COLTYPE_HIT6,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
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
    { 20, 60, -30, { 0, 0, 0 } },
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x04 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 1, { { 0, -240, 0 }, 28 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT6,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static struct_80034EC0_Entry sAnimations[] = {
    { &object_st_Anim_000304, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP_INTERP, 0.0f },
    { &object_st_Anim_005B98, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE_INTERP, -8.0f },
    { &object_st_Anim_000304, 4.0f, 0.0f, -1.0f, ANIMMODE_ONCE_INTERP, -8.0f },
    { &object_st_Anim_000304, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP_INTERP, -8.0f },
    { &object_st_Anim_0055A8, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE_INTERP, -8.0f },
    { &object_st_Anim_000304, 8.0f, 0.0f, -1.0f, ANIMMODE_LOOP_INTERP, -8.0f },
    { &object_st_Anim_000304, 6.0f, 0.0f, -1.0f, ANIMMODE_LOOP_INTERP, -8.0f },
    { &object_st_Anim_005B98, 2.0f, 0.0f, -1.0f, ANIMMODE_LOOP_INTERP, -8.0f },
};

void EnSt_SetupAction(EnSt* pthis, EnStActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

/**
 * Spawns `dustCnt` dust particles in a random pattern around the Skulltula
 */
void EnSt_SpawnDust(EnSt* pthis, GlobalContext* globalCtx, s32 dustCnt) {
    Color_RGBA8 primColor = { 170, 130, 90, 255 };
    Color_RGBA8 envColor = { 100, 60, 20, 0 };
    Vec3f dustVel = { 0.0f, 0.0f, 0.0f };
    Vec3f dustAccel = { 0.0f, 0.3f, 0.0f };
    Vec3f dustPos;
    Rotation yAngle;
    s32 i;

    yAngle = (Rand_ZeroOne() - 0.5f) * 65536.0f;
    dustPos.y = pthis->actor.floorHeight;
    for (i = dustCnt; i >= 0; i--, yAngle += (0x10000 / dustCnt)) {
        dustAccel.x = (Rand_ZeroOne() - 0.5f) * 4.0f;
        dustAccel.z = (Rand_ZeroOne() - 0.5f) * 4.0f;
        dustPos.x = pthis->actor.world.pos.x + (Math_SinS(yAngle.toS16()) * 22.0f);
        dustPos.z = pthis->actor.world.pos.z + (Math_CosS(yAngle.toS16()) * 22.0f);
        func_8002836C(globalCtx, &dustPos, &dustVel, &dustAccel, &primColor, &envColor, 120, 40, 10);
    }
}

void EnSt_SpawnBlastEffect(EnSt* pthis, GlobalContext* globalCtx) {
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    Vec3f blastPos;

    blastPos.x = pthis->actor.world.pos.x;
    blastPos.y = pthis->actor.floorHeight;
    blastPos.z = pthis->actor.world.pos.z;

    EffectSsBlast_SpawnWhiteCustomScale(globalCtx, &blastPos, &zeroVec, &zeroVec, 100, 220, 8);
}

void EnSt_SpawnDeadEffect(EnSt* pthis, GlobalContext* globalCtx) {
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    Vec3f firePos;

    firePos.x = pthis->actor.world.pos.x + ((Rand_ZeroOne() - 0.5f) * 60.0f);
    firePos.y = (pthis->actor.world.pos.y + 10.0f) + ((Rand_ZeroOne() - 0.5f) * 45.0f);
    firePos.z = pthis->actor.world.pos.z + ((Rand_ZeroOne() - 0.5f) * 60.0f);
    EffectSsDeadDb_Spawn(globalCtx, &firePos, &zeroVec, &zeroVec, 100, 0, 255, 255, 255, 255, 255, 0, 0, 1, 9, true);
}

s32 EnSt_CreateBlureEffect(GlobalContext* globalCtx) {
    EffectBlureInit1 blureInit;
    u8 p1StartColor[] = { 255, 255, 255, 75 };
    u8 p2StartColor[] = { 255, 255, 255, 75 };
    u8 p1EndColor[] = { 255, 255, 255, 0 };
    u8 p2EndColor[] = { 255, 255, 255, 0 };
    s32 i;
    s32 blureIdx;

    for (i = 0; i < 4; i++) {
        blureInit.p1StartColor[i] = p1StartColor[i];
        blureInit.p2StartColor[i] = p2StartColor[i];
        blureInit.p1EndColor[i] = p1EndColor[i];
        blureInit.p2EndColor[i] = p2EndColor[i];
    }

    blureInit.elemDuration = 6;
    blureInit.unkFlag = 0;
    blureInit.calcMode = 3;

    Effect_Add(globalCtx, &blureIdx, EFFECT_BLURE1, 0, 0, &blureInit);
    return blureIdx;
}

/**
 * Checks for the position of the ceiling above the Skulltula.
 * If no ceiling is found it is set to 1000 units above the Skulltula
 */
s32 EnSt_CheckCeilingPos(EnSt* pthis, GlobalContext* globalCtx) {
    CollisionPoly* poly;
    s32 bgId;
    Vec3f checkPos;

    checkPos.x = pthis->actor.world.pos.x;
    checkPos.y = pthis->actor.world.pos.y + 1000.0f;
    checkPos.z = pthis->actor.world.pos.z;
    if (!BgCheck_EntityLineTest1(&globalCtx->colCtx, &pthis->actor.world.pos, &checkPos, &pthis->ceilingPos, &poly, false,
                                 false, true, true, &bgId)) {
        return false;
    }
    pthis->unusedPos = pthis->actor.world.pos;
    pthis->unusedPos.y -= 100.0f * FRAMERATE_SCALER;
    return true;
}

void EnSt_AddBlurVertex(EnSt* pthis) {
    Vec3f v1 = { 834.0f, 834.0f, 0.0f };
    Vec3f v2 = { 834.0f, -584.0f, 0.0f };
    Vec3f v1Pos;
    Vec3f v2Pos;

    v1.x *= pthis->colliderScale;
    v1.y *= pthis->colliderScale;
    v1.z *= pthis->colliderScale;

    v2.x *= pthis->colliderScale;
    v2.y *= pthis->colliderScale;
    v2.z *= pthis->colliderScale;

    Matrix_Push();
    Matrix_MultVec3f(&v1, &v1Pos);
    Matrix_MultVec3f(&v2, &v2Pos);
    Matrix_Pop();
    EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->blureIdx), &v1Pos, &v2Pos);
}

void EnSt_AddBlurSpace(EnSt* pthis) {
	EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->blureIdx));
}

void EnSt_SetWaitingAnimation(EnSt* pthis) {
    func_80034EC0(&pthis->skelAnime, sAnimations, 3);
}

void EnSt_SetReturnToCeilingAnimation(EnSt* pthis) {
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_UP);
    func_80034EC0(&pthis->skelAnime, sAnimations, 2);
}

void EnSt_SetLandAnimation(EnSt* pthis) {
    pthis->actor.world.pos.y = pthis->actor.floorHeight + pthis->floorHeightOffset;
    func_80034EC0(&pthis->skelAnime, sAnimations, 4);
    pthis->sfxTimer = 0;
    pthis->animFrames = pthis->skelAnime.animLength;
}

void EnSt_SetDropAnimAndVel(EnSt* pthis) {
    if (pthis->takeDamageSpinTimer == 0) {
        func_80034EC0(&pthis->skelAnime, sAnimations, 4);
        pthis->animFrames = pthis->skelAnime.animLength;
    }
    pthis->sfxTimer = 0;
    pthis->actor.velocity.y = -10.0f;
}

/**
 * Initalizes the Skulltula's 6 cylinders, and sphere collider.
 */
void EnSt_InitColliders(EnSt* pthis, GlobalContext* globalCtx) {
    ColliderCylinderInit* cylinders[6] = {
        &sCylinderInit, &sCylinderInit, &sCylinderInit, &sCylinderInit2, &sCylinderInit2, &sCylinderInit2,
    };

    s32 i;
    s32 pad;

    for (i = 0; i < ARRAY_COUNT(cylinders); i++) {
        Collider_InitCylinder(globalCtx, &pthis->colCylinder[i]);
        Collider_SetCylinder(globalCtx, &pthis->colCylinder[i], &pthis->actor, cylinders[i]);
    }

    pthis->colCylinder[0].info.bumper.dmgFlags = 0x0003F8F9;
    pthis->colCylinder[1].info.bumper.dmgFlags = 0xFFC00706;
    pthis->colCylinder[2].base.colType = COLTYPE_METAL;
    pthis->colCylinder[2].info.bumperFlags = BUMP_ON | BUMP_HOOKABLE | BUMP_NO_AT_INFO;
    pthis->colCylinder[2].info.elemType = ELEMTYPE_UNK2;
    pthis->colCylinder[2].info.bumper.dmgFlags = 0xFFCC0706;

    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(2), &sColChkInit);

    Collider_InitJntSph(globalCtx, &pthis->colSph);
    Collider_SetJntSph(globalCtx, &pthis->colSph, &pthis->actor, &sJntSphInit, pthis->colSphItems);
}

void EnSt_CheckBodyStickHit(EnSt* pthis, GlobalContext* globalCtx) {
    ColliderInfo* body = &pthis->colCylinder[0].info;
    Player* player = GET_PLAYER(globalCtx);

    if (player->unk_860 != 0) {
        body->bumper.dmgFlags |= 2;
        pthis->colCylinder[1].info.bumper.dmgFlags &= ~2;
        pthis->colCylinder[2].info.bumper.dmgFlags &= ~2;
    } else {
        body->bumper.dmgFlags &= ~2;
        pthis->colCylinder[1].info.bumper.dmgFlags |= 2;
        pthis->colCylinder[2].info.bumper.dmgFlags |= 2;
    }
}

void EnSt_SetBodyCylinderAC(EnSt* pthis, GlobalContext* globalCtx) {
    Collider_UpdateCylinder(&pthis->actor, &pthis->colCylinder[0]);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder[0].base);
}

void EnSt_SetLegsCylinderAC(EnSt* pthis, GlobalContext* globalCtx) {
    s16 angleTowardsLink = ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y));

    if (angleTowardsLink < 0x3FFC) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->colCylinder[2]);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder[2].base);
    } else {
        Collider_UpdateCylinder(&pthis->actor, &pthis->colCylinder[1]);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder[1].base);
    }
}

s32 EnSt_SetCylinderOC(EnSt* pthis, GlobalContext* globalCtx) {
    Vec3f cyloffsets[] = {
        { 40.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { -40.0f, 0.0f, 0.0f },
    };
    Vec3f cylPos;
    s32 i;

    for (i = 0; i < 3; i++) {
        cylPos = pthis->actor.world.pos;
        cyloffsets[i].x *= pthis->colliderScale;
        cyloffsets[i].y *= pthis->colliderScale;
        cyloffsets[i].z *= pthis->colliderScale;
        Matrix_Push();
        Matrix_Translate(cylPos.x, cylPos.y, cylPos.z, MTXMODE_NEW);
        Matrix_RotateY((pthis->initalYaw.toFloat() / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_MultVec3f(&cyloffsets[i], &cylPos);
        Matrix_Pop();
        pthis->colCylinder[i + 3].dim.pos.x = cylPos.x;
        pthis->colCylinder[i + 3].dim.pos.y = cylPos.y;
        pthis->colCylinder[i + 3].dim.pos.z = cylPos.z;
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder[i + 3].base);
    }

    return true;
}

void EnSt_UpdateCylinders(EnSt* pthis, GlobalContext* globalCtx) {
    if ((pthis->actor.colChkInfo.health != 0) || (pthis->actionFunc == EnSt_FinishBouncing)) {
        if (DECR(pthis->gaveDamageSpinTimer) == 0) {
            EnSt_SetCylinderOC(pthis, globalCtx);
        }

        DECR(pthis->invulnerableTimer);
        DECR(pthis->takeDamageSpinTimer);

        if (pthis->invulnerableTimer == 0 && pthis->takeDamageSpinTimer == 0) {
            EnSt_SetBodyCylinderAC(pthis, globalCtx);
            EnSt_SetLegsCylinderAC(pthis, globalCtx);
        }
    }
}

s32 EnSt_CheckHitLink(EnSt* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 hit;
    s32 i;

    for (i = 0, hit = 0; i < 3; i++) {
        if (((pthis->colCylinder[i + 3].base.ocFlags2 & OC2_HIT_PLAYER) != 0) == 0) {
            continue;
        }
        pthis->colCylinder[i + 3].base.ocFlags2 &= ~OC2_HIT_PLAYER;
        hit = true;
    }

    if (!hit) {
        return false;
    }

    if (pthis->swayTimer == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_ROLL);
    }

    pthis->gaveDamageSpinTimer = 30;
    globalCtx->damagePlayer(globalCtx, -8);
    Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
    func_8002F71C(globalCtx, &pthis->actor, 4.0f, pthis->actor.yawTowardsPlayer, 6.0f);
    return true;
}

s32 EnSt_CheckHitFrontside(EnSt* pthis) {
    u8 acFlags = pthis->colCylinder[2].base.acFlags;

    if (!!(acFlags & AC_HIT) == 0) {
        // not hit
        return false;
    } else {
        pthis->colCylinder[2].base.acFlags &= ~AC_HIT;
        pthis->invulnerableTimer = 8;
        pthis->playSwayFlag = 0;
        pthis->swayTimer = 60;
        return true;
    }
}

s32 EnSt_CheckHitBackside(EnSt* pthis, GlobalContext* globalCtx) {
    ColliderCylinder* cyl = &pthis->colCylinder[0];
    s32 flags = 0; // ac hit flags from colliders 0 and 1
    s32 hit = false;

    if (cyl->base.acFlags & AC_HIT) {
        cyl->base.acFlags &= ~AC_HIT;
        hit = true;
        flags |= cyl->info.acHitInfo->toucher.dmgFlags;
    }

    cyl = &pthis->colCylinder[1];
    if (cyl->base.acFlags & AC_HIT) {
        cyl->base.acFlags &= ~AC_HIT;
        hit = true;
        flags |= cyl->info.acHitInfo->toucher.dmgFlags;
    }

    if (!hit) {
        return false;
    }

    pthis->invulnerableTimer = 8;
    if (pthis->actor.colChkInfo.damageEffect == 1) {
        if (pthis->stunTimer == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
            pthis->stunTimer = 120;
            Actor_SetColorFilter(&pthis->actor, 0, 0xC8, 0, pthis->stunTimer.whole());
        }
        return false;
    }

    pthis->swayTimer = pthis->stunTimer = 0;
    pthis->gaveDamageSpinTimer = 1;
    func_80034EC0(&pthis->skelAnime, sAnimations, 3);
    pthis->takeDamageSpinTimer = pthis->skelAnime.animLength;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xC8, 0, pthis->takeDamageSpinTimer.whole());
    if (Actor_ApplyDamage(&pthis->actor)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_DAMAGE);
        return false;
    }
    Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->groundBounces = 3;
    pthis->deathTimer = 20;
    pthis->actor.gravity = -1.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALWALL_DEAD);

    if (flags & 0x1F820) {
        // arrow, fire arrow, ice arrow, light arrow,
        // and three unknows, unused arrows?
        EnSt_SetupAction(pthis, EnSt_Die);
        pthis->finishDeathTimer = 8;
    } else {
        EnSt_SetupAction(pthis, EnSt_BounceAround);
    }

    return true;
}

/**
 * Checks if the Skulltula's colliders have been hit, returns true if the hit has dealt damage to the Skulltula
 */
s32 EnSt_CheckColliders(EnSt* pthis, GlobalContext* globalCtx) {
    if (EnSt_CheckHitFrontside(pthis)) {
        // player has hit the front shield area of the Skulltula
        return false;
    }

    if (globalCtx->actorCtx.unk_02 != 0) {
        return true;
    }

    if (EnSt_CheckHitBackside(pthis, globalCtx)) {
        // player has hit the backside of the Skulltula
        return true;
    }

    if (pthis->stunTimer == 0 && pthis->takeDamageSpinTimer == 0) {
        // check if the Skulltula has hit link.
        EnSt_CheckHitLink(pthis, globalCtx);
    }
    return false;
}

void EnSt_SetColliderScale(EnSt* pthis) {
    f32 scaleAmount = 1.0f;
    f32 radius;
    f32 height;
    f32 yShift;
    s32 i;

    if (pthis->actor.params == 1) {
        scaleAmount = 1.4f;
    }

    radius = pthis->colSph.elements[0].dim.modelSphere.radius;
    radius *= scaleAmount;
    pthis->colSph.elements[0].dim.modelSphere.radius = radius;

    for (i = 0; i < 6; i++) {
        yShift = pthis->colCylinder[i].dim.yShift;
        radius = pthis->colCylinder[i].dim.radius;
        height = pthis->colCylinder[i].dim.height;
        yShift *= scaleAmount;
        radius *= scaleAmount;
        height *= scaleAmount;

        pthis->colCylinder[i].dim.yShift = yShift;
        pthis->colCylinder[i].dim.radius = radius;
        pthis->colCylinder[i].dim.height = height;
    }
    Actor_SetScale(&pthis->actor, 0.04f * scaleAmount);
    pthis->colliderScale = scaleAmount;
    pthis->floorHeightOffset = 32.0f * scaleAmount;
}

s32 EnSt_SetTeethColor(EnSt* pthis, s16 redTarget, s16 greenTarget, s16 blueTarget, s16 minMaxStep) {
    s16 red = pthis->teethR;
    s16 green = pthis->teethG;
    s16 blue = pthis->teethB;

    minMaxStep = 255 / (s16)(0.6f * minMaxStep);
    if (minMaxStep <= 0) {
        minMaxStep = 1;
    }

    Math_SmoothStepToS(&red, redTarget, 1, minMaxStep, minMaxStep);
    Math_SmoothStepToS(&green, greenTarget, 1, minMaxStep, minMaxStep);
    Math_SmoothStepToS(&blue, blueTarget, 1, minMaxStep, minMaxStep);
    pthis->teethR = red;
    pthis->teethG = green;
    pthis->teethB = blue;
    return 1;
}

float EnSt_DecrStunTimer(EnSt* pthis) {
    if (pthis->stunTimer == 0) {
        return 0;
    }
    
    float r = pthis->stunTimer.toFloat();
    DECR(pthis->stunTimer);
    return r;
}

/**
 * Updates the yaw of the Skulltula, used for the shaking animation right before
 * turning, and the actual turning to face away from the player, and then back to
 * face the player
 */
void EnSt_UpdateYaw(EnSt* pthis, GlobalContext* globalCtx) {
    u16 yawDir = 0;
    Vec3s rot;
    s16 yawDiff;
    TimerS16 timer;
    s16 yawTarget;

    // Shake towards the end of the stun.
    if (pthis->stunTimer != 0) {
        if (pthis->stunTimer < 30) {
            if (pthis->stunTimer.whole() % 2) {
                pthis->actor.shape.rot.y += 0x800 * FRAMERATE_SCALER;
            } else {
                pthis->actor.shape.rot.y -= 0x800 * FRAMERATE_SCALER;
            }
        }
        return;
    }

    if (pthis->swayTimer == 0 && pthis->deathTimer == 0 && pthis->finishDeathTimer == 0) {
        // not swaying or dying
        if (pthis->takeDamageSpinTimer != 0 || pthis->gaveDamageSpinTimer != 0) {
            // Skulltula is doing a spinning animation
            pthis->actor.shape.rot.y += 0x2000 * FRAMERATE_SCALER;
            return;
        }

        if (pthis->actionFunc != EnSt_WaitOnGround) {
            // set the timers to turn away or turn towards the player
            pthis->rotAwayTimer = 30;
            pthis->rotTowardsTimer = 0;
        }

        if (pthis->rotAwayTimer != 0) {
            // turn away from the player
            DECR(pthis->rotAwayTimer);
            if (pthis->rotAwayTimer == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_ROLL);
                pthis->rotTowardsTimer = 30;
            }
        } else if (pthis->rotTowardsTimer != 0) {
            // turn towards the player
            DECR(pthis->rotTowardsTimer);
            if (pthis->rotTowardsTimer == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_ROLL);
                pthis->rotAwayTimer = 30;
            }
            yawDir = 0x8000;
        }

        // calculate the new yaw to or away from the player.
        rot = pthis->actor.shape.rot;
        yawTarget = (pthis->actionFunc == EnSt_WaitOnGround ? pthis->actor.yawTowardsPlayer : pthis->initalYaw.toS16());
        yawDiff = rot.y - (yawTarget ^ yawDir);
        if (ABS(yawDiff) <= 0x4000) {
            Math_SmoothStepToS(&rot.y, yawTarget ^ yawDir, 4, 0x2000, 1);
        } else {
            rot.y += 0x2000 * FRAMERATE_SCALER;
        }

        pthis->actor.shape.rot = pthis->actor.world.rot = rot;

        // Do the shaking animation.
        if (yawDir == 0 && pthis->rotAwayTimer < 10) {
            timer = pthis->rotAwayTimer;
        } else if (yawDir == 0x8000 && pthis->rotTowardsTimer < 10) {
            timer = pthis->rotTowardsTimer;
        } else {
            return;
        }

        if ((timer % 2) != 0) {
            pthis->actor.shape.rot.y += 0x800 * FRAMERATE_SCALER;
        } else {
            pthis->actor.shape.rot.y -= 0x800 * FRAMERATE_SCALER;
        }
    }
}

/**
 * Checks to see if the Skulltula is done bouncing on the ground,
 * spawns dust particles as the Skulltula hits the ground
 */
s32 EnSt_IsDoneBouncing(EnSt* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.velocity.y > 0.0f || pthis->groundBounces == 0) {
        // the Skulltula is moving upwards or the groundBounces is 0
        return false;
    }

    if (!(pthis->actor.bgCheckFlags & 1)) {
        // the Skulltula is not on the ground.
        return false;
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
    EnSt_SpawnDust(pthis, globalCtx, 10);
    // creates an elastic bouncing effect, boucing up less for each hit on the ground.
    pthis->actor.velocity.y = 6.0f / (4 - pthis->groundBounces);
    pthis->groundBounces--;
    if (pthis->groundBounces != 0) {
        return false;
    } else {
        // make sure the Skulltula stays on the ground.
        pthis->actor.velocity.y = 0.0f;
    }
    return true;
}

void EnSt_Bob(EnSt* pthis, GlobalContext* globalCtx) {
    f32 ySpeedTarget = 0.5f;

    if ((globalCtx->state.frames & 8) != 0) {
        ySpeedTarget *= -1.0f;
    }
    Math_SmoothStepToF(&pthis->actor.velocity.y, ySpeedTarget, 0.4f, 1000.0f, 0.0f);
}

s32 EnSt_IsCloseToPlayer(EnSt* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 yDist;

    if (pthis->takeDamageSpinTimer != 0) {
        // skull is spinning from damage.
        return false;
    } else if (pthis->actor.xzDistToPlayer > 160) {
        // player is more than 160 xz units from the Skulltula
        return false;
    }

    yDist = pthis->actor.world.pos.y - player->actor.world.pos.y;
    if (yDist < 0.0f || yDist > 400.0f) {
        // player is above the Skulltula or more than 400 units below
        // the Skulltula
        return false;
    }

    if (player->actor.world.pos.y < pthis->actor.floorHeight) {
        // player is below the Skulltula's ground position
        return false;
    }
    return true;
}

s32 EnSt_IsCloseToInitalPos(EnSt* pthis) {
    f32 velY = pthis->actor.velocity.y;
    f32 checkY = pthis->actor.world.pos.y + (velY * 2.0f);

    if (checkY >= pthis->actor.home.pos.y) {
        return true;
    }
    return false;
}

s32 EnSt_IsCloseToGround(EnSt* pthis) {
    f32 velY = pthis->actor.velocity.y;
    f32 checkY = pthis->actor.world.pos.y + (velY * 2.0f);

    if (checkY - pthis->actor.floorHeight <= pthis->floorHeightOffset) {
        return true;
    }
    return false;
}

/**
 * Does the animation of the Skulltula swaying back and forth after the Skulltula
 * has been hit in the front by a sword
 */
void EnSt_Sway(EnSt* pthis) {
    Vec3f amtToTranslate;
    Vec3f translatedPos;
    f32 swayAmt;
    s16 rotAngle;

    if (pthis->swayTimer != 0) {

        pthis->swayAngle += 0xA28;
        DECR(pthis->swayTimer);

        if (pthis->swayTimer == 0) {
            pthis->swayAngle = 0;
        }

        swayAmt = pthis->swayTimer.toFloat() * (7.0f / 15.0f);
        rotAngle = Math_SinS(pthis->swayAngle.toS16()) * (swayAmt * (65536.0f / 360.0f));

        if (pthis->absPrevSwayAngle >= ABS(rotAngle) && pthis->playSwayFlag == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_WAVE);
            pthis->playSwayFlag = 1;
        }

        if (pthis->absPrevSwayAngle < ABS(rotAngle)) {
            pthis->playSwayFlag = 0;
        }

        pthis->absPrevSwayAngle = ABS(rotAngle);
        amtToTranslate.x = Math_SinS(rotAngle) * -200.0f;
        amtToTranslate.y = Math_CosS(rotAngle) * -200.0f;
        amtToTranslate.z = 0.0f;
        Matrix_Push();
        Matrix_Translate(pthis->ceilingPos.x, pthis->ceilingPos.y, pthis->ceilingPos.z, MTXMODE_NEW);
        Matrix_RotateY(pthis->actor.world.rot.y * (M_PI / 32768.0f), MTXMODE_APPLY);
        Matrix_MultVec3f(&amtToTranslate, &translatedPos);
        Matrix_Pop();
        pthis->actor.shape.rot.z = -(rotAngle * 2);
        pthis->actor.world.pos.x = translatedPos.x;
        pthis->actor.world.pos.z = translatedPos.z;
    }
}

void EnSt_Init(Actor* pthisx, GlobalContext* globalCtx) {
    EnSt* pthis = (EnSt*)pthisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 14.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &object_st_Skel_005298, NULL, pthis->jointTable, pthis->morphTable, 30);
    func_80034EC0(&pthis->skelAnime, sAnimations, 0);
    pthis->blureIdx = EnSt_CreateBlureEffect(globalCtx);
    EnSt_InitColliders(pthis, globalCtx);
    if (pthisx->params == 2) {
        pthis->actor.flags |= ACTOR_FLAG_7;
    }
    if (pthis->actor.params == 1) {
        pthis->actor.naviEnemyId = 0x05;
    } else {
        pthis->actor.naviEnemyId = 0x04;
    }
    EnSt_CheckCeilingPos(pthis, globalCtx);
    pthis->actor.flags |= ACTOR_FLAG_14;
    pthis->actor.flags |= ACTOR_FLAG_24;
    EnSt_SetColliderScale(pthis);
    pthis->actor.gravity = 0.0f;
    pthis->initalYaw = pthis->actor.world.rot.y;
    EnSt_SetupAction(pthis, EnSt_StartOnCeilingOrGround);
}

void EnSt_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    EnSt* pthis = (EnSt*)pthisx;
    s32 i;

    Effect_Delete(globalCtx, pthis->blureIdx);
    for (i = 0; i < 6; i++) {
        Collider_DestroyCylinder(globalCtx, &pthis->colCylinder[i]);
    }
    Collider_DestroyJntSph(globalCtx, &pthis->colSph);
}

void EnSt_WaitOnCeiling(EnSt* pthis, GlobalContext* globalCtx) {
    if (EnSt_IsCloseToPlayer(pthis, globalCtx)) {
        EnSt_SetDropAnimAndVel(pthis);
        EnSt_SetupAction(pthis, EnSt_MoveToGround);
    } else {
        EnSt_Bob(pthis, globalCtx);
    }
}

/**
 * Skulltula is waiting on the ground for the player to move away, or for
 * a collider to have contact
 */
void EnSt_WaitOnGround(EnSt* pthis, GlobalContext* globalCtx) {
    if (pthis->takeDamageSpinTimer != 0) {
        DECR(pthis->takeDamageSpinTimer);
        if (pthis->takeDamageSpinTimer == 0) {
            func_80034EC0(&pthis->skelAnime, sAnimations, 3);
        }
    }

    if (pthis->animFrames != 0) {
        pthis->animFrames--;
        if (pthis->animFrames == 0) {
            func_80034EC0(&pthis->skelAnime, sAnimations, 3);
        }
    }

    if (!EnSt_IsCloseToPlayer(pthis, globalCtx)) {
        // Player is no longer within range, return to ceiling.
        EnSt_SetReturnToCeilingAnimation(pthis);
        EnSt_SetupAction(pthis, EnSt_ReturnToCeiling);
        return;
    }

    if (DECR(pthis->sfxTimer) == 0) {
        // play the "laugh" sfx every 64 frames.
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_LAUGH);
        pthis->sfxTimer = 64;
    }

    // simply bob up and down.
    EnSt_Bob(pthis, globalCtx);
}

void EnSt_LandOnGround(EnSt* pthis, GlobalContext* globalCtx) {
    if (pthis->animFrames != 0) {
        pthis->animFrames--;
        if (pthis->animFrames == 0) {
            func_80034EC0(&pthis->skelAnime, sAnimations, 3);
        }
    }

    if (pthis->takeDamageSpinTimer != 0) {
        DECR(pthis->takeDamageSpinTimer);
        if (pthis->takeDamageSpinTimer == 0) {
            func_80034EC0(&pthis->skelAnime, sAnimations, 3);
        }
    }

    pthis->sfxTimer++;
    if (pthis->sfxTimer == 14) {
        // play the sound effect of the Skulltula hitting the ground.
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_DOWN_SET);
    }

    if ((pthis->actor.floorHeight + pthis->floorHeightOffset) < pthis->actor.world.pos.y) {
        // the Skulltula has hit the ground.
        pthis->sfxTimer = 0;
        EnSt_SetupAction(pthis, EnSt_WaitOnGround);
    } else {
        Math_SmoothStepToF(&pthis->actor.velocity.y, 2.0f, 0.3f, 1.0f, 0.0f);
    }
}

void EnSt_MoveToGround(EnSt* pthis, GlobalContext* globalCtx) {
    if (pthis->takeDamageSpinTimer != 0) {
        DECR(pthis->takeDamageSpinTimer);
        if (pthis->takeDamageSpinTimer == 0) {
            func_80034EC0(&pthis->skelAnime, sAnimations, 5);
        }
    }

    if (!EnSt_IsCloseToPlayer(pthis, globalCtx)) {
        // the player moved out of range, return to the ceiling.
        EnSt_SetReturnToCeilingAnimation(pthis);
        EnSt_SetupAction(pthis, EnSt_ReturnToCeiling);
    } else if (EnSt_IsCloseToGround(pthis)) {
        // The Skulltula has become close to the ground.
        EnSt_SpawnBlastEffect(pthis, globalCtx);
        EnSt_SetLandAnimation(pthis);
        EnSt_SetupAction(pthis, EnSt_LandOnGround);
    } else if (DECR(pthis->sfxTimer) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_DOWN);
        pthis->sfxTimer = 3;
    }
}

void EnSt_ReturnToCeiling(EnSt* pthis, GlobalContext* globalCtx) {
    f32 animPctDone = pthis->skelAnime.curFrame / (pthis->skelAnime.animLength - 1.0f);

    if (animPctDone == 1.0f) {
        EnSt_SetReturnToCeilingAnimation(pthis);
    }

    if (EnSt_IsCloseToPlayer(pthis, globalCtx)) {
        // player came back into range
        EnSt_SetDropAnimAndVel(pthis);
        EnSt_SetupAction(pthis, EnSt_MoveToGround);
    } else if (EnSt_IsCloseToInitalPos(pthis)) {
        // the Skulltula is close to the initial postion.
        EnSt_SetWaitingAnimation(pthis);
        EnSt_SetupAction(pthis, EnSt_WaitOnCeiling);
    } else {
        // accelerate based on the current animation frame.
        pthis->actor.velocity.y = 4.0f * animPctDone;
    }
}

/**
 * The Skulltula has been killed, bounce around
 */
void EnSt_BounceAround(EnSt* pthis, GlobalContext* globalCtx) {
    pthis->actor.colorFilterTimer = pthis->deathTimer.whole();
    func_8002D868(&pthis->actor);
    pthis->actor.world.rot.x += 0x800 * FRAMERATE_SCALER;
    pthis->actor.world.rot.z -= 0x800 * FRAMERATE_SCALER;
    pthis->actor.shape.rot = pthis->actor.world.rot;
    if (EnSt_IsDoneBouncing(pthis, globalCtx)) {
        pthis->actor.shape.yOffset = 400.0f;
        pthis->actor.speedXZ = 1.0f;
        pthis->actor.gravity = -2.0f;
        EnSt_SetupAction(pthis, EnSt_FinishBouncing);
    } else {
        Math_SmoothStepToF(&pthis->actor.shape.yOffset, 400.0f, 0.4f, 10000.0f, 0.0f);
    }
}

/**
 * Finish up the bouncing animation, and rotate towards the final position
 */
void EnSt_FinishBouncing(EnSt* pthis, GlobalContext* globalCtx) {
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    if (DECR(pthis->deathTimer) == 0) {
        pthis->actor.velocity = zeroVec;
        pthis->finishDeathTimer = 8;
        EnSt_SetupAction(pthis, EnSt_Die);
        return;
    }

    if (DECR(pthis->setTargetYawTimer) == 0) {
        pthis->deathYawTarget = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
        pthis->setTargetYawTimer = 8;
    }

    Math_SmoothStepToS(&pthis->actor.world.rot.x, 0x3FFC, 4, 0x2710, 1);
    Math_SmoothStepToS(&pthis->actor.world.rot.z, 0, 4, 0x2710, 1);
    Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->deathYawTarget.toS16(), 0xA, 0x2710, 1);

    pthis->actor.shape.rot = pthis->actor.world.rot;

    func_8002D868(&pthis->actor);
    pthis->groundBounces = 2;
    EnSt_IsDoneBouncing(pthis, globalCtx);
}

/**
 * Spawn the enemy dying effects, and drop a random item
 */
void EnSt_Die(EnSt* pthis, GlobalContext* globalCtx) {
    if (DECR(pthis->finishDeathTimer) != 0) {
        EnSt_SpawnDeadEffect(pthis, globalCtx);
    } else {
        Item_DropCollectibleRandom(globalCtx, NULL, &pthis->actor.world.pos, 0xE0);
        Actor_Kill(&pthis->actor);
    }
}

void EnSt_StartOnCeilingOrGround(EnSt* pthis, GlobalContext* globalCtx) {
    if (!EnSt_IsCloseToGround(pthis)) {
        pthis->rotAwayTimer = 60;
        EnSt_SetupAction(pthis, EnSt_WaitOnCeiling);
        EnSt_WaitOnCeiling(pthis, globalCtx);
    } else {
        EnSt_SetLandAnimation(pthis);
        EnSt_SetupAction(pthis, EnSt_LandOnGround);
        EnSt_LandOnGround(pthis, globalCtx);
    }
}

void EnSt_Update(Actor* pthisx, GlobalContext* globalCtx) {
    EnSt* pthis = (EnSt*)pthisx;
    s32 pad;
    Color_RGBA8 color = { 0, 0, 0, 0 };

    if (pthis->actor.flags & ACTOR_FLAG_15) {
        SkelAnime_Update(&pthis->skelAnime);
    } else if (!EnSt_CheckColliders(pthis, globalCtx)) {
        // no collision has been detected.

        if (pthis->stunTimer == 0) {
            SkelAnime_Update(&pthis->skelAnime);
        }

        if (pthis->swayTimer == 0 && pthis->stunTimer == 0) {
            func_8002D7EC(&pthis->actor);
        }

        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);

        if ((pthis->stunTimer == 0) && (pthis->swayTimer == 0)) {
            // run the current action if the Skulltula isn't stunned
            // or swaying.
            pthis->actionFunc(pthis, globalCtx);
        } else if (pthis->stunTimer != 0) {
            // decrement the stun timer.
            EnSt_DecrStunTimer(pthis);
        } else {
            // sway the Skulltula.
            EnSt_Sway(pthis);
        }

        EnSt_UpdateYaw(pthis, globalCtx);

        if (pthis->actionFunc == EnSt_WaitOnGround) {
            if ((globalCtx->state.frames & 0x10) != 0) {
                color.r = 255;
            }
        }

        EnSt_SetTeethColor(pthis, color.r, color.g, color.b, 8);
        EnSt_UpdateCylinders(pthis, globalCtx);
        Actor_SetFocus(&pthis->actor, 0.0f);
    }
}

s32 EnSt_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dListP, Vec3f* pos, Vec3s* rot, void* pthisx) {
    EnSt* pthis = (EnSt*)pthisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_st.c", 2260);
    switch (limbIndex) {
        case 1:
            if (pthis->gaveDamageSpinTimer != 0 && pthis->swayTimer == 0) {
                if (pthis->gaveDamageSpinTimer >= 2) {
                    EnSt_AddBlurVertex(pthis);
                } else {
                    EnSt_AddBlurSpace(pthis);
                }
            }
            break;
        case 4:
            // teeth
            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetEnvColor(POLY_OPA_DISP++, pthis->teethR, pthis->teethG, pthis->teethB, 0);
            break;
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_st.c", 2295);
    return false;
}

void EnSt_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dListP, Vec3s* rot, void* pthisx) {
    EnSt* pthis = (EnSt*)pthisx;

    Collider_UpdateSpheres(limbIndex, &pthis->colSph);
}

void EnSt_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    EnSt* pthis = (EnSt*)pthisx;

    EnSt_CheckBodyStickHit(pthis, globalCtx);
    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnSt_OverrideLimbDraw,
                      EnSt_PostLimbDraw, pthis);
}
