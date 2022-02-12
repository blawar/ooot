#pragma once
struct OSMesgQueue;

extern OSMesgQueue __osPiAccessQueue;
extern u32 __osPiAccessQueueEnabled;

void __osPiCreateAccessQueue(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
