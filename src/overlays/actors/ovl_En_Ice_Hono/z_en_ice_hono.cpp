#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ICE_HONO_Z_EN_ICE_HONO_C
#include "actor_common.h"
/*
 * File: z_en_ice_hono.c
 * Overlay: ovl_En_Ice_Hono
 * Description: The various types of Blue Fire
 */

#include "z_en_ice_hono.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_rcp.h"

#define FLAGS 0

void EnIceHono_Init(Actor* thisx, GlobalContext* globalCtx);
void EnIceHono_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnIceHono_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnIceHono_Update(Actor* thisx, GlobalContext* globalCtx);
void EnIceHono_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnIceHono_CapturableFlame(EnIceHono* pthis, GlobalContext* globalCtx);
void EnIceHono_DropFlame(EnIceHono* pthis, GlobalContext* globalCtx);
void EnIceHono_SpreadFlames(EnIceHono* pthis, GlobalContext* globalCtx);
void EnIceHono_SmallFlameMove(EnIceHono* pthis, GlobalContext* globalCtx);

void EnIceHono_SetupActionCapturableFlame(EnIceHono* pthis);
void EnIceHono_SetupActionDroppedFlame(EnIceHono* pthis);
void EnIceHono_SetupActionSpreadFlames(EnIceHono* pthis);
void EnIceHono_SetupActionSmallFlame(EnIceHono* pthis);

ActorInit En_Ice_Hono_InitVars = {
    ACTOR_EN_ICE_HONO,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnIceHono),
    (ActorFunc)EnIceHono_Init,
    (ActorFunc)EnIceHono_Destroy,
    (ActorFunc)EnIceHono_Update,
    (ActorFunc)EnIceHono_Draw,
    (ActorFunc)EnIceHono_Reset,
};

static ColliderCylinderInit sCylinderInitCapturableFlame = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
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
    { 25, 80, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sCylinderInitDroppedFlame = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_OTHER,
        AC_NONE,
        OC1_ON | OC1_TYPE_2,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 12, 60, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChainCapturableFlame[] = {
    ICHAIN_U8(targetMode, 0, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 60, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

static InitChainEntry sInitChainDroppedFlame[] = {
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

static InitChainEntry sInitChainSmallFlame[] = {
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

f32 EnIceHono_XZDistanceSquared(Vec3f* v1, Vec3f* v2) {
    return SQ(v1->x - v2->x) + SQ(v1->z - v2->z);
}

void EnIceHono_InitCapturableFlame(Actor* thisx, GlobalContext* globalCtx) {
    EnIceHono* pthis = (EnIceHono*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChainCapturableFlame);
    Actor_SetScale(&pthis->actor, 0.0074f);
    pthis->actor.flags |= ACTOR_FLAG_0;
    Actor_SetFocus(&pthis->actor, 10.0f);

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInitCapturableFlame);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    EnIceHono_SetupActionCapturableFlame(pthis);
}

void EnIceHono_InitDroppedFlame(Actor* thisx, GlobalContext* globalCtx) {
    EnIceHono* pthis = (EnIceHono*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChainDroppedFlame);
    pthis->actor.scale.x = pthis->actor.scale.z = pthis->actor.scale.y = 0.00002f;
    pthis->actor.gravity = -0.3f;
    pthis->actor.minVelocityY = -4.0f;
    pthis->actor.shape.yOffset = 0.0f;
    pthis->actor.shape.rot.x = pthis->actor.shape.rot.y = pthis->actor.shape.rot.z = pthis->actor.world.rot.x =
        pthis->actor.world.rot.y = pthis->actor.world.rot.z = 0;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInitDroppedFlame);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

    pthis->collider.dim.radius = pthis->actor.scale.x * 4000.4f;
    pthis->collider.dim.height = pthis->actor.scale.y * 8000.2f;
    pthis->actor.colChkInfo.mass = 253;
    EnIceHono_SetupActionDroppedFlame(pthis);
}

void EnIceHono_InitSmallFlame(Actor* thisx, GlobalContext* globalCtx) {
    EnIceHono* pthis = (EnIceHono*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChainSmallFlame);
    pthis->actor.scale.x = pthis->actor.scale.z = pthis->actor.scale.y = 0.0008f;
    pthis->actor.gravity = -0.3f;
    pthis->actor.minVelocityY = -4.0f;
    pthis->actor.shape.yOffset = 0.0f;

    EnIceHono_SetupActionSmallFlame(pthis);
}

void EnIceHono_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnIceHono* pthis = (EnIceHono*)thisx;
    s16 params = pthis->actor.params;

    switch (pthis->actor.params) {
        case -1:
            EnIceHono_InitCapturableFlame(&pthis->actor, globalCtx);
            break;
        case 0:
            EnIceHono_InitDroppedFlame(&pthis->actor, globalCtx);
            break;
        case 1:
        case 2:
            EnIceHono_InitSmallFlame(&pthis->actor, globalCtx);
            break;
    }

    if ((pthis->actor.params == -1) || (pthis->actor.params == 0)) {
        Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, (s16)pthis->actor.world.pos.y + 10,
                                  pthis->actor.world.pos.z, 155, 210, 255, 0);
        pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
        pthis->unk_154 = Rand_ZeroOne() * (0x1FFFF / 2.0f);
        pthis->unk_156 = Rand_ZeroOne() * (0x1FFFF / 2.0f);
        osSyncPrintf("(ice 炎)(arg_data 0x%04x)\n", pthis->actor.params); // "(ice flame)"
    }
}

void EnIceHono_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnIceHono* pthis = (EnIceHono*)thisx;

    if ((pthis->actor.params == -1) || (pthis->actor.params == 0)) {
        LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
}

u32 EnIceHono_InBottleRange(EnIceHono* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->actor.xzDistToPlayer < 60.0f) {
        Vec3f tempPos;
        tempPos.x = Math_SinS(pthis->actor.yawTowardsPlayer + 0x8000) * 40.0f + player->actor.world.pos.x;
        tempPos.y = player->actor.world.pos.y;
        tempPos.z = Math_CosS(pthis->actor.yawTowardsPlayer + 0x8000) * 40.0f + player->actor.world.pos.z;

        //! @bug: pthis check is superfluous: it is automatically satisfied if the coarse check is satisfied. It may have
        //! been intended to check the actor is in front of Player, but yawTowardsPlayer does not depend on Player's
        //! world rotation.
        if (EnIceHono_XZDistanceSquared(&tempPos, &pthis->actor.world.pos) <= SQ(40.0f)) {
            return true;
        }
    }
    return false;
}

