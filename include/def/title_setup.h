#pragma once
#ifdef INTERNAL_SRC_CODE_TITLE_SETUP_C
void TitleSetup_Destroy(GameState* gameState);
void TitleSetup_Init(GameState* gameState);
void TitleSetup_InitImpl(GameState* gameState);
#else
void TitleSetup_Destroy(struct GameState* gameState);
void TitleSetup_Init(struct GameState* gameState);
void TitleSetup_InitImpl(struct GameState* gameState);
#endif
