#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_KIBAKO2_Z_OBJ_KIBAKO2_C
#include "actor_common.h"
/*
 * File: z_obj_kibako2.c
 * Overlay: ovl_Obj_Kibako2
 * Description: Large crate
 */

#include "z_obj_kibako2.h"
#include "objects/object_kibako2/object_kibako2.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"

#define FLAGS 0

void ObjKibako2_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjKibako2_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ObjKibako2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjKibako2_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjKibako2_Draw(Actor* thisx, GlobalContext* globalCtx);
void ObjKibako2_Idle(ObjKibako2* pthis, GlobalContext* globalCtx);
void ObjKibako2_Kill(ObjKibako2* pthis, GlobalContext* globalCtx);

ActorInit Obj_Kibako2_InitVars = {
    ACTOR_OBJ_KIBAKO2,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_KIBAKO2,
    sizeof(ObjKibako2),
    (ActorFunc)ObjKibako2_Init,
    (ActorFunc)ObjKibako2_Destroy,
    (ActorFunc)ObjKibako2_Update,
    (ActorFunc)ObjKibako2_Draw,
    (ActorFunc)ObjKibako2_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x40000040, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 31, 48, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 3000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void ObjKibako2_InitCollider(Actor* thisx, GlobalContext* globalCtx) {
    ObjKibako2* pthis = (ObjKibako2*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->dyna.actor, &sCylinderInit);
    Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->collider);
}

void ObjKibako2_Break(ObjKibako2* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    Vec3f* thisPos;
    Vec3f pos;
    Vec3f velocity;
    s16 angle;
    s32 i;

    thisPos = &pthis->dyna.actor.world.pos;
    for (i = 0, angle = 0; i < 0x10; i++, angle += 0x4E20) {
        f32 sn = Math_SinS(angle);
        f32 cs = Math_CosS(angle);
        f32 temp_rand;
        s32 phi_s0;

        temp_rand = Rand_ZeroOne() * 30.0f;
        pos.x = sn * temp_rand;
        pos.y = (Rand_ZeroOne() * 10.0f) + 2.0f;
        pos.z = cs * temp_rand;
        velocity.x = pos.x * 0.2f;
        velocity.y = (Rand_ZeroOne() * 10.0f) + 2.0f;
        velocity.z = pos.z * 0.2f;
        pos.x += thisPos->x;
        pos.y += thisPos->y;
        pos.z += thisPos->z;
        temp_rand = Rand_ZeroOne();
        if (temp_rand < 0.05f) {
            phi_s0 = 0x60;
        } else if (temp_rand < 0.7f) {
            phi_s0 = 0x40;
        } else {
            phi_s0 = 0x20;
        }
        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pos, -200, phi_s0, 28, 2, 0, (Rand_ZeroOne() * 30.0f) + 5.0f,
                             0, 0, 70, KAKERA_COLOR_NONE, OBJECT_KIBAKO2, gLargeCrateFragmentDL);
    }
    func_80033480(globalCtx, thisPos, 90.0f, 6, 100, 160, 1);
}

void ObjKibako2_SpawnCollectible(ObjKibako2* pthis, GlobalContext* globalCtx) {
    s16 itemDropped;
    s16 collectibleFlagTemp;

    collectibleFlagTemp = pthis->collectibleFlag;
    itemDropped = pthis->dyna.actor.home.rot.x;
    if (itemDropped >= 0 && itemDropped < 0x1A) {
        Item_DropCollectible(globalCtx, &pthis->dyna.actor.world.pos, itemDropped | (collectibleFlagTemp << 8));
    }
}

void ObjKibako2_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjKibako2* pthis = (ObjKibako2*)thisx;
    s16 pad;
    CollisionHeader* colHeader = NULL;
    u32 bgId;

    DynaPolyActor_Init(&pthis->dyna, 0);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    ObjKibako2_InitCollider(thisx, globalCtx);
    CollisionHeader_GetVirtual(&gLargeCrateCol, &colHeader);
    bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->collectibleFlag = pthis->dyna.actor.home.rot.z & 0x3F;
    pthis->dyna.bgId = bgId;
    pthis->actionFunc = ObjKibako2_Idle;
    pthis->dyna.actor.home.rot.z = pthis->dyna.actor.world.rot.z = pthis->dyna.actor.shape.rot.z =
        pthis->dyna.actor.world.rot.x = pthis->dyna.actor.shape.rot.x = 0;
    // "Wooden box (stationary)"
    osSyncPrintf("木箱(据置)(arg %04xH)(item %04xH %d)\n", pthis->dyna.actor.params, pthis->collectibleFlag,
                 pthis->dyna.actor.home.rot.x);
}

void ObjKibako2_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ObjKibako2* pthis = (ObjKibako2*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void ObjKibako2_Idle(ObjKibako2* pthis, GlobalContext* globalCtx) {
    if ((pthis->collider.base.acFlags & AC_HIT) || (pthis->dyna.actor.home.rot.z != 0) ||
        func_80033684(globalCtx, &pthis->dyna.actor) != NULL) {
        ObjKibako2_Break(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
        pthis->dyna.actor.flags |= ACTOR_FLAG_4;
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        pthis->dyna.actor.draw = NULL;
        pthis->actionFunc = ObjKibako2_Kill;
    } else if (pthis->dyna.actor.xzDistToPlayer < 600.0f) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void ObjKibako2_Kill(ObjKibako2* pthis, GlobalContext* globalCtx) {
    s16 params = pthis->dyna.actor.params;

    if ((params & 0x8000) == 0) {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_SW, pthis->dyna.actor.world.pos.x,
                    pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z, 0, pthis->dyna.actor.shape.rot.y, 0,
                    params | 0x8000);
    }
    ObjKibako2_SpawnCollectible(pthis, globalCtx);
    Actor_Kill(&pthis->dyna.actor);
}

void ObjKibako2_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjKibako2* pthis = (ObjKibako2*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void ObjKibako2_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gLargeCrateDL);
}

void ObjKibako2_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Obj_Kibako2_InitVars = {
        ACTOR_OBJ_KIBAKO2,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_KIBAKO2,
        sizeof(ObjKibako2),
        (ActorFunc)ObjKibako2_Init,
        (ActorFunc)ObjKibako2_Destroy,
        (ActorFunc)ObjKibako2_Update,
        (ActorFunc)ObjKibako2_Draw,
        (ActorFunc)ObjKibako2_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x40000040, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 31, 48, 0, { 0, 0, 0 } },
    };

}
