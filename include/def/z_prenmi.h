#pragma once
#ifdef INTERNAL_SRC_CODE_Z_PRENMI_C
void PreNMI_Init(GameState* thisx);
#else
void PreNMI_Init(struct GameState* thisx);
#endif
