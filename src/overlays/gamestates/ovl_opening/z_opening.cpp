#define INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_OPENING_Z_OPENING_C
#include "actor_common.h"
#include "framerate.h"
#include "z_opening.h"
#include "z_player.h"
/*
 * File: z_opening.c
 * Overlay: ovl_opening
 * Description: Initializes the game into the title screen
 */

#include "global.h"
#include "def/code_80097A00.h"
#include "def/sys_matrix.h"
#include "def/z_common_data.h"
#include "def/z_opening.h"
#include "def/z_rcp.h"
#include "def/z_sram.h"
#include "def/z_view.h"
#include "def/z_play.h" // FORCE

#define USE_INTRO_CS
#define CHILD_GAMEPLAY

void Opening_SetupTitleScreen(OpeningContext* pthis) {
#ifndef USE_INTRO_CS
    Sram_InitDebugSave();
    gSaveContext.gameMode = 0;
    Inventory_ChangeEquipment(EQUIP_SHIELD, 2);
    Inventory_ChangeEquipment(EQUIP_SWORD, 2);
    gSaveContext.unk_13F6 = gSaveContext.magic;
    gSaveContext.dayTime = gSaveContext.skyboxTime = 0x8000;
    gSaveContext.unk_13F4 = 0;
    gSaveContext.magicLevel = gSaveContext.magic = 0;
    gSaveContext.buttonStatus[4] = BTN_ENABLED;
    gSaveContext.buttonStatus[3] = BTN_ENABLED;
    gSaveContext.buttonStatus[2] = BTN_ENABLED;
    gSaveContext.buttonStatus[1] = BTN_ENABLED;
    gSaveContext.buttonStatus[0] = BTN_ENABLED;
    gSaveContext.unk_13E7 = gSaveContext.unk_13E8 = gSaveContext.unk_13EA = gSaveContext.unk_13EC = 0;

    gSaveContext.entranceIndex = 0xFC;
    //gSaveContext.entranceIndex = 0x0123;
    gSaveContext.entranceIndex = 0x000C; // dark ganon fight
    gSaveContext.entranceIndex = 0x00DB; // kakariko

    gSaveContext.respawnFlag = 0;
    gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex = -1;
    gSaveContext.seqId = (u8)NA_BGM_DISABLED;
    gSaveContext.natureAmbienceId = 0xFF;
    gSaveContext.showTitleCard = false;
#ifdef CHILD_GAMEPLAY
    gSaveContext.linkAge = 1;
    gSaveContext.equips.cButtonSlots[0] = ITEM_SLINGSHOT;
#else
    gSaveContext.linkAge = 0;
#endif
    pthis->state.running = false;
    SET_NEXT_GAMESTATE(&pthis->state, Gameplay_Init, GlobalContext);
#else
    gSaveContext.gameMode = 1;
    pthis->state.running = false;
    gSaveContext.linkAge = 0;
    Sram_InitDebugSave();
    gSaveContext.cutsceneIndex = 0xFFF3;
    gSaveContext.sceneSetupIndex = 7;
    //gSaveContext.sceneSetupIndex = 0xC;
    SET_NEXT_GAMESTATE(&pthis->state, Gameplay_Init, GlobalContext);
#endif
}

void func_80803C5C(OpeningContext* pthis) {
}

void Opening_Main(GameState* thisx) {
    OpeningContext* pthis = (OpeningContext*)thisx;

    Gfx_ClearDisplay(pthis->state.gfxCtx, 0, 0, 0);
    Opening_SetupTitleScreen(pthis);
    func_80803C5C(pthis);
}

void Opening_Destroy(GameState* thisx) {
}

void Opening_Init(GameState* thisx) {
    OpeningContext* pthis = (OpeningContext*)thisx;

    framerate_set_profile(PROFILE_OPENING);
    Matrix_Init(&pthis->state);
    View_Init(&pthis->view, pthis->state.gfxCtx);
    pthis->state.main = Opening_Main;
    pthis->state.destroy = Opening_Destroy;
}
