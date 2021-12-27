#pragma once
#ifdef INTERNAL_SRC_CODE_Z_SAMPLE_C
void Sample_Destroy(GameState* thisx);
void Sample_Init(GameState* thisx);
#else
void Sample_Destroy(struct GameState* thisx);
void Sample_Init(struct GameState* thisx);
#endif
