#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_GETACTIVEQUEUE_C
OSThread* __osGetActiveQueue(void);
#else
struct OSThread* __osGetActiveQueue(void);
#endif
