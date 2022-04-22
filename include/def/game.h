#pragma once
struct GameState;
struct GraphicsContext;
struct OSViMode;

extern u32 gViConfigFeatures;
extern f32 gViConfigXScale;
extern f32 gViConfigYScale;
extern OSViMode osViModeNtscLan1;

void* GameState_Alloc(GameState* gameState, size_t size, const char* file, s32 line);
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
