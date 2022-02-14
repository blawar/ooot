#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SSH_Z_EN_SSH_C
#include "actor_common.h"
#include "z_en_ssh.h"
#include "objects/object_ssh/object_ssh.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_eff_blure.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

#define SSH_STATE_STUNNED (1 << 0)
#define SSH_STATE_GROUND_START (1 << 2)
#define SSH_STATE_ATTACKED (1 << 3)
#define SSH_STATE_SPIN (1 << 4)

typedef enum {
    SSH_ANIM_UNK0, // Unused animation. Possibly being knocked back?
    SSH_ANIM_UP,
    SSH_ANIM_WAIT,
    SSH_ANIM_LAND,
    SSH_ANIM_DROP,
    SSH_ANIM_UNK5, // Slower version of ANIM_DROP
    SSH_ANIM_UNK6  // Faster repeating version of ANIM_UNK0
} EnSshAnimation;

void EnSsh_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSsh_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSsh_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSsh_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnSsh_Idle(EnSsh* pthis, GlobalContext* globalCtx);
void EnSsh_Drop(EnSsh* pthis, GlobalContext* globalCtx);
void EnSsh_Return(EnSsh* pthis, GlobalContext* globalCtx);
void EnSsh_Start(EnSsh* pthis, GlobalContext* globalCtx);

#include "overlays/ovl_En_Ssh/ovl_En_Ssh.cpp"

ActorInit En_Ssh_InitVars = {
    ACTOR_EN_SSH,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SSH,
    sizeof(EnSsh),
    (ActorFunc)EnSsh_Init,
    (ActorFunc)EnSsh_Destroy,
    (ActorFunc)EnSsh_Update,
    (ActorFunc)EnSsh_Draw,
};

static ColliderCylinderInit sCylinderInit1 = {
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

static CollisionCheckInfoInit2 sColChkInfoInit = { 1, 0, 0, 0, MASS_IMMOVABLE };

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
    ARRAY_COUNT(sJntSphElementsInit),
    sJntSphElementsInit,
};

void EnSsh_SetupAction(EnSsh* pthis, EnSshActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnSsh_SpawnShockwave(EnSsh* pthis, GlobalContext* globalCtx) {
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;

    pos.x = pthis->actor.world.pos.x;
    pos.y = pthis->actor.floorHeight;
    pos.z = pthis->actor.world.pos.z;
    EffectSsBlast_SpawnWhiteCustomScale(globalCtx, &pos, &zeroVec, &zeroVec, 100, 220, 8);
}

s32 EnSsh_CreateBlureEffect(GlobalContext* globalCtx) {
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

s32 EnSsh_CheckCeilingPos(EnSsh* pthis, GlobalContext* globalCtx) {
    CollisionPoly* poly;
    s32 bgId;
    Vec3f posB;

    posB.x = pthis->actor.world.pos.x;
    posB.y = pthis->actor.world.pos.y + 1000.0f;
    posB.z = pthis->actor.world.pos.z;
    if (!BgCheck_EntityLineTest1(&globalCtx->colCtx, &pthis->actor.world.pos, &posB, &pthis->ceilingPos, &poly, false,
                                 false, true, true, &bgId)) {
        return false;
    } else {
        return true;
    }
}

void EnSsh_AddBlureVertex(EnSsh* pthis) {
    Vec3f p1base = { 834.0f, 834.0f, 0.0f };
    Vec3f p2base = { 834.0f, -584.0f, 0.0f };
    Vec3f p1;
    Vec3f p2;

    p1base.x *= pthis->colliderScale;
    p1base.y *= pthis->colliderScale;
    p1base.z *= pthis->colliderScale;
    p2base.x *= pthis->colliderScale;
    p2base.y *= pthis->colliderScale;
    p2base.z *= pthis->colliderScale;
    Matrix_Push();
    Matrix_MultVec3f(&p1base, &p1);
    Matrix_MultVec3f(&p2base, &p2);
    Matrix_Pop();
    EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->blureIdx), &p1, &p2);
}

