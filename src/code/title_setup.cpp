#define INTERNAL_SRC_CODE_TITLE_SETUP_C
#include "global.h"
#include "z64game.h"
#include "z_title.h"
#include <z64save.h>
#include "def/title_setup.h"
#include "def/z_common_data.h"

void TitleSetup_InitImpl(GameState* gameState) {
    osSyncPrintf("Zelda common data initalization\n"); // "Zelda common data initalization"
    SaveContext_Init();
    gameState->running = false;
    SET_NEXT_GAMESTATE(gameState, Title_Init, TitleContext);
}

void TitleSetup_Destroy(GameState* gameState) {
}

void TitleSetup_Init(GameState* gameState) {
    gameState->destroy = TitleSetup_Destroy;
    TitleSetup_InitImpl(gameState);
}
