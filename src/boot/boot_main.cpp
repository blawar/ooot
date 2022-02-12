#include "global.h"
#include "sched.h"

StackEntry sBootThreadInfo;
OSThread sIdleThread;
u8 sIdleThreadStack[0x400];
StackEntry sIdleThreadInfo;
u8 sBootThreadStack[0x400];


