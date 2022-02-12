#pragma once
struct OSMesgQueue;

void osViSetEvent(OSMesgQueue* mq, OSMesg m, u32 retraceCount);
