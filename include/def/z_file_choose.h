#pragma once
#ifdef INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_FILE_CHOOSE_Z_FILE_CHOOSE_C
void FileChoose_Destroy(GameState* thisx);
void FileChoose_Init(GameState* thisx);
#else
void FileChoose_Destroy(struct GameState* thisx);
void FileChoose_Init(struct GameState* thisx);
#endif
