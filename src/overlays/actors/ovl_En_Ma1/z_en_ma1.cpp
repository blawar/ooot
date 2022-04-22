#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MA1_Z_EN_MA1_C
#include "actor_common.h"
/*
 * File: z_en_ma1.c
 * Overlay: En_Ma1
 * Description: Child Malon
 */

#include "z_en_ma1.h"
#include "def/audio.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "objects/object_ma1/object_ma1.h"

#define FLAGS (ACTOR_FLAG_VISIBLE | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_25)

void EnMa1_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMa1_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnMa1_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMa1_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMa1_Draw(Actor* thisx, GlobalContext* globalCtx);

u16 EnMa1_GetText(GlobalContext* globalCtx, Actor* pthis);
s16 func_80AA0778(GlobalContext* globalCtx, Actor* pthis);

void func_80AA0D88(EnMa1* pthis, GlobalContext* globalCtx);
void func_80AA0EA0(EnMa1* pthis, GlobalContext* globalCtx);
void func_80AA0EFC(EnMa1* pthis, GlobalContext* globalCtx);
void func_80AA0F44(EnMa1* pthis, GlobalContext* globalCtx);
void func_80AA106C(EnMa1* pthis, GlobalContext* globalCtx);
void func_80AA10EC(EnMa1* pthis, GlobalContext* globalCtx);
void func_80AA1150(EnMa1* pthis, GlobalContext* globalCtx);
void EnMa1_DoNothing(EnMa1* pthis, GlobalContext* globalCtx);

ActorInit En_Ma1_InitVars = {
    ACTOR_EN_MA1, ACTORCAT_NPC, FLAGS, OBJECT_MA1, sizeof(EnMa1), (ActorFunc)EnMa1_Init, (ActorFunc)EnMa1_Destroy, (ActorFunc)EnMa1_Update, (ActorFunc)EnMa1_Draw, (ActorFunc)EnMa1_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
	COLTYPE_NONE,
	AT_NONE,
	AC_NONE,
	OC1_ON | OC1_TYPE_ALL,
	OC2_TYPE_2,
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
    {18, 46, 0, {0, 0, 0}},
};

static CollisionCheckInfoInit2 sColChkInfoInit = {0, 0, 0, 0, MASS_IMMOVABLE};

static struct_D_80AA1678 sAnimationInfo[] = {
    {&gMalonChildIdleAnim, 1.0f, ANIMMODE_LOOP, 0.0f},
    {&gMalonChildIdleAnim, 1.0f, ANIMMODE_LOOP, -10.0f},
    {&gMalonChildSingAnim, 1.0f, ANIMMODE_LOOP, 0.0f},
    {&gMalonChildSingAnim, 1.0f, ANIMMODE_LOOP, -10.0f},
};

static Vec3f D_80AA16B8 = {800.0f, 0.0f, 0.0f};

static void* sMouthTextures[] = {
    gMalonChildNeutralMouthTex,
    gMalonChildSmilingMouthTex,
    gMalonChildTalkingMouthTex,
};

static void* sEyeTextures[] = {
    gMalonChildEyeOpenTex,
    gMalonChildEyeHalfTex,
    gMalonChildEyeClosedTex,
};

u16 EnMa1_GetText(GlobalContext* globalCtx, Actor* thisx)
{
	u16 faceReaction = Text_GetFaceReaction(globalCtx, 0x17);

	if(faceReaction != 0)
	{
		return faceReaction;
	}
	if(CHECK_QUEST_ITEM(QUEST_SONG_EPONA))
	{
		return 0x204A;
	}
	if(gSaveContext.eventChkInf[1] & 0x40)
	{
		return 0x2049;
	}
	if(gSaveContext.eventChkInf[1] & 0x20)
	{
		if((gSaveContext.infTable[8] & 0x20))
		{
			return 0x2049;
		}
		else
		{
			return 0x2048;
		}
	}
	if(gSaveContext.eventChkInf[1] & 0x10)
	{
		return 0x2047;
	}
	if(gSaveContext.eventChkInf[1] & 4)
	{
		return 0x2044;
	}
	if(gSaveContext.infTable[8] & 0x10)
	{
		if(gSaveContext.infTable[8] & 0x800)
		{
			return 0x2043;
		}
		else
		{
			return 0x2042;
		}
	}
	return 0x2041;
}

