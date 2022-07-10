#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_WF_Z_EN_WF_C
#include "actor_common.h"
/*
 * File: z_en_wf.c
 * Overlay: ovl_En_Wf
 * Description: Wolfos (Normal and White)
 */

#include "overlays/actors/ovl_En_Encount1/z_en_encount1.h"
#include "vt.h"
#include "z_en_wf.h"
#include "def/audio.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "objects/object_wf/object_wf.h"

#define FLAGS (ACTOR_FLAG_VISIBLE | ACTOR_FLAG_2 | ACTOR_FLAG_4)

void EnWf_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWf_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnWf_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWf_Update(Actor* thisx, GlobalContext* globalCtx);
void EnWf_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnWf_SetupWaitToAppear(EnWf* pthis);
void EnWf_WaitToAppear(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupWait(EnWf* pthis);
void EnWf_Wait(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupRunAtPlayer(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_RunAtPlayer(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupSearchForPlayer(EnWf* pthis);
void EnWf_SearchForPlayer(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupRunAroundPlayer(EnWf* pthis);
void EnWf_RunAroundPlayer(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupSlash(EnWf* pthis);
void EnWf_Slash(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_RecoilFromBlockedSlash(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupBackflipAway(EnWf* pthis);
void EnWf_BackflipAway(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_Stunned(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_Damaged(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupSomersaultAndAttack(EnWf* pthis);
void EnWf_SomersaultAndAttack(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupBlocking(EnWf* pthis);
void EnWf_Blocking(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupSidestep(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_Sidestep(EnWf* pthis, GlobalContext* globalCtx);
void EnWf_SetupDie(EnWf* pthis);
void EnWf_Die(EnWf* pthis, GlobalContext* globalCtx);
s32 EnWf_DodgeRanged(GlobalContext* globalCtx, EnWf* pthis);

static Vec3f colliderVec_94 = {1200.0f, 0.0f, 0.0f};

static Vec3f bodyPartVec_94 = {0.0f, 0.0f, 0.0f};

static ColliderJntSphElementInit sJntSphItemsInit[4] = {
    {
	{
	    ELEMTYPE_UNK0,
	    {0xFFCFFFFF, 0x00, 0x04},
	    {0x00000000, 0x00, 0x00},
	    TOUCH_ON | TOUCH_SFX_NORMAL,
	    BUMP_NONE,
	    OCELEM_NONE,
	},
	{WOLFOS_LIMB_FRONT_RIGHT_CLAW, {{0, 0, 0}, 15}, 100},
    },
    {
	{
	    ELEMTYPE_UNK0,
	    {0xFFCFFFFF, 0x00, 0x04},
	    {0x00000000, 0x00, 0x00},
	    TOUCH_ON | TOUCH_SFX_NORMAL,
	    BUMP_NONE,
	    OCELEM_NONE,
	},
	{WOLFOS_LIMB_FRONT_LEFT_CLAW, {{0, 0, 0}, 15}, 100},
    },
    {
	{
	    ELEMTYPE_UNK1,
	    {0x00000000, 0x00, 0x00},
	    {0xFFC1FFFF, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON | BUMP_HOOKABLE,
	    OCELEM_ON,
	},
	{WOLFOS_LIMB_HEAD, {{800, 0, 0}, 25}, 100},
    },
    {
	{
	    ELEMTYPE_UNK1,
	    {0x00000000, 0x00, 0x00},
	    {0xFFC1FFFF, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON | BUMP_HOOKABLE,
	    OCELEM_ON,
	},
	{WOLFOS_LIMB_THORAX, {{0, 0, 0}, 30}, 100},
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
	COLTYPE_METAL,
	AT_ON | AT_TYPE_ENEMY,
	AC_ON | AC_HARD | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_ALL,
	OC2_TYPE_1,
	COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(sJntSphItemsInit),
    sJntSphItemsInit,
};

static ColliderCylinderInit sBodyCylinderInit = {
    {
	COLTYPE_HIT5,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_NONE,
	OC2_NONE,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK1,
	{0x00000000, 0x00, 0x00},
	{0xFFCFFFFF, 0x00, 0x00},
	TOUCH_NONE,
	BUMP_ON,
	OCELEM_NONE,
    },
    {20, 50, 0, {0, 0, 0}},
};

static ColliderCylinderInit sTailCylinderInit = {
    {
	COLTYPE_HIT5,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_NONE,
	OC2_NONE,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK1,
	{0x00000000, 0x00, 0x00},
	{0xFFCFFFFF, 0x00, 0x00},
	TOUCH_NONE,
	BUMP_ON,
	OCELEM_NONE,
    },
    {15, 20, -15, {0, 0, 0}},
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, ENWF_DMGEFF_STUN),
    /* Deku stick    */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Slingshot     */ DMG_ENTRY(1, ENWF_DMGEFF_NONE),
    /* Explosive     */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Boomerang     */ DMG_ENTRY(0, ENWF_DMGEFF_STUN),
    /* Normal arrow  */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Hammer swing  */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Hookshot      */ DMG_ENTRY(0, ENWF_DMGEFF_STUN),
    /* Kokiri sword  */ DMG_ENTRY(1, ENWF_DMGEFF_NONE),
    /* Master sword  */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Giant's Knife */ DMG_ENTRY(4, ENWF_DMGEFF_NONE),
    /* Fire arrow    */ DMG_ENTRY(4, ENWF_DMGEFF_FIRE),
    /* Ice arrow     */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Light arrow   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Unk arrow 1   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Unk arrow 2   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Unk arrow 3   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Fire magic    */ DMG_ENTRY(4, ENWF_DMGEFF_FIRE),
    /* Ice magic     */ DMG_ENTRY(0, ENWF_DMGEFF_ICE_MAGIC),
    /* Light magic   */ DMG_ENTRY(3, ENWF_DMGEFF_LIGHT_MAGIC),
    /* Shield        */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
    /* Mirror Ray    */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
    /* Kokiri spin   */ DMG_ENTRY(1, ENWF_DMGEFF_NONE),
    /* Giant spin    */ DMG_ENTRY(4, ENWF_DMGEFF_NONE),
    /* Master spin   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Kokiri jump   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
    /* Giant jump    */ DMG_ENTRY(8, ENWF_DMGEFF_NONE),
    /* Master jump   */ DMG_ENTRY(4, ENWF_DMGEFF_NONE),
    /* Unknown 1     */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
    /* Unblockable   */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
    /* Hammer jump   */ DMG_ENTRY(4, ENWF_DMGEFF_NONE),
    /* Unknown 2     */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
};

ActorInit En_Wf_InitVars = {
    ACTOR_EN_WF, ACTORCAT_ENEMY, FLAGS, OBJECT_WF, ACTOR_FACTORY(EnWf), (ActorFunc)EnWf_Init, (ActorFunc)EnWf_Destroy, (ActorFunc)EnWf_Update, (ActorFunc)EnWf_Draw, (ActorFunc)EnWf_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -3000, ICHAIN_STOP),
};

void EnWf_SetupAction(EnWf* pthis, EnWfActionFunc actionFunc)
{
	pthis->actionFunc = actionFunc;
}

void EnWf_Init(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	EnWf* pthis = (EnWf*)thisx;

	Actor_ProcessInitChain(thisx, sInitChain);
	thisx->colChkInfo.damageTable = &sDamageTable;
	ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
	thisx->focus.pos = thisx->world.pos;
	thisx->colChkInfo.mass = MASS_HEAVY;
	thisx->colChkInfo.health = 8;
	thisx->colChkInfo.cylRadius = 50;
	thisx->colChkInfo.cylHeight = 100;
	pthis->switchFlag = (thisx->params >> 8) & 0xFF;
	thisx->params &= 0xFF;
	pthis->eyeIndex = 0;
	pthis->unk_2F4 = 10.0f; // Set and not used

	Collider_InitJntSph(globalCtx, &pthis->colliderSpheres);
	Collider_SetJntSph(globalCtx, &pthis->colliderSpheres, thisx, &sJntSphInit, pthis->colliderSpheresElements);
	Collider_InitCylinder(globalCtx, &pthis->colliderCylinderBody);
	Collider_SetCylinder(globalCtx, &pthis->colliderCylinderBody, thisx, &sBodyCylinderInit);
	Collider_InitCylinder(globalCtx, &pthis->colliderCylinderTail);
	Collider_SetCylinder(globalCtx, &pthis->colliderCylinderTail, thisx, &sTailCylinderInit);

	if(thisx->params == WOLFOS_NORMAL)
	{
		SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gWolfosNormalSkel, &gWolfosWaitingAnim, pthis->jointTable, pthis->morphTable, WOLFOS_LIMB_MAX);
		Actor_SetScale(thisx, 0.0075f);
		thisx->naviEnemyId = 0x4C; // Wolfos
	}
	else
	{ // WOLFOS_WHITE
		SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gWolfosWhiteSkel, &gWolfosWaitingAnim, pthis->jointTable, pthis->morphTable, WOLFOS_LIMB_MAX);
		Actor_SetScale(thisx, 0.01f);
		pthis->colliderSpheres.elements[0].info.toucher.damage = pthis->colliderSpheres.elements[1].info.toucher.damage = 8;
		thisx->naviEnemyId = 0x57; // White Wolfos
	}

	EnWf_SetupWaitToAppear(pthis);

	if((pthis->switchFlag != 0xFF) && Flags_GetSwitch(globalCtx, pthis->switchFlag))
	{
		Actor_Kill(thisx);
	}
}

void EnWf_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	EnWf* pthis = (EnWf*)thisx;

	Collider_DestroyJntSph(globalCtx, &pthis->colliderSpheres);
	Collider_DestroyCylinder(globalCtx, &pthis->colliderCylinderBody);
	Collider_DestroyCylinder(globalCtx, &pthis->colliderCylinderTail);

	if((pthis->actor.params != WOLFOS_NORMAL) && (pthis->switchFlag != 0xFF))
	{
		func_800F5B58();
	}

	if(pthis->actor.parent != NULL)
	{
		EnEncount1* parent = (EnEncount1*)pthis->actor.parent;

		if(parent->actor.update != NULL)
		{
			if(parent->curNumSpawn > 0)
			{
				parent->curNumSpawn--;
			}

			osSyncPrintf("\n\n");
			// "☆☆☆☆☆ Number of concurrent events ☆☆☆☆☆"
			osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 同時発生数 ☆☆☆☆☆%d\n" VT_RST, parent->curNumSpawn);
			osSyncPrintf("\n\n");
		}
	}
}

s32 EnWf_ChangeAction(GlobalContext* globalCtx, EnWf* pthis, s16 mustChoose)
{
	Player* player = GET_PLAYER(globalCtx);
	s32 pad;
	s16 wallYawDiff;
	s16 playerYawDiff;
	Actor* explosive;

	wallYawDiff = pthis->actor.wallYaw - pthis->actor.shape.rot.y;
	wallYawDiff = ABS(wallYawDiff);
	playerYawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
	playerYawDiff = ABS(playerYawDiff);

	if(func_800354B4(globalCtx, &pthis->actor, 100.0f, 0x2710, 0x2EE0, pthis->actor.shape.rot.y))
	{
		if(player->swordAnimation == 0x11)
		{
			EnWf_SetupBlocking(pthis);
			return true;
		}

		if((globalCtx->gameplayFrames % 2) != 0)
		{
			EnWf_SetupBlocking(pthis);
			return true;
		}
	}

	if(func_800354B4(globalCtx, &pthis->actor, 100.0f, 0x5DC0, 0x2AA8, pthis->actor.shape.rot.y))
	{
		pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

		if((pthis->actor.bgCheckFlags & BG_STATE_3) && (ABS(wallYawDiff) < 0x2EE0) && (pthis->actor.xzDistToPlayer < 120.0f))
		{
			EnWf_SetupSomersaultAndAttack(pthis);
			return true;
		}
		else if(player->swordAnimation == 0x11)
		{
			EnWf_SetupBlocking(pthis);
			return true;
		}
		else if((pthis->actor.xzDistToPlayer < 80.0f) && (globalCtx->gameplayFrames % 2) != 0)
		{
			EnWf_SetupBlocking(pthis);
			return true;
		}
		else
		{
			EnWf_SetupBackflipAway(pthis);
			return true;
		}
	}

	explosive = Actor_FindNearby(globalCtx, &pthis->actor, -1, ACTORCAT_EXPLOSIVE, 80.0f);

	if(explosive != NULL)
	{
		pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

		if(((pthis->actor.bgCheckFlags & BG_STATE_3) && (wallYawDiff < 0x2EE0)) || (explosive->id == ACTOR_EN_BOM_CHU))
		{
			if((explosive->id == ACTOR_EN_BOM_CHU) && (Actor_WorldDistXYZToActor(&pthis->actor, explosive) < 80.0f) && (s16)((pthis->actor.shape.rot.y - explosive->world.rot.y) + 0x8000) < 0x3E80)
			{
				EnWf_SetupSomersaultAndAttack(pthis);
				return true;
			}
			else
			{
				EnWf_SetupSidestep(pthis, globalCtx);
				return true;
			}
		}
		else
		{
			EnWf_SetupBackflipAway(pthis);
			return true;
		}
	}

	if(mustChoose)
	{
		s16 playerFacingAngleDiff;

		if(playerYawDiff >= 0x1B58)
		{
			EnWf_SetupSidestep(pthis, globalCtx);
			return true;
		}

		playerFacingAngleDiff = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

		if((pthis->actor.xzDistToPlayer <= 80.0f) && !Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (((globalCtx->gameplayFrames % 8) != 0) || (ABS(playerFacingAngleDiff) < 0x38E0)))
		{
			EnWf_SetupSlash(pthis);
			return true;
		}

		EnWf_SetupRunAroundPlayer(pthis);
		return true;
	}
	return false;
}

void EnWf_SetupWaitToAppear(EnWf* pthis)
{
	Animation_Change(&pthis->skelAnime, &gWolfosRearingUpFallingOverAnim, 0.5f, 0.0f, 7.0f, ANIMMODE_ONCE_INTERP, 0.0f);
	pthis->actor.world.pos.y = pthis->actor.home.pos.y - 5.0f;
	pthis->actionTimer = 20;
	pthis->unk_300 = false;
	pthis->action = WOLFOS_ACTION_WAIT_TO_APPEAR;
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	pthis->actor.scale.y = 0.0f;
	pthis->actor.gravity = 0.0f;
	EnWf_SetupAction(pthis, EnWf_WaitToAppear);
}

void EnWf_WaitToAppear(EnWf* pthis, GlobalContext* globalCtx)
{
	if(pthis->actionTimer >= 6)
	{
		pthis->actor.world.pos.y = pthis->actor.home.pos.y - 5.0f;

		if(pthis->actor.xzDistToPlayer < 240.0f)
		{
			pthis->actionTimer = 5;
			pthis->actor.flags |= ACTOR_FLAG_VISIBLE;

			if((pthis->actor.params != WOLFOS_NORMAL) && (pthis->switchFlag != 0xFF))
			{
				func_800F5ACC(0x38); // Mini-Boss Battle Theme
			}
		}
	}
	else if(pthis->actionTimer != 0)
	{
		pthis->actor.scale.y += pthis->actor.scale.x * 0.2f * FRAMERATE_SCALER;
		pthis->actor.world.pos.y += 0.5f * FRAMERATE_SCALER;
		Math_SmoothStepToF(&pthis->actor.shape.shadowScale, 70.0f, 1.0f, 14.0f, 0.0f);
		pthis->actionTimer--;

		if(pthis->actionTimer == 0)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_APPEAR);
		}
	}
	else
	{ // actionTimer == 0
		if(SkelAnime_Update(&pthis->skelAnime))
		{
			pthis->actor.scale.y = pthis->actor.scale.x;
			pthis->actor.gravity = -2.0f;
			EnWf_SetupWait(pthis);
		}
	}
}

void EnWf_SetupWait(EnWf* pthis)
{
	Animation_MorphToLoop(&pthis->skelAnime, &gWolfosWaitingAnim, -4.0f);
	pthis->action = WOLFOS_ACTION_WAIT;
	pthis->actionTimer = (Rand_ZeroOne() * 10.0f) + 2.0f;
	pthis->actor.speedXZ = 0.0f;
	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	EnWf_SetupAction(pthis, EnWf_Wait);
}

void EnWf_Wait(EnWf* pthis, GlobalContext* globalCtx)
{
	Player* player;
	s32 pad;
	s16 angle;

	player = GET_PLAYER(globalCtx);
	SkelAnime_Update(&pthis->skelAnime);

	if(pthis->unk_2E2 != 0)
	{
		angle = (pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y) - pthis->unk_4D4.y;

		if(ABS(angle) > 0x2000)
		{
			pthis->unk_2E2--;
			return;
		}

		pthis->unk_2E2 = 0;
	}

	angle = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
	angle = ABS(angle);

	if(!EnWf_DodgeRanged(globalCtx, pthis))
	{
		// Only use of unk_2E0: never not zero, so pthis if block never runs
		if(pthis->unk_2E0 != 0)
		{
			pthis->unk_2E0--;

			if(angle >= 0x1FFE)
			{
				return;
			}
			pthis->unk_2E0 = 0;
		}
		else
		{
			if(EnWf_ChangeAction(globalCtx, pthis, false))
			{
				return;
			}
		}

		angle = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
		angle = ABS(angle);

		if((pthis->actor.xzDistToPlayer < 80.0f) && (player->swordState != 0) && (angle >= 0x1F40))
		{
			pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
			EnWf_SetupRunAroundPlayer(pthis);
		}
		else
		{
			pthis->actionTimer--;

			if(pthis->actionTimer == 0)
			{
				if(Actor_IsFacingPlayer(&pthis->actor, 0x1555))
				{
					if(Rand_ZeroOne() > 0.3f)
					{
						EnWf_SetupRunAtPlayer(pthis, globalCtx);
					}
					else
					{
						EnWf_SetupRunAroundPlayer(pthis);
					}
				}
				else
				{
					EnWf_SetupSearchForPlayer(pthis);
				}
				if((globalCtx->gameplayFrames & 95) == 0)
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_CRY);
				}
			}
		}
	}
}

void EnWf_SetupRunAtPlayer(EnWf* pthis, GlobalContext* globalCtx)
{
	f32 lastFrame = Animation_GetLastFrame(&gWolfosRunningAnim);

	Animation_Change(&pthis->skelAnime, &gWolfosRunningAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP, -4.0f);
	pthis->action = WOLFOS_ACTION_RUN_AT_PLAYER;
	EnWf_SetupAction(pthis, EnWf_RunAtPlayer);
}

void EnWf_RunAtPlayer(EnWf* pthis, GlobalContext* globalCtx)
{
	s32 animPrevFrame;
	s32 sp58;
	s32 pad;
	f32 baseRange = 0.0f;
	s16 playerFacingAngleDiff;
	Player* player = GET_PLAYER(globalCtx);
	s32 playSpeed;

	if(!EnWf_DodgeRanged(globalCtx, pthis))
	{
		Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x2EE, 0);
		pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

		if(Actor_OtherIsTargeted(globalCtx, &pthis->actor))
		{
			baseRange = 150.0f;
		}

		if(pthis->actor.xzDistToPlayer <= (50.0f + baseRange))
		{
			Math_SmoothStepToF(&pthis->actor.speedXZ, -8.0f, 1.0f, 1.5f, 0.0f);
		}
		else if((65.0f + baseRange) < pthis->actor.xzDistToPlayer)
		{
			Math_SmoothStepToF(&pthis->actor.speedXZ, 8.0f, 1.0f, 1.5f, 0.0f);
		}
		else
		{
			Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 6.65f, 0.0f);
		}

		pthis->skelAnime.playSpeed = pthis->actor.speedXZ * 0.175f;
		playerFacingAngleDiff = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
		playerFacingAngleDiff = ABS(playerFacingAngleDiff);

		if((pthis->actor.xzDistToPlayer < (150.0f + baseRange)) && (player->swordState != 0) && (playerFacingAngleDiff >= 8000))
		{
			pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

			if(Rand_ZeroOne() > 0.7f)
			{
				EnWf_SetupRunAroundPlayer(pthis);
				return;
			}
		}

		animPrevFrame = pthis->skelAnime.curFrame;
		SkelAnime_Update(&pthis->skelAnime);
		sp58 = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
		playSpeed = (f32)ABS(pthis->skelAnime.playSpeed);

		if(!Actor_IsFacingPlayer(&pthis->actor, 0x11C7))
		{
			if(Rand_ZeroOne() > 0.5f)
			{
				EnWf_SetupRunAroundPlayer(pthis);
			}
			else
			{
				EnWf_SetupWait(pthis);
			}
		}
		else if(pthis->actor.xzDistToPlayer < (90.0f + baseRange))
		{
			s16 temp_v1 = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

			if(!Actor_OtherIsTargeted(globalCtx, &pthis->actor) && ((Rand_ZeroOne() > 0.03f) || ((pthis->actor.xzDistToPlayer <= 80.0f) && (ABS(temp_v1) < 0x38E0))))
			{
				EnWf_SetupSlash(pthis);
			}
			else if(Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (Rand_ZeroOne() > 0.5f))
			{
				EnWf_SetupBackflipAway(pthis);
			}
			else
			{
				EnWf_SetupRunAroundPlayer(pthis);
			}
		}

		if(!EnWf_ChangeAction(globalCtx, pthis, false))
		{
			if((globalCtx->gameplayFrames & 95) == 0)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_CRY);
			}
			if((animPrevFrame != (s32)pthis->skelAnime.curFrame) && (sp58 <= 0) && ((playSpeed + animPrevFrame) > 0))
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_WALK);
				Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 20.0f, 3, 3.0f, 50, 50, 1);
			}
		}
	}
}

void EnWf_SetupSearchForPlayer(EnWf* pthis)
{
	Animation_MorphToLoop(&pthis->skelAnime, &gWolfosSidesteppingAnim, -4.0f);
	pthis->action = WOLFOS_ACTION_SEARCH_FOR_PLAYER;
	EnWf_SetupAction(pthis, EnWf_SearchForPlayer);
}

void EnWf_SearchForPlayer(EnWf* pthis, GlobalContext* globalCtx)
{
	s16 yawDiff;
	s16 phi_v1;
	f32 phi_f2;

	if(!EnWf_DodgeRanged(globalCtx, pthis) && !EnWf_ChangeAction(globalCtx, pthis, false))
	{
		yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
		phi_v1 = (yawDiff > 0) ? (yawDiff * 0.25f) + 2000.0f : (yawDiff * 0.25f) - 2000.0f;
		pthis->actor.shape.rot.y += phi_v1;
		pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

		if(yawDiff > 0)
		{
			phi_f2 = phi_v1 * 0.5f;
			phi_f2 = CLAMP_MAX(phi_f2, 1.0f);
		}
		else
		{
			phi_f2 = phi_v1 * 0.5f;
			phi_f2 = CLAMP_MIN(phi_f2, -1.0f);
		}

		pthis->skelAnime.playSpeed = -phi_f2;
		SkelAnime_Update(&pthis->skelAnime);

		if(Actor_IsFacingPlayer(&pthis->actor, 0x1555))
		{
			if(Rand_ZeroOne() > 0.8f)
			{
				EnWf_SetupRunAroundPlayer(pthis);
			}
			else
			{
				EnWf_SetupRunAtPlayer(pthis, globalCtx);
			}
		}

		if((globalCtx->gameplayFrames & 95) == 0)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_CRY);
		}
	}
}

