#define INTERNAL_SRC_CODE_GRAPH_C
#include "global.h"
#include "gfx.h"
#include <string.h>
#include "../port/controller/tas.h"
#include "../port/options.h"
#include "gfxapi.h"
#include "n64fault.h"
#include "padmgr.h"
#include "speedmeter.h"
#include "state.h"
#include "ultra64/sched.h"
#include "ultra64/time.h"
#include "vt.h"
#include "z64game.h"
#include "z64save.h"
#include "def/TwoHeadArena.h"
#include "def/audio.h"
#include "def/createmesgqueue.h"
#include "def/fault.h"
#include "def/game.h"
#include "def/gettime.h"
#include "def/gfxbuffers.h"
#include "def/graph.h"
#include "def/idle.h"
#include "def/logutils.h"
#include "def/sched.h"
#include "def/speed_meter.h"
#include "def/sys_cfb.h"
#include "def/sys_ucode.h"
#include "def/system_malloc.h"
#include "def/title_setup.h"
#include "def/z_file_choose.h"
#include "def/z_opening.h"
#include "def/z_play.h" // FORCE
#include "def/z_select.h"
#include "def/z_title.h"

#define GFXPOOL_HEAD_MAGIC 0x1234
#define GFXPOOL_TAIL_MAGIC 0x5678

OSTime sGraphUpdateTime;
OSTime sGraphSetTaskTime;
FaultClient sGraphFaultClient;
CfbInfo sGraphCfbInfos[3];
FaultClient sGraphUcodeFaultClient;

static std::unique_ptr<oot::gamestate::Base> gCurrentGameState = nullptr;
static std::unique_ptr<oot::gamestate::Base> gNextGameState = nullptr;

bool isRunning();

void Graph_DisassembleUCode(Gfx* workBuf)
{
}

void Graph_UCodeFaultClient(Gfx* workBuf)
{
}

void Graph_InitTHGA(GraphicsContext* gfxCtx)
{
	GfxPool* pool = &gGfxPools[gfxCtx->gfxPoolIdx & 1];

	pool->headMagic = GFXPOOL_HEAD_MAGIC;
	pool->tailMagic = GFXPOOL_TAIL_MAGIC;
	THGA_Ct(&gfxCtx->polyOpa, pool->polyOpaBuffer, sizeof(pool->polyOpaBuffer));
	THGA_Ct(&gfxCtx->polyXlu, pool->polyXluBuffer, sizeof(pool->polyXluBuffer));
	THGA_Ct(&gfxCtx->overlay, pool->overlayBuffer, sizeof(pool->overlayBuffer));
	THGA_Ct(&gfxCtx->work, pool->workBuffer, sizeof(pool->workBuffer));

	gfxCtx->polyOpaBuffer = pool->polyOpaBuffer;
	gfxCtx->polyXluBuffer = pool->polyXluBuffer;
	gfxCtx->overlayBuffer = pool->overlayBuffer;
	gfxCtx->workBuffer = pool->workBuffer;

	gfxCtx->curFrameBuffer = (u16*)SysCfb_GetFbPtr(gfxCtx->fbIdx % 2);
	gfxCtx->unk_014 = 0;
}

void Graph_SetNextGameState(GameState* gameState)
{
	gNextGameState = std::unique_ptr<GameState>(gameState);
}

