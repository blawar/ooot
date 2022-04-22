#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT11_BAKUDANKABE_Z_BG_SPOT11_BAKUDANKABE_C
#include "actor_common.h"
/*
 * File: z_bg_spot11_bakudankabe.c
 * Overlay: ovl_Bg_Spot11_Bakudankabe
 * Description: Destructible Wall (Desert Colossus)
 */

#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "z_bg_spot11_bakudankabe.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/random.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"
#include "objects/object_spot11_obj/object_spot11_obj.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgSpot11Bakudankabe_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot11Bakudankabe_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot11Bakudankabe_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot11Bakudankabe_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot11Bakudankabe_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Bg_Spot11_Bakudankabe_InitVars = {
    ACTOR_BG_SPOT11_BAKUDANKABE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT11_OBJ,
    sizeof(BgSpot11Bakudankabe),
    (ActorFunc)BgSpot11Bakudankabe_Init,
    (ActorFunc)BgSpot11Bakudankabe_Destroy,
    (ActorFunc)BgSpot11Bakudankabe_Update,
    (ActorFunc)BgSpot11Bakudankabe_Draw,
    (ActorFunc)BgSpot11Bakudankabe_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
	COLTYPE_NONE,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_NONE,
	OC2_TYPE_2,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK0,
	{0x00000000, 0x00, 0x00},
	{0x00000008, 0x00, 0x00},
	TOUCH_NONE,
	BUMP_ON,
	OCELEM_NONE,
    },
    {40, 80, 0, {2259, 108, -1580}},
};

static Vec3f D_808B272C = {2259.0f, 108.0f, -1550.0f};
static Vec3f D_808B2738 = {2259.0f, 108.0f, -1550.0f};

void func_808B2180(BgSpot11Bakudankabe* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	Collider_InitCylinder(globalCtx, &pthis->collider);
	Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->dyna.actor, &sCylinderInit);
	pthis->collider.dim.pos.x += (s16)pthis->dyna.actor.world.pos.x;
	pthis->collider.dim.pos.y += (s16)pthis->dyna.actor.world.pos.y;
	pthis->collider.dim.pos.z += (s16)pthis->dyna.actor.world.pos.z;
}

void func_808B2218(BgSpot11Bakudankabe* pthis, GlobalContext* globalCtx)
{
	Actor* thisx = &pthis->dyna.actor;
	Vec3f burstDepthY;
	Vec3f burstDepthX;
	s32 i;

	burstDepthX.z = 0;
	burstDepthX.x = 0;

	for(i = 0; i < 20; i++)
	{
		s16 scale;
		s32 gravityInfluence;
		s32 rotationSpeed;

		Math_Vec3f_Sum(&thisx->world.pos, &D_808B272C, &burstDepthY);

		burstDepthY.x += (Rand_ZeroOne() - 0.5f) * 120.0f;
		burstDepthY.y += (30.0f + (i * 6.5f));
		burstDepthY.z += (Rand_ZeroOne() - 0.5f) * 20.0f;

		burstDepthX.y = (Rand_ZeroOne() - 0.2f) * 12.0f;
		scale = (Rand_ZeroOne() * 55.0f) + 8.0f;

		if(scale < 20)
		{
			gravityInfluence = -300;
		}
		else if(scale < 35)
		{
			gravityInfluence = -360;
		}
		else
		{
			gravityInfluence = -420;
		}
		if(Rand_ZeroOne() < 0.4f)
		{
			rotationSpeed = 65;
		}
		else
		{
			rotationSpeed = 33;
		}
		EffectSsKakera_Spawn(globalCtx, &burstDepthY, &burstDepthX, &burstDepthY, gravityInfluence, rotationSpeed, 0x1E, 4, 0, scale, 1, 3, 80, KAKERA_COLOR_NONE, OBJECT_GAMEPLAY_FIELD_KEEP, gFieldKakeraDL);
	}
	Math_Vec3f_Sum(&thisx->world.pos, &D_808B272C, &burstDepthY);
	func_80033480(globalCtx, &burstDepthY, 70, 4, 110, 160, 1);
	burstDepthY.y += 40;
	func_80033480(globalCtx, &burstDepthY, 70, 5, 110, 160, 1);
	burstDepthY.y += 40;
	func_80033480(globalCtx, &burstDepthY, 70, 4, 110, 160, 1);
}

void BgSpot11Bakudankabe_Init(Actor* thisx, GlobalContext* globalCtx)
{
	BgSpot11Bakudankabe* pthis = (BgSpot11Bakudankabe*)thisx;
	s32 pad;
	CollisionHeader* colHeader = NULL;

	DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
	if(Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params & 0x3F)))
	{
		Actor_Kill(&pthis->dyna.actor);
		return;
	}
	func_808B2180(pthis, globalCtx);
	CollisionHeader_GetVirtual(&gDesertColossusBombableWallCol, &colHeader);
	pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
	Actor_SetScale(&pthis->dyna.actor, 1.0f);
	osSyncPrintf("(spot11 爆弾壁)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
}

void BgSpot11Bakudankabe_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	BgSpot11Bakudankabe* pthis = (BgSpot11Bakudankabe*)thisx;

	DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
	Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void BgSpot11Bakudankabe_Update(Actor* thisx, GlobalContext* globalCtx)
{
	BgSpot11Bakudankabe* pthis = (BgSpot11Bakudankabe*)thisx;

	if(pthis->collider.base.acFlags & AC_HIT)
	{
		func_808B2218(pthis, globalCtx);
		Flags_SetSwitch(globalCtx, (pthis->dyna.actor.params & 0x3F));
		Audio_PlaySoundAtPosition(globalCtx, &D_808B2738, 40, NA_SE_EV_WALL_BROKEN);
		Common_PlaySfx(NA_SE_SY_CORRECT_CHIME);
		Actor_Kill(&pthis->dyna.actor);
		return;
	}
	CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void BgSpot11Bakudankabe_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	BgSpot11Bakudankabe* pthis = (BgSpot11Bakudankabe*)thisx;

	Gfx_DrawDListOpa(globalCtx, gDesertColossusBombableWallDL);
}

void BgSpot11Bakudankabe_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Bg_Spot11_Bakudankabe_InitVars = {
	    ACTOR_BG_SPOT11_BAKUDANKABE,
	    ACTORCAT_BG,
	    FLAGS,
	    OBJECT_SPOT11_OBJ,
	    sizeof(BgSpot11Bakudankabe),
	    (ActorFunc)BgSpot11Bakudankabe_Init,
	    (ActorFunc)BgSpot11Bakudankabe_Destroy,
	    (ActorFunc)BgSpot11Bakudankabe_Update,
	    (ActorFunc)BgSpot11Bakudankabe_Draw,
	    (ActorFunc)BgSpot11Bakudankabe_Reset,
	};

	sCylinderInit = {
	    {
		COLTYPE_NONE,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_NONE,
		OC2_TYPE_2,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK0,
		{0x00000000, 0x00, 0x00},
		{0x00000008, 0x00, 0x00},
		TOUCH_NONE,
		BUMP_ON,
		OCELEM_NONE,
	    },
	    {40, 80, 0, {2259, 108, -1580}},
	};

	D_808B272C = {2259.0f, 108.0f, -1550.0f};

	D_808B2738 = {2259.0f, 108.0f, -1550.0f};
}
