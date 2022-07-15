#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_ELF_MSG_Z_ELF_MSG_C
#include "actor_common.h"
/*
 * File: z_elf_msg.c
 * Overlay: ovl_Elf_Msg
 * Description: Readable Navi call spot
 */

#include "overlays/actors/ovl_En_Elf/z_en_elf.h"
#include "vt.h"
#include "z_elf_msg.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void ElfMsg_Init(Actor* thisx, GlobalContext* globalCtx);
void ElfMsg_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ElfMsg_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ElfMsg_Update(Actor* thisx, GlobalContext* globalCtx);
void ElfMsg_Draw(Actor* thisx, GlobalContext* globalCtx);

void ElfMsg_CallNaviCuboid(ElfMsg* pthis, GlobalContext* globalCtx);
void ElfMsg_CallNaviCylinder(ElfMsg* pthis, GlobalContext* globalCtx);

ActorInit Elf_Msg_InitVars = {
    ACTOR_ELF_MSG, ACTORCAT_ITEMACTION, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(ElfMsg), (ActorFunc)ElfMsg_Init, (ActorFunc)ElfMsg_Destroy, (ActorFunc)ElfMsg_Update, (ActorFunc)ElfMsg_Draw, (ActorFunc)ElfMsg_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_STOP),
};

void ElfMsg_SetupAction(ElfMsg* pthis, ElfMsgActionFunc actionFunc)
{
	pthis->actionFunc = actionFunc;
}

/**
 * Checks a scene flag - if flag is set, the actor is killed and function returns 1. Otherwise returns 0.
 * Can also set a switch flag from params while killing.
 */
s32 ElfMsg_KillCheck(ElfMsg* pthis, GlobalContext* globalCtx)
{
	if((pthis->actor.world.rot.y > 0) && (pthis->actor.world.rot.y < 0x41) && Flags_GetSwitch(globalCtx, pthis->actor.world.rot.y - 1))
	{
		LOG_STRING("共倒れ", "../z_elf_msg.c", 161); // "Mutual destruction"
		if(((pthis->actor.params >> 8) & 0x3F) != 0x3F)
		{
			Flags_SetSwitch(globalCtx, (pthis->actor.params >> 8) & 0x3F);
		}
		Actor_Kill(&pthis->actor);
		return 1;
	}
	else if((pthis->actor.world.rot.y == -1) && Flags_GetClear(globalCtx, pthis->actor.room))
	{
		LOG_STRING("共倒れ", "../z_elf_msg.c", 172); // "Mutual destruction"
		if(((pthis->actor.params >> 8) & 0x3F) != 0x3F)
		{
			Flags_SetSwitch(globalCtx, (pthis->actor.params >> 8) & 0x3F);
		}
		Actor_Kill(&pthis->actor);
		return 1;
	}
	else if(((pthis->actor.params >> 8) & 0x3F) == 0x3F)
	{
		return 0;
	}
	else if(Flags_GetSwitch(globalCtx, (pthis->actor.params >> 8) & 0x3F))
	{
		Actor_Kill(&pthis->actor);
		return 1;
	}
	return 0;
}

void ElfMsg_Init(Actor* thisx, GlobalContext* globalCtx)
{
	ElfMsg* pthis = (ElfMsg*)thisx;

	// "Conditions for Elf Tag disappearing"
	osSyncPrintf(VT_FGCOL(CYAN) "\nエルフ タグ 消える条件 %d" VT_RST "\n", (thisx->params >> 8) & 0x3F);
	osSyncPrintf(VT_FGCOL(CYAN) "\nthisx->shape.angle.sy = %d\n" VT_RST, thisx->shape.rot.y);
	if(thisx->shape.rot.y >= 0x41)
	{
		// "Conditions for Elf Tag appearing"
		osSyncPrintf(VT_FGCOL(CYAN) "\nエルフ タグ 出現条件 %d" VT_RST "\n", thisx->shape.rot.y - 0x41);
	}

	if(!ElfMsg_KillCheck(pthis, globalCtx))
	{
		Actor_ProcessInitChain(thisx, sInitChain);
		if(thisx->world.rot.x == 0)
		{
			thisx->scale.z = 0.4f;
			thisx->scale.x = 0.4f;
		}
		else
		{
			thisx->scale.x = thisx->scale.z = thisx->world.rot.x * 0.04f;
		}

		if(thisx->world.rot.z == 0)
		{
			thisx->scale.y = 0.4f;
		}
		else
		{
			thisx->scale.y = thisx->world.rot.z * 0.04f;
		}

		if(thisx->params & 0x4000)
		{
			ElfMsg_SetupAction(pthis, ElfMsg_CallNaviCuboid);
		}
		else
		{
			ElfMsg_SetupAction(pthis, ElfMsg_CallNaviCylinder);
		}

		thisx->shape.rot.x = thisx->shape.rot.y = thisx->shape.rot.z = 0;
	}
}