/*
GameStateOverlay* Graph_GetNextGameState(GameState* gameState)
{
	void* gameStateInitFunc = GameState_GetInit(gameState);

	if(gameStateInitFunc == TitleSetup_Init)
	{
		return &gGameStateOverlayTable[0];
	}
	if(gameStateInitFunc == Select_Init)
	{
		return &gGameStateOverlayTable[1];
	}
	if(gameStateInitFunc == Title_Init)
	{
		return &gGameStateOverlayTable[2];
	}
	if(gameStateInitFunc == Gameplay_Init)
	{
		return &gGameStateOverlayTable[3];
	}
	if(gameStateInitFunc == Opening_Init)
	{
		return &gGameStateOverlayTable[4];
	}
	if(gameStateInitFunc == FileChoose_Init)
	{
		return &gGameStateOverlayTable[5];
	}

	LOG_ADDRESS("game_init_func", gameStateInitFunc, "../graph.c", 696);
	return NULL;
}
*/
void Graph_Init(GraphicsContext* gfxCtx)
{
	memset(gfxCtx, 0, sizeof(GraphicsContext));
	gfxCtx->gfxPoolIdx = 0;
	gfxCtx->fbIdx = 0;
	gfxCtx->viMode = NULL;
	gfxCtx->viFeatures = gViConfigFeatures;
	gfxCtx->xScale = gViConfigXScale;
	gfxCtx->yScale = gViConfigYScale;
	gIsCtrlr2Valid = (gPadMgr.validCtrlrsMask & 2) != 0;
}

void Graph_Destroy(GraphicsContext* gfxCtx)
{
	gIsCtrlr2Valid = false;
}

void gfx_run(OSTask_t* task, u32 sz);

void Graph_TaskSet00(GraphicsContext* gfxCtx)
{
	static Gfx* D_8012D260 = NULL;
	static s32 sGraphCfbInfoIdx = 0;

	OSTime time;
	OSMesg msg;
	OSTask_t* task = &gfxCtx->task.list.t;
	OSScTask* scTask = &gfxCtx->task;
	CfbInfo* cfb;
	s32 pad1;

	D_8016A528 = osGetTime() - sGraphSetTaskTime - D_8016A558;

	D_8012D260 = gfxCtx->workBuffer;
	if(gfxCtx->callback != NULL)
	{
		gfxCtx->callback(gfxCtx, gfxCtx->callbackParam);
	}

	time = osGetTime();
	if(D_8016A550 != 0)
	{
		D_8016A558 = (D_8016A558 + time) - D_8016A550;
		D_8016A550 = time;
	}
	D_8016A520 = D_8016A558;
	D_8016A558 = 0;
	sGraphSetTaskTime = osGetTime();

	task->type = M_GFXTASK;
	task->flags = OS_SC_DRAM_DLIST;
	task->ucode_boot = SysUcode_GetUCodeBoot();
	task->ucode_boot_size = SysUcode_GetUCodeBootSize();
	task->ucode = SysUcode_GetUCode();
	task->ucode_data = SysUcode_GetUCodeData();
	task->ucode_size = SysUcode_GetUCodeSize();
	task->ucode_data_size = SysUcode_GetUCodeDataSize();
	task->dram_stack = (u64*)gGfxSPTaskStack;
	task->dram_stack_size = sizeof(gGfxSPTaskStack);
	task->output_buff = gGfxSPTaskOutputBuffer;
	task->output_buff_size = (u64*)((u8*)gGfxSPTaskOutputBuffer + sizeof(gGfxSPTaskOutputBuffer));
	task->data_ptr = (u64*)gfxCtx->workBuffer;

	OPEN_DISPS(gfxCtx, "../graph.c", 828);
	task->data_size = (uintptr_t)WORK_DISP - (uintptr_t)gfxCtx->workBuffer;
	CLOSE_DISPS(gfxCtx, "../graph.c", 830);

	task->yield_data_ptr = (u64*)gGfxSPTaskYieldBuffer;
	task->yield_data_size = sizeof(gGfxSPTaskYieldBuffer);

	scTask->next = NULL;
	scTask->flags = OS_SC_RCP_MASK | OS_SC_SWAPBUFFER | OS_SC_LAST_TASK;
	if(SREG(33) & 1)
	{ // SREG(33) is raised by the pause menu and PlayerPreRender (frame buffer effects)
		SREG(33) &= ~1;
		scTask->flags &= ~OS_SC_SWAPBUFFER;
		gfxCtx->fbIdx--;
	}

	scTask->msgQ = &gfxCtx->queue;
	scTask->msg = NULL;

	gfx_fbe_sync(gfxCtx, gGameInfo); // Sync with GLidenN64 frame buffer emulation

	cfb = &sGraphCfbInfos[sGraphCfbInfoIdx++];
	cfb->fb1 = gfxCtx->curFrameBuffer;
	cfb->swapBuffer = gfxCtx->curFrameBuffer;
	cfb->viMode = gfxCtx->viMode;
	cfb->features = gfxCtx->viFeatures;
	cfb->xScale = gfxCtx->xScale;
	cfb->yScale = gfxCtx->yScale;
	cfb->unk_10 = 0;
	cfb->updateRate = R_UPDATE_RATE;

	scTask->framebuffer = cfb;
	sGraphCfbInfoIdx = sGraphCfbInfoIdx % ARRAY_COUNT(sGraphCfbInfos);

	gfxCtx->schedMsgQ = &gSchedContext.cmdQ;

	// osSendMesg(&gSchedContext.cmdQ, scTask, OS_MESG_BLOCK);
	Sched_SendEntryMsg(&gSchedContext);

	if(oot::config().game().graphicsEnabled())
		gfx_schedule(task, sizeof(OSTask_t));
}

