#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DEMO_6K_Z_DEMO_6K_C
#include "actor_common.h"
/*
 * File: z_demo_6k.c
 * Overlay: ovl_Demo_6K
 * Description: Sages, balls of light (cutscene)
 */

#include "overlays/actors/ovl_Eff_Dust/z_eff_dust.h"
#include "vt.h"
#include "z_demo_6k.h"
#include "def/audio.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_demo_6k/object_demo_6k.h"
#include "objects/object_gnd_magic/object_gnd_magic.h"

#define FLAGS ACTOR_FLAG_4

void Demo6K_Init(Actor* thisx, GlobalContext* globalCtx);
void Demo6K_Reset(Actor* pthisx, GlobalContext* globalCtx);
void Demo6K_Destroy(Actor* thisx, GlobalContext* globalCtx);
void Demo6K_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80966DB0(Demo6K* pthis, GlobalContext* globalCtx);
void func_80966E04(Demo6K* pthis, GlobalContext* globalCtx);
void func_80966E98(Demo6K* pthis, GlobalContext* globalCtx);
void func_80966F84(Demo6K* pthis, GlobalContext* globalCtx);
void func_8096712C(Demo6K* pthis, GlobalContext* globalCtx);
void func_80967410(Demo6K* pthis, GlobalContext* globalCtx);
void func_809674E0(Demo6K* pthis, GlobalContext* globalCtx);
void func_8096784C(Demo6K* pthis, GlobalContext* globalCtx);
void func_80967A04(Demo6K* pthis, s32 i);
void func_80967AD0(Demo6K* pthis, GlobalContext* globalCtx);
void func_80967DBC(Demo6K* pthis, GlobalContext* globalCtx);
void func_80967F10(Demo6K* pthis, GlobalContext* globalCtx);
void func_80967FFC(Actor* thisx, GlobalContext* globalCtx);
void func_80968298(Actor* thisx, GlobalContext* globalCtx);
void func_8096865C(Actor* thisx, GlobalContext* globalCtx);
void func_809688C4(Actor* thisx, GlobalContext* globalCtx);
void func_80968B70(Actor* thisx, GlobalContext* globalCtx);
void func_80968FB0(Actor* thisx, GlobalContext* globalCtx);
void func_809691BC(Demo6K* pthis, GlobalContext* globalCtx, s32 params);

static u16 D_8096932C_58[] = {275, 275, 275, 275, 275, 275};

static Vec3f velocity_59 = {0.0f, 0.0f, 0.0f};

static Vec3f accel_59 = {0.0f, 0.0f, 0.0f};

static Color_RGBA8 primColor_59 = {255, 255, 255, 0};

static Color_RGBA8 envColor_59 = {255, 150, 0, 0};

static Vec3f velocity_62 = {0.0f, 0.0f, 0.0f};

static Vec3f accel_62 = {0.0f, 0.0f, 0.0f};

static Color_RGBA8 primColor_62 = {255, 255, 255, 0};

static Color_RGBA8 envColor_62 = {255, 150, 0, 0};

static Vec3f velocity_66 = {0.0f, 0.0f, 0.0f};

static Vec3f accel_66 = {0.0f, 0.0f, 0.0f};

static Color_RGBA8 primColor_66 = {255, 255, 255, 0};

static Color_RGBA8 envColor_66 = {255, 200, 0, 0};

static u8 skipIndices_71[] = {6, 7, 11, 16, 20, 24, 28, 33, 35, 41, 45, 50, 57, 58, 62, 255};

static u8 D_809693CC_75[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1};

ActorInit Demo_6K_InitVars = {
    ACTOR_DEMO_6K, ACTORCAT_PROP, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(Demo6K), (ActorFunc)Demo6K_Init, (ActorFunc)Demo6K_Destroy, (ActorFunc)Demo6K_Update, NULL, (ActorFunc)Demo6K_Reset,
};

static s16 sObjectIds[] = {
    OBJECT_GAMEPLAY_KEEP, OBJECT_DEMO_6K,	OBJECT_DEMO_6K,	  OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP,
    OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GND_MAGIC, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP, OBJECT_GAMEPLAY_KEEP,
};
static Color_RGB8 sEnvColors[] = {
    {255, 50, 0}, {0, 200, 0}, {200, 255, 0}, {200, 50, 255}, {255, 150, 0}, {0, 150, 255},
};
static f32 D_8096930C[] = {1.0f, 1.04f, 1.0f, 0.96f};
static f32 D_8096931C[] = {1.1f, 1.0f, 0.9f, 0.8f};