void EnSsh_AddBlureSpace(EnSsh* pthis) {
	EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->blureIdx));
}

void EnSsh_InitColliders(EnSsh* pthis, GlobalContext* globalCtx) {
    ColliderCylinderInit* cylinders[6] = {
        &sCylinderInit1, &sCylinderInit1, &sCylinderInit1, &sCylinderInit2, &sCylinderInit2, &sCylinderInit2,
    };
    s32 i;
    s32 pad;

    for (i = 0; i < ARRAY_COUNT(cylinders); i++) {
        Collider_InitCylinder(globalCtx, &pthis->colCylinder[i]);
        Collider_SetCylinder(globalCtx, &pthis->colCylinder[i], &pthis->actor, cylinders[i]);
    }

    pthis->colCylinder[0].info.bumper.dmgFlags = 0x0003F8E9;
    pthis->colCylinder[1].info.bumper.dmgFlags = 0xFFC00716;
    pthis->colCylinder[2].base.colType = COLTYPE_METAL;
    pthis->colCylinder[2].info.bumperFlags = BUMP_ON | BUMP_HOOKABLE | BUMP_NO_AT_INFO;
    pthis->colCylinder[2].info.elemType = ELEMTYPE_UNK2;
    pthis->colCylinder[2].info.bumper.dmgFlags = 0xFFCC0716;

    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(2), &sColChkInfoInit);

    Collider_InitJntSph(globalCtx, &pthis->colSph);
    Collider_SetJntSph(globalCtx, &pthis->colSph, &pthis->actor, &sJntSphInit, pthis->colSphElements);
}

f32 EnSsh_SetAnimation(EnSsh* pthis, s32 animIndex) {
    AnimationHeader* animation[] = {
        &object_ssh_Anim_005BE8, &object_ssh_Anim_000304, &object_ssh_Anim_000304, &object_ssh_Anim_0055F8,
        &object_ssh_Anim_000304, &object_ssh_Anim_000304, &object_ssh_Anim_005BE8,
    };
    f32 playbackSpeed[] = { 1.0f, 4.0f, 1.0f, 1.0f, 8.0f, 6.0f, 2.0f };
    u8 mode[] = { 3, 3, 1, 3, 1, 1, 1 };
    f32 frameCount = Animation_GetLastFrame(animation[animIndex]);
    s32 pad;

    Animation_Change(&pthis->skelAnime, animation[animIndex], playbackSpeed[animIndex], 0.0f, frameCount,
                     mode[animIndex], -6.0f);

    return frameCount;
}

void EnSsh_SetWaitAnimation(EnSsh* pthis) {
    EnSsh_SetAnimation(pthis, SSH_ANIM_WAIT);
}

void EnSsh_SetReturnAnimation(EnSsh* pthis) {
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_UP);
    EnSsh_SetAnimation(pthis, SSH_ANIM_UP);
}

void EnSsh_SetLandAnimation(EnSsh* pthis) {
    pthis->actor.world.pos.y = pthis->floorHeightOffset + pthis->actor.floorHeight;
    pthis->animTimer = EnSsh_SetAnimation(pthis, SSH_ANIM_LAND);
}

void EnSsh_SetDropAnimation(EnSsh* pthis) {
    if (pthis->unkTimer == 0) {
        pthis->animTimer = EnSsh_SetAnimation(pthis, SSH_ANIM_DROP);
    }
    pthis->actor.velocity.y = -10.0f;
}

void EnSsh_SetStunned(EnSsh* pthis) {
    if (pthis->stunTimer == 0) {
        pthis->stateFlags |= SSH_STATE_ATTACKED;
        pthis->stunTimer = 120;
        pthis->actor.colorFilterTimer = 0;
    }
}

