#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MIZU_WATER_Z_BG_MIZU_WATER_C
#include "actor_common.h"
/*
 * File: z_bg_mizu_water.c
 * Overlay: ovl_Bg_Mizu_Water
 * Description: Water plane in Water Temple. Changes height based on switches 0x1C, 0x1D, 0x1E.
 */

#include "z_bg_mizu_water.h"
#include "objects/object_mizu_objects/object_mizu_objects.h"
#include "def/code_800A9F30.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgMizuWater_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMizuWater_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMizuWater_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMizuWater_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgMizuWater_WaitForAction(BgMizuWater* pthis, GlobalContext* globalCtx);
void BgMizuWater_ChangeWaterLevel(BgMizuWater* pthis, GlobalContext* globalCtx);

typedef struct {
    s32 switchFlag;
    s32 yDiff;
} WaterLevel;

static WaterLevel sWaterLevels[] = {
    { 0x00, 0 },
    { WATER_TEMPLE_WATER_F3_FLAG, 0 },
    { WATER_TEMPLE_WATER_F2_FLAG, WATER_TEMPLE_WATER_F2_Y - WATER_TEMPLE_WATER_F3_Y },
    { WATER_TEMPLE_WATER_F1_FLAG, WATER_TEMPLE_WATER_F1_Y - WATER_TEMPLE_WATER_F3_Y },
};

ActorInit Bg_Mizu_Water_InitVars = {
    ACTOR_BG_MIZU_WATER,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MIZU_OBJECTS,
    sizeof(BgMizuWater),
    (ActorFunc)BgMizuWater_Init,
    (ActorFunc)BgMizuWater_Destroy,
    (ActorFunc)BgMizuWater_Update,
    (ActorFunc)BgMizuWater_Draw,
};

static f32 sUnused1 = 0;
static f32 sUnused2 = 110.0f;

static u32 sWaterBoxIndexes[] = { 2, 3, 5, 7, 12, 20, 21, 22 };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F(scale, 1, ICHAIN_STOP),
};

u32 BgMizuWater_GetWaterLevelActionIndex(s16 switchFlag, GlobalContext* globalCtx) {
    u32 ret;

    if (bREG(0) != 0) {
        switch (bREG(1)) {
            case 0:
                Flags_SetSwitch(globalCtx, WATER_TEMPLE_WATER_F1_FLAG);
                break;
            case 1:
                Flags_SetSwitch(globalCtx, WATER_TEMPLE_WATER_F2_FLAG);
                break;
            case 2:
                Flags_SetSwitch(globalCtx, WATER_TEMPLE_WATER_F3_FLAG);
                break;
        }
        bREG(0) = 0;
    }
    if (Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F1_FLAG) && (switchFlag != WATER_TEMPLE_WATER_F1_FLAG)) {
        ret = 3;
    } else if (Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F2_FLAG) && (switchFlag != WATER_TEMPLE_WATER_F2_FLAG)) {
        ret = 2;
    } else if (Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F3_FLAG) && (switchFlag != WATER_TEMPLE_WATER_F3_FLAG)) {
        ret = 1;
    } else {
        ret = 0;
    }

    return ret;
}

void BgMizuWater_SetWaterBoxesHeight(WaterBox* waterBoxes, s16 height) {
    u32 i;

    for (i = 0; i < 8; i++) {
        waterBoxes[sWaterBoxIndexes[i]].ySurface = height;
    }
}

