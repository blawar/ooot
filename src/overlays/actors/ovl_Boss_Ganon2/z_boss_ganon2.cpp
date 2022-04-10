#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BOSS_GANON2_Z_BOSS_GANON2_C
#include "actor_common.h"
#include "overlays/actors/ovl_Demo_Gj/z_demo_gj.h"
#include "overlays/actors/ovl_En_Zl3/z_en_zl3.h"
#include "z_boss_ganon2.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"
#include "def/code_800A9F30.h"
#include "def/cosf.h"
#include "def/graph.h"
#include "def/random.h"
#include "def/sinf.h"
#include "def/sys_math_atan.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_demo.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"
#include "objects/object_ganon/object_ganon.h"
#include "objects/object_ganon2/object_ganon2.h"
#include "objects/object_ganon_anime3/object_ganon_anime3.h"
#include "objects/object_geff/object_geff.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BossGanon2_Init(Actor* thisx, GlobalContext* globalCtx);
void BossGanon2_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BossGanon2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BossGanon2_Update(Actor* thisx, GlobalContext* globalCtx);
void BossGanon2_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808FD5C4(BossGanon2* pthis, GlobalContext* globalCtx);
void func_808FD5F4(BossGanon2* pthis, GlobalContext* globalCtx);
void func_808FFDB0(BossGanon2* pthis, GlobalContext* globalCtx);
void func_808FFEBC(BossGanon2* pthis, GlobalContext* globalCtx);
void func_808FFFE0(BossGanon2* pthis, GlobalContext* globalCtx);
void func_80900104(BossGanon2* pthis, GlobalContext* globalCtx);
void func_8090026C(BossGanon2* pthis, GlobalContext* globalCtx);
void func_809002CC(BossGanon2* pthis, GlobalContext* globalCtx);
void func_80900344(BossGanon2* pthis, GlobalContext* globalCtx);
void func_80900580(BossGanon2* pthis, GlobalContext* globalCtx);
void func_80900650(BossGanon2* pthis, GlobalContext* globalCtx);
void func_80900890(BossGanon2* pthis, GlobalContext* globalCtx);
void func_8090120C(BossGanon2* pthis, GlobalContext* globalCtx);
void BossGanon2_UpdateSpecialEffects(BossGanon2* pthis, GlobalContext* globalCtx);
void BossGanon2_DrawSpecialEffects(GlobalContext* globalCtx);
void BossGanon2_GenShadowTexture(void* shadowTexture, BossGanon2* pthis, GlobalContext* globalCtx);
void BossGanon2_DrawShadowTexture(void* shadowTexture, BossGanon2* pthis, GlobalContext* globalCtx);

ActorInit Boss_Ganon2_InitVars = {
    ACTOR_BOSS_GANON2, ACTORCAT_BOSS, FLAGS, OBJECT_GANON2, sizeof(BossGanon2), (ActorFunc)BossGanon2_Init, (ActorFunc)BossGanon2_Destroy, (ActorFunc)BossGanon2_Update, (ActorFunc)BossGanon2_Draw, (ActorFunc)BossGanon2_Reset,
};

#include "z_boss_ganon2_data.cpp"

void BossGanon2_InitRand(s32 seedInit0, s32 seedInit1, s32 seedInit2)
{
	sSeed1 = seedInit0;
	sSeed2 = seedInit1;
	sSeed3 = seedInit2;
}

f32 BossGanon2_RandZeroOne(void)
{
	// Wichmann-Hill algorithm
	f32 randFloat;

	sSeed1 = (sSeed1 * 171) % 30269;
	sSeed2 = (sSeed2 * 172) % 30307;
	sSeed3 = (sSeed3 * 170) % 30323;

	randFloat = (sSeed1 / 30269.0f) + (sSeed2 / 30307.0f) + (sSeed3 / 30323.0f);
	while(randFloat >= 1.0f)
	{
		randFloat -= 1.0f;
	}
	return fabsf(randFloat);
}

void func_808FD080(s32 idx, ColliderJntSph* collider, Vec3f* arg2)
{
	collider->elements[idx].dim.worldSphere.center.x = arg2->x;
	collider->elements[idx].dim.worldSphere.center.y = arg2->y;
	collider->elements[idx].dim.worldSphere.center.z = arg2->z;

	collider->elements[idx].dim.worldSphere.radius = collider->elements[idx].dim.modelSphere.radius * collider->elements[idx].dim.scale;
}

void BossGanon2_SetObjectSegment(BossGanon2* pthis, GlobalContext* globalCtx, s32 objectId, u8 setRSPSegment)
{
	s32 pad;
	s32 objectIdx = Object_GetIndex(&globalCtx->objectCtx, objectId);

	gSegments[6] = PHYSICAL_TO_VIRTUAL(gObjectTable[objectIdx].vromStart.get());

	if(setRSPSegment)
	{
		OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 790);

		gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[objectIdx].vromStart.get());
		gSPSegment(POLY_XLU_DISP++, 0x06, gObjectTable[objectIdx].vromStart.get());

		CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 799);
	}
}

void BossGanon2_RemoveLinksSword(GlobalContext* globalCtx, Vec3f* arg1)
{
	BossGanon2Effect* effect = (BossGanon2Effect*)globalCtx->specialEffects;

	effect->type = 1;
	effect->position = *arg1;
	effect->unk_2E = 0;
	effect->unk_01 = 0;
	effect->velocity.x = 25.0f;
	effect->velocity.y = 15.0f;
	effect->velocity.z = 0.0f;
	effect->accel.x = 0.0f;
	effect->accel.y = -1.0f;
	effect->accel.z = 0.0f;
}

void func_808FD27C(GlobalContext* globalCtx, Vec3f* position, Vec3f* velocity, f32 scale)
{
	BossGanon2Effect* effect = (BossGanon2Effect*)globalCtx->specialEffects;
	s16 i;

	for(i = 0; i < ARRAY_COUNT(sParticles); i++, effect++)
	{
		if(effect->type == 0)
		{
			effect->type = 2;
			effect->position = *position;
			effect->velocity = *velocity;
			effect->accel.x = 0.0;
			effect->accel.y = -1.0f;
			effect->accel.z = 0.0;
			effect->unk_38.z = Rand_ZeroFloat(2 * M_PI);
			effect->unk_38.y = Rand_ZeroFloat(2 * M_PI);
			effect->unk_38.x = Rand_ZeroFloat(2 * M_PI);
			effect->scale = scale;
			break;
		}
	}
}

void BossGanon2_Init(Actor* thisx, GlobalContext* globalCtx)
{
	BossGanon2* pthis = (BossGanon2*)thisx;
	s32 pad;
	s16 i;

	globalCtx->specialEffects = sParticles;

	for(i = 0; i < ARRAY_COUNT(sParticles); i++)
	{
		sParticles[i].type = 0;
	}

	pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
	pthis->actor.colChkInfo.health = 30;
	Collider_InitJntSph(globalCtx, &pthis->unk_424);
	Collider_SetJntSph(globalCtx, &pthis->unk_424, &pthis->actor, &sJntSphInit1, pthis->unk_464);
	Collider_InitJntSph(globalCtx, &pthis->unk_444);
	Collider_SetJntSph(globalCtx, &pthis->unk_444, &pthis->actor, &sJntSphInit2, pthis->unk_864);
	BossGanon2_SetObjectSegment(pthis, globalCtx, OBJECT_GANON, false);
	SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gDorfSkel, NULL, NULL, NULL, 0);
	func_808FD5C4(pthis, globalCtx);
	pthis->actor.naviEnemyId = 0x3E;
	pthis->actor.gravity = 0.0f;
}

void BossGanon2_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	BossGanon2* pthis = (BossGanon2*)thisx;

	SkelAnime_Free(&pthis->skelAnime, globalCtx);
	Collider_DestroyJntSph(globalCtx, &pthis->unk_424);
	Collider_DestroyJntSph(globalCtx, &pthis->unk_444);
}

void func_808FD4D4(BossGanon2* pthis, GlobalContext* globalCtx, s16 arg2, s16 arg3)
{
	if((arg2 == 0) || (arg2 == 1))
	{
		Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->unk_1D0, 25.0f, arg3, 8.0f, 0x1F4, 0xA, 1);
	}

	if((arg2 == 0) || (arg2 == 2))
	{
		Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->unk_1DC, 25.0f, arg3, 8.0f, 0x1F4, 0xA, 1);
	}

	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_WALK);
	func_80033E88(&pthis->actor, globalCtx, 2, 0xA);
}

void func_808FD5C4(BossGanon2* pthis, GlobalContext* globalCtx)
{
	pthis->actionFunc = func_808FD5F4;
	pthis->actor.flags &= ~ACTOR_FLAG_0;
	pthis->actor.world.pos.y = -3000.0f;
}

