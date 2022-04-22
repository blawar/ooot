#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_PO_RELAY_Z_EN_PO_RELAY_C
#include "actor_common.h"
/*
 * File: z_en_po_relay.c
 * Overlay: ovl_En_Po_Relay
 * Description: Dampé's Ghost
 */

#include "overlays/actors/ovl_En_Honotrap/z_en_honotrap.h"
#include "z_en_po_relay.h"
#include "def/random.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "objects/object_tk/object_tk.h"

#define FLAGS (ACTOR_FLAG_VISIBLE | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_12 | ACTOR_FLAG_16)

void EnPoRelay_Init(Actor* thisx, GlobalContext* globalCtx);
void EnPoRelay_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnPoRelay_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnPoRelay_Update(Actor* thisx, GlobalContext* globalCtx);
void EnPoRelay_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnPoRelay_Idle(EnPoRelay* pthis, GlobalContext* globalCtx);
void EnPoRelay_Race(EnPoRelay* pthis, GlobalContext* globalCtx);
void EnPoRelay_EndRace(EnPoRelay* pthis, GlobalContext* globalCtx);
void EnPoRelay_Talk(EnPoRelay* pthis, GlobalContext* globalCtx);
void EnPoRelay_Talk2(EnPoRelay* pthis, GlobalContext* globalCtx);
void EnPoRelay_DisappearAndReward(EnPoRelay* pthis, GlobalContext* globalCtx);
void EnPoRelay_SetupIdle(EnPoRelay* pthis);

static Vec3s D_80AD8C30[] = {
    {0xFFC4, 0xFDEE, 0xF47A}, {0x0186, 0xFE0C, 0xF47A}, {0x0186, 0xFE0C, 0xF0F6}, {0x00D2, 0xFDEE, 0xF0F6}, {0x00D2, 0xFD9E, 0xEEDA}, {0x023A, 0xFDC6, 0xEEDA}, {0x023A, 0xFDC6, 0xED18},
    {0x00D2, 0xFDC6, 0xED18}, {0x00D2, 0xFDC6, 0xEBCE}, {0x00D2, 0xFDC6, 0xEAA2}, {0x023A, 0xFDC6, 0xEAA2}, {0x023A, 0xFDC6, 0xEBB0}, {0x04EC, 0xFD9E, 0xEBB0}, {0x0672, 0xFD62, 0xED18},
    {0x0672, 0xFD30, 0xEE80}, {0x07DA, 0xFD26, 0xEE80}, {0x07DA, 0xFD26, 0xEF70}, {0x07DA, 0xFD26, 0xF204}, {0x0672, 0xFD44, 0xF204}, {0x0672, 0xFD6C, 0xF3C6}, {0x088E, 0xFD6C, 0xF3C6},
    {0x088E, 0xFDB2, 0xF5E2}, {0x099C, 0xFDD0, 0xF5E2}, {0x0B54, 0xFE66, 0xF772}, {0x0B4E, 0xFE66, 0xF87E}, {0x0B4A, 0xFE66, 0xF97A}, {0x0B4A, 0xFE98, 0xF9FC}, {0x0BAE, 0xFE98, 0xF9FC},
};

ActorInit En_Po_Relay_InitVars = {
    ACTOR_EN_PO_RELAY, ACTORCAT_NPC, FLAGS, OBJECT_TK, sizeof(EnPoRelay), (ActorFunc)EnPoRelay_Init, (ActorFunc)EnPoRelay_Destroy, (ActorFunc)EnPoRelay_Update, (ActorFunc)EnPoRelay_Draw, (ActorFunc)EnPoRelay_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
	COLTYPE_NONE,
	AT_NONE,
	AC_NONE,
	OC1_ON | OC1_TYPE_ALL,
	OC2_TYPE_1,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK0,
	{0x00000000, 0x00, 0x00},
	{0x00000000, 0x00, 0x00},
	TOUCH_NONE,
	BUMP_NONE,
	OCELEM_ON,
    },
    {30, 52, 0, {0, 0, 0}},
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x4F, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 1500, ICHAIN_STOP),
};

static Vec3f D_80AD8D30 = {0.0f, 1.5f, 0.0f};

static Vec3f D_80AD8D3C = {0.0f, 0.0f, 0.0f};

static Vec3f D_80AD8D48 = {0.0f, 1200.0f, 0.0f};

