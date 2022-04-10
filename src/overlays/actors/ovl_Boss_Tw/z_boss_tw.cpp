#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BOSS_TW_Z_BOSS_TW_C
#include "actor_common.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"
#include "z_boss_tw.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"
#include "def/code_800A9F30.h"
#include "def/cosf.h"
#include "def/math_float.h"
#include "def/random.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_demo.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "def/z_skin_matrix.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_tw/object_tw.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BossTw_Init(Actor* thisx, GlobalContext* globalCtx);
void BossTw_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BossTw_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BossTw_Update(Actor* thisx, GlobalContext* globalCtx);
void BossTw_Draw(Actor* thisx, GlobalContext* globalCtx);

void BossTw_TwinrovaDamage(BossTw* pthis, GlobalContext* globalCtx, u8 arg2);
void BossTw_TwinrovaSetupFly(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_DrawEffects(GlobalContext* globalCtx);
void BossTw_TwinrovaLaugh(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaFly(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaGetUp(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaSetupGetUp(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaSetupLaugh(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaDoneBlastShoot(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaSetupDoneBlastShoot(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaSetupShootBlast(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaSetupChargeBlast(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaArriveAtTarget(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaDeathCS(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaIntroCS(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_CSWait(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_DeathCS(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaMergeCS(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaSetupMergeCS(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_MergeCS(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_Spin(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_Laugh(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_SetupLaugh(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_FinishBeamShoot(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_SetupFinishBeamShoot(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_SetupHitByBeam(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_HitByBeam(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_Wait(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_ShootBeam(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_FlyTo(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_SetupShootBeam(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TurnToPlayer(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaUpdate(Actor* thisx, GlobalContext* globalCtx);
void BossTw_TwinrovaDraw(Actor* thisx, GlobalContext* globalCtx);
void BossTw_SetupWait(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaSetupIntroCS(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_SetupFlyTo(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_SetupCSWait(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_BlastUpdate(Actor* thisx, GlobalContext* globalCtx);
void BossTw_BlastDraw(Actor* thisx, GlobalContext* globalCtx);
void BossTw_BlastFire(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_BlastIce(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_DeathBall(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_DrawDeathBall(Actor* thisx, GlobalContext* globalCtx);
void BossTw_TwinrovaStun(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaSpin(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaShootBlast(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaChargeBlast(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_TwinrovaSetupSpin(BossTw* pthis, GlobalContext* globalCtx);
void BossTw_UpdateEffects(GlobalContext* globalCtx);

static Vec3f sPillarPositions_134[] = {{600.0f, 400.0f, 0.0f}, {0.0f, 400.0f, 600.0f}, {-600.0f, 400.0f, 0.0f}, {0.0f, 400.0f, -600.0f}};

static s16 D_8094A900_143[] = {
    0, 1, 2, 2, 1,
};

static s16 D_8094A90C_143[] = {
    0, 1, 2, 2, 2, 2, 2, 2, 1,
};

static Vec3f D_8094A944_143 = {0.0f, 0.0f, 0.0f};

static Vec3f D_8094A950_143 = {0.0f, 2000.0f, -2000.0f};

static Vec3f D_8094A95C_143[] = {
    {0.0f, 0.0f, -10000.0f}, {0.0f, 0.0f, -8000.0f}, {0.0f, 0.0f, -9000.0f}, {0.0f, 0.0f, -11000.0f}, {0.0f, 0.0f, -12000.0f},
};

static void* sEyeTextures_143[] = {
    object_tw_Tex_00A438,
    object_tw_Tex_00B238,
    object_tw_Tex_00B638,
};

static Vec3f D_8094A9A4_143 = {0.0f, 200.0f, 2000.0f};

static Vec3f D_8094A9BC_143 = {0.0f, 0.0f, 0.0f};

static Vec3f D_8094A9C8_143 = {0.0f, 2000.0f, -2000.0f};

static Vec3f D_8094A9D4_143 = {13000.0f, 0.0f, 0.0f};

static Vec3f D_8094A9E0_143 = {13000.0f, 0.0f, 0.0f};

static Vec3f D_8094A9EC_143 = {0.0f, 200.0f, 2000.0f};

static Color_RGB8 sDotColors_143[] = {
    {255, 128, 0}, {255, 0, 0}, {255, 255, 0}, {255, 0, 0}, {100, 100, 100}, {255, 255, 255}, {150, 150, 150}, {255, 255, 255},
};

static s32 sRandSeed0_143;

static s32 sRandSeed1_143;

static s32 sRandSeed2_143;

ActorInit Boss_Tw_InitVars = {
    ACTOR_BOSS_TW, ACTORCAT_BOSS, FLAGS, OBJECT_TW, sizeof(BossTw), (ActorFunc)BossTw_Init, (ActorFunc)BossTw_Destroy, (ActorFunc)BossTw_Update, (ActorFunc)BossTw_Draw, (ActorFunc)BossTw_Reset,
};

static Vec3f D_8094A7D0 = {0.0f, 0.0f, 1000.0f};
static Vec3f sZeroVector = {0.0f, 0.0f, 0.0f};

static ColliderCylinderInit sCylinderInitBlasts = {
    {
	COLTYPE_NONE,
	AT_ON | AT_TYPE_ALL,
	AC_ON | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_PLAYER,
	OC2_TYPE_1,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK0,
	{0xFFCFFFFF, 0x00, 0x30},
	{0x00100000, 0x00, 0x00},
	TOUCH_ON | TOUCH_SFX_NORMAL,
	BUMP_ON,
	OCELEM_ON,
    },
    {25, 35, -17, {0, 0, 0}},
};

static ColliderCylinderInit sCylinderInitKoumeKotake = {
    {
	COLTYPE_HIT3,
	AT_ON | AT_TYPE_ENEMY,
	AC_ON | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_PLAYER,
	OC2_TYPE_1,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK0,
	{0xFFCFFFFF, 0x00, 0x20},
	{0xFFCDFFFE, 0x00, 0x00},
	TOUCH_ON | TOUCH_SFX_NORMAL,
	BUMP_ON,
	OCELEM_ON,
    },
    {45, 120, -30, {0, 0, 0}},
};

static ColliderCylinderInit sCylinderInitTwinrova = {
    {
	COLTYPE_HIT3,
	AT_ON | AT_TYPE_ENEMY,
	AC_ON | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_ALL,
	OC2_TYPE_1,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK0,
	{0xFFCFFFFF, 0x00, 0x20},
	{0xFFCDFFFE, 0x00, 0x00},
	TOUCH_ON | TOUCH_SFX_NORMAL,
	BUMP_ON | BUMP_HOOKABLE,
	OCELEM_ON,
    },
    {45, 120, -30, {0, 0, 0}},
};

static Vec3f sTwinrovaPillarPos[] = {
    {580.0f, 380.0f, 0.0f},
    {0.0f, 380.0f, 580.0f},
    {-580.0f, 380.0f, 0.0f},
    {0.0f, 380.0f, -580.0f},
};

static u8 sTwInitalized = false;

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 5, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, 0, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 0, ICHAIN_STOP),
};

static s8 sEnvType;
static u8 sGroundBlastType;
static BossTw* sKotakePtr;
static BossTw* sKoumePtr;
static BossTw* sTwinrovaPtr;
static u8 sShieldFireCharge;
static u8 sShieldIceCharge;
static f32 D_8094C854;
static f32 D_8094C858;
static u8 sTwinrovaBlastType;
static u8 sFixedBlastType;
static u8 sFixedBlatSeq;
static u8 sFreezeState;
static Vec3f sShieldHitPos;
static s16 sShieldHitYaw;
static u8 sBeamDivertTimer;
static u8 D_8094C86F;
static u8 D_8094C870;
static s16 D_8094C872;
static s16 D_8094C874;
static s16 D_8094C876;
static u8 D_8094C878;
static s16 D_8094C87A;
static s16 D_8094C87C;
static u8 D_8094C87E;
static BossTwEffect sTwEffects[150];

void BossTw_AddDotEffect(GlobalContext* globalCtx, Vec3f* initalPos, Vec3f* initalSpeed, Vec3f* accel, f32 scale, s16 args, s16 countLimit)
{
	s16 i;
	BossTwEffect* eff;

	for(i = 0, eff = (BossTwEffect*)globalCtx->specialEffects; i < countLimit; i++, eff++)
	{
		if(eff->type == TWEFF_NONE)
		{
			eff->type = TWEFF_DOT;
			eff->pos = *initalPos;
			eff->curSpeed = *initalSpeed;
			eff->accel = *accel;
			eff->workf[EFF_SCALE] = scale / 1000.0f;
			eff->alpha = 255;
			eff->frame = (s16)Rand_ZeroFloat(10.0f);
			eff->work[EFF_ARGS] = args;
			break;
		}
	}
}

void BossTw_AddDmgCloud(GlobalContext* globalCtx, s16 type, Vec3f* initialPos, Vec3f* initalSpeed, Vec3f* accel, f32 scale, s16 alpha, s16 args, s16 countLimit)
{
	s16 i;
	BossTwEffect* eff;

	for(i = 0, eff = (BossTwEffect*)globalCtx->specialEffects; i < countLimit; i++, eff++)
	{
		if(eff->type == TWEFF_NONE)
		{
			eff->type = type;
			eff->pos = *initialPos;
			eff->curSpeed = *initalSpeed;
			eff->accel = *accel;
			eff->workf[EFF_SCALE] = scale / 1000.0f;
			eff->work[EFF_ARGS] = args;
			eff->alpha = alpha;
			eff->frame = (s16)Rand_ZeroFloat(100.0f);
			break;
		}
	}
}

void BossTw_AddRingEffect(GlobalContext* globalCtx, Vec3f* initalPos, f32 scale, f32 arg3, s16 alpha, s16 args, s16 arg6, s16 arg7)
{
	s16 i;
	BossTwEffect* eff;

	for(i = 0, eff = (BossTwEffect*)globalCtx->specialEffects; i < arg7; i++, eff++)
	{
		if(eff->type == TWEFF_NONE)
		{
			eff->type = TWEFF_RING;
			eff->pos = *initalPos;
			eff->curSpeed = sZeroVector;
			eff->accel = sZeroVector;
			eff->workf[EFF_SCALE] = scale * 0.0025f;
			eff->workf[EFF_DIST] = arg3 * 0.0025f;
			eff->work[EFF_ARGS] = args;
			eff->work[EFF_UNKS1] = arg6;
			eff->alpha = alpha;
			eff->workf[EFF_ROLL] = Rand_ZeroFloat(M_PI);
			eff->frame = 0;
			break;
		}
	}
}

void BossTw_AddPlayerFreezeEffect(GlobalContext* globalCtx, Actor* target)
{
	BossTwEffect* eff;
	s16 i;

	for(eff = (BossTwEffect*)globalCtx->specialEffects, i = 0; i < ARRAY_COUNT(sTwEffects); i++, eff++)
	{
		if(eff->type == TWEFF_NONE)
		{
			eff->type = TWEFF_PLYR_FRZ;
			eff->curSpeed = sZeroVector;
			eff->accel = sZeroVector;
			eff->frame = 0;
			eff->target = target;
			eff->workf[EFF_DIST] = 0.0f;
			eff->workf[EFF_SCALE] = 0.0f;
			eff->workf[EFF_ROLL] = 0.0f;
			if(target == NULL)
			{
				eff->work[EFF_ARGS] = 100;
			}
			else
			{
				eff->work[EFF_ARGS] = 20;
			}
			break;
		}
	}
}

void BossTw_AddFlameEffect(GlobalContext* globalCtx, Vec3f* initalPos, Vec3f* initalSpeed, Vec3f* accel, f32 scale, s16 args)
{
	s16 i;
	BossTwEffect* eff;

	for(i = 0, eff = (BossTwEffect*)globalCtx->specialEffects; i < ARRAY_COUNT(sTwEffects); i++, eff++)
	{
		if(eff->type == TWEFF_NONE)
		{
			eff->type = TWEFF_FLAME;
			eff->pos = *initalPos;
			eff->curSpeed = *initalSpeed;
			eff->accel = *accel;
			eff->workf[EFF_SCALE] = scale / 1000.0f;
			eff->work[EFF_ARGS] = args;
			eff->work[EFF_UNKS1] = 0;
			eff->alpha = 0;
			eff->frame = (s16)Rand_ZeroFloat(1000.0f);
			break;
		}
	}
}

void BossTw_AddMergeFlameEffect(GlobalContext* globalCtx, Vec3f* initialPos, f32 scale, f32 dist, s16 args)
{
	s16 i;
	BossTwEffect* eff;

	for(i = 0, eff = (BossTwEffect*)globalCtx->specialEffects; i < ARRAY_COUNT(sTwEffects); i++, eff++)
	{
		if(eff->type == TWEFF_NONE)
		{
			eff->type = TWEFF_MERGEFLAME;
			eff->pos = *initialPos;
			eff->curSpeed = sZeroVector;
			eff->accel = sZeroVector;
			eff->workf[EFF_SCALE] = scale / 1000.0f;
			eff->work[EFF_ARGS] = args;
			eff->work[EFF_UNKS1] = 0;
			eff->workf[EFF_DIST] = dist;
			eff->workf[EFF_ROLL] = Rand_ZeroFloat(2.0f * M_PI);
			eff->alpha = 0;
			eff->frame = (s16)Rand_ZeroFloat(1000.0f);
			break;
		}
	}
}

void BossTw_AddShieldBlastEffect(GlobalContext* globalCtx, Vec3f* initalPos, Vec3f* initalSpeed, Vec3f* accel, f32 scale, f32 arg5, s16 alpha, s16 args)
{
	s16 i;
	BossTwEffect* eff;

	for(i = 0, eff = (BossTwEffect*)globalCtx->specialEffects; i < ARRAY_COUNT(sTwEffects); i++, eff++)
	{
		if(eff->type == TWEFF_NONE)
		{
			eff->type = TWEFF_SHLD_BLST;
			eff->pos = *initalPos;
			eff->curSpeed = *initalSpeed;
			eff->accel = *accel;
			eff->workf[EFF_SCALE] = scale / 1000.0f;
			eff->workf[EFF_DIST] = arg5 / 1000.0f;
			eff->work[EFF_ARGS] = args;
			eff->work[EFF_UNKS1] = 0;
			eff->alpha = alpha;
			eff->frame = (s16)Rand_ZeroFloat(1000.0f);
			break;
		}
	}
}

void BossTw_AddShieldDeflectEffect(GlobalContext* globalCtx, f32 arg1, s16 arg2)
{
	s16 i;
	s16 j;
	BossTwEffect* eff;
	Player* player = GET_PLAYER(globalCtx);

	sShieldHitPos = player->bodyPartsPos[15];
	sShieldHitYaw = player->actor.shape.rot.y;

	for(i = 0; i < 8; i++)
	{
		for(eff = (BossTwEffect*)globalCtx->specialEffects, j = 0; j < ARRAY_COUNT(sTwEffects); j++, eff++)
		{
			if(eff->type == TWEFF_NONE)
			{
				eff->type = TWEFF_SHLD_DEFL;
				eff->pos = sShieldHitPos;
				eff->curSpeed = sZeroVector;
				eff->accel = sZeroVector;
				eff->workf[EFF_ROLL] = i * (M_PI / 4.0f);
				eff->workf[EFF_YAW] = M_PI / 2.0f;
				eff->workf[EFF_DIST] = 0.0f;
				eff->workf[EFF_SCALE] = arg1 / 1000.0f;
				eff->work[EFF_ARGS] = arg2;
				eff->work[EFF_UNKS1] = 0;
				eff->alpha = 255;
				eff->frame = (s16)Rand_ZeroFloat(1000.0f);
				break;
			}
		}
	}
}

void BossTw_AddShieldHitEffect(GlobalContext* globalCtx, f32 arg1, s16 arg2)
{
	s16 i;
	s16 j;
	BossTwEffect* eff;
	Player* player = GET_PLAYER(globalCtx);

	sShieldHitPos = player->bodyPartsPos[15];
	sShieldHitYaw = player->actor.shape.rot.y;

	for(i = 0; i < 8; i++)
	{
		for(eff = (BossTwEffect*)globalCtx->specialEffects, j = 0; j < ARRAY_COUNT(sTwEffects); j++, eff++)
		{
			if(eff->type == TWEFF_NONE)
			{
				eff->type = TWEFF_SHLD_HIT;
				eff->pos = sShieldHitPos;
				eff->curSpeed = sZeroVector;
				eff->accel = sZeroVector;
				eff->workf[EFF_ROLL] = i * (M_PI / 4.0f);
				eff->workf[EFF_YAW] = M_PI / 2.0f;
				eff->workf[EFF_DIST] = 0.0f;
				eff->workf[EFF_SCALE] = arg1 / 1000.0f;
				eff->work[EFF_ARGS] = arg2;
				eff->work[EFF_UNKS1] = 0;
				eff->alpha = 255;
				eff->frame = (s16)Rand_ZeroFloat(1000.0f);
				break;
			}
		}
	}
}

void BossTw_Init(Actor* thisx, GlobalContext* globalCtx2)
{
	GlobalContext* globalCtx = globalCtx2;
	BossTw* pthis = (BossTw*)thisx;
	s16 i;

	Actor_ProcessInitChain(&pthis->actor, sInitChain);
	ActorShape_Init(&pthis->actor.shape, 0.0f, NULL, 0.0f);

	if(pthis->actor.params >= TW_FIRE_BLAST)
	{
		// Blasts
		Actor_SetScale(&pthis->actor, 0.01f);
		pthis->actor.update = BossTw_BlastUpdate;
		pthis->actor.draw = BossTw_BlastDraw;
		pthis->actor.flags &= ~ACTOR_FLAG_0;

		Collider_InitCylinder(globalCtx, &pthis->collider);
		Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInitBlasts);

		if(pthis->actor.params == TW_FIRE_BLAST || pthis->actor.params == TW_FIRE_BLAST_GROUND)
		{
			pthis->actionFunc = BossTw_BlastFire;
			pthis->collider.info.toucher.effect = 1;
		}
		else if(pthis->actor.params == TW_ICE_BLAST || pthis->actor.params == TW_ICE_BLAST_GROUND)
		{
			pthis->actionFunc = BossTw_BlastIce;
		}
		else if(pthis->actor.params >= TW_DEATHBALL_KOTAKE)
		{
			pthis->actionFunc = BossTw_DeathBall;
			pthis->actor.draw = BossTw_DrawDeathBall;
			pthis->workf[TAIL_ALPHA] = 128.0f;

			if(thisx->params == TW_DEATHBALL_KOTAKE)
			{
				thisx->world.rot.y = sTwinrovaPtr->actor.world.rot.y + 0x4000;
			}
			else
			{
				thisx->world.rot.y = sTwinrovaPtr->actor.world.rot.y - 0x4000;
			}
		}

		pthis->timers[1] = 150;
		return;
	}

	Actor_SetScale(&pthis->actor, 2.5 * 0.01f);
	pthis->actor.colChkInfo.mass = 255;
	pthis->actor.colChkInfo.health = 0;
	Collider_InitCylinder(globalCtx, &pthis->collider);

	if(!sTwInitalized)
	{
		sTwInitalized = true;
		globalCtx->envCtx.unk_BF = 1;
		globalCtx->envCtx.unk_BE = 1;
		globalCtx->envCtx.unk_BD = 1;
		globalCtx->envCtx.unk_D8 = 0.0f;

		D_8094C874 = D_8094C876 = D_8094C878 = D_8094C87A = D_8094C87C = D_8094C87E = D_8094C870 = D_8094C86F = D_8094C872 = sBeamDivertTimer = sEnvType = sGroundBlastType = sFreezeState = sTwinrovaBlastType = sFixedBlatSeq = sShieldFireCharge =
		    sShieldIceCharge = 0;

		D_8094C858 = D_8094C854 = 0.0f;
		sFixedBlastType = Rand_ZeroFloat(1.99f);
		globalCtx->specialEffects = sTwEffects;

		for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
		{
			sTwEffects[i].type = TWEFF_NONE;
		}
	}

	if(pthis->actor.params == TW_KOTAKE)
	{
		Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInitKoumeKotake);
		pthis->actor.naviEnemyId = 0x33;
		SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_tw_Skel_0070E0, &object_tw_Anim_006F28, NULL, NULL, 0);

		if(gSaveContext.eventChkInf[7] & 0x20)
		{
			// began twinrova battle
			BossTw_SetupFlyTo(pthis, globalCtx);
			pthis->actor.world.pos.x = -600.0f;
			pthis->actor.world.pos.y = 400.0f;
			pthis->actor.world.pos.z = 0.0f;
			Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS);
		}
		else
		{
			BossTw_SetupCSWait(pthis, globalCtx);
		}

		Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_006F28, -3.0f);
		pthis->visible = true;
	}
	else if(pthis->actor.params == TW_KOUME)
	{
		Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInitKoumeKotake);
		pthis->actor.naviEnemyId = 0x32;
		SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_tw_Skel_01F888, &object_tw_Anim_006F28, NULL, NULL, 0);

		if(gSaveContext.eventChkInf[7] & 0x20)
		{
			// began twinrova battle
			BossTw_SetupFlyTo(pthis, globalCtx);
			pthis->actor.world.pos.x = 600.0f;
			pthis->actor.world.pos.y = 400.0f;
			pthis->actor.world.pos.z = 0.0f;
		}
		else
		{
			BossTw_SetupCSWait(pthis, globalCtx);
		}

		Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_006F28, -3.0f);
		pthis->visible = true;
	}
	else
	{
		// Twinrova
		Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInitTwinrova);
		pthis->actor.naviEnemyId = 0x5B;
		pthis->actor.colChkInfo.health = 24;
		pthis->actor.update = BossTw_TwinrovaUpdate;
		pthis->actor.draw = BossTw_TwinrovaDraw;
		SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_tw_Skel_032020, &object_tw_Anim_0244B4, NULL, NULL, 0);
		Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_0244B4, -3.0f);

		if(gSaveContext.eventChkInf[7] & 0x20)
		{
			// began twinrova battle
			BossTw_SetupWait(pthis, globalCtx);
		}
		else
		{
			BossTw_TwinrovaSetupIntroCS(pthis, globalCtx);
			pthis->actor.world.pos.x = 0.0f;
			pthis->actor.world.pos.y = 1000.0f;
			pthis->actor.world.pos.z = 0.0f;
		}

		pthis->actor.params = TW_TWINROVA;
		sTwinrovaPtr = pthis;

		if(Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num))
		{
			// twinrova has been defeated.
			Actor_Kill(&pthis->actor);
			Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, 600.0f, 230.0f, 0.0f, 0, 0, 0, WARP_DUNGEON_ADULT);
			Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, -600.0f, 230.0f, 0.0f, 0, 0, 0, 0);
		}
		else
		{
			sKotakePtr = (BossTw*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_TW, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, TW_KOTAKE);
			sKoumePtr = (BossTw*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_TW, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, TW_KOUME);
			sKotakePtr->actor.parent = &sKoumePtr->actor;
			sKoumePtr->actor.parent = &sKotakePtr->actor;
		}
	}

	pthis->fogR = globalCtx->lightCtx.fogColor[0];
	pthis->fogG = globalCtx->lightCtx.fogColor[1];
	pthis->fogB = globalCtx->lightCtx.fogColor[2];
	pthis->fogNear = globalCtx->lightCtx.fogNear;
	pthis->fogFar = 1000.0f;
}

void BossTw_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	BossTw* pthis = (BossTw*)thisx;

	Collider_DestroyCylinder(globalCtx, &pthis->collider);
	if(thisx->params < TW_FIRE_BLAST)
	{
		SkelAnime_Free(&pthis->skelAnime, globalCtx);
	}

	if(thisx->params == TW_TWINROVA)
	{
		sTwInitalized = false;
	}
}

void BossTw_SetupTurnToPlayer(BossTw* pthis, GlobalContext* globalCtx)
{
	BossTw* otherTw = (BossTw*)pthis->actor.parent;

	pthis->actionFunc = BossTw_TurnToPlayer;

	if((otherTw != NULL) && (otherTw->actionFunc == BossTw_ShootBeam))
	{
		pthis->timers[0] = 40;
	}
	else
	{
		pthis->timers[0] = 60;
	}

	pthis->rotateSpeed = 0.0f;
}

void BossTw_TurnToPlayer(BossTw* pthis, GlobalContext* globalCtx)
{
	BossTw* otherTw = (BossTw*)pthis->actor.parent;

	SkelAnime_Update(&pthis->skelAnime);
	Math_ApproachF(&pthis->actor.speedXZ, 0.0f, 1.0f, 1.0f);
	Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, pthis->rotateSpeed);
	Math_ApproachS(&pthis->actor.shape.rot.x, 0, 5, pthis->rotateSpeed);
	Math_ApproachF(&pthis->rotateSpeed, 4096.0f, 1.0f, 200.0f);
	func_8002D908(&pthis->actor);
	Actor_UpdatePosition(&pthis->actor);
	if(pthis->timers[0] == 0)
	{
		if((otherTw->actionFunc != BossTw_ShootBeam) && pthis->work[CAN_SHOOT])
		{
			pthis->work[CAN_SHOOT] = false;
			BossTw_SetupShootBeam(pthis, globalCtx);
			pthis->actor.speedXZ = 0.0f;
		}
		else
		{
			BossTw_SetupFlyTo(pthis, globalCtx);
		}
	}
}

void BossTw_SetupFlyTo(BossTw* pthis, GlobalContext* globalCtx)
{
	BossTw* otherTw = (BossTw*)pthis->actor.parent;

	pthis->unk_5F8 = 1;
	pthis->actor.flags |= ACTOR_FLAG_0;
	pthis->actionFunc = BossTw_FlyTo;
	pthis->rotateSpeed = 0.0f;
	Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_006F28, -10.0f);
	if((Rand_ZeroOne() < 0.5f) && (otherTw != NULL && otherTw->actionFunc == BossTw_ShootBeam))
	{
		// Other Sister is shooting a beam, go near them.
		pthis->targetPos.x = otherTw->actor.world.pos.x + Rand_CenteredFloat(200.0f);
		pthis->targetPos.y = Rand_ZeroFloat(200.0f) + 340.0f;
		pthis->targetPos.z = otherTw->actor.world.pos.z + Rand_CenteredFloat(200.0f);
		pthis->timers[0] = (s16)Rand_ZeroFloat(50.0f) + 50;
	}
	else if(Rand_ZeroOne() < 0.5f)
	{
		// Fly to a random spot.
		pthis->targetPos.x = Rand_CenteredFloat(800.0f);
		pthis->targetPos.y = Rand_ZeroFloat(200.0f) + 340.0f;
		pthis->targetPos.z = Rand_CenteredFloat(800.0f);
		pthis->timers[0] = (s16)Rand_ZeroFloat(50.0f) + 50;
	}
	else
	{
		// fly to a random pillar.
		s16 idx = Rand_ZeroFloat(ARRAY_COUNT(sPillarPositions_134) - 0.01f);

		pthis->targetPos = sPillarPositions_134[idx];
		pthis->timers[0] = 200;
		pthis->work[CAN_SHOOT] = true;
	}
}

void BossTw_FlyTo(BossTw* pthis, GlobalContext* globalCtx)
{
	f32 xDiff;
	f32 yDiff;
	f32 zDiff;
	f32 pitchTarget;
	f32 yawTarget;
	f32 xzDist;

	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_FLY - SFX_FLAG);
	Math_ApproachF(&pthis->scepterAlpha, 0.0f, 1.0f, 10.0f);
	SkelAnime_Update(&pthis->skelAnime);

	xDiff = pthis->targetPos.x - pthis->actor.world.pos.x;
	yDiff = pthis->targetPos.y - pthis->actor.world.pos.y;
	zDiff = pthis->targetPos.z - pthis->actor.world.pos.z;

	yawTarget = (s16)(Math_FAtan2F(xDiff, zDiff) * (32768.0f / M_PI));
	xzDist = sqrtf(SQ(xDiff) + SQ(zDiff));
	pitchTarget = (s16)(Math_FAtan2F(yDiff, xzDist) * (32768.0f / M_PI));

	Math_ApproachS(&pthis->actor.world.rot.x, pitchTarget, 0xA, pthis->rotateSpeed);
	Math_ApproachS(&pthis->actor.world.rot.y, yawTarget, 0xA, pthis->rotateSpeed);
	Math_ApproachS(&pthis->actor.shape.rot.y, yawTarget, 0xA, pthis->rotateSpeed);
	Math_ApproachS(&pthis->actor.shape.rot.x, pitchTarget, 0xA, pthis->rotateSpeed);
	Math_ApproachF(&pthis->rotateSpeed, 4096.0f, 1.0f, 100.0f);
	Math_ApproachF(&pthis->actor.speedXZ, 10.0f, 1.0f, 1.0f);
	func_8002D908(&pthis->actor);
	Actor_UpdatePosition(&pthis->actor);

	if((pthis->timers[0] == 0) || (xzDist < 70.0f))
	{
		BossTw_SetupTurnToPlayer(pthis, globalCtx);
	}
}

void BossTw_SetupShootBeam(BossTw* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	pthis->actionFunc = BossTw_ShootBeam;
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_007688, -5.0f);
	pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_007688);
	pthis->timers[1] = 70;
	pthis->targetPos = player->actor.world.pos;
	pthis->csState1 = 0;
	pthis->beamDist = 0.0f;
	pthis->beamReflectionDist = 0.0f;
	pthis->beamShootState = -1;
	pthis->beamScale = 0.01f;
	pthis->beamReflectionOrigin = pthis->beamOrigin;
	pthis->flameAlpha = 0.0f;
	pthis->spawnPortalAlpha = 0.0f;
	pthis->spawnPortalScale = 2000.0f;
	pthis->updateRate1 = 0.0f;
	pthis->portalRotation = 0.0f;
	pthis->updateRate2 = 0.0f;
}

void BossTw_SpawnGroundBlast(BossTw* pthis, GlobalContext* globalCtx, s16 blastType)
{
	BossTw* groundBlast;
	s16 i;
	Vec3f pos;
	Vec3f velocity;
	Vec3f accel;

	for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
	{
		velocity.x = Rand_CenteredFloat(20.0f);
		velocity.y = Rand_ZeroFloat(10.0f);
		velocity.z = Rand_CenteredFloat(20.0f);
		accel.y = 0.2f;
		accel.x = Rand_CenteredFloat(0.25f);
		accel.z = Rand_CenteredFloat(0.25f);
		pos = pthis->groundBlastPos;
		BossTw_AddDotEffect(globalCtx, &pos, &velocity, &accel, (s16)Rand_ZeroFloat(2.0f) + 8, blastType, 75);
	}

	if(blastType == 1)
	{
		sGroundBlastType = 1;
		groundBlast = (BossTw*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_TW, pthis->groundBlastPos.x, pthis->groundBlastPos.y, pthis->groundBlastPos.z, 0, 0, 0, TW_FIRE_BLAST_GROUND);
		if(groundBlast != NULL)
		{
			if(sTwinrovaPtr->actionFunc == BossTw_Wait)
			{
				groundBlast->timers[0] = 100;
			}
			else
			{
				groundBlast->timers[0] = 50;
			}
			sKoumePtr->workf[KM_GD_FLM_A] = sKoumePtr->workf[KM_GD_SMOKE_A] = sKoumePtr->workf[KM_GRND_CRTR_A] = 255.0f;
			sKoumePtr->workf[KM_GD_FLM_SCL] = 1.0f;
			sKoumePtr->workf[KM_GD_CRTR_SCL] = 0.005f;
			sKoumePtr->groundBlastPos2 = groundBlast->actor.world.pos;
			sEnvType = 4;
		}
	}
	else
	{
		sGroundBlastType = 2;
		groundBlast = (BossTw*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_TW, pthis->groundBlastPos.x, pthis->groundBlastPos.y, pthis->groundBlastPos.z, 0, 0, 0, TW_ICE_BLAST_GROUND);
		if(groundBlast != NULL)
		{
			if(sTwinrovaPtr->actionFunc == BossTw_Wait)
			{
				groundBlast->timers[0] = 100;
			}
			else
			{
				groundBlast->timers[0] = 50;
			}

			sKotakePtr->workf[UNK_F11] = 50.0f;
			sKotakePtr->workf[UNK_F9] = 250.0f;
			sKotakePtr->workf[UNK_F12] = 0.005f;
			sKotakePtr->workf[UNK_F14] = 1.0f;
			sKotakePtr->workf[UNK_F16] = 70.0f;
			sKotakePtr->groundBlastPos2 = groundBlast->actor.world.pos;
			sEnvType = 3;
		}
	}
}

s32 BossTw_BeamHitPlayerCheck(BossTw* pthis, GlobalContext* globalCtx)
{
	Vec3f offset;
	Vec3f beamDistFromPlayer;
	Player* player = GET_PLAYER(globalCtx);
	s16 i;

	offset.x = player->actor.world.pos.x - pthis->beamOrigin.x;
	offset.y = player->actor.world.pos.y - pthis->beamOrigin.y;
	offset.z = player->actor.world.pos.z - pthis->beamOrigin.z;

	Matrix_RotateX(-pthis->beamPitch, MTXMODE_NEW);
	Matrix_RotateY(-pthis->beamYaw, MTXMODE_APPLY);
	Matrix_MultVec3f(&offset, &beamDistFromPlayer);

	if(fabsf(beamDistFromPlayer.x) < 20.0f && fabsf(beamDistFromPlayer.y) < 50.0f && beamDistFromPlayer.z > 100.0f && beamDistFromPlayer.z <= pthis->beamDist)
	{
		if(sTwinrovaPtr->timers[2] == 0)
		{
			sTwinrovaPtr->timers[2] = 150;
			pthis->beamDist = sqrtf(SQ(offset.x) + SQ(offset.y) + SQ(offset.z));
			func_8002F6D4(globalCtx, &pthis->actor, 3.0f, pthis->actor.shape.rot.y, 0.0f, 0x20);

			if(pthis->actor.params == 0)
			{
				if(sFreezeState == 0)
				{
					sFreezeState = 1;
				}
			}
			else if(!player->isBurning)
			{
				for(i = 0; i < ARRAY_COUNT(player->flameTimers); i++)
				{
					player->flameTimers[i] = Rand_S16Offset(0, 200);
				}

				player->isBurning = true;
				func_8002F7DC(&player->actor, player->ageProperties->unk_92 + NA_SE_VO_LI_DEMO_DAMAGE);
			}
		}

		return true;
	}
	return false;
}

/**
 * Checks if the beam shot by `pthis` will be reflected
 * returns 0 if the beam will not be reflected,
 * returns 1 if the beam will be reflected,
 * and returns 2 if the beam will be diverted backwards
 */
s32 BossTw_CheckBeamReflection(BossTw* pthis, GlobalContext* globalCtx)
{
	Vec3f offset;
	Vec3f vec;
	Player* player = GET_PLAYER(globalCtx);

	if(player->stateFlags1 & PLAYER_STATE1_22 && (s16)(player->actor.shape.rot.y - pthis->actor.shape.rot.y + 0x8000) < 0x2000 && (s16)(player->actor.shape.rot.y - pthis->actor.shape.rot.y + 0x8000) > -0x2000)
	{
		// player is shielding and facing angles are less than 45 degrees in either direction
		offset.x = 0.0f;
		offset.y = 0.0f;
		offset.z = 10.0f;

		// set beam check point to 10 units in front of link.
		Matrix_RotateY(player->actor.shape.rot.y / 32768.0f * M_PI, MTXMODE_NEW);
		Matrix_MultVec3f(&offset, &vec);

		// calculates a vector where the origin is at the beams origin,
		// and the positive z axis is pointing in the direction the beam
		// is shooting
		offset.x = player->actor.world.pos.x + vec.x - pthis->beamOrigin.x;
		offset.y = player->actor.world.pos.y + vec.y - pthis->beamOrigin.y;
		offset.z = player->actor.world.pos.z + vec.z - pthis->beamOrigin.z;

		Matrix_RotateX(-pthis->beamPitch, MTXMODE_NEW);
		Matrix_RotateY(-pthis->beamYaw, MTXMODE_APPLY);
		Matrix_MultVec3f(&offset, &vec);

		if(fabsf(vec.x) < 30.0f && fabsf(vec.y) < 70.0f && vec.z > 100.0f && vec.z <= pthis->beamDist)
		{
			// if the beam's origin is within 30 x units, 70 y units, is farther than 100 units
			// and the distance from the beams origin to 10 units in front of link is less than the beams
			// current distance (the distance of the beam is equal to or longer than the distance to 10 units
			// in front of link)
			if(Player_HasMirrorShieldEquipped(globalCtx))
			{
				// player has mirror shield equipped
				pthis->beamDist = sqrtf(SQ(offset.x) + SQ(offset.y) + SQ(offset.z));
				return 1;
			}

			if(sBeamDivertTimer > 10)
			{
				return 0;
			}

			if(sBeamDivertTimer == 0)
			{
				// beam hit the shield, normal shield equipped,
				// divert the beam backwards from link's Y rotation
				BossTw_AddShieldDeflectEffect(globalCtx, 10.0f, pthis->actor.params);
				globalCtx->envCtx.unk_D8 = 1.0f;
				pthis->timers[0] = 10;
				Common_PlaySfx(NA_SE_IT_SHIELD_REFLECT_MG2);
			}

			sBeamDivertTimer++;
			pthis->beamDist = sqrtf(SQ(offset.x) + SQ(offset.y) + SQ(offset.z));
			return 2;
		}
	}

	return 0;
}

s32 BossTw_BeamReflHitCheck(BossTw* pthis, Vec3f* pos)
{
	Vec3f offset;
	Vec3f beamDistFromTarget;

	offset.x = pos->x - pthis->beamReflectionOrigin.x;
	offset.y = pos->y - pthis->beamReflectionOrigin.y;
	offset.z = pos->z - pthis->beamReflectionOrigin.z;

	Matrix_RotateX(-pthis->beamReflectionPitch, MTXMODE_NEW);
	Matrix_RotateY(-pthis->beamReflectionYaw, MTXMODE_APPLY);
	Matrix_MultVec3f(&offset, &beamDistFromTarget);

	if(fabsf(beamDistFromTarget.x) < 50.0f && fabsf(beamDistFromTarget.y) < 50.0f && beamDistFromTarget.z > 100.0f && beamDistFromTarget.z <= pthis->beamReflectionDist)
	{
		pthis->beamReflectionDist = sqrtf(SQ(offset.x) + SQ(offset.y) + SQ(offset.z)) * 1.1f;
		return true;
	}
	else
	{
		return false;
	}
}

f32 BossTw_GetFloorY(Vec3f* pos)
{
	Vec3f posRotated;

	if(fabsf(pos->x) < 350.0f && fabsf(pos->z) < 350.0f && pos->y < 240.0f)
	{
		if(pos->y > 200.0f)
		{
			return 240.0f;
		}
		return 35.0f;
	}

	if(fabsf(pos->x) < 110.0f && ((fabsf(pos->z - 600.0f) < 110.0f) || (fabsf(pos->z + 600.0f) < 110.0f)) && (pos->y < 230.0f))
	{
		if(pos->y > 190.0f)
		{
			return 230.0f;
		}
		return 35.0f;
	}

	if(fabsf(pos->z) < 110.0f && ((fabsf(pos->x - 600.0f) < 110.0f) || (fabsf(pos->x + 600.0f) < 110.0f)) && (pos->y < 230.0f))
	{
		if(pos->y > 190.0f)
		{
			return 230.0f;
		}
		return 35.0f;
	}

	if(pos->y < -20.0f)
	{
		return 0.0f;
	}

	if(fabsf(pos->x) > 1140.0f || fabsf(pos->z) > 1140.0f)
	{
		return 35.0f;
	}

	Matrix_Push();
	Matrix_RotateY((45.0f * (M_PI / 180.0f)), MTXMODE_NEW);
	Matrix_MultVec3f(pos, &posRotated);
	Matrix_Pop();

	if(fabsf(posRotated.x) > 920.0f || fabsf(posRotated.z) > 920.0f)
	{
		return 35.0f;
	}

	return -100.0f;
}

void BossTw_ShootBeam(BossTw* pthis, GlobalContext* globalCtx)
{
	s16 i;
	f32 xDiff;
	f32 yDiff;
	f32 zDiff;
	f32 floorY;
	Vec3f sp130;
	Vec3s sp128;
	Player* player = GET_PLAYER(globalCtx);
	BossTw* otherTw = (BossTw*)pthis->actor.parent;
	Input* input = &globalCtx->state.input[0];

	Math_ApproachF(&pthis->actor.world.pos.y, 400.0f, 0.05f, pthis->actor.speedXZ);
	Math_ApproachF(&pthis->actor.speedXZ, 5.0f, 1.0f, 0.25f);
	SkelAnime_Update(&pthis->skelAnime);
	pthis->beamRoll += -0.3f;

	if(pthis->timers[1] != 0)
	{
		Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, pthis->rotateSpeed);
		if((player->stateFlags1 & PLAYER_STATE1_22) && ((s16)((player->actor.shape.rot.y - pthis->actor.shape.rot.y) + 0x8000) < 0x2000) && ((s16)((player->actor.shape.rot.y - pthis->actor.shape.rot.y) + 0x8000) > -0x2000))
		{
			Math_ApproachF(&pthis->targetPos.x, player->bodyPartsPos[15].x, 1.0f, 400.0f);
			Math_ApproachF(&pthis->targetPos.y, player->bodyPartsPos[15].y, 1.0f, 400.0f);
			Math_ApproachF(&pthis->targetPos.z, player->bodyPartsPos[15].z, 1.0f, 400.0f);
		}
		else
		{
			Math_ApproachF(&pthis->targetPos.x, player->actor.world.pos.x, 1.0f, 400.0f);
			Math_ApproachF(&pthis->targetPos.y, player->actor.world.pos.y + 30.0f, 1.0f, 400.0f);
			Math_ApproachF(&pthis->targetPos.z, player->actor.world.pos.z, 1.0f, 400.0f);
		}

		pthis->timers[0] = 70;
		pthis->groundBlastPos.x = pthis->groundBlastPos.y = pthis->groundBlastPos.z = 0.0f;
		pthis->portalRotation += pthis->updateRate2 * 0.0025f;
		Math_ApproachF(&pthis->spawnPortalAlpha, 255.0f, 1.0f, 10.0f);
		Math_ApproachF(&pthis->updateRate2, 50.0f, 1.0f, 2.0f);

		if(pthis->timers[1] < 50)
		{
			if(pthis->timers[1] < 10)
			{
				if(pthis->timers[1] == 9)
				{
					globalCtx->envCtx.unk_D8 = 0.5f;
					globalCtx->envCtx.unk_BD = 3 - pthis->actor.params;
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_MASIC_SET);
				}

				if(pthis->timers[1] == 5)
				{
					pthis->scepterAlpha = 255;
				}

				if(pthis->timers[1] > 4)
				{
					s16 j;
					for(j = 0; j < 2; j++)
					{
						for(i = 0; i < ARRAY_COUNT(pthis->scepterFlamePos); i++)
						{
							Vec3f pos;
							Vec3f velocity;
							Vec3f accel;

							pos.x = pthis->scepterFlamePos[i].x;
							pos.y = pthis->scepterFlamePos[i].y;
							pos.z = pthis->scepterFlamePos[i].z;
							velocity.x = Rand_CenteredFloat(10.0f);
							velocity.y = Rand_CenteredFloat(10.0f);
							velocity.z = Rand_CenteredFloat(10.0f);
							accel.x = 0.0f;
							accel.y = 0.0f;
							accel.z = 0.0f;
							BossTw_AddFlameEffect(globalCtx, &pos, &velocity, &accel, Rand_ZeroFloat(10.0f) + 25.0f, pthis->actor.params);
						}
					}
				}
			}

			if(pthis->timers[1] < 20)
			{
				Math_ApproachF(&pthis->flameAlpha, 0, 1.0f, 20.0f);
				Math_ApproachF(&pthis->spawnPortalAlpha, 0, 1.0f, 30.0f);
			}
			else
			{
				Math_ApproachF(&pthis->flameAlpha, 255.0f, 1.0f, 10.0f);
				if(pthis->actor.params == 1)
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_MS_FIRE - SFX_FLAG);
				}
				else
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_MS_FREEZE - SFX_FLAG);
				}
			}

			pthis->flameRotation += pthis->updateRate1 * 0.0025f;
			Math_ApproachF(&pthis->spawnPortalScale, 0.0f, 0.1f, pthis->updateRate1);
			Math_ApproachF(&pthis->updateRate1, 50.0f, 1.0f, 2.0f);
		}

		if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
		{
			Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_009398, 0.0f);
			pthis->workf[ANIM_SW_TGT] = 10000.0f;
		}

		if(pthis->timers[1] == 1)
		{
			Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_003614, 0.0f);
			pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_003614);
			pthis->unk_4DC = 0.0f;
			pthis->spawnPortalAlpha = 0.0f;
			pthis->flameAlpha = 0.0f;
			sBeamDivertTimer = 0;
		}
	}
	else
	{
		if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
		{
			Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_003E34, 0.0f);
			pthis->workf[ANIM_SW_TGT] = 10000.0f;
		}

		if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT] - 5.0f))
		{
			pthis->beamShootState = 0;
			sEnvType = pthis->actor.params + 1;
		}

		if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT] - 13.0f))
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_THROW_MASIC);
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_SHOOT_VOICE);
		}

		xDiff = pthis->targetPos.x - pthis->beamOrigin.x;
		yDiff = pthis->targetPos.y - pthis->beamOrigin.y;
		zDiff = pthis->targetPos.z - pthis->beamOrigin.z;

		pthis->beamYaw = Math_FAtan2F(xDiff, zDiff);
		pthis->beamPitch = -Math_FAtan2F(yDiff, sqrtf(SQ(xDiff) + SQ(zDiff)));

		switch(pthis->beamShootState)
		{
			case -1:
				break;
			case 0:
				if(pthis->timers[0] != 0)
				{
					s32 beamReflection = BossTw_CheckBeamReflection(pthis, globalCtx);

					if(beamReflection == 1)
					{
						Vec3f pos;
						Vec3f velocity;
						Vec3f accel = {0.0f, 0.0f, 0.0f};

						for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
						{
							velocity.x = Rand_CenteredFloat(15.0f);
							velocity.y = Rand_CenteredFloat(15.0f);
							velocity.z = Rand_CenteredFloat(15.0f);
							pos = player->bodyPartsPos[15];
							BossTw_AddDotEffect(globalCtx, &pos, &velocity, &accel, (s16)Rand_ZeroFloat(2.0f) + 5, pthis->actor.params, 150);
						}

						pthis->beamShootState = 1;
						Common_PlaySfxAtPos(&player->actor.projectedPos, NA_SE_IT_SHIELD_REFLECT_MG);
						Matrix_MtxFToYXZRotS(&player->shieldMf, &sp128, 0);
						sp128.y += 0x8000;
						sp128.x = -sp128.x;
						pthis->magicDir.x = sp128.x;
						pthis->magicDir.y = sp128.y;
						pthis->groundBlastPos.x = 0.0f;
						pthis->groundBlastPos.y = 0.0f;
						pthis->groundBlastPos.z = 0.0f;
						globalCtx->envCtx.unk_D8 = 1.0f;
						Rumble_Shake(0.0f, 0x64, 5, 4);
					}
					else if(beamReflection == 0)
					{
						BossTw_BeamHitPlayerCheck(pthis, globalCtx);

						if(pthis->csState1 == 0)
						{
							Math_ApproachF(&pthis->beamDist, 2.0f * sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff)), 1.0f, 40.0f);
						}
					}
				}

				SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->viewProjectionMtxF, &pthis->beamReflectionOrigin, &pthis->unk_54C, &pthis->actor.projectedW);

				if(pthis->actor.params == 1)
				{
					Audio_PlaySoundGeneral(NA_SE_EN_TWINROBA_SHOOT_FIRE - SFX_FLAG, &pthis->unk_54C, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				}
				else
				{
					Audio_PlaySoundGeneral(NA_SE_EN_TWINROBA_SHOOT_FREEZE - SFX_FLAG, &pthis->unk_54C, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				}
				break;

			case 1:
				if(CHECK_BTN_ALL(input->cur.button, BTN_R))
				{
					Player* player = GET_PLAYER(globalCtx);

					pthis->beamDist = sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff));
					Math_ApproachF(&pthis->beamReflectionDist, 2000.0f, 1.0f, 40.0f);
					Math_ApproachF(&pthis->targetPos.x, player->bodyPartsPos[15].x, 1.0f, 400.0f);
					Math_ApproachF(&pthis->targetPos.y, player->bodyPartsPos[15].y, 1.0f, 400.0f);
					Math_ApproachF(&pthis->targetPos.z, player->bodyPartsPos[15].z, 1.0f, 400.0f);
					if((pthis->work[CS_TIMER_1] % 4) == 0)
					{
						BossTw_AddRingEffect(globalCtx, &player->bodyPartsPos[15], 0.5f, 3.0f, 0xFF, pthis->actor.params, 1, 150);
					}
				}
				else
				{
					pthis->beamShootState = 0;
					pthis->beamReflectionDist = 0.0f;
				}

				SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->viewProjectionMtxF, &pthis->unk_530, &pthis->unk_558, &pthis->actor.projectedW);

				if(pthis->actor.params == 1)
				{
					Audio_PlaySoundGeneral(NA_SE_EN_TWINROBA_SHOOT_FIRE - SFX_FLAG, &pthis->unk_558, 4U, &D_801333E0, &D_801333E0, &gReverbAdd2);
					Audio_PlaySoundGeneral(NA_SE_EN_TWINROBA_REFL_FIRE - SFX_FLAG, &pthis->unk_558, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				}
				else
				{
					Audio_PlaySoundGeneral(NA_SE_EN_TWINROBA_SHOOT_FREEZE - SFX_FLAG, &pthis->unk_558, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
					Audio_PlaySoundGeneral(NA_SE_EN_TWINROBA_REFL_FREEZE - SFX_FLAG, &pthis->unk_558, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				}
				break;
		}

		if(pthis->timers[0] == 0 && (sEnvType == 1 || sEnvType == 2))
		{
			sEnvType = 0;
		}

		if(pthis->timers[0] == 0)
		{
			Math_ApproachF(&pthis->beamScale, 0.0f, 1.0f, 0.0005f);

			if(pthis->beamScale == 0.0f)
			{
				BossTw_SetupFinishBeamShoot(pthis, globalCtx);
				pthis->beamReflectionDist = 0.0f;
				pthis->beamDist = 0.0f;
			}
		}
	}

	Matrix_Translate(pthis->beamOrigin.x, pthis->beamOrigin.y, pthis->beamOrigin.z, MTXMODE_NEW);
	Matrix_RotateY(pthis->beamYaw, MTXMODE_APPLY);
	Matrix_RotateX(pthis->beamPitch, MTXMODE_APPLY);

	sp130.x = 0.0f;
	sp130.y = 0.0f;
	sp130.z = pthis->beamDist + -5.0f;

	Matrix_MultVec3f(&sp130, &pthis->beamReflectionOrigin);

	if((pthis->csState1 == 0) && (pthis->beamShootState == 0) && (pthis->timers[0] != 0))
	{
		pthis->groundBlastPos.y = BossTw_GetFloorY(&pthis->beamReflectionOrigin);

		if(pthis->groundBlastPos.y >= 0.0f)
		{
			pthis->csState1 = 1;
			pthis->groundBlastPos.x = pthis->beamReflectionOrigin.x;
			pthis->groundBlastPos.z = pthis->beamReflectionOrigin.z;
			BossTw_SpawnGroundBlast(pthis, globalCtx, pthis->actor.params);
			pthis->timers[0] = 20;
		}
	}

	if(pthis->beamShootState == 1)
	{
		if(pthis->csState1 == 0)
		{
			Matrix_MtxFToYXZRotS(&player->shieldMf, &sp128, 0);
			sp128.y += 0x8000;
			sp128.x = -sp128.x;
			Math_ApproachS(&pthis->magicDir.x, sp128.x, 5, 0x2000);
			Math_ApproachS(&pthis->magicDir.y, sp128.y, 5, 0x2000);
			pthis->beamReflectionPitch = (pthis->magicDir.x / 32768.0f) * M_PI;
			pthis->beamReflectionYaw = (pthis->magicDir.y / 32768.0f) * M_PI;
		}

		Matrix_Translate(pthis->beamReflectionOrigin.x, pthis->beamReflectionOrigin.y, pthis->beamReflectionOrigin.z, MTXMODE_NEW);
		Matrix_RotateY(pthis->beamReflectionYaw, MTXMODE_APPLY);
		Matrix_RotateX(pthis->beamReflectionPitch, MTXMODE_APPLY);

		sp130.x = 0.0f;
		sp130.y = 0.0f;
		sp130.z = pthis->beamReflectionDist + -170.0f;

		Matrix_MultVec3f(&sp130, &pthis->unk_530);

		if(pthis->csState1 == 0)
		{
			sp130.z = 0.0f;

			for(i = 0; i < 200; i++)
			{
				Vec3f spBC;

				Matrix_MultVec3f(&sp130, &spBC);
				floorY = BossTw_GetFloorY(&spBC);
				pthis->groundBlastPos.y = floorY;

				if(floorY >= 0.0f)
				{
					if((pthis->groundBlastPos.y != 35.0f) && (0.0f < pthis->beamReflectionPitch) && (pthis->timers[0] != 0))
					{
						pthis->csState1 = 1;
						pthis->groundBlastPos.x = spBC.x;
						pthis->groundBlastPos.z = spBC.z;
						BossTw_SpawnGroundBlast(pthis, globalCtx, pthis->actor.params);
						pthis->timers[0] = 20;
					}
					else
					{
						for(i = 0; i < 5; i++)
						{
							Vec3f velocity;
							Vec3f accel;

							velocity.x = Rand_CenteredFloat(20.0f);
							velocity.y = Rand_CenteredFloat(20.0f);
							velocity.z = Rand_CenteredFloat(20.0f);

							accel.x = 0.0f;
							accel.y = 0.0f;
							accel.z = 0.0f;

							BossTw_AddFlameEffect(globalCtx, &pthis->unk_530, &velocity, &accel, Rand_ZeroFloat(10.0f) + 25.0f, pthis->actor.params);
						}

						pthis->beamReflectionDist = sp130.z;
						Math_ApproachF(&globalCtx->envCtx.unk_D8, 0.8f, 1.0f, 0.2f);
					}
					break;
				}

				sp130.z += 20.0f;

				if(pthis->beamReflectionDist < sp130.z)
				{
					break;
				}
			}
		}

		if(BossTw_BeamReflHitCheck(pthis, &pthis->actor.world.pos) && (pthis->work[CS_TIMER_1] % 4) == 0)
		{
			BossTw_AddRingEffect(globalCtx, &pthis->unk_530, 0.5f, 3.0f, 255, pthis->actor.params, 1, 150);
		}

		if(BossTw_BeamReflHitCheck(pthis, &otherTw->actor.world.pos) && otherTw->actionFunc != BossTw_HitByBeam)
		{
			for(i = 0; i < 50; i++)
			{
				Vec3f pos;
				Vec3f velocity;
				Vec3f accel;

				pos.x = otherTw->actor.world.pos.x + Rand_CenteredFloat(50.0f);
				pos.y = otherTw->actor.world.pos.y + Rand_CenteredFloat(50.0f);
				pos.z = otherTw->actor.world.pos.z + Rand_CenteredFloat(50.0f);

				velocity.x = Rand_CenteredFloat(20.0f);
				velocity.y = Rand_CenteredFloat(20.0f);
				velocity.z = Rand_CenteredFloat(20.0f);

				accel.x = 0.0f;
				accel.y = 0.0f;
				accel.z = 0.0f;

				BossTw_AddFlameEffect(globalCtx, &pos, &velocity, &accel, Rand_ZeroFloat(10.0f) + 25.0f, pthis->actor.params);
			}

			BossTw_SetupHitByBeam(otherTw, globalCtx);
			Audio_PlayActorSound2(&otherTw->actor, NA_SE_EN_TWINROBA_DAMAGE_VOICE);
			globalCtx->envCtx.unk_D8 = 1.0f;
			otherTw->actor.colChkInfo.health++;
		}
	}
}

