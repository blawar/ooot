#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_SPTASK_C
OSTask* _VirtualToPhysicalTask(OSTask* intp);
void osSpTaskLoad(OSTask* task);
void osSpTaskStartGo(OSTask* task);
#else
OSTask* _VirtualToPhysicalTask(OSTask* intp);
void osSpTaskLoad(OSTask* task);
void osSpTaskStartGo(OSTask* task);
#endif
