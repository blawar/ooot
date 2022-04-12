#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BOSS_VA_Z_BOSS_VA_C
#include "actor_common.h"
/*
 * File: z_boss_va.c
 * Overlay: ovl_Boss_Va
 * Description: Barinade
 */

#include "framerate.h"
#include "overlays/actors/ovl_En_Boom/z_en_boom.h"
#include "z_boss_va.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"
#include "def/random.h"
#include "def/sys_math.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_demo.h"
#include "def/z_eff_ss_dead.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_bv/object_bv.h"

#define FLAGS (ACTOR_FLAG_VISIBLE | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

#define GET_BODY(pthis) ((BossVa*)(pthis)->actor.parent)
#define vaGorePulse offset.x
#define vaGorePulseRate offset.y
#define vaBariUnused headRot
#define vaCamRotMod headRot.x
#define vaBodySpinRate headRot.y

#define PHASE_2 3
#define PHASE_3 9
#define PHASE_4 15
#define PHASE_DEATH 18

void BossVa_Init(Actor* thisx, GlobalContext* globalCtx);
void BossVa_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BossVa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BossVa_Update(Actor* thisx, GlobalContext* globalCtx);
void BossVa_Draw(Actor* thisx, GlobalContext* globalCtx);

void BossVa_UpdateEffects(GlobalContext* globalCtx);
void BossVa_DrawEffects(BossVaEffect* effect, GlobalContext* globalCtx);
void BossVa_DrawDoor(GlobalContext* globalCtx, s16 scale);

