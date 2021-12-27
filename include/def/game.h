#pragma once

extern u32 gViConfigFeatures;
extern f32 gViConfigXScale;
extern f32 gViConfigYScale;

#ifdef INTERNAL_SRC_CODE_GAME_C
void* GameState_Alloc(GameState* gameState, size_t size, char* file, s32 line);
void GameState_Destroy(GameState* gameState);
void GameState_Draw(GameState* gameState, GraphicsContext* gfxCtx);
void GameState_DrawInputDisplay(u16 input, Gfx** gfx);
void GameState_FaultPrint(void);
GameStateFunc GameState_GetInit(GameState* gameState);
void GameState_Init(GameState* gameState, GameStateFunc init, GraphicsContext* gfxCtx);
void GameState_InitArena(GameState* gameState, size_t size);
u32 GameState_IsRunning(GameState* gameState);
void GameState_Realloc(GameState* gameState, size_t size);
void GameState_ReqPadData(GameState* gameState);
void GameState_SetFBFilter(Gfx** gfx);
void GameState_SetFrameBuffer(GraphicsContext* gfxCtx);
void GameState_Update(GameState* gameState);
#else
void* GameState_Alloc(struct GameState* gameState, size_t size, char* file, s32 line);
void GameState_Destroy(struct GameState* gameState);
void GameState_Draw(struct GameState* gameState, struct GraphicsContext* gfxCtx);
void GameState_DrawInputDisplay(u16 input, Gfx** gfx);
void GameState_FaultPrint(void);
GameStateFunc GameState_GetInit(struct GameState* gameState);
void GameState_Init(struct GameState* gameState, GameStateFunc init, struct GraphicsContext* gfxCtx);
void GameState_InitArena(struct GameState* gameState, size_t size);
u32 GameState_IsRunning(struct GameState* gameState);
void GameState_Realloc(struct GameState* gameState, size_t size);
void GameState_ReqPadData(struct GameState* gameState);
void GameState_SetFBFilter(Gfx** gfx);
void GameState_SetFrameBuffer(struct GraphicsContext* gfxCtx);
void GameState_Update(struct GameState* gameState);
#endif
