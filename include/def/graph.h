#pragma once
#include <memory>
#include "globalctx.h"
struct GraphicsContext;

void* Graph_Alloc(GraphicsContext* gfxCtx, size_t size);
void* Graph_Alloc2(GraphicsContext* gfxCtx, size_t size);
Gfx* Graph_BranchDlist(Gfx* gfx, Gfx* dst);
void Graph_CloseDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line);
void Graph_Destroy(GraphicsContext* gfxCtx);
void Graph_DisassembleUCode(Gfx* workBuf);
void* Graph_DlistAlloc(Gfx** gfx, u32 size);
void Graph_SetNextGameState(GameState* gameState);
Gfx* Graph_GfxPlusOne(Gfx* gfx);
void Graph_Init(GraphicsContext* gfxCtx);
void Graph_InitTHGA(GraphicsContext* gfxCtx);
void Graph_OpenDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line);
void Graph_TaskSet00(GraphicsContext* gfxCtx);
void Graph_ThreadEntry(void*);
void Graph_UCodeFaultClient(Gfx* workBuf);
void Graph_Update(GraphicsContext* gfxCtx, GameState* gameState);