void Graph_Update(GraphicsContext* gfxCtx, GameState* gameState)
{
	u32 problem;

	gameState->unk_A0 = 0;
	Graph_InitTHGA(gfxCtx);

	OPEN_DISPS(gfxCtx, "../graph.c", 966);

	gDPNoOpString(WORK_DISP++, "WORK_DISP 開始", 0);
	gDPNoOpString(POLY_OPA_DISP++, "POLY_OPA_DISP 開始", 0);
	gDPNoOpString(POLY_XLU_DISP++, "POLY_XLU_DISP 開始", 0);
	gDPNoOpString(OVERLAY_DISP++, "OVERLAY_DISP 開始", 0);

	CLOSE_DISPS(gfxCtx, "../graph.c", 975);

	GameState_ReqPadData(gameState);
	GameState_Update(gameState);

	if(oot::config().game().enablDebugLevelSelect())
	{
		// All dpad buttons pressed on controller 1? (Same as the back button on an xinput controller)
		if(CHECK_BTN_ALL(gameState->input[0].cur.button, BTN_DUP | BTN_DDOWN | BTN_DLEFT | BTN_DRIGHT))
		{ // Open debug map select
			gameState->running = false;
			Graph_SetNextGameState(new oot::gamestate::Select(gameState->gfxCtx));
			return;
		}
	}

	OPEN_DISPS(gfxCtx, "../graph.c", 987);

	gDPNoOpString(WORK_DISP++, "WORK_DISP 終了", 0);
	gDPNoOpString(POLY_OPA_DISP++, "POLY_OPA_DISP 終了", 0);
	gDPNoOpString(POLY_XLU_DISP++, "POLY_XLU_DISP 終了", 0);
	gDPNoOpString(OVERLAY_DISP++, "OVERLAY_DISP 終了", 0);

	CLOSE_DISPS(gfxCtx, "../graph.c", 996);

	OPEN_DISPS(gfxCtx, "../graph.c", 999);

	gSPBranchList(WORK_DISP++, gfxCtx->polyOpaBuffer);
	gSPBranchList(POLY_OPA_DISP++, gfxCtx->polyXluBuffer);
	gSPBranchList(POLY_XLU_DISP++, gfxCtx->overlayBuffer);
	gDPPipeSync(OVERLAY_DISP++);
	gDPFullSync(OVERLAY_DISP++);
	gSPEndDisplayList(OVERLAY_DISP++);

	CLOSE_DISPS(gfxCtx, "../graph.c", 1028);

	if(HREG(80) == 10 && HREG(93) == 2)
	{
		HREG(80) = 7;
		HREG(81) = -1;
		HREG(83) = HREG(92);
	}

	if(HREG(80) == 7 && HREG(81) != 0)
	{
		if(HREG(82) == 3)
		{
			Fault_AddClient(&sGraphUcodeFaultClient, Graph_UCodeFaultClient, gfxCtx->workBuffer, (void*)"do_count_fault");
		}

		Graph_DisassembleUCode(gfxCtx->workBuffer);

		if(HREG(82) == 3)
		{
			Fault_RemoveClient(&sGraphUcodeFaultClient);
		}

		if(HREG(81) < 0)
		{
			HREG(81) = 0;
		}
	}

	problem = false;

	{
		GfxPool* pool = &gGfxPools[gfxCtx->gfxPoolIdx & 1];

		if(pool->headMagic != GFXPOOL_HEAD_MAGIC)
		{
			//! @bug (?) : "problem = true;" may be missing
			osSyncPrintf("%c", 7);
			// "Dynamic area head is destroyed"
			osSyncPrintf(VT_COL(RED, WHITE) "Dynamic area head is destroyed\n" VT_RST);
			Fault_AddHungupAndCrash("../graph.c", 1070);
		}
		if(pool->tailMagic != GFXPOOL_TAIL_MAGIC)
		{
			problem = true;
			osSyncPrintf("%c", 7);
			// "Dynamic region tail is destroyed"
			osSyncPrintf(VT_COL(RED, WHITE) "Dynamic region tail is destroyed\n" VT_RST);
			Fault_AddHungupAndCrash("../graph.c", 1076);
		}
	}

	if(THGA_IsCrash(&gfxCtx->polyOpa))
	{
		problem = true;
		osSyncPrintf("%c", 7);
		// "Zelda 0 is dead"
		osSyncPrintf(VT_COL(RED, WHITE) "Debug 0 is dead(graph_alloc is empty)\n" VT_RST);
	}
	if(THGA_IsCrash(&gfxCtx->polyXlu))
	{
		problem = true;
		osSyncPrintf("%c", 7);
		// "Zelda 1 is dead"
		osSyncPrintf(VT_COL(RED, WHITE) "Debug 1 is dead(graph_alloc is empty)\n" VT_RST);
	}
	if(THGA_IsCrash(&gfxCtx->overlay))
	{
		problem = true;
		osSyncPrintf("%c", 7);
		// "Zelda 4 is dead"
		osSyncPrintf(VT_COL(RED, WHITE) "Debug 4 is dead(graph_alloc is empty)\n" VT_RST);
	}

	if(!problem)
	{
		Graph_TaskSet00(gfxCtx);
		gfxCtx->gfxPoolIdx++;
		gfxCtx->fbIdx++;
	}

	Audio_UpdateAll();

	{
		OSTime time = osGetTime();
		s32 pad[4];

		gRSPGFXTotalTime_LastFrame = gRSPGFXTotalTime;
		gRSPAudioTotalTime_LastFrame = gRSPAudioTotalTime;
		gRDPTotalTime_LastFrame = gRDPTotalTime;
		gRSPGFXTotalTime = 0;
		gRSPAudioTotalTime = 0;
		gRDPTotalTime = 0;

		if(sGraphUpdateTime != 0)
		{
			D_8016A548 = time - sGraphUpdateTime;
		}
		sGraphUpdateTime = time;
	}
}