void func_808FD5F4(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s16 pad;
	u8 sp8D;
	Player* player;
	s32 objectIdx;
	s32 zero = 0;
	s32 pad2;

	sp8D = false;
	player = GET_PLAYER(globalCtx);
	pthis->timer++;

	switch(pthis->unk_39C)
	{
		case 0:
			objectIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON_ANIME3);
			if(Object_IsLoaded(&globalCtx->objectCtx, objectIdx))
			{
				func_80064520(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 8);
				pthis->unk_39E = Gameplay_CreateSubCamera(globalCtx);
				Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
				Gameplay_ChangeCameraStatus(globalCtx, pthis->unk_39E, CAM_STAT_ACTIVE);
				pthis->unk_39C = 1;
				sZelda = (EnZl3*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ZL3, 970.0f, 1086.0f, -200.0f, 0, 0, 0, 1);
				sZelda->unk_3C8 = 0;
				sZelda->actor.world.pos.x = 970.0f;
				sZelda->actor.world.pos.y = 1086.0f;
				sZelda->actor.world.pos.z = -214.0f;
				sZelda->actor.shape.rot.y = -0x7000;
				pthis->unk_3BC.x = 0.0f;
				pthis->unk_3BC.y = 1.0f;
				pthis->unk_3BC.z = 0.0f;
				pthis->timer = 0;
				pthis->unk_3A4.x = 0.0f;
				pthis->unk_3A4.y = 1400.0f;
				pthis->unk_3A4.z = 1600.0f;
				player->actor.world.pos.x = 970.0f;
				player->actor.world.pos.y = 1086.0f;
				player->actor.world.pos.z = -186.0f;
				player->actor.shape.rot.y = -0x5000;
				Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime3_Anim_002168, 0.0f);
				globalCtx->envCtx.unk_D8 = 0.0f;
				// fake, tricks the compiler into allocating more stack
				if(zero)
				{
					pthis->unk_3A4.x *= 2.0;
				}
			}
			else
			{
				break;
			}
		case 1:
			if(pthis->timer < 70)
			{
				globalCtx->envCtx.unk_D8 = 0.0f;
			}
			pthis->unk_339 = 3;
			Math_ApproachF(&pthis->unk_3A4.x, 1500.0f, 0.1f, pthis->unk_410.x * 1500.0f);
			Math_ApproachF(&pthis->unk_3A4.z, -160.0f, 0.1f, pthis->unk_410.x * 1760.0f);
			Math_ApproachF(&pthis->unk_410.x, 0.0075f, 1.0f, 0.0001f);
			pthis->unk_3B0.x = -200.0f;
			pthis->unk_3B0.y = 1086.0f;
			pthis->unk_3B0.z = -200.0f;
			if(pthis->timer == 150)
			{
				Message_StartTextbox(globalCtx, 0x70D3, NULL);
			}
			if(pthis->timer > 250 && Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)
			{
				pthis->unk_39C = 2;
				pthis->timer = 0;
				pthis->unk_410.x = 0.0f;
				globalCtx->envCtx.unk_D8 = 1.0f;
			}
			else
			{
				break;
			}
		case 2:
			pthis->unk_339 = 4;
			player->actor.world.pos.x = 970.0f;
			player->actor.world.pos.y = 1086.0f;
			player->actor.world.pos.z = -166.0f;
			sZelda->actor.world.pos.x = 974.0f;
			sZelda->actor.world.pos.y = 1086.0f;
			sZelda->actor.world.pos.z = -186.0f;
			player->actor.shape.rot.y = -0x5000;
			sZelda->actor.shape.rot.y = -0x5000;
			if(pthis->timer == 60)
			{
				Message_StartTextbox(globalCtx, 0x70D4, NULL);
			}
			if(pthis->timer == 40)
			{
				sZelda->unk_3C8 = 1;
				func_8002DF54(globalCtx, &pthis->actor, 0x4E);
			}
			if(pthis->timer == 85)
			{
				sZelda->unk_3C8 = 2;
				func_8002DF54(globalCtx, &pthis->actor, 0x4F);
			}
			pthis->unk_3A4.x = 930.0f;
			pthis->unk_3A4.y = 1129.0f;
			pthis->unk_3A4.z = -181.0f;
			pthis->unk_3B0.x = player->actor.world.pos.x;
			pthis->unk_3B0.z = (player->actor.world.pos.z - 15.0f) + 5.0f;
			if(pthis->timer > 104)
			{
				Math_ApproachF(&pthis->unk_3B0.y, player->actor.world.pos.y + 47.0f + 7.0f + 15.0f, 0.1f, pthis->unk_410.x);
				Math_ApproachF(&pthis->unk_410.x, 2.0f, 1.0f, 0.1f);
			}
			else
			{
				pthis->unk_3B0.y = player->actor.world.pos.y + 47.0f + 7.0f;
			}
			if((pthis->timer > 170) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE))
			{
				pthis->unk_39C = 3;
				pthis->timer = 0;
				pthis->unk_410.x = 0.0f;
			}
			break;
		case 3:
			Math_ApproachF(&pthis->unk_3B0.y, player->actor.world.pos.y + 47.0f + 7.0f, 0.1f, 2.0f);
			pthis->unk_339 = 4;
			if(pthis->timer == 10)
			{
				Common_PlaySfxAtPos(&D_80906D6C, NA_SE_EV_STONE_BOUND);
				Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_STOP);
			}
			if(pthis->timer == 20)
			{
				sZelda->unk_3C8 = 3;
				func_8002DF54(globalCtx, &pthis->actor, 0x50);
			}
			if(pthis->timer == 55)
			{
				pthis->unk_39C = 4;
				pthis->timer = 0;
				pthis->unk_410.x = 0.0f;
				sZelda->unk_3C8 = 4;
				func_8002DF54(globalCtx, &pthis->actor, 0x50);
			}
			break;
		case 4:
			pthis->unk_339 = 4;
			Math_ApproachF(&pthis->unk_3A4.x, -360.0f, 0.1f, pthis->unk_410.x * 1290.0f);
			Math_ApproachF(&pthis->unk_3A4.z, -20.0f, 0.1f, pthis->unk_410.x * 170.0f);
			Math_ApproachF(&pthis->unk_410.x, 0.04f, 1.0f, 0.0005f);
			if(pthis->timer == 100)
			{
				Camera* camera = Gameplay_GetCamera(globalCtx, MAIN_CAM);

				camera->eye = pthis->unk_3A4;
				camera->eyeNext = pthis->unk_3A4;
				camera->at = pthis->unk_3B0;
				func_800C08AC(globalCtx, pthis->unk_39E, 0);
				pthis->unk_39E = 0;
				func_80064534(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 7);
				pthis->unk_39C = 5;
				pthis->timer = 0;
			}
			break;
		case 5:
			pthis->unk_339 = 4;
			if(pthis->actor.xzDistToPlayer < 500.0f)
			{
				Message_CloseTextbox(globalCtx);
				pthis->unk_39C = 10;
				pthis->timer = 0;
				func_80064520(globalCtx, &globalCtx->csCtx);
				pthis->unk_39E = Gameplay_CreateSubCamera(globalCtx);
				Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
				Gameplay_ChangeCameraStatus(globalCtx, pthis->unk_39E, CAM_STAT_ACTIVE);
			}
			else
			{
				break;
			}
		case 10:
			player->actor.world.pos.x = 490.0f;
			player->actor.world.pos.y = 1086.0f;
			player->actor.world.pos.z = -166.0f;
			sZelda->actor.world.pos.x = 724.0f;
			sZelda->actor.world.pos.y = 1086.0f;
			sZelda->actor.world.pos.z = -186.0f;
			player->actor.shape.rot.y = -0x4000;
			sZelda->actor.shape.rot.y = -0x5000;
			pthis->unk_3A4.x = 410.0f;
			pthis->unk_3A4.y = 1096.0f;
			pthis->unk_3A4.z = -110.0f;
			pthis->unk_3B0.x = player->actor.world.pos.x + 10.0f;
			pthis->unk_3B0.y = (player->actor.world.pos.y + 200.0f) - 160.0f;
			pthis->unk_3B0.z = player->actor.world.pos.z;
			if(pthis->timer >= 20)
			{
				Common_PlaySfx(NA_SE_EN_GOMA_LAST - SFX_FLAG);
				Math_ApproachF(&pthis->unk_324, 255.0f, 1.0f, 10.0f);
				pthis->unk_339 = 5;
				if(pthis->timer == 20)
				{
					pthis->unk_33C = 0.0f;
					globalCtx->envCtx.unk_D8 = 0.0f;
				}
			}
			else
			{
				pthis->unk_339 = 4;
			}
			if(pthis->timer == 30)
			{
				sZelda->unk_3C8 = 5;
				func_8002DF54(globalCtx, &pthis->actor, 0x51);
			}
			if(pthis->timer == 50)
			{
				pthis->timer = 0;
				pthis->unk_39C = 11;
			}
			break;
		case 11:
			pthis->unk_339 = 5;
			Common_PlaySfx(NA_SE_EN_GOMA_LAST - SFX_FLAG);
			player->actor.world.pos.x = 490.0f;
			player->actor.world.pos.y = 1086.0f;
			player->actor.world.pos.z = -166.0f;
			sZelda->actor.world.pos.x = 724.0f;
			sZelda->actor.world.pos.y = 1086.0f;
			sZelda->actor.world.pos.z = -186.0f;
			player->actor.shape.rot.y = -0x4000;
			sZelda->actor.shape.rot.y = -0x5000;
			pthis->unk_3A4.x = 450.0f;
			pthis->unk_3A4.y = 1121.0f;
			pthis->unk_3A4.z = -158.0f;
			pthis->unk_3B0.x = (player->actor.world.pos.x - 20.0f) + 2.0f;
			pthis->unk_3B0.y = ((player->actor.world.pos.y + 200.0f) - 151.0f) - 2.0f;
			pthis->unk_3B0.z = player->actor.world.pos.z + 2.0f;
			if(pthis->timer == 10)
			{
				Common_PlaySfxAtPos(&D_80906D6C, NA_SE_EV_STONE_BOUND);
			}
			if(pthis->timer == 20)
			{
				Common_PlaySfx(NA_SE_EV_STONE_BOUND);
			}
			if(pthis->timer == 30)
			{
				func_8002DF54(globalCtx, &pthis->actor, 0x52);
			}
			if(pthis->timer == 50)
			{
				pthis->timer = 0;
				pthis->unk_39C = 12;
				Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime3_Anim_002168, 0.0f);
				pthis->unk_194 = Animation_GetLastFrame(&object_ganon_anime3_Anim_002168);
				pthis->actor.world.pos.x = pthis->actor.world.pos.z = -200.0f;
				pthis->actor.world.pos.y = 1009.0f;
				pthis->actor.shape.yOffset = 7000.0f;
				pthis->actor.world.rot.y = 0x5000;
				pthis->unk_3A4.x = -60.0f;
				pthis->unk_3A4.y = 1106.0f;
				pthis->unk_3A4.z = -200.0f;
				pthis->unk_3B0.x = pthis->unk_3B0.z = -200.0f;
				pthis->unk_3B0.y = pthis->actor.world.pos.y + 70.0f;
				globalCtx->envCtx.unk_D8 = 0.0f;
				globalCtx->envCtx.unk_BE = globalCtx->envCtx.unk_BD = 0;
				pthis->unk_339 = 0;
			}
			else
			{
				break;
			}
		case 12:
		case 13:
			SkelAnime_Update(&pthis->skelAnime);
			if(pthis->timer == 30)
			{
				D_80906D78 = 1;
				pthis->unk_314 = 1;
				Rumble_Shake2(0.0f, 0xC8, 0x14, 0x14);
			}
			if(pthis->timer == 30)
			{
				Common_PlaySfx(NA_SE_EV_GRAVE_EXPLOSION);
			}
			if(pthis->timer >= 30)
			{
				Math_ApproachF(&pthis->actor.world.pos.y, 1289.0f, 0.1f, 10.0f);
				pthis->unk_3B0.y = pthis->actor.world.pos.y + 70.0f;
			}
			if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
			{
				Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime3_Anim_002E6C, 0.0f);
				pthis->unk_39C = 14;
				pthis->timer = 0;
				pthis->actor.world.pos.x = -200.0f;
				pthis->actor.world.pos.y = pthis->actor.world.pos.y - 30.0f;
				pthis->actor.world.pos.z = -200.0f;
				Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_OPENING_GANON);
			}
			else
			{
				break;
			}
		case 14:
			SkelAnime_Update(&pthis->skelAnime);
			Math_ApproachF(&pthis->actor.world.pos.y, 1289.0f, 0.05f, 1.0f);
			player->actor.world.pos.x = 250.0f;
			player->actor.world.pos.y = 1086.0f;
			player->actor.world.pos.z = -266.0f;
			player->actor.shape.rot.y = -0x4000;
			sZelda->actor.world.pos.x = 724.0f;
			sZelda->actor.world.pos.y = 1086.0f;
			sZelda->actor.world.pos.z = -186.0f;
			pthis->unk_3A4.x = pthis->actor.world.pos.x + -10.0f;
			pthis->unk_3A4.y = pthis->actor.world.pos.y + 80.0f;
			pthis->unk_3A4.z = pthis->actor.world.pos.z + 50.0f;
			pthis->unk_3B0.x = player->actor.world.pos.x;
			pthis->unk_3B0.y = player->actor.world.pos.y;
			pthis->unk_3B0.z = player->actor.world.pos.z - 200.0f;
			if(pthis->timer == 20)
			{
				func_8002DF54(globalCtx, &pthis->actor, 0x1E);
			}
			if(pthis->timer == 60)
			{
				pthis->unk_3A4.x = (pthis->actor.world.pos.x + 200.0f) - 154.0f;
				pthis->unk_3A4.y = pthis->actor.world.pos.y + 60.0f;
				pthis->unk_3A4.z = pthis->actor.world.pos.z - 15.0f;
				pthis->unk_39C = 15;
				pthis->timer = 0;
				pthis->unk_3B0.y = pthis->actor.world.pos.y + 77.0f + 100.0f;
				pthis->unk_314 = 2;
				pthis->unk_3B0.z = pthis->actor.world.pos.z + 5.0f;
				pthis->unk_3B0.x = pthis->actor.world.pos.x;
			}
			if((globalCtx->gameplayFrames % 32) == 0)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_BREATH);
			}
			break;
		case 15:
			if(((globalCtx->gameplayFrames % 32) == 0) && (pthis->timer < 100))
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_BREATH);
			}
			SkelAnime_Update(&pthis->skelAnime);
			Math_ApproachF(&pthis->unk_3B0.y, pthis->actor.world.pos.y + 77.0f, 0.05f, 5.0f);
			if(pthis->timer >= 50)
			{
				if(pthis->timer == 50)
				{
					Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime3_Anim_000BFC, 0.0f);
					pthis->unk_194 = Animation_GetLastFrame(&object_ganon_anime3_Anim_000BFC);
					pthis->unk_314 = 3;
				}
				if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
				{
					Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime3_Anim_003F38, 0.0f);
					pthis->unk_194 = 1000.0f;
				}
			}
			if(pthis->timer > 70)
			{
				Math_ApproachF(&pthis->unk_1B4, 255.0f, 1.0f, 10.0f);
			}
			if(pthis->timer == 140)
			{
				pthis->unk_39C = 16;
				pthis->timer = 0;
				Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime3_Anim_003754, 0.0f);
				pthis->unk_194 = Animation_GetLastFrame(&object_ganon_anime3_Anim_003754);
				pthis->unk_339 = 55;
				globalCtx->envCtx.unk_D8 = 1.0f;
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_CASBREAK);
			}
			else
			{
				break;
			}
		case 16:
			if(pthis->timer < 25)
			{
				pthis->unk_339 = 55;
			}
			else
			{
				pthis->unk_339 = 6;
				if(pthis->unk_194 > 100.0f)
				{
					Math_ApproachF(&pthis->unk_30C, 15.0f, 1.0f, 2.0f);
				}
				else
				{
					Math_ApproachF(&pthis->unk_30C, 7.0f, 1.0f, 0.2f);
				}
			}
			pthis->unk_1B4 = 0.0f;
			SkelAnime_Update(&pthis->skelAnime);
			if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
			{
				Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime3_Anim_0028A8, 0.0f);
				pthis->unk_194 = 1000.0f;
			}
			Math_ApproachF(&pthis->unk_3A4.x, (pthis->actor.world.pos.x + 200.0f) - 90.0f, 0.1f, 6.3999996f);
			Math_ApproachF(&pthis->unk_3A4.y, ((pthis->actor.world.pos.y + 60.0f) - 60.0f) - 70.0f, 0.1f, 13.0f);
			Math_ApproachF(&pthis->unk_3B0.y, pthis->actor.world.pos.y + 40.0f, 0.1f, 3.6999998f);
			if(pthis->timer == 30)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_BIGMASIC);
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_THROW_BIG);
			}
			if(pthis->timer <= 50)
			{
				sp8D = true;
			}
			if(pthis->timer >= 60)
			{
				Camera* camera = Gameplay_GetCamera(globalCtx, MAIN_CAM);

				camera->eye = pthis->unk_3A4;
				camera->eyeNext = pthis->unk_3A4;
				camera->at = pthis->unk_3B0;
				pthis->unk_39C = 17;
				pthis->timer = 0;
				pthis->unk_337 = 2;
				BossGanon2_SetObjectSegment(pthis, globalCtx, OBJECT_GANON2, false);
				SkelAnime_Free(&pthis->skelAnime, globalCtx);
				SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_ganon2_Skel_025970, NULL, NULL, NULL, 0);
				BossGanon2_SetObjectSegment(pthis, globalCtx, OBJECT_GANON_ANIME3, false);
				func_8002DF54(globalCtx, &pthis->actor, 0x54);
				pthis->unk_314 = 3;
			}
			// fake, tricks the compiler into using stack the way we need it to
			if(zero)
			{
				Math_ApproachF(&pthis->unk_3B0.y, 0.0f, 0.0f, 0.0f);
			}
			break;
		case 17:
			pthis->unk_339 = 6;
			SkelAnime_Update(&pthis->skelAnime);
			pthis->unk_3A4.x = player->actor.world.pos.x - 40.0f;
			pthis->unk_3A4.y = player->actor.world.pos.y + 40.0f;
			pthis->unk_3A4.z = player->actor.world.pos.z + 20.0f;
			pthis->unk_3B0.x = player->actor.world.pos.x;
			pthis->unk_3B0.y = (player->actor.world.pos.y + 10.0f + 60.0f) - 30.0f;
			pthis->unk_3B0.z = player->actor.world.pos.z;
			if(pthis->timer == 25)
			{
				pthis->unk_39C = 18;
				pthis->timer = 0;
				Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime3_Anim_010380, 0.0f);
				pthis->skelAnime.playSpeed = 0.0f;
				pthis->unk_3A4.x = ((pthis->actor.world.pos.x + 500.0f) - 350.0f) - 50.0f;
				pthis->unk_3A4.y = pthis->actor.world.pos.y;
				pthis->unk_3A4.z = pthis->actor.world.pos.z;
				pthis->unk_3B0.x = pthis->actor.world.pos.x + 50.0f;
				pthis->unk_3B0.y = pthis->actor.world.pos.y + 60.0f;
				pthis->unk_3B0.z = pthis->actor.world.pos.z;
				pthis->actor.world.rot.y = 0x4000;
			}
			break;
		case 18:
			pthis->unk_339 = 6;
			if(pthis->timer == 30)
			{
				Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_GANON_BOSS);
			}
			Math_ApproachF(&pthis->unk_30C, 7.0f, 1.0f, 0.1f);
			Math_ApproachF(&pthis->unk_3A4.x, (pthis->actor.world.pos.x + 500.0f) - 350.0f, 0.1f, 1.0f);
			Math_ApproachF(&pthis->unk_3B0.x, pthis->actor.world.pos.x, 0.1f, 1.0f);
			Math_ApproachF(&pthis->unk_228, 1.0f, 0.1f, 0.02f);
			if(pthis->timer == 65)
			{
				pthis->unk_39C = 19;
				pthis->timer = 0;
			}
			break;
		case 19:
			pthis->unk_394 += 0.5f;
			pthis->unk_339 = 6;
			pthis->actor.world.pos.y += pthis->actor.velocity.y;
			pthis->actor.velocity.y -= 1.0f;
			if(pthis->timer == 10)
			{
				pthis->unk_39C = 20;
				pthis->timer = 0;
				pthis->actor.world.pos.x += 250;
				pthis->actor.world.pos.y = 1886.0f;
				pthis->unk_394 = 0.0f;
				func_8002DF54(globalCtx, &pthis->actor, 0x53);
				pthis->unk_30C = 5.0f;
				pthis->unk_228 = 1.0f;
			}
			break;
		case 20:
			pthis->unk_339 = 6;
			SkelAnime_Update(&pthis->skelAnime);
			pthis->actor.world.pos.y += pthis->actor.velocity.y;
			pthis->actor.velocity.y -= 1.0f;
			player->actor.world.pos.x = 250.0f;
			player->actor.world.pos.y = 1086.0f;
			player->actor.world.pos.z = -266.0f;
			player->actor.shape.rot.y = -0x4000;
			pthis->unk_3A4.x = (player->actor.world.pos.x - 40.0f) - 200.0f;
			pthis->unk_3A4.y = (player->actor.world.pos.y + 40.0f) - 30.0f;
			pthis->unk_3A4.z = (player->actor.world.pos.z - 20.0f) + 100.0f;
			pthis->unk_3B0.x = player->actor.world.pos.x;
			pthis->unk_3B0.y = ((player->actor.world.pos.y + 10.0f + 60.0f) - 20.0f) + 30.0f;
			pthis->unk_3B0.z = player->actor.world.pos.z;
			pthis->unk_3BC.x = 0.8f;
			if(pthis->actor.world.pos.y <= 1099.0f)
			{
				pthis->actor.world.pos.y = 1099.0f;
				pthis->unk_39C = 21;
				pthis->timer = 0;
				pthis->unk_420 = 10.0f;
				pthis->actor.velocity.y = 0.0f;
				Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime3_Anim_010380, 0.0f);
				func_808FD4D4(pthis, globalCtx, 0, 3);
				Rumble_Shake2(0.0f, 0xC8, 0x14, 0x14);
			}
			break;
		case 21:
			pthis->unk_339 = 6;
			SkelAnime_Update(&pthis->skelAnime);
			pthis->unk_41C = Math_CosS(globalCtx->gameplayFrames * 0x8000) * pthis->unk_420;
			Math_ApproachZeroF(&pthis->unk_420, 1.0f, 0.75f);
			if(pthis->timer == 30)
			{
				pthis->unk_39C = 22;
				pthis->unk_30C = 10.0f;
			}
			else
			{
				break;
			}
		case 22:
			if(pthis->timer < 60)
			{
				pthis->unk_339 = 7;
			}
			pthis->unk_3BC.x = 0.0f;
			pthis->actor.world.pos.y = 1099.0f;
			SkelAnime_Update(&pthis->skelAnime);
			Math_ApproachZeroF(&pthis->unk_30C, 1.0f, 0.1f);
			if(pthis->timer > 50)
			{
				Math_ApproachF(&pthis->unk_224, 1.0f, 1.0f, 0.025f);
			}
			if(pthis->timer == 60)
			{
				pthis->unk_336 = 2;
			}
			if(pthis->timer == 80)
			{
				BossGanon2_SetObjectSegment(pthis, globalCtx, OBJECT_GANON2, false);
				TitleCard_InitBossName(globalCtx, &globalCtx->actorCtx.titleCtx, SEGMENTED_TO_VIRTUAL(object_ganon2_Tex_021A90), 160, 180, 128, 40);
			}
			pthis->unk_3A4.x = ((pthis->actor.world.pos.x + 500.0f) - 350.0f) + 100.0f;
			pthis->unk_3A4.y = pthis->actor.world.pos.y;
			pthis->unk_3A4.z = pthis->actor.world.pos.z;
			pthis->unk_3B0.x = pthis->actor.world.pos.x;
			pthis->unk_3B0.z = pthis->actor.world.pos.z;
			pthis->unk_3B0.y = (pthis->unk_1B8.y + 60.0f) - 40.0f;
			if(pthis->timer > 166 && pthis->timer < 173)
			{
				pthis->startAttack = 2;
			}
			if(pthis->timer > 186 && pthis->timer < 196)
			{
				pthis->startAttack = 1;
			}
			if(pthis->timer > 202 && pthis->timer < 210)
			{
				pthis->startAttack = 2;
			}
			if((pthis->timer == 166) || (pthis->timer == 185) || (pthis->timer == 200))
			{
				Common_PlaySfx(NA_SE_EN_MGANON_SWORD);
				Common_PlaySfx(NA_SE_EN_MGANON_ROAR);
			}
			if(pthis->timer == 215)
			{
				pthis->unk_39C = 23;
				pthis->unk_224 = 0.0f;
				func_8002DF54(globalCtx, &pthis->actor, 0x55);
			}
			break;
		case 23:
			SkelAnime_Update(&pthis->skelAnime);
			if(pthis->timer > 222 && pthis->timer < 232)
			{
				pthis->startAttack = 2;
			}
			if(pthis->timer == 222)
			{
				Common_PlaySfx(NA_SE_EN_MGANON_SWORD);
				Common_PlaySfx(NA_SE_EN_MGANON_ROAR);
			}
			pthis->unk_3A4.x = (player->actor.world.pos.x - 40.0f) + 6.0f;
			pthis->unk_3A4.y = player->actor.world.pos.y + 40.0f;
			pthis->unk_3A4.z = (player->actor.world.pos.z + 20.0f) - 7.0f;
			pthis->unk_3B0.x = player->actor.world.pos.x;
			pthis->unk_3B0.y = ((player->actor.world.pos.y + 10.0f + 60.0f) - 20.0f) - 2.0f;
			pthis->unk_3B0.z = player->actor.world.pos.z;
			if(pthis->timer == 228)
			{
				Common_PlaySfx(NA_SE_IT_SHIELD_REFLECT_SW);
				func_8002DF54(globalCtx, &pthis->actor, 0x56);
				Rumble_Shake2(0.0f, 0xFF, 0xA, 0x32);
			}
			if(pthis->timer >= 229)
			{
				globalCtx->envCtx.fillScreen = true;
				globalCtx->envCtx.screenFillColor[0] = globalCtx->envCtx.screenFillColor[1] = globalCtx->envCtx.screenFillColor[2] = 255;
				globalCtx->envCtx.screenFillColor[3] = 100;
				if(pthis->timer == 234)
				{
					Vec3f sp68;

					globalCtx->envCtx.fillScreen = false;
					pthis->unk_39C = 24;
					pthis->timer = 0;
					sp68 = player->actor.world.pos;
					sp68.y += 60.0f;
					BossGanon2_RemoveLinksSword(globalCtx, &sp68);
					globalCtx->envCtx.unk_D8 = 0.0f;
					globalCtx->envCtx.unk_BE = 0;
					pthis->unk_339 = 0;
				}
			}
			break;
		case 24:
			SkelAnime_Update(&pthis->skelAnime);
			if(1)
			{
				BossGanon2Effect* effect = (BossGanon2Effect*)globalCtx->specialEffects;

				pthis->unk_3B0 = effect->position;
				pthis->unk_3A4.x = effect->position.x + 70.0f;
				pthis->unk_3A4.y = effect->position.y - 30.0f;
				pthis->unk_3A4.z = effect->position.z + 70.0f;
			}
			if((pthis->timer & 3) == 0)
			{
				Common_PlaySfx(NA_SE_IT_SWORD_SWING);
			}
			if(pthis->timer == 25)
			{
				func_8002DF54(globalCtx, &pthis->actor, 0x57);
				pthis->unk_39C = 25;
				pthis->timer = 0;
			}
			break;
		case 25:
			SkelAnime_Update(&pthis->skelAnime);
			pthis->unk_3A4.x = (player->actor.world.pos.x - 40.0f) + 80.0f;
			pthis->unk_3A4.y = player->actor.world.pos.y + 40.0f + 10.0f;
			pthis->unk_3A4.z = player->actor.world.pos.z + 20.0f + 10.0f;
			pthis->unk_3B0.x = player->actor.world.pos.x - 20.0f;
			pthis->unk_3B0.y = ((player->actor.world.pos.y + 10.0f + 60.0f) - 20.0f) - 3.0f;
			pthis->unk_3B0.z = (player->actor.world.pos.z - 40.0f) - 10.0f;
			if(pthis->timer == 10)
			{
				BossGanon2Effect* effect = (BossGanon2Effect*)globalCtx->specialEffects;

				effect->unk_2E = 1;
				effect->position.x = sZelda->actor.world.pos.x + 50.0f + 10.0f;
				effect->position.y = sZelda->actor.world.pos.y + 350.0f;
				effect->position.z = sZelda->actor.world.pos.z - 25.0f;
				effect->velocity.x = 0.0f;
				effect->velocity.z = 0.0f;
				effect->velocity.y = -30.0f;
				pthis->unk_39C = 26;
				pthis->timer = 0;
			}
			else
			{
				break;
			}
		case 26:
			pthis->unk_3A4.x = sZelda->actor.world.pos.x + 100.0f + 30.0f;
			pthis->unk_3A4.y = sZelda->actor.world.pos.y + 10.0f;
			pthis->unk_3A4.z = sZelda->actor.world.pos.z + 5.0f;
			pthis->unk_3B0.x = sZelda->actor.world.pos.x;
			pthis->unk_3B0.y = sZelda->actor.world.pos.y + 30.0f;
			pthis->unk_3B0.z = sZelda->actor.world.pos.z - 20.0f;
			pthis->unk_3BC.z = -0.5f;
			if(pthis->timer == 13)
			{
				sZelda->unk_3C8 = 6;
			}
			if(pthis->timer == 50)
			{
				pthis->unk_39C = 27;
				pthis->timer = 0;
			}
			break;
		case 27:
			pthis->unk_3BC.z = 0.0f;
			if(pthis->timer == 4)
			{
				func_8002DF54(globalCtx, &pthis->actor, 0x58);
			}
			pthis->unk_3A4.x = player->actor.world.pos.x - 20.0f;
			pthis->unk_3A4.y = player->actor.world.pos.y + 50.0f;
			pthis->unk_3A4.z = player->actor.world.pos.z;
			pthis->unk_3B0.x = player->actor.world.pos.x;
			pthis->unk_3B0.y = player->actor.world.pos.y + 50.0f;
			pthis->unk_3B0.z = player->actor.world.pos.z;
			if(pthis->timer == 26)
			{
				D_8090EB30 = globalCtx->actorCtx.actorLists[ACTORCAT_ITEMACTION].head;
				while(D_8090EB30 != NULL)
				{
					if(D_8090EB30->id == ACTOR_EN_ELF)
					{
						pthis->unk_3A4.x = D_8090EB30->world.pos.x - 30.0f;
						pthis->unk_3A4.y = D_8090EB30->world.pos.y;
						pthis->unk_3A4.z = D_8090EB30->world.pos.z;
						pthis->unk_3B0.x = D_8090EB30->world.pos.x;
						pthis->unk_3B0.y = D_8090EB30->world.pos.y;
						pthis->unk_3B0.z = D_8090EB30->world.pos.z;
						break;
					}
					D_8090EB30 = D_8090EB30->next;
				}
				pthis->unk_39C = 28;
				pthis->timer = 0;
			}
			break;
		case 28:
			if(pthis->timer == 5)
			{
				Message_StartTextbox(globalCtx, 0x70D6, NULL);
			}
			if(D_8090EB30 != NULL)
			{
				pthis->unk_3A4.x = D_8090EB30->world.pos.x - 20.0f;
				pthis->unk_3A4.y = D_8090EB30->world.pos.y;
				pthis->unk_3A4.z = D_8090EB30->world.pos.z;
				Math_ApproachF(&pthis->unk_3B0.x, D_8090EB30->world.pos.x, 0.2f, 50.0f);
				Math_ApproachF(&pthis->unk_3B0.y, D_8090EB30->world.pos.y, 0.2f, 50.0f);
				Math_ApproachF(&pthis->unk_3B0.z, D_8090EB30->world.pos.z, 0.2f, 50.0f);
				if((pthis->timer > 40) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE))
				{
					pthis->unk_39C = 29;
					pthis->timer = 0;
					Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime3_Anim_0147E0, 0.0f);
					pthis->unk_194 = Animation_GetLastFrame(&object_ganon_anime3_Anim_0147E0);
					pthis->actor.shape.yOffset = 0.0f;
					pthis->actor.world.pos.y = 1086.0f;
					pthis->actor.gravity = -1.0f;
					pthis->unk_335 = 1;
					pthis->unk_224 = 1.0f;
				}
			}
			break;
		case 29:
			SkelAnime_Update(&pthis->skelAnime);
			pthis->unk_3A4.x = (((pthis->actor.world.pos.x + 500.0f) - 350.0f) + 100.0f) - 60.0f;
			pthis->unk_3B0.x = pthis->actor.world.pos.x;
			pthis->unk_3B0.z = pthis->actor.world.pos.z;
			pthis->unk_3A4.y = pthis->actor.world.pos.y;
			pthis->unk_3A4.z = pthis->actor.world.pos.z + 10.0f;
			pthis->unk_3B0.y = (pthis->unk_1B8.y + 60.0f) - 40.0f;
			player->actor.shape.rot.y = -0x4000;
			player->actor.world.pos.x = 140.0f;
			player->actor.world.pos.z = -196.0f;
			if(pthis->timer == 50)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_ROAR);
			}
			if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
			{
				Camera* camera = Gameplay_GetCamera(globalCtx, MAIN_CAM);

				camera->eye = pthis->unk_3A4;
				camera->eyeNext = pthis->unk_3A4;
				camera->at = pthis->unk_3B0;
				func_800C08AC(globalCtx, pthis->unk_39E, 0);
				pthis->unk_39E = 0;
				func_80064534(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 7);
				pthis->unk_39C = 0;
				pthis->unk_337 = 1;
				func_808FFDB0(pthis, globalCtx);
				pthis->unk_1A2[1] = 50;
				pthis->actor.flags |= ACTOR_FLAG_0;
				sZelda->unk_3C8 = 7;
			}
			break;
	}

	if((pthis->unk_30C > 4.0f) && !sp8D)
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_BODY_SPARK - SFX_FLAG);
	}

	if(pthis->unk_39E != 0)
	{
		// fake, tricks the compiler into putting some pointers on the stack
		if(zero)
		{
			osSyncPrintf(NULL, 0, 0);
		}
		pthis->unk_3B0.y += pthis->unk_41C;
		Gameplay_CameraSetAtEyeUp(globalCtx, pthis->unk_39E, &pthis->unk_3B0, &pthis->unk_3A4, &pthis->unk_3BC);
	}
}