void BossTw_SetupFinishBeamShoot(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_FinishBeamShoot;
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_004548, 0.0f);
	pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_004548);
}

void BossTw_FinishBeamShoot(BossTw* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	Math_ApproachF(&pthis->scepterAlpha, 0.0f, 1.0f, 10.0f);

	if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
	{
		if(sTwinrovaPtr->timers[2] == 0)
		{
			BossTw_SetupFlyTo(pthis, globalCtx);
		}
		else
		{
			BossTw_SetupLaugh(pthis, globalCtx);
		}

		pthis->scepterAlpha = 0.0f;
	}
}

void BossTw_SetupHitByBeam(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_HitByBeam;
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_00578C, 0.0f);
	pthis->timers[0] = 53;
	pthis->actor.speedXZ = 0.0f;

	if(pthis->actor.params == 0)
	{
		pthis->work[FOG_TIMER] = 20;
	}
}

void BossTw_HitByBeam(BossTw* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);

	if((pthis->work[CS_TIMER_1] % 4) == 0)
	{
		Vec3f pos;
		Vec3f velocity;
		Vec3f accel;

		pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(80.0f);
		pos.y = pthis->actor.world.pos.y + Rand_CenteredFloat(80.0f);
		pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(80.0f);

		velocity.x = 0.0f;
		velocity.y = 0.0f;
		velocity.z = 0.0f;

		accel.x = 0.0f;
		accel.y = 0.1f;
		accel.z = 0.0f;

		BossTw_AddDmgCloud(globalCtx, pthis->actor.params + 2, &pos, &velocity, &accel, Rand_ZeroFloat(10.0f) + 15.0f, 0, 0, 150);
	}

	if(pthis->actor.params == 1)
	{
		Math_ApproachF(&pthis->fogR, 255.0f, 1.0f, 30.0f);
		Math_ApproachF(&pthis->fogG, 255.0f, 1.0f, 30.0f);
		Math_ApproachF(&pthis->fogB, 255.0f, 1.0f, 30.0f);
		Math_ApproachF(&pthis->fogNear, 900.0f, 1.0f, 30.0f);
		Math_ApproachF(&pthis->fogFar, 1099.0f, 1.0f, 30.0f);
	}

	Math_ApproachF(&pthis->actor.world.pos.y, ((Math_SinS(pthis->work[CS_TIMER_1] * 1500) * 20.0f) + 350.0f) + 50.0f, 0.1f, pthis->actor.speedXZ);
	Math_ApproachF(&pthis->actor.speedXZ, 5.0f, 1.0f, 1.0f);

	pthis->actor.world.pos.y -= 50.0f;
	Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 4);
	pthis->actor.world.pos.y += 50.0f;

	if(pthis->actor.bgCheckFlags & BG_STATE_0)
	{
		pthis->actor.speedXZ = 0.0f;
	}

	if(pthis->timers[0] == 1)
	{
		Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_006530, 0.0f);
		pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_006530);
	}

	if((pthis->timers[0] == 0) && Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
	{
		BossTw_SetupFlyTo(pthis, globalCtx);
	}
}

