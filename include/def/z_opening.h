#pragma once
#ifdef INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_OPENING_Z_OPENING_C
void Opening_Destroy(GameState* thisx);
void Opening_Init(GameState* thisx);
#else
void Opening_Destroy(struct GameState* thisx);
void Opening_Init(struct GameState* thisx);
#endif