static u64 frameCount = 0;

void Graph_ThreadEntry(void* arg0)
{
	GraphicsContext gfxCtx;

	osSyncPrintf("Start graphic thread execution\n"); // "Start graphic thread execution"
	Graph_Init(&gfxCtx);

	gCurrentGameState = std::make_unique<oot::gamestate::TitleSetup>(&gfxCtx);

	while(gCurrentGameState && isRunning())
	{
		gCurrentGameState->start();

		while(gCurrentGameState->running && isRunning())
		{
			// Has the TAS playback completed?
			/*if (oot::hid::tas::isTasPlaying() && oot::hid::tas::hasTasEnded())
			    break; TODO FIX*/

			if(!oot::config().game().graphicsEnabled())
			{
				gfx_start_frame();
				Graph_Update(&gfxCtx, gCurrentGameState.get());
				gfx_end_frame();
			}
			else
			{
				if(oot::state.fastForward == 1 || (frameCount % oot::state.fastForward) == 0)
				{
					if(gfx_start_frame())
					{
						Graph_Update(&gfxCtx, gCurrentGameState.get());
						gfx_end_frame();
					}
				}
				frameCount++;
			}
		}

		gfx_wait_ready();

		if(gNextGameState)
		{
			gCurrentGameState = std::move(gNextGameState);
			gNextGameState = nullptr;
		}
		else
		{
			gCurrentGameState = std::unique_ptr<oot::gamestate::Base>(gCurrentGameState->next());
		}
	}

	gfx_wait_ready();
	gCurrentGameState.reset();

	Graph_Destroy(&gfxCtx);
	osSyncPrintf("End of graphic thread execution\n"); // "End of graphic thread execution"
}