void BossGanon2_SpawnRubble(BossGanon2* pthis, GlobalContext* globalCtx)
{
	if((pthis->startAttack != 0) && (pthis->unk_39E == 0))
	{
		Actor* actor = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;
		while(actor != NULL)
		{
			if(actor->id == ACTOR_DEMO_GJ)
			{
				DemoGj* gj = (DemoGj*)actor;

				if(((actor->params & 0xFF) == 0x10) || ((actor->params & 0xFF) == 0x11) || ((actor->params & 0xFF) == 0x16))
				{
					if(SQ(pthis->unk_218.x - gj->dyna.actor.world.pos.x) + SQ(pthis->unk_218.z - gj->dyna.actor.world.pos.z) < SQ(100.0f))
					{
						s32 pad;
						Vec3f sp28;

						Matrix_RotateY(((pthis->actor.shape.rot.y / (f32)0x8000) * M_PI) + 0.5f, MTXMODE_NEW);
						sp28.x = 0.0f;
						sp28.y = 0.0f;
						sp28.z = 1.0f;
						Matrix_MultVec3f(&sp28, &gj->explosionDirection);
						gj->killFlag = true;
						Rumble_Shake2(0.0f, 0x96, 0x14, 0x32);
						pthis->unk_392 = 6;
						return;
					}
				}
			}

			actor = actor->next;
		}

		if(pthis->unk_392 == 4)
		{
			Common_PlaySfx(NA_SE_EV_GRAVE_EXPLOSION);
		}

		if(pthis->unk_392 == 3)
		{
			Common_PlaySfx(NA_SE_EN_MGANON_SWDIMP);
		}
	}
}

s32 func_808FFA24(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Actor* actor = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;

	while(actor != NULL)
	{
		if(actor->id == ACTOR_DEMO_GJ)
		{
			DemoGj* gj = (DemoGj*)actor;

			if(((actor->params & 0xFF) == 0x10) || ((actor->params & 0xFF) == 0x11) || ((actor->params & 0xFF) == 0x16))
			{
				if(SQ(pthis->actor.world.pos.x - gj->dyna.actor.world.pos.x) + SQ(pthis->actor.world.pos.z - gj->dyna.actor.world.pos.z) < SQ(200.0f))
				{
					return true;
				}
			}
		}

		actor = actor->next;
	}

	return false;
}

void func_808FFAC8(BossGanon2* pthis, GlobalContext* globalCtx, u8 arg2)
{
	s16 temp_v1;
	s16 phi_a1;

	if(pthis->unk_313 || (arg2 != 0))
	{
		phi_a1 = pthis->actor.shape.rot.y - pthis->actor.yawTowardsPlayer;

		if(phi_a1 > 0x3000)
		{
			phi_a1 = 0x3000;
		}
		else if(phi_a1 < -0x3000)
		{
			phi_a1 = -0x3000;
		}
	}
	else if(pthis->unk_19C & 0x20)
	{
		phi_a1 = 0x3000;
	}
	else
	{
		phi_a1 = -0x3000;
	}

	Math_ApproachS(&pthis->unk_31A, phi_a1, 5, 0x7D0);

	temp_v1 = Math_Atan2S(pthis->actor.xzDistToPlayer, 150.0f) - 0xBB8;
	temp_v1 = CLAMP_MAX(temp_v1, 0x1B58);
	temp_v1 = CLAMP_MIN(temp_v1, -0x1B58);

	Math_ApproachS(&pthis->unk_31C, temp_v1, 5, 0x7D0);
}

void func_808FFBBC(BossGanon2* pthis, GlobalContext* globalCtx, u8 arg2)
{
	if(arg2 != 0 || pthis->unk_313)
	{
		f32 phi_f0;
		f32 phi_f2;

		Math_ApproachS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 5, pthis->unk_320);

		if(pthis->unk_334 != 0)
		{
			phi_f0 = 5000.0f;
			phi_f2 = 200.0f;
		}
		else
		{
			phi_f0 = 3000.0f;
			phi_f2 = 30.0f;
		}

		Math_ApproachF(&pthis->unk_320, phi_f0, 1.0f, phi_f2);
	}
	else
	{
		pthis->unk_320 = 0.0f;
	}
}

void func_808FFC84(BossGanon2* pthis)
{
	if(ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) < 0x2800)
	{
		pthis->unk_313 = true;
		pthis->actor.focus.pos = pthis->unk_1B8;
	}
	else
	{
		pthis->unk_313 = false;
		pthis->actor.focus.pos = pthis->unk_1C4;
	}
}

void func_808FFCFC(BossGanon2* pthis, GlobalContext* globalCtx)
{
	if(pthis->actor.xzDistToPlayer < 150.0f && ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) < 0x2800)
	{
		pthis->unk_311 = false;
		func_80900580(pthis, globalCtx);
		Audio_StopSfxById(NA_SE_EN_MGANON_UNARI);
	}
	else if((pthis->actor.bgCheckFlags & BG_STATE_3) && func_808FFA24(pthis, globalCtx))
	{
		pthis->unk_311 = false;
		func_80900580(pthis, globalCtx);
		Audio_StopSfxById(NA_SE_EN_MGANON_UNARI);
	}
}

void func_808FFDB0(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s32 sp28;
	s32 objectIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON2);

	if(Object_IsLoaded(&globalCtx->objectCtx, objectIdx))
	{
		gSegments[6] = PHYSICAL_TO_VIRTUAL(gObjectTable[objectIdx].vromStart.get());
		Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_00FFE4, -10.0f);
		pthis->actionFunc = func_808FFEBC;

		if(pthis->unk_334 != 0)
		{
			pthis->unk_1A2[0] = Rand_ZeroFloat(30.0f);
		}
		else
		{
			pthis->unk_1A2[0] = 40;
		}

		pthis->unk_336 = 1;
		pthis->actor.flags |= ACTOR_FLAG_0;
		pthis->unk_228 = 1.0f;
		pthis->unk_224 = 1.0f;
	}
	else
	{
		pthis->actionFunc = func_808FFDB0;
	}
}

void func_808FFEBC(BossGanon2* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_390 == 0)
	{
		pthis->unk_390 = (s16)Rand_ZeroFloat(50.0f) + 30;
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_UNARI);
	}

	SkelAnime_Update(&pthis->skelAnime);
	Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 1.0f);

	if(pthis->unk_1A2[0] == 0)
	{
		func_809002CC(pthis, globalCtx);
	}
	else if(pthis->unk_1A2[1] == 0)
	{
		func_808FFCFC(pthis, globalCtx);
	}

	func_808FFAC8(pthis, globalCtx, 0);
	func_808FFBBC(pthis, globalCtx, 0);
}

void func_808FFF90(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_00FFE4, -10.0f);
	pthis->actionFunc = func_808FFFE0;
	pthis->unk_1A2[0] = 40;
}

