#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FW_Z_EN_FW_C
#include "actor_common.h"
/*
 * File: z_en_fw.c
 * Overlay: ovl_En_Fw
 * Description: Flare Dancer Core
 */

#include "z_en_fw.h"
#include "objects/object_fw/object_fw.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_9)

void EnFw_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFw_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnFw_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFw_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFw_Draw(Actor* thisx, GlobalContext* globalCtx);
void EnFw_UpdateDust(EnFw* pthis);
void EnFw_DrawDust(EnFw* pthis, GlobalContext* globalCtx);
void EnFw_AddDust(EnFw* pthis, Vec3f* initialPos, Vec3f* initialSpeed, Vec3f* accel, u8 initialTimer, f32 scale,
                  f32 scaleStep);
void EnFw_Bounce(EnFw* pthis, GlobalContext* globalCtx);
void EnFw_Run(EnFw* pthis, GlobalContext* globalCtx);
void EnFw_JumpToParentInitPos(EnFw* pthis, GlobalContext* globalCtx);
void EnFw_TurnToParentInitPos(EnFw* pthis, GlobalContext* globalCtx);

static void* dustTextures_54[] = {
    gDust8Tex, gDust7Tex, gDust6Tex, gDust5Tex, gDust4Tex, gDust3Tex, gDust2Tex, gDust1Tex,
};


ActorInit En_Fw_InitVars = {
    ACTOR_EN_FW,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_FW,
    sizeof(EnFw),
    (ActorFunc)EnFw_Init,
    (ActorFunc)EnFw_Destroy,
    (ActorFunc)EnFw_Update,
    (ActorFunc)EnFw_Draw,
    (ActorFunc)EnFw_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x04 },
            { 0xFFCFFFFE, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 2, { { 1200, 0, 0 }, 16 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT6,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static CollisionCheckInfoInit2 D_80A1FB94 = { 8, 2, 25, 25, MASS_IMMOVABLE };

static struct_80034EC0_Entry D_80A1FBA0[] = {
    { &gFlareDancerCoreInitRunCycleAnim, 0.0f, 0.0f, -1.0f, ANIMMODE_ONCE_INTERP, 0.0f },
    { &gFlareDancerCoreRunCycleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE_INTERP, -8.0f },
    { &gFlareDancerCoreEndRunCycleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP_INTERP, -8.0f },
};

s32 EnFw_DoBounce(EnFw* pthis, s32 totalBounces, f32 yVelocity) {
    s16 temp_v1;

    if (!(pthis->actor.bgCheckFlags & 1) || (pthis->actor.velocity.y > 0.0f)) {
        // not on the ground or moving upwards.
        return false;
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
    pthis->bounceCnt--;
    if (pthis->bounceCnt <= 0) {
        if (pthis->bounceCnt == 0) {
            pthis->bounceCnt = 0;
            pthis->actor.velocity.y = 0.0f;
            return true;
        }
        pthis->bounceCnt = totalBounces;
    }
    pthis->actor.velocity.y = yVelocity;
    pthis->actor.velocity.y *= ((f32)pthis->bounceCnt / totalBounces);
    return 1;
}

s32 EnFw_PlayerInRange(EnFw* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    CollisionPoly* poly;
    s32 bgId;
    Vec3f collisionPos;

    if (pthis->actor.xzDistToPlayer > 300.0f) {
        return false;
    }

    if (ABS((s16)((f32)pthis->actor.yawTowardsPlayer - (f32)pthis->actor.shape.rot.y)) > 0x1C70) {
        return false;
    }

    if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &pthis->actor.world.pos, &player->actor.world.pos, &collisionPos,
                                &poly, true, false, false, true, &bgId)) {
        return false;
    }

    return true;
}

Vec3f* EnFw_GetPosAdjAroundCircle(Vec3f* dst, EnFw* pthis, f32 radius, s16 dir) {
    s16 angle;
    Vec3f posAdj;

    // increase rotation around circle ~30 degrees.
    angle = Math_Vec3f_Yaw(&pthis->actor.parent->home.pos, &pthis->actor.world.pos) + (dir * 0x1554);
    posAdj.x = (Math_SinS(angle) * radius) + pthis->actor.parent->home.pos.x;
    posAdj.z = (Math_CosS(angle) * radius) + pthis->actor.parent->home.pos.z;
    posAdj.x -= pthis->actor.world.pos.x;
    posAdj.z -= pthis->actor.world.pos.z;
    *dst = posAdj;
    return dst;
}

s32 EnFw_CheckCollider(EnFw* pthis, GlobalContext* globalCtx) {
    ColliderInfo* info;
    s32 phi_return;

    if (pthis->collider.base.acFlags & AC_HIT) {
        info = &pthis->collider.elements[0].info;
        if (info->acHitInfo->toucher.dmgFlags & 0x80) {
            pthis->lastDmgHook = true;
        } else {
            pthis->lastDmgHook = false;
        }
        pthis->collider.base.acFlags &= ~AC_HIT;
        if (Actor_ApplyDamage(&pthis->actor) <= 0) {
            if (pthis->actor.parent->colChkInfo.health <= 8) {
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                pthis->actor.parent->colChkInfo.health = 0;
            } else {
                pthis->actor.parent->colChkInfo.health -= 8;
            }
            pthis->returnToParentTimer = 0;
        }
        return true;
    } else {
        return false;
    }
}

s32 EnFw_SpawnDust(EnFw* pthis, u8 timer, f32 scale, f32 scaleStep, s32 dustCnt, f32 radius, f32 xzAccel, f32 yAccel) {
    Vec3f pos = { 0.0f, 0.0f, 0.0f };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    s16 angle;
    s32 i;

    pos = pthis->actor.world.pos;
    pos.y = pthis->actor.floorHeight + 2.0f;
    angle = ((Rand_ZeroOne() - 0.5f) * 0x10000);
    i = dustCnt;
    while (i >= 0) {
        accel.x = (Rand_ZeroOne() - 0.5f) * xzAccel;
        accel.y = yAccel;
        accel.z = (Rand_ZeroOne() - 0.5f) * xzAccel;
        pos.x = (Math_SinS(angle) * radius) + pthis->actor.world.pos.x;
        pos.z = (Math_CosS(angle) * radius) + pthis->actor.world.pos.z;
        EnFw_AddDust(pthis, &pos, &velocity, &accel, timer, scale, scaleStep);
        angle += (s16)(0x10000 / dustCnt);
        i--;
    }
    return 0;
}

void EnFw_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnFw* pthis = (EnFw*)thisx;

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gFlareDancerCoreSkel, NULL, pthis->jointTable, pthis->morphTable,
                       11);
    func_80034EC0(&pthis->skelAnime, D_80A1FBA0, 0);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 20.0f);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->sphs);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(0x10), &D_80A1FB94);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->runDirection = -pthis->actor.params;
    pthis->actionFunc = EnFw_Bounce;
    pthis->actor.gravity = -1.0f;
}