void ElfMsg_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
}

s32 ElfMsg_GetMessageId(ElfMsg* pthis)
{
	// Negative message ID forces link to talk to Navi
	if(pthis->actor.params & 0x8000)
	{
		return (pthis->actor.params & 0xFF) + 0x100;
	}
	else
	{
		return -((pthis->actor.params & 0xFF) + 0x100);
	}
}

void ElfMsg_CallNaviCuboid(ElfMsg* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	EnElf* navi = (EnElf*)player->naviActor;

	if((fabsf(player->actor.world.pos.x - pthis->actor.world.pos.x) < (100.0f * pthis->actor.scale.x)) && (pthis->actor.world.pos.y <= player->actor.world.pos.y) &&
	   ((player->actor.world.pos.y - pthis->actor.world.pos.y) < (100.0f * pthis->actor.scale.y)) && (fabsf(player->actor.world.pos.z - pthis->actor.world.pos.z) < (100.0f * pthis->actor.scale.z)))
	{
		player->naviTextId = ElfMsg_GetMessageId(pthis);
		navi->elfMsg = pthis;
	}
}

s32 ElfMsg_WithinXZDistance(Vec3f* pos1, Vec3f* pos2, f32 distance)
{
	return (SQ(pos2->x - pos1->x) + SQ(pos2->z - pos1->z)) < SQ(distance);
}

void ElfMsg_CallNaviCylinder(ElfMsg* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	EnElf* navi = (EnElf*)player->naviActor;

	if(ElfMsg_WithinXZDistance(&player->actor.world.pos, &pthis->actor.world.pos, pthis->actor.scale.x * 100.0f) && (pthis->actor.world.pos.y <= player->actor.world.pos.y) &&
	   ((player->actor.world.pos.y - pthis->actor.world.pos.y) < (100.0f * pthis->actor.scale.y)))
	{
		player->naviTextId = ElfMsg_GetMessageId(pthis);
		navi->elfMsg = pthis;
	}
}

void ElfMsg_Update(Actor* thisx, GlobalContext* globalCtx)
{
	ElfMsg* pthis = (ElfMsg*)thisx;

	if(!ElfMsg_KillCheck(pthis, globalCtx))
	{
		if(Actor_ProcessTalkRequest(&pthis->actor, globalCtx))
		{
			if(((pthis->actor.params >> 8) & 0x3F) != 0x3F)
			{
				Flags_SetSwitch(globalCtx, (pthis->actor.params >> 8) & 0x3F);
			}
			Actor_Kill(&pthis->actor);
			return;
		}
		if((pthis->actor.world.rot.y <= 0x41) || (pthis->actor.world.rot.y > 0x80) || Flags_GetSwitch(globalCtx, pthis->actor.world.rot.y - 0x41))
		{
			pthis->actionFunc(pthis, globalCtx);
		}
	}
}

#ifndef RETAIL
#include "overlays/ovl_Elf_Msg/ovl_Elf_Msg.cpp"
#endif

void ElfMsg_Draw(Actor* thisx, GlobalContext* globalCtx)
{
#ifndef RETAIL
	OPEN_DISPS(globalCtx->gfxCtx, "../z_elf_msg.c", 436);

	if(R_NAVI_MSG_REGION_ALPHA == 0)
	{
		return;
	}

	func_80093D18(globalCtx->gfxCtx);
	if(thisx->params & 0x8000)
	{
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 100, 100, R_NAVI_MSG_REGION_ALPHA);
	}
	else
	{
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, R_NAVI_MSG_REGION_ALPHA);
	}

	gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_elf_msg.c", 448), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPDisplayList(POLY_XLU_DISP++, D_809AD278);

	if(thisx->params & 0x4000)
	{
		gSPDisplayList(POLY_XLU_DISP++, sElfMsgCubeDL);
	}
	else
	{
		gSPDisplayList(POLY_XLU_DISP++, sElfMsgCylinderDL);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_elf_msg.c", 457);
#endif
}

void ElfMsg_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Elf_Msg_InitVars = {
	    ACTOR_ELF_MSG, ACTORCAT_ITEMACTION, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(ElfMsg), (ActorFunc)ElfMsg_Init, (ActorFunc)ElfMsg_Destroy, (ActorFunc)ElfMsg_Update, (ActorFunc)ElfMsg_Draw, (ActorFunc)ElfMsg_Reset,
	};
}
