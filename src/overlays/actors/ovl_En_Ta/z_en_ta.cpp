#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_TA_Z_EN_TA_C
#include "actor_common.h"
/*
 * File: z_en_ta.c
 * Overlay: ovl_En_Ta
 * Description: Talon
 */

#include "vt.h"
#include "z_en_ta.h"
#include "def/audio.h"
#include "def/audio_command.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "objects/object_ta/object_ta.h"

#define FLAGS (ACTOR_FLAG_VISIBLE | ACTOR_FLAG_3)

void EnTa_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTa_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnTa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTa_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTa_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B14634(EnTa* pthis, GlobalContext* globalCtx);
void func_80B146F8(EnTa* pthis, GlobalContext* globalCtx);
void func_80B14754(EnTa* pthis, GlobalContext* globalCtx);
void func_80B14C18(EnTa* pthis, GlobalContext* globalCtx);
void func_80B14CAC(EnTa* pthis, GlobalContext* globalCtx);
void func_80B14D98(EnTa* pthis, GlobalContext* globalCtx);
void func_80B154FC(EnTa* pthis, GlobalContext* globalCtx);
void func_80B16504(EnTa* pthis, GlobalContext* globalCtx);
void func_80B16608(EnTa* pthis, GlobalContext* globalCtx);
void func_80B166CC(EnTa* pthis);
void func_80B16700(EnTa* pthis);
void func_80B167C0(EnTa* pthis);
void func_80B167FC(EnTa* pthis);
void func_80B16854(EnTa* pthis);
void func_80B16938(EnTa* pthis);

static Vec3f D_80B16E7C_111 = {
    1100.0f,
    1000.0f,
    0.0f,
};

static void* eyeTextures_112[] = {
    gTalonEyeOpenTex,
    gTalonEyeHalfTex,
    gTalonEyeClosedTex,
};

ActorInit En_Ta_InitVars = {
    ACTOR_EN_TA, ACTORCAT_NPC, FLAGS, OBJECT_TA, sizeof(EnTa), (ActorFunc)EnTa_Init, (ActorFunc)EnTa_Destroy, (ActorFunc)EnTa_Update, (ActorFunc)EnTa_Draw, (ActorFunc)EnTa_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
	COLTYPE_NONE,
	AT_NONE,
	AC_ON | AC_TYPE_PLAYER,
	OC1_ON | OC1_TYPE_ALL,
	OC2_TYPE_1,
	COLSHAPE_CYLINDER,
    },
    {
	ELEMTYPE_UNK0,
	{0x00000000, 0x00, 0x00},
	{0x00000004, 0x00, 0x00},
	TOUCH_NONE,
	BUMP_ON,
	OCELEM_ON,
    },
    {30, 40, 0, {0, 0, 0}},
};

void func_80B13AA0(EnTa* pthis, EnTaActionFunc arg1, EnTaUnkFunc arg2)
{
	pthis->actionFunc = arg1;
	pthis->unk_260 = arg2;
}

void func_80B13AAC(EnTa* pthis, GlobalContext* globalCtx)
{
	u16 faceReaction = Text_GetFaceReaction(globalCtx, 24);

	if(gSaveContext.eventInf[0] & 0x400)
	{
		if(gSaveContext.eventInf[0] & 0x100)
		{
			if(gSaveContext.itemGetInf[0] & 4)
			{
				pthis->actor.textId = 0x2088;
			}
			else
			{
				pthis->actor.textId = 0x2086;
			}
		}
		else
		{
			pthis->actor.textId = 0x2085;
		}
		gSaveContext.eventInf[0] &= ~0x100;
	}
	else if(faceReaction == 0)
	{
		if(gSaveContext.infTable[7] & 0x4000)
		{
			if(gSaveContext.itemGetInf[0] & 4)
			{
				pthis->actor.textId = 0x208B;
			}
			else
			{
				pthis->actor.textId = 0x207F;
			}
		}
		else
		{
			pthis->actor.textId = 0x207E;
		}
	}
	else
	{
		pthis->actor.textId = faceReaction;
	}
}

