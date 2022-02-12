#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BA_Z_EN_BA_C
#include "actor_common.h"
/*
 * File: z_en_ba.c
 * Overlay: ovl_En_Ba
 * Description: Tentacle from inside Lord Jabu-Jabu
 */

#include "z_en_ba.h"
#include "objects/object_bxa/object_bxa.h"
#include "def/graph.h"
#include "def/sys_math.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)

void EnBa_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBa_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBa_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnBa_SetupIdle(EnBa* pthis);
void EnBa_SetupFallAsBlob(EnBa* pthis);
void EnBa_Idle(EnBa* pthis, GlobalContext* globalCtx);
void EnBa_FallAsBlob(EnBa* pthis, GlobalContext* globalCtx);
void EnBa_SwingAtPlayer(EnBa* pthis, GlobalContext* globalCtx);
void EnBa_RecoilFromDamage(EnBa* pthis, GlobalContext* globalCtx);
void EnBa_Die(EnBa* pthis, GlobalContext* globalCtx);
void EnBa_SetupSwingAtPlayer(EnBa* pthis);

ActorInit En_Ba_InitVars = {
    ACTOR_EN_BA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BXA,
    sizeof(EnBa),
    (ActorFunc)EnBa_Init,
    (ActorFunc)EnBa_Destroy,
    (ActorFunc)EnBa_Update,
    (ActorFunc)EnBa_Draw,
};

static Vec3f D_809B8080 = { 0.0f, 0.0f, 32.0f };

static ColliderJntSphElementInit sJntSphElementInit[2] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000010, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 8, { { 0, 0, 0 }, 20 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x20000000, 0x00, 0x04 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 13, { { 0, 0, 0 }, 25 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT0,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_JNTSPH,
    },
    2,
    sJntSphElementInit,
};

void EnBa_SetupAction(EnBa* pthis, EnBaActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

static Vec3f D_809B80E4 = { 0.01f, 0.01f, 0.01f };

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x15, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2500, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 0, ICHAIN_STOP),
};

void EnBa_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnBa* pthis = (EnBa*)thisx;
    Vec3f sp38 = D_809B80E4;
    s32 pad;
    s16 i;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + 100.0f;
    for (i = 13; i >= 0; i--) {
        pthis->unk200[i] = sp38;
        pthis->unk2A8[i].x = -0x4000;
        pthis->unk158[i] = pthis->actor.world.pos;
        pthis->unk158[i].y = pthis->actor.world.pos.y - (i + 1) * 32.0f;
    }

    pthis->actor.targetMode = 4;
    pthis->upperParams = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;

    if (pthis->actor.params < EN_BA_DEAD_BLOB) {
        if (Flags_GetSwitch(globalCtx, pthis->upperParams)) {
            Actor_Kill(&pthis->actor);
            return;
        }
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 48.0f);
        Actor_SetScale(&pthis->actor, 0.01f);
        EnBa_SetupIdle(pthis);
        pthis->actor.colChkInfo.health = 4;
        pthis->actor.colChkInfo.mass = MASS_HEAVY;
        Collider_InitJntSph(globalCtx, &pthis->collider);
        Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItems);
    } else {
        Actor_SetScale(&pthis->actor, 0.021f);
        EnBa_SetupFallAsBlob(pthis);
    }
}

void EnBa_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnBa* pthis = (EnBa*)thisx;
    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnBa_SetupIdle(EnBa* pthis) {
    pthis->unk14C = 2;
    pthis->unk31C = 1500;
    pthis->actor.speedXZ = 10.0f;
    EnBa_SetupAction(pthis, EnBa_Idle);
}

