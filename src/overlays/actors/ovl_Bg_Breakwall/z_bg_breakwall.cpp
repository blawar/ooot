#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_BREAKWALL_Z_BG_BREAKWALL_C
#include "actor_common.h"
/*
 * File: z_bg_breakwall.c
 * Overlay: Bg_Breakwall
 * Description: Bombable Wall
 */

#include "scenes/dungeons/ddan/ddan_scene.h"
#include "z_bg_breakwall.h"
#include "def/audio_bank.h"
#include "def/code_80043480.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_demo.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "objects/object_bwall/object_bwall.h"
#include "objects/object_kingdodongo/object_kingdodongo.h"

#define FLAGS ACTOR_FLAG_4

void BgBreakwall_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgBreakwall_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgBreakwall_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgBreakwall_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgBreakwall_Draw(Actor* pthisx, GlobalContext* globalCtx);

void BgBreakwall_WaitForObject(BgBreakwall* pthis, GlobalContext* globalCtx);
void BgBreakwall_Wait(BgBreakwall* pthis, GlobalContext* globalCtx);
void BgBreakwall_LavaCoverMove(BgBreakwall* pthis, GlobalContext* globalCtx);

ActorInit Bg_Breakwall_InitVars = {
    ACTOR_BG_BREAKWALL, ACTORCAT_BG, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(BgBreakwall), (ActorFunc)BgBreakwall_Init, (ActorFunc)BgBreakwall_Destroy, (ActorFunc)BgBreakwall_Update, NULL, (ActorFunc)BgBreakwall_Reset,
};

static ColliderQuadInit sQuadInit = {
    {
	COLTYPE_NONE,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER | AC_TYPE_OTHER,
	OC1_NONE,
	OC2_TYPE_2,
	COLSHAPE_QUAD,
    },
    {
	ELEMTYPE_UNK0,
	{0x00000048, 0x00, 0x00},
	{0x00000048, 0x00, 0x00},
	TOUCH_NONE,
	BUMP_ON,
	OCELEM_NONE,
    },
    {{{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}},
};

static BombableWallInfo sBombableWallInfo[] = {
    {&object_bwall_Col_000118, object_bwall_DL_000040, 0},
    {&object_bwall_Col_000118, object_bwall_DL_000040, 0},
    {&object_kingdodongo_Col_0264A8, object_kingdodongo_DL_025BD0, 1},
    {&object_kingdodongo_Col_025B64, NULL, -1},
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 400, ICHAIN_STOP),
};

void BgBreakwall_SetupAction(BgBreakwall* pthis, BgBreakwallActionFunc actionFunc)
{
	pthis->actionFunc = actionFunc;
}

void BgBreakwall_Init(Actor* pthisx, GlobalContext* globalCtx)
{
	BgBreakwall* pthis = (BgBreakwall*)pthisx;
	s32 pad;
	s32 wallType = ((pthis->dyna.actor.params >> 13) & 3) & 0xFF;

	Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
	DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
	pthis->bombableWallDList = sBombableWallInfo[wallType].dList;
	pthis->colType = sBombableWallInfo[wallType].colType;

	if(pthis->colType == 1)
	{
		pthis->dyna.actor.world.rot.x = 0x4000;
	}

	if(pthis->bombableWallDList != NULL)
	{
		if(Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F))
		{
			Actor_Kill(&pthis->dyna.actor);
			return;
		}

		ActorShape_Init(&pthis->dyna.actor.shape, 0.0f, NULL, 0.0f);
		Collider_InitQuad(globalCtx, &pthis->collider);
		Collider_SetQuad(globalCtx, &pthis->collider, &pthis->dyna.actor, &sQuadInit);
	}
	else
	{
		pthis->dyna.actor.world.pos.y -= 40.0f;
	}

	pthis->bankIndex = (wallType >= BWALL_KD_FLOOR) ? Object_GetIndex(&globalCtx->objectCtx, OBJECT_KINGDODONGO) : Object_GetIndex(&globalCtx->objectCtx, OBJECT_BWALL);

	if(pthis->bankIndex < 0)
	{
		Actor_Kill(&pthis->dyna.actor);
	}
	else
	{
		BgBreakwall_SetupAction(pthis, BgBreakwall_WaitForObject);
	}
}

