#define INTERNAL_SRC_CODE_Z_MAP_EXP_C
#include "global.h"
#include "z64global.h"
#include "gfx_align.h"
#include "n64mapdata.h"
#include "segment_symbols.h"
#include "sfx.h"
#include "textures/map_grand_static/map_grand_static.h"
#include "textures/map_i_static/map_i_static.h"
#include "textures/parameter_static/parameter_static.h"
#include "vt.h"
#include "z64item.h"
#include "z64player.h"
#include "z64save.h"
#include "def/audio_bank.h"
#include "def/game.h"
#include "def/graph.h" // FORCE
#include "def/inventory.h"
#include "def/sys_matrix.h"
#include "def/z_map_data.h"
#include "def/z_map_exp.h"
#include "def/z_map_mark.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_std_dma.h"
#include "objects/gameplay_keep/gameplay_keep.h"

MapData* gMapData;
extern MapData gMapDataTable;

s16 sPlayerInitialPosX = 0;
s16 sPlayerInitialPosZ = 0;
s16 sPlayerInitialDirection = 0;
s16 sEntranceIconMapIndex = 0;

void Map_SavePlayerInitialInfo(GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	sPlayerInitialPosX = player->actor.world.pos.x;
	sPlayerInitialPosZ = player->actor.world.pos.z;
	sPlayerInitialDirection = (s16)((0x7FFF - player->actor.shape.rot.y) / 0x400);
}

void Map_SetPaletteData(GlobalContext* globalCtx, s16 room)
{
	s32 mapIndex = gSaveContext.mapIndex;
	InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
	s16 paletteIndex = gMapData->roomPalette[mapIndex][room];

	if(interfaceCtx->mapRoomNum == room)
	{
		interfaceCtx->mapPaletteIndex = paletteIndex;
	}

	osSyncPrintf(VT_FGCOL(YELLOW));
	// "PALETE Set"
	osSyncPrintf("Palette【 i=%x : room=%x 】Room_Inf[%d][4]=%x  ( map_palete_no = %d )\n", paletteIndex, room, mapIndex, gSaveContext.sceneFlags[mapIndex].rooms, interfaceCtx->mapPaletteIndex);
	osSyncPrintf(VT_RST);

	interfaceCtx->mapPalette[paletteIndex * 2] = 2;
	interfaceCtx->mapPalette[paletteIndex * 2 + 1] = 0xBF;
}

void Map_SetFloorPalettesData(GlobalContext* globalCtx, s16 floor)
{
	s32 mapIndex = gSaveContext.mapIndex;
	InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
	s16 room;
	s16 i;

	for(i = 0; i < 16; i++)
	{
		interfaceCtx->mapPalette[i] = 0;
		interfaceCtx->mapPalette[i + 16] = 0;
	}

	if(CHECK_DUNGEON_ITEM(DUNGEON_MAP, mapIndex))
	{
		interfaceCtx->mapPalette[30] = 0;
		interfaceCtx->mapPalette[31] = 1;
	}

	switch(globalCtx->sceneNum)
	{
		case SCENE_YDAN:
		case SCENE_DDAN:
		case SCENE_BDAN:
		case SCENE_BMORI1:
		case SCENE_HIDAN:
		case SCENE_MIZUSIN:
		case SCENE_JYASINZOU:
		case SCENE_HAKADAN:
		case SCENE_HAKADANCH:
		case SCENE_ICE_DOUKUTO:
		case SCENE_YDAN_BOSS:
		case SCENE_DDAN_BOSS:
		case SCENE_BDAN_BOSS:
		case SCENE_MORIBOSSROOM:
		case SCENE_FIRE_BS:
		case SCENE_MIZUSIN_BS:
		case SCENE_JYASINBOSS:
		case SCENE_HAKADAN_BS:
			for(i = 0; i < gMapData->maxPaletteCount[mapIndex]; i++)
			{
				room = gMapData->paletteRoom[mapIndex][floor][i];
				if((room != 0xFF) && (gSaveContext.sceneFlags[mapIndex].rooms & gBitFlags[room]))
				{
					Map_SetPaletteData(globalCtx, room);
				}
			}
			break;
	}
}