void EnBa_Idle(EnBa* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 i;
    s32 pad;
    Vec3s sp5C;

    if ((pthis->actor.colChkInfo.mass == MASS_IMMOVABLE) && (pthis->actor.xzDistToPlayer > 175.0f)) {
        Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 330.0f, 1.0f, 7.0f, 0.0f);
    } else {
        pthis->actor.flags |= ACTOR_FLAG_0;
        Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 100.0f, 1.0f, 10.0f, 0.0f);
    }
    pthis->unk2FC = pthis->actor.world.pos;
    if (globalCtx->gameplayFrames % 16 == 0) {
        pthis->unk308.z += Rand_CenteredFloat(180.0f);
        pthis->unk314 += Rand_CenteredFloat(180.0f);
        pthis->unk308.x = Math_SinF(pthis->unk308.z) * 80.0f;
        pthis->unk308.y = Math_CosF(pthis->unk314) * 80.0f;
    }
    pthis->unk2FC.y -= 448.0f;
    pthis->unk2FC.x += pthis->unk308.x;
    pthis->unk2FC.z += pthis->unk308.y;
    func_80033AEC(&pthis->unk2FC, &pthis->unk158[13], 1.0f, pthis->actor.speedXZ, 0.0f, 0.0f);
    for (i = 12; i >= 0; i--) {
        func_80035844(&pthis->unk158[i + 1], &pthis->unk158[i], &sp5C, 0);
        Matrix_Translate(pthis->unk158[i + 1].x, pthis->unk158[i + 1].y, pthis->unk158[i + 1].z, MTXMODE_NEW);
        Matrix_RotateZYX(sp5C.x, sp5C.y, 0, MTXMODE_APPLY);
        Matrix_MultVec3f(&D_809B8080, &pthis->unk158[i]);
    }
    func_80035844(&pthis->unk158[0], &pthis->unk2FC, &sp5C, 0);
    Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->unk2A8[0].y, 3, pthis->unk31C, 182);
    Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->unk2A8[0].x, 3, pthis->unk31C, 182);
    Matrix_RotateZYX(pthis->actor.shape.rot.x - 0x8000, pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);
    Matrix_MultVec3f(&D_809B8080, &pthis->unk158[0]);
    pthis->unk2A8[13].y = sp5C.y;
    pthis->unk2A8[13].x = sp5C.x + 0x8000;

    for (i = 0; i < 13; i++) {
        Matrix_Translate(pthis->unk158[i].x, pthis->unk158[i].y, pthis->unk158[i].z, MTXMODE_NEW);
        Math_SmoothStepToS(&pthis->unk2A8[i].y, pthis->unk2A8[i + 1].y, 3, pthis->unk31C, 182);
        Math_SmoothStepToS(&pthis->unk2A8[i].x, pthis->unk2A8[i + 1].x, 3, pthis->unk31C, 182);
        Matrix_RotateZYX(pthis->unk2A8[i].x - 0x8000, pthis->unk2A8[i].y, 0, MTXMODE_APPLY);
        Matrix_MultVec3f(&D_809B8080, &pthis->unk158[i + 1]);
    }
    pthis->unk2A8[13].x = pthis->unk2A8[12].x;
    pthis->unk2A8[13].y = pthis->unk2A8[12].y;
    if (!(player->stateFlags1 & 0x4000000) && (pthis->actor.xzDistToPlayer <= 175.0f) &&
        (pthis->actor.world.pos.y == pthis->actor.home.pos.y + 100.0f)) {
        EnBa_SetupSwingAtPlayer(pthis);
    }
}

void EnBa_SetupFallAsBlob(EnBa* pthis) {
    pthis->unk14C = 0;
    pthis->actor.speedXZ = Rand_CenteredFloat(8.0f);
    pthis->actor.world.rot.y = Rand_CenteredFloat(65535.0f);
    pthis->unk318 = 20;
    pthis->actor.gravity = -2.0f;
    EnBa_SetupAction(pthis, EnBa_FallAsBlob);
}

/**
 * Action function of the pink fleshy blobs that spawn and fall to the floor when a tentacle dies
 */
void EnBa_FallAsBlob(EnBa* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.scale.y -= 0.001f;
        pthis->actor.scale.x += 0.0005f;
        pthis->actor.scale.z += 0.0005f;
        pthis->unk318--;
        if (pthis->unk318 == 0) {
            Actor_Kill(&pthis->actor);
        }
    } else {
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 30.0f, 28.0f, 80.0f, 5);
    }
}