void EnWf_SetupRunAroundPlayer(EnWf* pthis)
{
	f32 lastFrame = Animation_GetLastFrame(&gWolfosRunningAnim);

	Animation_Change(&pthis->skelAnime, &gWolfosRunningAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP, -4.0f);

	if(Rand_ZeroOne() > 0.5f)
	{
		pthis->runAngle = 16000;
	}
	else
	{
		pthis->runAngle = -16000;
	}

	pthis->skelAnime.playSpeed = pthis->actor.speedXZ = 6.0f;
	pthis->skelAnime.playSpeed *= 0.175f;
	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	pthis->actionTimer = (Rand_ZeroOne() * 30.0f) + 30.0f;
	pthis->action = WOLFOS_ACTION_RUN_AROUND_PLAYER;
	pthis->runSpeed = 0.0f;

	EnWf_SetupAction(pthis, EnWf_RunAroundPlayer);
}

void EnWf_RunAroundPlayer(EnWf* pthis, GlobalContext* globalCtx)
{
	s16 angle1;
	s16 angle2;
	s32 pad;
	f32 baseRange = 0.0f;
	s32 animPrevFrame;
	s32 animFrameSpeedDiff;
	s32 animSpeed;
	Player* player = GET_PLAYER(globalCtx);

	Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer + pthis->runAngle, 1, 4000, 1);

	if(!EnWf_DodgeRanged(globalCtx, pthis) && !EnWf_ChangeAction(globalCtx, pthis, false))
	{
		pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
		angle1 = player->actor.shape.rot.y + pthis->runAngle + 0x8000;

		// Actor_TestFloorInDirection is useless here (see comment below)
		if((pthis->actor.bgCheckFlags & BG_STATE_3) || !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ, pthis->actor.shape.rot.y))
		{
			angle2 = (pthis->actor.bgCheckFlags & BG_STATE_3) ? (pthis->actor.wallYaw - pthis->actor.yawTowardsPlayer) - pthis->runAngle : 0;

			// This is probably meant to reverse direction if the edge of a floor is encountered, but does nothing
			// unless bgCheckFlags & BG_STATE_3 anyway, since angle2 = 0 otherwise
			if(ABS(angle2) > 0x2EE0)
			{
				pthis->runAngle = -pthis->runAngle;
			}
		}

		if(Actor_OtherIsTargeted(globalCtx, &pthis->actor))
		{
			baseRange = 150.0f;
		}

		if(pthis->actor.xzDistToPlayer <= (60.0f + baseRange))
		{
			Math_SmoothStepToF(&pthis->runSpeed, -4.0f, 1.0f, 1.5f, 0.0f);
		}
		else if((80.0f + baseRange) < pthis->actor.xzDistToPlayer)
		{
			Math_SmoothStepToF(&pthis->runSpeed, 4.0f, 1.0f, 1.5f, 0.0f);
		}
		else
		{
			Math_SmoothStepToF(&pthis->runSpeed, 0.0f, 1.0f, 6.65f, 0.0f);
		}

		if(pthis->runSpeed != 0.0f)
		{
			pthis->actor.world.pos.x += Math_SinS(pthis->actor.shape.rot.y) * pthis->runSpeed;
			pthis->actor.world.pos.z += Math_CosS(pthis->actor.shape.rot.y) * pthis->runSpeed;
		}

		if(ABS(pthis->runSpeed) < pthis->actor.speedXZ.abs())
		{
			pthis->skelAnime.playSpeed = pthis->actor.speedXZ * 0.175f;
		}
		else
		{
			pthis->skelAnime.playSpeed = pthis->runSpeed * 0.175f;
		}

		pthis->skelAnime.playSpeed = CLAMP(pthis->skelAnime.playSpeed, -3.0f, 3.0f);
		animPrevFrame = pthis->skelAnime.curFrame;
		SkelAnime_Update(&pthis->skelAnime);
		animFrameSpeedDiff = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
		animSpeed = (f32)ABS(pthis->skelAnime.playSpeed);

		if((animPrevFrame != (s32)pthis->skelAnime.curFrame) && (animFrameSpeedDiff <= 0) && (animSpeed + animPrevFrame > 0))
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_WALK);
			Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 20.0f, 3, 3.0f, 50, 50, 1);
		}

		if((globalCtx->gameplayFrames & 95) == 0)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_CRY);
		}

		if((Math_CosS(angle1 - pthis->actor.shape.rot.y) < -0.85f) && !Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (pthis->actor.xzDistToPlayer <= 80.0f))
		{
			EnWf_SetupSlash(pthis);
		}
		else
		{
			pthis->actionTimer--;

			if(pthis->actionTimer == 0)
			{
				if(Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (Rand_ZeroOne() > 0.5f))
				{
					EnWf_SetupBackflipAway(pthis);
				}
				else
				{
					EnWf_SetupWait(pthis);
					pthis->actionTimer = (Rand_ZeroOne() * 3.0f) + 1.0f;
				}
			}
		}
	}
}