void EnSsh_SetColliderScale(EnSsh* pthis, f32 scale, f32 radiusMod) {
    f32 radius;
    f32 height;
    f32 yShift;
    s32 i;

    radius = pthis->colSph.elements[0].dim.modelSphere.radius;
    radius *= scale;
    pthis->colSph.elements[0].dim.modelSphere.radius = radius;

    for (i = 0; i < 6; i++) {
        yShift = pthis->colCylinder[i].dim.yShift;
        radius = pthis->colCylinder[i].dim.radius;
        height = pthis->colCylinder[i].dim.height;
        yShift *= scale;
        radius *= scale * radiusMod;
        height *= scale;

        pthis->colCylinder[i].dim.yShift = yShift;
        pthis->colCylinder[i].dim.radius = radius;
        pthis->colCylinder[i].dim.height = height;
    }
    Actor_SetScale(&pthis->actor, 0.04f * scale);
    pthis->floorHeightOffset = 40.0f * scale;
    pthis->colliderScale = scale * 1.5f;
}

s32 EnSsh_Damaged(EnSsh* pthis) {
    if ((pthis->stunTimer == 120) && (pthis->stateFlags & SSH_STATE_STUNNED)) {
        Actor_SetColorFilter(&pthis->actor, 0, 0xC8, 0, pthis->stunTimer.whole());
    }
    if (DECR(pthis->stunTimer) != 0) {
        Math_SmoothStepToS(&pthis->maxTurnRate, 0x2710, 0xA, 0x3E8, 1);
        return false;
    } else {
        pthis->stunTimer = 0;
        pthis->stateFlags &= ~SSH_STATE_STUNNED;
        pthis->spinTimer = 0;
        if (pthis->swayTimer == 0) {
            pthis->spinTimer = 30;
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_ROLL);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_ST_ATTACK);
        return true;
    }
}

