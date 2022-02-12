#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_KIBAKO_Z_OBJ_KIBAKO_C
#include "actor_common.h"
/*
 * File: z_obj_kibako.c
 * Overlay: ovl_Obj_Kibako
 * Description: Small wooden box
 */

#include "z_obj_kibako.h"
#include "objects/gameplay_dangeon_keep/gameplay_dangeon_keep.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_26)

void ObjKibako_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjKibako_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjKibako_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjKibako_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjKibako_SetupIdle(ObjKibako* pthis);
void ObjKibako_Idle(ObjKibako* pthis, GlobalContext* globalCtx);
void ObjKibako_SetupHeld(ObjKibako* pthis);
void ObjKibako_Held(ObjKibako* pthis, GlobalContext* globalCtx);
void ObjKibako_SetupThrown(ObjKibako* pthis);
void ObjKibako_Thrown(ObjKibako* pthis, GlobalContext* globalCtx);

ActorInit Obj_Kibako_InitVars = {
    ACTOR_OBJ_KIBAKO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(ObjKibako),
    (ActorFunc)ObjKibako_Init,
    (ActorFunc)ObjKibako_Destroy,
    (ActorFunc)ObjKibako_Update,
    (ActorFunc)ObjKibako_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_PLAYER,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000002, 0x00, 0x01 },
        { 0x4FC00748, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 12, 27, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sCCInfoInit = { 0, 12, 60, MASS_HEAVY };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 60, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void ObjKibako_SpawnCollectible(ObjKibako* pthis, GlobalContext* globalCtx) {
    s16 collectible;

    collectible = pthis->actor.params & 0x1F;
    if ((collectible >= 0) && (collectible <= 0x19)) {
        Item_DropCollectible(globalCtx, &pthis->actor.world.pos,
                             collectible | (((pthis->actor.params >> 8) & 0x3F) << 8));
    }
}

void ObjKibako_ApplyGravity(ObjKibako* pthis) {
    pthis->actor.velocity.y += pthis->actor.gravity;
    if (pthis->actor.velocity.y < pthis->actor.minVelocityY) {
        pthis->actor.velocity.y = pthis->actor.minVelocityY;
    }
}

void ObjKibako_InitCollider(Actor* thisx, GlobalContext* globalCtx) {
    ObjKibako* pthis = (ObjKibako*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
}

void ObjKibako_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjKibako* pthis = (ObjKibako*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.gravity = -1.2f;
    pthis->actor.minVelocityY = -13.0f;
    ObjKibako_InitCollider(&pthis->actor, globalCtx);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sCCInfoInit);
    ObjKibako_SetupIdle(pthis);
    // "wooden box"
    osSyncPrintf("(dungeon keep 木箱)(arg_data 0x%04x)\n", pthis->actor.params);
}

void ObjKibako_Destroy(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    ObjKibako* pthis = (ObjKibako*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void ObjKibako_AirBreak(ObjKibako* pthis, GlobalContext* globalCtx) {
    s16 angle;
    s32 i;
    Vec3f* breakPos = &pthis->actor.world.pos;
    Vec3f pos;
    Vec3f velocity;

    for (i = 0, angle = 0; i < 12; i++, angle += 0x4E20) {
        f32 sn = Math_SinS(angle);
        f32 cs = Math_CosS(angle);
        f32 temp_rand;
        s16 phi_s0;

        pos.x = sn * 16.0f;
        pos.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        pos.z = cs * 16.0f;
        velocity.x = pos.x * 0.2f;
        velocity.y = (Rand_ZeroOne() * 6.0f) + 2.0f;
        velocity.z = pos.z * 0.2f;
        pos.x += breakPos->x;
        pos.y += breakPos->y;
        pos.z += breakPos->z;
        temp_rand = Rand_ZeroOne();
        if (temp_rand < 0.1f) {
            phi_s0 = 0x60;
        } else if (temp_rand < 0.7f) {
            phi_s0 = 0x40;
        } else {
            phi_s0 = 0x20;
        }
        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, breakPos, -200, phi_s0, 10, 10, 0,
                             (Rand_ZeroOne() * 30.0f) + 10.0f, 0, 32, 60, KAKERA_COLOR_NONE,
                             OBJECT_GAMEPLAY_DANGEON_KEEP, gSmallWoodenBoxFragmentDL);
    }
    func_80033480(globalCtx, &pthis->actor.world.pos, 40.0f, 3, 50, 140, 1);
}

void ObjKibako_WaterBreak(ObjKibako* pthis, GlobalContext* globalCtx) {
    s16 angle;
    s32 i;
    Vec3f* breakPos = &pthis->actor.world.pos;
    Vec3f pos;
    Vec3f velocity;

    pos = *breakPos;
    pos.y += pthis->actor.yDistToWater;
    EffectSsGSplash_Spawn(globalCtx, &pos, NULL, NULL, 0, 500);

    for (i = 0, angle = 0; i < 12; i++, angle += 0x4E20) {
        f32 sn = Math_SinS(angle);
        f32 cs = Math_CosS(angle);
        f32 temp_rand;
        s16 phi_s0;

        pos.x = sn * 16.0f;
        pos.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        pos.z = cs * 16.0f;
        velocity.x = pos.x * 0.18f;
        velocity.y = (Rand_ZeroOne() * 4.0f) + 2.0f;
        velocity.z = pos.z * 0.18f;
        pos.x += breakPos->x;
        pos.y += breakPos->y;
        pos.z += breakPos->z;
        temp_rand = Rand_ZeroOne();
        phi_s0 = (temp_rand < 0.2f) ? 0x40 : 0x20;
        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, breakPos, -180, phi_s0, 30, 30, 0,
                             (Rand_ZeroOne() * 30.0f) + 10.0f, 0, 32, 70, KAKERA_COLOR_NONE,
                             OBJECT_GAMEPLAY_DANGEON_KEEP, gSmallWoodenBoxFragmentDL);
    }
}

void ObjKibako_SetupIdle(ObjKibako* pthis) {
    pthis->actionFunc = ObjKibako_Idle;
    pthis->actor.colChkInfo.mass = MASS_HEAVY;
}

void ObjKibako_Idle(ObjKibako* pthis, GlobalContext* globalCtx) {
    s32 pad;

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        ObjKibako_SetupHeld(pthis);
    } else if ((pthis->actor.bgCheckFlags & 0x20) && (pthis->actor.yDistToWater > 19.0f)) {
        ObjKibako_WaterBreak(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
        ObjKibako_SpawnCollectible(pthis, globalCtx);
        Actor_Kill(&pthis->actor);
    } else if (pthis->collider.base.acFlags & AC_HIT) {
        ObjKibako_AirBreak(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
        ObjKibako_SpawnCollectible(pthis, globalCtx);
        Actor_Kill(&pthis->actor);
    } else {
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 19.0f, 20.0f, 0.0f, 5);
        if (!(pthis->collider.base.ocFlags1 & OC1_TYPE_PLAYER) && (pthis->actor.xzDistToPlayer > 28.0f)) {
            pthis->collider.base.ocFlags1 |= OC1_TYPE_PLAYER;
        }
        if (pthis->actor.xzDistToPlayer < 600.0f) {
            Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            if (pthis->actor.xzDistToPlayer < 180.0f) {
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }
        }
        if (pthis->actor.xzDistToPlayer < 100.0f) {
            func_8002F580(&pthis->actor, globalCtx);
        }
    }
}

void ObjKibako_SetupHeld(ObjKibako* pthis) {
    pthis->actionFunc = ObjKibako_Held;
    pthis->actor.room = -1;
    func_8002F7DC(&pthis->actor, NA_SE_PL_PULL_UP_WOODBOX);
}

void ObjKibako_Held(ObjKibako* pthis, GlobalContext* globalCtx) {
    if (Actor_HasNoParent(&pthis->actor, globalCtx)) {
        pthis->actor.room = globalCtx->roomCtx.curRoom.num;
        if (fabsf(pthis->actor.speedXZ) < 0.1f) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_PUT_DOWN_WOODBOX);
            ObjKibako_SetupIdle(pthis);
            pthis->collider.base.ocFlags1 &= ~OC1_TYPE_PLAYER;
        } else {
            ObjKibako_SetupThrown(pthis);
            ObjKibako_ApplyGravity(pthis);
            func_8002D7EC(&pthis->actor);
        }
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 19.0f, 20.0f, 0.0f, 5);
    }
}

