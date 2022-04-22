#pragma once
struct IrqMgr;
struct IrqMgrClient;
struct OSMesgQueue;

extern vu32 gIrqMgrResetStatus;
extern volatile OSTime gIrqMgrRetraceTime;

void IrqMgr_AddClient(IrqMgr* pthis, IrqMgrClient* c, OSMesgQueue* msgQ);
void IrqMgr_CheckStack();
void IrqMgr_HandlePRENMI450(IrqMgr* pthis);
void IrqMgr_HandlePRENMI480(IrqMgr* pthis);
void IrqMgr_HandlePRENMI500(IrqMgr* pthis);
void IrqMgr_HandlePreNMI(IrqMgr* pthis);
void IrqMgr_HandleRetrace(IrqMgr* pthis);
void IrqMgr_Init(IrqMgr* pthis, void* stack, OSPri pri, u8 retraceCount);
void IrqMgr_JamMesgForClient(IrqMgr* pthis, OSMesg msg);
void IrqMgr_RemoveClient(IrqMgr* pthis, IrqMgrClient* c);
void IrqMgr_SendMesgForClient(IrqMgr* pthis, OSMesg msg);
void IrqMgr_ThreadEntry(void* arg0);
