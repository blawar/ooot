#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MORI_IDOMIZU_Z_BG_MORI_IDOMIZU_C
#include "actor_common.h"
/*
 * File: z_bg_mori_idomizu.c
 * Overlay: ovl_Bg_Mori_Idomizu
 * Description: Square of water in Forest Temple well
 */

#include "z_bg_mori_idomizu.h"
#include "objects/object_mori_objects/object_mori_objects.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgMoriIdomizu_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMoriIdomizu_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgMoriIdomizu_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMoriIdomizu_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMoriIdomizu_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgMoriIdomizu_SetupWaitForMoriTex(BgMoriIdomizu* pthis);
void BgMoriIdomizu_WaitForMoriTex(BgMoriIdomizu* pthis, GlobalContext* globalCtx);
void BgMoriIdomizu_SetupMain(BgMoriIdomizu* pthis);
void BgMoriIdomizu_Main(BgMoriIdomizu* pthis, GlobalContext* globalCtx);

static s16 sIsSpawned = false;

ActorInit Bg_Mori_Idomizu_InitVars = {
    ACTOR_BG_MORI_IDOMIZU,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriIdomizu),
    (ActorFunc)BgMoriIdomizu_Init,
    (ActorFunc)BgMoriIdomizu_Destroy,
    (ActorFunc)BgMoriIdomizu_Update,
    NULL,
    (ActorFunc)BgMoriIdomizu_Reset,
};

void BgMoriIdomizu_SetupAction(BgMoriIdomizu* pthis, BgMoriIdomizuActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgMoriIdomizu_SetWaterLevel(GlobalContext* globalCtx, s16 waterLevel) {
    WaterBox* waterBox = globalCtx->colCtx.colHeader->waterBoxes;

    waterBox[2].ySurface = waterLevel;
    waterBox[3].ySurface = waterLevel;
    waterBox[4].ySurface = waterLevel;
}

void BgMoriIdomizu_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriIdomizu* pthis = (BgMoriIdomizu*)thisx;

    if (sIsSpawned) {
        Actor_Kill(&pthis->actor);
        return;
    }
    pthis->actor.scale.x = 1.1f;
    pthis->actor.scale.y = 1.0f;
    pthis->actor.scale.z = 1.0f;
    pthis->actor.world.pos.x = 119.0f;
    pthis->actor.world.pos.z = -1820.0f;
    pthis->prevSwitchFlagSet = Flags_GetSwitch(globalCtx, pthis->actor.params & 0x3F);
    if (pthis->prevSwitchFlagSet != 0) {
        pthis->actor.world.pos.y = -282.0f;
        BgMoriIdomizu_SetWaterLevel(globalCtx, -282);
    } else {
        pthis->actor.world.pos.y = 184.0f;
        BgMoriIdomizu_SetWaterLevel(globalCtx, 184);
    }
    pthis->moriTexObjIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_TEX);
    if (pthis->moriTexObjIndex < 0) {
        Actor_Kill(&pthis->actor);
        // "Bank danger!"
        osSyncPrintf("Error : バンク危険！(arg_data 0x%04x)(%s %d)\n", pthis->actor.params, "../z_bg_mori_idomizu.c",
                     202);
        return;
    }
    BgMoriIdomizu_SetupWaitForMoriTex(pthis);
    sIsSpawned = true;
    pthis->isLoaded = true;
    pthis->actor.room = -1;
    // "Forest Temple well water"
    osSyncPrintf("(森の神殿 井戸水)(arg_data 0x%04x)\n", pthis->actor.params);
}

void BgMoriIdomizu_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriIdomizu* pthis = (BgMoriIdomizu*)thisx;

    if (pthis->isLoaded) {
        sIsSpawned = false;
    }
}

void BgMoriIdomizu_SetupWaitForMoriTex(BgMoriIdomizu* pthis) {
    BgMoriIdomizu_SetupAction(pthis, BgMoriIdomizu_WaitForMoriTex);
}

void BgMoriIdomizu_WaitForMoriTex(BgMoriIdomizu* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->moriTexObjIndex)) {
        BgMoriIdomizu_SetupMain(pthis);
        pthis->actor.draw = BgMoriIdomizu_Draw;
    }
}

void BgMoriIdomizu_SetupMain(BgMoriIdomizu* pthis) {
    BgMoriIdomizu_SetupAction(pthis, BgMoriIdomizu_Main);
}

void BgMoriIdomizu_Main(BgMoriIdomizu* pthis, GlobalContext* globalCtx) {
    s8 roomNum;
    Actor* thisx = &pthis->actor;
    s32 switchFlagSet;

    roomNum = globalCtx->roomCtx.curRoom.num;
    switchFlagSet = Flags_GetSwitch(globalCtx, thisx->params & 0x3F);
    if (switchFlagSet) {
        pthis->targetWaterLevel = -282.0f;
    } else {
        pthis->targetWaterLevel = 184.0f;
    }
    if (switchFlagSet && !pthis->prevSwitchFlagSet) {
        OnePointCutscene_Init(globalCtx, 3240, 70, thisx, MAIN_CAM);
        pthis->drainTimer = 90;
    } else if (!switchFlagSet && pthis->prevSwitchFlagSet) {
        OnePointCutscene_Init(globalCtx, 3240, 70, thisx, MAIN_CAM);
        pthis->drainTimer = 90;
        thisx->world.pos.y = 0.0f;
    }
    pthis->drainTimer--;
    if ((roomNum == 7) || (roomNum == 8) || (roomNum == 9)) {
        if (pthis->drainTimer < 70) {
            Math_StepToF(&thisx->world.pos.y, pthis->targetWaterLevel, 3.5f);
            BgMoriIdomizu_SetWaterLevel(globalCtx, thisx->world.pos.y);
            if (pthis->drainTimer > 0) {
                if (switchFlagSet) {
                    func_800788CC(NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
                } else {
                    func_800788CC(NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
                }
            }
        }
    } else {
        thisx->world.pos.y = pthis->targetWaterLevel;
        BgMoriIdomizu_SetWaterLevel(globalCtx, thisx->world.pos.y);
        Actor_Kill(thisx);
        return;
    }
    pthis->prevSwitchFlagSet = switchFlagSet;
}

void BgMoriIdomizu_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriIdomizu* pthis = (BgMoriIdomizu*)thisx;

    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
}

void BgMoriIdomizu_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriIdomizu* pthis = (BgMoriIdomizu*)thisx;
    u32 gameplayFrames = globalCtx->gameplayFrames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_idomizu.c", 356);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_idomizu.c", 360),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPSegment(POLY_XLU_DISP++, 0x08, gObjectTable[pthis->moriTexObjIndex].vromStart.get());

    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, 128);

    gSPSegment(POLY_XLU_DISP++, 0x09,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0x7F - (gameplayFrames & 0x7F), gameplayFrames % 0x80, 0x20,
                                0x20, 1, gameplayFrames & 0x7F, gameplayFrames % 0x80, 0x20, 0x20));

    gSPDisplayList(POLY_XLU_DISP++, gMoriIdomizuWaterDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_idomizu.c", 382);
}

void BgMoriIdomizu_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sIsSpawned = false;

    Bg_Mori_Idomizu_InitVars = {
        ACTOR_BG_MORI_IDOMIZU,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_MORI_OBJECTS,
        sizeof(BgMoriIdomizu),
        (ActorFunc)BgMoriIdomizu_Init,
        (ActorFunc)BgMoriIdomizu_Destroy,
        (ActorFunc)BgMoriIdomizu_Update,
        NULL,
        (ActorFunc)BgMoriIdomizu_Reset,
    };

}