static void* sEyesTextures[] = {
    gDampeEyeOpenTex,
    gDampeEyeHalfTex,
    gDampeEyeClosedTex,
};

static s32 gDampeSpawnFlag = 0; // Flag to ensure that Damp is only spawned once

void EnPoRelay_Init(Actor* thisx, GlobalContext* globalCtx)
{
	EnPoRelay* pthis = (EnPoRelay*)thisx;

	Actor_ProcessInitChain(&pthis->actor, sInitChain);
	ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 42.0f);
	SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gDampeSkel, &gDampeFloatAnim, pthis->jointTable, pthis->morphTable, 18);
	Collider_InitCylinder(globalCtx, &pthis->collider);
	Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
	pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
	Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z, 255, 255, 255, 200);
	pthis->lightColor.a = 255;

	if(gDampeSpawnFlag != 0)
	{				   // Has Dampe already been spawned?
		Actor_Kill(&pthis->actor); // Don't spawn again
	}
	else
	{
		gDampeSpawnFlag = 1;
		Actor_SetTextWithPrefix(globalCtx, &pthis->actor, 65);
		pthis->textId = pthis->actor.textId;
		EnPoRelay_SetupIdle(pthis);
	}

	pthis->actor.params &= 0x3F;
}

void EnPoRelay_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	EnPoRelay* pthis = (EnPoRelay*)thisx;

	LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
	Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnPoRelay_SetupIdle(EnPoRelay* pthis)
{
	pthis->bouncingTimer = 32;
	pthis->pathIndex = 0;
	pthis->actor.room = -1;
	pthis->actor.shape.rot.y = 0;
	pthis->actor.world.rot.y = -0x8000;
	pthis->actor.colChkInfo.mass = MASS_HEAVY;
	pthis->actionFunc = EnPoRelay_Idle;
}

void EnPoRelay_Vec3sToVec3f(Vec3f* dest, Vec3s* src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
}

void EnPoRelay_SetupRace(EnPoRelay* pthis)
{
	Vec3f vec;

	EnPoRelay_Vec3sToVec3f(&vec, &D_80AD8C30[pthis->pathIndex]);
	pthis->actionTimer = ((s16)(pthis->actor.shape.rot.y - pthis->actor.world.rot.y - 0x8000) >> 0xB) % 32U;
	func_80088B34(0);
	pthis->hookshotSlotFull = INV_CONTENT(ITEM_HOOKSHOT) != ITEM_NONE;
	pthis->unk_19A = Actor_WorldYawTowardPoint(&pthis->actor, &vec);
	pthis->actor.flags |= ACTOR_FLAG_27;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
	pthis->actionFunc = EnPoRelay_Race;
}

void EnPoRelay_SetupEndRace(EnPoRelay* pthis)
{
	pthis->actor.world.rot.y = pthis->actor.home.rot.y + 0xC000;
	pthis->actor.flags &= ~ACTOR_FLAG_27;
	pthis->actor.speedXZ = 0.0f;
	pthis->actionFunc = EnPoRelay_EndRace;
}

void EnPoRelay_CorrectY(EnPoRelay* pthis)
{
	Math_StepToF(&pthis->actor.home.pos.y, D_80AD8C30[(pthis->pathIndex >= 28) ? 27 : pthis->pathIndex].y + 45.0f, 2.0f);
	pthis->actor.world.pos.y = Math_SinS(pthis->bouncingTimer * 0x800) * 8.0f + pthis->actor.home.pos.y;
}

void EnPoRelay_Idle(EnPoRelay* pthis, GlobalContext* globalCtx)
{
	Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0x100);
	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		pthis->actor.flags &= ~ACTOR_FLAG_16;
		pthis->actionFunc = EnPoRelay_Talk;
	}
	else if(pthis->actor.xzDistToPlayer < 250.0f)
	{
		pthis->actor.flags |= ACTOR_FLAG_16;
		pthis->actor.textId = pthis->textId;
		func_8002F2CC(&pthis->actor, globalCtx, 250.0f);
	}
	func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
}

void EnPoRelay_Talk(EnPoRelay* pthis, GlobalContext* globalCtx)
{
	Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0x100);
	if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		Actor_SetTextWithPrefix(globalCtx, &pthis->actor, 0x2F);
		pthis->textId = pthis->actor.textId;
		EnPoRelay_SetupRace(pthis);
	}
	func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
}