void Demo6K_SetupAction(Demo6K* pthis, Demo6KActionFunc actionFunc)
{
	pthis->actionFunc = actionFunc;
}

void Demo6K_Init(Actor* thisx, GlobalContext* globalCtx)
{
	Demo6K* pthis = (Demo6K*)thisx;
	s32 pad;
	s32 params = pthis->actor.params;
	s32 objBankIndex;
	s32 i;

	osSyncPrintf("no = %d\n", params);

	if(sObjectIds[params] != OBJECT_GAMEPLAY_KEEP)
	{
		objBankIndex = Object_GetIndex(&globalCtx->objectCtx, sObjectIds[params]);
	}
	else
	{
		objBankIndex = 0;
	}

	osSyncPrintf("bank_ID = %d\n", objBankIndex);

	if(objBankIndex < 0)
	{
		ASSERT(0, "0", "../z_demo_6k.c", 334);
	}
	else
	{
		pthis->objBankIndex = objBankIndex;
	}

	Demo6K_SetupAction(pthis, func_80966DB0);
	pthis->timer1 = 0;
	pthis->flags = 0;
	pthis->timer2 = 0;

	switch(params)
	{
		case 0:
			pthis->drawFunc = func_809688C4;
			pthis->initActionFunc = func_80967AD0;
			Actor_SetScale(&pthis->actor, 1.0f);

			for(i = 0; i < 16; i++)
			{
				func_80967A04(pthis, i);
				pthis->unk_1B4[i] = 0.0f;
			}

			pthis->unk_170 = 0.0f;
			break;
		case 1:
			pthis->drawFunc = func_80967FFC;
			pthis->initActionFunc = func_80966E04;
			Actor_SetScale(&pthis->actor, 0.228f);
			break;
		case 2:
			pthis->drawFunc = func_80968298;
			pthis->initActionFunc = func_80966F84;
			Actor_SetScale(&pthis->actor, 0.1f);
			pthis->unk_164 = 1.0f;
			pthis->unk_168 = 1.0f;
			pthis->unk_16C = 0.0f;
			pthis->unk_170 = 0.0f;
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			pthis->drawFunc = func_8096865C;
			pthis->initActionFunc = func_8096712C;
			Actor_SetScale(&pthis->actor, 0.0f);
			pthis->unk_293 = params - 3;
			break;
		case 9:
		case 10:
			pthis->drawFunc = func_8096865C;
			Actor_SetScale(&pthis->actor, 0.0f);
			pthis->initActionFunc = func_809674E0;
			break;
		case 11:
			pthis->drawFunc = func_8096865C;
			Actor_SetScale(&pthis->actor, 0.0f);
			pthis->initActionFunc = func_8096784C;
			pthis->actor.velocity.x = pthis->actor.velocity.y = pthis->actor.velocity.z = 0.0f;
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_NABALL_VANISH);
			break;
		case 12:
			Actor_SetScale(&pthis->actor, 0.0f);
			pthis->initActionFunc = func_80967F10;
			pthis->drawFunc = func_80968B70;
			Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ITEMACTION);
			break;
		case 13:
			Actor_SetScale(&pthis->actor, 0.14f);
			Demo6K_SetupAction(pthis, func_80967DBC);
			pthis->actor.draw = func_80968FB0;
			pthis->unk_293 = 0;
			break;
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
			pthis->actor.flags |= ACTOR_FLAG_5;
			pthis->drawFunc = func_8096865C;
			pthis->initActionFunc = func_80967410;
			pthis->flags |= 1;
			Actor_SetScale(&pthis->actor, 0.2f);
			pthis->unk_293 = params - 14;
			break;
		default:
			ASSERT(0, "0", "../z_demo_6k.c", 435);
			break;
	}

	switch(params)
	{
		case 9:
			pthis->unk_293 = 0;
			break;
		case 10:
			pthis->unk_293 = 5;
			break;
		case 11:
			pthis->unk_293 = 4;
			break;
	}

	Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 255, 255, 255, 100);
	pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
}

void Demo6K_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	Demo6K* pthis = (Demo6K*)thisx;

	LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
}