void Map_InitData(GlobalContext* globalCtx, s16 room)
{
	s32 mapIndex = gSaveContext.mapIndex;
	InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
	s16 extendedMapIndex;

	switch(globalCtx->sceneNum)
	{
		case SCENE_SPOT00:
		case SCENE_SPOT01:
		case SCENE_SPOT02:
		case SCENE_SPOT03:
		case SCENE_SPOT04:
		case SCENE_SPOT05:
		case SCENE_SPOT06:
		case SCENE_SPOT07:
		case SCENE_SPOT08:
		case SCENE_SPOT09:
		case SCENE_SPOT10:
		case SCENE_SPOT11:
		case SCENE_SPOT12:
		case SCENE_SPOT13:
		case SCENE_SPOT15:
		case SCENE_SPOT16:
		case SCENE_SPOT17:
		case SCENE_SPOT18:
		case SCENE_SPOT20:
		case SCENE_GANON_TOU:
			extendedMapIndex = mapIndex;
			if(globalCtx->sceneNum == SCENE_SPOT02)
			{
				if(CHECK_QUEST_ITEM(QUEST_SONG_NOCTURNE))
				{
					extendedMapIndex = 0x14;
				}
			}
			else if(globalCtx->sceneNum == SCENE_SPOT06)
			{
				if((LINK_AGE_IN_YEARS == YEARS_ADULT) && !CHECK_QUEST_ITEM(QUEST_MEDALLION_WATER))
				{
					extendedMapIndex = 0x15;
				}
			}
			else if(globalCtx->sceneNum == SCENE_SPOT09)
			{
				if((LINK_AGE_IN_YEARS == YEARS_ADULT) && !((gSaveContext.eventChkInf[9] & 0xF) == 0xF))
				{
					extendedMapIndex = 0x16;
				}
			}
			else if(globalCtx->sceneNum == SCENE_SPOT12)
			{
				if((gSaveContext.eventChkInf[9] & 0xF) == 0xF)
				{
					extendedMapIndex = 0x17;
				}
			}
			osSyncPrintf(VT_FGCOL(BLUE));
			osSyncPrintf("ＫＫＫ＝%d\n", extendedMapIndex);
			osSyncPrintf(VT_RST);
			sEntranceIconMapIndex = extendedMapIndex;

			interfaceCtx->mapSegment1 = (u8*)POINTER_ADD(_map_grand_staticSegmentRomStart, gMapData->owMinimapTexOffset[extendedMapIndex]);

			// interfaceCtx->mapSegment = map_grand_static_lut[extendedMapIndex];
			interfaceCtx->unk_258 = mapIndex;
			break;
		case SCENE_YDAN:
		case SCENE_DDAN:
		case SCENE_BDAN:
		case SCENE_BMORI1:
		case SCENE_HIDAN:
		case SCENE_MIZUSIN:
		case SCENE_JYASINZOU:
		case SCENE_HAKADAN:
		case SCENE_HAKADANCH:
		case SCENE_ICE_DOUKUTO:
		case SCENE_YDAN_BOSS:
		case SCENE_DDAN_BOSS:
		case SCENE_BDAN_BOSS:
		case SCENE_MORIBOSSROOM:
		case SCENE_FIRE_BS:
		case SCENE_MIZUSIN_BS:
		case SCENE_JYASINBOSS:
		case SCENE_HAKADAN_BS:
			osSyncPrintf(VT_FGCOL(YELLOW));
			osSyncPrintf("Deku Tree Dungeon MAP Texture DMA(%x) scene_id_offset=%d  VREG(30)=%d\n", room, mapIndex, VREG(30));
			osSyncPrintf(VT_RST);
			globalCtx->interfaceCtx.mapSegment1 = (u8*)map_i_static_lut[gMapData->dgnMinimapTexIndexOffset[mapIndex] + room];
			R_COMPASS_OFFSET_X = gMapData->roomCompassOffsetX[mapIndex][room];
			R_COMPASS_OFFSET_Y = gMapData->roomCompassOffsetY[mapIndex][room];
			Map_SetFloorPalettesData(globalCtx, VREG(30));
			osSyncPrintf("MAP Individual Floor ON Check\n");
			break;
	}
}

