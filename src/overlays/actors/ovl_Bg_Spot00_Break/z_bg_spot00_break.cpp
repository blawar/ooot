#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT00_BREAK_Z_BG_SPOT00_BREAK_C
#include "actor_common.h"
/*
 * File: z_bg_spot00_break.c
 * Overlay: ovl_Bg_Spot00_Break
 * Description: Broken drawbridge in Hyrule Field.
 */

#include "z_bg_spot00_break.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "objects/object_spot00_break/object_spot00_break.h"

#define FLAGS 0

void BgSpot00Break_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot00Break_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot00Break_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot00Break_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot00Break_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Bg_Spot00_Break_InitVars = {
    ACTOR_BG_SPOT00_BREAK, ACTORCAT_PROP, FLAGS, OBJECT_SPOT00_BREAK, ACTOR_FACTORY(BgSpot00Break), (ActorFunc)BgSpot00Break_Init, (ActorFunc)BgSpot00Break_Destroy, (ActorFunc)BgSpot00Break_Update, (ActorFunc)BgSpot00Break_Draw, (ActorFunc)BgSpot00Break_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

void BgSpot00Break_Init(Actor* thisx, GlobalContext* globalCtx)
{
	BgSpot00Break* pthis = (BgSpot00Break*)thisx;
	s32 pad;
	CollisionHeader* colHeader = NULL;

	Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
	DynaPolyActor_Init(&pthis->dyna, DPM_UNK);

	if(pthis->dyna.actor.params == 1)
	{
		CollisionHeader_GetVirtual(&gBarbedWireFenceCol, &colHeader);
	}
	else
	{
		CollisionHeader_GetVirtual(&gBrokenDrawbridgeCol, &colHeader);
	}

	pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

	if(!LINK_IS_ADULT)
	{
		Actor_Kill(&pthis->dyna.actor);
	}
}

void BgSpot00Break_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	BgSpot00Break* pthis = (BgSpot00Break*)thisx;

	DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgSpot00Break_Update(Actor* thisx, GlobalContext* globalCtx)
{
}

void BgSpot00Break_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	BgSpot00Break* pthis = (BgSpot00Break*)thisx;

	if(pthis->dyna.actor.params == 1)
	{
		Gfx_DrawDListOpa(globalCtx, gBarbedWireFenceDL);
	}
	else
	{
		Gfx_DrawDListOpa(globalCtx, gBrokenDrawbridgeDL);
	}
}

void BgSpot00Break_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Bg_Spot00_Break_InitVars = {
	    ACTOR_BG_SPOT00_BREAK,	    ACTORCAT_PROP, FLAGS, OBJECT_SPOT00_BREAK, ACTOR_FACTORY(BgSpot00Break), (ActorFunc)BgSpot00Break_Init, (ActorFunc)BgSpot00Break_Destroy, (ActorFunc)BgSpot00Break_Update, (ActorFunc)BgSpot00Break_Draw,
	    (ActorFunc)BgSpot00Break_Reset,
	};
}
