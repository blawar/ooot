#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_ICE_OBJECTS_Z_BG_ICE_OBJECTS_C
#include "actor_common.h"
/*
 * File: z_bg_ice_objects.c
 * Overlay: ovl_Bg_Ice_Objects
 * Description: Pushable ice block (Ice Cavern)
 */

#include "z_bg_ice_objects.h"
#include "def/code_80043480.h"
#include "def/random.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "objects/object_ice_objects/object_ice_objects.h"

#define FLAGS 0

void BgIceObjects_Init(Actor* thisx, GlobalContext* globalCtx);
void BgIceObjects_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgIceObjects_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgIceObjects_Update(Actor* thisx, GlobalContext* globalCtx);
void BgIceObjects_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgIceObjects_Idle(BgIceObjects* pthis, GlobalContext* globalCtx);
void BgIceObjects_Slide(BgIceObjects* pthis, GlobalContext* globalCtx);
void BgIceObjects_Reset(BgIceObjects* pthis, GlobalContext* globalCtx);
void BgIceObjects_Stuck(BgIceObjects* pthis, GlobalContext* globalCtx);

static Color_RGBA8 sWhite = {250, 250, 250, 255};
static Color_RGBA8 sGray = {180, 180, 180, 255};
static Vec3f sZeroVec = {0.0f, 0.0f, 0.0f};