void EnIceHono_SetupActionCapturableFlame(EnIceHono* pthis) {
    pthis->actionFunc = EnIceHono_CapturableFlame;
    pthis->alpha = 255;
    pthis->actor.shape.yOffset = -1000.0f;
}

void EnIceHono_CapturableFlame(EnIceHono* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
    } else if (EnIceHono_InBottleRange(pthis, globalCtx)) {
        // GI_MAX in pthis case allows the player to catch the actor in a bottle
        func_8002F434(&pthis->actor, globalCtx, GI_MAX, 60.0f, 100.0f);
    }

    if (pthis->actor.xzDistToPlayer < 200.0f) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
    func_8002F8F0(&pthis->actor, NA_SE_EV_FIRE_PILLAR_S - SFX_FLAG);
}

void EnIceHono_SetupActionDroppedFlame(EnIceHono* pthis) {
    pthis->actionFunc = EnIceHono_DropFlame;
    pthis->timer = 200;
    pthis->alpha = 255;
}

void EnIceHono_DropFlame(EnIceHono* pthis, GlobalContext* globalCtx) {
    u32 bgFlag = pthis->actor.bgCheckFlags & 1;

    Math_StepToF(&pthis->actor.scale.x, 0.0017f, 0.00008f);
    pthis->actor.scale.z = pthis->actor.scale.x;
    Math_StepToF(&pthis->actor.scale.y, 0.0017f, 0.00008f);

    if (bgFlag != 0) {
        s32 i;
        for (i = 0; i < 8; i++) {
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ICE_HONO, pthis->actor.world.pos.x,
                        pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0,
                        ((s32)(Rand_ZeroOne() * 1000.0f) + i * 0x2000) - 0x1F4, 0, 1);
        }
        EnIceHono_SetupActionSpreadFlames(pthis);
    }
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, pthis->actor.scale.x * 3500.0f, 0.0f, 5);

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    pthis->collider.dim.radius = pthis->actor.scale.x * 4000.0f;
    pthis->collider.dim.height = pthis->actor.scale.y * 8000.0f;
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

    if (pthis->timer <= 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnIceHono_SetupActionSpreadFlames(EnIceHono* pthis) {
    pthis->actionFunc = EnIceHono_SpreadFlames;
    pthis->timer = 60;
    pthis->alpha = 255;
}

void EnIceHono_SpreadFlames(EnIceHono* pthis, GlobalContext* globalCtx) {
    if (pthis->timer > 20) {
        Math_StepToF(&pthis->actor.scale.x, 0.011f, 0.00014f);
        Math_StepToF(&pthis->actor.scale.y, 0.006f, 0.00012f);
    } else {
        Math_StepToF(&pthis->actor.scale.x, 0.0001f, 0.00015f);
        Math_StepToF(&pthis->actor.scale.y, 0.0001f, 0.00015f);
    }
    pthis->actor.scale.z = pthis->actor.scale.x;
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, pthis->actor.scale.x * 3500.0f, 0.0f, 4);
    if (pthis->timer < 25) {
        pthis->alpha -= 10;
        pthis->alpha = CLAMP(pthis->alpha, 0, 255);
    }

    if ((pthis->alpha > 100) && (pthis->timer < 40)) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        pthis->collider.dim.radius = pthis->actor.scale.x * 6000.0f;
        pthis->collider.dim.height = pthis->actor.scale.y * 8000.0f;
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
    if (pthis->timer == 46) {
        s32 i;
        for (i = 0; i < 10; i++) {
            s32 rot = i * 0x1999;
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ICE_HONO, pthis->actor.world.pos.x,
                        pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0,
                        ((s32)(Rand_ZeroOne() * 1000.0f) + rot) - 0x1F4, 0, 2);
        }
    }

    if (pthis->timer <= 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnIceHono_SetupActionSmallFlame(EnIceHono* pthis) {
    pthis->actionFunc = EnIceHono_SmallFlameMove;
    pthis->timer = 44;
    pthis->alpha = 255;
    if (pthis->actor.params == 1) {
        pthis->smallFlameTargetYScale = (Rand_ZeroOne() * 0.005f) + 0.004f;
        pthis->actor.speedXZ = (Rand_ZeroOne() * 1.6f) + 0.5f;
    } else {
        pthis->smallFlameTargetYScale = (Rand_ZeroOne() * 0.005f) + 0.003f;
        pthis->actor.speedXZ = (Rand_ZeroOne() * 2.0f) + 0.5f;
    }
}

void EnIceHono_SmallFlameMove(EnIceHono* pthis, GlobalContext* globalCtx) {
    if (pthis->timer > 20) {
        Math_StepToF(&pthis->actor.scale.x, 0.006f, 0.00016f);
        Math_StepToF(&pthis->actor.scale.y, pthis->smallFlameTargetYScale * 0.667f, 0.00014f);
    } else {
        Math_StepToF(&pthis->actor.scale.x, 0.0001f, 0.00015f);
        Math_StepToF(&pthis->actor.scale.y, 0.0001f, 0.00015f);
    }
    pthis->actor.scale.z = pthis->actor.scale.x;
    Math_StepToF(&pthis->actor.speedXZ, 0, 0.06f);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 0.0f, 5);

    if (pthis->timer < 25) {
        pthis->alpha -= 10;
        pthis->alpha = CLAMP(pthis->alpha, 0, 255);
    }
    if (pthis->timer <= 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnIceHono_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnIceHono* pthis = (EnIceHono*)thisx;
    s32 pad1;
    f32 intensity;
    s32 pad2;
    f32 sin154;
    f32 sin156;

    if (pthis->timer > 0) {
        pthis->timer--;
    }
    if (pthis->actor.params == 0) {
        func_8002F8F0(&pthis->actor, NA_SE_IT_FLAME - SFX_FLAG);
    }
    if ((pthis->actor.params == -1) || (pthis->actor.params == 0)) {
        pthis->unk_154 += 0x1111;
        pthis->unk_156 += 0x4000;
        sin156 = Math_SinS(pthis->unk_156);
        sin154 = Math_SinS(pthis->unk_154);
        intensity = (Rand_ZeroOne() * 0.05f) + ((sin154 * 0.125f) + (sin156 * 0.1f)) + 0.425f;
        if ((intensity > 0.7f) || (intensity < 0.2f)) {
            osSyncPrintf("ありえない値(ratio = %f)\n", intensity); // "impossible value(ratio = %f)"
        }
        Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, (s16)pthis->actor.world.pos.y + 10,
                                  pthis->actor.world.pos.z, (s32)(155.0f * intensity), (s32)(210.0f * intensity),
                                  (s32)(255.0f * intensity), 1400);
    }

    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
}

