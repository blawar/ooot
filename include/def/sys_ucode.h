#pragma once
#ifdef INTERNAL_SRC_CODE_SYS_UCODE_C
u64* SysUcode_GetUCode(void);
u64* SysUcode_GetUCodeBoot(void);
u64 SysUcode_GetUCodeBootSize(void);
u64* SysUcode_GetUCodeData(void);
#else
u64* SysUcode_GetUCode(void);
u64* SysUcode_GetUCodeBoot(void);
u64 SysUcode_GetUCodeBootSize(void);
u64* SysUcode_GetUCodeData(void);
#endif