void func_80966DB0(Demo6K* pthis, GlobalContext* globalCtx)
{
	if(Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex))
	{
		pthis->actor.objBankIndex = pthis->objBankIndex;
		pthis->actor.draw = pthis->drawFunc;
		pthis->actionFunc = pthis->initActionFunc;
	}
}

void func_80966E04(Demo6K* pthis, GlobalContext* globalCtx)
{
	if(globalCtx->csCtx.frames > 214)
	{
		func_8002F948(&pthis->actor, NA_SE_EV_LIGHT_GATHER - SFX_FLAG);
	}

	if(globalCtx->csCtx.frames > 264)
	{
		func_8002F948(&pthis->actor, NA_SE_EV_GOD_LIGHTBALL_2 - SFX_FLAG);
	}

	if((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[6] != NULL) && (globalCtx->csCtx.npcActions[6]->action == 2))
	{
		Demo6K_SetupAction(pthis, func_80966E98);
	}
}

void func_80966E98(Demo6K* pthis, GlobalContext* globalCtx)
{
	if(globalCtx->csCtx.frames < 353)
	{
		func_8002F948(&pthis->actor, NA_SE_EV_LIGHT_GATHER - SFX_FLAG);
		func_8002F948(&pthis->actor, NA_SE_EV_GOD_LIGHTBALL_2 - SFX_FLAG);
	}

	if(globalCtx->csCtx.frames == 342)
	{
		func_800F3F3C(2);
	}

	if(pthis->timer1 == 39)
	{
		Common_PlaySfx2(NA_SE_EV_CONSENTRATION);
		Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DEMO_6K, pthis->actor.world.pos.x, pthis->actor.world.pos.y + 10.0f, pthis->actor.world.pos.z, 0, 0, 0, 2);
	}

	if(pthis->timer1 == 64)
	{
		Actor_Kill(&pthis->actor);
	}

	pthis->timer1++;
}

void func_80966F84(Demo6K* pthis, GlobalContext* globalCtx)
{
	if(pthis->timer1 < 5)
	{
		pthis->unk_168 = D_8096930C[pthis->timer1 & 3];
	}
	else if(pthis->timer1 < 15)
	{
		pthis->actor.scale.x += 0.012f;
		Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
		Math_StepToF(&pthis->unk_170, 0.6f, 0.05f);
		pthis->unk_168 = 1.0f;
	}
	else
	{
		if(pthis->timer1 == 15)
		{
			Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EFF_DUST, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, EFF_DUST_TYPE_1);
		}
		Math_StepToF(&pthis->unk_16C, 1.0f, 0.02f);
		pthis->unk_168 = D_8096930C[pthis->timer1 & 1];
	}

	pthis->timer1++;
}

void func_809670AC(Demo6K* pthis, GlobalContext* globalCtx)
{
	pthis->timer2++;

	if(pthis->timer1 < 10)
	{
		pthis->timer1++;
	}
	else if(pthis->actor.scale.x > 0.0f)
	{
		pthis->actor.scale.x -= 1.0f / 120.0f;
		Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
	}
	else
	{
		Actor_Kill(&pthis->actor);
	}
}

void func_8096712C(Demo6K* pthis, GlobalContext* globalCtx)
{
	const auto& frames = globalCtx->frames;

	if(pthis->actor.scale.x < 0.1f)
	{
		pthis->actor.scale.x += 0.0017f;
	}
	else if(frames & 1)
	{
		pthis->actor.scale.x = 0.1f * 1.04f;
	}
	else
	{
		pthis->actor.scale.x = 0.1f;
	}

	if((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[6] != NULL) && (globalCtx->csCtx.npcActions[6]->action == 2))
	{
		Demo6K_SetupAction(pthis, func_809670AC);
		pthis->timer1 = 0;
		pthis->actor.scale.x = 0.1f;
	}

	Actor_SetScale(&pthis->actor, pthis->actor.scale.x);

	pthis->timer2++;

	if((globalCtx->sceneNum == SCENE_GANONTIKA) && (globalCtx->csCtx.frames < D_8096932C_58[pthis->actor.params - 3]))
	{
		func_8002F974(&pthis->actor, NA_SE_EV_LIGHT_GATHER - SFX_FLAG);
	}
}

