#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_YDAN_HASI_Z_BG_YDAN_HASI_C
#include "actor_common.h"
/*
 * File: z_bg_ydan_hasi.c
 * Overlay: ovl_Bg_Ydan_Hasi
 * Description: Deku Tree Puzzle elements. Water plane and floating block in B1, and 3 blocks on 2F
 */

#include "z_bg_ydan_hasi.h"
#include "objects/object_ydan_objects/object_ydan_objects.h"
#include "def/code_80043480.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgYdanHasi_Init(Actor* thisx, GlobalContext* globalCtx);
void BgYdanHasi_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgYdanHasi_Update(Actor* thisx, GlobalContext* globalCtx);
void BgYdanHasi_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgYdanHasi_InitWater(BgYdanHasi* pthis, GlobalContext* globalCtx);
void BgYdanHasi_UpdateFloatingBlock(BgYdanHasi* pthis, GlobalContext* globalCtx);
void BgYdanHasi_SetupThreeBlocks(BgYdanHasi* pthis, GlobalContext* globalCtx);
void BgYdanHasi_MoveWater(BgYdanHasi* pthis, GlobalContext* globalCtx);
void BgYdanHasi_DecWaterTimer(BgYdanHasi* pthis, GlobalContext* globalCtx);
void BgYdanHasi_UpdateThreeBlocks(BgYdanHasi* pthis, GlobalContext* globalCtx);

ActorInit Bg_Ydan_Hasi_InitVars = {
    ACTOR_BG_YDAN_HASI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_YDAN_OBJECTS,
    sizeof(BgYdanHasi),
    (ActorFunc)BgYdanHasi_Init,
    (ActorFunc)BgYdanHasi_Destroy,
    (ActorFunc)BgYdanHasi_Update,
    (ActorFunc)BgYdanHasi_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgYdanHasi_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgYdanHasi* pthis = (BgYdanHasi*)thisx;
    CollisionHeader* colHeader = NULL;
    WaterBox* waterBox;

    Actor_ProcessInitChain(thisx, sInitChain);
    pthis->type = ((thisx->params >> 8) & 0x3F);
    thisx->params = thisx->params & 0xFF;
    waterBox = &globalCtx->colCtx.colHeader->waterBoxes[1];
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    if (thisx->params == HASI_WATER) {
        // Water the moving platform floats on in B1. Never runs in Master Quest
        waterBox->ySurface = thisx->world.pos.y = thisx->home.pos.y += -5.0f;
        pthis->actionFunc = BgYdanHasi_InitWater;
    } else {
        if (thisx->params == HASI_WATER_BLOCK) {
            // Moving platform on the water in B1
            CollisionHeader_GetVirtual(&gDTSlidingPlatformCol, &colHeader);
            thisx->scale.z = 0.15f;
            thisx->scale.x = 0.15f;
            thisx->world.pos.y = (waterBox->ySurface + 20.0f);
            pthis->actionFunc = BgYdanHasi_UpdateFloatingBlock;
        } else {
            // 3 platforms on 2F
            CollisionHeader_GetVirtual(&gDTRisingPlatformsCol, &colHeader);
            thisx->draw = NULL;
            pthis->actionFunc = BgYdanHasi_SetupThreeBlocks;
            Actor_SetFocus(&pthis->dyna.actor, 40.0f);
        }
        pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    }
    pthis->timer = 0;
}

