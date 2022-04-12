#define INTERNAL_SRC_CODE_GAME_C
#include "global.h"
#include "gfx.h"
#include "z64global.h"
#include "code_800ACE70.h"
#include "framerate.h"
#include "functions.h"
#include "n64fault.h"
#include "speedmeter.h"
#include "ultra64/time.h"
#include "vt.h"
#include "z_vismono.h"
#include "def/TwoHeadArena.h"
#include "def/__osMalloc.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/code_800A9F30.h"
#include "def/code_800ACE70.h"
#include "def/code_800AD920.h"
#include "def/fault.h"
#include "def/fault_drawer.h"
#include "def/game.h"
#include "def/gamealloc.h"
#include "def/gettime.h"
#include "def/graph.h"
#include "def/idle.h"
#include "def/logutils.h"
#include "def/recvmesg.h"
#include "def/speed_meter.h"
#include "def/system_malloc.h"
#include "def/vimodentsclan1.h"
#include "def/z_debug.h"
#include "def/z_malloc.h"
#include "def/z_std_dma.h"
#include "def/z_vimode.h"
#include "def/z_vismono.h"
#include "def/zbuffer.h"

extern u32 gDmaMgrDmaBuffSize;
extern s32 gSystemArenaLogSeverity;
extern s32 gZeldaArenaLogSeverity;

extern u32 osTvType;

extern OSViMode osViModeNtscLan1;
extern OSViMode osViModeMpalLan1;
extern OSViMode osViModePalLan1;
extern OSViMode osViModeFpalLan1;

void KaleidoScope_SetupGrayIcons();

f32 gViConfigXScale = 1.0;
f32 gViConfigYScale = 1.0;
u32 gViConfigFeatures = OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF;

OSViMode osViModeNtscLan1 = {
    2, // type
    {
	// comRegs
	BE16(0x311E), // ctrl
	SCREEN_WIDTH, // width
	0x3E52239,    // burst
	0x20D,	      // vSync
	0xC15,	      // hSync
	0xC150C15,    // leap
	0x6C02EC,     // hStart
	0x200,	      // xScale
	0,	      // vCurrent
    },
    {// fldRegs
     {
	 // [0]
	 0x280,	   // origin
	 0x400,	   // yScale
	 0x2501FF, // vStart
	 0xE0204,  // vBurst
	 2,	   // vIntr
     },
     {
	 // [1]
	 0x280,	   // origin
	 0x400,	   // yScale
	 0x2501FF, // vStart
	 0xE0204,  // vBurst
	 2,	   // vIntr
     }},
};

SpeedMeter D_801664D0;
struct_801664F0 D_801664F0;
struct_80166500 D_80166500;
VisMono sMonoColors;
ViMode sViMode;
FaultClient sGameFaultClient;
u16 sLastButtonPressed;

void GameState_FaultPrint(void)
{
	static char sBtnChars[] = "ABZSuldr*+LRudlr";
	s32 i;

	osSyncPrintf("last_button=%04x\n", sLastButtonPressed);
	FaultDrawer_DrawText(120, 180, "%08x", sLastButtonPressed);
	for(i = 0; i < ARRAY_COUNT(sBtnChars); i++)
	{
		if(sLastButtonPressed & (1 << i))
		{
			FaultDrawer_DrawText((i * 8) + 0x78, 0xBE, "%c", sBtnChars[i]);
		}
	}
}

