#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BUBBLE_Z_EN_BUBBLE_C
#include "actor_common.h"
/*
 * File: z_en_bubble.cpp
 * Description: Bubble
 */

#include "z_en_bubble.h"
#include "def/code_8006BA00.h"
#include "def/random.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "objects/object_bubble/object_bubble.h"

#define FLAGS ACTOR_FLAG_VISIBLE

void EnBubble_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBubble_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBubble_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBubble_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBubble_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnBubble_Wait(EnBubble* pthis, GlobalContext* globalCtx);
void EnBubble_Pop(EnBubble* pthis, GlobalContext* globalCtx);
void EnBubble_Regrow(EnBubble* pthis, GlobalContext* globalCtx);

ActorInit En_Bubble_InitVars = {
    ACTOR_EN_BUBBLE, ACTORCAT_ENEMY, FLAGS, OBJECT_BUBBLE, ACTOR_FACTORY(EnBubble), (ActorFunc)EnBubble_Init, (ActorFunc)EnBubble_Destroy, (ActorFunc)EnBubble_Update, (ActorFunc)EnBubble_Draw, (ActorFunc)EnBubble_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[2] = {
    {
	{
	    ELEMTYPE_UNK0,
	    {0x00000000, 0x00, 0x04},
	    {0xFFCFD753, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON,
	    OCELEM_ON,
	},
	{0, {{0, 0, 0}, 16}, 100},
    },
    {
	{
	    ELEMTYPE_UNK0,
	    {0x00000000, 0x00, 0x00},
	    {0x00002824, 0x00, 0x00},
	    TOUCH_NONE,
	    BUMP_ON | BUMP_NO_AT_INFO | BUMP_NO_DAMAGE | BUMP_NO_SWORD_SFX | BUMP_NO_HITMARK,
	    OCELEM_NONE,
	},
	{0, {{0, 0, 0}, 16}, 100},
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
	COLTYPE_HIT6,
	AT_ON | AT_TYPE_ENEMY,
	AC_ON | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_ALL,
	OC2_TYPE_1,
	COLSHAPE_JNTSPH,
    },
    2,
    sJntSphElementsInit,
};

static CollisionCheckInfoInit2 sColChkInfoInit2 = {
    1, 2, 25, 25, MASS_IMMOVABLE,
};

static Vec3f sEffectAccel = {0.0f, -0.5f, 0.0f};

static Color_RGBA8 sEffectPrimColor = {255, 255, 255, 255};

static Color_RGBA8 sEffectEnvColor = {150, 150, 150, 0};

void EnBubble_SetDimensions(EnBubble* pthis, f32 dim)
{
	f32 a;
	f32 b;
	f32 c;
	f32 d;

	pthis->actor.flags |= ACTOR_FLAG_VISIBLE;
	Actor_SetScale(&pthis->actor, 1.0f);
	pthis->actor.shape.yOffset = 16.0f;
	pthis->graphicRotSpeed = 16.0f;
	pthis->graphicEccentricity = 0.08f;
	pthis->expansionWidth = dim;
	pthis->expansionHeight = dim;
	a = Rand_ZeroOne();
	b = Rand_ZeroOne();
	c = Rand_ZeroOne();
	pthis->unk_218 = 1.0f;
	pthis->unk_21C = 1.0f;
	d = (a * a) + (b * b) + (c * c);
	pthis->unk_1FC.x = a / d;
	pthis->unk_1FC.y = b / d;
	pthis->unk_1FC.z = c / d;
}

u32 func_809CBCBC(EnBubble* pthis)
{
	ColliderInfo* info = &pthis->colliderSphere.elements[0].info;

	info->toucher.dmgFlags = 0x8;
	info->toucher.effect = 0;
	info->toucher.damage = 4;
	info->toucherFlags = TOUCH_ON;
	pthis->actor.velocity.y = 0.0f;
	return 6;
}

// only called in an unused actionFunc
u32 func_809CBCEC(EnBubble* pthis)
{
	EnBubble_SetDimensions(pthis, -1.0f);
	return 12;
}

void EnBubble_DamagePlayer(EnBubble* pthis, GlobalContext* globalCtx)
{
	s32 damage = -pthis->colliderSphere.elements[0].info.toucher.damage;

	globalCtx->damagePlayer(globalCtx, damage);
	func_8002F7A0(globalCtx, &pthis->actor, 6.0f, pthis->actor.yawTowardsPlayer, 6.0f);
}

s32 EnBubble_Explosion(EnBubble* pthis, GlobalContext* globalCtx)
{
	u32 i;
	Vec3f effectAccel;
	Vec3f effectVel;
	Vec3f effectPos;

	effectAccel = sEffectAccel;
	Math_SmoothStepToF(&pthis->expansionWidth, 4.0f, 0.1f, 1000.0f, 0.0f);
	Math_SmoothStepToF(&pthis->expansionHeight, 4.0f, 0.1f, 1000.0f, 0.0f);
	Math_SmoothStepToF(&pthis->graphicRotSpeed, 54.0f, 0.1f, 1000.0f, 0.0f);
	Math_SmoothStepToF(&pthis->graphicEccentricity, 0.2f, 0.1f, 1000.0f, 0.0f);
	pthis->actor.shape.yOffset = ((pthis->expansionHeight + 1.0f) * 16.0f);

	if(DECR(pthis->explosionCountdown) != 0)
	{
		return -1;
	}
	effectPos.x = pthis->actor.world.pos.x;
	effectPos.y = pthis->actor.world.pos.y + pthis->actor.shape.yOffset;
	effectPos.z = pthis->actor.world.pos.z;
	for(i = 0; i < 20; i++)
	{
		effectVel.x = (Rand_ZeroOne() - 0.5f) * 7.0f;
		effectVel.y = Rand_ZeroOne() * 7.0f;
		effectVel.z = (Rand_ZeroOne() - 0.5f) * 7.0f;
		EffectSsDtBubble_SpawnCustomColor(globalCtx, &effectPos, &effectVel, &effectAccel, &sEffectPrimColor, &sEffectEnvColor, Rand_S16Offset(100, 50), 0x19, 0);
	}
	Item_DropCollectibleRandom(globalCtx, NULL, &pthis->actor.world.pos, 0x50);
	pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
	return Rand_S16Offset(90, 60);
}

// only called in an unused actionFunc
u32 func_809CBFD4(EnBubble* pthis)
{
	if(DECR(pthis->explosionCountdown) != 0)
	{
		return -1;
	}
	return func_809CBCEC(pthis);
}

// only called in an unused actionFunc
s32 func_809CC020(EnBubble* pthis)
{
	pthis->expansionWidth += 1.0f / 12.0f;
	pthis->expansionHeight += 1.0f / 12.0f;

	if(DECR(pthis->explosionCountdown) != 0)
	{
		return false;
	}
	return true;
}

void EnBubble_Vec3fNormalizedRelfect(Vec3f* vec1, Vec3f* vec2, Vec3f* ret)
{
	f32 norm;

	Math3D_Vec3fReflect(vec1, vec2, ret);
	norm = sqrtf((ret->x * ret->x) + (ret->y * ret->y) + (ret->z * ret->z));
	if(norm != 0.0f)
	{
		ret->x /= norm;
		ret->y /= norm;
		ret->z /= norm;
	}
	else
	{
		ret->x = ret->y = ret->z = 0.0f;
	}
}

void EnBubble_Vec3fNormalize(Vec3f* vec)
{
	f32 norm = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));

	if(norm != 0.0f)
	{
		vec->x /= norm;
		vec->y /= norm;
		vec->z /= norm;
	}
	else
	{
		vec->x = vec->y = vec->z = 0.0f;
	}
}