void EnTa_Init(Actor* thisx, GlobalContext* globalCtx2)
{
	EnTa* pthis = (EnTa*)thisx;
	GlobalContext* globalCtx = globalCtx2;

	ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 36.0f);
	SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gTalonSkel, &gTalonStandAnim, pthis->jointTable, pthis->morphTable, 17);
	Collider_InitCylinder(globalCtx, &pthis->collider);
	Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);

	pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
	pthis->unk_2E0 = 0;
	pthis->unk_2CE = 0;
	pthis->unk_2E2 = 0;
	pthis->blinkTimer = 20;
	pthis->unk_2B0 = func_80B166CC;
	Actor_SetScale(&pthis->actor, 0.01f);
	pthis->actor.targetMode = 6;
	pthis->actor.velocity.y = -4.0f;
	pthis->actor.minVelocityY = -4.0f;
	pthis->actor.gravity = -1.0f;

	switch(pthis->actor.params)
	{
		case 1:
			osSyncPrintf(VT_FGCOL(CYAN) " 追放タロン \n" VT_RST);
			if(gSaveContext.eventChkInf[6] & 0x800)
			{
				Actor_Kill(&pthis->actor);
			}
			else if(!LINK_IS_ADULT)
			{
				Actor_Kill(&pthis->actor);
			}
			else if(gSaveContext.eventChkInf[6] & 0x400)
			{
				func_80B13AA0(pthis, func_80B14CAC, func_80B167C0);
				pthis->eyeIndex = 0;
				Animation_PlayOnce(&pthis->skelAnime, &gTalonStandAnim);
				pthis->currentAnimation = &gTalonStandAnim;
			}
			else
			{
				func_80B13AA0(pthis, func_80B14754, func_80B167FC);
				pthis->eyeIndex = 2;
				Animation_PlayOnce(&pthis->skelAnime, &gTalonSleepAnim);
				pthis->currentAnimation = &gTalonSleepAnim;
				pthis->actor.shape.shadowScale = 54.0f;
			}
			break;
		case 2:
			osSyncPrintf(VT_FGCOL(CYAN) " 出戻りタロン \n" VT_RST);
			if(!(gSaveContext.eventChkInf[6] & 0x800))
			{
				Actor_Kill(&pthis->actor);
			}
			else if(!LINK_IS_ADULT)
			{
				Actor_Kill(&pthis->actor);
			}
			else if(globalCtx->sceneNum == SCENE_MALON_STABLE && gSaveContext.nightFlag)
			{
				Actor_Kill(&pthis->actor);
				osSyncPrintf(VT_FGCOL(CYAN) " 夜はいない \n" VT_RST);
			}
			else
			{
				func_80B13AA0(pthis, func_80B14D98, func_80B167C0);
				pthis->eyeIndex = 0;
				Animation_PlayOnce(&pthis->skelAnime, &gTalonStandAnim);
				pthis->currentAnimation = &gTalonStandAnim;
			}
			break;
		default:
			osSyncPrintf(VT_FGCOL(CYAN) " その他のタロン \n" VT_RST);
			if(globalCtx->sceneNum == SCENE_SPOT15)
			{
				if(gSaveContext.eventChkInf[1] & 0x10)
				{
					Actor_Kill(&pthis->actor);
				}
				else if(gSaveContext.eventChkInf[1] & 0x8)
				{
					func_80B13AA0(pthis, func_80B14C18, func_80B167C0);
					pthis->eyeIndex = 0;
					Animation_PlayOnce(&pthis->skelAnime, &gTalonStandAnim);
					pthis->currentAnimation = &gTalonStandAnim;
				}
				else
				{
					func_80B13AA0(pthis, func_80B14634, func_80B167FC);
					pthis->eyeIndex = 2;
					Animation_PlayOnce(&pthis->skelAnime, &gTalonSleepAnim);
					pthis->currentAnimation = &gTalonSleepAnim;
					pthis->actor.shape.shadowScale = 54.0f;
				}
			}
			else if(globalCtx->sceneNum == SCENE_SOUKO)
			{
				osSyncPrintf(VT_FGCOL(CYAN) " ロンロン牧場の倉庫 の タロン\n" VT_RST);
				if(!(gSaveContext.eventChkInf[1] & 0x10))
				{
					Actor_Kill(&pthis->actor);
				}
				else if(LINK_IS_ADULT)
				{
					Actor_Kill(&pthis->actor);
				}
				else
				{
					if(IS_DAY)
					{
						pthis->actor.flags |= ACTOR_FLAG_4;
						pthis->unk_2C4[0] = pthis->unk_2C4[1] = pthis->unk_2C4[2] = 7;
						pthis->superCuccos[0] = (EnNiw*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_NIW, pthis->actor.world.pos.x + 5.0f, pthis->actor.world.pos.y + 3.0f, pthis->actor.world.pos.z + 26.0f, 0, 0, 0, 0xD);
						pthis->superCuccos[1] = (EnNiw*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_NIW, pthis->actor.world.pos.x - 20.0f, pthis->actor.world.pos.y + 40.0f, pthis->actor.world.pos.z - 30.0f, 0, 0, 0, 0xD);
						pthis->superCuccos[2] = (EnNiw*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_NIW, pthis->actor.world.pos.x + 20.0f, pthis->actor.world.pos.y + 40.0f, pthis->actor.world.pos.z - 30.0f, 0, 0, 0, 0xD);
						func_80B13AAC(pthis, globalCtx);

						if(gSaveContext.eventInf[0] & 0x400)
						{
							func_80B13AA0(pthis, func_80B16608, func_80B16938);
							Animation_Change(&pthis->skelAnime, &gTalonSitWakeUpAnim, 1.0f, Animation_GetLastFrame(&gTalonSitWakeUpAnim) - 1.0f, Animation_GetLastFrame(&gTalonSitWakeUpAnim), ANIMMODE_ONCE, 0.0f);
							gSaveContext.eventInf[0] &= ~0x400;
						}
						else
						{
							func_80B13AA0(pthis, func_80B16504, func_80B16854);
							pthis->eyeIndex = 0;
							Animation_PlayOnce(&pthis->skelAnime, &gTalonSitSleepingAnim);
							pthis->currentAnimation = &gTalonSitSleepingAnim;
						}
					}
					else
					{
						func_80B13AA0(pthis, func_80B146F8, func_80B167FC);
						pthis->eyeIndex = 2;
						Animation_PlayOnce(&pthis->skelAnime, &gTalonSleepAnim);
						pthis->currentAnimation = &gTalonSleepAnim;
						pthis->actor.shape.shadowScale = 54.0f;
					}
				}
			}
			else
			{
				func_80B13AA0(pthis, func_80B14634, func_80B167FC);
				pthis->eyeIndex = 2;
				Animation_PlayOnce(&pthis->skelAnime, &gTalonSleepAnim);
				pthis->currentAnimation = &gTalonSleepAnim;
				pthis->actor.shape.shadowScale = 54.0f;
			}
			break;
	}
}

void func_80B14248(EnTa* pthis)
{
	if(pthis->actor.shape.shadowScale > 36.0f)
	{
		pthis->actor.shape.shadowScale -= 0.8f;
	}
}

void EnTa_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	EnTa* pthis = (EnTa*)thisx;

	Collider_DestroyCylinder(globalCtx, &pthis->collider);

	if(pthis->actor.params != 1 && pthis->actor.params != 2 && globalCtx->sceneNum == SCENE_SOUKO)
	{
		gSaveContext.timer1State = 0;
	}

	if(pthis->unk_2E0 & 0x200)
	{
		func_800F5B58();
	}
}

s32 func_80B142F4(EnTa* pthis, GlobalContext* globalCtx, u16 textId)
{
	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		return true;
	}

	pthis->actor.textId = textId;

	if((ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) <= 0x4300) && (pthis->actor.xzDistToPlayer < 100.0f))
	{
		pthis->unk_2E0 |= 1;
		func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
	}
	return false;
}

void func_80B14398(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		func_80B13AA0(pthis, func_80B14754, func_80B167FC);
	}
}

void func_80B143D4(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		func_80B13AA0(pthis, func_80B146F8, func_80B167FC);
	}
}