void BossTw_SetupLaugh(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_Laugh;
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_0088C8, 0.0f);
	pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_0088C8);
	pthis->actor.speedXZ = 0.0f;
}

void BossTw_Laugh(BossTw* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);

	if(Animation_OnFrame(&pthis->skelAnime, 10.0f))
	{
		if(pthis->actor.params == TW_KOUME)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_LAUGH);
		}
		else
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_LAUGH2);
		}
	}

	if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
	{
		BossTw_SetupFlyTo(pthis, globalCtx);
	}
}

void BossTw_SetupSpin(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_Spin;
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_007CA8, -3.0f);
	pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_007CA8);
	pthis->actor.speedXZ = 0.0f;
	SkelAnime_Update(&pthis->skelAnime);
	pthis->timers[0] = 20;
}

void BossTw_Spin(BossTw* pthis, GlobalContext* globalCtx)
{
	if(pthis->timers[0] != 0)
	{
		pthis->collider.base.colType = COLTYPE_METAL;
		pthis->actor.shape.rot.y -= 0x3000;

		if((pthis->timers[0] % 4) == 0)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_ROLL);
		}
	}
	else
	{
		SkelAnime_Update(&pthis->skelAnime);
		Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.y, 3, 0x2000);

		if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
		{
			BossTw_SetupFlyTo(pthis, globalCtx);
		}
	}
}

void BossTw_SetupMergeCS(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_MergeCS;
	pthis->rotateSpeed = 0.0f;
	pthis->actor.speedXZ = 0.0f;
	Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_006F28, -10.0f);
}

void BossTw_MergeCS(BossTw* pthis, GlobalContext* globalCtx)
{
	Math_ApproachF(&pthis->scepterAlpha, 0.0f, 1.0f, 10.0f);
	SkelAnime_Update(&pthis->skelAnime);
}

void BossTw_SetupWait(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_Wait;
	pthis->visible = false;
	pthis->actor.world.pos.y = -2000.0f;
	pthis->actor.flags &= ~ACTOR_FLAG_0;
}

void BossTw_Wait(BossTw* pthis, GlobalContext* globalCtx)
{
	if((pthis->actor.params == TW_TWINROVA) && (sKoumePtr->actionFunc == BossTw_FlyTo) && (sKotakePtr->actionFunc == BossTw_FlyTo) && ((sKoumePtr->actor.colChkInfo.health + sKotakePtr->actor.colChkInfo.health) >= 4))
	{
		BossTw_TwinrovaSetupMergeCS(pthis, globalCtx);
		BossTw_SetupMergeCS(sKotakePtr, globalCtx);
		BossTw_SetupMergeCS(sKoumePtr, globalCtx);
	}
}

void BossTw_TwinrovaSetupMergeCS(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_TwinrovaMergeCS;
	pthis->csState2 = 0;
	pthis->csState1 = 0;
}

void BossTw_TwinrovaMergeCS(BossTw* pthis, GlobalContext* globalCtx)
{
	s16 i;
	Vec3f spB0;
	Vec3f spA4;
	Player* player = GET_PLAYER(globalCtx);

	switch(pthis->csState2)
	{
		case 0:
			pthis->csState2 = 1;
			func_80064520(globalCtx, &globalCtx->csCtx);
			func_8002DF54(globalCtx, &pthis->actor, 0x39);
			pthis->subCamId = Gameplay_CreateSubCamera(globalCtx);
			Gameplay_ChangeCameraStatus(globalCtx, 0, CAM_STAT_WAIT);
			Gameplay_ChangeCameraStatus(globalCtx, pthis->subCamId, CAM_STAT_ACTIVE);
			pthis->subCamDist = 800.0f;
			pthis->subCamYaw = M_PI;
			sKoumePtr->actor.world.rot.x = 0;
			sKoumePtr->actor.shape.rot.x = 0;
			sKotakePtr->actor.world.rot.x = 0;
			sKotakePtr->actor.shape.rot.x = 0;
			pthis->workf[UNK_F9] = 0.0f;
			pthis->workf[UNK_F10] = 0.0f;
			pthis->workf[UNK_F11] = 600.0f;
			Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0xC800FF);
			pthis->work[CS_TIMER_2] = 0;
			// fallthrough
		case 1:
			if(pthis->work[CS_TIMER_2] == 20)
			{
				Message_StartTextbox(globalCtx, 0x6059, NULL);
			}

			if(pthis->work[CS_TIMER_2] == 80)
			{
				Message_StartTextbox(globalCtx, 0x605A, NULL);
			}

			pthis->subCamAt.x = 0.0f;
			pthis->subCamAt.y = 440.0f;
			pthis->subCamAt.z = 0.0f;

			spB0.x = 0.0f;
			spB0.y = 0.0f;
			spB0.z = pthis->subCamDist;

			Matrix_RotateY(pthis->subCamYaw, MTXMODE_NEW);
			Matrix_MultVec3f(&spB0, &spA4);

			pthis->subCamEye.x = spA4.x;
			pthis->subCamEye.y = 300.0f;
			pthis->subCamEye.z = spA4.z;

			Math_ApproachF(&pthis->subCamYaw, 0.3f, 0.02f, 0.03f);
			Math_ApproachF(&pthis->subCamDist, 200.0f, 0.1f, 5.0f);
			break;

		case 2:
			spB0.x = 0.0f;
			spB0.y = 0.0f;
			spB0.z = pthis->subCamDist;
			Matrix_RotateY(pthis->subCamYaw, MTXMODE_NEW);
			Matrix_MultVec3f(&spB0, &spA4);
			pthis->subCamEye.x = spA4.x;
			pthis->subCamEye.z = spA4.z;
			Math_ApproachF(&pthis->subCamEye.y, 420.0f, 0.1f, pthis->subCamUpdateRate * 20.0f);
			Math_ApproachF(&pthis->subCamAt.y, 470.0f, 0.1f, pthis->subCamUpdateRate * 6.0f);
			Math_ApproachF(&pthis->subCamYaw, 0.3f, 0.02f, 0.03f);
			Math_ApproachF(&pthis->subCamDist, 60.0f, 0.1f, pthis->subCamUpdateRate * 32.0f);
			Math_ApproachF(&pthis->subCamUpdateRate, 1, 1, 0.1f);
			break;
	}

	if(pthis->subCamId != 0)
	{
		if(pthis->unk_5F9 == 0)
		{
			Gameplay_CameraSetAtEye(globalCtx, pthis->subCamId, &pthis->subCamAt, &pthis->subCamEye);
		}
		else
		{
			Gameplay_CameraSetAtEye(globalCtx, pthis->subCamId, &pthis->subCamAt2, &pthis->subCamEye2);
		}
	}

	switch(pthis->csState1)
	{
		case 0:
			Audio_PlayActorSound2(&sKotakePtr->actor, NA_SE_EN_TWINROBA_FLY - SFX_FLAG);
			Audio_PlayActorSound2(&sKoumePtr->actor, NA_SE_EN_TWINROBA_FLY - SFX_FLAG);
			spB0.x = pthis->workf[UNK_F11];
			spB0.y = 400.0f;
			spB0.z = 0.0f;
			Matrix_RotateY(pthis->workf[UNK_F9], MTXMODE_NEW);
			Matrix_MultVec3f(&spB0, &spA4);
			sKoumePtr->actor.world.pos.x = spA4.x;
			sKoumePtr->actor.world.pos.y = spA4.y;
			sKoumePtr->actor.world.pos.z = spA4.z;
			sKoumePtr->actor.shape.rot.y = (pthis->workf[UNK_F9] / M_PI) * 32768.0f;
			sKotakePtr->actor.world.pos.x = -spA4.x;
			sKotakePtr->actor.world.pos.y = spA4.y;
			sKotakePtr->actor.world.pos.z = -spA4.z;
			sKotakePtr->actor.shape.rot.y = ((pthis->workf[UNK_F9] / M_PI) * 32768.0f) + 32768.0f;
			Math_ApproachF(&pthis->workf[UNK_F11], 0.0f, 0.1f, 7.0f);
			pthis->workf[UNK_F9] -= pthis->workf[UNK_F10];
			Math_ApproachF(&pthis->workf[UNK_F10], 0.5f, 1, 0.0039999997f);
			if(pthis->workf[UNK_F11] < 10.0f)
			{
				if(!pthis->work[PLAYED_CHRG_SFX])
				{
					Audio_PlayActorSound2(&sKoumePtr->actor, NA_SE_EN_TWINROBA_POWERUP);
					pthis->work[PLAYED_CHRG_SFX] = true;
				}

				Math_ApproachF(&sKoumePtr->actor.scale.x, 0.005000001f, 1, 0.0003750001f);

				for(i = 0; i < 4; i++)
				{
					Vec3f pos;
					f32 yOffset;
					f32 xScale;

					xScale = sKoumePtr->actor.scale.x * 3000.0f;
					yOffset = Rand_CenteredFloat(xScale * 2.0f);
					pos.x = 3000.0f;
					pos.y = 400.0f + yOffset;
					pos.z = 0.0f;
					BossTw_AddMergeFlameEffect(globalCtx, &pos, Rand_ZeroFloat(5.0f) + 10.0f, sqrtf(SQ(xScale) - SQ(yOffset)), Rand_ZeroFloat(1.99f));
				}

				if(sKoumePtr->actor.scale.x <= 0.0051f)
				{
					Vec3f pos;
					Vec3f velocity;
					Vec3f accel;

					pthis->actor.world.pos.y = 400.0f;

					for(i = 0; i < 50; i++)
					{
						pos = pthis->actor.world.pos;
						velocity.x = Rand_CenteredFloat(20.0f);
						velocity.y = Rand_CenteredFloat(20.0f);
						velocity.z = Rand_CenteredFloat(20.0f);
						pos.x += velocity.x;
						pos.y += velocity.y;
						pos.z += velocity.z;
						accel.z = accel.y = accel.x = 0.0f;
						BossTw_AddFlameEffect(globalCtx, &pos, &velocity, &accel, Rand_ZeroFloat(10.0f) + 25.0f, velocity.x < 0.0f);
					}

					pthis->csState1 = 1;
					pthis->visible = true;
					pthis->actor.flags |= ACTOR_FLAG_0;
					pthis->actor.shape.rot.y = 0;
					BossTw_SetupWait(sKotakePtr, globalCtx);
					BossTw_SetupWait(sKoumePtr, globalCtx);
					Actor_SetScale(&pthis->actor, 0.0f);
					Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_038E2C, 0.0f);
					pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_038E2C);
					pthis->timers[0] = 50;
					func_8002DF54(globalCtx, &pthis->actor, 2);
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_TRANSFORM);
					Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS);
				}
			}

			sKotakePtr->actor.scale.x = sKotakePtr->actor.scale.y = sKotakePtr->actor.scale.z = sKoumePtr->actor.scale.y = sKoumePtr->actor.scale.z = sKoumePtr->actor.scale.x;
			break;

		case 1:
			if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
			{
				Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_032BF8, -15.0f);
			}

			sEnvType = -1;
			globalCtx->envCtx.unk_BD = 4;
			Math_ApproachF(&globalCtx->envCtx.unk_D8, 1, 1, 0.1f);
			// fallthrough
		case 2:
			SkelAnime_Update(&pthis->skelAnime);
			Math_ApproachF(&pthis->actor.scale.x, 0.0069999993f, 1, 0.0006999999f);
			pthis->actor.scale.y = pthis->actor.scale.z = pthis->actor.scale.x;

			if(pthis->timers[0] == 1)
			{
				pthis->csState2 = 2;
				pthis->subCamUpdateRate = 0.0f;
				pthis->timers[1] = 65;
				pthis->timers[2] = 90;
				pthis->timers[3] = 50;
				player->actor.world.pos.x = 0.0f;
				player->actor.world.pos.y = 240.0f;
				player->actor.world.pos.z = 270.0f;
				player->actor.world.rot.y = player->actor.shape.rot.y = -0x8000;
				pthis->subCamEye2.x = 0.0f;
				pthis->subCamEye2.y = 290.0f;
				pthis->subCamEye2.z = 222.0f;
				pthis->subCamAt2.x = player->actor.world.pos.x;
				pthis->subCamAt2.y = player->actor.world.pos.y + 54.0f;
				pthis->subCamAt2.z = player->actor.world.pos.z;
			}

			if(pthis->timers[3] == 19)
			{
				func_8002DF54(globalCtx, &pthis->actor, 5);
			}

			if(pthis->timers[3] == 16)
			{
				func_8002F7DC(&player->actor, player->ageProperties->unk_92 + NA_SE_VO_LI_SURPRISE);
			}

			if((pthis->timers[3] != 0) && (pthis->timers[3] < 20))
			{
				pthis->unk_5F9 = 1;
				Math_ApproachF(&pthis->subCamEye2.z, 242.0f, 0.2f, 100.0f);
			}
			else
			{
				pthis->unk_5F9 = 0;
			}

			if(pthis->timers[1] == 8)
			{
				pthis->work[TW_BLINK_IDX] = 8;
				Common_PlaySfx(NA_SE_EN_TWINROBA_YOUNG_WINK);
			}
			if(pthis->timers[2] == 4)
			{
				sEnvType = 0;
				globalCtx->envCtx.unk_BE = 5;
			}

			if(pthis->timers[2] == 1)
			{
				Camera* cam = Gameplay_GetCamera(globalCtx, MAIN_CAM);

				cam->eye = pthis->subCamEye;
				cam->eyeNext = pthis->subCamEye;
				cam->at = pthis->subCamAt;
				func_800C08AC(globalCtx, pthis->subCamId, 0);
				pthis->subCamId = 0;
				pthis->csState2 = pthis->subCamId;
				func_80064534(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 7);
				pthis->work[TW_PLLR_IDX] = 0;
				pthis->targetPos = sTwinrovaPillarPos[0];
				BossTw_TwinrovaSetupFly(pthis, globalCtx);
			}
			break;
	}
}

void BossTw_SetupDeathCS(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_DeathCS;
	Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_0004A4, -3.0f);
	pthis->unk_5F8 = 0;
	pthis->work[CS_TIMER_2] = Rand_ZeroFloat(20.0f);
}

void BossTw_DeathCS(BossTw* pthis, GlobalContext* globalCtx)
{
	if(pthis->timers[0] == 0)
	{
		SkelAnime_Update(&pthis->skelAnime);
	}

	Math_ApproachS(&pthis->actor.shape.rot.y, pthis->work[YAW_TGT], 5, pthis->rotateSpeed);
	Math_ApproachF(&pthis->rotateSpeed, 20480.0f, 1.0f, 1000.0f);

	if(sTwinrovaPtr->work[CS_TIMER_2] > 140)
	{
		Math_ApproachF(&pthis->fogR, 100.0f, 1.0f, 15.0f);
		Math_ApproachF(&pthis->fogG, 255.0f, 1.0f, 15.0f);
		Math_ApproachF(&pthis->fogB, 255.0f, 1.0f, 15.0f);
		Math_ApproachF(&pthis->fogNear, 850.0f, 1.0f, 15.0f);
		Math_ApproachF(&pthis->fogFar, 1099.0f, 1.0f, 15.0f);
	}
}

void BossTw_SetupCSWait(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_CSWait;
	pthis->visible = false;
	pthis->actor.world.pos.y = -2000.0f;
	pthis->actor.flags &= ~ACTOR_FLAG_0;
}

/**
 * Do nothing while waiting for the inital cutscene to start
 */
void BossTw_CSWait(BossTw* pthis, GlobalContext* globalCtx)
{
}

void BossTw_TwinrovaSetupIntroCS(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_TwinrovaIntroCS;
	pthis->visible = false;
	pthis->actor.world.pos.y = -2000.0f;
	pthis->actor.flags &= ~ACTOR_FLAG_0;
}

