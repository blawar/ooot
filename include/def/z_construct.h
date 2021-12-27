#pragma once
#ifdef INTERNAL_SRC_CODE_Z_CONSTRUCT_C
void Message_Init(GlobalContext* globalCtx);
void func_80110990(GlobalContext* globalCtx);
void func_801109B0(GlobalContext* globalCtx);
void func_80112098(GlobalContext* globalCtx);
#else
void Message_Init(struct GlobalContext* globalCtx);
void func_80110990(struct GlobalContext* globalCtx);
void func_801109B0(struct GlobalContext* globalCtx);
void func_80112098(struct GlobalContext* globalCtx);
#endif