void func_80B14410(EnTa* pthis)
{
	if(!LINK_IS_ADULT)
	{
		func_80B13AA0(pthis, func_80B14C18, func_80B167C0);
		gSaveContext.eventChkInf[1] |= 0x8;
	}
	else
	{
		func_80B13AA0(pthis, func_80B14CAC, func_80B167C0);
		gSaveContext.eventChkInf[6] |= 0x400;
	}
}

void func_80B1448C(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		func_80B14410(pthis);
	}
	func_80B14248(pthis);
	pthis->unk_2E0 |= 0x4;
}

void func_80B144D8(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		func_80B14410(pthis);
		pthis->blinkTimer = 1;
		pthis->unk_2B0 = func_80B16700;
	}

	if(Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE)
	{
		pthis->eyeIndex = 1;
		func_80B13AA0(pthis, func_80B1448C, func_80B167C0);
	}
	func_80B14248(pthis);
	pthis->unk_2E0 |= 4;
}

void func_80B14570(EnTa* pthis, GlobalContext* globalCtx)
{
	pthis->unk_2E0 |= 4;

	if(pthis->unk_2CC == 0)
	{
		func_80B13AA0(pthis, func_80B144D8, func_80B167C0);
		pthis->unk_2CE = 3;
		pthis->unk_2CC = 60;
		Animation_PlayOnce(&pthis->skelAnime, &gTalonWakeUpAnim);
		pthis->currentAnimation = &gTalonStandAnim;
		Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_TA_SURPRISE);
	}
}

void func_80B145F8(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		func_80B13AA0(pthis, func_80B14634, func_80B167FC);
	}
}

void func_80B14634(EnTa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		s32 exchangeItemId = func_8002F368(globalCtx);

		switch(exchangeItemId)
		{
			case EXCH_ITEM_CHICKEN:
				player->actor.textId = 0x702B;
				func_80B13AA0(pthis, func_80B14570, func_80B167C0);
				pthis->unk_2CC = 40;
				break;
			default:
				if(exchangeItemId != EXCH_ITEM_NONE)
				{
					player->actor.textId = 0x702A;
				}
				func_80B13AA0(pthis, func_80B145F8, func_80B167FC);
				break;
		}
	}
	else
	{
		pthis->actor.textId = 0x702A;
		func_8002F298(&pthis->actor, globalCtx, 100.0f, 3);
	}
}

void func_80B146F8(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		func_80B13AA0(pthis, func_80B143D4, func_80B167FC);
	}
	pthis->actor.textId = 0x204B;
	func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
}

void func_80B14754(EnTa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		s32 exchangeItemId = func_8002F368(globalCtx);

		switch(exchangeItemId)
		{
			case EXCH_ITEM_POCKET_CUCCO:
				player->actor.textId = 0x702B;
				func_80B13AA0(pthis, func_80B14570, func_80B167C0);
				pthis->unk_2CC = 40;
				break;
			default:
				if(exchangeItemId != EXCH_ITEM_NONE)
				{
					player->actor.textId = 0x5015;
				}
				func_80B13AA0(pthis, func_80B14398, func_80B167FC);
				break;
		}
	}
	else
	{
		pthis->actor.textId = 0x5015;
		func_8002F298(&pthis->actor, globalCtx, 100.0f, 6);
	}
}

void func_80B14818(EnTa* pthis, GlobalContext* globalCtx)
{
	s32 framesMod12 = globalCtx->frames % 12;

	if(framesMod12 == 0 || framesMod12 == 6)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_PL_WALK_GROUND);
	}
	if(pthis->actor.speedXZ < 6.0f)
	{
		pthis->actor.speedXZ += 0.4f;
	}
	Actor_MoveForward(&pthis->actor);
}

void func_80B14898(EnTa* pthis, GlobalContext* globalCtx)
{
	func_80033480(globalCtx, &pthis->actor.world.pos, 50.0f, 2, 250, 20, 1);
	func_80B14818(pthis, globalCtx);

	if(pthis->unk_2CC == 0)
	{
		Actor_Kill(&pthis->actor);
	}
}

void func_80B1490C(EnTa* pthis, GlobalContext* globalCtx)
{
	pthis->actor.world.rot.y += 0xC00;
	pthis->actor.shape.rot.y += 0xC00;

	if(pthis->unk_2CC == 0)
	{
		func_80B13AA0(pthis, func_80B14898, func_80B167C0);
		pthis->unk_2CC = 60;
	}
}

void func_80B1496C(EnTa* pthis, GlobalContext* globalCtx)
{
	func_80033480(globalCtx, &pthis->actor.world.pos, 50.0f, 2, 250, 20, 1);
	func_80B14818(pthis, globalCtx);

	if(pthis->unk_2CC == 0)
	{
		func_80B13AA0(pthis, func_80B1490C, func_80B167C0);
		pthis->unk_2CC = 5;
	}
}

void func_80B149F4(EnTa* pthis, GlobalContext* globalCtx)
{
	pthis->actor.world.rot.y -= 0xD00;
	pthis->actor.shape.rot.y -= 0xD00;

	if(pthis->unk_2CC == 0)
	{
		func_80B13AA0(pthis, func_80B1496C, func_80B167C0);
		pthis->unk_2CC = 65;
	}
}

void func_80B14A54(EnTa* pthis, GlobalContext* globalCtx)
{
	func_80033480(globalCtx, &pthis->actor.world.pos, 50.0f, 2, 250, 20, 1);
	func_80B14818(pthis, globalCtx);

	if(pthis->unk_2CC == 20)
	{
		Message_CloseTextbox(globalCtx);
	}
	if(pthis->unk_2CC == 0)
	{
		pthis->unk_2CC = 5;
		func_80B13AA0(pthis, func_80B149F4, func_80B167C0);
	}
}

void func_80B14AF4(EnTa* pthis, GlobalContext* globalCtx)
{
	pthis->actor.world.rot.y -= 0xC00;
	pthis->actor.shape.rot.y -= 0xC00;

	if(pthis->unk_2CC == 0)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_TA_CRY_1);
		func_80B13AA0(pthis, func_80B14A54, func_80B167C0);
		pthis->unk_2CC = 65;
		pthis->actor.flags |= ACTOR_FLAG_4;
	}
}