void BgMizuWater_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgMizuWater* pthis = (BgMizuWater*)thisx;
    f32 initialActorY;
    WaterBox* waterBoxes;
    s32 waterLevelActionIndex;

    waterBoxes = globalCtx->colCtx.colHeader->waterBoxes;
    pthis->type = pthis->actor.params & 0xFF;
    pthis->switchFlag = (pthis->actor.params >> 8) & 0xFF;
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    initialActorY = pthis->actor.world.pos.y;
    pthis->baseY = initialActorY;
    pthis->targetY = initialActorY;

    switch (pthis->type) {
        case 0:
            if (bREG(15) == 0) {
                osSyncPrintf("<コンストラクト>%x %x %x\n", Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F1_FLAG),
                             Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F2_FLAG),
                             Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F3_FLAG));
            }
            waterLevelActionIndex = BgMizuWater_GetWaterLevelActionIndex(-1, globalCtx);
            pthis->actor.world.pos.y = sWaterLevels[waterLevelActionIndex].yDiff + pthis->baseY;
            BgMizuWater_SetWaterBoxesHeight(waterBoxes, pthis->actor.world.pos.y);
            pthis->actor.params = sWaterLevels[waterLevelActionIndex].switchFlag;
            Flags_UnsetSwitch(globalCtx, WATER_TEMPLE_WATER_F1_FLAG);
            Flags_UnsetSwitch(globalCtx, WATER_TEMPLE_WATER_F2_FLAG);
            Flags_UnsetSwitch(globalCtx, WATER_TEMPLE_WATER_F3_FLAG);

            switch (pthis->actor.params) {
                case 0x1E:
                    Flags_SetSwitch(globalCtx, WATER_TEMPLE_WATER_F3_FLAG);
                    break;
                case 0x1D:
                    Flags_SetSwitch(globalCtx, WATER_TEMPLE_WATER_F2_FLAG);
                    break;
                case 0x1C:
                default:
                    Flags_SetSwitch(globalCtx, WATER_TEMPLE_WATER_F1_FLAG);
                    break;
            }
            pthis->targetY = pthis->actor.world.pos.y;
            break;
        case 1:
            break;
        case 2:
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->actor.world.pos.y = pthis->baseY + 85.0f;
            }
            waterBoxes[6].ySurface = pthis->actor.world.pos.y;
            break;
        case 3:
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->actor.world.pos.y = pthis->baseY + 110.0f;
                if (1) {}
                pthis->targetY = pthis->actor.world.pos.y;
            }
            waterBoxes[8].ySurface = pthis->actor.world.pos.y;
            break;
        case 4:
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->actor.world.pos.y = pthis->baseY + 160.0f;
                if (1) {}
                pthis->targetY = pthis->actor.world.pos.y;
            }
            waterBoxes[16].ySurface = pthis->actor.world.pos.y;
            break;
    }

    pthis->actionFunc = BgMizuWater_WaitForAction;
}

void BgMizuWater_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void BgMizuWater_WaitForAction(BgMizuWater* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 waterLevelActionIndex;
    s16 prevSwitchFlag;

    switch (pthis->type) {
        case 0:
            prevSwitchFlag = pthis->actor.params;
            waterLevelActionIndex = BgMizuWater_GetWaterLevelActionIndex(pthis->actor.params, globalCtx);
            if (waterLevelActionIndex != 0) {
                if (prevSwitchFlag != sWaterLevels[waterLevelActionIndex].switchFlag) {
                    OnePointCutscene_Init(globalCtx, 3120, -100 - waterLevelActionIndex, NULL, MAIN_CAM);
                    pthis->actor.params = sWaterLevels[waterLevelActionIndex].switchFlag;
                    pthis->targetY = sWaterLevels[waterLevelActionIndex].yDiff + pthis->baseY;
                }
            }
            if ((prevSwitchFlag != pthis->actor.params) && (prevSwitchFlag != 0)) {
                Flags_UnsetSwitch(globalCtx, prevSwitchFlag);
            }
            break;
        case 1:
            break;
        case 2:
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->targetY = pthis->baseY + 85.0f;
            } else {
                pthis->targetY = pthis->baseY;
            }
            break;
        case 3:
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->targetY = pthis->baseY + 110.0f;
            } else {
                pthis->targetY = pthis->baseY;
            }
            break;
        case 4:
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->targetY = pthis->baseY + 160.0f;
            } else {
                pthis->targetY = pthis->baseY;
            }
    }

    if (pthis->targetY != pthis->actor.world.pos.y) {
        pthis->actionFunc = BgMizuWater_ChangeWaterLevel;
    }
}

