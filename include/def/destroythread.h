#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_DESTROYTHREAD_C
void osDestroyThread(OSThread* thread);
#else
void osDestroyThread(struct OSThread* thread);
#endif
