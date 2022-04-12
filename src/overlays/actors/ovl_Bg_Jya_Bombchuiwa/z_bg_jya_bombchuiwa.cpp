#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_BOMBCHUIWA_Z_BG_JYA_BOMBCHUIWA_C
#include "actor_common.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "z_bg_jya_bombchuiwa.h"
#include "def/code_8006BA00.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "objects/object_jya_obj/object_jya_obj.h"
#define FLAGS ACTOR_FLAG_VISIBLE

void BgJyaBombchuiwa_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBombchuiwa_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgJyaBombchuiwa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBombchuiwa_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBombchuiwa_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgJyaBombchuiwa_WaitForExplosion(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx);
void BgJyaBombchuiwa_SetupWaitForExplosion(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx);
void func_808949B8(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx);
void BgJyaBombchuiwa_CleanUpAfterExplosion(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx);
void BgJyaBombchuiwa_SpawnLightRay(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx);

static Vec3f D_80894F88_42 = {-920.0f, 480.0f, -889.0f};

static Vec3s D_80894F94_42 = {0, 0, 0};

ActorInit Bg_Jya_Bombchuiwa_InitVars = {
    ACTOR_BG_JYA_BOMBCHUIWA,	      ACTORCAT_BG, FLAGS, OBJECT_JYA_OBJ, sizeof(BgJyaBombchuiwa), (ActorFunc)BgJyaBombchuiwa_Init, (ActorFunc)BgJyaBombchuiwa_Destroy, (ActorFunc)BgJyaBombchuiwa_Update, (ActorFunc)BgJyaBombchuiwa_Draw,
    (ActorFunc)BgJyaBombchuiwa_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
	{
	    ELEMTYPE_UNK0,
	    {0x00000000, 0x00, 0x00},
	    {0x00000008, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON,
	    OCELEM_ON,
	},
	{0, {{-300, 0, 0}, 40}, 100},
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
	COLTYPE_NONE,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_2,
	OC2_TYPE_2,
	COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 3, ICHAIN_CONTINUE), ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE), ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE), ICHAIN_F32(uncullZoneScale, 1000, ICHAIN_CONTINUE), ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void BgJyaBombchuiwa_SetupCollider(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	Collider_InitJntSph(globalCtx, &pthis->collider);
	Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, &pthis->colliderItems);
}

void BgJyaBombchuiwa_SetDrawFlags(BgJyaBombchuiwa* pthis, u8 drawFlags)
{
	pthis->drawFlags &= ~7;
	pthis->drawFlags |= drawFlags;
}

void BgJyaBombchuiwa_Init(Actor* thisx, GlobalContext* globalCtx)
{
	BgJyaBombchuiwa* pthis = (BgJyaBombchuiwa*)thisx;

	Actor_ProcessInitChain(&pthis->actor, sInitChain);
	BgJyaBombchuiwa_SetupCollider(pthis, globalCtx);
	if(Flags_GetSwitch(globalCtx, pthis->actor.params & 0x3F))
	{
		BgJyaBombchuiwa_SpawnLightRay(pthis, globalCtx);
	}
	else
	{
		BgJyaBombchuiwa_SetupWaitForExplosion(pthis, globalCtx);
	}
	Actor_SetFocus(&pthis->actor, 0.0f);
}

void BgJyaBombchuiwa_Destroy(Actor* thisx, GlobalContext* globalCtx2)
{
	GlobalContext* globalCtx = globalCtx2;
	BgJyaBombchuiwa* pthis = (BgJyaBombchuiwa*)thisx;

	Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void BgJyaBombchuiwa_Break(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx)
{
	Vec3f pos;
	Vec3f velocity;
	s16 scale;
	s16 arg5;
	s16 arg6;
	s16 arg7;
	s32 i;

	for(i = 0; i < 20; i++)
	{
		pos.x = Rand_ZeroOne() * 10.0f + pthis->actor.world.pos.x - 10.0f;
		pos.y = Rand_ZeroOne() * 40.0f + pthis->actor.world.pos.y - 20.0f;
		pos.z = Rand_ZeroOne() * 50.0f + pthis->actor.world.pos.z - 25.0f;
		velocity.x = Rand_ZeroOne() * 3.0f - 0.3f;
		velocity.y = Rand_ZeroOne() * 18.0f;
		velocity.z = (Rand_ZeroOne() - 0.5f) * 15.0f;
		scale = (s32)(Rand_ZeroOne() * 20.0f) + 1;
		if(scale > 10)
		{
			arg5 = 5;
		}
		else
		{
			arg5 = 1;
		}
		if(Rand_ZeroOne() < 0.4f)
		{
			arg5 |= 0x40;
			arg6 = 0xC;
			arg7 = 8;
		}
		else
		{
			arg5 |= 0x20;
			arg6 = 0xC;
			arg7 = 8;
			if(scale < 8)
			{
				arg6 = 0x46;
				arg7 = 0x28;
			}
		}
		EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pos, -300, arg5, arg6, arg7, 0, scale, 1, 15, 80, KAKERA_COLOR_NONE, OBJECT_JYA_OBJ, gBombiwaEffectDL);
	}
	func_80033480(globalCtx, &pthis->actor.world.pos, 100.0f, 8, 100, 160, 0);
}

void BgJyaBombchuiwa_SetupWaitForExplosion(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BgJyaBombchuiwa_WaitForExplosion;
	BgJyaBombchuiwa_SetDrawFlags(pthis, 3);
	pthis->timer = 0;
}