void EnFw_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFw* pthis = (EnFw*)thisx;
    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnFw_Bounce(EnFw* pthis, GlobalContext* globalCtx) {
    if (EnFw_DoBounce(pthis, 3, 8.0f) && pthis->bounceCnt == 0) {
        pthis->returnToParentTimer = Rand_S16Offset(300, 150);
        pthis->actionFunc = EnFw_Run;
    }
}

void EnFw_Run(EnFw* pthis, GlobalContext* globalCtx) {
    f32 tmpAngle;
    s16 phi_v0;
    f32 facingDir;
    EnBom* bomb;
    Actor* flareDancer;

    Math_SmoothStepToF(&pthis->skelAnime.playSpeed, 1.0f, 0.1f, 1.0f, 0.0f);
    if (pthis->skelAnime.animation == &gFlareDancerCoreInitRunCycleAnim) {
        if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame) == 0) {
            pthis->runRadius = Math_Vec3f_DistXYZ(&pthis->actor.world.pos, &pthis->actor.parent->world.pos);
            func_80034EC0(&pthis->skelAnime, D_80A1FBA0, 2);
        }
        return;
    }

    if (pthis->damageTimer == 0 && pthis->explosionTimer == 0 && EnFw_CheckCollider(pthis, globalCtx)) {
        if (pthis->actor.parent->colChkInfo.health > 0) {
            if (!pthis->lastDmgHook) {
                pthis->actor.velocity.y = 6.0f;
            }
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLAME_MAN_DAMAGE);
            pthis->damageTimer = 20;
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLAME_MAN_DAMAGE);
            pthis->explosionTimer = 6;
        }
        pthis->actor.speedXZ = 0.0f;
    }

    if (pthis->explosionTimer != 0) {
        pthis->skelAnime.playSpeed = 0.0f;
        Math_SmoothStepToF(&pthis->actor.scale.x, 0.024999999f, 0.08f, 0.6f, 0.0f);
        Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
        if (pthis->actor.colorFilterTimer == 0) {
            Actor_SetColorFilter(&pthis->actor, 0x4000, 0xC8, 0, pthis->explosionTimer);
            pthis->explosionTimer--;
        }

        if (pthis->explosionTimer == 0) {
            bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pthis->bompPos.x, pthis->bompPos.y,
                                       pthis->bompPos.z, 0, 0, 0x600, 0);
            if (bomb != NULL) {
                bomb->timer = 0;
            }
            flareDancer = pthis->actor.parent;
            flareDancer->params |= 0x4000;
            Item_DropCollectibleRandom(globalCtx, NULL, &pthis->actor.world.pos, 0xA0);
            Actor_Kill(&pthis->actor);
            return;
        }
    } else {
        if (!(pthis->actor.bgCheckFlags & 1) || pthis->actor.velocity.y > 0.0f) {
            Actor_SetColorFilter(&pthis->actor, 0x4000, 0xC8, 0, pthis->damageTimer);
            return;
        }
        DECR(pthis->damageTimer);
        if ((200.0f - pthis->runRadius) < 0.9f) {
            if (DECR(pthis->returnToParentTimer) == 0) {
                pthis->actor.speedXZ = 0.0f;
                pthis->actionFunc = EnFw_TurnToParentInitPos;
                return;
            }
        }

        // Run outwards until the radius of the run circle is 200
        Math_SmoothStepToF(&pthis->runRadius, 200.0f, 0.3f, 100.0f, 0.0f);

        if (pthis->turnAround) {
            Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.1f, 1.0f, 0.0f);
            tmpAngle = (s16)(pthis->actor.world.rot.y ^ 0x8000);
            facingDir = pthis->actor.shape.rot.y;
            tmpAngle = Math_SmoothStepToF(&facingDir, tmpAngle, 0.1f, 10000.0f, 0.0f);
            pthis->actor.shape.rot.y = facingDir;
            if (tmpAngle > 0x1554) {
                return;
            }
            pthis->turnAround = false;
        } else {
            Vec3f sp48;
            EnFw_GetPosAdjAroundCircle(&sp48, pthis, pthis->runRadius, pthis->runDirection);
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, (Math_FAtan2F(sp48.x, sp48.z) * (0x8000 / M_PI)), 4, 0xFA0, 1);
        }

        pthis->actor.world.rot = pthis->actor.shape.rot;

        if (pthis->slideTimer == 0 && EnFw_PlayerInRange(pthis, globalCtx)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLAME_MAN_SURP);
            pthis->slideSfxTimer = 8;
            pthis->slideTimer = 8;
        }

        if (pthis->slideTimer != 0) {
            if (DECR(pthis->slideSfxTimer) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLAME_MAN_SLIDE);
                pthis->slideSfxTimer = 4;
            }
            Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.1f, 1.0f, 0.0f);
            pthis->skelAnime.playSpeed = 0.0f;
            EnFw_SpawnDust(pthis, 8, 0.16f, 0.2f, 3, 8.0f, 20.0f, ((Rand_ZeroOne() - 0.5f) * 0.2f) + 0.3f);
            pthis->slideTimer--;
            if (pthis->slideTimer == 0) {
                pthis->turnAround = true;
                pthis->runDirection = -pthis->runDirection;
            }
        } else {
            Math_SmoothStepToF(&pthis->actor.speedXZ, 6.0f, 0.1f, 1.0f, 0.0f);
            phi_v0 = pthis->skelAnime.curFrame;
            if (phi_v0 == 1 || phi_v0 == 4) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLAME_MAN_RUN);
                EnFw_SpawnDust(pthis, 8, 0.16f, 0.1f, 1, 0.0f, 20.0f, 0.0f);
            }
        }
    }
}

