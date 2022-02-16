#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_BOMBWALL_Z_BG_BOMBWALL_C
#include "actor_common.h"
/*
 * File: z_bg_bombwall.c
 * Overlay: ovl_Bg_Bombwall
 * Description: Bombable Wall
 */

#include "z_bg_bombwall.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"
#include "def/code_80043480.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_22

void BgBombwall_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgBombwall_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgBombwall_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgBombwall_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgBombwall_Draw(Actor* pthisx, GlobalContext* globalCtx);

void func_8086ED50(BgBombwall* pthis, GlobalContext* globalCtx);
void func_8086ED70(BgBombwall* pthis, GlobalContext* globalCtx);
void func_8086EDFC(BgBombwall* pthis, GlobalContext* globalCtx);
void func_8086EE40(BgBombwall* pthis, GlobalContext* globalCtx);
void func_8086EE94(BgBombwall* pthis, GlobalContext* globalCtx);

static ColliderTrisElementInit sTrisElementsInit[3] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x40000048, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { -70.0f, 176.0f, 0.0f }, { -70.0f, -4.0f, 0.0f }, { 0.0f, -4.0f, 30.0f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x40000048, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 70.0f, 176.0f, 0.0f }, { -70.0f, 176.0f, 0.0f }, { 0.0f, -4.0f, 30.0f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x40000048, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 70.0f, -4.0f, 0.0f }, { 70.0f, 176.0f, 0.0f }, { 0.0f, -4.0f, 30.0f } } },
    },
};

static ColliderTrisInit sTrisInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_TRIS,
    },
    3,
    sTrisElementsInit,
};

ActorInit Bg_Bombwall_InitVars = {
    ACTOR_BG_BOMBWALL,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(BgBombwall),
    (ActorFunc)BgBombwall_Init,
    (ActorFunc)BgBombwall_Destroy,
    (ActorFunc)BgBombwall_Update,
    (ActorFunc)BgBombwall_Draw,
    (ActorFunc)BgBombwall_Reset,
};

void BgBombwall_InitDynapoly(BgBombwall* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 pad2;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gBgBombwallCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        // "Warning : move BG login failed"
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(arg_data 0x%04x)\n", "../z_bg_bombwall.c", 243,
                     pthis->dyna.actor.params);
    }
}

void BgBombwall_RotateVec(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3) {
    arg0->x = (arg1->z * arg2) + (arg1->x * arg3);
    arg0->y = arg1->y;
    arg0->z = (arg1->z * arg3) - (arg1->x * arg2);
}

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 1800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void BgBombwall_Init(Actor* pthisx, GlobalContext* globalCtx) {
    s32 i;
    s32 j;
    Vec3f vecs[3];
    Vec3f sp80;
    s32 pad;
    BgBombwall* pthis = (BgBombwall*)pthisx;
    f32 sin = Math_SinS(pthis->dyna.actor.shape.rot.y);
    f32 cos = Math_CosS(pthis->dyna.actor.shape.rot.y);

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    Actor_SetScale(&pthis->dyna.actor, 0.1f);

    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
        func_8086EE94(pthis, globalCtx);
    } else {
        BgBombwall_InitDynapoly(pthis, globalCtx);
        pthis->unk_2A2 |= 2;
        Collider_InitTris(globalCtx, &pthis->collider);
        Collider_SetTris(globalCtx, &pthis->collider, &pthis->dyna.actor, &sTrisInit, pthis->colliderItems);

        for (i = 0; i <= 2; i++) {
            for (j = 0; j <= 2; j++) {
                sp80.x = sTrisInit.elements[i].dim.vtx[j].x;
                sp80.y = sTrisInit.elements[i].dim.vtx[j].y;
                sp80.z = sTrisInit.elements[i].dim.vtx[j].z + 2.0f;

                BgBombwall_RotateVec(&vecs[j], &sp80, sin, cos);

                vecs[j].x += pthis->dyna.actor.world.pos.x;
                vecs[j].y += pthis->dyna.actor.world.pos.y;
                vecs[j].z += pthis->dyna.actor.world.pos.z;
            }
            Collider_SetTrisVertices(&pthis->collider, i, &vecs[0], &vecs[1], &vecs[2]);
        }

        pthis->unk_2A2 |= 1;
        func_8086ED50(pthis, globalCtx);
    }

    osSyncPrintf("(field keep 汎用爆弾壁)(arg_data 0x%04x)(angY %d)\n", pthis->dyna.actor.params,
                 pthis->dyna.actor.shape.rot.y);
}

