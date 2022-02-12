#pragma once
struct StackEntry;

u32 StackCheck_Check(StackEntry* entry);
u32 StackCheck_CheckAll(void);
void StackCheck_Cleanup(StackEntry* entry);
StackStatus StackCheck_GetState(StackEntry* entry);
void StackCheck_Init(StackEntry* entry, void* stackTop, void* stackBottom, u32 initValue, s32 minSpace, const char* name);