void BgJyaBombchuiwa_WaitForExplosion(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx)
{
	if((pthis->collider.base.acFlags & AC_HIT) || (pthis->timer > 0))
	{
		if(pthis->timer == 0)
		{
			OnePointCutscene_Init(globalCtx, 3410, -99, &pthis->actor, MAIN_CAM);
		}
		pthis->timer++;
		if(pthis->timer > 10)
		{
			BgJyaBombchuiwa_Break(pthis, globalCtx);
			BgJyaBombchuiwa_CleanUpAfterExplosion(pthis, globalCtx);
			Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_WALL_BROKEN);
		}
	}
	else
	{
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
		CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
	}
}

void BgJyaBombchuiwa_CleanUpAfterExplosion(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = func_808949B8;
	BgJyaBombchuiwa_SetDrawFlags(pthis, 4);
	pthis->lightRayIntensity = 0.3f;
	pthis->timer = 0;
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
}

void func_808949B8(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx)
{
	pthis->timer++;
	if(pthis->timer & 4)
	{
		func_80033480(globalCtx, &pthis->actor.world.pos, 60.0f, 3, 100, 100, 0);
	}
	if(Math_StepToF(&pthis->lightRayIntensity, 1.0f, 0.028))
	{
		BgJyaBombchuiwa_SpawnLightRay(pthis, globalCtx);
	}
}

void BgJyaBombchuiwa_SpawnLightRay(BgJyaBombchuiwa* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = NULL;
	pthis->lightRayIntensity = 153.0f;
	BgJyaBombchuiwa_SetDrawFlags(pthis, 4);
	if(Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_MIR_RAY, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0) == NULL)
	{
		// "Occurrence failure"
		osSyncPrintf("Ｅｒｒｏｒ : Mir_Ray 発生失敗(%s %d)(arg_data 0x%04x)\n", "../z_bg_jya_bombchuiwa.c", 410, pthis->actor.params);
	}
}

void BgJyaBombchuiwa_Update(Actor* thisx, GlobalContext* globalCtx)
{
	BgJyaBombchuiwa* pthis = (BgJyaBombchuiwa*)thisx;

	if(pthis->actionFunc != NULL)
	{
		pthis->actionFunc(pthis, globalCtx);
	}
}

void BgJyaBombchuiwa_DrawRock(GlobalContext* globalCtx)
{
	OPEN_DISPS(globalCtx->gfxCtx, "../z_bg_jya_bombchuiwa.c", 436);
	func_80093D84(globalCtx->gfxCtx);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_bg_jya_bombchuiwa.c", 439), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPDisplayList(POLY_XLU_DISP++, gBombchuiwa2DL);
	CLOSE_DISPS(globalCtx->gfxCtx, "../z_bg_jya_bombchuiwa.c", 443);
}

void BgJyaBombchuiwa_DrawLight(Actor* thisx, GlobalContext* globalCtx)
{
	BgJyaBombchuiwa* pthis = (BgJyaBombchuiwa*)thisx;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_bg_jya_bombchuiwa.c", 453);
	func_80093D84(globalCtx->gfxCtx);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_bg_jya_bombchuiwa.c", 457), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, CLAMP_MAX((u32)(pthis->lightRayIntensity * 153.0f), 153));
	gSPDisplayList(POLY_XLU_DISP++, gBombchuiwaLight1DL);
	gDPPipeSync(POLY_XLU_DISP++);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, CLAMP_MAX((u32)(pthis->lightRayIntensity * 255.0f), 255));
	gSPDisplayList(POLY_XLU_DISP++, gBombchuiwaLight2DL);
	CLOSE_DISPS(globalCtx->gfxCtx, "../z_bg_jya_bombchuiwa.c", 472);
}

void BgJyaBombchuiwa_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	BgJyaBombchuiwa* pthis = (BgJyaBombchuiwa*)thisx;

	if(pthis->drawFlags & 1)
	{
		Gfx_DrawDListOpa(globalCtx, gBombchuiwaDL);
		Collider_UpdateSpheres(0, &pthis->collider);
	}

	if(pthis->drawFlags & 2)
	{
		BgJyaBombchuiwa_DrawRock(globalCtx);
	}
	if(pthis->drawFlags & 4)
	{
		func_800D1694(D_80894F88_42.x, D_80894F88_42.y, D_80894F88_42.z, &D_80894F94_42);
		Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
		if(pthis->drawFlags & 4)
		{
			BgJyaBombchuiwa_DrawLight(thisx, globalCtx);
		}
	}
}

void BgJyaBombchuiwa_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	D_80894F88_42 = {-920.0f, 480.0f, -889.0f};

	D_80894F94_42 = {0, 0, 0};

	Bg_Jya_Bombchuiwa_InitVars = {
	    ACTOR_BG_JYA_BOMBCHUIWA,	      ACTORCAT_BG, FLAGS, OBJECT_JYA_OBJ, sizeof(BgJyaBombchuiwa), (ActorFunc)BgJyaBombchuiwa_Init, (ActorFunc)BgJyaBombchuiwa_Destroy, (ActorFunc)BgJyaBombchuiwa_Update, (ActorFunc)BgJyaBombchuiwa_Draw,
	    (ActorFunc)BgJyaBombchuiwa_Reset,
	};

	sJntSphInit = {
	    {
		COLTYPE_NONE,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_2,
		OC2_TYPE_2,
		COLSHAPE_JNTSPH,
	    },
	    1,
	    sJntSphElementsInit,
	};
}
