#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_OS_JAMMESG_C
s32 osJamMesg(OSMesgQueue* mq, OSMesg mesg, s32 flag);
#else
s32 osJamMesg(struct OSMesgQueue* mq, OSMesg mesg, s32 flag);
#endif
