#pragma once

extern u32 __osBaseCounter;
extern OSTime __osCurrentTime;
extern u32 __osTimerCounter;
extern OSTimer* __osTimerList;
extern u32 __osViIntrCount;

#ifdef INTERNAL_SRC_LIBULTRA_OS_TIMERINTR_C
OSTime __osInsertTimer(OSTimer* timer);
void __osSetTimerIntr(OSTime time);
void __osTimerInterrupt(void);
void __osTimerServicesInit(void);
#else
OSTime __osInsertTimer(struct OSTimer* timer);
void __osSetTimerIntr(OSTime time);
void __osTimerInterrupt(void);
void __osTimerServicesInit(void);
#endif
