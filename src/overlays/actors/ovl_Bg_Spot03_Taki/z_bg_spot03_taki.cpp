#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT03_TAKI_Z_BG_SPOT03_TAKI_C
#include "actor_common.h"
/*
 * File: z_bg_spot03_taki.c
 * Overlay: ovl_Bg_Spot03_Taki
 * Description: Zora's River Waterfall
 */

#include "z_bg_spot03_taki.h"
#include "objects/object_spot03_object/object_spot03_object.h"
#include "def/code_80043480.h"
#include "def/code_800EC960.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgSpot03Taki_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot03Taki_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot03Taki_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot03Taki_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot03Taki_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808ADEF0(BgSpot03Taki* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot03_Taki_InitVars = {
    ACTOR_BG_SPOT03_TAKI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT03_OBJECT,
    sizeof(BgSpot03Taki),
    (ActorFunc)BgSpot03Taki_Init,
    (ActorFunc)BgSpot03Taki_Destroy,
    (ActorFunc)BgSpot03Taki_Update,
    (ActorFunc)BgSpot03Taki_Draw,
    (ActorFunc)BgSpot03Taki_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgSpot03Taki_ApplyOpeningAlpha(BgSpot03Taki* pthis, s32 bufferIndex) {
    s32 i;
    Vtx* vtx = (bufferIndex == 0) ? object_spot03_object_Vtx_000800 : object_spot03_object_Vtx_000990;

    for (i = 0; i < 5; i++) {
        vtx[i + 10].v.cn[3] = pthis->openingAlpha;
    }
}

void BgSpot03Taki_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot03Taki* pthis = (BgSpot03Taki*)thisx;
    s16 pad;
    CollisionHeader* colHeader = NULL;

    pthis->switchFlag = (pthis->dyna.actor.params & 0x3F);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&object_spot03_object_Col_000C98, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    pthis->bufferIndex = 0;
    pthis->openingAlpha = 255.0f;
    BgSpot03Taki_ApplyOpeningAlpha(pthis, 0);
    BgSpot03Taki_ApplyOpeningAlpha(pthis, 1);
    pthis->actionFunc = func_808ADEF0;
}

void BgSpot03Taki_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot03Taki* pthis = (BgSpot03Taki*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808ADEF0(BgSpot03Taki* pthis, GlobalContext* globalCtx) {
    if (pthis->state == WATERFALL_CLOSED) {
        if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
            pthis->state = WATERFALL_OPENING_ANIMATED;
            pthis->timer = 40;
            OnePointCutscene_Init(globalCtx, 4100, -99, NULL, MAIN_CAM);
        }
    } else if (pthis->state == WATERFALL_OPENING_IDLE) {
        pthis->timer--;
        if (pthis->timer < 0) {
            pthis->state = WATERFALL_OPENING_ANIMATED;
        }
    } else if (pthis->state == WATERFALL_OPENING_ANIMATED) {
        if (pthis->openingAlpha > 0) {
            pthis->openingAlpha -= 5;
            if (pthis->openingAlpha <= 0.0f) {
                func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
                pthis->timer = 400;
                pthis->state = WATERFALL_OPENED;
                pthis->openingAlpha = 0;
            }
        }
    } else if (pthis->state == WATERFALL_OPENED) {
        pthis->timer--;
        if (pthis->timer < 0) {
            pthis->state = WATERFALL_CLOSING;
        }
    } else if (pthis->state == WATERFALL_CLOSING) {
        if (pthis->openingAlpha < 255.0f) {
            pthis->openingAlpha += 5.0f;
            if (pthis->openingAlpha >= 255.0f) {
                func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
                pthis->state = WATERFALL_CLOSED;
                pthis->openingAlpha = 255.0f;
                Flags_UnsetSwitch(globalCtx, pthis->switchFlag);
            }
        }
    }

    BgSpot03Taki_ApplyOpeningAlpha(pthis, pthis->bufferIndex);
}

void BgSpot03Taki_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot03Taki* pthis = (BgSpot03Taki*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot03Taki_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot03Taki* pthis = (BgSpot03Taki*)thisx;
    s32 pad;
    u32 gameplayFrames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot03_taki.c", 321);

    gameplayFrames = globalCtx->gameplayFrames;

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot03_taki.c", 325),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(
        POLY_XLU_DISP++, 0x08,
        Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, gameplayFrames * 5, 64, 64, 1, 0, gameplayFrames * 5, 64, 64));

    gSPDisplayList(POLY_XLU_DISP++, object_spot03_object_DL_000B20);

    if (pthis->bufferIndex == 0) {
        gSPVertex(POLY_XLU_DISP++, object_spot03_object_Vtx_000800, 25, 0);
    } else {
        gSPVertex(POLY_XLU_DISP++, object_spot03_object_Vtx_000990, 25, 0);
    }

    gSPDisplayList(POLY_XLU_DISP++, object_spot03_object_DL_000BC0);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, gameplayFrames * 1, gameplayFrames * 3, 64, 64, 1,
                                -gameplayFrames, gameplayFrames * 3, 64, 64));

    gSPDisplayList(POLY_XLU_DISP++, object_spot03_object_DL_001580);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot03_taki.c", 358);

    pthis->bufferIndex = pthis->bufferIndex == 0;

    if (pthis->state >= WATERFALL_OPENING_IDLE && pthis->state <= WATERFALL_OPENED) {
        Audio_PlaySoundWaterfall(&pthis->dyna.actor.projectedPos, 0.5f);
    } else {
        Audio_PlaySoundWaterfall(&pthis->dyna.actor.projectedPos, 1.0f);
    }
}

void BgSpot03Taki_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Spot03_Taki_InitVars = {
        ACTOR_BG_SPOT03_TAKI,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_SPOT03_OBJECT,
        sizeof(BgSpot03Taki),
        (ActorFunc)BgSpot03Taki_Init,
        (ActorFunc)BgSpot03Taki_Destroy,
        (ActorFunc)BgSpot03Taki_Update,
        (ActorFunc)BgSpot03Taki_Draw,
        (ActorFunc)BgSpot03Taki_Reset,
    };

}
