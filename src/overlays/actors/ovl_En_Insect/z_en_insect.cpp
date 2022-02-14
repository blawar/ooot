#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_INSECT_Z_EN_INSECT_C
#include "actor_common.h"
#include "kaleido.h"
/*
 * File: z_en_insect.c
 * Overlay: ovl_En_Insect
 * Description: Bugs
 */

#include "z_en_insect.h"
#include "vt.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS 0

void EnInsect_Init(Actor* thisx, GlobalContext* globalCtx);
void EnInsect_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnInsect_Update(Actor* thisx, GlobalContext* globalCtx);
void EnInsect_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A7C3A0(EnInsect* pthis);
void func_80A7C3F4(EnInsect* pthis, GlobalContext* globalCtx);
void func_80A7C598(EnInsect* pthis);
void func_80A7C5EC(EnInsect* pthis, GlobalContext* globalCtx);
void func_80A7C818(EnInsect* pthis);
void func_80A7C86C(EnInsect* pthis, GlobalContext* globalCtx);
void func_80A7CAD0(EnInsect* pthis, GlobalContext* globalCtx);
void func_80A7CBC8(EnInsect* pthis);
void func_80A7CC3C(EnInsect* pthis, GlobalContext* globalCtx);
void func_80A7CE60(EnInsect* pthis);
void func_80A7CEC0(EnInsect* pthis, GlobalContext* globalCtx);
void func_80A7D1F4(EnInsect* pthis);
void func_80A7D26C(EnInsect* pthis, GlobalContext* globalCtx);
void func_80A7D39C(EnInsect* pthis);
void func_80A7D460(EnInsect* pthis, GlobalContext* globalCtx);

static f32 D_80A7DEB0 = 0.0f;
static s16 D_80A7DEB4 = 0;
static s16 D_80A7DEB8 = 0;

ActorInit En_Insect_InitVars = {
    ACTOR_EN_INSECT,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnInsect),
    (ActorFunc)EnInsect_Init,
    (ActorFunc)EnInsect_Destroy,
    (ActorFunc)EnInsect_Update,
    (ActorFunc)EnInsect_Draw,
};

static ColliderJntSphElementInit sColliderItemInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 5 }, 100 },
    },
};

static ColliderJntSphInit sColliderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER | OC1_TYPE_1,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sColliderItemInit,
};

static u16 D_80A7DF10[] = { 0, 5, 7, 7 };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 700, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 20, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 600, ICHAIN_STOP),
};

void func_80A7BE20(EnInsect* pthis) {
    pthis->unk_314 = D_80A7DF10[pthis->actor.params & 3];
}

f32 EnInsect_XZDistanceSquared(Vec3f* v1, Vec3f* v2) {
    return SQ(v1->x - v2->x) + SQ(v1->z - v2->z);
}

s32 EnInsect_InBottleRange(EnInsect* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f pos;

    if (pthis->actor.xzDistToPlayer < 32.0f) {
        pos.x = Math_SinS(pthis->actor.yawTowardsPlayer + 0x8000) * 16.0f + player->actor.world.pos.x;
        pos.y = player->actor.world.pos.y;
        pos.z = Math_CosS(pthis->actor.yawTowardsPlayer + 0x8000) * 16.0f + player->actor.world.pos.z;

        //! @bug: pthis check is superfluous: it is automatically satisfied if the coarse check is satisfied. It may have
        //! been intended to check the actor is in front of Player, but yawTowardsPlayer does not depend on Player's
        //! world rotation.
        if (EnInsect_XZDistanceSquared(&pos, &pthis->actor.world.pos) <= SQ(20.0f)) {
            return true;
        }
    }

    return false;
}

void func_80A7BF58(EnInsect* pthis) {
    Animation_Change(&pthis->skelAnime, &gBugCrawlAnim, 1.0f, 0.0f, 0.0f, ANIMMODE_LOOP_INTERP, 0.0f);
}

/**
 * Find the nearest soft dirt patch within 6400 units in the xz plane and the current room
 *
 * @return 1 if one was found, 0 otherwise
 */
