#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_OKARINA_EFFECT_Z_EN_OKARINA_EFFECT_C
#include "actor_common.h"
/*
 * File: z_en_okarina_effect.c
 * Overlay: ovl_En_Okarina_Effect
 * Description: Manages the storm created when playing Song of Storms
 */

#include "vt.h"
#include "z_en_okarina_effect.h"
#include "z_kankyo.h"
#include "def/audio.h"
#include "def/audio_command.h"
#include "def/environment_flags.h"
#include "def/z_actor.h"
#include "def/z_kankyo.h"
#include "def/z_play.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_25)

void EnOkarinaEffect_Init(Actor* thisx, GlobalContext* globalCtx);
void EnOkarinaEffect_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnOkarinaEffect_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnOkarinaEffect_Update(Actor* thisx, GlobalContext* globalCtx);

void EnOkarinaEffect_TriggerStorm(EnOkarinaEffect* pthis, GlobalContext* globalCtx);
void EnOkarinaEffect_ManageStorm(EnOkarinaEffect* pthis, GlobalContext* globalCtx);

ActorInit En_Okarina_Effect_InitVars = {
    ACTOR_EN_OKARINA_EFFECT, ACTORCAT_ITEMACTION, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(EnOkarinaEffect), (ActorFunc)EnOkarinaEffect_Init, (ActorFunc)EnOkarinaEffect_Destroy, (ActorFunc)EnOkarinaEffect_Update, NULL, (ActorFunc)EnOkarinaEffect_Reset,
};

void EnOkarinaEffect_SetupAction(EnOkarinaEffect* pthis, EnOkarinaEffectActionFunc actionFunc)
{
	pthis->actionFunc = actionFunc;
}

void EnOkarinaEffect_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	EnOkarinaEffect* pthis = (EnOkarinaEffect*)thisx;

	globalCtx->envCtx.unk_F2[0] = 0;
	if((gWeatherMode != 4) && (gWeatherMode != 5) && (globalCtx->envCtx.gloomySkyMode == 1))
	{
		globalCtx->envCtx.gloomySkyMode = 2; // end gloomy sky
		func_80077684(globalCtx);
	}
	globalCtx->envCtx.lightningMode = LIGHTNING_MODE_LAST;
}

void EnOkarinaEffect_Init(Actor* thisx, GlobalContext* globalCtx)
{
	EnOkarinaEffect* pthis = (EnOkarinaEffect*)thisx;

	osSyncPrintf("\n\n");
	// "Ocarina Storm Effect"
	osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ オカリナあらし効果ビカビカビカ〜 ☆☆☆☆☆ \n" VT_RST);
	osSyncPrintf("\n\n");
	if(globalCtx->envCtx.unk_EE[1] != 0)
	{
		Actor_Kill(&pthis->actor);
	}
	EnOkarinaEffect_SetupAction(pthis, EnOkarinaEffect_TriggerStorm);
}

void EnOkarinaEffect_TriggerStorm(EnOkarinaEffect* pthis, GlobalContext* globalCtx)
{
	pthis->timer = 400;		     // 20 seconds
	globalCtx->envCtx.unk_F2[0] = 20;    // rain intensity target
	globalCtx->envCtx.gloomySkyMode = 1; // start gloomy sky
	if((gWeatherMode != 0) || globalCtx->envCtx.unk_17 != 0)
	{
		globalCtx->envCtx.skyState = 1;
	}
	globalCtx->envCtx.lightningMode = LIGHTNING_MODE_ON;
	func_80077624(globalCtx);
	EnOkarinaEffect_SetupAction(pthis, EnOkarinaEffect_ManageStorm);
}

void EnOkarinaEffect_ManageStorm(EnOkarinaEffect* pthis, GlobalContext* globalCtx)
{
	Flags_UnsetEnv(globalCtx, 5); // clear storms env flag
	if(((globalCtx->pauseCtx.state == 0) && (globalCtx->gameOverCtx.state == GAMEOVER_INACTIVE) && (globalCtx->msgCtx.msgLength == 0) && (!FrameAdvance_IsEnabled(globalCtx)) && ((globalCtx->transitionMode == 0) || (gSaveContext.gameMode != 0))) ||
	   (pthis->timer >= 250))
	{
		if(globalCtx->envCtx.indoors || globalCtx->envCtx.unk_1F != 1)
		{
			pthis->timer--;
		}
		osSyncPrintf("\nthis->timer=[%d]", pthis->timer);
		if(pthis->timer == 308)
		{
			osSyncPrintf("\n\n\n豆よ のびろ 指定\n\n\n"); // "Let's grow some beans"
			Flags_SetEnv(globalCtx, 5);		      // set storms env flag
		}
	}

	if(D_8011FB38 != 0)
	{
		pthis->timer = 0;
	}

	if(pthis->timer == 0)
	{
		globalCtx->envCtx.unk_F2[0] = 0;
		if(globalCtx->csCtx.state == CS_STATE_IDLE)
		{
			func_80077684(globalCtx);
		}
		else if(Audio_GetSequenceBeingPlayed(SEQ_PLAYER_BGM_MAIN) == NA_BGM_NATURE_AMBIENCE)
		{
			func_800F6D58(0xF, 1, 0);
			func_800F6D58(0xE, 1, 0);
		}
		osSyncPrintf("\n\n\nE_wether_flg=[%d]", gWeatherMode);
		osSyncPrintf("\nrain_evt_trg=[%d]\n\n", globalCtx->envCtx.gloomySkyMode);
		if(gWeatherMode == 0 && (globalCtx->envCtx.gloomySkyMode == 1))
		{
			globalCtx->envCtx.gloomySkyMode = 2; // end gloomy sky
		}
		else
		{
			globalCtx->envCtx.gloomySkyMode = 0;
			globalCtx->envCtx.skyState = 0;
		}
		globalCtx->envCtx.lightningMode = LIGHTNING_MODE_LAST;
		Actor_Kill(&pthis->actor);
	}
}

void EnOkarinaEffect_Update(Actor* thisx, GlobalContext* globalCtx)
{
	EnOkarinaEffect* pthis = (EnOkarinaEffect*)thisx;

	pthis->actionFunc(pthis, globalCtx);
}

void EnOkarinaEffect_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	En_Okarina_Effect_InitVars = {
	    ACTOR_EN_OKARINA_EFFECT, ACTORCAT_ITEMACTION, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(EnOkarinaEffect), (ActorFunc)EnOkarinaEffect_Init, (ActorFunc)EnOkarinaEffect_Destroy, (ActorFunc)EnOkarinaEffect_Update, NULL, (ActorFunc)EnOkarinaEffect_Reset,
	};
}