void EnWf_SetupSlash(EnWf* pthis)
{
	Animation_PlayOnce(&pthis->skelAnime, &gWolfosSlashingAnim);
	pthis->colliderSpheres.base.atFlags &= ~AT_BOUNCED;
	pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
	pthis->action = WOLFOS_ACTION_SLASH;
	pthis->unk_2FA = 0; // Set and not used
	pthis->actionTimer = 7;
	pthis->skelAnime.endFrame = 20.0f;
	pthis->actor.speedXZ = 0.0f;

	EnWf_SetupAction(pthis, EnWf_Slash);
}

void EnWf_Slash(EnWf* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	s16 shapeAngleDiff = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
	s16 yawAngleDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
	s32 curFrame = pthis->skelAnime.curFrame;

	shapeAngleDiff = ABS(shapeAngleDiff);
	yawAngleDiff = ABS(yawAngleDiff);
	pthis->actor.speedXZ = 0.0f;

	if(((curFrame >= 9) && (curFrame <= 12)) || ((curFrame >= 17) && (curFrame <= 19)))
	{
		if(pthis->slashStatus == 0)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_ATTACK);
		}

		pthis->slashStatus = 1;
	}
	else
	{
		pthis->slashStatus = 0;
	}

	if(((curFrame == 15) && !Actor_IsTargeted(globalCtx, &pthis->actor) && (!Actor_IsFacingPlayer(&pthis->actor, 0x2000) || (pthis->actor.xzDistToPlayer >= 100.0f))) || SkelAnime_Update(&pthis->skelAnime))
	{
		if((curFrame != 15) && (pthis->actionTimer != 0))
		{
			pthis->actor.shape.rot.y += (s16)(3276.0f * (1.5f + (pthis->actionTimer - 4) * 0.4f));
			Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 15.0f, 1, 2.0f, 50, 50, 1);
			pthis->actionTimer--;
		}
		else if(!Actor_IsFacingPlayer(&pthis->actor, 0x1554) && (curFrame != 15))
		{
			EnWf_SetupWait(pthis);
			pthis->actionTimer = (Rand_ZeroOne() * 5.0f) + 5.0f;

			if(yawAngleDiff > 13000)
			{
				pthis->unk_2E2 = 7;
			}
		}
		else if((Rand_ZeroOne() > 0.7f) || (pthis->actor.xzDistToPlayer >= 120.0f))
		{
			EnWf_SetupWait(pthis);
			pthis->actionTimer = (Rand_ZeroOne() * 5.0f) + 5.0f;
		}
		else
		{
			pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

			if(Rand_ZeroOne() > 0.7f)
			{
				EnWf_SetupSidestep(pthis, globalCtx);
			}
			else if(shapeAngleDiff <= 10000)
			{
				if(yawAngleDiff > 16000)
				{
					pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
					EnWf_SetupRunAroundPlayer(pthis);
				}
				else
				{
					EnWf_ChangeAction(globalCtx, pthis, true);
				}
			}
			else
			{
				EnWf_SetupRunAroundPlayer(pthis);
			}
		}
	}
}