void EnIceHono_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnIceHono* pthis = (EnIceHono*)thisx;
    u32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ice_hono.c", 695);
    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0, (globalCtx->state.frames * -20) % 512,
                                32, 128));

    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 170, 255, 255, pthis->alpha);

    gDPSetEnvColor(POLY_XLU_DISP++, 0, 150, 255, 0);

    Matrix_RotateY((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) - pthis->actor.shape.rot.y + 0x8000) *
                       (M_PI / 0x8000),
                   MTXMODE_APPLY);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ice_hono.c", 718),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ice_hono.c", 722);
}

void EnIceHono_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Ice_Hono_InitVars = {
        ACTOR_EN_ICE_HONO,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnIceHono),
        (ActorFunc)EnIceHono_Init,
        (ActorFunc)EnIceHono_Destroy,
        (ActorFunc)EnIceHono_Update,
        (ActorFunc)EnIceHono_Draw,
        (ActorFunc)EnIceHono_Reset,
    };

    sCylinderInitCapturableFlame = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
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
        { 25, 80, 0, { 0, 0, 0 } },
    };

    sCylinderInitDroppedFlame = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_OTHER,
            AC_NONE,
            OC1_ON | OC1_TYPE_2,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 12, 60, 0, { 0, 0, 0 } },
    };

}
