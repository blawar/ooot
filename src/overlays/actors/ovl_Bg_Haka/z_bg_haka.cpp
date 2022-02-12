#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HAKA_Z_BG_HAKA_C
#include "actor_common.h"
/*
 * File: z_bg_haka.c
 * Overlay: ovl_Bg_Haka
 * Description: Gravestone
 */

#include "z_bg_haka.h"
#include "objects/object_haka/object_haka.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_play.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgHaka_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHaka_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHaka_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHaka_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8087B758(BgHaka* pthis, Player* player);
void func_8087B7E8(BgHaka* pthis, GlobalContext* globalCtx);
void func_8087B938(BgHaka* pthis, GlobalContext* globalCtx);
void func_8087BAAC(BgHaka* pthis, GlobalContext* globalCtx);
void func_8087BAE4(BgHaka* pthis, GlobalContext* globalCtx);

ActorInit Bg_Haka_InitVars = {
    ACTOR_BG_HAKA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA,
    sizeof(BgHaka),
    (ActorFunc)BgHaka_Init,
    (ActorFunc)BgHaka_Destroy,
    (ActorFunc)BgHaka_Update,
    (ActorFunc)BgHaka_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(minVelocityY, 0, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHaka_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHaka* pthis = (BgHaka*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gGravestoneCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->actionFunc = func_8087B7E8;
}

void BgHaka_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHaka* pthis = (BgHaka*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_8087B758(BgHaka* pthis, Player* player) {
    Vec3f sp1C;

    func_8002DBD0(&pthis->dyna.actor, &sp1C, &player->actor.world.pos);
    if (fabsf(sp1C.x) < 34.6f && sp1C.z > -112.8f && sp1C.z < -36.0f) {
        player->stateFlags2 |= 0x200;
    }
}

void func_8087B7E8(BgHaka* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->dyna.unk_150 != 0.0f) {
        if (globalCtx->sceneNum == SCENE_SPOT02 && !LINK_IS_ADULT && !gSaveContext.nightFlag) {
            pthis->dyna.unk_150 = 0.0f;
            player->stateFlags2 &= ~0x10;
            if (!Gameplay_InCsMode(globalCtx)) {
                Message_StartTextbox(globalCtx, 0x5073, NULL);
                pthis->dyna.actor.params = 100;
                pthis->actionFunc = func_8087BAE4;
            }
        } else if (0.0f < pthis->dyna.unk_150 ||
                   (globalCtx->sceneNum == SCENE_SPOT06 && !LINK_IS_ADULT && !Flags_GetSwitch(globalCtx, 0x23))) {
            pthis->dyna.unk_150 = 0.0f;
            player->stateFlags2 &= ~0x10;
        } else {
            pthis->dyna.actor.world.rot.y = pthis->dyna.actor.shape.rot.y + 0x8000;
            pthis->actionFunc = func_8087B938;
        }
    }
    func_8087B758(pthis, player);
}

void func_8087B938(BgHaka* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 sp38;

    pthis->dyna.actor.speedXZ += 0.05f;
    pthis->dyna.actor.speedXZ = CLAMP_MAX(pthis->dyna.actor.speedXZ, 1.5f);
    sp38 = Math_StepToF(&pthis->dyna.actor.minVelocityY, 60.0f, pthis->dyna.actor.speedXZ);
    pthis->dyna.actor.world.pos.x =
        Math_SinS(pthis->dyna.actor.world.rot.y) * pthis->dyna.actor.minVelocityY + pthis->dyna.actor.home.pos.x;
    pthis->dyna.actor.world.pos.z =
        Math_CosS(pthis->dyna.actor.world.rot.y) * pthis->dyna.actor.minVelocityY + pthis->dyna.actor.home.pos.z;
    if (sp38 != 0) {
        pthis->dyna.unk_150 = 0.0f;
        player->stateFlags2 &= ~0x10;
        if (pthis->dyna.actor.params == 1) {
            func_80078884(NA_SE_SY_CORRECT_CHIME);
        } else if (!IS_DAY && globalCtx->sceneNum == SCENE_SPOT02) {
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_POH, pthis->dyna.actor.home.pos.x,
                        pthis->dyna.actor.home.pos.y, pthis->dyna.actor.home.pos.z, 0, pthis->dyna.actor.shape.rot.y, 0,
                        1);
        }
        pthis->actionFunc = func_8087BAAC;
    }
    func_8002F974(&pthis->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
}

void func_8087BAAC(BgHaka* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->dyna.unk_150 != 0.0f) {
        pthis->dyna.unk_150 = 0.0f;
        player->stateFlags2 &= ~0x10;
    }
}

void func_8087BAE4(BgHaka* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;

    if (pthis->dyna.actor.params != 0) {
        pthis->dyna.actor.params -= 1;
    }
    if (pthis->dyna.unk_150 != 0.0f) {
        pthis->dyna.unk_150 = 0.0f;
        player->stateFlags2 &= ~0x10;
    }
    if (pthis->dyna.actor.params == 0) {
        pthis->actionFunc = func_8087B7E8;
    }
    func_8087B758(pthis, player);
}

void BgHaka_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHaka* pthis = (BgHaka*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgHaka_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka.c", 401);

    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka.c", 406),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gGravestoneStoneDL);
    Matrix_Translate(0.0f, 0.0f, thisx->minVelocityY * 10.0f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka.c", 416),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gGravestoneEarthDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka.c", 421);
}