void func_80B14B6C(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT)
	{
		OnePointCutscene_Init(globalCtx, 4175, -99, &pthis->actor, MAIN_CAM);
		func_80B13AA0(pthis, func_80B14AF4, func_80B167C0);
		pthis->unk_2CC = 5;
		gSaveContext.eventChkInf[1] |= 0x10;
		Animation_PlayOnce(&pthis->skelAnime, &gTalonRunTransitionAnim);
		pthis->currentAnimation = &gTalonRunAnim;
	}
	pthis->unk_2E0 |= 1;
}

void func_80B14C18(EnTa* pthis, GlobalContext* globalCtx)
{
	if(func_80B142F4(pthis, globalCtx, 0x702C))
	{
		func_80B13AA0(pthis, func_80B14B6C, func_80B167C0);
	}
	func_80B14248(pthis);
}

void func_80B14C60(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		func_80B13AA0(pthis, func_80B14CAC, func_80B167C0);
	}
	pthis->unk_2E0 |= 1;
}

void func_80B14CAC(EnTa* pthis, GlobalContext* globalCtx)
{
	if(gSaveContext.eventChkInf[1] & 0x100)
	{
		if(func_80B142F4(pthis, globalCtx, 0x5017))
		{
			func_80B13AA0(pthis, func_80B14C60, func_80B167C0);
			gSaveContext.eventChkInf[6] |= 0x800;
		}
	}
	else if(func_80B142F4(pthis, globalCtx, 0x5016))
	{
		func_80B13AA0(pthis, func_80B14C60, func_80B167C0);
	}
	func_80B14248(pthis);
}

void func_80B14D4C(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		func_80B13AA0(pthis, func_80B14D98, func_80B167C0);
	}
	pthis->unk_2E0 |= 1;
}

void func_80B14D98(EnTa* pthis, GlobalContext* globalCtx)
{
	if(func_80B142F4(pthis, globalCtx, 0x2055))
	{
		func_80B13AA0(pthis, func_80B14D4C, func_80B167C0);
	}
}

s32 func_80B14DD8(void)
{
	if(gSaveContext.rupees < 30)
	{
		return 0;
	}
	else if(!Inventory_HasEmptyBottle())
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

void func_80B14E28(EnTa* pthis, GlobalContext* globalCtx)
{
	Vec3f b;
	Vec3f a;

	pthis->unk_2D0 = Gameplay_CreateSubCamera(globalCtx);
	pthis->unk_2D2 = globalCtx->activeCamera;
	Gameplay_ChangeCameraStatus(globalCtx, pthis->unk_2D2, CAM_STAT_WAIT);
	Gameplay_ChangeCameraStatus(globalCtx, pthis->unk_2D0, CAM_STAT_ACTIVE);

	b.x = 1053.0f;
	b.y = 11.0f;
	b.z = 22.0f;

	a.x = 1053.0f;
	a.y = 45.0f;
	a.z = -40.0f;

	Gameplay_CameraSetAtEye(globalCtx, pthis->unk_2D0, &a, &b);
}

void func_80B14EDC(EnTa* pthis, GlobalContext* globalCtx)
{
	Gameplay_ChangeCameraStatus(globalCtx, pthis->unk_2D2, CAM_STAT_ACTIVE);
	Gameplay_ClearCamera(globalCtx, pthis->unk_2D0);
}

void func_80B14F20(EnTa* pthis, EnTaActionFunc arg1)
{
	func_80B13AA0(pthis, arg1, func_80B16854);
	pthis->eyeIndex = 2;
	Animation_Change(&pthis->skelAnime, &gTalonSitSleepingAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gTalonSitSleepingAnim), ANIMMODE_ONCE, -5.0f);
	pthis->unk_2E2 = 0;
	pthis->currentAnimation = &gTalonSitSleepingAnim;
}

void func_80B14FAC(EnTa* pthis, EnTaActionFunc arg1)
{
	pthis->eyeIndex = 1;
	func_80B13AA0(pthis, arg1, func_80B16938);
	pthis->unk_2E0 &= ~0x10;
	Animation_Change(&pthis->skelAnime, &gTalonSitWakeUpAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gTalonSitWakeUpAnim), ANIMMODE_ONCE, -5.0f);
}

void func_80B15034(EnTa* pthis, GlobalContext* globalCtx)
{
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		Message_CloseTextbox(globalCtx);
		func_80B14F20(pthis, func_80B16504);
		func_80B13AAC(pthis, globalCtx);
	}
	pthis->unk_2E0 |= 1;
}

s32 func_80B150AC(EnTa* pthis, GlobalContext* globalCtx, s32 idx)
{
	Player* player = GET_PLAYER(globalCtx);
	Actor* interactRangeActor;

	if(player->stateFlags1 & PLAYER_STATE1_11)
	{
		interactRangeActor = player->interactRangeActor;
		if(interactRangeActor != NULL && interactRangeActor->id == ACTOR_EN_NIW && interactRangeActor == &pthis->superCuccos[idx]->actor)
		{
			return true;
		}
	}
	return false;
}

void func_80B15100(EnTa* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		s32 unk_2CA;

		Animation_Change(&pthis->skelAnime, &gTalonSitWakeUpAnim, 1.0f, Animation_GetLastFrame(&gTalonSitWakeUpAnim) - 1.0f, Animation_GetLastFrame(&gTalonSitWakeUpAnim), ANIMMODE_ONCE, 10.0f);
		pthis->unk_2E0 &= ~0x10;
		Message_CloseTextbox(globalCtx);
		unk_2CA = pthis->unk_2CA;
		pthis->actionFunc = func_80B154FC;
		pthis->superCuccos[unk_2CA]->actor.gravity = 0.1f;
		pthis->superCuccos[unk_2CA]->actor.velocity.y = 0.0f;
		pthis->superCuccos[unk_2CA]->actor.speedXZ = 0.0f;
		pthis->superCuccos[unk_2CA]->actor.parent = NULL;

		if(player->interactRangeActor == &pthis->superCuccos[unk_2CA]->actor)
		{
			player->interactRangeActor = NULL;
		}
		if(player->heldActor == &pthis->superCuccos[unk_2CA]->actor)
		{
			player->heldActor = NULL;
		}
		player->stateFlags1 &= ~PLAYER_STATE1_11;
		pthis->superCuccos[unk_2CA] = NULL;
	}
	pthis->unk_2E0 |= 1;
}