void BossTw_TwinrovaIntroCS(BossTw* pthis, GlobalContext* globalCtx)
{
	u8 updateCam = 0;
	s16 i;
	Vec3f sp90;
	Vec3f sp84;
	Player* player = GET_PLAYER(globalCtx);

	if(pthis->csSfxTimer > 220 && pthis->csSfxTimer < 630)
	{
		Common_PlaySfx(NA_SE_EN_TWINROBA_UNARI - SFX_FLAG);
	}

	if(pthis->csSfxTimer == 180)
	{
		Common_PlaySfxAtPos(&D_8094A7D0, NA_SE_EN_TWINROBA_LAUGH);
		Common_PlaySfxAtPos(&D_8094A7D0, NA_SE_EN_TWINROBA_LAUGH2);
		Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_KOTAKE_KOUME);
	}

	pthis->csSfxTimer++;

	switch(pthis->csState2)
	{
		case 0:
			pthis->csSfxTimer = 0;

			if(SQ(player->actor.world.pos.x) + SQ(player->actor.world.pos.z) < SQ(150.0f))
			{
				player->actor.world.pos.x = player->actor.world.pos.z = .0f;
				pthis->csState2 = 1;
				func_80064520(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 0x39);
				pthis->subCamId = Gameplay_CreateSubCamera(globalCtx);
				Gameplay_ChangeCameraStatus(globalCtx, 0, CAM_STAT_WAIT);
				Gameplay_ChangeCameraStatus(globalCtx, pthis->subCamId, CAM_STAT_ACTIVE);
				pthis->subCamEye.x = 0.0f;
				pthis->subCamEye.y = 350;
				pthis->subCamEye.z = 200;

				pthis->subCamEyeTarget.x = 450;
				pthis->subCamEyeTarget.y = 900;

				pthis->subCamAt.x = 0;
				pthis->subCamAt.y = 270;
				pthis->subCamAt.z = 0;

				pthis->subCamAtTarget.x = 0;
				pthis->subCamAtTarget.y = 240;
				pthis->subCamAtTarget.z = 140;

				pthis->subCamEyeTarget.z = 530;
				pthis->subCamEyeStep.x = fabsf(pthis->subCamEyeTarget.x - pthis->subCamEye.x);
				pthis->subCamEyeStep.y = fabsf(pthis->subCamEyeTarget.y - pthis->subCamEye.y);
				pthis->subCamEyeStep.z = fabsf(pthis->subCamEyeTarget.z - pthis->subCamEye.z);
				pthis->subCamAtStep.x = fabsf(pthis->subCamAtTarget.x - pthis->subCamAt.x);
				pthis->subCamAtStep.y = fabsf(pthis->subCamAtTarget.y - pthis->subCamAt.y);
				pthis->subCamAtStep.z = fabsf(pthis->subCamAtTarget.z - pthis->subCamAt.z);

				pthis->subCamDistStep = 0.05f;
				pthis->work[CS_TIMER_1] = 0;
			}
			break;

		case 1:
			updateCam = 1;

			if(pthis->work[CS_TIMER_1] == 30)
			{
				Message_StartTextbox(globalCtx, 0x6048, NULL);
			}

			Math_ApproachF(&pthis->subCamUpdateRate, 0.01f, 1.0f, 0.0001f);

			if(pthis->work[CS_TIMER_1] > 100)
			{
				globalCtx->envCtx.unk_BD = 0;
				Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.03f);
			}

			if(pthis->work[CS_TIMER_1] == 180)
			{
				Common_PlaySfx(NA_SE_EN_TWINROBA_APPEAR_MS);
			}

			if(pthis->work[CS_TIMER_1] > 180)
			{
				pthis->spawnPortalScale = 0.05f;
				Math_ApproachF(&pthis->spawnPortalAlpha, 255.0f, 1.0f, 5.f);

				if(pthis->work[CS_TIMER_1] >= 236)
				{
					pthis->csState2 = 2;
					sKoumePtr->visible = 1;
					Animation_MorphToLoop(&sKoumePtr->skelAnime, &object_tw_Anim_0004A4, 0.0f);
					sKoumePtr->actor.world.pos.x = 0.0f;
					sKoumePtr->actor.world.pos.y = 80.0f;
					sKoumePtr->actor.world.pos.z = 600.0f;
					sKoumePtr->actor.shape.rot.y = sKoumePtr->actor.world.rot.y = -0x8000;

					pthis->subCamEye.x = -30;
					pthis->subCamEye.y = 260;
					pthis->subCamEye.z = 470;

					pthis->subCamAt.x = 0.0F;
					pthis->subCamAt.y = 270;
					pthis->subCamAt.z = 600.0F;

					pthis->work[CS_TIMER_1] = 0;

					Actor_SetScale(&sKoumePtr->actor, 0.014999999f);
				}
			}
			break;

		case 2:
			SkelAnime_Update(&sKoumePtr->skelAnime);
			Math_ApproachF(&sKoumePtr->actor.world.pos.y, 240.0f, 0.05f, 5.0f);
			pthis->subCamEye.x -= 0.2f;
			pthis->subCamEye.z += 0.2f;

			if(pthis->work[CS_TIMER_1] > 50)
			{
				pthis->csState2 = 3;

				pthis->subCamEyeTarget.x = -30;
				pthis->subCamEyeTarget.y = 260;
				pthis->subCamEyeTarget.z = 530;

				pthis->subCamAtTarget.x = 0.0f;
				pthis->subCamAtTarget.y = 265;
				pthis->subCamAtTarget.z = 580;

				pthis->subCamEyeStep.x = fabsf(pthis->subCamEyeTarget.x - pthis->subCamEye.x);
				pthis->subCamEyeStep.y = fabsf(pthis->subCamEyeTarget.y - pthis->subCamEye.y);
				pthis->subCamEyeStep.z = fabsf(pthis->subCamEyeTarget.z - pthis->subCamEye.z);
				pthis->subCamAtStep.x = fabsf(pthis->subCamAtTarget.x - pthis->subCamAt.x);
				pthis->subCamAtStep.y = fabsf(pthis->subCamAtTarget.y - pthis->subCamAt.y);
				pthis->subCamAtStep.z = fabsf(pthis->subCamAtTarget.z - pthis->subCamAt.z);
				pthis->subCamUpdateRate = 0;
				pthis->subCamDistStep = 0.1f;
				pthis->work[CS_TIMER_1] = 0;
			}
			break;

		case 3:
			SkelAnime_Update(&sKoumePtr->skelAnime);
			updateCam = 1;
			Math_ApproachF(&sKoumePtr->actor.world.pos.y, 240.0f, 0.05f, 5.0f);
			Math_ApproachF(&pthis->subCamUpdateRate, 1.0f, 1.0f, 0.02f);

			if(pthis->work[CS_TIMER_1] == 30)
			{
				Message_StartTextbox(globalCtx, 0x6049, NULL);
			}

			if(pthis->work[CS_TIMER_1] > 80)
			{
				pthis->csState2 = 4;
				pthis->actor.speedXZ = 0;

				pthis->subCamEyeTarget.x = -80.0f;
				pthis->subCamEyeTarget.y = 260.0f;
				pthis->subCamEyeTarget.z = 430.0f;

				pthis->subCamAtTarget.x = sKoumePtr->actor.world.pos.x;
				pthis->subCamAtTarget.y = sKoumePtr->actor.world.pos.y + 20.0f;
				pthis->subCamAtTarget.z = sKoumePtr->actor.world.pos.z;

				pthis->subCamEyeStep.x = fabsf(pthis->subCamEyeTarget.x - pthis->subCamEye.x);
				pthis->subCamEyeStep.y = fabsf(pthis->subCamEyeTarget.y - pthis->subCamEye.y);
				pthis->subCamEyeStep.z = fabsf(pthis->subCamEyeTarget.z - pthis->subCamEye.z);
				pthis->subCamAtStep.x = fabsf(pthis->subCamAtTarget.x - pthis->subCamAt.x);
				pthis->subCamAtStep.y = fabsf(pthis->subCamAtTarget.y - pthis->subCamAt.y);
				pthis->subCamAtStep.z = fabsf(pthis->subCamAtTarget.z - pthis->subCamAt.z);
				pthis->subCamUpdateRate = 0.0f;
				pthis->subCamDistStep = 0.05f;
				Animation_MorphToPlayOnce(&sKoumePtr->skelAnime, &object_tw_Anim_000AAC, 0.0f);
				pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_000AAC);
				pthis->work[CS_TIMER_1] = 0;
			}
			break;

		case 4:
			updateCam = 1;
			SkelAnime_Update(&sKoumePtr->skelAnime);
			pthis->subCamAtTarget.y = 20.0f + sKoumePtr->actor.world.pos.y;
			Math_ApproachF(&sKoumePtr->actor.world.pos.y, 350, 0.1f, pthis->actor.speedXZ);
			Math_ApproachF(&pthis->actor.speedXZ, 9.0f, 1.0f, 0.9f);
			Math_ApproachF(&pthis->subCamUpdateRate, 1.0f, 1.0f, 0.02f);

			if(pthis->work[CS_TIMER_1] >= 30)
			{
				if(pthis->work[CS_TIMER_1] < 45)
				{
					globalCtx->envCtx.unk_BE = 0;
					globalCtx->envCtx.unk_BD = 2;
					globalCtx->envCtx.unk_D8 = 1.0f;
				}
				else
				{
					Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.1f);
				}

				if(pthis->work[CS_TIMER_1] == 30)
				{
					for(i = 0; i < 50; i++)
					{
						Vec3f pos;
						Vec3f velocity;

						pos.x = sKoumePtr->actor.world.pos.x + Rand_CenteredFloat(50.0f);
						pos.y = sKoumePtr->actor.world.pos.y + Rand_CenteredFloat(50.0f);
						pos.z = sKoumePtr->actor.world.pos.z + Rand_CenteredFloat(50.0f);
						velocity.x = Rand_CenteredFloat(20.0f);
						velocity.y = Rand_CenteredFloat(20.0f);
						velocity.z = Rand_CenteredFloat(20.0f);
						BossTw_AddFlameEffect(globalCtx, &pos, &velocity, &sZeroVector, Rand_ZeroFloat(10.0f) + 25.0f, 1);
					}

					Audio_PlayActorSound2(&sKoumePtr->actor, NA_SE_EN_TWINROBA_TRANSFORM);
					globalCtx->envCtx.unk_D8 = 0;
				}

				if(pthis->work[CS_TIMER_1] >= 35)
				{
					if(pthis->work[CS_TIMER_1] < 50)
					{
						Math_ApproachF(&sKoumePtr->actor.scale.x, ((Math_SinS(pthis->work[CS_TIMER_1] * 0x4200) * 20.0f) / 10000.0f) + 0.024999999f, 1.0f, 0.005f);
					}
					else
					{
						if(pthis->work[CS_TIMER_1] == 50)
						{
							Animation_MorphToPlayOnce(&sKoumePtr->skelAnime, &object_tw_Anim_0088C8, -5);
							pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_0088C8);
						}

						if(pthis->work[CS_TIMER_1] == 60)
						{
							Audio_PlayActorSound2(&sKoumePtr->actor, NA_SE_EN_TWINROBA_LAUGH);
						}

						if(Animation_OnFrame(&sKoumePtr->skelAnime, pthis->workf[ANIM_SW_TGT]))
						{
							Animation_MorphToLoop(&sKoumePtr->skelAnime, &object_tw_Anim_006F28, 0.f);
							pthis->workf[ANIM_SW_TGT] = 1000.0f;
						}

						Math_ApproachF(&sKoumePtr->actor.scale.x, 0.024999999f, 0.1f, 0.005f);
					}

					Actor_SetScale(&sKoumePtr->actor, sKoumePtr->actor.scale.x);
					sKoumePtr->actor.shape.rot.y = -0x8000;
					sKoumePtr->unk_5F8 = 1;

					if(pthis->work[CS_TIMER_1] == 0x64)
					{
						pthis->csState2 = 10;
						pthis->work[CS_TIMER_1] = 0;
						pthis->subCamYawStep = 0.0f;
						sKotakePtr->visible = 1;
						Animation_MorphToLoop(&sKotakePtr->skelAnime, &object_tw_Anim_0004A4, 0.0f);
						sKotakePtr->actor.world.pos.x = 0.0f;
						sKotakePtr->actor.world.pos.y = 80.0f;
						sKotakePtr->actor.world.pos.z = -600.0f;
						sKotakePtr->actor.shape.rot.y = sKotakePtr->actor.world.rot.y = 0;
						pthis->work[CS_TIMER_1] = 0;

						pthis->subCamEye.x = -30.0f;
						pthis->subCamEye.y = 260.0f;
						pthis->subCamEye.z = -470.0f;

						pthis->subCamAt.x = 0;
						pthis->subCamAt.y = 270.0f;
						pthis->subCamAt.z = -600.0f;
						Actor_SetScale(&sKotakePtr->actor, 0.014999999f);
					}
				}
				else
				{
					sKoumePtr->actor.shape.rot.y = sKoumePtr->actor.shape.rot.y + (s16)pthis->subCamYawStep;
				}
			}
			else
			{
				if((pthis->work[CS_TIMER_1] % 8) == 0)
				{
					Audio_PlayActorSound2(&sKoumePtr->actor, NA_SE_EN_TWINROBA_ROLL);
				}

				sKoumePtr->actor.shape.rot.y = sKoumePtr->actor.shape.rot.y + (s16)pthis->subCamYawStep;
				Math_ApproachF(&pthis->subCamYawStep, 12288.0f, 1.0f, 384.0f);

				if(Animation_OnFrame(&sKoumePtr->skelAnime, pthis->workf[ANIM_SW_TGT]))
				{
					Animation_MorphToLoop(&sKoumePtr->skelAnime, &object_tw_Anim_006F28, 0.0f);
					pthis->workf[ANIM_SW_TGT] = 1000.0f;
				}
			}
			break;

		case 10:
			SkelAnime_Update(&sKotakePtr->skelAnime);
			Math_ApproachF(&sKotakePtr->actor.world.pos.y, 240.0f, 0.05f, 5.0f);
			pthis->subCamEye.x -= 0.2f;
			pthis->subCamEye.z -= 0.2f;

			if(pthis->work[CS_TIMER_1] >= 0x33)
			{
				pthis->csState2 = 11;
				pthis->subCamEyeTarget.x = -30;
				pthis->subCamEyeTarget.y = 260;
				pthis->subCamEyeTarget.z = -530;
				pthis->subCamAtTarget.x = 0;
				pthis->subCamAtTarget.y = 265;
				pthis->subCamAtTarget.z = -580;
				pthis->subCamEyeStep.x = fabsf(pthis->subCamEyeTarget.x - pthis->subCamEye.x);
				pthis->subCamEyeStep.y = fabsf(pthis->subCamEyeTarget.y - pthis->subCamEye.y);
				pthis->subCamEyeStep.z = fabsf(pthis->subCamEyeTarget.z - pthis->subCamEye.z);
				pthis->subCamAtStep.x = fabsf(pthis->subCamAtTarget.x - pthis->subCamAt.x);
				pthis->subCamAtStep.y = fabsf(pthis->subCamAtTarget.y - pthis->subCamAt.y);
				pthis->subCamAtStep.z = fabsf(pthis->subCamAtTarget.z - pthis->subCamAt.z);
				pthis->subCamUpdateRate = 0;
				pthis->subCamDistStep = 0.1f;
				pthis->work[CS_TIMER_1] = 0;
			}
			break;

		case 11:
			SkelAnime_Update(&sKotakePtr->skelAnime);
			updateCam = 1;
			Math_ApproachF(&sKotakePtr->actor.world.pos.y, 240.0f, 0.05f, 5.0f);
			Math_ApproachF(&pthis->subCamUpdateRate, 1.0f, 1.0f, 0.02f);

			if(pthis->work[CS_TIMER_1] == 30)
			{
				Message_StartTextbox(globalCtx, 0x604A, NULL);
			}

			if(pthis->work[CS_TIMER_1] > 80)
			{
				pthis->csState2 = 12;
				pthis->actor.speedXZ = 0;

				pthis->subCamEyeTarget.y = 260.0f;
				pthis->subCamEyeTarget.x = -80.0f;
				pthis->subCamEyeTarget.z = -430.0f;

				pthis->subCamAtTarget.x = sKotakePtr->actor.world.pos.x;
				pthis->subCamAtTarget.y = sKotakePtr->actor.world.pos.y + 20.0f;
				pthis->subCamAtTarget.z = sKotakePtr->actor.world.pos.z;

				pthis->subCamEyeStep.x = fabsf(pthis->subCamEyeTarget.x - pthis->subCamEye.x);
				pthis->subCamEyeStep.y = fabsf(pthis->subCamEyeTarget.y - pthis->subCamEye.y);
				pthis->subCamEyeStep.z = fabsf(pthis->subCamEyeTarget.z - pthis->subCamEye.z);
				pthis->subCamAtStep.x = fabsf(pthis->subCamAtTarget.x - pthis->subCamAt.x);
				pthis->subCamAtStep.y = fabsf(pthis->subCamAtTarget.y - pthis->subCamAt.y);
				pthis->subCamAtStep.z = fabsf(pthis->subCamAtTarget.z - pthis->subCamAt.z);
				pthis->subCamUpdateRate = 0;
				pthis->subCamDistStep = 0.05f;
				Animation_MorphToPlayOnce(&sKotakePtr->skelAnime, &object_tw_Anim_000AAC, 0);
				pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_000AAC);
				pthis->work[CS_TIMER_1] = 0;
			}
			break;

		case 12:
			updateCam = 1;
			SkelAnime_Update(&sKotakePtr->skelAnime);
			pthis->subCamAtTarget.y = sKotakePtr->actor.world.pos.y + 20.0f;
			Math_ApproachF(&sKotakePtr->actor.world.pos.y, 350, 0.1f, pthis->actor.speedXZ);
			Math_ApproachF(&pthis->actor.speedXZ, 9.0f, 1.0f, 0.9f);
			Math_ApproachF(&pthis->subCamUpdateRate, 1.0f, 1.0f, 0.02f);

			if(pthis->work[CS_TIMER_1] >= 30)
			{
				if(pthis->work[CS_TIMER_1] < 45)
				{
					globalCtx->envCtx.unk_BD = 3;
					globalCtx->envCtx.unk_D8 = 1.0f;
				}
				else
				{
					Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.1f);
				}

				if(pthis->work[CS_TIMER_1] == 30)
				{
					for(i = 0; i < 50; i++)
					{
						Vec3f pos;
						Vec3f velocity;
						pos.x = sKotakePtr->actor.world.pos.x + Rand_CenteredFloat(50.0f);
						pos.y = sKotakePtr->actor.world.pos.y + Rand_CenteredFloat(50.0f);
						pos.z = sKotakePtr->actor.world.pos.z + Rand_CenteredFloat(50.0f);
						velocity.x = Rand_CenteredFloat(20.0f);
						velocity.y = Rand_CenteredFloat(20.0f);
						velocity.z = Rand_CenteredFloat(20.0f);
						BossTw_AddFlameEffect(globalCtx, &pos, &velocity, &sZeroVector, Rand_ZeroFloat(10.f) + 25.0f, 0);
					}

					Audio_PlayActorSound2(&sKotakePtr->actor, NA_SE_EN_TWINROBA_TRANSFORM);
					globalCtx->envCtx.unk_D8 = 0.0f;
				}

				if(pthis->work[CS_TIMER_1] >= 35)
				{
					if(pthis->work[CS_TIMER_1] < 50)
					{
						Math_ApproachF(&sKotakePtr->actor.scale.x, ((Math_SinS(pthis->work[CS_TIMER_1] * 0x4200) * 20.0f) / 10000.0f) + 0.024999999f, 1.0f, 0.005f);
					}
					else
					{
						if(pthis->work[CS_TIMER_1] == 50)
						{
							Animation_MorphToPlayOnce(&sKotakePtr->skelAnime, &object_tw_Anim_0088C8, -5.0f);
							pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_0088C8);
						}

						if(pthis->work[CS_TIMER_1] == 60)
						{
							Audio_PlayActorSound2(&sKotakePtr->actor, NA_SE_EN_TWINROBA_LAUGH2);
						}

						if(Animation_OnFrame(&sKotakePtr->skelAnime, pthis->workf[ANIM_SW_TGT]))
						{
							Animation_MorphToLoop(&sKotakePtr->skelAnime, &object_tw_Anim_006F28, 0.0f);
							pthis->workf[ANIM_SW_TGT] = 1000.0f;
						}

						Math_ApproachF(&sKotakePtr->actor.scale.x, 0.024999999f, 0.1f, 0.005f);
					}

					Actor_SetScale(&sKotakePtr->actor, sKotakePtr->actor.scale.x);
					sKotakePtr->actor.shape.rot.y = 0;
					sKotakePtr->unk_5F8 = 1;

					if(pthis->work[CS_TIMER_1] == 100)
					{
						pthis->csState2 = 20;
						pthis->work[CS_TIMER_1] = 0;

						pthis->workf[UNK_F11] = 600.0f;

						pthis->subCamEye.x = 800.0f;
						pthis->subCamEye.y = 300.0f;
						pthis->subCamEye.z = 0;

						pthis->subCamAt.x = 0.0f;
						pthis->subCamAt.y = 400.0f;
						pthis->subCamAt.z = 0;

						pthis->workf[UNK_F9] = -M_PI / 2.0f;
						pthis->workf[UNK_F10] = 0.0f;

						pthis->subCamEyeStep.x = 0.0f;
						pthis->spawnPortalAlpha = 0.0f;
					}
				}
				else
				{
					sKotakePtr->actor.shape.rot.y = sKotakePtr->actor.shape.rot.y + (s16)pthis->subCamYawStep;
				}
			}
			else
			{
				if((pthis->work[CS_TIMER_1] % 8) == 0)
				{
					Audio_PlayActorSound2(&sKotakePtr->actor, NA_SE_EN_TWINROBA_ROLL);
				}

				sKotakePtr->actor.shape.rot.y = sKotakePtr->actor.shape.rot.y + (s16)pthis->subCamYawStep;
				Math_ApproachF(&pthis->subCamYawStep, 12288.0f, 1.0f, 384.0f);

				if(Animation_OnFrame(&sKotakePtr->skelAnime, pthis->workf[ANIM_SW_TGT]))
				{
					Animation_MorphToLoop(&sKotakePtr->skelAnime, &object_tw_Anim_006F28, 0.0f);
					pthis->workf[ANIM_SW_TGT] = 1000.0f;
				}
			}
			break;

		case 20:
			if(pthis->work[CS_TIMER_1] > 20 && pthis->work[CS_TIMER_1] < 120)
			{
				globalCtx->envCtx.unk_BD = 1;
				Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.015f);
			}

			if(pthis->work[CS_TIMER_1] == 90)
			{
				Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x5A00FF);
			}

			if(pthis->work[CS_TIMER_1] == 120)
			{
				sEnvType = 0;
				globalCtx->envCtx.unk_BE = 1;
				globalCtx->envCtx.unk_BD = 1;
				globalCtx->envCtx.unk_D8 = 0.0f;
				TitleCard_InitBossName(globalCtx, &globalCtx->actorCtx.titleCtx, SEGMENTED_TO_VIRTUAL(object_tw_Blob_02E170), 0xA0, 0xB4, 0x80, 0x28);
				gSaveContext.eventChkInf[7] |= 0x20;
				Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS);
			}

			if(pthis->work[CS_TIMER_1] >= 160)
			{
				if(pthis->work[CS_TIMER_1] == 160)
				{
					pthis->subCamEyeStep.x = 0.0f;
				}
				Math_ApproachF(&pthis->subCamEye.x, 0.0f, 0.05f, pthis->subCamEyeStep.x * 0.5f);
				Math_ApproachF(&pthis->subCamEye.z, 1000.0f, 0.05f, pthis->subCamEyeStep.x);
				Math_ApproachF(&pthis->subCamEyeStep.x, 40.0f, 1.0f, 1);
			}
			else
			{
				Math_ApproachF(&pthis->subCamEye.x, 300.0f, 0.05f, pthis->subCamEyeStep.x);
				Math_ApproachF(&pthis->subCamEyeStep.x, 5.0f, 1.0f, 0.5f);
			}

			if(pthis->work[CS_TIMER_1] < 200)
			{
				Audio_PlayActorSound2(&sKoumePtr->actor, NA_SE_EN_TWINROBA_FLY - SFX_FLAG);
				Audio_PlayActorSound2(&sKotakePtr->actor, NA_SE_EN_TWINROBA_FLY - SFX_FLAG);
				sp90.x = pthis->workf[UNK_F11];
				sp90.y = 400.0f;
				sp90.z = 0.0f;
				Matrix_RotateY(pthis->workf[UNK_F9], MTXMODE_NEW);
				Matrix_MultVec3f(&sp90, &sp84);
				sKoumePtr->actor.world.pos.x = sp84.x;
				sKoumePtr->actor.world.pos.y = sp84.y;
				sKoumePtr->actor.world.pos.z = sp84.z;
				sKoumePtr->actor.world.rot.y = sKoumePtr->actor.shape.rot.y = (pthis->workf[UNK_F9] / M_PI) * 32768.0f;
				sKotakePtr->actor.world.pos.x = -sp84.x;
				sKotakePtr->actor.world.pos.y = sp84.y;
				sKotakePtr->actor.world.pos.z = -sp84.z;
				sKotakePtr->actor.shape.rot.y = sKotakePtr->actor.world.rot.y = ((pthis->workf[UNK_F9] / M_PI) * 32768.0f) + 32768.0f;
				Math_ApproachF(&pthis->workf[UNK_F11], 80.0f, 0.1f, 5.0f);
				pthis->workf[UNK_F9] -= pthis->workf[UNK_F10];
				Math_ApproachF(&pthis->workf[UNK_F10], 0.19999999f, 1.0f, 0.0019999994f);
			}

			if(pthis->work[CS_TIMER_1] == 200)
			{
				sKoumePtr->actionFunc = BossTw_FlyTo;
				sKotakePtr->actionFunc = BossTw_FlyTo;
				sKoumePtr->targetPos.x = 600.0f;
				sKoumePtr->targetPos.y = 400.0f;
				sKoumePtr->targetPos.z = 0.0f;
				sKoumePtr->timers[0] = 100;
				sKotakePtr->targetPos.x = -600.0f;
				sKotakePtr->targetPos.y = 400.0f;
				sKotakePtr->targetPos.z = 0.0f;
				sKotakePtr->timers[0] = 100;
			}

			if(pthis->work[CS_TIMER_1] == 260)
			{
				Camera* cam = Gameplay_GetCamera(globalCtx, MAIN_CAM);

				cam->eye = pthis->subCamEye;
				cam->eyeNext = pthis->subCamEye;
				cam->at = pthis->subCamAt;
				func_800C08AC(globalCtx, pthis->subCamId, 0);
				pthis->subCamId = 0;
				pthis->csState2 = pthis->subCamId;
				func_80064534(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 7);
				BossTw_SetupWait(pthis, globalCtx);
			}
			break;
	}

	if(pthis->subCamId != 0)
	{
		if(updateCam)
		{
			Math_ApproachF(&pthis->subCamEye.x, pthis->subCamEyeTarget.x, pthis->subCamDistStep, pthis->subCamEyeStep.x * pthis->subCamUpdateRate);
			Math_ApproachF(&pthis->subCamEye.y, pthis->subCamEyeTarget.y, pthis->subCamDistStep, pthis->subCamEyeStep.y * pthis->subCamUpdateRate);
			Math_ApproachF(&pthis->subCamEye.z, pthis->subCamEyeTarget.z, pthis->subCamDistStep, pthis->subCamEyeStep.z * pthis->subCamUpdateRate);
			Math_ApproachF(&pthis->subCamAt.x, pthis->subCamAtTarget.x, pthis->subCamDistStep, pthis->subCamAtStep.x * pthis->subCamUpdateRate);
			Math_ApproachF(&pthis->subCamAt.y, pthis->subCamAtTarget.y, pthis->subCamDistStep, pthis->subCamAtStep.y * pthis->subCamUpdateRate);
			Math_ApproachF(&pthis->subCamAt.z, pthis->subCamAtTarget.z, pthis->subCamDistStep, pthis->subCamAtStep.z * pthis->subCamUpdateRate);
		}

		Gameplay_CameraSetAtEye(globalCtx, pthis->subCamId, &pthis->subCamAt, &pthis->subCamEye);
	}
}

void BossTw_DeathBall(BossTw* pthis, GlobalContext* globalCtx)
{
	f32 xDiff;
	f32 yDiff;
	f32 zDiff;
	s32 pad;
	s16 i;
	s16 yaw;

	if((pthis->work[CS_TIMER_1] % 16) == 0)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_FB_FLY);
	}

	if(sTwinrovaPtr->csState2 < 2)
	{
		if(pthis->timers[0] == 0)
		{
			pthis->timers[0] = 20;
			pthis->targetPos.x = Rand_CenteredFloat(100.0f) + sTwinrovaPtr->actor.world.pos.x;
			pthis->targetPos.y = Rand_CenteredFloat(50.0f) + 400.0f;
			pthis->targetPos.z = Rand_CenteredFloat(100.0f) + sTwinrovaPtr->actor.world.pos.z;
		}

		pthis->timers[1] = 10;
		pthis->rotateSpeed = 8192.0f;
		pthis->actor.speedXZ = 5.0f;
	}
	else
	{
		if(pthis->timers[1] == 9)
		{
			pthis->targetPos.y = 413.0f;
			pthis->actor.world.pos.z = 0.0f;
			pthis->actor.world.pos.x = 0.0f;
			for(i = 0; i < ARRAY_COUNT(pthis->blastTailPos); i++)
			{
				pthis->blastTailPos[i] = pthis->actor.world.pos;
			}
		}

		if(pthis->actor.params == 0x69)
		{
			pthis->targetPos.x = sKoumePtr->actor.world.pos.x;
			pthis->targetPos.z = sKoumePtr->actor.world.pos.z;
		}
		else
		{
			pthis->targetPos.x = sKotakePtr->actor.world.pos.x;
			pthis->targetPos.z = sKotakePtr->actor.world.pos.z;
		}

		Math_ApproachF(&pthis->targetPos.y, 263.0f, 1.0f, 2.0f);

		if(pthis->targetPos.y == 263.0f)
		{
			Math_ApproachF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.2f);
			if(sTwinrovaPtr->csState2 == 3)
			{
				Actor_Kill(&pthis->actor);
			}
		}
	}

	xDiff = pthis->targetPos.x - pthis->actor.world.pos.x;
	yDiff = pthis->targetPos.y - pthis->actor.world.pos.y;
	zDiff = pthis->targetPos.z - pthis->actor.world.pos.z;

	yaw = Math_FAtan2F(xDiff, zDiff) * (32768 / M_PI);
	Math_ApproachS(&pthis->actor.world.rot.x, Math_FAtan2F(yDiff, sqrtf(SQ(xDiff) + SQ(zDiff))) * (32768 / M_PI), 5, pthis->rotateSpeed);
	Math_ApproachS(&pthis->actor.world.rot.y, yaw, 5, pthis->rotateSpeed);
	func_8002D908(&pthis->actor);
	Actor_UpdatePosition(&pthis->actor);
}

void BossTw_TwinrovaSetupDeathCS(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_TwinrovaDeathCS;
	Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_024374, -3.0f);
	pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
	pthis->actor.flags &= ~ACTOR_FLAG_0;
	pthis->csState2 = pthis->csState1 = 0;
	pthis->work[CS_TIMER_1] = pthis->work[CS_TIMER_2] = 0;
	pthis->work[INVINC_TIMER] = 10000;
	BossTw_SetupDeathCS(sKoumePtr, globalCtx);
	BossTw_SetupDeathCS(sKotakePtr, globalCtx);
	sKotakePtr->timers[0] = 8;
	pthis->workf[UNK_F19] = 1.0f;
}

void BossTw_DeathCSMsgSfx(BossTw* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	s32 pad2;
	s32 pad3;
	s16 msgId2;
	s16 msgId1;
	u8 kotakeAnim;
	u8 koumeAnim;
	u8 sp35;

	msgId2 = 0;
	msgId1 = 0;
	kotakeAnim = 0;
	koumeAnim = 0;
	sp35 = 0;

	if(pthis->work[CS_TIMER_2] == 80)
	{
		koumeAnim = 1;
	}

	if(pthis->work[CS_TIMER_2] == 80)
	{
		msgId2 = 0x604B;
		sp35 = 50;
	}

	if(pthis->work[CS_TIMER_2] == 140)
	{
		kotakeAnim = koumeAnim = 2;
	}

	if(pthis->work[CS_TIMER_2] == 170)
	{
		kotakeAnim = 3;
		sKotakePtr->work[YAW_TGT] = -0x4000;
		sKotakePtr->rotateSpeed = 0.0f;
		Audio_PlayActorSound2(&sKotakePtr->actor, NA_SE_EN_TWINROBA_SENSE);
		msgId2 = 0x604C;
	}

	if(pthis->work[CS_TIMER_2] == 210)
	{
		D_8094C874 = 30;
	}

	if(pthis->work[CS_TIMER_2] == 270)
	{
		koumeAnim = 3;
		sKoumePtr->work[YAW_TGT] = 0x4000;
		sKoumePtr->rotateSpeed = 0.0f;
		Audio_PlayActorSound2(&sKoumePtr->actor, NA_SE_EN_TWINROBA_SENSE);
	}

	if(pthis->work[CS_TIMER_2] == 290)
	{
		msgId2 = 0x604D;
		sp35 = 35;
	}

	if(pthis->work[CS_TIMER_2] == 350)
	{
		koumeAnim = kotakeAnim = 2;
		sKoumePtr->work[YAW_TGT] = sKotakePtr->work[YAW_TGT] = 0;
		sKoumePtr->rotateSpeed = sKotakePtr->rotateSpeed = 0.0f;
	}

	if(pthis->work[CS_TIMER_2] == 380)
	{
		koumeAnim = kotakeAnim = 3;
	}

	if(pthis->work[CS_TIMER_2] == 400)
	{
		koumeAnim = kotakeAnim = 2;
	}

	if(pthis->work[CS_TIMER_2] == 430)
	{
		koumeAnim = 4;
		D_8094C874 = 435;
		D_8094C878 = 1;
	}

	if(pthis->work[CS_TIMER_2] > 440 && pthis->work[CS_TIMER_2] < 860)
	{
		Common_PlaySfx(NA_SE_EN_TWINROBA_FIGHT - SFX_FLAG);
	}

	if(pthis->work[CS_TIMER_2] == 430)
	{
		msgId2 = 0x604E;
	}

	if(pthis->work[CS_TIMER_2] == 480)
	{
		kotakeAnim = 4;
		sKotakePtr->work[YAW_TGT] = -0x4000;
	}

	if(pthis->work[CS_TIMER_2] == 500)
	{
		koumeAnim = 2;
	}

	if(pthis->work[CS_TIMER_2] == 480)
	{
		msgId1 = 0x604F;
	}

	if(pthis->work[CS_TIMER_2] == 530)
	{
		koumeAnim = 4;
		sKoumePtr->work[YAW_TGT] = 0x4000;
		D_8094C87A = 335;
		D_8094C87E = 1;
	}

	if(pthis->work[CS_TIMER_2] == 530)
	{
		msgId2 = 0x6050;
	}

	if(pthis->work[CS_TIMER_2] == 580)
	{
		msgId1 = 0x6051;
	}

	if(pthis->work[CS_TIMER_2] == 620)
	{
		msgId2 = 0x6052;
	}

	if(pthis->work[CS_TIMER_2] == 660)
	{
		msgId1 = 0x6053;
	}

	if(pthis->work[CS_TIMER_2] == 700)
	{
		msgId2 = 0x6054;
	}

	if(pthis->work[CS_TIMER_2] == 740)
	{
		msgId1 = 0x6055;
	}

	if(pthis->work[CS_TIMER_2] == 780)
	{
		msgId2 = 0x6056;
	}

	if(pthis->work[CS_TIMER_2] == 820)
	{
		msgId1 = 0x6057;
		Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x5000FF);
	}

	if(pthis->work[CS_TIMER_2] == 860)
	{
		koumeAnim = kotakeAnim = 3;
	}

	if(pthis->work[CS_TIMER_2] == 900)
	{
		Audio_PlayActorSound2(&sKoumePtr->actor, NA_SE_EN_TWINROBA_DIE);
		Audio_PlayActorSound2(&sKotakePtr->actor, NA_SE_EN_TWINROBA_DIE);
	}

	if(pthis->work[CS_TIMER_2] == 930)
	{
		msgId2 = 0x6058;
	}

	if(msgId2 != 0)
	{
		Message_StartTextbox(globalCtx, msgId2, NULL);

		if(sp35)
		{
			D_8094C876 = 10;
			D_8094C874 = sp35;
			D_8094C878 = 0;
		}
	}

	if(msgId1 != 0)
	{
		Message_StartTextbox(globalCtx, msgId1, NULL);
	}

	switch(kotakeAnim)
	{
		case 1:
			Animation_MorphToLoop(&sKotakePtr->skelAnime, &object_tw_Anim_00230C, -5.0f);
			break;
		case 2:
			Animation_MorphToLoop(&sKotakePtr->skelAnime, &object_tw_Anim_001D10, -5.0f);
			break;
		case 3:
			Animation_MorphToLoop(&sKotakePtr->skelAnime, &object_tw_Anim_0017E0, -5.0f);
			break;
		case 4:
			Animation_MorphToLoop(&sKotakePtr->skelAnime, &object_tw_Anim_0012A4, -5.0f);
			break;
	}

	switch(koumeAnim)
	{
		case 1:
			Animation_MorphToLoop(&sKoumePtr->skelAnime, &object_tw_Anim_00230C, -5.0f);
			break;
		case 2:
			Animation_MorphToLoop(&sKoumePtr->skelAnime, &object_tw_Anim_001D10, -5.0f);
			break;
		case 3:
			Animation_MorphToLoop(&sKoumePtr->skelAnime, &object_tw_Anim_0017E0, -5.0f);
			break;
		case 4:
			Animation_MorphToLoop(&sKoumePtr->skelAnime, &object_tw_Anim_0012A4, -5.0f);
			break;
	}

	if(pthis->work[CS_TIMER_2] >= 120 && pthis->work[CS_TIMER_2] < 500)
	{
		Math_ApproachF(&pthis->workf[UNK_F18], 255.0f, 0.1f, 5.0f);
	}

	if(pthis->work[CS_TIMER_2] >= 150)
	{
		Math_ApproachF(&sKoumePtr->workf[UNK_F17], (Math_SinS(pthis->work[CS_TIMER_1] * 2000) * 0.05f) + 0.4f, 0.1f, 0.01f);
		Math_ApproachF(&sKotakePtr->workf[UNK_F17], (Math_CosS(pthis->work[CS_TIMER_1] * 1700) * 0.05f) + 0.4f, 0.1f, 0.01f);

		if(pthis->work[CS_TIMER_2] >= 880)
		{
			Math_ApproachF(&sKotakePtr->actor.world.pos.y, 2000.0f, 1.0f, pthis->actor.speedXZ);
			Math_ApproachF(&sKoumePtr->actor.world.pos.y, 2000.0f, 1.0f, pthis->actor.speedXZ);
			Math_ApproachF(&pthis->actor.speedXZ, 10.0f, 1.0f, 0.25f);

			if(pthis->work[CS_TIMER_2] >= 930)
			{
				Math_ApproachF(&pthis->workf[UNK_F19], 5.0f, 1.0f, 0.05f);
				Math_ApproachF(&pthis->workf[UNK_F18], 0.0f, 1.0f, 3.0f);
			}

			Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GOTO_HEAVEN - SFX_FLAG);
		}
		else
		{
			f32 yTarget = Math_CosS(pthis->work[CS_TIMER_2] * 1700) * 4.0f;
			Math_ApproachF(&sKotakePtr->actor.world.pos.y, 20.0f + (263.0f + yTarget), 0.1f, pthis->actor.speedXZ);
			yTarget = Math_SinS(pthis->work[CS_TIMER_2] * 1500) * 4.0f;
			Math_ApproachF(&sKoumePtr->actor.world.pos.y, 20.0f + (263.0f + yTarget), 0.1f, pthis->actor.speedXZ);
			Math_ApproachF(&pthis->actor.speedXZ, 1.0f, 1.0f, 0.05f);
		}
	}
}