void EnWf_SetupRecoilFromBlockedSlash(EnWf* pthis)
{
	f32 endFrame = 1.0f;

	if((s32)pthis->skelAnime.curFrame >= 16)
	{
		endFrame = 15.0f;
	}

	Animation_Change(&pthis->skelAnime, &gWolfosSlashingAnim, -0.5f, pthis->skelAnime.curFrame - 1.0f, endFrame, ANIMMODE_ONCE_INTERP, 0.0f);
	pthis->action = WOLFOS_ACTION_RECOIL_FROM_BLOCKED_SLASH;
	pthis->slashStatus = 0;
	EnWf_SetupAction(pthis, EnWf_RecoilFromBlockedSlash);
}

void EnWf_RecoilFromBlockedSlash(EnWf* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	s16 angle1 = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
	s16 angle2 = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

	angle1 = ABS(angle1);
	angle2 = ABS(angle2);

	if(SkelAnime_Update(&pthis->skelAnime))
	{
		if(!Actor_IsFacingPlayer(&pthis->actor, 0x1554))
		{
			EnWf_SetupWait(pthis);
			pthis->actionTimer = (Rand_ZeroOne() * 5.0f) + 5.0f;

			if(angle2 > 0x32C8)
			{
				pthis->unk_2E2 = 30;
			}
		}
		else
		{
			if((Rand_ZeroOne() > 0.7f) || (pthis->actor.xzDistToPlayer >= 120.0f))
			{
				EnWf_SetupWait(pthis);
				pthis->actionTimer = (Rand_ZeroOne() * 5.0f) + 5.0f;
			}
			else
			{
				pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

				if(Rand_ZeroOne() > 0.7f)
				{
					EnWf_SetupSidestep(pthis, globalCtx);
				}
				else if(angle1 <= 0x2710)
				{
					if(angle2 > 0x3E80)
					{
						pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
						EnWf_SetupRunAroundPlayer(pthis);
					}
					else
					{
						EnWf_ChangeAction(globalCtx, pthis, true);
					}
				}
				else
				{
					EnWf_SetupRunAroundPlayer(pthis);
				}
			}
		}
	}
}

