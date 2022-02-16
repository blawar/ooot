#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_TSUBO_Z_OBJ_TSUBO_C
#include "actor_common.h"
/*
 * File: z_obj_tsubo.c
 * Overlay: ovl_Obj_Tsubo
 * Description: Breakable pot
 */

#include "z_obj_tsubo.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "objects/gameplay_dangeon_keep/gameplay_dangeon_keep.h"
#include "objects/object_tsubo/object_tsubo.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_scene.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_23)

void ObjTsubo_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjTsubo_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ObjTsubo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjTsubo_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjTsubo_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjTsubo_SpawnCollectible(ObjTsubo* pthis, GlobalContext* globalCtx);
void ObjTsubo_ApplyGravity(ObjTsubo* pthis);
s32 ObjTsubo_SnapToFloor(ObjTsubo* pthis, GlobalContext* globalCtx);
void ObjTsubo_InitCollider(Actor* thisx, GlobalContext* globalCtx);
void ObjTsubo_AirBreak(ObjTsubo* pthis, GlobalContext* globalCtx);
void ObjTsubo_WaterBreak(ObjTsubo* pthis, GlobalContext* globalCtx);
void ObjTsubo_SetupWaitForObject(ObjTsubo* pthis);
void ObjTsubo_WaitForObject(ObjTsubo* pthis, GlobalContext* globalCtx);
void ObjTsubo_SetupIdle(ObjTsubo* pthis);
void ObjTsubo_Idle(ObjTsubo* pthis, GlobalContext* globalCtx);
void ObjTsubo_SetupLiftedUp(ObjTsubo* pthis);
void ObjTsubo_LiftedUp(ObjTsubo* pthis, GlobalContext* globalCtx);
void ObjTsubo_SetupThrown(ObjTsubo* pthis);
void ObjTsubo_Thrown(ObjTsubo* pthis, GlobalContext* globalCtx);

static s16 D_80BA1B50 = 0;
static s16 D_80BA1B54 = 0;
static s16 D_80BA1B58 = 0;
static s16 D_80BA1B5C = 0;

ActorInit Obj_Tsubo_InitVars = {
    ACTOR_OBJ_TSUBO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjTsubo),
    (ActorFunc)ObjTsubo_Init,
    (ActorFunc)ObjTsubo_Destroy,
    (ActorFunc)ObjTsubo_Update,
    NULL,
    (ActorFunc)ObjTsubo_Reset,
};

static s16 sObjectIds[] = { OBJECT_GAMEPLAY_DANGEON_KEEP, OBJECT_TSUBO };

static Gfx* D_80BA1B84[] = { gPotDL, object_tsubo_DL_0017C0 };

static Gfx* D_80BA1B8C[] = { gPotFragmentDL, object_tsubo_DL_001960 };

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HARD,
        AT_ON | AT_TYPE_PLAYER,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000002, 0x00, 0x01 },
        { 0x4FC1FFFE, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 9, 26, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit[] = { 0, 12, 60, MASS_IMMOVABLE };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32_DIV1000(gravity, -1200, ICHAIN_CONTINUE), ICHAIN_F32_DIV1000(minVelocityY, -20000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 150, ICHAIN_CONTINUE),   ICHAIN_F32(uncullZoneForward, 900, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 100, ICHAIN_CONTINUE),   ICHAIN_F32(uncullZoneDownward, 800, ICHAIN_STOP),
};

void ObjTsubo_SpawnCollectible(ObjTsubo* pthis, GlobalContext* globalCtx) {
    s16 dropParams = pthis->actor.params & 0x1F;

    if ((dropParams >= ITEM00_RUPEE_GREEN) && (dropParams <= ITEM00_BOMBS_SPECIAL)) {
        Item_DropCollectible(globalCtx, &pthis->actor.world.pos,
                             (dropParams | (((pthis->actor.params >> 9) & 0x3F) << 8)));
    }
}

void ObjTsubo_ApplyGravity(ObjTsubo* pthis) {
    pthis->actor.velocity.y += pthis->actor.gravity;
    if (pthis->actor.velocity.y < pthis->actor.minVelocityY) {
        pthis->actor.velocity.y = pthis->actor.minVelocityY;
    }
}

s32 ObjTsubo_SnapToFloor(ObjTsubo* pthis, GlobalContext* globalCtx) {
    CollisionPoly* floorPoly;
    Vec3f pos;
    s32 bgID;
    f32 floorY;

    pos.x = pthis->actor.world.pos.x;
    pos.y = pthis->actor.world.pos.y + 20.0f;
    pos.z = pthis->actor.world.pos.z;
    floorY = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &floorPoly, &bgID, &pthis->actor, &pos);
    if (floorY > BGCHECK_Y_MIN) {
        pthis->actor.world.pos.y = floorY;
        Math_Vec3f_Copy(&pthis->actor.home.pos, &pthis->actor.world.pos);
        return true;
    } else {
        osSyncPrintf("地面に付着失敗\n");
        return false;
    }
}