void BossTw_TwinrovaDeathCS(BossTw* pthis, GlobalContext* globalCtx)
{
	s16 i;
	Vec3f spD0;
	Player* player = GET_PLAYER(globalCtx);
	Camera* mainCam = Gameplay_GetCamera(globalCtx, MAIN_CAM);

	SkelAnime_Update(&pthis->skelAnime);
	pthis->work[UNK_S8] += 20;

	if(pthis->work[UNK_S8] > 255)
	{
		pthis->work[UNK_S8] = 255;
	}

	Math_ApproachF(&pthis->workf[UNK_F12], 0.0f, 1.0f, 0.05f);
	pthis->unk_5F8 = 1;

	switch(pthis->csState1)
	{
		case 0:
			if(pthis->work[CS_TIMER_1] == 15)
			{
				Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_0216DC, -3.0f);
			}

			if(pthis->work[CS_TIMER_1] >= 15)
			{
				Math_ApproachF(&pthis->actor.world.pos.y, 400.0f, 0.05f, 10.0f);
			}

			if(pthis->work[CS_TIMER_1] >= 55)
			{
				if(pthis->work[CS_TIMER_1] == 55)
				{
					globalCtx->envCtx.unk_D8 = 0;
				}

				sEnvType = -1;
				globalCtx->envCtx.unk_BE = 5;
				globalCtx->envCtx.unk_BD = 0;
				Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.015f);
				Math_ApproachF(&pthis->actor.scale.x, 0.00024999998f, 0.1f, 0.00005f);
				pthis->actor.shape.rot.y += (s16)pthis->actor.speedXZ;
				pthis->workf[UNK_F13] += pthis->actor.speedXZ;
				if(pthis->workf[UNK_F13] > 65536.0f)
				{
					pthis->workf[UNK_F13] -= 65536.0f;
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_ROLL);
				}
				Math_ApproachF(&pthis->actor.speedXZ, 12288.0f, 1.0f, 256.0f);
				if(pthis->work[CS_TIMER_1] == 135)
				{
					Vec3f spBC;
					Vec3f spB0;
					Vec3f spA4 = {0.0f, 0.0f, 0.0f};
					Common_PlaySfx(NA_SE_EN_TWINROBA_TRANSFORM);
					for(i = 0; i < 100; i++)
					{
						spB0.x = Rand_CenteredFloat(5.0f);
						spB0.y = Rand_CenteredFloat(5.0f);
						spB0.z = Rand_CenteredFloat(5.0f);
						spBC = pthis->actor.world.pos;
						spBC.x += spB0.x;
						spBC.y += spB0.y;
						spBC.z += spB0.z;
						BossTw_AddFlameEffect(globalCtx, &spBC, &spB0, &spA4, Rand_ZeroFloat(2.0f) + 5, Rand_ZeroFloat(1.99f));
					}
					pthis->csState1 = 1;
					pthis->visible = false;
					pthis->actor.scale.x = 0.0f;
					Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_TW, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, TW_DEATHBALL_KOUME);
					Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_TW, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, TW_DEATHBALL_KOTAKE);
					pthis->actor.flags &= ~ACTOR_FLAG_0;
				}
			}
			Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
			break;
		case 1:
			break;
	}

	switch(pthis->csState2)
	{
		case 0:
			pthis->csState2 = 1;
			func_80064520(globalCtx, &globalCtx->csCtx);
			func_8002DF54(globalCtx, &pthis->actor, 8);
			pthis->subCamId = Gameplay_CreateSubCamera(globalCtx);
			Gameplay_ChangeCameraStatus(globalCtx, 0, CAM_STAT_WAIT);
			Gameplay_ChangeCameraStatus(globalCtx, pthis->subCamId, CAM_STAT_ACTIVE);
			pthis->subCamEye = mainCam->eye;
			pthis->subCamAt = mainCam->at;
			Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x100FF);
			break;
		case 1:
			spD0.x = Math_SinS(pthis->actor.world.rot.y) * 200.0f;
			spD0.z = Math_CosS(pthis->actor.world.rot.y) * 200.0f;
			Math_ApproachF(&pthis->subCamEye.x, spD0.x + pthis->actor.world.pos.x, 0.1f, 50.0f);
			Math_ApproachF(&pthis->subCamEye.y, 300.0f, 0.1f, 50.0f);
			Math_ApproachF(&pthis->subCamEye.z, spD0.z + pthis->actor.world.pos.z, 0.1f, 50.0f);
			Math_ApproachF(&pthis->subCamAt.x, pthis->actor.world.pos.x, 0.1f, 50.0f);
			Math_ApproachF(&pthis->subCamAt.y, pthis->actor.world.pos.y, 0.1f, 50.0f);
			Math_ApproachF(&pthis->subCamAt.z, pthis->actor.world.pos.z, 0.1f, 50.0f);
			if(pthis->work[CS_TIMER_1] == 170)
			{
				pthis->csState2 = 2;
				pthis->work[CS_TIMER_2] = 0;
				pthis->subCamEye.z = 170.0f;
				pthis->subCamDist = 170.0f;
				pthis->subCamEye.x = 0.0f;
				pthis->subCamAt.x = 0.0f;
				pthis->subCamAt.z = 0.0f;
				pthis->subCamEye.y = 260.0f;
				player->actor.shape.rot.y = -0x8000;
				player->actor.world.pos.x = -40.0f;
				player->actor.world.pos.y = 240.0f;
				player->actor.world.pos.z = 90.0f;
				sKoumePtr->actor.world.pos.x = -37.0f;
				sKotakePtr->actor.world.pos.x = 37.0f;
				sKotakePtr->actor.world.pos.y = 263.0f;
				sKoumePtr->actor.world.pos.y = sKotakePtr->actor.world.pos.y;
				pthis->subCamAt.y = sKoumePtr->actor.world.pos.y + 17.0f;
				sKotakePtr->actor.world.pos.z = 0.0f;
				sKoumePtr->actor.world.pos.z = sKotakePtr->actor.world.pos.z;
				sKoumePtr->work[YAW_TGT] = sKotakePtr->work[YAW_TGT] = sKoumePtr->actor.shape.rot.x = sKotakePtr->actor.shape.rot.x = sKoumePtr->actor.shape.rot.y = sKotakePtr->actor.shape.rot.y = 0;
				func_8002DF54(globalCtx, &sKoumePtr->actor, 1);
				sKoumePtr->actor.flags |= ACTOR_FLAG_0;
			}
			break;
		case 2:
			if(pthis->work[CS_TIMER_2] == 100)
			{
				Vec3f pos;
				Vec3f velocity;
				Vec3f accel = {0.0f, 0.0f, 0.0f};
				s32 zero = 0;

				for(i = 0; i < 50; i++)
				{
					velocity.x = Rand_CenteredFloat(3.0f);
					velocity.y = Rand_CenteredFloat(3.0f);
					velocity.z = Rand_CenteredFloat(3.0f);
					pos = sKoumePtr->actor.world.pos;
					pos.x += velocity.x * 2.0f;
					pos.y += velocity.y * 2.0f;
					pos.z += velocity.z * 2.0f;
					BossTw_AddFlameEffect(globalCtx, &pos, &velocity, &accel, Rand_ZeroFloat(2.0f) + 5, 1);

					// fake code needed to match, tricks the compiler into allocating more stack
					if(1)
					{
					}
					if(zero)
					{
						accel.x *= 2.0;
					}

					velocity.x = Rand_CenteredFloat(3.0f);
					velocity.y = Rand_CenteredFloat(3.0f);
					velocity.z = Rand_CenteredFloat(3.0f);
					pos = sKotakePtr->actor.world.pos;
					pos.x += velocity.x * 2.0f;
					pos.y += velocity.y * 2.0f;
					pos.z += velocity.z * 2.0f;
					BossTw_AddFlameEffect(globalCtx, &pos, &velocity, &accel, Rand_ZeroFloat(2.0f) + 5, 0);
				}

				Actor_SetScale(&sKoumePtr->actor, 0.0f);
				Actor_SetScale(&sKotakePtr->actor, 0.0f);
				sKoumePtr->visible = 1;
				sKotakePtr->visible = 1;
				Common_PlaySfx(NA_SE_EN_TWINROBA_TRANSFORM);
				Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_KOTAKE_KOUME);
				pthis->csState2 = 3;
				pthis->work[CS_TIMER_2] = 0;
				pthis->subCamYaw = pthis->subCamYawStep = pthis->actor.speedXZ = pthis->subCamDistStep = 0.0f;
			}
			break;
		case 3:
			BossTw_DeathCSMsgSfx(pthis, globalCtx);
			if(pthis->work[CS_TIMER_2] < 150)
			{
				globalCtx->envCtx.unk_BE = 1;
				globalCtx->envCtx.unk_BD = 0;
				Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.1f);
			}
			else
			{
				globalCtx->envCtx.unk_BE = 1;
				globalCtx->envCtx.unk_BD = 6;
				Math_ApproachF(&globalCtx->envCtx.unk_D8, (Math_SinS(pthis->work[CS_TIMER_2] * 4096) / 4.0f) + 0.75f, 1.0f, 0.1f);
			}

			Math_ApproachF(&pthis->subCamAt.y, sKoumePtr->actor.world.pos.y + 17.0f, 0.05f, 10.0f);

			if(pthis->work[CS_TIMER_2] >= 50)
			{
				Math_ApproachF(&pthis->subCamDist, 110.0f, 0.05f, pthis->subCamDistStep);
				Math_ApproachF(&pthis->subCamDistStep, 1.0f, 1.0f, 0.025f);
				pthis->subCamEye.x = pthis->subCamDist * sinf(pthis->subCamYaw);
				pthis->subCamEye.z = pthis->subCamDist * cosf(pthis->subCamYaw);
				if(pthis->work[CS_TIMER_2] >= 151)
				{
					pthis->subCamYaw += pthis->subCamYawStep;
					if(pthis->work[CS_TIMER_2] >= 800)
					{
						Math_ApproachF(&pthis->subCamYawStep, 0.0f, 1.0f, 0.0001f);
					}
					else
					{
						Math_ApproachF(&pthis->subCamYawStep, 0.015f, 1.0f, 0.0001f);
					}
				}
			}
			Math_ApproachF(&sKoumePtr->actor.scale.x, 0.009999999f, 0.1f, 0.001f);
			Actor_SetScale(&sKoumePtr->actor, sKoumePtr->actor.scale.x);
			Actor_SetScale(&sKotakePtr->actor, sKoumePtr->actor.scale.x);
			if(pthis->work[CS_TIMER_2] >= 1020)
			{
				mainCam = Gameplay_GetCamera(globalCtx, MAIN_CAM);
				mainCam->eye = pthis->subCamEye;
				mainCam->eyeNext = pthis->subCamEye;
				mainCam->at = pthis->subCamAt;
				func_800C08AC(globalCtx, pthis->subCamId, 0);
				pthis->csState2 = 4;
				pthis->subCamId = 0;
				func_80064534(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 7);
				Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS_CLEAR);
				Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, 600.0f, 230.0f, 0.0f, 0, 0, 0, WARP_DUNGEON_ADULT);
				Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, -600.0f, 230.f, 0.0f, 0, 0, 0, 0);
				pthis->actor.world.pos.y = -2000.0f;
				pthis->workf[UNK_F18] = 0.0f;
				sKoumePtr->visible = sKotakePtr->visible = false;
				if(&pthis->subCamEye)
				{
				} // fixes regalloc, may be fake
				Flags_SetClear(globalCtx, globalCtx->roomCtx.curRoom.num);
			}
			break;
		case 4:
			sEnvType = 0;
			break;
	}

	if(pthis->subCamId)
	{
		if(1)
		{
		}
		Gameplay_CameraSetAtEye(globalCtx, pthis->subCamId, &pthis->subCamAt, &pthis->subCamEye);
	}
}

void BossTw_Update(Actor* thisx, GlobalContext* globalCtx)
{
	BossTw* pthis = (BossTw*)thisx;
	Player* player = GET_PLAYER(globalCtx);
	s16 i;
	s32 pad;

	pthis->collider.base.colType = COLTYPE_HIT3;
	Math_ApproachF(&pthis->fogR, globalCtx->lightCtx.fogColor[0], 1.0f, 10.0f);
	Math_ApproachF(&pthis->fogG, globalCtx->lightCtx.fogColor[1], 1.0f, 10.0f);
	Math_ApproachF(&pthis->fogB, globalCtx->lightCtx.fogColor[2], 1.0f, 10.0f);
	Math_ApproachF(&pthis->fogNear, globalCtx->lightCtx.fogNear, 1.0f, 10.0f);
	Math_ApproachF(&pthis->fogFar, 1000.0f, 1.0f, 10.0f);
	pthis->work[CS_TIMER_1]++;
	pthis->work[CS_TIMER_2]++;
	pthis->work[TAIL_IDX]++;

	if(pthis->work[TAIL_IDX] >= ARRAY_COUNT(pthis->blastTailPos))
	{
		pthis->work[TAIL_IDX] = 0;
	}

	pthis->blastTailPos[pthis->work[TAIL_IDX]] = pthis->actor.world.pos;

	if(1)
	{
	}
	if(1)
	{
	}

	for(i = 0; i < 5; i++)
	{
		if(pthis->timers[i] != 0)
		{
			pthis->timers[i]--;
		}
	}

	if(pthis->work[INVINC_TIMER] != 0)
	{
		pthis->work[INVINC_TIMER]--;
	}

	if(pthis->work[FOG_TIMER] != 0)
	{
		pthis->work[FOG_TIMER]--;
	}

	if(pthis->actionFunc == BossTw_FlyTo || pthis->actionFunc == BossTw_Spin || pthis->actionFunc == BossTw_TurnToPlayer)
	{
		if((s16)(player->actor.shape.rot.y - pthis->actor.yawTowardsPlayer + 0x8000) < 0x1000 && (s16)(player->actor.shape.rot.y - pthis->actor.yawTowardsPlayer + 0x8000) > -0x1000 && player->unk_A73)
		{
			BossTw_SetupSpin(pthis, globalCtx);
		}
	}

	pthis->actionFunc(pthis, globalCtx);

	if(pthis->actionFunc != BossTw_Wait)
	{
		pthis->collider.dim.radius = 45;

		if(pthis->actionFunc == BossTw_Spin)
		{
			pthis->collider.dim.radius *= 2;
		}

		pthis->collider.dim.height = 120;
		pthis->collider.dim.yShift = -30;

		if(pthis->work[INVINC_TIMER] == 0)
		{
			if(pthis->collider.base.acFlags & AC_HIT)
			{
				pthis->collider.base.acFlags &= ~AC_HIT;
			}

			Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
			CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
		}

		if(pthis->actor.params == 0)
		{
			pthis->workf[OUTR_CRWN_TX_X2] += 1.0f;
			pthis->workf[OUTR_CRWN_TX_Y2] -= 7.0f;
			pthis->workf[INNR_CRWN_TX_Y1] += 1.0f;
		}
		else
		{
			pthis->workf[OUTR_CRWN_TX_X2] += 0.0f;
			pthis->workf[INNR_CRWN_TX_X2] += 0.0f;
			pthis->workf[OUTR_CRWN_TX_Y2] += -15.0f;
			pthis->workf[INNR_CRWN_TX_Y2] += -10.0f;
		}

		if(((pthis->work[CS_TIMER_2] % 32) == 0) && (Rand_ZeroOne() < 0.3f))
		{
			pthis->work[BLINK_IDX] = 4;
		}

		pthis->eyeTexIdx = D_8094A900_143[pthis->work[BLINK_IDX]];

		if(pthis->work[BLINK_IDX] != 0)
		{
			pthis->work[BLINK_IDX]--;
		}

		if(pthis->actionFunc != BossTw_MergeCS && pthis->unk_5F8 != 0)
		{
			Vec3f pos;
			Vec3f velocity = {0.0f, 0.0f, 0.0f};
			Vec3f accel = {0.0f, 0.0f, 0.0f};

			if(pthis->scepterAlpha > 0.0f)
			{
				for(i = 0; i <= 0; i++)
				{
					pos = pthis->scepterFlamePos[0];
					pos.x += Rand_CenteredFloat(70.0f);
					pos.y += Rand_CenteredFloat(70.0f);
					pos.z += Rand_CenteredFloat(70.0f);
					accel.y = 0.4f;
					accel.x = Rand_CenteredFloat(0.5f);
					accel.z = Rand_CenteredFloat(0.5f);
					BossTw_AddDotEffect(globalCtx, &pos, &velocity, &accel, (s16)Rand_ZeroFloat(2.0f) + 8, pthis->actor.params, 37);
				}
			}

			for(i = 0; i <= 0; i++)
			{
				pos = pthis->crownPos;
				pos.x += Rand_CenteredFloat(70.0f);
				pos.y += Rand_CenteredFloat(70.0f);
				pos.z += Rand_CenteredFloat(70.0f);
				accel.y = 0.4f;
				accel.x = Rand_CenteredFloat(0.5f);
				accel.z = Rand_CenteredFloat(0.5f);
				BossTw_AddDotEffect(globalCtx, &pos, &velocity, &accel, (s16)Rand_ZeroFloat(2.0f) + 8, pthis->actor.params, 37);
			}
		}
	}
}

void BossTw_TwinrovaUpdate(Actor* thisx, GlobalContext* globalCtx2)
{
	s16 i;
	GlobalContext* globalCtx = globalCtx2;
	BossTw* pthis = (BossTw*)thisx;
	Player* player = GET_PLAYER(globalCtx);

	pthis->actor.flags &= ~ACTOR_FLAG_10;
	pthis->unk_5F8 = 0;
	pthis->collider.base.colType = COLTYPE_HIT3;

	Math_ApproachF(&pthis->fogR, globalCtx->lightCtx.fogColor[0], 1.0f, 10.0f);
	Math_ApproachF(&pthis->fogG, globalCtx->lightCtx.fogColor[1], 1.0f, 10.0f);
	Math_ApproachF(&pthis->fogB, globalCtx->lightCtx.fogColor[2], 1.0f, 10.0f);
	Math_ApproachF(&pthis->fogNear, globalCtx->lightCtx.fogNear, 1.0f, 10.0f);
	Math_ApproachF(&pthis->fogFar, 1000.0f, 1.0f, 10.0f);

	pthis->work[CS_TIMER_1]++;
	pthis->work[CS_TIMER_2]++;

	for(i = 0; i < 5; i++)
	{
		if(pthis->timers[i] != 0)
		{
			pthis->timers[i]--;
		}
	}

	if(pthis->work[INVINC_TIMER] != 0)
	{
		pthis->work[INVINC_TIMER]--;
	}

	if(pthis->work[FOG_TIMER] != 0)
	{
		pthis->work[FOG_TIMER]--;
	}

	pthis->actionFunc(pthis, globalCtx);

	if(pthis->actionFunc != BossTw_TwinrovaShootBlast && pthis->actionFunc != BossTw_TwinrovaChargeBlast && pthis->visible && pthis->unk_5F8 == 0 && (s16)(player->actor.shape.rot.y - pthis->actor.yawTowardsPlayer + 0x8000) < 0x1000 &&
	   (s16)(player->actor.shape.rot.y - pthis->actor.yawTowardsPlayer + 0x8000) > -0x1000 && player->unk_A73 != 0)
	{
		BossTw_TwinrovaSetupSpin(pthis, globalCtx);
	}

	pthis->eyeTexIdx = D_8094A900_143[pthis->work[BLINK_IDX]];
	if(pthis->work[BLINK_IDX] != 0)
	{
		pthis->work[BLINK_IDX]--;
	}

	if((pthis->work[CS_TIMER_2] % 32) == 0)
	{
		if(pthis->actionFunc != BossTw_TwinrovaMergeCS)
		{
			if(Rand_ZeroOne() < 0.3f)
			{
				pthis->work[BLINK_IDX] = 4;
			}
		}
	}

	if(pthis->actionFunc == BossTw_TwinrovaMergeCS)
	{
		pthis->leftEyeTexIdx = D_8094A90C_143[pthis->work[TW_BLINK_IDX]];
		if(pthis->work[TW_BLINK_IDX] != 0)
		{
			pthis->work[TW_BLINK_IDX]--;
		}
	}
	else
	{
		if(pthis->actionFunc == BossTw_TwinrovaStun)
		{
			pthis->eyeTexIdx = 1;
		}

		if(pthis->actionFunc == BossTw_TwinrovaDeathCS)
		{
			pthis->eyeTexIdx = 2;
		}

		pthis->leftEyeTexIdx = pthis->eyeTexIdx;
	}

	if(pthis->visible && pthis->unk_5F8 == 0)
	{
		Vec3f pos;
		Vec3f velocity = {0.0f, 0.0f, 0.0f};
		Vec3f accel;

		if(pthis->work[UNK_S8] != 0)
		{
			pthis->work[UNK_S8] -= 20;
			if(pthis->work[UNK_S8] < 0)
			{
				pthis->work[UNK_S8] = 0;
			}
		}

		Math_ApproachF(&pthis->workf[UNK_F12], 1.0f, 1.0f, 0.05f);
		accel.y = 0.4f;

		for(i = 0; i < 2; i++)
		{
			pos = pthis->leftScepterPos;
			pos.x += Rand_CenteredFloat(30.0f);
			pos.y += Rand_CenteredFloat(30.0f);
			pos.z += Rand_CenteredFloat(30.0f);
			accel.x = Rand_CenteredFloat(0.5f);
			accel.z = Rand_CenteredFloat(0.5f);
			BossTw_AddDotEffect(globalCtx, &pos, &velocity, &accel, (s16)Rand_ZeroFloat(2.0f) + 7, 0, 75);
		}

		for(i = 0; i < 2; i++)
		{
			pos = pthis->rightScepterPos;
			pos.x += Rand_CenteredFloat(30.0f);
			pos.y += Rand_CenteredFloat(30.0f);
			pos.z += Rand_CenteredFloat(30.0f);
			accel.x = Rand_CenteredFloat(0.5f);
			accel.z = Rand_CenteredFloat(0.5f);
			BossTw_AddDotEffect(globalCtx, &pos, &velocity, &accel, (s16)Rand_ZeroFloat(2.0f) + 7, 1, 75);
		}
	}

	pthis->collider.dim.radius = 35;

	if(pthis->actionFunc == BossTw_TwinrovaSpin)
	{
		pthis->collider.dim.radius *= 2;
	}

	pthis->collider.dim.height = 150;
	pthis->collider.dim.yShift = -60;
	Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

	if(pthis->work[INVINC_TIMER] == 0)
	{
		if(pthis->actionFunc != BossTw_TwinrovaStun)
		{
			if(pthis->twinrovaStun != 0)
			{
				pthis->twinrovaStun = 0;
				pthis->work[FOG_TIMER] = 10;
				BossTw_TwinrovaDamage(pthis, globalCtx, 0);
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_YOUNG_DAMAGE);
			}
			else if(pthis->collider.base.acFlags & AC_HIT)
			{
				ColliderInfo* info = pthis->collider.info.acHitInfo;

				pthis->collider.base.acFlags &= ~AC_HIT;
				if(info->toucher.dmgFlags & (DMG_SLINGSHOT | DMG_ARROW))
				{
				}
			}
		}
		else if(pthis->collider.base.acFlags & AC_HIT)
		{
			u8 damage;
			u8 swordDamage;
			ColliderInfo* info = pthis->collider.info.acHitInfo;

			pthis->collider.base.acFlags &= ~AC_HIT;
			swordDamage = false;
			damage = CollisionCheck_GetSwordDamage(info->toucher.dmgFlags);

			if(damage == 0)
			{
				damage = 2;
			}
			else
			{
				swordDamage = true;
			}

			if(!(info->toucher.dmgFlags & DMG_HOOKSHOT))
			{
				if(((s8)pthis->actor.colChkInfo.health < 3) && !swordDamage)
				{
					damage = 0;
				}

				BossTw_TwinrovaDamage(pthis, globalCtx, damage);
			}
		}
	}

	CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
	osSyncPrintf("OooooooooooooooooooooooooooooooooCC\n");
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

	globalCtx->envCtx.unk_DC = 2;

	switch(sEnvType)
	{
		case 0:
			Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.02f);
			break;
		case 1:
			globalCtx->envCtx.unk_BD = 3;
			Math_ApproachF(&globalCtx->envCtx.unk_D8, 0.5f, 1.0f, 0.05f);
			break;
		case 2:
			globalCtx->envCtx.unk_BD = 2;
			Math_ApproachF(&globalCtx->envCtx.unk_D8, (Math_SinS(pthis->work[CS_TIMER_1] * 0x3000) * 0.03f) + 0.5f, 1.0f, 0.05f);
			break;
		case 3:
			globalCtx->envCtx.unk_BD = 3;
			Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.1f);
			break;
		case 4:
			globalCtx->envCtx.unk_BD = 2;
			Math_ApproachF(&globalCtx->envCtx.unk_D8, (Math_SinS(pthis->work[CS_TIMER_1] * 0x3E00) * 0.05f) + 0.95f, 1.0f, 0.1f);
			break;
		case 5:
			globalCtx->envCtx.unk_BD = 0;
			Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
			break;
		case -1:
			break;
	}

	BossTw_UpdateEffects(globalCtx);

	if(sFreezeState == 1)
	{
		sFreezeState = 2;
		BossTw_AddPlayerFreezeEffect(globalCtx, NULL);
		Common_PlaySfxAtPos(&player->actor.projectedPos, NA_SE_VO_LI_FREEZE);
		Common_PlaySfxAtPos(&player->actor.projectedPos, NA_SE_PL_FREEZE);

		if(sShieldFireCharge != 0)
		{
			sShieldFireCharge = 4;
		}
	}

	if(player->isBurning && sShieldIceCharge != 0)
	{
		sShieldIceCharge = 4;
	}
}

s32 BossTw_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	BossTw* pthis = (BossTw*)thisx;

	if(limbIndex == 21)
	{
		if(pthis->unk_5F8 == 0)
		{
			if(pthis->actor.params == 0)
			{
				*dList = object_tw_DL_012CE0;
			}
			else
			{
				*dList = object_tw_DL_0134B8;
			}
		}
	}

	if(limbIndex == 14)
	{
		if(pthis->actionFunc == BossTw_DeathCS)
		{
			*dList = NULL;
		}
		else if(pthis->scepterAlpha == 0.0f)
		{
			if(pthis->actor.params == 0)
			{
				*dList = object_tw_DL_012B38;
			}
			else
			{
				*dList = object_tw_DL_013310;
			}
		}
	}

	return false;
}

void BossTw_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	BossTw* pthis = (BossTw*)thisx;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6168);

	switch(limbIndex)
	{
		case 21:
			Matrix_MultVec3f(&D_8094A944_143, &pthis->actor.focus.pos);
			Matrix_MultVec3f(&D_8094A950_143, &pthis->crownPos);

			if(pthis->unk_5F8 != 0)
			{
				gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6190), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
				if(pthis->actor.params == 0)
				{
					gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_013AE8));
				}
				else
				{
					gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_013D68));
				}
			}
			break;
		case 14:
			Matrix_MultVec3f(&D_8094A95C_143[0], &pthis->scepterFlamePos[0]);
			Matrix_MultVec3f(&D_8094A95C_143[1], &pthis->scepterFlamePos[1]);
			Matrix_MultVec3f(&D_8094A95C_143[2], &pthis->scepterFlamePos[2]);
			Matrix_MultVec3f(&D_8094A95C_143[3], &pthis->scepterFlamePos[3]);
			Matrix_MultVec3f(&D_8094A95C_143[4], &pthis->scepterFlamePos[4]);

			if(pthis->scepterAlpha > 0.0f)
			{
				gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6221), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
				if(pthis->actor.params == 0)
				{
					gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 225, 255, (s16)pthis->scepterAlpha);
					gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_013E98));
					gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, (s16)pthis->scepterAlpha);
					gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_013F98));
				}
				else
				{
					gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 100, 20, 0, (s16)pthis->scepterAlpha);
					gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_014070));
					gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 70, 0, (s16)pthis->scepterAlpha);
					gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_014158));
				}
			}
			break;
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6236);
}

void func_80941BC0(BossTw* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6341);

	Matrix_Push();
	func_80093D84(globalCtx->state.gfxCtx);
	Matrix_Translate(pthis->groundBlastPos2.x, pthis->groundBlastPos2.y, pthis->groundBlastPos2.z, MTXMODE_NEW);
	Matrix_Scale(pthis->workf[UNK_F12], pthis->workf[UNK_F12], pthis->workf[UNK_F12], MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6358), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s16)pthis->workf[UNK_F11]);
	gDPSetEnvColor(POLY_XLU_DISP++, 0, 40, 30, 80);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01BC00));
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 215, 215, 215, (s16)pthis->workf[UNK_F11] * pthis->workf[UNK_F14]);
	gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 128);
	gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, (u32)pthis->workf[UNK_F16] & 0x3F, (pthis->work[CS_TIMER_2] * 4) & 0x3F, 0x10, 0x10));
	Matrix_Push();
	Matrix_RotateY(pthis->workf[UNK_F15], MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6423), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01C1C0));
	Matrix_Pop();
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6427), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPSegment(POLY_XLU_DISP++, 0xD, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, pthis->work[CS_TIMER_2] & 0x7F, (pthis->work[CS_TIMER_2] * 8) & 0xFF, 0x20, 0x40, 1, (-pthis->work[CS_TIMER_2] * 2) & 0x3F, 0, 0x10, 0x10));
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, (s16)pthis->workf[UNK_F9]);
	gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 128);
	gDPSetRenderMode(POLY_XLU_DISP++, Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_DEC | FORCE_BL | GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA), G_RM_ZB_OVL_SURF2);
	gSPSetGeometryMode(POLY_XLU_DISP++, G_CULL_BACK | G_FOG);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A790));
	Matrix_Pop();

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6461);
}

void func_80942180(BossTw* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6468);

	Matrix_Push();

	func_80093D84(globalCtx->state.gfxCtx);
	Matrix_Translate(pthis->groundBlastPos2.x, pthis->groundBlastPos2.y, pthis->groundBlastPos2.z, MTXMODE_NEW);
	Matrix_Scale(pthis->workf[KM_GD_CRTR_SCL], pthis->workf[KM_GD_CRTR_SCL], pthis->workf[KM_GD_CRTR_SCL], MTXMODE_APPLY);
	gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (-pthis->work[CS_TIMER_1]) & 0x7F, 0, 0x20, 0x20, 1, (pthis->work[CS_TIMER_1] * 2) & 0x7F, 0, 0x20, 0x20));
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6497), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 100, 40, 00, (s16)pthis->workf[KM_GRND_CRTR_A]);
	gDPPipeSync(POLY_XLU_DISP++);
	gDPSetEnvColor(POLY_XLU_DISP++, 255, 245, 255, 128);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_019D40));

	func_800D1FD4(&globalCtx->billboardMtxF);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6514), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPSegment(
	    POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, pthis->work[CS_TIMER_1] & 0x7F, (-pthis->work[CS_TIMER_1] * 6) & 0xFF, 0x20, 0x40, 1, (pthis->work[CS_TIMER_1] * 2) & 0x7F, (-pthis->work[CS_TIMER_1] * 6) & 0xFF, 0x20, 0x40));
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 80, 0, 0, (s16)pthis->workf[KM_GD_SMOKE_A]);
	gDPPipeSync(POLY_XLU_DISP++);
	gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, 100);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_018FC0));

	gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (-pthis->work[CS_TIMER_1] * 3) & 0x7F, 0, 0x20, 0x20, 1, 0, (-pthis->work[CS_TIMER_1] * 10) & 0xFF, 0x20, 0x40));
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 100, 50, 0, (s16)(pthis->workf[KM_GD_FLM_A] * 0.7f));
	gDPPipeSync(POLY_XLU_DISP++);
	gDPSetEnvColor(POLY_XLU_DISP++, 200, 235, 240, 128);
	Matrix_Scale(pthis->workf[KM_GD_FLM_SCL], pthis->workf[KM_GD_FLM_SCL], pthis->workf[KM_GD_FLM_SCL], MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6575), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_019938));

	Matrix_Pop();

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6579);
}