void EnFw_TurnToParentInitPos(EnFw* pthis, GlobalContext* globalCtx) {
    s16 angleToParentInit;

    angleToParentInit = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.parent->home.pos);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, angleToParentInit, 4, 0xFA0, 1);
    if (ABS(angleToParentInit - pthis->actor.shape.rot.y) < 0x65) {
        // angle to parent init pos is ~0.5 degrees
        pthis->actor.world.rot = pthis->actor.shape.rot;
        pthis->actor.velocity.y = 14.0f;
        pthis->actor.home.pos = pthis->actor.world.pos;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
        func_80034EC0(&pthis->skelAnime, D_80A1FBA0, 1);
        pthis->actionFunc = EnFw_JumpToParentInitPos;
    }
}

void EnFw_JumpToParentInitPos(EnFw* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 1 && pthis->actor.velocity.y <= 0.0f) {
        pthis->actor.parent->params |= 0x8000;
        Actor_Kill(&pthis->actor);
    } else {
        Math_SmoothStepToF(&pthis->actor.world.pos.x, pthis->actor.parent->home.pos.x, 0.6f, 8.0f, 0.0f);
        Math_SmoothStepToF(&pthis->actor.world.pos.z, pthis->actor.parent->home.pos.z, 0.6f, 8.0f, 0.0f);
    }
}

