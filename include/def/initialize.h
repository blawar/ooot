#pragma once

extern OSHWIntr __OSGlobalIntMask;
extern u32 __osShutdown;
extern s32 osViClock;

#ifdef INTERNAL_SRC_LIBULTRA_OS_INITIALIZE_C
void __osInitialize_autodetect(void);
void __osInitialize_common(void);
#else
void __osInitialize_autodetect(void);
void __osInitialize_common(void);
#endif
