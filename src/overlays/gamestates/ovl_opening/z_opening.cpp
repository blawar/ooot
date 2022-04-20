#define INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_OPENING_Z_OPENING_C
#include "actor_common.h"
#include "framerate.h"
/*
 * File: z_opening.c
 * Overlay: ovl_opening
 * Description: Initializes the game into the title screen
 */

#include "global.h"
#include "def/inventory.h"
#include "def/sys_matrix.h"
#include "def/z_opening.h"
#include "def/z_play.h" // FORCE
#include "def/z_rcp.h"
#include "def/z_view.h"

#define USE_INTRO_CS
#define CHILD_GAMEPLAY

namespace oot::gamestate
{
	Opening::Opening(GraphicsContext* gfxCtx) : Base(gfxCtx)
	{
	}

	void Opening::init()
	{
		framerate_set_profile(PROFILE_OPENING);
		Matrix_Init(this);
		View_Init(&view, this->gfxCtx);
	}

	Opening::~Opening()
	{
	}

	Base* Opening::next()
	{
		return new Opening(gfxCtx);
	}

	void Opening::main()
	{
		Gfx_ClearDisplay(this->gfxCtx, 0, 0, 0);

#ifndef USE_INTRO_CS
		Sram_InitDebugSave();
		gSaveContext.gameMode = 0;
		Inventory_ChangeEquipment(EQUIP_SHIELD, 2);
		Inventory_ChangeEquipment(EQUIP_SWORD, 2);
		gSaveContext.magicMax = gSaveContext.magic;
		gSaveContext.dayTime = gSaveContext.skyboxTime = 0x8000;
		gSaveContext.unk_13F4 = 0;
		gSaveContext.magicLevel = gSaveContext.magic = 0;
		gSaveContext.buttonStatus[4] = BTN_ENABLED;
		gSaveContext.buttonStatus[3] = BTN_ENABLED;
		gSaveContext.buttonStatus[2] = BTN_ENABLED;
		gSaveContext.buttonStatus[1] = BTN_ENABLED;
		gSaveContext.buttonStatus[0] = BTN_ENABLED;
		gSaveContext.startDemo = gSaveContext.unk_13E8 = gSaveContext.unk_13EA = gSaveContext.unk_13EC = 0;

		gSaveContext.entranceIndex = 0xFC;
		// gSaveContext.entranceIndex = 0x0123;
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
		this->running = false;
		SET_NEXT_GAMESTATE(&this->state, Gameplay_Init, GlobalContext);
#else
		gSaveContext.gameMode = 1;
		this->running = false;
		gSaveContext.linkAge = LINK_AGE_ADULT;
		gSaveContext.createDebug();
		gSaveContext.cutsceneIndex = 0xFFF3;
		gSaveContext.sceneSetupIndex = 7;
		// gSaveContext.sceneSetupIndex = 0xC;
		Graph_SetNextGameState(new Global(gfxCtx));
#endif
	}
} // namespace oot::gamestate