s32 EnInsect_FoundNearbySoil(EnInsect* pthis, GlobalContext* globalCtx) {
    Actor* currentActor;
    f32 currentDistance;
    f32 bestDistance;
    s32 ret;

    ret = 0;
    currentActor = globalCtx->actorCtx.actorLists[ACTORCAT_ITEMACTION].head;
    bestDistance = 6400.0f;
    pthis->soilActor = NULL;

    while (currentActor != NULL) {
        if (currentActor->id == ACTOR_OBJ_MAKEKINSUTA) {
            currentDistance = Math3D_Dist2DSq(pthis->actor.world.pos.x, pthis->actor.world.pos.z,
                                              currentActor->world.pos.x, currentActor->world.pos.z);

            if (currentDistance < bestDistance && currentActor->room == pthis->actor.room) {
                ret = 1;
                bestDistance = currentDistance;
                pthis->soilActor = (ObjMakekinsuta*)currentActor;
            }
        }
        currentActor = currentActor->next;
    }
    return ret;
}

void func_80A7C058(EnInsect* pthis) {
    if (pthis->unk_31E > 0) {
        pthis->unk_31E--;
        return;
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MUSI_WALK);

    pthis->unk_31E = 3.0f / CLAMP_MIN(pthis->skelAnime.playSpeed, 0.1f);
    if (pthis->unk_31E < 2) {
        pthis->unk_31E = 2;
    }
}

void EnInsect_Init(Actor* thisx, GlobalContext* globalCtx2) {
    EnInsect* pthis = (EnInsect*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    f32 rand;
    s16 temp_s2;
    s32 count;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    func_80A7BE20(pthis);

    temp_s2 = pthis->actor.params & 3;

    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gBugSkel, &gBugCrawlAnim, pthis->jointTable, pthis->morphTable, 24);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sColliderInit, &pthis->colliderItem);

    pthis->actor.colChkInfo.mass = 30;

    if (pthis->unk_314 & 1) {
        pthis->actor.gravity = -0.2f;
        pthis->actor.minVelocityY = -2.0f;
    }

    if (pthis->unk_314 & 4) {
        pthis->unk_31C = Rand_S16Offset(200, 40);
        pthis->actor.flags |= ACTOR_FLAG_4;
    }

    if (temp_s2 == 2 || temp_s2 == 3) {
        if (EnInsect_FoundNearbySoil(pthis, globalCtx)) {
            pthis->unk_314 |= 0x10;
            D_80A7DEB0 = 0.0f;
        }

        if (temp_s2 == 2) {
            pthis->actor.world.rot.z = 0;
            pthis->actor.shape.rot.z = pthis->actor.world.rot.z;

            for (count = 0; count < 2; count++) {
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_INSECT, pthis->actor.world.pos.x,
                            pthis->actor.world.pos.y, pthis->actor.world.pos.z, pthis->actor.shape.rot.x,
                            pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, 3);
            }
        }

        func_80A7D39C(pthis);

        D_80A7DEB8++;
    } else {
        rand = Rand_ZeroOne();

        if (rand < 0.3f) {
            func_80A7C3A0(pthis);
        } else if (rand < 0.4f) {
            func_80A7C598(pthis);
        } else {
            func_80A7C818(pthis);
        }
    }
}

void EnInsect_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s16 temp_v0;
    EnInsect* pthis = (EnInsect*)thisx;

    temp_v0 = pthis->actor.params & 3;
    Collider_DestroyJntSph(globalCtx, &pthis->collider);
    if ((temp_v0 == 2 || temp_v0 == 3) && D_80A7DEB8 > 0) {
        D_80A7DEB8--;
    }
}

void func_80A7C3A0(EnInsect* pthis) {
    pthis->unk_31A = Rand_S16Offset(5, 35);
    func_80A7BF58(pthis);
    pthis->actionFunc = func_80A7C3F4;
    pthis->unk_314 |= 0x100;
}

void func_80A7C3F4(EnInsect* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 sp2E;
    f32 playSpeed;

    sp2E = pthis->actor.params & 3;

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.1f, 0.5f, 0.0f);

    playSpeed = (Rand_ZeroOne() * 0.8f) + (pthis->actor.speedXZ * 1.2f);
    pthis->skelAnime.playSpeed = CLAMP(playSpeed, 0.0f, 1.9f);

    SkelAnime_Update(&pthis->skelAnime);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    if (pthis->unk_31A <= 0) {
        func_80A7C598(pthis);
    }

    if (((pthis->unk_314 & 4) && pthis->unk_31C <= 0) ||
        ((sp2E == 2 || sp2E == 3) && (pthis->unk_314 & 1) && (pthis->actor.bgCheckFlags & 1) && D_80A7DEB8 >= 4)) {
        func_80A7CBC8(pthis);
    } else if ((pthis->unk_314 & 1) && (pthis->actor.bgCheckFlags & 0x40)) {
        func_80A7CE60(pthis);
    } else if (pthis->actor.xzDistToPlayer < 40.0f) {
        func_80A7C818(pthis);
    }
}