void ObjKibako_SetupThrown(ObjKibako* pthis) {
    pthis->actor.velocity.x = Math_SinS(pthis->actor.world.rot.y) * pthis->actor.speedXZ;
    pthis->actor.velocity.z = Math_CosS(pthis->actor.world.rot.y) * pthis->actor.speedXZ;
    pthis->actor.colChkInfo.mass = 240;
    pthis->actionFunc = ObjKibako_Thrown;
}

void ObjKibako_Thrown(ObjKibako* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 pad2;

    if ((pthis->actor.bgCheckFlags & 0xB) || (pthis->collider.base.atFlags & AT_HIT)) {
        ObjKibako_AirBreak(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
        ObjKibako_SpawnCollectible(pthis, globalCtx);
        Actor_Kill(&pthis->actor);
    } else if (pthis->actor.bgCheckFlags & 0x40) {
        ObjKibako_WaterBreak(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
        ObjKibako_SpawnCollectible(pthis, globalCtx);
        Actor_Kill(&pthis->actor);
    } else {
        ObjKibako_ApplyGravity(pthis);
        func_8002D7EC(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 19.0f, 20.0f, 0.0f, 5);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void ObjKibako_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjKibako* pthis = (ObjKibako*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void ObjKibako_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjKibako* pthis = (ObjKibako*)thisx;

    Gfx_DrawDListOpa(globalCtx, gSmallWoodenBoxDL);
}