void func_80967244(Demo6K* pthis, GlobalContext* globalCtx)
{
	Vec3f pos;
	s16 rand1;
	s16 rand2;
	s32 scale;

	pos.x = pthis->actor.world.pos.x;
	pos.y = pthis->actor.world.pos.y;
	pos.z = pthis->actor.world.pos.z;

	rand1 = Rand_ZeroFloat(0xFFFF);
	rand2 = Rand_ZeroFloat(0xFFFF);

	velocity_59.x = Math_SinS(rand2) * Math_CosS(rand1) * 20.0f;
	velocity_59.z = Math_CosS(rand2) * Math_CosS(rand1) * 20.0f;
	velocity_59.y = Math_SinS(rand1) * 20.0f;

	accel_59.y = 0.0f;

	envColor_59.r = sEnvColors[pthis->unk_293].r;
	envColor_59.g = sEnvColors[pthis->unk_293].g;
	envColor_59.b = sEnvColors[pthis->unk_293].b;

	if(globalCtx->sceneNum == SCENE_TOKINOMA)
	{
		scale = 6000;
	}
	else if(globalCtx->csCtx.frames < 419)
	{
		scale = 6000;
	}
	else
	{
		scale = 18000;
	}

	EffectSsKiraKira_SpawnFocused(globalCtx, &pos, &velocity_59, &accel_59, &primColor_59, &envColor_59, scale, 20);
}

void func_80967410(Demo6K* pthis, GlobalContext* globalCtx)
{
	s32 params = pthis->actor.params - 14;

	pthis->timer2++;

	Actor_SetScale(&pthis->actor, 0.2f);

	if((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[params] != NULL))
	{
		func_809691BC(pthis, globalCtx, params);

		if(globalCtx->csCtx.npcActions[params]->action == 3)
		{
			pthis->flags &= ~1;
			func_80967244(pthis, globalCtx);
		}
		else
		{
			pthis->flags |= 1;
		}
	}
	else
	{
		pthis->flags |= 1;
	}
}

void func_809674E0(Demo6K* pthis, GlobalContext* globalCtx)
{
	const auto& frames = globalCtx->frames;

	if(pthis->actor.scale.x < 0.05f)
	{
		pthis->actor.scale.x += 0.005f;
	}
	else if(frames & 1)
	{
		pthis->actor.scale.x = 0.05f * 1.04f;
	}
	else
	{
		pthis->actor.scale.x = 0.05f;
	}

	Actor_SetScale(&pthis->actor, pthis->actor.scale.x);

	pthis->timer2++;

	if(pthis->timer2 > 47)
	{
		Actor_Kill(&pthis->actor);
	}
	else if(pthis->timer2 > 39)
	{
		f32 dTimer = pthis->timer2 - 39;
		f32 temp = 1.0f / (9.0f - dTimer);

		pthis->actor.world.pos.x += (-1611.0f - pthis->actor.world.pos.x) * temp;
		pthis->actor.world.pos.y += (19.0f - pthis->actor.world.pos.y) * temp;
		pthis->actor.world.pos.z += (1613.0f - pthis->actor.world.pos.z) * temp;

		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_FIRE - SFX_FLAG);
	}

	Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, sEnvColors[pthis->unk_293].r, sEnvColors[pthis->unk_293].g, sEnvColors[pthis->unk_293].b, pthis->actor.scale.x * 4000.0f);
}

void func_809676A4(Demo6K* pthis, GlobalContext* globalCtx)
{
	Vec3f pos;
	f32 temp = pthis->actor.scale.x * 500.0f;
	s32 i;

	for(i = 0; i < 8; i++)
	{
		pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(temp);
		pos.y = pthis->actor.world.pos.y + Rand_CenteredFloat(temp);
		pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(temp);

		velocity_62.x = Rand_CenteredFloat(2.0f);
		velocity_62.y = (Rand_ZeroFloat(-10.0f) - 5.0f) * 0.1f;
		velocity_62.z = Rand_CenteredFloat(2.0f);

		accel_62.y = 0.0f;

		EffectSsKiraKira_SpawnFocused(globalCtx, &pos, &velocity_62, &accel_62, &primColor_62, &envColor_62, 500, 20);
	}
}

