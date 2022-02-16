#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_ZG_Z_BG_ZG_C
#include "actor_common.h"
/*
 * File: z_bg_zg.c
 * Overlay: ovl_Bg_Zg
 * Description: Metal bars (Ganon's Castle)
 */

#include "z_bg_zg.h"
#include "objects/object_zg/object_zg.h"
#include "vt.h"
#include "def/code_80043480.h"
#include "def/code_800F7260.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void BgZg_Init(Actor* thisx, GlobalContext* globalCtx);
void BgZg_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgZg_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgZg_Update(Actor* thisx, GlobalContext* globalCtx);
void BgZg_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808C0C50(BgZg* pthis);
s32 func_808C0C98(BgZg* pthis, GlobalContext* globalCtx);
s32 func_808C0CC8(BgZg* pthis);
void func_808C0CD4(BgZg* pthis, GlobalContext* globalCtx);
void func_808C0D08(BgZg* pthis, GlobalContext* globalCtx);
void func_808C0EEC(BgZg* pthis, GlobalContext* globalCtx);

static BgZgActionFunc sActionFuncs[] = {
    func_808C0CD4,
    func_808C0D08,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

static BgZgDrawFunc sDrawFuncs[] = {
    func_808C0EEC,
};

ActorInit Bg_Zg_InitVars = {
    ACTOR_BG_ZG,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZG,
    sizeof(BgZg),
    (ActorFunc)BgZg_Init,
    (ActorFunc)BgZg_Destroy,
    (ActorFunc)BgZg_Update,
    (ActorFunc)BgZg_Draw,
    (ActorFunc)BgZg_Reset,
};

void BgZg_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgZg* pthis = (BgZg*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808C0C50(BgZg* pthis) {
    Audio_PlaySoundGeneral(NA_SE_EV_METALDOOR_OPEN, &pthis->dyna.actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                           &D_801333E8);
}

s32 func_808C0C98(BgZg* pthis, GlobalContext* globalCtx) {
    s32 flag = (pthis->dyna.actor.params >> 8) & 0xFF;

    return Flags_GetSwitch(globalCtx, flag);
}

s32 func_808C0CC8(BgZg* pthis) {
    s32 flag = pthis->dyna.actor.params & 0xFF;

    return flag;
}

void func_808C0CD4(BgZg* pthis, GlobalContext* globalCtx) {
    if (func_808C0C98(pthis, globalCtx) != 0) {
        pthis->action = 1;
        func_808C0C50(pthis);
    }
}

void func_808C0D08(BgZg* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.world.pos.y += (kREG(16) + 20.0f) * 1.2f;
    if ((((kREG(17) + 200.0f) * 1.2f) + pthis->dyna.actor.home.pos.y) <= pthis->dyna.actor.world.pos.y) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgZg_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgZg* pthis = (BgZg*)thisx;
    s32 action = pthis->action;

    if (((action < 0) || (1 < action)) || (sActionFuncs[action] == NULL)) {
        // "Main Mode is wrong!!!!!!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
    } else {
        sActionFuncs[action](pthis, globalCtx);
    }
}

void BgZg_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad[2];
    BgZg* pthis = (BgZg*)thisx;
    CollisionHeader* colHeader;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    colHeader = NULL;
    CollisionHeader_GetVirtual(&gTowerCollapseBarsCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if ((func_808C0CC8(pthis) == 8) || (func_808C0CC8(pthis) == 9)) {
        pthis->dyna.actor.scale.x = pthis->dyna.actor.scale.x * 1.3f;
        pthis->dyna.actor.scale.z = pthis->dyna.actor.scale.z * 1.3f;
        pthis->dyna.actor.scale.y = pthis->dyna.actor.scale.y * 1.2f;
    }

    pthis->action = 0;
    pthis->drawConfig = 0;
    if (func_808C0C98(pthis, globalCtx)) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void func_808C0EEC(BgZg* pthis, GlobalContext* globalCtx) {
    GraphicsContext* localGfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(localGfxCtx, "../z_bg_zg.c", 311);

    func_80093D18(localGfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(localGfxCtx, "../z_bg_zg.c", 315),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gTowerCollapseBarsDL);

    CLOSE_DISPS(localGfxCtx, "../z_bg_zg.c", 320);
}

void BgZg_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgZg* pthis = (BgZg*)thisx;
    s32 drawConfig = pthis->drawConfig;

    if (((drawConfig < 0) || (drawConfig > 0)) || sDrawFuncs[drawConfig] == NULL) {
        // "Drawing mode is wrong !!!!!!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
    } else {
        sDrawFuncs[drawConfig](pthis, globalCtx);
    }
}

void BgZg_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Zg_InitVars = {
        ACTOR_BG_ZG,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_ZG,
        sizeof(BgZg),
        (ActorFunc)BgZg_Init,
        (ActorFunc)BgZg_Destroy,
        (ActorFunc)BgZg_Update,
        (ActorFunc)BgZg_Draw,
        (ActorFunc)BgZg_Reset,
    };

}
