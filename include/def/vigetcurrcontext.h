#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_VIGETCURRCONTEXT_C
OSViContext* __osViGetCurrentContext(void);
#else
struct OSViContext* __osViGetCurrentContext(void);
#endif