void EnBubble_Fly(EnBubble* pthis, GlobalContext* globalCtx)
{
	CollisionPoly* sp94;
	Actor* bumpActor;
	Vec3f sp84;
	VecPos pos1;
	VecPos pos2;
	Vec3f normal;
	Vec3f vel;
	f32 bounceSpeed;
	s32 bgId;
	u8 bounceCount;

	if(pthis->colliderSphere.elements[1].info.bumperFlags & BUMP_HIT)
	{
		bumpActor = pthis->colliderSphere.base.ac;
		pthis->normalizedBumpVelocity = bumpActor->velocity;
		EnBubble_Vec3fNormalize(&pthis->normalizedBumpVelocity);
		pthis->velocityFromBump.x += (pthis->normalizedBumpVelocity.x * 3.0f);
		pthis->velocityFromBump.y += (pthis->normalizedBumpVelocity.y * 3.0f);
		pthis->velocityFromBump.z += (pthis->normalizedBumpVelocity.z * 3.0f);
	}
	pthis->sinkSpeed -= 0.1f;
	if(pthis->sinkSpeed < pthis->actor.minVelocityY)
	{
		pthis->sinkSpeed = pthis->actor.minVelocityY / FRAMERATE_SCALER_INV;
	}
	vel.x = pthis->velocityFromBounce.x + pthis->velocityFromBump.x;
	vel.y = pthis->velocityFromBounce.y + pthis->velocityFromBump.y + pthis->sinkSpeed;
	vel.z = pthis->velocityFromBounce.z + pthis->velocityFromBump.z;
	EnBubble_Vec3fNormalize(&vel);

	pos1.x = pthis->actor.world.pos.x;
	pos1.y = pthis->actor.world.pos.y + pthis->actor.shape.yOffset;
	pos1.z = pthis->actor.world.pos.z;
	pos2 = pos1;

	pos2.x += (vel.x * 24.0f) / FRAMERATE_SCALER_INV;
	pos2.y += (vel.y * 24.0f) / FRAMERATE_SCALER_INV;
	pos2.z += (vel.z * 24.0f) / FRAMERATE_SCALER_INV;

	Vec3f pos1Chk = pos1;
	Vec3f pos2Chk = pos2;
	if(BgCheck_EntityLineTest1(&globalCtx->colCtx, &pos1Chk, &pos2Chk, &sp84, &sp94, true, true, true, false, &bgId))
	{
		normal.x = COLPOLY_GET_NORMAL(sp94->normal.x);
		normal.y = COLPOLY_GET_NORMAL(sp94->normal.y);
		normal.z = COLPOLY_GET_NORMAL(sp94->normal.z);
		EnBubble_Vec3fNormalizedRelfect(&vel, &normal, &vel);
		pthis->bounceDirection = vel;
		bounceCount = pthis->bounceCount;
		pthis->bounceCount = ++bounceCount;
		if(bounceCount > (s16)(Rand_ZeroOne() * 10.0f))
		{
			pthis->bounceCount = 0;
		}
		bounceSpeed = (pthis->bounceCount == 0) ? 3.6000001f : 3.0f;
		pthis->velocityFromBump.x = pthis->velocityFromBump.y = pthis->velocityFromBump.z = 0.0f;
		pthis->velocityFromBounce.x = (pthis->bounceDirection.x * bounceSpeed);
		pthis->velocityFromBounce.y = (pthis->bounceDirection.y * bounceSpeed);
		pthis->velocityFromBounce.z = (pthis->bounceDirection.z * bounceSpeed);
		pthis->sinkSpeed = 0.0f;
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_AWA_BOUND);
		pthis->graphicRotSpeed = 128.0f / FRAMERATE_SCALER_INV;
		pthis->graphicEccentricity = 0.48f;
	}
	else if(pthis->actor.bgCheckFlags & BG_STATE_5 && vel.y < 0.0f)
	{
		normal.x = normal.z = 0.0f;
		normal.y = 1.0f;
		EnBubble_Vec3fNormalizedRelfect(&vel, &normal, &vel);
		pthis->bounceDirection = vel;
		bounceCount = pthis->bounceCount;
		pthis->bounceCount = ++bounceCount;
		if(bounceCount > (s16)(Rand_ZeroOne() * 10.0f))
		{
			pthis->bounceCount = 0;
		}
		bounceSpeed = (pthis->bounceCount == 0) ? 3.6000001f : 3.0f;
		pthis->velocityFromBump.x = pthis->velocityFromBump.y = pthis->velocityFromBump.z = 0.0f;
		pthis->velocityFromBounce.x = (pthis->bounceDirection.x * bounceSpeed);
		pthis->velocityFromBounce.y = (pthis->bounceDirection.y * bounceSpeed);
		pthis->velocityFromBounce.z = (pthis->bounceDirection.z * bounceSpeed);
		pthis->sinkSpeed = 0.0f;
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_AWA_BOUND);
		pthis->graphicRotSpeed = 128.0f / FRAMERATE_SCALER_INV;
		pthis->graphicEccentricity = 0.48f;
	}
	pthis->actor.velocity.x = pthis->velocityFromBounce.x + pthis->velocityFromBump.x;
	pthis->actor.velocity.y = pthis->velocityFromBounce.y + pthis->velocityFromBump.y + pthis->sinkSpeed;
	pthis->actor.velocity.z = pthis->velocityFromBounce.z + pthis->velocityFromBump.z;
	Math_ApproachF(&pthis->velocityFromBump.x, 0.0f, 0.3f, 0.1f);
	Math_ApproachF(&pthis->velocityFromBump.y, 0.0f, 0.3f, 0.1f);
	Math_ApproachF(&pthis->velocityFromBump.z, 0.0f, 0.3f, 0.1f);
}

