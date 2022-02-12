#pragma once
struct OSContPad;
struct OSMesgQueue;

void __osPackReadData(void);
void osContGetReadData(OSContPad* pad);
s32 osContStartReadData(OSMesgQueue* mq);
