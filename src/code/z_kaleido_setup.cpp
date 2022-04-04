#define INTERNAL_SRC_CODE_Z_KALEIDO_SETUP_C
#include "global.h"
#include "z64save.h"
#include "padmgr.h"
#include "kaleido.h"
#include "kaleido_macros.h"
#include "z64global.h"
#include "z64item.h"
#include "framerate.h"
#include "def/audio.h"
#include "def/shrink_window.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_kaleido_setup.h"
#include "def/z_play.h"
#include "def/z_view.h"

s16 sKaleidoSetupKscpPos0[] = {PAUSE_QUEST, PAUSE_EQUIP, PAUSE_ITEM, PAUSE_MAP};
s16 sKaleidoSetupKscpPos1[] = {PAUSE_MAP, PAUSE_QUEST, PAUSE_EQUIP, PAUSE_ITEM};

void KaleidoSetup_Update(GlobalContext* globalCtx)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	Input* input = &globalCtx->state.input[0];

	if(pauseCtx->state == 0 && pauseCtx->debugState == 0 && globalCtx->gameOverCtx.state == GAMEOVER_INACTIVE && globalCtx->sceneLoadFlag == 0 && globalCtx->transitionMode == 0 && gSaveContext.cutsceneIndex < 0xFFF0 &&
	   gSaveContext.nextCutsceneIndex < 0xFFF0 && !Gameplay_InCsMode(globalCtx) && globalCtx->shootingGalleryStatus <= 1 && gSaveContext.unk_13F0 != 8 && gSaveContext.unk_13F0 != 9 &&
	   (globalCtx->sceneNum != SCENE_BOWLING || !Flags_GetSwitch(globalCtx, 0x38)))
	{
		if(CHECK_BTN_ALL(input->cur.button, BTN_L) && CHECK_BTN_ALL(input->press.button, BTN_CUP))
		{
			if(BREG(0))
			{
				pauseCtx->debugState = 3;
			}
		}
		else if(CHECK_BTN_ALL(input->press.button, BTN_START))
		{
			gSaveContext.unk_13EE = gSaveContext.unk_13EA;

			PAUSE_LEFT_CARET = -175;
			PAUSE_RIGHT_CARET = 155;

			pauseCtx->rotAccum = 0;
			pauseCtx->unk_1E4 = 1;

			if(ZREG(48) == 0)
			{
				KaleidoScope_SetPage(globalCtx, sKaleidoSetupKscpPos0[pauseCtx->pageIndex]);
			}
			else
			{
				KaleidoScope_SetPage(globalCtx, sKaleidoSetupKscpPos1[pauseCtx->pageIndex]);
			}

			pauseCtx->state = 1;
		}

		if(pauseCtx->state == 1)
		{
			WREG(2) = -6240;
			framerate_set_profile(PROFILE_PAUSE);

			if(ShrinkWindow_GetVal())
			{
				ShrinkWindow_SetVal(0);
			}

			Audio_PlayKaleido(1);
		}
	}
}

void KaleidoSetup_Init(GlobalContext* globalCtx)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;

	pauseCtx->state = 0;
	pauseCtx->debugState = 0;
	pauseCtx->alpha = 0;
	pauseCtx->rotAccum = 0;
	pauseCtx->unk_1E4 = 0;
	KaleidoScope_SetPage(globalCtx, PAUSE_ITEM);

	pauseCtx->radius = 93.6f;
	pauseCtx->eye.pos.x = pauseCtx->eye.pos.y = 0.0f;
	pauseCtx->unk_204 = -314.0f;

	pauseCtx->infoPanelOffsetY = -40;
	pauseCtx->nameDisplayTimer = 0;
	pauseCtx->nameColorSet = 0;
	pauseCtx->cursorColorSet = 4;
	pauseCtx->ocarinaSongIdx = -1;
	pauseCtx->cursorSpecialPos = 0;

	View_Init(&pauseCtx->view, globalCtx->state.gfxCtx);
}

void KaleidoSetup_Destroy(GlobalContext* globalCtx)
{
}