void EnPoRelay_Race(EnPoRelay* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	Vec3f vec;
	f32 speed;
	f32 multiplier;

	if(pthis->actionTimer != 0)
	{
		pthis->actionTimer--;
	}
	if(pthis->actionTimer == 0 && Rand_ZeroOne() < 0.03f)
	{
		pthis->actionTimer = 32;
		if(pthis->pathIndex < 23)
		{
			speed = Rand_ZeroOne() * 3.0f;
			if(speed < 1.0f)
			{
				multiplier = 1.0f;
			}
			else if(speed < 2.0f)
			{
				multiplier = -1.0f;
			}
			else
			{
				multiplier = 0.0f;
			}
			speed = 30.0f * multiplier;
			Actor_Spawn(
			    &globalCtx->actorCtx, globalCtx, ACTOR_EN_HONOTRAP, Math_CosS(pthis->unk_19A) * speed + pthis->actor.world.pos.x, pthis->actor.world.pos.y, Math_SinS(pthis->unk_19A) * speed + pthis->actor.world.pos.z, 0,
			    (pthis->unk_19A + 0x8000) - (0x2000 * multiplier), 0, HONOTRAP_FLAME_DROP);
		}
	}
	Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_19A, 2, 0x1000, 0x100);
	pthis->actor.shape.rot.y = pthis->actor.world.rot.y + (pthis->actionTimer * 0x800) + 0x8000;
	if(pthis->pathIndex < 23)
	{
		// If the player travels along a different path to Dampé that converges later
		if((Math3D_PointInSquare2D(660.0f, 840.0f, -4480.0f, -3760.0f, player->actor.world.pos.x, player->actor.world.pos.z) != 0) ||
		   (Math3D_PointInSquare2D(1560.0f, 1740.0f, -4030.0f, -3670.0f, player->actor.world.pos.x, player->actor.world.pos.z) != 0) ||
		   (Math3D_PointInSquare2D(1580.0f, 2090.0f, -3030.0f, -2500.0f, player->actor.world.pos.x, player->actor.world.pos.z) != 0))
		{
			speed = (pthis->hookshotSlotFull) ? player->actor.speedXZ * 1.4f : player->actor.speedXZ * 1.2f;
		}
		else if(pthis->actor.xzDistToPlayer < 150.0f)
		{
			speed = (pthis->hookshotSlotFull) ? player->actor.speedXZ * 1.2f : player->actor.speedXZ;
		}
		else if(pthis->actor.xzDistToPlayer < 300.0f)
		{
			speed = (pthis->hookshotSlotFull) ? player->actor.speedXZ : player->actor.speedXZ * 0.8f;
		}
		else if(pthis->hookshotSlotFull)
		{
			speed = 4.5f;
		}
		else
		{
			speed = 3.5f;
		}
		multiplier = 250.0f - pthis->actor.xzDistToPlayer;
		multiplier = CLAMP_MIN(multiplier, 0.0f);
		speed += multiplier * 0.02f + 1.0f;
		Math_ApproachF(&pthis->actor.speedXZ, speed, 0.5f, 1.5f);
	}
	else
	{
		Math_ApproachF(&pthis->actor.speedXZ, 3.5f, 0.5f, 1.5f);
	}
	EnPoRelay_Vec3sToVec3f(&vec, &D_80AD8C30[pthis->pathIndex]);
	if(Actor_WorldDistXZToPoint(&pthis->actor, &vec) < 40.0f)
	{
		pthis->pathIndex++;
		EnPoRelay_Vec3sToVec3f(&vec, &D_80AD8C30[pthis->pathIndex]);
		if(pthis->pathIndex == 28)
		{
			EnPoRelay_SetupEndRace(pthis);
		}
		else if(pthis->pathIndex == 9)
		{
			Flags_SetSwitch(globalCtx, 0x35);
		}
		else if(pthis->pathIndex == 17)
		{
			Flags_SetSwitch(globalCtx, 0x36);
		}
		else if(pthis->pathIndex == 25)
		{
			Flags_SetSwitch(globalCtx, 0x37);
		}
	}
	pthis->unk_19A = Actor_WorldYawTowardPoint(&pthis->actor, &vec);
	func_8002F974(&pthis->actor, NA_SE_EN_PO_AWAY - SFX_FLAG);
}