void func_8096784C(Demo6K* pthis, GlobalContext* globalCtx)
{
	const auto& frames = globalCtx->frames;

	pthis->timer2++;

	if(pthis->timer2 > 24)
	{
		Actor_Kill(&pthis->actor);
	}
	else if(pthis->timer2 > 4)
	{
		pthis->actor.velocity.x += Rand_CenteredFloat(0.2f);
		pthis->actor.velocity.y += 0.12f;
		pthis->actor.velocity.z += Rand_CenteredFloat(0.2f);

		pthis->actor.world.pos.x += pthis->actor.velocity.x;
		pthis->actor.world.pos.y += pthis->actor.velocity.y;
		pthis->actor.world.pos.z += pthis->actor.velocity.z;

		pthis->actor.scale.x -= 0.0015f;

		func_809676A4(pthis, globalCtx);
	}
	else if(frames & 1)
	{
		pthis->actor.scale.x = 0.033f;
	}
	else
	{
		pthis->actor.scale.x = 0.03f;
	}

	Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
	Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, sEnvColors[pthis->unk_293].r, sEnvColors[pthis->unk_293].g, sEnvColors[pthis->unk_293].b, pthis->actor.scale.x * 4000.0f);
}

void func_80967A04(Demo6K* pthis, s32 i)
{
	pthis->unk_174[i] = (i * 10.0f) - 80.0f;
	pthis->unk_1B4[i] = Rand_ZeroFloat(100.0f) + 100.0f;
	pthis->unk_1F4[i] = -3.0f - Rand_ZeroFloat(6.0f);
	pthis->unk_274[i] = (s32)Rand_ZeroFloat(6.0f);
	pthis->unk_234[i] = Rand_ZeroFloat(0.02f) + 0.01f;
}

void func_80967AD0(Demo6K* pthis, GlobalContext* globalCtx)
{
	s32 i;

	if((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[1] != NULL))
	{
		if(globalCtx->csCtx.npcActions[1]->action == 2)
		{
			pthis->unk_170++;
			func_8002F948(&pthis->actor, NA_SE_EV_RAINBOW_SHOWER - SFX_FLAG);
		}

		func_809691BC(pthis, globalCtx, 1);
	}

	for(i = 0; (i < (s32)pthis->unk_170) && (i < 16); i++)
	{
		pthis->unk_1B4[i] += pthis->unk_1F4[i];
		if(pthis->unk_1B4[i] < 0.0f)
		{
			func_80967A04(pthis, i);
		}
	}

	pthis->timer1++;
}

void func_80967BF8(Player* player, GlobalContext* globalCtx)
{
	Vec3f pos;
	s32 i;

	for(i = 0; i < 150; i++)
	{
		pos.x = Rand_CenteredFloat(15.0f) + player->actor.world.pos.x;
		pos.y = Rand_CenteredFloat(15.0f) + player->actor.world.pos.y + 30.0f;
		pos.z = Rand_CenteredFloat(15.0f) + player->actor.world.pos.z;

		velocity_66.x = Rand_CenteredFloat(8.0f) + 1.0f;
		velocity_66.y = Rand_CenteredFloat(4.0f);
		velocity_66.z = Rand_CenteredFloat(8.0f) + 2.0f;

		accel_66.y = 0.0f;

		EffectSsKiraKira_SpawnFocused(globalCtx, &pos, &velocity_66, &accel_66, &primColor_66, &envColor_66, 1000, (s32)Rand_ZeroFloat(60.0f) + 60);
	}
}

void func_80967DBC(Demo6K* pthis, GlobalContext* globalCtx)
{
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_ATTACK_DEMO - SFX_FLAG);

	pthis->timer2++;

	if(pthis->timer2 > 44)
	{
		if(pthis->unk_293 < 236)
		{
			pthis->unk_293 += 20;
		}
		else
		{
			pthis->unk_293 = 255;
		}

		if(pthis->timer2 > 104)
		{
			func_80967BF8(GET_PLAYER(globalCtx), globalCtx);
			Actor_Kill(&pthis->actor);
			Audio_PlayActorSound2(&GET_PLAYER(globalCtx)->actor, NA_SE_EN_FANTOM_HIT_THUNDER);
		}
		else if(pthis->timer2 > 94)
		{
			Actor_SetScale(&pthis->actor, pthis->actor.scale.x + 0.03f);

			if(pthis->timer2 == 95)
			{
				osSyncPrintf(VT_FGCOL(CYAN) "  NA_SE_EN_GANON_FIRE_DEMO\n" VT_RST);
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_FIRE_DEMO);
			}
		}

		Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 255, 200, 0, pthis->unk_293);
	}
}

