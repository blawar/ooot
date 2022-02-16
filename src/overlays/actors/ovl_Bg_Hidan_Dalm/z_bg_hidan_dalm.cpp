#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_DALM_Z_BG_HIDAN_DALM_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_dalm.c
 * Overlay: ovl_Bg_Hidan_Dalm
 * Description: Hammerable Totem Pieces (Fire Temple)
 */

#include "z_bg_hidan_dalm.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "def/code_80043480.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"

#define FLAGS 0

void BgHidanDalm_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanDalm_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgHidanDalm_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanDalm_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanDalm_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgHidanDalm_Wait(BgHidanDalm* pthis, GlobalContext* globalCtx);
void BgHidanDalm_Shrink(BgHidanDalm* pthis, GlobalContext* globalCtx);

static Vec3f accel_31 = { 0, 0, 0 };


ActorInit Bg_Hidan_Dalm_InitVars = {
    ACTOR_BG_HIDAN_DALM,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanDalm),
    (ActorFunc)BgHidanDalm_Init,
    (ActorFunc)BgHidanDalm_Destroy,
    (ActorFunc)BgHidanDalm_Update,
    (ActorFunc)BgHidanDalm_Draw,
    (ActorFunc)BgHidanDalm_Reset,
};

static ColliderTrisElementInit sTrisElementInit[4] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000040, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_NO_AT_INFO | BUMP_NO_DAMAGE | BUMP_NO_SWORD_SFX | BUMP_NO_HITMARK,
            OCELEM_NONE,
        },
        { { { 305.0f, 0.0f, -300.0f }, { 305.0f, 600.0f, -300.0f }, { 305.0f, 600.0f, 300.0f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000040, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_NO_AT_INFO | BUMP_NO_DAMAGE | BUMP_NO_SWORD_SFX | BUMP_NO_HITMARK,
            OCELEM_NONE,
        },
        { { { 305.0f, 0.0f, -300.0f }, { 305.0f, 600.0f, 300.0f }, { 305.0f, 0.0f, 300.0f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000040, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_NO_AT_INFO | BUMP_NO_DAMAGE | BUMP_NO_SWORD_SFX | BUMP_NO_HITMARK,
            OCELEM_NONE,
        },
        { { { -305.0f, 0.0f, -300.0f }, { -305.0f, 600.0f, 300.0f }, { -305.0f, 600.0f, -300.0f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000040, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_NO_AT_INFO | BUMP_NO_DAMAGE | BUMP_NO_SWORD_SFX | BUMP_NO_HITMARK,
            OCELEM_NONE,
        },
        { { { -305.0f, 0.0f, -300.0f }, { -305.0f, 0.0f, 300.0f }, { -305.0f, 600.0f, 300.0f } } },
    },
};

static ColliderTrisInit sTrisInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_TRIS,
    },
    4,
    sTrisElementInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -200, ICHAIN_STOP),
};

void BgHidanDalm_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanDalm* pthis = (BgHidanDalm*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(thisx, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gFireTempleHammerableTotemCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    Collider_InitTris(globalCtx, &pthis->collider);
    Collider_SetTris(globalCtx, &pthis->collider, thisx, &sTrisInit, pthis->colliderItems);

    pthis->switchFlag = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;
    if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        Actor_Kill(thisx);
    } else {
        pthis->actionFunc = BgHidanDalm_Wait;
    }
}

void BgHidanDalm_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanDalm* pthis = (BgHidanDalm*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyTris(globalCtx, &pthis->collider);
}

void BgHidanDalm_Wait(BgHidanDalm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((pthis->collider.base.acFlags & AC_HIT) && !Player_InCsMode(globalCtx) &&
        (player->swordAnimation == 22 || player->swordAnimation == 23)) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        if ((pthis->collider.elements[0].info.bumperFlags & BUMP_HIT) ||
            (pthis->collider.elements[1].info.bumperFlags & BUMP_HIT)) {
            pthis->dyna.actor.world.rot.y -= 0x4000;
        } else {
            pthis->dyna.actor.world.rot.y += 0x4000;
        }
        pthis->dyna.actor.world.pos.x += 32.5f * Math_SinS(pthis->dyna.actor.world.rot.y);
        pthis->dyna.actor.world.pos.z += 32.5f * Math_CosS(pthis->dyna.actor.world.rot.y);

        func_8002DF54(globalCtx, &pthis->dyna.actor, 8);
        pthis->dyna.actor.flags |= ACTOR_FLAG_4;
        pthis->actionFunc = BgHidanDalm_Shrink;
        pthis->dyna.actor.bgCheckFlags &= ~2;
        pthis->dyna.actor.bgCheckFlags &= ~8;
        pthis->dyna.actor.speedXZ = 10.0f;
        Flags_SetSwitch(globalCtx, pthis->switchFlag);
        func_8002F7DC(&GET_PLAYER(globalCtx)->actor, NA_SE_IT_HAMMER_HIT);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_DARUMA_VANISH);
    } else {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void BgHidanDalm_Shrink(BgHidanDalm* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f velocity;
    Vec3f pos;

    if (Math_StepToF(&pthis->dyna.actor.scale.x, 0.0f, 0.004f)) {
        func_8002DF54(globalCtx, &pthis->dyna.actor, 7);
        Actor_Kill(&pthis->dyna.actor);
    }

    pthis->dyna.actor.scale.y = pthis->dyna.actor.scale.z = pthis->dyna.actor.scale.x;

    pos.x = pthis->dyna.actor.world.pos.x;
    pos.y = pthis->dyna.actor.world.pos.y + pthis->dyna.actor.scale.x * 160.0f;
    pos.z = pthis->dyna.actor.world.pos.z;

    for (i = 0; i < 4; i++) {
        velocity.x = 5.0f * Math_SinS(pthis->dyna.actor.world.rot.y + 0x8000) + (Rand_ZeroOne() - 0.5f) * 5.0f;
        velocity.z = 5.0f * Math_CosS(pthis->dyna.actor.world.rot.y + 0x8000) + (Rand_ZeroOne() - 0.5f) * 5.0f;
        velocity.y = (Rand_ZeroOne() - 0.5f) * 1.5f;
        EffectSsKiraKira_SpawnSmallYellow(globalCtx, &pos, &velocity, &accel_31);
    }
}

void BgHidanDalm_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanDalm* pthis = (BgHidanDalm*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->dyna.actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 10.0f, 15.0f, 32.0f, 5);
}