u32 func_809CC648(EnBubble* pthis)
{
	if(((pthis->colliderSphere.base.acFlags & AC_HIT) != 0) == false)
	{
		return false;
	}
	pthis->colliderSphere.base.acFlags &= ~AC_HIT;
	if(pthis->colliderSphere.elements[1].info.bumperFlags & BUMP_HIT)
	{
		pthis->unk_1F0.x = pthis->colliderSphere.base.ac->velocity.x / 10.0f;
		pthis->unk_1F0.y = pthis->colliderSphere.base.ac->velocity.y / 10.0f;
		pthis->unk_1F0.z = pthis->colliderSphere.base.ac->velocity.z / 10.0f;
		pthis->graphicRotSpeed = 128.0f;
		pthis->graphicEccentricity = 0.48f;
		return false;
	}
	pthis->unk_208 = 8;
	return true;
}

u32 EnBubble_DetectPop(EnBubble* pthis, GlobalContext* globalCtx)
{
	if(DECR(pthis->unk_208) != 0 || pthis->actionFunc == EnBubble_Pop)
	{
		return false;
	}
	if(pthis->colliderSphere.base.ocFlags2 & OC2_HIT_PLAYER)
	{
		pthis->colliderSphere.base.ocFlags2 &= ~OC2_HIT_PLAYER;
		EnBubble_DamagePlayer(pthis, globalCtx);
		pthis->unk_208 = 8;
		return true;
	}
	return func_809CC648(pthis);
}

