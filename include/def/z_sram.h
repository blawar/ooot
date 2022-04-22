#pragma once
struct GameState;
struct SramContext;
struct FileChooseContext;
struct GlobalContext;

extern u16 gSramSlotOffsets[];

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