void GameState_SetFBFilter(Gfx** gfx)
{
	Gfx* gfxP;
	gfxP = *gfx;

	if((R_FB_FILTER_TYPE > 0) && (R_FB_FILTER_TYPE < 5))
	{
		D_801664F0.type = R_FB_FILTER_TYPE;
		D_801664F0.color.r = R_FB_FILTER_PRIM_COLOR(0);
		D_801664F0.color.g = R_FB_FILTER_PRIM_COLOR(1);
		D_801664F0.color.b = R_FB_FILTER_PRIM_COLOR(2);
		D_801664F0.color.a = R_FB_FILTER_A;
		func_800ACE98(&D_801664F0, &gfxP);
	}
	else if((R_FB_FILTER_TYPE == 5) || (R_FB_FILTER_TYPE == 6))
	{
		D_80166500.useRgba = (R_FB_FILTER_TYPE == 6);
		D_80166500.primColor.r = R_FB_FILTER_PRIM_COLOR(0);
		D_80166500.primColor.g = R_FB_FILTER_PRIM_COLOR(1);
		D_80166500.primColor.b = R_FB_FILTER_PRIM_COLOR(2);
		D_80166500.primColor.a = R_FB_FILTER_A;
		D_80166500.envColor.r = R_FB_FILTER_ENV_COLOR(0);
		D_80166500.envColor.g = R_FB_FILTER_ENV_COLOR(1);
		D_80166500.envColor.b = R_FB_FILTER_ENV_COLOR(2);
		D_80166500.envColor.a = R_FB_FILTER_A;
		func_800AD958(&D_80166500, &gfxP);
	}
	else if(R_FB_FILTER_TYPE == 7)
	{
		sMonoColors.unk_00 = 0;
		sMonoColors.primColor.r = R_FB_FILTER_PRIM_COLOR(0);
		sMonoColors.primColor.g = R_FB_FILTER_PRIM_COLOR(1);
		sMonoColors.primColor.b = R_FB_FILTER_PRIM_COLOR(2);
		sMonoColors.primColor.a = R_FB_FILTER_A;
		sMonoColors.envColor.r = R_FB_FILTER_ENV_COLOR(0);
		sMonoColors.envColor.g = R_FB_FILTER_ENV_COLOR(1);
		sMonoColors.envColor.b = R_FB_FILTER_ENV_COLOR(2);
		sMonoColors.envColor.a = R_FB_FILTER_A;
		VisMono_Draw(&sMonoColors, &gfxP);
	}
	*gfx = gfxP;
}

void func_800C4344(GameState* gameState)
{
	Input* selectedInput;
	s32 hexDumpSize;
	u16 hReg82;

	if(HREG(80) == 0xC)
	{
		selectedInput = &gameState->input[(u32)HREG(81) < 4U ? HREG(81) : 0];
		hReg82 = HREG(82);
		HREG(83) = selectedInput->cur.button;
		HREG(84) = selectedInput->press.button;
		HREG(85) = selectedInput->rel.stick_x;
		HREG(86) = selectedInput->rel.stick_y;
		HREG(87) = selectedInput->rel.stick_x;
		HREG(88) = selectedInput->rel.stick_y;
		HREG(89) = selectedInput->cur.stick_x;
		HREG(90) = selectedInput->cur.stick_y;
		HREG(93) = (selectedInput->cur.button == hReg82);
		HREG(94) = CHECK_BTN_ALL(selectedInput->cur.button, hReg82);
		HREG(95) = CHECK_BTN_ALL(selectedInput->press.button, hReg82);
	}

	if(gIsCtrlr2Valid)
	{
		func_8006390C(&gameState->input[1]);
	}

	gDmaMgrDmaBuffSize = SREG(21) != 0 ? ALIGN16(SREG(21)) : 0x2000;
	gSystemArenaLogSeverity = HREG(61);
	gZeldaArenaLogSeverity = HREG(62);
	if(HREG(80) == 8)
	{
		if(HREG(94) != 8)
		{
			HREG(94) = 8;
			HREG(81) = 0;
			HREG(82) = 0;
			HREG(83) = 0;
		}
		if(HREG(81) < 0)
		{
			HREG(81) = 0;
			// & 0xFFFFFFFF necessary for matching.
			hexDumpSize = (HREG(83) == 0 ? 0x100 : HREG(83) * 0x10) & 0xFFFFFFFF;
			LogUtils_LogHexDump((void*)PHYSICAL_TO_VIRTUAL(HREG(82) << 8), hexDumpSize);
		}
	}
}

void GameState_DrawInputDisplay(u16 input, Gfx** gfx)
{
	static const u16 sInpDispBtnColors[] = {
	    GPACK_RGBA5551(255, 255, 0, 1), GPACK_RGBA5551(255, 255, 0, 1),   GPACK_RGBA5551(255, 255, 0, 1),	GPACK_RGBA5551(255, 255, 0, 1),	  GPACK_RGBA5551(120, 120, 120, 1), GPACK_RGBA5551(120, 120, 120, 1),
	    GPACK_RGBA5551(0, 255, 255, 1), GPACK_RGBA5551(255, 0, 255, 1),   GPACK_RGBA5551(120, 120, 120, 1), GPACK_RGBA5551(120, 120, 120, 1), GPACK_RGBA5551(120, 120, 120, 1), GPACK_RGBA5551(120, 120, 120, 1),
	    GPACK_RGBA5551(255, 0, 0, 1),   GPACK_RGBA5551(120, 120, 120, 1), GPACK_RGBA5551(0, 255, 0, 1),	GPACK_RGBA5551(0, 0, 255, 1),
	};
	s32 i, j, k;
	Gfx* gfxP = *gfx;

	gDPPipeSync(gfxP++);
	gDPSetOtherMode(gfxP++, G_AD_PATTERN | G_CD_MAGICSQ | G_CK_NONE | G_TC_CONV | G_TF_POINT | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_FILL | G_PM_NPRIMITIVE, G_AC_NONE | G_ZS_PIXEL | G_RM_NOOP | G_RM_NOOP2);

	for(i = 0; i < 16; i++)
	{
		j = i;
		if(input & (1 << i))
		{
			gDPSetFillColor(gfxP++, (sInpDispBtnColors[i] << 0x10) | sInpDispBtnColors[i]);
			k = i + 1;
			gDPFillRectangle(gfxP++, (j * 4) + 226, 220, (k * 4) + 225, 223);
			gDPPipeSync(gfxP++);
		}
	}

	*gfx = gfxP;
}

