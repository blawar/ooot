#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_GETTHREADID_C
OSId osGetThreadId(OSThread* thread);
#else
OSId osGetThreadId(struct OSThread* thread);
#endif