void Map_InitRoomData(GlobalContext* globalCtx, s16 room)
{
	s32 mapIndex = gSaveContext.mapIndex;
	InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

	osSyncPrintf("＊＊＊＊＊＊＊\n＊＊＊＊＊＊＊\nroom_no=%d (%d)(%d)\n＊＊＊＊＊＊＊\n＊＊＊＊＊＊＊\n", room, mapIndex, globalCtx->sceneNum);

	if(room >= 0)
	{
		switch(globalCtx->sceneNum)
		{
			case SCENE_YDAN:
			case SCENE_DDAN:
			case SCENE_BDAN:
			case SCENE_BMORI1:
			case SCENE_HIDAN:
			case SCENE_MIZUSIN:
			case SCENE_JYASINZOU:
			case SCENE_HAKADAN:
			case SCENE_HAKADANCH:
			case SCENE_ICE_DOUKUTO:
			case SCENE_YDAN_BOSS:
			case SCENE_DDAN_BOSS:
			case SCENE_BDAN_BOSS:
			case SCENE_MORIBOSSROOM:
			case SCENE_FIRE_BS:
			case SCENE_MIZUSIN_BS:
			case SCENE_JYASINBOSS:
			case SCENE_HAKADAN_BS:
				gSaveContext.sceneFlags[mapIndex].rooms |= gBitFlags[room];
				osSyncPrintf("Room_inf＝%d\n", gSaveContext.sceneFlags[mapIndex].rooms);
				interfaceCtx->mapRoomNum = room;
				interfaceCtx->unk_25A = mapIndex;
				Map_SetPaletteData(globalCtx, room);
				osSyncPrintf(VT_FGCOL(YELLOW));
				osSyncPrintf("Room room＝%d\n", room);
				osSyncPrintf(VT_RST);
				Map_InitData(globalCtx, room);
				break;
		}
	}
	else
	{
		interfaceCtx->mapRoomNum = 0;
	}

	if(gSaveContext.sunsSongState != SUNSSONG_SPEED_TIME)
	{
		gSaveContext.sunsSongState = SUNSSONG_INACTIVE;
	}
}

void Map_Destroy(GlobalContext* globalCtx)
{
	MapMark_ClearPointers(globalCtx);
	gMapData = NULL;
}

