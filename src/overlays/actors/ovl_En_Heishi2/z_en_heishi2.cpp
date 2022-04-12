#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HEISHI2_Z_EN_HEISHI2_C
#include <z64math.h>
#include "actor_common.h"
/*
 * File: z_en_heishi2.c
 * Overlay: ovl_En_Heishi2
 * Description: Hyrulian Guards
 */

#include "overlays/actors/ovl_Bg_Gate_Shutter/z_bg_gate_shutter.h"
#include "overlays/actors/ovl_Bg_Spot15_Saku/z_bg_spot15_saku.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "vt.h"
#include "z_en_heishi2.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"
#include "objects/object_link_child/object_link_child.h"
#include "objects/object_sd/object_sd.h"

#define FLAGS (ACTOR_FLAG_VISIBLE | ACTOR_FLAG_3)

void EnHeishi2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi2_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnHeishi2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi2_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi2_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnHeishi2_DrawKingGuard(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi2_DoNothing1(EnHeishi2* pthis, GlobalContext* globalCtx);
void EnHeishi_DoNothing2(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A531E4(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53278(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A5344C(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A54954(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53538(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A535BC(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A5399C(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53638(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A5372C(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A5475C(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53AD4(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53C0C(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53C90(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53D0C(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A544AC(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53908(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53F30(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A54038(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A5427C(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A549E8(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53850(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A54320(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A543A0(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A5455C(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A546DC(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A541FC(EnHeishi2* pthis, GlobalContext* globalCtx);
void func_80A53DF8(EnHeishi2* pthis, GlobalContext* globalCtx);

ActorInit En_Heishi2_InitVars = {
    ACTOR_EN_HEISHI2, ACTORCAT_NPC, FLAGS, OBJECT_SD, sizeof(EnHeishi2), (ActorFunc)EnHeishi2_Init, (ActorFunc)EnHeishi2_Destroy, (ActorFunc)EnHeishi2_Update, (ActorFunc)EnHeishi2_Draw, (ActorFunc)EnHeishi2_Reset,
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
    {33, 40, 0, {0, 0, 0}},
};

void EnHeishi2_Init(Actor* thisx, GlobalContext* globalCtx)
{
	ColliderCylinder* collider;
	EnHeishi2* pthis = (EnHeishi2*)thisx;

	Actor_SetScale(&pthis->actor, 0.01f);
	pthis->type = pthis->actor.params & 0xFF;
	pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;

	if((pthis->type == 6) || (pthis->type == 9))
	{
		pthis->actor.draw = EnHeishi2_DrawKingGuard;
		pthis->actor.flags &= ~ACTOR_FLAG_VISIBLE;
		Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, 6);
		if(pthis->type == 6)
		{
			pthis->actionFunc = EnHeishi2_DoNothing1;
		}
		else
		{
			osSyncPrintf("\n\n");
			// "No, I'm completely disappointed" (message for when shooting guard window in courtyard)
			osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆☆☆☆ いやー ついうっかり ☆☆☆☆☆ \n" VT_RST);

			Actor_SetScale(&pthis->actor, 0.02f);

			pthis->unk_274 = pthis->actor.world.pos;
			pthis->actor.world.rot.y = 0x7918;
			pthis->actor.world.pos.x += 90.0f;
			pthis->actor.world.pos.y -= 60.0f;
			pthis->actor.world.pos.z += 90.0f;
			pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
			Collider_DestroyCylinder(globalCtx, &pthis->collider);
			func_8002DF54(globalCtx, 0, 8);
			pthis->actor.flags |= ACTOR_FLAG_VISIBLE | ACTOR_FLAG_4;
			pthis->actionFunc = func_80A544AC;
		}
	}
	else
	{
		pthis->unk_2E0 = 60.0f;
		ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
		SkelAnime_Init(globalCtx, &pthis->skelAnime, &gEnHeishiSkel, &gEnHeishiIdleAnim, pthis->jointTable, pthis->morphTable, 17);
		collider = &pthis->collider;
		Collider_InitCylinder(globalCtx, collider);
		Collider_SetCylinder(globalCtx, collider, &pthis->actor, &sCylinderInit);
		pthis->collider.dim.yShift = 0;
		pthis->collider.dim.radius = 15;
		pthis->collider.dim.height = 70;
		pthis->actor.targetMode = 6;

		switch(pthis->type)
		{
			case 2:
				pthis->actionFunc = func_80A531E4;
				pthis->actor.gravity = -1.0f;
				break;
			case 5:
				pthis->actionFunc = func_80A53908;
				pthis->actor.gravity = -1.0f;
				break;
			case 6:
				osSyncPrintf("\n\n");
				// "Peep hole soldier!"
				osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 覗き穴奥兵士ふぃ〜 ☆☆☆☆☆ \n" VT_RST);
				Collider_DestroyCylinder(globalCtx, collider);
				pthis->actor.flags &= ~(ACTOR_FLAG_VISIBLE | ACTOR_FLAG_3);
				pthis->actionFunc = EnHeishi_DoNothing2;
				break;
		}

		pthis->unk_2F0 = (pthis->actor.params >> 8) & 0xFF;
		osSyncPrintf("\n\n");
		// "Soldier Set 2 Completed!"
		osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 兵士２セット完了！ ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params);
		// "Identification Completed!"
		osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ 識別完了！         ☆☆☆☆☆ %d\n" VT_RST, pthis->type);
		// "Message completed!"
		osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆☆☆☆ メッセージ完了！   ☆☆☆☆☆ %x\n\n" VT_RST, (pthis->actor.params >> 8) & 0xF);
	}
}

void EnHeishi2_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	EnHeishi2* pthis = (EnHeishi2*)thisx;

	if((pthis->collider.dim.radius != 0) || (pthis->collider.dim.height != 0))
	{
		Collider_DestroyCylinder(globalCtx, &pthis->collider);
	}
}

void EnHeishi2_DoNothing1(EnHeishi2* pthis, GlobalContext* globalCtx)
{
}

void EnHeishi_DoNothing2(EnHeishi2* pthis, GlobalContext* globalCtx)
{
}

void func_80A531E4(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

	Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
	pthis->actionFunc = func_80A53278;
}

void func_80A53278(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	pthis->unk_30B = 0;
	pthis->unk_30E = 0;
	if(Text_GetFaceReaction(globalCtx, 5) != 0)
	{
		pthis->actor.textId = Text_GetFaceReaction(globalCtx, 5);
		pthis->unk_30B = 1;
		pthis->unk_300 = TEXT_STATE_DONE;
		pthis->actionFunc = func_80A5475C;
	}
	else if((gSaveContext.eventChkInf[0] & 0x200) && (gSaveContext.eventChkInf[2] & 0x20) && (gSaveContext.eventChkInf[3] & 0x80))
	{
		// "Get all spiritual stones!"
		osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 全部の精霊石GET！ ☆☆☆☆☆ \n" VT_RST);
		pthis->unk_300 = TEXT_STATE_DONE;
		pthis->actor.textId = 0x7006;
		pthis->actionFunc = func_80A5475C;
	}
	else if(!IS_DAY)
	{
		// "Sleep early for children!"
		osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ 子供ははやくネロ！ ☆☆☆☆☆ \n" VT_RST);
		pthis->unk_300 = TEXT_STATE_DONE;
		pthis->actor.textId = 0x7002;
		pthis->actionFunc = func_80A5475C;
	}
	else if(pthis->unk_30C != 0)
	{
		// "Anything passes"
		osSyncPrintf(VT_FGCOL(BLUE) " ☆☆☆☆☆ なんでも通るよ ☆☆☆☆☆ \n" VT_RST);
		pthis->unk_300 = TEXT_STATE_DONE;
		pthis->actor.textId = 0x7099;
		pthis->actionFunc = func_80A5475C;
	}
	else if(gSaveContext.eventChkInf[1] & 4)
	{
		if(pthis->unk_30E == 0)
		{
			// "Start under the first sleeve!"
			osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆☆☆☆ １回目袖の下開始！ ☆☆☆☆☆ \n" VT_RST);
			pthis->actor.textId = 0x7071;
			pthis->unk_30E = 1;
		}
		else
		{
			// "Start under the second sleeve!"
			osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆☆☆☆ ２回目袖の下開始！ ☆☆☆☆☆ \n" VT_RST);
			pthis->actor.textId = 0x7072;
		}
		pthis->unk_300 = TEXT_STATE_CHOICE;
		pthis->actionFunc = func_80A5475C;
	}
	else
	{
		// "That's okay"
		osSyncPrintf(VT_FGCOL(CYAN) " ☆☆☆☆☆ それはとおらんよぉ ☆☆☆☆☆ \n" VT_RST);
		pthis->unk_300 = TEXT_STATE_DONE;
		pthis->actor.textId = 0x7029;
		pthis->actionFunc = func_80A5475C;
	}
}

void func_80A5344C(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx))
	{
		pthis->unk_300 = TEXT_STATE_EVENT;
		switch(globalCtx->msgCtx.choiceIndex)
		{
			case 0:
				if(gSaveContext.rupees >= 10)
				{
					Rupees_ChangeBy(-10);
					pthis->actor.textId = 0x7098;
					pthis->actionFunc = func_80A53538;
					break;
				}
				else
				{
					pthis->actor.textId = 0x7097;
					pthis->actionFunc = func_80A54954;
					break;
				}
			case 1:
				pthis->actor.textId = 0x7096;
				pthis->actionFunc = func_80A54954;
				break;

			default:
				break;
		}
		Message_ContinueTextbox(globalCtx, pthis->actor.textId);
	}
}

void func_80A53538(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	if(pthis->unk_300 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx))
	{
		func_8002DF54(globalCtx, NULL, 8);
		globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
		pthis->actionFunc = func_80A535BC;
	}
}

void func_80A535BC(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	f32 frameCount = Animation_GetLastFrame(&gEnHeishiSlamSpearAnim);

	pthis->unk_2EC = frameCount;
	Animation_Change(&pthis->skelAnime, &gEnHeishiSlamSpearAnim, 1.0f, 0.0f, frameCount, ANIMMODE_ONCE, -10.0f);
	pthis->actionFunc = func_80A53638;
}

void func_80A53638(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	f32 frameCount = pthis->skelAnime.curFrame;

	BgSpot15Saku* actor = (BgSpot15Saku*)globalCtx->actorCtx.actorLists[ACTORCAT_ITEMACTION].head;

	SkelAnime_Update(&pthis->skelAnime);
	if((frameCount >= 12.0f) && (!pthis->audioFlag))
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_SPEAR_HIT);
		pthis->audioFlag = 1;
	}
	if(pthis->unk_2EC <= frameCount)
	{
		while(actor != NULL)
		{
			if(actor->dyna.actor.id != ACTOR_BG_SPOT15_SAKU)
			{
				actor = (BgSpot15Saku*)(actor->dyna.actor.next);
			}
			else
			{
				pthis->gate = &actor->dyna.actor;
				actor->unk_168 = 1;
				break;
			}
		}
		// "I've come!"
		osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆ きたきたきたぁ！ ☆☆☆ %x\n" VT_RST, actor->dyna.actor.next);
		pthis->actionFunc = func_80A5372C;
	}
}

void func_80A5372C(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

	Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
	pthis->unk_2F2[0] = 200;
	pthis->cameraId = Gameplay_CreateSubCamera(globalCtx);
	Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
	Gameplay_ChangeCameraStatus(globalCtx, pthis->cameraId, CAM_STAT_ACTIVE);
	pthis->unk_280.x = 947.0f;
	pthis->unk_280.y = 1195.0f;
	pthis->unk_280.z = 2682.0f;

	pthis->unk_28C.x = 1164.0f;
	pthis->unk_28C.y = 1145.0f;
	pthis->unk_28C.z = 3014.0f;

	Gameplay_CameraSetAtEye(globalCtx, pthis->cameraId, &pthis->unk_280, &pthis->unk_28C);
	pthis->actionFunc = func_80A53850;
}

void func_80A53850(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	BgSpot15Saku* gate;

	SkelAnime_Update(&pthis->skelAnime);
	Gameplay_CameraSetAtEye(globalCtx, pthis->cameraId, &pthis->unk_280, &pthis->unk_28C);
	gate = (BgSpot15Saku*)pthis->gate;
	if((pthis->unk_2F2[0] == 0) || (gate->unk_168 == 0))
	{
		Gameplay_ClearCamera(globalCtx, pthis->cameraId);
		Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_ACTIVE);
		Message_CloseTextbox(globalCtx);
		pthis->unk_30C = 1;
		func_8002DF54(globalCtx, NULL, 7);
		pthis->actionFunc = func_80A531E4;
	}
}

void func_80A53908(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

	Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
	pthis->actionFunc = func_80A5399C;
}

void func_80A5399C(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	s16 var;

	pthis->unk_30B = 0;
	var = 0;
	if(gSaveContext.infTable[7] & 0x40)
	{
		if(!(gSaveContext.infTable[7] & 0x80))
		{
			if(Player_GetMask(globalCtx) == PLAYER_MASK_KEATON)
			{
				if(pthis->unk_309 == 0)
				{
					pthis->actor.textId = 0x200A;
				}
				else
				{
					pthis->actor.textId = 0x200B;
				}
				pthis->unk_300 = TEXT_STATE_CHOICE;
				pthis->unk_30B = 1;
				var = 1;
			}
			else
			{
				pthis->actor.textId = 0x2016;
				pthis->unk_300 = TEXT_STATE_DONE;
				var = 1;
			}
		}
		else
		{
			pthis->actor.textId = 0x2020;
			pthis->unk_300 = TEXT_STATE_EVENT;
			pthis->unk_30E = 0;
		}
		if(Text_GetFaceReaction(globalCtx, 5) != 0)
		{
			if(var == 0)
			{
				pthis->actor.textId = Text_GetFaceReaction(globalCtx, 5);
				pthis->unk_30B = 1;
				pthis->unk_300 = TEXT_STATE_DONE;
				pthis->unk_30E = 0;
			}
		}
		pthis->actionFunc = func_80A5475C;
	}
	else
	{
		// "I don't know"
		osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆☆☆☆ とおしゃしねぇちゅーの ☆☆☆☆☆ \n" VT_RST);
		pthis->actionFunc = func_80A53AD4;
	}
}

void func_80A53AD4(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	s32 exchangeItemId;
	s16 yawDiffTemp;
	s16 yawDiff;

	SkelAnime_Update(&pthis->skelAnime);
	if(Text_GetFaceReaction(globalCtx, 5) != 0)
	{
		pthis->actor.textId = Text_GetFaceReaction(globalCtx, 5);
	}
	else
	{
		pthis->actor.textId = 0x200E;
	}
	pthis->unk_300 = TEXT_STATE_DONE;
	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		exchangeItemId = func_8002F368(globalCtx);
		if(exchangeItemId == EXCH_ITEM_LETTER_ZELDA)
		{
			Common_PlaySfx(NA_SE_SY_CORRECT_CHIME);
			player->actor.textId = 0x2010;
			pthis->unk_300 = TEXT_STATE_EVENT;
			pthis->actionFunc = func_80A53C0C;
		}
		else if(exchangeItemId != EXCH_ITEM_NONE)
		{
			player->actor.textId = 0x200F;
		}
	}
	else
	{
		yawDiffTemp = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
		yawDiff = ABS(yawDiffTemp);
		if(!(120.0f < pthis->actor.xzDistToPlayer) && (yawDiff < 0x4300))
		{
			func_8002F298(&pthis->actor, globalCtx, 100.0f, EXCH_ITEM_LETTER_ZELDA);
		}
	}
}

void func_80A53C0C(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	if((pthis->unk_300 == Message_GetState(&globalCtx->msgCtx)) && Message_ShouldAdvance(globalCtx))
	{
		func_8002DF54(globalCtx, 0, 8);
		globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
		pthis->actionFunc = func_80A53C90;
	}
}

void func_80A53C90(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	f32 frameCount = Animation_GetLastFrame(&gEnHeishiSlamSpearAnim);

	pthis->unk_2EC = frameCount;
	Animation_Change(&pthis->skelAnime, &gEnHeishiSlamSpearAnim, 1.0f, 0.0f, frameCount, ANIMMODE_ONCE, -10.0f);
	pthis->actionFunc = func_80A53D0C;
}

void func_80A53D0C(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	f32 frameCount;
	BgGateShutter* gate;

	frameCount = pthis->skelAnime.curFrame;
	gate = (BgGateShutter*)globalCtx->actorCtx.actorLists[ACTORCAT_ITEMACTION].head;
	SkelAnime_Update(&pthis->skelAnime);
	if(12.0f <= frameCount)
	{
		if(pthis->audioFlag == 0)
		{
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_SPEAR_HIT);
			pthis->audioFlag = 1;
		}
	}
	if(pthis->unk_2EC <= frameCount)
	{
		while(gate != NULL)
		{
			if(gate->dyna.actor.id != ACTOR_BG_GATE_SHUTTER)
			{
				gate = (BgGateShutter*)gate->dyna.actor.next;
			}
			else
			{
				pthis->gate = &gate->dyna.actor;
				gate->openingState = 1;
				break;
			}
		}
		// "I've come!"
		osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆ きたきたきたぁ！ ☆☆☆ %x\n" VT_RST, gate->dyna.actor.next);
		pthis->actionFunc = func_80A53DF8;
	}
}

void func_80A53DF8(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

	Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
	pthis->unk_2F2[0] = 200;
	pthis->cameraId = Gameplay_CreateSubCamera(globalCtx);
	Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
	Gameplay_ChangeCameraStatus(globalCtx, pthis->cameraId, CAM_STAT_ACTIVE);
	pthis->unk_2BC.x = -71.0f;
	pthis->unk_280.x = -71.0f;
	pthis->unk_2BC.y = 571.0f;
	pthis->unk_280.y = 571.0f;
	pthis->unk_2BC.z = -1487.0f;
	pthis->unk_280.z = -1487.0f;
	pthis->unk_298.x = 181.0f;
	pthis->unk_28C.x = 181.0f;
	pthis->unk_298.y = 417.0f;
	pthis->unk_28C.y = 417.0f;
	pthis->unk_298.z = -1079.0f;
	pthis->unk_28C.z = -1079.0f;
	Gameplay_CameraSetAtEye(globalCtx, pthis->cameraId, &pthis->unk_280, &pthis->unk_28C);
	pthis->actionFunc = func_80A53F30;
}

void func_80A53F30(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	BgGateShutter* gate;

	SkelAnime_Update(&pthis->skelAnime);
	Gameplay_CameraSetAtEye(globalCtx, pthis->cameraId, &pthis->unk_280, &pthis->unk_28C);
	gate = (BgGateShutter*)pthis->gate;
	if((pthis->unk_2F2[0] == 0) || (gate->openingState == 0))
	{
		Gameplay_ClearCamera(globalCtx, pthis->cameraId);
		Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_ACTIVE);
		if((pthis->unk_30A != 2))
		{
			if(pthis->unk_30A == 0)
			{
				pthis->actor.textId = 0x2015;
				Message_ContinueTextbox(globalCtx, pthis->actor.textId);
				pthis->actionFunc = func_80A54038;
			}
			else
			{
				Message_CloseTextbox(globalCtx);
				func_8002DF54(globalCtx, NULL, 7);
				pthis->actionFunc = func_80A53908;
			}
		}
		else
		{
			pthis->unk_30E = 0;
			pthis->actor.textId = 0x2021;
			Rupees_ChangeBy(15);
			Message_ContinueTextbox(globalCtx, pthis->actor.textId);
			pthis->actionFunc = func_80A5427C;
		}
	}
}

void func_80A54038(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		gSaveContext.infTable[7] |= 0x40;
		Message_CloseTextbox(globalCtx);
		func_8002DF54(globalCtx, 0, 7);
		pthis->actionFunc = func_80A53908;
	}
}

void func_80A540C0(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx))
	{
		switch(globalCtx->msgCtx.choiceIndex)
		{
			case 0:
				pthis->actor.textId = 0x2020;
				Message_ContinueTextbox(globalCtx, pthis->actor.textId);
				Player_UnsetMask(globalCtx);
				gSaveContext.infTable[7] |= 0x80;
				gSaveContext.itemGetInf[3] |= 0x100;
				Item_Give(globalCtx, ITEM_SOLD_OUT);
				if(pthis->unk_30A != 0)
				{
					pthis->unk_30A = 2;
					pthis->unk_30E = 1;
					pthis->actionFunc = func_80A5427C;
				}
				else
				{
					pthis->unk_30E = 0;
					pthis->actionFunc = func_80A541FC;
				}
				break;
			case 1:
				pthis->unk_30E = 1;
				pthis->actor.textId = 0x200C;
				Message_ContinueTextbox(globalCtx, pthis->actor.textId);
				pthis->unk_300 = TEXT_STATE_EVENT;
				if(pthis->unk_30A == 0)
				{
					pthis->actionFunc = func_80A5427C;
				}
				else
				{
					pthis->actionFunc = func_80A54954;
				}
		}
	}
}

void func_80A541FC(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		pthis->actor.textId = 0x2021;
		Rupees_ChangeBy(15);
		Message_ContinueTextbox(globalCtx, pthis->actor.textId);
		pthis->actionFunc = func_80A5427C;
	}
}

void func_80A5427C(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		if(pthis->unk_30E == 0)
		{
			pthis->unk_30E = 0;
			pthis->unk_30A = pthis->unk_30E;
			Message_CloseTextbox(globalCtx);
			pthis->actionFunc = func_80A53908;
		}
		else
		{
			globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
			pthis->actionFunc = func_80A54320;
		}
	}
}

void func_80A54320(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	f32 frameCount = Animation_GetLastFrame(&gEnHeishiSlamSpearAnim);

	pthis->unk_2EC = frameCount;
	Animation_Change(&pthis->skelAnime, &gEnHeishiSlamSpearAnim, 1.0f, 0.0f, frameCount, ANIMMODE_ONCE, -10.0f);
	pthis->audioFlag = 0;
	pthis->actionFunc = func_80A543A0;
}

void func_80A543A0(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	f32 frameCount = pthis->skelAnime.curFrame;
	BgGateShutter* gate = (BgGateShutter*)(globalCtx->actorCtx.actorLists[ACTORCAT_ITEMACTION].head);
	SkelAnime_Update(&pthis->skelAnime);

	if((frameCount >= 12.0f) && (!pthis->audioFlag))
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_SPEAR_HIT);
		pthis->audioFlag = 1;
	}

	if(pthis->unk_2EC <= frameCount)
	{
		while(gate != NULL)
		{
			if(ACTOR_BG_GATE_SHUTTER != gate->dyna.actor.id)
			{
				gate = (BgGateShutter*)(gate->dyna.actor.next);
			}
			else
			{
				pthis->gate = &gate->dyna.actor;
				if(pthis->unk_30A != 2)
				{
					gate->openingState = -1;
					break;
				}
				else
				{
					gate->openingState = 2;
					break;
				}
			}
		}
		if(pthis->unk_30A == 0)
		{
			pthis->unk_30A = 1;
		}
		pthis->actionFunc = func_80A53DF8;
	}
}

void func_80A544AC(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	Math_SmoothStepToS(&pthis->actor.shape.rot.z, -6100, 5, pthis->unk_2E4, 0);
	Math_ApproachF(&pthis->unk_2E4, 3000.0f, 1.0f, 500.0f);
	pthis->actor.world.rot.z = pthis->actor.shape.rot.z;
	if(pthis->actor.shape.rot.z < -6000)
	{
		Message_StartTextbox(globalCtx, 0x708F, NULL);
		pthis->actor.flags |= ACTOR_FLAG_16;
		pthis->actionFunc = func_80A5455C;
		pthis->unk_2E4 = 0.0f;
	}
}

void func_80A5455C(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	Vec3f pos;
	f32 rotY;
	EnBom* bomb;

	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		func_8002DF54(globalCtx, NULL, 7);
		Message_CloseTextbox(globalCtx);

		pos.x = Rand_CenteredFloat(20.0f) + pthis->unk_274.x;
		pos.y = Rand_CenteredFloat(20.0f) + (pthis->unk_274.y - 40.0f);
		pos.z = Rand_CenteredFloat(20.0f) + (pthis->unk_274.z - 20.0f);
		rotY = Rand_CenteredFloat(7000.0f) + pthis->actor.yawTowardsPlayer;
		bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pos.x, pos.y, pos.z, 0, rotY, 0, 0);
		if(bomb != NULL)
		{
			bomb->actor.speedXZ = Rand_CenteredFloat(5.0f) + 10.0f;
			bomb->actor.velocity.y = Rand_CenteredFloat(5.0f) + 10.0f;
		}

		// "This is down!"
		osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ これでダウンだ！ ☆☆☆☆☆ \n" VT_RST);
		pthis->actionFunc = func_80A546DC;
	}
}

void func_80A546DC(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	Math_SmoothStepToS(&pthis->actor.shape.rot.z, 200, 5, pthis->unk_2E4, 0);
	Math_ApproachF(&pthis->unk_2E4, 3000.0f, 1.0f, 500.0f);
	pthis->actor.world.rot.z = pthis->actor.shape.rot.z;
	if(pthis->actor.shape.rot.z > 0)
	{
		Actor_Kill(&pthis->actor);
	}
}

void func_80A5475C(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	s16 yawDiff;

	SkelAnime_Update(&pthis->skelAnime);

	if(Text_GetFaceReaction(globalCtx, 5) != 0)
	{
		if(pthis->unk_30B == 0)
		{
			if(pthis->type == 2)
			{
				pthis->actionFunc = func_80A53278;
				return;
			}
			if(pthis->type == 5)
			{
				pthis->actionFunc = func_80A5399C;
				return;
			}
		}
	}
	else if(pthis->unk_30B != 0)
	{
		if(pthis->type == 2)
		{
			pthis->actionFunc = func_80A53278;
			return;
		}
		if(pthis->type == 5)
		{
			pthis->actionFunc = func_80A5399C;
			return;
		}
	}

	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		if(pthis->type == 2)
		{
			if(pthis->unk_30E == 1)
			{
				pthis->actionFunc = func_80A5344C;
				return;
			}
			else
			{
				pthis->actionFunc = func_80A53278;
				return;
			}
		}
		else if(pthis->type == 5)
		{
			if(pthis->unk_300 == TEXT_STATE_DONE)
			{
				pthis->actionFunc = func_80A5399C;
			}

			if(pthis->unk_300 == TEXT_STATE_EVENT)
			{
				pthis->actionFunc = func_80A54954;
			}

			if(pthis->unk_300 == TEXT_STATE_CHOICE)
			{
				pthis->unk_309 = 1;
				Common_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
				pthis->actionFunc = func_80A540C0;
			}
			return;
		}
	}

	if(((pthis->type != 2) && (pthis->type != 5)) || ((yawDiff = ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)), !(pthis->actor.xzDistToPlayer > 120.0f)) && (yawDiff < 0x4300)))
	{
		func_8002F2F4(&pthis->actor, globalCtx);
	}
}

void func_80A54954(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

	Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
	pthis->actionFunc = func_80A549E8;
}

void func_80A549E8(EnHeishi2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	if(pthis->unk_300 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx))
	{
		Message_CloseTextbox(globalCtx);
		if(pthis->type == 2)
		{
			pthis->actionFunc = func_80A531E4;
		}
		if(pthis->type == 5)
		{
			pthis->actionFunc = func_80A53908;
		}
	}
}

void EnHeishi2_Update(Actor* thisx, GlobalContext* globalCtx)
{
	s32 pad;
	EnHeishi2* pthis = (EnHeishi2*)thisx;
	s32 i;

	Actor_SetFocus(&pthis->actor, pthis->unk_2E0);
	if((pthis->type == 2) || (pthis->type == 5))
	{
		pthis->actor.focus.pos.y = 70.0f;
		Actor_SetFocus(&pthis->actor, 70.0f);
		func_80038290(globalCtx, &pthis->actor, &pthis->unk_260, &pthis->unk_26C, pthis->actor.focus.pos);
	}

	pthis->unk_2FC++;

	for(i = 0; i != 5; i++)
	{
		if(pthis->unk_2F2[i] != 0)
		{
			pthis->unk_2F2[i]--;
		}
	}
	pthis->actionFunc(pthis, globalCtx);
	Actor_MoveForward(&pthis->actor);
	switch(pthis->type)
	{
		case 6:
			break;
		case 9:
			break;
		default:
			Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 30.0f, 0x1D);
			Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
			CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
			break;
	}
}

s32 EnHeishi2_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	EnHeishi2* pthis = (EnHeishi2*)thisx;

	switch(pthis->type)
	{
		case 1:
			break;
		case 7:
			break;
		default:
			if(limbIndex == 9)
			{
				rot->x = rot->x + pthis->unk_26C.y;
			}
			if(limbIndex == 16)
			{
				rot->x = rot->x + pthis->unk_260.y;
				rot->z = rot->z + pthis->unk_260.z;
			}
	}

	return false;
}

