#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_HAHENIRON_Z_BG_JYA_HAHENIRON_C
#include "actor_common.h"
/*
 * File: z_bg_jya_haheniron
 * Overlay: ovl_Bg_Jya_Haheniron
 * Description: Chunks of Iron Knucle Chair and Pillar
 */

#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "z_bg_jya_haheniron.h"
#include "def/code_8006BA00.h"
#include "def/random.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "objects/object_jya_iron/object_jya_iron.h"

#define FLAGS ACTOR_FLAG_4

void BgJyaHaheniron_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaHaheniron_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgJyaHaheniron_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaHaheniron_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaHaheniron_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgJyaHaheniron_SetupChairCrumble(BgJyaHaheniron* pthis);
void BgJyaHaheniron_ChairCrumble(BgJyaHaheniron* pthis, GlobalContext* globalCtx);
void BgJyaHaheniron_SetupPillarCrumble(BgJyaHaheniron* pthis);
void BgJyaHaheniron_PillarCrumble(BgJyaHaheniron* pthis, GlobalContext* globalCtx);
void BgJyaHaheniron_SetupRubbleCollide(BgJyaHaheniron* pthis);
void BgJyaHaheniron_RubbleCollide(BgJyaHaheniron* pthis, GlobalContext* globalCtx);

static Gfx* dLists_45[] = {
    gObjectJyaIronDL_000880,
    gObjectJyaIronDL_000AE0,
    gObjectJyaIronDL_000600,
};

ActorInit Bg_Jya_Haheniron_InitVars = {
    ACTOR_BG_JYA_HAHENIRON, ACTORCAT_PROP, FLAGS, OBJECT_JYA_IRON, ACTOR_FACTORY(BgJyaHaheniron), (ActorFunc)BgJyaHaheniron_Init, (ActorFunc)BgJyaHaheniron_Destroy, (ActorFunc)BgJyaHaheniron_Update, (ActorFunc)BgJyaHaheniron_Draw, (ActorFunc)BgJyaHaheniron_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
	{
	    ELEMTYPE_UNK0,
	    {0xFFCFFFFF, 0x00, 0x04},
	    {0x00000000, 0x00, 0x00},
	    TOUCH_ON | TOUCH_SFX_NORMAL,
	    BUMP_NONE,
	    OCELEM_NONE,
	},
	{0, {{0, 0, 0}, 10}, 100},
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
	COLTYPE_NONE,
	AT_ON | AT_TYPE_ENEMY,
	AC_ON,
	OC1_NONE,
	OC2_NONE,
	COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static s16 sKakeraScales[] = {5, 8, 11, 14, 17};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32_DIV1000(gravity, -2000, ICHAIN_CONTINUE), ICHAIN_F32_DIV1000(minVelocityY, -15000, ICHAIN_CONTINUE), ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),	 ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

static f32 D_80898794[] = {0.13f, 0.1f, 0.1f};

static Vec3f D_808987A0[] = {0.0f, 14.0f, 0.0f};

static Vec3f D_808987AC[] = {0.0f, 8.0f, 0.0f};

void BgJyaHaheniron_ColliderInit(BgJyaHaheniron* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	Collider_InitJntSph(globalCtx, &pthis->collider);
	Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItems);
}

void BgJyaHaheniron_SpawnFragments(GlobalContext* globalCtx, Vec3f* vec1, Vec3f* vec2)
{
	Vec3f vel;
	Vec3f pos;
	s16 arg5;
	s32 angle;
	s32 i;
	f32 rand1;

	for(angle = 0, i = 0; i < ARRAY_COUNT(sKakeraScales); i++)
	{
		rand1 = Rand_ZeroOne() * 10.0f;
		vel.x = (Math_SinS(angle) * rand1) + vec2->x;
		vel.y = (Rand_ZeroOne() * 10.0f) + vec2->y;
		vel.z = (Math_CosS(angle) * rand1) + vec2->z;

		rand1 = Rand_ZeroOne();
		if(rand1 < 0.2f)
		{
			arg5 = 96;
		}
		else if(rand1 < 0.8f)
		{
			arg5 = 64;
		}
		else
		{
			arg5 = 32;
		}

		EffectSsKakera_Spawn(globalCtx, vec1, &vel, vec1, -350, arg5, 40, 4, 0, sKakeraScales[i], 0, 20, 40, KAKERA_COLOR_NONE, OBJECT_JYA_IRON, gObjectJyaIronDL_000880);
		angle += 0x3333;
	}
	pos.x = vec1->x + (vec2->x * 5.0f);
	pos.y = vec1->y + (vec2->y * 5.0f);
	pos.z = vec1->z + (vec2->z * 5.0f);
	func_80033480(globalCtx, &pos, 100.0f, 4, 100, 160, 1);
}

