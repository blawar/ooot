#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_VISETEVENT_C
void osViSetEvent(OSMesgQueue* mq, OSMesg m, u32 retraceCount);
#else
void osViSetEvent(struct OSMesgQueue* mq, OSMesg m, u32 retraceCount);
#endif
