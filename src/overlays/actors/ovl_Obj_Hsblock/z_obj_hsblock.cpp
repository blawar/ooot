#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_HSBLOCK_Z_OBJ_HSBLOCK_C
#include "actor_common.h"
/*
 * File: z_obj_hsblock.c
 * Overlay: ovl_Obj_Hsblock
 * Description: Stone Hookshot Target
 */

#include "z_obj_hsblock.h"
#include "objects/object_d_hsblock/object_d_hsblock.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void ObjHsblock_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjHsblock_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjHsblock_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjHsblock_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B93DF4(ObjHsblock* pthis, GlobalContext* globalCtx);
void func_80B93E5C(ObjHsblock* pthis, GlobalContext* globalCtx);

void func_80B93D90(ObjHsblock* pthis);
void func_80B93DB0(ObjHsblock* pthis);
void func_80B93E38(ObjHsblock* pthis);

ActorInit Obj_Hsblock_InitVars = {
    ACTOR_OBJ_HSBLOCK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_D_HSBLOCK,
    sizeof(ObjHsblock),
    (ActorFunc)ObjHsblock_Init,
    (ActorFunc)ObjHsblock_Destroy,
    (ActorFunc)ObjHsblock_Update,
    (ActorFunc)ObjHsblock_Draw,
};

static f32 D_80B940C0[] = { 85.0f, 85.0f, 0.0f };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2000, ICHAIN_STOP),
};

static CollisionHeader* sCollisionHeaders[] = { &gHookshotTargetCol, &gHookshotTargetCol, &gHookshotPostCol };

static Color_RGB8 sFireTempleColor = { 165, 125, 55 };

static Gfx* sDLists[] = { gHookshotPostDL, gHookshotPostDL, gHookshotTargetDL };

void ObjHsblock_SetupAction(ObjHsblock* pthis, ObjHsblockActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void func_80B93B68(ObjHsblock* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 moveFlags) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2[2];

    DynaPolyActor_Init(&pthis->dyna, moveFlags);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_obj_hsblock.c", 163,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void func_80B93BF0(ObjHsblock* pthis, GlobalContext* globalCtx) {
    if ((pthis->dyna.actor.params >> 5) & 1) {
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_OBJ_ICE_POLY,
                           pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z,
                           pthis->dyna.actor.world.rot.x, pthis->dyna.actor.world.rot.y, pthis->dyna.actor.world.rot.z, 1);
    }
}

void ObjHsblock_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjHsblock* pthis = (ObjHsblock*)thisx;

    func_80B93B68(pthis, globalCtx, sCollisionHeaders[thisx->params & 3], DPM_UNK);
    Actor_ProcessInitChain(thisx, sInitChain);
    func_80B93BF0(pthis, globalCtx);

    switch (thisx->params & 3) {
        case 0:
        case 2:
            func_80B93D90(pthis);
            break;
        case 1:
            if (Flags_GetSwitch(globalCtx, (thisx->params >> 8) & 0x3F)) {
                func_80B93D90(pthis);
            } else {
                func_80B93DB0(pthis);
            }
    }

    mREG(13) = 255;
    mREG(14) = 255;
    mREG(15) = 255;
}

void ObjHsblock_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ObjHsblock* pthis = (ObjHsblock*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80B93D90(ObjHsblock* pthis) {
    ObjHsblock_SetupAction(pthis, NULL);
}

void func_80B93DB0(ObjHsblock* pthis) {
    pthis->dyna.actor.flags |= ACTOR_FLAG_4;
    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y - 105.0f;
    ObjHsblock_SetupAction(pthis, func_80B93DF4);
}

void func_80B93DF4(ObjHsblock* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
        func_80B93E38(pthis);
    }
}

void func_80B93E38(ObjHsblock* pthis) {
    ObjHsblock_SetupAction(pthis, func_80B93E5C);
}

void func_80B93E5C(ObjHsblock* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->dyna.actor.velocity.y, 16.0f, 0.1f, 0.8f, 0.0f);
    if (fabsf(Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 0.3f,
                                 pthis->dyna.actor.velocity.y, 0.3f)) < 0.001f) {
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y;
        func_80B93D90(pthis);
        pthis->dyna.actor.flags &= ~ACTOR_FLAG_4;
    }
}

void ObjHsblock_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjHsblock* pthis = (ObjHsblock*)thisx;

    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
    Actor_SetFocus(thisx, D_80B940C0[thisx->params & 3]);
}

void ObjHsblock_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Color_RGB8* color;
    Color_RGB8 defaultColor;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_obj_hsblock.c", 365);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_hsblock.c", 369),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (globalCtx->sceneNum == SCENE_HIDAN) {
        color = &sFireTempleColor;
    } else {
        defaultColor.r = mREG(13);
        defaultColor.g = mREG(14);
        defaultColor.b = mREG(15);
        color = &defaultColor;
    }

    gDPSetEnvColor(POLY_OPA_DISP++, color->r, color->g, color->b, 255);
    gSPDisplayList(POLY_OPA_DISP++, sDLists[thisx->params & 3]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_obj_hsblock.c", 399);
}