void EnWf_SetupBackflipAway(EnWf* pthis)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &gWolfosBackflippingAnim, -3.0f);
	pthis->actor.speedXZ = -6.0f;
	pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
	pthis->actionTimer = 0;
	pthis->unk_300 = true;
	pthis->action = WOLFOS_ACTION_BACKFLIP_AWAY;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
	EnWf_SetupAction(pthis, EnWf_BackflipAway);
}

void EnWf_BackflipAway(EnWf* pthis, GlobalContext* globalCtx)
{
	if(SkelAnime_Update(&pthis->skelAnime))
	{
		if(!Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (pthis->actor.xzDistToPlayer < 170.0f) && (pthis->actor.xzDistToPlayer > 140.0f) && (Rand_ZeroOne() < 0.2f))
		{
			EnWf_SetupRunAtPlayer(pthis, globalCtx);
		}
		else if((globalCtx->gameplayFrames % 2) != 0)
		{
			EnWf_SetupSidestep(pthis, globalCtx);
		}
		else
		{
			EnWf_SetupWait(pthis);
		}
	}
	if((globalCtx->frames & 95) == 0)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_CRY);
	}
}

void EnWf_SetupStunned(EnWf* pthis)
{
	if(pthis->actor.bgCheckFlags & BG_STATE_0)
	{
		pthis->actor.speedXZ = 0.0f;
	}

	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
	Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gWolfosDamagedAnim, 0.0f);
	pthis->action = WOLFOS_ACTION_STUNNED;
	EnWf_SetupAction(pthis, EnWf_Stunned);
}

void EnWf_Stunned(EnWf* pthis, GlobalContext* globalCtx)
{
	if(pthis->actor.bgCheckFlags & BG_STATE_1)
	{
		pthis->actor.speedXZ = 0.0f;
	}

	if(pthis->actor.bgCheckFlags & BG_STATE_0)
	{
		if(pthis->actor.speedXZ < 0.0f)
		{
			pthis->actor.speedXZ += 0.05f;
		}

		pthis->unk_300 = false;
	}

	if((pthis->actor.colorFilterTimer == 0) && (pthis->actor.bgCheckFlags & BG_STATE_0))
	{
		if(pthis->actor.colChkInfo.health == 0)
		{
			EnWf_SetupDie(pthis);
		}
		else
		{
			EnWf_ChangeAction(globalCtx, pthis, true);
		}
	}
}

void EnWf_SetupDamaged(EnWf* pthis)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &gWolfosDamagedAnim, -4.0f);

	if(pthis->actor.bgCheckFlags & BG_STATE_0)
	{
		pthis->unk_300 = false;
		pthis->actor.speedXZ = -4.0f;
	}
	else
	{
		pthis->unk_300 = true;
	}

	pthis->unk_2E2 = 0;
	pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_DAMAGE);
	pthis->action = WOLFOS_ACTION_DAMAGED;
	EnWf_SetupAction(pthis, EnWf_Damaged);
}

void EnWf_Damaged(EnWf* pthis, GlobalContext* globalCtx)
{
	s16 angleToWall;

	if(pthis->actor.bgCheckFlags & BG_STATE_1)
	{
		pthis->actor.speedXZ = 0.0f;
	}

	if(pthis->actor.bgCheckFlags & BG_STATE_0)
	{
		if(pthis->actor.speedXZ < 0.0f)
		{
			pthis->actor.speedXZ += 0.05f;
		}

		pthis->unk_300 = false;
	}

	Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 4500, 0);

	if(!EnWf_ChangeAction(globalCtx, pthis, false) && SkelAnime_Update(&pthis->skelAnime))
	{
		if(pthis->actor.bgCheckFlags & BG_STATE_0)
		{
			angleToWall = pthis->actor.wallYaw - pthis->actor.shape.rot.y;
			angleToWall = ABS(angleToWall);

			if((pthis->actor.bgCheckFlags & BG_STATE_3) && (ABS(angleToWall) < 12000) && (pthis->actor.xzDistToPlayer < 120.0f))
			{
				EnWf_SetupSomersaultAndAttack(pthis);
			}
			else if(!EnWf_DodgeRanged(globalCtx, pthis))
			{
				if((pthis->actor.xzDistToPlayer <= 80.0f) && !Actor_OtherIsTargeted(globalCtx, &pthis->actor) && ((globalCtx->gameplayFrames % 8) != 0))
				{
					EnWf_SetupSlash(pthis);
				}
				else if(Rand_ZeroOne() > 0.5f)
				{
					EnWf_SetupWait(pthis);
					pthis->actionTimer = (Rand_ZeroOne() * 5.0f) + 5.0f;
					pthis->unk_2E2 = 30;
				}
				else
				{
					EnWf_SetupBackflipAway(pthis);
				}
			}
		}
	}
}

void EnWf_SetupSomersaultAndAttack(EnWf* pthis)
{
	f32 lastFrame = Animation_GetLastFrame(&gWolfosBackflippingAnim);

	Animation_Change(&pthis->skelAnime, &gWolfosBackflippingAnim, -1.0f, lastFrame, 0.0f, ANIMMODE_ONCE, -3.0f);
	pthis->actionTimer = 0;
	pthis->unk_300 = false;
	pthis->action = WOLFOS_ACTION_TURN_TOWARDS_PLAYER;
	pthis->actor.speedXZ = 6.5f;
	pthis->actor.velocity.y = 15.0f;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	EnWf_SetupAction(pthis, EnWf_SomersaultAndAttack);
}

void EnWf_SomersaultAndAttack(EnWf* pthis, GlobalContext* globalCtx)
{
	Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 4000, 1);

	if(pthis->actor.velocity.y >= 5.0f)
	{
		//! @bug unk_4C8 and unk_4BC are used but not set (presumably intended to be feet positions like other actors)
		func_800355B8(globalCtx, &pthis->unk_4C8);
		func_800355B8(globalCtx, &pthis->unk_4BC);
	}

	if(SkelAnime_Update(&pthis->skelAnime) && (pthis->actor.bgCheckFlags & (1 | 2)))
	{
		pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
		pthis->actor.shape.rot.x = 0;
		pthis->actor.speedXZ = pthis->actor.velocity.y = 0.0f;
		pthis->actor.world.pos.y = pthis->actor.floorHeight;

		if(!Actor_OtherIsTargeted(globalCtx, &pthis->actor))
		{
			EnWf_SetupSlash(pthis);
		}
		else
		{
			EnWf_SetupWait(pthis);
		}
	}
}

void EnWf_SetupBlocking(EnWf* pthis)
{
	f32 lastFrame = Animation_GetLastFrame(&gWolfosBlockingAnim);

	if(pthis->slashStatus != 0)
	{
		pthis->slashStatus = -1;
	}

	pthis->actor.speedXZ = 0.0f;
	pthis->action = WOLFOS_ACTION_BLOCKING;
	pthis->actionTimer = 10;

	Animation_Change(&pthis->skelAnime, &gWolfosBlockingAnim, 0.0f, 0.0f, lastFrame, ANIMMODE_ONCE_INTERP, -4.0f);
	EnWf_SetupAction(pthis, EnWf_Blocking);
}

