#pragma once
#include "ultra64/vi.h"

extern OSViContext* __osViCurr;
extern OSViContext* __osViNext;

#ifdef INTERNAL_SRC_LIBULTRA_IO_VI_C
void __osViInit(void);
#else
void __osViInit(void);
#endif