void EnSsh_Turn(EnSsh* pthis, GlobalContext* globalCtx) {
    if (pthis->hitTimer != 0) {
        pthis->hitTimer--;
    }
    if (DECR(pthis->spinTimer) != 0) {
	    pthis->actor.world.rot.y += 10000.0f * FRAMERATE_SCALER * (pthis->spinTimer.toFloat() / 30.0f);
    } else if ((pthis->swayTimer == 0) && (pthis->stunTimer == 0)) {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 4, 0x2710, 1);
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnSsh_Stunned(EnSsh* pthis, GlobalContext* globalCtx) {
    if ((pthis->swayTimer == 0) && (pthis->stunTimer == 0)) {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer ^ 0x8000, 4, pthis->maxTurnRate, 1);
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    if (pthis->stunTimer < 30) {
        if (pthis->stunTimer.whole() & 1) {
            pthis->actor.shape.rot.y += 0x7D0 * FRAMERATE_SCALER;
        } else {
            pthis->actor.shape.rot.y -= 0x7D0 * FRAMERATE_SCALER;
        }
    }
}

void EnSsh_UpdateYaw(EnSsh* pthis, GlobalContext* globalCtx) {
    if (pthis->stunTimer != 0) {
        EnSsh_Stunned(pthis, globalCtx);
    } else {
        EnSsh_Turn(pthis, globalCtx);
    }
}

void EnSsh_Bob(EnSsh* pthis, GlobalContext* globalCtx) {
    f32 bobVel = 0.5f;

    if ((globalCtx->state.frames & 8) != 0) {
        bobVel *= -1.0f;
    }
    Math_SmoothStepToF(&pthis->actor.velocity.y, bobVel, 0.4f, 1000.0f, 0.0f);
}

s32 EnSsh_IsCloseToLink(EnSsh* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 yDist;

    if (pthis->stateFlags & SSH_STATE_GROUND_START) {
        return true;
    }
    if (pthis->unkTimer != 0) {
        return true;
    }
    if (pthis->swayTimer != 0) {
        return true;
    }
    if (pthis->animTimer != 0) {
        return true;
    }

    if (pthis->actor.xzDistToPlayer > 160.0f) {
        return false;
    }

    yDist = pthis->actor.world.pos.y - player->actor.world.pos.y;
    if (yDist < 0.0f || yDist > 400.0f) {
        return false;
    }

    if (player->actor.world.pos.y < pthis->actor.floorHeight) {
        return false;
    }
    return true;
}

s32 EnSsh_IsCloseToHome(EnSsh* pthis) {
    f32 vel = pthis->actor.velocity.y;
    f32 nextY = pthis->actor.world.pos.y + 2.0f * pthis->actor.velocity.y;

    if (nextY >= pthis->actor.home.pos.y) {
        return 1;
    }
    return 0;
}

s32 EnSsh_IsCloseToGround(EnSsh* pthis) {
    f32 vel = pthis->actor.velocity.y;
    f32 nextY = pthis->actor.world.pos.y + 2.0f * pthis->actor.velocity.y;

    if ((nextY - pthis->actor.floorHeight) <= pthis->floorHeightOffset) {
        return 1;
    }
    return 0;
}

void EnSsh_Sway(EnSsh* pthis) {
    Vec3f swayVecBase;
    Vec3f swayVec;
    f32 temp;
    s16 swayAngle;

    if (pthis->swayTimer != 0) {
        pthis->swayAngle += 0x640 * FRAMERATE_SCALER;
        pthis->swayTimer--;
        if (pthis->swayTimer == 0) {
            pthis->swayAngle = 0;
        }
        temp = pthis->swayTimer.toFloat() * (1.0f / 6.0f);
        swayAngle = temp * (0x10000 / 360.0f) * Math_SinS(pthis->swayAngle);
        temp = pthis->actor.world.pos.y - pthis->ceilingPos.y;
        swayVecBase.x = Math_SinS(swayAngle) * temp;
        swayVecBase.y = Math_CosS(swayAngle) * temp;
        swayVecBase.z = 0.0f;
        Matrix_Push();
        Matrix_Translate(pthis->ceilingPos.x, pthis->ceilingPos.y, pthis->ceilingPos.z, MTXMODE_NEW);
        Matrix_RotateY(pthis->actor.world.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);
        Matrix_MultVec3f(&swayVecBase, &swayVec);
        Matrix_Pop();
        pthis->actor.shape.rot.z = -(swayAngle * 2);
        pthis->actor.world.pos.x = swayVec.x;
        pthis->actor.world.pos.z = swayVec.z;
    }
}

void EnSsh_CheckBodyStickHit(EnSsh* pthis, GlobalContext* globalCtx) {
    ColliderInfo* info = &pthis->colCylinder[0].info;
    Player* player = GET_PLAYER(globalCtx);

    if (player->unk_860 != 0) {
        info->bumper.dmgFlags |= 2;
        pthis->colCylinder[1].info.bumper.dmgFlags &= ~2;
        pthis->colCylinder[2].info.bumper.dmgFlags &= ~2;
    } else {
        info->bumper.dmgFlags &= ~2;
        pthis->colCylinder[1].info.bumper.dmgFlags |= 2;
        pthis->colCylinder[2].info.bumper.dmgFlags |= 2;
    }
}

s32 EnSsh_CheckHitPlayer(EnSsh* pthis, GlobalContext* globalCtx) {
    s32 i;
    s32 hit = false;

    if ((pthis->hitCount == 0) && (pthis->spinTimer == 0)) {
        return false;
    }
    for (i = 0; i < 3; i++) {
        if (pthis->colCylinder[i + 3].base.ocFlags2 & OC2_HIT_PLAYER) {
            pthis->colCylinder[i + 3].base.ocFlags2 &= ~OC2_HIT_PLAYER;
            hit = true;
        }
    }
    if (!hit) {
        return false;
    }
    pthis->hitTimer = 30;
    if (pthis->swayTimer == 0) {
        pthis->spinTimer = pthis->hitTimer;
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_ROLL);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_ST_ATTACK);
    globalCtx->damagePlayer(globalCtx, -8);
    func_8002F71C(globalCtx, &pthis->actor, 4.0f, pthis->actor.yawTowardsPlayer, 6.0f);
    pthis->hitCount--;
    return true;
}