void func_809426F0(BossTw* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	s16 i;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6587);

	gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, (u8)(-pthis->work[CS_TIMER_2] * 15), 0x20, 0x40, 1, 0, 0, 0x40, 0x40));
	Matrix_Push();
	Matrix_Translate(0.0f, 0.0f, 5000.0f, MTXMODE_APPLY);
	Matrix_Scale(pthis->spawnPortalScale / 2000.0f, pthis->spawnPortalScale / 2000.0f, pthis->spawnPortalScale / 2000.0f, MTXMODE_APPLY);
	Matrix_RotateZ(pthis->portalRotation, MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6614), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);

	if(pthis->actor.params == 0)
	{
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 135, 175, 165, (s16)pthis->spawnPortalAlpha);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01CEE0));
	}
	else
	{
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 0, (s16)pthis->spawnPortalAlpha);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01DBE8));
	}

	Matrix_Pop();

	if(pthis->actor.params == 0)
	{
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, (s16)pthis->flameAlpha);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A998));
	}
	else
	{
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 200, 20, 0, (s16)pthis->flameAlpha);
		gDPSetEnvColor(POLY_XLU_DISP++, 255, 215, 255, 128);
	}

	for(i = 0; i < 8; i++)
	{
		Matrix_Push();
		Matrix_Translate(0.0f, 0.0f, 5000.0f, MTXMODE_APPLY);
		Matrix_RotateZ(((i * M_PI) * 2.0f * 0.125f) + pthis->flameRotation, MTXMODE_APPLY);
		Matrix_Translate(0.0f, pthis->spawnPortalScale * 1.5f, 0.0f, MTXMODE_APPLY);
		gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, ((pthis->work[CS_TIMER_2] * 3) + (i * 10)) & 0x7F, (u8)((-pthis->work[CS_TIMER_2] * 15) + (i * 50)), 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
		Matrix_Scale(0.4f, 0.4f, 0.4f, MTXMODE_APPLY);
		func_800D1FD4(&globalCtx->billboardMtxF);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6751), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A430));
		Matrix_Pop();
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6756);
}

void func_80942C70(Actor* thisx, GlobalContext* globalCtx)
{
	BossTw* pthis = (BossTw*)thisx;
	s16 alpha;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6765);

	if(pthis->beamDist != 0.0f)
	{
		Matrix_Push();
		gSPSegment(POLY_XLU_DISP++, 0xC, Gfx_TexScroll(globalCtx->state.gfxCtx, 0, (u8)(pthis->work[CS_TIMER_1] * -0xF), 0x20, 0x40));
		alpha = pthis->beamScale * 100.0f * 255.0f;

		if(pthis->actor.params == 1)
		{
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 60, alpha);
			gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 128);
		}
		else
		{
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, alpha);
			gDPSetEnvColor(POLY_XLU_DISP++, 100, 100, 255, 128);
		}

		Matrix_Translate(pthis->beamOrigin.x, pthis->beamOrigin.y, pthis->beamOrigin.z, MTXMODE_NEW);
		Matrix_RotateY(pthis->beamYaw, MTXMODE_APPLY);
		Matrix_RotateX(pthis->beamPitch, MTXMODE_APPLY);
		Matrix_RotateZ(pthis->beamRoll, MTXMODE_APPLY);
		Matrix_Scale(pthis->beamScale, pthis->beamScale, (pthis->beamDist * 0.01f * 98.0f) / 20000.0f, MTXMODE_APPLY);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6846), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01DDF0));

		if(pthis->beamReflectionDist > 10.0f)
		{
			Matrix_Translate(pthis->beamReflectionOrigin.x, pthis->beamReflectionOrigin.y, pthis->beamReflectionOrigin.z, MTXMODE_NEW);
			Matrix_RotateY(pthis->beamReflectionYaw, MTXMODE_APPLY);
			Matrix_RotateX(pthis->beamReflectionPitch, MTXMODE_APPLY);
			Matrix_RotateZ(pthis->beamRoll, MTXMODE_APPLY);
			Matrix_Scale(pthis->beamScale, pthis->beamScale, (pthis->beamReflectionDist * 0.01f * 100.0f) / 20000.0f, MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6870), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
			gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01DDF0));
		}

		Matrix_Pop();
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6878);
}

void func_80943028(Actor* thisx, GlobalContext* globalCtx)
{
	BossTw* pthis = (BossTw*)thisx;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6885);

	Matrix_Push();
	Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y + 57.0f, pthis->actor.world.pos.z, MTXMODE_NEW);
	Matrix_Scale(pthis->workf[UNK_F17], pthis->workf[UNK_F17], pthis->workf[UNK_F17], MTXMODE_APPLY);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6908), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01F608));
	func_80094044(globalCtx->state.gfxCtx);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, 200);
	Matrix_Translate(pthis->actor.world.pos.x, 240.0f, pthis->actor.world.pos.z, MTXMODE_NEW);
	Matrix_Scale((pthis->actor.scale.x * 4000.0f) / 100.0f, 1.0f, (pthis->actor.scale.x * 4000.0f) / 100.0f, MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6926), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gCircleShadowDL));
	Matrix_Pop();

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6933);
}

void BossTw_Draw(Actor* thisx, GlobalContext* globalCtx2)
{
	GlobalContext* globalCtx = globalCtx2;
	BossTw* pthis = (BossTw*)thisx;
	Player* player = GET_PLAYER(globalCtx);

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 6947);

	if(pthis->visible)
	{
		gSPSegment(POLY_OPA_DISP++, 10, SEGMENTED_TO_VIRTUAL(sEyeTextures_143[pthis->eyeTexIdx]));
		gSPSegment(POLY_XLU_DISP++, 10, SEGMENTED_TO_VIRTUAL(sEyeTextures_143[pthis->eyeTexIdx]));
		gSPSegment(
		    POLY_XLU_DISP++, 8,
		    Gfx_TwoTexScroll(
			globalCtx->state.gfxCtx, 0, (s16)pthis->workf[OUTR_CRWN_TX_X1] & 0x7F, (s16)pthis->workf[OUTR_CRWN_TX_Y1] & 0x7F, 0x20, 0x20, 1, (s16)pthis->workf[OUTR_CRWN_TX_X2] & 0x7F, (s16)pthis->workf[OUTR_CRWN_TX_Y2] & 0xFF, 0x20, 0x40));

		if(pthis->actor.params == TW_KOTAKE)
		{
			gSPSegment(POLY_XLU_DISP++, 9, Gfx_TexScroll(globalCtx->state.gfxCtx, (s16)pthis->workf[INNR_CRWN_TX_X1] & 0x7F, (s16)pthis->workf[INNR_CRWN_TX_Y1] & 0xFF, 0x20, 0x40));
		}
		else
		{
			gSPSegment(
			    POLY_XLU_DISP++, 9,
			    Gfx_TwoTexScroll(
				globalCtx->state.gfxCtx, 0, (s16)pthis->workf[INNR_CRWN_TX_X1] & 0x7F, (s16)pthis->workf[INNR_CRWN_TX_Y1] & 0x7F, 0x20, 0x20, 1, (s16)pthis->workf[INNR_CRWN_TX_X2] & 0x7F, (s16)pthis->workf[INNR_CRWN_TX_Y2] & 0xFF, 0x20,
				0x40));
		}

		func_80093D18(globalCtx->state.gfxCtx);
		func_80093D84(globalCtx->state.gfxCtx);

		if(pthis->work[FOG_TIMER] & 2)
		{
			POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, 255, 50, 0, 0, 900, 1099);
		}
		else
		{
			POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, (u32)pthis->fogR, (u32)pthis->fogG, (u32)pthis->fogB, 0, pthis->fogNear, pthis->fogFar);
		}

		Matrix_Push();
		SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, BossTw_OverrideLimbDraw, BossTw_PostLimbDraw, pthis);
		Matrix_Pop();
		POLY_OPA_DISP = Gameplay_SetFog(globalCtx, POLY_OPA_DISP);
	}

	if(pthis->actor.params == TW_KOTAKE)
	{
		if(pthis->workf[UNK_F9] > 0.0f)
		{
			if(pthis->workf[UNK_F11] > 0.0f)
			{
				Vec3f diff;
				diff.x = pthis->groundBlastPos2.x - player->actor.world.pos.x;
				diff.y = pthis->groundBlastPos2.y - player->actor.world.pos.y;
				diff.z = pthis->groundBlastPos2.z - player->actor.world.pos.z;

				if((fabsf(diff.y) < 10.0f) && (player->actor.bgCheckFlags & BG_STATE_0) && (sqrtf(SQ(diff.x) + SQ(diff.z)) < (pthis->workf[UNK_F12] * 4600.0f)) && (sFreezeState == 0) && (pthis->workf[UNK_F11] > 200.0f))
				{
					sFreezeState = 1;
					sTwinrovaPtr->timers[2] = 100;
				}
			}

			func_80941BC0(pthis, globalCtx);
		}
	}
	else
	{
		func_80942180(pthis, globalCtx);
	}

	if(pthis->visible)
	{
		if(pthis->actionFunc == BossTw_DeathCS)
		{
			func_80943028(&pthis->actor, globalCtx);
		}
		else
		{
			func_809426F0(pthis, globalCtx);
			Matrix_MultVec3f(&D_8094A9A4_143, &pthis->beamOrigin);
			func_80942C70(&pthis->actor, globalCtx);
		}
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7123);
}

void* D_8094A9B0[] = {
    object_tw_Tex_02A9B0,
    object_tw_Tex_02A070,
    object_tw_Tex_02A470,
};

s32 BossTw_TwinrovaOverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	BossTw* pthis = (BossTw*)thisx;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7139);

	switch(limbIndex)
	{
		case 21:
			gSPSegment(POLY_OPA_DISP++, 0xC, Gfx_TexScroll(globalCtx->state.gfxCtx, 0, (s16)(f32)pthis->work[CS_TIMER_1], 8, 8));
			gSPSegment(POLY_OPA_DISP++, 8, SEGMENTED_TO_VIRTUAL(D_8094A9B0[pthis->eyeTexIdx]));
			gSPSegment(POLY_OPA_DISP++, 9, SEGMENTED_TO_VIRTUAL(D_8094A9B0[pthis->leftEyeTexIdx]));
			gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, pthis->work[UNK_S8]);
			break;
		case 17:
		case 41:
			*dList = NULL;
			gSPSegment(POLY_XLU_DISP++, 0xA, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x20, 1, 0, -pthis->work[CS_TIMER_1] * 0xF, 0x20, 0x40));
			break;
		case 18:
		case 42:
			*dList = NULL;
			gSPSegment(POLY_XLU_DISP++, 0xB, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x20, 1, 0, -pthis->work[CS_TIMER_1] * 0xA, 0x20, 0x40));
			break;
		case 16:
		case 32:
			*dList = NULL;
			gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x20, 1, pthis->work[CS_TIMER_1], -pthis->work[CS_TIMER_1] * 7, 0x20, 0x40));
			break;
		case 15:
		case 31:
			*dList = NULL;
			gSPSegment(POLY_XLU_DISP++, 9, Gfx_TexScroll(globalCtx->state.gfxCtx, 0, pthis->work[CS_TIMER_1], 0x20, 0x40));
			break;
		case 19:
			if(pthis->unk_5F8 != 0)
			{
				*dList = object_tw_DL_02D940;
			}
			break;

		case 20:
			if(pthis->unk_5F8 != 0)
			{
				*dList = object_tw_DL_02D890;
			}
			break;
	}

	if(pthis->unk_5F8 != 0 && ((limbIndex == 34) || (limbIndex == 40)))
	{
		*dList = NULL;
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7251);

	return false;
}

void BossTw_TwinrovaPostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	BossTw* pthis = (BossTw*)thisx;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7262);

	switch(limbIndex)
	{
		case 34:
			Matrix_MultVec3f(&D_8094A9D4_143, &pthis->leftScepterPos);
			break;
		case 40:
			Matrix_MultVec3f(&D_8094A9E0_143, &pthis->rightScepterPos);
			break;
		case 21:
			Matrix_MultVec3f(&D_8094A9BC_143, &pthis->actor.focus.pos);
			Matrix_MultVec3f(&D_8094A9C8_143, &pthis->crownPos);
			break;
		case 15:
		case 16:
		case 17:
		case 18:
		case 31:
		case 32:
		case 41:
		case 42:
			Matrix_Push();
			Matrix_Scale(pthis->workf[UNK_F12], pthis->workf[UNK_F12], pthis->workf[UNK_F12], MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7295), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
			Matrix_Pop();
			gSPDisplayList(POLY_XLU_DISP++, *dList);
			break;
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7301);
}

void BossTw_ShieldChargeDraw(BossTw* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	Player* player = GET_PLAYER(globalCtx);
	s16 temp_t0;
	s16 temp_a0;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7311);

	Matrix_Push();

	temp_t0 = sShieldFireCharge | sShieldIceCharge;

	if(temp_t0 == 1)
	{
		Common_PlaySfx(NA_SE_IT_SHIELD_CHARGE_LV1 & ~SFX_FLAG);
	}
	else if(temp_t0 == 2)
	{
		Common_PlaySfx(NA_SE_IT_SHIELD_CHARGE_LV2 & ~SFX_FLAG);
	}
	else if(temp_t0 == 3)
	{
		Common_PlaySfx(NA_SE_IT_SHIELD_CHARGE_LV3 & ~SFX_FLAG);
	}

	if(temp_t0 != 0 && temp_t0 < 4)
	{
		Math_ApproachF(&D_8094C854, 255.0f, 1.0f, 20.0f);
		if(temp_t0 == 3)
		{
			temp_t0 *= 3;
		}
	}
	else if(temp_t0 == 0)
	{
		D_8094C854 = 0.0f;
	}
	else
	{
		Math_ApproachF(&D_8094C854, 0.0f, 1.0f, 10.0f);
		if(D_8094C854 == 0.0f)
		{
			sShieldIceCharge = 0;
			sShieldFireCharge = 0;
		}

		temp_t0 = 1;
	}

	if(Player_HasMirrorShieldEquipped(globalCtx))
	{
		if(temp_t0 != 0)
		{
			Matrix_Mult(&player->shieldMf, MTXMODE_NEW);
			Matrix_RotateX(M_PI / 2.0f, MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7362), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
			temp_a0 = (Math_SinS(pthis->work[CS_TIMER_1] * 2730 * temp_t0) * D_8094C854 * 0.5f) + (D_8094C854 * 0.5f);
			if(sShieldFireCharge != 0)
			{
				gDPSetEnvColor(POLY_XLU_DISP++, 255, 245, 255, temp_a0);
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01E0E0));
				gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (pthis->work[CS_TIMER_1] * 2) * temp_t0, 0, 0x20, 0x20, 1, (-pthis->work[CS_TIMER_1] * 2) * temp_t0, 0, 0x20, 0x20));
				gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 100, 20, 0, (s16)D_8094C854);
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01E020));
			}
			else
			{
				gDPSetEnvColor(POLY_XLU_DISP++, 225, 255, 255, temp_a0);
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01E3A0));
				gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, (-pthis->work[CS_TIMER_1] * 5) * temp_t0, 0x20, 0x40, 1, (pthis->work[CS_TIMER_1] * 4) * temp_t0, 0, 0x20, 0x20));
				gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 175, 205, 195, (s16)D_8094C854);
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01E2C0));
			}
		}
	}

	if(D_8094C86F != 0)
	{
		f32 step = D_8094C872 > 0 ? 100.0f : 60.0f;

		D_8094C86F--;
		Math_ApproachF(&D_8094C858, 255.0f, 1.0f, step);
	}
	else
	{
		f32 step = D_8094C872 > 0 ? 40.0f : 20.0f;

		Math_ApproachF(&D_8094C858, 0.0f, 1.0f, step);
	}

	if(Player_HasMirrorShieldEquipped(globalCtx) && D_8094C858 > 0.0f)
	{
		f32 scale = D_8094C872 > 0 ? 1.3f : 1.0f;

		Matrix_Mult(&player->shieldMf, MTXMODE_NEW);
		Matrix_RotateX(M_PI / 2.0f, MTXMODE_APPLY);
		Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7486), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
		if(sShieldFireCharge != 0)
		{
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 220, 20, (s16)D_8094C858);
			gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 20, 110);
		}
		else
		{
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s16)D_8094C858);
			gDPSetEnvColor(POLY_XLU_DISP++, 185, 225, 205, 150);
		}

		gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, pthis->work[CS_TIMER_1] * D_8094C872, 0x20, 0x40, 1, 0, pthis->work[CS_TIMER_1] * D_8094C872, 0x20, 0x20));
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01E9F0));
	}

	Matrix_Pop();

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7531);
}

void BossTw_SpawnPortalDraw(BossTw* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7546);

	func_80093D84(globalCtx->state.gfxCtx);
	gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, -pthis->work[CS_TIMER_1] * 15, 0x20, 0x40, 1, 0, 0, 0x40, 0x40));

	Matrix_Push();

	Matrix_Translate(0.0f, 232.0f, -600.0f, MTXMODE_NEW);
	Matrix_Scale(pthis->spawnPortalScale, pthis->spawnPortalScale, pthis->spawnPortalScale, MTXMODE_APPLY);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, (s16)pthis->spawnPortalAlpha);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7582), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01EC68));

	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 135, 175, 165, (s16)pthis->spawnPortalAlpha);
	Matrix_Translate(0.0f, 2.0f, 0.0f, MTXMODE_APPLY);
	Matrix_RotateX(M_PI / 2.0f, MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7596), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01CEE0));

	Matrix_Translate(0.0f, 232.0f, 600.0f, MTXMODE_NEW);
	Matrix_Scale(pthis->spawnPortalScale, pthis->spawnPortalScale, pthis->spawnPortalScale, MTXMODE_APPLY);
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, (s16)pthis->spawnPortalAlpha);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7617), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01EC68));

	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 0, (s16)pthis->spawnPortalAlpha);
	Matrix_Translate(0.0f, 2.0f, 0.0f, MTXMODE_APPLY);
	Matrix_RotateX(M_PI / 2.0f, MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7631), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01DBE8));

	Matrix_Pop();

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7635);
}

void func_80944C50(BossTw* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	f32 scale;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7645);

	Matrix_Push();
	Matrix_Translate(0.0f, 750.0f, 0.0f, MTXMODE_NEW);
	Matrix_Scale(0.35f, 0.35f, 0.35f, MTXMODE_APPLY);
	Matrix_Push();
	Matrix_Scale(pthis->workf[UNK_F19], pthis->workf[UNK_F19], pthis->workf[UNK_F19], MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7671), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01F390));

	Matrix_Pop();
	gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, -sKoumePtr->work[CS_TIMER_1] * 2, 0, 0x20, 0x20, 1, -sKoumePtr->work[CS_TIMER_1] * 2, 0, 0x20, 0x40));
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s16)pthis->workf[UNK_F18] / 2);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7694), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01F238));

	gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, -sKoumePtr->work[CS_TIMER_1] * 5, -sKoumePtr->work[CS_TIMER_1] * 2, 0x20, 0x40, 1, 0, -sKoumePtr->work[CS_TIMER_1] * 2, 0x10, 0x10));
	gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s16)(pthis->workf[UNK_F18] * 0.3f));

	scale = pthis->workf[UNK_F18] / 150.0f;
	scale = CLAMP_MAX(scale, 1.0f);

	Matrix_Scale(scale, 1.0f, scale, MTXMODE_APPLY);
	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7728), G_MTX_LOAD | G_MTX_MODELVIEW | G_MTX_NOPUSH);
	gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01EEB0));
	Matrix_Pop();

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7732);
}

void BossTw_TwinrovaDraw(Actor* thisx, GlobalContext* globalCtx2)
{
	GlobalContext* globalCtx = globalCtx2;
	BossTw* pthis = (BossTw*)thisx;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7748);

	if(pthis->visible)
	{
		func_80093D18(globalCtx->state.gfxCtx);
		func_80093D84(globalCtx->state.gfxCtx);

		POLY_OPA_DISP = (pthis->work[FOG_TIMER] & 2) ? Gfx_SetFog2(POLY_OPA_DISP, 255, 50, 0, 0, 900, 1099) : Gfx_SetFog2(POLY_OPA_DISP, (u32)pthis->fogR, (u32)pthis->fogG, (u32)pthis->fogB, 0, pthis->fogNear, pthis->fogFar);

		Matrix_Push();
		SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, BossTw_TwinrovaOverrideLimbDraw, BossTw_TwinrovaPostLimbDraw, thisx);
		Matrix_Pop();

		Matrix_MultVec3f(&D_8094A9EC_143, &pthis->beamOrigin);
		POLY_OPA_DISP = Gfx_SetFog2(POLY_OPA_DISP, globalCtx->lightCtx.fogColor[0], globalCtx->lightCtx.fogColor[1], globalCtx->lightCtx.fogColor[2], 0, globalCtx->lightCtx.fogNear, 1000);
	}

	BossTw_DrawEffects(globalCtx);
	BossTw_ShieldChargeDraw(pthis, globalCtx);

	if(pthis->spawnPortalAlpha > 0.0f)
	{
		BossTw_SpawnPortalDraw(pthis, globalCtx);
	}

	if(pthis->workf[UNK_F18] > 0.0f)
	{
		func_80944C50(pthis, globalCtx);
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 7804);
}

void BossTw_BlastFire(BossTw* pthis, GlobalContext* globalCtx)
{
	s16 i;
	f32 xDiff;
	f32 yDiff;
	f32 zDiff;
	f32 distXZ;
	Player* player = GET_PLAYER(globalCtx);
	Player* player2 = player;

	switch(pthis->actor.params)
	{
		case TW_FIRE_BLAST:
			switch(pthis->csState1)
			{
				case 0:
					Actor_SetScale(&pthis->actor, 0.03f);
					pthis->csState1 = 1;
					xDiff = player->actor.world.pos.x - pthis->actor.world.pos.x;
					yDiff = (player->actor.world.pos.y + 30.0f) - pthis->actor.world.pos.y;
					zDiff = player->actor.world.pos.z - pthis->actor.world.pos.z;
					// yaw
					pthis->actor.world.rot.y = Math_FAtan2F(xDiff, zDiff) * (32768 / M_PI);
					// pitch
					distXZ = sqrtf(SQ(xDiff) + SQ(zDiff));
					pthis->actor.world.rot.x = Math_FAtan2F(yDiff, distXZ) * (32768 / M_PI);
					pthis->actor.speedXZ = 20.0f;

					for(i = 0; i < 50; i++)
					{
						pthis->blastTailPos[i] = pthis->actor.world.pos;
					}
					pthis->workf[TAIL_ALPHA] = 255.0f;
					// fallthrough
				case 1:
				case 10:
					pthis->blastActive = true;
					if(pthis->timers[0] == 0)
					{
						func_8002D908(&pthis->actor);
						Actor_UpdatePosition(&pthis->actor);
						Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_SHOOT_FIRE & ~SFX_FLAG);
					}
					else
					{
						Vec3f velocity;
						Vec3f velDir;
						Vec3s blastDir;
						s16 alpha;

						pthis->actor.world.pos = player2->bodyPartsPos[15];
						pthis->actor.world.pos.y = -2000.0f;
						Matrix_MtxFToYXZRotS(&player2->shieldMf, &blastDir, 0);
						blastDir.x = -blastDir.x;
						blastDir.y = blastDir.y + 0x8000;
						Math_ApproachS(&pthis->magicDir.x, blastDir.x, 0xA, 0x800);
						Math_ApproachS(&pthis->magicDir.y, blastDir.y, 0xA, 0x800);

						if(pthis->timers[0] == 50)
						{
							D_8094C86F = 10;
							D_8094C872 = 7;
							globalCtx->envCtx.unk_D8 = 1.0f;
						}

						if(pthis->timers[0] <= 50)
						{
							Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_SHOOT_FIRE & ~SFX_FLAG);
							Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_REFL_FIRE & ~SFX_FLAG);
							Matrix_RotateY((pthis->magicDir.y / 32678.0f) * M_PI, MTXMODE_NEW);
							Matrix_RotateX((pthis->magicDir.x / 32678.0f) * M_PI, MTXMODE_APPLY);
							velDir.x = 0.0f;
							velDir.y = 0.0f;
							velDir.z = 50.0f;
							Matrix_MultVec3f(&velDir, &velocity);
							alpha = pthis->timers[0] * 10;
							alpha = CLAMP_MAX(alpha, 255);

							BossTw_AddShieldBlastEffect(globalCtx, &player2->bodyPartsPos[15], &velocity, &sZeroVector, 10.0f, 80.0f, alpha, 1);
						}

						if(pthis->timers[0] == 1)
						{
							sEnvType = 0;
							sShieldFireCharge++;
							Actor_Kill(&pthis->actor);
						}

						return;
					}

					pthis->groundBlastPos.y = BossTw_GetFloorY(&pthis->actor.world.pos);

					if(pthis->groundBlastPos.y >= 0.0f)
					{
						if(pthis->groundBlastPos.y != 35.0f)
						{
							pthis->groundBlastPos.x = pthis->actor.world.pos.x;
							pthis->groundBlastPos.z = pthis->actor.world.pos.z;
							BossTw_SpawnGroundBlast(pthis, globalCtx, 1);
						}
						else
						{
							Vec3f velocity;
							Vec3f accel;

							for(i = 0; i < 50; i++)
							{
								velocity.x = Rand_CenteredFloat(20.0f);
								velocity.y = Rand_CenteredFloat(20.0f);
								velocity.z = Rand_CenteredFloat(20.0f);
								accel.x = 0.0f;
								accel.y = 0.0f;
								accel.z = 0.0f;
								BossTw_AddFlameEffect(globalCtx, &pthis->actor.world.pos, &velocity, &accel, Rand_ZeroFloat(10.0f) + 25.0f, pthis->blastType);
							}

							globalCtx->envCtx.unk_D8 = 0.5f;
						}

						pthis->csState1 = 2;
						pthis->timers[0] = 20;
					}
					else
					{
						Vec3f pos;
						Vec3f velocity = {0.0f, 0.0f, 0.0f};
						Vec3f accel = {0.0f, 0.0f, 0.0f};

						for(i = 0; i < 10; i++)
						{
							pos = pthis->blastTailPos[(s16)Rand_ZeroFloat(29.9f)];
							pos.x += Rand_CenteredFloat(40.0f);
							pos.y += Rand_CenteredFloat(40.0f);
							pos.z += Rand_CenteredFloat(40.0f);
							accel.y = 0.4f;
							accel.x = Rand_CenteredFloat(0.5f);
							accel.z = Rand_CenteredFloat(0.5f);
							BossTw_AddDotEffect(globalCtx, &pos, &velocity, &accel, (s16)Rand_ZeroFloat(2.0f) + 8, 1, 75);
						}
					}
					break;
				case 2:
					Math_ApproachF(&pthis->workf[TAIL_ALPHA], 0.0f, 1.0f, 15.0f);
					if(pthis->timers[0] == 0)
					{
						Actor_Kill(&pthis->actor);
					}
					break;
			}
			break;

		case TW_FIRE_BLAST_GROUND:
			if(pthis->timers[0] != 0)
			{
				if(pthis->timers[0] == 1)
				{
					sEnvType = 0;
				}

				if(sGroundBlastType == 2)
				{
					pthis->timers[0] = 0;
				}

				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_FIRE_EXP - SFX_FLAG);

				xDiff = sKoumePtr->groundBlastPos2.x - player->actor.world.pos.x;
				yDiff = sKoumePtr->groundBlastPos2.y - player->actor.world.pos.y;
				zDiff = sKoumePtr->groundBlastPos2.z - player->actor.world.pos.z;

				if(!player->isBurning && (player->actor.bgCheckFlags & BG_STATE_0) && (fabsf(yDiff) < 10.0f) && (sqrtf(SQ(xDiff) + SQ(zDiff)) < (sKoumePtr->workf[UNK_F13] * 4550.0f)))
				{
					s16 j;

					for(j = 0; j < 18; j++)
					{
						player->flameTimers[j] = Rand_S16Offset(0, 200);
					}

					player->isBurning = 1;

					if(pthis->work[BURN_TMR] == 0)
					{
						func_8002F7DC(&player->actor, player->ageProperties->unk_92 + NA_SE_VO_LI_DEMO_DAMAGE);
						pthis->work[BURN_TMR] = 40;
					}

					sTwinrovaPtr->timers[2] = 100;
				}

				Math_ApproachF(&sKoumePtr->workf[UNK_F13], 0.04f, 0.1f, 0.002f);
				break;
			}

			{
				f32 sp4C = sGroundBlastType == 2 ? 3.0f : 1.0f;

				Math_ApproachF(&sKoumePtr->workf[UNK_F9], 0.0f, 1.0f, 10.0f * sp4C);
				Math_ApproachF(&sKoumePtr->workf[UNK_F12], 0.0f, 1.0f, 0.03f * sp4C);
				Math_ApproachF(&sKoumePtr->workf[TAIL_ALPHA], 0.0f, 1.0f, 3.0f * sp4C);
				Math_ApproachF(&sKoumePtr->workf[UNK_F11], 0.0f, 1.0f, 6.0f * sp4C);
			}

			if(sKoumePtr->workf[TAIL_ALPHA] <= 0.0f)
			{
				Actor_Kill(&pthis->actor);
			}

			break;
	}
}