void func_80967F10(Demo6K* pthis, GlobalContext* globalCtx)
{
	if(pthis->timer2 == 0)
	{
		Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DEMO_6K, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 13);
	}

	pthis->timer2++;

	if(pthis->timer2 > 60)
	{
		Actor_Kill(&pthis->actor);
	}

	Actor_SetScale(&pthis->actor, 0.05f - (pthis->timer2 * 0.00075f));
}

void Demo6K_Update(Actor* thisx, GlobalContext* globalCtx)
{
	Demo6K* pthis = (Demo6K*)thisx;

	pthis->actionFunc(pthis, globalCtx);
}

void func_80967FFC(Actor* thisx, GlobalContext* globalCtx)
{
	Demo6K* pthis = (Demo6K*)thisx;
	s32 pad;
	u16 timer1 = pthis->timer1;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1070);

	func_80093D84(globalCtx->gfxCtx);
	Matrix_RotateX(-M_PI / 2, MTXMODE_APPLY);
	gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 0, 0x7FFF - ((timer1 * 8) & 0x7FFF), 16, 512, 1, 0, 0x7FFF - ((timer1 * 8) & 0x7FFF), 16, 32));

	{
		s32 i;
		s32 pad;
		Color_RGB8 colors[6][2] = {
		    {{255, 170, 255}, {255, 0, 100}}, {{255, 255, 170}, {0, 255, 0}}, {{255, 255, 170}, {255, 255, 0}}, {{255, 170, 255}, {50, 0, 255}}, {{255, 255, 170}, {255, 100, 0}}, {{170, 255, 255}, {0, 100, 255}},
		};

		Matrix_RotateZ(-M_PI / 2, MTXMODE_APPLY);

		for(i = 0; i < 6; i++)
		{
			Matrix_RotateZ(M_PI / 3, MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_demo_6k.c", 1115), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gDPPipeSync(POLY_XLU_DISP++);
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, colors[i][0].r, colors[i][0].g, colors[i][0].b, 255);
			gDPSetEnvColor(POLY_XLU_DISP++, colors[i][1].r, colors[i][1].g, colors[i][1].b, 255);
			gSPDisplayList(POLY_XLU_DISP++, object_demo_6k_DL_0022B0);
		}

		// required to avoid optimizing out i
		if((s16)i)
		{
		}
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1127);
}

void func_80968298(Actor* thisx, GlobalContext* globalCtx)
{
	Demo6K* pthis = (Demo6K*)thisx;
	s32 pad;
	u32 timer1 = pthis->timer1;
	f32 scale = pthis->unk_164 * pthis->unk_168;
	Vtx* vertices = SEGMENTED_TO_VIRTUAL(object_demo_6kVtx_0035E0);
	s32 i;
	s32 i2;
	u8 alpha;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1145);

	alpha = (s32)(pthis->unk_170 * 255.0f);
	POLY_XLU_DISP = func_800937C0(POLY_XLU_DISP);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, alpha);
	gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_DISABLE);
	gDPSetColorDither(POLY_XLU_DISP++, G_CD_DISABLE);
	gDPFillRectangle(POLY_XLU_DISP++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
	func_80093D84(globalCtx->gfxCtx);

	alpha = (s32)(pthis->unk_16C * 255.0f);
	for(i2 = 0, i = 0; i < 63; i++)
	{
		if(i == skipIndices_71[i2])
		{
			i2++;
		}
		else
		{
			vertices[i].v.cn[3] = alpha;
		}
	}

	Matrix_RotateX(-M_PI / 2, MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_demo_6k.c", 1170), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 210, 210, 210, 255);
	gDPSetEnvColor(POLY_XLU_DISP++, 100, 100, 100, 255);
	gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, (0xFFF - (timer1 * 6)) & 0xFFF, (timer1 * 12) & 0xFFF, 128, 64, 1, (0xFFF - (timer1 * 6)) & 0xFFF, (timer1 * 12) & 0xFFF, 64, 32));
	gSPDisplayList(POLY_XLU_DISP++, object_demo_6k_DL_0039D0);
	Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_demo_6k.c", 1189), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	func_80093D84(globalCtx->gfxCtx);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
	gDPSetEnvColor(POLY_XLU_DISP++, 50, 50, 50, 255);
	gSPDisplayList(POLY_XLU_DISP++, object_demo_6k_DL_001040);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1198);
}