/**
 * Update vertices of collider tris based on the current matrix
 */
void BgHidanDalm_UpdateCollider(BgHidanDalm* pthis) {
    Vec3f pos2;
    Vec3f pos1;
    Vec3f pos0;

    Matrix_MultVec3f(&sTrisElementInit[0].dim.vtx[0], &pos0);
    Matrix_MultVec3f(&sTrisElementInit[0].dim.vtx[1], &pos1);
    Matrix_MultVec3f(&sTrisElementInit[0].dim.vtx[2], &pos2);
    Collider_SetTrisVertices(&pthis->collider, 0, &pos0, &pos1, &pos2);
    Matrix_MultVec3f(&sTrisElementInit[1].dim.vtx[2], &pos1);
    Collider_SetTrisVertices(&pthis->collider, 1, &pos0, &pos2, &pos1);

    Matrix_MultVec3f(&sTrisElementInit[2].dim.vtx[0], &pos0);
    Matrix_MultVec3f(&sTrisElementInit[2].dim.vtx[1], &pos1);
    Matrix_MultVec3f(&sTrisElementInit[2].dim.vtx[2], &pos2);
    Collider_SetTrisVertices(&pthis->collider, 2, &pos0, &pos1, &pos2);
    Matrix_MultVec3f(&sTrisElementInit[3].dim.vtx[1], &pos2);
    Collider_SetTrisVertices(&pthis->collider, 3, &pos0, &pos2, &pos1);
}

void BgHidanDalm_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanDalm* pthis = (BgHidanDalm*)thisx;

    if (pthis->dyna.actor.params == 0) {
        Gfx_DrawDListOpa(globalCtx, gFireTempleHammerableTotemBodyDL);
    } else {
        Gfx_DrawDListOpa(globalCtx, gFireTempleHammerableTotemHeadDL);
    }

    if (pthis->actionFunc == BgHidanDalm_Wait) {
        BgHidanDalm_UpdateCollider(pthis);
    }
}

void BgHidanDalm_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    accel_31 = { 0, 0, 0 };

    Bg_Hidan_Dalm_InitVars = {
        ACTOR_BG_HIDAN_DALM,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_HIDAN_OBJECTS,
        sizeof(BgHidanDalm),
        (ActorFunc)BgHidanDalm_Init,
        (ActorFunc)BgHidanDalm_Destroy,
        (ActorFunc)BgHidanDalm_Update,
        (ActorFunc)BgHidanDalm_Draw,
        (ActorFunc)BgHidanDalm_Reset,
    };

    sTrisInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_TRIS,
        },
        4,
        sTrisElementInit,
    };

}
