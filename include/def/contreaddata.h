#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_CONTREADDATA_C
void __osPackReadData(void);
void osContGetReadData(OSContPad* pad);
s32 osContStartReadData(OSMesgQueue* mq);
#else
void __osPackReadData(void);
void osContGetReadData(struct OSContPad* pad);
s32 osContStartReadData(struct OSMesgQueue* mq);
#endif