void func_8096865C(Actor* thisx, GlobalContext* globalCtx)
{
	Demo6K* pthis = (Demo6K*)thisx;
	s32 pad;
	Gfx* displayList;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1208);

	if(!(pthis->flags & 1))
	{
		if(pthis->actor.params > 8)
		{
			displayList = gEffFlash1DL;
		}
		else
		{
			displayList = gEffFlash2DL;
		}

		func_80093D84(globalCtx->gfxCtx);
		gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 255, 255);
		gDPSetEnvColor(POLY_XLU_DISP++, sEnvColors[pthis->unk_293].r, sEnvColors[pthis->unk_293].g, sEnvColors[pthis->unk_293].b, 255);
		Matrix_Mult(&globalCtx->billboardMtxF, MTXMODE_APPLY);
		Matrix_Push();
		Matrix_RotateZ((f32)(pthis->timer2 * 6) * (M_PI / 180.0f), MTXMODE_APPLY);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_demo_6k.c", 1230), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, displayList);
		Matrix_Pop();
		Matrix_RotateZ(-(f32)(pthis->timer2 * 6) * (M_PI / 180.0f), MTXMODE_APPLY);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_demo_6k.c", 1236), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, displayList);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1242);
}

void func_809688C4(Actor* thisx, GlobalContext* globalCtx2)
{
	Demo6K* pthis = (Demo6K*)thisx;
	GlobalContext* globalCtx = globalCtx2;
	const auto& frames = globalCtx->frames;
	s32 i;

	if((i = (globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[1] != NULL)) && (globalCtx->csCtx.npcActions[1]->action != 1))
	{
		OPEN_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1277);

		func_80093D84(globalCtx->gfxCtx);
		gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 255, 255);
		Matrix_RotateY((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000) * (M_PI / 0x8000), MTXMODE_APPLY);

		for(i = 0; i < 16; i++)
		{
			gDPPipeSync(POLY_XLU_DISP++);
			gDPSetEnvColor(POLY_XLU_DISP++, sEnvColors[pthis->unk_274[i]].r, sEnvColors[pthis->unk_274[i]].g, sEnvColors[pthis->unk_274[i]].b, 255);
			Matrix_Push();
			Matrix_Translate(pthis->unk_174[i], pthis->unk_1B4[i], 0.0f, MTXMODE_APPLY);
			s32 idx = ((s32)frames + i) & 3;
			Matrix_Scale(pthis->unk_234[i] * D_8096931C[idx], pthis->unk_234[i] * D_8096931C[idx], pthis->unk_234[i] * D_8096931C[idx], MTXMODE_APPLY);
			func_800D1FD4(&globalCtx->billboardMtxF);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_demo_6k.c", 1297), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, gEffFlash1DL);
			Matrix_Pop();
		}

		gSPDisplayList(POLY_XLU_DISP++, gEffFlash1DL);

		CLOSE_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1305);
	}
}

void func_80968B70(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	Demo6K* pthis = (Demo6K*)thisx;
	u32 timer2 = pthis->timer2;
	u8 primColor[4];
	u8 envColor[3];

	if(1)
	{
	}

	OPEN_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1316);

	func_80093D84(globalCtx->gfxCtx);
	Matrix_Mult(&globalCtx->billboardMtxF, MTXMODE_APPLY);
	Matrix_RotateX(M_PI / 2, MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_demo_6k.c", 1322), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 0xFF - ((timer2 * 2) & 0xFF), 0, 32, 32, 1, 0xFF - ((timer2 * 2) & 0xFF), (timer2 * 15) & 0x3FF, 16, 64));

	if(pthis->timer2 < 40)
	{
		primColor[0] = primColor[2] = 100 - (pthis->timer2 * 2.5f);
		primColor[1] = envColor[1] = 0;
		envColor[0] = 100 - primColor[2];
		primColor[3] = pthis->timer2 * 6.375f;
		envColor[2] = envColor[0] * 2;
	}
	else if(pthis->timer2 < 50)
	{
		primColor[0] = (pthis->timer2 * 5) - 200;
		primColor[1] = primColor[2] = 0;
		primColor[3] = 255;
		envColor[0] = 100 - primColor[0];
		envColor[1] = primColor[0] * 2;
		envColor[2] = 200 - (primColor[0] * 4);
	}
	else
	{
		primColor[2] = (pthis->timer2 * 5) - 250;
		envColor[2] = 0;
		primColor[1] = primColor[2] * 3;
		primColor[3] = 255;
		primColor[0] = envColor[0] = (primColor[2] * 2) + 50;
		envColor[1] = 100 - primColor[2];
	}

	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, primColor[0], primColor[1], primColor[2], primColor[3]);
	gDPSetEnvColor(POLY_XLU_DISP++, envColor[0], envColor[1], envColor[2], 128);
	gSPDisplayList(POLY_XLU_DISP++, object_gnd_magic_DL_001190);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1368);
}

