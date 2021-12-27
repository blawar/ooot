#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_SETTHREADPRI_C
void osSetThreadPri(OSThread* thread, OSPri pri);
#else
void osSetThreadPri(struct OSThread* thread, OSPri pri);
#endif