s16 func_80AA0778(GlobalContext* globalCtx, Actor* thisx)
{
	s16 ret = 1;

	switch(Message_GetState(&globalCtx->msgCtx))
	{
		case TEXT_STATE_CLOSING:
			switch(thisx->textId)
			{
				case 0x2041:
					gSaveContext.infTable[8] |= 0x10;
					gSaveContext.eventChkInf[1] |= 1;
					ret = 0;
					break;
				case 0x2043:
					ret = 1;
					break;
				case 0x2047:
					gSaveContext.eventChkInf[1] |= 0x20;
					ret = 0;
					break;
				case 0x2048:
					gSaveContext.infTable[8] |= 0x20;
					ret = 0;
					break;
				case 0x2049:
					gSaveContext.eventChkInf[1] |= 0x40;
					ret = 0;
					break;
				case 0x2061:
					ret = 2;
					break;
				default:
					ret = 0;
					break;
			}
			break;
		case TEXT_STATE_CHOICE:
		case TEXT_STATE_EVENT:
			if(Message_ShouldAdvance(globalCtx))
			{
				ret = 2;
			}
			break;
		case TEXT_STATE_DONE:
			if(Message_ShouldAdvance(globalCtx))
			{
				ret = 3;
			}
			break;
		case TEXT_STATE_NONE:
		case TEXT_STATE_DONE_HAS_NEXT:
		case TEXT_STATE_DONE_FADING:
		case TEXT_STATE_SONG_DEMO_DONE:
		case TEXT_STATE_8:
		case TEXT_STATE_9:
			ret = 1;
			break;
	}
	return ret;
}

s32 func_80AA08C4(EnMa1* pthis, GlobalContext* globalCtx)
{
	if((pthis->actor.shape.rot.z == 3) && (gSaveContext.sceneSetupIndex == 5))
	{
		return 1;
	}
	if(!LINK_IS_CHILD)
	{
		return 0;
	}
	if(((globalCtx->sceneNum == SCENE_MARKET_NIGHT) || (globalCtx->sceneNum == SCENE_MARKET_DAY)) && !(gSaveContext.eventChkInf[1] & 0x10) && !(gSaveContext.infTable[8] & 0x800))
	{
		return 1;
	}
	if((globalCtx->sceneNum == SCENE_SPOT15) && !(gSaveContext.eventChkInf[1] & 0x10))
	{
		if(gSaveContext.infTable[8] & 0x800)
		{
			return 1;
		}
		else
		{
			gSaveContext.infTable[8] |= 0x800;
			return 0;
		}
	}
	if((globalCtx->sceneNum == SCENE_SOUKO) && IS_NIGHT && (gSaveContext.eventChkInf[1] & 0x10))
	{
		return 1;
	}
	if(globalCtx->sceneNum != SCENE_SPOT20)
	{
		return 0;
	}
	if((pthis->actor.shape.rot.z == 3) && IS_DAY && (gSaveContext.eventChkInf[1] & 0x10))
	{
		return 1;
	}
	return 0;
}

void EnMa1_UpdateEyes(EnMa1* pthis)
{
	if(DECR(pthis->blinkTimer) == 0)
	{
		pthis->eyeIndex += 1;
		if(pthis->eyeIndex >= 3)
		{
			pthis->blinkTimer = Rand_S16Offset(30, 30);
			pthis->eyeIndex = 0;
		}
	}
}

void EnMa1_ChangeAnimation(EnMa1* pthis, UNK_TYPE idx)
{
	f32 frameCount = Animation_GetLastFrame(sAnimationInfo[idx].animation);

	Animation_Change(&pthis->skelAnime, sAnimationInfo[idx].animation, 1.0f, 0.0f, frameCount, sAnimationInfo[idx].mode, sAnimationInfo[idx].transitionRate);
}

void func_80AA0AF4(EnMa1* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	s16 phi_a3;

	if((pthis->unk_1E8.unk_00 == 0) && (pthis->skelAnime.animation == &gMalonChildSingAnim))
	{
		phi_a3 = 1;
	}
	else
	{
		phi_a3 = 0;
	}

	pthis->unk_1E8.position = player->actor.world.pos;
	pthis->unk_1E8.position.y -= -10.0f;

	func_80034A14(&pthis->actor, &pthis->unk_1E8, 0, phi_a3);
}

void func_80AA0B74(EnMa1* pthis)
{
	if(pthis->skelAnime.animation == &gMalonChildSingAnim)
	{
		if(pthis->unk_1E8.unk_00 == 0)
		{
			if(pthis->unk_1E0 != 0)
			{
				pthis->unk_1E0 = 0;
				func_800F6584(0);
			}
		}
		else
		{
			if(pthis->unk_1E0 == 0)
			{
				pthis->unk_1E0 = 1;
				func_800F6584(1);
			}
		}
	}
}