void func_808FFFE0(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s16 target;

	SkelAnime_Update(&pthis->skelAnime);
	Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 1.0f);

	if(pthis->unk_1A2[0] == 0)
	{
		func_809002CC(pthis, globalCtx);
	}

	if(pthis->unk_1A2[0] < 30 && pthis->unk_1A2[0] >= 10)
	{
		target = Math_SinS(pthis->unk_1A2[0] * 0x3000) * (f32)0x2000;
	}
	else
	{
		target = 0;
	}

	Math_ApproachS(&pthis->unk_31A, target, 2, 0x4000);
}

void func_809000A0(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_026510, -2.0f);
	pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_026510);
	pthis->unk_1AC = 0;
	pthis->actionFunc = func_80900104;
}

void func_80900104(BossGanon2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 1.0f);

	switch(pthis->unk_1AC)
	{
		case 0:
			if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
			{
				pthis->unk_1AC = 1;
				Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_026AF4, 0.0f);
				pthis->unk_1A2[0] = 80;
			}
			break;
		case 1:
			if(pthis->unk_1A2[0] == 0)
			{
				pthis->unk_1AC = 2;
				Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_027824, -5.0f);
				pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_027824);
			}
			break;
		case 2:
			if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
			{
				func_809002CC(pthis, globalCtx);
			}
			break;
	}
}

void func_80900210(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon2_Anim_00DFF0, -3.0f);
	pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_00DFF0);
	pthis->actionFunc = func_8090026C;
}

void func_8090026C(BossGanon2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);
	Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);

	if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
	{
		func_809002CC(pthis, globalCtx);
	}
}

void func_809002CC(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_00E8EC, -10.0f);
	pthis->actionFunc = func_80900344;
	pthis->unk_338 = 0;
	pthis->unk_1A2[0] = 100;
	pthis->unk_390 = (s16)Rand_ZeroFloat(50.0f) + 50;
}

void func_80900344(BossGanon2* pthis, GlobalContext* globalCtx)
{
	f32 phi_f0;

	if(pthis->unk_390 == 0)
	{
		pthis->unk_390 = (s16)Rand_ZeroFloat(50.0f) + 30;
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_UNARI);
	}

	Math_ApproachF(&pthis->unk_324, 255.0f, 1.0f, 10.0f);

	if(pthis->unk_338 != 0)
	{
		if(Animation_OnFrame(&pthis->skelAnime, 13.0f))
		{
			func_808FD4D4(pthis, globalCtx, 1, 3);
		}
		else if(Animation_OnFrame(&pthis->skelAnime, 28.0f))
		{
			func_808FD4D4(pthis, globalCtx, 2, 3);
		}
		if(pthis->actor.xzDistToPlayer < 200.0f)
		{
			pthis->unk_338 = 0;
			Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_00E8EC, -10.0f);
		}
		else
		{
			pthis->skelAnime.playSpeed = ((pthis->actor.xzDistToPlayer - 300.0f) * 0.005f) + 1.0f;
			if(pthis->skelAnime.playSpeed > 2.0f)
			{
				pthis->skelAnime.playSpeed = 2.0f;
			}
			if(pthis->unk_334 != 0)
			{
				pthis->skelAnime.playSpeed *= 1.5f;
			}
		}
		phi_f0 = pthis->skelAnime.playSpeed * 3.0f;
	}
	else
	{
		phi_f0 = 2.0f;
		if(pthis->actor.xzDistToPlayer >= 200.0f)
		{
			pthis->unk_338 = 1;
			Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_0353C0, -10.0f);
		}
	}

	SkelAnime_Update(&pthis->skelAnime);
	Math_ApproachF(&pthis->actor.speedXZ, phi_f0, 0.5f, 1.0f);

	if(pthis->unk_1A2[0] == 0)
	{
		func_808FFDB0(pthis, globalCtx);
	}
	else
	{
		func_808FFCFC(pthis, globalCtx);
	}

	func_808FFAC8(pthis, globalCtx, 1);
	func_808FFBBC(pthis, globalCtx, 1);
}

void func_80900580(BossGanon2* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_311 == 0)
	{
		Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon2_Anim_00ADD0, -5.0f);
		pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_00ADD0);
		pthis->unk_198 = (pthis->unk_194 - 15.0f) - 5.0f;
	}
	else
	{
		Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon2_Anim_00CAF8, -5.0f);
		pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_00CAF8);
		pthis->unk_198 = (pthis->unk_194 - 15.0f) - 5.0f;
	}

	pthis->actionFunc = func_80900650;
}

void func_80900650(BossGanon2* pthis, GlobalContext* globalCtx)
{
	SkelAnime_Update(&pthis->skelAnime);

	if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_198))
	{
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_SWORD);
		Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_ROAR);
	}

	if(pthis->unk_311 == 0)
	{
		if(((pthis->unk_198 - 4.0f) < pthis->skelAnime.curFrame) && (pthis->skelAnime.curFrame < (pthis->unk_198 + 6.0f)))
		{
			pthis->startAttack = 1;
		}
	}
	else if((((pthis->unk_198 - 4.0f) + 4.0f) < pthis->skelAnime.curFrame) && (pthis->skelAnime.curFrame < (pthis->unk_198 + 6.0f)))
	{
		pthis->startAttack = 2;
	}

	Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 1.0f);

	if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
	{
		pthis->unk_311 = 1 - pthis->unk_311;

		if((pthis->unk_311 == 1) && (pthis->actor.xzDistToPlayer < 250.0f) && pthis->unk_313)
		{
			func_80900580(pthis, globalCtx);
		}
		else
		{
			func_808FFDB0(pthis, globalCtx);
		}
	}

	func_808FFAC8(pthis, globalCtx, 0);

	if((pthis->unk_334 == 0) && (pthis->unk_311 == 0))
	{
		pthis->unk_320 = 0.0f;
	}
	else
	{
		func_808FFBBC(pthis, globalCtx, 0);
	}
}

void func_80900818(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon2_Anim_02A848, -5.0f);
	pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_02A848);
	pthis->actionFunc = func_80900890;
	pthis->unk_1AC = 0;
	pthis->unk_39C = 0;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_DEAD1);
	pthis->unk_336 = 0;
}

void func_80900890(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Vec3f sp5C;
	Vec3f sp50;
	Camera* sp4C;
	Player* player;
	Camera* temp_v0;
	Camera* temp_v0_2;
	s32 pad;
	f32 temp_f12;
	f32 temp_f2;

	sp4C = Gameplay_GetCamera(globalCtx, MAIN_CAM);
	player = GET_PLAYER(globalCtx);
	SkelAnime_Update(&pthis->skelAnime);
	pthis->timer++;
	pthis->unk_339 = 20;

	switch(pthis->unk_39C)
	{
		case 0:
			func_80064520(globalCtx, &globalCtx->csCtx);
			pthis->unk_39E = Gameplay_CreateSubCamera(globalCtx);
			Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
			Gameplay_ChangeCameraStatus(globalCtx, pthis->unk_39E, CAM_STAT_ACTIVE);
			func_8002DF54(globalCtx, &pthis->actor, 8);
			pthis->unk_39C = 1;
			pthis->unk_3A4 = sp4C->eye;
			pthis->unk_3B0 = sp4C->at;
			pthis->unk_1A2[0] = 300;
			pthis->unk_1A2[1] = 100;
			globalCtx->envCtx.unk_D8 = 0.0f;
		case 1:
			if(pthis->unk_1A2[1] == 50)
			{
				Common_PlaySfx(NA_SE_EN_MGANON_WALK);
			}
			Matrix_RotateY(((pthis->actor.shape.rot.y / (f32)0x8000) * M_PI) + 0.3f, MTXMODE_NEW);
			sp5C.x = 0.0f;
			sp5C.y = 0.0f;
			sp5C.z = 250.0f;
			Matrix_MultVec3f(&sp5C, &sp50);
			Math_ApproachF(&pthis->unk_3A4.x, pthis->actor.world.pos.x + sp50.x, 0.2f, 100.0f);
			Math_ApproachF(&pthis->unk_3A4.y, 1136.0f, 0.2f, 100.0f);
			Math_ApproachF(&pthis->unk_3A4.z, pthis->actor.world.pos.z + sp50.z, 0.2f, 100.0f);
			Math_ApproachF(&pthis->unk_3B0.x, pthis->unk_1B8.x, 0.2f, 100.0f);
			Math_ApproachF(&pthis->unk_3B0.y, pthis->unk_1B8.y, 0.2f, 100.0f);
			Math_ApproachF(&pthis->unk_3B0.z, pthis->unk_1B8.z, 0.2f, 100.0f);
			if(pthis->unk_1A2[1] == 0)
			{
				pthis->unk_39C = 2;
				pthis->unk_1A2[1] = 90;
			}
			break;
		case 2:
			pthis->unk_1A2[0] = 300;
			pthis->unk_3A4.x = sZelda->actor.world.pos.x - 100.0f;
			pthis->unk_3A4.y = sZelda->actor.world.pos.y + 30.0f;
			pthis->unk_3A4.z = (sZelda->actor.world.pos.z + 30.0f) - 60.0f;
			pthis->unk_3B0.x = sZelda->actor.world.pos.x;
			pthis->unk_3B0.y = sZelda->actor.world.pos.y + 30.0f;
			pthis->unk_3B0.z = sZelda->actor.world.pos.z - 10.0f;
			Math_ApproachZeroF(&pthis->unk_324, 1.0f, 5.0f);
			Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 1.0f / 51);
			if(pthis->unk_1A2[1] == 80)
			{
				Message_StartTextbox(globalCtx, 0x70D7, NULL);
			}
			if((pthis->unk_1A2[1] < 30) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE))
			{
				temp_v0 = Gameplay_GetCamera(globalCtx, MAIN_CAM);
				temp_v0->eye = pthis->unk_3A4;
				temp_v0->eyeNext = pthis->unk_3A4;
				temp_v0->at = pthis->unk_3B0;
				func_800C08AC(globalCtx, pthis->unk_39E, 0);
				pthis->unk_39E = 0;
				func_80064534(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 7);
				pthis->unk_39C = 3;
			}
			break;
		case 10:
			func_80064520(globalCtx, &globalCtx->csCtx);
			pthis->unk_39E = Gameplay_CreateSubCamera(globalCtx);
			Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
			Gameplay_ChangeCameraStatus(globalCtx, pthis->unk_39E, CAM_STAT_ACTIVE);
			pthis->unk_39C = 11;
			pthis->unk_334 = 1;
			func_8002DF54(globalCtx, &pthis->actor, 0x60);
			pthis->timer = 0;
		case 11:
			player->actor.world.pos.x = sZelda->actor.world.pos.x + 50.0f + 10.0f;
			player->actor.world.pos.z = sZelda->actor.world.pos.z - 25.0f;
			player->actor.shape.rot.y = -0x8000;
			pthis->unk_3A4.x = (player->actor.world.pos.x + 100.0f) - 80.0f;
			pthis->unk_3A4.y = (player->actor.world.pos.y + 60.0f) - 40.0f;
			pthis->unk_3A4.z = player->actor.world.pos.z - 110.0f;
			pthis->unk_3B0.x = player->actor.world.pos.x;
			pthis->unk_3B0.y = (player->actor.world.pos.y + 60.0f) - 25.0f;
			pthis->unk_3B0.z = player->actor.world.pos.z;
			if(pthis->timer == 80)
			{
				temp_v0_2 = Gameplay_GetCamera(globalCtx, MAIN_CAM);
				temp_v0_2->eye = pthis->unk_3A4;
				temp_v0_2->eyeNext = pthis->unk_3A4;
				temp_v0_2->at = pthis->unk_3B0;
				pthis->unk_39C = 3;
				func_800C08AC(globalCtx, pthis->unk_39E, 0);
				pthis->unk_39E = 0;
				func_80064534(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 7);
			}
			break;
	}

	if(pthis->unk_39E != 0)
	{
		Gameplay_CameraSetAtEye(globalCtx, pthis->unk_39E, &pthis->unk_3B0, &pthis->unk_3A4);
	}

	switch(pthis->unk_1AC)
	{
		case 0:
			if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
			{
				Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_034278, 0.0f);
				pthis->unk_1AC = 1;
			}
			break;
		case 1:
			if((globalCtx->gameplayFrames % 32) == 0)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_BREATH);
			}

			if((pthis->unk_1A2[0] == 0) || (pthis->unk_334 != 0))
			{
				temp_f2 = -200.0f - player->actor.world.pos.x;
				temp_f12 = -200.0f - player->actor.world.pos.z;

				if(sqrtf(SQ(temp_f2) + SQ(temp_f12)) <= 784.0f)
				{
					Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon2_Anim_0334F8, 0.0f);
					pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_0334F8);
					pthis->unk_1AC = 2;
					pthis->unk_1A2[0] = 40;
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_ROAR);
				}
			}
			break;
		case 2:
			Math_ApproachF(&pthis->unk_324, 255.0f, 1.0f, 10.0f);
			Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 2.0f / 51.0f);
			if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
			{
				func_808FFDB0(pthis, globalCtx);
				if(pthis->unk_334 == 0)
				{
					pthis->actor.colChkInfo.health = 25;
				}
				pthis->unk_336 = 1;
			}
			break;
	}

	Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 1.0f);
}

void func_80901020(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon2_Anim_02A848, -5.0f);
	pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_02A848);
	pthis->actionFunc = func_8090120C;
	pthis->unk_1AC = 0;
	pthis->unk_39C = 0;
	Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_DEAD1);
	pthis->unk_314 = 4;
}

void func_8090109C(BossGanon2* pthis, GlobalContext* globalCtx)
{
	u8 i;

	for(i = 0; i < 70; i++)
	{
		Vec3f velocity;
		Vec3f accel;
		Vec3f pos;

		velocity.x = Rand_CenteredFloat(50.0f);
		velocity.y = Rand_CenteredFloat(10.0f) + 5.0f;
		velocity.z = Rand_CenteredFloat(50.0f);
		accel.x = 0.0f;
		accel.y = -1.0f;
		accel.z = 0.0f;
		pos.x = pthis->unk_1B8.x;
		pos.y = pthis->unk_1B8.y;
		pos.z = pthis->unk_1B8.z;
		func_8002836C(globalCtx, &pos, &velocity, &accel, &sPrimColor, &sEnvColor, (s16)Rand_ZeroFloat(50.0f) + 50, 0, 17);
	}
}