void EnPoRelay_EndRace(EnPoRelay* pthis, GlobalContext* globalCtx)
{
	Math_ScaledStepToS(&pthis->actor.shape.rot.y, -0x4000, 0x800);
	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		pthis->actionFunc = EnPoRelay_Talk2;
	}
	else if(globalCtx->roomCtx.curRoom.num == 5)
	{
		Actor_Kill(&pthis->actor);
		gSaveContext.timer1State = 0;
	}
	else if(Actor_IsFacingAndNearPlayer(&pthis->actor, 150.0f, 0x3000))
	{
		pthis->actor.textId = pthis->textId;
		func_8002F2CC(&pthis->actor, globalCtx, 250.0f);
	}
	func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
}

void EnPoRelay_Talk2(EnPoRelay* pthis, GlobalContext* globalCtx)
{
	Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0x100);
	if(Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT)
	{
		if(Message_ShouldAdvance(globalCtx))
		{
			if(pthis->hookshotSlotFull != 0)
			{
				Actor_SetTextWithPrefix(globalCtx, &pthis->actor, 0x2E);
			}
			else
			{
				Actor_SetTextWithPrefix(globalCtx, &pthis->actor, 0x2D);
			}
			pthis->textId = pthis->actor.textId;
			Message_ContinueTextbox(globalCtx, pthis->actor.textId);
		}
	}
	else if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		gSaveContext.timer1State = 0;
		pthis->actionTimer = 0;
		pthis->actionFunc = EnPoRelay_DisappearAndReward;
	}
	func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
}

void EnPoRelay_DisappearAndReward(EnPoRelay* pthis, GlobalContext* globalCtx)
{
	Vec3f vec;
	f32 multiplier;
	s32 pad;
	Vec3f sp60;
	s32 pad1;

	pthis->actionTimer++;
	if(pthis->actionTimer < 8)
	{
		if(pthis->actionTimer < 5)
		{
			vec.y = Math_SinS((pthis->actionTimer * 0x1000) - 0x4000) * 23.0f + (pthis->actor.world.pos.y + 40.0f);
			multiplier = Math_CosS((pthis->actionTimer * 0x1000) - 0x4000) * 23.0f;
			vec.x = (Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * multiplier) + pthis->actor.world.pos.x;
			vec.z = (Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * multiplier) + pthis->actor.world.pos.z;
		}
		else
		{
			vec.y = pthis->actor.world.pos.y + 40.0f + 15.0f * (pthis->actionTimer - 5);
			vec.x = (Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * 23.0f) + pthis->actor.world.pos.x;
			vec.z = (Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * 23.0f) + pthis->actor.world.pos.z;
		}
		EffectSsDeadDb_Spawn(globalCtx, &vec, &D_80AD8D30, &D_80AD8D3C, pthis->actionTimer * 10 + 80, 0, 255, 255, 255, 255, 0, 0, 255, 1, 9, true);
		vec.x = (pthis->actor.world.pos.x + pthis->actor.world.pos.x) - vec.x;
		vec.z = (pthis->actor.world.pos.z + pthis->actor.world.pos.z) - vec.z;
		EffectSsDeadDb_Spawn(globalCtx, &vec, &D_80AD8D30, &D_80AD8D3C, pthis->actionTimer * 10 + 80, 0, 255, 255, 255, 255, 0, 0, 255, 1, 9, true);
		vec.x = pthis->actor.world.pos.x;
		vec.z = pthis->actor.world.pos.z;
		EffectSsDeadDb_Spawn(globalCtx, &vec, &D_80AD8D30, &D_80AD8D3C, pthis->actionTimer * 10 + 80, 0, 255, 255, 255, 255, 0, 0, 255, 1, 9, true);
		if(pthis->actionTimer == 1)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EXTINCT);
		}
	}
	if(Math_StepToF(&pthis->actor.scale.x, 0.0f, 0.001f) != 0)
	{
		if(pthis->hookshotSlotFull != 0)
		{
			sp60.x = pthis->actor.world.pos.x;
			sp60.y = pthis->actor.floorHeight;
			sp60.z = pthis->actor.world.pos.z;
			if(gSaveContext.timer1Value < HIGH_SCORE(HS_DAMPE_RACE))
			{
				HIGH_SCORE(HS_DAMPE_RACE) = gSaveContext.timer1Value;
			}
			if(Flags_GetCollectible(globalCtx, pthis->actor.params) == 0 && gSaveContext.timer1Value <= 60)
			{
				Item_DropCollectible2(globalCtx, &sp60, (pthis->actor.params << 8) + (0x4000 | ITEM00_HEART_PIECE));
			}
			else
			{
				Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ITEM00, sp60.x, sp60.y, sp60.z, 0, 0, 0, 2);
			}
		}
		else
		{
			Flags_SetTempClear(globalCtx, 4);
			HIGH_SCORE(HS_DAMPE_RACE) = gSaveContext.timer1Value;
		}
		Actor_Kill(&pthis->actor);
	}
	pthis->actor.scale.y = pthis->actor.scale.x;
	pthis->actor.scale.z = pthis->actor.scale.x;
	pthis->actor.world.pos.y += 10.0f;
}