void Map_Init(GlobalContext* globalCtx)
{
	s32 mapIndex = gSaveContext.mapIndex;
	InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

	gMapData = &gMapDataTable;

	interfaceCtx->unk_258 = -1;
	interfaceCtx->unk_25A = -1;

	interfaceCtx->mapSegment1 = NULL;
	interfaceCtx->mapSegment2 = NULL;

	switch(globalCtx->sceneNum)
	{
		case SCENE_SPOT00:
		case SCENE_SPOT01:
		case SCENE_SPOT02:
		case SCENE_SPOT03:
		case SCENE_SPOT04:
		case SCENE_SPOT05:
		case SCENE_SPOT06:
		case SCENE_SPOT07:
		case SCENE_SPOT08:
		case SCENE_SPOT09:
		case SCENE_SPOT10:
		case SCENE_SPOT11:
		case SCENE_SPOT12:
		case SCENE_SPOT13:
		case SCENE_SPOT15:
		case SCENE_SPOT16:
		case SCENE_SPOT17:
		case SCENE_SPOT18:
		case SCENE_SPOT20:
		case SCENE_GANON_TOU:
			mapIndex = globalCtx->sceneNum - SCENE_SPOT00;
			R_MAP_INDEX = gSaveContext.mapIndex = mapIndex;
			R_COMPASS_SCALE_X = gMapData->owCompassInfo[mapIndex][0];
			R_COMPASS_SCALE_Y = gMapData->owCompassInfo[mapIndex][1];
			R_COMPASS_OFFSET_X = gMapData->owCompassInfo[mapIndex][2];
			R_COMPASS_OFFSET_Y = gMapData->owCompassInfo[mapIndex][3];
			Map_InitData(globalCtx, mapIndex);
			R_OW_MINIMAP_X = gMapData->owMinimapPosX[mapIndex];
			R_OW_MINIMAP_Y = gMapData->owMinimapPosY[mapIndex];
			break;
		case SCENE_YDAN:
		case SCENE_DDAN:
		case SCENE_BDAN:
		case SCENE_BMORI1:
		case SCENE_HIDAN:
		case SCENE_MIZUSIN:
		case SCENE_JYASINZOU:
		case SCENE_HAKADAN:
		case SCENE_HAKADANCH:
		case SCENE_ICE_DOUKUTO:
		case SCENE_GANON:
		case SCENE_MEN:
		case SCENE_GERUDOWAY:
		case SCENE_GANONTIKA:
		case SCENE_GANON_SONOGO:
		case SCENE_GANONTIKA_SONOGO:
		case SCENE_TAKARAYA:
		case SCENE_YDAN_BOSS:
		case SCENE_DDAN_BOSS:
		case SCENE_BDAN_BOSS:
		case SCENE_MORIBOSSROOM:
		case SCENE_FIRE_BS:
		case SCENE_MIZUSIN_BS:
		case SCENE_JYASINBOSS:
		case SCENE_HAKADAN_BS:
			mapIndex = (globalCtx->sceneNum >= SCENE_YDAN_BOSS) ? globalCtx->sceneNum - SCENE_YDAN_BOSS : globalCtx->sceneNum;
			R_MAP_INDEX = gSaveContext.mapIndex = mapIndex;
			if((globalCtx->sceneNum <= SCENE_ICE_DOUKUTO) || (globalCtx->sceneNum >= SCENE_YDAN_BOSS))
			{
				R_COMPASS_SCALE_X = gMapData->dgnCompassInfo[mapIndex][0];
				R_COMPASS_SCALE_Y = gMapData->dgnCompassInfo[mapIndex][1];
				R_COMPASS_OFFSET_X = gMapData->dgnCompassInfo[mapIndex][2];
				R_COMPASS_OFFSET_Y = gMapData->dgnCompassInfo[mapIndex][3];
				R_MAP_TEX_INDEX = R_MAP_TEX_INDEX_BASE = gMapData->dgnMinimapTexIndexBase[mapIndex];
				Map_InitRoomData(globalCtx, globalCtx->roomCtx.curRoom.num);
				MapMark_Init(globalCtx);
			}
			break;
	}
}