void func_8090120C(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Player* player;
	f32 temp_f14;
	f32 temp_f12;
	Camera* temp_v0_2;
	s16 temp_a0_2;
	f32 phi_f0;
	s32 phi_a1;

	player = GET_PLAYER(globalCtx);
	pthis->timer++;
	SkelAnime_Update(&pthis->skelAnime);

	pthis->unk_3BC.x = 0.0f;
	pthis->unk_3BC.y = 1.0f;
	pthis->unk_3BC.z = 0.0f;

	switch(pthis->unk_39C)
	{
		case 0:
			func_80064520(globalCtx, &globalCtx->csCtx);
			pthis->unk_39E = Gameplay_CreateSubCamera(globalCtx);
			Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
			Gameplay_ChangeCameraStatus(globalCtx, pthis->unk_39E, CAM_STAT_ACTIVE);
			func_8002DF54(globalCtx, &pthis->actor, 8);
			pthis->unk_39C = 1;
			pthis->timer = 0;
			sZelda->unk_3C8 = 9;
			pthis->unk_31C = 0;
			pthis->unk_1A2[2] = 0;
			pthis->unk_336 = 0;
			pthis->unk_324 = 0.0f;
			pthis->actor.speedXZ = 0.0f;
			pthis->unk_31A = pthis->unk_31C;
			globalCtx->envCtx.unk_D8 = 0.0f;
		case 1:
			if(pthis->timer < 90)
			{
				pthis->unk_339 = 20;
				Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.1f);
			}
			else if(pthis->timer >= 90)
			{
				pthis->unk_339 = 21;
				Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.08f);
			}
			if(pthis->timer == 50)
			{
				Common_PlaySfx(NA_SE_EN_MGANON_WALK);
			}
			if(pthis->timer > 90)
			{
				Math_ApproachF(&pthis->unk_380, 0.25f, 1.0f, 0.0125f);
				pthis->unk_37C = 200.0f;
				Common_PlaySfx(NA_SE_EV_TIMETRIP_LIGHT - SFX_FLAG);
			}
			if(pthis->timer >= 110)
			{
				if(pthis->timer == 110)
				{
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_HIT_THUNDER);
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_DAMAGE);
				}
				Math_ApproachF(&pthis->unk_30C, 10.0f, 0.2f, 5.0f);
				pthis->skelAnime.playSpeed = 3.0f;
			}
			if(pthis->timer == 120)
			{
				func_8002DF54(globalCtx, &pthis->actor, 0x63);
			}
			pthis->actor.world.rot.y = 0x4000;
			pthis->actor.world.pos.x = pthis->actor.world.pos.z = 0.0f;
			player->actor.shape.rot.y = -0x4000;
			player->actor.world.pos.x = 200.0f;
			player->actor.world.pos.z = 30.0f;
			sZelda->actor.world.pos.x = 340.0f;
			sZelda->actor.world.pos.z = -250.0f;
			sZelda->actor.world.rot.y = sZelda->actor.shape.rot.y = -0x2000;
			pthis->unk_3A4.x = 250;
			pthis->unk_3A4.y = 1150.0f;
			pthis->unk_3A4.z = 0.0f;
			pthis->unk_3B0.x = pthis->unk_1B8.x;
			pthis->unk_3B0.y = pthis->unk_1B8.y;
			pthis->unk_3B0.z = pthis->unk_1B8.z;
			if(pthis->timer > 135)
			{
				pthis->unk_39C = 2;
				pthis->timer = 0;
			}
			break;
		case 2:
			pthis->unk_339 = 22;
			Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.1f);
			Common_PlaySfx(NA_SE_EV_TIMETRIP_LIGHT - SFX_FLAG);
			pthis->unk_3A4.x = 250;
			pthis->unk_3A4.y = 1150.0f;
			pthis->unk_3A4.z = 0.0f;
			Math_ApproachF(&pthis->unk_3B0.x, sZelda->actor.world.pos.x, 0.2f, 20.0f);
			Math_ApproachF(&pthis->unk_3B0.y, sZelda->actor.world.pos.y + 50.0f, 0.2f, 10.0f);
			Math_ApproachF(&pthis->unk_3B0.z, sZelda->actor.world.pos.z, 0.2f, 20.0f);
			if(pthis->timer == 50)
			{
				pthis->unk_39C = 3;
				pthis->timer = 0;
			}
			break;
		case 3:
			pthis->unk_339 = 22;
			Common_PlaySfx(NA_SE_EV_TIMETRIP_LIGHT - SFX_FLAG);
			pthis->unk_3A4.x = 330.0f;
			pthis->unk_3A4.y = 1120.0f;
			pthis->unk_3A4.z = -150.0f;
			pthis->unk_3B0.x = sZelda->actor.world.pos.x;
			pthis->unk_3B0.y = sZelda->actor.world.pos.y + 40.0f;
			pthis->unk_3B0.z = sZelda->actor.world.pos.z;
			if(pthis->timer == 10)
			{
				Message_StartTextbox(globalCtx, 0x70D8, NULL);
			}
			if((pthis->timer > 80) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE))
			{
				pthis->unk_39C = 4;
				pthis->timer = 0;
			}
			break;
		case 4:
			if(pthis->timer > 10)
			{
				Math_ApproachZeroF(&pthis->unk_37C, 1.0f, 10.0f);
				if(pthis->timer == 30)
				{
					sZelda->unk_3C8 = 10;
				}
				pthis->unk_339 = 23;
				Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
			}
			else
			{
				pthis->unk_339 = 22;
			}
			if(pthis->timer == 100)
			{
				pthis->unk_39C = 5;
				pthis->timer = 40;
				pthis->skelAnime.playSpeed = 1.0f;
				func_8002DF54(globalCtx, &pthis->actor, 0x64);
			}
			break;
		case 5:
			pthis->unk_339 = 23;
			if((pthis->timer >= 60) && (pthis->timer <= 90))
			{
				if(pthis->timer == 62)
				{
					Common_PlaySfx(NA_SE_EV_TRIFORCE_FLASH);
				}
				Math_ApproachF(&pthis->unk_38C, 200.0f, 1.0f, 8.0f);
			}
			else
			{
				Math_ApproachZeroF(&pthis->unk_38C, 1.0f, 8.0f);
			}
			if(pthis->timer == 70)
			{
				func_8002DF54(globalCtx, &pthis->actor, 0x65);
			}
			if(pthis->timer == 150)
			{
				func_8002DF54(globalCtx, &pthis->actor, 0x66);
			}
			pthis->unk_30C = 10.0f;
			player->actor.world.pos.x = 250.0f;
			player->actor.world.pos.z = 30.0f;
			pthis->unk_3A4.x = player->actor.world.pos.x - 50.0f;
			pthis->unk_3A4.y = player->actor.world.pos.y + 50.0f;
			pthis->unk_3A4.z = player->actor.world.pos.z + 40.0f;
			pthis->unk_3B0.x = player->actor.world.pos.x;
			pthis->unk_3B0.y = player->actor.world.pos.y + 40.0f;
			pthis->unk_3B0.z = player->actor.world.pos.z;
			if(pthis->timer == 166)
			{
				temp_v0_2 = Gameplay_GetCamera(globalCtx, MAIN_CAM);
				temp_v0_2->eye = pthis->unk_3A4;
				temp_v0_2->eyeNext = pthis->unk_3A4;
				temp_v0_2->at = pthis->unk_3B0;
				func_800C08AC(globalCtx, pthis->unk_39E, 0);
				pthis->unk_39E = 0;
				func_80064534(globalCtx, &globalCtx->csCtx);
				func_8002DF54(globalCtx, &pthis->actor, 7);
				pthis->unk_39C = 6;
			}
			break;
		case 6:
			pthis->unk_339 = 23;
			temp_f14 = pthis->unk_1B8.x - player->actor.world.pos.x;
			temp_f12 = pthis->unk_1B8.z - player->actor.world.pos.z;
			temp_a0_2 = Math_Atan2S(temp_f12, temp_f14) - player->actor.shape.rot.y;
			if((ABS(temp_a0_2) < 0x2000) && (sqrtf(SQ(temp_f14) + SQ(temp_f12)) < 70.0f) && (player->swordState != 0) && (player->heldItemActionParam == PLAYER_AP_SWORD_MASTER))
			{
				func_80064520(globalCtx, &globalCtx->csCtx);
				pthis->unk_39E = Gameplay_CreateSubCamera(globalCtx);
				Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
				Gameplay_ChangeCameraStatus(globalCtx, pthis->unk_39E, CAM_STAT_ACTIVE);
				pthis->unk_39C = 7;
				pthis->timer = 0;
				Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon2_Anim_003B1C, 0.0f);
				pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_003B1C);
				globalCtx->startPlayerCutscene(globalCtx, &pthis->actor, 0x61);
			}
			else
			{
				break;
			}
		case 7:
			pthis->unk_339 = 23;
			Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.2f);
			player->actor.world.pos.x = 250.0f;
			player->actor.shape.rot.y = -0x4000;
			player->actor.world.pos.z = 30.0f;
			if((pthis->timer == 20) || (pthis->timer == 30) || (pthis->timer == 65) || (pthis->timer == 40))
			{
				Common_PlaySfx(NA_SE_VO_LI_SWORD_N);
				Common_PlaySfx(NA_SE_IT_SWORD_SWING_HARD);
			}
			if((pthis->timer == 22) || (pthis->timer == 35) || (pthis->timer == 72) || (pthis->timer == 45))
			{
				Common_PlaySfx(NA_SE_EN_MGANON_DAMAGE);
				Common_PlaySfx(NA_SE_IT_SHIELD_BOUND);
				globalCtx->envCtx.unk_D8 = 1.0f;
			}
			if((pthis->timer == 22) || (pthis->timer == 35) || (pthis->timer == 72) || (pthis->timer == 45))
			{
				func_8090109C(pthis, globalCtx);
			}
			if((pthis->timer >= 34) && (pthis->timer < 40))
			{
				pthis->unk_3A4.x = 269.0f;
				pthis->unk_3A4.y = 1112.0f;
				pthis->unk_3A4.z = -28.0f;
				pthis->unk_3B0.x = 234.0f;
				pthis->unk_3B0.y = 1117.0f;
				pthis->unk_3B0.z = -11.0f;
			}
			else
			{
				if(pthis->timer < 30)
				{
					phi_a1 = 0;
				}
				else if(pthis->timer < 43)
				{
					phi_a1 = 1;
				}
				else
				{
					pthis->unk_3BC.z = -0.8f;
					player->actor.world.pos.x = 200.0f;
					player->actor.world.pos.z = 10.0f;
					phi_a1 = 2;
				}
				pthis->unk_3A4.x = D_8090702C[phi_a1].x + (player->actor.world.pos.x - 50.0f);
				pthis->unk_3A4.y = D_8090702C[phi_a1].y + (player->actor.world.pos.y + 50.0f);
				pthis->unk_3A4.z = D_8090702C[phi_a1].z + (player->actor.world.pos.z + 40.0f);
				pthis->unk_3B0.x = D_80907050[phi_a1].x + player->actor.world.pos.x;
				pthis->unk_3B0.y = D_80907050[phi_a1].y + (player->actor.world.pos.y + 40.0f);
				pthis->unk_3B0.z = D_80907050[phi_a1].z + player->actor.world.pos.z;
			}
			if(pthis->timer > 80)
			{
				Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x100FF);
				pthis->unk_39C = 75;
				pthis->timer = 0;
				pthis->unk_3A4.x = 112.0f;
				pthis->unk_3A4.y = 1146.0f;
				pthis->unk_3A4.z = 202.0f;
				pthis->unk_3B0.x = 110.0f;
				pthis->unk_3B0.y = 1144.0f;
				pthis->unk_3B0.z = 177.0f;
				player->actor.world.pos.x = 200.0f;
				pthis->unk_3BC.z = 0.0f;
			}
			break;
		case 75:
			pthis->unk_339 = 23;
			if(pthis->timer == 55)
			{
				Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon2_Anim_007288, 0.0f);
				pthis->unk_194 = Animation_GetLastFrame(&object_ganon2_Anim_007288);
				func_8002DF54(globalCtx, &pthis->actor, 0x62);
				pthis->unk_39C = 8;
				pthis->timer = 1000;
			}
			break;
		case 8:
			if(pthis->timer == 1025)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_STAND);
			}
			if(pthis->timer >= 1000)
			{
				if(pthis->timer < 1040)
				{
					pthis->unk_339 = 23;
					Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.2f);
				}
			}
			if(pthis->timer == 1040)
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_DEAD2);
				pthis->unk_336 = 2;
				pthis->unk_339 = 0;
				globalCtx->envCtx.unk_BE = 0;
				globalCtx->envCtx.unk_D8 = 0.0f;
			}
			if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
			{
				Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon2_Anim_008EB8, 0.0f);
				pthis->timer = 0;
				pthis->unk_194 = 1000.0f;
			}
			pthis->unk_3A4.x = 250;
			pthis->unk_3A4.y = 1150.0f;
			pthis->unk_3A4.z = 0.0f;
			pthis->unk_3B0.x = pthis->unk_1B8.x;
			pthis->unk_3B0.y = pthis->unk_1B8.y;
			pthis->unk_3B0.z = pthis->unk_1B8.z;
			if((pthis->timer < 1000) && ((pthis->timer % 16) == 0))
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_SWORD);
			}
			if(pthis->timer == 40)
			{
				pthis->unk_39C = 9;
				pthis->timer = 0;
				sZelda->unk_3C8 = 11;
				Message_StartTextbox(globalCtx, 0x70D9, NULL);
				pthis->unk_336 = 0;
				globalCtx->envCtx.unk_D8 = 0.0f;
			}
			break;
		case 9:
			pthis->unk_339 = 24;
			pthis->unk_3A4.x = 330.0f;
			pthis->unk_3A4.y = 1120.0f;
			pthis->unk_3A4.z = -150.0f;
			pthis->unk_3B0.x = sZelda->actor.world.pos.x;
			pthis->unk_3B0.y = sZelda->actor.world.pos.y + 40.0f;
			pthis->unk_3B0.z = sZelda->actor.world.pos.z;
			if(pthis->timer > 60)
			{
				pthis->unk_39C = 10;
				pthis->timer = 0;
				pthis->unk_410.x = 0.0f;
			}
			break;
		case 10:
			pthis->unk_339 = 24;
			Math_ApproachF(&pthis->unk_3A4.x, 290.0f, 0.05f, pthis->unk_410.x);
			Math_ApproachF(&pthis->unk_3A4.y, 1130.0f, 0.05f, pthis->unk_410.x * 0.25f);
			Math_ApproachF(&pthis->unk_3A4.z, -260.0f, 0.05f, pthis->unk_410.x * 1.25f);
			if((pthis->timer >= 40) && (pthis->timer <= 110))
			{
				Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.02f);
				Math_ApproachF(&pthis->unk_384, 10.0f, 0.1f, 0.2f);
				Audio_PlayActorSound2(&sZelda->actor, NA_SE_EV_GOD_LIGHTBALL_2 - SFX_FLAG);
			}
			else
			{
				Math_ApproachZeroF(&pthis->unk_384, 1.0f, 0.2f);
			}
			if(pthis->timer > 130)
			{
				Math_ApproachF(&pthis->unk_3B0.y, (sZelda->actor.world.pos.y + 40.0f + 10.0f) - 20.0f, 0.1f, pthis->unk_410.x);
			}
			else
			{
				Math_ApproachF(&pthis->unk_3B0.y, sZelda->actor.world.pos.y + 40.0f + 10.0f, 0.05f, pthis->unk_410.x * 0.25f);
			}
			Math_ApproachF(&pthis->unk_410.x, 1.0f, 1.0f, 0.01f);
			if(pthis->timer == 10)
			{
				sZelda->unk_3C8 = 12;
			}
			if(pthis->timer == 110)
			{
				sZelda->unk_3C8 = 13;
			}
			if(pthis->timer == 140)
			{
				Audio_PlayActorSound2(&sZelda->actor, NA_SE_EV_HUMAN_BOUND);
			}
			if(pthis->timer < 160)
			{
				break;
			}
		case 20:
			globalCtx->nextEntranceIndex = 0x6B;
			gSaveContext.nextCutsceneIndex = 0xFFF2;
			globalCtx->sceneLoadFlag = 0x14;
			globalCtx->fadeTransition = 3;
			globalCtx->linkAgeOnLoad = 1;
			break;
	}

	if(pthis->unk_39E != 0)
	{
		Gameplay_CameraSetAtEyeUp(globalCtx, pthis->unk_39E, &pthis->unk_3B0, &pthis->unk_3A4, &pthis->unk_3BC);
	}

	switch(pthis->unk_1AC)
	{
		case 0:
			if(Animation_OnFrame(&pthis->skelAnime, pthis->unk_194))
			{
				Animation_MorphToLoop(&pthis->skelAnime, &object_ganon2_Anim_034278, 0.0f);
				pthis->unk_1AC = 1;
			}
			break;
		case 1:
			if((pthis->unk_39C < 7) && ((globalCtx->gameplayFrames % 32) == 0))
			{
				Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_BREATH);
			}
			break;
	}
}

void func_80902348(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Player* player;
	f32 temp_f2;
	f32 temp_f12;
	s16 i;
	s16 j;
	s16 phi_v0_2;

	if(pthis->unk_316 == 0)
	{
		for(i = 0; i < ARRAY_COUNT(pthis->unk_864); i++)
		{
			if(pthis->unk_444.elements[i].info.bumperFlags & 2)
			{
				pthis->unk_444.elements[i].info.bumperFlags &= ~2;
			}
			else if(pthis->unk_444.elements[i].info.toucherFlags & 2)
			{
				pthis->unk_444.elements[i].info.toucherFlags &= ~2;

				if(pthis->startAttack == 1)
				{
					phi_v0_2 = 0x1800;
				}
				else
				{
					phi_v0_2 = 0;
				}

				func_8002F6D4(globalCtx, &pthis->actor, 15.0f, pthis->actor.yawTowardsPlayer + phi_v0_2, 2.0f, 0);
				sZelda->unk_3C8 = 8;
				pthis->unk_316 = 10;
				break;
			}
		}
	}

	if(pthis->unk_324 > 0.0f)
	{
		player = GET_PLAYER(globalCtx);
		temp_f2 = -200.0f - player->actor.world.pos.x;
		temp_f12 = -200.0f - player->actor.world.pos.z;

		if(sqrtf(SQ(temp_f2) + SQ(temp_f12)) > 784.0f)
		{
			for(j = 0; j < ARRAY_COUNT(player->flameTimers); j++)
			{
				player->flameTimers[j] = Rand_S16Offset(0, 200);
			}

			player->isBurning = true;
			func_8002F6D4(globalCtx, &pthis->actor, 10.0f, Math_Atan2S(temp_f12, temp_f2), 0.0f, 0x10);
			sZelda->unk_3C8 = 8;
		}
	}
}