void GameState_Draw(GameState* gameState, GraphicsContext* gfxCtx)
{
	Gfx* newDList;
	Gfx* polyOpaP;

	OPEN_DISPS(gfxCtx, "../game.c", 746);

	newDList = Graph_GfxPlusOne(polyOpaP = POLY_OPA_DISP);
	gSPDisplayList(OVERLAY_DISP++, newDList);

	if(R_ENABLE_FB_FILTER == 1)
	{
		GameState_SetFBFilter(&newDList);
	}

	sLastButtonPressed = gameState->input[0].press.button | gameState->input[0].cur.button;
#ifdef OOT_DEBUG_ROM
	if(R_DISABLE_INPUT_DISPLAY == 0)
	{
		GameState_DrawInputDisplay(sLastButtonPressed, &newDList);
	}
#endif

	gSPEndDisplayList(newDList++);
	Graph_BranchDlist(polyOpaP, newDList);
	POLY_OPA_DISP = newDList;

	CLOSE_DISPS(gfxCtx, "../game.c", 800);

	func_80063D7C(gfxCtx);
}

void GameState_SetFrameBuffer(GraphicsContext* gfxCtx)
{
	OPEN_DISPS(gfxCtx, "../game.c", 814);

	gSPSegment(POLY_OPA_DISP++, 0, 0);
	gSPSegment(POLY_OPA_DISP++, 0xF, gfxCtx->curFrameBuffer);
	gSPSegment(POLY_OPA_DISP++, 0xE, gZBuffer);
	gSPSegment(POLY_XLU_DISP++, 0, 0);
	gSPSegment(POLY_XLU_DISP++, 0xF, gfxCtx->curFrameBuffer);
	gSPSegment(POLY_XLU_DISP++, 0xE, gZBuffer);
	gSPSegment(OVERLAY_DISP++, 0, 0);
	gSPSegment(OVERLAY_DISP++, 0xF, gfxCtx->curFrameBuffer);
	gSPSegment(OVERLAY_DISP++, 0xE, gZBuffer);

	CLOSE_DISPS(gfxCtx, "../game.c", 838);
}

void func_800C49F4(GraphicsContext* gfxCtx)
{
	Gfx* newDlist;
	Gfx* polyOpaP;

	OPEN_DISPS(gfxCtx, "../game.c", 846);

	newDlist = Graph_GfxPlusOne(polyOpaP = POLY_OPA_DISP);
	gSPDisplayList(OVERLAY_DISP++, newDlist);

	gSPEndDisplayList(newDlist++);
	Graph_BranchDlist(polyOpaP, newDlist);
	POLY_OPA_DISP = newDlist;

	CLOSE_DISPS(gfxCtx, "../game.c", 865);
}

void PadMgr_RequestPadData(PadMgr*, Input*, s32);

void GameState_ReqPadData(GameState* gameState)
{
	PadMgr_RequestPadData(&gPadMgr, &gameState->input[0], 1);
}

