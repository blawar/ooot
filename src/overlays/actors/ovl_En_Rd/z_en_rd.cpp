#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_RD_Z_EN_RD_C
#include "actor_common.h"
#include "z_en_rd.h"
#include "def/code_800A9F30.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "objects/object_rd/object_rd.h"

#define FLAGS (ACTOR_FLAG_VISIBLE | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_10)

void EnRd_Init(Actor* thisx, GlobalContext* globalCtx);
void EnRd_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnRd_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnRd_Update(Actor* thisx, GlobalContext* globalCtx);
void EnRd_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80AE269C(EnRd* pthis);
void func_80AE2744(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE2970(EnRd* pthis);
void func_80AE2A10(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE2C1C(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE2F50(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE2FD0(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE31DC(EnRd* pthis);
void func_80AE3260(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE33F0(EnRd* pthis);
void func_80AE392C(EnRd* pthis);
void func_80AE39D4(EnRd* pthis);
void func_80AE3454(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE37BC(EnRd* pthis);
void func_80AE3834(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE3978(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE3A54(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE3B18(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE3C98(EnRd* pthis, GlobalContext* globalCtx);
void func_80AE3ECC(EnRd* pthis, GlobalContext* globalCtx);

ActorInit En_Rd_InitVars = {
    ACTOR_EN_RD, ACTORCAT_ENEMY, FLAGS, OBJECT_RD, ACTOR_FACTORY(EnRd), (ActorFunc)EnRd_Init, (ActorFunc)EnRd_Destroy, (ActorFunc)EnRd_Update, (ActorFunc)EnRd_Draw, (ActorFunc)EnRd_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
	COLTYPE_HIT0,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_PLAYER,
	OC2_TYPE_1,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK1,
	{0x00000000, 0x00, 0x00},
	{0xFFCFFFFF, 0x00, 0x00},
	TOUCH_NONE,
	BUMP_ON | BUMP_HOOKABLE,
	OCELEM_ON,
    },
    {20, 70, 0, {0, 0, 0}},
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(2, 0xF),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(0, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(0, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0xF),
    /* Hookshot      */ DMG_ENTRY(0, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(1, 0xF),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
    /* Fire arrow    */ DMG_ENTRY(0, 0x0),
    /* Ice arrow     */ DMG_ENTRY(0, 0x0),
    /* Light arrow   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(4, 0xE),
    /* Ice magic     */ DMG_ENTRY(0, 0x6),
    /* Light magic   */ DMG_ENTRY(3, 0xD),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0xF),
    /* Giant spin    */ DMG_ENTRY(4, 0xF),
    /* Master spin   */ DMG_ENTRY(2, 0xF),
    /* Kokiri jump   */ DMG_ENTRY(2, 0xF),
    /* Giant jump    */ DMG_ENTRY(8, 0xF),
    /* Master jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -3500, ICHAIN_STOP),
};

static Vec3f D_80AE4918 = {0.0f, 0.0f, 0.0f};

// I'm guessing these are primitive and environment colors that go unused
static Color_RGBA8 D_80AE4924 = {200, 200, 255, 255};
static Color_RGBA8 D_80AE4928 = {0, 0, 255, 0};

static Vec3f D_80AE492C = {0.0f, 0.0f, 0.0f};
static Color_RGBA8 D_80AE4938 = {200, 200, 255, 255};
static Color_RGBA8 D_80AE493C = {0, 0, 255, 0};

static Vec3f D_80AE4940 = {300.0f, 0.0f, 0.0f};
static Vec3f D_80AE494C = {300.0f, 0.0f, 0.0f};
static Vec3f D_80AE4958 = {0.25f, 0.25f, 0.25f};

void EnRd_SetupAction(EnRd* pthis, EnRdActionFunc actionFunc)
{
	pthis->actionFunc = actionFunc;
}

void EnRd_Init(Actor* thisx, GlobalContext* globalCtx)
{
	EnRd* pthis = (EnRd*)thisx;

	Actor_ProcessInitChain(thisx, sInitChain);
	thisx->targetMode = 0;
	thisx->colChkInfo.damageTable = &sDamageTable;
	ActorShape_Init(&thisx->shape, 0.0f, NULL, 0.0f);
	pthis->unk_310 = pthis->unk_30E = 0;
	thisx->focus.pos = thisx->world.pos;
	thisx->focus.pos.y += 50.0f;
	thisx->colChkInfo.mass = MASS_HEAVY;
	thisx->colChkInfo.health = 8;
	pthis->unk_314 = pthis->unk_31D = 0xFF;
	pthis->unk_312 = (thisx->params & 0xFF00) >> 8;

	if(thisx->params & 0x80)
	{
		thisx->params |= 0xFF00;
	}
	else
	{
		thisx->params &= 0xFF;
	}

	if(thisx->params >= -1)
	{
		SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_rd_Skel_00E778, &object_rd_Anim_0087D0, pthis->jointTable, pthis->morphTable, 26);
		thisx->naviEnemyId = 0x2A;
	}
	else
	{
		SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_rd_Skel_003DD8, &object_rd_Anim_0087D0, pthis->jointTable, pthis->morphTable, 26);
		thisx->naviEnemyId = 0x2D;
	}

	Collider_InitCylinder(globalCtx, &pthis->collider);
	Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sCylinderInit);

	if(thisx->params >= -2)
	{
		func_80AE269C(pthis);
	}
	else
	{
		func_80AE2970(pthis);
	}

	SkelAnime_Update(&pthis->skelAnime);

	if(thisx->params == 3)
	{
		thisx->flags |= ACTOR_FLAG_7;
	}
}

void EnRd_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	EnRd* pthis = (EnRd*)thisx;

	if(gSaveContext.sunsSongState != SUNSSONG_INACTIVE)
	{
		gSaveContext.sunsSongState = SUNSSONG_INACTIVE;
	}
	Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AE2630(GlobalContext* globalCtx, Actor* thisx, s32 arg2)
{
	Actor* enemyIt = globalCtx->actorCtx.actorLists[ACTORCAT_ENEMY].head;

	while(enemyIt != NULL)
	{
		if((enemyIt->id != ACTOR_EN_RD) || (enemyIt == thisx) || (enemyIt->params < 0))
		{
			enemyIt = enemyIt->next;
			continue;
		}

		if(arg2 != 0)
		{
			enemyIt->parent = thisx;
		}
		else if(enemyIt->parent == thisx)
		{
			enemyIt->parent = NULL;
		}
		enemyIt = enemyIt->next;
	}
}

void func_80AE269C(EnRd* pthis)
{
	if(pthis->actor.params != 2)
	{
		Animation_MorphToLoop(&pthis->skelAnime, &object_rd_Anim_0087D0, -6.0f);
	}
	else
	{
		Animation_PlayLoop(&pthis->skelAnime, &object_rd_Anim_005D98);
	}

	pthis->unk_31B = 0;
	pthis->unk_30C = (Rand_ZeroOne() * 10.0f) + 5.0f;
	pthis->actor.speedXZ = 0.0f;
	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	EnRd_SetupAction(pthis, func_80AE2744);
}

void func_80AE2744(EnRd* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	Math_SmoothStepToS(&pthis->unk_30E, 0, 1, 0x64, 0);
	Math_SmoothStepToS(&pthis->unk_310, 0, 1, 0x64, 0);

	if((pthis->actor.params == 2) && (0.0f == pthis->skelAnime.curFrame))
	{
		if(Rand_ZeroOne() >= 0.5f)
		{
			Animation_PlayLoop(&pthis->skelAnime, &object_rd_Anim_005D98);
		}
		else
		{
			Animation_PlayLoop(&pthis->skelAnime, &object_rd_Anim_0057AC);
		}
	}
	else
	{
		pthis->unk_30C--;
		if(pthis->unk_30C == 0)
		{
			pthis->unk_30C = (Rand_ZeroOne() * 10.0f) + 10.0f;
			pthis->skelAnime.curFrame = 0.0f;
		}
	}

	if(pthis->actor.parent != NULL)
	{
		if(pthis->unk_305 == 0)
		{
			if(pthis->actor.params != 2)
			{
				func_80AE31DC(pthis);
			}
			else
			{
				func_80AE392C(pthis);
			}
		}
	}
	else
	{
		if(pthis->unk_305 != 0)
		{
			if(pthis->actor.params != 2)
			{
				func_80AE37BC(pthis);
			}
			else
			{
				func_80AE392C(pthis);
			}
		}

		pthis->unk_305 = 0;
		if((pthis->actor.xzDistToPlayer <= 150.0f) && func_8002DDE4(globalCtx))
		{
			if((pthis->actor.params != 2) && (pthis->unk_305 == 0))
			{
				func_80AE37BC(pthis);
			}
			else
			{
				func_80AE392C(pthis);
			}
		}
	}

	if((globalCtx->gameplayFrames & 0x5F) == 0)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_CRY);
	}
}

void func_80AE2970(EnRd* pthis)
{
	Animation_Change(&pthis->skelAnime, &object_rd_Anim_0087D0, 0, 0, Animation_GetLastFrame(&object_rd_Anim_0087D0), ANIMMODE_LOOP, -6.0f);
	pthis->unk_31B = 11;
	pthis->unk_30C = 6;
	pthis->actor.shape.rot.x = -0x4000;
	pthis->actor.gravity = 0.0f;
	pthis->actor.shape.yOffset = 0.0f;
	pthis->actor.speedXZ = 0.0f;
	EnRd_SetupAction(pthis, func_80AE2A10);
}

// Rising out of coffin
void func_80AE2A10(EnRd* pthis, GlobalContext* globalCtx)
{
	if(pthis->actor.shape.rot.x != -0x4000)
	{
		Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0, 1, 0x7D0, 0);
		if(Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.3f, 2.0f, 0.3f) == 0.0f)
		{
			pthis->actor.gravity = -3.5f;
			func_80AE269C(pthis);
		}
	}
	else
	{
		if(pthis->actor.world.pos.y == pthis->actor.home.pos.y)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_CRY);
		}
		if(Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 50.0f, 0.3f, 2.0f, 0.3f) == 0.0f)
		{
			if(pthis->unk_30C != 0)
			{
				pthis->unk_30C--;
				Math_SmoothStepToF(&pthis->actor.speedXZ, 6.0f, 0.3f, 1.0f, 0.3f);
			}
			else if(Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.3f, 1.0f, 0.3f) == 0.0f)
			{
				Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0, 1, 0x7D0, 0);
			}
		}
	}
}

void StartPursuingTarget(EnRd* pthis, GlobalContext* globalCtx)
{
	Animation_Change(&pthis->skelAnime, &object_rd_Anim_00EFDC, 1.0f, 4.0f, Animation_GetLastFrame(&object_rd_Anim_00EFDC), ANIMMODE_LOOP_INTERP, -4.0f);
	pthis->actor.speedXZ = 0.4f;
	pthis->unk_31B = 4;
	EnRd_SetupAction(pthis, func_80AE2C1C);
}

void func_80AE2C1C(EnRd* pthis, GlobalContext* globalCtx)
{
	Vec3f sp44 = D_80AE4918;
	Color_RGBA8 sp40 = D_80AE4924;
	Color_RGBA8 sp3C = D_80AE4928;
	Player* player = GET_PLAYER(globalCtx);
	s32 pad;
	s16 sp32 = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y - pthis->unk_30E - pthis->unk_310;

	pthis->skelAnime.playSpeed = pthis->actor.speedXZ;
	Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA, 0);
	Math_SmoothStepToS(&pthis->unk_30E, 0, 1, 0x64, 0);
	Math_SmoothStepToS(&pthis->unk_310, 0, 1, 0x64, 0);
	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	SkelAnime_Update(&pthis->skelAnime);

	if(Actor_WorldDistXYZToPoint(&player->actor, &pthis->actor.home.pos) >= 150.0f)
	{
		func_80AE2F50(pthis, globalCtx);
	}

	if((ABS(sp32) < 0x1554) && (Actor_WorldDistXYZToActor(&pthis->actor, &player->actor) <= 150.0f))
	{
		if(!(player->stateFlags1 & (PLAYER_STATE1_DEAD | PLAYER_STATE1_13 | PLAYER_STATE1_14 | PLAYER_STATE1_18 | PLAYER_STATE1_19 | PLAYER_STATE1_21)) && !(player->stateFlags2 & PLAYER_STATE2_7))
		{
			if(pthis->unk_306 == 0)
			{
				if(!(pthis->unk_312 & 0x80))
				{
					player->actor.freezeTimer = 40;
					StartInvolintaryZtarget(globalCtx, &pthis->actor);
					GET_PLAYER(globalCtx)->unk_684 = &pthis->actor;
					Rumble_Shake(pthis->actor.xzDistToPlayer, 0xFF, 0x14, 0x96);
				}
				pthis->unk_306 = 0x3C;
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_AIM);
			}
		}
		else
		{
			func_80AE2F50(pthis, globalCtx);
		}
	}

	if(pthis->unk_307 != 0)
	{
		pthis->unk_307--;
	}

	if(!pthis->unk_307 && (Actor_WorldDistXYZToActor(&pthis->actor, &player->actor) <= 45.0f) && Actor_IsFacingPlayer(&pthis->actor, 0x38E3))
	{
		player->actor.freezeTimer = 0;
		if(globalCtx->grabPlayer(globalCtx, player))
		{
			pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
			func_80AE33F0(pthis);
		}
	}
	else if(pthis->actor.params > 0)
	{
		if(pthis->actor.parent != NULL)
		{
			func_80AE31DC(pthis);
		}
		else
		{
			pthis->unk_305 = 0;
		}
	}

	if((pthis->skelAnime.curFrame == 10.0f) || (pthis->skelAnime.curFrame == 22.0f))
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_WALK);
	}
	else if((globalCtx->gameplayFrames & 0x5F) == 0)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_CRY);
	}
}

void func_80AE2F50(EnRd* pthis, GlobalContext* globalCtx)
{
	Animation_Change(&pthis->skelAnime, &object_rd_Anim_00EFDC, 0.5f, 0, Animation_GetLastFrame(&object_rd_Anim_00EFDC), ANIMMODE_LOOP_INTERP, -4.0f);
	pthis->unk_31B = 2;
	EnRd_SetupAction(pthis, func_80AE2FD0);
}

void func_80AE2FD0(EnRd* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	s32 pad;
	s16 targetY = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos);

	if(Actor_WorldDistXYZToPoint(&pthis->actor, &pthis->actor.home.pos) >= 5.0f)
	{
		Math_SmoothStepToS(&pthis->actor.shape.rot.y, targetY, 1, 0x1C2, 0);
	}
	else
	{
		pthis->actor.speedXZ = 0.0f;
		if(Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y, 1, 0x1C2, 0) == 0)
		{
			if(pthis->actor.params != 2)
			{
				func_80AE269C(pthis);
			}
			else
			{
				func_80AE39D4(pthis);
			}
		}
	}

	Math_SmoothStepToS(&pthis->unk_30E, 0, 1, 0x64, 0);
	Math_SmoothStepToS(&pthis->unk_310, 0, 1, 0x64, 0);
	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	SkelAnime_Update(&pthis->skelAnime);

	if(!(player->stateFlags1 & (PLAYER_STATE1_DEAD | PLAYER_STATE1_13 | PLAYER_STATE1_14 | PLAYER_STATE1_18 | PLAYER_STATE1_19 | PLAYER_STATE1_21)) && !(player->stateFlags2 & PLAYER_STATE2_7) &&
	   (Actor_WorldDistXYZToPoint(&player->actor, &pthis->actor.home.pos) < 150.0f))
	{
		pthis->actor.targetMode = 0;
		StartPursuingTarget(pthis, globalCtx);
	}
	else if(pthis->actor.params > 0)
	{
		if(pthis->actor.parent != NULL)
		{
			func_80AE31DC(pthis);
		}
		else
		{
			pthis->unk_305 = 0;
		}
	}

	if(pthis->skelAnime.curFrame == 10.0f || pthis->skelAnime.curFrame == 22.0f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_WALK);
	}
	else if((globalCtx->gameplayFrames & 0x5F) == 0)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_CRY);
	}
}

void func_80AE31DC(EnRd* pthis)
{
	Animation_Change(&pthis->skelAnime, &object_rd_Anim_00EFDC, 0.5f, 0, Animation_GetLastFrame(&object_rd_Anim_00EFDC), ANIMMODE_LOOP_INTERP, -4.0f);
	pthis->unk_31B = 3;
	pthis->unk_305 = 1;
	EnRd_SetupAction(pthis, func_80AE3260);
}

void func_80AE3260(EnRd* pthis, GlobalContext* globalCtx)
{
	if(pthis->actor.parent != NULL)
	{
		s32 pad;
		s16 targetY;
		Vec3f thisPos = pthis->actor.parent->world.pos;

		targetY = Actor_WorldYawTowardPoint(&pthis->actor, &thisPos);

		Math_SmoothStepToS(&pthis->actor.shape.rot.y, targetY, 1, 0xFA, 0);

		if(Actor_WorldDistXYZToPoint(&pthis->actor, &thisPos) >= 45.0f)
		{
			pthis->actor.speedXZ = 0.4f;
		}
		else
		{
			pthis->actor.speedXZ = 0.0f;

			if(pthis->actor.params != 2)
			{
				func_80AE269C(pthis);
			}
			else
			{
				func_80AE39D4(pthis);
			}
		}

		Math_SmoothStepToS(&pthis->unk_30E, 0, 1, 0x64, 0);
		Math_SmoothStepToS(&pthis->unk_310, 0, 1, 0x64, 0);
	}
	else
	{
		StartPursuingTarget(pthis, globalCtx);
	}

	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	SkelAnime_Update(&pthis->skelAnime);

	if(pthis->skelAnime.curFrame == 10.0f || pthis->skelAnime.curFrame == 22.0f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_WALK);
	}
	else if((globalCtx->gameplayFrames & 0x5F) == 0)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_CRY);
	}
}

void func_80AE33F0(EnRd* pthis)
{
	Animation_PlayOnce(&pthis->skelAnime, &object_rd_Anim_004ADC);
	pthis->unk_30C = pthis->unk_304 = 0;
	pthis->unk_319 = 200;
	pthis->unk_31B = 8;
	pthis->actor.speedXZ = 0.0f;
	EnRd_SetupAction(pthis, func_80AE3454);
}

void func_80AE3454(EnRd* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	Player* player = GET_PLAYER(globalCtx);

	if(SkelAnime_Update(&pthis->skelAnime))
	{
		pthis->unk_304++;
	}

	if(pthis->unk_304.isWhole())
	{
		switch(pthis->unk_304.whole())
		{
			case 1:
				Animation_PlayLoop(&pthis->skelAnime, &object_rd_Anim_004268);
				pthis->unk_304++;
				globalCtx->damagePlayer(globalCtx, -8);
				Rumble_Shake(pthis->actor.xzDistToPlayer, 0xFF, 1, 0xC);
				pthis->unk_319 = 20;
			case 0:
				Math_SmoothStepToS(&pthis->unk_30E, 0, 1, 0x5DC, 0);
				Math_SmoothStepToS(&pthis->unk_310, 0, 1, 0x5DC, 0);
			case 2:
				if(!(player->stateFlags2 & PLAYER_STATE2_7))
				{
					Animation_Change(&pthis->skelAnime, &object_rd_Anim_0046F8, 0.5f, 0.0f, Animation_GetLastFrame(&object_rd_Anim_0046F8), ANIMMODE_ONCE_INTERP, 0.0f);
					pthis->unk_304++;
					pthis->unk_31B = 4;
					return;
				}

				if(!LINK_IS_ADULT)
				{
					Math_SmoothStepToF(&pthis->actor.shape.yOffset, -1500.0f, 1.0f, 150.0f, 0.0f);
				}

				Math_SmoothStepToF(&pthis->actor.world.pos.x, (Math_SinS(player->actor.shape.rot.y) * -25.0f) + player->actor.world.pos.x, 1.0f, 10.0f, 0.0f);
				Math_SmoothStepToF(&pthis->actor.world.pos.y, player->actor.world.pos.y, 1.0f, 10.0f, 0.0f);
				Math_SmoothStepToF(&pthis->actor.world.pos.z, (Math_CosS(player->actor.shape.rot.y) * -25.0f) + player->actor.world.pos.z, 1.0f, 10.0f, 0.0f);
				Math_SmoothStepToS(&pthis->actor.shape.rot.y, player->actor.shape.rot.y, 1, 0x1770, 0);

				if(pthis->skelAnime.curFrame == 0.0f)
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_ATTACK);
				}
				pthis->unk_319--;

				if(pthis->unk_319 == 0)
				{
					globalCtx->damagePlayer(globalCtx, -8);
					Rumble_Shake(pthis->actor.xzDistToPlayer, 0xF0, 1, 0xC);
					pthis->unk_319 = 20;
					func_8002F7DC(&player->actor, NA_SE_VO_LI_DAMAGE_S + player->ageProperties->unk_92);
				}
				break;
			case 3:
				if(!LINK_IS_ADULT)
				{
					Math_SmoothStepToF(&pthis->actor.shape.yOffset, 0, 1.0f, 400.0f, 0.0f);
				}
				break;
			case 4:
				if(!LINK_IS_ADULT)
				{
					Math_SmoothStepToF(&pthis->actor.shape.yOffset, 0, 1.0f, 400.0f, 0.0f);
				}
				pthis->actor.targetMode = 0;
				pthis->actor.flags |= ACTOR_FLAG_VISIBLE;
				pthis->unk_306 = 0xA;
				pthis->unk_307 = 0xF;
				StartPursuingTarget(pthis, globalCtx);
				break;
		}
	}
}

void func_80AE37BC(EnRd* pthis)
{
	Animation_Change(&pthis->skelAnime, &object_rd_Anim_004F94, 0.0f, 0.0f, Animation_GetLastFrame(&object_rd_Anim_004F94), ANIMMODE_ONCE, 0.0f);
	pthis->unk_31B = 7;
	EnRd_SetupAction(pthis, func_80AE3834);
}

void func_80AE3834(EnRd* pthis, GlobalContext* globalCtx)
{
	Vec3f sp34 = D_80AE492C;
	Color_RGBA8 sp30 = D_80AE4938;
	Color_RGBA8 sp2C = D_80AE493C;
	Player* player = GET_PLAYER(globalCtx);
	s16 temp_v0 = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y - pthis->unk_30E - pthis->unk_310;

	if(ABS(temp_v0) < 0x2008)
	{
		if(!(pthis->unk_312 & 0x80))
		{
			player->actor.freezeTimer = 60;
			Rumble_Shake(pthis->actor.xzDistToPlayer, 0xFF, 0x14, 0x96);
			StartInvolintaryZtarget(globalCtx, &pthis->actor);
		}
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_AIM);
		StartPursuingTarget(pthis, globalCtx);
	}
}

void func_80AE392C(EnRd* pthis)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_rd_Anim_008040, -4.0f);
	pthis->unk_31B = 5;
	EnRd_SetupAction(pthis, func_80AE3978);
}

void func_80AE3978(EnRd* pthis, GlobalContext* globalCtx)
{
	if(SkelAnime_Update(&pthis->skelAnime))
	{
		if(pthis->actor.parent != NULL)
		{
			func_80AE31DC(pthis);
		}
		else
		{
			func_80AE37BC(pthis);
		}
	}
}

void func_80AE39D4(EnRd* pthis)
{
	Animation_Change(&pthis->skelAnime, &object_rd_Anim_008040, -1.0f, Animation_GetLastFrame(&object_rd_Anim_008040), 0.0f, ANIMMODE_ONCE, -4.0f);
	pthis->unk_31B = 6;
	EnRd_SetupAction(pthis, func_80AE3A54);
}

void func_80AE3A54(EnRd* pthis, GlobalContext* globalCtx)
{
	if(SkelAnime_Update(&pthis->skelAnime))
	{
		func_80AE269C(pthis);
	}
}

void func_80AE3A8C(EnRd* pthis)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_rd_Anim_0074F0, -6.0f);

	if(pthis->actor.bgCheckFlags & BG_STATE_0)
	{
		pthis->actor.speedXZ = -2.0f;
	}

	pthis->actor.flags |= ACTOR_FLAG_VISIBLE;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_DAMAGE);
	pthis->unk_31B = 9;
	EnRd_SetupAction(pthis, func_80AE3B18);
}

void func_80AE3B18(EnRd* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	if(pthis->actor.speedXZ < 0.0f)
	{
		pthis->actor.speedXZ += 0.15f;
	}

	pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
	Math_SmoothStepToS(&pthis->unk_30E, 0, 1, 0x12C, 0);
	Math_SmoothStepToS(&pthis->unk_310, 0, 1, 0x12C, 0);
	if(SkelAnime_Update(&pthis->skelAnime))
	{
		pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

		if(pthis->actor.parent != NULL)
		{
			func_80AE31DC(pthis);
		}
		else if(Actor_WorldDistXYZToPoint(&player->actor, &pthis->actor.home.pos) >= 150.0f)
		{
			func_80AE2F50(pthis, globalCtx);
		}
		else
		{
			StartPursuingTarget(pthis, globalCtx);
		}

		pthis->unk_31D = 0xFF;
	}
}

void func_80AE3C20(EnRd* pthis)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_rd_Anim_006E88, -1.0f);
	pthis->unk_31B = 10;
	pthis->unk_30C = 300;
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	pthis->actor.speedXZ = 0.0f;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_REDEAD_DEAD);
	EnRd_SetupAction(pthis, func_80AE3C98);
}

void func_80AE3C98(EnRd* pthis, GlobalContext* globalCtx)
{
	if(pthis->actor.category != ACTORCAT_PROP)
	{
		Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
	}

	Math_SmoothStepToS(&pthis->unk_30E, 0, 1, 0x7D0, 0);
	Math_SmoothStepToS(&pthis->unk_310, 0, 1, 0x7D0, 0);

	if(SkelAnime_Update(&pthis->skelAnime))
	{
		if(pthis->unk_30C == 0)
		{
			if(!Flags_GetSwitch(globalCtx, pthis->unk_312 & 0x7F))
			{
				Flags_SetSwitch(globalCtx, pthis->unk_312 & 0x7F);
			}
			if(pthis->unk_314 != 0)
			{
				if(pthis->unk_314 == 0xB4)
				{
					func_80AE2630(globalCtx, &pthis->actor, 0);
				}
				pthis->actor.scale.y -= 0.000075f;
				pthis->unk_314 -= 5;
			}
			else
			{
				Actor_Kill(&pthis->actor);
			}
		}
		else
		{
			pthis->unk_30C--;
		}
	}
	else if(((s32)pthis->skelAnime.curFrame == 33) || ((s32)pthis->skelAnime.curFrame == 40))
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
	}
}

void func_80AE3DE4(EnRd* pthis)
{
	pthis->unk_31B = 1;
	pthis->actor.speedXZ = 0.0f;
	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	if(gSaveContext.sunsSongState != SUNSSONG_INACTIVE)
	{
		pthis->unk_318 = 1;
		pthis->unk_316 = 0x258;
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_LIGHT_ARROW_HIT);
		Actor_SetColorFilter(&pthis->actor, -0x8000, -0x7F38, 0, 0xFF);
	}
	else if(pthis->unk_31C == 1)
	{
		Actor_SetColorFilter(&pthis->actor, 0, 0xC8, 0, 0x50);
	}
	else
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_LIGHT_ARROW_HIT);
		Actor_SetColorFilter(&pthis->actor, -0x8000, 0xC8, 0, 0x50);
	}
	EnRd_SetupAction(pthis, func_80AE3ECC);
}

void func_80AE3ECC(EnRd* pthis, GlobalContext* globalCtx)
{
	if((pthis->unk_318 != 0) && (pthis->unk_316 != 0))
	{
		pthis->unk_316--;
		if(pthis->unk_316 >= 0xFF)
		{
			Actor_SetColorFilter(&pthis->actor, -0x8000, 0xC8, 0, 0xFF);
		}
		if(pthis->unk_316 == 0)
		{
			pthis->unk_318 = 0;
			gSaveContext.sunsSongState = SUNSSONG_INACTIVE;
		}
	}

	if(pthis->actor.colorFilterTimer == 0)
	{
		if(pthis->actor.colChkInfo.health == 0)
		{
			func_80AE2630(globalCtx, &pthis->actor, 1);
			func_80AE3C20(pthis);
			Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x90);
		}
		else
		{
			func_80AE3A8C(pthis);
		}
	}
}

void func_80AE3F9C(EnRd* pthis, GlobalContext* globalCtx)
{
	s16 temp1;
	s16 temp2;
	s16 temp3;

	temp1 = pthis->actor.yawTowardsPlayer - (s16)(pthis->actor.shape.rot.y + pthis->unk_310);
	temp2 = CLAMP(temp1, -500, 500);

	temp1 -= pthis->unk_30E;
	temp3 = CLAMP(temp1, -500, 500);

	if((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y) >= 0)
	{
		pthis->unk_310 += ABS(temp2);
		pthis->unk_30E += ABS(temp3);
	}
	else
	{
		pthis->unk_310 -= ABS(temp2);
		pthis->unk_30E -= ABS(temp3);
	}

	pthis->unk_310 = CLAMP(pthis->unk_310, -18783, 18783);
	pthis->unk_30E = CLAMP(pthis->unk_30E, -9583, 9583);
}

void func_80AE4114(EnRd* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	Player* player = GET_PLAYER(globalCtx);

	if((gSaveContext.sunsSongState != SUNSSONG_INACTIVE) && (pthis->actor.shape.rot.x == 0) && (pthis->unk_318 == 0) && (pthis->unk_31B != 9) && (pthis->unk_31B != 10) && (pthis->unk_31B != 1))
	{
		func_80AE3DE4(pthis);
		return;
	}

	if(pthis->collider.base.acFlags & AC_HIT)
	{
		pthis->collider.base.acFlags &= ~AC_HIT;
		pthis->unk_31C = pthis->actor.colChkInfo.damageEffect;

		if(pthis->unk_31B != 11)
		{
			Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);
			if(player->unk_844 != 0)
			{
				pthis->unk_31D = player->unk_845;
			}

			if((pthis->unk_31C != 0) && (pthis->unk_31C != 6))
			{
				if(((pthis->unk_31C == 1) || (pthis->unk_31C == 13)) && (pthis->unk_31B != 1))
				{
					Actor_ApplyDamage(&pthis->actor);
					func_80AE3DE4(pthis);
					return;
				}

				pthis->unk_318 = 0;
				pthis->unk_316 = 0;

				if(pthis->unk_31C == 0xE)
				{
					Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0x50);
					pthis->unk_31A = 0x28;
				}
				else
				{
					Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
				}

				Actor_ApplyDamage(&pthis->actor);
				if(pthis->actor.colChkInfo.health == 0)
				{
					func_80AE2630(globalCtx, &pthis->actor, 1);
					func_80AE3C20(pthis);
					Item_DropCollectibleRandom(globalCtx, 0, &pthis->actor.world.pos, 0x90);
				}
				else
				{
					func_80AE3A8C(pthis);
				}
			}
		}
	}
}

void EnRd_Update(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	EnRd* pthis = (EnRd*)thisx;
	Player* player = GET_PLAYER(globalCtx);
	s32 pad2;

	func_80AE4114(pthis, globalCtx);

	if(gSaveContext.sunsSongState != SUNSSONG_INACTIVE && pthis->unk_318 == 0)
	{
		gSaveContext.sunsSongState = SUNSSONG_INACTIVE;
	}

	if(pthis->unk_31C != 6 && ((pthis->unk_31B != 11) || (pthis->unk_31C != 14)))
	{
		if(pthis->unk_306 != 0)
		{
			pthis->unk_306--;
		}

		pthis->actionFunc(pthis, globalCtx);
		if(pthis->unk_31B != 8 && pthis->actor.speedXZ != 0.0f)
		{
			Actor_MoveForward(&pthis->actor);
		}

		if((pthis->actor.shape.rot.x == 0) && (pthis->unk_31B != 8) && (pthis->actor.speedXZ != 0.0f))
		{
			Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 30.0f, 20.0f, 35.0f, 0x1D);
		}

		if(pthis->unk_31B == 7)
		{
			func_80AE3F9C(pthis, globalCtx);
		}
	}

	pthis->actor.focus.pos = pthis->actor.world.pos;
	pthis->actor.focus.pos.y += 50.0f;

	if((pthis->actor.colChkInfo.health > 0) && (pthis->unk_31B != 8))
	{
		Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
		CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
		if((pthis->unk_31B != 9) || ((player->unk_844 != 0) && (player->unk_845 != pthis->unk_31D)))
		{
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
		}
	}
}

s32 EnRd_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx, Gfx** gfx)
{
	EnRd* pthis = (EnRd*)thisx;

	if(limbIndex == 23)
	{
		rot->y += pthis->unk_30E;
	}
	else if(limbIndex == 12)
	{
		rot->y += pthis->unk_310;
	}
	return false;
}

void EnRd_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx)
{
	Vec3f sp2C = D_80AE4940;
	EnRd* pthis = (EnRd*)thisx;
	s32 idx = -1;
	Vec3f destPos;

	if((pthis->unk_31A != 0) || ((pthis->actor.colorFilterTimer != 0) && (pthis->actor.colorFilterParams & 0x4000)))
	{
		switch(limbIndex - 1)
		{
			case 23:
				idx = 0;
				break;
			case 0:
				idx = 1;
				break;
			case 21:
				idx = 2;
				break;
			case 17:
				idx = 3;
				break;
			case 13:
				idx = 4;
				break;
			case 24:
				idx = 5;
				break;
			case 8:
				idx = 6;
				break;
			case 3:
				idx = 7;
				break;
			case 10:
				idx = 8;
				break;
			case 5:
				idx = 9;
				break;
		}

		if(idx >= 0)
		{
			Matrix_MultVec3f(&sp2C, &destPos);
			pthis->firePos[idx].x = destPos.x;
			pthis->firePos[idx].y = destPos.y;
			pthis->firePos[idx].z = destPos.z;
		}
	}
}

void EnRd_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	EnRd* pthis = (EnRd*)thisx;
	Vec3f thisPos = thisx->world.pos;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_rd.c", 1679);

	if(pthis->unk_314 == 0xFF)
	{
		func_80093D18(globalCtx->gfxCtx);
		gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, pthis->unk_314);
		gSPSegment(POLY_OPA_DISP++, 8, &D_80116280[2]);
		POLY_OPA_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, EnRd_OverrideLimbDraw, EnRd_PostLimbDraw, pthis, POLY_OPA_DISP);
		func_80033C30(&thisPos, &D_80AE4958, 255, globalCtx);
		if(pthis->unk_31A != 0)
		{
			thisx->colorFilterTimer++;
			pthis->unk_31A--;
			if(pthis->unk_31A.isWhole() && pthis->unk_31A % 4 == 0)
			{
				EffectSsEnFire_SpawnVec3s(globalCtx, thisx, &pthis->firePos[pthis->unk_31A >> 2], 0x4B, 0, 0, (pthis->unk_31A >> 2));
			}
		}
	}
	else
	{
		func_80093D84(globalCtx->gfxCtx);
		gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->unk_314);
		gSPSegment(POLY_XLU_DISP++, 8, &D_80116280[0]);
		POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, EnRd_OverrideLimbDraw, NULL, pthis, POLY_XLU_DISP);

		func_80033C30(&thisPos, &D_80AE4958, pthis->unk_314, globalCtx);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_rd.c", 1735);
}

void EnRd_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	En_Rd_InitVars = {
	    ACTOR_EN_RD, ACTORCAT_ENEMY, FLAGS, OBJECT_RD, ACTOR_FACTORY(EnRd), (ActorFunc)EnRd_Init, (ActorFunc)EnRd_Destroy, (ActorFunc)EnRd_Update, (ActorFunc)EnRd_Draw, (ActorFunc)EnRd_Reset,
	};

	sCylinderInit = {
	    {
		COLTYPE_HIT0,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_PLAYER,
		OC2_TYPE_1,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK1,
		{0x00000000, 0x00, 0x00},
		{0xFFCFFFFF, 0x00, 0x00},
		TOUCH_NONE,
		BUMP_ON | BUMP_HOOKABLE,
		OCELEM_ON,
	    },
	    {20, 70, 0, {0, 0, 0}},
	};

	sDamageTable = {
	    /* Deku nut      */ DMG_ENTRY(0, 0x0),
	    /* Deku stick    */ DMG_ENTRY(2, 0xF),
	    /* Slingshot     */ DMG_ENTRY(0, 0x0),
	    /* Explosive     */ DMG_ENTRY(0, 0x0),
	    /* Boomerang     */ DMG_ENTRY(0, 0x0),
	    /* Normal arrow  */ DMG_ENTRY(0, 0x0),
	    /* Hammer swing  */ DMG_ENTRY(2, 0xF),
	    /* Hookshot      */ DMG_ENTRY(0, 0x1),
	    /* Kokiri sword  */ DMG_ENTRY(1, 0xF),
	    /* Master sword  */ DMG_ENTRY(2, 0xF),
	    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
	    /* Fire arrow    */ DMG_ENTRY(0, 0x0),
	    /* Ice arrow     */ DMG_ENTRY(0, 0x0),
	    /* Light arrow   */ DMG_ENTRY(0, 0x0),
	    /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
	    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
	    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
	    /* Fire magic    */ DMG_ENTRY(4, 0xE),
	    /* Ice magic     */ DMG_ENTRY(0, 0x6),
	    /* Light magic   */ DMG_ENTRY(3, 0xD),
	    /* Shield        */ DMG_ENTRY(0, 0x0),
	    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
	    /* Kokiri spin   */ DMG_ENTRY(1, 0xF),
	    /* Giant spin    */ DMG_ENTRY(4, 0xF),
	    /* Master spin   */ DMG_ENTRY(2, 0xF),
	    /* Kokiri jump   */ DMG_ENTRY(2, 0xF),
	    /* Giant jump    */ DMG_ENTRY(8, 0xF),
	    /* Master jump   */ DMG_ENTRY(4, 0xF),
	    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
	    /* Unblockable   */ DMG_ENTRY(0, 0x0),
	    /* Hammer jump   */ DMG_ENTRY(4, 0xF),
	    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
	};

	D_80AE4918 = {0.0f, 0.0f, 0.0f};

	D_80AE4924 = {200, 200, 255, 255};

	D_80AE4928 = {0, 0, 255, 0};

	D_80AE492C = {0.0f, 0.0f, 0.0f};

	D_80AE4938 = {200, 200, 255, 255};

	D_80AE493C = {0, 0, 255, 0};

	D_80AE4940 = {300.0f, 0.0f, 0.0f};

	D_80AE494C = {300.0f, 0.0f, 0.0f};

	D_80AE4958 = {0.25f, 0.25f, 0.25f};
}