void func_80902524(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s8 temp_v0_4;
	ColliderInfo* acHitInfo;
	s16 i;
	u8 phi_v1_2;

	osSyncPrintf("pthis->no_hit_time %d\n", pthis->unk_316);
	if(pthis->unk_316 != 0 || ((pthis->unk_334 == 0) && (pthis->actionFunc == func_80900890)))
	{
		for(i = 0; i < ARRAY_COUNT(pthis->unk_464); i++)
		{
			pthis->unk_424.elements[i].info.bumperFlags &= ~2;
		}
	}

	osSyncPrintf("pthis->look_on %d\n", pthis->unk_313);
	if(pthis->unk_313)
	{
		if(pthis->actionFunc != func_808FFFE0)
		{
			if(pthis->unk_424.elements[0].info.bumperFlags & 2)
			{
				pthis->unk_424.elements[0].info.bumperFlags &= ~2;
				acHitInfo = pthis->unk_424.elements[0].info.acHitInfo;
				if((acHitInfo->toucher.dmgFlags & 0x2000) && (pthis->actionFunc != func_80900890))
				{
					func_809000A0(pthis, globalCtx);
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_HIT_THUNDER);
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_DAMAGE);
					Audio_StopSfxById(NA_SE_EN_MGANON_UNARI);
				}
				else if((pthis->actionFunc == func_80900890) && (acHitInfo->toucher.dmgFlags & 0x9000200))
				{
					pthis->unk_316 = 60;
					pthis->unk_342 = 5;
					Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_DAMAGE);
					Audio_StopSfxById(NA_SE_EN_MGANON_UNARI);
					pthis->actor.colChkInfo.health -= 2;
					temp_v0_4 = pthis->actor.colChkInfo.health;
					if(temp_v0_4 < 0x15 && pthis->unk_334 == 0)
					{
						func_80900818(pthis, globalCtx);
					}
					else
					{
						if(temp_v0_4 <= 0)
						{
							func_80901020(pthis, globalCtx);
						}
						else
						{
							func_80900210(pthis, globalCtx);
						}
					}
				}
				else if(pthis->actionFunc != func_80900890)
				{
					func_808FFF90(pthis, globalCtx);
					Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_HOOKSHOT_REFLECT);
				}
			}
		}
	}
	else
	{
		if(pthis->unk_424.elements[15].info.bumperFlags & 2)
		{
			pthis->unk_424.elements[15].info.bumperFlags &= ~2;
			acHitInfo = pthis->unk_424.elements[15].info.acHitInfo;
			pthis->unk_316 = 60;
			pthis->unk_344 = 0x32;
			pthis->unk_342 = 5;
			Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MGANON_DAMAGE);
			Audio_StopSfxById(NA_SE_EN_MGANON_UNARI);
			phi_v1_2 = 1;
			if(acHitInfo->toucher.dmgFlags & 0x9000200)
			{
				if(acHitInfo->toucher.dmgFlags & 0x8000000)
				{
					phi_v1_2 = 4;
				}
				else
				{
					phi_v1_2 = 2;
				}
			}
			pthis->actor.colChkInfo.health -= phi_v1_2;
			temp_v0_4 = pthis->actor.colChkInfo.health;
			if((temp_v0_4 < 0x15) && (pthis->unk_334 == 0))
			{
				func_80900818(pthis, globalCtx);
			}
			else if((temp_v0_4 <= 0) && (phi_v1_2 >= 2))
			{
				func_80901020(pthis, globalCtx);
			}
			else
			{
				if(temp_v0_4 <= 0)
				{
					pthis->actor.colChkInfo.health = 1;
				}
				func_80900210(pthis, globalCtx);
			}
		}
	}
}

void BossGanon2_Update(Actor* thisx, GlobalContext* globalCtx)
{
	BossGanon2* pthis = (BossGanon2*)thisx;
	s32 pad;
	s16 i;
	f32 phi_f2;
	u16 i2;
	Vec3f sp58;
	Vec3f sp4C;
	f32 angle;
	f32 sp44;

	if((pthis->unk_337 == 0) || (pthis->unk_337 == 2))
	{
		BossGanon2_SetObjectSegment(pthis, globalCtx, OBJECT_GANON_ANIME3, false);
	}
	else
	{
		BossGanon2_SetObjectSegment(pthis, globalCtx, OBJECT_GANON2, false);
		Math_ApproachZeroF(&pthis->unk_30C, 1.0f, 0.5f);
	}
	func_808FFC84(pthis);
	pthis->startAttack = 0;
	pthis->unk_19C++;
	Actor_SetScale(&pthis->actor, 0.01f);
	pthis->actionFunc(pthis, globalCtx);
	for(i = 0; i < ARRAY_COUNT(pthis->unk_1A2); i++)
	{
		if(pthis->unk_1A2[i] != 0)
		{
			pthis->unk_1A2[i]--;
		}
	}
	if(pthis->unk_316 != 0)
	{
		pthis->unk_316--;
	}
	if(pthis->unk_342 != 0)
	{
		pthis->unk_342--;
	}
	if(pthis->unk_390 != 0)
	{
		pthis->unk_390--;
	}
	if(pthis->unk_392 != 0)
	{
		pthis->unk_392--;
	}
	Actor_MoveForward(&pthis->actor);
	pthis->actor.shape.rot = pthis->actor.world.rot;
	if(pthis->unk_335 != 0)
	{
		Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 60.0f, 60.0f, 100.0f, 5);
		if(pthis->actor.bgCheckFlags & BG_STATE_0)
		{
			if(pthis->actor.velocity.y < -5.0f)
			{
				func_80033E88(&pthis->actor, globalCtx, 5, 20);
				Common_PlaySfx(NA_SE_IT_BOMB_EXPLOSION);
			}
			pthis->actor.velocity.y = 0.0f;
		}
	}
	if(((pthis->unk_19C & 0x1F) == 0) && (Rand_ZeroOne() < 0.3f))
	{
		pthis->unk_318 = 4;
	}
	pthis->unk_310 = D_80907074[pthis->unk_318];
	if(pthis->unk_318 != 0)
	{
		pthis->unk_318--;
	}
	pthis->unk_1B0 = (Math_SinS(pthis->unk_19C * 0x2AAA) * 64.0f) + 191.0f;
	if(pthis->unk_344 != 0)
	{
		pthis->unk_344--;
		Math_ApproachF(&pthis->unk_360.x, 5000.0f, 0.5f, 3000.0f);
		Math_ApproachF(&pthis->unk_370.x, 5500.0f, 0.5f, 3000.0f);
		Math_ApproachF(&pthis->unk_360.z, 8000.0f, 0.1f, 4000.0f);
		Math_ApproachF(&pthis->unk_370.z, 8000.0f, 0.1f, 4000.0f);
		Math_ApproachS(&pthis->unk_346, 0xFA0, 0xA, 0x7D0);
	}
	else
	{
		pthis->unk_360.y = 14000.0f;
		Math_ApproachF(&pthis->unk_360.x, 2000.0f, 0.1f, 100.0f);
		pthis->unk_370.y = 12000.0f;
		Math_ApproachF(&pthis->unk_370.x, 1500.0f, 0.1f, 100.0f);
		if((pthis->actionFunc == func_808FFEBC) || (pthis->actionFunc == func_808FFFE0) || (pthis->actionFunc == func_80900104))
		{
			Math_ApproachF(&pthis->unk_360.z, 1000.0f, 0.1f, 100.0f);
			Math_ApproachF(&pthis->unk_370.z, 1000.0f, 0.1f, 100.0f);
			Math_ApproachS(&pthis->unk_346, -0xFA0, 0xA, 0x64);
		}
		else
		{
			Math_ApproachF(&pthis->unk_360.z, 5000.0f, 0.1f, 200.0f);
			Math_ApproachF(&pthis->unk_370.z, 5000.0f, 0.1f, 200.0f);
			Math_ApproachS(&pthis->unk_346, 0, 0xA, 0x64);
		}
	}
	if(pthis->unk_39C != 75)
	{
		pthis->unk_35C += pthis->unk_360.x;
		pthis->unk_36C += pthis->unk_370.x;
	}
	if(pthis->unk_337 == 2)
	{
		pthis->unk_370.z = 0.0f;
		pthis->unk_360.z = 0.0f;
	}

	for(i = 0; i < ARRAY_COUNT(pthis->unk_348); i++)
	{
		if(i == 0)
		{
			phi_f2 = 0.2f;
		}
		else if(i == 1)
		{
			phi_f2 = 0.5f;
		}
		else
		{
			phi_f2 = 1.0f;
		}

		pthis->unk_348[i] = Math_SinS(((s16)pthis->unk_35C + (i * (s16)pthis->unk_360.y))) * phi_f2 * pthis->unk_360.z;
		pthis->unk_352[i] = Math_SinS(((s16)pthis->unk_36C + (i * (s16)pthis->unk_370.y))) * phi_f2 * pthis->unk_370.z;
	}

	BossGanon2_SpawnRubble(pthis, globalCtx);
	func_80902348(pthis, globalCtx);
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->unk_424.base);
	if(pthis->actionFunc != func_8090120C)
	{
		func_80902524(pthis, globalCtx);
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->unk_424.base);
		CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->unk_444.base);
		CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->unk_444.base);
		if(pthis->unk_39E == 0)
		{
			CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->unk_444.base);
		}
	}
	if((pthis->unk_332 == 0) && (pthis->unk_336 != 0))
	{
		if(pthis->unk_336 == 2)
		{
			pthis->unk_332 = (s16)Rand_ZeroFloat(30.0f) + 8;
		}
		else
		{
			pthis->unk_332 = (s16)Rand_ZeroFloat(60.0f) + 0xA;
		}
		pthis->unk_339 = 0;
		globalCtx->envCtx.unk_BE = 0;
		globalCtx->envCtx.unk_BD = (s8)Rand_ZeroFloat(1.9f) + 1;
		globalCtx->envCtx.unk_D8 = 1.0f;
		D_8090EB20.y = 0.0f;
		D_8090EB20.x = D_8090EB20.y;
		D_8090EB20.z = D_8090EB20.x;
		if(Rand_ZeroOne() < 0.5f)
		{
			D_8090EB20.z = Rand_ZeroFloat(1000.0f);
		}
		Common_PlaySfxAtPos(&D_8090EB20, NA_SE_EV_LIGHTNING);
		pthis->unk_328 = 0xFF;
		pthis->unk_330 = 5;
		pthis->unk_32C = 0.0f;
		pthis->unk_340 = (s16)Rand_ZeroFloat(10000.0f);
	}
	else if(pthis->unk_332 != 0)
	{
		pthis->unk_332--;
	}
	if((globalCtx->envCtx.unk_D8 > 0.0f) && (pthis->unk_336 != 0))
	{
		globalCtx->envCtx.customSkyboxFilter = 1;
		globalCtx->envCtx.skyboxFilterColor[0] = 255;
		globalCtx->envCtx.skyboxFilterColor[1] = 255;
		globalCtx->envCtx.skyboxFilterColor[2] = 255;
		globalCtx->envCtx.skyboxFilterColor[3] = (s16)(globalCtx->envCtx.unk_D8 * 200.0f);
	}
	else
	{
		globalCtx->envCtx.customSkyboxFilter = 0;
	}
	globalCtx->envCtx.unk_BF = 0;
	globalCtx->envCtx.unk_DC = 2;

	switch(pthis->unk_339)
	{
		case 0:
			Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.1f);
			break;
		case 3:
			globalCtx->envCtx.unk_BE = 3;
			globalCtx->envCtx.unk_BD = 4;
			Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.0125f);
			break;
		case 4:
			globalCtx->envCtx.unk_BE = 5;
			globalCtx->envCtx.unk_BD = 6;
			Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.0125f);
			break;
		case 5:
			globalCtx->envCtx.unk_BE = 6;
			globalCtx->envCtx.unk_BD = 7;
			Math_ApproachF(&pthis->unk_33C, 0.69f, 1.0f, 0.05f);
			globalCtx->envCtx.unk_D8 = (Math_SinS(globalCtx->gameplayFrames * 0x5000) * 0.15f) + (0.15f + pthis->unk_33C);
			break;
		case 55:
			globalCtx->envCtx.unk_BE = 2;
			globalCtx->envCtx.unk_BD = 0;
			Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
			break;
		case 6:
			globalCtx->envCtx.unk_BE = 2;
			globalCtx->envCtx.unk_BD = 8;
			Math_ApproachF(&pthis->unk_33C, 0.69f, 1.0f, 0.05f);
			globalCtx->envCtx.unk_D8 = (Math_SinS(globalCtx->gameplayFrames * 0x7000) * 0.15f) + (0.15f + pthis->unk_33C);
			break;
		case 7:
			globalCtx->envCtx.unk_BE = 0;
			globalCtx->envCtx.unk_BD = 8;
			Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.02f);
			break;
		case 20:
			globalCtx->envCtx.unk_BE = 0;
			globalCtx->envCtx.unk_BD = 9;
			break;
		case 21:
			globalCtx->envCtx.unk_BE = 0xA;
			globalCtx->envCtx.unk_BD = 9;
			break;
		case 22:
			globalCtx->envCtx.unk_BE = 0xA;
			globalCtx->envCtx.unk_BD = 0xB;
			break;
		case 23:
			globalCtx->envCtx.unk_BE = 9;
			globalCtx->envCtx.unk_BD = 0xB;
			break;
		case 24:
			globalCtx->envCtx.unk_BE = 0;
			globalCtx->envCtx.unk_BD = 0xC;
			break;
		case -1:
			break;
	}

	if(pthis->unk_339 >= 0)
	{
		pthis->unk_339 = 0;
	}
	if(D_80906D78 != 0)
	{
		D_80906D78 = 0;

		for(i2 = 0; i2 < ARRAY_COUNT(sParticles); i2++)
		{
			angle = Rand_ZeroFloat(2 * M_PI);
			sp44 = Rand_ZeroFloat(40.0f) + 10.0f;
			sp58 = pthis->actor.world.pos;
			sp58.y = 1200.0f;
			sp4C.x = cosf(angle) * sp44;
			sp4C.z = sinf(angle) * sp44;
			sp4C.y = Rand_ZeroFloat(15.0f) + 15.0f;
			sp58.x += sp4C.x * 10.0f * 0.1f;
			sp58.z += sp4C.z * 10.0f * 0.1f;
			func_808FD27C(globalCtx, &sp58, &sp4C, Rand_ZeroFloat(0.3f) + 0.2f);
		}
	}
	pthis->unk_388 += 0.15f;
	BossGanon2_UpdateSpecialEffects(pthis, globalCtx);
}