void GameState_Update(GameState* gameState)
{
	GraphicsContext* gfxCtx = gameState->gfxCtx;

	GameState_SetFrameBuffer(gfxCtx);

	gameState->main();

	func_800C4344(gameState);

	SREG(63) = 2; // Hack that is currently used the make the lines below work

	if(SREG(63) == 1u)
	{
		if(SREG(48) < 0)
		{
			SREG(48) = 0;
			gfxCtx->viMode = &gViConfigMode;
			gfxCtx->viFeatures = gViConfigFeatures;
			gfxCtx->xScale = gViConfigXScale;
			gfxCtx->yScale = gViConfigYScale;
		}
		else if(SREG(48) > 0)
		{
			ViMode_Update(&sViMode, gameState->input);
			gfxCtx->viMode = &sViMode.customViMode;
			gfxCtx->viFeatures = sViMode.viFeatures;
			gfxCtx->xScale = 1.0f;
			gfxCtx->yScale = 1.0f;
		}
	}
	else if(SREG(63) >= 2)
	{
		gfxCtx->viMode = &gViConfigMode;
		gfxCtx->viFeatures = gViConfigFeatures;
		gfxCtx->xScale = gViConfigXScale;
		gfxCtx->yScale = gViConfigYScale;
		if(SREG(63) == 6 || (SREG(63) == 2u && osTvType == OS_TV_NTSC))
		{
			gfxCtx->viMode = &osViModeNtscLan1;
			gfxCtx->yScale = 1.0f;
		}

		if(SREG(63) == 5 || (SREG(63) == 2u && osTvType == OS_TV_MPAL))
		{
			gfxCtx->viMode = &osViModeMpalLan1;
			gfxCtx->yScale = 1.0f;
		}

		if(SREG(63) == 4 || (SREG(63) == 2u && osTvType == OS_TV_PAL))
		{
			gfxCtx->viMode = &osViModePalLan1;
			gfxCtx->yScale = 1.0f;
		}

		if(SREG(63) == 3 || (SREG(63) == 2u && osTvType == OS_TV_PAL))
		{
			gfxCtx->viMode = &osViModeFpalLan1;
			gfxCtx->yScale = 0.833f;
		}
	}
	else
	{
		gfxCtx->viMode = NULL;
	}

	if(HREG(80) == 0x15)
	{
		if(HREG(95) != 0x15)
		{
			HREG(95) = 0x15;
			HREG(81) = 0;
			HREG(82) = gViConfigAdditionalScanLines;
			HREG(83) = 0;
			HREG(84) = 0;
		}

		if(HREG(82) < 0)
		{
			HREG(82) = 0;
		}
		if(HREG(82) > 0x30)
		{
			HREG(82) = 0x30;
		}

		if((HREG(83) != HREG(82)) || HREG(84) != HREG(81))
		{
			HREG(83) = HREG(82);
			HREG(84) = HREG(81);
			gViConfigAdditionalScanLines = HREG(82);
			gViConfigYScale = HREG(81) == 0 ? 240.0f / (gViConfigAdditionalScanLines + 240.0f) : 1.0f;
			D_80009430 = 1;
		}
	}

	if(R_PAUSE_MENU_MODE != 2u)
	{
		GameState_Draw(gameState, gfxCtx);
		func_800C49F4(gfxCtx);
	}

	gameState->frames++;
}
#include <string.h>
void GameState_InitArena(GameState* gameState, size_t size)
{
	void* arena;

	osSyncPrintf("Hyrule reserved size = %u bytes\n");			      // "Hyrule reserved size = %u bytes"
	arena = GameAlloc_MallocDebug(&gameState->alloc, size * 2, "../game.c", 992); // TODO FIX

	if(arena != NULL)
	{
		THA_Ct(&gameState->tha, arena, size);
		osSyncPrintf("Successful Hyrule\n"); // "Successful Hyrule"
	}
	else
	{
		THA_Ct(&gameState->tha, NULL, 0);
		osSyncPrintf("Failure to secure Hyrule\n"); // "Failure to secure Hyrule"
		Fault_AddHungupAndCrash("../game.c", 999);
	}
}

void GameState_Realloc(GameState* gameState, size_t size)
{
	GameAlloc* alloc = &gameState->alloc;
	void* gameArena;
	u32 systemMaxFree;
	u32 systemFree;
	u32 systemAlloc;
	void* thaBufp = gameState->tha.bufp;

	THA_Dt(&gameState->tha);
	GameAlloc_Free(alloc, thaBufp);
	osSyncPrintf("Hyrule temporarily released!!\n"); // "Hyrule temporarily released!!"
	SystemArena_GetSizes(&systemMaxFree, &systemFree, &systemAlloc);
	if((systemMaxFree - 0x10) < size)
	{
		osSyncPrintf("%c", 7);
		osSyncPrintf(VT_FGCOL(RED));

		// "Not enough memory. Change the hyral size to the largest possible value"
		osSyncPrintf("Not enough memory. Change the hyral size to the largest possible value\n");
		osSyncPrintf("(hyral=%08x max=%08x free=%08x alloc=%08x)\n", size, systemMaxFree, systemFree, systemAlloc);
		osSyncPrintf(VT_RST);
		size = systemMaxFree - 0x10;
	}

	osSyncPrintf("Hyrule reallocate size = %u bytes\n", size);	       // "Hyrule reallocate size = %u bytes"
	gameArena = GameAlloc_MallocDebug(alloc, size * 2, "../game.c", 1033); // TODO FIX
	if(gameArena != NULL)
	{
		THA_Ct(&gameState->tha, gameArena, size);
		osSyncPrintf("Successful reacquisition of Hyrule\n"); // "Successful reacquisition of Hyrule"
	}
	else
	{
		THA_Ct(&gameState->tha, NULL, 0);
		osSyncPrintf("Failure to secure Hyrule\n"); // "Failure to secure Hyrule"
		SystemArena_Display();
		Fault_AddHungupAndCrash("../game.c", 1044);
	}
}