void BgJyaHaheniron_Init(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	BgJyaHaheniron* pthis = (BgJyaHaheniron*)thisx;

	Actor_ProcessInitChain(&pthis->actor, sInitChain);
	Actor_SetScale(&pthis->actor, D_80898794[pthis->actor.params]);
	if(pthis->actor.params == 0)
	{
		BgJyaHaheniron_ColliderInit(pthis, globalCtx);
		pthis->actor.shape.rot.z = (Rand_ZeroOne() * 65535.0f);
		BgJyaHaheniron_SetupChairCrumble(pthis);
	}
	else if(pthis->actor.params == 1)
	{
		BgJyaHaheniron_SetupPillarCrumble(pthis);
	}
	else if(pthis->actor.params == 2)
	{
		BgJyaHaheniron_SetupRubbleCollide(pthis);
	}
}

void BgJyaHaheniron_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	BgJyaHaheniron* pthis = (BgJyaHaheniron*)thisx;

	if(pthis->actor.params == 0)
	{
		Collider_DestroyJntSph(globalCtx, &pthis->collider);
	}
}

void BgJyaHaheniron_SetupChairCrumble(BgJyaHaheniron* pthis)
{
	pthis->actionFunc = BgJyaHaheniron_ChairCrumble;
}

void BgJyaHaheniron_ChairCrumble(BgJyaHaheniron* pthis, GlobalContext* globalCtx)
{
	Vec3f vec;

	Actor_MoveForward(&pthis->actor);
	Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 8.0f, 0.0f, 0x85);
	if((pthis->actor.bgCheckFlags & (BG_STATE_0 | BG_STATE_3)) || ((pthis->collider.base.atFlags & AT_HIT) && (pthis->collider.base.at != NULL) && (pthis->collider.base.at->category == ACTORCAT_PLAYER)))
	{
		vec.x = -Rand_ZeroOne() * pthis->actor.velocity.x;
		vec.y = -Rand_ZeroOne() * pthis->actor.velocity.y;
		vec.z = -Rand_ZeroOne() * pthis->actor.velocity.z;
		BgJyaHaheniron_SpawnFragments(globalCtx, &pthis->actor.world.pos, &vec);
		Actor_Kill(&pthis->actor);
	}
	else if(pthis->timer > 60)
	{
		Actor_Kill(&pthis->actor);
	}
	else
	{
		CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
	}
	pthis->actor.shape.rot.y += 0x4B0;
	pthis->actor.shape.rot.x += 0xFA0;
}

void BgJyaHaheniron_SetupPillarCrumble(BgJyaHaheniron* pthis)
{
	pthis->actionFunc = BgJyaHaheniron_PillarCrumble;
}

void BgJyaHaheniron_PillarCrumble(BgJyaHaheniron* pthis, GlobalContext* globalCtx)
{
	if(pthis->timer >= 8)
	{
		Actor_MoveForward(&pthis->actor);
	}
	else if(pthis->timer >= 17)
	{
		BgJyaHaheniron_SpawnFragments(globalCtx, &pthis->actor.world.pos, D_808987A0);
		Actor_Kill(&pthis->actor);
	}
	pthis->actor.shape.rot.y += 0x258;
	pthis->actor.shape.rot.x += 0x3E8;
}

void BgJyaHaheniron_SetupRubbleCollide(BgJyaHaheniron* pthis)
{
	pthis->actionFunc = BgJyaHaheniron_RubbleCollide;
}

void BgJyaHaheniron_RubbleCollide(BgJyaHaheniron* pthis, GlobalContext* globalCtx)
{
	if(pthis->timer >= 17)
	{
		BgJyaHaheniron_SpawnFragments(globalCtx, &pthis->actor.world.pos, D_808987AC);
		Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 80, NA_SE_EN_IRONNACK_BREAK_PILLAR2);
		Actor_Kill(&pthis->actor);
	}
}

void BgJyaHaheniron_Update(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	BgJyaHaheniron* pthis = (BgJyaHaheniron*)thisx;

	pthis->timer++;
	pthis->actionFunc(pthis, globalCtx);
}

void BgJyaHaheniron_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	BgJyaHaheniron* pthis = (BgJyaHaheniron*)thisx;

	if(pthis->actor.params == 0)
	{
		Collider_UpdateSpheres(0, &pthis->collider);
	}
	Gfx_DrawDListOpa(globalCtx, dLists_45[pthis->actor.params]);
}

void BgJyaHaheniron_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Bg_Jya_Haheniron_InitVars = {
	    ACTOR_BG_JYA_HAHENIRON,	     ACTORCAT_PROP, FLAGS, OBJECT_JYA_IRON, ACTOR_FACTORY(BgJyaHaheniron), (ActorFunc)BgJyaHaheniron_Init, (ActorFunc)BgJyaHaheniron_Destroy, (ActorFunc)BgJyaHaheniron_Update, (ActorFunc)BgJyaHaheniron_Draw,
	    (ActorFunc)BgJyaHaheniron_Reset,
	};

	sJntSphInit = {
	    {
		COLTYPE_NONE,
		AT_ON | AT_TYPE_ENEMY,
		AC_ON,
		OC1_NONE,
		OC2_NONE,
		COLSHAPE_JNTSPH,
	    },
	    1,
	    sJntSphElementsInit,
	};
}
