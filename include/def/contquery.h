#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_CONTQUERY_C
void osContGetQuery(OSContStatus* data);
s32 osContStartQuery(OSMesgQueue* mq);
#else
void osContGetQuery(struct OSContStatus* data);
s32 osContStartQuery(struct OSMesgQueue* mq);
#endif
