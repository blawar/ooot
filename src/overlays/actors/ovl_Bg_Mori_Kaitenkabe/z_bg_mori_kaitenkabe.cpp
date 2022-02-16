#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MORI_KAITENKABE_Z_BG_MORI_KAITENKABE_C
#include "actor_common.h"
/*
 * File: z_bg_mori_kaitenkabe.c
 * Overlay: ovl_Bg_Mori_Kaitenkabe
 * Description: Rotating wall in Forest Temple basement
 */

#include "z_bg_mori_kaitenkabe.h"
#include "objects/object_mori_objects/object_mori_objects.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS 0

void BgMoriKaitenkabe_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMoriKaitenkabe_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgMoriKaitenkabe_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMoriKaitenkabe_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMoriKaitenkabe_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgMoriKaitenkabe_WaitForMoriTex(BgMoriKaitenkabe* pthis, GlobalContext* globalCtx);
void BgMoriKaitenkabe_SetupWait(BgMoriKaitenkabe* pthis);
void BgMoriKaitenkabe_Wait(BgMoriKaitenkabe* pthis, GlobalContext* globalCtx);
void BgMoriKaitenkabe_SetupRotate(BgMoriKaitenkabe* pthis);
void BgMoriKaitenkabe_Rotate(BgMoriKaitenkabe* pthis, GlobalContext* globalCtx);

ActorInit Bg_Mori_Kaitenkabe_InitVars = {
    ACTOR_BG_MORI_KAITENKABE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriKaitenkabe),
    (ActorFunc)BgMoriKaitenkabe_Init,
    (ActorFunc)BgMoriKaitenkabe_Destroy,
    (ActorFunc)BgMoriKaitenkabe_Update,
    NULL,
    (ActorFunc)BgMoriKaitenkabe_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

void BgMoriKaitenkabe_CrossProduct(Vec3f* dest, Vec3f* v1, Vec3f* v2) {
    dest->x = (v1->y * v2->z) - (v1->z * v2->y);
    dest->y = (v1->z * v2->x) - (v1->x * v2->z);
    dest->z = (v1->x * v2->y) - (v1->y * v2->x);
}

void BgMoriKaitenkabe_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriKaitenkabe* pthis = (BgMoriKaitenkabe*)thisx;
    CollisionHeader* colHeader = NULL;

    // "Forest Temple object 【Rotating Wall (arg_data: 0x% 04x)】 appears"
    osSyncPrintf("◯◯◯森の神殿オブジェクト【回転壁(arg_data : 0x%04x)】出現 \n", pthis->dyna.actor.params);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gMoriKaitenkabeCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->moriTexObjIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_TEX);
    if (pthis->moriTexObjIndex < 0) {
        Actor_Kill(&pthis->dyna.actor);
        // "【Rotating wall】 Bank danger!"
        osSyncPrintf("【回転壁】 バンク危険！(%s %d)\n", "../z_bg_mori_kaitenkabe.c", 176);
    } else {
        pthis->actionFunc = BgMoriKaitenkabe_WaitForMoriTex;
    }
}

void BgMoriKaitenkabe_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriKaitenkabe* pthis = (BgMoriKaitenkabe*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgMoriKaitenkabe_WaitForMoriTex(BgMoriKaitenkabe* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->moriTexObjIndex)) {
        BgMoriKaitenkabe_SetupWait(pthis);
        pthis->dyna.actor.draw = BgMoriKaitenkabe_Draw;
    }
}

void BgMoriKaitenkabe_SetupWait(BgMoriKaitenkabe* pthis) {
    pthis->actionFunc = BgMoriKaitenkabe_Wait;
    pthis->timer = 0;
}