void func_80A7C598(EnInsect* pthis) {
    pthis->unk_31A = Rand_S16Offset(10, 45);
    func_80A7BF58(pthis);
    pthis->actionFunc = func_80A7C5EC;
    pthis->unk_314 |= 0x100;
}

void func_80A7C5EC(EnInsect* pthis, GlobalContext* globalCtx) {
    s32 pad1;
    s32 pad2;
    s16 yaw;
    s16 sp34 = pthis->actor.params & 3;

    Math_SmoothStepToF(&pthis->actor.speedXZ, 1.5f, 0.1f, 0.5f, 0.0f);

    if (EnInsect_XZDistanceSquared(&pthis->actor.world.pos, &pthis->actor.home.pos) > 1600.0f || (pthis->unk_31A < 4)) {
        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
        Math_ScaledStepToS(&pthis->actor.world.rot.y, yaw, 2000);
    } else if (pthis->actor.child != NULL && &pthis->actor != pthis->actor.child) {
        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.child->world.pos);
        Math_ScaledStepToS(&pthis->actor.world.rot.y, yaw, 2000);
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    pthis->skelAnime.playSpeed = CLAMP(pthis->actor.speedXZ * 1.4f, 0.7f, 1.9f);

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_31A <= 0) {
        func_80A7C3A0(pthis);
    }

    if (((pthis->unk_314 & 4) && pthis->unk_31C <= 0) ||
        ((sp34 == 2 || sp34 == 3) && (pthis->unk_314 & 1) && (pthis->actor.bgCheckFlags & 1) && D_80A7DEB8 >= 4)) {
        func_80A7CBC8(pthis);
    } else if ((pthis->unk_314 & 1) && (pthis->actor.bgCheckFlags & 0x40)) {
        func_80A7CE60(pthis);
    } else if (pthis->actor.xzDistToPlayer < 40.0f) {
        func_80A7C818(pthis);
    }
}

void func_80A7C818(EnInsect* pthis) {
    pthis->unk_31A = Rand_S16Offset(10, 40);
    func_80A7BF58(pthis);
    pthis->actionFunc = func_80A7C86C;
    pthis->unk_314 |= 0x100;
}

void func_80A7C86C(EnInsect* pthis, GlobalContext* globalCtx) {
    s32 pad1;
    s32 pad2;
    s16 pad3;
    const auto& frames = globalCtx->state.frames;
    s16 yaw;
    s16 sp38 = pthis->actor.xzDistToPlayer < 40.0f;

    Math_SmoothStepToF(&pthis->actor.speedXZ, 1.8f, 0.1f, 0.5f, 0.0f);

    if (EnInsect_XZDistanceSquared(&pthis->actor.world.pos, &pthis->actor.home.pos) > 25600.0f || pthis->unk_31A < 4) {
        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
        Math_ScaledStepToS(&pthis->actor.world.rot.y, yaw, 2000);
    } else if (sp38 != 0) {
        yaw = pthis->actor.yawTowardsPlayer + 0x8000;

        if (frames & 0x10) {
            if (frames & 0x20) {
                yaw += 0x2000;
            }
        } else {
            if (frames & 0x20) {
                yaw -= 0x2000;
            }
        }
        if (globalCtx) {} // Must be 'globalCtx'
        Math_ScaledStepToS(&pthis->actor.world.rot.y, yaw, 2000);
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    pthis->skelAnime.playSpeed = CLAMP(pthis->actor.speedXZ * 1.6f, 0.8f, 1.9f);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_31A <= 0 || !sp38) {
        func_80A7C3A0(pthis);
    } else if ((pthis->unk_314 & 1) && (pthis->actor.bgCheckFlags & 0x40)) {
        func_80A7CE60(pthis);
    }
}

