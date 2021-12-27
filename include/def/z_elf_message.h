#pragma once
#ifdef INTERNAL_SRC_CODE_Z_ELF_MESSAGE_C
u16 ElfMessage_GetCUpText(GlobalContext* globalCtx);
u16 ElfMessage_GetSariaText(GlobalContext* globalCtx);
#else
u16 ElfMessage_GetCUpText(struct GlobalContext* globalCtx);
u16 ElfMessage_GetSariaText(struct GlobalContext* globalCtx);
#endif
