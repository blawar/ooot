#pragma once
#ifdef INTERNAL_SRC_CODE_FLG_SET_C
void FlagSet_Update(GlobalContext* globalCtx);
#else
void FlagSet_Update(struct GlobalContext* globalCtx);
#endif
