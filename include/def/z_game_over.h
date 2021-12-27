#pragma once
#ifdef INTERNAL_SRC_CODE_Z_GAME_OVER_C
void GameOver_FadeInLights(GlobalContext* globalCtx);
void GameOver_Init(GlobalContext* globalCtx);
void GameOver_Update(GlobalContext* globalCtx);
#else
void GameOver_FadeInLights(struct GlobalContext* globalCtx);
void GameOver_Init(struct GlobalContext* globalCtx);
void GameOver_Update(struct GlobalContext* globalCtx);
#endif