void func_809CC774(EnBubble* pthis)
{
	ColliderJntSphElementDim* dim;
	Vec3f src;
	Vec3f dest;

	dim = &pthis->colliderSphere.elements[0].dim;
	src.x = dim->modelSphere.center.x;
	src.y = dim->modelSphere.center.y;
	src.z = dim->modelSphere.center.z;

	Matrix_MultVec3f(&src, &dest);
	dim->worldSphere.center.x = dest.x;
	dim->worldSphere.center.y = dest.y;
	dim->worldSphere.center.z = dest.z;
	dim->worldSphere.radius = dim->modelSphere.radius * (1.0f + pthis->expansionWidth);
	pthis->colliderSphere.elements[1].dim = *dim;
}

void EnBubble_Init(Actor* thisx, GlobalContext* globalCtx)
{
	EnBubble* pthis = (EnBubble*)thisx;
	u32 pad;

	ActorShape_Init(&pthis->actor.shape, 16.0f, ActorShadow_DrawCircle, 0.2f);
	Collider_InitJntSph(globalCtx, &pthis->colliderSphere);
	Collider_SetJntSph(globalCtx, &pthis->colliderSphere, &pthis->actor, &sJntSphInit, pthis->colliderSphereItems);
	CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(9), &sColChkInfoInit2);
	pthis->actor.naviEnemyId = 0x16;
	pthis->bounceDirection.x = Rand_ZeroOne();
	pthis->bounceDirection.y = Rand_ZeroOne();
	pthis->bounceDirection.z = Rand_ZeroOne();
	EnBubble_Vec3fNormalize(&pthis->bounceDirection);
	pthis->velocityFromBounce.x = pthis->bounceDirection.x * 3.0f;
	pthis->velocityFromBounce.y = pthis->bounceDirection.y * 3.0f;
	pthis->velocityFromBounce.z = pthis->bounceDirection.z * 3.0f;
	EnBubble_SetDimensions(pthis, 0.0f);
	pthis->actionFunc = EnBubble_Wait;
}

void EnBubble_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	EnBubble* pthis = (EnBubble*)thisx;

	Collider_DestroyJntSph(globalCtx, &pthis->colliderSphere);
}