void BgMizuWater_ChangeWaterLevel(BgMizuWater* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 prevSwitchFlag;
    s32 waterLevelActionIndex;
    WaterBox* waterBoxes;

    waterBoxes = globalCtx->colCtx.colHeader->waterBoxes;
    switch (pthis->type) {
        case 0:
            prevSwitchFlag = pthis->actor.params;
            waterLevelActionIndex = BgMizuWater_GetWaterLevelActionIndex(pthis->actor.params, globalCtx);
            if (waterLevelActionIndex != 0) {
                if (prevSwitchFlag != sWaterLevels[waterLevelActionIndex].switchFlag) {
                    pthis->actor.params = sWaterLevels[waterLevelActionIndex].switchFlag;
                    pthis->targetY = sWaterLevels[waterLevelActionIndex].yDiff + pthis->baseY;
                }
            }

            if ((prevSwitchFlag != pthis->actor.params) && (prevSwitchFlag != 0)) {
                Flags_UnsetSwitch(globalCtx, prevSwitchFlag);
            }

            if (Math_StepToF(&pthis->actor.world.pos.y, pthis->targetY, 5.0f)) {
                globalCtx->roomCtx.unk_74[0] = 0;
                pthis->actionFunc = BgMizuWater_WaitForAction;
                Message_CloseTextbox(globalCtx);
            }
            BgMizuWater_SetWaterBoxesHeight(globalCtx->colCtx.colHeader->waterBoxes, pthis->actor.world.pos.y);
            break;
        case 1:
            break;
        case 2:
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->targetY = pthis->baseY + 85.0f;
            } else {
                pthis->targetY = pthis->baseY;
            }
            if (Math_StepToF(&pthis->actor.world.pos.y, pthis->targetY, 1.0f)) {
                globalCtx->roomCtx.unk_74[0] = 0;
                pthis->actionFunc = BgMizuWater_WaitForAction;
            }
            waterBoxes[6].ySurface = pthis->actor.world.pos.y;
            break;
        case 3:
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->targetY = pthis->baseY + 110.0f;
            } else {
                pthis->targetY = pthis->baseY;
            }
            if (Math_StepToF(&pthis->actor.world.pos.y, pthis->targetY, 1.0f)) {
                globalCtx->roomCtx.unk_74[0] = 0;
                pthis->actionFunc = BgMizuWater_WaitForAction;
            }
            waterBoxes[8].ySurface = pthis->actor.world.pos.y;
            break;
        case 4:
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->targetY = pthis->baseY + 160.0f;
            } else {
                pthis->targetY = pthis->baseY;
            }
            if (Math_StepToF(&pthis->actor.world.pos.y, pthis->targetY, 1.0f)) {
                globalCtx->roomCtx.unk_74[0] = 0;
                pthis->actionFunc = BgMizuWater_WaitForAction;
            }
            waterBoxes[16].ySurface = pthis->actor.world.pos.y;
            break;
    }

    if (pthis->targetY < pthis->actor.world.pos.y) {
        func_800AA000(0.0f, 0x78, 0x14, 0xA);
        func_8002F948(&pthis->actor, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
    } else if (pthis->targetY > pthis->actor.world.pos.y) {
        func_800AA000(0.0f, 0x78, 0x14, 0xA);
        func_8002F948(&pthis->actor, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
    }
}

void BgMizuWater_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgMizuWater* pthis = (BgMizuWater*)thisx;
    s32 posY;
    s32 unk0;
    s32 unk1;
    s32 pad;

    if (bREG(15) == 0) {
        osSyncPrintf("%x %x %x\n", Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F1_FLAG),
                     Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F2_FLAG),
                     Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F3_FLAG));
    }
    if (pthis->type == 0) {
        posY = pthis->actor.world.pos.y;
        unk0 = 0;
        unk1 = 0;
        if (posY < WATER_TEMPLE_WATER_F1_Y) {
            unk0 = 0;
            unk1 = (posY - WATER_TEMPLE_WATER_B1_Y) / (WATER_TEMPLE_WATER_F1_Y - WATER_TEMPLE_WATER_B1_Y) * 200;
        } else if (posY < WATER_TEMPLE_WATER_F2_Y) {
            unk0 = 1;
            unk1 = 255 - (s32)((posY - WATER_TEMPLE_WATER_F1_Y) / (WATER_TEMPLE_WATER_F2_Y - WATER_TEMPLE_WATER_F1_Y) *
                               (255 - 160));
        } else if (posY <= WATER_TEMPLE_WATER_F3_Y) {
            unk0 = 2;
            unk1 = 255 - (s32)((posY - WATER_TEMPLE_WATER_F2_Y) / (WATER_TEMPLE_WATER_F3_Y - WATER_TEMPLE_WATER_F2_Y) *
                               (255 - 160));
        }
        globalCtx->roomCtx.unk_74[1] = ((u8)unk0 << 8) | (unk1 & 0xFF);
    }

    pthis->actionFunc(pthis, globalCtx);
}

void BgMizuWater_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgMizuWater* pthis = (BgMizuWater*)thisx;
    s32 gameplayFrames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mizu_water.c", 738);
    gameplayFrames = globalCtx->gameplayFrames;
    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x0C,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, -gameplayFrames * 1, gameplayFrames * 1, 32, 32, 1, 0,
                                -gameplayFrames * 1, 32, 32));

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mizu_water.c", 749),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 128);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 102);

    gSPDisplayList(POLY_XLU_DISP++, gObjectMizuObjectsWaterDL_004B20);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mizu_water.c", 756);
}