s32 EnSsh_CheckHitFront(EnSsh* pthis) {
    u32 acFlags;

    if (pthis->colCylinder[2].base.acFlags) {} // Needed for matching
    acFlags = pthis->colCylinder[2].base.acFlags;

    if (!!(acFlags & AC_HIT) == 0) {
        return 0;
    } else {
        pthis->colCylinder[2].base.acFlags &= ~AC_HIT;
        pthis->invincibilityTimer = 8;
        if ((pthis->swayTimer == 0) && (pthis->hitTimer == 0) && (pthis->stunTimer == 0)) {
            pthis->swayTimer = 60;
        }
        return 1;
    }
}

s32 EnSsh_CheckHitBack(EnSsh* pthis, GlobalContext* globalCtx) {
    ColliderCylinder* cyl = &pthis->colCylinder[0];
    s32 hit = false;

    if (cyl->base.acFlags & AC_HIT) {
        cyl->base.acFlags &= ~AC_HIT;
        hit = true;
    }
    cyl = &pthis->colCylinder[1];
    if (cyl->base.acFlags & AC_HIT) {
        cyl->base.acFlags &= ~AC_HIT;
        hit = true;
    }
    if (!hit) {
        return false;
    }
    pthis->invincibilityTimer = 8;
    if (pthis->hitCount <= 0) {
        pthis->hitCount++;
    }
    if (pthis->stunTimer == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_ST_DAMAGE);
    }
    EnSsh_SetStunned(pthis);
    pthis->stateFlags |= SSH_STATE_STUNNED;
    return false;
}

s32 EnSsh_CollisionCheck(EnSsh* pthis, GlobalContext* globalCtx) {
    if (pthis->stunTimer == 0) {
        EnSsh_CheckHitPlayer(pthis, globalCtx);
    }
    if (EnSsh_CheckHitFront(pthis)) {
        return false;
    } else if (globalCtx->actorCtx.unk_02 != 0) {
        pthis->invincibilityTimer = 8;
        if (pthis->stunTimer == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_ST_DAMAGE);
        }
        EnSsh_SetStunned(pthis);
        pthis->stateFlags |= SSH_STATE_STUNNED;
        return false;
    } else {
        return EnSsh_CheckHitBack(pthis, globalCtx);
        // Always returns false
    }
}

void EnSsh_SetBodyCylinderAC(EnSsh* pthis, GlobalContext* globalCtx) {
    Collider_UpdateCylinder(&pthis->actor, &pthis->colCylinder[0]);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder[0].base);
}

void EnSsh_SetLegsCylinderAC(EnSsh* pthis, GlobalContext* globalCtx) {
    s16 angleTowardsLink = ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y));

    if (angleTowardsLink < 90 * (0x10000 / 360)) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->colCylinder[2]);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder[2].base);
    } else {
        Collider_UpdateCylinder(&pthis->actor, &pthis->colCylinder[1]);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder[1].base);
    }
}

s32 EnSsh_SetCylinderOC(EnSsh* pthis, GlobalContext* globalCtx) {
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
        Matrix_RotateY((pthis->initialYaw / (f32)0x8000) * M_PI, MTXMODE_APPLY);
        Matrix_MultVec3f(&cyloffsets[i], &cylPos);
        Matrix_Pop();
        pthis->colCylinder[i + 3].dim.pos.x = cylPos.x;
        pthis->colCylinder[i + 3].dim.pos.y = cylPos.y;
        pthis->colCylinder[i + 3].dim.pos.z = cylPos.z;
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder[i + 3].base);
    }
    return 1;
}