void func_80B15260(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		pthis->actionFunc = func_80B15100;
		pthis->actor.flags &= ~ACTOR_FLAG_16;
	}
	else
	{
		func_8002F2CC(&pthis->actor, globalCtx, 1000.0f);
	}
	pthis->unk_2E0 |= 1;
}

s32 EnTa_GetSuperCuccosCount(EnTa* pthis, GlobalContext* globalCtx)
{
	s32 count;
	s32 i;

	for(count = 0, i = 0; i < ARRAY_COUNT(pthis->superCuccos); i++)
	{
		if(pthis->superCuccos[i] != NULL)
		{
			count++;
		}
	}
	return count;
}

void func_80B15308(EnTa* pthis)
{
	if(pthis->unk_2E0 & 0x10)
	{
		if(pthis->unk_2E0 & 0x100)
		{
			Animation_Change(&pthis->skelAnime, &gTalonSitHandsUpAnim, 1.0f, 17.0f, 22.0f, ANIMMODE_ONCE, 0.0f);
			pthis->unk_2E0 &= ~0x100;
		}
		else
		{
			Animation_Change(&pthis->skelAnime, &gTalonSitHandsUpAnim, -1.0f, 21.0f, 16.0f, ANIMMODE_ONCE, 3.0f);
			pthis->unk_2E0 |= 0x100;
		}
		pthis->unk_2E0 &= ~0x10;
	}
}

void func_80B153D4(EnTa* pthis, GlobalContext* globalCtx)
{
	func_80B15308(pthis);

	if(pthis->unk_2CC == 0)
	{
		if(pthis->unk_2E0 & 0x80)
		{
			pthis->unk_2E0 &= ~0x80;
			func_80B14EDC(pthis, globalCtx);
		}
	}
}

void func_80B15424(EnTa* pthis, GlobalContext* globalCtx)
{
	func_80B15308(pthis);

	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		globalCtx->nextEntranceIndex = 0x5E4;

		if(gSaveContext.eventInf[0] & 0x100)
		{
			globalCtx->fadeTransition = 46;
			gSaveContext.nextTransition = 3;
		}
		else
		{
			globalCtx->fadeTransition = 38;
			gSaveContext.nextTransition = 2;
		}

		globalCtx->sceneLoadFlag = 0x14;
		gSaveContext.eventInf[0] |= 0x400;
		pthis->actionFunc = func_80B153D4;
		pthis->unk_2CC = 22;
	}
}

void func_80B154FC(EnTa* pthis, GlobalContext* globalCtx)
{
	s32 i;

	for(i = 0; i < ARRAY_COUNT(pthis->superCuccos); i++)
	{
		if(pthis->superCuccos[i] != NULL)
		{
			if(pthis->superCuccos[i]->actor.gravity > -2.0f)
			{
				pthis->superCuccos[i]->actor.gravity -= 0.03f;
			}

			if(func_80B150AC(pthis, globalCtx, i))
			{
				if(pthis->unk_2C4[i] > 0)
				{
					pthis->unk_2C4[i]--;
				}
				else
				{
					pthis->unk_2CA = i;
					Animation_Change(&pthis->skelAnime, &gTalonSitHandsUpAnim, 1.0f, 8.0f, 29.0f, ANIMMODE_ONCE, -10.0f);
					pthis->unk_2E0 &= ~0x10;

					switch(EnTa_GetSuperCuccosCount(pthis, globalCtx))
					{
						case 1:
							gSaveContext.timer1State = 0;
							func_8002DF54(globalCtx, &pthis->actor, 1);

							Message_StartTextbox(globalCtx, 0x2084, &pthis->actor);
							pthis->actionFunc = func_80B15424;
							Animation_Change(&pthis->skelAnime, &gTalonSitHandsUpAnim, 1.0f, 8.0f, 29.0f, ANIMMODE_ONCE, -10.0f);
							pthis->unk_2E0 &= ~0x10;
							pthis->unk_2E0 &= ~0x100;
							gSaveContext.eventInf[0] |= 0x100;
							Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_STOP);
							pthis->unk_2E0 &= ~0x200;
							Audio_PlayFanfare(NA_BGM_SMALL_ITEM_GET);
							return;
						case 2:
							pthis->actor.textId = 0x2083;
							Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_TA_CRY_1);
							break;
						case 3:
							pthis->actor.textId = 0x2082;
							Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_TA_SURPRISE);
							break;
					}
					pthis->actionFunc = func_80B15260;
					pthis->actor.flags |= ACTOR_FLAG_16;
					func_8002F2CC(&pthis->actor, globalCtx, 1000.0f);
					return;
				}
			}
			else
			{
				pthis->unk_2C4[i] = 7;
			}
		}
	}

	if(gSaveContext.timer1Value == 10)
	{
		Audio_UpdateTempo();
	}

	if(gSaveContext.timer1Value == 0 && !Gameplay_InCsMode(globalCtx))
	{
		Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_STOP);
		pthis->unk_2E0 &= ~0x200;
		Common_PlaySfx(NA_SE_SY_FOUND);
		gSaveContext.timer1State = 0;
		func_8002DF54(globalCtx, &pthis->actor, 1);
		Message_StartTextbox(globalCtx, 0x2081, &pthis->actor);
		pthis->actionFunc = func_80B15424;
		func_80B14E28(pthis, globalCtx);
		gSaveContext.eventInf[0] &= ~0x100;
		pthis->unk_2E0 |= 0x80;
		Animation_Change(&pthis->skelAnime, &gTalonSitHandsUpAnim, 1.0f, 8.0f, 29.0f, ANIMMODE_ONCE, -10.0f);
		pthis->unk_2E0 &= ~0x10;
		pthis->unk_2E0 &= ~0x100;
	}

	pthis->unk_2E0 |= 1;
}