void EnWf_Blocking(EnWf* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	s32 pad;

	if(pthis->actionTimer != 0)
	{
		pthis->actionTimer--;
	}
	else
	{
		pthis->skelAnime.playSpeed = 1.0f;
	}

	if(SkelAnime_Update(&pthis->skelAnime))
	{
		s16 yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

		if((ABS(yawDiff) <= 0x4000) && (pthis->actor.xzDistToPlayer < 60.0f) && (ABS(pthis->actor.yDistToPlayer) < 50.0f))
		{
			if(func_800354B4(globalCtx, &pthis->actor, 100.0f, 10000, 0x4000, pthis->actor.shape.rot.y))
			{
				if(player->swordAnimation == 0x11)
				{
					EnWf_SetupBlocking(pthis);
				}
				else if((globalCtx->gameplayFrames % 2) != 0)
				{
					EnWf_SetupBlocking(pthis);
				}
				else
				{
					EnWf_SetupBackflipAway(pthis);
				}
			}
			else
			{
				s16 angleFacingLink = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

				if(!Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (((globalCtx->gameplayFrames % 2) != 0) || (ABS(angleFacingLink) < 0x38E0)))
				{
					EnWf_SetupSlash(pthis);
				}
				else
				{
					EnWf_SetupRunAroundPlayer(pthis);
				}
			}
		}
		else
		{
			EnWf_SetupRunAroundPlayer(pthis);
		}
	}
	else if(pthis->actionTimer == 0)
	{
		if(func_800354B4(globalCtx, &pthis->actor, 100.0f, 10000, 0x4000, pthis->actor.shape.rot.y))
		{
			if(player->swordAnimation == 0x11)
			{
				EnWf_SetupBlocking(pthis);
			}
			else if((globalCtx->gameplayFrames % 2) != 0)
			{
				EnWf_SetupBlocking(pthis);
			}
			else
			{
				EnWf_SetupBackflipAway(pthis);
			}
		}
	}
}

void EnWf_SetupSidestep(EnWf* pthis, GlobalContext* globalCtx)
{
	s16 angle;
	Player* player;
	f32 lastFrame = Animation_GetLastFrame(&gWolfosRunningAnim);

	Animation_Change(&pthis->skelAnime, &gWolfosRunningAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP, -4.0f);

	player = GET_PLAYER(globalCtx);
	angle = player->actor.shape.rot.y + pthis->runAngle;

	if(Math_SinS(angle - pthis->actor.yawTowardsPlayer) > 0.0f)
	{
		pthis->runAngle = 16000;
	}
	else if(Math_SinS(angle - pthis->actor.yawTowardsPlayer) < 0.0f)
	{
		pthis->runAngle = -16000;
	}
	else if(Rand_ZeroOne() > 0.5f)
	{
		pthis->runAngle = 16000;
	}
	else
	{
		pthis->runAngle = -16000;
	}

	pthis->skelAnime.playSpeed = pthis->actor.speedXZ = 6.0f;
	pthis->skelAnime.playSpeed *= 0.175f;
	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	pthis->runSpeed = 0.0f;
	pthis->actionTimer = (Rand_ZeroOne() * 10.0f) + 5.0f;
	pthis->action = WOLFOS_ACTION_SIDESTEP;

	EnWf_SetupAction(pthis, EnWf_Sidestep);
}

void EnWf_Sidestep(EnWf* pthis, GlobalContext* globalCtx)
{
	s16 angleDiff1;
	Player* player = GET_PLAYER(globalCtx);
	s32 animPrevFrame;
	s32 animFrameSpeedDiff;
	s32 animSpeed;
	f32 baseRange = 0.0f;

	Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer + pthis->runAngle, 1, 3000, 1);

	// Actor_TestFloorInDirection is useless here (see comment below)
	if((pthis->actor.bgCheckFlags & BG_STATE_3) || !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ, pthis->actor.shape.rot.y))
	{
		s16 angle = (pthis->actor.bgCheckFlags & BG_STATE_3) ? (pthis->actor.wallYaw - pthis->actor.yawTowardsPlayer) - pthis->runAngle : 0;

		// This is probably meant to reverse direction if the edge of a floor is encountered, but does nothing
		// unless bgCheckFlags & BG_STATE_3 anyway, since angle = 0 otherwise
		if(ABS(angle) > 0x2EE0)
		{
			pthis->runAngle = -pthis->runAngle;
		}
	}

	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

	if(Actor_OtherIsTargeted(globalCtx, &pthis->actor))
	{
		baseRange = 150.0f;
	}

	if(pthis->actor.xzDistToPlayer <= (60.0f + baseRange))
	{
		Math_SmoothStepToF(&pthis->runSpeed, -4.0f, 1.0f, 1.5f, 0.0f);
	}
	else if((80.0f + baseRange) < pthis->actor.xzDistToPlayer)
	{
		Math_SmoothStepToF(&pthis->runSpeed, 4.0f, 1.0f, 1.5f, 0.0f);
	}
	else
	{
		Math_SmoothStepToF(&pthis->runSpeed, 0.0f, 1.0f, 6.65f, 0.0f);
	}

	if(pthis->runSpeed != 0.0f)
	{
		pthis->actor.world.pos.x += Math_SinS(pthis->actor.shape.rot.y) * pthis->runSpeed;
		pthis->actor.world.pos.z += Math_CosS(pthis->actor.shape.rot.y) * pthis->runSpeed;
	}

	if(ABS(pthis->runSpeed) < pthis->actor.speedXZ.abs())
	{
		pthis->skelAnime.playSpeed = pthis->actor.speedXZ * 0.175f;
	}
	else
	{
		pthis->skelAnime.playSpeed = pthis->runSpeed * 0.175f;
	}

	pthis->skelAnime.playSpeed = CLAMP(pthis->skelAnime.playSpeed, -3.0f, 3.0f);

	animPrevFrame = pthis->skelAnime.curFrame;
	SkelAnime_Update(&pthis->skelAnime);
	animFrameSpeedDiff = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
	animSpeed = (f32)ABS(pthis->skelAnime.playSpeed);

	if(!EnWf_ChangeAction(globalCtx, pthis, false))
	{
		pthis->actionTimer--;

		if(pthis->actionTimer == 0)
		{
			angleDiff1 = player->actor.shape.rot.y - pthis->actor.yawTowardsPlayer;
			angleDiff1 = ABS(angleDiff1);

			if(angleDiff1 >= 0x3A98)
			{
				EnWf_SetupWait(pthis);
				pthis->actionTimer = (Rand_ZeroOne() * 3.0f) + 1.0f;
			}
			else
			{
				Player* player2 = GET_PLAYER(globalCtx);
				s16 angleDiff2 = player2->actor.shape.rot.y - pthis->actor.yawTowardsPlayer;

				pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

				if((pthis->actor.xzDistToPlayer <= 80.0f) && !Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (((globalCtx->gameplayFrames % 4) == 0) || (ABS(angleDiff2) < 0x38E0)))
				{
					EnWf_SetupSlash(pthis);
				}
				else
				{
					EnWf_SetupRunAtPlayer(pthis, globalCtx);
				}
			}
		}

		if((animPrevFrame != (s32)pthis->skelAnime.curFrame) && (animFrameSpeedDiff <= 0) && ((animSpeed + animPrevFrame) > 0))
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_WALK);
			Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 20.0f, 3, 3.0f, 50, 50, 1);
		}

		if((globalCtx->gameplayFrames & 95) == 0)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_CRY);
		}
	}
}

void EnWf_SetupDie(EnWf* pthis)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &gWolfosRearingUpFallingOverAnim, -4.0f);
	pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

	if(pthis->actor.bgCheckFlags & BG_STATE_0)
	{
		pthis->unk_300 = false;
		pthis->actor.speedXZ = -6.0f;
	}
	else
	{
		pthis->unk_300 = true;
	}

	pthis->action = WOLFOS_ACTION_DIE;
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	pthis->actionTimer = pthis->skelAnime.animLength;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_WOLFOS_DEAD);
	EnWf_SetupAction(pthis, EnWf_Die);
}