void BgBreakwall_Destroy(Actor* pthisx, GlobalContext* globalCtx)
{
	BgBreakwall* pthis = (BgBreakwall*)pthisx;

	DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

/**
 * Spawns fragments using ACTOR_EN_A_OBJ whenever the wall or floor is exploded.
 * Returns the last spawned actor
 */
Actor* BgBreakwall_SpawnFragments(GlobalContext* globalCtx, BgBreakwall* pthis, Vec3f* pos, f32 velocity, f32 scaleY, f32 scaleX, s32 count, f32 accel)
{
	Actor* actor = NULL;
	Vec3f actorPos;
	s32 k;
	s32 j;
	s32 i;
	s16 angle1;
	s16 angle2 = 0;
	Vec3f zeroVec = {0.0f, 0.0f, 0.0f}; // unused
	Vec3s actorRotList[] = {{0, 0, 0}, {0, 0, 0x4000}, {0, 0, -0x4000}, {0, 0, 0}};
	Vec3f actorScaleList[] = {
	    {0.004f, 0.004f, 0.004f},
	    {0.004f, 0.004f, 0.004f},
	    {0.004f, 0.004f, 0.004f},
	    {0.004f, 0.004f, 0.004f},
	};
	Vec3f actorPosList[][4] = {
	    {{40.0f, 15.0f, 0.0f}, {30.0f, 57.0f, 0.0f}, {50.0f, 57.0f, 0.0f}, {40.0f, 70.0f, 0.0f}},
	    {{55.0f, -15.0f, 0.0f}, {30.0f, -32.0f, 0.0f}, {50.0f, -32.0f, 0.0f}, {20.0f, -10.0f, 0.0f}},
	    {{-40.0f, 14.0f, 0.0f}, {-50.0f, 57.0f, 0.0f}, {-30.0f, 57.0f, 0.0f}, {-40.0f, 70.0f, 0.0f}},
	    {{-55.0f, -15.0f, 0.0f}, {-55.0f, -32.0f, 0.0f}, {-30.0f, -32.0f, 0.0f}, {-20.0f, -10.0f, 0.0f}},
	};
	s32 pad;

	for(k = 3; k >= 0; k--)
	{
		if((k == 0) || (k == 3))
		{
			actorScaleList[k].x *= scaleX;
			actorScaleList[k].y *= scaleY;
			actorScaleList[k].z *= scaleY;
		}
		else
		{
			actorScaleList[k].x *= scaleY;
			actorScaleList[k].y *= scaleX;
			actorScaleList[k].z *= scaleX;
		}
	}

	for(i = 0; i < count; angle2 += 0x4000, i++)
	{
		angle1 = pthis->dyna.actor.world.rot.y.abs() + angle2;
		Matrix_Translate(pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z, MTXMODE_NEW);
		Matrix_RotateZYX(pthis->dyna.actor.world.rot.x, pthis->dyna.actor.world.rot.y, pthis->dyna.actor.world.rot.z, MTXMODE_APPLY);
		Matrix_Translate(pos->x, pos->y, pos->z, MTXMODE_APPLY);

		for(j = 3; j >= 0; j--)
		{
			for(k = 3; k >= 0; k--)
			{
				Matrix_MultVec3f(&actorPosList[j][k], &actorPos);
				actor = Actor_Spawn(
				    &globalCtx->actorCtx, globalCtx, ACTOR_EN_A_OBJ, Rand_CenteredFloat(20.0f) + actorPos.x, Rand_CenteredFloat(20.0f) + actorPos.y, Rand_CenteredFloat(20.0f) + actorPos.z, actorRotList[k].x, actorRotList[k].y + angle1,
				    actorRotList[k].z, 0x000B);

				if((j & 1) == 0)
				{
					func_80033480(globalCtx, &actorPos, velocity * 200.0f, 1, 650, 150, 1);
				}

				if(actor != NULL)
				{
					actor->speedXZ = Rand_ZeroOne() + (accel * 0.6f);
					actor->velocity.y = Rand_ZeroOne() + (accel * 0.6f);
					actor->world.rot.y += (s16)((Rand_ZeroOne() - 0.5f) * 3000.0f);
					actor->world.rot.x = (s16)(Rand_ZeroOne() * 3500.0f) + 2000;
					actor->world.rot.z = (s16)(Rand_ZeroOne() * 3500.0f) + 2000;
					actor->parent = &pthis->dyna.actor;
					actor->scale.x = actorScaleList[k].x + Rand_CenteredFloat(0.001f);
					actor->scale.y = actorScaleList[k].y + Rand_CenteredFloat(0.001f);
					actor->scale.z = actorScaleList[k].z + Rand_CenteredFloat(0.001f);
				}
			}
		}
	}

	return actor;
}

/**
 * Sets up the collision model as well is the object dependency and action function to use.
 */
void BgBreakwall_WaitForObject(BgBreakwall* pthis, GlobalContext* globalCtx)
{
	if(Object_IsLoaded(&globalCtx->objectCtx, pthis->bankIndex))
	{
		CollisionHeader* colHeader = NULL;
		s32 wallType = ((pthis->dyna.actor.params >> 13) & 3) & 0xFF;

		pthis->dyna.actor.objBankIndex = pthis->bankIndex;
		Actor_SetObjectDependency(globalCtx, &pthis->dyna.actor);
		pthis->dyna.actor.flags &= ~ACTOR_FLAG_4;
		pthis->dyna.actor.draw = BgBreakwall_Draw;
		CollisionHeader_GetVirtual(sBombableWallInfo[wallType].colHeader, &colHeader);
		pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

		if(wallType == BWALL_KD_LAVA_COVER)
		{
			BgBreakwall_SetupAction(pthis, BgBreakwall_LavaCoverMove);
		}
		else
		{
			BgBreakwall_SetupAction(pthis, BgBreakwall_Wait);
		}
	}
}

/**
 * Checks for an explosion using quad collision. If the wall or floor is exploded then it will spawn fragments and
 * despawn itself.
 */
void BgBreakwall_Wait(BgBreakwall* pthis, GlobalContext* globalCtx)
{
	if(pthis->collider.base.acFlags & 2)
	{
		Vec3f effectPos;
		s32 wallType = ((pthis->dyna.actor.params >> 13) & 3) & 0xFF;

		DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
		effectPos.y = effectPos.z = effectPos.x = 0.0f;

		if(pthis->dyna.actor.world.rot.x == 0)
		{
			effectPos.y = 55.0f;
		}
		else
		{
			effectPos.z = 25.0f;
			effectPos.y = -10.0f;
		}

		BgBreakwall_SpawnFragments(globalCtx, pthis, &effectPos, 0.0f, 6.4f, 5.0f, 1, 2.0f);
		Flags_SetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);

		if(wallType == BWALL_KD_FLOOR)
		{
			Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_EXPLOSION);
		}
		else
		{
			Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_WALL_BROKEN);
		}

		if((wallType == BWALL_DC_ENTRANCE) && (!(Flags_GetEventChkInf(0xB0))))
		{
			Flags_SetEventChkInf(0xB0);
			Cutscene_SetSegment(globalCtx, gDcOpeningCs);
			gSaveContext.cutsceneTrigger = 1;
			Audio_PlaySoundGeneral(NA_SE_SY_CORRECT_CHIME, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
			func_8002DF54(globalCtx, NULL, 0x31);
		}

		if(pthis->dyna.actor.params < 0)
		{
			Audio_PlaySoundGeneral(NA_SE_SY_TRE_BOX_APPEAR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
		}

		Actor_Kill(&pthis->dyna.actor);
	}
}

