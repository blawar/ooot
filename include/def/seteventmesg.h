#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_SETEVENTMESG_C
void osSetEventMesg(OSEvent e, OSMesgQueue* mq, OSMesg msg);
#else
void osSetEventMesg(OSEvent e, struct OSMesgQueue* mq, OSMesg msg);
#endif
