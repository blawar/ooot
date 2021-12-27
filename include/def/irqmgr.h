#pragma once

extern vu32 gIrqMgrResetStatus;
extern volatile OSTime gIrqMgrRetraceTime;

#ifdef INTERNAL_SRC_CODE_IRQMGR_C
void IrqMgr_AddClient(IrqMgr* this, IrqMgrClient* c, OSMesgQueue* msgQ);
void IrqMgr_CheckStack();
void IrqMgr_HandlePRENMI450(IrqMgr* this);
void IrqMgr_HandlePRENMI480(IrqMgr* this);
void IrqMgr_HandlePRENMI500(IrqMgr* this);
void IrqMgr_HandlePreNMI(IrqMgr* this);
void IrqMgr_HandleRetrace(IrqMgr* this);
void IrqMgr_Init(IrqMgr* this, void* stack, OSPri pri, u8 retraceCount);
void IrqMgr_JamMesgForClient(IrqMgr* this, OSMesg msg);
void IrqMgr_RemoveClient(IrqMgr* this, IrqMgrClient* c);
void IrqMgr_SendMesgForClient(IrqMgr* this, OSMesg msg);
void IrqMgr_ThreadEntry(void* arg0);
#else
void IrqMgr_AddClient(struct IrqMgr* this, struct IrqMgrClient* c, struct OSMesgQueue* msgQ);
void IrqMgr_CheckStack(void);
void IrqMgr_HandlePRENMI450(struct IrqMgr* this);
void IrqMgr_HandlePRENMI480(struct IrqMgr* this);
void IrqMgr_HandlePRENMI500(struct IrqMgr* this);
void IrqMgr_HandlePreNMI(struct IrqMgr* this);
void IrqMgr_HandleRetrace(struct IrqMgr* this);
void IrqMgr_Init(struct IrqMgr* this, void* stack, OSPri pri, u8 retraceCount);
void IrqMgr_JamMesgForClient(struct IrqMgr* this, OSMesg msg);
void IrqMgr_RemoveClient(struct IrqMgr* this, struct IrqMgrClient* c);
void IrqMgr_SendMesgForClient(struct IrqMgr* this, OSMesg msg);
void IrqMgr_ThreadEntry(void* arg0);
#endif