void EnBa_SetupSwingAtPlayer(EnBa* pthis) {
    pthis->unk14C = 3;
    pthis->unk318 = 20;
    pthis->unk31A = 0;
    pthis->unk31C = 1500;
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->actor.speedXZ = 20.0f;
    EnBa_SetupAction(pthis, EnBa_SwingAtPlayer);
}

void EnBa_SwingAtPlayer(EnBa* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 temp;
    s16 i;
    Vec3s sp58;
    s16 phi_fp;

    Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 60.0f, 1.0f, 10.0f, 0.0f);
    if ((pthis->actor.xzDistToPlayer <= 175.0f) || (pthis->unk31A != 0)) {
        if (pthis->unk318 == 20) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_HAND_UP);
            pthis->unk31C = 1500;
        }
        if (pthis->unk318 != 0) {
            pthis->unk31A = 10;
            pthis->unk318--;
            if (pthis->unk318 >= 11) {
                pthis->unk2FC = player->actor.world.pos;
                pthis->unk2FC.y += 30.0f;
                phi_fp = pthis->actor.yawTowardsPlayer;
            } else {
                phi_fp = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->unk2FC);
            }
            Math_SmoothStepToS(&pthis->unk31C, 1500, 1, 30, 0);
            func_80035844(&pthis->actor.world.pos, &pthis->unk158[0], &sp58, 0);
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, sp58.y, 1, pthis->unk31C, 0);
            Math_SmoothStepToS(&pthis->actor.shape.rot.x, (sp58.x + 0x8000), 1, pthis->unk31C, 0);
            Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
            Matrix_RotateZYX((pthis->actor.shape.rot.x - 0x8000), pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);
            Matrix_MultVec3f(&D_809B8080, &pthis->unk158[0]);

            for (i = 0; i < 13; i++) {
                Math_SmoothStepToS(&pthis->unk2A8[i].x, (i * 1200) - 0x4000, 1, pthis->unk31C, 0);
                Math_SmoothStepToS(&pthis->unk2A8[i].y, phi_fp, 1, pthis->unk31C, 0);
                Matrix_Translate(pthis->unk158[i].x, pthis->unk158[i].y, pthis->unk158[i].z, MTXMODE_NEW);
                Matrix_RotateZYX((pthis->unk2A8[i].x - 0x8000), pthis->unk2A8[i].y, 0, MTXMODE_APPLY);
                Matrix_MultVec3f(&D_809B8080, &pthis->unk158[i + 1]);
            }
        } else {
            if (pthis->unk31A == 10) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_HAND_DOWN);
            }
            if (pthis->unk31A != 0) {
                pthis->unk31C = 8000;
                pthis->actor.speedXZ = 30.0f;
                phi_fp = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->unk2FC);
                temp = Math_Vec3f_Pitch(&pthis->actor.world.pos, &pthis->unk158[0]) + 0x8000;
                Math_SmoothStepToS(&pthis->actor.shape.rot.y, phi_fp, 1, pthis->unk31C, 0);
                Math_SmoothStepToS(&pthis->actor.shape.rot.x, temp, 1, pthis->unk31C, 0);
                Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z,
                                 MTXMODE_NEW);
                Matrix_RotateZYX(pthis->actor.shape.rot.x - 0x8000, pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);
                Matrix_MultVec3f(&D_809B8080, pthis->unk158);

                for (i = 0; i < 13; i++) {
                    temp = -Math_CosS(pthis->unk31A * 0xCCC) * (i * 1200);
                    Math_SmoothStepToS(&pthis->unk2A8[i].x, temp - 0x4000, 1, pthis->unk31C, 0);
                    Math_SmoothStepToS(&pthis->unk2A8[i].y, phi_fp, 1, pthis->unk31C, 0);
                    Matrix_Translate(pthis->unk158[i].x, pthis->unk158[i].y, pthis->unk158[i].z, MTXMODE_NEW);
                    Matrix_RotateZYX(pthis->unk2A8[i].x - 0x8000, pthis->unk2A8[i].y, 0, MTXMODE_APPLY);
                    Matrix_MultVec3f(&D_809B8080, &pthis->unk158[i + 1]);
                }
                pthis->unk31A--;
            } else if ((pthis->actor.xzDistToPlayer > 175.0f) || (player->stateFlags1 & 0x4000000)) {
                EnBa_SetupIdle(pthis);
            } else {
                EnBa_SetupSwingAtPlayer(pthis);
                pthis->unk318 = 27;
                pthis->unk31C = 750;
            }
        }
        pthis->unk2A8[13].x = pthis->unk2A8[12].x;
        pthis->unk2A8[13].y = pthis->unk2A8[12].y;
        if (pthis->collider.base.atFlags & 2) {
            pthis->collider.base.atFlags &= ~2;
            if (pthis->collider.base.at == &player->actor) {
                func_8002F71C(globalCtx, &pthis->actor, 8.0f, pthis->actor.yawTowardsPlayer, 8.0f);
            }
        }
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        return;
    }
    if ((pthis->actor.xzDistToPlayer > 175.0f) || (player->stateFlags1 & 0x4000000)) {
        EnBa_SetupIdle(pthis);
    } else {
        EnBa_SetupSwingAtPlayer(pthis);
        pthis->unk318 = 27;
        pthis->unk31C = 750;
    }
}