void func_80B1585C(EnTa* pthis, GlobalContext* globalCtx)
{
	s32 i;

	if(pthis->unk_2CC > 35)
	{
		for(i = 1; i < ARRAY_COUNT(pthis->superCuccos); i++)
		{
			if(pthis->superCuccos[i] != NULL)
			{
				Math_SmoothStepToS(&pthis->superCuccos[i]->actor.world.rot.y, i * -10000 - 3000, 2, 0x800, 0x100);
				pthis->superCuccos[i]->actor.shape.rot.y = pthis->superCuccos[i]->actor.world.rot.y;
			}
		}
	}
	else if(pthis->unk_2CC == 35)
	{
		for(i = 0; i < ARRAY_COUNT(pthis->superCuccos); i++)
		{
			pthis->unk_2C4[i] = (s32)(Rand_CenteredFloat(6.0f) + 10.0f);

			if(pthis->superCuccos[i] != NULL)
			{
				EnNiw* niw = pthis->superCuccos[i];

				niw->unk_308 = 1;
				niw->actor.gravity = 0.0f;
			}
		}
	}
	else
	{
		for(i = 0; i < ARRAY_COUNT(pthis->superCuccos); i++)
		{
			if(pthis->unk_2CC < 35 - pthis->unk_2C4[i])
			{
				if(pthis->superCuccos[i] != NULL)
				{
					if(pthis->superCuccos[i]->actor.gravity > -2.0f)
					{
						pthis->superCuccos[i]->actor.gravity -= 0.03f;
					}
				}
			}
		}
	}

	if(pthis->unk_2CC == 0)
	{
		func_80B13AA0(pthis, func_80B154FC, func_80B16938);
		pthis->unk_2E0 &= ~0x10;
		Animation_Change(&pthis->skelAnime, &gTalonSitWakeUpAnim, 1.0f, Animation_GetLastFrame(&gTalonSitWakeUpAnim) - 1.0f, Animation_GetLastFrame(&gTalonSitWakeUpAnim), ANIMMODE_ONCE, 10.0f);
		func_8002DF54(globalCtx, &pthis->actor, 7);
	}
}

void func_80B15AD4(EnTa* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_2CC == 0 && pthis->unk_2E0 & 0x20)
	{
		func_80B13AA0(pthis, func_80B1585C, func_80B16938);
		pthis->unk_2E0 &= ~0x10;
		Animation_Change(&pthis->skelAnime, &gTalonSitHandsUpAnim, 1.0f, 1.0f, Animation_GetLastFrame(&gTalonSitHandsUpAnim), ANIMMODE_ONCE, 0.0f);
		pthis->unk_2CC = 50;
		func_80088B34(0x1E);
		func_800F5ACC(NA_BGM_MINI_GAME_2);
		pthis->unk_2E0 |= 0x200;
		Message_CloseTextbox(globalCtx);
		func_8002DF54(globalCtx, &pthis->actor, 1);
	}

	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		pthis->unk_2E0 |= 0x20;
	}

	pthis->unk_2E0 |= 1;
}

void func_80B15BF8(EnTa* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_2E0 & 0x10)
	{
		func_80B13AA0(pthis, func_80B15AD4, func_80B16938);
		pthis->unk_2E0 &= ~0x10;
		Animation_Change(&pthis->skelAnime, &gTalonSitHandsUpAnim, 1.0f, 0.0f, 1.0f, ANIMMODE_ONCE, 0.0f);
		pthis->unk_2CC = 5;
	}
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		pthis->unk_2E0 |= 0x20;
	}
	pthis->unk_2E0 |= 1;
}

void func_80B15CC8(EnTa* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_2E0 & 0x10)
	{
		func_80B13AA0(pthis, func_80B15BF8, func_80B16938);
		pthis->unk_2E0 &= ~0x10;
		Animation_Change(&pthis->skelAnime, &gTalonSitHandsUpAnim, -1.0f, 29.0f, 0.0f, ANIMMODE_ONCE, 10.0f);
	}
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		pthis->unk_2E0 |= 0x20;
	}
	pthis->unk_2E0 |= 1;
}

void func_80B15D90(EnTa* pthis, GlobalContext* globalCtx)
{
	func_80B13AA0(pthis, func_80B15CC8, func_80B16938);
	pthis->unk_2E0 &= ~0x10;
	Animation_Change(&pthis->skelAnime, &gTalonSitHandsUpAnim, 1.0f, 8.0f, 29.0f, ANIMMODE_ONCE, -10.0f);
	Message_ContinueTextbox(globalCtx, 0x2080);
	pthis->unk_2E0 &= ~0x20;
}

void func_80B15E28(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_TextboxIsClosing(&pthis->actor, globalCtx))
	{
		func_80B14F20(pthis, func_80B16504);
		func_80B13AAC(pthis, globalCtx);
	}
	pthis->unk_2E0 |= 1;
}

void func_80B15E80(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_HasParent(&pthis->actor, globalCtx))
	{
		pthis->actor.parent = NULL;
		pthis->actionFunc = func_80B15E28;
		if(!(pthis->unk_2E0 & 0x2))
		{
			gSaveContext.itemGetInf[0] |= 4;
		}
		pthis->unk_2E0 &= ~0x2;
	}
	else if(pthis->unk_2E0 & 2)
	{
		func_8002F434(&pthis->actor, globalCtx, GI_MILK, 10000.0f, 50.0f);
	}
	else
	{
		func_8002F434(&pthis->actor, globalCtx, GI_MILK_BOTTLE, 10000.0f, 50.0f);
	}
	pthis->unk_2E0 |= 1;
}

void func_80B15F54(EnTa* pthis, GlobalContext* globalCtx)
{
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		Message_CloseTextbox(globalCtx);
		pthis->unk_2E0 &= ~0x2;
		func_80B13AA0(pthis, func_80B15E80, func_80B16938);
		func_8002F434(&pthis->actor, globalCtx, GI_MILK_BOTTLE, 10000.0f, 50.0f);
	}
}