void* Graph_Alloc(GraphicsContext* gfxCtx, size_t size)
{
	TwoHeadGfxArena* thga = &gfxCtx->polyOpa;

	if(HREG(59) == 1)
	{
		osSyncPrintf("graph_alloc siz=%d thga size=%08x bufp=%08x head=%08x tail=%08x\n", size, thga->size, thga->bufp, thga->p, thga->d);
	}
	return THGA_AllocEnd(&gfxCtx->polyOpa, ALIGN16(size));
}

void* Graph_Alloc2(GraphicsContext* gfxCtx, size_t size)
{
	TwoHeadGfxArena* thga = &gfxCtx->polyOpa;

	if(HREG(59) == 1)
	{
		osSyncPrintf("graph_alloc siz=%d thga size=%08x bufp=%08x head=%08x tail=%08x\n", size, thga->size, thga->bufp, thga->p, thga->d);
	}
	return THGA_AllocEnd(&gfxCtx->polyOpa, ALIGN16(size));
}

void Graph_OpenDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line)
{
	if(HREG(80) == 7 && HREG(82) != 4)
	{
		dispRefs[0] = gfxCtx->polyOpa.p;
		dispRefs[1] = gfxCtx->polyXlu.p;
		dispRefs[2] = gfxCtx->overlay.p;

		gDPNoOpOpenDisp(gfxCtx->polyOpa.p++, file, line);
		gDPNoOpOpenDisp(gfxCtx->polyXlu.p++, file, line);
		gDPNoOpOpenDisp(gfxCtx->overlay.p++, file, line);
	}
}

void Graph_CloseDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line)
{
	if(HREG(80) == 7 && HREG(82) != 4)
	{
		if(dispRefs[0] + 1 == gfxCtx->polyOpa.p)
		{
			gfxCtx->polyOpa.p = dispRefs[0];
		}
		else
		{
			gDPNoOpCloseDisp(gfxCtx->polyOpa.p++, file, line);
		}

		if(dispRefs[1] + 1 == gfxCtx->polyXlu.p)
		{
			gfxCtx->polyXlu.p = dispRefs[1];
		}
		else
		{
			gDPNoOpCloseDisp(gfxCtx->polyXlu.p++, file, line);
		}

		if(dispRefs[2] + 1 == gfxCtx->overlay.p)
		{
			gfxCtx->overlay.p = dispRefs[2];
		}
		else
		{
			gDPNoOpCloseDisp(gfxCtx->overlay.p++, file, line);
		}
	}
}

Gfx* Graph_GfxPlusOne(Gfx* gfx)
{
	return gfx + 1;
}

Gfx* Graph_BranchDlist(Gfx* gfx, Gfx* dst)
{
	gSPBranchList(gfx, dst);
	return dst;
}

void* Graph_DlistAlloc(Gfx** gfx, u32 size)
{
	u8* ptr;
	Gfx* dst;

	size = ((size + 7) & ~7),

	ptr = (u8*)(*gfx + 1);

	dst = (Gfx*)(ptr + size);
	gSPBranchList(*gfx, dst);

	*gfx = dst;
	return ptr;
}