void func_809B7174(EnBa* pthis) {
    pthis->unk14C = 1;
    pthis->unk31C = 1500;
    pthis->unk318 = 20;
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->actor.speedXZ = 10.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_HAND_DAMAGE);
    Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 12);
    EnBa_SetupAction(pthis, EnBa_RecoilFromDamage);
}

void EnBa_RecoilFromDamage(EnBa* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3s sp6C;

    Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 330.0f, 1.0f, 30.0f, 0.0f);
    pthis->unk2FC = pthis->actor.world.pos;
    if (globalCtx->gameplayFrames % 16 == 0) {
        pthis->unk308.z += Rand_CenteredFloat(180.0f);
        pthis->unk314 += Rand_CenteredFloat(180.0f);
        pthis->unk308.x = Math_SinF(pthis->unk308.z) * 80.0f;
        pthis->unk308.y = Math_CosF(pthis->unk314) * 80.0f;
    }
    pthis->unk2FC.y -= 448.0f;
    pthis->unk2FC.x += pthis->unk308.x;
    pthis->unk2FC.z += pthis->unk308.y;
    func_80033AEC(&pthis->unk2FC, &pthis->unk158[13], 1.0f, pthis->actor.speedXZ, 0.0f, 0.0f);
    for (i = 12; i >= 0; i--) {
        func_80035844(&pthis->unk158[i + 1], &pthis->unk158[i], &sp6C, 0);
        Matrix_Translate(pthis->unk158[i + 1].x, pthis->unk158[i + 1].y, pthis->unk158[i + 1].z, MTXMODE_NEW);
        Matrix_RotateZYX(sp6C.x, sp6C.y, 0, MTXMODE_APPLY);
        Matrix_MultVec3f(&D_809B8080, &pthis->unk158[i]);
    }
    func_80035844(&pthis->actor.world.pos, &pthis->unk158[0], &sp6C, 0);
    Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, sp6C.y, 3, pthis->unk31C, 182);
    Math_SmoothStepToS(&pthis->actor.shape.rot.x, sp6C.x + 0x8000, 3, pthis->unk31C, 182);
    Matrix_RotateZYX(pthis->actor.shape.rot.x - 0x8000, pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);
    Matrix_MultVec3f(&D_809B8080, &pthis->unk158[0]);

    for (i = 0; i < 13; i++) {
        func_80035844(&pthis->unk158[i], &pthis->unk158[i + 1], &sp6C, 0);
        Matrix_Translate(pthis->unk158[i].x, pthis->unk158[i].y, pthis->unk158[i].z, MTXMODE_NEW);
        Math_SmoothStepToS(&pthis->unk2A8[i].y, sp6C.y, 3, pthis->unk31C, 182);
        Math_SmoothStepToS(&pthis->unk2A8[i].x, sp6C.x + 0x8000, 3, pthis->unk31C, 182);
        Matrix_RotateZYX(pthis->unk2A8[i].x - 0x8000, pthis->unk2A8[i].y, 0, MTXMODE_APPLY);
        Matrix_MultVec3f(&D_809B8080, &pthis->unk158[i + 1]);
    }

    pthis->unk2A8[13].x = pthis->unk2A8[12].x;
    pthis->unk2A8[13].y = pthis->unk2A8[12].y;
    pthis->unk318--;
    if (pthis->unk318 == 0) {
        EnBa_SetupIdle(pthis);
    }
}

