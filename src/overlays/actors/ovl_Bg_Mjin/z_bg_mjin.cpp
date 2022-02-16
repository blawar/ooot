#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MJIN_Z_BG_MJIN_C
#include "actor_common.h"
/*
 * File: z_bg_mjin.c
 * Overlay: ovl_Bg_Mjin
 * Description: Warp Pad
 */

#include "z_bg_mjin.h"
#include "objects/object_mjin/object_mjin.h"
#include "objects/object_mjin_wind/object_mjin_wind.h"
#include "objects/object_mjin_soul/object_mjin_soul.h"
#include "objects/object_mjin_dark/object_mjin_dark.h"
#include "objects/object_mjin_ice/object_mjin_ice.h"
#include "objects/object_mjin_flame/object_mjin_flame.h"
#include "objects/object_mjin_flash/object_mjin_flash.h"
#include "objects/object_mjin_oka/object_mjin_oka.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS ACTOR_FLAG_4

void BgMjin_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMjin_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgMjin_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMjin_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMjin_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808A0850(BgMjin* pthis, GlobalContext* globalCtx);
void BgMjin_DoNothing(BgMjin* pthis, GlobalContext* globalCtx);

ActorInit Bg_Mjin_InitVars = {
    ACTOR_BG_MJIN,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgMjin),
    (ActorFunc)BgMjin_Init,
    (ActorFunc)BgMjin_Destroy,
    (ActorFunc)BgMjin_Update,
    NULL,
    (ActorFunc)BgMjin_Reset,
};

extern UNK_TYPE D_06000000;

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 400, ICHAIN_STOP),
};

static s16 sObjectIDs[] = { OBJECT_MJIN_FLASH, OBJECT_MJIN_DARK, OBJECT_MJIN_FLAME,
                            OBJECT_MJIN_ICE,   OBJECT_MJIN_SOUL, OBJECT_MJIN_WIND };

void BgMjin_SetupAction(BgMjin* pthis, BgMjinActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgMjin_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgMjin* pthis = (BgMjin*)thisx;
    s32 objBankIndex;

    Actor_ProcessInitChain(thisx, sInitChain);
    objBankIndex = Object_GetIndex(&globalCtx->objectCtx, (thisx->params != 0 ? OBJECT_MJIN : OBJECT_MJIN_OKA));
    pthis->objBankIndex = objBankIndex;
    if (objBankIndex < 0) {
        Actor_Kill(thisx);
    } else {
        BgMjin_SetupAction(pthis, func_808A0850);
    }
}

void BgMjin_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgMjin* pthis = (BgMjin*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808A0850(BgMjin* pthis, GlobalContext* globalCtx) {
    CollisionHeader* colHeader;
    CollisionHeader* collision;

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex)) {
        colHeader = NULL;
        pthis->dyna.actor.flags &= ~ACTOR_FLAG_4;
        pthis->dyna.actor.objBankIndex = pthis->objBankIndex;
        Actor_SetObjectDependency(globalCtx, &pthis->dyna.actor);
        DynaPolyActor_Init(&pthis->dyna, 0);
        collision = pthis->dyna.actor.params != 0 ? &gWarpPadCol : &gOcarinaWarpPadCol;
        CollisionHeader_GetVirtual(collision, &colHeader);
        pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
        BgMjin_SetupAction(pthis, BgMjin_DoNothing);
        pthis->dyna.actor.draw = BgMjin_Draw;
    }
}

void BgMjin_DoNothing(BgMjin* pthis, GlobalContext* globalCtx) {
}

void BgMjin_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgMjin* pthis = (BgMjin*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgMjin_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgMjin* pthis = (BgMjin*)thisx;
    Gfx* dlist;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mjin.c", 250);

    if (thisx->params != 0) {
        s32 objBankIndex = Object_GetIndex(&globalCtx->objectCtx, sObjectIDs[thisx->params - 1]);

        if (objBankIndex >= 0) {
            gSegments[6] = gObjectTable[objBankIndex].vromStart.get();
        }

        gSPSegment(POLY_OPA_DISP++, 0x08, gObjectTable[objBankIndex].vromStart.get());
        dlist = gWarpPadBaseDL;
    } else {
        dlist = gOcarinaWarpPadDL;
    }

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mjin.c", 285),
              G_MTX_NOPUSH | G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, dlist);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mjin.c", 288);
}

void BgMjin_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Mjin_InitVars = {
        ACTOR_BG_MJIN,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(BgMjin),
        (ActorFunc)BgMjin_Init,
        (ActorFunc)BgMjin_Destroy,
        (ActorFunc)BgMjin_Update,
        NULL,
        (ActorFunc)BgMjin_Reset,
    };

}