void EnHeishi2_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	EnHeishi2* pthis = (EnHeishi2*)thisx;

	if(limbIndex == 16)
	{
		Matrix_Get(&pthis->mtxf_330);
	}
}

void EnHeishi2_DrawKingGuard(Actor* thisx, GlobalContext* globalCtx)
{
	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_heishi2.c", 1772);

	gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_en_heishi2.c", 1774), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPDisplayList(POLY_OPA_DISP++, gHeishiKingGuardDL);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_heishi2.c", 1777);
}

void EnHeishi2_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	EnHeishi2* pthis = (EnHeishi2*)thisx;
	Mtx* mtx;
	s32 linkObjBankIndex;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_heishi2.c", 1792);

	func_80093D18(globalCtx->gfxCtx);

	SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnHeishi2_OverrideLimbDraw, EnHeishi2_PostLimbDraw, pthis);
	if((pthis->type == 5) && (gSaveContext.infTable[7] & 0x80))
	{
		linkObjBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_LINK_CHILD);
		if(linkObjBankIndex >= 0)
		{
			Matrix_Put(&pthis->mtxf_330);
			Matrix_Translate(-570.0f, 0.0f, 0.0f, MTXMODE_APPLY);
			Matrix_RotateZ(DEGTORAD(70.0), MTXMODE_APPLY);
			mtx = (Mtx*)POINTER_SUB(Matrix_NewMtx(globalCtx->gfxCtx, "../z_en_heishi2.c", 1820), 7 * sizeof(float[4][4]));

			gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[linkObjBankIndex].vromStart.get());
			gSPSegment(POLY_OPA_DISP++, 0x0D, mtx);
			gSPDisplayList(POLY_OPA_DISP++, gLinkChildKeatonMaskDL);
			gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->actor.objBankIndex].vromStart.get());
		}
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_heishi2.c", 1834);
}

void EnHeishi2_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	En_Heishi2_InitVars = {
	    ACTOR_EN_HEISHI2, ACTORCAT_NPC, FLAGS, OBJECT_SD, sizeof(EnHeishi2), (ActorFunc)EnHeishi2_Init, (ActorFunc)EnHeishi2_Destroy, (ActorFunc)EnHeishi2_Update, (ActorFunc)EnHeishi2_Draw, (ActorFunc)EnHeishi2_Reset,
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
	    {33, 40, 0, {0, 0, 0}},
	};
}
