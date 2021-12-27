#pragma once
#ifdef INTERNAL_SRC_BOOT_STACKCHECK_C
u32 StackCheck_Check(StackEntry* entry);
u32 StackCheck_CheckAll(void);
void StackCheck_Cleanup(StackEntry* entry);
StackStatus StackCheck_GetState(StackEntry* entry);
void StackCheck_Init(StackEntry* entry, void* stackTop, void* stackBottom, u32 initValue, s32 minSpace, const char* name);
#else
u32 StackCheck_Check(struct StackEntry* entry);
u32 StackCheck_CheckAll(void);
void StackCheck_Cleanup(struct StackEntry* entry);
StackStatus StackCheck_GetState(struct StackEntry* entry);
void StackCheck_Init(struct StackEntry* entry, void* stackTop, void* stackBottom, u32 initValue, s32 minSpace, const char* name);
#endif
