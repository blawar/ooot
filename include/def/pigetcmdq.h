#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PIGETCMDQ_C
OSMesgQueue* osPiGetCmdQueue(void);
#else
struct OSMesgQueue* osPiGetCmdQueue(void);
#endif