void BgBombwall_DestroyCollision(BgBombwall* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_2A2 & 2) {
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        pthis->unk_2A2 &= ~2;
    }

    if (pthis->unk_2A2 & 1) {
        Collider_DestroyTris(globalCtx, &pthis->collider);
        pthis->unk_2A2 &= ~1;
    }
}

void BgBombwall_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgBombwall* pthis = (BgBombwall*)pthisx;

    BgBombwall_DestroyCollision(pthis, globalCtx);
}

static Vec3s D_8086F010[] = {
    { 40, 85, 21 }, { -43, 107, 14 }, { -1, 142, 14 }, { -27, 44, 27 }, { 28, 24, 20 }, { -39, 54, 21 }, { 49, 50, 20 },
};

void func_8086EB5C(BgBombwall* pthis, GlobalContext* globalCtx) {
    s16 rand;
    s16 rand2;
    Vec3f sp88;
    s32 i;
    f32 sin = Math_SinS(pthis->dyna.actor.shape.rot.y);
    f32 cos = Math_CosS(pthis->dyna.actor.shape.rot.y);
    Vec3f* pos = &pthis->dyna.actor.world.pos;
    f32 temp;
    f32 new_var;

    for (i = 0; i < 7; i++) {
        new_var = D_8086F010[i].x;
        temp = new_var * cos;
        sp88.x = ((sin * D_8086F010[i].z) + ((f32)temp)) + pos->x;
        sp88.y = pos->y + D_8086F010[i].y;
        sp88.z = ((D_8086F010[i].z * cos) - (sin * D_8086F010[i].x)) + pos->z;
        rand = ((s16)(Rand_ZeroOne() * 120.0f)) + 0x14;
        rand2 = ((s16)(Rand_ZeroOne() * 240.0f)) + 0x14;
        func_80033480(globalCtx, &sp88, 50.0f, 2, rand, rand2, 1);
    }

    sp88.x = pos->x;
    new_var = pos->y + 90.0f;
    sp88.y = pos->y + 90.0f;
    sp88.z = pos->z + 15.0f;
    func_80033480(globalCtx, &sp88, 40.0f, 4, 0xA, 0x32, 1);
}

void func_8086ED50(BgBombwall* pthis, GlobalContext* globalCtx) {
    pthis->dList = gBgBombwallNormalDL;
    pthis->actionFunc = func_8086ED70;
}

void func_8086ED70(BgBombwall* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        func_8086EDFC(pthis, globalCtx);
        Flags_SetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);
    } else if (pthis->dyna.actor.xzDistToPlayer < 600.0f) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void func_8086EDFC(BgBombwall* pthis, GlobalContext* globalCtx) {
    pthis->dList = gBgBombwallNormalDL;
    pthis->unk_2A0 = 1;
    func_8086EB5C(pthis, globalCtx);
    pthis->actionFunc = func_8086EE40;
}

void func_8086EE40(BgBombwall* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_2A0 > 0) {
        pthis->unk_2A0--;
    } else {
        func_8086EE94(pthis, globalCtx);

        if (((pthis->dyna.actor.params >> 0xF) & 1) != 0) {
            func_80078884(NA_SE_SY_CORRECT_CHIME);
        }
    }
}

void func_8086EE94(BgBombwall* pthis, GlobalContext* globalCtx) {
    pthis->dList = gBgBombwallBrokenDL;
    BgBombwall_DestroyCollision(pthis, globalCtx);
    pthis->actionFunc = NULL;
}

void BgBombwall_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgBombwall* pthis = (BgBombwall*)pthisx;

    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
}

void BgBombwall_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    BgBombwall* pthis = (BgBombwall*)pthisx;

    Gfx_DrawDListOpa(globalCtx, pthis->dList);
}

void BgBombwall_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sTrisInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_TRIS,
        },
        3,
        sTrisElementsInit,
    };

    Bg_Bombwall_InitVars = {
        ACTOR_BG_BOMBWALL,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_GAMEPLAY_FIELD_KEEP,
        sizeof(BgBombwall),
        (ActorFunc)BgBombwall_Init,
        (ActorFunc)BgBombwall_Destroy,
        (ActorFunc)BgBombwall_Update,
        (ActorFunc)BgBombwall_Draw,
        (ActorFunc)BgBombwall_Reset,
    };

}
