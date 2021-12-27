#pragma once
#ifdef INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_TITLE_Z_TITLE_C
void Title_Destroy(GameState* thisx);
void Title_Init(GameState* thisx);
#else
void Title_Destroy(struct GameState* thisx);
void Title_Init(struct GameState* thisx);
#endif