void BossTw_BlastIce(BossTw* pthis, GlobalContext* globalCtx)
{
	s16 i;
	f32 xDiff;
	f32 yDiff;
	f32 zDiff;
	f32 xzDist;
	Player* player = GET_PLAYER(globalCtx);
	Player* player2 = player;

	switch(pthis->actor.params)
	{
		case TW_ICE_BLAST:
			switch(pthis->csState1)
			{
				case 0:
					Actor_SetScale(&pthis->actor, 0.03f);
					pthis->csState1 = 1;
					xDiff = player->actor.world.pos.x - pthis->actor.world.pos.x;
					yDiff = (player->actor.world.pos.y + 30.0f) - pthis->actor.world.pos.y;
					zDiff = player->actor.world.pos.z - pthis->actor.world.pos.z;
					pthis->actor.world.rot.y = Math_FAtan2F(xDiff, zDiff) * (32768 / M_PI);
					xzDist = sqrtf(SQ(xDiff) + SQ(zDiff));
					pthis->actor.world.rot.x = Math_FAtan2F(yDiff, xzDist) * (32768 / M_PI);
					pthis->actor.speedXZ = 20.0f;
					for(i = 0; i < 50; i++)
					{
						pthis->blastTailPos[i] = pthis->actor.world.pos;
					}

					pthis->workf[TAIL_ALPHA] = 255.0f;
					// fallthrough
				case 1:
				case 10:
					pthis->blastActive = true;

					if(pthis->timers[0] == 0)
					{
						func_8002D908(&pthis->actor);
						Actor_UpdatePosition(&pthis->actor);
						Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_SHOOT_FREEZE - SFX_FLAG);
					}
					else
					{
						Vec3f velocity;
						Vec3f spF4;
						Vec3s reflDir;
						s16 alpha;

						pthis->actor.world.pos = player2->bodyPartsPos[15];
						pthis->actor.world.pos.y = -2000.0f;
						Matrix_MtxFToYXZRotS(&player2->shieldMf, &reflDir, 0);
						reflDir.x = -reflDir.x;
						reflDir.y += 0x8000;
						Math_ApproachS(&pthis->magicDir.x, reflDir.x, 0xA, 0x800);
						Math_ApproachS(&pthis->magicDir.y, reflDir.y, 0xA, 0x800);

						if(pthis->timers[0] == 50)
						{
							D_8094C86F = 10;
							D_8094C872 = 7;
							globalCtx->envCtx.unk_D8 = 1.0f;
						}

						if(pthis->timers[0] <= 50)
						{
							Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_SHOOT_FREEZE - SFX_FLAG);
							Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_REFL_FREEZE - SFX_FLAG);
							Matrix_RotateY((pthis->magicDir.y / 32678.0f) * M_PI, MTXMODE_NEW);
							Matrix_RotateX((pthis->magicDir.x / 32678.0f) * M_PI, MTXMODE_APPLY);
							spF4.x = 0.0f;
							spF4.y = 0.0f;
							spF4.z = 50.0f;
							Matrix_MultVec3f(&spF4, &velocity);
							alpha = pthis->timers[0] * 10;
							alpha = CLAMP_MAX(alpha, 255);

							BossTw_AddShieldBlastEffect(globalCtx, &player2->bodyPartsPos[15], &velocity, &sZeroVector, 10.0f, 80.0f, alpha, 0);
						}

						if(pthis->timers[0] == 1)
						{
							sEnvType = 0;
							sShieldIceCharge++;
							Actor_Kill(&pthis->actor);
						}

						break;
					}

					pthis->groundBlastPos.y = BossTw_GetFloorY(&pthis->actor.world.pos);

					if(pthis->groundBlastPos.y >= 0.0f)
					{
						if(pthis->groundBlastPos.y != 35.0f)
						{
							pthis->groundBlastPos.x = pthis->actor.world.pos.x;
							pthis->groundBlastPos.z = pthis->actor.world.pos.z;
							BossTw_SpawnGroundBlast(pthis, globalCtx, 0);
						}
						else
						{
							for(i = 0; i < 50; i++)
							{
								Vec3f velocity;
								Vec3f accel;

								velocity.x = Rand_CenteredFloat(20.0f);
								velocity.y = Rand_CenteredFloat(20.0f);
								velocity.z = Rand_CenteredFloat(20.0f);
								accel.x = 0.0f;
								accel.y = 0.0f;
								accel.z = 0.0f;
								BossTw_AddFlameEffect(globalCtx, &pthis->actor.world.pos, &velocity, &accel, Rand_ZeroFloat(10.0f) + 25.0f, pthis->blastType);
							}

							globalCtx->envCtx.unk_D8 = 0.5f;
						}

						pthis->csState1 = 2;
						pthis->timers[0] = 20;
					}
					else
					{
						Vec3f pos;
						Vec3f velocity = {0.0f, 0.0f, 0.0f};
						Vec3f accel = {0.0f, 0.0f, 0.0f};

						for(i = 0; i < 10; i++)
						{
							pos = pthis->blastTailPos[(s16)Rand_ZeroFloat(29.9f)];
							pos.x += Rand_CenteredFloat(40.0f);
							pos.y += Rand_CenteredFloat(40.0f);
							pos.z += Rand_CenteredFloat(40.0f);
							accel.y = 0.4f;
							accel.x = Rand_CenteredFloat(0.5f);
							accel.z = Rand_CenteredFloat(0.5f);
							BossTw_AddDotEffect(globalCtx, &pos, &velocity, &accel, ((s16)Rand_ZeroFloat(2.0f) + 8), 0, 75);
						}
					}
					break;

				case 2:
					Math_ApproachF(&pthis->workf[TAIL_ALPHA], 0.0f, 1.0f, 15.0f);
					if(pthis->timers[0] == 0)
					{
						Actor_Kill(&pthis->actor);
					}
					break;
			}
			break;

		case TW_ICE_BLAST_GROUND:
			if(pthis->timers[0] != 0)
			{
				if(pthis->timers[0] == 1)
				{
					sEnvType = 0;
				}

				if(sGroundBlastType == 1)
				{
					pthis->timers[0] = 0;
				}

				Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_ICE_FREEZE - SFX_FLAG);

				if(pthis->timers[0] > (sTwinrovaPtr->actionFunc == BossTw_Wait ? 70 : 20))
				{
					s32 pad;
					Vec3f pos;
					Vec3f velocity;
					Vec3f accel;

					pos.x = sKotakePtr->groundBlastPos2.x + Rand_CenteredFloat(320.0f);
					pos.z = sKotakePtr->groundBlastPos2.z + Rand_CenteredFloat(320.0f);
					pos.y = sKotakePtr->groundBlastPos2.y;
					velocity.x = 0.0f;
					velocity.y = 0.0f;
					velocity.z = 0.0f;
					accel.x = 0.0f;
					accel.y = 0.13f;
					accel.z = 0.0f;
					BossTw_AddDmgCloud(globalCtx, 3, &pos, &velocity, &accel, Rand_ZeroFloat(5.0f) + 20.0f, 0, 0, 80);
					velocity.x = Rand_CenteredFloat(10.0f);
					velocity.z = Rand_CenteredFloat(10.0f);
					velocity.y = Rand_ZeroFloat(3.0f) + 3.0f;
					pos.x = sKotakePtr->groundBlastPos2.x + (velocity.x * 0.5f);
					pos.z = sKotakePtr->groundBlastPos2.z + (velocity.z * 0.5f);
					BossTw_AddDmgCloud(globalCtx, 3, &pos, &velocity, &accel, Rand_ZeroFloat(5.0f) + 15.0f, 255, 2, 130);
				}

				Math_ApproachF(&sKotakePtr->workf[UNK_F9], 80.0f, 1.0f, 3.0f);
				Math_ApproachF(&sKotakePtr->workf[UNK_F11], 255.0f, 1.0f, 10.0f);
				Math_ApproachF(&sKotakePtr->workf[UNK_F12], 0.04f, 0.1f, 0.002f);
				Math_ApproachF(&sKotakePtr->workf[UNK_F16], 70.0f, 1.0f, 5.0f);

				if((pthis->timers[0] == 70) || (pthis->timers[0] == 30))
				{
					sKotakePtr->workf[UNK_F16] = 10.0f;
				}

				if((pthis->timers[0] % 4) == 0)
				{
					sKotakePtr->workf[UNK_F15] = (2.0f * (s16)Rand_ZeroFloat(9.9f) * M_PI) / 10.0f;
				}
			}
			else
			{
				f32 sp80;

				if(sGroundBlastType == 1)
				{
					if(sKotakePtr->workf[UNK_F11] > 1.0f)
					{
						for(i = 0; i < 3; i++)
						{
							Vec3f pos;
							Vec3f velocity;
							Vec3f accel;
							pos.x = Rand_CenteredFloat(280.0f) + sKotakePtr->groundBlastPos2.x;
							pos.z = Rand_CenteredFloat(280.0f) + sKotakePtr->groundBlastPos2.z;
							pos.y = sKotakePtr->groundBlastPos2.y + 30.0f;
							velocity.x = 0.0f;
							velocity.y = 0.0f;
							velocity.z = 0.0f;
							accel.x = 0.0f;
							accel.y = 0.13f;
							accel.z = 0.0f;
							BossTw_AddDmgCloud(globalCtx, 3, &pos, &velocity, &accel, Rand_ZeroFloat(5.0f) + 20, 0, 0, 80);
						}
					}
					sp80 = 3.0f;
				}
				else
				{
					sp80 = 1.0f;
				}

				Math_ApproachF(&sKotakePtr->workf[UNK_F14], 0.0f, 1.0f, 0.2f * sp80);
				Math_ApproachF(&sKotakePtr->workf[UNK_F11], 0.0f, 1.0f, 5.0f * sp80);
				Math_ApproachF(&sKotakePtr->workf[UNK_F9], 0.0f, 1.0f, sp80);

				if(sKotakePtr->workf[UNK_F9] <= 0.0f)
				{
					Actor_Kill(&pthis->actor);
				}
			}
			break;
	}
}

s32 BossTw_BlastShieldCheck(BossTw* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	s32 ret = false;
	ColliderInfo* info;

	if(1)
	{
	}

	if(pthis->csState1 == 1)
	{
		if(pthis->collider.base.acFlags & AC_HIT)
		{
			pthis->collider.base.acFlags &= ~AC_HIT;
			pthis->collider.base.atFlags &= ~AT_HIT;
			info = pthis->collider.info.acHitInfo;

			if(info->toucher.dmgFlags & DMG_SHIELD)
			{
				pthis->work[INVINC_TIMER] = 7;
				globalCtx->envCtx.unk_D8 = 1.0f;
				Rumble_Shake(0.0f, 100, 5, 4);

				if(Player_HasMirrorShieldEquipped(globalCtx))
				{
					if(pthis->blastType == 1)
					{
						if(sShieldIceCharge != 0)
						{
							sShieldIceCharge = 0;
							BossTw_AddShieldDeflectEffect(globalCtx, 10.0f, 1);
						}
						else
						{
							BossTw_AddShieldHitEffect(globalCtx, 10.0f, 1);
							sShieldFireCharge++;
							D_8094C86F = (sShieldFireCharge * 2) + 8;
							D_8094C872 = -7;
						}
					}
					else
					{
						if(sShieldFireCharge != 0)
						{
							sShieldFireCharge = 0;
							if(1)
							{
							}
							BossTw_AddShieldDeflectEffect(globalCtx, 10.0f, 0);
						}
						else
						{
							BossTw_AddShieldHitEffect(globalCtx, 10.0f, 0);
							sShieldIceCharge++;
							D_8094C86F = (sShieldIceCharge * 2) + 8;
							D_8094C872 = -7;
						}
					}

					if((sShieldIceCharge >= 3) || (sShieldFireCharge >= 3))
					{
						pthis->timers[0] = 80;
						pthis->csState1 = 10;
						Matrix_MtxFToYXZRotS(&player->shieldMf, &pthis->magicDir, 0);
						pthis->magicDir.y += 0x8000;
						pthis->magicDir.x = -pthis->magicDir.x;
						D_8094C86F = 8;
					}
					else
					{
						pthis->csState1 = 2;
						pthis->timers[0] = 20;
						sEnvType = 0;
					}
				}
				else
				{
					BossTw_AddShieldDeflectEffect(globalCtx, 10.0f, pthis->blastType);
					pthis->csState1 = 2;
					pthis->timers[0] = 20;
					sEnvType = 0;
					sShieldIceCharge = 0;
					sShieldFireCharge = 0;
					Common_PlaySfx(NA_SE_IT_SHIELD_REFLECT_MG2);
				}

				ret = true;
			}
		}
	}

	return ret;
}

void BossTw_BlastUpdate(Actor* thisx, GlobalContext* globalCtx)
{
	BossTw* pthis = (BossTw*)thisx;
	ColliderCylinder* collider;
	s16 i;

	pthis->work[CS_TIMER_1]++;
	pthis->work[CS_TIMER_2]++;
	pthis->work[TAIL_IDX]++;

	if(pthis->work[TAIL_IDX] > 29)
	{
		pthis->work[TAIL_IDX] = 0;
	}

	pthis->blastTailPos[pthis->work[TAIL_IDX]] = pthis->actor.world.pos;

	pthis->actionFunc(pthis, globalCtx);

	for(i = 0; i < 5; i++)
	{
		if(pthis->timers[i] != 0)
		{
			pthis->timers[i]--;
		}
	}

	if(pthis->work[INVINC_TIMER] != 0)
	{
		pthis->work[INVINC_TIMER]--;
	}

	if(pthis->work[BURN_TMR] != 0)
	{
		pthis->work[BURN_TMR]--;
	}

	pthis->actor.focus.pos = pthis->actor.world.pos;
	collider = &pthis->collider;
	Collider_UpdateCylinder(&pthis->actor, collider);

	if(pthis->blastActive && pthis->work[INVINC_TIMER] == 0 && !BossTw_BlastShieldCheck(pthis, globalCtx))
	{
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &collider->base);
		CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &collider->base);
	}

	pthis->blastActive = false;
}

void BossTw_BlastDraw(Actor* thisx, GlobalContext* globalCtx2)
{
	GlobalContext* globalCtx = globalCtx2;
	BossTw* pthis = (BossTw*)thisx;
	f32 scaleFactor;
	s16 tailIdx;
	s16 i;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 8818);

	func_80093D84(globalCtx->state.gfxCtx);

	switch(pthis->actor.params)
	{
		case TW_FIRE_BLAST:
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 200, 20, 0, (s8)pthis->workf[TAIL_ALPHA]);
			gDPSetEnvColor(POLY_XLU_DISP++, 255, 215, 255, 128);
			for(i = 9; i >= 0; i--)
			{
				gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, ((pthis->work[CS_TIMER_1] * 3) + (i * 10)) & 0x7F, ((-pthis->work[CS_TIMER_1] * 15) + (i * 50)) & 0xFF, 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
				tailIdx = ((pthis->work[TAIL_IDX] - i) + 30) % 30;
				Matrix_Translate(pthis->blastTailPos[tailIdx].x, pthis->blastTailPos[tailIdx].y, pthis->blastTailPos[tailIdx].z, MTXMODE_NEW);
				scaleFactor = 1.0f - (i * 0.09f);
				Matrix_Scale(pthis->actor.scale.x * scaleFactor, pthis->actor.scale.y * scaleFactor, pthis->actor.scale.z * scaleFactor, MTXMODE_APPLY);
				func_800D1FD4(&globalCtx->billboardMtxF);
				gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 8865), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A430));
			}
			break;

		case TW_FIRE_BLAST_GROUND:
			break;

		case TW_ICE_BLAST:
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, (s8)pthis->workf[TAIL_ALPHA]);
			gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A998));
			for(i = 9; i >= 0; i--)
			{
				gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, ((pthis->work[CS_TIMER_1] * 3) + (i * 0xA)) & 0x7F, (u8)((-pthis->work[CS_TIMER_1] * 0xF) + (i * 50)), 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
				tailIdx = ((pthis->work[TAIL_IDX] - i) + 30) % 30;
				Matrix_Translate(pthis->blastTailPos[tailIdx].x, pthis->blastTailPos[tailIdx].y, pthis->blastTailPos[tailIdx].z, MTXMODE_NEW);
				scaleFactor = 1.0f - (i * 0.09f);
				Matrix_Scale(pthis->actor.scale.x * scaleFactor, pthis->actor.scale.y * scaleFactor, pthis->actor.scale.z * scaleFactor, MTXMODE_APPLY);
				func_800D1FD4(&globalCtx->billboardMtxF);
				gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 9004), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01AB00));
			}
			break;

		case TW_ICE_BLAST_GROUND:
			break;
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 9013);
}

void BossTw_DrawDeathBall(Actor* thisx, GlobalContext* globalCtx2)
{
	GlobalContext* globalCtx = globalCtx2;
	BossTw* pthis = (BossTw*)thisx;
	f32 scaleFactor;
	s16 tailIdx;
	s16 i;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 9028);

	func_80093D84(globalCtx->state.gfxCtx);

	if(pthis->actor.params == TW_DEATHBALL_KOUME)
	{
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 200, 20, 0, (s8)pthis->workf[TAIL_ALPHA]);
		gDPSetEnvColor(POLY_XLU_DISP++, 255, 215, 255, 128);

		for(i = 9; i >= 0; i--)
		{
			gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (((pthis->work[CS_TIMER_1] * 3) + (i * 0xA))) & 0x7F, (u8)((-pthis->work[CS_TIMER_1] * 0xF) + (i * 50)), 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
			tailIdx = ((pthis->work[TAIL_IDX] - i) + 30) % 30;
			Matrix_Translate(pthis->blastTailPos[tailIdx].x, pthis->blastTailPos[tailIdx].y, pthis->blastTailPos[tailIdx].z, MTXMODE_NEW);
			scaleFactor = (1.0f - (i * 0.09f));
			Matrix_Scale(pthis->actor.scale.x * scaleFactor, pthis->actor.scale.y * scaleFactor, pthis->actor.scale.z * scaleFactor, MTXMODE_APPLY);
			func_800D1FD4(&globalCtx->billboardMtxF);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 9071), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A430));
		}
	}
	else
	{
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, (s8)pthis->workf[TAIL_ALPHA]);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A998));

		for(i = 9; i >= 0; i--)
		{
			gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (((pthis->work[CS_TIMER_1] * 3) + (i * 0xA))) & 0x7F, (u8)((-pthis->work[CS_TIMER_1] * 0xF) + (i * 50)), 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
			tailIdx = ((pthis->work[TAIL_IDX] - i) + 30) % 30;
			Matrix_Translate(pthis->blastTailPos[tailIdx].x, pthis->blastTailPos[tailIdx].y, pthis->blastTailPos[tailIdx].z, MTXMODE_NEW);
			scaleFactor = (1.0f - (i * 0.09f));
			Matrix_Scale(pthis->actor.scale.x * scaleFactor, pthis->actor.scale.y * scaleFactor, pthis->actor.scale.z * scaleFactor, MTXMODE_APPLY);
			func_800D1FD4(&globalCtx->billboardMtxF);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_tw.c", 9107), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01AB00));
		}
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_tw.c", 9111);
}

void BossTw_UpdateEffects(GlobalContext* globalCtx)
{
	Vec3f sp11C;
	BossTwEffect* eff = (BossTwEffect*)globalCtx->specialEffects;
	Player* player = GET_PLAYER(globalCtx);
	u8 sp113 = 0;
	s16 i;
	s16 j;
	s16 colorIdx;
	Vec3f off;
	Vec3f spF4;
	Vec3f spE8;
	Vec3f spDC;
	Vec3f spD0;
	f32 phi_f22;
	Vec3f spC0;
	Vec3f spB4;
	Vec3f spA8;
	s16 spA6;
	f32 phi_f0;
	Actor* unk44;

	for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
	{
		if(eff->type != 0)
		{
			eff->pos.x += eff->curSpeed.x;
			eff->pos.y += eff->curSpeed.y;
			eff->pos.z += eff->curSpeed.z;
			eff->frame++;
			eff->curSpeed.x += eff->accel.x;
			eff->curSpeed.y += eff->accel.y;
			eff->curSpeed.z += eff->accel.z;

			if(eff->type == 1)
			{
				colorIdx = eff->frame % 4;

				if(eff->work[EFF_ARGS] == 0)
				{
					colorIdx += 4;
				}

				eff->color.r = sDotColors_143[colorIdx].r;
				eff->color.g = sDotColors_143[colorIdx].g;
				eff->color.b = sDotColors_143[colorIdx].b;
				eff->alpha -= 20;

				if(eff->alpha <= 0)
				{
					eff->alpha = 0;
					eff->type = TWEFF_NONE;
				}
			}
			else if((eff->type == 3) || (eff->type == 2))
			{
				if(eff->work[EFF_ARGS] == 2)
				{
					eff->alpha -= 20;
					if(eff->alpha <= 0)
					{
						eff->alpha = 0;
						eff->type = TWEFF_NONE;
					}
				}
				else if(eff->work[EFF_ARGS] == 0)
				{
					eff->alpha += 10;
					if(eff->alpha >= 100)
					{
						eff->work[EFF_ARGS]++;
					}
				}
				else
				{
					eff->alpha -= 3;
					if(eff->alpha <= 0)
					{
						eff->alpha = 0;
						eff->type = TWEFF_NONE;
					}
				}
			}
			else if(eff->type == TWEFF_FLAME)
			{
				if(eff->work[EFF_UNKS1] != 0)
				{
					eff->alpha = (eff->alpha - (i & 7)) - 0xD;
					if(eff->alpha <= 0)
					{
						eff->alpha = 0;
						eff->type = TWEFF_NONE;
					}
				}
				else
				{
					eff->alpha += 300;
					if(eff->alpha >= 255)
					{
						eff->alpha = 255;
						eff->work[EFF_UNKS1]++;
					}
				}
			}
			else if(eff->type == TWEFF_SHLD_BLST)
			{
				D_8094C870 = 1;
				eff->work[EFF_UNKS1]++;
				if(eff->work[EFF_UNKS1] > 30)
				{
					eff->alpha -= 10;
					if(eff->alpha <= 0)
					{
						eff->alpha = 0;
						eff->type = TWEFF_NONE;
					}
				}

				Math_ApproachF(&eff->workf[EFF_SCALE], eff->workf[EFF_DIST], 0.1f, 0.003f);
				off.x = sTwinrovaPtr->actor.world.pos.x - eff->pos.x;
				off.y = (sTwinrovaPtr->actor.world.pos.y - eff->pos.y) * 0.5f;
				off.z = sTwinrovaPtr->actor.world.pos.z - eff->pos.z;

				if(sTwinrovaPtr->actionFunc != BossTw_TwinrovaStun)
				{
					if((SQ(off.x) + SQ(off.y) + SQ(off.z)) < SQ(60.0f))
					{
						for(j = 0; j < 50; j++)
						{
							spF4.x = sTwinrovaPtr->actor.world.pos.x + Rand_CenteredFloat(35.0f);
							spF4.y = sTwinrovaPtr->actor.world.pos.y + Rand_CenteredFloat(70.0f);
							spF4.z = sTwinrovaPtr->actor.world.pos.z + Rand_CenteredFloat(35.0f);
							spE8.x = Rand_CenteredFloat(20.0f);
							spE8.y = Rand_CenteredFloat(20.0f);
							spE8.z = Rand_CenteredFloat(20.0f);
							spDC.x = 0.0f;
							spDC.y = 0.0f;
							spDC.z = 0.0f;
							BossTw_AddFlameEffect(globalCtx, &spF4, &spE8, &spDC, Rand_ZeroFloat(10.0f) + 25.0f, eff->work[EFF_ARGS]);
						}

						sTwinrovaPtr->twinrovaStun = 1;
						globalCtx->envCtx.unk_D8 = 1.0f;
						eff->type = TWEFF_NONE;
					}
				}
			}
			else if(eff->type == TWEFF_MERGEFLAME)
			{
				sp11C.x = 0.0f;
				sp11C.y = eff->pos.y;
				sp11C.z = eff->workf[EFF_DIST];
				Matrix_RotateY(sTwinrovaPtr->workf[UNK_F9] + eff->workf[EFF_ROLL], MTXMODE_NEW);
				Matrix_MultVec3f(&sp11C, &eff->pos);

				if(eff->work[EFF_UNKS1] != 0)
				{
					eff->alpha -= 60;
					if(eff->alpha <= 0)
					{
						eff->alpha = 0;
						eff->type = TWEFF_NONE;
					}
				}
				else
				{
					eff->alpha += 60;
					if(eff->alpha >= 255)
					{
						eff->alpha = 255;
						eff->work[EFF_UNKS1]++;
					}
				}
			}
			else if(eff->type == TWEFF_SHLD_DEFL)
			{
				eff->work[EFF_UNKS1]++;
				sp11C.x = 0.0f;
				sp11C.y = 0.0f;
				sp11C.z = -eff->workf[EFF_DIST];
				Matrix_RotateY((sShieldHitYaw / 32768.0f) * M_PI, MTXMODE_NEW);
				Matrix_RotateX(-0.2f, MTXMODE_APPLY);
				Matrix_RotateZ(eff->workf[EFF_ROLL], MTXMODE_APPLY);
				Matrix_RotateY(eff->workf[EFF_YAW], MTXMODE_APPLY);
				Matrix_MultVec3f(&sp11C, &eff->pos);
				eff->pos.x += sShieldHitPos.x;
				eff->pos.y += sShieldHitPos.y;
				eff->pos.z += sShieldHitPos.z;

				if(eff->work[EFF_UNKS1] < 10)
				{
					Math_ApproachF(&eff->workf[EFF_DIST], 50.0f, 0.5f, 100.0f);
				}
				else
				{
					Math_ApproachF(&eff->workf[EFF_YAW], 0.0f, 0.5f, 10.0f);
					Math_ApproachF(&eff->workf[EFF_DIST], 1000.0f, 1.0f, 10.0f);
					if(eff->work[EFF_UNKS1] >= 0x10)
					{
						if((eff->work[EFF_UNKS1] == 16) && (sp113 == 0))
						{
							sp113 = 1;
							spD0 = eff->pos;
							if(eff->pos.y > 40.0f)
							{
								spD0.y = 220.0f;
							}
							else
							{
								spD0.y = -50.0f;
							}
							sTwinrovaPtr->groundBlastPos.y = phi_f0 = BossTw_GetFloorY(&spD0);
							if(phi_f0 >= 0.0f)
							{
								if(sTwinrovaPtr->groundBlastPos.y != 35.0f)
								{
									sTwinrovaPtr->groundBlastPos.x = eff->pos.x;
									sTwinrovaPtr->groundBlastPos.z = eff->pos.z;
									BossTw_SpawnGroundBlast(sTwinrovaPtr, globalCtx, eff->work[EFF_ARGS]);
								}
							}
						}
						eff->alpha -= 300;
						if(eff->alpha <= 0)
						{
							eff->alpha = 0;
							eff->type = TWEFF_NONE;
						}
					}
				}

				BossTw_AddFlameEffect(globalCtx, &eff->pos, &sZeroVector, &sZeroVector, 10, eff->work[EFF_ARGS]);
			}
			else if(eff->type == TWEFF_SHLD_HIT)
			{
				eff->work[EFF_UNKS1]++;
				sp11C.x = 0.0f;
				sp11C.y = 0.0f;
				sp11C.z = -eff->workf[EFF_DIST];
				Matrix_RotateY((sShieldHitYaw / 32768.0f) * M_PI, MTXMODE_NEW);
				Matrix_RotateX(-0.2f, MTXMODE_APPLY);
				Matrix_RotateZ(eff->workf[EFF_ROLL], MTXMODE_APPLY);
				Matrix_RotateY(eff->workf[EFF_YAW], MTXMODE_APPLY);
				Matrix_MultVec3f(&sp11C, &eff->pos);
				eff->pos.x += sShieldHitPos.x;
				eff->pos.y += sShieldHitPos.y;
				eff->pos.z += sShieldHitPos.z;

				if(eff->work[EFF_UNKS1] < 5)
				{
					Math_ApproachF(&eff->workf[EFF_DIST], 40.0f, 0.5f, 100.0f);
				}
				else
				{
					Math_ApproachF(&eff->workf[EFF_DIST], 0.0f, 0.2f, 5.0f);
					if(eff->work[EFF_UNKS1] >= 11)
					{
						eff->alpha -= 30;
						if(eff->alpha <= 0)
						{
							eff->alpha = 0;
							eff->type = TWEFF_NONE;
						}
					}
				}

				BossTw_AddFlameEffect(globalCtx, &eff->pos, &sZeroVector, &sZeroVector, 10, eff->work[EFF_ARGS]);
			}
			else if(eff->type == 4)
			{
				if(eff->work[EFF_UNKS1] == 0)
				{
					Math_ApproachF(&eff->workf[EFF_SCALE], eff->workf[EFF_DIST], 0.05f, 1.0f);

					if(eff->frame >= 16)
					{
						eff->alpha -= 10;
						if(eff->alpha <= 0)
						{
							eff->alpha = 0;
							eff->type = TWEFF_NONE;
						}
					}
				}
				else
				{
					Math_ApproachF(&eff->workf[EFF_SCALE], eff->workf[EFF_DIST], 0.1f, 2.0f);
					eff->alpha -= 15;

					if(eff->alpha <= 0)
					{
						eff->alpha = 0;
						eff->type = TWEFF_NONE;
					}
				}
			}
			else if(eff->type == TWEFF_PLYR_FRZ)
			{
				if(eff->work[EFF_ARGS] < eff->frame)
				{
					phi_f0 = 1.0f;

					if(eff->target != NULL || sGroundBlastType == 1)
					{
						phi_f0 *= 3.0f;
					}

					Math_ApproachF(&eff->workf[EFF_SCALE], 0.0f, 1.0f, 0.0005f * phi_f0);

					if(eff->workf[EFF_SCALE] == 0.0f)
					{
						eff->type = TWEFF_NONE;
						if(eff->target == NULL)
						{
							player->stateFlags2 &= ~PLAYER_STATE2_15;
							sFreezeState = 0;
						}
					}
				}
				else
				{
					if(sGroundBlastType == 1)
					{
						eff->frame = 100;
					}
					Math_ApproachF(&eff->workf[EFF_DIST], 0.8f, 0.2f, 0.04f);

					if(eff->target == NULL)
					{
						Math_ApproachF(&eff->workf[EFF_SCALE], 0.012f, 1.0f, 0.002f);
						eff->workf[EFF_ROLL] += eff->workf[EFF_DIST];

						if(eff->workf[EFF_ROLL] >= 0.8f)
						{
							eff->workf[EFF_ROLL] -= 0.8f;
							player->stateFlags2 |= PLAYER_STATE2_15;
						}
						else
						{
							player->stateFlags2 &= ~PLAYER_STATE2_15;
						}

						if((sKotakePtr->workf[UNK_F11] > 10.0f) && (sKotakePtr->workf[UNK_F11] < 200.0f))
						{
							eff->frame = 100;
						}

						if(!(globalCtx->gameplayFrames & 1))
						{
							globalCtx->damagePlayer(globalCtx, -1);
						}
					}
					else
					{
						Math_ApproachF(&eff->workf[EFF_SCALE], 0.042f, 1.0f, 0.002f);
					}

					if((eff->workf[EFF_DIST] > 0.4f) && ((eff->frame & 7) == 0))
					{
						spA6 = Rand_ZeroFloat(17.9f);

						if(eff->target == NULL)
						{
							spC0.x = player->bodyPartsPos[spA6].x + Rand_CenteredFloat(5.0f);
							spC0.y = player->bodyPartsPos[spA6].y + Rand_CenteredFloat(5.0f);
							spC0.z = player->bodyPartsPos[spA6].z + Rand_CenteredFloat(5.0f);
							phi_f22 = 10.0f;
						}
						else
						{
							unk44 = eff->target;
							spC0.x = unk44->world.pos.x + Rand_CenteredFloat(40.0f);
							spC0.y = unk44->world.pos.y + Rand_CenteredFloat(40.0f);
							spC0.z = unk44->world.pos.z + Rand_CenteredFloat(40.0f);
							phi_f22 = 20.0f;
						}

						spB4.x = 0.0f;
						spB4.y = 0.0f;
						spB4.z = 0.0f;
						spA8.x = 0.0f;
						spA8.y = 0.1f;
						spA8.z = 0.0f;

						BossTw_AddDmgCloud(globalCtx, 3, &spC0, &spB4, &spA8, phi_f22 + Rand_ZeroFloat(phi_f22 * 0.5f), 0, 0, 150);
					}
				}
			}
		}
		eff++;
	}
}

