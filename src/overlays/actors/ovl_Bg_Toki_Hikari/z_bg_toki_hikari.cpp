#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_TOKI_HIKARI_Z_BG_TOKI_HIKARI_C
#include "actor_common.h"
/*
 * File: z_bg_toki_hikari.c
 * Overlay: ovl_Toki_Hikari
 * Description: Temple of Time Windows
 */

#include "z_bg_toki_hikari.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "objects/object_toki_objects/object_toki_objects.h"

#define FLAGS ACTOR_FLAG_5

void BgTokiHikari_Init(Actor* thisx, GlobalContext* globalCtx);
void BgTokiHikari_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgTokiHikari_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgTokiHikari_Update(Actor* thisx, GlobalContext* globalCtx);
void BgTokiHikari_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgTokiHikari_DoNothing(BgTokiHikari* pthis, GlobalContext* globalCtx);
void func_808BA018(BgTokiHikari* pthis, GlobalContext* globalCtx);
void func_808BA204(BgTokiHikari* pthis, GlobalContext* globalCtx);
void func_808BA22C(BgTokiHikari* pthis, GlobalContext* globalCtx);
void func_808BA274(BgTokiHikari* pthis, GlobalContext* globalCtx);
void func_808BA2CC(BgTokiHikari* pthis, GlobalContext* globalCtx);

ActorInit Bg_Toki_Hikari_InitVars = {
    ACTOR_BG_TOKI_HIKARI, ACTORCAT_BG, FLAGS, OBJECT_TOKI_OBJECTS, ACTOR_FACTORY(BgTokiHikari), (ActorFunc)BgTokiHikari_Init, (ActorFunc)BgTokiHikari_Destroy, (ActorFunc)BgTokiHikari_Update, (ActorFunc)BgTokiHikari_Draw, (ActorFunc)BgTokiHikari_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

void BgTokiHikari_Init(Actor* thisx, GlobalContext* globalCtx)
{
	BgTokiHikari* pthis = (BgTokiHikari*)thisx;

	switch(pthis->actor.params)
	{
		case 0:
			Actor_ProcessInitChain(&pthis->actor, sInitChain);
			pthis->actionFunc = BgTokiHikari_DoNothing;
			break;
		case 1:
			if(!(gSaveContext.eventChkInf[4] & 0x800))
			{
				pthis->actionFunc = func_808BA204;
				pthis->unk_14C = 0.0f;
			}
			else
			{
				Actor_Kill(&pthis->actor);
			}
			break;
	}
}

void BgTokiHikari_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
}

void BgTokiHikari_DoNothing(BgTokiHikari* pthis, GlobalContext* globalCtx)
{
}

void BgTokiHikari_Update(Actor* thisx, GlobalContext* globalCtx)
{
	BgTokiHikari* pthis = (BgTokiHikari*)thisx;

	pthis->actionFunc(pthis, globalCtx);
}

void BgTokiHikari_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	BgTokiHikari* pthis = (BgTokiHikari*)thisx;

	switch(pthis->actor.params)
	{
		case 0:
			func_808BA018(pthis, globalCtx);
			break;
		case 1:
			func_808BA2CC(pthis, globalCtx);
			break;
	}
}

void func_808BA018(BgTokiHikari* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_bg_toki_hikari.c", 246);
	func_80093D18(globalCtx->gfxCtx);
	gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_bg_toki_hikari.c", 252), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	if(LINK_IS_ADULT)
	{
		gSPDisplayList(POLY_OPA_DISP++, object_toki_objects_DL_008190);
	}
	else
	{
		gSPDisplayList(POLY_OPA_DISP++, object_toki_objects_DL_007E20);
		func_80093D84(globalCtx->gfxCtx);
		gSPSegment(POLY_XLU_DISP++, 8, Gfx_TexScroll(globalCtx->gfxCtx, 0, globalCtx->gameplayFrames % 128, 64, 32));

		gSPSegment(POLY_XLU_DISP++, 9, Gfx_TexScroll(globalCtx->gfxCtx, 0, globalCtx->gameplayFrames % 128, 64, 32));

		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_bg_toki_hikari.c", 278), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

		gSPDisplayList(POLY_XLU_DISP++, object_toki_objects_DL_007EE0);
	}
	CLOSE_DISPS(globalCtx->gfxCtx, "../z_bg_toki_hikari.c", 284);
}