void Boss_Ganon2_UpdateAttack(Vec3f* arg0, Vec3f* arg1)
{
	Vtx* vtx;
	Vec3f sp2D0;
	s16 temp_s1;
	s16 temp_a1;
	s16 sp2CA;
	s16 sp2C8;
	s16 i;
	u8 phi_s2;
	u8 temp_s4;
	u8 temp_s4_2;
	f32 temp_f12;
	Vec3f temp_f20;
	Vec3f temp_f2;
	Vec3f temp_f22;
	f32 sp294;
	f32 phi_f30;
	f32 temp_f28;
	f32 temp_f26;
	s32 pad[3];
	Vec3f sp18C[20];
	Vec3f sp9C[20];

	for(i = 0; i < 20; i++)
	{
		sp18C[i] = *arg0;
		sp9C[i] = *arg1;
	}

	temp_s4 = 0;

	D_809105D8[3] = D_809105D8[2];
	D_809105D8[2] = D_809105D8[1];
	D_809105D8[1] = D_809105D8[0];
	D_809105D8[0] = *arg0;

	sp2D0 = D_809105D8[0];

	temp_f20.x = D_809105D8[1].x - sp2D0.x;
	temp_f20.y = D_809105D8[1].y - sp2D0.y;
	temp_f20.z = D_809105D8[1].z - sp2D0.z;

	sp2CA = Math_Atan2S(temp_f20.z, temp_f20.x);
	sp2C8 = Math_Atan2S(sqrtf(SQXZ(temp_f20)), temp_f20.y);

	temp_f2.x = D_809105D8[2].x - D_809105D8[1].x;
	temp_f2.y = D_809105D8[2].y - D_809105D8[1].y;
	temp_f2.z = D_809105D8[2].z - D_809105D8[1].z;

	temp_f22.x = D_809105D8[3].x - D_809105D8[2].x;
	temp_f22.y = D_809105D8[3].y - D_809105D8[2].y;
	temp_f22.z = D_809105D8[3].z - D_809105D8[2].z;

	temp_f12 = sqrtf(SQXYZ(temp_f20)) + sqrtf(SQXYZ(temp_f2)) + sqrtf(SQXYZ(temp_f22));
	if(temp_f12 <= 1.0f)
	{
		temp_f12 = 1.0f;
	}

	temp_f28 = temp_f12 * 0.083f;
	phi_f30 = sqrtf(SQXYZ(temp_f20)) / 2.0f;
	sp294 = sqrtf(SQXYZ(temp_f2)) / 2.0f;

	phi_s2 = 1;

	while(true)
	{
		temp_f20.x = D_809105D8[phi_s2].x - sp2D0.x;
		temp_f20.y = D_809105D8[phi_s2].y - sp2D0.y;
		temp_f20.z = D_809105D8[phi_s2].z - sp2D0.z;

		temp_s1 = Math_Atan2S(temp_f20.z, temp_f20.x);
		temp_a1 = Math_Atan2S(sqrtf(SQXZ(temp_f20)), temp_f20.y);

		Math_ApproachS(&sp2C8, temp_a1, 1, 0x1000);
		Math_ApproachS(&sp2CA, temp_s1, 1, 0x1000);

		temp_f26 = temp_f28 * Math_CosS(sp2C8);

		sp18C[temp_s4] = sp2D0;

		sp2D0.x += temp_f26 * Math_SinS(sp2CA);
		sp2D0.y += temp_f28 * Math_SinS(sp2C8);
		sp2D0.z += temp_f26 * Math_CosS(sp2CA);

		temp_f20.x = D_809105D8[phi_s2].x - sp2D0.x;
		temp_f20.y = D_809105D8[phi_s2].y - sp2D0.y;
		temp_f20.z = D_809105D8[phi_s2].z - sp2D0.z;

		if(phi_s2 < 3)
		{
			if(sqrtf(SQXYZ(temp_f20)) <= phi_f30)
			{
				phi_f30 = sp294;
				phi_s2++;
			}
		}
		else
		{
			if(sqrtf(SQXYZ(temp_f20)) <= (temp_f28 + 1.0f))
			{
				phi_s2++;
			}
		}

		temp_s4++;

		if((temp_s4 >= 20) || (phi_s2 >= 4))
		{
			break;
		}
	}

	temp_s4_2 = 0;

	D_80910608[3] = D_80910608[2];
	D_80910608[2] = D_80910608[1];
	D_80910608[1] = D_80910608[0];
	D_80910608[0] = *arg1;

	sp2D0 = D_80910608[0];

	temp_f20.x = D_80910608[1].x - sp2D0.x;
	temp_f20.y = D_80910608[1].y - sp2D0.y;
	temp_f20.z = D_80910608[1].z - sp2D0.z;

	sp2CA = Math_Atan2S(temp_f20.z, temp_f20.x);
	sp2C8 = Math_Atan2S(sqrtf(SQXZ(temp_f20)), temp_f20.y);

	temp_f2.x = D_80910608[2].x - D_80910608[1].x;
	temp_f2.y = D_80910608[2].y - D_80910608[1].y;
	temp_f2.z = D_80910608[2].z - D_80910608[1].z;

	temp_f22.x = D_80910608[3].x - D_80910608[2].x;
	temp_f22.y = D_80910608[3].y - D_80910608[2].y;
	temp_f22.z = D_80910608[3].z - D_80910608[2].z;

	temp_f12 = sqrtf(SQXYZ(temp_f20)) + sqrtf(SQXYZ(temp_f2)) + sqrtf(SQXYZ(temp_f22));
	if(temp_f12 <= 1.0f)
	{
		temp_f12 = 1.0f;
	}

	temp_f28 = temp_f12 * 0.083f;
	phi_f30 = sqrtf(SQXYZ(temp_f20)) / 2.0f;
	sp294 = sqrtf(SQXYZ(temp_f2)) / 2.0f;

	phi_s2 = 1;

	while(true)
	{
		temp_f20.x = D_80910608[phi_s2].x - sp2D0.x;
		temp_f20.y = D_80910608[phi_s2].y - sp2D0.y;
		temp_f20.z = D_80910608[phi_s2].z - sp2D0.z;

		temp_s1 = Math_Atan2S(temp_f20.z, temp_f20.x);
		temp_a1 = Math_Atan2S(sqrtf(SQXZ(temp_f20)), temp_f20.y);

		Math_ApproachS(&sp2C8, temp_a1, 1, 0x1000);
		Math_ApproachS(&sp2CA, temp_s1, 1, 0x1000);

		temp_f26 = temp_f28 * Math_CosS(sp2C8);

		sp9C[temp_s4_2] = sp2D0;

		sp2D0.x += temp_f26 * Math_SinS(sp2CA);
		sp2D0.y += temp_f28 * Math_SinS(sp2C8);
		sp2D0.z += temp_f26 * Math_CosS(sp2CA);

		temp_f20.x = D_80910608[phi_s2].x - sp2D0.x;
		temp_f20.y = D_80910608[phi_s2].y - sp2D0.y;
		temp_f20.z = D_80910608[phi_s2].z - sp2D0.z;

		if(phi_s2 < 3)
		{
			if(sqrtf(SQXYZ(temp_f20)) <= phi_f30)
			{
				phi_f30 = sp294;
				phi_s2++;
			}
		}
		else
		{
			if(sqrtf(SQXYZ(temp_f20)) <= (temp_f28 + 1.0f))
			{
				phi_s2++;
			}
		}

		temp_s4_2++;

		if((temp_s4_2 >= 20) || (phi_s2 >= 4))
		{
			break;
		}
	}

	vtx = SEGMENTED_TO_VIRTUAL(ovl_Boss_Ganon2_Vtx_00BA20);
	for(i = 0; i < 11; i++)
	{
		if((temp_s4 - i) > 0)
		{
			vtx[D_80907084[i]].n.ob[0] = sp18C[temp_s4 - i - 1].x;
			vtx[D_80907084[i]].n.ob[1] = sp18C[temp_s4 - i - 1].y;
			vtx[D_80907084[i]].n.ob[2] = sp18C[temp_s4 - i - 1].z;
		}
		if((temp_s4_2 - i) > 0)
		{
			vtx[D_80907090[i]].n.ob[0] = sp9C[temp_s4_2 - i - 1].x;
			vtx[D_80907090[i]].n.ob[1] = sp9C[temp_s4_2 - i - 1].y;
			vtx[D_80907090[i]].n.ob[2] = sp9C[temp_s4_2 - i - 1].z;
		}
	}
}

void Boss_Ganon2_DrawAttack(BossGanon2* pthis, GlobalContext* globalCtx)
{
	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5083);

	if(pthis->startAttack != 0)
	{
		Boss_Ganon2_UpdateAttack(&pthis->unk_200, &pthis->unk_20C);
		gGanon_AttackTimer = 0xFF;
	}

	if(D_80910638 >= 4)
	{
		gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 32, 32, 1, globalCtx->gameplayFrames * 18, 0, 32, 32));
		gDPPipeSync(POLY_XLU_DISP++);
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, gGanon_AttackTimer);
		Matrix_Translate(0.0f, 0.0f, 0.0f, MTXMODE_NEW);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5117), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, ovl_Boss_Ganon2_DL_00BB80);
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5122);
}

void func_80904108(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	if(pthis->unk_324 > 0.0f)
	{
		OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5131);

		Matrix_Push();
		gDPPipeSync(POLY_XLU_DISP++);
		gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (s32)globalCtx->gameplayFrames, 0, 32, 64, 1, -globalCtx->gameplayFrames * 2, -globalCtx->gameplayFrames * 8, 32, 32));
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 200, 0, (s8)pthis->unk_324);
		gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 128);
		Matrix_Translate(-200.0f, 1086.0f, -200.0f, MTXMODE_NEW);
		Matrix_Scale(0.098000005f, 0.1f, 0.098000005f, MTXMODE_APPLY);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5183), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(ovl_Boss_Ganon2_DL_00E1C0));
		Matrix_Pop();

		CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5186);
	}
}

void func_80904340(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s16 i;
	f32 rand;
	f32 angle;
	f32 sin;
	f32 cos;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5196);
	Matrix_Push();

	if((pthis->unk_330 != 0) || (pthis->unk_328 != 0))
	{
		if(pthis->unk_330 != 0)
		{
			pthis->unk_330--;
		}
		else
		{
			pthis->unk_328 -= 70;

			if(pthis->unk_328 < 0)
			{
				pthis->unk_328 = 0;
			}
		}

		Math_ApproachF(&pthis->unk_32C, 0.13f, 1.0f, 0.065f);
		gDPPipeSync(POLY_XLU_DISP++);
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, pthis->unk_328);
		BossGanon2_InitRand(pthis->unk_340 + 1, 0x71AC - pthis->unk_340, 0x263A);
		rand = BossGanon2_RandZeroOne();
		if(1)
		{
		}

		for(i = 0; i < 5; i++)
		{
			angle = (i * (2 * M_PI / 5)) + (rand * M_PI);
			sin = 5000.0f * sinf(angle);
			cos = 5000.0f * cosf(angle);
			Matrix_Translate(-200.0f + sin, 4786.0f, -200.0f + cos, MTXMODE_NEW);
			Matrix_Scale(pthis->unk_32C, pthis->unk_32C, pthis->unk_32C, MTXMODE_APPLY);
			Matrix_RotateY(angle, MTXMODE_APPLY);
			Matrix_RotateZ((BossGanon2_RandZeroOne() - 0.5f) * 100.0f * 0.01f, MTXMODE_APPLY);

			if(BossGanon2_RandZeroOne() < 0.5f)
			{
				Matrix_RotateY(M_PI, MTXMODE_APPLY);
			}

			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5250), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(ovl_Boss_Ganon2_DL_00D798));
		}
	}

	Matrix_Pop();
	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5255);
}

void func_8090464C(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	if(pthis->unk_1B4 > 0.0f)
	{
		OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5264);

		Matrix_Push();
		gDPPipeSync(POLY_XLU_DISP++);
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 170, (s16)pthis->unk_1B4);
		gDPSetEnvColor(POLY_XLU_DISP++, 255, 200, 0, 128);
		Matrix_Translate(pthis->unk_1B8.x, pthis->unk_1B8.y, pthis->unk_1B8.z, MTXMODE_NEW);
		func_800D1FD4(&globalCtx->billboardMtxF);
		Matrix_RotateZ(-0.2f, MTXMODE_APPLY);
		Matrix_Scale(0.6f, 0.6f, 1.0f, MTXMODE_APPLY);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5290), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(ovl_Boss_Ganon2_DL_00CCD8));
		Matrix_Pop();

		CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5293);
	}
}

s32 BossGanon2_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	s32 pad;
	BossGanon2* pthis = (BossGanon2*)thisx;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5355);

	if(limbIndex == 15)
	{
		rot->y += pthis->unk_31A;
		rot->z += pthis->unk_31C;
	}

	if(limbIndex >= 42)
	{
		rot->x += pthis->unk_2F4[limbIndex] + pthis->unk_346;
		rot->y += pthis->unk_2FE[limbIndex];

		if(pthis->unk_342 & 1)
		{
			gDPSetEnvColor(POLY_OPA_DISP++, 255, 0, 0, 255);
		}
		else
		{
			gDPSetEnvColor(POLY_OPA_DISP++, (s16)pthis->unk_1B0, (s16)pthis->unk_1B0, (s16)(*pthis).unk_1B0, 255);
		}
	}

	if((limbIndex == 7) || (limbIndex == 13) || (limbIndex == 33) || (limbIndex == 34))
	{
		*dList = NULL;
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5431);
	return 0;
}

void BossGanon2_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	s8 pad;
	s8 temp_v0;
	BossGanon2* pthis = (BossGanon2*)thisx;
	Vec3f sp4C;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5459);

	D_80907120.z = 17000.0f;
	D_8090712C.z = 3000.0f;

	if(D_809070CC[limbIndex] >= 0)
	{
		Matrix_MultVec3f(&D_80906D60, &pthis->unk_234[D_809070CC[limbIndex]]);
	}

	if(limbIndex == 15)
	{
		Matrix_MultVec3f(&D_80906D60, &pthis->unk_1B8);
	}
	else if(limbIndex == 3)
	{
		Matrix_MultVec3f(&D_80907108, &pthis->unk_1F4);
	}
	else if(limbIndex == 9)
	{
		Matrix_MultVec3f(&D_80907114, &pthis->unk_1E8);
	}
	else if(limbIndex == 38)
	{
		Matrix_MultVec3f(&D_80906D60, &pthis->unk_1DC);
	}
	else if(limbIndex == 41)
	{
		Matrix_MultVec3f(&D_80906D60, &pthis->unk_1D0);
	}
	else if(limbIndex == 45)
	{
		Matrix_MultVec3f(&D_80907138, &pthis->unk_1C4);
	}

	temp_v0 = D_8090709C[limbIndex];
	if(temp_v0 >= 0)
	{
		Matrix_MultVec3f(&D_80906D60, &sp4C);
		func_808FD080(temp_v0, &pthis->unk_424, &sp4C);
	}

	if((limbIndex == 7) || (limbIndex == 13))
	{
		Matrix_Push();
		Matrix_Scale(pthis->unk_224, pthis->unk_224, pthis->unk_224, MTXMODE_APPLY);
		gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5522), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_OPA_DISP++, *dList);
		Matrix_Pop();
	}
	else if((limbIndex == 33) || (limbIndex == 34))
	{
		Matrix_Push();
		Matrix_Scale(pthis->unk_228, pthis->unk_228, pthis->unk_228, MTXMODE_APPLY);
		gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5533), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_OPA_DISP++, *dList);
		Matrix_Pop();
	}

	if(*dList != NULL)
	{
		if((limbIndex == 7) && (pthis->startAttack == 1))
		{
			Matrix_MultVec3f(&D_809070FC, &pthis->unk_218);
			func_808FD080(0, &pthis->unk_444, &pthis->unk_218);
			Matrix_MultVec3f(&D_80907120, &pthis->unk_200);
			Matrix_MultVec3f(&D_8090712C, &pthis->unk_20C);
		}
		else if((limbIndex == 13) && (pthis->startAttack == 2))
		{
			Matrix_MultVec3f(&D_809070FC, &pthis->unk_218);
			func_808FD080(1, &pthis->unk_444, &pthis->unk_218);
			Matrix_MultVec3f(&D_80907120, &pthis->unk_200);
			Matrix_MultVec3f(&D_8090712C, &pthis->unk_20C);
		}
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5566);
}

void func_80904D88(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	s16 i;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5575);

	if(pthis->unk_30C > 0.0f)
	{
		func_80093D84(globalCtx->state.gfxCtx);
		if(pthis->unk_380 > 0.0f)
		{
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 170, 255);
			gDPSetEnvColor(POLY_XLU_DISP++, 255, 200, 0, 0);
		}
		else
		{
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
			gDPSetEnvColor(POLY_XLU_DISP++, 100, 255, 255, 0);
		}
		gSPDisplayList(POLY_XLU_DISP++, ovl_Boss_Ganon2_DL_00B308);

		for(i = 0; i < 15; i++)
		{
			Matrix_Translate(pthis->unk_234[i].x, pthis->unk_234[i].y, pthis->unk_234[i].z, MTXMODE_NEW);
			func_800D1FD4(&globalCtx->billboardMtxF);
			Matrix_Scale(pthis->unk_30C, pthis->unk_30C, pthis->unk_30C, MTXMODE_APPLY);
			Matrix_RotateZ(Rand_CenteredFloat(M_PI), MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5618), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, ovl_Boss_Ganon2_DL_00B378);
		}
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5622);
}

void func_80904FC8(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5632);

	if(pthis->unk_384 > 0.0f)
	{
		func_80093D84(globalCtx->state.gfxCtx);
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 200);
		gDPSetEnvColor(POLY_XLU_DISP++, 255, 200, 0, 0);
		gSPDisplayList(POLY_XLU_DISP++, ovl_Boss_Ganon2_DL_00B308);
		Matrix_Translate(sZelda->actor.world.pos.x, sZelda->actor.world.pos.y + 80.0f, sZelda->actor.world.pos.z, MTXMODE_NEW);
		func_800D1FD4(&globalCtx->billboardMtxF);
		Matrix_Scale(pthis->unk_384, pthis->unk_384, pthis->unk_384, MTXMODE_APPLY);
		Matrix_RotateZ(pthis->unk_388, MTXMODE_APPLY);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5661), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(ovl_Boss_Ganon2_DL_00B378));
		Matrix_RotateZ(pthis->unk_388 * -2.0f, MTXMODE_APPLY);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5664), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(ovl_Boss_Ganon2_DL_00B378));
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5667);
}

void func_8090523C(BossGanon2* pthis, GlobalContext* globalCtx)
{
	Player* player;
	f32 phi_f20;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5675);

	if(pthis->unk_38C > 0.0f)
	{
		s8 i;

		player = GET_PLAYER(globalCtx);
		func_80093D84(globalCtx->state.gfxCtx);
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s16)pthis->unk_38C);
		gDPSetEnvColor(POLY_XLU_DISP++, 0, 255, 255, 0);
		gSPDisplayList(POLY_XLU_DISP++, ovl_Boss_Ganon2_DL_00B308);

		for(i = 0; i < 11; i++)
		{
			Matrix_Mult(&player->mf_9E0, MTXMODE_NEW);
			Matrix_Translate((i * 250.0f) + 900.0f, 350.0f, 0.0f, MTXMODE_APPLY);

			if(i < 7)
			{
				phi_f20 = 1.0f;
			}
			else
			{
				phi_f20 = 1.0f - ((i - 7) * 0.2333333f); // 7 / 30
			}

			func_800D1FD4(&globalCtx->billboardMtxF);
			Matrix_Scale(200.0f * phi_f20, 200.0f * phi_f20, 1.0f, MTXMODE_APPLY);
			Matrix_RotateZ(Rand_ZeroFloat(2.0f * M_PI), MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5721), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(ovl_Boss_Ganon2_DL_00B378));
		}
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5725);
}