void BossTw_InitRand(s32 seed0, s32 seed1, s32 seed2)
{
	sRandSeed0_143 = seed0;
	sRandSeed1_143 = seed1;
	sRandSeed2_143 = seed2;
}

f32 BossTw_RandZeroOne(void)
{
	f32 rand;

	// Wichmann-Hill algorithm
	sRandSeed0_143 = (sRandSeed0_143 * 171) % 30269;
	sRandSeed1_143 = (sRandSeed1_143 * 172) % 30307;
	sRandSeed2_143 = (sRandSeed2_143 * 170) % 30323;

	rand = (sRandSeed0_143 / 30269.0f) + (sRandSeed1_143 / 30307.0f) + (sRandSeed2_143 / 30323.0f);
	while(rand >= 1.0f)
	{
		rand -= 1.0f;
	}

	return fabsf(rand);
}

void BossTw_DrawEffects(GlobalContext* globalCtx)
{
	u8 sp18F = 0;
	s16 i;
	s16 j;
	s32 pad;
	Player* player = GET_PLAYER(globalCtx);
	s16 phi_s4;
	BossTwEffect* currentEffect = (BossTwEffect*)globalCtx->specialEffects;
	BossTwEffect* effectHead;
	GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

	effectHead = currentEffect;

	OPEN_DISPS(gfxCtx, "../z_boss_tw.c", 9592);

	func_80093D84(globalCtx->state.gfxCtx);

	for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
	{
		if(currentEffect->type == 1)
		{
			if(sp18F == 0)
			{
				gSPDisplayList(POLY_XLU_DISP++, object_tw_DL_01A528);
				sp18F++;
			}

			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, currentEffect->color.r, currentEffect->color.g, currentEffect->color.b, currentEffect->alpha);
			Matrix_Translate(currentEffect->pos.x, currentEffect->pos.y, currentEffect->pos.z, MTXMODE_NEW);
			func_800D1FD4(&globalCtx->billboardMtxF);
			Matrix_Scale(currentEffect->workf[EFF_SCALE], currentEffect->workf[EFF_SCALE], 1.0f, MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_tw.c", 9617), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, object_tw_DL_01A5A8);
		}

		currentEffect++;
	}

	sp18F = 0;
	currentEffect = effectHead;

	for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
	{
		if(currentEffect->type == 3)
		{
			if(sp18F == 0)
			{
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A998));
				sp18F++;
			}

			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, currentEffect->alpha);
			gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (currentEffect->frame * 3) & 0x7F, (currentEffect->frame * 15) & 0xFF, 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
			Matrix_Translate(currentEffect->pos.x, currentEffect->pos.y, currentEffect->pos.z, MTXMODE_NEW);
			func_800D1FD4(&globalCtx->billboardMtxF);
			Matrix_Scale(currentEffect->workf[EFF_SCALE], currentEffect->workf[EFF_SCALE], 1.0f, MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_tw.c", 9660), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01AB00));
		}
		currentEffect++;
	}

	sp18F = 0;
	currentEffect = effectHead;

	for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
	{
		if(currentEffect->type == 2)
		{
			if(sp18F == 0)
			{
				gDPPipeSync(POLY_XLU_DISP++);
				gDPSetEnvColor(POLY_XLU_DISP++, 255, 215, 255, 128);
				sp18F++;
			}

			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 200, 20, 0, currentEffect->alpha);
			gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (currentEffect->frame * 3) & 0x7F, (currentEffect->frame * 15) & 0xFF, 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
			Matrix_Translate(currentEffect->pos.x, currentEffect->pos.y, currentEffect->pos.z, MTXMODE_NEW);
			func_800D1FD4(&globalCtx->billboardMtxF);
			Matrix_Scale(currentEffect->workf[EFF_SCALE], currentEffect->workf[EFF_SCALE], 1.0f, MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_tw.c", 9709), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A430));
		}

		currentEffect++;
	}

	sp18F = 0;
	currentEffect = effectHead;

	for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
	{
		if(currentEffect->type == 4)
		{
			if(sp18F == 0)
			{
				sp18F++;
			}

			gSPSegment(POLY_XLU_DISP++, 0xD, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, currentEffect->frame & 0x7F, (currentEffect->frame * 8) & 0xFF, 0x20, 0x40, 1, (currentEffect->frame * -2) & 0x7F, 0, 0x10, 0x10));

			if(currentEffect->work[EFF_ARGS] == 1)
			{
				gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 65, 0, currentEffect->alpha);
				gDPPipeSync(POLY_XLU_DISP++);
				gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 0, 128);
			}
			else
			{
				gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, currentEffect->alpha);
				gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 128);
			}

			Matrix_Translate(currentEffect->pos.x, currentEffect->pos.y, currentEffect->pos.z, MTXMODE_NEW);
			func_800D1FD4(&globalCtx->billboardMtxF);

			if(currentEffect->work[EFF_UNKS1] == 0)
			{
				Matrix_Translate(0.0f, 0.0f, 60.0f, MTXMODE_APPLY);
			}
			else
			{
				Matrix_Translate(0.0f, 0.0f, 0.0f, MTXMODE_APPLY);
			}

			Matrix_RotateZ(currentEffect->workf[EFF_ROLL], MTXMODE_APPLY);
			Matrix_RotateX(M_PI / 2.0f, MTXMODE_APPLY);
			Matrix_Scale(currentEffect->workf[EFF_SCALE], 1.0f, currentEffect->workf[EFF_SCALE], MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_tw.c", 9775), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gDPSetRenderMode(POLY_XLU_DISP++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
			gSPClearGeometryMode(POLY_XLU_DISP++, G_CULL_BACK | G_FOG);
			gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A790));
		}

		currentEffect++;
	}

	sp18F = 0;
	currentEffect = effectHead;

	for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
	{
		Actor* actor;
		Vec3f off;

		if(currentEffect->type == TWEFF_PLYR_FRZ)
		{
			if(sp18F == 0)
			{
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01AA50));
				gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, 255);
				gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
				sp18F++;
				BossTw_InitRand(1, 0x71AC, 0x263A);
			}

			actor = currentEffect->target;
			phi_s4 = actor == NULL ? 70 : 20;

			for(j = 0; j < phi_s4; j++)
			{
				off.x = (BossTw_RandZeroOne() - 0.5f) * 30.0f;
				off.y = currentEffect->workf[EFF_DIST] * j;
				off.z = (BossTw_RandZeroOne() - 0.5f) * 30.0f;

				if(actor != NULL)
				{
					Matrix_Translate(actor->world.pos.x + off.x, actor->world.pos.y + off.y, actor->world.pos.z + off.z, MTXMODE_NEW);
				}
				else
				{
					Matrix_Translate(player->actor.world.pos.x + off.x, player->actor.world.pos.y + off.y, player->actor.world.pos.z + off.z, MTXMODE_NEW);
				}

				Matrix_Scale(currentEffect->workf[EFF_SCALE], currentEffect->workf[EFF_SCALE], currentEffect->workf[EFF_SCALE], MTXMODE_APPLY);
				Matrix_RotateY(BossTw_RandZeroOne() * M_PI, MTXMODE_APPLY);
				Matrix_RotateX((BossTw_RandZeroOne() - 0.5f) * M_PI * 0.5f, MTXMODE_APPLY);
				gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_tw.c", 9855), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01AB00));
			}
		}

		currentEffect++;
	}

	sp18F = 0;
	currentEffect = effectHead;

	for(i = 0; i < ARRAY_COUNT(sTwEffects); i++)
	{
		if(currentEffect->type >= 6)
		{
			if(currentEffect->work[EFF_ARGS] == 0)
			{
				gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, currentEffect->alpha);
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A998));
			}
			else
			{
				gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 200, 20, 0, currentEffect->alpha);
				gDPPipeSync(POLY_XLU_DISP++);
				gDPSetEnvColor(POLY_XLU_DISP++, 255, 215, 255, 128);
			}

			gSPSegment(POLY_XLU_DISP++, 8, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (currentEffect->frame * 3) & 0x7F, (-currentEffect->frame * 15) & 0xFF, 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
			Matrix_Translate(currentEffect->pos.x, currentEffect->pos.y, currentEffect->pos.z, MTXMODE_NEW);
			func_800D1FD4(&globalCtx->billboardMtxF);
			Matrix_Scale(currentEffect->workf[EFF_SCALE], currentEffect->workf[EFF_SCALE], 1.0f, MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_tw.c", 9911), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

			if(currentEffect->work[EFF_ARGS] == 0)
			{
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01AB00));
			}
			else
			{
				gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_tw_DL_01A430));
			}
		}

		currentEffect++;
	}

	CLOSE_DISPS(gfxCtx, "../z_boss_tw.c", 9920);
}

void BossTw_TwinrovaSetupArriveAtTarget(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_TwinrovaArriveAtTarget;
	Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_032BF8, -3.0f);
	pthis->work[CS_TIMER_1] = Rand_ZeroFloat(100.0f);
	pthis->timers[1] = 25;
	pthis->rotateSpeed = 0.0f;
}

void BossTw_TwinrovaArriveAtTarget(BossTw* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	Math_ApproachF(&pthis->actor.world.pos.x, pthis->targetPos.x, 0.1f, fabsf(pthis->actor.velocity.x) * 1.5f);
	Math_ApproachF(&pthis->actor.world.pos.y, pthis->targetPos.y, 0.1f, fabsf(pthis->actor.velocity.y) * 1.5f);
	Math_ApproachF(&pthis->targetPos.y, 380.0f, 1.0f, 2.0f);
	Math_ApproachF(&pthis->actor.world.pos.z, pthis->targetPos.z, 0.1f, fabsf(pthis->actor.velocity.z) * 1.5f);

	if(pthis->timers[1] == 1)
	{
		BossTw_TwinrovaSetupChargeBlast(pthis, globalCtx);
	}

	Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, pthis->rotateSpeed);
	Math_ApproachF(&pthis->rotateSpeed, 4096.0f, 1.0f, 350.0f);
}

void BossTw_TwinrovaSetupChargeBlast(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_TwinrovaChargeBlast;
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_036FBC, -5.0f);
	pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_036FBC);
	pthis->csState1 = 0;
}

void BossTw_TwinrovaChargeBlast(BossTw* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);

	Math_ApproachF(&pthis->actor.world.pos.x, pthis->targetPos.x, 0.03f, fabsf(pthis->actor.velocity.x) * 1.5f);
	Math_ApproachF(&pthis->actor.world.pos.y, pthis->targetPos.y, 0.03f, fabsf(pthis->actor.velocity.y) * 1.5f);
	Math_ApproachF(&pthis->actor.world.pos.z, pthis->targetPos.z, 0.03f, fabsf(pthis->actor.velocity.z) * 1.5f);
	Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 0x1000);

	if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
	{
		if((s8)pthis->actor.colChkInfo.health < 10)
		{
			sTwinrovaBlastType = Rand_ZeroFloat(1.99f);
		}
		else
		{
			if(++sFixedBlatSeq >= 4)
			{
				sFixedBlatSeq = 1;
				sFixedBlastType = !sFixedBlastType;
			}

			sTwinrovaBlastType = sFixedBlastType;
		}

		BossTw_TwinrovaSetupShootBlast(pthis, globalCtx);
	}
}

void BossTw_TwinrovaSetupShootBlast(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_TwinrovaShootBlast;

	if(sTwinrovaBlastType == 0)
	{
		Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_022700, 0.0f);
	}
	else
	{
		Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_023750, 0.0f);
	}

	pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_023750);
}

void BossTw_TwinrovaShootBlast(BossTw* pthis, GlobalContext* globalCtx)
{
	BossTw* twMagic;
	Vec3f* magicSpawnPos;
	s32 magicParams;
	s16 i;

	SkelAnime_Update(&pthis->skelAnime);

	if(Animation_OnFrame(&pthis->skelAnime, 8.0f))
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_THROW_MASIC);
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_YOUNG_SHOOTVC);
	}

	if(Animation_OnFrame(&pthis->skelAnime, 12.0f))
	{
		if(sTwinrovaBlastType != 0)
		{
			magicParams = TW_FIRE_BLAST;
			magicSpawnPos = &pthis->rightScepterPos;
		}
		else
		{
			magicParams = TW_ICE_BLAST;
			magicSpawnPos = &pthis->leftScepterPos;
		}

		twMagic = (BossTw*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_TW, magicSpawnPos->x, magicSpawnPos->y, magicSpawnPos->z, 0, 0, 0, magicParams);

		if(twMagic != NULL)
		{
			twMagic->blastType = magicParams == TW_ICE_BLAST ? 0 : 1;
		}

		sEnvType = twMagic->blastType + 1;

		{
			Vec3f velocity = {0.0f, 0.0f, 0.0f};
			Vec3f accel = {0.0f, 0.0f, 0.0f};

			for(i = 0; i < 100; i++)
			{
				velocity.x = Rand_CenteredFloat(30.0f);
				velocity.y = Rand_CenteredFloat(30.0f);
				velocity.z = Rand_CenteredFloat(30.0f);
				BossTw_AddDotEffect(globalCtx, magicSpawnPos, &velocity, &accel, (s16)Rand_ZeroFloat(2.0f) + 11, twMagic->blastType, 75);
			}
		}
	}

	if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
	{
		BossTw_TwinrovaSetupDoneBlastShoot(pthis, globalCtx);
	}

	Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 0x1000);
}

void BossTw_TwinrovaSetupDoneBlastShoot(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_TwinrovaDoneBlastShoot;
	Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_032BF8, -10.0f);
	pthis->timers[1] = 60;
}

void BossTw_TwinrovaDoneBlastShoot(BossTw* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);

	if(pthis->timers[1] == 0 && D_8094C870 == 0)
	{
		if(sTwinrovaPtr->timers[2] == 0)
		{
			BossTw_TwinrovaSetupFly(pthis, globalCtx);
		}
		else
		{
			BossTw_TwinrovaSetupLaugh(pthis, globalCtx);
		}
	}

	D_8094C870 = 0;
	Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 0x1000);
}

void BossTw_TwinrovaDamage(BossTw* pthis, GlobalContext* globalCtx, u8 damage)
{
	if(pthis->actionFunc != BossTw_TwinrovaStun)
	{
		Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_0338F0, -15.0f);
		pthis->timers[0] = 150;
		pthis->timers[1] = 20;
		pthis->csState1 = 0;
		pthis->actor.velocity.y = 0.0f;
	}
	else
	{
		pthis->work[FOG_TIMER] = 10;
		pthis->work[INVINC_TIMER] = 20;
		Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_024374, -3.0f);
		pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_024374);
		pthis->csState1 = 1;

		if((s8)(pthis->actor.colChkInfo.health -= damage) < 0)
		{
			pthis->actor.colChkInfo.health = 0;
		}

		if((s8)pthis->actor.colChkInfo.health <= 0)
		{
			BossTw_TwinrovaSetupDeathCS(pthis, globalCtx);
			Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_YOUNG_DEAD);
			return;
		}

		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_YOUNG_DAMAGE2);
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_CUTBODY);
	}

	pthis->actionFunc = BossTw_TwinrovaStun;
}

void BossTw_TwinrovaStun(BossTw* pthis, GlobalContext* globalCtx)
{
	s16 cloudType;

	pthis->unk_5F8 = 1;
	pthis->actor.flags |= ACTOR_FLAG_10;

	cloudType = sTwinrovaBlastType == 0 ? 3 : 2;

	if((pthis->work[CS_TIMER_1] % 8) == 0)
	{
		Vec3f pos;
		Vec3f velocity;
		Vec3f accel;
		pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(20.0f);
		pos.y = pthis->actor.world.pos.y + Rand_CenteredFloat(40.0f) + 20;
		pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(20.0f);
		velocity.x = 0.0f;
		velocity.y = 0.0f;
		velocity.z = 0.0f;
		accel.x = 0.0f;
		accel.y = 0.1f;
		accel.z = 0.0f;
		BossTw_AddDmgCloud(globalCtx, cloudType, &pos, &velocity, &accel, Rand_ZeroFloat(5.0f) + 10.0f, 0, 0, 150);
	}

	SkelAnime_Update(&pthis->skelAnime);
	pthis->work[UNK_S8] += 20;

	if(pthis->work[UNK_S8] > 255)
	{
		pthis->work[UNK_S8] = 255;
	}

	Math_ApproachF(&pthis->workf[UNK_F12], 0.0f, 1.0f, 0.05f);
	pthis->actor.world.pos.y += pthis->actor.velocity.y;
	Math_ApproachF(&pthis->actor.velocity.y, -5.0f, 1.0f, 0.5f);
	pthis->actor.world.pos.y -= 30.0f;
	Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 4);
	pthis->actor.world.pos.y += 30.0f;

	if(pthis->csState1 == 0)
	{
		if(pthis->timers[1] == 0)
		{
			pthis->csState1 = 1;
			pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_0343B4);
			Animation_Change(&pthis->skelAnime, &object_tw_Anim_0343B4, 1.0f, 0.0f, pthis->workf[ANIM_SW_TGT], 3, 0.0f);
		}
	}
	else if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
	{
		pthis->workf[ANIM_SW_TGT] = 1000.0f;
		Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_035030, 0.0f);
	}

	if(pthis->actor.bgCheckFlags & BG_STATE_0)
	{
		pthis->actor.velocity.y = 0.0f;
	}

	if(pthis->timers[0] == 0)
	{
		BossTw_TwinrovaSetupGetUp(pthis, globalCtx);
	}
}

void BossTw_TwinrovaSetupGetUp(BossTw* pthis, GlobalContext* globalCtx)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_035988, 0.0f);
	pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_035988);
	pthis->actionFunc = BossTw_TwinrovaGetUp;
	pthis->timers[0] = 50;
}

void BossTw_TwinrovaGetUp(BossTw* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	Math_ApproachF(&pthis->actor.world.pos.y, pthis->targetPos.y, 0.05f, 5.0f);

	if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
	{
		pthis->workf[ANIM_SW_TGT] = 1000.0f;
		Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_032BF8, 0.0f);
	}

	if(pthis->timers[0] == 0)
	{
		BossTw_TwinrovaSetupFly(pthis, globalCtx);
	}
}

void BossTw_TwinrovaSetupFly(BossTw* pthis, GlobalContext* globalCtx)
{
	f32 xDiff;
	f32 zDiff;
	f32 yDiff;
	f32 xzDist;
	Player* player = GET_PLAYER(globalCtx);

	do
	{
		pthis->work[TW_PLLR_IDX] += (s16)(((s16)Rand_ZeroFloat(2.99f)) + 1);
		pthis->work[TW_PLLR_IDX] %= 4;
		pthis->targetPos = sTwinrovaPillarPos[pthis->work[TW_PLLR_IDX]];
		xDiff = pthis->targetPos.x - player->actor.world.pos.x;
		zDiff = pthis->targetPos.z - player->actor.world.pos.z;
		xzDist = SQ(xDiff) + SQ(zDiff);
	} while(!(xzDist > SQ(300.0f)));

	pthis->targetPos.y = 480.0f;
	xDiff = pthis->targetPos.x - pthis->actor.world.pos.x;
	yDiff = pthis->targetPos.y - pthis->actor.world.pos.y;
	zDiff = pthis->targetPos.z - pthis->actor.world.pos.z;
	pthis->actionFunc = BossTw_TwinrovaFly;
	pthis->rotateSpeed = 0.0f;
	pthis->actor.speedXZ = 0.0f;
	pthis->actor.world.rot.y = Math_FAtan2F(xDiff, zDiff) * (32768 / M_PI);
	xzDist = sqrtf(SQ(xDiff) + SQ(zDiff));
	pthis->actor.world.rot.x = Math_FAtan2F(yDiff, xzDist) * (32768 / M_PI);
	Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_032BF8, -10.0f);
}

void BossTw_TwinrovaFly(BossTw* pthis, GlobalContext* globalCtx)
{
	f32 xDiff;
	f32 yDiff;
	f32 zDiff;
	s32 pad;
	f32 yaw;
	f32 xzDist;

	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_FLY - SFX_FLAG);
	SkelAnime_Update(&pthis->skelAnime);
	xDiff = pthis->targetPos.x - pthis->actor.world.pos.x;
	yDiff = pthis->targetPos.y - pthis->actor.world.pos.y;
	zDiff = pthis->targetPos.z - pthis->actor.world.pos.z;
	// Convert from radians to degrees, then degrees to binary angle
	yaw = (s16)(Math_FAtan2F(xDiff, zDiff) * ((180.0f / M_PI) * (65536.0f / 360.0f)));
	xzDist = sqrtf(SQ(xDiff) + SQ(zDiff));
	Math_ApproachS(&pthis->actor.world.rot.x, (f32)(s16)(Math_FAtan2F(yDiff, xzDist) * ((180.0f / M_PI) * (65536.0f / 360.0f))), 0xA, pthis->rotateSpeed);
	Math_ApproachS(&pthis->actor.world.rot.y, yaw, 0xA, pthis->rotateSpeed);
	Math_ApproachS(&pthis->actor.shape.rot.y, yaw, 0xA, pthis->rotateSpeed);
	Math_ApproachF(&pthis->rotateSpeed, 2000.0f, 1.0f, 100.0f);
	Math_ApproachF(&pthis->actor.speedXZ, 30.0f, 1.0f, 2.0f);
	func_8002D908(&pthis->actor);
	Math_ApproachF(&pthis->actor.world.pos.x, pthis->targetPos.x, 0.1f, fabsf(pthis->actor.velocity.x) * 1.5f);
	Math_ApproachF(&pthis->actor.world.pos.y, pthis->targetPos.y, 0.1f, fabsf(pthis->actor.velocity.y) * 1.5f);
	Math_ApproachF(&pthis->targetPos.y, 380.0f, 1.0f, 2.0f);
	Math_ApproachF(&pthis->actor.world.pos.z, pthis->targetPos.z, 0.1f, fabsf(pthis->actor.velocity.z) * 1.5f);

	if(xzDist < 200.0f)
	{
		BossTw_TwinrovaSetupArriveAtTarget(pthis, globalCtx);
	}
}

void BossTw_TwinrovaSetupSpin(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_TwinrovaSpin;
	Animation_MorphToLoop(&pthis->skelAnime, &object_tw_Anim_032BF8, 0.0f);
	pthis->timers[0] = 20;
	pthis->actor.speedXZ = 0.0f;
}

void BossTw_TwinrovaSpin(BossTw* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	if(pthis->timers[0] != 0)
	{
		pthis->collider.base.colType = COLTYPE_METAL;
		pthis->actor.shape.rot.y -= 0x3000;

		if((pthis->timers[0] % 4) == 0)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_ROLL);
		}
	}
	else
	{
		BossTw_TwinrovaSetupFly(pthis, globalCtx);
	}
}

void BossTw_TwinrovaSetupLaugh(BossTw* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = BossTw_TwinrovaLaugh;
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_tw_Anim_03A2D0, 0.0f);
	pthis->workf[ANIM_SW_TGT] = Animation_GetLastFrame(&object_tw_Anim_03A2D0);
	pthis->actor.speedXZ = 0.0f;
}

void BossTw_TwinrovaLaugh(BossTw* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);

	if(Animation_OnFrame(&pthis->skelAnime, 10.0f))
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_YOUNG_LAUGH);
	}

	if(Animation_OnFrame(&pthis->skelAnime, pthis->workf[ANIM_SW_TGT]))
	{
		BossTw_TwinrovaSetupFly(pthis, globalCtx);
	}
}

void BossTw_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	D_8094A944_143 = {0.0f, 0.0f, 0.0f};

	D_8094A950_143 = {0.0f, 2000.0f, -2000.0f};

	D_8094A9A4_143 = {0.0f, 200.0f, 2000.0f};

	D_8094A9BC_143 = {0.0f, 0.0f, 0.0f};

	D_8094A9C8_143 = {0.0f, 2000.0f, -2000.0f};

	D_8094A9D4_143 = {13000.0f, 0.0f, 0.0f};

	D_8094A9E0_143 = {13000.0f, 0.0f, 0.0f};

	D_8094A9EC_143 = {0.0f, 200.0f, 2000.0f};

	sRandSeed0_143 = 0;

	sRandSeed1_143 = 0;

	sRandSeed2_143 = 0;

	Boss_Tw_InitVars = {
	    ACTOR_BOSS_TW, ACTORCAT_BOSS, FLAGS, OBJECT_TW, sizeof(BossTw), (ActorFunc)BossTw_Init, (ActorFunc)BossTw_Destroy, (ActorFunc)BossTw_Update, (ActorFunc)BossTw_Draw, (ActorFunc)BossTw_Reset,
	};

	D_8094A7D0 = {0.0f, 0.0f, 1000.0f};

	sZeroVector = {0.0f, 0.0f, 0.0f};

	sCylinderInitBlasts = {
	    {
		COLTYPE_NONE,
		AT_ON | AT_TYPE_ALL,
		AC_ON | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_PLAYER,
		OC2_TYPE_1,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK0,
		{0xFFCFFFFF, 0x00, 0x30},
		{0x00100000, 0x00, 0x00},
		TOUCH_ON | TOUCH_SFX_NORMAL,
		BUMP_ON,
		OCELEM_ON,
	    },
	    {25, 35, -17, {0, 0, 0}},
	};

	sCylinderInitKoumeKotake = {
	    {
		COLTYPE_HIT3,
		AT_ON | AT_TYPE_ENEMY,
		AC_ON | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_PLAYER,
		OC2_TYPE_1,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK0,
		{0xFFCFFFFF, 0x00, 0x20},
		{0xFFCDFFFE, 0x00, 0x00},
		TOUCH_ON | TOUCH_SFX_NORMAL,
		BUMP_ON,
		OCELEM_ON,
	    },
	    {45, 120, -30, {0, 0, 0}},
	};

	sCylinderInitTwinrova = {
	    {
		COLTYPE_HIT3,
		AT_ON | AT_TYPE_ENEMY,
		AC_ON | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_ALL,
		OC2_TYPE_1,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK0,
		{0xFFCFFFFF, 0x00, 0x20},
		{0xFFCDFFFE, 0x00, 0x00},
		TOUCH_ON | TOUCH_SFX_NORMAL,
		BUMP_ON | BUMP_HOOKABLE,
		OCELEM_ON,
	    },
	    {45, 120, -30, {0, 0, 0}},
	};

	sTwInitalized = false;

	sEnvType = 0;

	sGroundBlastType = 0;

	sKotakePtr = 0;

	sKoumePtr = 0;

	sTwinrovaPtr = 0;

	sShieldFireCharge = 0;

	sShieldIceCharge = 0;

	D_8094C854 = {0};

	D_8094C858 = {0};

	sTwinrovaBlastType = 0;

	sFixedBlastType = 0;

	sFixedBlatSeq = 0;

	sFreezeState = 0;

	sShieldHitPos = {0, 0, 0};

	sShieldHitYaw = 0;

	sBeamDivertTimer = 0;

	D_8094C86F = 0;

	D_8094C870 = 0;

	D_8094C872 = 0;

	D_8094C874 = 0;

	D_8094C876 = 0;

	D_8094C878 = 0;

	D_8094C87A = 0;

	D_8094C87C = 0;

	D_8094C87E = 0;
}