void func_809B75A0(EnBa* pthis, GlobalContext* globalCtx2) {
    s16 unk_temp;
    s32 i;
    Vec3f sp74 = { 0.0f, 0.0f, 0.0f };
    GlobalContext* globalCtx = globalCtx2;

    pthis->unk31C = 2500;
    EffectSsDeadSound_SpawnStationary(globalCtx, &pthis->actor.projectedPos, NA_SE_EN_BALINADE_HAND_DEAD, 1, 1, 40);
    pthis->unk14C = 0;

    for (i = 7; i < 14; i++) {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BA, pthis->unk158[i].x, pthis->unk158[i].y,
                    pthis->unk158[i].z, 0, 0, 0, EN_BA_DEAD_BLOB);
    }
    unk_temp = Math_Vec3f_Pitch(&pthis->actor.world.pos, &pthis->unk158[0]) + 0x8000;
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, pthis->unk31C, 0);
    Math_SmoothStepToS(&pthis->actor.shape.rot.x, unk_temp, 1, pthis->unk31C, 0);
    Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
    Matrix_RotateZYX(pthis->actor.shape.rot.x - 0x8000, pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);
    Matrix_MultVec3f(&D_809B8080, &pthis->unk158[0]);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    for (i = 5; i < 13; i++) {
        Math_SmoothStepToS(&pthis->unk2A8[i].x, pthis->unk2A8[5].x, 1, pthis->unk31C, 0);
        Math_SmoothStepToS(&pthis->unk2A8[i].y, pthis->unk2A8[5].y, 1, pthis->unk31C, 0);
        Matrix_Translate(pthis->unk158[i].x, pthis->unk158[i].y, pthis->unk158[i].z, MTXMODE_NEW);
        Matrix_RotateZYX(pthis->unk2A8[i].x - 0x8000, pthis->unk2A8[i].y, 0, MTXMODE_APPLY);
        Matrix_MultVec3f(&sp74, &pthis->unk158[i + 1]);
    }
    pthis->unk31A = 15;
    EnBa_SetupAction(pthis, EnBa_Die);
}

void EnBa_Die(EnBa* pthis, GlobalContext* globalCtx) {
    Vec3f sp6C = { 0.0f, 0.0f, 0.0f };
    s16 temp;
    s32 i;

    if (pthis->unk31A != 0) {
        pthis->actor.speedXZ = 30.0f;
        pthis->unk31C = 8000;
        pthis->actor.world.pos.y += 8.0f;
        temp = Math_Vec3f_Pitch(&pthis->actor.world.pos, &pthis->unk158[0]) + 0x8000;
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, pthis->unk31C, 0);
        Math_SmoothStepToS(&pthis->actor.shape.rot.x, temp, 1, pthis->unk31C, 0);
        Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
        Matrix_RotateZYX(pthis->actor.shape.rot.x - 0x8000, pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);
        Matrix_MultVec3f(&D_809B8080, &pthis->unk158[0]);
        for (i = 0; i < 5; i++) {
            temp = -Math_CosS(pthis->unk31A * 0x444) * (i * 400);
            Math_SmoothStepToS(&pthis->unk2A8[i].x, temp - 0x4000, 1, pthis->unk31C, 0);
            Math_SmoothStepToS(&pthis->unk2A8[i].y, pthis->actor.yawTowardsPlayer, 1, pthis->unk31C, 0);
            Matrix_Translate(pthis->unk158[i].x, pthis->unk158[i].y, pthis->unk158[i].z, MTXMODE_NEW);
            Matrix_RotateZYX(pthis->unk2A8[i].x - 0x8000, pthis->unk2A8[i].y, 0, MTXMODE_APPLY);
            Matrix_MultVec3f(&D_809B8080, &pthis->unk158[i + 1]);
        }
        for (i = 5; i < 13; i++) {
            Math_SmoothStepToS(&pthis->unk2A8[i].x, pthis->unk2A8[5].x, 1, pthis->unk31C, 0);
            Math_SmoothStepToS(&pthis->unk2A8[i].y, pthis->unk2A8[5].y, 1, pthis->unk31C, 0);
            Matrix_Translate(pthis->unk158[i].x, pthis->unk158[i].y, pthis->unk158[i].z, MTXMODE_NEW);
            Matrix_RotateZYX(pthis->unk2A8[i].x - 0x8000, pthis->unk2A8[i].y, 0, MTXMODE_APPLY);
            Matrix_MultVec3f(&sp6C, &pthis->unk158[i + 1]);
        }
        pthis->unk31A--;
    } else {
        Flags_SetSwitch(globalCtx, pthis->upperParams);
        Actor_Kill(&pthis->actor);
    }
}