void func_80A7CA64(EnInsect* pthis) {
    pthis->unk_31A = 200;

    Actor_SetScale(&pthis->actor, 0.001f);

    pthis->actor.draw = NULL;
    pthis->actor.speedXZ = 0.0f;

    func_80A7BF58(pthis);

    pthis->skelAnime.playSpeed = 0.3f;
    pthis->actionFunc = func_80A7CAD0;
    pthis->unk_314 &= ~0x100;
}

void func_80A7CAD0(EnInsect* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_31A == 20 && !(pthis->unk_314 & 4)) {
        pthis->actor.draw = EnInsect_Draw;
    } else if (pthis->unk_31A == 0) {
        if (pthis->unk_314 & 4) {
            Actor_Kill(&pthis->actor);
        } else {
            Actor_SetScale(&pthis->actor, 0.01f);
            func_80A7C3A0(pthis);
        }
    } else if (pthis->unk_31A < 20) {
        Actor_SetScale(&pthis->actor, CLAMP_MAX(pthis->actor.scale.x + 0.001f, 0.01f));
        SkelAnime_Update(&pthis->skelAnime);
    }
}

void func_80A7CBC8(EnInsect* pthis) {
    pthis->unk_31A = 60;
    func_80A7BF58(pthis);
    pthis->skelAnime.playSpeed = 1.9f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MUSI_SINK);
    Math_Vec3f_Copy(&pthis->actor.home.pos, &pthis->actor.world.pos);
    pthis->actionFunc = func_80A7CC3C;
    pthis->unk_314 &= ~0x100;
    pthis->unk_314 |= 0x8;
}

void func_80A7CC3C(EnInsect* pthis, GlobalContext* globalCtx) {
    static Vec3f accel = { 0.0f, 0.0f, 0.0f };
    static Vec3f unused = { 0.0f, 0.0f, 0.0f };
    s32 pad[2];
    Vec3f velocity;

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.1f, 0.5f, 0.0f);
    Math_StepToS(&pthis->actor.shape.rot.x, 10922, 352);

    Actor_SetScale(&pthis->actor, CLAMP_MIN(pthis->actor.scale.x - 0.0002f, 0.001f));

    pthis->actor.shape.yOffset -= 0.8f;
    pthis->actor.world.pos.x = Rand_ZeroOne() + pthis->actor.home.pos.x - 0.5f;
    pthis->actor.world.pos.z = Rand_ZeroOne() + pthis->actor.home.pos.z - 0.5f;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_31A > 20 && Rand_ZeroOne() < 0.1f) {
        velocity.x = Math_SinS(pthis->actor.shape.rot.y) * -0.6f;
        velocity.y = Math_SinS(pthis->actor.shape.rot.x) * 0.6f;
        velocity.z = Math_CosS(pthis->actor.shape.rot.y) * -0.6f;
        func_800286CC(globalCtx, &pthis->actor.world.pos, &velocity, &accel, Rand_ZeroOne() * 5.0f + 8.0f,
                      Rand_ZeroOne() * 5.0f + 8.0f);
    }

    if (pthis->unk_31A <= 0) {
        if ((pthis->unk_314 & 0x10) && pthis->soilActor != NULL &&
            Math3D_Vec3fDistSq(&pthis->soilActor->actor.world.pos, &pthis->actor.world.pos) < 64.0f) {
            pthis->soilActor->unk_152 = 1;
        }
        Actor_Kill(&pthis->actor);
    }
}

void func_80A7CE60(EnInsect* pthis) {
    pthis->unk_31A = Rand_S16Offset(120, 50);
    func_80A7BF58(pthis);
    pthis->unk_316 = pthis->unk_318 = 0;
    pthis->actionFunc = func_80A7CEC0;
    pthis->unk_314 &= ~0x100;
}

