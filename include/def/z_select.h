#pragma once
#ifdef INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_SELECT_Z_SELECT_C
void Select_Destroy(GameState* thisx);
void Select_Init(GameState* thisx);
#else
void Select_Destroy(struct GameState* thisx);
void Select_Init(struct GameState* thisx);
#endif
