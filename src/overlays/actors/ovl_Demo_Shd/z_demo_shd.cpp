#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DEMO_SHD_Z_DEMO_SHD_C
#include "actor_common.h"
/*
 * File: z_demo_shd.c
 * Overlay: Demo_Shd
 * Description: Bongo Bongo's Shadow
 */

#include "z_demo_shd.h"
#include "def/audio.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void DemoShd_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoShd_Reset(Actor* pthisx, GlobalContext* globalCtx);
void DemoShd_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoShd_Update(Actor* thisx, GlobalContext* globalCtx);
void DemoShd_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80991298(DemoShd* pthis, GlobalContext* globalCtx);

ActorInit Demo_Shd_InitVars = {
    ACTOR_DEMO_SHD, ACTORCAT_ITEMACTION, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(DemoShd), (ActorFunc)DemoShd_Init, (ActorFunc)DemoShd_Destroy, (ActorFunc)DemoShd_Update, (ActorFunc)DemoShd_Draw, (ActorFunc)DemoShd_Reset,
};

#include "overlays/ovl_Demo_Shd/ovl_Demo_Shd.cpp"

void DemoShd_SetupAction(DemoShd* pthis, DemoShdActionFunc actionFunc)
{
	pthis->actionFunc = actionFunc;
}

void DemoShd_Init(Actor* thisx, GlobalContext* globalCtx)
{
	DemoShd* pthis = (DemoShd*)thisx;

	pthis->unk_14C = 0;
	DemoShd_SetupAction(pthis, func_80991298);
	Actor_SetScale(&pthis->actor, 0.4f);
	pthis->actor.world.pos.y = 0.0f;
	pthis->actor.world.pos.x = 0.0f;
}

void DemoShd_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
}

void func_80991298(DemoShd* pthis, GlobalContext* globalCtx)
{
	if((globalCtx->csCtx.state != CS_STATE_IDLE && globalCtx->csCtx.npcActions[0] != NULL) || (globalCtx->csCtx.state != CS_STATE_IDLE && globalCtx->csCtx.npcActions[1] != NULL))
	{
		if(globalCtx->csCtx.frames == 800)
		{
			func_800F3F3C(9);
		}
		if(globalCtx->csCtx.frames == 1069)
		{
			func_800F3F3C(8);
		}
	}

	if(globalCtx->csCtx.state != CS_STATE_IDLE)
	{
		CsCmdActorAction* npcAction0 = globalCtx->csCtx.npcActions[0];

		if(npcAction0 != NULL)
		{
			if(npcAction0->action == 2)
			{
				if(!(pthis->unk_14C & 1))
				{
					pthis->unk_14E = npcAction0->startPos.x;
				}
				pthis->unk_14C |= 1;
			}
			else
			{
				pthis->unk_14C &= ~1;
			}
		}
	}

	if(globalCtx->csCtx.state != CS_STATE_IDLE)
	{
		CsCmdActorAction* npcAction1 = globalCtx->csCtx.npcActions[1];

		if(npcAction1 != NULL)
		{
			if(npcAction1->action == 2)
			{
				if(!(pthis->unk_14C & 2))
				{
					pthis->unk_14E = npcAction1->startPos.x;
				}
				pthis->unk_14C |= 2;
			}
			else
			{
				pthis->unk_14C &= ~2;
			}
		}
	}

	pthis->unk_14E++;
}

void DemoShd_Update(Actor* thisx, GlobalContext* globalCtx)
{
	DemoShd* pthis = (DemoShd*)thisx;

	pthis->actionFunc(pthis, globalCtx);
}

void DemoShd_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	DemoShd* pthis = (DemoShd*)thisx;
	s32 pad;
	u32 unk_14E = pthis->unk_14E;

	if(1)
	{
	} // Necessary to match, can be anywhere in the function

	OPEN_DISPS(globalCtx->gfxCtx, "../z_demo_shd.c", 726);

	func_80093D84(globalCtx->gfxCtx);

	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_demo_shd.c", 729), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPDisplayList(POLY_XLU_DISP++, D_809932D0);

	if(pthis->unk_14C & 1)
	{
		gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 0, 0x3FF - ((unk_14E * 5) & 0x3FF), 16, 256, 1, 0, 255 - ((unk_14E * 5) & 255), 32, 32));
		gSPDisplayList(POLY_XLU_DISP++, D_80993390);
	}
	else if(pthis->unk_14C & 2)
	{
		gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 0, 0x3FF - ((unk_14E * 5) & 0x3FF), 16, 256, 1, 0, 255 - ((unk_14E * 5) & 255), 32, 32));
		gSPDisplayList(POLY_XLU_DISP++, D_809934B8);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_demo_shd.c", 762);
}

void DemoShd_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Demo_Shd_InitVars = {
	    ACTOR_DEMO_SHD, ACTORCAT_ITEMACTION, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(DemoShd), (ActorFunc)DemoShd_Init, (ActorFunc)DemoShd_Destroy, (ActorFunc)DemoShd_Update, (ActorFunc)DemoShd_Draw, (ActorFunc)DemoShd_Reset,
	};
}