void BgYdanHasi_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgYdanHasi* pthis = (BgYdanHasi*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgYdanHasi_UpdateFloatingBlock(BgYdanHasi* pthis, GlobalContext* globalCtx) {
    WaterBox* waterBox;
    f32 framesAfterMath;

    framesAfterMath = sinf((globalCtx->gameplayFrames & 0xFF) * (M_PI / 128)) * 165.0f;
    pthis->dyna.actor.world.pos.x =
        ((Math_SinS(pthis->dyna.actor.world.rot.y) * framesAfterMath) + pthis->dyna.actor.home.pos.x);
    pthis->dyna.actor.world.pos.z =
        ((Math_CosS(pthis->dyna.actor.world.rot.y) * framesAfterMath) + pthis->dyna.actor.home.pos.z);
    waterBox = &globalCtx->colCtx.colHeader->waterBoxes[1];
    pthis->dyna.actor.world.pos.y = waterBox->ySurface + 20.0f;
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        pthis->timer = 50;
    }
    pthis->dyna.actor.world.pos.y += 2.0f * sinf(pthis->timer * (M_PI / 25));
}

void BgYdanHasi_InitWater(BgYdanHasi* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->type)) {
        pthis->timer = 600;
        pthis->actionFunc = BgYdanHasi_MoveWater;
    }
}

void BgYdanHasi_MoveWater(BgYdanHasi* pthis, GlobalContext* globalCtx) {
    WaterBox* waterBox;

    if (pthis->timer == 0) {
        if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 1.0f) != 0) {
            Flags_UnsetSwitch(globalCtx, pthis->type);
            pthis->actionFunc = BgYdanHasi_InitWater;
        }
        func_8002F948(&pthis->dyna.actor, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
    } else {
        if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y - 47.0f, 0.5f)) {
            pthis->actionFunc = BgYdanHasi_DecWaterTimer;
        }
        func_8002F948(&pthis->dyna.actor, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
    }
    waterBox = &globalCtx->colCtx.colHeader->waterBoxes[1];
    waterBox->ySurface = pthis->dyna.actor.world.pos.y;
}

void BgYdanHasi_DecWaterTimer(BgYdanHasi* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    func_8002F994(&pthis->dyna.actor, pthis->timer);
    if (pthis->timer == 0) {
        pthis->actionFunc = BgYdanHasi_MoveWater;
    }
}

void BgYdanHasi_SetupThreeBlocks(BgYdanHasi* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->type)) {
        pthis->timer = 260;
        pthis->dyna.actor.draw = BgYdanHasi_Draw;
        pthis->actionFunc = BgYdanHasi_UpdateThreeBlocks;
        OnePointCutscene_Init(globalCtx, 3040, 30, &pthis->dyna.actor, MAIN_CAM);
    }
}

void BgYdanHasi_UpdateThreeBlocks(BgYdanHasi* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 3.0f) != 0) {
            Flags_UnsetSwitch(globalCtx, pthis->type);
            pthis->dyna.actor.draw = NULL;
            pthis->actionFunc = BgYdanHasi_SetupThreeBlocks;
        } else {
            func_8002F948(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE - SFX_FLAG);
        }
    } else if (!Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 120.0f, 3.0f)) {
        func_8002F948(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE - SFX_FLAG);

    } else {
        func_8002F994(&pthis->dyna.actor, pthis->timer);
    }
}

void BgYdanHasi_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgYdanHasi* pthis = (BgYdanHasi*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgYdanHasi_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Gfx* dLists[] = { gDTSlidingPlatformDL, gDTWaterPlaneDL, gDTRisingPlatformsDL };
    BgYdanHasi* pthis = (BgYdanHasi*)thisx;

    if (pthis->dyna.actor.params == HASI_WATER_BLOCK || pthis->dyna.actor.params == HASI_THREE_BLOCKS) {
        Gfx_DrawDListOpa(globalCtx, dLists[pthis->dyna.actor.params]);
    } else {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_ydan_hasi.c", 577);

        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, -globalCtx->gameplayFrames % 128,
                                    globalCtx->gameplayFrames % 128, 0x20, 0x20, 1, globalCtx->gameplayFrames % 128,
                                    globalCtx->gameplayFrames % 128, 0x20, 0x20));
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_ydan_hasi.c", 592),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gDTWaterPlaneDL);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_ydan_hasi.c", 597);
    }
}