void func_808BA204(BgTokiHikari* pthis, GlobalContext* globalCtx)
{
	if(globalCtx->roomCtx.unk_74[1] != 0)
	{
		pthis->actionFunc = func_808BA22C;
	}
}

void func_808BA22C(BgTokiHikari* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_14C < 1.0f)
	{
		pthis->unk_14C += 0.05f;
	}
	else
	{
		pthis->unk_14C = 1.0f;
		pthis->actionFunc = func_808BA274;
	}
}

void func_808BA274(BgTokiHikari* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_14C > 0.2f)
	{
		pthis->unk_14C -= 0.025f;
	}
	else
	{
		pthis->unk_14C = 0.0f;
		Actor_Kill(&pthis->actor);
	}
}

void func_808BA2CC(BgTokiHikari* pthis, GlobalContext* globalCtx)
{
	s32 pad[2];

	OPEN_DISPS(globalCtx->gfxCtx, "../z_bg_toki_hikari.c", 350);
	Matrix_Translate(0.0f, 276.0f, 1122.0f, MTXMODE_NEW);
	Matrix_Scale(0.32f, 0.32f, pthis->unk_14C * 7.0f, MTXMODE_APPLY);
	Matrix_RotateZ(M_PI, MTXMODE_APPLY);
	func_80093D18(globalCtx->gfxCtx);
	Matrix_Push();
	gDPPipeSync(POLY_XLU_DISP++);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, pthis->unk_14C * 255.0f, (u8)(155.0f * pthis->unk_14C) + 100, pthis->unk_14C * 255.0f, pthis->unk_14C * 255.0f);

	gDPSetEnvColor(POLY_XLU_DISP++, (u8)(pthis->unk_14C * 155.0f) + 100, (u8)(255.0f * pthis->unk_14C), 0, 128);

	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_bg_toki_hikari.c", 382), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, -2 * (globalCtx->gameplayFrames & 0x7F), 0, 0x20, 0x40, 1, (globalCtx->gameplayFrames & 0x7F) * 4, 0, 0x20, 0x40));

	gSPDisplayList(POLY_XLU_DISP++, object_toki_objects_DL_000880);
	Matrix_Pop();
	Matrix_Push();
	gDPPipeSync(POLY_XLU_DISP++);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)(pthis->unk_14C * 200.0f));

	gDPSetEnvColor(POLY_XLU_DISP++, (u8)(pthis->unk_14C * 255.0f), (u8)(pthis->unk_14C * 255.0f), (u8)(pthis->unk_14C * 255.0f), (u8)(200.0f * pthis->unk_14C));

	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_bg_toki_hikari.c", 415), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	gSPDisplayList(POLY_XLU_DISP++, object_toki_objects_DL_0009C0);
	Matrix_Pop();
	Matrix_Push();
	gDPPipeSync(POLY_XLU_DISP++);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)(pthis->unk_14C * 200.0f));

	gDPSetEnvColor(POLY_XLU_DISP++, (u8)(pthis->unk_14C * 255.0f), (u8)(pthis->unk_14C * 255.0f), (u8)(pthis->unk_14C * 255.0f), (u8)(200.0f * pthis->unk_14C));

	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_bg_toki_hikari.c", 437), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	gSPDisplayList(POLY_XLU_DISP++, &object_toki_objects_DL_0009C0[10]);
	Matrix_Pop();
	CLOSE_DISPS(globalCtx->gfxCtx, "../z_bg_toki_hikari.c", 443);
}

void BgTokiHikari_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Bg_Toki_Hikari_InitVars = {
	    ACTOR_BG_TOKI_HIKARI, ACTORCAT_BG, FLAGS, OBJECT_TOKI_OBJECTS, ACTOR_FACTORY(BgTokiHikari), (ActorFunc)BgTokiHikari_Init, (ActorFunc)BgTokiHikari_Destroy, (ActorFunc)BgTokiHikari_Update, (ActorFunc)BgTokiHikari_Draw, (ActorFunc)BgTokiHikari_Reset,
	};
}