void EnSsh_SetColliders(EnSsh* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.colChkInfo.health == 0) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colSph.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colSph.base);
    } else {
        if (pthis->hitTimer == 0) {
            EnSsh_SetCylinderOC(pthis, globalCtx);
        }
        if (DECR(pthis->invincibilityTimer) == 0) {
            EnSsh_SetBodyCylinderAC(pthis, globalCtx);
            EnSsh_SetLegsCylinderAC(pthis, globalCtx);
        }
    }
}

void EnSsh_Init(Actor* thisx, GlobalContext* globalCtx) {
    f32 frameCount;
    s32 pad;
    EnSsh* pthis = (EnSsh*)thisx;

    frameCount = Animation_GetLastFrame(&object_ssh_Anim_000304);
    if (pthis->actor.params == ENSSH_FATHER) {
        if (gSaveContext.inventory.gsTokens >= 100) {
            Actor_Kill(&pthis->actor);
            return;
        }
    } else if (gSaveContext.inventory.gsTokens >= (pthis->actor.params * 10)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &object_ssh_Skel_0052E0, NULL, pthis->jointTable, pthis->morphTable, 30);
    Animation_Change(&pthis->skelAnime, &object_ssh_Anim_000304, 1.0f, 0.0f, frameCount, ANIMMODE_LOOP_INTERP, 0.0f);
    pthis->blureIdx = EnSsh_CreateBlureEffect(globalCtx);
    EnSsh_InitColliders(pthis, globalCtx);
    pthis->stateFlags = 0;
    pthis->hitCount = 0;
    EnSsh_CheckCeilingPos(pthis, globalCtx);
    if (pthis->actor.params != ENSSH_FATHER) {
        EnSsh_SetColliderScale(pthis, 0.5f, 1.0f);
    } else {
        EnSsh_SetColliderScale(pthis, 0.75f, 1.0f);
    }
    pthis->actor.gravity = 0.0f;
    pthis->initialYaw = pthis->actor.world.rot.y;
    EnSsh_SetupAction(pthis, EnSsh_Start);
}

void EnSsh_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnSsh* pthis = (EnSsh*)thisx;
    s32 i;

    Effect_Delete(globalCtx, pthis->blureIdx);
    for (i = 0; i < 6; i++) {
        Collider_DestroyCylinder(globalCtx, &pthis->colCylinder[i]);
    }
    Collider_DestroyJntSph(globalCtx, &pthis->colSph);
}

void EnSsh_Wait(EnSsh* pthis, GlobalContext* globalCtx) {
    if (EnSsh_IsCloseToLink(pthis, globalCtx)) {
        EnSsh_SetDropAnimation(pthis);
        EnSsh_SetupAction(pthis, EnSsh_Drop);
    } else {
        EnSsh_Bob(pthis, globalCtx);
    }
}

void EnSsh_Talk(EnSsh* pthis, GlobalContext* globalCtx) {
    EnSsh_Bob(pthis, globalCtx);
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnSsh_Idle;
    }
}

