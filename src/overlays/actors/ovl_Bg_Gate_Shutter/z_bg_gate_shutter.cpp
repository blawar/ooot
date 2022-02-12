#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_GATE_SHUTTER_Z_BG_GATE_SHUTTER_C
#include "actor_common.h"
/*
 * File: z_bg_gate_shutter.c
 * Overlay: Bg_Gate_Shutter
 * Description: Death Mountain Trail Gate
 */

#include "z_bg_gate_shutter.h"
#include "objects/object_spot01_matoyab/object_spot01_matoyab.h"
#include "vt.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgGateShutter_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgGateShutter_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgGateShutter_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgGateShutter_Draw(Actor* pthisx, GlobalContext* globalCtx);

void func_8087828C(BgGateShutter* pthis, GlobalContext* globalCtx);
void func_80878300(BgGateShutter* pthis, GlobalContext* globalCtx);
void func_808783AC(BgGateShutter* pthis, GlobalContext* globalCtx);
void func_808783D4(BgGateShutter* pthis, GlobalContext* globalCtx);

ActorInit Bg_Gate_Shutter_InitVars = {
    ACTOR_BG_GATE_SHUTTER,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_SPOT01_MATOYAB,
    sizeof(BgGateShutter),
    (ActorFunc)BgGateShutter_Init,
    (ActorFunc)BgGateShutter_Destroy,
    (ActorFunc)BgGateShutter_Update,
    (ActorFunc)BgGateShutter_Draw,
};

void BgGateShutter_Init(Actor* pthisx, GlobalContext* globalCtx) {
    BgGateShutter* pthis = (BgGateShutter*)pthisx;
    s32 pad[2];
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gKakarikoGuardGateCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, pthisx, colHeader);
    pthis->somePos.x = pthisx->world.pos.x;
    pthis->somePos.y = pthisx->world.pos.y;
    pthis->somePos.z = pthisx->world.pos.z;
    if (((gSaveContext.infTable[7] & 0x40) || (gSaveContext.eventChkInf[4] & 0x20)) &&
        (globalCtx->sceneNum == SCENE_SPOT01)) {
        pthisx->world.pos.x = -89.0f;
        pthisx->world.pos.z = -1375.0f;
    }
    pthisx->scale.x = 1.0f;
    pthisx->scale.y = 1.0f;
    pthisx->scale.z = 1.0f;
    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 柵でたなぁ ☆☆☆☆☆ \n" VT_RST);
    pthis->actionFunc = func_8087828C;
}

void BgGateShutter_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgGateShutter* pthis = (BgGateShutter*)pthisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_8087828C(BgGateShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->openingState == 1 && !(gSaveContext.infTable[7] & 0x40)) {
        pthis->unk_178 = 2;
        pthis->actionFunc = func_80878300;
    } else if (pthis->openingState == 2) {
        pthis->unk_178 = 2;
        pthis->actionFunc = func_80878300;
    } else if (pthis->openingState < 0) {
        pthis->unk_178 = 2;
        pthis->actionFunc = func_808783D4;
    }
}

void func_80878300(BgGateShutter* pthis, GlobalContext* globalCtx) {
    Actor* pthisx = &pthis->dyna.actor;

    if (pthis->unk_178 == 0) {
        Audio_PlayActorSound2(pthisx, NA_SE_EV_METALGATE_OPEN - SFX_FLAG);
        pthisx->world.pos.x -= 2.0f;
        Math_ApproachF(&pthisx->world.pos.z, -1375.0f, 0.8f, 0.3f);
        if (pthisx->world.pos.x < -89.0f) {
            Audio_PlayActorSound2(pthisx, NA_SE_EV_BRIDGE_OPEN_STOP);
            pthis->unk_178 = 0x1E;
            pthis->actionFunc = func_808783AC;
        }
    }
}

void func_808783AC(BgGateShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_178 == 0) {
        pthis->openingState = 0;
        pthis->actionFunc = func_8087828C;
    }
}

void func_808783D4(BgGateShutter* pthis, GlobalContext* globalCtx) {
    Actor* pthisx = &pthis->dyna.actor;

    if (pthis->unk_178 == 0) {
        Audio_PlayActorSound2(pthisx, NA_SE_EV_METALGATE_OPEN - SFX_FLAG);
        pthisx->world.pos.x += 2.0f;
        Math_ApproachF(&pthisx->world.pos.z, -1350.0f, 0.8f, 0.3f);
        if (pthisx->world.pos.x > 90.0f) {
            pthisx->world.pos.x = 91.0f;
            Audio_PlayActorSound2(pthisx, NA_SE_EV_BRIDGE_OPEN_STOP);
            pthis->unk_178 = 30;
            pthis->actionFunc = func_808783AC;
        }
    }
}

void BgGateShutter_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgGateShutter* pthis = (BgGateShutter*)pthisx;

    if (pthis->unk_178 != 0) {
        pthis->unk_178 -= 1;
    }
    pthis->actionFunc(pthis, globalCtx);
}

void BgGateShutter_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_gate_shutter.c", 323);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_gate_shutter.c", 328),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gKakarikoGuardGateDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_gate_shutter.c", 333);
}