void func_80A7CEC0(EnInsect* pthis, GlobalContext* globalCtx) {
    f32 temp_f0;
    s16 temp_v1;
    s16 pad;
    s16 sp4E;
    Vec3f sp40;
    s32 phi_v0;
    s32 phi_v0_2;

    sp4E = pthis->actor.params & 3;

    if (pthis->unk_31A >= 81) {
        Math_StepToF(&pthis->actor.speedXZ, 0.6f, 0.08f);
    } else {
        Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.02f);
    }
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.world.pos.y += pthis->actor.yDistToWater;
    pthis->skelAnime.playSpeed = CLAMP(pthis->unk_31A * 0.018f, 0.1f, 1.9f);

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_31A >= 81) {
        pthis->unk_316 += Rand_S16Offset(-50, 100);
        pthis->unk_318 += Rand_S16Offset(-300, 600);
    }

    temp_v1 = pthis->skelAnime.playSpeed * 200.0f;

    if (pthis->unk_316 < -temp_v1) {
        pthis->unk_316 = -temp_v1;
    } else {
        if (temp_v1 < pthis->unk_316) {
            phi_v0 = temp_v1;
        } else {
            phi_v0 = pthis->unk_316;
        }
        pthis->unk_316 = phi_v0;
    }
    pthis->actor.world.rot.y += pthis->unk_316;

    temp_v1 = pthis->skelAnime.playSpeed * 1000.0f;
    if (pthis->unk_318 < -temp_v1) {
        pthis->unk_318 = -temp_v1;
    } else {
        if (temp_v1 < pthis->unk_318) {
            phi_v0_2 = temp_v1;
        } else {
            phi_v0_2 = pthis->unk_318;
        }
        pthis->unk_318 = phi_v0_2;
    }
    pthis->actor.shape.rot.y += pthis->unk_318;

    Math_ScaledStepToS(&pthis->actor.world.rot.x, 0, 3000);
    pthis->actor.shape.rot.x = pthis->actor.world.rot.x;

    if (Rand_ZeroOne() < 0.03f) {
        sp40.x = pthis->actor.world.pos.x;
        sp40.y = pthis->actor.world.pos.y + pthis->actor.yDistToWater;
        sp40.z = pthis->actor.world.pos.z;
        EffectSsGRipple_Spawn(globalCtx, &sp40, 20, 100, 4);
        EffectSsGRipple_Spawn(globalCtx, &sp40, 40, 200, 8);
    }

    if (pthis->unk_31A <= 0 || ((pthis->unk_314 & 4) && pthis->unk_31C <= 0) ||
        ((sp4E == 2 || sp4E == 3) && (pthis->unk_314 & 1) && D_80A7DEB8 >= 4)) {
        func_80A7D1F4(pthis);
    } else if (!(pthis->actor.bgCheckFlags & 0x40)) {
        if (pthis->unk_314 & 0x10) {
            func_80A7D39C(pthis);
        } else {
            func_80A7C3A0(pthis);
        }
    }
}

void func_80A7D1F4(EnInsect* pthis) {
    pthis->unk_31A = 100;
    func_80A7BF58(pthis);
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.minVelocityY = -0.8f;
    pthis->actor.gravity = -0.04f;
    pthis->unk_314 &= ~0x3;
    pthis->actionFunc = func_80A7D26C;
    pthis->unk_314 &= ~0x100;
    pthis->unk_314 |= 8;
}

void func_80A7D26C(EnInsect* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.rot.x -= 500;
    pthis->actor.shape.rot.y += 200;
    Actor_SetScale(&pthis->actor, CLAMP_MIN(pthis->actor.scale.x - 0.00005f, 0.001f));

    if (pthis->actor.yDistToWater > 5.0f && pthis->actor.yDistToWater < 30.0f && Rand_ZeroOne() < 0.3f) {
        EffectSsBubble_Spawn(globalCtx, &pthis->actor.world.pos, -5.0f, 5.0f, 5.0f, (Rand_ZeroOne() * 0.04f) + 0.02f);
    }

    if (pthis->unk_31A <= 0) {
        Actor_Kill(&pthis->actor);
    }
}

void func_80A7D39C(EnInsect* pthis) {
    func_80A7BF58(pthis);
    pthis->unk_31A = 100;
    pthis->unk_324 = 1.5f;
    pthis->unk_328 = Rand_ZeroOne() * (0xFFFF + 0.5f);
    pthis->unk_316 = (Rand_ZeroOne() - 0.5f) * 1500.0f;
    pthis->actor.world.rot.y = Rand_ZeroOne() * (0xFFFF + 0.5f);
    Actor_SetScale(&pthis->actor, 0.003f);
    pthis->actionFunc = func_80A7D460;
    pthis->unk_314 |= 0x100;
}