void EnBa_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnBa* pthis = (EnBa*)thisx;

    if ((pthis->actor.params < EN_BA_DEAD_BLOB) && (pthis->collider.base.acFlags & 2)) {
        pthis->collider.base.acFlags &= ~2;
        pthis->actor.colChkInfo.health--;
        if (pthis->actor.colChkInfo.health == 0) {
            func_809B75A0(pthis, globalCtx);
        } else {
            func_809B7174(pthis);
        }
    }
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->actor.params < EN_BA_DEAD_BLOB) {
        pthis->actor.focus.pos = pthis->unk158[6];
    }
    if (pthis->unk14C >= 2) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

static void* D_809B8118[] = {
    object_bxa_Tex_0024F0,
    object_bxa_Tex_0027F0,
    object_bxa_Tex_0029F0,
};

void EnBa_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnBa* pthis = (EnBa*)thisx;
    s32 pad;
    s16 i;
    Mtx* mtx = (Mtx*)Graph_Alloc(globalCtx->state.gfxCtx, sizeof(Mtx) * 14);
    Vec3f unused = { 0.0f, 0.0f, 448.0f };

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ba.c", 933);
    func_80093D18(globalCtx->state.gfxCtx);
    if (pthis->actor.params < EN_BA_DEAD_BLOB) {
        Matrix_Push();
        gSPSegment(POLY_OPA_DISP++, 0x0C, mtx);
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(D_809B8118[pthis->actor.params]));
        gSPSegment(POLY_OPA_DISP++, 0x09,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 16, 16, 1, 0,
                                    (globalCtx->gameplayFrames * -10) % 128, 32, 32));
        for (i = 0; i < 14; i++, mtx++) {
            Matrix_Translate(pthis->unk158[i].x, pthis->unk158[i].y, pthis->unk158[i].z, MTXMODE_NEW);
            Matrix_RotateZYX(pthis->unk2A8[i].x, pthis->unk2A8[i].y, pthis->unk2A8[i].z, MTXMODE_APPLY);
            Matrix_Scale(pthis->unk200[i].x, pthis->unk200[i].y, pthis->unk200[i].z, MTXMODE_APPLY);
            if ((i == 6) || (i == 13)) {
                switch (i) {
                    case 13:
                        Collider_UpdateSpheres(i, &pthis->collider);
                        break;
                    default:
                        Matrix_Scale(0.5f, 0.5f, 1.0f, MTXMODE_APPLY);
                        Collider_UpdateSpheres(8, &pthis->collider);
                        break;
                }
            }
            Matrix_ToMtx(mtx, "../z_en_ba.c", 970);
        }
        Matrix_Pop();
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ba.c", 973),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_bxa_DL_000890);
    } else {
        gSPSegment(POLY_OPA_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (globalCtx->gameplayFrames * 2) % 128,
                                    (globalCtx->gameplayFrames * 2) % 128, 32, 32, 1,
                                    (globalCtx->gameplayFrames * -5) % 128, (globalCtx->gameplayFrames * -5) % 128, 32,
                                    32));
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 125, 100, 255);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ba.c", 991),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_bxa_DL_001D80);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ba.c", 995);
}
