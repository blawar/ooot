#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_GETCURRFAULTEDTHREAD_C
OSThread* __osGetCurrFaultedThread(void);
#else
struct OSThread* __osGetCurrFaultedThread(void);
#endif
