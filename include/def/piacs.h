#pragma once

extern OSMesgQueue __osPiAccessQueue;
extern u32 __osPiAccessQueueEnabled;

#ifdef INTERNAL_SRC_LIBULTRA_IO_PIACS_C
void __osPiCreateAccessQueue(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
#else
void __osPiCreateAccessQueue(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
#endif