void BgMoriKaitenkabe_Wait(BgMoriKaitenkabe* pthis, GlobalContext* globalCtx) {
    Vec3f push;
    Vec3f leverArm;
    Vec3f torque;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->dyna.unk_150 > 0.001f) {
        pthis->timer++;
        if ((pthis->timer > 28) && !Player_InCsMode(globalCtx)) {
            BgMoriKaitenkabe_SetupRotate(pthis);
            func_8002DF54(globalCtx, &pthis->dyna.actor, 8);
            Math_Vec3f_Copy(&pthis->lockedPlayerPos, &player->actor.world.pos);
            push.x = Math_SinS(pthis->dyna.unk_158);
            push.y = 0.0f;
            push.z = Math_CosS(pthis->dyna.unk_158);
            leverArm.x = pthis->dyna.actor.world.pos.x - player->actor.world.pos.x;
            leverArm.y = 0.0f;
            leverArm.z = pthis->dyna.actor.world.pos.z - player->actor.world.pos.z;
            BgMoriKaitenkabe_CrossProduct(&torque, &push, &leverArm);
            pthis->rotDirection = (torque.y > 0.0f) ? 1.0f : -1.0f;
        }
    } else {
        pthis->timer = 0;
    }
    if (fabsf(pthis->dyna.unk_150) > 0.001f) {
        pthis->dyna.unk_150 = 0.0f;
        player->stateFlags2 &= ~0x10;
    }
}

void BgMoriKaitenkabe_SetupRotate(BgMoriKaitenkabe* pthis) {
    pthis->actionFunc = BgMoriKaitenkabe_Rotate;
    pthis->rotSpeed = 0.0f;
    pthis->rotYdeg = 0.0f;
}

void BgMoriKaitenkabe_Rotate(BgMoriKaitenkabe* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Actor* thisx = &pthis->dyna.actor;
    s16 rotY;

    Math_StepToF(&pthis->rotSpeed, 0.6f, 0.02f);
    if (Math_StepToF(&pthis->rotYdeg, pthis->rotDirection * 45.0f, pthis->rotSpeed)) {
        BgMoriKaitenkabe_SetupWait(pthis);
        func_8002DF54(globalCtx, thisx, 7);
        if (pthis->rotDirection > 0.0f) {
            thisx->home.rot.y += 0x2000;
        } else {
            thisx->home.rot.y -= 0x2000;
        }
        thisx->world.rot.y = thisx->shape.rot.y = thisx->home.rot.y;
        func_800788CC(NA_SE_EV_STONEDOOR_STOP);
    } else {
        rotY = pthis->rotYdeg * (0x10000 / 360.0f);
        thisx->world.rot.y = thisx->shape.rot.y = thisx->home.rot.y + rotY;
        func_800788CC(NA_SE_EV_WALL_SLIDE - SFX_FLAG);
    }
    if (fabsf(pthis->dyna.unk_150) > 0.001f) {
        pthis->dyna.unk_150 = 0.0f;
        player->stateFlags2 &= ~0x10;
    }
    Math_Vec3f_Copy(&player->actor.world.pos, &pthis->lockedPlayerPos);
}

void BgMoriKaitenkabe_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriKaitenkabe* pthis = (BgMoriKaitenkabe*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgMoriKaitenkabe_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriKaitenkabe* pthis = (BgMoriKaitenkabe*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_kaitenkabe.c", 347);
    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, gObjectTable[pthis->moriTexObjIndex].vromStart.get());

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_kaitenkabe.c", 352),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_OPA_DISP++, gMoriKaitenkabeDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_kaitenkabe.c", 356);
}

void BgMoriKaitenkabe_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Mori_Kaitenkabe_InitVars = {
        ACTOR_BG_MORI_KAITENKABE,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_MORI_OBJECTS,
        sizeof(BgMoriKaitenkabe),
        (ActorFunc)BgMoriKaitenkabe_Init,
        (ActorFunc)BgMoriKaitenkabe_Destroy,
        (ActorFunc)BgMoriKaitenkabe_Update,
        NULL,
        (ActorFunc)BgMoriKaitenkabe_Reset,
    };

}