void BossGanon2_PostLimbDraw2(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	s8 temp_v1 = D_80907144[limbIndex];
	BossGanon2* pthis = (BossGanon2*)thisx;

	if(temp_v1 >= 0)
	{
		Matrix_MultVec3f(&D_80906D60, &pthis->unk_234[temp_v1]);
	}
	if(limbIndex == 11)
	{
		OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5749);

		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5752), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_ganon_DL_00BE90));

		CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5754);
	}
	else if(limbIndex == 10)
	{
		Matrix_MultVec3f(&D_80907164, &pthis->unk_1B8);
	}
}

void func_80905674(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s32 pad;

	if(pthis->unk_380 > 0.0f)
	{
		OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5772);

		Matrix_Push();
		gDPPipeSync(POLY_XLU_DISP++);
		gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, pthis->unk_19C * -8, 0, 32, 64, 1, pthis->unk_19C * -4, pthis->unk_19C * -8, 32, 32));
		gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 170, (s16)pthis->unk_37C);
		gDPSetEnvColor(POLY_XLU_DISP++, 255, 200, 0, 128);
		Matrix_Translate(sZelda->actor.world.pos.x + 100.0f, sZelda->actor.world.pos.y + 35.0f + 7.0f, sZelda->actor.world.pos.z - 100.0f, MTXMODE_NEW);
		Matrix_RotateY(-M_PI / 4.0f, MTXMODE_APPLY);
		Matrix_Scale(0.040000003f, 0.040000003f, pthis->unk_380, MTXMODE_APPLY);
		Matrix_RotateX(M_PI / 2.0f, MTXMODE_APPLY);
		gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5814), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(ovl_Boss_Ganon2_DL_00EC40));
		Matrix_Pop();

		CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5817);
	}
}

void BossGanon2_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	void* shadowTexture = Graph_Alloc(globalCtx->state.gfxCtx, 4096);
	BossGanon2* pthis = (BossGanon2*)thisx;
	s16 i;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5840);

	func_80093D18(globalCtx->state.gfxCtx);
	func_80093D84(globalCtx->state.gfxCtx);

	switch(pthis->unk_337)
	{
		case 0:
			BossGanon2_SetObjectSegment(pthis, globalCtx, OBJECT_GANON, true);
			gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(object_ganon_Tex_00A8E0));
			gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(object_ganon_Tex_00A8E0));
			SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, NULL, BossGanon2_PostLimbDraw2, pthis);
			break;
		case 1:
		case 2:
			BossGanon2_SetObjectSegment(pthis, globalCtx, OBJECT_GANON2, true);
			gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures[pthis->unk_310]));
			func_808FD080(0, &pthis->unk_444, &D_8090717C);
			func_808FD080(1, &pthis->unk_444, &D_8090717C);
			pthis->unk_218 = D_8090717C;
			if(pthis->unk_342 & 1)
			{
				POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, 0xFF, 0, 0, 0xFF, 0x384, 0x44B);
			}
			Matrix_Translate(0.0f, -4000.0f, 4000.0f, MTXMODE_APPLY);
			Matrix_RotateX(pthis->unk_394, MTXMODE_APPLY);
			Matrix_Translate(0.0f, 4000.0f, -4000.0f, MTXMODE_APPLY);
			gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5910), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, BossGanon2_OverrideLimbDraw, BossGanon2_PostLimbDraw, pthis);
			POLY_OPA_DISP = Gameplay_SetFog(globalCtx, POLY_OPA_DISP);
			BossGanon2_GenShadowTexture(shadowTexture, pthis, globalCtx);
			BossGanon2_DrawShadowTexture(shadowTexture, pthis, globalCtx);
			break;
	}

	BossGanon2_SetObjectSegment(pthis, globalCtx, OBJECT_GANON2, true);
	func_80904340(pthis, globalCtx);
	func_80904108(pthis, globalCtx);
	func_80904D88(pthis, globalCtx);
	func_8090464C(pthis, globalCtx);
	func_80905674(pthis, globalCtx);
	func_80904FC8(pthis, globalCtx);
	func_8090523C(pthis, globalCtx);

	if((pthis->startAttack != 0) || (gGanon_AttackTimer != 0))
	{
		Boss_Ganon2_DrawAttack(pthis, globalCtx);
		if(pthis->startAttack == 0)
		{
			s32 pad;

			gGanon_AttackTimer -= 40;
			if(gGanon_AttackTimer <= 0)
			{
				gGanon_AttackTimer = 0;
			}
		}

		D_80910638++;
	}
	else
	{
		for(i = 0; i < 3; i++)
		{
			D_809105D8[i] = pthis->unk_200;
			D_80910608[i] = pthis->unk_20C;
		}

		D_80910638 = 0;
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 5983);

	BossGanon2_DrawSpecialEffects(globalCtx);
}

void BossGanon2_UpdateSpecialEffects(BossGanon2* pthis, GlobalContext* globalCtx)
{
	s32 pad[5];
	Player* player = GET_PLAYER(globalCtx);
	BossGanon2Effect* effect = (BossGanon2Effect*)globalCtx->specialEffects;
	Vec3f sp78;
	s16 i;

	for(i = 0; i < ARRAY_COUNT(sParticles); i++, effect++)
	{
		if(effect->type != 0)
		{
			effect->position.x += effect->velocity.x;
			effect->position.y += effect->velocity.y;
			effect->position.z += effect->velocity.z;
			effect->unk_01++;
			effect->velocity.x += effect->accel.x;
			effect->velocity.y += effect->accel.y;
			effect->velocity.z += effect->accel.z;
			if(effect->type == 1)
			{
				if(effect->unk_2E == 0)
				{
					effect->unk_38.z += 1.0f;
					effect->unk_38.y = (2.0f * M_PI) / 5.0f;
				}
				else
				{
					effect->unk_38.z = M_PI / 2.0f;
					effect->unk_38.y = 0.0f;
					if(effect->position.y <= 1098.0f)
					{
						effect->position.y = 1098.0f;
						if(effect->velocity.y < -10.0f)
						{
							sp78 = effect->position;
							sp78.y = 1086.0f;
							Common_PlaySfx(NA_SE_IT_SHIELD_REFLECT_SW);
							CollisionCheck_SpawnShieldParticlesMetal(globalCtx, &sp78);
						}
						effect->velocity.y = 0.0f;
					}
					if((SQ(player->actor.world.pos.x - effect->position.x) + SQ(player->actor.world.pos.z - effect->position.z)) < SQ(25.0f))
					{
						effect->type = 0;
						pthis->unk_39C = 10;
					}
				}
			}
			else if(effect->type == 2)
			{
				effect->unk_38.x += 0.1f;
				effect->unk_38.y += 0.4f;
				if((sqrtf(SQ(-200.0f - effect->position.x) + SQ(-200.0f - effect->position.z)) < 1000.0f))
				{
					if(effect->position.y < 1186.0f)
					{
						if(effect->unk_2E == 0)
						{
							effect->unk_2E++;
							effect->position.y = 1186.0f;
							effect->velocity.x *= 0.75f;
							effect->velocity.z *= 0.75f;
							effect->velocity.y *= -0.2f;
						}
						else
						{
							effect->type = 0;
						}
					}
				}
				else if((effect->position.y < 0.0f))
				{
					effect->type = 0;
				}
			}
		}
	}
}

void BossGanon2_DrawSpecialEffects(GlobalContext* globalCtx)
{
	s16 alpha;
	u8 usingObjectGEff = false;
	BossGanon2Effect* effect;
	s16 i;
	BossGanon2Effect* effects;

	effects = effect = (BossGanon2Effect*)globalCtx->specialEffects;

	OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 6086);

	func_80093D18(globalCtx->state.gfxCtx);

	for(i = 0; i < 1; i++)
	{
		if(effect->type == 1)
		{
			Vec3f spA0;
			f32 temp_f0;
			f32 angle;

			func_80093D84(globalCtx->state.gfxCtx);
			spA0.x = globalCtx->envCtx.dirLight1.params.dir.x;
			spA0.y = globalCtx->envCtx.dirLight1.params.dir.y;
			spA0.z = globalCtx->envCtx.dirLight1.params.dir.z;
			func_8002EABC(&effect->position, &globalCtx->view.eye, &spA0, globalCtx->state.gfxCtx);
			Matrix_Translate(effect->position.x, effect->position.y, effect->position.z, MTXMODE_NEW);
			Matrix_Scale(0.03f, 0.03f, 0.03f, MTXMODE_APPLY);
			Matrix_RotateY(effect->unk_38.z, MTXMODE_APPLY);
			Matrix_RotateX(effect->unk_38.y, MTXMODE_APPLY);
			gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 6116), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPSegment(POLY_OPA_DISP++, 0x08, Gfx_TexScroll(globalCtx->state.gfxCtx, 0, 0 - (globalCtx->gameplayFrames & 0x7F), 32, 32));
			gSPDisplayList(POLY_OPA_DISP++, ovl_Boss_Ganon2_DL_0103A8);
			if((globalCtx->envCtx.unk_BD == 1) || (globalCtx->envCtx.unk_BD == 2))
			{
				alpha = (s16)(globalCtx->envCtx.unk_D8 * 150.0f) + 50;
				angle = M_PI / 5.0f;
			}
			else
			{
				alpha = 100;
				angle = M_PI / 2.0f;
			}
			gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, alpha);
			temp_f0 = effect->position.y - 1098.0f;
			Matrix_Translate(effect->position.x + temp_f0, 1086.0f, (effect->position.z - 1.0f) + temp_f0, MTXMODE_NEW);
			Matrix_RotateY(angle, MTXMODE_APPLY);
			Matrix_Scale(1.0f, 0.0f, 1.0f, MTXMODE_APPLY);
			gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 6155), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_XLU_DISP++, ovl_Boss_Ganon2_DL_00F188);
		}
	}

	effect = effects;

	for(i = 0; i < ARRAY_COUNT(sParticles); i++, effect++)
	{
		if(effect->type == 2)
		{
			if(!usingObjectGEff)
			{
				BossGanon2_SetObjectSegment(NULL, globalCtx, OBJECT_GEFF, true);
				usingObjectGEff++;
			}
			Matrix_Translate(effect->position.x, effect->position.y, effect->position.z, MTXMODE_NEW);
			Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);
			Matrix_RotateY(effect->unk_38.z, MTXMODE_APPLY);
			Matrix_RotateX(effect->unk_38.y, MTXMODE_APPLY);
			Matrix_RotateZ(effect->unk_38.x, MTXMODE_APPLY);
			gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 6179), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			gSPDisplayList(POLY_OPA_DISP++, gGanonRubbleDL);
		}
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 6185);
}

void func_80906538(BossGanon2* pthis, u8* shadowTexture, f32 arg2)
{
	s16 temp_t0;
	s16 temp_v0;
	s16 temp_a3;
	s16 phi_v1;
	s16 phi_a1;
	s16 i;
	f32 lerpx;
	s16 j;
	f32 lerpy;
	f32 lerpz;
	Vec3f sp70;
	Vec3f sp64;

	for(i = 0; i < 15; i++)
	{
		if((arg2 == 0.0f) || ((j = D_809071CC[i]) >= 0))
		{
			if(arg2 > 0.0f)
			{
				lerpx = pthis->unk_234[i].x + (pthis->unk_234[j].x - pthis->unk_234[i].x) * arg2;
				lerpy = pthis->unk_234[i].y + (pthis->unk_234[j].y - pthis->unk_234[i].y) * arg2;
				lerpz = pthis->unk_234[i].z + (pthis->unk_234[j].z - pthis->unk_234[i].z) * arg2;

				sp70.x = lerpx - pthis->actor.world.pos.x;
				sp70.y = lerpy - pthis->actor.world.pos.y + 76.0f + 30.0f + 30.0f + 100.0f;
				sp70.z = lerpz - pthis->actor.world.pos.z;
			}
			else
			{
				sp70.x = pthis->unk_234[i].x - pthis->actor.world.pos.x;
				sp70.y = pthis->unk_234[i].y - pthis->actor.world.pos.y + 76.0f + 30.0f + 30.0f + 100.0f;
				sp70.z = pthis->unk_234[i].z - pthis->actor.world.pos.z;
			}

			Matrix_MultVec3f(&sp70, &sp64);
			sp64.x *= 0.2f;
			sp64.y *= 0.2f;
			temp_a3 = sp64.x + 32.0f;
			temp_t0 = (s16)sp64.y * 64;

			if(D_809071EC[i] == 2)
			{
				for(j = 0, phi_a1 = -0x180; j < 12; j++, phi_a1 += 0x40)
				{
					for(phi_v1 = -D_809071B4[j]; phi_v1 < D_809071B4[j]; phi_v1++)
					{
						temp_v0 = temp_a3 + phi_v1 + temp_t0 + phi_a1;
						if((temp_v0 >= 0) && (temp_v0 < 0x1000))
						{
							shadowTexture[temp_v0] = 0xFF;
						}
					}
				}
			}
			else if(D_809071EC[i] == 1)
			{
				for(j = 0, phi_a1 = -0x100; j < 8; j++, phi_a1 += 0x40)
				{
					for(phi_v1 = -D_809071A4[j]; phi_v1 < D_809071A4[j]; phi_v1++)
					{
						temp_v0 = temp_a3 + phi_v1 + temp_t0 + phi_a1;
						if((temp_v0 >= 0) && (temp_v0 < 0x1000))
						{
							shadowTexture[temp_v0] = 0xFF;
						}
					}
				}
			}
			else if(D_809071EC[i] == 0)
			{
				for(j = 0, phi_a1 = -0xC0; j < 7; j++, phi_a1 += 0x40)
				{
					for(phi_v1 = -D_80907194[j]; phi_v1 < D_80907194[j] - 1; phi_v1++)
					{
						temp_v0 = temp_a3 + phi_v1 + temp_t0 + phi_a1;
						if((temp_v0 >= 0) && (temp_v0 < 0x1000))
						{
							shadowTexture[temp_v0] = 0xFF;
						}
					}
				}
			}
			else
			{
				for(j = 0, phi_a1 = -0x80; j < 6; j++, phi_a1 += 0x40)
				{
					for(phi_v1 = -D_80907188[j]; phi_v1 < D_80907188[j] - 1; phi_v1++)
					{
						temp_v0 = temp_a3 + phi_v1 + temp_t0 + phi_a1;
						if((temp_v0 >= 0) && (temp_v0 < 0x1000))
						{
							shadowTexture[temp_v0] = 0xFF;
						}
					}
				}
			}
		}
	}
}

void BossGanon2_GenShadowTexture(void* shadowTexture, BossGanon2* pthis, GlobalContext* globalCtx)
{
	s16 i;
	u32* p = (u32*)shadowTexture;

	for(i = 0; i < 1024; i++, p++)
	{
		*p = 0;
	}

	Matrix_RotateX(1.0f, MTXMODE_NEW);

	for(i = 0; i < 6; i++)
	{
		func_80906538(pthis, (u8*)shadowTexture, i / 5.0f);
	}
}

void BossGanon2_DrawShadowTexture(void* shadowTexture, BossGanon2* pthis, GlobalContext* globalCtx)
{
	s32 pad;
	GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
	s16 alpha;

	OPEN_DISPS(gfxCtx, "../z_boss_ganon2.c", 6430);

	func_80093D18(globalCtx->state.gfxCtx);

	if((globalCtx->envCtx.unk_BD == 1) || (globalCtx->envCtx.unk_BD == 2))
	{
		alpha = (s16)(globalCtx->envCtx.unk_D8 * 180.0f) + 30;
	}
	else
	{
		alpha = 120;
	}

	gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 0, 0, 0, alpha);
	gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
	Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.floorHeight, pthis->actor.world.pos.z - 20.0f, MTXMODE_NEW);
	Matrix_Scale(1.65f, 1.0f, 1.65f, MTXMODE_APPLY);
	gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 6457), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPDisplayList(POLY_OPA_DISP++, ovl_Boss_Ganon2_DL_00B3D0);
	gDPLoadTextureBlock(POLY_OPA_DISP++, shadowTexture, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
	gSPDisplayList(POLY_OPA_DISP++, ovl_Boss_Ganon2_DL_00B3F0);

	CLOSE_DISPS(gfxCtx, "../z_boss_ganon2.c", 6479);
}

void BossGanon2_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	Boss_Ganon2_InitVars = {
	    ACTOR_BOSS_GANON2, ACTORCAT_BOSS, FLAGS, OBJECT_GANON2, sizeof(BossGanon2), (ActorFunc)BossGanon2_Init, (ActorFunc)BossGanon2_Destroy, (ActorFunc)BossGanon2_Update, (ActorFunc)BossGanon2_Draw, (ActorFunc)BossGanon2_Reset,
	};
}
