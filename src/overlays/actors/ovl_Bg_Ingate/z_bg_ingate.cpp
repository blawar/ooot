#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_INGATE_Z_BG_INGATE_C
#include "actor_common.h"
/*
 * File: z_bg_ingate.c
 * Overlay: ovl_Bg_Ingate
 * Description: Ingo's Gates (Lon Lon Ranch)
 */

#include "z_bg_ingate.h"
#include "objects/object_ingate/object_ingate.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgInGate_Init(Actor* thisx, GlobalContext* globalCtx);
void BgInGate_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgInGate_Update(Actor* thisx, GlobalContext* globalCtx);
void BgInGate_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80892890(BgInGate* pthis, GlobalContext* globalCtx);
void BgInGate_DoNothing(BgInGate* pthis, GlobalContext* globalCtx);

ActorInit Bg_Ingate_InitVars = {
    ACTOR_BG_INGATE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_INGATE,
    sizeof(BgInGate),
    (ActorFunc)BgInGate_Init,
    (ActorFunc)BgInGate_Destroy,
    (ActorFunc)BgInGate_Update,
    (ActorFunc)BgInGate_Draw,
};

void BgInGate_SetupAction(BgInGate* pthis, BgInGateActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgInGate_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgInGate* pthis = (BgInGate*)thisx;

    s32 pad;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gIngoGateCol, &colHeader);

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if ((globalCtx->sceneNum != SCENE_SPOT20 || !LINK_IS_ADULT) ||
        (((gSaveContext.eventChkInf[1] & 0x100)) && (gSaveContext.cutsceneIndex != 0xFFF0))) {
        Actor_Kill(&pthis->dyna.actor);
        return;
    }

    Actor_SetScale(&pthis->dyna.actor, 0.1f);
    if (((pthis->dyna.actor.params & 1) != 0) && ((gSaveContext.eventInf[0] & 0xF) == 6)) {
        globalCtx->csCtx.frames = 0;
        BgInGate_SetupAction(pthis, func_80892890);
    } else {
        BgInGate_SetupAction(pthis, BgInGate_DoNothing);
    }
}

void BgInGate_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgInGate* pthis = (BgInGate*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80892890(BgInGate* pthis, GlobalContext* globalCtx) {
    s32 phi0;
	s16 phi1;
    s16 csFrames;

    if (globalCtx->csCtx.frames >= 50) {
        phi0 = 0x4000;
        if ((pthis->dyna.actor.params & 2) == 0) {
            phi0 = -0x4000;
        }
        pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.world.rot.y + phi0;
        BgInGate_SetupAction(pthis, BgInGate_DoNothing);
    } else if (globalCtx->csCtx.frames >= 10) {
        csFrames = (globalCtx->csCtx.frames - 10);
        csFrames *= 400;
        phi1 = csFrames;
        if (csFrames > 0x4000) {
            csFrames = 0x4000;
        }
        csFrames = (Math_SinS(csFrames) * 16384.0f);
        phi1 = csFrames;
        if ((pthis->dyna.actor.params & 2) == 0) {
            phi1 = -phi1;
        }
        pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.world.rot.y + phi1;
    }
}

void BgInGate_DoNothing(BgInGate* pthis, GlobalContext* globalCtx) {
}

void BgInGate_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgInGate* pthis = (BgInGate*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgInGate_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_ingate.c", 240);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_ingate.c", 245),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_OPA_DISP++, gIngoGateDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_ingate.c", 250);
}