void func_80B15FE8(EnTa* pthis, GlobalContext* globalCtx)
{
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx))
	{
		switch(globalCtx->msgCtx.choiceIndex)
		{
			case 0:
				switch(func_80B14DD8())
				{
					case 0:
						Message_ContinueTextbox(globalCtx, 0x85);
						func_80B13AA0(pthis, func_80B15034, func_80B16938);
						break;
					case 1:
						Message_ContinueTextbox(globalCtx, 0x208A);
						func_80B13AA0(pthis, func_80B15E28, func_80B16938);
						break;
					case 2:
						pthis->unk_2E0 |= 2;
						func_80B13AA0(pthis, func_80B15E80, func_80B16938);
						Rupees_ChangeBy(-30);
						func_8002F434(&pthis->actor, globalCtx, GI_MILK, 10000.0f, 50.0f);
						break;
				}
				break;
			case 1:
				if(gSaveContext.rupees < 10)
				{
					Message_ContinueTextbox(globalCtx, 0x85);
					func_80B13AA0(pthis, func_80B15034, func_80B16938);
				}
				else
				{
					Rupees_ChangeBy(-10);
					func_80B15D90(pthis, globalCtx);
				}
				break;
			case 2:
				func_80B14F20(pthis, func_80B16504);
				func_80B13AAC(pthis, globalCtx);
				break;
		}
	}

	if(pthis->unk_2E0 & 0x10)
	{
		pthis->unk_2E0 |= 1;
	}
}

void func_80B161C0(EnTa* pthis, GlobalContext* globalCtx)
{
	s32 price;

	if(pthis->actor.textId == 0x2085)
	{
		price = 5;
	}
	else
	{
		price = 10;
	}

	if(Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx))
	{
		switch(globalCtx->msgCtx.choiceIndex)
		{
			case 0:
				if(gSaveContext.rupees < price)
				{
					Message_ContinueTextbox(globalCtx, 0x85);
					func_80B13AA0(pthis, func_80B15034, func_80B16938);
				}
				else
				{
					Rupees_ChangeBy(-price);
					func_80B15D90(pthis, globalCtx);
				}
				break;
			case 1:
				func_80B14F20(pthis, func_80B16504);
				func_80B13AAC(pthis, globalCtx);
				break;
		}
	}

	if(pthis->unk_2E0 & 0x10)
	{
		pthis->unk_2E0 |= 1;
	}
}

void func_80B162E8(EnTa* pthis, GlobalContext* globalCtx)
{
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx))
	{
		Message_ContinueTextbox(globalCtx, 0x2087);
		func_80B13AA0(pthis, func_80B15F54, func_80B16938);
	}

	if(pthis->unk_2E0 & 0x10)
	{
		pthis->unk_2E0 |= 1;
	}
}

void func_80B16364(EnTa* pthis, GlobalContext* globalCtx)
{
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		gSaveContext.infTable[7] |= 0x4000;
		if(gSaveContext.itemGetInf[0] & 4)
		{
			Message_ContinueTextbox(globalCtx, 0x208B);
			func_80B13AA0(pthis, func_80B15FE8, func_80B16938);
		}
		else
		{
			Message_ContinueTextbox(globalCtx, 0x207F);
			func_80B13AA0(pthis, func_80B161C0, func_80B16938);
		}
	}

	if(pthis->unk_2E0 & 0x10)
	{
		pthis->unk_2E0 |= 1;
	}
}

void func_80B1642C(EnTa* pthis, GlobalContext* globalCtx)
{
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx))
	{
		if(Inventory_HasEmptyBottle())
		{
			Message_CloseTextbox(globalCtx);
			pthis->unk_2E0 |= 2;
			func_80B13AA0(pthis, func_80B15E80, func_80B16938);
			func_8002F434(&pthis->actor, globalCtx, GI_MILK, 10000.0f, 50.0f);
		}
		else
		{
			Message_ContinueTextbox(globalCtx, 0x208A);
			func_80B13AA0(pthis, func_80B15E28, func_80B16938);
		}
	}
}

void func_80B16504(EnTa* pthis, GlobalContext* globalCtx)
{
	u16 faceReaction = Text_GetFaceReaction(globalCtx, 0x18);

	func_80B13AAC(pthis, globalCtx);

	if(func_80B142F4(pthis, globalCtx, pthis->actor.textId))
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_TA_SURPRISE);

		if(faceReaction != 0)
		{
			func_80B14FAC(pthis, func_80B15E28);
		}
		else
		{
			gSaveContext.infTable[7] |= 0x4000;

			switch(pthis->actor.textId)
			{
				case 0x207E:
				case 0x207F:
					func_80B14FAC(pthis, func_80B161C0);
					break;
				case 0x208B:
					func_80B14FAC(pthis, func_80B15FE8);
					break;
				default:
					func_80B14FAC(pthis, func_80B16364);
					break;
			}
		}
	}
	pthis->unk_2E0 &= ~1;
}

void func_80B16608(EnTa* pthis, GlobalContext* globalCtx)
{
	if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
	{
		switch(pthis->actor.textId)
		{
			case 0x2085:
				pthis->actionFunc = func_80B161C0;
				break;
			case 0x2086:
				pthis->actionFunc = func_80B162E8;
				break;
			case 0x2088:
				pthis->actionFunc = func_80B1642C;
				break;
		}
		pthis->actor.flags &= ~ACTOR_FLAG_16;
	}
	else
	{
		pthis->actor.flags |= ACTOR_FLAG_16;
		func_8002F2CC(&pthis->actor, globalCtx, 1000.0f);
	}
	pthis->unk_2E0 |= 1;
}

void func_80B166CC(EnTa* pthis)
{
	s16 temp_v0 = pthis->blinkTimer - 1;

	if(temp_v0 != 0)
	{
		pthis->blinkTimer = temp_v0;
	}
	else
	{
		pthis->unk_2B0 = func_80B16700;
	}
}

