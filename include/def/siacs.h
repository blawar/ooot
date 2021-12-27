#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_SIACS_C
void __osSiCreateAccessQueue(void);
void __osSiGetAccess(void);
void __osSiRelAccess(void);
#else
void __osSiCreateAccessQueue(void);
void __osSiGetAccess(void);
void __osSiRelAccess(void);
#endif