ActorInit Bg_Ice_Objects_InitVars = {
    ACTOR_BG_ICE_OBJECTS, ACTORCAT_PROP, FLAGS, OBJECT_ICE_OBJECTS, sizeof(BgIceObjects), (ActorFunc)BgIceObjects_Init, (ActorFunc)BgIceObjects_Destroy, (ActorFunc)BgIceObjects_Update, (ActorFunc)BgIceObjects_Draw, (ActorFunc)BgIceObjects_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgIceObjects_Init(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	BgIceObjects* pthis = (BgIceObjects*)thisx;
	CollisionHeader* colHeader = NULL;

	Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
	DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
	CollisionHeader_GetVirtual(&object_ice_objects_Col_0003F0, &colHeader);
	Math_Vec3f_Copy(&pthis->targetPos, &pthis->dyna.actor.home.pos);
	pthis->actionFunc = BgIceObjects_Idle;
	pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
	pthis->dyna.actor.params = 0;
}

void BgIceObjects_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	BgIceObjects* pthis = (BgIceObjects*)thisx;

	DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

static s16 sXStarts[] = {
    -1060, -1200, -1240, -1387, -1580, -1680, -1780,
};
static s16 sZStarts[] = {
    -580, -660, -780, -820, -860, -900, -1087,
};
static s16 sZStops[7][2] = {
    {-580, -1087}, {-780, -1260}, {-340, -820}, {-260, -1260}, {-340, -860}, {-660, -1260}, {-340, -740},
};
static s16 sXStops[7][2] = {
    {-860, -1580}, {-1240, -1780}, {-860, -1680}, {-860, -1680}, {-1387, -1680}, {-860, -1200}, {-860, -1800},
};

/*
 * Checks which of the eight possible x and z positions the block is at,
 * defaulting to the maximum x wall or minimum z wall. Each x and z position
 * has only one possible wall or pit on each side of it.
 */
void BgIceObjects_SetNextTarget(BgIceObjects* pthis, GlobalContext* globalCtx)
{
	s16 x16;
	s16 z16 = 0; // needed to match
	s32 i;

	if((pthis->dyna.unk_158 == 0) || (pthis->dyna.unk_158 == -0x8000))
	{
		x16 = pthis->dyna.actor.world.pos.x;
		for(i = 0; i < 7; i++)
		{
			if(x16 == sXStarts[i])
			{
				z16 = (pthis->dyna.unk_158 == 0) ? sZStops[i][0] : sZStops[i][1];
				pthis->targetPos.z = z16;
				return;
			}
		}
		pthis->targetPos.z = (pthis->dyna.unk_158 == 0) ? -340 : -1260;
	}
	else
	{
		z16 = pthis->dyna.actor.world.pos.z;
		for(i = 0; i < 7; i++)
		{
			if(z16 == sZStarts[i])
			{
				x16 = (pthis->dyna.unk_158 == 0x4000) ? sXStops[i][0] : sXStops[i][1];
				pthis->targetPos.x = x16;
				return;
			}
		}
		pthis->targetPos.x = (pthis->dyna.unk_158 == 0x4000) ? -860 : -1780;
	}
}

/*
 * Checks if the block has fallen into any of the pits.
 */
void BgIceObjects_CheckPits(BgIceObjects* pthis, GlobalContext* globalCtx)
{
	Actor* thisx = &pthis->dyna.actor;

	if((thisx->velocity.y > 0.0f) || ((thisx->world.pos.x <= -1660.0f) && (thisx->world.pos.z <= -1060.0f)) || ((thisx->world.pos.x <= -1580.0f) && (thisx->world.pos.z >= -420.0f)) ||
	   ((thisx->world.pos.x >= -980.0f) && (thisx->world.pos.z <= -1180.0f)) || ((thisx->world.pos.x >= -860.0f) && (thisx->world.pos.z >= -700.0f)))
	{
		thisx->velocity.y += 1.0f;
		if(Math_StepToF(&thisx->world.pos.y, -300.0f, thisx->velocity.y))
		{
			thisx->velocity.y = 0.0f;
			thisx->world.pos.x = thisx->home.pos.x;
			thisx->world.pos.y = thisx->home.pos.y - 60.0f;
			thisx->world.pos.z = thisx->home.pos.z;
			if(thisx->params != 0)
			{
				func_8002DF54(globalCtx, thisx, 7);
			}
			pthis->actionFunc = BgIceObjects_Reset;
		}
	}
}

void BgIceObjects_Idle(BgIceObjects* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	Actor* thisx = &pthis->dyna.actor;

	if(pthis->dyna.unk_150 != 0.0f)
	{
		player->stateFlags2 &= ~PLAYER_STATE2_4;
		if((pthis->dyna.unk_150 > 0.0f) && !Player_InCsMode(globalCtx))
		{
			BgIceObjects_SetNextTarget(pthis, globalCtx);
			if(Actor_WorldDistXZToPoint(thisx, &pthis->targetPos) > 1.0f)
			{
				thisx->flags |= ACTOR_FLAG_4;
				func_8002DF54(globalCtx, thisx, 8);
				thisx->params = 1;
				pthis->actionFunc = BgIceObjects_Slide;
			}
		}
		pthis->dyna.unk_150 = 0.0f;
	}
	if(thisx->velocity.y > 0.0f)
	{
		BgIceObjects_CheckPits(pthis, globalCtx);
	}
}

void BgIceObjects_Slide(BgIceObjects* pthis, GlobalContext* globalCtx)
{
	s32 atTarget;
	Vec3f pos;
	Vec3f velocity;
	f32 spread;
	Actor* thisx = &pthis->dyna.actor;

	Math_StepToF(&thisx->speedXZ, 10.0f, 0.5f);
	atTarget = Math_StepToF(&thisx->world.pos.x, pthis->targetPos.x, thisx->speedXZ);
	atTarget &= Math_StepToF(&thisx->world.pos.z, pthis->targetPos.z, thisx->speedXZ);
	if(atTarget)
	{
		thisx->speedXZ = 0.0f;
		pthis->targetPos.x = thisx->world.pos.x;
		pthis->targetPos.z = thisx->world.pos.z;
		if(thisx->velocity.y <= 0.0f)
		{
			thisx->flags &= ~ACTOR_FLAG_4;
		}
		thisx->params = 0;
		func_8002DF54(globalCtx, thisx, 7);
		Audio_PlayActorSound2(thisx, NA_SE_EV_BLOCK_BOUND);
		if((fabsf(thisx->world.pos.x + 1387.0f) < 1.0f) && (fabsf(thisx->world.pos.z + 260.0f) < 1.0f))
		{
			pthis->actionFunc = BgIceObjects_Stuck;
		}
		else
		{
			pthis->actionFunc = BgIceObjects_Idle;
		}
	}
	else if((thisx->speedXZ > 6.0f) && (thisx->world.pos.y >= 0.0f))
	{
		spread = Rand_CenteredFloat(120.0f);
		velocity.x = -(1.5f + Rand_ZeroOne()) * Math_SinS(pthis->dyna.unk_158);
		velocity.y = Rand_ZeroOne() + 1.0f;
		velocity.z = -(1.5f + Rand_ZeroOne()) * Math_CosS(pthis->dyna.unk_158);
		pos.x = thisx->world.pos.x - (60.0f * Math_SinS(pthis->dyna.unk_158)) - (Math_CosS(pthis->dyna.unk_158) * spread);
		pos.z = thisx->world.pos.z - (60.0f * Math_CosS(pthis->dyna.unk_158)) + (Math_SinS(pthis->dyna.unk_158) * spread);
		pos.y = thisx->world.pos.y;
		func_8002829C(globalCtx, &pos, &velocity, &sZeroVec, &sWhite, &sGray, 250, Rand_S16Offset(40, 15));
		spread = Rand_CenteredFloat(120.0f);
		pos.x = thisx->world.pos.x - (60.0f * Math_SinS(pthis->dyna.unk_158)) + (Math_CosS(pthis->dyna.unk_158) * spread);
		pos.z = thisx->world.pos.z - (60.0f * Math_CosS(pthis->dyna.unk_158)) - (Math_SinS(pthis->dyna.unk_158) * spread);
		func_8002829C(globalCtx, &pos, &velocity, &sZeroVec, &sWhite, &sGray, 250, Rand_S16Offset(40, 15));
		func_8002F974(thisx, NA_SE_PL_SLIP_ICE_LEVEL - SFX_FLAG);
	}
	BgIceObjects_CheckPits(pthis, globalCtx);
}

void BgIceObjects_Reset(BgIceObjects* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	Actor* thisx = &pthis->dyna.actor;

	if(pthis->dyna.unk_150 != 0.0f)
	{
		player->stateFlags2 &= ~PLAYER_STATE2_4;
		pthis->dyna.unk_150 = 0.0f;
	}
	if(Math_StepToF(&thisx->world.pos.y, thisx->home.pos.y, 1.0f))
	{
		thisx->flags &= ~ACTOR_FLAG_4;
		Math_Vec3f_Copy(&pthis->targetPos, &thisx->home.pos);
		pthis->actionFunc = BgIceObjects_Idle;
		thisx->speedXZ = 0.0f;
	}
}

void BgIceObjects_Stuck(BgIceObjects* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	if(pthis->dyna.unk_150 != 0.0f)
	{
		player->stateFlags2 &= ~PLAYER_STATE2_4;
		pthis->dyna.unk_150 = 0.0f;
	}
}

void BgIceObjects_Update(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	BgIceObjects* pthis = (BgIceObjects*)thisx;

	pthis->actionFunc(pthis, globalCtx);
}

void BgIceObjects_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	BgIceObjects* pthis = (BgIceObjects*)thisx;

	Gfx_DrawDListOpa(globalCtx, object_ice_objects_DL_000190);
}

void BgIceObjects_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	sWhite = {250, 250, 250, 255};

	sGray = {180, 180, 180, 255};

	sZeroVec = {0.0f, 0.0f, 0.0f};

	Bg_Ice_Objects_InitVars = {
	    ACTOR_BG_ICE_OBJECTS, ACTORCAT_PROP, FLAGS, OBJECT_ICE_OBJECTS, sizeof(BgIceObjects), (ActorFunc)BgIceObjects_Init, (ActorFunc)BgIceObjects_Destroy, (ActorFunc)BgIceObjects_Update, (ActorFunc)BgIceObjects_Draw, (ActorFunc)BgIceObjects_Reset,
	};
}
