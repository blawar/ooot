#define INTERNAL_SRC_CODE_Z_PLAY_C
#include "global.h"
#include "z64global.h"
#include <functional>
#include <string>
#include "audiomgr.h"
#include "framerate.h"
#include "gamestate.h"
#include "gfxapi.h"
#include "n64fault.h"
#include "padmgr.h"
#include "sequence.h"
#include "sfx.h"
#include "unk.h"
#include "vt.h"
#include "z64item.h"
#include "z64player.h"
#include "z64save.h"
#include "z64memory.h"
#include "z64transition.h"
#include "z_fbdemo_circle.h"
#include "z_scene_table.h"
#include "z_vismono.h"
#include "def/PreRender.h"
#include "def/TwoHeadArena.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/code_8006BA00.h"
#include "def/code_800A9F30.h"
#include "def/environment_flags.h"
#include "def/fault.h"
#include "def/game.h"
#include "def/gettime.h"
#include "def/graph.h"
#include "def/random.h"
#include "def/shrink_window.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/system_malloc.h"
#include "def/z_actor.h"
#include "def/z_actor_dlftbls.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_camera_data.h"
#include "def/z_collision_check.h"
#include "def/z_construct.h"
#include "def/z_demo.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite.h"
#include "def/z_fbdemo.h"
#include "def/z_fbdemo_fade.h"
#include "def/z_file_choose.h"
#include "def/z_frame_advance.h"
#include "def/z_game_over.h"
#include "def/z_kaleido_manager.h"
#include "def/z_kaleido_scope_call.h"
#include "def/z_kaleido_setup.h"
#include "def/z_kankyo.h"
#include "def/z_lights.h"
#include "def/z_malloc.h"
#include "def/z_message_PAL.h"
#include "def/z_msgevent.h"
#include "def/z_onepointdemo.h"
#include "def/z_opening.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"
#include "def/z_quake.h"
#include "def/z_rcp.h"
#include "def/z_room.h"
#include "def/z_scene.h"
#include "def/z_scene_table.h"
#include "def/z_skelanime.h"
#include "def/z_std_dma.h"
#include "def/z_view.h"
#include "def/z_vismono.h"
#include "def/z_vr_box.h"
#include "def/z_vr_box_draw.h"
#include "def/zbuffer.h"

void Gameplay_SpawnScene(GlobalContext* globalCtx, s32 sceneNum, s32 spawn);

void* D_8012D1F0 = NULL;
UNK_TYPE D_8012D1F4 = 0; // unused
Input* D_8012D1F8 = NULL;

TransitionUnk sTrnsnUnk;
s32 gTrnsnUnkState;
VisMono D_80161498;
Color_RGBA8 D_801614B0;
FaultClient D_801614B8;
s16 D_801614C8;
u64 D_801614D0[0xA00];

void func_800BC450(GlobalContext* globalCtx)
{
	Camera_ChangeDataIdx(GET_ACTIVE_CAM(globalCtx), globalCtx->unk_1242B - 1);
}