void func_80A7D460(EnInsect* pthis, GlobalContext* globalCtx) {
    s32 temp_a0;
    s32 sp50;
    f32 phi_f0;
    EnInsect* thisTemp = pthis;
    s32 temp_a1;
    f32 sp40;
    f32 phi_f2;
    s16 sp3A;
    s16 sp38;
    f32 sp34;

    sp50 = 0;
    sp3A = pthis->actor.params & 3;

    if (pthis->soilActor != NULL) {
        sp40 = Math3D_Vec3fDistSq(&pthis->actor.world.pos, &pthis->soilActor->actor.world.pos);
    } else {
        if (pthis->unk_314 & 0x10) {
            osSyncPrintf(VT_COL(YELLOW, BLACK));
            // "warning: target Actor is NULL"
            osSyncPrintf("warning:目標 Actor が NULL (%s %d)\n", "../z_en_mushi.c", 1046);
            osSyncPrintf(VT_RST);
        }
        sp40 = 40.0f;
    }

    D_80A7DEB0 += 0.99999994f / 300.0f;
    if (D_80A7DEB0 > 1.0f) {
        D_80A7DEB0 = 1.0f;
    }

    if (D_80A7DEB0 > 0.999f) {
        phi_f2 = 0.0f;
    } else {
        if (sp40 > 900.0f) {
            phi_f2 = ((1.1f - D_80A7DEB0) * 100.0f) + 20.0f;
        } else {
            phi_f2 = (1.0f - D_80A7DEB0) * 10.0f;
        }
    }

    if (pthis->soilActor != NULL && Rand_ZeroOne() < 0.07f) {
        pthis->actor.home.pos.x = (Rand_ZeroOne() - 0.5f) * phi_f2 + thisTemp->soilActor->actor.world.pos.x;
        pthis->actor.home.pos.y = thisTemp->soilActor->actor.world.pos.y;
        pthis->actor.home.pos.z = (Rand_ZeroOne() - 0.5f) * phi_f2 + thisTemp->soilActor->actor.world.pos.z;
    }

    if (D_80A7DEB0 > 0.999f) {
        pthis->unk_328 = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
        pthis->unk_324 = Rand_ZeroOne() * 0.6f + 0.6f;
    } else if (Rand_ZeroOne() < 0.07f) {
        if (pthis->unk_324 > 1.0f) {
            pthis->unk_324 = 0.1f;
        } else {
            pthis->unk_324 = Rand_ZeroOne() * 0.8f + 1.0f;
        }

        sp34 = 1.3f - D_80A7DEB0;
        if (sp34 < 0.0f) {
            sp34 = 0.0f;
        } else {
            if (sp34 > 1.0f) {
                phi_f0 = 1.0f;
            } else {
                phi_f0 = sp34;
            }
            sp34 = phi_f0;
        }

        sp38 = (Rand_ZeroOne() - 0.5f) * 65535.0f * sp34;
        pthis->unk_328 = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos) + sp38;
    }

    Actor_SetScale(&pthis->actor, CLAMP_MAX(thisTemp->actor.scale.x + 0.0008f, 0.01f));

    if (pthis->actor.bgCheckFlags & 1) {
        Math_SmoothStepToF(&pthis->actor.speedXZ, pthis->unk_324, 0.1f, 0.5f, 0.0f);
        Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->unk_328, 2000);
        sp50 = Math_ScaledStepToS(&pthis->actor.world.rot.x, 0, 2000);
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        pthis->actor.shape.rot.x = pthis->actor.world.rot.x;
    } else {
        Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.1f, 0.5f, 0.0f);
        pthis->actor.speedXZ += (Rand_ZeroOne() - 0.5f) * 0.14f;
        pthis->actor.velocity.y += Rand_ZeroOne() * 0.12f;
        pthis->actor.world.rot.y += pthis->unk_316;
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        pthis->actor.shape.rot.x -= 2000;
    }

    phi_f2 = Rand_ZeroOne() * 0.5f + pthis->actor.speedXZ * 1.3f;
    if (phi_f2 < 0.0f) {
        pthis->skelAnime.playSpeed = 0.0f;
    } else {
        if (phi_f2 > 1.9f) {
            phi_f0 = 1.9f;
        } else {
            phi_f0 = phi_f2;
        }
        pthis->skelAnime.playSpeed = phi_f0;
    }

    SkelAnime_Update(&pthis->skelAnime);
    if (!(pthis->unk_314 & 0x40) && (pthis->unk_314 & 1) && (pthis->actor.bgCheckFlags & 1)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MUSI_LAND);
        pthis->unk_314 |= 0x40;
    }

    if (sp3A == 2 && (pthis->unk_314 & 0x10) && !(pthis->unk_314 & 0x80)) {
        if (pthis->unk_32A >= 15) {
            if (pthis->soilActor != NULL) {
                if (!(GET_GS_FLAGS(((pthis->soilActor->actor.params >> 8) & 0x1F) - 1) &
                      (pthis->soilActor->actor.params & 0xFF))) {
                    func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
                }
            }
            pthis->unk_314 |= 0x80;
        } else {
            pthis->unk_32A++;
        }
    }

    if ((pthis->unk_314 & 1) && (pthis->actor.bgCheckFlags & 0x40)) {
        func_80A7CE60(pthis);
    } else if (pthis->unk_314 & 0x10) {
        if (sp40 < 9.0f) {
            func_80A7CBC8(pthis);
        } else if (pthis->unk_31A <= 0 || pthis->unk_31C <= 0 ||
                   ((pthis->unk_314 & 1) && (pthis->actor.bgCheckFlags & 1) && D_80A7DEB8 >= 4 &&
                    (sp3A == 2 || sp3A == 3))) {
            func_80A7CBC8(pthis);
        } else {
            if (sp40 < 900.0f) {
                pthis->unk_31C++;
                pthis->unk_314 |= 0x20;
            } else {
                pthis->unk_31A = 100;
            }
        }
    } else if (sp50 != 0) {
        func_80A7C3A0(pthis);
    } else if ((sp3A == 2 || sp3A == 3) && (pthis->unk_314 & 1) && pthis->unk_31C <= 0 && pthis->unk_31A <= 0 &&
               pthis->actor.floorHeight < BGCHECK_Y_MIN + 10.0f) {
        osSyncPrintf(VT_COL(YELLOW, BLACK));
        // "BG missing? To do Actor_delete"
        osSyncPrintf("BG 抜け？ Actor_delete します(%s %d)\n", "../z_en_mushi.c", 1197);
        osSyncPrintf(VT_RST);
        Actor_Kill(&pthis->actor);
    }
}

