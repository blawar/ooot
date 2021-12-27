#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_DEQUEUETHREAD_C
void __osDequeueThread(OSThread** queue, OSThread* thread);
#else
void __osDequeueThread(struct OSThread** queue, struct OSThread* thread);
#endif