void* GameState_Alloc(GameState* gameState, size_t size, const char* file, s32 line)
{
	void* ret;

	if(THA_IsCrash(&gameState->tha))
	{
		osSyncPrintf("Hyrule has been destroyed\n");
		ret = NULL;
	}
	else if((u32)THA_GetSize(&gameState->tha) < size)
	{
		// "Hyrule on the verge of extinction does not have %d bytes left (%d bytes until extinction)"
		osSyncPrintf("Hyrule on the verge of extinction does not have %d bytes left (%d bytes until extinction)\n", size, THA_GetSize(&gameState->tha));
		ret = NULL;
	}
	else
	{
		ret = THA_AllocEndAlign16(&gameState->tha, size);
		if(THA_IsCrash(&gameState->tha))
		{
			osSyncPrintf("Hyrule has been destroyed\n"); // "Hyrule has been destroyed"
			ret = NULL;
		}
	}
	if(ret != NULL)
	{
		osSyncPrintf(VT_FGCOL(GREEN));
		osSyncPrintf("game_alloc(%08x) %08x-%08x [%s:%d]\n", size, ret, (uintptr_t)ret + size, file, line);
		osSyncPrintf(VT_RST);
	}
	return ret;
}

void* GameState_AllocEndAlign16(GameState* gameState, size_t size)
{
	return THA_AllocEndAlign16(&gameState->tha, size);
}

s32 GameState_GetArenaSize(GameState* gameState)
{
	return THA_GetSize(&gameState->tha);
}

namespace oot::gamestate
{
	Base::Base(GraphicsContext* gfxCtx) : gfxCtx(gfxCtx)
	{
	}

	void Base::start()
	{
		osSyncPrintf("game constructor start\n"); // "game constructor start"

		frames = 0;
		running = 1;

		GameAlloc_Init(&alloc);

		// Generate grayscale versions of all icons
		KaleidoScope_SetupGrayIcons();

		GameState_InitArena(this, 0x100000 * sizeof(uintptr_t) / 4); // TODO FIX HACK
		framerate_set_profile(PROFILE_GAMEPLAY);

		init();

		func_800ACE70(&D_801664F0);
		func_800AD920(&D_80166500);
		VisMono_Init(&sMonoColors);

		if(SREG(48) == 0)
		{
			ViMode_Init(&sViMode);
		}

		SpeedMeter_Init(&D_801664D0);
		Rumble_Reset();
		// osSendMesg(&gameState->gfxCtx->queue, NULL, OS_MESG_BLOCK);

		Fault_AddClient(&sGameFaultClient, GameState_FaultPrint, NULL, NULL);

		osSyncPrintf("game constructor end\n"); // "game constructor end"
	}

	Base::~Base()
	{
		osSyncPrintf("game destructor start\n"); // "game destructor start"
		Audio_StopAllBanks();
		Audio_UpdateAll();
		// osRecvMesg(&gameState->gfxCtx->queue, NULL, OS_MESG_BLOCK);

		Rumble_Destroy();
		SpeedMeter_Destroy(&D_801664D0);
		func_800ACE90(&D_801664F0);
		func_800AD950(&D_80166500);
		VisMono_Destroy(&sMonoColors);

		if(SREG(48) == 0)
		{
			ViMode_Destroy(&sViMode);
		}

		THA_Dt(&tha);
		GameAlloc_Cleanup(&alloc);
		SystemArena_Display();
		Fault_RemoveClient(&sGameFaultClient);

		osSyncPrintf("game destructor end\n"); // "game destructor end"
	}

	void Base::loadNext()
	{
		Graph_SetNextGameState(next());
	}
} // namespace oot::gamestate