/**
 * Moves the actor's y position to cover the lava floor in King Dodongo's lair after he is defeated so the player is no
 * longer hurt by the lava.
 */
void BgBreakwall_LavaCoverMove(BgBreakwall* pthis, GlobalContext* globalCtx)
{
	Math_StepToF(&pthis->dyna.actor.world.pos.y, KREG(80) + pthis->dyna.actor.home.pos.y, 1.0f);
}

void BgBreakwall_Update(Actor* pthisx, GlobalContext* globalCtx)
{
	BgBreakwall* pthis = (BgBreakwall*)pthisx;

	pthis->actionFunc(pthis, globalCtx);
}

/**
 * These are the quads used for the wall and floor collision. These are used for the detecting when a bomb explosion has
 * collided with a wall, and can be adjusted for different wall or floor sizes.
 */
static Vec3f sColQuadList[][4] = {
    {{800.0f, 1600.0f, 100.0f}, {-800.0f, 1600.0f, 100.0f}, {800.0f, 0.0f, 100.0f}, {-800.0f, 0.0f, 100.0f}},
    {{10.0f, 0.0f, 10.0f}, {-10.0f, 0.0f, 10.0f}, {10.0f, 0.0f, -10.0f}, {-10.0f, 0.0f, -10.0f}},
};

void BgBreakwall_Draw(Actor* pthisx, GlobalContext* globalCtx)
{
	s32 pad;
	BgBreakwall* pthis = (BgBreakwall*)pthisx;

	if(pthis->bombableWallDList != NULL)
	{
		OPEN_DISPS(globalCtx->gfxCtx, "../z_bg_breakwall.c", 767);

		func_80093D18(globalCtx->gfxCtx);
		gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_bg_breakwall.c", 771), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_OPA_DISP++, pthis->bombableWallDList);

		if(pthis->colType >= 0)
		{
			Vec3f colQuad[4];
			Vec3f* src = &sColQuadList[pthis->colType][0];
			Vec3f* dst = &colQuad[0];
			s32 i;

			for(i = 0; i < 4; i++)
			{
				Matrix_MultVec3f(src++, dst++);
			}

			Collider_SetQuadVertices(&pthis->collider, &colQuad[0], &colQuad[1], &colQuad[2], &colQuad[3]);
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
		}

		CLOSE_DISPS(globalCtx->gfxCtx, "../z_bg_breakwall.c", 822);
	}
}

void BgBreakwall_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Bg_Breakwall_InitVars = {
	    ACTOR_BG_BREAKWALL, ACTORCAT_BG, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(BgBreakwall), (ActorFunc)BgBreakwall_Init, (ActorFunc)BgBreakwall_Destroy, (ActorFunc)BgBreakwall_Update, NULL, (ActorFunc)BgBreakwall_Reset,
	};

	sQuadInit = {
	    {
		COLTYPE_NONE,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER | AC_TYPE_OTHER,
		OC1_NONE,
		OC2_TYPE_2,
		COLSHAPE_QUAD,
	    },
	    {
		ELEMTYPE_UNK0,
		{0x00000048, 0x00, 0x00},
		{0x00000048, 0x00, 0x00},
		TOUCH_NONE,
		BUMP_ON,
		OCELEM_NONE,
	    },
	    {{{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}},
	};
}
