#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_SYOKU_Z_BG_HIDAN_SYOKU_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_syoku.c
 * Overlay: ovl_Bg_Hidan_Syoku
 * Description: Stone Elevator in the Fire Temple
 */

#include "z_bg_hidan_syoku.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "def/code_80043480.h"
#include "def/cosf.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_4

void BgHidanSyoku_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanSyoku_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgHidanSyoku_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanSyoku_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanSyoku_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8088F4B8(BgHidanSyoku* pthis, GlobalContext* globalCtx);
void func_8088F514(BgHidanSyoku* pthis, GlobalContext* globalCtx);
void func_8088F62C(BgHidanSyoku* pthis, GlobalContext* globalCtx);

ActorInit Bg_Hidan_Syoku_InitVars = {
    ACTOR_BG_HIDAN_SYOKU,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanSyoku),
    (ActorFunc)BgHidanSyoku_Init,
    (ActorFunc)BgHidanSyoku_Destroy,
    (ActorFunc)BgHidanSyoku_Update,
    (ActorFunc)BgHidanSyoku_Draw,
    (ActorFunc)BgHidanSyoku_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHidanSyoku_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHidanSyoku* pthis = (BgHidanSyoku*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(&gFireTempleFlareDancerPlatformCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->actionFunc = func_8088F4B8;
    pthis->dyna.actor.home.pos.y += 540.0f;
}

void BgHidanSyoku_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanSyoku* pthis = (BgHidanSyoku*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_8088F47C(BgHidanSyoku* pthis) {
    pthis->timer = 60;
    Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
    pthis->actionFunc = func_8088F62C;
}

void func_8088F4B8(BgHidanSyoku* pthis, GlobalContext* globalCtx) {
    if (Flags_GetClear(globalCtx, pthis->dyna.actor.room) && func_8004356C(&pthis->dyna)) {
        pthis->timer = 140;
        pthis->actionFunc = func_8088F514;
    }
}

void func_8088F514(BgHidanSyoku* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    pthis->dyna.actor.world.pos.y = (cosf(pthis->timer * (M_PI / 140)) * 540.0f) + pthis->dyna.actor.home.pos.y;
    if (pthis->timer == 0) {
        func_8088F47C(pthis);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE3 - SFX_FLAG);
    }
}

void func_8088F5A0(BgHidanSyoku* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y - (cosf(pthis->timer * (M_PI / 140)) * 540.0f);
    if (pthis->timer == 0) {
        func_8088F47C(pthis);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE3 - SFX_FLAG);
    }
}

void func_8088F62C(BgHidanSyoku* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        pthis->timer = 140;
        if (pthis->dyna.actor.world.pos.y < pthis->dyna.actor.home.pos.y) {
            pthis->actionFunc = func_8088F514;
        } else {
            pthis->actionFunc = func_8088F5A0;
        }
    }
}

void BgHidanSyoku_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanSyoku* pthis = (BgHidanSyoku*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    if (func_8004356C(&pthis->dyna)) {
        if (pthis->unk_168 == 0) {
            pthis->unk_168 = 3;
        }
        Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_FIRE_PLATFORM);
    } else if (!func_8004356C(&pthis->dyna)) {
        if (pthis->unk_168 != 0) {
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DUNGEON0);
        }
        pthis->unk_168 = 0;
    }
}

void BgHidanSyoku_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gFireTempleFlareDancerPlatformDL);
}

void BgHidanSyoku_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Hidan_Syoku_InitVars = {
        ACTOR_BG_HIDAN_SYOKU,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_HIDAN_OBJECTS,
        sizeof(BgHidanSyoku),
        (ActorFunc)BgHidanSyoku_Init,
        (ActorFunc)BgHidanSyoku_Destroy,
        (ActorFunc)BgHidanSyoku_Update,
        (ActorFunc)BgHidanSyoku_Draw,
        (ActorFunc)BgHidanSyoku_Reset,
    };

}