void EnSsh_Idle(EnSsh* pthis, GlobalContext* globalCtx) {
    if (1) {}
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnSsh_Talk;
        if (pthis->actor.params == ENSSH_FATHER) {
            gSaveContext.eventChkInf[9] |= 0x40;
        }
        if ((pthis->actor.textId == 0x26) || (pthis->actor.textId == 0x27)) {
            gSaveContext.infTable[25] |= 0x40;
        }
        if ((pthis->actor.textId == 0x24) || (pthis->actor.textId == 0x25)) {
            gSaveContext.infTable[25] |= 0x80;
        }
    } else {
        if ((pthis->unkTimer != 0) && (DECR(pthis->unkTimer) == 0)) {
            EnSsh_SetAnimation(pthis, SSH_ANIM_WAIT);
        }
        if ((pthis->animTimer != 0) && (DECR(pthis->animTimer) == 0)) {
            EnSsh_SetAnimation(pthis, SSH_ANIM_WAIT);
        }
        if (!EnSsh_IsCloseToLink(pthis, globalCtx)) {
            EnSsh_SetReturnAnimation(pthis);
            EnSsh_SetupAction(pthis, EnSsh_Return);
        } else {
            if (DECR(pthis->sfxTimer) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_LAUGH);
                pthis->sfxTimer = 64;
            }
            EnSsh_Bob(pthis, globalCtx);
            if ((pthis->unkTimer == 0) && (pthis->animTimer == 0)) {
                pthis->actor.textId = Text_GetFaceReaction(globalCtx, 0xD);
                if (pthis->actor.textId == 0) {
                    if (pthis->actor.params == ENSSH_FATHER) {
                        if (gSaveContext.inventory.gsTokens >= 50) {
                            pthis->actor.textId = 0x29;
                        } else if (gSaveContext.inventory.gsTokens >= 10) {
                            if (gSaveContext.infTable[25] & 0x80) {
                                pthis->actor.textId = 0x24;
                            } else {
                                pthis->actor.textId = 0x25;
                            }
                        } else {
                            if (gSaveContext.infTable[25] & 0x40) {
                                pthis->actor.textId = 0x27;
                            } else {
                                pthis->actor.textId = 0x26;
                            }
                        }
                    } else {
                        pthis->actor.textId = 0x22;
                    }
                }
                func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
            }
        }
    }
}

void EnSsh_Land(EnSsh* pthis, GlobalContext* globalCtx) {
    if ((pthis->unkTimer != 0) && (DECR(pthis->unkTimer) == 0)) {
        EnSsh_SetAnimation(pthis, SSH_ANIM_WAIT);
    }
    if ((pthis->animTimer != 0) && (DECR(pthis->animTimer) == 0)) {
        EnSsh_SetAnimation(pthis, SSH_ANIM_WAIT);
    }
    if ((pthis->actor.floorHeight + pthis->floorHeightOffset) <= pthis->actor.world.pos.y) {
        EnSsh_SetupAction(pthis, EnSsh_Idle);
    } else {
        Math_SmoothStepToF(&pthis->actor.velocity.y, 2.0f, 0.6f, 1000.0f, 0.0f);
    }
}

void EnSsh_Drop(EnSsh* pthis, GlobalContext* globalCtx) {
    if ((pthis->unkTimer != 0) && (DECR(pthis->unkTimer) == 0)) {
        EnSsh_SetAnimation(pthis, SSH_ANIM_DROP);
    }
    if (!EnSsh_IsCloseToLink(pthis, globalCtx)) {
        EnSsh_SetReturnAnimation(pthis);
        EnSsh_SetupAction(pthis, EnSsh_Return);
    } else if (EnSsh_IsCloseToGround(pthis)) {
        EnSsh_SpawnShockwave(pthis, globalCtx);
        EnSsh_SetLandAnimation(pthis);
        EnSsh_SetupAction(pthis, EnSsh_Land);
    } else if (DECR(pthis->sfxTimer) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALTU_DOWN);
        pthis->sfxTimer = 3;
    }
}

void EnSsh_Return(EnSsh* pthis, GlobalContext* globalCtx) {
    f32 frameRatio = pthis->skelAnime.curFrame / (pthis->skelAnime.animLength - 1.0f);

    if (frameRatio == 1.0f) {
        EnSsh_SetReturnAnimation(pthis);
    }
    if (EnSsh_IsCloseToLink(pthis, globalCtx)) {
        EnSsh_SetDropAnimation(pthis);
        EnSsh_SetupAction(pthis, EnSsh_Drop);
    } else if (EnSsh_IsCloseToHome(pthis)) {
        EnSsh_SetWaitAnimation(pthis);
        EnSsh_SetupAction(pthis, EnSsh_Wait);
    } else {
        pthis->actor.velocity.y = 4.0f * frameRatio;
    }
}