void BossVa_SetupIntro(BossVa* pthis);
void BossVa_SetupBodyPhase1(BossVa* pthis);
void BossVa_SetupBodyPhase2(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupBodyPhase3(BossVa* pthis);
void BossVa_SetupBodyPhase4(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupBodyDeath(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_SetupSupportIntro(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupSupportAttached(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupSupportCut(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_SetupZapperIntro(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupZapperAttack(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupZapperEnraged(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupZapperDamaged(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupZapperHold(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_SetupStump(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_SetupDoor(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_SetupBariIntro(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupBariPhase2Attack(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupBariPhase3Attack(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupBariPhase3Stunned(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SetupBariDeath(BossVa* pthis);

void BossVa_BodyIntro(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_BodyPhase1(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_BodyPhase2(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_BodyPhase3(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_BodyPhase4(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_BodyDeath(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_SupportIntro(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SupportAttached(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_SupportCut(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_ZapperIntro(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_ZapperAttack(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_ZapperEnraged(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_ZapperDamaged(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_ZapperHold(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_ZapperDeath(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_Stump(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_Door(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_BariIntro(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_BariPhase3Attack(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_BariPhase2Attack(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_BariPhase3Stunned(BossVa* pthis, GlobalContext* globalCtx);
void BossVa_BariDeath(BossVa* pthis, GlobalContext* globalCtx);

void BossVa_SpawnBloodSplatter(GlobalContext* globalCtx, BossVaEffect* effect, Vec3f* pos, s16 yaw, s16 scale);
void BossVa_SpawnGore(GlobalContext* globalCtx, BossVaEffect* effect, Vec3f* pos, s16 yaw, s16 scale);
void BossVa_SpawnSpark(GlobalContext* globalCtx, BossVaEffect* effect, BossVa* pthis, Vec3f* offset, s16 scale, u8 mode);
void BossVa_SpawnZapperCharge(GlobalContext* globalCtx, BossVaEffect* effect, BossVa* pthis, Vec3f* pos, Vec3s* rot, s16 scale, u8 mode);
void BossVa_SpawnTumor(GlobalContext* globalCtx, BossVaEffect* effect, BossVa* pthis, Vec3f* offset, s16 scale, u8 mode);
void BossVa_SpawnSparkBall(GlobalContext* globalCtx, BossVaEffect* effect, BossVa* pthis, Vec3f* offset, s16 scale, u8 mode);
void BossVa_SpawnBloodDroplets(GlobalContext* globalCtx, BossVaEffect* effect, Vec3f* pos, s16 scale, s16 phase, s16 yaw);
void BossVa_Tumor(GlobalContext* globalCtx, BossVa* pthis, s32 count, s16 scale, f32 xzSpread, f32 ySpread, u8 mode, f32 range, u8 fixed);

static void* sSparkBallTex_206[] = {
    gBarinadeSparkBall1Tex, gBarinadeSparkBall2Tex, gBarinadeSparkBall3Tex, gBarinadeSparkBall4Tex, gBarinadeSparkBall5Tex, gBarinadeSparkBall6Tex, gBarinadeSparkBall7Tex, gBarinadeSparkBall8Tex,
};

static Gfx* doorPieceDispList_214[] = {
    gBarinadeDoorPiece1DL, gBarinadeDoorPiece2DL, gBarinadeDoorPiece3DL, gBarinadeDoorPiece4DL, gBarinadeDoorPiece5DL, gBarinadeDoorPiece6DL, gBarinadeDoorPiece7DL, gBarinadeDoorPiece8DL,
};

static s16 doorPieceLength_214[] = {836, 900, 836, 1016, 800, 1016, 836, 900};

ActorInit Boss_Va_InitVars = {
    ACTOR_BOSS_VA, ACTORCAT_BOSS, FLAGS, OBJECT_BV, sizeof(BossVa), (ActorFunc)BossVa_Init, (ActorFunc)BossVa_Destroy, (ActorFunc)BossVa_Update, (ActorFunc)BossVa_Draw, (ActorFunc)BossVa_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
	COLTYPE_NONE,
	AT_ON | AT_TYPE_ENEMY,
	AC_ON | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_ALL,
	OC2_TYPE_2,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK0,
	{0xFFCFFFEF, 0x03, 0x08},
	{0x00000010, 0x00, 0x00},
	TOUCH_ON | TOUCH_SFX_NORMAL,
	BUMP_ON,
	OCELEM_ON,
    },
    {85, 120, 0, {0, 0, 0}},
};

static ColliderJntSphElementInit sJntSphElementsInitSupport[1] = {
    {
	{
	    ELEMTYPE_UNK0,
	    {0x00000000, 0x00, 0x00},
	    {0x00000010, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON,
	    OCELEM_NONE,
	},
	{0, {{0, 0, 0}, 25}, 100},
    },
};

static ColliderJntSphInit sJntSphInitSupport = {
    {
	COLTYPE_HIT6,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_NONE,
	OC2_TYPE_1,
	COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(sJntSphElementsInitSupport),
    sJntSphElementsInitSupport,
};

static ColliderJntSphElementInit sJntSphElementsInitBari[1] = {
    {
	{
	    ELEMTYPE_UNK0,
	    {0xFFCFFFFF, 0x03, 0x04},
	    {0xFFCFFFFF, 0x00, 0x00},
	    TOUCH_ON | TOUCH_SFX_NORMAL,
	    BUMP_ON,
	    OCELEM_NONE,
	},
	{0, {{0, 0, 0}, 30}, 100},
    },
};

static ColliderJntSphInit sJntSphInitBari = {
    {
	COLTYPE_NONE,
	AT_ON | AT_TYPE_ENEMY,
	AC_ON | AC_TYPE_PLAYER,
	OC1_NONE,
	OC2_TYPE_1,
	COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(sJntSphElementsInitBari),
    sJntSphElementsInitBari,
};

static ColliderQuadInit sQuadInit = {
    {
	COLTYPE_METAL,
	AT_ON | AT_TYPE_ENEMY,
	AC_ON | AC_TYPE_PLAYER,
	OC1_NONE,
	OC2_NONE,
	COLSHAPE_QUAD,
    },
    {
	ELEMTYPE_UNK0,
	{0x20000000, 0x03, 0x04},
	{0x00000010, 0x00, 0x00},
	TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
	BUMP_ON,
	OCELEM_NONE,
    },
    {{{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}},
};

static Vec3f sInitPosOffsets[] = {
    {0.0f, 175.35f, 0.0f},	 // Support 1
    {0.0f, 175.35f, 0.0f},	 // Support 2
    {0.0f, 175.35f, 0.0f},	 // Support 3
    {120.0f, 103.425f, -67.0f},	 // Zapper 1
    {0.0f, 103.425f, 140.0f},	 // Zapper 2
    {-120.0f, 103.425f, -70.0f}, // Zapper 3
    {-2.0f, 16.0f, 50.0f},	 // Upper Bari 1
    {48.0f, 16.0f, 15.0f},	 // Upper Bari 2
    {25.0f, 16.0f, -36.0f},	 // Upper Bari 3
    {-29.0f, 16.0f, -36.0f},	 // Upper Bari 4
    {-63.0f, 16.0f, 22.0f},	 // Upper Bari 5
    {0.0f, -10.0f, -64.0f},	 // Lower Bari 1
    {63.0f, -10.0f, -22.0f},	 // Lower Bari 2
    {35.0f, -10.0f, 46.0f},	 // Lower Bari 3
    {-36.0f, -10.0f, 46.0f},	 // Lower Bari 4
    {-49.0f, -10.0f, -17.0f},	 // Lower Bari 5
    {0.0f, 160.0f, 370.0f},	 // Upper Bari 1 CS
    {65.0f, 35.0f, 370.0f},	 // Upper Bari 2 CS
    {80.0f, 70.0f, -130.0f},	 // Upper Bari 3 CS
    {-160.0f, 100.0f, -130.0f},	 // Upper Bari 4 CS
    {-150.0f, 130.0f, 0.0f},	 // Upper Bari 5 CS
    {230.0f, 0.0f, 0.0f},	 // Lower Bari 1 CS
    {60.0f, 140.0f, 0.0f},	 // Lower Bari 2 CS
    {0.0f, 40.0f, 270.0f},	 // Lower Bari 3 CS
    {-100.0f, 10.0f, 200.0f},	 // Lower Bari 4 CS
    {-90.0f, 70.0f, -310.0f},	 // Lower Bari 5 CS
};

static Vec3s sInitRot[] = {
    {0x1FFE, 0x0000, 0x0000}, {0x1FFE, 0x5550, 0x0000}, {0x1FFE, 0xAAB0, 0x0000}, {0xD558, 0x5550, 0x0000}, {0xD558, 0x0000, 0x0000}, {0xD558, 0xAAB0, 0x0000}, {0x2AA8, 0xFCCC, 0x0000}, {0x2AA8, 0x3330, 0x0000},
    {0x2AA8, 0x6660, 0x0000}, {0x2AA8, 0x99A0, 0x0000}, {0x2AA8, 0xCCD0, 0x0000}, {0x4C98, 0x81D0, 0x0000}, {0x4C98, 0x4F70, 0x0000}, {0x4C98, 0x1758, 0x0000}, {0x4C98, 0xE8A8, 0x0000}, {0x4C98, 0xB648, 0x0000},
};

static Vec3f sWarpPos[] = {
    {10.0f, 0.0f, 30.0f},
    {260.0f, 0.0f, -470.0f},
    {-240.0f, 0.0f, -470.0f},
};

static DamageTable sDamageTable[] = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x1),
    /* Normal arrow  */ DMG_ENTRY(2, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(2, 0x0),
    /* Ice arrow     */ DMG_ENTRY(2, 0x0),
    /* Light arrow   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0xE),
    /* Ice magic     */ DMG_ENTRY(0, 0x6),
    /* Light magic   */ DMG_ENTRY(0, 0xD),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
    /* Giant spin    */ DMG_ENTRY(4, 0x0),
    /* Master spin   */ DMG_ENTRY(2, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
    /* Giant jump    */ DMG_ENTRY(8, 0x0),
    /* Master jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static Vec3f sZeroVec = {0.0f, 0.0f, 0.0f};
static u8 sKillBari = 0;
static u8 sBodyBari[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static s16 sCsCamera = 0;

static BossVaEffect sVaEffects[400];
static u8 sBodyState;
static u8 sFightPhase;
static s8 sCsState;
static Vec3f sCameraEye;
static Vec3f sCameraAt;
static Vec3f sCameraNextEye;
static Vec3f sCameraNextAt;
static Vec3f sCameraEyeMaxVel;
static Vec3f sCameraAtMaxVel;
static s16 sDoorState;
static u8 sPhase3StopMoving;
static Vec3s sZapperRot;
static u16 sPhase2Timer;
static s8 sPhase4HP;

void BossVa_SetupAction(BossVa* pthis, BossVaActionFunc func)
{
	pthis->actionFunc = func;
}

void BossVa_AttachToBody(BossVa* pthis)
{
	BossVa* vaBody = GET_BODY(pthis);

	Matrix_Translate(vaBody->actor.world.pos.x, vaBody->actor.world.pos.y, vaBody->actor.world.pos.z, MTXMODE_NEW);
	Matrix_RotateZYX(vaBody->actor.shape.rot.x, 0, vaBody->actor.shape.rot.z, MTXMODE_APPLY);
	Matrix_MultVec3f(&sInitPosOffsets[pthis->actor.params], &pthis->actor.world.pos);

	switch(pthis->actor.params)
	{
		case BOSSVA_SUPPORT_1:
		case BOSSVA_SUPPORT_2:
		case BOSSVA_SUPPORT_3:
			if(!pthis->onCeiling)
			{
				pthis->actor.shape.rot.x = sInitRot[pthis->actor.params].x + vaBody->actor.shape.rot.x;
				pthis->actor.shape.rot.y = sInitRot[pthis->actor.params].y;
				pthis->actor.shape.rot.z = sInitRot[pthis->actor.params].z + vaBody->actor.shape.rot.z;
			}
			break;

		case BOSSVA_ZAPPER_1:
		case BOSSVA_ZAPPER_2:
		case BOSSVA_ZAPPER_3:
			pthis->actor.shape.rot.y = sInitRot[pthis->actor.params].y;
			pthis->actor.shape.rot.x = (sInitRot[pthis->actor.params].x + (s16)(Math_CosS(sInitRot[pthis->actor.params].y) * vaBody->actor.shape.rot.x)) - (s16)(Math_SinS(sInitRot[pthis->actor.params].y) * vaBody->actor.shape.rot.z);
			pthis->actor.shape.rot.z = (s16)(Math_CosS(sInitRot[pthis->actor.params].y) * vaBody->actor.shape.rot.z) + (sInitRot[pthis->actor.params].z + (s16)(Math_SinS(sInitRot[pthis->actor.params].y) * vaBody->actor.shape.rot.x));
			break;
	}

	pthis->actor.world.rot = pthis->actor.shape.rot;
	pthis->actor.shape.yOffset = GET_BODY(pthis)->actor.shape.yOffset;
}

void BossVa_BloodDroplets(GlobalContext* globalCtx, Vec3f* pos, s16 phase, s16 yaw)
{
	s32 i;
	Vec3f spawnPos;

	for(i = 2; i > 0; i--)
	{
		spawnPos.x = Rand_CenteredFloat(10.0f) + pos->x;
		spawnPos.y = pos->y - (Rand_ZeroOne() * 15.0f);
		spawnPos.z = Rand_CenteredFloat(10.0f) + pos->z;
		BossVa_SpawnBloodDroplets(globalCtx, sVaEffects, &spawnPos, 65, phase, yaw);
	}
}

void BossVa_BloodSplatter(GlobalContext* globalCtx, BossVaEffect* src, s16 yaw, s16 scale, s32 count)
{
	s32 i;
	Vec3f pos;

	for(i = count; i > 0; i--)
	{
		pos.x = Rand_CenteredFloat(10.0f) + src->pos.x;
		pos.y = src->pos.y - (Rand_ZeroOne() * 15.0f);
		pos.z = Rand_CenteredFloat(10.0f) + src->pos.z;
		BossVa_SpawnBloodSplatter(globalCtx, sVaEffects, &pos, (s16)Rand_CenteredFloat(0x6590) + yaw, scale);
	}
}

void BossVa_Gore(GlobalContext* globalCtx, BossVaEffect* src, s16 yaw, s16 scale)
{
	s32 i;
	Vec3f pos;

	for(i = (sCsState <= DEATH_SHELL_BURST) ? 2 : 1; i > 0; i--)
	{
		pos.x = Rand_CenteredFloat(10.0f) + src->pos.x;
		pos.y = Rand_CenteredFloat(10.0f) + src->pos.y;
		pos.z = Rand_CenteredFloat(10.0f) + src->pos.z;
		BossVa_SpawnGore(globalCtx, sVaEffects, &pos, (s16)Rand_CenteredFloat(0x6590) + yaw, scale);
	}
}

void BossVa_Spark(GlobalContext* globalCtx, BossVa* pthis, s32 count, s16 scale, f32 xzSpread, f32 ySpread, u8 mode, f32 range, u8 fixed)
{
	s32 i;
	s16 index;
	Vec3f offset;

	for(i = count; i > 0; i--)
	{
		if(!fixed)
		{
			index = Rand_ZeroOne() * (range - 0.6f);
		}
		else
		{
			index = range - 0.6f;
		}
		offset.x = Rand_CenteredFloat(xzSpread) + pthis->effectPos[index].x - pthis->actor.world.pos.x;
		offset.y = Rand_CenteredFloat(ySpread) + pthis->effectPos[index].y - pthis->actor.world.pos.y;
		offset.z = Rand_CenteredFloat(xzSpread) + pthis->effectPos[index].z - pthis->actor.world.pos.z;
		BossVa_SpawnSpark(globalCtx, sVaEffects, pthis, &offset, scale, mode);
	}
}

void BossVa_Tumor(GlobalContext* globalCtx, BossVa* pthis, s32 count, s16 scale, f32 xzSpread, f32 ySpread, u8 mode, f32 range, u8 fixed)
{
	s16 index;
	s32 i;
	Vec3f offset;

	for(i = count; i > 0; i--)
	{
		if(!fixed)
		{
			index = Rand_ZeroOne() * (range - 0.6f);
		}
		else
		{
			index = range - 0.6f;
		}

		offset.x = Rand_CenteredFloat(xzSpread) + pthis->effectPos[index].x - pthis->actor.world.pos.x;
		offset.y = Rand_CenteredFloat(ySpread) + pthis->effectPos[index].y - pthis->actor.world.pos.y;
		offset.z = Rand_CenteredFloat(xzSpread) + pthis->effectPos[index].z - pthis->actor.world.pos.z;
		BossVa_SpawnTumor(globalCtx, sVaEffects, pthis, &offset, scale, mode);
	}
}

void BossVa_SetSparkEnv(GlobalContext* globalCtx)
{
	globalCtx->envCtx.adjAmbientColor[0] = 0xA;
	globalCtx->envCtx.adjAmbientColor[1] = 0xA;
	globalCtx->envCtx.adjAmbientColor[2] = 0xA;
	globalCtx->envCtx.adjLight1Color[0] = 0x73;
	globalCtx->envCtx.adjLight1Color[1] = 0x41;
	globalCtx->envCtx.adjLight1Color[2] = 0x64;
	globalCtx->envCtx.adjFogColor[0] = 0x78;
	globalCtx->envCtx.adjFogColor[1] = 0x78;
	globalCtx->envCtx.adjFogColor[2] = 0x46;
}

void BossVa_SetDeathEnv(GlobalContext* globalCtx)
{
	globalCtx->envCtx.adjFogColor[0] = 0xDC;
	globalCtx->envCtx.adjFogColor[1] = 0xDC;
	globalCtx->envCtx.adjFogColor[2] = 0x96;
	globalCtx->envCtx.adjFogNear = -0x3E8;
	globalCtx->envCtx.adjFogFar = -0x384;
	globalCtx->envCtx.adjAmbientColor[0] = 0xC8;
	globalCtx->envCtx.adjAmbientColor[1] = 0xC8;
	globalCtx->envCtx.adjAmbientColor[2] = 0xC8;
	globalCtx->envCtx.adjLight1Color[0] = 0xD7;
	globalCtx->envCtx.adjLight1Color[1] = 0xA5;
	globalCtx->envCtx.adjLight1Color[2] = 0xC8;
	globalCtx->envCtx.screenFillColor[0] = 0xDC;
	globalCtx->envCtx.screenFillColor[1] = 0xDC;
	globalCtx->envCtx.screenFillColor[2] = 0x96;
	globalCtx->envCtx.screenFillColor[3] = 0x64;
}

EnBoom* BossVa_FindBoomerang(GlobalContext* globalCtx)
{
	Actor* actorIt = globalCtx->actorCtx.actorLists[ACTORCAT_MISC].head;

	while(actorIt != NULL)
	{
		if(actorIt->id != ACTOR_EN_BOOM)
		{
			actorIt = actorIt->next;
			continue;
		}
		return (EnBoom*)actorIt;
	}
	return NULL;
}

void BossVa_KillBari(BossVa* pthis, GlobalContext* globalCtx)
{
	s32 i;
	s16 scale;
	Vec3f pos;
	Vec3f velocity = {0.0f, 0.0f, 0.0f};
	Vec3f accel = {0.0f, 0.0f, 0.0f};

	for(i = 7; i >= 0; i--)
	{
		pos.x = Rand_CenteredFloat(60.0f) + pthis->actor.world.pos.x;
		pos.y = Rand_CenteredFloat(50.0f) + (pthis->actor.world.pos.y + (pthis->actor.shape.yOffset * pthis->actor.scale.y));
		pos.z = Rand_CenteredFloat(60.0f) + pthis->actor.world.pos.z;
		velocity.y = Rand_ZeroOne() + 1.0f;
		scale = Rand_S16Offset(80, 100);
		if(Rand_ZeroOne() < 0.7f)
		{
			EffectSsDtBubble_SpawnColorProfile(globalCtx, &pos, &velocity, &accel, scale, 25, 2, 1);
		}
		else
		{
			EffectSsDtBubble_SpawnColorProfile(globalCtx, &pos, &velocity, &accel, scale, 25, 0, 1);
		}
	}

	sFightPhase++;
	BossVa_SetupBariDeath(pthis);
}

void BossVa_Init(Actor* thisx, GlobalContext* globalCtx2)
{
	GlobalContext* globalCtx = globalCtx2;
	BossVa* pthis = (BossVa*)thisx;
	s32 i;
	s16 warpId;

	Actor_SetScale(&pthis->actor, 0.1f);
	pthis->actor.targetMode = 5;
	pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;

	switch(pthis->actor.params)
	{
		case BOSSVA_BODY:
			SkelAnime_Init(globalCtx, &pthis->skelAnime, &gBarinadeBodySkel, &gBarinadeBodyAnim, NULL, NULL, 0);
			pthis->actor.flags |= ACTOR_FLAG_24;
			break;
		case BOSSVA_SUPPORT_1:
		case BOSSVA_SUPPORT_2:
		case BOSSVA_SUPPORT_3:
			SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBarinadeSupportSkel, &gBarinadeSupportAttachedAnim, NULL, NULL, 0);
			break;
		case BOSSVA_ZAPPER_1:
		case BOSSVA_ZAPPER_2:
		case BOSSVA_ZAPPER_3:
			SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBarinadeZapperSkel, &gBarinadeZapperIdleAnim, NULL, NULL, 0);
			break;
		case BOSSVA_STUMP_1:
		case BOSSVA_STUMP_2:
		case BOSSVA_STUMP_3:
			SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBarinadeStumpSkel, &gBarinadeStumpAnim, NULL, NULL, 0);
			break;
		default:
			pthis->actor.flags |= ACTOR_FLAG_24;
			SkelAnime_Init(globalCtx, &pthis->skelAnime, &gBarinadeBariSkel, &gBarinadeBariAnim, NULL, NULL, 0);
			pthis->actor.shape.yOffset = 400.0f;
			break;
		case BOSSVA_DOOR:
			break;
	}

	pthis->actor.focus.pos = pthis->actor.world.pos;
	pthis->onCeiling = false;
	pthis->actor.naviEnemyId = 0x14;

	switch(pthis->actor.params)
	{
		case BOSSVA_BODY:
			Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_VA, 0.0f, 80.0f, 400.0f, 0, 0, 0, BOSSVA_DOOR);
			if(Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num))
			{
				warpId = ACTOR_EN_RU1;
				if(gSaveContext.eventChkInf[3] & 0x80)
				{
					warpId = ACTOR_DOOR_WARP1;
				}
				Actor_Spawn(&globalCtx->actorCtx, globalCtx, warpId, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0,
					    0); //! params could be WARP_DUNGEON_CHILD however pthis can also spawn Ru1
				Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, pthis->actor.world.pos.x + 160.0f, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0);
				sDoorState = 100;
				Actor_Kill(&pthis->actor);
			}
			else
			{
				pthis->actor.colChkInfo.damageTable = sDamageTable;
				sPhase2Timer = 0xFFFF;
				if(gSaveContext.eventChkInf[7] & 0x40)
				{
					sCsState = INTRO_CALL_BARI;
					sDoorState = 100;
					func_8002DF54(globalCtx, &pthis->actor, 1);
					globalCtx->envCtx.screenFillColor[0] = 0xDC;
					globalCtx->envCtx.screenFillColor[1] = 0xDC;
					globalCtx->envCtx.screenFillColor[2] = 0xBE;
					globalCtx->envCtx.screenFillColor[3] = 0xD2;
					func_80064520(globalCtx, &globalCtx->csCtx);
					sCsCamera = Gameplay_CreateSubCamera(globalCtx);
					Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
					Gameplay_ChangeCameraStatus(globalCtx, sCsCamera, CAM_STAT_ACTIVE);
					sCameraNextEye.x = sCameraEye.x = 140.0f;
					sCameraNextEye.y = sCameraEye.y = 205.0f;
					sCameraNextEye.z = sCameraEye.z = -20.0f;
					sCameraNextAt.x = sCameraAt.x = 10.0f;
					sCameraNextAt.y = sCameraAt.y = 50.0f;
					sCameraNextAt.z = sCameraAt.z = -220.0f;
					Gameplay_CameraSetAtEye(globalCtx, sCsCamera, &sCameraAt, &sCameraEye);
					pthis->timer = 20;

					for(i = BOSSVA_BARI_LOWER_5; i >= BOSSVA_BARI_UPPER_1; i--)
					{
						Actor_SpawnAsChild(
						    &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_VA, sInitPosOffsets[i].x + pthis->actor.world.pos.x, sInitPosOffsets[i].y + pthis->actor.world.pos.y,
						    sInitPosOffsets[i].z + pthis->actor.world.pos.z, sInitRot[i].x + pthis->actor.world.rot.x, sInitRot[i].y + pthis->actor.world.rot.y, sInitRot[i].z + pthis->actor.world.rot.z, i);
					}

					sCameraAtMaxVel = sCameraEyeMaxVel = sZeroVec;
				}
				else
				{
					sCsState = INTRO_START;
					sDoorState = 5;
				}

				pthis->zapHeadPos.x = 1.0f;
				Collider_InitCylinder(globalCtx, &pthis->colliderBody);
				Collider_SetCylinder(globalCtx, &pthis->colliderBody, &pthis->actor, &sCylinderInit);

				for(i = BOSSVA_ZAPPER_3; i >= BOSSVA_SUPPORT_1; i--)
				{
					Actor_SpawnAsChild(
					    &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_VA, sInitPosOffsets[i].x + pthis->actor.world.pos.x, sInitPosOffsets[i].y + pthis->actor.world.pos.y, sInitPosOffsets[i].z + pthis->actor.world.pos.z,
					    sInitRot[i].x + pthis->actor.world.rot.x, sInitRot[i].y + pthis->actor.world.rot.y, sInitRot[i].z + pthis->actor.world.rot.z, i);
				}

				Lib_MemSet((u8*)sVaEffects, ARRAY_COUNT(sVaEffects) * sizeof(BossVaEffect), 0);
				if(sCsState < BOSSVA_BATTLE)
				{
					BossVa_SetupIntro(pthis);
				}
				else
				{
					BossVa_SetupBodyPhase1(pthis);
				}
			}
			break;
		case BOSSVA_SUPPORT_1:
		case BOSSVA_SUPPORT_2:
		case BOSSVA_SUPPORT_3:
			Collider_InitJntSph(globalCtx, &pthis->colliderSph);
			Collider_SetJntSph(globalCtx, &pthis->colliderSph, &pthis->actor, &sJntSphInitSupport, pthis->elements);
			if(sCsState < BOSSVA_BATTLE)
			{
				BossVa_SetupSupportIntro(pthis, globalCtx);
			}
			else
			{
				BossVa_SetupSupportAttached(pthis, globalCtx);
			}
			pthis->onCeiling++;
			break;
		case BOSSVA_ZAPPER_1:
		case BOSSVA_ZAPPER_2:
		case BOSSVA_ZAPPER_3:
			Collider_InitQuad(globalCtx, &pthis->colliderLightning);
			Collider_SetQuad(globalCtx, &pthis->colliderLightning, &pthis->actor, &sQuadInit);
			if(sCsState < BOSSVA_BATTLE)
			{
				BossVa_SetupZapperIntro(pthis, globalCtx);
			}
			else
			{
				BossVa_SetupZapperAttack(pthis, globalCtx);
			}
			break;
		case BOSSVA_STUMP_1:
		case BOSSVA_STUMP_2:
		case BOSSVA_STUMP_3:
			BossVa_SetupStump(pthis, globalCtx);
			break;
		case BOSSVA_DOOR:
			BossVa_SetupDoor(pthis, globalCtx);
			break;
		default:
			Collider_InitJntSph(globalCtx, &pthis->colliderSph);
			Collider_SetJntSph(globalCtx, &pthis->colliderSph, &pthis->actor, &sJntSphInitBari, pthis->elements);
			Collider_InitQuad(globalCtx, &pthis->colliderLightning);
			Collider_SetQuad(globalCtx, &pthis->colliderLightning, &pthis->actor, &sQuadInit);
			pthis->unk_1D8.x = 1.0f;
			pthis->unk_1D8.y = 1.0f;
			if(sCsState < BOSSVA_BATTLE)
			{
				BossVa_SetupBariIntro(pthis, globalCtx);
			}
			else if(sFightPhase >= PHASE_3)
			{
				BossVa_SetupBariPhase3Attack(pthis, globalCtx);
			}
			else
			{
				BossVa_SetupBariPhase2Attack(pthis, globalCtx);
			}
			break;
	}
}

void BossVa_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	BossVa* pthis = (BossVa*)thisx;

	SkelAnime_Free(&pthis->skelAnime, globalCtx);
	Collider_DestroyJntSph(globalCtx, &pthis->colliderSph);
	Collider_DestroyCylinder(globalCtx, &pthis->colliderBody);
}

void BossVa_SetupIntro(BossVa* pthis)
{
	f32 lastFrame = Animation_GetLastFrame(&gBarinadeBodyAnim);

	Animation_Change(&pthis->skelAnime, &gBarinadeBodyAnim, 1.0f, lastFrame, lastFrame, ANIMMODE_ONCE, 0.0f);
	pthis->actor.shape.yOffset = -450.0f;
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	BossVa_SetupAction(pthis, BossVa_BodyIntro);
}

void BossVa_BodyIntro(BossVa* pthis, GlobalContext* globalCtx)
{
	s32 i;
	Player* player = GET_PLAYER(globalCtx);

	pthis->unk_1AC += 0xC31;
	pthis->unk_1A0 = (Math_CosS(pthis->unk_1AC) * 0.1f) + 1.0f;
	pthis->unk_1A4 = (Math_SinS(pthis->unk_1AC) * 0.05f) + 1.0f;

	switch(sCsState)
	{
		case INTRO_UNUSED_START:
			pthis->timer--;
			if(pthis->timer == 0)
			{
				sCsState = INTRO_CLOSE_DOOR;
				pthis->timer = 10;
			}
			break;
		case INTRO_START:
			globalCtx->envCtx.screenFillColor[0] = 0xDC;
			globalCtx->envCtx.screenFillColor[1] = 0xDC;
			globalCtx->envCtx.screenFillColor[2] = 0xBE;
			globalCtx->envCtx.screenFillColor[3] = 0xD2;
			func_8002DF54(globalCtx, &pthis->actor, 8);
			player->actor.world.rot.y = player->actor.shape.rot.y = 0x7FFF;
			sCsState++;
			break;
		case INTRO_LOOK_DOOR:
			func_80064520(globalCtx, &globalCtx->csCtx);
			if(sCsCamera == SUBCAM_FREE)
			{
				sCsCamera = Gameplay_CreateSubCamera(globalCtx);
			}
			Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
			Gameplay_ChangeCameraStatus(globalCtx, sCsCamera, CAM_STAT_ACTIVE);

			sCameraNextEye.x = sCameraEye.x = 13.0f;
			sCameraNextEye.y = sCameraEye.y = 124.0f;
			sCameraNextEye.z = sCameraEye.z = 167.0f;

			sCameraNextAt.x = sCameraAt.x = player->actor.world.pos.x;
			sCameraNextAt.y = sCameraAt.y = player->actor.world.pos.y;
			sCameraNextAt.z = sCameraAt.z = player->actor.world.pos.z;

			sCameraAtMaxVel = sCameraEyeMaxVel = sZeroVec;

			pthis->timer = 10;
			sCsState++;
			break;
		case INTRO_CLOSE_DOOR:
			pthis->timer--;
			if(pthis->timer == 0)
			{
				func_8002DF54(globalCtx, &pthis->actor, 2);
				sCsState++;
				pthis->timer = 30;
			}
			break;
		case INTRO_DOOR_SHUT:
			pthis->timer--;
			if(pthis->timer == 0)
			{
				sCsState++;
			}
			if(Rand_ZeroOne() < 0.1f)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
			}
			break;
		case INTRO_CRACKLE:
			func_8002DF54(globalCtx, &pthis->actor, 1);
			sCsState++;
			break;
		case INTRO_SPAWN_BARI:
			func_80064520(globalCtx, &globalCtx->csCtx);
			if(sCsCamera == SUBCAM_FREE)
			{
				sCsCamera = Gameplay_CreateSubCamera(globalCtx);
			}
			Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
			Gameplay_ChangeCameraStatus(globalCtx, sCsCamera, CAM_STAT_ACTIVE);

			sCameraNextEye.x = sCameraEye.x = 13.0f;
			sCameraNextEye.y = sCameraEye.y = 124.0f;
			sCameraNextEye.z = sCameraEye.z = 167.0f;

			sCameraNextAt.x = sCameraAt.x = player->actor.world.pos.x;
			sCameraNextAt.y = sCameraAt.y = player->actor.world.pos.y;
			sCameraNextAt.z = sCameraAt.z = player->actor.world.pos.z;

			sCameraAtMaxVel = sCameraEyeMaxVel = sZeroVec;

			for(i = BOSSVA_BARI_LOWER_5; i >= BOSSVA_BARI_UPPER_1; i--)
			{
				Actor_SpawnAsChild(
				    &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_VA, sInitPosOffsets[i].x + pthis->actor.world.pos.x, sInitPosOffsets[i].y + pthis->actor.world.pos.y, sInitPosOffsets[i].z + pthis->actor.world.pos.z,
				    sInitRot[i].x + pthis->actor.world.rot.x, sInitRot[i].y + pthis->actor.world.rot.y, sInitRot[i].z + pthis->actor.world.rot.z, i);
			}

			pthis->timer = 90;
			sCsState++;
			break;
		case INTRO_REVERSE_CAMERA:
			sCameraNextEye.x = -92.0f;
			sCameraNextEye.y = 22.0f;
			sCameraNextEye.z = 360.0f;
			sCameraNextAt.x = 63.0f;
			sCameraNextAt.y = 104.0f;
			sCameraNextAt.z = 248.0f;
			Math_SmoothStepToF(&sCameraEyeMaxVel.x, 7.0f, 0.3f, 0.7f, 0.05f);
			sCameraEyeMaxVel.z = sCameraEyeMaxVel.x;
			sCameraEyeMaxVel.y = sCameraEyeMaxVel.z;
			sCameraAtMaxVel = sCameraEyeMaxVel;

			pthis->timer--;
			if(pthis->timer == 0)
			{
				sCsState++;
				pthis->timer = 60;
			}
			break;
		case INTRO_SUPPORT_CAMERA:
			sCameraNextEye.x = sCameraEye.x = 140.0f;
			sCameraNextEye.y = sCameraEye.y = 205.0f;
			sCameraNextEye.z = sCameraEye.z = -20.0f;

			sCameraNextAt.x = sCameraAt.x = 10.0f;
			sCameraNextAt.y = sCameraAt.y = 247.0f;
			sCameraNextAt.z = sCameraAt.z = -220.0f;

			sCsState++;
			pthis->timer = 1;
			break;
		case INTRO_BODY_SOUND:
			sCameraNextAt.x = 10.0f;
			sCameraNextAt.y = 247.0f;
			sCameraNextAt.z = -220.0f;
			Math_SmoothStepToF(&sCameraEyeMaxVel.x, 7.0f, 0.3f, 0.7f, 0.05f);
			sCameraEyeMaxVel.z = sCameraEyeMaxVel.x;
			sCameraEyeMaxVel.y = sCameraEyeMaxVel.z;
			sCameraAtMaxVel = sCameraEyeMaxVel;

			pthis->timer--;
			if(pthis->timer == 0)
			{
				sCsState++;
				pthis->timer = 40;
			}
			break;
		case INTRO_LOOK_SUPPORT:
			pthis->timer--;
			if(pthis->timer == 0)
			{
				sCameraNextAt.x = 10.0f;
				sCameraNextAt.y = 50.0f;
				sCameraNextAt.z = -220.0f;

				sCameraAtMaxVel = sCameraEyeMaxVel = sZeroVec;

				sCsState++;
				sCsState++;
				pthis->timer = 20;
			}
			break;
		case INTRO_CALL_BARI:
			Math_SmoothStepToF(&sCameraEyeMaxVel.x, 14.0f, 0.3f, 1.0f, 0.25f);

			sCameraEyeMaxVel.y = sCameraEyeMaxVel.x * 0.7f;
			sCameraEyeMaxVel.z = sCameraEyeMaxVel.x;

			sCameraAtMaxVel = sCameraEyeMaxVel;
			sCameraAtMaxVel.z = sCameraAtMaxVel.z * 1.75f;

			pthis->timer--;
			if(pthis->timer == 0)
			{
				sCsState++;
				pthis->timer = 7500;
				pthis->unk_1F2 = 0;
			}
			break;
		case INTRO_ATTACH_BARI:
			for(i = 10; i >= 1; i--)
			{
				if(sBodyBari[i - 1])
				{
					if(sBodyBari[i - 1] == 1)
					{
						Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_STICK);
						BossVa_SetSparkEnv(globalCtx);
						if(pthis->onCeiling == 0)
						{
							pthis->onCeiling = 2; // Not used by body
						}
					}
					else if(sBodyBari[i - 1] == 2)
					{
						BossVa_Spark(globalCtx, pthis, 6, 140, 50.0f, 30.0f, SPARK_BARI, i, true);
					}

					if(sBodyBari[i - 1] <= 2)
					{
						sBodyBari[i - 1]++;
					}
				}
			}
			Math_SmoothStepToS(&pthis->unk_1F2, 0x280, 1, 0x32, 0);
			Math_SmoothStepToF(&sCameraEyeMaxVel.x, 14.0f, 0.3f, 1.0f, 0.25f);
			sCameraEyeMaxVel.z = sCameraEyeMaxVel.x;
			sCameraAtMaxVel = sCameraEyeMaxVel;
			if(pthis->timer >= 45000)
			{
				globalCtx->envCtx.unk_BF = 1;
				func_8002DF54(globalCtx, &pthis->actor, 8);
			}
			else if(pthis->timer >= 35000)
			{
				Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS);
			}

			pthis->timer += pthis->unk_1F2;
			if(pthis->timer >= 65536)
			{
				sCameraEyeMaxVel.y = sCameraAtMaxVel.y = 9.8f;
				sCsState++;

				sCameraNextEye.x = 10.0f;
				sCameraNextEye.z = 0.0f;

				sCameraNextAt.x = 10.0f;
				sCameraNextAt.y = 140.0f;
				sCameraNextAt.z = -200.0f;

				if(!(gSaveContext.eventChkInf[7] & 0x40))
				{
					TitleCard_InitBossName(globalCtx, &globalCtx->actorCtx.titleCtx, SEGMENTED_TO_VIRTUAL(gBarinadeTitleCardTex), 0xA0, 0xB4, 0x80, 0x28);
				}

				if(Rand_ZeroOne() < 0.1f)
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
				}

				pthis->timer = 40;
			}
			else
			{
				sCameraEyeMaxVel.y = 1.6f;
				sCameraNextEye.y = 5.0f;
				sCameraNextEye.x = Math_SinS(pthis->timer) * 200.0f;
				sCameraNextEye.z = (Math_CosS(pthis->timer) * 200.0f) + -200.0f;
			}
			break;
		case INTRO_TITLE:
			BossVa_Spark(globalCtx, pthis, 3, 140, 50.0f, 30.0f, SPARK_BARI, 10.0f, false);
			pthis->timer--;
			if(pthis->timer == 0)
			{
				sCsState++;
				pthis->timer = 45;
			}
			break;
		case INTRO_BRIGHTEN:
			BossVa_Spark(globalCtx, pthis, 3, 140, 50.0f, 30.0f, SPARK_BARI, 10.0f, false);
			pthis->timer--;
			if(pthis->timer == 0)
			{
				sCsState++;
				pthis->timer = 11;
			}
			break;
		case INTRO_FINISH:
			pthis->timer--;
			if(pthis->timer == 0)
			{
				Gameplay_ClearCamera(globalCtx, sCsCamera);
				sCsCamera = 0;
				func_80064534(globalCtx, &globalCtx->csCtx);
				Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_ACTIVE);
				func_8002DF54(globalCtx, &pthis->actor, 7);
				sCsState++;
				gSaveContext.eventChkInf[7] |= 0x40;
				player->actor.shape.rot.y = player->actor.world.rot.y = pthis->actor.yawTowardsPlayer + 0x8000;
			}
			break;
		case BOSSVA_BATTLE:
			BossVa_SetupBodyPhase1(pthis);
			break;
	}

	if(sCsState >= INTRO_BODY_SOUND)
	{
		func_800F436C(&pthis->actor.projectedPos, NA_SE_EN_BALINADE_LEVEL - SFX_FLAG, 1.0f);
		if((sCsState >= INTRO_CALL_BARI) && ((globalCtx->gameplayFrames % 4) == 0))
		{
			BossVa_Spark(globalCtx, pthis, 1, 100, 50.0f, 10.0f, SPARK_BODY, 10.0f, false);
		}
	}

	pthis->unk_1B0 += 0xCE4;
	pthis->bodyGlow = (s16)(Math_SinS(pthis->unk_1B0) * 50.0f) + 150;
	if((sCsCamera != 0) && (sCsState <= INTRO_TITLE))
	{
		Math_SmoothStepToF(&sCameraEye.x, sCameraNextEye.x, 0.3f, sCameraEyeMaxVel.x, 0.075f);
		Math_SmoothStepToF(&sCameraEye.y, sCameraNextEye.y, 0.3f, sCameraEyeMaxVel.y, 0.075f);
		Math_SmoothStepToF(&sCameraEye.z, sCameraNextEye.z, 0.3f, sCameraEyeMaxVel.z, 0.075f);
		Math_SmoothStepToF(&sCameraAt.x, sCameraNextAt.x, 0.3f, sCameraAtMaxVel.x, 0.075f);
		Math_SmoothStepToF(&sCameraAt.y, sCameraNextAt.y, 0.3f, sCameraAtMaxVel.y, 0.075f);
		Math_SmoothStepToF(&sCameraAt.z, sCameraNextAt.z, 0.3f, sCameraAtMaxVel.z, 0.075f);
		Gameplay_CameraSetAtEye(globalCtx, sCsCamera, &sCameraAt, &sCameraEye);
	}
}

void BossVa_SetupBodyPhase1(BossVa* pthis)
{
	f32 lastFrame = Animation_GetLastFrame(&gBarinadeBodyAnim);

	Animation_Change(&pthis->skelAnime, &gBarinadeBodyAnim, 1.0f, lastFrame, lastFrame, ANIMMODE_ONCE, 0.0f);
	pthis->actor.shape.yOffset = -450.0f;
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	pthis->timer = 25;
	sBodyState = 0x80;
	BossVa_SetupAction(pthis, BossVa_BodyPhase1);
}

void BossVa_BodyPhase1(BossVa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	pthis->unk_1B0 += 0xCE4;
	pthis->bodyGlow = (s16)(Math_SinS(pthis->unk_1B0) * 50.0f) + 150;
	if(pthis->timer != 0)
	{
		pthis->timer--;
		if(pthis->timer == 0)
		{
			sBodyState &= (u8)~0x80;
		}
	}

	if(pthis->colliderBody.base.atFlags & AT_HIT)
	{
		pthis->colliderBody.base.atFlags &= ~AT_HIT;
		if(pthis->colliderBody.base.at == &player->actor)
		{
			func_8002F71C(globalCtx, &pthis->actor, 8.0f, pthis->actor.yawTowardsPlayer, 8.0f);
		}
	}

	if(sBodyState & 0x7F)
	{
		pthis->skelAnime.curFrame = 0.0f;
		Actor_SetColorFilter(&pthis->actor, 0, 255, 0, 12);
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_DAMAGE);
	}

	if(SkelAnime_Update(&pthis->skelAnime) && (sFightPhase >= PHASE_2))
	{
		BossVa_SetupBodyPhase2(pthis, globalCtx);
	}

	Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->actor.world.rot.x, 1, 0xC8, 0);
	Math_SmoothStepToS(&pthis->actor.shape.rot.z, pthis->actor.world.rot.z, 1, 0xC8, 0);
	pthis->unk_1AC += 0xC31;
	pthis->unk_1A0 = (Math_CosS(pthis->unk_1AC) * 0.1f) + 1.0f;
	pthis->unk_1A4 = (Math_SinS(pthis->unk_1AC) * 0.05f) + 1.0f;
	if((globalCtx->gameplayFrames % 4) == 0)
	{
		BossVa_Spark(globalCtx, pthis, 1, 100, 50.0f, 10.0f, SPARK_BARI, 10.0f, false);
	}

	if(Rand_ZeroOne() < 0.1f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
	}

	Collider_UpdateCylinder(&pthis->actor, &pthis->colliderBody);
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	func_800F436C(&pthis->actor.projectedPos, NA_SE_EN_BALINADE_LEVEL - SFX_FLAG, 1.0f);
}

void BossVa_SetupBodyPhase2(BossVa* pthis, GlobalContext* globalCtx)
{
	s32 i;

	sFightPhase++;
	for(i = BOSSVA_BARI_UPPER_5; i >= BOSSVA_BARI_UPPER_1; i--)
	{
		Actor_SpawnAsChild(
		    &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_VA, sInitPosOffsets[i].x + pthis->actor.world.pos.x, sInitPosOffsets[i].y + pthis->actor.world.pos.y, sInitPosOffsets[i].z + pthis->actor.world.pos.z,
		    sInitRot[i].x + pthis->actor.world.rot.x, sInitRot[i].y + pthis->actor.world.rot.y, sInitRot[i].z + pthis->actor.world.rot.z, i);
	}

	pthis->invincibilityTimer = 0;
	pthis->actor.flags |= ACTOR_FLAG_VISIBLE;
	BossVa_SetupAction(pthis, BossVa_BodyPhase2);
}

void BossVa_BodyPhase2(BossVa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	Vec3f sp48;

	if(pthis->actor.colorFilterTimer == 0)
	{
		sPhase2Timer++;
		if((pthis->invincibilityTimer != 0) && (pthis->actor.colorFilterParams & 0x4000))
		{
			Actor_SetColorFilter(&pthis->actor, 0, 255, 0, 160);
			pthis->actor.colorFilterTimer = pthis->invincibilityTimer;
		}
		else
		{
			pthis->colliderBody.info.bumper.dmgFlags = 0x10;
		}
	}

	if(pthis->colliderBody.base.acFlags & AC_HIT)
	{
		pthis->colliderBody.base.acFlags &= ~AC_HIT;

		if(pthis->colliderBody.base.ac->id == ACTOR_EN_BOOM)
		{
			sPhase2Timer &= 0xFE00;
			Actor_SetColorFilter(&pthis->actor, 0, 255, 0, 160);
			pthis->colliderBody.info.bumper.dmgFlags = 0xFC00712;
		}
		else
		{
			sKillBari++;
			if((pthis->actor.colorFilterTimer != 0) && !(pthis->actor.colorFilterParams & 0x4000))
			{
				pthis->invincibilityTimer = pthis->actor.colorFilterTimer - 5;
				if(pthis->invincibilityTimer > 160)
				{
					pthis->invincibilityTimer = 0;
				}
			}

			Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 12);
		}

		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_FAINT);
	}

	if(pthis->colliderBody.base.atFlags & AT_HIT)
	{
		pthis->colliderBody.base.atFlags &= ~AT_HIT;

		sPhase2Timer = (sPhase2Timer + 0x18) & 0xFFF0;
		if(pthis->colliderBody.base.at == &player->actor)
		{
			func_8002F71C(globalCtx, &pthis->actor, 8.0f, pthis->actor.yawTowardsPlayer, 8.0f);
			Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
		}
	}

	if((sPhase2Timer > 10) && !(sPhase2Timer & 7) && (pthis->actor.speedXZ == 1.0f))
	{
		sp48 = pthis->actor.world.pos;
		sp48.y += 310.0f + (pthis->actor.shape.yOffset * pthis->actor.scale.y);
		sp48.x += -10.0f;
		sp48.z += 220.0f;
		BossVa_SpawnSparkBall(globalCtx, sVaEffects, pthis, &sp48, 4, 0);
	}

	if(Rand_ZeroOne() < 0.1f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
	}

	Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->actor.world.rot.x, 1, 0xC8, 0);
	Math_SmoothStepToS(&pthis->actor.shape.rot.z, pthis->actor.world.rot.z, 1, 0xC8, 0);
	Math_SmoothStepToF(&pthis->actor.shape.yOffset, -1000.0f, 1.0f, 20.0f, 0.0f);
	if(!(sPhase2Timer & 0x100))
	{
		pthis->actor.flags |= ACTOR_FLAG_VISIBLE;
		pthis->actor.speedXZ = 1.0f;
	}
	else
	{
		pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
		pthis->actor.speedXZ = 0.0f;
	}

	if(SkelAnime_Update(&pthis->skelAnime) && (sFightPhase >= PHASE_3))
	{
		BossVa_SetupBodyPhase3(pthis);
	}

	pthis->unk_1AC += 0xC31;
	pthis->unk_1A0 = (Math_CosS(pthis->unk_1AC) * 0.1f) + 1.0f;
	pthis->unk_1A4 = (Math_SinS(pthis->unk_1AC) * 0.05f) + 1.0f;
	if((globalCtx->gameplayFrames % 4) == 0)
	{
		BossVa_Spark(globalCtx, pthis, 1, 100, 50.0f, 10.0f, SPARK_BODY, 10.0f, false);
	}

	pthis->actor.focus.pos = pthis->actor.world.pos;
	pthis->actor.focus.pos.y += 45.0f;

	Collider_UpdateCylinder(&pthis->actor, &pthis->colliderBody);
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	if(pthis->actor.colorFilterTimer == 0)
	{
		CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	}

	if((pthis->actor.colorFilterTimer == 0) || !(pthis->actor.colorFilterParams & 0x4000))
	{
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	}

	func_800F436C(&pthis->actor.projectedPos, NA_SE_EN_BALINADE_LEVEL - SFX_FLAG, (pthis->vaBodySpinRate * 0.00025f) + 1.0f);
}

void BossVa_SetupBodyPhase3(BossVa* pthis)
{
	pthis->colliderBody.info.bumper.dmgFlags = 0x10;
	pthis->actor.speedXZ = 0.0f;
	sPhase3StopMoving = false;
	BossVa_SetupAction(pthis, BossVa_BodyPhase3);
}

void BossVa_BodyPhase3(BossVa* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	Player* player = GET_PLAYER(globalCtx);
	s32 i;
	s16 sp62;

	sp62 = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
	pthis->unk_1B0 += 0xCE4;
	pthis->bodyGlow = (s16)(Math_SinS(pthis->unk_1B0) * 50.0f) + 150;
	if(pthis->colliderBody.base.atFlags & AT_HIT)
	{
		pthis->colliderBody.base.atFlags &= ~AT_HIT;
		if(pthis->colliderBody.base.at == &player->actor)
		{
			func_8002F71C(globalCtx, &pthis->actor, 8.0f, pthis->actor.yawTowardsPlayer, 8.0f);
			pthis->actor.world.rot.y += (s16)Rand_CenteredFloat(0x2EE0) + 0x8000;
			Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
		}
	}

	if(pthis->colliderBody.base.acFlags & AC_HIT)
	{
		pthis->skelAnime.curFrame = 0.0f;
		Actor_SetColorFilter(&pthis->actor, 0, 255, 0, 12);
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_FAINT);
		sBodyState = 1;
		pthis->timer = 131;
		pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	}
	else
	{
		sBodyState = 0;
		if(pthis->timer == 0)
		{
			if(Math_SmoothStepToS(&pthis->vaBodySpinRate, 0xFA0, 1, 0x12C, 0) == 0)
			{
				if(pthis->actor.speedXZ == 0.0f)
				{
					pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
				}
				Math_SmoothStepToF(&pthis->actor.speedXZ, 3.0f, 1.0f, 0.15f, 0.0f);
			}
			pthis->actor.flags |= ACTOR_FLAG_VISIBLE;
		}
		else
		{
			pthis->timer--;
			if(pthis->timer < 35)
			{
				sBodyState = 0x80;
			}
			Math_SmoothStepToS(&pthis->vaBodySpinRate, 0, 1, 0x12C, 0);
			Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.2f, 0.0f);
			Math_SmoothStepToF(&pthis->actor.shape.yOffset, -1420.0f, 1.0f, 30.0f, 0.0f);
		}
	}

	if(Math_Vec3f_DistXZ(&pthis->actor.world.pos, &pthis->actor.home.pos) >= 400.0f)
	{
		Math_SmoothStepToS(&pthis->actor.world.rot.y, sp62, 1, 0x3E8, 0);
	}
	else if(player->invincibilityTimer != 0)
	{
		Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer + 0x8000, 1, 0x12C, 0);
	}
	else if((globalCtx->gameplayFrames & 0x80) == 0)
	{
		Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x12C, 0);
	}
	else
	{
		Math_SmoothStepToS(&pthis->actor.world.rot.y, sp62, 1, 0x258, 0);
	}

	if(sPhase3StopMoving)
	{
		pthis->actor.speedXZ = 0.0f;
	}

	Actor_MoveForward(&pthis->actor);
	if(SkelAnime_Update(&pthis->skelAnime) && (sFightPhase >= PHASE_4))
	{
		BossVa_SetupBodyPhase4(pthis, globalCtx);
	}

	pthis->actor.shape.rot.y += pthis->vaBodySpinRate;
	if(sFightPhase == PHASE_3)
	{
		Math_SmoothStepToF(&pthis->actor.shape.yOffset, -450.0f, 1.0f, 15.0f, 0.0f);
	}
	else
	{
		Math_SmoothStepToF(&pthis->actor.shape.yOffset, -810.0f, 1.0f, 15.0f, 0.0f);
	}

	if((pthis->actor.shape.yOffset >= -500.0f) && (sFightPhase == PHASE_3))
	{
		for(i = BOSSVA_BARI_LOWER_5; i >= BOSSVA_BARI_LOWER_1; i--)
		{
			Actor_SpawnAsChild(
			    &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_VA, sInitPosOffsets[i].x + pthis->actor.world.pos.x, sInitPosOffsets[i].y + pthis->actor.world.pos.y, sInitPosOffsets[i].z + pthis->actor.world.pos.z,
			    sInitRot[i].x + pthis->actor.world.rot.x, sInitRot[i].y + pthis->actor.world.rot.y, sInitRot[i].z + pthis->actor.world.rot.z, i);
		}
		sFightPhase++;
	}

	pthis->unk_1AC += 0xC31;
	pthis->unk_1A0 = (Math_CosS(pthis->unk_1AC) * 0.1f) + 1.0f;
	pthis->unk_1A4 = (Math_SinS(pthis->unk_1AC) * 0.05f) + 1.0f;
	if((globalCtx->gameplayFrames % 4) == 0)
	{
		BossVa_Spark(globalCtx, pthis, 1, 0x64, 50.0f, 10.0f, SPARK_BODY, 10.0f, false);
	}

	pthis->actor.focus.pos = pthis->actor.world.pos;
	pthis->actor.focus.pos.y += 20.0f;
	if(Rand_ZeroOne() < 0.1f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
	}

	Collider_UpdateCylinder(&pthis->actor, &pthis->colliderBody);
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	if(pthis->timer == 0)
	{
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	}

	func_800F436C(&pthis->actor.projectedPos, NA_SE_EN_BALINADE_LEVEL - SFX_FLAG, (pthis->vaBodySpinRate * 0.00025f) + 1.0f);
}

void BossVa_SetupBodyPhase4(BossVa* pthis, GlobalContext* globalCtx)
{
	pthis->unk_1AC = 0;
	pthis->actor.flags |= ACTOR_FLAG_VISIBLE;
	pthis->vaBodySpinRate = pthis->unk_1AC;
	pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
	pthis->timer2 = (s16)(Rand_ZeroOne() * 150.0f) + 300;
	sBodyState = 1;
	sPhase4HP = 4;
	if(pthis->actor.shape.yOffset != 0.0f)
	{
		pthis->timer = -30;
	}

	pthis->colliderBody.dim.radius = 55;
	BossVa_SetupAction(pthis, BossVa_BodyPhase4);
}

void BossVa_BodyPhase4(BossVa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	f32 tmpf1;
	EnBoom* boomerang;

	pthis->unk_1B0 = (pthis->unk_1B0 + (s16)((sFightPhase - PHASE_4 + 1) * 1000.0f)) + 0xCE4;
	pthis->bodyGlow = (s16)(Math_SinS(pthis->unk_1B0) * 50.0f) + 150;
	if(pthis->colliderBody.base.atFlags & AT_HIT)
	{
		pthis->colliderBody.base.atFlags &= ~AT_HIT;
		if(pthis->colliderBody.base.at == &player->actor)
		{
			func_8002F71C(globalCtx, &pthis->actor, 8.0f, pthis->actor.yawTowardsPlayer, 8.0f);
			pthis->actor.world.rot.y += (s16)Rand_CenteredFloat(0x2EE0) + 0x8000;
			Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
		}
	}
	if(Rand_ZeroOne() < 0.1f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
	}

	if(pthis->colliderBody.base.acFlags & AC_HIT)
	{
		pthis->colliderBody.base.acFlags &= ~AC_HIT;
		pthis->skelAnime.curFrame = 0.0f;
		if(pthis->timer >= 0)
		{
			if(pthis->invincibilityTimer == 0)
			{
				pthis->invincibilityTimer = 8;
				if(pthis->actor.colChkInfo.damageEffect != 1)
				{
					pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_DAMAGE);
					Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 12);
					sPhase4HP -= pthis->actor.colChkInfo.damage;
					if(sPhase4HP <= 0)
					{
						pthis->timer = 0;
						sFightPhase++;
						sPhase4HP += 3;
						if(sFightPhase >= PHASE_DEATH)
						{
							BossVa_SetupBodyDeath(pthis, globalCtx);
							Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
							return;
						}
						pthis->actor.speedXZ = -10.0f;
						pthis->timer = -170 - (s16)(Rand_ZeroOne() * 150.0f);
					}
				}
				else
				{
					pthis->timer = (s16)Rand_CenteredFloat(40.0f) + 160;
					pthis->vaBodySpinRate = 0;
					pthis->actor.speedXZ = 0.0f;
					Actor_SetColorFilter(&pthis->actor, 0, 125, 0, 255);
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_FAINT);
				}
			}
		}
		else if(pthis->colliderBody.base.ac->id == ACTOR_EN_BOOM)
		{
			boomerang = (EnBoom*)pthis->colliderBody.base.ac;
			boomerang->returnTimer = 0;
			boomerang->moveTo = &player->actor;
			boomerang->actor.world.rot.y = boomerang->actor.yawTowardsPlayer;
			Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_SHIELD_REFLECT_SW);
		}
	}
	else if((pthis->timer2 == 0) && (pthis->actor.shape.yOffset == 0.0f))
	{
		pthis->timer = -220 - (s16)(Rand_ZeroOne() * 200.0f);
	}
	else if(pthis->timer2 != 0)
	{
		pthis->timer2--;
	}

	SkelAnime_Update(&pthis->skelAnime);
	if(pthis->timer == 0)
	{
		Math_SmoothStepToF(&pthis->actor.shape.yOffset, 0.0f, 1.0f, ((sFightPhase - PHASE_4 + 1) * 5.0f) + 10.0f, 0.0f);
		if(Math_SmoothStepToS(&pthis->vaBodySpinRate, (s16)((sFightPhase - PHASE_4 + 1) * 500.0f) + 0xFA0, 1, 0x12C, 0) == 0)
		{
			if(pthis->actor.speedXZ == 0.0f)
			{
				pthis->actor.colorFilterTimer = 0;
				pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
				pthis->timer2 = (s16)(Rand_ZeroOne() * 150.0f) + 300;
			}
			Math_SmoothStepToF(&pthis->actor.speedXZ, ((sFightPhase - PHASE_4 + 1) * 1.5f) + 4.0f, 1.0f, 0.25f, 0.0f);
		}
		pthis->colliderBody.info.bumper.dmgFlags = 0x10;
	}
	else
	{
		Math_SmoothStepToS(&pthis->vaBodySpinRate, 0, 1, 0x96, 0);
		if(pthis->timer > 0)
		{
			if((player->stateFlags1 & PLAYER_STATE1_26) && (pthis->timer > 35))
			{
				pthis->timer = 35;
			}
			Math_SmoothStepToF(&pthis->actor.shape.yOffset, -480.0f, 1.0f, 30.0f, 0.0f);
			pthis->colliderBody.info.bumper.dmgFlags = 0xFC00712;
			pthis->timer--;
		}
		else
		{
			if((player->stateFlags1 & PLAYER_STATE1_26) && (pthis->timer < -60))
			{
				pthis->timer = -59;
			}
			if((globalCtx->gameplayFrames % 4) == 0)
			{
				BossVa_Spark(globalCtx, pthis, 2, 0x64, 220.0f, 5.0f, SPARK_BODY, 12.0f, true);
			}
			if(pthis->timer < -30)
			{
				if(pthis->actor.speedXZ > 0.0f)
				{
					Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
				}
				Math_SmoothStepToF(&pthis->actor.shape.yOffset, -1400.0f, 1.0f, 60.0f, 0.0f);
			}
			else
			{
				if(pthis->actor.speedXZ == 0.0f)
				{
					pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer + 0x8000;
					pthis->timer2 = (s16)(Rand_ZeroOne() * 150.0f) + 330;
				}
				Math_SmoothStepToS(&pthis->vaBodySpinRate, 0xFA0, 1, 0x1F4, 0);
				tmpf1 = sFightPhase - PHASE_4 + 1;
				Math_SmoothStepToF(&pthis->actor.speedXZ, (tmpf1 + tmpf1) + 4.0f, 1.0f, 0.25f, 0.0f);
				Math_SmoothStepToF(&pthis->actor.shape.yOffset, 0.0f, 1.0f, 20.0f, 0.0f);
			}
			pthis->timer++;
		}
	}

	pthis->actor.shape.rot.y += pthis->vaBodySpinRate;
	if(pthis->actor.speedXZ < 0.0f)
	{
		Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
	}

	pthis->unk_1AC += 0xC31;
	pthis->unk_1A0 = (Math_CosS(pthis->unk_1AC) * 0.1f) + 1.0f;
	pthis->unk_1A4 = (Math_SinS(pthis->unk_1AC) * 0.05f) + 1.0f;
	if(pthis->actor.bgCheckFlags & BG_STATE_3)
	{
		pthis->actor.bgCheckFlags &= ~BG_STATE_3;
		pthis->actor.world.rot.y = (s16)Rand_CenteredFloat(30 * (0x10000 / 360)) + pthis->actor.wallYaw;
	}

	if(sFightPhase <= PHASE_4)
	{
		if(Math_Vec3f_DistXZ(&pthis->actor.world.pos, &pthis->actor.home.pos) >= 400.0f)
		{
			Math_SmoothStepToS(&pthis->actor.world.rot.y, Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos), 1, 0x5DC, 0);
		}
		else if(player->invincibilityTimer != 0)
		{
			Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer + 0x8000, 1, 0x12C, 0);
		}
		else if((globalCtx->gameplayFrames & 0x80) == 0)
		{
			Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, (s16)((sFightPhase - PHASE_4 + 1) * 100.0f) + 0x64, 0);
		}
	}

	Actor_MoveForward(&pthis->actor);
	pthis->actor.focus.pos = pthis->actor.world.pos;
	pthis->actor.focus.pos.y += 60.0f;
	if(((globalCtx->gameplayFrames % 2) == 0) && (pthis->timer == 0))
	{
		BossVa_Spark(globalCtx, pthis, 2, 125, 40.0f, 10.0f, SPARK_BODY, 10.0f, false);
		BossVa_Spark(globalCtx, pthis, 1, 100, 15.0f, 10.0f, SPARK_BARI, 11.0f, true);
	}

	Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 30.0f, 70.0f, 0.0f, 1);
	Collider_UpdateCylinder(&pthis->actor, &pthis->colliderBody);
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	if(pthis->invincibilityTimer == 0)
	{
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	}
	if((pthis->vaBodySpinRate > 0x3E8) || (pthis->actor.shape.yOffset < -1200.0f))
	{
		CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
	}
	func_800F436C(&pthis->actor.projectedPos, NA_SE_EN_BALINADE_LEVEL - SFX_FLAG, (pthis->vaBodySpinRate * 0.00025f) + 1.0f);
	if(pthis->invincibilityTimer != 0)
	{
		pthis->invincibilityTimer--;
		sBodyState = (sBodyState & 0x80) | 2;
	}
	else
	{
		sBodyState = (sBodyState & 0x80) | 1;
	}
}

void BossVa_SetupBodyDeath(BossVa* pthis, GlobalContext* globalCtx)
{
	func_800F436C(&pthis->actor.projectedPos, NA_SE_EN_BALINADE_LEVEL - SFX_FLAG, 1.0f);
	pthis->actor.flags &= ~(ACTOR_FLAG_VISIBLE | ACTOR_FLAG_2);
	Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x100FF);
	pthis->vaCamRotMod = 0xC31;
	sCsState = DEATH_START;
	pthis->actor.speedXZ = 0.0f;
	pthis->unk_1A8 = 0.0f;
	Flags_SetClear(globalCtx, globalCtx->roomCtx.curRoom.num);
	BossVa_SetupAction(pthis, BossVa_BodyDeath);
}

void BossVa_BodyDeath(BossVa* pthis, GlobalContext* globalCtx)
{
	s32 i;
	Camera* camera = Gameplay_GetCamera(globalCtx, 0);
	s32 sp7C;
	Player* player = GET_PLAYER(globalCtx);
	s16 tmp16;

	switch(sCsState)
	{
		case DEATH_START:
			func_8002DF54(globalCtx, &pthis->actor, 1);
			func_80064520(globalCtx, &globalCtx->csCtx);
			sCsCamera = Gameplay_CreateSubCamera(globalCtx);
			Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
			Gameplay_ChangeCameraStatus(globalCtx, sCsCamera, CAM_STAT_ACTIVE);

			sCameraNextAt.x = pthis->actor.world.pos.x;
			sCameraNextAt.y = pthis->actor.world.pos.y;
			sCameraNextAt.z = pthis->actor.world.pos.z;

			sCameraAt = camera->at;

			sCameraNextEye = sCameraEye = camera->eye;

			sCameraNextEye.y = 40.0f;
			sCameraNextAt.y = 140.0f;

			sCameraAtMaxVel = sCameraEyeMaxVel = sZeroVec;

			pthis->unk_1AC = Math_Vec3f_Yaw(&sCameraEye, &sCameraNextAt) - 0x100;
			pthis->unk_1B0 = 15;
			globalCtx->envCtx.screenFillColor[0] = globalCtx->envCtx.screenFillColor[1] = globalCtx->envCtx.screenFillColor[2] = 0xFF;
			globalCtx->envCtx.screenFillColor[3] = 0;
			globalCtx->envCtx.fillScreen = true;
			sCsState++;
		case DEATH_BODY_TUMORS:
			pthis->unk_1AC += 0x100;
			sCameraNextEye.x = (Math_SinS(pthis->unk_1AC) * (160.0f + pthis->unk_1A8)) + sCameraNextAt.x;
			sCameraNextEye.z = (Math_CosS(pthis->unk_1AC) * (160.0f + pthis->unk_1A8)) + sCameraNextAt.z;
			Math_SmoothStepToF(&sCameraEyeMaxVel.x, 16.0f, 0.4f, 1.5f, 0.5f);
			sCameraEyeMaxVel.z = sCameraEyeMaxVel.x;
			sCameraEyeMaxVel.y = sCameraEyeMaxVel.x * 0.5f;
			sCameraAtMaxVel = sCameraEyeMaxVel;
			tmp16 = Rand_CenteredFloat(0.5f) + ((sCameraEyeMaxVel.x * 0.5f) + 0.6f);
			if(((globalCtx->gameplayFrames % 4) == 0) && (pthis->unk_1B0 != 0))
			{
				for(i = 6; i > 1; i--)
				{
					BossVa_Tumor(globalCtx, pthis, 1, tmp16, 0.0f, 0.0f, TUMOR_BODY, i, true);
				}

				BossVa_Tumor(globalCtx, pthis, 1, tmp16, 0.0f, 0.0f, TUMOR_BODY, 11.0f, true);
				pthis->unk_1B0--;
			}

			if(pthis->unk_1B0 == 0)
			{
				sCsState++;

				sCameraAtMaxVel = sCameraEyeMaxVel = sZeroVec;
			}
			break;
		case DEATH_CORE_DEAD:
			pthis->unk_1AC += 0x1862;
			pthis->unk_1A0 = (Math_CosS(pthis->unk_1AC) * 0.12f) + 1.0f;
			pthis->unk_1A4 = (Math_SinS(pthis->unk_1AC) * 0.075f) + 1.0f;
			if(!pthis->isDead)
			{
				pthis->burst++;
				pthis->isDead++;
				pthis->timer = 30;
				sCsState++;
				EffectSsDeadSound_SpawnStationary(globalCtx, &pthis->actor.projectedPos, NA_SE_EN_BALINADE_DEAD, 1, 1, 0x28);
				pthis->onCeiling = 2; // Not used by body
				BossVa_SetDeathEnv(globalCtx);
				func_8002DF54(globalCtx, &pthis->actor, 8);
			}
			break;
		case DEATH_CORE_BURST:
			if(pthis->timer == 13)
			{
				Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS_CLEAR);
			}

			pthis->timer--;
			if(pthis->timer == 0)
			{
				sCameraNextAt.x = pthis->actor.world.pos.x;
				sCameraNextAt.y = pthis->actor.world.pos.y + 30.0f;
				sCameraNextAt.z = pthis->actor.world.pos.z;

				sCameraNextEye.x = (Math_SinS(player->actor.shape.rot.y) * -130.0f) + player->actor.world.pos.x;
				sCameraNextEye.z = (Math_CosS(player->actor.shape.rot.y) * -130.0f) + player->actor.world.pos.z;
				sCameraNextEye.y = player->actor.world.pos.y + 55.0f;

				sCameraAtMaxVel = sCameraEyeMaxVel = sZeroVec;

				sCsState++;
				pthis->timer = 133;
			}
			break;
		case DEATH_MUSIC:
			Math_SmoothStepToF(&sCameraEyeMaxVel.x, 1.5f, 0.3f, 0.05f, 0.015f);
			sCameraEyeMaxVel.z = sCameraEyeMaxVel.x;
			sCameraEyeMaxVel.y = sCameraEyeMaxVel.z;
			sCameraAtMaxVel = sCameraEyeMaxVel;

			pthis->timer--;
			if(pthis->timer == 0)
			{
				Gameplay_ClearCamera(globalCtx, sCsCamera);
				sCsCamera = 0;
				func_80064534(globalCtx, &globalCtx->csCtx);
				Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_ACTIVE);

				camera->eyeNext = camera->eye = sCameraEye;

				camera->at = sCameraAt;

				func_8002DF54(globalCtx, &pthis->actor, 7);
				sCsState++;

				Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0);

				for(i = 2, sp7C = 2; i > 0; i--)
				{
					if(Math_Vec3f_DistXYZ(&sWarpPos[i], &player->actor.world.pos) < Math_Vec3f_DistXYZ(&sWarpPos[i - 1], &player->actor.world.pos))
					{
						sp7C = i - 1;
					}
				}

				Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_RU1, sWarpPos[sp7C].x, sWarpPos[sp7C].y, sWarpPos[sp7C].z, 0, 0, 0, 0);
			}
		case DEATH_FINISH:
			Rand_CenteredFloat(0.5f);
			globalCtx->envCtx.fillScreen = false;
			break;
	}

	if(sCsCamera != 0)
	{
		Math_SmoothStepToF(&sCameraEye.x, sCameraNextEye.x, 0.3f, sCameraEyeMaxVel.x, 0.15f);
		Math_SmoothStepToF(&sCameraEye.y, sCameraNextEye.y, 0.3f, sCameraEyeMaxVel.y, 0.15f);
		Math_SmoothStepToF(&sCameraEye.z, sCameraNextEye.z, 0.3f, sCameraEyeMaxVel.z, 0.15f);
		Math_SmoothStepToF(&sCameraAt.x, sCameraNextAt.x, 0.3f, sCameraAtMaxVel.x, 0.15f);
		Math_SmoothStepToF(&sCameraAt.y, sCameraNextAt.y, 0.3f, sCameraAtMaxVel.y, 0.15f);
		Math_SmoothStepToF(&sCameraAt.z, sCameraNextAt.z, 0.3f, sCameraAtMaxVel.z, 0.15f);
		Gameplay_CameraSetAtEye(globalCtx, sCsCamera, &sCameraAt, &sCameraEye);
	}

	SkelAnime_Update(&pthis->skelAnime);
	Math_SmoothStepToF(&pthis->actor.shape.yOffset, -480.0f, 1.0f, 30.0f, 0.0f);
	Math_SmoothStepToS(&pthis->vaBodySpinRate, 0, 1, 0xC8, 0);
	Math_SmoothStepToS(&pthis->vaCamRotMod, 0, 1, 0xC8, 0);
	Math_SmoothStepToS(&pthis->bodyGlow, 200, 1, 10, 0);
	if(globalCtx->envCtx.screenFillColor[3] != 0)
	{
		globalCtx->envCtx.screenFillColor[3] -= 50;
	}

	Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
	pthis->actor.shape.rot.y += pthis->vaBodySpinRate;
	pthis->unk_1AC += pthis->vaCamRotMod;

	pthis->unk_1A0 = (Math_CosS(pthis->unk_1AC) * 0.1f) + 1.0f;
	pthis->unk_1A4 = (Math_SinS(pthis->unk_1AC) * 0.05f) + 1.0f;
}

void BossVa_SetupSupportIntro(BossVa* pthis, GlobalContext* globalCtx)
{
	Animation_Change(&pthis->skelAnime, &gBarinadeSupportAttachedAnim, 0.0f, 0.0f, Animation_GetLastFrame(&gBarinadeSupportAttachedAnim), ANIMMODE_LOOP_INTERP, 0.0f);
	pthis->timer = 0;
	BossVa_SetupAction(pthis, BossVa_SupportIntro);
}

void BossVa_SupportIntro(BossVa* pthis, GlobalContext* globalCtx)
{
	BossVa_AttachToBody(pthis);
	if(sCsState == BOSSVA_BATTLE)
	{
		BossVa_SetupSupportAttached(pthis, globalCtx);
	}
	else if(sCsState >= INTRO_REVERSE_CAMERA)
	{
		pthis->timer++;
		if((pthis->timer % 2) == 0)
		{
			BossVa_Spark(globalCtx, pthis, 2, 90, 5.0f, 0.0f, SPARK_BODY, ((pthis->timer & 0x20) >> 5) + 1, true);
		}

		SkelAnime_Update(&pthis->skelAnime);
		Math_SmoothStepToF(&pthis->skelAnime.playSpeed, 1.0f, 1.0f, 0.05f, 0.0f);
		if(Rand_ZeroOne() < 0.1f)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
		}
	}
}

void BossVa_SetupSupportAttached(BossVa* pthis, GlobalContext* globalCtx)
{
	Animation_Change(&pthis->skelAnime, &gBarinadeSupportAttachedAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gBarinadeSupportAttachedAnim), ANIMMODE_LOOP, 0.0f);
	pthis->timer = pthis->actor.params * 10;
	BossVa_SetupAction(pthis, BossVa_SupportAttached);
}

void BossVa_SupportAttached(BossVa* pthis, GlobalContext* globalCtx)
{
	pthis->timer++;
	if(sBodyState & 0x7F)
	{
		Actor_SetColorFilter(&pthis->actor, 0, 255, 0, 12);
		if(Rand_ZeroOne() > 0.5f)
		{
			Animation_Change(&pthis->skelAnime, &gBarinadeSupportDamage1Anim, 1.0f, 0.0f, Animation_GetLastFrame(&gBarinadeSupportDamage1Anim), ANIMMODE_ONCE, 0.0f);
		}
		else
		{
			Animation_Change(&pthis->skelAnime, &gBarinadeSupportDamage2Anim, 1.0f, 0.0f, Animation_GetLastFrame(&gBarinadeSupportDamage2Anim), ANIMMODE_ONCE, 0.0f);
		}
	}

	if(SkelAnime_Update(&pthis->skelAnime))
	{
		Animation_Change(&pthis->skelAnime, &gBarinadeSupportAttachedAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gBarinadeSupportAttachedAnim), ANIMMODE_LOOP, 0.0f);
	}

	BossVa_AttachToBody(pthis);
	if(Rand_ZeroOne() < 0.1f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
	}

	if(pthis->colliderSph.base.acFlags & AC_HIT)
	{
		BossVa_SetupSupportCut(pthis, globalCtx);
	}
	else
	{
		if(pthis->actor.colorFilterTimer == 0)
		{
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSph.base);
		}

		if((pthis->timer % 2) == 0)
		{
			BossVa_Spark(globalCtx, pthis, 1, 100, 5.0f, 0.0f, SPARK_BODY, ((pthis->timer & 0x20) >> 5) + 1, true);
		}
	}
}

void BossVa_SetupSupportCut(BossVa* pthis, GlobalContext* globalCtx)
{
	s32 stumpParams = pthis->actor.params + BOSSVA_STUMP_1;

	sBodyState++;
	sFightPhase++;
	Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BOSS_VA, pthis->armTip.x, pthis->armTip.y + 20.0f, pthis->armTip.z, 0, pthis->actor.shape.rot.y, 0, stumpParams);
	Camera_AddQuake(&globalCtx->mainCamera, 2, 11, 8);
	pthis->burst = false;
	pthis->timer2 = 0;
	BossVa_SetupAction(pthis, BossVa_SupportCut);
}

void BossVa_SupportCut(BossVa* pthis, GlobalContext* globalCtx)
{
	BossVa* vaBody = GET_BODY(pthis);
	f32 lastFrame;

	BossVa_AttachToBody(pthis);

	if(pthis->onCeiling)
	{
		lastFrame = Animation_GetLastFrame(&gBarinadeSupportCutAnim);
		pthis->onCeiling = false;
		pthis->timer = (s32)(Rand_ZeroOne() * 10.0f) + 5;
		SkelAnime_Free(&pthis->skelAnime, globalCtx);
		SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBarinadeCutSupportSkel, &gBarinadeSupportCutAnim, NULL, NULL, 0);
		Animation_Change(&pthis->skelAnime, &gBarinadeSupportCutAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, 0.0f);
		sBodyState = 0;
		GET_BODY(pthis)->actor.shape.yOffset -= 60.0f;

		switch(pthis->actor.params)
		{
			case BOSSVA_SUPPORT_1:
				GET_BODY(pthis)->actor.world.rot.x += 0x4B0;
				break;
			case BOSSVA_SUPPORT_2:
				GET_BODY(pthis)->actor.world.rot.x -= 0x258;
				GET_BODY(pthis)->actor.world.rot.z -= 0x4E2;
				break;
			case BOSSVA_SUPPORT_3:
				GET_BODY(pthis)->actor.world.rot.x -= 0x258;
				GET_BODY(pthis)->actor.world.rot.z += 0x4E2;
				break;
		}
	}

	Math_SmoothStepToS(&pthis->headRot.x, vaBody->vaBodySpinRate * -3, 1, 0x4B0, 0);
	if(SkelAnime_Update(&pthis->skelAnime))
	{
		lastFrame = Animation_GetLastFrame(&gBarinadeSupportDetachedAnim);
		Animation_Change(&pthis->skelAnime, &gBarinadeSupportDetachedAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP, 0.0f);
		pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	}

	if((pthis->timer == 0) && (sCsState < DEATH_START))
	{
		pthis->timer = (s32)(Rand_ZeroOne() * 10.0f) + 10;
		BossVa_BloodDroplets(globalCtx, &pthis->armTip, pthis->headRot.x, pthis->actor.shape.rot.y);
	}

	if(sCsState >= DEATH_START)
	{
		Math_SmoothStepToF(&pthis->skelAnime.playSpeed, 0.0f, 0.3f, 0.25f, 0.125f);
	}

	switch(sCsState)
	{
		case DEATH_SHELL_BURST:
			sCameraEye = sCameraNextEye;
			sCameraAt = sCameraNextAt;
			Math_SmoothStepToF(&sCameraEye.x, sCameraNextAt.x, 1.0f, 10.0f, 0.0f);
			Math_SmoothStepToF(&sCameraEye.z, sCameraNextAt.z, 1.0f, 10.0f, 0.0f);
			sCameraEye.y += 20.0f;
			sCsState++;

		case DEATH_CORE_TUMORS:
		case DEATH_CORE_DEAD:
		case DEATH_CORE_BURST:
			if(!pthis->burst)
			{
				if((globalCtx->gameplayFrames % 2) != 0)
				{
					BossVa_Tumor(globalCtx, pthis, 1, (s16)Rand_CenteredFloat(5.0f) + 6, 7.0f, 5.0f, TUMOR_ARM, (pthis->timer2 >> 3) + 1, true);
				}

				pthis->timer2++;
				if(pthis->timer2 >= 32)
				{
					pthis->burst++;
					pthis->isDead = true;
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BREAK2);
					if(pthis->actor.params == BOSSVA_SUPPORT_3)
					{
						sCsState++;
					}
				}
			}
			else
			{
				pthis->timer2--;
				if(pthis->timer2 == 0)
				{
					Actor_Kill(&pthis->actor);
				}
			}
			break;
	}

	pthis->timer--;
}

void BossVa_SetupStump(BossVa* pthis, GlobalContext* globalCtx)
{
	Animation_Change(&pthis->skelAnime, &gBarinadeStumpAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gBarinadeStumpAnim), ANIMMODE_ONCE, 0.0f);
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	BossVa_SetupAction(pthis, BossVa_Stump);
}

void BossVa_Stump(BossVa* pthis, GlobalContext* globalCtx)
{
	if(SkelAnime_Update(&pthis->skelAnime) && (Rand_ZeroOne() < 0.3f))
	{
		pthis->skelAnime.curFrame -= Rand_ZeroOne() * 3.0f;
	}

	if(sCsState >= DEATH_START)
	{
		Actor_Kill(&pthis->actor);
	}
}

void BossVa_SetupZapperIntro(BossVa* pthis, GlobalContext* globalCtx)
{
	f32 lastFrame = Animation_GetLastFrame(&gBarinadeZapperIdleAnim);

	Animation_Change(&pthis->skelAnime, &gBarinadeZapperIdleAnim, 1.0f, lastFrame - 1.0f, lastFrame, ANIMMODE_LOOP_INTERP, -6.0f);
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	BossVa_SetupAction(pthis, BossVa_ZapperIntro);
}

void BossVa_ZapperIntro(BossVa* pthis, GlobalContext* globalCtx)
{
	BossVa_AttachToBody(pthis);

	switch(sCsState)
	{
		case INTRO_TITLE:
		case INTRO_BRIGHTEN:
		case INTRO_FINISH:
			SkelAnime_Update(&pthis->skelAnime);
			break;
		case BOSSVA_BATTLE:
			BossVa_SetupZapperAttack(pthis, globalCtx);
			break;
	}

	Math_SmoothStepToS(&pthis->unk_1F2, pthis->actor.shape.rot.y - pthis->actor.shape.rot.x, 1, 0x2EE, 0);
	Math_SmoothStepToS(&pthis->unk_1F0, pthis->skelAnime.jointTable[7].z, 1, 0x2EE, 0);
}

void BossVa_SetupZapperAttack(BossVa* pthis, GlobalContext* globalCtx)
{
	f32 lastFrame = Animation_GetLastFrame(&gBarinadeZapperIdleAnim);

	Animation_Change(&pthis->skelAnime, &gBarinadeZapperIdleAnim, 1.0f, lastFrame - 1.0f, lastFrame, ANIMMODE_LOOP_INTERP, -6.0f);
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	BossVa_SetupAction(pthis, BossVa_ZapperAttack);
}

void BossVa_ZapperAttack(BossVa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	EnBoom* boomerang;
	Actor* boomTarget;
	s16 yaw;
	s16 sp98;
	s16 sp96;
	s16 sp94;
	s16 tmp17;
	s16 sp90 = 0x1F4;
	s16 sp8E;
	u32 sp88;
	Vec3f sp7C;
	s32 pad3;
	f32 sp74;
	s32 i;
	s16 sp6E;
	s16 sp6C;
	f32 sp68;
	f32 sp64;
	f32 sp60;
	f32 sp5C;
	s16 sp5A;
	s16 sp58;
	s16 sp56;
	s16 sp54;
	f32 sp50;

	boomerang = BossVa_FindBoomerang(globalCtx);

	if((boomerang == NULL) || (boomerang->moveTo == NULL) || (boomerang->moveTo == &player->actor))
	{
		sp7C = player->actor.world.pos;
		sp7C.y += 10.0f;
		sp8E = 0x3E80;
	}
	else
	{
		sp74 = FRAMERATE_ANIM_SCALER;
		sp8E = 0x4650;

		boomTarget = boomerang->moveTo;
		sp7C = boomerang->actor.world.pos;
		sp6C = boomerang->actor.world.rot.y;
		sp56 = boomerang->actor.world.rot.x;

		for(i = boomerang->returnTimer; i >= 3; i--)
		{
			sp6E = Math_Vec3f_Yaw(&sp7C, &boomTarget->focus.pos);
			sp5A = sp6C - sp6E;
			sp58 = Math_Vec3f_Pitch(&sp7C, &boomTarget->focus.pos);
			sp54 = sp56 - sp58;

			sp50 = (200.0f - Math_Vec3f_DistXYZ(&sp7C, &boomTarget->focus.pos)) * 0.005f;
			if(sp50 < 0.12f)
			{
				sp50 = 0.12f;
			}

			if(sp5A < 0)
			{
				sp5A = -sp5A;
			}

			if(sp54 < 0)
			{
				sp54 = -sp54;
			}

			Math_ScaledStepToS(&sp6C, sp6E, sp5A * sp50);
			Math_ScaledStepToS(&sp56, sp58, sp54 * sp50);

			sp68 = -Math_SinS(sp56) * 12.0f;
			sp5C = Math_CosS(sp56) * 12.0f;
			sp64 = Math_SinS(sp6C) * sp5C;
			sp60 = Math_CosS(sp6C);
			sp7C.x += sp64 * sp74;
			sp7C.y += sp68 * sp74;
			sp7C.z += sp60 * sp5C * sp74;
		}
		sp90 = 0x3E80;
	}

	SkelAnime_Update(&pthis->skelAnime);
	BossVa_AttachToBody(pthis);
	if(sFightPhase >= PHASE_4)
	{
		BossVa_SetupZapperEnraged(pthis, globalCtx);
		return;
	}

	if(sBodyState & 0x7F)
	{
		BossVa_SetupZapperDamaged(pthis, globalCtx);
		return;
	}

	if((sFightPhase < PHASE_4) && (GET_BODY(pthis)->actor.speedXZ != 0.0f))
	{
		BossVa_SetupZapperHold(pthis, globalCtx);
		return;
	}

	sp98 = Math_Vec3f_Yaw(&sp7C, &pthis->armTip);
	tmp17 = sp98 - pthis->actor.shape.rot.y;

	if((sp8E >= ABS(tmp17) || pthis->burst) && !(sBodyState & 0x80) && !(player->stateFlags1 & PLAYER_STATE1_26))
	{
		if(!pthis->burst)
		{
			sp94 = sp98 - pthis->actor.shape.rot.y;

			if(ABS(sp94) > 0x1770)
			{
				sp94 = (sp94 > 0) ? 0x1770 : -0x1770;
			}

			tmp17 = Math_SmoothStepToS(&pthis->unk_1E6, sp94, 1, 0x6D6, 0);
			sp88 = ABS(tmp17);

			sp94 = sp98 - sp94;

			if(ABS(sp94) > 0x1770)
			{
				sp94 = (sp94 > 0) ? 0x1770 : -0x1770;
			}

			tmp17 = Math_SmoothStepToS(&pthis->unk_1EC, sp94, 1, 0x6D6, 0);
			sp88 += ABS(tmp17);

			yaw = Math_Vec3f_Yaw(&pthis->zapHeadPos, &sp7C);
			tmp17 = Math_SmoothStepToS(&pthis->unk_1F2, yaw - 0x4000, 1, 0x9C4, 0);
			sp88 += ABS(tmp17);

			sp96 = pthis->actor.shape.rot.x + pthis->skelAnime.jointTable[1].z + pthis->skelAnime.jointTable[2].z + pthis->skelAnime.jointTable[3].z + pthis->skelAnime.jointTable[4].z + pthis->skelAnime.jointTable[5].z;

			yaw = Math_Vec3f_Pitch(&sp7C, &pthis->zapNeckPos);
			tmp17 = Math_SmoothStepToS(&pthis->unk_1EA, yaw - sp96, 1, 0xFA0, 0);
			sp88 += ABS(tmp17);

			yaw = Math_Vec3f_Pitch(&pthis->zapHeadPos, &sp7C);
			tmp17 = Math_SmoothStepToS(&pthis->unk_1F0, -yaw, 1, 0xFA0, 0);
			sp88 += ABS(tmp17);

			pthis->skelAnime.playSpeed = 0.0f;
			if(Math_SmoothStepToF(&pthis->skelAnime.curFrame, 0.0f, 1.0f, 2.0f, 0.0f) == 0.0f)
			{
				if(sp88 < sp90)
				{
					pthis->timer2 = 0;
					pthis->burst++;
					pthis->unk_1D8 = sp7C;
				}

				if(Rand_ZeroOne() < 0.1f)
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
				}
			}
		}
	}
	else
	{
		if(pthis->burst || (pthis->timer2 < 0))
		{
			if(pthis->colliderLightning.base.atFlags & AT_HIT)
			{
				if(pthis->timer2 > 0)
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_HIT_RINK);
					BossVa_SetSparkEnv(globalCtx);
					pthis->timer2 = -1;
					GET_BODY(pthis)->onCeiling = 6; // not used by body
				}
			}
			else if(pthis->timer2 > 0)
			{
				pthis->timer2 = 0;
			}

			if((pthis->timer2 < 0) && (player->stateFlags1 & PLAYER_STATE1_26))
			{
				BossVa_Spark(globalCtx, pthis, 1, 30, 0.0f, 0.0f, SPARK_LINK, 0.0f, true);
			}
		}

		Math_SmoothStepToS(&pthis->unk_1E6, 0, 1, 0x6D6, 0);
		Math_SmoothStepToS(&pthis->unk_1EC, 0, 1, 0x6D6, 0);
		Math_SmoothStepToS(&pthis->unk_1EA, 0, 1, 0x6D6, 0);
		Math_SmoothStepToS(&pthis->unk_1F2, pthis->actor.shape.rot.y - pthis->actor.shape.rot.x, 1, 0x6D6, 0);
		Math_SmoothStepToS(&pthis->unk_1F0, pthis->skelAnime.jointTable[7].z, 1, 0x6D6, 0);
		Math_SmoothStepToF(&pthis->skelAnime.playSpeed, 1.0f, 1.0f, 0.05f, 0.0f);
		pthis->burst = false;
	}

	if(pthis->burst && (pthis->burst != 2))
	{ // burst can never be 2
		if(pthis->timer2 >= 32)
		{
			if(pthis->timer2 == 32)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_THUNDER);
			}
			BossVa_Spark(globalCtx, pthis, 2, 110, 15.0f, 15.0f, SPARK_BLAST, 5.0f, true);
			BossVa_Spark(globalCtx, pthis, 2, 110, 15.0f, 15.0f, SPARK_BLAST, 6.0f, true);
			BossVa_Spark(globalCtx, pthis, 2, 110, 15.0f, 15.0f, SPARK_BLAST, 7.0f, true);
			CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderLightning.base);
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderLightning.base);
		}
		else
		{
			BossVa_Spark(globalCtx, pthis, 2, 50, 15.0f, 0.0f, SPARK_BODY, (pthis->timer2 >> 3) + 1, true);
			if(pthis->timer2 == 30)
			{
				BossVa_SetSparkEnv(globalCtx);
			}
			if(pthis->timer2 == 20)
			{
				Vec3f sp44 = pthis->zapHeadPos;

				BossVa_SpawnZapperCharge(globalCtx, sVaEffects, pthis, &sp44, &pthis->headRot, 100, 0);
			}
		}

		pthis->timer2++;
		if(pthis->timer2 >= 40)
		{
			pthis->burst = false;
		}
	}
}

void BossVa_SetupZapperDamaged(BossVa* pthis, GlobalContext* globalCtx)
{
	if(Rand_ZeroOne() > 0.5f)
	{
		Animation_Change(&pthis->skelAnime, &gBarinadeZapperDamage1Anim, 0.5f, 0.0f, Animation_GetLastFrame(&gBarinadeZapperDamage1Anim), ANIMMODE_ONCE_INTERP, 4.0f);
	}
	else
	{
		Animation_Change(&pthis->skelAnime, &gBarinadeZapperDamage2Anim, 0.5f, 0.0f, Animation_GetLastFrame(&gBarinadeZapperDamage2Anim), ANIMMODE_ONCE_INTERP, 4.0f);
	}

	Actor_SetColorFilter(&pthis->actor, 0, 255, 0, 12);
	pthis->burst = false;
	BossVa_SetupAction(pthis, BossVa_ZapperDamaged);
}

void BossVa_ZapperDamaged(BossVa* pthis, GlobalContext* globalCtx)
{
	BossVa_AttachToBody(pthis);
	Math_SmoothStepToS(&pthis->unk_1E6, 0, 1, 0xFA0, 0);
	Math_SmoothStepToS(&pthis->unk_1E4, 0, 1, 0xFA0, 0);
	Math_SmoothStepToS(&pthis->unk_1EC, 0, 1, 0xFA0, 0);
	Math_SmoothStepToS(&pthis->unk_1EA, 0, 1, 0xFA0, 0);
	Math_SmoothStepToS(&pthis->unk_1F2, pthis->actor.shape.rot.y - pthis->actor.shape.rot.x, 1, 0x2EE, 0);
	Math_SmoothStepToS(&pthis->unk_1F0, pthis->skelAnime.jointTable[7].z, 1, 0x2EE, 0);
	if(SkelAnime_Update(&pthis->skelAnime))
	{
		if(sFightPhase >= PHASE_4)
		{
			BossVa_SetupZapperEnraged(pthis, globalCtx);
		}
		else
		{
			BossVa_SetupZapperAttack(pthis, globalCtx);
		}
	}
}

void BossVa_SetupZapperDeath(BossVa* pthis, GlobalContext* globalCtx)
{
	f32 lastFrame = Animation_GetLastFrame(&gBarinadeZapperIdleAnim);

	Animation_Change(&pthis->skelAnime, &gBarinadeZapperIdleAnim, Rand_ZeroOne() + 0.25f, Rand_ZeroOne() * 3.0f, lastFrame, ANIMMODE_LOOP_INTERP, -6.0f);
	pthis->burst = false;
	pthis->timer2 = (pthis->actor.params * -6) + 18;
	pthis->unk_1B0 = 0;
	BossVa_SetupAction(pthis, BossVa_ZapperDeath);
}

void BossVa_ZapperDeath(BossVa* pthis, GlobalContext* globalCtx)
{
	f32 sp3C = 55.0f;
	f32 tmpf1;
	f32 tmpf2;

	BossVa_AttachToBody(pthis);
	if(((globalCtx->gameplayFrames % 32) == 0) && (sCsState <= DEATH_BODY_TUMORS))
	{
		pthis->unk_1E8 = Rand_CenteredFloat(0x4000);
		pthis->unk_1EE = Rand_CenteredFloat(0x4000);
		pthis->unk_1F4 = (s16)Rand_CenteredFloat(0x4000) + pthis->actor.shape.rot.y - pthis->actor.shape.rot.x;
	}
	else
	{
		Math_SmoothStepToF(&pthis->skelAnime.playSpeed, 0.0f, 1.0f, 0.025f, 0.0f);
	}

	SkelAnime_Update(&pthis->skelAnime);
	Math_SmoothStepToS(&pthis->unk_1E6, pthis->unk_1E8, 1, (s16)Rand_CenteredFloat(500.0f) + 0x1F4, 0);
	Math_SmoothStepToS(&pthis->unk_1E4, 0, 1, 0x1F4, 0);
	Math_SmoothStepToS(&pthis->unk_1EC, pthis->unk_1EE, 1, (s16)Rand_CenteredFloat(500.0f) + 0x1F4, 0);
	Math_SmoothStepToS(&pthis->unk_1EA, 0, 1, 0x1F4, 0);
	Math_SmoothStepToS(&pthis->unk_1F2, pthis->unk_1F4, 1, (s16)Rand_CenteredFloat(500.0f) + 0x1F4, 0);

	switch(sCsState)
	{
		case DEATH_ZAPPER_2:
			sp3C = -55.0f;
		case DEATH_ZAPPER_1:
		case DEATH_ZAPPER_3:
			if(!pthis->burst)
			{
				if(((pthis->actor.params == BOSSVA_ZAPPER_1) && (pthis->timer2 < 16)) || ((pthis->actor.params == BOSSVA_ZAPPER_2) && (pthis->timer2 < 24)) || (pthis->actor.params == BOSSVA_ZAPPER_3))
				{
					if((pthis->timer2 % 2) == 0 && (pthis->timer2 >= 0))
					{
						if(pthis->timer2 < 8)
						{
							BossVa_Tumor(globalCtx, pthis, 1, (s16)Rand_CenteredFloat(5.0f) + 0xD, 0.0f, 0.0f, TUMOR_ARM, 0.6f, true);
						}
						else
						{
							BossVa_Tumor(globalCtx, pthis, 1, (s16)Rand_CenteredFloat(5.0f) + 6, 0.0f, 7.0f, TUMOR_ARM, (pthis->timer2 >> 3) + 1, true);
						}

						BossVa_Spark(globalCtx, pthis, 2, 50, 15.0f, 0.0f, SPARK_BODY, (pthis->timer2 >> 3) + 1, true);
					}

					pthis->timer2++;
					if(pthis->timer2 >= 32)
					{
						pthis->burst++;
						pthis->isDead = true;
						BossVa_SetDeathEnv(globalCtx);
						Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BREAK2);
					}
				}
				else
				{
					pthis->burst++;
					pthis->isDead = true;
					pthis->timer2 = 32;
					sCsState++;
				}

				if((pthis->actor.params - BOSSVA_ZAPPER_1 + DEATH_ZAPPER_1) == sCsState)
				{
					sCameraAt.x = pthis->zapNeckPos.x;
					sCameraEye.y = sCameraAt.y = pthis->zapNeckPos.y;
					sCameraAt.z = pthis->zapNeckPos.z;
					sCameraEye.x = (Math_CosS(-(pthis->actor.shape.rot.y + pthis->unk_1B0)) * sp3C) + pthis->zapNeckPos.x;
					sCameraEye.z = (Math_SinS(-(pthis->actor.shape.rot.y + pthis->unk_1B0)) * sp3C) + pthis->zapNeckPos.z;
					pthis->unk_1B0 += 0x15E;
				}
			}
			else
			{
				pthis->timer2--;
				if(pthis->timer2 == 0)
				{
					if(pthis->actor.params == BOSSVA_ZAPPER_3)
					{
						sCsState++;
					}
					Actor_Kill(&pthis->actor);
				}
			}
			break;
	}
}

void BossVa_SetupZapperEnraged(BossVa* pthis, GlobalContext* globalCtx)
{
	f32 lastFrame = Animation_GetLastFrame(&gBarinadeZapperIdleAnim);

	Animation_Change(&pthis->skelAnime, &gBarinadeZapperIdleAnim, 1.0f, lastFrame - 1.0f, lastFrame, ANIMMODE_LOOP_INTERP, -6.0f);
	pthis->burst = false;
	BossVa_SetupAction(pthis, BossVa_ZapperEnraged);
}

void BossVa_ZapperEnraged(BossVa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	s32 pad;
	s16 tmp16;
	s16 sp6C;
	s16 sp6A;
	s16 sp68;
	s16 yaw;
	u32 sp60;
	Vec3f sp54 = player->actor.world.pos;

	sp54.y += 10.0f;
	SkelAnime_Update(&pthis->skelAnime);
	BossVa_AttachToBody(pthis);
	if(sFightPhase >= PHASE_DEATH)
	{
		BossVa_SetupZapperDeath(pthis, globalCtx);
		return;
	}

	if(sBodyState & 0x7E)
	{
		BossVa_SetupZapperDamaged(pthis, globalCtx);
		return;
	}

	sp54.y += 25.0;

	sp6C = Math_Vec3f_Yaw(&sp54, &pthis->armTip);
	tmp16 = sp6C - pthis->actor.shape.rot.y;

	if((ABS(tmp16) <= 0x4650 || pthis->burst) && !(sBodyState & 0x80) && !(player->stateFlags1 & PLAYER_STATE1_26))
	{
		if(!pthis->burst)
		{
			sp68 = sp6C - pthis->actor.shape.rot.y;
			if(ABS(sp68) > 0x1770)
			{
				sp68 = (sp68 > 0) ? 0x1770 : -0x1770;
			}

			tmp16 = Math_SmoothStepToS(&pthis->unk_1E6, sp68, 1, 0xDAC, 0);
			sp60 = ABS(tmp16);

			sp68 = sp6C - sp68;
			if(ABS(sp68) > 0x1770)
			{
				sp68 = sp68 > 0 ? 0x1770 : -0x1770;
			}

			tmp16 = Math_SmoothStepToS(&pthis->unk_1EC, sp68, 1, 0xDAC, 0);
			sp60 += ABS(tmp16);

			yaw = Math_Vec3f_Yaw(&pthis->zapHeadPos, &sp54);
			tmp16 = Math_SmoothStepToS(&pthis->unk_1F2, yaw - 0x4000, 1, 0xEA6, 0);
			sp60 += ABS(tmp16);

			sp6A = pthis->actor.shape.rot.x + pthis->skelAnime.jointTable[1].x + pthis->skelAnime.jointTable[2].x + pthis->skelAnime.jointTable[3].x + pthis->skelAnime.jointTable[4].x + pthis->skelAnime.jointTable[5].x;

			yaw = Math_Vec3f_Pitch(&sp54, &pthis->zapNeckPos);
			tmp16 = Math_SmoothStepToS(&pthis->unk_1EA, yaw - sp6A, 1, 0x1B58, 0);
			sp60 += ABS(tmp16);

			yaw = Math_Vec3f_Pitch(&pthis->zapHeadPos, &sp54);
			tmp16 = Math_SmoothStepToS(&pthis->unk_1F0, -yaw, 1, 0x1B58, 0);
			sp60 += ABS(tmp16);

			pthis->skelAnime.playSpeed = 0.0f;
			if((Math_SmoothStepToF(&pthis->skelAnime.curFrame, 0.0f, 1.0f, 3.0f, 0.0f) == 0.0f) && (sp60 < 0x258))
			{
				pthis->timer2 = 0;
				pthis->burst++;
				pthis->unk_1D8 = sp54;
				if(Rand_ZeroOne() < 0.1f)
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
				}
			}
		}
	}
	else
	{
		if(pthis->burst || (pthis->timer2 < 0))
		{
			if(pthis->colliderLightning.base.atFlags & AT_HIT)
			{
				if(pthis->timer2 > 0)
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_HIT_RINK);
					BossVa_SetSparkEnv(globalCtx);
					pthis->timer2 = -1;
					GET_BODY(pthis)->onCeiling = 6; // not used by body
				}
			}
			else if(pthis->timer2 > 0)
			{
				pthis->timer2 = 0;
			}

			if((pthis->timer2 < 0) && (player->stateFlags1 & PLAYER_STATE1_26))
			{
				BossVa_Spark(globalCtx, pthis, 1, 30, 0.0f, 0, SPARK_LINK, 0.0f, true);
			}
		}

		Math_SmoothStepToS(&pthis->unk_1E6, 0, 1, 0xEA6, 0);
		Math_SmoothStepToS(&pthis->unk_1EC, 0, 1, 0xEA6, 0);
		Math_SmoothStepToS(&pthis->unk_1EA, 0, 1, 0xEA6, 0);
		Math_SmoothStepToS(&pthis->unk_1F2, pthis->actor.shape.rot.y - pthis->actor.shape.rot.x, 1, 0xEA6, 0);
		Math_SmoothStepToS(&pthis->unk_1F0, pthis->skelAnime.jointTable[7].z, 1, 0xEA6, 0);
		Math_SmoothStepToF(&pthis->skelAnime.playSpeed, 1.0f, 1.0f, 0.05f, 0.0f);
		pthis->burst = false;
	}

	if(pthis->burst && (pthis->burst != 2))
	{ // burst can never be 2
		if(pthis->timer2 >= 16)
		{
			if(pthis->timer2 == 18)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_THUNDER);
			}

			BossVa_Spark(globalCtx, pthis, 2, 110, 15.0f, 15.0f, SPARK_BLAST, 5.0f, true);
			BossVa_Spark(globalCtx, pthis, 2, 110, 15.0f, 15.0f, SPARK_BLAST, 6.0f, true);
			BossVa_Spark(globalCtx, pthis, 2, 110, 15.0f, 15.0f, SPARK_BLAST, 7.0f, true);
			CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderLightning.base);
			CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderLightning.base);
		}
		else
		{
			BossVa_Spark(globalCtx, pthis, 2, 50, 15.0f, 0.0f, SPARK_BODY, (pthis->timer2 >> 1) + 1, true);
			if(pthis->timer2 == 14)
			{
				BossVa_SetSparkEnv(globalCtx);
			}
			if(pthis->timer2 == 4)
			{
				Vec3f sp48 = pthis->zapHeadPos;

				BossVa_SpawnZapperCharge(globalCtx, sVaEffects, pthis, &sp48, &pthis->headRot, 100, 0);
			}
		}

		pthis->timer2++;
		if(pthis->timer2 >= 24)
		{
			pthis->burst = false;
		}
	}
}

void BossVa_SetupZapperHold(BossVa* pthis, GlobalContext* globalCtx)
{
	Animation_Change(&pthis->skelAnime, &gBarinadeZapperDamage2Anim, 0.0f, 0.0f, Animation_GetLastFrame(&gBarinadeZapperDamage2Anim), ANIMMODE_ONCE_INTERP, -6.0f);
	pthis->burst = false;
	BossVa_SetupAction(pthis, BossVa_ZapperHold);
}

void BossVa_ZapperHold(BossVa* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	BossVa_AttachToBody(pthis);
	Math_SmoothStepToS(&pthis->unk_1E6, 0, 1, 0x1770, 0);
	Math_SmoothStepToS(&pthis->unk_1E4, 0, 1, 0x1770, 0);
	Math_SmoothStepToS(&pthis->unk_1EC, 0, 1, 0x1770, 0);
	Math_SmoothStepToS(&pthis->unk_1EA, 0, 1, 0x1770, 0);
	Math_SmoothStepToS(&pthis->unk_1F2, pthis->actor.shape.rot.y - 0x4000, 1, 0x2710, 0);
	Math_SmoothStepToS(&pthis->unk_1F0, pthis->skelAnime.jointTable[7].z - 0x1388, 1, 0x1770, 0);
	if(GET_BODY(pthis)->actor.speedXZ == 0.0f)
	{
		BossVa_SetupZapperAttack(pthis, globalCtx);
	}
}

void BossVa_SetupBariIntro(BossVa* pthis, GlobalContext* globalCtx)
{
	Animation_Change(&pthis->skelAnime, &gBarinadeBariAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gBarinadeBariAnim), ANIMMODE_LOOP, 0.0f);
	pthis->unk_1A0 = 60.0f;
	pthis->unk_1A4 = Rand_ZeroOne() * 360.0f;
	pthis->timer2 = 64;
	pthis->unk_1F0 = 120;
	pthis->unk_1A8 = 0.0f;
	pthis->actor.world.pos.x = sInitPosOffsets[pthis->actor.params + 10].x + pthis->actor.home.pos.x;
	pthis->actor.world.pos.y = sInitPosOffsets[pthis->actor.params + 10].y + pthis->actor.home.pos.y;
	pthis->actor.world.pos.z = sInitPosOffsets[pthis->actor.params + 10].z + pthis->actor.home.pos.z;
	pthis->timer = 45;
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	BossVa_SetupAction(pthis, BossVa_BariIntro);
}

void BossVa_BariIntro(BossVa* pthis, GlobalContext* globalCtx)
{
	Vec3f sp54 = pthis->actor.home.pos;
	f32 sp50 = 40.0f;
	s16 sp4E;
	s16 tmp;

	if(pthis->actor.home.pos.y >= 0.0f)
	{
		sp54.y += 25.0f;
	}

	pthis->unk_1A4 += Rand_ZeroOne() * 0.25f;

	switch(sCsState)
	{
		case INTRO_LOOK_BARI:
			if(pthis->actor.params == BOSSVA_BARI_UPPER_1)
			{
				func_8002DF54(globalCtx, &pthis->actor, 1);
				if(Math_SmoothStepToF(&pthis->actor.world.pos.y, 60.0f, 0.3f, 1.0f, 0.15f) == 0.0f)
				{
					pthis->timer--;
					if(pthis->timer == 0)
					{
						sCsState++;
					}
				}
			}
			pthis->actor.shape.rot.x = 0;
			break;
		case INTRO_REVERSE_CAMERA:
		case INTRO_SUPPORT_CAMERA:
		case INTRO_BODY_SOUND:
		case INTRO_LOOK_SUPPORT:
			if(pthis->actor.params != BOSSVA_BARI_UPPER_1)
			{
				Math_SmoothStepToF(&pthis->actor.world.pos.y, sInitPosOffsets[pthis->actor.params + 10].y + pthis->actor.home.pos.y, 0.3f, 1.0f, 0.15f);
				pthis->actor.world.pos.x += (Math_SinF(pthis->unk_1A4 * 0.25f) * 0.5f);
			}
			else
			{
				Math_SmoothStepToF(&pthis->actor.world.pos.y, 60.0f, 0.3f, 1.0f, 0.15f);
			}
			pthis->actor.world.pos.y += Math_SinF(pthis->unk_1A4) * (2.0f - Math_SinF(pthis->unk_1A4));
			break;
		case INTRO_CALL_BARI:
		case INTRO_ATTACH_BARI:
			if((pthis->timer2 > 15) && (pthis->timer < 0))
			{
				Math_SmoothStepToF(&pthis->actor.world.pos.x, sp54.x, 1.0f, 6.5f, 0.0f);
				Math_SmoothStepToF(&pthis->actor.world.pos.y, sp54.y, 1.0f, 6.5f, 0.0f);
				Math_SmoothStepToF(&pthis->actor.world.pos.z, sp54.z, 1.0f, 6.5f, 0.0f);

				sp50 = Math_Vec3f_DistXYZ(&sp54, &pthis->actor.world.pos);
				if(sp50 <= 60.0f)
				{
					tmp = Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->actor.home.rot.x, 1, 0x7D0, 0);
					sp4E = ABS(tmp);

					tmp = Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y, 1, 0x7D0, 0);
					sp4E += ABS(tmp);

					if((sp50 == 0.0f) && (sp4E == 0))
					{
						if(!pthis->isDead)
						{
							if(pthis->actor.params >= BOSSVA_BARI_LOWER_1)
							{
								if(pthis->actor.params == BOSSVA_BARI_LOWER_1)
								{
									sBodyBari[0]++;
								}
								else
								{
									sBodyBari[pthis->actor.params - BOSSVA_BARI_UPPER_1]++;
								}
							}
							else
							{
								sBodyBari[pthis->actor.params - BOSSVA_BARI_UPPER_1 + 1]++;
							}
							pthis->timer = -30;
							pthis->isDead++;
						}
						else
						{
							pthis->timer++;
							if(pthis->timer == 0)
							{
								Actor_Kill(&pthis->actor);
							}
						}
						return;
					}
				}
			}
		case INTRO_UNUSED_CALL_BARI:
			pthis->timer--;
			if(pthis->timer == 0)
			{
				pthis->timer2 = 0;
			}
			else
			{
				func_80035844(&GET_BODY(pthis)->actor.world.pos, &pthis->actor.world.pos, &pthis->actor.world.rot, false);
				pthis->unk_1A0 = Math_Vec3f_DistXYZ(&GET_BODY(pthis)->actor.world.pos, &pthis->actor.world.pos);
				if(sp50 > 30.0f)
				{
					BossVa_Spark(globalCtx, pthis, 1, 80, 15.0f, 0.0f, SPARK_BARI, 1.0f, true);
				}
			}
			break;
		case BOSSVA_BATTLE:
			pthis->timer++;
			if(pthis->timer == 0)
			{
				Actor_Kill(&pthis->actor);
			}
			return;
		case INTRO_TITLE:
		case INTRO_BRIGHTEN:
		case INTRO_FINISH:
			break;
	}

	if(((globalCtx->gameplayFrames % 4) == 0) && (sCsState < INTRO_ATTACH_BARI))
	{
		BossVa_Spark(globalCtx, pthis, 1, 70, 25.0f, 20.0f, SPARK_BARI, 2.0f, true);
	}

	if(Rand_ZeroOne() < 0.1f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
	}
}

void BossVa_SetupBariPhase3Attack(BossVa* pthis, GlobalContext* globalCtx)
{
	Animation_Change(&pthis->skelAnime, &gBarinadeBariAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gBarinadeBariAnim), ANIMMODE_LOOP, 0.0f);
	pthis->timer2 = 0x80;
	pthis->unk_1F0 = 0x78;
	pthis->unk_1A0 = 60.0f;
	pthis->unk_1A8 = 0.0f;
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	BossVa_SetupAction(pthis, BossVa_BariPhase3Attack);
}

void BossVa_BariPhase3Attack(BossVa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	EnBoom* boomerang;
	Vec3f sp54 = GET_BODY(pthis)->unk_1D8;
	s16 sp52;
	s32 pad;

	pthis->unk_1A4 += Rand_ZeroOne() * 0.5f;
	sp52 = pthis->timer2 & 0x1FF;

	if((globalCtx->gameplayFrames % 128) == 0)
	{
		pthis->vaBariUnused.x = (s16)(Rand_ZeroOne() * 100.0f) + 100;
	}

	Math_SmoothStepToS(&pthis->vaBariUnused.z, pthis->vaBariUnused.x, 1, 0x1E, 0);
	pthis->vaBariUnused.y += pthis->vaBariUnused.z;
	if((pthis->colliderLightning.base.atFlags & AT_HIT) || (pthis->colliderSph.base.atFlags & AT_HIT))
	{
		if((pthis->colliderLightning.base.at == &player->actor) || (pthis->colliderSph.base.at == &player->actor))
		{
			func_8002F71C(globalCtx, &pthis->actor, 8.0f, GET_BODY(pthis)->actor.yawTowardsPlayer, 8.0f);
			Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
			pthis->colliderSph.base.at = NULL;
			pthis->colliderLightning.base.at = NULL;
		}

		pthis->colliderLightning.base.atFlags &= ~AT_HIT;
		pthis->colliderSph.base.atFlags &= ~AT_HIT;
	}

	if(pthis->colliderSph.base.acFlags & AC_HIT)
	{
		pthis->colliderSph.base.acFlags &= ~AC_HIT;
		if((pthis->colliderSph.base.ac->id == ACTOR_EN_BOOM) && (sp52 >= 128))
		{
			boomerang = (EnBoom*)pthis->colliderSph.base.ac;
			boomerang->returnTimer = 0;
			boomerang->moveTo = &player->actor;
			boomerang->actor.world.rot.y = boomerang->actor.yawTowardsPlayer;
			Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_SHIELD_REFLECT_SW);
		}
	}

	pthis->actor.world.pos.x = (Math_SinS(pthis->actor.world.rot.y) * pthis->unk_1A0) + sp54.x;
	pthis->actor.world.pos.z = (Math_CosS(pthis->actor.world.rot.y) * pthis->unk_1A0) + sp54.z;
	Math_SmoothStepToF(&pthis->actor.world.pos.y, 4.0f, 1.0f, 2.0f, 0.0f);
	pthis->actor.world.pos.y += 2.0f * Math_SinF(pthis->unk_1A4);
	pthis->actor.world.rot.x = Math_Vec3f_Pitch(&sp54, &pthis->actor.world.pos);
	Math_SmoothStepToF(&pthis->unk_1A0, 160.0f, 1.0f, 2.0f, 0.0f);
	Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0, 1, 0x5DC, 0);
	if(!(pthis->timer2 & 0x200))
	{
		pthis->unk_1AC = 0xBB8;
	}
	else
	{
		pthis->unk_1AC = -0xBB8;
	}

	if(sp52 >= 128)
	{
		BossVa_Spark(globalCtx, pthis, 1, 75, 15.0f, 7.0f, SPARK_TETHER, 1.0f, true);
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSph.base);
		sPhase3StopMoving = false;
	}
	else
	{
		sPhase3StopMoving = true;
	}

	CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderLightning.base);
	CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSph.base);
	if((globalCtx->gameplayFrames % 4) == 0)
	{
		Math_SmoothStepToS(&pthis->unk_1F0, 0x78, 1, 0xA, 0);
	}

	if(Rand_ZeroOne() < 0.1f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
	}

	pthis->actor.world.rot.y += pthis->unk_1AC;
	if(sBodyState & 0x7F)
	{
		BossVa_SetupBariPhase3Stunned(pthis, globalCtx);
	}
}

void BossVa_SetupBariPhase2Attack(BossVa* pthis, GlobalContext* globalCtx)
{
	Animation_Change(&pthis->skelAnime, &gBarinadeBariAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gBarinadeBariAnim), ANIMMODE_LOOP, 0.0f);
	pthis->timer2 = 0x40;
	pthis->unk_1F0 = 0x78;
	pthis->unk_1A0 = 60.0f;
	pthis->unk_1A8 = 0.0f;
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	BossVa_SetupAction(pthis, BossVa_BariPhase2Attack);
}

void BossVa_BariPhase2Attack(BossVa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	EnBoom* boomerang;
	Vec3f sp54 = GET_BODY(pthis)->unk_1D8;
	s16 sp52;
	s16 sp50;
	f32 sp4C;
	s32 pad;

	pthis->unk_1A4 += Rand_ZeroOne() * 0.5f;
	sp52 = pthis->timer2 & 0x1FF;
	if((globalCtx->gameplayFrames % 128) == 0)
	{
		pthis->vaBariUnused.x = (s16)(Rand_ZeroOne() * 100.0f) + 100;
	}

	sp50 = (sFightPhase * 70) - 280;
	Math_SmoothStepToS(&pthis->vaBariUnused.z, pthis->vaBariUnused.x, 1, 0x1E, 0);
	pthis->vaBariUnused.y += pthis->vaBariUnused.z;
	if(sKillBari != 0)
	{
		sKillBari--;
		BossVa_KillBari(pthis, globalCtx);
		return;
	}

	if((pthis->colliderLightning.base.atFlags & AT_HIT) || (pthis->colliderSph.base.atFlags & AT_HIT))
	{
		if((pthis->colliderLightning.base.at == &player->actor) || (pthis->colliderSph.base.at == &player->actor))
		{
			func_8002F71C(globalCtx, &pthis->actor, 8.0f, GET_BODY(pthis)->actor.yawTowardsPlayer, 8.0f);
			Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
			pthis->colliderSph.base.at = NULL;
			pthis->colliderLightning.base.at = NULL;
		}

		pthis->colliderLightning.base.atFlags &= ~AT_HIT;
		pthis->colliderSph.base.atFlags &= ~AT_HIT;
	}

	Math_SmoothStepToF(&pthis->actor.world.pos.y, 4.0f, 1.0f, 2.0f, 0.0f);
	pthis->actor.world.rot.x = Math_Vec3f_Pitch(&sp54, &pthis->actor.world.pos);
	if((globalCtx->gameplayFrames % 8) == 0)
	{
		Math_SmoothStepToS(&pthis->unk_1F0, 0x28, 1, 0xA, 0);
		BossVa_Spark(globalCtx, pthis, 1, pthis->unk_1F0, 25.0f, 20.0f, 2, 2.0f, true);
	}

	if(!(sPhase2Timer & 0x100) && (GET_BODY(pthis)->actor.colorFilterTimer == 0))
	{
		sp4C = 200.0f;
		BossVa_Spark(globalCtx, pthis, 1, 125, 15.0f, 7.0f, SPARK_TETHER, 1.0f, true);
		pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
		if(pthis->actor.params & 1)
		{
			sp4C = -200.0f;
		}

		Math_SmoothStepToF(&pthis->unk_1A0, (Math_SinS(sPhase2Timer * 0x190) * sp4C) + 320.0f, 1.0f, 10.0f, 0.0f);
		Math_SmoothStepToS(&pthis->unk_1AC, sp50 + 0x1F4, 1, 0x3C, 0);
		pthis->actor.world.pos.y += 2.0f * Math_SinF(pthis->unk_1A4);
		if(pthis->colliderSph.base.acFlags & AC_HIT)
		{
			pthis->colliderSph.base.acFlags &= ~AC_HIT;

			if((pthis->colliderSph.base.ac->id == ACTOR_EN_BOOM) && (sp52 >= 64))
			{
				boomerang = (EnBoom*)pthis->colliderSph.base.ac;
				boomerang->returnTimer = 0;
				boomerang->moveTo = &player->actor;
				boomerang->actor.world.rot.y = boomerang->actor.yawTowardsPlayer;
				Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_SHIELD_REFLECT_SW);
			}
		}

		CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderLightning.base);
		CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSph.base);
	}
	else
	{
		pthis->actor.flags |= ACTOR_FLAG_VISIBLE;
		Math_SmoothStepToS(&pthis->unk_1AC, sp50 + 150, 1, 0x3C, 0);
		if(GET_BODY(pthis)->actor.colorFilterTimer == 0)
		{
			Math_SmoothStepToF(&pthis->unk_1A0, 180.0f, 1.0f, 1.5f, 0.0f);
		}
		else
		{
			pthis->unk_1AC = 0;
			if(pthis->actor.colorFilterTimer == 0)
			{
				Actor_SetColorFilter(&pthis->actor, 0, 255, 0x2000, GET_BODY(pthis)->actor.colorFilterTimer);
			}
		}

		pthis->actor.world.pos.y += Math_SinF(pthis->unk_1A4) * 4.0f;
		if(pthis->colliderSph.base.acFlags & AC_HIT)
		{
			BossVa_KillBari(pthis, globalCtx);
		}
	}

	Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0, 1, 0x5DC, 0);
	CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSph.base);
	if((globalCtx->gameplayFrames % 4) == 0)
	{
		Math_SmoothStepToS(&pthis->unk_1F0, 0x78, 1, 0xA, 0);
	}

	if(Rand_ZeroOne() < 0.1f)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_SPARK - SFX_FLAG);
	}

	if(GET_BODY(pthis)->actor.colorFilterTimer == 0)
	{
		if(!(pthis->timer2 & 0x400))
		{
			pthis->actor.world.rot.y += pthis->unk_1AC;
		}
		else
		{
			pthis->actor.world.rot.y -= pthis->unk_1AC;
		}

		pthis->actor.world.pos.x = (Math_SinS(pthis->actor.world.rot.y) * pthis->unk_1A0) + sp54.x;
		pthis->actor.world.pos.z = (Math_CosS(pthis->actor.world.rot.y) * pthis->unk_1A0) + sp54.z;
	}
}

void BossVa_SetupBariPhase3Stunned(BossVa* pthis, GlobalContext* globalCtx)
{
	pthis->actor.flags |= ACTOR_FLAG_VISIBLE;
	pthis->timer = GET_BODY(pthis)->timer;
	Actor_SetColorFilter(&pthis->actor, 0, 255, 0x2000, pthis->timer);
	BossVa_SetupAction(pthis, BossVa_BariPhase3Stunned);
}

void BossVa_BariPhase3Stunned(BossVa* pthis, GlobalContext* globalCtx)
{
	s32 sp44_pad;
	Vec3f sp40 = GET_BODY(pthis)->unk_1D8;

	pthis->actor.world.rot.x = Math_Vec3f_Pitch(&GET_BODY(pthis)->actor.world.pos, &pthis->actor.world.pos);
	if(pthis->colliderSph.base.acFlags & AC_HIT)
	{
		BossVa_KillBari(pthis, globalCtx);
		return;
	}

	pthis->unk_1A4 += Rand_ZeroOne() * 0.5f;
	Math_SmoothStepToF(&pthis->actor.world.pos.y, 4.0f, 1.0f, 2.0f, 0.0f);
	pthis->actor.world.pos.y += Math_SinF(pthis->unk_1A4) * 3.0f;
	CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSph.base);
	if((globalCtx->gameplayFrames % 4) == 0)
	{
		Math_SmoothStepToS(&pthis->unk_1F0, 0x28, 1, 0xA, 0);
		BossVa_Spark(globalCtx, pthis, 1, pthis->unk_1F0, 25.0f, 20.0f, SPARK_BARI, 2.0f, true);
	}

	pthis->timer--;
	pthis->actor.world.rot.x = Math_Vec3f_Pitch(&sp40, &pthis->actor.world.pos);
	if(pthis->timer <= 0)
	{
		if(pthis->timer == 0)
		{
			pthis->timer2 = 0;
		}
		else
		{
			BossVa_Spark(globalCtx, pthis, 1, 85, 15.0f, 0.0f, SPARK_TETHER, 1.0f, true);
			if(pthis->timer2 >= 0x10)
			{
				pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
				pthis->timer2 = 0x80;
				BossVa_SetupAction(pthis, BossVa_BariPhase3Attack);
			}
		}
	}
}

void BossVa_SetupBariDeath(BossVa* pthis)
{
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	pthis->timer = 30;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BALINADE_BL_DEAD);
	pthis->isDead++;
	BossVa_SetupAction(pthis, BossVa_BariDeath);
}

void BossVa_BariDeath(BossVa* pthis, GlobalContext* globalCtx)
{
	pthis->timer--;
	if(pthis->timer == 0)
	{
		Actor_Kill(&pthis->actor);
	}
}

void BossVa_SetupDoor(BossVa* pthis, GlobalContext* globalCtx)
{
	if(sCsState >= INTRO_SPAWN_BARI)
	{
		sDoorState = 100;
	}
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	BossVa_SetupAction(pthis, BossVa_Door);
}

void BossVa_Door(BossVa* pthis, GlobalContext* globalCtx)
{
	if(sDoorState == 29)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_BUYODOOR_CLOSE);
	}

	if(sCsState <= INTRO_DOOR_SHUT)
	{
		if(sDoorState < 100)
		{
			sDoorState += 8;
		}
		else
		{
			sDoorState = 100;
		}
	}
}

void BossVa_Update(Actor* thisx, GlobalContext* globalCtx2)
{
	GlobalContext* globalCtx = globalCtx2;
	BossVa* pthis = (BossVa*)thisx;
	EnBoom* boomerang;
	s32 i;

	pthis->actionFunc(pthis, globalCtx);

	switch(pthis->actor.params)
	{
		case BOSSVA_BODY:
			if(pthis->colliderBody.base.acFlags & AC_HIT)
			{
				pthis->colliderBody.base.acFlags &= ~AC_HIT;
				if(pthis->colliderBody.base.ac->id == ACTOR_EN_BOOM)
				{
					boomerang = (EnBoom*)pthis->colliderBody.base.ac;
					boomerang->returnTimer = 0;
				}
			}

			BossVa_UpdateEffects(globalCtx);

			for(i = 2; i >= 0; i--)
			{
				if((globalCtx->envCtx.adjAmbientColor[i] - 1) > 0)
				{
					globalCtx->envCtx.adjAmbientColor[i] -= 1;
				}
				else
				{
					globalCtx->envCtx.adjAmbientColor[i] = 0;
				}

				if((globalCtx->envCtx.adjLight1Color[i] - 10) > 0)
				{
					globalCtx->envCtx.adjLight1Color[i] -= 10;
				}
				else
				{
					globalCtx->envCtx.adjLight1Color[i] = 0;
				}

				if((globalCtx->envCtx.adjFogColor[i] - 10) > 0)
				{
					globalCtx->envCtx.adjFogColor[i] -= 10;
				}
				else
				{
					globalCtx->envCtx.adjFogColor[i] = 0;
				}
			}

			if(pthis->onCeiling > 0)
			{
				pthis->onCeiling--; // not used by body
			}
			break;

		default:
			pthis->timer2++;
			pthis->actor.focus.pos = pthis->actor.world.pos;
			pthis->actor.focus.pos.y += 45.0f;
			pthis->unk_1D8.y = (Math_CosS(pthis->timer2 * 0xFA4) * 0.24f) + 0.76f;
			pthis->unk_1D8.x = (Math_SinS(pthis->timer2 * 0xFA4) * 0.2f) + 1.0f;
			break;

		case BOSSVA_SUPPORT_1:
		case BOSSVA_SUPPORT_2:
		case BOSSVA_SUPPORT_3:
		case BOSSVA_ZAPPER_1:
		case BOSSVA_ZAPPER_2:
		case BOSSVA_ZAPPER_3:
		case BOSSVA_DOOR:
			break;
	}
}

s32 BossVa_BodyOverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	BossVa* pthis = (BossVa*)thisx;
	s32 pad;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 4156);

	if(limbIndex == 20)
	{
		gDPPipeSync(POLY_OPA_DISP++);
		gSPSegment(POLY_OPA_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 0, 0, 8, 16, 1, 0, (globalCtx->gameplayFrames.whole() * -2) % 64, 16, 16));
		gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, pthis->bodyGlow);
		Matrix_RotateX(-M_PI / 2, MTXMODE_APPLY);
	}
	else if((limbIndex >= 10) && (limbIndex < 20))
	{
		rot->x -= 0x4000;
		*dList = NULL;
	}
	else if(limbIndex == 6)
	{
		Matrix_Scale(pthis->unk_1A4, pthis->unk_1A4, pthis->unk_1A4, MTXMODE_APPLY);
	}
	else if(limbIndex == 61)
	{
		Matrix_Scale(pthis->unk_1A0, pthis->unk_1A0, pthis->unk_1A0, MTXMODE_APPLY);
	}
	else if(limbIndex == 7)
	{
		rot->x -= 0xCCC;
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 4183);
	return false;
}

void BossVa_BodyPostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	BossVa* pthis = (BossVa*)thisx;
	Vec3f sp78 = {0.0f, 0.0f, 0.0f};
	s32 pad;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 4192);

	if(limbIndex == 6)
	{
		if(sFightPhase < PHASE_3)
		{
			sp78.x = -1000.0f;
		}
		else
		{
			sp78.x = 200.0f;
		}
		Matrix_MultVec3f(&sp78, &pthis->unk_1D8);
	}
	else if((limbIndex >= 10) && (limbIndex < 20) && (sBodyBari[limbIndex - 10] != 0))
	{
		if(((limbIndex >= 16) || (limbIndex == 10)) && (sFightPhase <= PHASE_3))
		{
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_boss_va.c", 4208), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_008BB8);
		}
		else if((limbIndex >= 11) && (sFightPhase <= PHASE_2))
		{
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_boss_va.c", 4212), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_008BB8);
		}

		if(sCsState >= DEATH_START)
		{
			sp78.x = Rand_CenteredFloat(530.0f);
			sp78.y = Rand_CenteredFloat(530.0f);
			sp78.z = -60.0f;
		}
		Matrix_MultVec3f(&sp78, &pthis->effectPos[limbIndex - 10]);
	}
	else if(limbIndex == 25)
	{
		gSPSegment(POLY_XLU_DISP++, 0x09, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 0, (globalCtx->gameplayFrames.whole() * 10) % 128, 16, 32, 1, 0, (globalCtx->gameplayFrames.whole() * 5) % 128, 16, 32));
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_boss_va.c", 4232), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_008D70);
	}
	else if((*dList != NULL) && (limbIndex >= 29) && (limbIndex < 56))
	{
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_boss_va.c", 4236), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, *dList);
	}
	else if((limbIndex == 24) && (sCsState < DEATH_START))
	{
		sp78.x = (pthis->actor.shape.yOffset + 450.0f) + -140.0f;
		Matrix_MultVec3f(&sp78, &pthis->unk_280);
		sp78.x = 200.0f;
		Matrix_MultVec3f(&sp78, &pthis->unk_274);
	}

	if((limbIndex == 7) && (sCsState >= DEATH_START))
	{
		sp78.x = Rand_CenteredFloat(320.0f) + -250.0f;
		sp78.y = Rand_CenteredFloat(320.0f);
		sp78.z = Rand_CenteredFloat(320.0f);

		if(sp78.y < 0.0f)
		{
			sp78.y -= 150.0f;
		}
		else
		{
			sp78.y += 150.0f;
		}

		if(sp78.z < 0.0f)
		{
			sp78.z -= 150.0f;
		}
		else
		{
			sp78.z += 150.0f;
		}
		Matrix_MultVec3f(&sp78, &pthis->unk_274);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 4264);
}

s32 BossVa_SupportOverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	BossVa* pthis = (BossVa*)thisx;

	if(!pthis->onCeiling && (limbIndex == 4))
	{
		rot->z += pthis->headRot.x;
	}
	return false;
}

void BossVa_SupportPostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	BossVa* pthis = (BossVa*)thisx;
	Vec3f sp20 = {0.0f, 0.0f, 0.0f};
	s32 pad;

	if(pthis->onCeiling)
	{
		switch(limbIndex)
		{
			case 4:
				Matrix_MultVec3f(&sZeroVec, &pthis->actor.focus.pos);
				Collider_UpdateSpheres(0, &pthis->colliderSph);
				break;
			case 7:
				Matrix_MultVec3f(&sZeroVec, &pthis->armTip);
				sp20.x = ((pthis->timer & 0x1F) >> 1) * -40.0f;
				sp20.y = ((pthis->timer & 0x1F) >> 1) * -7.0f;
				Matrix_MultVec3f(&sp20, &pthis->effectPos[0]);
				break;
			case 9:
				sp20.x = ((pthis->timer & 0x1F) >> 1) * -60.0f;
				sp20.y = ((pthis->timer & 0x1F) >> 1) * -45.0f;
				Matrix_MultVec3f(&sp20, &pthis->effectPos[1]);
				break;
		}
	}
	else
	{
		switch(limbIndex)
		{
			case 5:
				Matrix_MultVec3f(&sZeroVec, &pthis->armTip);
				break;
			case 8:
				sp20.x = (pthis->timer2 & 7) * 90.0f;
				Matrix_MultVec3f(&sp20, &pthis->effectPos[2]);
				break;
			case 9:
				sp20.x = (pthis->timer2 & 7) * 50.0f;
				Matrix_MultVec3f(&sp20, &pthis->effectPos[1]);
				break;
			case 10:
				sp20.x = (pthis->timer2 & 7) * 46.0f;
				Matrix_MultVec3f(&sp20, &pthis->effectPos[0]);
				break;
		}
	}
}

s32 BossVa_ZapperOverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	BossVa* pthis = (BossVa*)thisx;
	MtxF zapperMtx;

	switch(limbIndex)
	{
		case 4:
			rot->y += pthis->unk_1E6;
			rot->z += pthis->unk_1E4;
			break;
		case 5:
			rot->y += pthis->unk_1EC;
			rot->z += pthis->unk_1EA;
			break;
		case 7:
			Matrix_Translate(pos->x, pos->y, pos->z, MTXMODE_APPLY);
			Matrix_Get(&zapperMtx);
			Matrix_MtxFToZYXRotS(&zapperMtx, &sZapperRot, false);
			Matrix_RotateX(-sZapperRot.x * (M_PI / 0x8000), MTXMODE_APPLY);
			Matrix_RotateY(-sZapperRot.y * (M_PI / 0x8000), MTXMODE_APPLY);
			Matrix_RotateZ(-sZapperRot.z * (M_PI / 0x8000), MTXMODE_APPLY);
			Matrix_RotateY(pthis->unk_1F2 * (M_PI / 0x8000), MTXMODE_APPLY);
			Matrix_RotateZ(pthis->unk_1F0 * (M_PI / 0x8000), MTXMODE_APPLY);
			pos->x = pos->y = pos->z = 0.0f;
			rot->x = rot->y = rot->z = 0;
			break;
	}
	return false;
}

void BossVa_ZapperPostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	BossVa* pthis = (BossVa*)thisx;
	Vec3f sp70 = {0.0f, 0.0f, 0.0f};
	Vec3f sp64 = {15.0f, 0.0f, 0.0f};
	Vec3f sp58 = {-15.0f, 0.0f, 0.0f};
	Vec3f sp4C = {15.0f, 0.0f, 0.0f};
	Vec3f sp40 = {-15.0f, 0.0f, 0.0f};
	s16 sp3E;
	s16 sp3C;

	switch(limbIndex)
	{
		case 3:
			sp70.x = (pthis->timer2 & 7) * 30.0f;
			Matrix_MultVec3f(&sp70, &pthis->effectPos[0]);
			break;

		case 4:
			Matrix_MultVec3f(&sZeroVec, &pthis->armTip);
			sp70.x = (pthis->timer2 & 7) * 30.0f;
			Matrix_MultVec3f(&sp70, &pthis->effectPos[1]);
			break;

		case 5:
			Matrix_MultVec3f(&sZeroVec, &pthis->zapNeckPos);
			sp70.x = (pthis->timer2 & 7) * 46.0f;
			Matrix_MultVec3f(&sp70, &pthis->effectPos[2]);
			break;

		case 7:
			Matrix_MultVec3f(&sZeroVec, &pthis->zapHeadPos);
			sp70.x = (pthis->timer2 & 7) * 46.0f;
			Matrix_MultVec3f(&sp70, &pthis->effectPos[3]);
			sp70.x = 20.0f;
			Matrix_MultVec3f(&sp70, &pthis->effectPos[9]);
			func_80035844(&pthis->effectPos[9], &pthis->unk_1D8, &pthis->headRot, false);
			sp3E = pthis->headRot.x;
			sp3C = pthis->headRot.y;
			Matrix_Push();
			Matrix_Translate(pthis->effectPos[9].x, pthis->effectPos[9].y, pthis->effectPos[9].z, MTXMODE_NEW);
			Matrix_RotateZYX(sp3E, sp3C, 0, MTXMODE_APPLY);
			sp70.x = 0.0f;
			if(sFightPhase >= PHASE_4)
			{
				sp70.z = ((pthis->timer2.whole() - 16) & 7) * 120.0f;
			}
			else
			{
				sp70.z = ((pthis->timer2.whole() - 32) & 0xF) * 80.0f;
			}
			sp4C.z = sp40.z = sp70.z += 40.0f;
			sp70.z += 50.0f;
			Matrix_MultVec3f(&sp70, &pthis->effectPos[4]);
			if(sFightPhase >= PHASE_4)
			{
				sp70.z -= 33.0f;
				if(sp70.z < 0.0f)
				{
					sp70.z = 0.0f;
				}
				Matrix_MultVec3f(&sp70, &pthis->effectPos[6]);
				sp70.z -= 33.0f;
				if(sp70.z < 0.0f)
				{
					sp70.z = 0.0f;
				}
			}
			else
			{
				sp70.z -= 22.0f;
				if(sp70.z < 0.0f)
				{
					sp70.z = 0.0f;
				}
				Matrix_MultVec3f(&sp70, &pthis->effectPos[6]);
				sp70.z -= 22.0f;
				if(sp70.z < 0.0f)
				{
					sp70.z = 0.0f;
				}
			}
			Matrix_MultVec3f(&sp70, &pthis->effectPos[5]);
			Matrix_MultVec3f(&sp64, &pthis->colliderLightning.dim.quad[1]);
			Matrix_MultVec3f(&sp58, &pthis->colliderLightning.dim.quad[0]);
			Matrix_MultVec3f(&sp4C, &pthis->colliderLightning.dim.quad[3]);
			Matrix_MultVec3f(&sp40, &pthis->colliderLightning.dim.quad[2]);
			Collider_SetQuadVertices(&pthis->colliderLightning, &pthis->colliderLightning.dim.quad[0], &pthis->colliderLightning.dim.quad[1], &pthis->colliderLightning.dim.quad[2], &pthis->colliderLightning.dim.quad[3]);
			Matrix_Pop();
			break;
	}
}

s32 BossVa_BariOverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	BossVa* pthis = (BossVa*)thisx;

	switch(limbIndex)
	{
		case 2:
			*dList = NULL;
			break;
		case 3:
			Matrix_Scale(pthis->unk_1D8.x, 1.0f, pthis->unk_1D8.x, MTXMODE_APPLY);
			break;
		case 4:
			Matrix_Scale(1.0f, pthis->unk_1D8.y, 1.0f, MTXMODE_APPLY);
			break;
	}
	return false;
}

void BossVa_BariPostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	BossVa* pthis = (BossVa*)thisx;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 4494);

	if(limbIndex == 2)
	{
		gSPSegment(POLY_XLU_DISP++, 0x0A, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 0, (globalCtx->gameplayFrames.whole() * 10) % 32, 16, 32, 1, 0, (globalCtx->gameplayFrames.whole() * -5) % 32, 16, 32));
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_boss_va.c", 4508), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_000FA0);
	}
	else if((limbIndex == 3) || (limbIndex == 4))
	{
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_boss_va.c", 4512), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, *dList);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 4517);
}

void BossVa_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	s16* paramsPtr; // This stack slot is almost certainly actually globalCtx2, but can't make it match
	BossVa* pthis = (BossVa*)thisx;
	Vec3f spBC;
	Vec3f spB0 = {0.0f, 45.0f, 0.0f};
	Vec3f spA4 = {0.4f, 0.4f, 0.4f};
	Vec3f sp98 = {15.0f, 40.0f, 0.0f};
	Vec3f sp8C = {-15.0f, 40.0f, 0.0f};
	Vec3f sp80 = {15.0f, 40.0f, 0.0f};
	Vec3f sp74 = {-15.0f, 40.0f, 0.0f};
	Color_RGBA8 unused = {250, 250, 230, 200};

	OPEN_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 4542);

	func_80093D18(globalCtx->gfxCtx);
	paramsPtr = &pthis->actor.params;
	func_80093D84(globalCtx->gfxCtx);

	switch(pthis->actor.params)
	{
		case BOSSVA_BODY:
			if(globalCtx->envCtx.adjFogNear != 0)
			{
				globalCtx->envCtx.adjFogNear += 0x15E;
				if(globalCtx->envCtx.adjFogNear > 0)
				{
					globalCtx->envCtx.adjFogNear = 0;
				}
			}

			if(globalCtx->envCtx.adjFogFar != 0)
			{
				globalCtx->envCtx.adjFogFar += 0x15E;
				if(globalCtx->envCtx.adjFogFar > 0)
				{
					globalCtx->envCtx.adjFogFar = 0;
				}
			}

			if(!pthis->isDead)
			{
				gSPSegment(POLY_OPA_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 0, 0, 8, 16, 1, 0, (globalCtx->gameplayFrames.whole() * -10) % 16, 16, 16));
				gSPSegment(POLY_OPA_DISP++, 0x09, Gfx_TwoTexScroll(globalCtx->gfxCtx, 0, 0, (globalCtx->gameplayFrames.whole() * -10) % 32, 16, 0x20, 1, 0, (globalCtx->gameplayFrames.whole() * -5) % 32, 16, 32));
				SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, BossVa_BodyOverrideLimbDraw, BossVa_BodyPostLimbDraw, pthis);
			}
			break;
		case BOSSVA_SUPPORT_1:
		case BOSSVA_SUPPORT_2:
		case BOSSVA_SUPPORT_3:
			if(!pthis->isDead)
			{
				SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, BossVa_SupportOverrideLimbDraw, BossVa_SupportPostLimbDraw, pthis);
			}
			break;
		case BOSSVA_ZAPPER_1:
		case BOSSVA_ZAPPER_2:
		case BOSSVA_ZAPPER_3:
			if(!pthis->isDead)
			{
				SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, BossVa_ZapperOverrideLimbDraw, BossVa_ZapperPostLimbDraw, pthis);
			}
			break;
		case BOSSVA_STUMP_1:
		case BOSSVA_STUMP_2:
		case BOSSVA_STUMP_3:
			SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, NULL, NULL, NULL);
			break;
		default:
			if(!pthis->isDead)
			{
				SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, BossVa_BariOverrideLimbDraw, BossVa_BariPostLimbDraw, pthis);
				Collider_UpdateSpheres(0, &pthis->colliderSph);
				if(sCsState < BOSSVA_BATTLE)
				{
					spBC = GET_BODY(pthis)->actor.world.pos;
				}
				else
				{
					spBC = GET_BODY(pthis)->unk_1D8;
				}
				Matrix_MultVec3f(&sZeroVec, &pthis->effectPos[1]);
				Matrix_Push();
				Matrix_Translate(spBC.x, spBC.y, spBC.z, MTXMODE_NEW);
				Matrix_RotateZYX(pthis->actor.world.rot.x, pthis->actor.world.rot.y, 0, MTXMODE_APPLY);
				sp80.z = sp74.z = pthis->unk_1A0;
				spB0.z = (pthis->timer2 & 0xF) * (pthis->unk_1A0 * 0.0625f);
				Matrix_MultVec3f(&spB0, &pthis->effectPos[0]);
				Matrix_MultVec3f(&sp98, &pthis->colliderLightning.dim.quad[1]);
				Matrix_MultVec3f(&sp8C, &pthis->colliderLightning.dim.quad[0]);
				Matrix_MultVec3f(&sp80, &pthis->colliderLightning.dim.quad[3]);
				Matrix_MultVec3f(&sp74, &pthis->colliderLightning.dim.quad[2]);
				Collider_SetQuadVertices(&pthis->colliderLightning, &pthis->colliderLightning.dim.quad[0], &pthis->colliderLightning.dim.quad[1], &pthis->colliderLightning.dim.quad[2], &pthis->colliderLightning.dim.quad[3]);
				Matrix_Pop();
				spBC = pthis->actor.world.pos;
				spBC.y += 9.0f;
				if(pthis->actor.colorFilterTimer != 0)
				{
					func_80026A6C(globalCtx);
				}
				func_80033C30(&spBC, &spA4, 0xFF, globalCtx);
				if(pthis->actor.colorFilterTimer != 0)
				{
					Color_RGBA8 blue = {0, 0, 255, 255};

					func_80026860(globalCtx, &blue, pthis->actor.colorFilterTimer, pthis->actor.colorFilterParams & 0xFF);
				}
			}
			break;
		case BOSSVA_DOOR:
			break;
	}

	if(*paramsPtr == BOSSVA_BODY)
	{
		BossVa_DrawEffects(sVaEffects, globalCtx);
	}
	else if(*paramsPtr == BOSSVA_DOOR)
	{
		BossVa_DrawDoor(globalCtx, sDoorState);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 4673);
}

static s32 sUnkValue = 0x009B0000; // Unreferenced? Possibly a color

void BossVa_UpdateEffects(GlobalContext* globalCtx)
{
	BossVaEffect* effect = sVaEffects;
	Player* player = GET_PLAYER(globalCtx);
	s16 spB6;
	s16 i;
	f32 floorY;
	s32 padAC;
	s16 pitch;
	s16 yaw;
	BossVa* refActor2;
	BossVa* refActor;
	Vec3f sp94;
	CollisionPoly* sp90;
	f32 pad8C;
	Vec3f sp80;
	CollisionPoly* sp7C;
	f32 pad78;
	f32 pad74;

	for(i = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type != VA_NONE)
		{
			effect->timer--;

			effect->pos.x += effect->velocity.x;
			effect->pos.y += effect->velocity.y;
			effect->pos.z += effect->velocity.z;

			effect->velocity.x += effect->accel.x;
			effect->velocity.y += effect->accel.y;
			effect->velocity.z += effect->accel.z;

			if((effect->type == VA_LARGE_SPARK) || (effect->type == VA_SMALL_SPARK))
			{
				refActor = effect->parent;

				effect->rot.z += (s16)(Rand_ZeroOne() * 0x4E20) + 0x2000;
				effect->rot.y += (s16)(Rand_ZeroOne() * 0x2710) + 0x2000;

				if((effect->mode == SPARK_TETHER) || (effect->mode == SPARK_UNUSED))
				{
					pitch = effect->rot.x - Math_Vec3f_Pitch(&refActor->actor.world.pos, &GET_BODY(refActor)->unk_1D8);
					pad8C = Math_SinS(refActor->actor.world.rot.y);
					effect->pos.x = refActor->actor.world.pos.x - (effect->offset.x * pad8C);
					pad74 = Math_CosS(refActor->actor.world.rot.y);
					effect->pos.z = refActor->actor.world.pos.z - (effect->offset.x * pad74);
					pad78 = Math_CosS(-pitch);
					effect->pos.y = (effect->offset.y * pad78) + refActor->actor.world.pos.y;
				}
				else if((effect->mode == SPARK_BARI) || (effect->mode == SPARK_BODY))
				{
					effect->pos.x = effect->offset.x + refActor->actor.world.pos.x;
					effect->pos.y = effect->offset.y + refActor->actor.world.pos.y;
					effect->pos.z = effect->offset.z + refActor->actor.world.pos.z;
				}
				else
				{
					spB6 = Rand_ZeroFloat(ARRAY_COUNT(player->bodyPartsPos) - 0.1f);
					effect->pos.x = player->bodyPartsPos[spB6].x + Rand_CenteredFloat(10.0f);
					effect->pos.y = player->bodyPartsPos[spB6].y + Rand_CenteredFloat(15.0f);
					effect->pos.z = player->bodyPartsPos[spB6].z + Rand_CenteredFloat(10.0f);
				}

				if(effect->timer < 100)
				{
					effect->primColor[3] -= 50;
					if(effect->primColor[3] < 0)
					{
						effect->primColor[3] = 0;
						effect->timer = 0;
						effect->type = VA_NONE;
					}
				}
			}

			if(effect->type == VA_BLAST_SPARK)
			{
				effect->rot.z += (s16)(Rand_ZeroOne() * 0x4E20) + 0x4000;
				if(effect->timer < 100)
				{
					effect->primColor[3] -= 50;
					if(effect->primColor[3] < 0)
					{
						effect->primColor[3] = 0;
						effect->timer = 0;
						effect->type = VA_NONE;
					}
				}
			}

			if(effect->type == VA_SPARK_BALL)
			{
				refActor2 = effect->parent;

				effect->rot.z += (s16)(Rand_ZeroOne() * 0x2710) + 0x24A8;
				effect->pos.x = effect->offset.x + refActor2->actor.world.pos.x;
				effect->pos.y = refActor2->actor.world.pos.y + 310.0f + (refActor2->actor.shape.yOffset * refActor2->actor.scale.y);
				effect->pos.z = effect->offset.z + refActor2->actor.world.pos.z;
				effect->mode = (effect->mode + 1) & 7;

				if(effect->timer < 100)
				{
					effect->primColor[3] -= 50;
					if(effect->primColor[3] < 0)
					{
						effect->primColor[3] = 0;
						effect->timer = 0;
						effect->type = VA_NONE;
					}
				}
			}

			if(effect->type == VA_ZAP_CHARGE)
			{
				effect->mode = (effect->mode + 1) & 7;
				effect->primColor[3] -= 20;
				if(effect->primColor[3] <= 0)
				{
					effect->primColor[3] = 0;
					effect->timer = 0;
					effect->type = VA_NONE;
				}
			}

			if(effect->type == VA_BLOOD)
			{
				if(effect->mode < BLOOD_SPOT)
				{
					sp94 = effect->pos;
					sp94.y -= effect->velocity.y + 4.0f;
					floorY = BgCheck_EntityRaycastFloor1(&globalCtx->colCtx, &sp90, &sp94);
					if((sp90 != NULL) && (effect->pos.y <= floorY))
					{
						effect->mode = BLOOD_SPOT;
						effect->pos.y = floorY + 1.0f;
						if(sCsState <= DEATH_SHELL_BURST)
						{
							effect->timer = 80;
						}
						else
						{
							effect->timer = 60000;
						}

						effect->accel = effect->velocity = sZeroVec;
					}
					if(!effect->timer)
					{
						effect->type = VA_NONE;
					}
				}
				else
				{
					if(effect->timer < 20)
					{
						effect->envColor[3] = effect->timer * 5;
						effect->primColor[3] = effect->timer * 10;
					}
					else if(effect->timer > 50000)
					{
						effect->timer++;
					}
				}

				if(!effect->timer)
				{
					effect->type = VA_NONE;
				}
			}

			if(effect->type == VA_GORE)
			{
				if(effect->mode == GORE_PERMANENT)
				{
					sp80 = effect->pos;
					sp80.y -= effect->velocity.y + 4.0f;
					effect->rot.x += 0x1770;
					floorY = BgCheck_EntityRaycastFloor1(&globalCtx->colCtx, &sp7C, &sp80);
					if((sp7C != NULL) && (effect->pos.y <= floorY))
					{
						effect->mode = GORE_FLOOR;
						effect->timer = 30;
						effect->pos.y = floorY + 1.0f;
						effect->accel = effect->velocity = sZeroVec;
						effect->rot.x = -0x4000;
					}

					if(!effect->timer)
					{
						effect->type = VA_NONE;
					}
				}
				else if(effect->mode == GORE_FADING)
				{
					if(effect->timer == 0)
					{
						effect->type = VA_NONE;
						if(1)
						{
						}
					}
				}
				else
				{
					Math_SmoothStepToF(&effect->scaleMod, 0.075f, 1.0f, 0.005f, 0.0f);
					Math_SmoothStepToF(&effect->vaGorePulseRate, 0.0f, 0.6f, 0.005f, 0.0013f);
					if((globalCtx->gameplayFrames % 4) == 0)
					{
						Math_SmoothStepToS(&effect->primColor[0], 95, 1, 1, 0);
					}
				}
				effect->vaGorePulse += effect->vaGorePulseRate;
			}

			if(effect->type == VA_TUMOR)
			{
				refActor = effect->parent;

				effect->rot.z += 0x157C;
				effect->envColor[3] = (s16)(Math_SinS(effect->rot.z) * 50.0f) + 80;
				Math_SmoothStepToF(&effect->scale, effect->scaleMod, 1.0f, 0.01f, 0.005f);
				effect->pos.x = effect->offset.x + refActor->actor.world.pos.x;
				effect->pos.y = effect->offset.y + refActor->actor.world.pos.y;
				effect->pos.z = effect->offset.z + refActor->actor.world.pos.z;

				switch(effect->mode)
				{
					case TUMOR_UNUSED:
						if(effect->timer == 0)
						{
							yaw = Math_Vec3f_Yaw(&refActor->actor.world.pos, &effect->pos);
							effect->type = VA_NONE;
							BossVa_BloodSplatter(globalCtx, effect, yaw, effect->scale * 4500.0f, 1);
							BossVa_Gore(globalCtx, effect, yaw, effect->scale * 1.2f);
						}
						break;
					case TUMOR_BODY:
					case TUMOR_ARM:
						if(refActor->burst)
						{
							effect->type = VA_NONE;
							yaw = Math_Vec3f_Yaw(&refActor->actor.world.pos, &effect->pos);
							BossVa_BloodSplatter(globalCtx, effect, yaw, effect->scale * 4500.0f, 1);
							BossVa_Gore(globalCtx, effect, yaw, effect->scale * 1.2f);
						}
						break;
				}
				if(1)
				{
				}
			}
		}
	}
}

void BossVa_DrawEffects(BossVaEffect* effect, GlobalContext* globalCtx)
{
	s16 i;
	GraphicsContext* gfxCtx = globalCtx->gfxCtx;
	u8 flag = 0;
	BossVaEffect* effectHead = effect;
	Camera* camera = Gameplay_GetCamera(globalCtx, sCsCamera);

	OPEN_DISPS(gfxCtx, "../z_boss_va.c", 4953);

	for(i = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_LARGE_SPARK)
		{
			if(!flag)
			{
				func_80093D84(globalCtx->gfxCtx);
				gDPSetEnvColor(POLY_XLU_DISP++, 130, 130, 30, 0);
				gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_0156A0);
				flag++;
			}

			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 230, 230, 230, effect->primColor[3]);
			Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
			func_800D1FD4(&globalCtx->billboardMtxF);
			Matrix_RotateZ((effect->rot.z / (f32)0x8000) * 3.1416f, MTXMODE_APPLY);
			Matrix_Scale(effect->scale * 0.0185f, effect->scale * 0.0185f, 1.0f, MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_va.c", 4976), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_015710);
		}
	}

	effect = effectHead;
	for(i = 0, flag = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_SPARK_BALL)
		{
			if(!flag)
			{
				func_80093D84(globalCtx->gfxCtx);
				gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_011738);
				flag++;
			}
			Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
			func_800D1FD4(&globalCtx->billboardMtxF);
			Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);
			Matrix_RotateZ((effect->rot.z / (f32)0x8000) * 3.1416f, MTXMODE_APPLY);

			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_va.c", 5002), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gDPPipeSync(POLY_XLU_DISP++);
			gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sSparkBallTex_206[effect->mode]));
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, effect->primColor[0], effect->primColor[1], effect->primColor[2], effect->primColor[3]);
			gDPPipeSync(POLY_XLU_DISP++);
			gDPSetEnvColor(POLY_XLU_DISP++, effect->envColor[0], effect->envColor[1], effect->envColor[2], effect->envColor[3]);
			gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_011768);
		}
	}

	effect = effectHead;
	for(i = 0, flag = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_BLOOD)
		{
			if(!flag)
			{
				func_80093D84(globalCtx->gfxCtx);
				gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_009430);
				gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(gEffBubble1Tex));
				flag++;
			}

			gDPPipeSync(POLY_XLU_DISP++);
			gDPSetEnvColor(POLY_XLU_DISP++, 0, 100, 0, effect->envColor[3]);
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 150, 0, effect->primColor[3]);

			Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
			if(effect->mode == BLOOD_SPOT)
			{
				Matrix_RotateX(M_PI / 2, MTXMODE_APPLY);
			}
			else
			{
				func_800D1FD4(&globalCtx->billboardMtxF);
			}

			Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);

			gDPPipeSync(POLY_XLU_DISP++);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_va.c", 5052), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_009468);
		}
	}

	effect = effectHead;
	for(i = 0, flag = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_TUMOR)
		{
			BossVa* parent = effect->parent;

			if(!flag)
			{
				func_80093D18(globalCtx->gfxCtx);
				gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, effect->envColor[3]);
				gSPDisplayList(POLY_OPA_DISP++, gBarinadeDL_0128B8);
				flag++;
			}

			if((effect->mode != TUMOR_BODY) || ((Math_Vec3f_DistXZ(&camera->eye, &effect->pos) - Math_Vec3f_DistXZ(&camera->eye, &parent->actor.world.pos)) < 10.0f))
			{
				Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
				Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);

				gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_va.c", 5080), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
				gSPDisplayList(POLY_OPA_DISP++, gBarinadeDL_012948);
			}
		}
	}

	effect = effectHead;
	for(i = 0, flag = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_GORE)
		{
			if(!flag)
			{
				func_80093D18(globalCtx->gfxCtx);
				gSPDisplayList(POLY_OPA_DISP++, gBarinadeDL_012BA0);
				flag++;
			}

			gDPPipeSync(POLY_OPA_DISP++);
			gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, effect->primColor[3]);
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, effect->primColor[0], effect->primColor[1], effect->primColor[2], effect->primColor[3]);

			Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
			Matrix_RotateZYX(effect->rot.x, effect->rot.y, 0, MTXMODE_APPLY);
			Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);
			Matrix_RotateX(effect->offset.x * 0.115f, MTXMODE_APPLY);
			Matrix_RotateY(effect->offset.x * 0.13f, MTXMODE_APPLY);
			Matrix_RotateZ(effect->offset.x * 0.1f, MTXMODE_APPLY);
			Matrix_Scale(1.0f - effect->scaleMod, effect->scaleMod + 1.0f, 1.0f - effect->scaleMod, MTXMODE_APPLY);
			Matrix_RotateZ(-(effect->offset.x * 0.1f), MTXMODE_APPLY);
			Matrix_RotateY(-(effect->offset.x * 0.13f), MTXMODE_APPLY);
			Matrix_RotateX(-(effect->offset.x * 0.115f), MTXMODE_APPLY);

			gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_va.c", 5124), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_OPA_DISP++, gBarinadeDL_012C50);
		}
	}

	effect = effectHead;
	for(i = 0, flag = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_ZAP_CHARGE)
		{
			if(!flag)
			{
				func_80093D84(globalCtx->gfxCtx);
				gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_0135B0);
				flag++;
			}

			gDPPipeSync(POLY_XLU_DISP++);
			gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 50, effect->primColor[3]);
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, effect->primColor[3]);

			Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
			Matrix_RotateZYX(effect->rot.x, effect->rot.y, 0, MTXMODE_APPLY);
			Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);

			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_va.c", 5152), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_013638);
		}
	}

	effect = effectHead;
	for(i = 0, flag = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_BLAST_SPARK)
		{
			if(!flag)
			{
				func_80093C14(globalCtx->gfxCtx);
				gDPSetEnvColor(POLY_XLU_DISP++, 130, 130, 30, 0);
				gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_0156A0);
				flag++;
			}

			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 230, 230, 230, effect->primColor[3]);
			Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
			func_800D1FD4(&globalCtx->billboardMtxF);
			Matrix_RotateZ((effect->rot.z / (f32)0x8000) * 3.1416f, MTXMODE_APPLY);
			Matrix_Scale(effect->scale * 0.02f, effect->scale * 0.02f, 1.0f, MTXMODE_APPLY);

			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_va.c", 5180), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_015710);
		}
	}

	effect = effectHead;
	for(i = 0, flag = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_SMALL_SPARK)
		{
			if(!flag)
			{
				func_80093D84(globalCtx->gfxCtx);
				gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 100, 0);
				gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_008F08);
				flag++;
			}

			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, effect->primColor[3]);
			Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
			Matrix_RotateZ((effect->rot.z / (f32)0x8000) * 3.1416f, MTXMODE_APPLY);
			Matrix_RotateY((effect->rot.y / (f32)0x8000) * 3.1416f, MTXMODE_APPLY);
			Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);

			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_va.c", 5208), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, gBarinadeDL_008F70);
		}
	}

	CLOSE_DISPS(gfxCtx, "../z_boss_va.c", 5215);
}

void BossVa_SpawnSpark(GlobalContext* globalCtx, BossVaEffect* effect, BossVa* pthis, Vec3f* offset, s16 scale, u8 mode)
{
	Player* player = GET_PLAYER(globalCtx);
	s16 index;
	Vec3f pos = {0.0f, -1000.0f, 0.0f};
	Vec3f tempVec;
	s16 i;

	for(i = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_NONE)
		{
			effect->type = VA_LARGE_SPARK;
			effect->parent = pthis;
			effect->pos = pos;
			effect->timer = (s16)(Rand_ZeroOne() * 10.0f) + 111;
			effect->velocity = effect->accel = sZeroVec;
			effect->mode = mode;

			switch(mode)
			{
				case SPARK_UNUSED:
					effect->type = VA_SMALL_SPARK;
				case SPARK_TETHER:
					tempVec = *offset;
					tempVec.x += pthis->actor.world.pos.x;
					tempVec.z += pthis->actor.world.pos.z;
					effect->offset.x = Math_Vec3f_DistXZ(&pthis->actor.world.pos, &tempVec);
					effect->rot.x = Math_Vec3f_Pitch(&pthis->actor.world.pos, &GET_BODY(pthis)->unk_1D8);
					break;

				case SPARK_BODY:
					effect->type = VA_SMALL_SPARK;
				case SPARK_BARI:
					effect->offset.x = offset->x;
					effect->offset.z = offset->z;
					break;

				case SPARK_BLAST:
					effect->type = VA_BLAST_SPARK;
					effect->pos.x = offset->x + pthis->actor.world.pos.x;
					effect->pos.y = offset->y + pthis->actor.world.pos.y;
					effect->pos.z = offset->z + pthis->actor.world.pos.z;
					effect->timer = 111;
					break;

				case SPARK_LINK:
					effect->type = VA_SMALL_SPARK;
					index = Rand_ZeroFloat(ARRAY_COUNT(player->bodyPartsPos) - 0.1f);
					effect->pos.x = player->bodyPartsPos[index].x + Rand_CenteredFloat(10.0f);
					effect->pos.y = player->bodyPartsPos[index].y + Rand_CenteredFloat(15.0f);
					effect->pos.z = player->bodyPartsPos[index].z + Rand_CenteredFloat(10.0f);
					break;
			}

			effect->offset.y = offset->y;
			effect->scale = (Rand_ZeroFloat(scale) + scale) * 0.01f;
			effect->primColor[3] = 255;
			break;
		}
	}
}

void BossVa_SpawnSparkBall(GlobalContext* globalCtx, BossVaEffect* effect, BossVa* pthis, Vec3f* offset, s16 scale, u8 mode)
{
	Vec3f pos = {0.0f, -1000.0f, 0.0f};
	s16 i;

	for(i = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_NONE)
		{
			effect->type = VA_SPARK_BALL;
			effect->parent = pthis;

			effect->pos = pos;

			effect->velocity = effect->accel = sZeroVec;

			effect->mode = 0;
			effect->offset.x = offset->x;
			effect->offset.z = offset->z;
			effect->offset.y = offset->y;
			effect->timer = (s16)(Rand_ZeroOne() * 10.0f) + 111;
			effect->primColor[0] = effect->primColor[1] = effect->primColor[2] = effect->primColor[3] = 230;
			effect->envColor[0] = 0;
			effect->envColor[1] = 100;
			effect->envColor[2] = 220;
			effect->envColor[3] = 160;

			effect->scale = (Rand_ZeroFloat(scale) + scale) * 0.01f;
			return;
		}
	}
}

void BossVa_SpawnBloodDroplets(GlobalContext* globalCtx, BossVaEffect* effect, Vec3f* pos, s16 scale, s16 phase, s16 yaw)
{
	s32 i;
	Vec3f accel = {0.0f, 0.0f, 0.0f};
	Vec3f velocity = {0.0f, 0.0f, 0.0f};
	f32 xzVel;

	for(i = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_NONE)
		{
			effect->type = VA_BLOOD;
			effect->pos = *pos;
			effect->mode = BLOOD_DROPLET;

			xzVel = Math_SinS(phase) * 6.0f;
			velocity.x = Rand_CenteredFloat(1.0f) + (-Math_SinS(yaw) * xzVel);
			velocity.z = Rand_CenteredFloat(1.0f) + (-Math_CosS(yaw) * xzVel);

			effect->velocity = velocity;

			accel.y = Rand_CenteredFloat(0.3f) - 1.0f;
			effect->accel = accel;

			effect->timer = 20;
			effect->envColor[3] = 100;
			effect->primColor[3] = 200;
			effect->scale = (Rand_ZeroFloat(scale) + scale) * 0.01f;
			break;
		}
	}
}

void BossVa_SpawnBloodSplatter(GlobalContext* globalCtx, BossVaEffect* effect, Vec3f* pos, s16 yaw, s16 scale)
{
	s32 i;
	f32 xzVel;
	Vec3f accel = {0.0f, 0.0f, 0.0f};
	Vec3f velocity;

	for(i = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_NONE)
		{
			effect->type = VA_BLOOD;
			effect->pos = *pos;

			effect->mode = BLOOD_SPLATTER;

			xzVel = Rand_ZeroOne() * 7.0f;
			velocity.x = Math_SinS(yaw) * xzVel;
			velocity.y = Rand_CenteredFloat(4.0f) + 4.0f;
			velocity.z = Math_CosS(yaw) * xzVel;
			effect->velocity = velocity;

			accel.y = Rand_CenteredFloat(0.3f) - 1.0f;
			effect->accel = accel;

			if(sCsState <= DEATH_SHELL_BURST)
			{
				effect->timer = 20;
			}
			else
			{
				effect->timer = 60;
			}
			effect->envColor[3] = 100;
			effect->primColor[3] = 200;
			effect->scale = scale * 0.01f;
			break;
		}
	}
}

void BossVa_SpawnTumor(GlobalContext* globalCtx, BossVaEffect* effect, BossVa* pthis, Vec3f* offset, s16 scale, u8 mode)
{
	Vec3f pos = {0.0f, -1000.0f, 0.0f};
	s16 i;

	for(i = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_NONE)
		{
			effect->type = VA_TUMOR;
			effect->parent = pthis;
			effect->pos = pos;

			effect->velocity = effect->accel = sZeroVec;

			effect->mode = mode;
			effect->rot.z = 0;

			effect->offset.x = offset->x;
			effect->offset.z = offset->z;
			effect->offset.y = offset->y;

			effect->timer = (s16)(Rand_ZeroOne() * 10.0f) + 10;
			effect->envColor[3] = 100;
			effect->scaleMod = scale * 0.01f;
			effect->scale = 0.0f;

			if(((i % 4) == 0) || (mode == 2))
			{
				Audio_PlaySoundGeneral(NA_SE_EN_BALINADE_BREAK, &effect->pos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
			}
			break;
		}
	}
}

void BossVa_SpawnGore(GlobalContext* globalCtx, BossVaEffect* effect, Vec3f* pos, s16 yaw, s16 scale)
{
	s32 i;
	f32 xzVel;
	Vec3f accel = {0.0f, 0.0f, 0.0f};
	Vec3f velocity;

	for(i = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_NONE)
		{
			effect->type = VA_GORE;
			effect->pos = *pos;
			effect->scaleMod = 0.0f;

			xzVel = (Rand_ZeroOne() * 4.0f) + 4.0f;
			velocity.x = Math_SinS(yaw) * xzVel;
			velocity.y = Rand_CenteredFloat(8.0f);
			velocity.z = Math_CosS(yaw) * xzVel;
			effect->velocity = velocity;

			accel.y = Rand_CenteredFloat(0.3f) - 1.0f;
			effect->accel = accel;

			effect->timer = 20;
			if(sCsState <= DEATH_SHELL_BURST)
			{
				effect->mode = GORE_FADING;
			}
			else
			{
				effect->mode = GORE_PERMANENT;
			}

			effect->primColor[3] = effect->envColor[0] = effect->envColor[1] = effect->envColor[2] = effect->envColor[3] = 255;

			effect->primColor[0] = 155;
			effect->primColor[1] = effect->primColor[2] = 55;

			effect->rot.x = Rand_CenteredFloat(0x10000);
			effect->rot.y = Rand_CenteredFloat(0x10000);
			effect->scale = (Rand_ZeroFloat(scale) + scale) * 0.01f;
			effect->vaGorePulseRate = (Rand_ZeroOne() * 0.25f) + 0.9f;
			break;
		}
	}
}

void BossVa_SpawnZapperCharge(GlobalContext* globalCtx, BossVaEffect* effect, BossVa* pthis, Vec3f* pos, Vec3s* rot, s16 scale, u8 mode)
{
	Vec3f unused = {0.0f, -1000.0f, 0.0f};
	s16 i;

	for(i = 0; i < ARRAY_COUNT(sVaEffects); i++, effect++)
	{
		if(effect->type == VA_NONE)
		{
			effect->type = VA_ZAP_CHARGE;
			effect->parent = pthis;
			effect->pos = *pos;

			effect->velocity = effect->accel = sZeroVec;

			effect->mode = mode;
			effect->rot.x = rot->x + 0x4000;
			effect->rot.y = rot->y;
			effect->timer = (s16)(Rand_ZeroOne() * 10.0f) + 10;
			effect->primColor[3] = 240;
			effect->scale = scale * 0.01f;
			break;
		}
	}
}

void BossVa_DrawDoor(GlobalContext* globalCtx, s16 scale)
{
	MtxF doorMtx;
	f32 yScale;
	f32 segAngle = 0.0f;
	s32 i;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 5600);

	Matrix_Translate(0.0f, 80.0f, 400.0f, MTXMODE_NEW);
	Matrix_RotateY(M_PI, MTXMODE_APPLY);
	yScale = (scale * 0.01f) * 0.1f;
	Matrix_Scale(0.1f, yScale, 0.1f, MTXMODE_APPLY);

	if(yScale != 0.0f)
	{
		yScale = 0.1f / yScale;
	}
	else
	{
		yScale = 0.0f;
	}

	Matrix_Get(&doorMtx);

	for(i = 0; i < 8; i++, segAngle -= M_PI / 4)
	{
		Matrix_Put(&doorMtx);
		Matrix_RotateZ(segAngle, MTXMODE_APPLY);
		Matrix_Translate(0.0f, doorPieceLength_214[i] * yScale, 0.0f, MTXMODE_APPLY);

		gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_boss_va.c", 5621), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_OPA_DISP++, doorPieceDispList_214[i]);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_boss_va.c", 5629);
}

void BossVa_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Boss_Va_InitVars = {
	    ACTOR_BOSS_VA, ACTORCAT_BOSS, FLAGS, OBJECT_BV, sizeof(BossVa), (ActorFunc)BossVa_Init, (ActorFunc)BossVa_Destroy, (ActorFunc)BossVa_Update, (ActorFunc)BossVa_Draw, (ActorFunc)BossVa_Reset,
	};

	sCylinderInit = {
	    {
		COLTYPE_NONE,
		AT_ON | AT_TYPE_ENEMY,
		AC_ON | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_ALL,
		OC2_TYPE_2,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK0,
		{0xFFCFFFEF, 0x03, 0x08},
		{0x00000010, 0x00, 0x00},
		TOUCH_ON | TOUCH_SFX_NORMAL,
		BUMP_ON,
		OCELEM_ON,
	    },
	    {85, 120, 0, {0, 0, 0}},
	};

	sJntSphInitSupport = {
	    {
		COLTYPE_HIT6,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_NONE,
		OC2_TYPE_1,
		COLSHAPE_JNTSPH,
	    },
	    ARRAY_COUNT(sJntSphElementsInitSupport),
	    sJntSphElementsInitSupport,
	};

	sJntSphInitBari = {
	    {
		COLTYPE_NONE,
		AT_ON | AT_TYPE_ENEMY,
		AC_ON | AC_TYPE_PLAYER,
		OC1_NONE,
		OC2_TYPE_1,
		COLSHAPE_JNTSPH,
	    },
	    ARRAY_COUNT(sJntSphElementsInitBari),
	    sJntSphElementsInitBari,
	};

	sQuadInit = {
	    {
		COLTYPE_METAL,
		AT_ON | AT_TYPE_ENEMY,
		AC_ON | AC_TYPE_PLAYER,
		OC1_NONE,
		OC2_NONE,
		COLSHAPE_QUAD,
	    },
	    {
		ELEMTYPE_UNK0,
		{0x20000000, 0x03, 0x04},
		{0x00000010, 0x00, 0x00},
		TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
		BUMP_ON,
		OCELEM_NONE,
	    },
	    {{{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}},
	};

	sZeroVec = {0.0f, 0.0f, 0.0f};

	sKillBari = 0;

	sCsCamera = 0;

	sBodyState = 0;

	sFightPhase = 0;

	sCsState = 0;

	sCameraEye = {0, 0, 0};

	sCameraAt = {0, 0, 0};

	sCameraNextEye = {0, 0, 0};

	sCameraNextAt = {0, 0, 0};

	sCameraEyeMaxVel = {0, 0, 0};

	sCameraAtMaxVel = {0, 0, 0};

	sDoorState = 0;

	sPhase3StopMoving = 0;

	sZapperRot = {0, 0, 0};

	sPhase2Timer = 0;

	sPhase4HP = 0;

	sUnkValue = 0x009B0000;
}