void func_800BC490(GlobalContext* globalCtx, s16 point)
{
	ASSERT(point == 1 || point == 2, "point == 1 || point == 2", "../z_play.c", 2160);

	globalCtx->unk_1242B = point;

	if((YREG(15) != 0x10) && (gSaveContext.cutsceneIndex < 0xFFF0))
	{
		Audio_PlaySoundGeneral((point == 1) ? NA_SE_SY_CAMERA_ZOOM_DOWN : NA_SE_SY_CAMERA_ZOOM_UP, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
	}

	func_800BC450(globalCtx);
}

s32 func_800BC56C(GlobalContext* globalCtx, s16 arg1)
{
	return (arg1 == globalCtx->unk_1242B);
}

// original name: "Game_play_shop_pr_vr_switch_set"
void func_800BC590(GlobalContext* globalCtx)
{
	osSyncPrintf("Game_play_shop_pr_vr_switch_set()\n");

	if(YREG(15) == 0x10)
	{
		globalCtx->unk_1242B = 2;
	}
}

void func_800BC5E0(GlobalContext* globalCtx, s32 transitionType)
{
	TransitionContext* transitionCtx = &globalCtx->transitionCtx;

	memset(transitionCtx, 0, sizeof(TransitionContext));

	transitionCtx->transitionType = transitionType;

	if((transitionCtx->transitionType >> 5) == 1)
	{
		transitionCtx->init = TransitionCircle_Init;
		transitionCtx->destroy = TransitionCircle_Destroy;
		transitionCtx->start = TransitionCircle_Start;
		transitionCtx->isDone = TransitionCircle_IsDone;
		transitionCtx->draw = TransitionCircle_Draw;
		transitionCtx->update = TransitionCircle_Update;
		transitionCtx->setType = TransitionCircle_SetType;
		transitionCtx->setColor = TransitionCircle_SetColor;
		transitionCtx->setEnvColor = TransitionCircle_SetEnvColor;
	}
	else
	{
		switch(transitionCtx->transitionType)
		{
			case 1:
				transitionCtx->init = TransitionTriforce_Init;
				transitionCtx->destroy = TransitionTriforce_Destroy;
				transitionCtx->start = TransitionTriforce_Start;
				transitionCtx->isDone = TransitionTriforce_IsDone;
				transitionCtx->draw = TransitionTriforce_Draw;
				transitionCtx->update = TransitionTriforce_Update;
				transitionCtx->setType = TransitionTriforce_SetType;
				transitionCtx->setColor = TransitionTriforce_SetColor;
				transitionCtx->setEnvColor = NULL;
				break;
			case 0:
			case 8:
				transitionCtx->init = TransitionWipe_Init;
				transitionCtx->destroy = TransitionWipe_Destroy;
				transitionCtx->start = TransitionWipe_Start;
				transitionCtx->isDone = TransitionWipe_IsDone;
				transitionCtx->draw = TransitionWipe_Draw;
				transitionCtx->update = TransitionWipe_Update;
				transitionCtx->setType = TransitionWipe_SetType;
				transitionCtx->setColor = TransitionWipe_SetColor;
				transitionCtx->setEnvColor = NULL;
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 13:
			case 17:
			case 18:
			case 19:
				transitionCtx->init = TransitionFade_Init;
				transitionCtx->destroy = TransitionFade_Destroy;
				transitionCtx->start = TransitionFade_Start;
				transitionCtx->isDone = TransitionFade_IsDone;
				transitionCtx->draw = TransitionFade_Draw;
				transitionCtx->update = TransitionFade_Update;
				transitionCtx->setType = TransitionFade_SetType;
				transitionCtx->setColor = TransitionFade_SetColor;
				transitionCtx->setEnvColor = NULL;
				break;
			case 9:
			case 10:
				globalCtx->transitionMode = 4;
				break;
			case 11:
				globalCtx->transitionMode = 10;
				break;
			case 12:
				globalCtx->transitionMode = 7;
				break;
			case 14:
				globalCtx->transitionMode = 12;
				break;
			case 15:
				globalCtx->transitionMode = 14;
				break;
			case 16:
				globalCtx->transitionMode = 16;
				break;
			default:
				Fault_AddHungupAndCrash("../z_play.c", 2290);
				break;
		}
	}
}

void func_800BC88C(GlobalContext* globalCtx)
{
	globalCtx->transitionCtx.transitionType = -1;
}

Gfx* Gameplay_SetFog(GlobalContext* globalCtx, Gfx* gfx)
{
	return Gfx_SetFog2(gfx, globalCtx->lightCtx.fogColor[0], globalCtx->lightCtx.fogColor[1], globalCtx->lightCtx.fogColor[2], 0, globalCtx->lightCtx.fogNear, 1000);
}

namespace oot::gamestate
{
	Global::~Global()
	{
		GlobalContext* globalCtx = this;
		Player* player = GET_PLAYER(globalCtx);

		globalCtx->gfxCtx->callback = NULL;
		globalCtx->gfxCtx->callbackParam = 0;
		SREG(91) = 0;
		R_PAUSE_MENU_MODE = 0;

		PreRender_Destroy(&globalCtx->pauseBgPreRender);
		Effect_DeleteAll(globalCtx);
		EffectSs_ClearAll(globalCtx);
		CollisionCheck_DestroyContext(globalCtx, &globalCtx->colChkCtx);

		if(gTrnsnUnkState == 3)
		{
			TransitionUnk_Destroy(&sTrnsnUnk);
			gTrnsnUnkState = 0;
		}

		if(globalCtx->transitionMode == 3)
		{
			globalCtx->transitionCtx.destroy(&globalCtx->transitionCtx.data);
			func_800BC88C(globalCtx);
			globalCtx->transitionMode = 0;
		}

		ShrinkWindow_Destroy();
		TransitionFade_Destroy(&globalCtx->transitionFade);
		VisMono_Destroy(&D_80161498);

		if(gSaveContext.linkAge != globalCtx->linkAgeOnLoad)
		{
			Inventory_SwapAgeEquipment();
			Player_SetEquipmentData(globalCtx, player);
		}

		func_80031C3C(&globalCtx->actorCtx, globalCtx);
		func_80110990(globalCtx);
		KaleidoScopeCall_Destroy(globalCtx);
		KaleidoManager_Destroy();
		ZeldaArena_Cleanup();
		Fault_RemoveClient(&D_801614B8);
	}
} // namespace oot::gamestate

namespace oot::gamestate
{
	Global::Global(GraphicsContext* gfxCtx) : Base(gfxCtx), GlobalData()
	{
	}

	void Global::init()
	{
		GlobalContext* globalCtx = this;
		Player* player;
		s32 playerStartCamId;
		s32 i;
		u8 tempSetupIndex;
		s32 pad[2];

		if(gSaveContext.entranceIndex == -1)
		{
			gSaveContext.entranceIndex = 0;
			globalCtx->running = false;
			Graph_SetNextGameState(new oot::gamestate::Opening(globalCtx->gfxCtx));
			return;
		}

		SystemArena_Display();
		GameState_Realloc(globalCtx, 0x1D4790 * sizeof(uintptr_t) / 4);
		KaleidoManager_Init(globalCtx);
		View_Init(&globalCtx->view, gfxCtx);
		Audio_SetExtraFilter(0);
		Quake_Init();

		for(i = 0; i < NUM_CAMS; i++)
		{
			globalCtx->cameraPtrs[i] = NULL;
		}

		Camera_Init(&globalCtx->mainCamera, &globalCtx->view, &globalCtx->colCtx, globalCtx);
		Camera_ChangeStatus(&globalCtx->mainCamera, CAM_STAT_ACTIVE);

		for(i = 0; i < 3; i++)
		{
			Camera_Init(&globalCtx->subCameras[i], &globalCtx->view, &globalCtx->colCtx, globalCtx);
			Camera_ChangeStatus(&globalCtx->subCameras[i], CAM_STAT_UNK100);
		}

		globalCtx->cameraPtrs[MAIN_CAM] = &globalCtx->mainCamera;
		globalCtx->cameraPtrs[MAIN_CAM]->uid = 0;
		globalCtx->activeCamera = MAIN_CAM;
		func_8005AC48(&globalCtx->mainCamera, 0xFF);
		func_80112098(globalCtx);
		Message_Init(globalCtx);
		GameOver_Init(globalCtx);
		func_8006BA00(globalCtx);
		Effect_InitContext(globalCtx);
		EffectSs_InitInfo(globalCtx, 0x55);
		CollisionCheck_InitContext(globalCtx, &globalCtx->colChkCtx);
		AnimationContext_Reset(&globalCtx->animationCtx);
		Cutscene_Stop(globalCtx, &globalCtx->csCtx);

		if(gSaveContext.nextCutsceneIndex != 0xFFEF)
		{
			gSaveContext.cutsceneIndex = gSaveContext.nextCutsceneIndex;
			gSaveContext.nextCutsceneIndex = 0xFFEF;
		}

		if(gSaveContext.cutsceneIndex == 0xFFFD)
		{
			gSaveContext.cutsceneIndex = 0;
		}

		if(gSaveContext.nextDayTime != 0xFFFF)
		{
			gSaveContext.dayTime = gSaveContext.nextDayTime;
			gSaveContext.skyboxTime = gSaveContext.nextDayTime;
		}

		if(gSaveContext.dayTime > 0xC000 || gSaveContext.dayTime < 0x4555)
		{
			gSaveContext.nightFlag = 1;
		}
		else
		{
			gSaveContext.nightFlag = 0;
		}

		Cutscene_HandleConditionalTriggers(globalCtx);

		if(gSaveContext.gameMode != 0 || gSaveContext.cutsceneIndex >= 0xFFF0)
		{
			gSaveContext.nayrusLoveTimer = 0;
			func_800876C8(globalCtx);
			gSaveContext.sceneSetupIndex = (gSaveContext.cutsceneIndex & 0xF) + 4;
		}
		else if(!LINK_IS_ADULT && IS_DAY)
		{
			gSaveContext.sceneSetupIndex = 0;
		}
		else if(!LINK_IS_ADULT && !IS_DAY)
		{
			gSaveContext.sceneSetupIndex = 1;
		}
		else if(LINK_IS_ADULT && IS_DAY)
		{
			gSaveContext.sceneSetupIndex = 2;
		}
		else
		{
			gSaveContext.sceneSetupIndex = 3;
		}

		tempSetupIndex = gSaveContext.sceneSetupIndex;
		if((gEntranceTable[((void)0, gSaveContext.entranceIndex)].scene == SCENE_SPOT00) && !LINK_IS_ADULT && gSaveContext.sceneSetupIndex < 4)
		{
			if(CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD) && CHECK_QUEST_ITEM(QUEST_GORON_RUBY) && CHECK_QUEST_ITEM(QUEST_ZORA_SAPPHIRE))
			{
				gSaveContext.sceneSetupIndex = 1;
			}
			else
			{
				gSaveContext.sceneSetupIndex = 0;
			}
		}
		else if((gEntranceTable[((void)0, gSaveContext.entranceIndex)].scene == SCENE_SPOT04) && LINK_IS_ADULT && gSaveContext.sceneSetupIndex < 4)
		{
			gSaveContext.sceneSetupIndex = (gSaveContext.eventChkInf[4] & 0x100) ? 3 : 2;
		}

		Gameplay_SpawnScene(globalCtx, gEntranceTable[((void)0, gSaveContext.entranceIndex) + ((void)0, gSaveContext.sceneSetupIndex)].scene, gEntranceTable[((void)0, gSaveContext.sceneSetupIndex) + ((void)0, gSaveContext.entranceIndex)].spawn);
		osSyncPrintf("\nSCENE_NO=%d COUNTER=%d\n", ((void)0, gSaveContext.entranceIndex), gSaveContext.sceneSetupIndex);

		// When entering Gerudo Valley in the right setup, trigger the GC emulator to play the ending movie.
		// The emulator constantly checks whether PC is 0x81000000, so this works even though it's not a valid address.
		if((gEntranceTable[((void)0, gSaveContext.entranceIndex)].scene == SCENE_SPOT09) && gSaveContext.sceneSetupIndex == 6)
		{
			osSyncPrintf("エンディングはじまるよー\n"); // "The ending starts"
#ifdef N64_VERSION
			((void (*)())0x81000000)();
#endif
			osSyncPrintf("出戻り？\n"); // "Return?"
		}

		Cutscene_HandleEntranceTriggers(globalCtx);
		KaleidoScopeCall_Init(globalCtx);
		func_801109B0(globalCtx);

		if(gSaveContext.nextDayTime != 0xFFFF)
		{
			if(gSaveContext.nextDayTime == 0x8001)
			{
				gSaveContext.totalDays++;
				gSaveContext.bgsDayCount++;
				gSaveContext.dogIsLost = true;
				if(Inventory_ReplaceItem(globalCtx, ITEM_WEIRD_EGG, ITEM_CHICKEN) || Inventory_ReplaceItem(globalCtx, ITEM_POCKET_EGG, ITEM_POCKET_CUCCO))
				{
					Message_StartTextbox(globalCtx, 0x3066, NULL);
				}
				gSaveContext.nextDayTime = 0xFFFE;
			}
			else
			{
				gSaveContext.nextDayTime = 0xFFFD;
			}
		}

		SREG(91) = -1;
		R_PAUSE_MENU_MODE = 0;
		PreRender_Init(&globalCtx->pauseBgPreRender);
		PreRender_SetValuesSave(&globalCtx->pauseBgPreRender, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0);
		PreRender_SetValues(&globalCtx->pauseBgPreRender, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
		gTrnsnUnkState = 0;
		globalCtx->transitionMode = 0;
		FrameAdvance_Init(&globalCtx->frameAdvCtx);
#ifdef N64_VERSION
		Rand_Seed((u32)osGetTime());
#else
		using namespace std::string_literals;
		Rand_Seed((u32)std::hash<std::string>{}("Open Ocarina Team"s));
#endif
		Matrix_Init(globalCtx);
		globalCtx->sceneLoadFlag = -0x14;
		globalCtx->unk_11E16 = 0xFF;
		globalCtx->unk_11E18 = 0;
		globalCtx->unk_11DE9 = 0;

		if(gSaveContext.gameMode != 1)
		{
			if(gSaveContext.nextTransition == 0xFF)
			{
				globalCtx->fadeTransition = (gEntranceTable[((void)0, gSaveContext.entranceIndex) + tempSetupIndex].field >> 7) & 0x7F; // Fade In
			}
			else
			{
				globalCtx->fadeTransition = gSaveContext.nextTransition;
				gSaveContext.nextTransition = 0xFF;
			}
		}
		else
		{
			globalCtx->fadeTransition = 6;
		}

		ShrinkWindow_Init();
		TransitionFade_Init(&globalCtx->transitionFade);
		TransitionFade_SetType(&globalCtx->transitionFade, 3);
		TransitionFade_SetColor(&globalCtx->transitionFade, Color_RGBA8(160, 160, 160, 255));
		TransitionFade_Start(&globalCtx->transitionFade);
		VisMono_Init(&D_80161498);
		D_801614B0.a = 0;
		Flags_UnsetAllEnv(globalCtx);

		Fault_AddClient(&D_801614B8, ZeldaArena_Display, NULL, NULL);
		Actor_InitContext(globalCtx, &globalCtx->actorCtx, globalCtx->linkActorEntry);

		while(!func_800973FC(globalCtx, &globalCtx->roomCtx))
		{
			; // Empty Loop
		}

		// Check if the room in our scene has a prerendered background
		Room* currentRoom = &globalCtx->roomCtx.curRoom;
		PolygonType1* polygon1 = &currentRoom->mesh->polygon1;
		// Switch GLideN64 to 4:3 if necessary
		gfx_force_43(currentRoom->mesh->polygon.type == 1 && (polygon1->format == 1 || polygon1->format == 2));

		player = GET_PLAYER(globalCtx);
		Camera_InitPlayerSettings(&globalCtx->mainCamera, player);
		Camera_ChangeMode(&globalCtx->mainCamera, CAM_MODE_NORMAL);

		playerStartCamId = player->actor.params & 0xFF;
		if(playerStartCamId != 0xFF)
		{
			osSyncPrintf("player has start camera ID (" VT_FGCOL(BLUE) "%d" VT_RST ")\n", playerStartCamId);
			Camera_ChangeDataIdx(&globalCtx->mainCamera, playerStartCamId);
		}

		if(YREG(15) == 32)
		{
			globalCtx->unk_1242B = 2;
		}
		else if(YREG(15) == 16)
		{
			globalCtx->unk_1242B = 1;
		}
		else
		{
			globalCtx->unk_1242B = 0;
		}

		Interface_SetSceneRestrictions(globalCtx);
		func_800758AC(globalCtx);
		gSaveContext.seqId = globalCtx->sequenceCtx.seqId;
		gSaveContext.natureAmbienceId = globalCtx->sequenceCtx.natureAmbienceId;
		func_8002DF18(globalCtx, GET_PLAYER(globalCtx));
		AnimationContext_Update(globalCtx, &globalCtx->animationCtx);
		gSaveContext.respawnFlag = 0;

		if(dREG(95) != 0)
		{
			D_8012D1F0 = D_801614D0;
			osSyncPrintf("\nkawauso_data=[%x]", D_8012D1F0);
			/* Unsure what this is for, possibly a cutscene. */
			/* DmaMgr_DmaRomToRam(0x03FEB000, D_8012D1F0, sizeof(D_801614D0)); */
		}
	}
} // namespace oot::gamestate

void Gameplay_Update(GlobalContext* globalCtx)
{
	s32 pad1;
	s32 pauseGamePlay;
	Input* input;
	u32 i;
	s32 pad2;

	input = globalCtx->input;

	if((SREG(1) < 0) || (DREG(0) != 0))
	{
		SREG(1) = 0;
		ZeldaArena_Display();
	}

	if((HREG(80) == 18) && (HREG(81) < 0))
	{
		HREG(81) = 0;
		osSyncPrintf("object_exchange_rom_address %u\n", gObjectTableSize);
		osSyncPrintf("RomStart RomEnd   Size\n");
		for(i = 0; i < gObjectTableSize; i++)
		{
			s32 size = POINTER_SUB2(gObjectTable[i].vromEnd, gObjectTable[i].vromStart);

			osSyncPrintf("%08x-%08x %08x(%8.3fKB)\n", gObjectTable[i].vromStart, gObjectTable[i].vromEnd, size, size / 1024.0f);
		}
		osSyncPrintf("\n");
	}

	if((HREG(81) == 18) && (HREG(82) < 0))
	{
		HREG(82) = 0;
		ActorOverlayTable_LogPrint();
	}

	gSegments[4] = gObjectTable[globalCtx->objectCtx.mainKeepIndex].vromStart.get();
	gSegments[5] = gObjectTable[globalCtx->objectCtx.subKeepIndex].vromStart.get();
	gSegments[2] = (uintptr_t)globalCtx->sceneSegment;

	if(FrameAdvance_Update(&globalCtx->frameAdvCtx, &input[1]))
	{
		if((globalCtx->transitionMode == 0) && (globalCtx->sceneLoadFlag != 0))
		{
			globalCtx->transitionMode = 1;
		}

		if(gTrnsnUnkState != 0)
		{
			switch(gTrnsnUnkState)
			{
				case 2:
					if(TransitionUnk_Init(&sTrnsnUnk, 10, 7) == NULL)
					{
						osSyncPrintf("fbdemo_init呼出し失敗！\n"); // "fbdemo_init call failed!"
						gTrnsnUnkState = 0;
					}
					else
					{
						sTrnsnUnk.zBuffer = (u16*)gZBuffer;
						gTrnsnUnkState = 3;
						framerate_set_profile(PROFILE_UNKNOWN1);
					}
					break;
				case 3:
					func_800B23E8(&sTrnsnUnk);
					break;
			}
		}

		if(globalCtx->transitionMode)
		{
			switch(globalCtx->transitionMode)
			{
				case 1:
					if(globalCtx->sceneLoadFlag != -0x14)
					{
						s16 sp6E = 0;
						Interface_ChangeAlpha(1);

						if(gSaveContext.cutsceneIndex >= 0xFFF0)
						{
							sp6E = (gSaveContext.cutsceneIndex & 0xF) + 4;
						}

						if(!(gEntranceTable[globalCtx->nextEntranceIndex + sp6E].field & 0x8000))
						{ // Continue BGM Off
							// "Sound initalized. 111"
							osSyncPrintf("\n\n\nサウンドイニシャル来ました。111");
							if((globalCtx->fadeTransition < 56) && !Environment_IsForcedSequenceDisabled())
							{
								// "Sound initalized. 222"
								osSyncPrintf("\n\n\nサウンドイニシャル来ました。222");
								Audio_FadeOutMostSFX(0x14);
								gSaveContext.seqId = (u8)NA_BGM_DISABLED;
								gSaveContext.natureAmbienceId = 0xFF;
							}
						}
					}

					if(CREG(11) == 0)
					{
						func_800BC5E0(globalCtx, globalCtx->fadeTransition);
					}
					else
					{
						func_800BC5E0(globalCtx, CREG(12));
					}

					if(globalCtx->transitionMode >= 4)
					{
						break;
					}

				case 2:
					globalCtx->transitionCtx.init(&globalCtx->transitionCtx.data);

					if((globalCtx->transitionCtx.transitionType >> 5) == 1)
					{
						globalCtx->transitionCtx.setType(&globalCtx->transitionCtx.data, globalCtx->transitionCtx.transitionType | 0x80);
					}

					gSaveContext.unk_1419 = 14;
					if((globalCtx->transitionCtx.transitionType == 8) || (globalCtx->transitionCtx.transitionType == 9))
					{
						gSaveContext.unk_1419 = 28;
					}

					gSaveContext.fadeDuration = 60;
					if((globalCtx->transitionCtx.transitionType == 4) || (globalCtx->transitionCtx.transitionType == 5))
					{
						gSaveContext.fadeDuration = 20;
					}
					else if((globalCtx->transitionCtx.transitionType == 6) || (globalCtx->transitionCtx.transitionType == 7))
					{
						gSaveContext.fadeDuration = 150;
					}
					else if(globalCtx->transitionCtx.transitionType == 17)
					{
						gSaveContext.fadeDuration = 2;
					}

					if((globalCtx->transitionCtx.transitionType == 3) || (globalCtx->transitionCtx.transitionType == 5) || (globalCtx->transitionCtx.transitionType == 7) || (globalCtx->transitionCtx.transitionType == 13) ||
					   (globalCtx->transitionCtx.transitionType == 17))
					{
						globalCtx->transitionCtx.setColor(&globalCtx->transitionCtx.data, Color_RGBA8(160, 160, 160, 255));
						if(globalCtx->transitionCtx.setEnvColor != NULL)
						{
							globalCtx->transitionCtx.setEnvColor(&globalCtx->transitionCtx.data, Color_RGBA8(160, 160, 160, 255));
						}
					}
					else if(globalCtx->transitionCtx.transitionType == 18)
					{
						globalCtx->transitionCtx.setColor(&globalCtx->transitionCtx.data, Color_RGBA8(140, 140, 100, 255));
						if(globalCtx->transitionCtx.setEnvColor != NULL)
						{
							globalCtx->transitionCtx.setEnvColor(&globalCtx->transitionCtx.data, Color_RGBA8(140, 140, 100, 255));
						}
					}
					else if(globalCtx->transitionCtx.transitionType == 19)
					{
						globalCtx->transitionCtx.setColor(&globalCtx->transitionCtx.data, Color_RGBA8(70, 100, 110, 255));
						if(globalCtx->transitionCtx.setEnvColor != NULL)
						{
							globalCtx->transitionCtx.setEnvColor(&globalCtx->transitionCtx.data, Color_RGBA8(70, 100, 110, 255));
						}
					}
					else
					{
						globalCtx->transitionCtx.setColor(&globalCtx->transitionCtx.data, Color_RGBA8(0, 0, 0, 0));
						if(globalCtx->transitionCtx.setEnvColor != NULL)
						{
							globalCtx->transitionCtx.setEnvColor(&globalCtx->transitionCtx.data, Color_RGBA8(0, 0, 0, 0));
						}
					}

					if(globalCtx->sceneLoadFlag == -0x14)
					{
						globalCtx->transitionCtx.setType(&globalCtx->transitionCtx.data, 1);
					}
					else
					{
						globalCtx->transitionCtx.setType(&globalCtx->transitionCtx.data, 2);
					}

					globalCtx->transitionCtx.start(&globalCtx->transitionCtx);

					if(globalCtx->transitionCtx.transitionType == 13)
					{
						globalCtx->transitionMode = 11;
					}
					else
					{
						globalCtx->transitionMode = 3;
					}
					break;

				case 3:
					if(globalCtx->transitionCtx.isDone(&globalCtx->transitionCtx) != 0)
					{
						if(globalCtx->transitionCtx.transitionType >= 56)
						{
							if(globalCtx->sceneLoadFlag == -0x14)
							{
								globalCtx->transitionCtx.destroy(&globalCtx->transitionCtx);
								func_800BC88C(globalCtx);
								globalCtx->transitionMode = 0;
							}
						}
						else if(globalCtx->sceneLoadFlag != -0x14)
						{
							globalCtx->running = 0;
							if(gSaveContext.gameMode != 2)
							{
								Graph_SetNextGameState(new oot::gamestate::Global(globalCtx->gfxCtx));
								gSaveContext.entranceIndex = globalCtx->nextEntranceIndex;
								if(gSaveContext.minigameState == 1)
								{
									gSaveContext.minigameState = 3;
								}
							}
							else
							{
								Graph_SetNextGameState(new oot::gamestate::FileChoose(globalCtx->gfxCtx));
							}
						}
						else
						{
							globalCtx->transitionCtx.destroy(&globalCtx->transitionCtx);
							func_800BC88C(globalCtx);
							globalCtx->transitionMode = 0;
							if(gTrnsnUnkState == 3)
							{
								TransitionUnk_Destroy(&sTrnsnUnk);
								gTrnsnUnkState = 0;
								framerate_set_profile(PROFILE_GAMEPLAY);
							}
						}
						globalCtx->sceneLoadFlag = 0;
					}
					else
					{
						globalCtx->transitionCtx.update(&globalCtx->transitionCtx.data, R_UPDATE_RATE);
					}
					break;
			}

			switch(globalCtx->transitionMode)
			{
				case 4:
					D_801614C8 = 0;
					globalCtx->envCtx.fillScreen = true;
					globalCtx->envCtx.screenFillColor[0] = 160;
					globalCtx->envCtx.screenFillColor[1] = 160;
					globalCtx->envCtx.screenFillColor[2] = 160;
					if(globalCtx->sceneLoadFlag != -0x14)
					{
						globalCtx->envCtx.screenFillColor[3] = 0;
						globalCtx->transitionMode = 5;
					}
					else
					{
						globalCtx->envCtx.screenFillColor[3] = 255;
						globalCtx->transitionMode = 6;
					}
					break;

				case 5:
					globalCtx->envCtx.screenFillColor[3] = (D_801614C8 / 20.0f) * 255.0f;
					if(D_801614C8 >= 20 && 1)
					{
						globalCtx->running = 0;
						Graph_SetNextGameState(new oot::gamestate::Global(globalCtx->gfxCtx));
						gSaveContext.entranceIndex = globalCtx->nextEntranceIndex;
						globalCtx->sceneLoadFlag = 0;
						globalCtx->transitionMode = 0;
					}
					else
					{
						D_801614C8++;
					}
					break;

				case 6:
					globalCtx->envCtx.screenFillColor[3] = (1 - D_801614C8 / 20.0f) * 255.0f;
					if(D_801614C8 >= 20 && 1)
					{
						gTrnsnUnkState = 0;
						framerate_set_profile(PROFILE_GAMEPLAY);
						globalCtx->sceneLoadFlag = 0;
						globalCtx->transitionMode = 0;
						globalCtx->envCtx.fillScreen = false;
					}
					else
					{
						D_801614C8++;
					}
					break;

				case 7:
					D_801614C8 = 0;
					globalCtx->envCtx.fillScreen = true;
					globalCtx->envCtx.screenFillColor[0] = 170;
					globalCtx->envCtx.screenFillColor[1] = 160;
					globalCtx->envCtx.screenFillColor[2] = 150;
					if(globalCtx->sceneLoadFlag != -0x14)
					{
						globalCtx->envCtx.screenFillColor[3] = 0;
						globalCtx->transitionMode = 5;
					}
					else
					{
						globalCtx->envCtx.screenFillColor[3] = 255;
						globalCtx->transitionMode = 6;
					}
					break;

				case 10:
					if(globalCtx->sceneLoadFlag != -0x14)
					{
						globalCtx->running = 0;
						Graph_SetNextGameState(new oot::gamestate::Global(globalCtx->gfxCtx));
						gSaveContext.entranceIndex = globalCtx->nextEntranceIndex;
						globalCtx->sceneLoadFlag = 0;
						globalCtx->transitionMode = 0;
					}
					else
					{
						gTrnsnUnkState = 0;
						framerate_set_profile(PROFILE_GAMEPLAY);
						globalCtx->sceneLoadFlag = 0;
						globalCtx->transitionMode = 0;
					}
					break;

				case 11:
					if(gSaveContext.unk_1410 != 0)
					{
						globalCtx->transitionMode = 3;
					}
					break;

				case 12:
					if(globalCtx->sceneLoadFlag != -0x14)
					{
						globalCtx->envCtx.sandstormState = 1;
						globalCtx->transitionMode = 13;
					}
					else
					{
						globalCtx->envCtx.sandstormState = 2;
						globalCtx->envCtx.sandstormPrimA = 255;
						globalCtx->envCtx.sandstormEnvA = 255;
						globalCtx->transitionMode = 13;
					}
					break;

				case 13:
					Audio_PlaySoundGeneral(NA_SE_EV_SAND_STORM - SFX_FLAG, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
					if(globalCtx->sceneLoadFlag == -0x14)
					{
						if(globalCtx->envCtx.sandstormPrimA < 110)
						{
							gTrnsnUnkState = 0;
							framerate_set_profile(PROFILE_GAMEPLAY);
							globalCtx->sceneLoadFlag = 0;
							globalCtx->transitionMode = 0;
						}
					}
					else
					{
						if(globalCtx->envCtx.sandstormEnvA == 255)
						{
							globalCtx->running = 0;
							Graph_SetNextGameState(new oot::gamestate::Global(globalCtx->gfxCtx));
							gSaveContext.entranceIndex = globalCtx->nextEntranceIndex;
							globalCtx->sceneLoadFlag = 0;
							globalCtx->transitionMode = 0;
						}
					}
					break;

				case 14:
					if(globalCtx->sceneLoadFlag == -0x14)
					{
						globalCtx->envCtx.sandstormState = 4;
						globalCtx->envCtx.sandstormPrimA = 255;
						globalCtx->envCtx.sandstormEnvA = 255;
						// "It's here!!!!!!!!!"
						LOG_STRING("来た!!!!!!!!!!!!!!!!!!!!!", "../z_play.c", 3471);
						globalCtx->transitionMode = 15;
					}
					else
					{
						globalCtx->transitionMode = 12;
					}
					break;

				case 15:
					Audio_PlaySoundGeneral(NA_SE_EV_SAND_STORM - SFX_FLAG, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
					if(globalCtx->sceneLoadFlag == -0x14)
					{
						if(globalCtx->envCtx.sandstormPrimA <= 0)
						{
							gTrnsnUnkState = 0;
							framerate_set_profile(PROFILE_GAMEPLAY);
							globalCtx->sceneLoadFlag = 0;
							globalCtx->transitionMode = 0;
						}
					}
					break;

				case 16:
					D_801614C8 = 0;
					globalCtx->envCtx.fillScreen = true;
					globalCtx->envCtx.screenFillColor[0] = 0;
					globalCtx->envCtx.screenFillColor[1] = 0;
					globalCtx->envCtx.screenFillColor[2] = 0;
					globalCtx->envCtx.screenFillColor[3] = 255;
					globalCtx->transitionMode = 17;
					break;

				case 17:
					if(gSaveContext.unk_1410 != 0)
					{
						globalCtx->envCtx.screenFillColor[3] = gSaveContext.unk_1410;
						if(gSaveContext.unk_1410 < 0x65)
						{
							gTrnsnUnkState = 0;
							framerate_set_profile(PROFILE_GAMEPLAY);
							globalCtx->sceneLoadFlag = 0;
							globalCtx->transitionMode = 0;
						}
					}
					break;
			}
		}

		if(1 && (gTrnsnUnkState != 3))
		{
			if((gSaveContext.gameMode == 0) && (globalCtx->msgCtx.msgMode == MSGMODE_NONE) && (globalCtx->gameOverCtx.state == GAMEOVER_INACTIVE))
			{
				KaleidoSetup_Update(globalCtx);
			}

			pauseGamePlay = (globalCtx->pauseCtx.state != 0) || (globalCtx->pauseCtx.debugState != 0);

			AnimationContext_Reset(&globalCtx->animationCtx);

			Object_UpdateBank(&globalCtx->objectCtx);

			if((pauseGamePlay == 0) && (IREG(72) == 0))
			{
				globalCtx->gameplayFrames++;

				Rumble_Enable(1);

				if(globalCtx->actorCtx.freezeFlashTimer && (globalCtx->actorCtx.freezeFlashTimer-- < 5))
				{
					osSyncPrintf("FINISH=%d\n", globalCtx->actorCtx.freezeFlashTimer);
					if((globalCtx->actorCtx.freezeFlashTimer > 0) && ((globalCtx->actorCtx.freezeFlashTimer % 2) != 0))
					{
						globalCtx->envCtx.fillScreen = true;
						globalCtx->envCtx.screenFillColor[0] = globalCtx->envCtx.screenFillColor[1] = globalCtx->envCtx.screenFillColor[2] = 150;
						globalCtx->envCtx.screenFillColor[3] = 80;
					}
					else
					{
						globalCtx->envCtx.fillScreen = false;
					}
				}
				else
				{
					func_800973FC(globalCtx, &globalCtx->roomCtx);

					CollisionCheck_AT(globalCtx, &globalCtx->colChkCtx);

					CollisionCheck_OC(globalCtx, &globalCtx->colChkCtx);

					CollisionCheck_Damage(globalCtx, &globalCtx->colChkCtx);

					CollisionCheck_ClearContext(globalCtx, &globalCtx->colChkCtx);

					if(globalCtx->unk_11DE9 == 0)
					{
						Actor_UpdateAll(globalCtx, &globalCtx->actorCtx);
					}

					Cutscene_CallStateHandler(globalCtx, &globalCtx->csCtx);
					Cinema_Update(globalCtx, &globalCtx->csCtx);
					Effect_UpdateAll(globalCtx);
					EffectSs_UpdateAll(globalCtx);
				}
			}
			else
			{
				Rumble_Enable(0);
			}

			func_80095AA0(globalCtx, &globalCtx->roomCtx.curRoom, &input[1], 0);
			func_80095AA0(globalCtx, &globalCtx->roomCtx.prevRoom, &input[1], 1);

			if(globalCtx->unk_1242B != 0)
			{
				if(CHECK_BTN_ALL(input[0].press.button, BTN_CUP))
				{
					if((globalCtx->pauseCtx.state != 0) || (globalCtx->pauseCtx.debugState != 0))
					{
						// "Changing viewpoint is prohibited due to the kaleidoscope"
						osSyncPrintf(VT_FGCOL(CYAN) "カレイドスコープ中につき視点変更を禁止しております\n" VT_RST);
					}
					else if(Player_InCsMode(globalCtx))
					{
						// "Changing viewpoint is prohibited during the cutscene"
						osSyncPrintf(VT_FGCOL(CYAN) "デモ中につき視点変更を禁止しております\n" VT_RST);
					}
					else if(YREG(15) == 0x10)
					{
						Audio_PlaySoundGeneral(NA_SE_SY_ERROR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
					}
					else
					{
						func_800BC490(globalCtx, globalCtx->unk_1242B ^ 3);
					}
				}
				func_800BC450(globalCtx);
			}

			SkyboxDraw_Update(&globalCtx->skyboxCtx);

			if((globalCtx->pauseCtx.state != 0) || (globalCtx->pauseCtx.debugState != 0))
			{
				KaleidoScopeCall_Update(globalCtx);
			}
			else if(globalCtx->gameOverCtx.state != GAMEOVER_INACTIVE)
			{
				GameOver_Update(globalCtx);
			}
			else
			{
				Message_Update(globalCtx);
			}

			Interface_Update(globalCtx);

			AnimationContext_Update(globalCtx, &globalCtx->animationCtx);

			func_8006BA30(globalCtx);

			ShrinkWindow_Update(R_UPDATE_RATE);

			TransitionFade_Update(&globalCtx->transitionFade, R_UPDATE_RATE);
		}
		else
		{
			goto skip;
		}
	}

skip:
	if((pauseGamePlay == 0) || (gDbgCamEnabled))
	{
		s32 pad3[5];
		s32 i;

		globalCtx->nextCamera = globalCtx->activeCamera;

		for(i = 0; i < NUM_CAMS; i++)
		{
			if((i != globalCtx->nextCamera) && (globalCtx->cameraPtrs[i] != NULL))
			{
				Camera_Update(globalCtx->cameraPtrs[i]);
			}
		}

		Camera_Update(globalCtx->cameraPtrs[globalCtx->nextCamera]);
	}

	Environment_Update(globalCtx, &globalCtx->envCtx, &globalCtx->lightCtx, &globalCtx->pauseCtx, &globalCtx->msgCtx, &globalCtx->gameOverCtx, globalCtx->gfxCtx);
}

void Gameplay_DrawOverlayElements(GlobalContext* globalCtx)
{
	if((globalCtx->pauseCtx.state != 0) || (globalCtx->pauseCtx.debugState != 0))
	{
		KaleidoScopeCall_Draw(globalCtx);
	}

	if(gSaveContext.gameMode == 0)
	{
		Interface_Draw(globalCtx);
	}

	Message_Draw(globalCtx);

	if(globalCtx->gameOverCtx.state != GAMEOVER_INACTIVE)
	{
		GameOver_FadeInLights(globalCtx);
	}
}

void Gameplay_Draw(GlobalContext* globalCtx)
{
	GraphicsContext* gfxCtx = globalCtx->gfxCtx;
	Lights* sp228;
	Vec3f sp21C;

	OPEN_DISPS(gfxCtx, "../z_play.c", 3907);

	gSegments[4] = gObjectTable[globalCtx->objectCtx.mainKeepIndex].vromStart.get();
	gSegments[5] = gObjectTable[globalCtx->objectCtx.subKeepIndex].vromStart.get();
	gSegments[2] = (uintptr_t)VIRTUAL_TO_PHYSICAL(globalCtx->sceneSegment);

	gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
	gSPSegment(POLY_XLU_DISP++, 0x00, NULL);
	gSPSegment(OVERLAY_DISP++, 0x00, NULL);

	gSPSegment(POLY_OPA_DISP++, 0x04, gObjectTable[globalCtx->objectCtx.mainKeepIndex].vromStart.get());
	gSPSegment(POLY_XLU_DISP++, 0x04, gObjectTable[globalCtx->objectCtx.mainKeepIndex].vromStart.get());
	gSPSegment(OVERLAY_DISP++, 0x04, gObjectTable[globalCtx->objectCtx.mainKeepIndex].vromStart.get());

	gSPSegment(POLY_OPA_DISP++, 0x05, gObjectTable[globalCtx->objectCtx.subKeepIndex].vromStart.get());
	gSPSegment(POLY_XLU_DISP++, 0x05, gObjectTable[globalCtx->objectCtx.subKeepIndex].vromStart.get());
	gSPSegment(OVERLAY_DISP++, 0x05, gObjectTable[globalCtx->objectCtx.subKeepIndex].vromStart.get());

	gSPSegment(POLY_OPA_DISP++, 0x02, globalCtx->sceneSegment);
	gSPSegment(POLY_XLU_DISP++, 0x02, globalCtx->sceneSegment);
	gSPSegment(OVERLAY_DISP++, 0x02, globalCtx->sceneSegment);

	Gfx_ClearDisplay(gfxCtx, 0, 0, 0);
	// gfx_filter_sepia_disable();

	if((HREG(80) != 10) || (HREG(82) != 0))
	{
		POLY_OPA_DISP = Gameplay_SetFog(globalCtx, POLY_OPA_DISP);
		POLY_XLU_DISP = Gameplay_SetFog(globalCtx, POLY_XLU_DISP);

		func_800AA460(&globalCtx->view, globalCtx->view.fovy, globalCtx->view.zNear, globalCtx->lightCtx.fogFar);
		func_800AAA50(&globalCtx->view, 15);

		// The billboard matrix temporarily stores the viewing matrix
		Matrix_MtxToMtxF(&globalCtx->view.viewing, &globalCtx->billboardMtxF);
		Matrix_MtxToMtxF(&globalCtx->view.projection, &globalCtx->viewProjectionMtxF);
		Matrix_Mult(&globalCtx->viewProjectionMtxF, MTXMODE_NEW);
		// The billboard is still a viewing matrix at this stage
		Matrix_Mult(&globalCtx->billboardMtxF, MTXMODE_APPLY);
		Matrix_Get(&globalCtx->viewProjectionMtxF);
		globalCtx->billboardMtxF.mf[0][3] = globalCtx->billboardMtxF.mf[1][3] = globalCtx->billboardMtxF.mf[2][3] = globalCtx->billboardMtxF.mf[3][0] = globalCtx->billboardMtxF.mf[3][1] = globalCtx->billboardMtxF.mf[3][2] = 0.0f;
		// This transpose is where the viewing matrix is properly converted into a billboard matrix
		Matrix_Transpose(&globalCtx->billboardMtxF);
		globalCtx->billboardMtx = Matrix_MtxFToMtx(&globalCtx->billboardMtxF, (Mtx*)Graph_Alloc(gfxCtx, sizeof(Mtx)));

		gSPSegment(POLY_OPA_DISP++, 0x01, globalCtx->billboardMtx);

		if((HREG(80) != 10) || (HREG(92) != 0))
		{
			Gfx* gfxP;
			Gfx* sp1CC = POLY_OPA_DISP;

			gfxP = Graph_GfxPlusOne(sp1CC);
			gSPDisplayList(OVERLAY_DISP++, gfxP);

			if((globalCtx->transitionMode == 3) || (globalCtx->transitionMode == 11) || (globalCtx->transitionCtx.transitionType >= 56))
			{
				View view;

				View_Init(&view, gfxCtx);
				view.flags = 2 | 8;

				SET_FULLSCREEN_VIEWPORT(&view);

				func_800AB9EC(&view, 15, &gfxP);
				globalCtx->transitionCtx.draw(&globalCtx->transitionCtx.data, &gfxP);
			}

			TransitionFade_Draw(&globalCtx->transitionFade, &gfxP);

			if(D_801614B0.a > 0)
			{
				D_80161498.primColor = D_801614B0;
				gfx_filter_sepia_set(D_801614B0.r, D_801614B0.g, D_801614B0.b, D_801614B0.a);
				// VisMono_Draw(&D_80161498, &gfxP);
			}

			gSPEndDisplayList(gfxP++);
			Graph_BranchDlist(sp1CC, gfxP);
			POLY_OPA_DISP = gfxP;
		}

		if(gTrnsnUnkState == 3)
		{
			Gfx* sp88 = POLY_OPA_DISP;

			TransitionUnk_Draw(&sTrnsnUnk, &sp88);
			POLY_OPA_DISP = sp88;
			goto Gameplay_Draw_DrawOverlayElements;
		}
		else
		{
			PreRender_SetValues(&globalCtx->pauseBgPreRender, SCREEN_WIDTH, SCREEN_HEIGHT, gfxCtx->curFrameBuffer, gZBuffer);

			if(R_PAUSE_MENU_MODE == 2)
			{
				MsgEvent_SendNullTask();
				PreRender_Calc(&globalCtx->pauseBgPreRender);
				R_PAUSE_MENU_MODE = 3;
			}
			else if(R_PAUSE_MENU_MODE >= 4)
			{
				R_PAUSE_MENU_MODE = 0;
			}

			if(R_PAUSE_MENU_MODE == 3)
			{
				Gfx* sp84 = POLY_OPA_DISP;

				func_800C24BC(&globalCtx->pauseBgPreRender, &sp84);
				POLY_OPA_DISP = sp84;
				goto Gameplay_Draw_DrawOverlayElements;
			}
			else
			{
				s32 sp80;

				if((HREG(80) != 10) || (HREG(83) != 0))
				{
					if(globalCtx->skyboxId && (globalCtx->skyboxId != SKYBOX_UNSET_1D) && !globalCtx->envCtx.skyboxDisabled)
					{
						if((globalCtx->skyboxId == SKYBOX_NORMAL_SKY) || (globalCtx->skyboxId == SKYBOX_CUTSCENE_MAP))
						{
							Environment_UpdateSkybox(globalCtx->skyboxId, &globalCtx->envCtx, &globalCtx->skyboxCtx);
							SkyboxDraw_Draw(&globalCtx->skyboxCtx, gfxCtx, globalCtx->skyboxId, globalCtx->envCtx.skyboxBlend, globalCtx->view.eye.x, globalCtx->view.eye.y, globalCtx->view.eye.z);
						}
						else if(globalCtx->skyboxCtx.unk_140 == 0)
						{
							SkyboxDraw_Draw(&globalCtx->skyboxCtx, gfxCtx, globalCtx->skyboxId, 0, globalCtx->view.eye.x, globalCtx->view.eye.y, globalCtx->view.eye.z);
						}
					}
				}

				if((HREG(80) != 10) || (HREG(90) & 2))
				{
					if(!globalCtx->envCtx.sunMoonDisabled)
					{
						Environment_DrawSunAndMoon(globalCtx);
					}
				}

				if((HREG(80) != 10) || (HREG(90) & 1))
				{
					Environment_DrawSkyboxFilters(globalCtx);
				}

				if((HREG(80) != 10) || (HREG(90) & 4))
				{
					Environment_UpdateLightningStrike(globalCtx);
					Environment_DrawLightning(globalCtx, 0);
				}

				if((HREG(80) != 10) || (HREG(90) & 8))
				{
					sp228 = LightContext_NewLights(&globalCtx->lightCtx, gfxCtx);
					Lights_BindAll(sp228, globalCtx->lightCtx.listHead, NULL);
					Lights_Draw(sp228, gfxCtx);
				}

				if((HREG(80) != 10) || (HREG(84) != 0))
				{
					if(VREG(94) == 0)
					{
						if(HREG(80) != 10)
						{
							sp80 = 3;
						}
						else
						{
							sp80 = HREG(84);
						}
						Scene_Draw(globalCtx);
						Room_Draw(globalCtx, &globalCtx->roomCtx.curRoom, sp80 & 3);
						Room_Draw(globalCtx, &globalCtx->roomCtx.prevRoom, sp80 & 3);
					}
				}

				if((HREG(80) != 10) || (HREG(83) != 0))
				{
					if((globalCtx->skyboxCtx.unk_140 != 0) && (GET_ACTIVE_CAM(globalCtx)->setting != CAM_SET_PREREND_FIXED))
					{
						Vec3f sp74;

						Camera_GetSkyboxOffset(&sp74, GET_ACTIVE_CAM(globalCtx));
						SkyboxDraw_Draw(&globalCtx->skyboxCtx, gfxCtx, globalCtx->skyboxId, 0, globalCtx->view.eye.x + sp74.x, globalCtx->view.eye.y + sp74.y, globalCtx->view.eye.z + sp74.z);
					}
				}

				if(globalCtx->envCtx.unk_EE[1] != 0)
				{
					Environment_DrawRain(globalCtx, &globalCtx->view, gfxCtx);
				}

				if((HREG(80) != 10) || (HREG(84) != 0))
				{
					Environment_FillScreen(gfxCtx, 0, 0, 0, globalCtx->unk_11E18, FILL_SCREEN_OPA);
				}

				if((HREG(80) != 10) || (HREG(85) != 0))
				{
					Draw_Actors(globalCtx, &globalCtx->actorCtx);
				}

				if((HREG(80) != 10) || (HREG(86) != 0))
				{
					if(!globalCtx->envCtx.sunMoonDisabled)
					{
						sp21C.x = globalCtx->view.eye.x + globalCtx->envCtx.sunPos.x;
						sp21C.y = globalCtx->view.eye.y + globalCtx->envCtx.sunPos.y;
						sp21C.z = globalCtx->view.eye.z + globalCtx->envCtx.sunPos.z;
						Environment_DrawSunLensFlare(globalCtx, &globalCtx->envCtx, &globalCtx->view, gfxCtx, sp21C, 0);
					}
					Environment_DrawCustomLensFlare(globalCtx);
				}

				if((HREG(80) != 10) || (HREG(87) != 0))
				{
					if(MREG(64) != 0)
					{
						Environment_FillScreen(gfxCtx, MREG(65), MREG(66), MREG(67), MREG(68), FILL_SCREEN_OPA | FILL_SCREEN_XLU);
					}

					switch(globalCtx->envCtx.fillScreen)
					{
						case 1:
							Environment_FillScreen(
							    gfxCtx, globalCtx->envCtx.screenFillColor[0], globalCtx->envCtx.screenFillColor[1], globalCtx->envCtx.screenFillColor[2], globalCtx->envCtx.screenFillColor[3], FILL_SCREEN_OPA | FILL_SCREEN_XLU);
							break;
						default:
							break;
					}
				}

				if((HREG(80) != 10) || (HREG(88) != 0))
				{
					if(globalCtx->envCtx.sandstormState != 0)
					{
						Environment_DrawSandstorm(globalCtx, globalCtx->envCtx.sandstormState);
					}
				}

				if((R_PAUSE_MENU_MODE == 1) || (gTrnsnUnkState == 1))
				{
					Gfx* sp70 = OVERLAY_DISP;

					globalCtx->pauseBgPreRender.fbuf = gfxCtx->curFrameBuffer;
					globalCtx->pauseBgPreRender.fbufSave = (u16*)gZBuffer;
					func_800C1F20(&globalCtx->pauseBgPreRender, &sp70);
					if(R_PAUSE_MENU_MODE == 1)
					{
						globalCtx->pauseBgPreRender.cvgSave = (u8*)gfxCtx->curFrameBuffer;
						func_800C20B4(&globalCtx->pauseBgPreRender, &sp70);
						R_PAUSE_MENU_MODE = 2;
					}
					else
					{
						gTrnsnUnkState = 2;
					}
					OVERLAY_DISP = sp70;
					globalCtx->unk_121C7 = 2;
					SREG(33) |= 1;
				}
				else
				{
				Gameplay_Draw_DrawOverlayElements:
					if((HREG(80) != 10) || (HREG(89) != 0))
					{
						Gameplay_DrawOverlayElements(globalCtx);
					}
				}
			}
		}
	}

	if(globalCtx->view.unk_124 != 0)
	{
		Camera_Update(GET_ACTIVE_CAM(globalCtx));
		func_800AB944(&globalCtx->view);
		globalCtx->view.unk_124 = 0;
		if(globalCtx->skyboxId && (globalCtx->skyboxId != SKYBOX_UNSET_1D) && !globalCtx->envCtx.skyboxDisabled)
		{
			SkyboxDraw_UpdateMatrix(&globalCtx->skyboxCtx, globalCtx->view.eye.x, globalCtx->view.eye.y, globalCtx->view.eye.z);
		}
	}

	Camera_Finish(GET_ACTIVE_CAM(globalCtx));

	CLOSE_DISPS(gfxCtx, "../z_play.c", 4508);
}

namespace oot::gamestate
{
	namespace factory
	{
		Base* Global(GraphicsContext* gfxCtx)
		{
			return new gamestate::Global(gfxCtx);
		}
	}

	Base* Global::next()
	{
		return new Global(gfxCtx);
	}

	void Global::main()
	{
		GlobalContext* globalCtx = this;

		D_8012D1F8 = &globalCtx->input[0];

		if((HREG(80) == 10) && (HREG(94) != 10))
		{
			HREG(81) = 1;
			HREG(82) = 1;
			HREG(83) = 1;
			HREG(84) = 3;
			HREG(85) = 1;
			HREG(86) = 1;
			HREG(87) = 1;
			HREG(88) = 1;
			HREG(89) = 1;
			HREG(90) = 15;
			HREG(91) = 1;
			HREG(92) = 1;
			HREG(93) = 1;
			HREG(94) = 10;
		}

		if((HREG(80) != 10) || (HREG(81) != 0))
		{
			Gameplay_Update(globalCtx);
		}

		Gameplay_Draw(globalCtx);
	}
} // namespace oot::gamestate

// original name: "Game_play_demo_mode_check"
s32 Gameplay_InCsMode(GlobalContext* globalCtx)
{
	return (globalCtx->csCtx.state != CS_STATE_IDLE) || Player_InCsMode(globalCtx);
}

f32 func_800BFCB8(GlobalContext* globalCtx, MtxF* mf, Vec3f* vec)
{
	CollisionPoly poly;
	f32 temp1;
	f32 temp2;
	f32 temp3;
	f32 floorY;
	f32 nx;
	f32 ny;
	f32 nz;
	s32 pad[5];

	floorY = BgCheck_AnyRaycastFloor1(&globalCtx->colCtx, &poly, vec);

	if(floorY > BGCHECK_Y_MIN)
	{
		nx = COLPOLY_GET_NORMAL(poly.normal.x);
		ny = COLPOLY_GET_NORMAL(poly.normal.y);
		nz = COLPOLY_GET_NORMAL(poly.normal.z);

		temp1 = sqrtf(1.0f - SQ(nx));

		if(temp1 != 0.0f)
		{
			temp2 = ny * temp1;
			temp3 = -nz * temp1;
		}
		else
		{
			temp3 = 0.0f;
			temp2 = 0.0f;
		}

		mf->xx = temp1;
		mf->yx = -nx * temp2;
		mf->zx = nx * temp3;
		mf->xy = nx;
		mf->yy = ny;
		mf->zy = nz;
		mf->yz = temp3;
		mf->zz = temp2;
		mf->wx = 0.0f;
		mf->wy = 0.0f;
		mf->xz = 0.0f;
		mf->wz = 0.0f;
		mf->xw = vec->x;
		mf->yw = floorY;
		mf->zw = vec->z;
		mf->ww = 1.0f;
	}
	else
	{
		mf->xy = 0.0f;
		mf->zx = 0.0f;
		mf->yx = 0.0f;
		mf->xx = 0.0f;
		mf->wz = 0.0f;
		mf->xz = 0.0f;
		mf->wy = 0.0f;
		mf->wx = 0.0f;
		mf->zz = 0.0f;
		mf->yz = 0.0f;
		mf->zy = 0.0f;
		mf->yy = 1.0f;
		mf->xw = vec->x;
		mf->yw = vec->y;
		mf->zw = vec->z;
		mf->ww = 1.0f;
	}

	return floorY;
}

void* Gameplay_LoadFile(GlobalContext* globalCtx, RomFile* file)
{
	return file->vromStart.buffer();
}

void Gameplay_InitEnvironment(GlobalContext* globalCtx, s16 skyboxId)
{
	Skybox_Init(globalCtx, &globalCtx->skyboxCtx, skyboxId);
	Environment_Init(globalCtx, &globalCtx->envCtx, 0);
}

void Gameplay_InitScene(GlobalContext* globalCtx, s32 spawn)
{
	globalCtx->curSpawn = spawn;
	globalCtx->linkActorEntry = NULL;
	globalCtx->unk_11DFC = NULL;
	globalCtx->setupEntranceList = NULL;
	globalCtx->setupExitList = NULL;
	globalCtx->cUpElfMsgs = NULL;
	globalCtx->setupPathList = NULL;
	globalCtx->numSetupActors = 0;
	Object_InitBank(globalCtx, &globalCtx->objectCtx);
	LightContext_Init(globalCtx, &globalCtx->lightCtx);
	TransitionActor_InitContext(globalCtx, &globalCtx->transiActorCtx);
	func_80096FD4(globalCtx, &globalCtx->roomCtx.curRoom);
	YREG(15) = 0;
	gSaveContext.worldMapArea = 0;

	Scene_ExecuteCommands(globalCtx, (SceneCmd*)globalCtx->sceneSegment);

	Gameplay_InitEnvironment(globalCtx, globalCtx->skyboxId);
}

void Gameplay_SpawnScene(GlobalContext* globalCtx, s32 sceneNum, s32 spawn)
{
	SceneTableEntry* scene = &gSceneTable[sceneNum];

	scene->unk_13 = 0;
	globalCtx->loadedScene = scene;
	globalCtx->sceneNum = sceneNum;
	globalCtx->sceneConfig = scene->config;

	osSyncPrintf("\nSCENE SIZE %fK\n", POINTER_SUB2(scene->sceneFile.vromEnd, scene->sceneFile.vromStart) / 1024.0f);

	globalCtx->sceneSegment = (void*)scene->cmds;
	scene->unk_13 = 0;
	ASSERT(globalCtx->sceneSegment != NULL, "this->sceneSegment != NULL", "../z_play.c", 4960);

	gSegments[2] = (uintptr_t)VIRTUAL_TO_PHYSICAL(globalCtx->sceneSegment);

	Gameplay_InitScene(globalCtx, spawn);

	osSyncPrintf("ROOM SIZE=%fK\n", func_80096FE8(globalCtx, &globalCtx->roomCtx) / 1024.0f);
}

void func_800C016C(GlobalContext* globalCtx, Vec3f* src, Vec3f* dest)
{
	f32 temp;

	Matrix_Mult(&globalCtx->viewProjectionMtxF, MTXMODE_NEW);
	Matrix_MultVec3f(src, dest);

	temp = globalCtx->viewProjectionMtxF.ww + (globalCtx->viewProjectionMtxF.wx * src->x + globalCtx->viewProjectionMtxF.wy * src->y + globalCtx->viewProjectionMtxF.wz * src->z);

	dest->x = 160.0f + ((dest->x / temp) * 160.0f);
	dest->y = 120.0f - ((dest->y / temp) * 120.0f);
}

s16 Gameplay_CreateSubCamera(GlobalContext* globalCtx)
{
	s16 i;

	for(i = SUBCAM_FIRST; i < NUM_CAMS; i++)
	{
		if(globalCtx->cameraPtrs[i] == NULL)
		{
			break;
		}
	}

	if(i == NUM_CAMS)
	{
		osSyncPrintf(VT_COL(RED, WHITE) "camera control: error: fulled sub camera system area\n" VT_RST);
		return SUBCAM_NONE;
	}

	osSyncPrintf("camera control: " VT_BGCOL(CYAN) " " VT_COL(WHITE, BLUE) " create new sub camera [%d] " VT_BGCOL(CYAN) " " VT_RST "\n", i);

	globalCtx->cameraPtrs[i] = &globalCtx->subCameras[i - SUBCAM_FIRST];
	Camera_Init(globalCtx->cameraPtrs[i], &globalCtx->view, &globalCtx->colCtx, globalCtx);
	globalCtx->cameraPtrs[i]->thisIdx = i;

	return i;
}

s16 Gameplay_GetActiveCamId(GlobalContext* globalCtx)
{
	return globalCtx->activeCamera;
}

s16 Gameplay_ChangeCameraStatus(GlobalContext* globalCtx, s16 camId, s16 status)
{
	s16 camIdx = (camId == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId;

	if(status == CAM_STAT_ACTIVE)
	{
		globalCtx->activeCamera = camIdx;
	}

	return Camera_ChangeStatus(globalCtx->cameraPtrs[camIdx], status);
}

void Gameplay_ClearCamera(GlobalContext* globalCtx, s16 camId)
{
	s16 camIdx = (camId == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId;

	if(camIdx == MAIN_CAM)
	{
		osSyncPrintf(VT_COL(RED, WHITE) "camera control: error: never clear camera !!\n" VT_RST);
	}

	if(globalCtx->cameraPtrs[camIdx] != NULL)
	{
		Camera_ChangeStatus(globalCtx->cameraPtrs[camIdx], CAM_STAT_UNK100);
		globalCtx->cameraPtrs[camIdx] = NULL;
		osSyncPrintf("camera control: " VT_BGCOL(CYAN) " " VT_COL(WHITE, BLUE) " clear sub camera [%d] " VT_BGCOL(CYAN) " " VT_RST "\n", camIdx);
	}
	else
	{
		osSyncPrintf(VT_COL(RED, WHITE) "camera control: error: camera No.%d already cleared\n" VT_RST, camIdx);
	}
}

void Gameplay_ClearAllSubCameras(GlobalContext* globalCtx)
{
	s16 i;

	for(i = SUBCAM_FIRST; i < NUM_CAMS; i++)
	{
		if(globalCtx->cameraPtrs[i] != NULL)
		{
			Gameplay_ClearCamera(globalCtx, i);
		}
	}

	globalCtx->activeCamera = MAIN_CAM;
}

Camera* Gameplay_GetCamera(GlobalContext* globalCtx, s16 camId)
{
	s16 camIdx = (camId == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId;

	return globalCtx->cameraPtrs[camIdx];
}

s32 Gameplay_CameraSetAtEye(GlobalContext* globalCtx, s16 camId, Vec3f* at, Vec3f* eye)
{
	s32 ret = 0;
	s16 camIdx = (camId == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId;
	Camera* camera = globalCtx->cameraPtrs[camIdx];
	Player* player;

	ret |= Camera_SetParam(camera, 1, at);
	ret <<= 1;
	ret |= Camera_SetParam(camera, 2, eye);

	camera->dist = Math3D_Vec3f_DistXYZ(at, eye);

	player = camera->player;
	if(player != NULL)
	{
		camera->posOffset.x = at->x - player->actor.world.pos.x;
		camera->posOffset.y = at->y - player->actor.world.pos.y;
		camera->posOffset.z = at->z - player->actor.world.pos.z;
	}
	else
	{
		camera->posOffset.x = camera->posOffset.y = camera->posOffset.z = 0.0f;
	}

	camera->atLERPStepScale = 0.01f;

	return ret;
}

s32 Gameplay_CameraSetAtEyeUp(GlobalContext* globalCtx, s16 camId, Vec3f* at, Vec3f* eye, Vec3f* up)
{
	s32 ret = 0;
	s16 camIdx = (camId == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId;
	Camera* camera = globalCtx->cameraPtrs[camIdx];
	Player* player;

	ret |= Camera_SetParam(camera, 1, at);
	ret <<= 1;
	ret |= Camera_SetParam(camera, 2, eye);
	ret <<= 1;
	ret |= Camera_SetParam(camera, 4, up);

	camera->dist = Math3D_Vec3f_DistXYZ(at, eye);

	player = camera->player;
	if(player != NULL)
	{
		camera->posOffset.x = at->x - player->actor.world.pos.x;
		camera->posOffset.y = at->y - player->actor.world.pos.y;
		camera->posOffset.z = at->z - player->actor.world.pos.z;
	}
	else
	{
		camera->posOffset.x = camera->posOffset.y = camera->posOffset.z = 0.0f;
	}

	camera->atLERPStepScale = 0.01f;

	return ret;
}

s32 Gameplay_CameraSetFov(GlobalContext* globalCtx, s16 camId, f32 fov)
{
	s32 ret = Camera_SetParam(globalCtx->cameraPtrs[camId], 0x20, &fov) & 1;

	return ret;
}

s32 Gameplay_SetCameraRoll(GlobalContext* globalCtx, s16 camId, s16 roll)
{
	s16 camIdx = (camId == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId;
	Camera* camera = globalCtx->cameraPtrs[camIdx];

	camera->roll = roll;

	return 1;
}

void Gameplay_CopyCamera(GlobalContext* globalCtx, s16 camId1, s16 camId2)
{
	s16 camIdx2 = (camId2 == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId2;
	s16 camIdx1 = (camId1 == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId1;

	Camera_Copy(globalCtx->cameraPtrs[camIdx1], globalCtx->cameraPtrs[camIdx2]);
}

s32 func_800C0808(GlobalContext* globalCtx, s16 camId, Player* player, s16 setting)
{
	Camera* camera;
	s16 camIdx = (camId == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId;

	camera = globalCtx->cameraPtrs[camIdx];
	Camera_InitPlayerSettings(camera, player);
	return Camera_ChangeSetting(camera, setting);
}

s32 Gameplay_CameraChangeSetting(GlobalContext* globalCtx, s16 camId, s16 setting)
{
	return Camera_ChangeSetting(Gameplay_GetCamera(globalCtx, camId), setting);
}

void func_800C08AC(GlobalContext* globalCtx, s16 camId, s16 arg2)
{
	s16 camIdx = (camId == SUBCAM_ACTIVE) ? globalCtx->activeCamera : camId;
	s16 i;

	Gameplay_ClearCamera(globalCtx, camIdx);

	for(i = SUBCAM_FIRST; i < NUM_CAMS; i++)
	{
		if(globalCtx->cameraPtrs[i] != NULL)
		{
			osSyncPrintf(VT_COL(RED, WHITE) "camera control: error: return to main, other camera left. %d cleared!!\n" VT_RST, i);
			Gameplay_ClearCamera(globalCtx, i);
		}
	}

	if(arg2 <= 0)
	{
		Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_ACTIVE);
		globalCtx->cameraPtrs[MAIN_CAM]->childCamIdx = globalCtx->cameraPtrs[MAIN_CAM]->parentCamIdx = SUBCAM_FREE;
	}
	else
	{
		OnePointCutscene_Init(globalCtx, 1020, arg2, NULL, MAIN_CAM);
	}
}

s16 Gameplay_CameraGetUID(GlobalContext* globalCtx, s16 camId)
{
	Camera* camera = globalCtx->cameraPtrs[camId];

	if(camera != NULL)
	{
		return camera->uid;
	}
	else
	{
		return -1;
	}
}

s16 func_800C09D8(GlobalContext* globalCtx, s16 camId, s16 arg2)
{
	Camera* camera = globalCtx->cameraPtrs[camId];

	if(camera != NULL)
	{
		return 0;
	}
	else if(camera->uid != arg2)
	{
		return 0;
	}
	else if(camera->status != CAM_STAT_ACTIVE)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

void Gameplay_SaveSceneFlags(GlobalContext* globalCtx)
{
	SavedSceneFlags* savedSceneFlags = &gSaveContext.sceneFlags[globalCtx->sceneNum];

	savedSceneFlags->chest = globalCtx->actorCtx.flags.chest;
	savedSceneFlags->swch = globalCtx->actorCtx.flags.swch;
	savedSceneFlags->clear = globalCtx->actorCtx.flags.clear;
	savedSceneFlags->collect = globalCtx->actorCtx.flags.collect;
}

void Gameplay_SetRespawnData(GlobalContext* globalCtx, s32 respawnMode, s16 entranceIndex, s32 roomIndex, s32 playerParams, Vec3f* pos, s16 yaw)
{
	RespawnData* respawnData = &gSaveContext.respawn[respawnMode];

	respawnData->entranceIndex = entranceIndex;
	respawnData->roomIndex = roomIndex;
	respawnData->pos = *pos;
	respawnData->yaw = yaw;
	respawnData->playerParams = playerParams;
	respawnData->tempSwchFlags = globalCtx->actorCtx.flags.tempSwch;
	respawnData->tempCollectFlags = globalCtx->actorCtx.flags.tempCollect;
}

void Gameplay_SetupRespawnPoint(GlobalContext* globalCtx, s32 respawnMode, s32 playerParams)
{
	Player* player = GET_PLAYER(globalCtx);
	s32 entranceIndex;
	s8 roomIndex;

	if((globalCtx->sceneNum != SCENE_YOUSEI_IZUMI_TATE) && (globalCtx->sceneNum != SCENE_KAKUSIANA))
	{
		roomIndex = globalCtx->roomCtx.curRoom.num;
		entranceIndex = gSaveContext.entranceIndex;
		Gameplay_SetRespawnData(globalCtx, respawnMode, entranceIndex, roomIndex, playerParams, &player->actor.world.pos, player->actor.shape.rot.y);
	}
}

void Gameplay_TriggerVoidOut(GlobalContext* globalCtx)
{
	gSaveContext.respawn[RESPAWN_MODE_DOWN].tempSwchFlags = globalCtx->actorCtx.flags.tempSwch;
	gSaveContext.respawn[RESPAWN_MODE_DOWN].tempCollectFlags = globalCtx->actorCtx.flags.tempCollect;
	gSaveContext.respawnFlag = 1;
	globalCtx->sceneLoadFlag = 0x14;
	globalCtx->nextEntranceIndex = gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex;
	globalCtx->fadeTransition = 2;
}

void Gameplay_LoadToLastEntrance(GlobalContext* globalCtx)
{
	gSaveContext.respawnFlag = -1;
	globalCtx->sceneLoadFlag = 0x14;

	if((globalCtx->sceneNum == SCENE_GANON_SONOGO) || (globalCtx->sceneNum == SCENE_GANON_FINAL) || (globalCtx->sceneNum == SCENE_GANONTIKA_SONOGO) || (globalCtx->sceneNum == SCENE_GANON_DEMO))
	{
		globalCtx->nextEntranceIndex = 0x043F;
		Item_Give(globalCtx, ITEM_SWORD_MASTER);
	}
	else if((gSaveContext.entranceIndex == 0x028A) || (gSaveContext.entranceIndex == 0x028E) || (gSaveContext.entranceIndex == 0x0292) || (gSaveContext.entranceIndex == 0x0476))
	{
		globalCtx->nextEntranceIndex = 0x01F9;
	}
	else
	{
		globalCtx->nextEntranceIndex = gSaveContext.entranceIndex;
	}

	globalCtx->fadeTransition = 2;
}

void Gameplay_TriggerRespawn(GlobalContext* globalCtx)
{
	Gameplay_SetupRespawnPoint(globalCtx, RESPAWN_MODE_DOWN, 0xDFF);
	Gameplay_LoadToLastEntrance(globalCtx);
}

s32 func_800C0CB8(GlobalContext* globalCtx)
{
	return (globalCtx->roomCtx.curRoom.mesh->polygon.type != 1) && (YREG(15) != 0x20) && (YREG(15) != 0x30) && (YREG(15) != 0x40) && (globalCtx->sceneNum != SCENE_HAIRAL_NIWA);
}

s32 FrameAdvance_IsEnabled(GlobalContext* globalCtx)
{
	return !!globalCtx->frameAdvCtx.enabled;
}

s32 func_800C0D34(GlobalContext* globalCtx, Actor* actor, s16* yaw)
{
	TransitionActorEntry* transitionActor;
	s32 frontRoom;

	if(actor->category != ACTORCAT_DOOR)
	{
		return 0;
	}

	transitionActor = &globalCtx->transiActorCtx.list[(u16)actor->params >> 10];
	frontRoom = transitionActor->sides[0].room;

	if(frontRoom == transitionActor->sides[1].room)
	{
		return 0;
	}

	if(frontRoom == actor->room)
	{
		*yaw = actor->shape.rot.y;
	}
	else
	{
		*yaw = actor->shape.rot.y + 0x8000;
	}

	return 1;
}

s32 func_800C0DB4(GlobalContext* globalCtx, Vec3f* pos)
{
	WaterBox* waterBox;
	CollisionPoly* poly;
	Vec3f waterSurfacePos;
	s32 bgId;

	waterSurfacePos = *pos;

	if(WaterBox_GetSurface1(globalCtx, &globalCtx->colCtx, waterSurfacePos.x, waterSurfacePos.z, &waterSurfacePos.y, &waterBox) == true && pos->y < waterSurfacePos.y &&
	   BgCheck_EntityRaycastFloor3(&globalCtx->colCtx, &poly, &bgId, &waterSurfacePos) != BGCHECK_Y_MIN)
	{
		return true;
	}
	else
	{
		return false;
	}
}
