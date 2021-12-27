#pragma once

extern u16 gSramSlotOffsets[];

#ifdef INTERNAL_SRC_CODE_Z_SRAM_C
void Sram_Alloc(GameState* gameState, SramContext* sramCtx);
void Sram_CopySave(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_EraseSave(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_Init(GlobalContext* globalCtx, SramContext* sramCtx);
void Sram_InitDebugSave(void);
void Sram_InitNewSave(void);
void Sram_InitSave(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_InitSram(GameState* gameState, SramContext* sramCtx);
void Sram_OpenSave(SramContext* sramCtx);
void Sram_VerifyAndLoadAllSaves(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_WriteSave(SramContext* sramCtx);
void Sram_WriteSramHeader(SramContext* sramCtx);
#else
void Sram_Alloc(struct GameState* gameState, struct SramContext* sramCtx);
void Sram_CopySave(struct FileChooseContext* fileChoose, struct SramContext* sramCtx);
void Sram_EraseSave(struct FileChooseContext* fileChoose, struct SramContext* sramCtx);
void Sram_Init(struct GlobalContext* globalCtx, struct SramContext* sramCtx);
void Sram_InitDebugSave(void);
void Sram_InitNewSave(void);
void Sram_InitSave(struct FileChooseContext* fileChoose, struct SramContext* sramCtx);
void Sram_InitSram(struct GameState* gameState, struct SramContext* sramCtx);
void Sram_OpenSave(struct SramContext* sramCtx);
void Sram_VerifyAndLoadAllSaves(struct FileChooseContext* fileChoose, struct SramContext* sramCtx);
void Sram_WriteSave(struct SramContext* sramCtx);
void Sram_WriteSramHeader(struct SramContext* sramCtx);
#endif