void EnMa1_Init(Actor* thisx, GlobalContext* globalCtx)
{
	EnMa1* pthis = (EnMa1*)thisx;
	s32 pad;

	ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 18.0f);
	SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gMalonChildSkel, NULL, NULL, NULL, 0);
	Collider_InitCylinder(globalCtx, &pthis->collider);
	Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
	CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(22), &sColChkInfoInit);

	if(!func_80AA08C4(pthis, globalCtx))
	{
		Actor_Kill(&pthis->actor);
		return;
	}

	Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
	Actor_SetScale(&pthis->actor, 0.01f);
	pthis->actor.targetMode = 6;
	pthis->unk_1E8.unk_00 = 0;

	if(!(gSaveContext.eventChkInf[1] & 0x10) || CHECK_QUEST_ITEM(QUEST_SONG_EPONA))
	{
		pthis->actionFunc = func_80AA0D88;
		EnMa1_ChangeAnimation(pthis, 2);
	}
	else
	{
		pthis->actionFunc = func_80AA0F44;
		EnMa1_ChangeAnimation(pthis, 2);
	}
}

void EnMa1_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	EnMa1* pthis = (EnMa1*)thisx;

	SkelAnime_Free(&pthis->skelAnime, globalCtx);
	Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AA0D88(EnMa1* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_1E8.unk_00 != 0)
	{
		if(pthis->skelAnime.animation != &gMalonChildIdleAnim)
		{
			EnMa1_ChangeAnimation(pthis, 1);
		}
	}
	else
	{
		if(pthis->skelAnime.animation != &gMalonChildSingAnim)
		{
			EnMa1_ChangeAnimation(pthis, 3);
		}
	}

	if((globalCtx->sceneNum == SCENE_SPOT15) && (gSaveContext.eventChkInf[1] & 0x10))
	{
		Actor_Kill(&pthis->actor);
	}
	else if(!(gSaveContext.eventChkInf[1] & 0x10) || CHECK_QUEST_ITEM(QUEST_SONG_EPONA))
	{
		if(pthis->unk_1E8.unk_00 == 2)
		{
			pthis->actionFunc = func_80AA0EA0;
			globalCtx->msgCtx.stateTimer = 4;
			globalCtx->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
		}
	}
}

void func_80AA0EA0(EnMa1* pthis, GlobalContext* globalCtx)
{
	if(Actor_HasParent(&pthis->actor, globalCtx))
	{
		pthis->actor.parent = NULL;
		pthis->actionFunc = func_80AA0EFC;
	}
	else
	{
		func_8002F434(&pthis->actor, globalCtx, GI_WEIRD_EGG, 120.0f, 10.0f);
	}
}

void func_80AA0EFC(EnMa1* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_1E8.unk_00 == 3)
	{
		pthis->unk_1E8.unk_00 = 0;
		pthis->actionFunc = func_80AA0D88;
		gSaveContext.eventChkInf[1] |= 4;
		globalCtx->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
	}
}

void func_80AA0F44(EnMa1* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	if(pthis->unk_1E8.unk_00 != 0)
	{
		if(pthis->skelAnime.animation != &gMalonChildIdleAnim)
		{
			EnMa1_ChangeAnimation(pthis, 1);
		}
	}
	else
	{
		if(pthis->skelAnime.animation != &gMalonChildSingAnim)
		{
			EnMa1_ChangeAnimation(pthis, 3);
		}
	}

	if(gSaveContext.eventChkInf[1] & 0x40)
	{
		if(player->stateFlags2 & PLAYER_STATE2_24)
		{
			player->stateFlags2 |= PLAYER_STATE2_25;
			player->unk_6A8 = &pthis->actor;
			pthis->actor.textId = 0x2061;
			Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
			pthis->unk_1E8.unk_00 = 1;
			pthis->actor.flags |= ACTOR_FLAG_16;
			pthis->actionFunc = func_80AA106C;
		}
		else if(pthis->actor.xzDistToPlayer < 30.0f + (f32)pthis->collider.dim.radius)
		{
			player->stateFlags2 |= PLAYER_STATE2_23;
		}
	}
}

void func_80AA106C(EnMa1* pthis, GlobalContext* globalCtx)
{
	GET_PLAYER(globalCtx)->stateFlags2 |= PLAYER_STATE2_23;
	if(pthis->unk_1E8.unk_00 == 2)
	{
		Audio_OcaSetInstrument(2);
		func_8010BD58(globalCtx, OCARINA_ACTION_TEACH_EPONA);
		pthis->actor.flags &= ~ACTOR_FLAG_16;
		pthis->actionFunc = func_80AA10EC;
	}
}

