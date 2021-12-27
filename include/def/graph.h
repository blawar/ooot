#pragma once
#ifdef INTERNAL_SRC_CODE_GRAPH_C
void* Graph_Alloc(GraphicsContext* gfxCtx, size_t size);
void* Graph_Alloc2(GraphicsContext* gfxCtx, size_t size);
Gfx* Graph_BranchDlist(Gfx* gfx, Gfx* dst);
void Graph_CloseDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line);
void Graph_Destroy(GraphicsContext* gfxCtx);
void Graph_DisassembleUCode(Gfx* workBuf);
void* Graph_DlistAlloc(Gfx** gfx, u32 size);
GameStateOverlay* Graph_GetNextGameState(GameState* gameState);
Gfx* Graph_GfxPlusOne(Gfx* gfx);
void Graph_Init(GraphicsContext* gfxCtx);
void Graph_InitTHGA(GraphicsContext* gfxCtx);
void Graph_OpenDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line);
void Graph_TaskSet00(GraphicsContext* gfxCtx);
void Graph_ThreadEntry(void*);
void Graph_UCodeFaultClient(Gfx* workBuf);
void Graph_Update(GraphicsContext* gfxCtx, GameState* gameState);
#else
void* Graph_Alloc(struct GraphicsContext* gfxCtx, size_t size);
void* Graph_Alloc2(struct GraphicsContext* gfxCtx, size_t size);
Gfx* Graph_BranchDlist(Gfx* gfx, Gfx* dst);
void Graph_CloseDisps(Gfx** dispRefs, struct GraphicsContext* gfxCtx, const char* file, s32 line);
void Graph_Destroy(struct GraphicsContext* gfxCtx);
void Graph_DisassembleUCode(Gfx* workBuf);
void* Graph_DlistAlloc(Gfx** gfx, u32 size);
struct GameStateOverlay* Graph_GetNextGameState(struct GameState* gameState);
Gfx* Graph_GfxPlusOne(Gfx* gfx);
void Graph_Init(struct GraphicsContext* gfxCtx);
void Graph_InitTHGA(struct GraphicsContext* gfxCtx);
void Graph_OpenDisps(Gfx** dispRefs, struct GraphicsContext* gfxCtx, const char* file, s32 line);
void Graph_TaskSet00(struct GraphicsContext* gfxCtx);
void Graph_ThreadEntry(void*);
void Graph_UCodeFaultClient(Gfx* workBuf);
void Graph_Update(struct GraphicsContext* gfxCtx, struct GameState* gameState);
#endif