void func_80968FB0(Actor* thisx, GlobalContext* globalCtx)
{
	Demo6K* pthis = (Demo6K*)thisx;
	Gfx* displayList = (Gfx*)Graph_Alloc(globalCtx->gfxCtx, 4 * sizeof(Gfx));
	u16 frames = globalCtx->gameplayFrames;
	f32 scaleFactor;
	s32 pad;

	if(1)
	{
	}

	OPEN_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1386);

	func_80093D84(globalCtx->gfxCtx);
	scaleFactor = ((s16)D_809693CC_75[(frames * 4) & 0xF] * 0.01f) + 1.0f;
	Matrix_Scale(pthis->actor.scale.x * scaleFactor, pthis->actor.scale.y * scaleFactor, pthis->actor.scale.z * scaleFactor, MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_demo_6k.c", 1394), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPSegment(POLY_XLU_DISP++, 0x08, displayList);
	gDPPipeSync(displayList++);
	gDPSetPrimColor(displayList++, 0, 0x80, 255, 255, 255, pthis->unk_293);
	gDPSetRenderMode(displayList++, G_RM_PASS, G_RM_ZB_CLD_SURF2);
	gSPEndDisplayList(displayList++);
	gDPSetEnvColor(POLY_XLU_DISP++, 255, 200, 0, 255);
	gSPDisplayList(POLY_XLU_DISP++, gGlowCircleSmallDL);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_demo_6k.c", 1411);
}

void func_809691BC(Demo6K* pthis, GlobalContext* globalCtx, s32 params)
{
	Vec3f startPos;
	Vec3f endPos;
	f32 temp;
	CsCmdActorAction* csAction = globalCtx->csCtx.npcActions[params];

	startPos.x = csAction->startPos.x;
	startPos.y = csAction->startPos.y;
	startPos.z = csAction->startPos.z;

	endPos.x = csAction->endPos.x;
	endPos.y = csAction->endPos.y;
	endPos.z = csAction->endPos.z;

	temp = Environment_LerpWeight(csAction->endFrame, csAction->startFrame, globalCtx->csCtx.frames);

	pthis->actor.world.pos.x = (((endPos.x - startPos.x) * temp) + startPos.x);
	pthis->actor.world.pos.y = (((endPos.y - startPos.y) * temp) + startPos.y);
	pthis->actor.world.pos.z = (((endPos.z - startPos.z) * temp) + startPos.z);
}

void Demo6K_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	velocity_59 = {0.0f, 0.0f, 0.0f};

	accel_59 = {0.0f, 0.0f, 0.0f};

	primColor_59 = {255, 255, 255, 0};

	envColor_59 = {255, 150, 0, 0};

	velocity_62 = {0.0f, 0.0f, 0.0f};

	accel_62 = {0.0f, 0.0f, 0.0f};

	primColor_62 = {255, 255, 255, 0};

	envColor_62 = {255, 150, 0, 0};

	velocity_66 = {0.0f, 0.0f, 0.0f};

	accel_66 = {0.0f, 0.0f, 0.0f};

	primColor_66 = {255, 255, 255, 0};

	envColor_66 = {255, 200, 0, 0};

	Demo_6K_InitVars = {
	    ACTOR_DEMO_6K, ACTORCAT_PROP, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(Demo6K), (ActorFunc)Demo6K_Init, (ActorFunc)Demo6K_Destroy, (ActorFunc)Demo6K_Update, NULL, (ActorFunc)Demo6K_Reset,
	};
}
