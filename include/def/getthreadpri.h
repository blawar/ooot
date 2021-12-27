#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_GETTHREADPRI_C
OSPri osGetThreadPri(OSThread* thread);
#else
OSPri osGetThreadPri(struct OSThread* thread);
#endif