void EnSsh_UpdateColliderScale(EnSsh* pthis) {
    if (pthis->stateFlags & SSH_STATE_SPIN) {
        if (pthis->spinTimer == 0) {
            pthis->stateFlags &= ~SSH_STATE_SPIN;
            if (pthis->actor.params != ENSSH_FATHER) {
                EnSsh_SetColliderScale(pthis, 0.5f, 1.0f);
            } else {
                EnSsh_SetColliderScale(pthis, 0.75f, 1.0f);
            }
        }
    } else {
        if (pthis->spinTimer != 0) {
            pthis->stateFlags |= SSH_STATE_SPIN;
            if (pthis->actor.params != ENSSH_FATHER) {
                EnSsh_SetColliderScale(pthis, 0.5f, 2.0f);
            } else {
                EnSsh_SetColliderScale(pthis, 0.75f, 2.0f);
            }
        }
    }
}

void EnSsh_Start(EnSsh* pthis, GlobalContext* globalCtx) {
    if (!EnSsh_IsCloseToGround(pthis)) {
        EnSsh_SetupAction(pthis, EnSsh_Wait);
        EnSsh_Wait(pthis, globalCtx);
    } else {
        EnSsh_SetLandAnimation(pthis);
        pthis->stateFlags |= 4;
        EnSsh_SetupAction(pthis, EnSsh_Land);
        EnSsh_Land(pthis, globalCtx);
    }
}

void EnSsh_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnSsh* pthis = (EnSsh*)thisx;

    EnSsh_UpdateColliderScale(pthis);
    if (EnSsh_CollisionCheck(pthis, globalCtx)) {
        return; // EnSsh_CollisionCheck always returns false, so pthis never happens
    }
    if (pthis->stunTimer != 0) {
        EnSsh_Damaged(pthis);
    } else {
        SkelAnime_Update(&pthis->skelAnime);
        func_8002D7EC(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
        pthis->actionFunc(pthis, globalCtx);
    }
    EnSsh_UpdateYaw(pthis, globalCtx);
    if (DECR(pthis->blinkTimer) == 0) {
        pthis->blinkTimer = Rand_S16Offset(60, 60);
    }
    pthis->blinkState = pthis->blinkTimer;
    if (pthis->blinkState >= 3) {
        pthis->blinkState = 0;
    }
    EnSsh_SetColliders(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, 0.0f);
}

s32 EnSsh_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnSsh* pthis = (EnSsh*)thisx;

    switch (limbIndex) {
        case 1:
            if ((pthis->spinTimer != 0) && (pthis->swayTimer == 0)) {
                if (pthis->spinTimer >= 2) {
                    EnSsh_AddBlureVertex(pthis);
                } else {
                    EnSsh_AddBlureSpace(pthis);
                }
            }
            break;
        case 4:
            if (pthis->actor.params == ENSSH_FATHER) {
                *dList = object_ssh_DL_0046C0;
            }
            break;
        case 5:
            if (pthis->actor.params == ENSSH_FATHER) {
                *dList = object_ssh_DL_004080;
            }
            break;
        case 8:
            if (pthis->actor.params == ENSSH_FATHER) {
                *dList = object_ssh_DL_004DE8;
            }
            break;
    }
    return false;
}

void EnSsh_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnSsh* pthis = (EnSsh*)thisx;

    Collider_UpdateSpheres(limbIndex, &pthis->colSph);
}

void EnSsh_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* blinkTex[] = {
        object_ssh_Tex_0007E0,
        object_ssh_Tex_000C60,
        object_ssh_Tex_001060,
    };
    s32 pad;
    EnSsh* pthis = (EnSsh*)thisx;

    EnSsh_CheckBodyStickHit(pthis, globalCtx);
    EnSsh_Sway(pthis);
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ssh.c", 2333);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(blinkTex[pthis->blinkState]));
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ssh.c", 2336);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnSsh_OverrideLimbDraw,
                      EnSsh_PostLimbDraw, &pthis->actor);
}
