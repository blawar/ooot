#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT15_SAKU_Z_BG_SPOT15_SAKU_C
#include "actor_common.h"
/*
 * File: z_bg_spot15_saku.c
 * Overlay: ovl_Bg_Spot15_Saku
 * Description: Hyrule Castle Gate
 */

#include "z_bg_spot15_saku.h"
#include "objects/object_spot15_obj/object_spot15_obj.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgSpot15Saku_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot15Saku_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot15Saku_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot15Saku_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot15Saku_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B4930(BgSpot15Saku* pthis, GlobalContext* globalCtx);
void func_808B4978(BgSpot15Saku* pthis, GlobalContext* globalCtx);
void func_808B4A04(BgSpot15Saku* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot15_Saku_InitVars = {
    ACTOR_BG_SPOT15_SAKU,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_SPOT15_OBJ,
    sizeof(BgSpot15Saku),
    (ActorFunc)BgSpot15Saku_Init,
    (ActorFunc)BgSpot15Saku_Destroy,
    (ActorFunc)BgSpot15Saku_Update,
    (ActorFunc)BgSpot15Saku_Draw,
    (ActorFunc)BgSpot15Saku_Reset,
};

void BgSpot15Saku_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgSpot15Saku* pthis = (BgSpot15Saku*)thisx;
    s32 pad2;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gLonLonCorralFenceCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->dyna.actor.scale.x = 0.1f;
    pthis->dyna.actor.scale.y = 0.1f;
    pthis->dyna.actor.scale.z = 0.1f;
    pthis->unk_170.x = pthis->dyna.actor.world.pos.x;
    pthis->unk_170.y = pthis->dyna.actor.world.pos.y;
    pthis->unk_170.z = pthis->dyna.actor.world.pos.z;
    if (gSaveContext.infTable[7] & 2) {
        pthis->dyna.actor.world.pos.z = 2659.0f;
    }
    pthis->actionFunc = func_808B4930;
}

void BgSpot15Saku_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot15Saku* pthis = (BgSpot15Saku*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808B4930(BgSpot15Saku* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_168 && !(gSaveContext.infTable[7] & 2)) {
        pthis->timer = 2;
        pthis->actionFunc = func_808B4978;
    }
}

void func_808B4978(BgSpot15Saku* pthis, GlobalContext* globalCtx) {
    if (pthis->timer == 0) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALGATE_OPEN - SFX_FLAG);
        pthis->dyna.actor.world.pos.z -= 2.0f;
        if (pthis->dyna.actor.world.pos.z < 2660.0f) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BRIDGE_OPEN_STOP);
            pthis->timer = 30;
            pthis->actionFunc = func_808B4A04;
        }
    }
}

void func_808B4A04(BgSpot15Saku* pthis, GlobalContext* globalCtx) {
    if (pthis->timer == 0) {
        pthis->unk_168 = 0;
        pthis->actionFunc = func_808B4930;
    }
}

void BgSpot15Saku_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot15Saku* pthis = (BgSpot15Saku*)thisx;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot15Saku_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot15_saku.c", 259);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot15_saku.c", 263),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gLonLonCorralFenceDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot15_saku.c", 268);
}

void BgSpot15Saku_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Spot15_Saku_InitVars = {
        ACTOR_BG_SPOT15_SAKU,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_SPOT15_OBJ,
        sizeof(BgSpot15Saku),
        (ActorFunc)BgSpot15Saku_Init,
        (ActorFunc)BgSpot15Saku_Destroy,
        (ActorFunc)BgSpot15Saku_Update,
        (ActorFunc)BgSpot15Saku_Draw,
        (ActorFunc)BgSpot15Saku_Reset,
    };

}
