#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT11_OASIS_Z_BG_SPOT11_OASIS_C
#include "actor_common.h"
/*
 * File: z_bg_spot11_oasis.c
 * Overlay: ovl_Bg_Spot11_Oasis
 * Description: Refilling Oasis (Desert Colossus)
 */

#include "overlays/actors/ovl_En_Elf/z_en_elf.h"
#include "z_bg_spot11_oasis.h"
#include "def/environment_flags.h"
#include "def/random.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "objects/object_spot11_obj/object_spot11_obj.h"

#define FLAGS ACTOR_FLAG_4

void BgSpot11Oasis_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot11Oasis_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot11Oasis_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot11Oasis_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_808B2970(BgSpot11Oasis* pthis);
void func_808B2980(BgSpot11Oasis* pthis, GlobalContext* globalCtx);
void func_808B29E0(BgSpot11Oasis* pthis);
void func_808B29F0(BgSpot11Oasis* pthis, GlobalContext* globalCtx);
void func_808B2AA8(BgSpot11Oasis* pthis);
void func_808B2AB8(BgSpot11Oasis* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot11_Oasis_InitVars = {
    ACTOR_BG_SPOT11_OASIS, ACTORCAT_BG, FLAGS, OBJECT_SPOT11_OBJ, sizeof(BgSpot11Oasis), (ActorFunc)BgSpot11Oasis_Init, (ActorFunc)Actor_Noop, (ActorFunc)BgSpot11Oasis_Update, NULL, (ActorFunc)BgSpot11Oasis_Reset,
};

static s16 D_808B2E10[][2] = {
    {1260, 2040}, {1259, 1947}, {1135, 1860}, {1087, 1912}, {1173, 2044},
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F(scale, 1, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 3000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

static Vec3f D_808B2E34[] = {
    {0.0f, -100.0f, 0.0f}, {100.0f, -80.0f, -50.0f}, {-50.0f, -80.0f, -100.0f}, {-75.0f, -90.0f, 90.0f}, {30.0f, -100.0f, 40.0f},
};

void func_808B27F0(GlobalContext* globalCtx, s16 waterSurface)
{
	WaterBox* waterBox = &globalCtx->colCtx.colHeader->waterBoxes[0];

	waterBox->ySurface = waterSurface;
}

s32 func_808B280C(GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	Vec3f sp58;
	Vec3f sp4C;
	Vec3f sp40;
	s32 i;

	sp58.x = D_808B2E10[0][0];
	sp58.z = D_808B2E10[0][1];
	sp58.y = 0.0f;

	sp4C.y = 0.0f;
	sp40.y = 0.0f;

	for(i = 1; i < ARRAY_COUNT(D_808B2E10) - 1; i++)
	{
		sp4C.x = D_808B2E10[i][0];
		sp4C.z = D_808B2E10[i][1];
		sp40.x = D_808B2E10[i + 1][0];
		sp40.z = D_808B2E10[i + 1][1];
		if(Math3D_TriChkPointParaYSlopedY(&sp58, &sp4C, &sp40, player->actor.world.pos.z, player->actor.world.pos.x))
		{
			return 1;
		}
	}
	return 0;
}

void BgSpot11Oasis_Init(Actor* thisx, GlobalContext* globalCtx)
{
	BgSpot11Oasis* pthis = (BgSpot11Oasis*)thisx;

	Actor_ProcessInitChain(&pthis->actor, sInitChain);
	func_808B2970(pthis);
	pthis->actor.world.pos.y = -100.0f;
	func_808B27F0(globalCtx, -100);
}

void func_808B2970(BgSpot11Oasis* pthis)
{
	pthis->actionFunc = func_808B2980;
}

void func_808B2980(BgSpot11Oasis* pthis, GlobalContext* globalCtx)
{
	if(Flags_GetEnv(globalCtx, 5) && func_808B280C(globalCtx))
	{
		OnePointCutscene_Init(globalCtx, 4150, -99, &pthis->actor, MAIN_CAM);
		func_808B29E0(pthis);
	}
}

void func_808B29E0(BgSpot11Oasis* pthis)
{
	pthis->actionFunc = func_808B29F0;
}

void func_808B29F0(BgSpot11Oasis* pthis, GlobalContext* globalCtx)
{
	if(Math_StepToF(&pthis->actor.world.pos.y, 0.0f, 0.7f))
	{
		func_808B2AA8(pthis);
		Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ELF, pthis->actor.world.pos.x, pthis->actor.world.pos.y + 40.0f, pthis->actor.world.pos.z, 0, 0, 0, FAIRY_SPAWNER);
		Common_PlaySfx(NA_SE_SY_CORRECT_CHIME);
	}
	func_808B27F0(globalCtx, pthis->actor.world.pos.y);
}

void func_808B2AA8(BgSpot11Oasis* pthis)
{
	pthis->actionFunc = func_808B2AB8;
}

void func_808B2AB8(BgSpot11Oasis* pthis, GlobalContext* globalCtx)
{
}

void BgSpot11Oasis_Update(Actor* thisx, GlobalContext* globalCtx)
{
	BgSpot11Oasis* pthis = (BgSpot11Oasis*)thisx;
	s32 pad;
	u32 gameplayFrames;
	Vec3f sp30;

	pthis->actionFunc(pthis, globalCtx);
	if(pthis->actionFunc == func_808B2980)
	{
		pthis->actor.draw = NULL;
		return;
	}
	pthis->actor.draw = BgSpot11Oasis_Draw;
	if(pthis->unk_150 && (pthis->actor.projectedPos.z < 400.0f) && (pthis->actor.projectedPos.z > -40.0f))
	{
		gameplayFrames = globalCtx->gameplayFrames;
		if(gameplayFrames & 4)
		{
			Math_Vec3f_Sum(&pthis->actor.world.pos, &D_808B2E34[pthis->unk_151], &sp30);
			EffectSsBubble_Spawn(globalCtx, &sp30, 0.0f, 15.0f, 50.0f, (Rand_ZeroOne() * 0.12f) + 0.02f);
			if(Rand_ZeroOne() < 0.3f)
			{
				pthis->unk_151 = Rand_ZeroOne() * 4.9f;
			}
		}
	}
	else
	{
		pthis->unk_150 = 1;
	}
}

void BgSpot11Oasis_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	u32 gameplayFrames = globalCtx->gameplayFrames;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_bg_spot11_oasis.c", 327);
	func_80093D84(globalCtx->gfxCtx);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_bg_spot11_oasis.c", 331), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 127 - (gameplayFrames % 128), (gameplayFrames * 1) % 128, 32, 32, 1, gameplayFrames % 128, (gameplayFrames * 1) % 128, 32, 32));
	gSPDisplayList(POLY_XLU_DISP++, gDesertColossusOasisDL);
	CLOSE_DISPS(globalCtx->gfxCtx, "../z_bg_spot11_oasis.c", 346);
}

void BgSpot11Oasis_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Bg_Spot11_Oasis_InitVars = {
	    ACTOR_BG_SPOT11_OASIS, ACTORCAT_BG, FLAGS, OBJECT_SPOT11_OBJ, sizeof(BgSpot11Oasis), (ActorFunc)BgSpot11Oasis_Init, (ActorFunc)Actor_Noop, (ActorFunc)BgSpot11Oasis_Update, NULL, (ActorFunc)BgSpot11Oasis_Reset,
	};
}