void ObjTsubo_InitCollider(Actor* thisx, GlobalContext* globalCtx) {
    ObjTsubo* pthis = (ObjTsubo*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
}

void ObjTsubo_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjTsubo* pthis = (ObjTsubo*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ObjTsubo_InitCollider(&pthis->actor, globalCtx);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, sColChkInfoInit);
    if (!ObjTsubo_SnapToFloor(pthis, globalCtx)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    pthis->objTsuboBankIndex = Object_GetIndex(&globalCtx->objectCtx, sObjectIds[(pthis->actor.params >> 8) & 1]);
    if (pthis->objTsuboBankIndex < 0) {
        osSyncPrintf("Error : バンク危険！ (arg_data 0x%04x)(%s %d)\n", pthis->actor.params, "../z_obj_tsubo.c", 410);
        Actor_Kill(&pthis->actor);
    } else {
        ObjTsubo_SetupWaitForObject(pthis);
        osSyncPrintf("(dungeon keep 壷)(arg_data 0x%04x)\n", pthis->actor.params);
    }
}

void ObjTsubo_Destroy(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    ObjTsubo* pthis = (ObjTsubo*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void ObjTsubo_AirBreak(ObjTsubo* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 rand;
    s16 angle;
    Vec3f pos;
    Vec3f velocity;
    f32 sins;
    f32 coss;
    s32 arg5;
    s32 i;

    for (i = 0, angle = 0; i < 15; i++, angle += 0x4E20) {
        sins = Math_SinS(angle);
        coss = Math_CosS(angle);
        pos.x = sins * 8.0f;
        pos.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        pos.z = coss * 8.0f;
        velocity.x = pos.x * 0.23f;
        velocity.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        velocity.z = pos.z * 0.23f;
        Math_Vec3f_Sum(&pos, &pthis->actor.world.pos, &pos);
        rand = Rand_ZeroOne();
        if (rand < 0.2f) {
            arg5 = 96;
        } else if (rand < 0.6f) {
            arg5 = 64;
        } else {
            arg5 = 32;
        }
        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pthis->actor.world.pos, -240, arg5, 10, 10, 0,
                             (Rand_ZeroOne() * 95.0f) + 15.0f, 0, 32, 60, KAKERA_COLOR_NONE,
                             sObjectIds[(pthis->actor.params >> 8) & 1], D_80BA1B8C[(pthis->actor.params >> 8) & 1]);
    }
    func_80033480(globalCtx, &pthis->actor.world.pos, 30.0f, 4, 20, 50, 1);
}

void ObjTsubo_WaterBreak(ObjTsubo* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 angle;
    Vec3f pos = pthis->actor.world.pos;
    Vec3f velocity;
    s32 phi_s0;
    s32 i;

    pos.y += pthis->actor.yDistToWater;
    EffectSsGSplash_Spawn(globalCtx, &pos, NULL, NULL, 0, 400);
    for (i = 0, angle = 0; i < 15; i++, angle += 0x4E20) {
        f32 sins = Math_SinS(angle);
        f32 coss = Math_CosS(angle);

        pos.x = sins * 8.0f;
        pos.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        pos.z = coss * 8.0f;
        velocity.x = pos.x * 0.2f;
        velocity.y = (Rand_ZeroOne() * 4.0f) + 2.0f;
        velocity.z = pos.z * 0.2f;
        Math_Vec3f_Sum(&pos, &pthis->actor.world.pos, &pos);
        phi_s0 = (Rand_ZeroOne() < .2f) ? 64 : 32;
        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pthis->actor.world.pos, -180, phi_s0, 30, 30, 0,
                             (Rand_ZeroOne() * 95.0f) + 15.0f, 0, 32, 70, KAKERA_COLOR_NONE,
                             sObjectIds[(pthis->actor.params >> 8) & 1], D_80BA1B8C[(pthis->actor.params >> 8) & 1]);
    }
}

void ObjTsubo_SetupWaitForObject(ObjTsubo* pthis) {
    pthis->actionFunc = ObjTsubo_WaitForObject;
}

void ObjTsubo_WaitForObject(ObjTsubo* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objTsuboBankIndex)) {
        pthis->actor.draw = ObjTsubo_Draw;
        pthis->actor.objBankIndex = pthis->objTsuboBankIndex;
        ObjTsubo_SetupIdle(pthis);
        pthis->actor.flags &= ~ACTOR_FLAG_4;
    }
}

void ObjTsubo_SetupIdle(ObjTsubo* pthis) {
    pthis->actionFunc = ObjTsubo_Idle;
}