void func_80B16700(EnTa* pthis)
{
	s16 blinkTimer = pthis->blinkTimer - 1;

	if(blinkTimer != 0)
	{
		pthis->blinkTimer = blinkTimer;
	}
	else
	{
		s16 nextEyeIndex = pthis->eyeIndex + 1;
		s16 blinkTimer = 3;

		if(nextEyeIndex >= blinkTimer)
		{
			pthis->eyeIndex = 0;
			if(pthis->unk_2CE > 0)
			{
				pthis->unk_2CE--;
				blinkTimer = 1;
			}
			else
			{
				blinkTimer = (s32)(Rand_ZeroOne() * 60.0f) + 20;
			}
			pthis->blinkTimer = blinkTimer;
			pthis->unk_2B0 = func_80B166CC;
		}
		else
		{
			pthis->eyeIndex = nextEyeIndex;
			pthis->blinkTimer = 1;
		}
	}
}

void func_80B167C0(EnTa* pthis)
{
	if(SkelAnime_Update(&pthis->skelAnime))
	{
		Animation_PlayOnce(&pthis->skelAnime, pthis->currentAnimation);
	}
}

void func_80B167FC(EnTa* pthis)
{
	if(SkelAnime_Update(&pthis->skelAnime))
	{
		Animation_PlayOnce(&pthis->skelAnime, pthis->currentAnimation);
		Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_TA_SLEEP);
	}
	pthis->unk_2E0 |= 0xC;
}

void func_80B16854(EnTa* pthis)
{
	if(pthis->unk_2E2 > 0)
	{
		pthis->unk_2E2--;
	}
	else
	{
		if(SkelAnime_Update(&pthis->skelAnime))
		{
			Animation_PlayOnce(&pthis->skelAnime, pthis->currentAnimation);
			pthis->unk_2E2 = Rand_ZeroFloat(100.0f) + 100.0f;
		}

		if(pthis->skelAnime.curFrame < 96.0f && pthis->skelAnime.curFrame >= 53.0f)
		{
			pthis->eyeIndex = 1;
		}
		else
		{
			pthis->eyeIndex = 2;
		}
		pthis->unk_2E0 |= 8;
	}
	pthis->unk_2E0 |= 4;
}

void func_80B16938(EnTa* pthis)
{
	if(!(pthis->unk_2E0 & 0x10))
	{
		if(SkelAnime_Update(&pthis->skelAnime))
		{
			pthis->unk_2E0 |= 0x10;
		}
		pthis->unk_2E0 |= 8;
	}
}

void EnTa_Update(Actor* thisx, GlobalContext* globalCtx)
{
	EnTa* pthis = (EnTa*)thisx;
	s32 pad;

	Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
	Actor_MoveForward(&pthis->actor);
	Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
	pthis->unk_260(pthis);
	pthis->actionFunc(pthis, globalCtx);

	if(!(pthis->unk_2E0 & 4))
	{
		pthis->unk_2B0(pthis);
	}

	if(pthis->unk_2E0 & 1)
	{
		func_80038290(globalCtx, &pthis->actor, &pthis->unk_2D4, &pthis->unk_2DA, pthis->actor.focus.pos);
	}
	else
	{
		Math_SmoothStepToS(&pthis->unk_2D4.x, 0, 6, 6200, 100);
		Math_SmoothStepToS(&pthis->unk_2D4.y, 0, 6, 6200, 100);
		Math_SmoothStepToS(&pthis->unk_2DA.x, 0, 6, 6200, 100);
		Math_SmoothStepToS(&pthis->unk_2DA.y, 0, 6, 6200, 100);
	}

	pthis->unk_2E0 &= ~0x5;

	if(pthis->unk_2CC > 0)
	{
		pthis->unk_2CC--;
	}
}

s32 EnTa_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	EnTa* pthis = (EnTa*)thisx;

	switch(limbIndex)
	{
		case 8:
			rot->x += pthis->unk_2DA.y;
			rot->y -= pthis->unk_2DA.x;
			break;
		case 15:
			rot->x += pthis->unk_2D4.y;
			rot->z += pthis->unk_2D4.x;
			break;
	}

	if(pthis->unk_2E0 & 0x8)
	{
		pthis->unk_2E0 &= ~0x8;
	}
	else if((limbIndex == 8) || (limbIndex == 10) || (limbIndex == 13))
	{
		s32 limbIdx50 = limbIndex * 50;

		rot->y += Math_SinS((globalCtx->frames * (s16)(limbIdx50 + 0x814))) * 200.0f;
		rot->z += Math_CosS((globalCtx->frames * (s16)(limbIdx50 + 0x940))) * 200.0f;
	}

	return false;
}

void EnTa_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	EnTa* pthis = (EnTa*)thisx;

	if(limbIndex == 15)
	{
		Matrix_MultVec3f(&D_80B16E7C_111, &pthis->actor.focus.pos);
	}
}

void EnTa_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	EnTa* pthis = (EnTa*)thisx;
	s32 pad;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_ta.c", 2381);

	func_800943C8(globalCtx->gfxCtx);

	gSPSegment(POLY_OPA_DISP++, 0x8, SEGMENTED_TO_VIRTUAL(eyeTextures_112[pthis->eyeIndex]));
	gSPSegment(POLY_OPA_DISP++, 0x9, SEGMENTED_TO_VIRTUAL(gTalonHeadSkinTex));

	SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, EnTa_OverrideLimbDraw, EnTa_PostLimbDraw, pthis);

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_ta.c", 2400);
}

void EnTa_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	D_80B16E7C_111 = {
	    1100.0f,
	    1000.0f,
	    0.0f,
	};

	En_Ta_InitVars = {
	    ACTOR_EN_TA, ACTORCAT_NPC, FLAGS, OBJECT_TA, sizeof(EnTa), (ActorFunc)EnTa_Init, (ActorFunc)EnTa_Destroy, (ActorFunc)EnTa_Update, (ActorFunc)EnTa_Draw, (ActorFunc)EnTa_Reset,
	};

	sCylinderInit = {
	    {
		COLTYPE_NONE,
		AT_NONE,
		AC_ON | AC_TYPE_PLAYER,
		OC1_ON | OC1_TYPE_ALL,
		OC2_TYPE_1,
		COLSHAPE_CYLINDER,
	    },
	    {
		ELEMTYPE_UNK0,
		{0x00000000, 0x00, 0x00},
		{0x00000004, 0x00, 0x00},
		TOUCH_NONE,
		BUMP_ON,
		OCELEM_ON,
	    },
	    {30, 40, 0, {0, 0, 0}},
	};
}