void EnWf_Die(EnWf* pthis, GlobalContext* globalCtx)
{
	if(pthis->actor.bgCheckFlags & BG_STATE_1)
	{
		pthis->actor.speedXZ = 0.0f;
	}

	if(pthis->actor.bgCheckFlags & BG_STATE_0)
	{
		Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
		pthis->unk_300 = false;
	}

	if(SkelAnime_Update(&pthis->skelAnime))
	{
		Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xD0);

		if(pthis->switchFlag != 0xFF)
		{
			Flags_SetSwitch(globalCtx, pthis->switchFlag);
		}

		Actor_Kill(&pthis->actor);
	}
	else
	{
		s32 i;
		Vec3f pos;
		Vec3f velAndAccel = {0.0f, 0.5f, 0.0f};

		pthis->actionTimer--;

		for(i = ((s32)(pthis->skelAnime.animLength - pthis->actionTimer)) >> 1; i >= 0; i--)
		{
			pos.x = Rand_CenteredFloat(60.0f) + pthis->actor.world.pos.x;
			pos.z = Rand_CenteredFloat(60.0f) + pthis->actor.world.pos.z;
			pos.y = Rand_CenteredFloat(50.0f) + (pthis->actor.world.pos.y + 20.0f);
			EffectSsDeadDb_Spawn(globalCtx, &pos, &velAndAccel, &velAndAccel, 100, 0, 255, 255, 255, 255, 0, 0, 255, 1, 9, true);
		}
	}
}

void func_80B36F40(EnWf* pthis, GlobalContext* globalCtx)
{
	if((pthis->action == WOLFOS_ACTION_WAIT) && (pthis->unk_2E2 != 0))
	{
		pthis->unk_4D4.y = Math_SinS(pthis->unk_2E2 * 4200) * 8920.0f;
	}
	else if(pthis->action != WOLFOS_ACTION_STUNNED)
	{
		if(pthis->action != WOLFOS_ACTION_SLASH)
		{
			Math_SmoothStepToS(&pthis->unk_4D4.y, pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y, 1, 1500, 0);
			pthis->unk_4D4.y = CLAMP(pthis->unk_4D4.y, -0x3127, 0x3127);
		}
		else
		{
			pthis->unk_4D4.y = 0;
		}
	}
}

void EnWf_UpdateDamage(EnWf* pthis, GlobalContext* globalCtx)
{
	if(pthis->colliderSpheres.base.acFlags & AC_BOUNCED)
	{
		pthis->colliderSpheres.base.acFlags &= ~(AC_HIT | AC_BOUNCED);
		pthis->colliderCylinderBody.base.acFlags &= ~AC_HIT;
		pthis->colliderCylinderTail.base.acFlags &= ~AC_HIT;
	}
	else if((pthis->colliderCylinderBody.base.acFlags & AC_HIT) || (pthis->colliderCylinderTail.base.acFlags & AC_HIT))
	{
		if(pthis->action >= WOLFOS_ACTION_WAIT)
		{
			s16 yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

			if((!(pthis->colliderCylinderBody.base.acFlags & AC_HIT) && (pthis->colliderCylinderTail.base.acFlags & AC_HIT)) || (ABS(yawDiff) > 19000))
			{
				pthis->actor.colChkInfo.damage *= 4;
			}

			pthis->colliderCylinderBody.base.acFlags &= ~AC_HIT;
			pthis->colliderCylinderTail.base.acFlags &= ~AC_HIT;

			if(pthis->actor.colChkInfo.damageEffect != ENWF_DMGEFF_ICE_MAGIC)
			{
				pthis->damageEffect = pthis->actor.colChkInfo.damageEffect;
				Actor_SetDropFlag(&pthis->actor, &pthis->colliderCylinderBody.info, 1);
				pthis->slashStatus = 0;

				if((pthis->actor.colChkInfo.damageEffect == ENWF_DMGEFF_STUN) || (pthis->actor.colChkInfo.damageEffect == ENWF_DMGEFF_UNDEF))
				{
					if(pthis->action != WOLFOS_ACTION_STUNNED)
					{
						Actor_SetColorFilter(&pthis->actor, 0, 120, 0, 80);
						Actor_ApplyDamage(&pthis->actor);
						EnWf_SetupStunned(pthis);
					}
				}
				else
				{ // LIGHT_MAGIC, FIRE, NONE
					Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 8);

					if(pthis->damageEffect == ENWF_DMGEFF_FIRE)
					{
						pthis->fireTimer = 40;
					}

					if(Actor_ApplyDamage(&pthis->actor) == 0)
					{
						EnWf_SetupDie(pthis);
						Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
					}
					else
					{
						EnWf_SetupDamaged(pthis);
					}
				}
			}
		}
	}
}

void EnWf_Update(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	EnWf* pthis = (EnWf*)thisx;

	EnWf_UpdateDamage(pthis, globalCtx);

	if(pthis->actor.colChkInfo.damageEffect != ENWF_DMGEFF_ICE_MAGIC)
	{
		Actor_MoveForward(&pthis->actor);
		Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 32.0f, 30.0f, 60.0f, 0x1D);
		pthis->actionFunc(pthis, globalCtx);
		func_80B36F40(pthis, globalCtx);
	}

	if(pthis->actor.bgCheckFlags & (1 | 2))
	{
		func_800359B8(&pthis->actor, pthis->actor.shape.rot.y, &pthis->actor.shape.rot);
	}
	else
	{
		Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0, 1, 1000, 0);
		Math_SmoothStepToS(&pthis->actor.shape.rot.z, 0, 1, 1000, 0);
	}

	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSpheres.base);

	if(pthis->action >= WOLFOS_ACTION_WAIT)
	{
		if((pthis->actor.colorFilterTimer == 0) || !(pthis->actor.colorFilterParams & 0x4000))
		{
			Collider_UpdateCylinder(&pthis->actor, &pthis->colliderCylinderBody);
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCylinderTail.base);
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCylinderBody.base);
		}
	}

	if(pthis->action == WOLFOS_ACTION_BLOCKING)
	{
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSpheres.base);
	}

	if(pthis->slashStatus > 0)
	{
		if(!(pthis->colliderSpheres.base.atFlags & AT_BOUNCED))
		{
			CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSpheres.base);
		}
		else
		{
			EnWf_SetupRecoilFromBlockedSlash(pthis);
		}
	}

	pthis->actor.focus.pos = pthis->actor.world.pos;
	pthis->actor.focus.pos.y += 25.0f;

	if(pthis->eyeIndex == 0)
	{
		if((Rand_ZeroOne() < 0.2f) && ((globalCtx->gameplayFrames % 4) == 0) && (pthis->actor.colorFilterTimer == 0))
		{
			pthis->eyeIndex++;
		}
	}
	else
	{
		pthis->eyeIndex = (pthis->eyeIndex + 1) & 3;
	}
}

s32 EnWf_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	EnWf* pthis = (EnWf*)thisx;

	if((limbIndex == WOLFOS_LIMB_HEAD) || (limbIndex == WOLFOS_LIMB_EYES))
	{
		rot->y -= pthis->unk_4D4.y;
	}

	return false;
}

