#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HAKA_WATER_Z_BG_HAKA_WATER_C
#include "actor_common.h"
/*
 * File: z_bg_haka_water.c
 * Overlay: ovl_Bg_Haka_Water
 * Description: Bottom of the Well water level changer
 */

#include "z_bg_haka_water.h"
#include "objects/object_hakach_objects/object_hakach_objects.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgHakaWater_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaWater_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgHakaWater_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaWater_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaWater_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgHakaWater_LowerWater(BgHakaWater* pthis, GlobalContext* globalCtx);
void BgHakaWater_Wait(BgHakaWater* pthis, GlobalContext* globalCtx);
void BgHakaWater_ChangeWaterLevel(BgHakaWater* pthis, GlobalContext* globalCtx);

ActorInit Bg_Haka_Water_InitVars = {
    ACTOR_BG_HAKA_WATER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_HAKACH_OBJECTS,
    sizeof(BgHakaWater),
    (ActorFunc)BgHakaWater_Init,
    (ActorFunc)BgHakaWater_Destroy,
    (ActorFunc)BgHakaWater_Update,
    (ActorFunc)BgHakaWater_Draw,
    (ActorFunc)BgHakaWater_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHakaWater_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaWater* pthis = (BgHakaWater*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    if (Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        pthis->isLowered = true;
        pthis->actor.home.pos.y -= 200.0f;
        pthis->actor.world.pos.y = pthis->actor.home.pos.y;
    } else {
        pthis->isLowered = false;
    }
    BgHakaWater_LowerWater(pthis, globalCtx);
    pthis->actionFunc = BgHakaWater_Wait;
}

void BgHakaWater_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void BgHakaWater_LowerWater(BgHakaWater* pthis, GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i < 9; i++) {
        globalCtx->colCtx.colHeader->waterBoxes[i].ySurface = (s16)pthis->actor.world.pos.y - 8;
    }
}

void BgHakaWater_Wait(BgHakaWater* pthis, GlobalContext* globalCtx) {
    if ((!pthis->isLowered && Flags_GetSwitch(globalCtx, pthis->actor.params)) ||
        (pthis->isLowered && !Flags_GetSwitch(globalCtx, pthis->actor.params))) {
        if (pthis->isLowered) {
            pthis->isLowered = false;
            pthis->actor.draw = BgHakaWater_Draw;
            pthis->actor.home.pos.y += 200.0f;
        } else {
            pthis->isLowered = true;
            pthis->actor.home.pos.y -= 200.0f;
        }
        pthis->actionFunc = BgHakaWater_ChangeWaterLevel;
    }
}

void BgHakaWater_ChangeWaterLevel(BgHakaWater* pthis, GlobalContext* globalCtx) {
    if (!pthis->isLowered && Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        pthis->isLowered = true;
        pthis->actor.home.pos.y -= 200.0f;
    } else if (pthis->isLowered && !Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        pthis->isLowered = false;
        pthis->actor.home.pos.y += 200.0f;
    }

    if (pthis->actor.home.pos.y < pthis->actor.world.pos.y) {
        func_8002F948(&pthis->actor, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
    } else {
        func_8002F948(&pthis->actor, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
    }

    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.5f) != 0) {
        pthis->actionFunc = BgHakaWater_Wait;
        if (pthis->isLowered) {
            pthis->actor.draw = NULL;
        }
    }
    BgHakaWater_LowerWater(pthis, globalCtx);
}

void BgHakaWater_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaWater* pthis = (BgHakaWater*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgHakaWater_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaWater* pthis = (BgHakaWater*)thisx;
    s32 pad;
    f32 temp;
    s32 pad2;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_water.c", 287);
    func_80093D84(globalCtx->state.gfxCtx);

    if (pthis->isLowered) {
        temp = pthis->actor.world.pos.y - pthis->actor.home.pos.y;
    } else {
        temp = pthis->actor.world.pos.y - (pthis->actor.home.pos.y - 200.0f);
    }

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)(0.765f * temp));
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, globalCtx->gameplayFrames % 128,
                                globalCtx->gameplayFrames % 128, 32, 32, 1, 0, (0 - globalCtx->gameplayFrames) % 128,
                                32, 32));

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_water.c", 312),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gBotwWaterRingDL);

    Matrix_Translate(0.0f, 92.0f, -1680.0f, MTXMODE_NEW);
    Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
    temp -= 170.0f;
    if (temp < 0.0f) {
        temp = 0.0f;
    }

    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)(5.1f * temp));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_water.c", 328),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gBotwWaterFallDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_water.c", 332);
}

void BgHakaWater_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Haka_Water_InitVars = {
        ACTOR_BG_HAKA_WATER,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_HAKACH_OBJECTS,
        sizeof(BgHakaWater),
        (ActorFunc)BgHakaWater_Init,
        (ActorFunc)BgHakaWater_Destroy,
        (ActorFunc)BgHakaWater_Update,
        (ActorFunc)BgHakaWater_Draw,
        (ActorFunc)BgHakaWater_Reset,
    };

}
