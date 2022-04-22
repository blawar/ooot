#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_BOMBIWA_Z_BG_JYA_BOMBIWA_C
#include "actor_common.h"
/*
 * File: z_bg_jya_bombiwa.c
 * Overlay: ovl_Bg_Jya_Bombiwa
 * Description: Spirit Temple top room bombable wall
 */

#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "vt.h"
#include "z_bg_jya_bombiwa.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/random.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "objects/object_jya_obj/object_jya_obj.h"

#define FLAGS 0

void BgJyaBombiwa_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBombiwa_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgJyaBombiwa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBombiwa_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBombiwa_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Bg_Jya_Bombiwa_InitVars = {
    ACTOR_BG_JYA_BOMBIWA, ACTORCAT_BG, FLAGS, OBJECT_JYA_OBJ, sizeof(BgJyaBombiwa), (ActorFunc)BgJyaBombiwa_Init, (ActorFunc)BgJyaBombiwa_Destroy, (ActorFunc)BgJyaBombiwa_Update, (ActorFunc)BgJyaBombiwa_Draw, (ActorFunc)BgJyaBombiwa_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[] = {
    {
	{
	    ELEMTYPE_UNK0,
	    {0x00000000, 0x00, 0x00},
	    {0x00000008, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON,
	    OCELEM_NONE,
	},
	{0, {{0, 0, 0}, 50}, 100},
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
	COLTYPE_NONE,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_NONE,
	OC2_NONE,
	COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void BgJyaBombiwa_SetupDynaPoly(BgJyaBombiwa* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 flag)
{
	s16 pad1;
	CollisionHeader* colHeader = NULL;
	s16 pad2;

	DynaPolyActor_Init(&pthis->dyna, flag);
	CollisionHeader_GetVirtual(collision, &colHeader);
	pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
	if(pthis->dyna.bgId == BG_ACTOR_MAX)
	{
		// "Warning: move BG registration failed"
		osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_jya_bombiwa.c", 174, pthis->dyna.actor.id, pthis->dyna.actor.params);
	}
}

void BgJyaBombiwa_InitCollider(BgJyaBombiwa* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	Collider_InitJntSph(globalCtx, &pthis->collider);
	Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->dyna.actor, &sJntSphInit, pthis->colliderItems);
}

void BgJyaBombiwa_Init(Actor* thisx, GlobalContext* globalCtx)
{
	BgJyaBombiwa* pthis = (BgJyaBombiwa*)thisx;

	if((pthis->dyna.actor.params & 0x3F) != 0x29)
	{
		osSyncPrintf(VT_COL(YELLOW, BLACK));

		// "Warning: Switch Number changed (%s %d)(SW %d)"
		osSyncPrintf("Ｗａｒｎｉｎｇ : Switch Number が変更された(%s %d)(SW %d)\n", "../z_bg_jya_bombiwa.c", 218, pthis->dyna.actor.params & 0x3F);
		osSyncPrintf(VT_RST);
	}
	BgJyaBombiwa_SetupDynaPoly(pthis, globalCtx, &gBombiwaCol, DPM_UNK);
	BgJyaBombiwa_InitCollider(pthis, globalCtx);
	if(Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F))
	{
		Actor_Kill(&pthis->dyna.actor);
	}
	else
	{
		Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);

		// "Rock destroyed by jya bomb"
		osSyncPrintf("(jya 爆弾で破壊岩)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
	}
}

void BgJyaBombiwa_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	BgJyaBombiwa* pthis = (BgJyaBombiwa*)thisx;

	DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
	Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void BgJyaBombiwa_Break(BgJyaBombiwa* pthis, GlobalContext* globalCtx)
{
	Vec3f pos;
	Vec3f velocity;
	s16 arg5;
	s8 arg6;
	s8 arg7;
	s32 i;
	s16 scale;

	for(i = 0; i < 16; i++)
	{
		pos.x = ((Rand_ZeroOne() * 80.0f) + pthis->dyna.actor.world.pos.x) - 40.0f;
		pos.y = (Rand_ZeroOne() * 140.0f) + pthis->dyna.actor.world.pos.y;
		pos.z = ((Rand_ZeroOne() * 80.0f) + pthis->dyna.actor.world.pos.z) - 40.0f;
		velocity.x = (Rand_ZeroOne() - 0.5f) * 10.0f;
		velocity.y = Rand_ZeroOne() * 12.0f;
		velocity.z = (Rand_ZeroOne() - 0.5f) * 10.0f;
		scale = (s32)(i * 1.8f) + 3;
		if(scale > 15)
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
			if(scale < 10)
			{
				arg6 = 0x50;
				arg7 = 80;
			}
		}
		EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pos, -400, arg5, arg6, arg7, 0, scale, 1, 20, 80, KAKERA_COLOR_NONE, OBJECT_JYA_OBJ, gBombiwaEffectDL);
	}
	pos.x = pthis->dyna.actor.world.pos.x;
	pos.y = pthis->dyna.actor.world.pos.y + 70.0f;
	pos.z = pthis->dyna.actor.world.pos.z;
	func_80033480(globalCtx, &pos, 100.0f, 0xA, 0x64, 0xA0, 1);
}

void BgJyaBombiwa_Update(Actor* thisx, GlobalContext* globalCtx)
{
	BgJyaBombiwa* pthis = (BgJyaBombiwa*)thisx;

	if(pthis->collider.base.acFlags & AC_HIT)
	{
		BgJyaBombiwa_Break(pthis, globalCtx);
		Flags_SetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);
		Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 40, NA_SE_EV_WALL_BROKEN);
		Actor_Kill(&pthis->dyna.actor);
	}
	else
	{
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
	}
}

void BgJyaBombiwa_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	BgJyaBombiwa* pthis = (BgJyaBombiwa*)thisx;

	Gfx_DrawDListOpa(globalCtx, gBombiwaDL);
	Collider_UpdateSpheres(0, &pthis->collider);
}

void BgJyaBombiwa_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Bg_Jya_Bombiwa_InitVars = {
	    ACTOR_BG_JYA_BOMBIWA, ACTORCAT_BG, FLAGS, OBJECT_JYA_OBJ, sizeof(BgJyaBombiwa), (ActorFunc)BgJyaBombiwa_Init, (ActorFunc)BgJyaBombiwa_Destroy, (ActorFunc)BgJyaBombiwa_Update, (ActorFunc)BgJyaBombiwa_Draw, (ActorFunc)BgJyaBombiwa_Reset,
	};

	sJntSphInit = {
	    {
		COLTYPE_NONE,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_NONE,
		OC2_NONE,
		COLSHAPE_JNTSPH,
	    },
	    1,
	    sJntSphElementsInit,
	};
}
