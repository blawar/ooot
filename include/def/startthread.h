#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_STARTTHREAD_C
void osStartThread(OSThread* thread);
#else
void osStartThread(struct OSThread* thread);
#endif