void ObjTsubo_Idle(ObjTsubo* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 temp_v0;
    s32 phi_v1;

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        ObjTsubo_SetupLiftedUp(pthis);
    } else if ((pthis->actor.bgCheckFlags & 0x20) && (pthis->actor.yDistToWater > 15.0f)) {
        ObjTsubo_WaterBreak(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_POT_BROKEN);
        ObjTsubo_SpawnCollectible(pthis, globalCtx);
        Actor_Kill(&pthis->actor);
    } else if ((pthis->collider.base.acFlags & AC_HIT) &&
               (pthis->collider.info.acHitInfo->toucher.dmgFlags & 0x4FC1FFFC)) {
        ObjTsubo_AirBreak(pthis, globalCtx);
        ObjTsubo_SpawnCollectible(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_POT_BROKEN);
        Actor_Kill(&pthis->actor);
    } else {
        if (pthis->actor.xzDistToPlayer < 600.0f) {
            Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
            pthis->collider.base.acFlags &= ~AC_HIT;
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            if (pthis->actor.xzDistToPlayer < 150.0f) {
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }
        }
        if (pthis->actor.xzDistToPlayer < 100.0f) {
            temp_v0 = pthis->actor.yawTowardsPlayer - GET_PLAYER(globalCtx)->actor.world.rot.y;
            phi_v1 = ABS(temp_v0);
            if (phi_v1 >= 0x5556) {
                // GI_NONE in pthis case allows the player to lift the actor
                func_8002F434(&pthis->actor, globalCtx, GI_NONE, 30.0f, 30.0f);
            }
        }
    }
}

void ObjTsubo_SetupLiftedUp(ObjTsubo* pthis) {
    pthis->actionFunc = ObjTsubo_LiftedUp;
    pthis->actor.room = -1;
    func_8002F7DC(&pthis->actor, NA_SE_PL_PULL_UP_POT);
    pthis->actor.flags |= ACTOR_FLAG_4;
}

void ObjTsubo_LiftedUp(ObjTsubo* pthis, GlobalContext* globalCtx) {
    if (Actor_HasNoParent(&pthis->actor, globalCtx)) {
        pthis->actor.room = globalCtx->roomCtx.curRoom.num;
        ObjTsubo_SetupThrown(pthis);
        ObjTsubo_ApplyGravity(pthis);
        func_8002D7EC(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 15.0f, 0.0f, 0x85);
    }
}

void ObjTsubo_SetupThrown(ObjTsubo* pthis) {
    pthis->actor.velocity.x = Math_SinS(pthis->actor.world.rot.y) * pthis->actor.speedXZ;
    pthis->actor.velocity.z = Math_CosS(pthis->actor.world.rot.y) * pthis->actor.speedXZ;
    pthis->actor.colChkInfo.mass = 240;
    D_80BA1B50 = (Rand_ZeroOne() - 0.7f) * 2800.0f;
    D_80BA1B58 = (Rand_ZeroOne() - 0.5f) * 2000.0f;
    D_80BA1B54 = 0;
    D_80BA1B5C = 0;
    pthis->actionFunc = ObjTsubo_Thrown;
}

void ObjTsubo_Thrown(ObjTsubo* pthis, GlobalContext* globalCtx) {
    s32 pad[2];

    if ((pthis->actor.bgCheckFlags & 0xB) || (pthis->collider.base.atFlags & AT_HIT)) {
        ObjTsubo_AirBreak(pthis, globalCtx);
        ObjTsubo_SpawnCollectible(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_POT_BROKEN);
        Actor_Kill(&pthis->actor);
    } else if (pthis->actor.bgCheckFlags & 0x40) {
        ObjTsubo_WaterBreak(pthis, globalCtx);
        ObjTsubo_SpawnCollectible(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_POT_BROKEN);
        Actor_Kill(&pthis->actor);
    } else {
        ObjTsubo_ApplyGravity(pthis);
        func_8002D7EC(&pthis->actor);
        Math_StepToS(&D_80BA1B54, D_80BA1B50, 0x64);
        Math_StepToS(&D_80BA1B5C, D_80BA1B58, 0x64);
        pthis->actor.shape.rot.x += D_80BA1B54;
        pthis->actor.shape.rot.y += D_80BA1B5C;
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 15.0f, 0.0f, 0x85);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void ObjTsubo_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjTsubo* pthis = (ObjTsubo*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void ObjTsubo_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, D_80BA1B84[(thisx->params >> 8) & 1]);
}

void ObjTsubo_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    D_80BA1B50 = 0;

    D_80BA1B54 = 0;

    D_80BA1B58 = 0;

    D_80BA1B5C = 0;

    Obj_Tsubo_InitVars = {
        ACTOR_OBJ_TSUBO,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(ObjTsubo),
        (ActorFunc)ObjTsubo_Init,
        (ActorFunc)ObjTsubo_Destroy,
        (ActorFunc)ObjTsubo_Update,
        NULL,
        (ActorFunc)ObjTsubo_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_HARD,
            AT_ON | AT_TYPE_PLAYER,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000002, 0x00, 0x01 },
            { 0x4FC1FFFE, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 9, 26, 0, { 0, 0, 0 } },
    };

}
