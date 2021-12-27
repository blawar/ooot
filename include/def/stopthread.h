#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_STOPTHREAD_C
void osStopThread(OSThread* thread);
#else
void osStopThread(struct OSThread* thread);
#endif