void EnFw_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnFw* pthis = (EnFw*)thisx;
    SkelAnime_Update(&pthis->skelAnime);
    if (!CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_13)) {
        // not attached to hookshot.
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 20.0f, 0.0f, 5);
        pthis->actionFunc(pthis, globalCtx);
        if (pthis->damageTimer == 0 && pthis->explosionTimer == 0 && pthis->actionFunc == EnFw_Run) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

s32 EnFw_OverrideLimbDraw(GlobalContext* globalContext, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                          void* thisx) {
    return false;
}

void EnFw_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnFw* pthis = (EnFw*)thisx;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    if (limbIndex == 2) {
        // body
        Matrix_MultVec3f(&zeroVec, &pthis->bompPos);
    }

    if (limbIndex == 3) {
        // head
        Matrix_MultVec3f(&zeroVec, &pthis->actor.focus.pos);
    }

    Collider_UpdateSpheres(limbIndex, &pthis->collider);
}

void EnFw_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnFw* pthis = (EnFw*)thisx;

    EnFw_UpdateDust(pthis);
    Matrix_Push();
    EnFw_DrawDust(pthis, globalCtx);
    Matrix_Pop();
    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnFw_OverrideLimbDraw, EnFw_PostLimbDraw, pthis);
}

void EnFw_AddDust(EnFw* pthis, Vec3f* initialPos, Vec3f* initialSpeed, Vec3f* accel, u8 initialTimer, f32 scale,
                  f32 scaleStep) {
    EnFwEffect* eff = pthis->effects;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++, eff++) {
        if (eff->type != 1) {
            eff->scale = scale;
            eff->scaleStep = scaleStep;
            eff->initialTimer = eff->timer = initialTimer;
            eff->type = 1;
            eff->pos = *initialPos;
            eff->accel = *accel;
            eff->velocity = *initialSpeed;
            return;
        }
    }
}

void EnFw_UpdateDust(EnFw* pthis) {
    EnFwEffect* eff = pthis->effects;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++, eff++) {
        if (eff->type != 0) {
            if ((--eff->timer) == 0) {
                eff->type = 0;
            }
            eff->accel.x = (Rand_ZeroOne() * 0.4f) - 0.2f;
            eff->accel.z = (Rand_ZeroOne() * 0.4f) - 0.2f;
            eff->pos.x += eff->velocity.x;
            eff->pos.y += eff->velocity.y;
            eff->pos.z += eff->velocity.z;
            eff->velocity.x += eff->accel.x;
            eff->velocity.y += eff->accel.y;
            eff->velocity.z += eff->accel.z;
            eff->scale += eff->scaleStep;
        }
    }
}

void EnFw_DrawDust(EnFw* pthis, GlobalContext* globalCtx) {
    EnFwEffect* eff = pthis->effects;
    s16 firstDone;
    s16 alpha;
    s16 i;
    s16 idx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fw.c", 1191);

    firstDone = false;
    func_80093D84(globalCtx->state.gfxCtx);
    if (1) {}

    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++, eff++) {
        if (eff->type != 0) {
            if (!firstDone) {
                POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0U);
                gSPDisplayList(POLY_XLU_DISP++, gFlareDancerDL_7928);
                gDPSetEnvColor(POLY_XLU_DISP++, 100, 60, 20, 0);
                firstDone = true;
            }

            alpha = eff->timer * (255.0f / eff->initialTimer);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 170, 130, 90, alpha);
            gDPPipeSync(POLY_XLU_DISP++);
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(eff->scale, eff->scale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fw.c", 1229),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            idx = eff->timer * (8.0f / eff->initialTimer);
            gSPSegment(POLY_XLU_DISP++, 0x8, SEGMENTED_TO_VIRTUAL(dustTextures_54[idx]));
            gSPDisplayList(POLY_XLU_DISP++, gFlareDancerSquareParticleDL);
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fw.c", 1243);
}

void EnFw_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Fw_InitVars = {
        ACTOR_EN_FW,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_FW,
        sizeof(EnFw),
        (ActorFunc)EnFw_Init,
        (ActorFunc)EnFw_Destroy,
        (ActorFunc)EnFw_Update,
        (ActorFunc)EnFw_Draw,
        (ActorFunc)EnFw_Reset,
    };

    sJntSphInit = {
        {
            COLTYPE_HIT6,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphElementsInit,
    };

    D_80A1FB94 = { 8, 2, 25, 25, MASS_IMMOVABLE };

}