void Minimap_DrawCompassIcons(GlobalContext* globalCtx)
{
	s32 pad;
	Player* player = GET_PLAYER(globalCtx);
	s16 tempX, tempZ;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_map_exp.c", 565);

	if(globalCtx->interfaceCtx.minimapAlpha >= 0xAA)
	{
		func_80094A14(globalCtx->gfxCtx);

		gSPMatrix(OVERLAY_DISP++, &gMtxClear, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
		gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, 255);
		gDPSetCombineMode(OVERLAY_DISP++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

		tempX = player->actor.world.pos.x;
		tempZ = player->actor.world.pos.z;
		tempX /= R_COMPASS_SCALE_X;
		tempZ /= R_COMPASS_SCALE_Y;
		Matrix_Translate(GFX_ALIGN_RIGHT_F((R_COMPASS_OFFSET_X + tempX) / 10.0f), (R_COMPASS_OFFSET_Y - tempZ) / 10.0f, 0.0f, MTXMODE_NEW);
		Matrix_Scale(0.4f, 0.4f, 0.4f, MTXMODE_APPLY);
		Matrix_RotateX(-1.6f, MTXMODE_APPLY);
		tempX = (0x7FFF - player->actor.shape.rot.y) / 0x400;
		Matrix_RotateY(tempX / 10.0f, MTXMODE_APPLY);
		gSPMatrix(OVERLAY_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_map_exp.c", 585), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

		gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 200, 255, 0, 255);
		gSPDisplayList(OVERLAY_DISP++, gCompassArrowDL);

		tempX = sPlayerInitialPosX;
		tempZ = sPlayerInitialPosZ;
		tempX /= R_COMPASS_SCALE_X;
		tempZ /= R_COMPASS_SCALE_Y;
		Matrix_Translate(GFX_ALIGN_RIGHT_F((R_COMPASS_OFFSET_X + tempX) / 10.0f), (R_COMPASS_OFFSET_Y - tempZ) / 10.0f, 0.0f, MTXMODE_NEW);
		Matrix_Scale(VREG(9) / 100.0f, VREG(9) / 100.0f, VREG(9) / 100.0f, MTXMODE_APPLY);
		Matrix_RotateX(VREG(52) / 10.0f, MTXMODE_APPLY);
		Matrix_RotateY(sPlayerInitialDirection / 10.0f, MTXMODE_APPLY);
		gSPMatrix(OVERLAY_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_map_exp.c", 603), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

		gDPSetPrimColor(OVERLAY_DISP++, 0, 0xFF, 200, 0, 0, 255);
		gSPDisplayList(OVERLAY_DISP++, gCompassArrowDL);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_map_exp.c", 607);
}

void Minimap_Draw(GlobalContext* globalCtx)
{
	s32 pad[2];
	InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
	s32 mapIndex = gSaveContext.mapIndex;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_map_exp.c", 626);

	if(globalCtx->pauseCtx.state < 4)
	{
		switch(globalCtx->sceneNum)
		{
			case SCENE_YDAN:
			case SCENE_DDAN:
			case SCENE_BDAN:
			case SCENE_BMORI1:
			case SCENE_HIDAN:
			case SCENE_MIZUSIN:
			case SCENE_JYASINZOU:
			case SCENE_HAKADAN:
			case SCENE_HAKADANCH:
			case SCENE_ICE_DOUKUTO:
				if(!R_MINIMAP_DISABLED)
				{
					func_80094520(globalCtx->gfxCtx);
					gDPSetCombineLERP(OVERLAY_DISP++, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0);

					if(CHECK_DUNGEON_ITEM(DUNGEON_MAP, mapIndex))
					{
						gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 100, 255, 255, interfaceCtx->minimapAlpha);

						gDPLoadTextureBlock_4b(OVERLAY_DISP++, interfaceCtx->mapSegment1, G_IM_FMT_I, 96, 85, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

						gSPTextureRectangle(
						    OVERLAY_DISP++, GFX_ALIGN_RIGHT(R_DGN_MINIMAP_X) << 2, R_DGN_MINIMAP_Y << 2, (GFX_ALIGN_RIGHT(R_DGN_MINIMAP_X) + 96) << 2, (R_DGN_MINIMAP_Y + 85) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
					}

					if(CHECK_DUNGEON_ITEM(DUNGEON_COMPASS, mapIndex))
					{
						Minimap_DrawCompassIcons(globalCtx); // Draw icons for the player spawn and current position
						func_80094520(globalCtx->gfxCtx);
						MapMark_Draw(globalCtx);
					}
				}

				if(CHECK_BTN_ALL(globalCtx->input[0].press.button, BTN_L) && !Gameplay_InCsMode(globalCtx))
				{
					osSyncPrintf("Game_play_demo_mode_check=%d\n", Gameplay_InCsMode(globalCtx));
					// clang-format off
                    if (!R_MINIMAP_DISABLED) { Audio_PlaySoundGeneral(NA_SE_SY_CAMERA_ZOOM_UP, &gAudioDefaultPos, 4,
                                                                      &D_801333E0, &D_801333E0, &gReverbAdd2); }
                    else { Audio_PlaySoundGeneral(NA_SE_SY_CAMERA_ZOOM_DOWN, &gAudioDefaultPos, 4,
                                                  &D_801333E0, &D_801333E0, &gReverbAdd2); }
					// clang-format on
					R_MINIMAP_DISABLED ^= 1;
				}

				break;
			case SCENE_SPOT00:
			case SCENE_SPOT01:
			case SCENE_SPOT02:
			case SCENE_SPOT03:
			case SCENE_SPOT04:
			case SCENE_SPOT05:
			case SCENE_SPOT06:
			case SCENE_SPOT07:
			case SCENE_SPOT08:
			case SCENE_SPOT09:
			case SCENE_SPOT10:
			case SCENE_SPOT11:
			case SCENE_SPOT12:
			case SCENE_SPOT13:
			case SCENE_SPOT15:
			case SCENE_SPOT16:
			case SCENE_SPOT17:
			case SCENE_SPOT18:
			case SCENE_SPOT20:
			case SCENE_GANON_TOU:
				if(!R_MINIMAP_DISABLED)
				{
					func_80094520(globalCtx->gfxCtx);

					gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
					gDPSetPrimColor(OVERLAY_DISP++, 0, 0, R_MINIMAP_COLOR(0), R_MINIMAP_COLOR(1), R_MINIMAP_COLOR(2), interfaceCtx->minimapAlpha);

					gDPLoadTextureBlock_4b(
					    OVERLAY_DISP++, interfaceCtx->mapSegment1, G_IM_FMT_IA, gMapData->owMinimapWidth[mapIndex], gMapData->owMinimapHeight[mapIndex], 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
					    G_TX_NOLOD, G_TX_NOLOD);

					gSPTextureRectangle(
					    OVERLAY_DISP++, GFX_ALIGN_RIGHT(R_OW_MINIMAP_X) << 2, R_OW_MINIMAP_Y << 2, (GFX_ALIGN_RIGHT(R_OW_MINIMAP_X) + gMapData->owMinimapWidth[mapIndex]) << 2, (R_OW_MINIMAP_Y + gMapData->owMinimapHeight[mapIndex]) << 2,
					    G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

					if(((globalCtx->sceneNum != SCENE_SPOT01) && (globalCtx->sceneNum != SCENE_SPOT04) && (globalCtx->sceneNum != SCENE_SPOT08)) || (LINK_AGE_IN_YEARS != YEARS_ADULT))
					{
						if((gMapData->owEntranceFlag[sEntranceIconMapIndex] == 0xFFFF) || ((gMapData->owEntranceFlag[sEntranceIconMapIndex] != 0xFFFF) && (gSaveContext.infTable[26] & gBitFlags[gMapData->owEntranceFlag[mapIndex]])))
						{
							gDPLoadTextureBlock(
							    OVERLAY_DISP++, gMapDungeonEntranceIconTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

							gSPTextureRectangle(
							    OVERLAY_DISP++, GFX_ALIGN_RIGHT(gMapData->owEntranceIconPosX[sEntranceIconMapIndex]) << 2, gMapData->owEntranceIconPosY[sEntranceIconMapIndex] << 2,
							    GFX_ALIGN_RIGHT(gMapData->owEntranceIconPosX[sEntranceIconMapIndex] + 8) << 2, (gMapData->owEntranceIconPosY[sEntranceIconMapIndex] + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
						}
					}

					if((globalCtx->sceneNum == SCENE_SPOT08) && (gSaveContext.infTable[26] & gBitFlags[9]))
					{
						gDPLoadTextureBlock(OVERLAY_DISP++, gMapDungeonEntranceIconTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

						gSPTextureRectangle(OVERLAY_DISP++, GFX_ALIGN_RIGHT(270) << 2, 616, 1112, 648, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
					}

					Minimap_DrawCompassIcons(globalCtx); // Draw icons for the player spawn and current position
				}

				if(CHECK_BTN_ALL(globalCtx->input[0].press.button, BTN_L) && !Gameplay_InCsMode(globalCtx))
				{
					// clang-format off
                    if (!R_MINIMAP_DISABLED) { Audio_PlaySoundGeneral(NA_SE_SY_CAMERA_ZOOM_UP, &gAudioDefaultPos, 4,
                                                                      &D_801333E0, &D_801333E0, &gReverbAdd2); }
                    else { Audio_PlaySoundGeneral(NA_SE_SY_CAMERA_ZOOM_DOWN, &gAudioDefaultPos, 4,
                                                  &D_801333E0, &D_801333E0, &gReverbAdd2); }
					// clang-format on
					R_MINIMAP_DISABLED ^= 1;
				}

				break;
		}
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_map_exp.c", 782);
}

s16 Map_GetFloorTextIndexOffset(s32 mapIndex, s32 floor)
{
	return gMapData->floorTexIndexOffset[mapIndex][floor];
}

void Map_Update(GlobalContext* globalCtx)
{
	static s16 sLastRoomNum = 99;
	Player* player = GET_PLAYER(globalCtx);
	s32 mapIndex = gSaveContext.mapIndex;
	InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
	s16 floor;
	s16 i;

	if((globalCtx->pauseCtx.state == 0) && (globalCtx->pauseCtx.debugState == 0))
	{
		switch(globalCtx->sceneNum)
		{
			case SCENE_YDAN:
			case SCENE_DDAN:
			case SCENE_BDAN:
			case SCENE_BMORI1:
			case SCENE_HIDAN:
			case SCENE_MIZUSIN:
			case SCENE_JYASINZOU:
			case SCENE_HAKADAN:
			case SCENE_HAKADANCH:
			case SCENE_ICE_DOUKUTO:
				interfaceCtx->mapPalette[30] = 0;
				if(CHECK_DUNGEON_ITEM(DUNGEON_MAP, mapIndex))
				{
					interfaceCtx->mapPalette[31] = 1;
				}
				else
				{
					interfaceCtx->mapPalette[31] = 0;
				}

				for(floor = 0; floor < 8; floor++)
				{
					if(player->actor.world.pos.y > gMapData->floorCoordY[mapIndex][floor])
					{
						break;
					}
				}

				gSaveContext.sceneFlags[mapIndex].floors |= gBitFlags[floor];
				VREG(30) = floor;
				if(R_MAP_TEX_INDEX != (R_MAP_TEX_INDEX_BASE + Map_GetFloorTextIndexOffset(mapIndex, floor)))
				{
					R_MAP_TEX_INDEX = R_MAP_TEX_INDEX_BASE + Map_GetFloorTextIndexOffset(mapIndex, floor);
				}

				if(interfaceCtx->mapRoomNum != sLastRoomNum)
				{
					osSyncPrintf("Current floor＝%d  Current room＝%x  number of rooms＝%d\n", floor, interfaceCtx->mapRoomNum, gMapData->switchEntryCount[mapIndex]);
					sLastRoomNum = interfaceCtx->mapRoomNum;
				}

				for(i = 0; i < gMapData->switchEntryCount[mapIndex]; i++)
				{
					if((interfaceCtx->mapRoomNum == gMapData->switchFromRoom[mapIndex][i]) && (floor == gMapData->switchFromFloor[mapIndex][i]))
					{
						interfaceCtx->mapRoomNum = gMapData->switchToRoom[mapIndex][i];
						osSyncPrintf(VT_FGCOL(YELLOW));
						osSyncPrintf("Layer switching＝%x\n", interfaceCtx->mapRoomNum);
						osSyncPrintf(VT_RST);
						Map_InitData(globalCtx, interfaceCtx->mapRoomNum);
						gSaveContext.sunsSongState = SUNSSONG_INACTIVE;
						Map_SavePlayerInitialInfo(globalCtx);
					}
				}

				VREG(10) = interfaceCtx->mapRoomNum;
				break;
			case SCENE_YDAN_BOSS:
			case SCENE_DDAN_BOSS:
			case SCENE_BDAN_BOSS:
			case SCENE_MORIBOSSROOM:
			case SCENE_FIRE_BS:
			case SCENE_MIZUSIN_BS:
			case SCENE_JYASINBOSS:
			case SCENE_HAKADAN_BS:
				VREG(30) = gMapData->bossFloor[globalCtx->sceneNum - SCENE_YDAN_BOSS];
				R_MAP_TEX_INDEX = R_MAP_TEX_INDEX_BASE + gMapData->floorTexIndexOffset[globalCtx->sceneNum - SCENE_YDAN_BOSS][VREG(30)];
				break;
		}
	}
}