void func_80AA10EC(EnMa1* pthis, GlobalContext* globalCtx)
{
	GET_PLAYER(globalCtx)->stateFlags2 |= PLAYER_STATE2_23;
	if(Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_SONG_DEMO_DONE)
	{
		func_8010BD58(globalCtx, OCARINA_ACTION_PLAYBACK_EPONA);
		pthis->actionFunc = func_80AA1150;
	}
}

void func_80AA1150(EnMa1* pthis, GlobalContext* globalCtx)
{
	GET_PLAYER(globalCtx)->stateFlags2 |= PLAYER_STATE2_23;
	if(globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03)
	{
		globalCtx->nextEntranceIndex = 0x157;
		gSaveContext.nextCutsceneIndex = 0xFFF1;
		globalCtx->fadeTransition = 42;
		globalCtx->sceneLoadFlag = 0x14;
		pthis->actionFunc = EnMa1_DoNothing;
	}
}

void EnMa1_DoNothing(EnMa1* pthis, GlobalContext* globalCtx)
{
}

void EnMa1_Update(Actor* thisx, GlobalContext* globalCtx)
{
	EnMa1* pthis = (EnMa1*)thisx;
	s32 pad;

	Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
	SkelAnime_Update(&pthis->skelAnime);
	EnMa1_UpdateEyes(pthis);
	pthis->actionFunc(pthis, globalCtx);
	if(pthis->actionFunc != EnMa1_DoNothing)
	{
		func_800343CC(globalCtx, &pthis->actor, &pthis->unk_1E8.unk_00, (f32)pthis->collider.dim.radius + 30.0f, EnMa1_GetText, func_80AA0778);
	}
	func_80AA0B74(pthis);
	func_80AA0AF4(pthis, globalCtx);
}

s32 EnMa1_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	EnMa1* pthis = (EnMa1*)thisx;
	Vec3s vec;

	if((limbIndex == 2) || (limbIndex == 5))
	{
		*dList = NULL;
	}
	if(limbIndex == 15)
	{
		Matrix_Translate(1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
		vec = pthis->unk_1E8.unk_08;
		Matrix_RotateX((vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
		Matrix_RotateZ((vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
		Matrix_Translate(-1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
	}
	if(limbIndex == 8)
	{
		vec = pthis->unk_1E8.unk_0E;
		Matrix_RotateX((-vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
		Matrix_RotateZ((-vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
	}
	return false;
}

void EnMa1_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	EnMa1* pthis = (EnMa1*)thisx;
	Vec3f vec = D_80AA16B8;

	if(limbIndex == 15)
	{
		Matrix_MultVec3f(&vec, &pthis->actor.focus.pos);
	}
}

void EnMa1_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	EnMa1* pthis = (EnMa1*)thisx;
	Camera* camera;
	f32 distFromCamera;
	s32 pad;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_ma1.c", 1226);

	camera = GET_ACTIVE_CAM(globalCtx);
	distFromCamera = Math_Vec3f_DistXZ(&pthis->actor.world.pos, &camera->eye);
	func_800F6268(distFromCamera, NA_BGM_LONLON);
	func_80093D18(globalCtx->gfxCtx);

	gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sMouthTextures[pthis->mouthIndex]));
	gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures[pthis->eyeIndex]));

	SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, EnMa1_OverrideLimbDraw, EnMa1_PostLimbDraw, pthis);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_ma1.c", 1261);
}

void EnMa1_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	En_Ma1_InitVars = {
	    ACTOR_EN_MA1, ACTORCAT_NPC, FLAGS, OBJECT_MA1, sizeof(EnMa1), (ActorFunc)EnMa1_Init, (ActorFunc)EnMa1_Destroy, (ActorFunc)EnMa1_Update, (ActorFunc)EnMa1_Draw, (ActorFunc)EnMa1_Reset,
	};

	sCylinderInit = {
	    {
		COLTYPE_NONE,
		AT_NONE,
		AC_NONE,
		OC1_ON | OC1_TYPE_ALL,
		OC2_TYPE_2,
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
	    {18, 46, 0, {0, 0, 0}},
	};

	sColChkInfoInit = {0, 0, 0, 0, MASS_IMMOVABLE};

	D_80AA16B8 = {800.0f, 0.0f, 0.0f};
}