void EnPoRelay_Update(Actor* thisx, GlobalContext* globalCtx)
{
	EnPoRelay* pthis = (EnPoRelay*)thisx;
	s32 pad;

	SkelAnime_Update(&pthis->skelAnime);
	pthis->actionFunc(pthis, globalCtx);
	Actor_MoveForward(&pthis->actor);
	EnPoRelay_CorrectY(pthis);
	Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 27.0f, 60.0f, 4);
	Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
	Actor_SetFocus(&pthis->actor, 50.0f);
	if(pthis->bouncingTimer != 0)
	{
		pthis->bouncingTimer -= 1;
	}
	if(pthis->bouncingTimer == 0)
	{
		pthis->bouncingTimer = 32;
	}
	pthis->eyeTextureIdx++;
	if(pthis->eyeTextureIdx == 3)
	{
		pthis->eyeTextureIdx = 0;
	}
}

void EnPoRelay_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	EnPoRelay* pthis = (EnPoRelay*)thisx;

	if(limbIndex == 14)
	{
		f32 rand;
		Vec3f vec;

		OPEN_DISPS(globalCtx->gfxCtx, "../z_en_po_relay.c", 885);
		rand = Rand_ZeroOne();
		pthis->lightColor.r = (s16)(rand * 30.0f) + 225;
		pthis->lightColor.g = (s16)(rand * 100.0f) + 155;
		pthis->lightColor.b = (s16)(rand * 160.0f) + 95;
		gDPPipeSync(POLY_OPA_DISP++);
		gDPSetEnvColor(POLY_OPA_DISP++, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b, 128);
		gSPDisplayList(POLY_OPA_DISP++, gDampeLanternDL);
		if(1)
		{
		}
		CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_po_relay.c", 901);
		Matrix_MultVec3f(&D_80AD8D48, &vec);
		Lights_PointNoGlowSetInfo(&pthis->lightInfo, vec.x, vec.y, vec.z, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b, 200);
	}
	else if(limbIndex == 8)
	{
		OPEN_DISPS(globalCtx->gfxCtx, "../z_en_po_relay.c", 916);
		gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_en_po_relay.c", 918), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_OPA_DISP++, gDampeHaloDL);
		CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_po_relay.c", 922);
	}
}

void EnPoRelay_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	EnPoRelay* pthis = (EnPoRelay*)thisx;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_po_relay.c", 940);
	func_80093D18(globalCtx->gfxCtx);
	gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyesTextures[pthis->eyeTextureIdx]));
	SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, NULL, EnPoRelay_PostLimbDraw, &pthis->actor);
	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_po_relay.c", 954);
}

void EnPoRelay_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	En_Po_Relay_InitVars = {
	    ACTOR_EN_PO_RELAY, ACTORCAT_NPC, FLAGS, OBJECT_TK, sizeof(EnPoRelay), (ActorFunc)EnPoRelay_Init, (ActorFunc)EnPoRelay_Destroy, (ActorFunc)EnPoRelay_Update, (ActorFunc)EnPoRelay_Draw, (ActorFunc)EnPoRelay_Reset,
	};

	sCylinderInit = {
	    {
		COLTYPE_NONE,
		AT_NONE,
		AC_NONE,
		OC1_ON | OC1_TYPE_ALL,
		OC2_TYPE_1,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK0,
		{0x00000000, 0x00, 0x00},
		{0x00000000, 0x00, 0x00},
		TOUCH_NONE,
		BUMP_NONE,
		OCELEM_ON,
	    },
	    {30, 52, 0, {0, 0, 0}},
	};

	D_80AD8D30 = {0.0f, 1.5f, 0.0f};

	D_80AD8D3C = {0.0f, 0.0f, 0.0f};

	D_80AD8D48 = {0.0f, 1200.0f, 0.0f};

	gDampeSpawnFlag = 0;
}