void EnBubble_Wait(EnBubble* pthis, GlobalContext* globalCtx)
{
	if(EnBubble_DetectPop(pthis, globalCtx))
	{
		pthis->explosionCountdown = func_809CBCBC(pthis);
		pthis->actionFunc = EnBubble_Pop;
	}
	else
	{
		EnBubble_Fly(pthis, globalCtx);
		pthis->actor.shape.yOffset = ((pthis->expansionHeight + 1.0f) * 16.0f);
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSphere.base);
		CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSphere.base);
	}
}

void EnBubble_Pop(EnBubble* pthis, GlobalContext* globalCtx)
{
	if(EnBubble_Explosion(pthis, globalCtx) >= 0)
	{
		Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 60, NA_SE_EN_AWA_BREAK);
		Actor_Kill(&pthis->actor);
	}
}

// unused
void EnBubble_Disappear(EnBubble* pthis, GlobalContext* globalCtx)
{
	s32 temp_v0;

	temp_v0 = func_809CBFD4(pthis);
	if(temp_v0 >= 0)
	{
		pthis->actor.shape.shadowDraw = ActorShadow_DrawCircle;
		pthis->explosionCountdown = temp_v0;
		pthis->actionFunc = EnBubble_Regrow;
	}
}

// unused
void EnBubble_Regrow(EnBubble* pthis, GlobalContext* globalCtx)
{
	if(func_809CC020(pthis))
	{
		pthis->actionFunc = EnBubble_Wait;
	}
	CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSphere.base);
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSphere.base);
}

void EnBubble_Update(Actor* thisx, GlobalContext* globalCtx)
{
	EnBubble* pthis = (EnBubble*)thisx;

	Actor_UpdatePosition(&pthis->actor);
	Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 16.0f, 16.0f, 0.0f, 7);
	pthis->actionFunc(pthis, globalCtx);
	Actor_SetFocus(&pthis->actor, pthis->actor.shape.yOffset);
}

void EnBubble_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	EnBubble* pthis = (EnBubble*)thisx;
	u32 pad;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_bubble.c", 1175);

	if(pthis->actionFunc != EnBubble_Disappear)
	{
		func_80093D84(globalCtx->gfxCtx);
		Math_SmoothStepToF(&pthis->graphicRotSpeed, 16.0f, 0.2f, 1000.0f, 0.0f);
		Math_SmoothStepToF(&pthis->graphicEccentricity, 0.08f, 0.2f, 1000.0f, 0.0f);
		func_800D1FD4(&globalCtx->billboardMtxF);

		Matrix_Scale(pthis->expansionWidth + 1.0f, pthis->expansionHeight + 1.0f, 1.0f, MTXMODE_APPLY);
		Matrix_RotateZ(((f32)globalCtx->frames.toFloat() * (M_PI / 180.0f)) * pthis->graphicRotSpeed, MTXMODE_APPLY);
		Matrix_Scale(pthis->graphicEccentricity + 1.0f, 1.0f, 1.0f, MTXMODE_APPLY);
		Matrix_RotateZ((-(f32)globalCtx->frames.toFloat() * (M_PI / 180.0f)) * pthis->graphicRotSpeed, MTXMODE_APPLY);

		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_en_bubble.c", 1220), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, gBubbleDL);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_bubble.c", 1226);

	if(pthis->actionFunc != EnBubble_Disappear)
	{
		pthis->actor.shape.shadowScale = (f32)((pthis->expansionWidth + 1.0f) * 0.2f);
		func_809CC774(pthis);
	}
}

void EnBubble_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	En_Bubble_InitVars = {
	    ACTOR_EN_BUBBLE, ACTORCAT_ENEMY, FLAGS, OBJECT_BUBBLE, ACTOR_FACTORY(EnBubble), (ActorFunc)EnBubble_Init, (ActorFunc)EnBubble_Destroy, (ActorFunc)EnBubble_Update, (ActorFunc)EnBubble_Draw, (ActorFunc)EnBubble_Reset,
	};

	sJntSphInit = {
	    {
		COLTYPE_HIT6,
		AT_ON | AT_TYPE_ENEMY,
		AC_ON | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_ALL,
		OC2_TYPE_1,
		COLSHAPE_JNTSPH,
	    },
	    2,
	    sJntSphElementsInit,
	};

	sColChkInfoInit2 = {
	    1, 2, 25, 25, MASS_IMMOVABLE,
	};

	sEffectAccel = {0.0f, -0.5f, 0.0f};

	sEffectPrimColor = {255, 255, 255, 255};

	sEffectEnvColor = {150, 150, 150, 0};
}