void EnWf_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	EnWf* pthis = (EnWf*)thisx;
	s32 bodyPartIndex = -1;

	Collider_UpdateSpheres(limbIndex, &pthis->colliderSpheres);

	if(limbIndex == WOLFOS_LIMB_TAIL)
	{
		Vec3f colliderPos;

		bodyPartIndex = -1;
		Matrix_MultVec3f(&colliderVec_94, &colliderPos);
		pthis->colliderCylinderTail.dim.pos.x = colliderPos.x;
		pthis->colliderCylinderTail.dim.pos.y = colliderPos.y;
		pthis->colliderCylinderTail.dim.pos.z = colliderPos.z;
	}

	if((pthis->fireTimer != 0) || ((pthis->actor.colorFilterTimer != 0) && (pthis->actor.colorFilterParams & 0x4000)))
	{
		switch(limbIndex)
		{
			case WOLFOS_LIMB_EYES:
				bodyPartIndex = 0;
				break;
			case WOLFOS_LIMB_FRONT_RIGHT_LOWER_LEG:
				bodyPartIndex = 1;
				break;
			case WOLFOS_LIMB_FRONT_LEFT_LOWER_LEG:
				bodyPartIndex = 2;
				break;
			case WOLFOS_LIMB_THORAX:
				bodyPartIndex = 3;
				break;
			case WOLFOS_LIMB_ABDOMEN:
				bodyPartIndex = 4;
				break;
			case WOLFOS_LIMB_TAIL:
				bodyPartIndex = 5;
				break;
			case WOLFOS_LIMB_BACK_RIGHT_SHIN:
				bodyPartIndex = 6;
				break;
			case 37:
				//! @bug There is no limb with index pthis large, so bodyPartsPos[7] is uninitialised. Thus a flame will
				//! be drawn at 0,0,0 when the Wolfos is on fire.
				bodyPartIndex = 7;
				break;
			case WOLFOS_LIMB_BACK_RIGHT_PASTERN:
				bodyPartIndex = 8;
				break;
			case WOLFOS_LIMB_BACK_LEFT_PAW:
				bodyPartIndex = 9;
				break;
		}

		if(bodyPartIndex >= 0)
		{
			Vec3f bodyPartPos;

			Matrix_MultVec3f(&bodyPartVec_94, &bodyPartPos);
			pthis->bodyPartsPos[bodyPartIndex].x = bodyPartPos.x;
			pthis->bodyPartsPos[bodyPartIndex].y = bodyPartPos.y;
			pthis->bodyPartsPos[bodyPartIndex].z = bodyPartPos.z;
		}
	}
}

static void* sWolfosNormalEyeTextures[] = {gWolfosNormalEyeOpenTex, gWolfosNormalEyeHalfTex, gWolfosNormalEyeNarrowTex, gWolfosNormalEyeHalfTex};
static void* sWolfosWhiteEyeTextures[] = {gWolfosWhiteEyeOpenTex, gWolfosWhiteEyeHalfTex, gWolfosWhiteEyeNarrowTex, gWolfosWhiteEyeHalfTex};

void EnWf_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	EnWf* pthis = (EnWf*)thisx;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_wf.c", 2157);

	// This conditional will always evaluate to true, since unk_300 is false whenever action is
	// WOLFOS_ACTION_WAIT_TO_APPEAR.
	if((pthis->action != WOLFOS_ACTION_WAIT_TO_APPEAR) || !pthis->unk_300)
	{
		func_80093D18(globalCtx->gfxCtx);

		if(pthis->actor.params == WOLFOS_NORMAL)
		{
			gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sWolfosNormalEyeTextures[pthis->eyeIndex]));
		}
		else
		{
			gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sWolfosWhiteEyeTextures[pthis->eyeIndex]));
		}

		SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, EnWf_OverrideLimbDraw, EnWf_PostLimbDraw, &pthis->actor);

		if(pthis->fireTimer != 0)
		{
			pthis->actor.colorFilterTimer++;
			if(1)
			{
			}
			pthis->fireTimer--;

			if((pthis->fireTimer % 4) == 0)
			{
				s32 fireIndex = pthis->fireTimer >> 2;

				EffectSsEnFire_SpawnVec3s(globalCtx, &pthis->actor, &pthis->bodyPartsPos[fireIndex], 75, 0, 0, fireIndex);
			}
		}
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_wf.c", 2190);
}

s32 EnWf_DodgeRanged(GlobalContext* globalCtx, EnWf* pthis)
{
	Actor* actor = Actor_GetProjectileActor(globalCtx, &pthis->actor, 600.0f);

	if(actor != NULL)
	{
		s16 angleToFacing;
		s16 pad;
		f32 dist;

		angleToFacing = Actor_WorldYawTowardActor(&pthis->actor, actor) - pthis->actor.shape.rot.y;
		pthis->actor.world.rot.y = (u16)pthis->actor.shape.rot.y & 0xFFFF;
		dist = Actor_WorldDistXYZToPoint(&pthis->actor, &actor->world.pos);

		if((ABS(angleToFacing) < 0x2EE0) && (sqrt(dist) < 400.0))
		{
			EnWf_SetupBlocking(pthis);
		}
		else
		{
			pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;
			if((ABS(angleToFacing) < 0x2000) || (ABS(angleToFacing) > 0x5FFF))
			{
				EnWf_SetupSidestep(pthis, globalCtx);
				pthis->actor.speedXZ *= 2.0f;
			}
			else if(ABS(angleToFacing) < 0x5FFF)
			{
				EnWf_SetupBackflipAway(pthis);
			}
		}
		return true;
	}

	return false;
}

void EnWf_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	colliderVec_94 = {1200.0f, 0.0f, 0.0f};

	bodyPartVec_94 = {0.0f, 0.0f, 0.0f};

	sJntSphInit = {
	    {
		COLTYPE_METAL,
		AT_ON | AT_TYPE_ENEMY,
		AC_ON | AC_HARD | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_ALL,
		OC2_TYPE_1,
		COLSHAPE_JNTSPH,
	    },
	    ARRAY_COUNT(sJntSphItemsInit),
	    sJntSphItemsInit,
	};

	sBodyCylinderInit = {
	    {
		COLTYPE_HIT5,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_NONE,
		OC2_NONE,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK1,
		{0x00000000, 0x00, 0x00},
		{0xFFCFFFFF, 0x00, 0x00},
		TOUCH_NONE,
		BUMP_ON,
		OCELEM_NONE,
	    },
	    {20, 50, 0, {0, 0, 0}},
	};

	sTailCylinderInit = {
	    {
		COLTYPE_HIT5,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_NONE,
		OC2_NONE,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK1,
		{0x00000000, 0x00, 0x00},
		{0xFFCFFFFF, 0x00, 0x00},
		TOUCH_NONE,
		BUMP_ON,
		OCELEM_NONE,
	    },
	    {15, 20, -15, {0, 0, 0}},
	};

	sDamageTable = {
	    /* Deku nut      */ DMG_ENTRY(0, ENWF_DMGEFF_STUN),
	    /* Deku stick    */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Slingshot     */ DMG_ENTRY(1, ENWF_DMGEFF_NONE),
	    /* Explosive     */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Boomerang     */ DMG_ENTRY(0, ENWF_DMGEFF_STUN),
	    /* Normal arrow  */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Hammer swing  */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Hookshot      */ DMG_ENTRY(0, ENWF_DMGEFF_STUN),
	    /* Kokiri sword  */ DMG_ENTRY(1, ENWF_DMGEFF_NONE),
	    /* Master sword  */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Giant's Knife */ DMG_ENTRY(4, ENWF_DMGEFF_NONE),
	    /* Fire arrow    */ DMG_ENTRY(4, ENWF_DMGEFF_FIRE),
	    /* Ice arrow     */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Light arrow   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Unk arrow 1   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Unk arrow 2   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Unk arrow 3   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Fire magic    */ DMG_ENTRY(4, ENWF_DMGEFF_FIRE),
	    /* Ice magic     */ DMG_ENTRY(0, ENWF_DMGEFF_ICE_MAGIC),
	    /* Light magic   */ DMG_ENTRY(3, ENWF_DMGEFF_LIGHT_MAGIC),
	    /* Shield        */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
	    /* Mirror Ray    */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
	    /* Kokiri spin   */ DMG_ENTRY(1, ENWF_DMGEFF_NONE),
	    /* Giant spin    */ DMG_ENTRY(4, ENWF_DMGEFF_NONE),
	    /* Master spin   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Kokiri jump   */ DMG_ENTRY(2, ENWF_DMGEFF_NONE),
	    /* Giant jump    */ DMG_ENTRY(8, ENWF_DMGEFF_NONE),
	    /* Master jump   */ DMG_ENTRY(4, ENWF_DMGEFF_NONE),
	    /* Unknown 1     */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
	    /* Unblockable   */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
	    /* Hammer jump   */ DMG_ENTRY(4, ENWF_DMGEFF_NONE),
	    /* Unknown 2     */ DMG_ENTRY(0, ENWF_DMGEFF_NONE),
	};

	En_Wf_InitVars = {
	    ACTOR_EN_WF, ACTORCAT_ENEMY, FLAGS, OBJECT_WF, ACTOR_FACTORY(EnWf), (ActorFunc)EnWf_Init, (ActorFunc)EnWf_Destroy, (ActorFunc)EnWf_Update, (ActorFunc)EnWf_Draw, (ActorFunc)EnWf_Reset,
	};
}