void EnInsect_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnInsect* pthis = (EnInsect*)thisx;
    s32 phi_v0;

    if (pthis->actor.child != NULL) {
        if (pthis->actor.child->update == NULL) {
            if (&pthis->actor != pthis->actor.child) {
                pthis->actor.child = NULL;
            }
        }
    }

    if (pthis->unk_31A > 0) {
        pthis->unk_31A--;
    }

    if (pthis->unk_31C > 0) {
        pthis->unk_31C--;
    }

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->actor.update != NULL) {
        Actor_MoveForward(&pthis->actor);
        if (pthis->unk_314 & 0x100) {
            if (pthis->unk_314 & 1) {
                if (pthis->actor.bgCheckFlags & 1) {
                    func_80A7C058(pthis);
                }
            } else {
                func_80A7C058(pthis);
            }
        }

        phi_v0 = 0;

        if (pthis->unk_314 & 1) {
            phi_v0 = 4;
        }

        if (pthis->unk_314 & 2) {
            phi_v0 |= 1;
        }

        if (phi_v0 != 0) {
            phi_v0 |= 0x40;
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 8.0f, 5.0f, 0.0f, phi_v0);
        }

        if (Actor_HasParent(&pthis->actor, globalCtx)) {
            pthis->actor.parent = NULL;
            phi_v0 = pthis->actor.params & 3;

            if (phi_v0 == 2 || phi_v0 == 3) {
                Actor_Kill(&pthis->actor);
            } else {
                func_80A7CA64(pthis);
            }
        } else if (pthis->actor.xzDistToPlayer < 50.0f && pthis->actionFunc != func_80A7CAD0) {
            if (!(pthis->unk_314 & 0x20) && pthis->unk_31C < 180) {
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }

            if (!(pthis->unk_314 & 8) && D_80A7DEB4 < 4 && EnInsect_InBottleRange(pthis, globalCtx) &&
                // GI_MAX in pthis case allows the player to catch the actor in a bottle
                func_8002F434(&pthis->actor, globalCtx, GI_MAX, 60.0f, 30.0f)) {
                D_80A7DEB4++;
            }
        }

        Actor_SetFocus(&pthis->actor, 0.0f);
    }
}

void EnInsect_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnInsect* pthis = (EnInsect*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL, NULL, NULL);
    Collider_UpdateSpheres(0, &pthis->collider);
    D_80A7DEB4 = 0;
}
