#pragma once
#ifdef INTERNAL_SRC_CODE_PADMGR_C
void PadMgr_HandlePreNMI(PadMgr* padmgr);
void PadMgr_HandleRetraceMsg(PadMgr* padmgr);
void PadMgr_Init(PadMgr* padmgr, OSMesgQueue* siIntMsgQ, IrqMgr* irqMgr, OSId id, OSPri priority, void* stack);
void PadMgr_LockPadData(PadMgr* padmgr);
OSMesgQueue* PadMgr_LockSerialMesgQueue(PadMgr* padmgr);
void PadMgr_ProcessInputs(PadMgr* padmgr);
void PadMgr_RumbleControl(PadMgr* padmgr);
void PadMgr_RumbleReset(PadMgr* padmgr);
void PadMgr_RumbleSet(PadMgr* padmgr, u8* ctrlrRumbles);
void PadMgr_RumbleStop(PadMgr* padmgr);
void PadMgr_UnlockPadData(PadMgr* padmgr);
void PadMgr_UnlockSerialMesgQueue(PadMgr* padmgr, OSMesgQueue* ctrlrqueue);
#else
void PadMgr_HandlePreNMI(struct PadMgr* padmgr);
void PadMgr_HandleRetraceMsg(struct PadMgr* padmgr);
void PadMgr_Init(struct PadMgr* padmgr, struct OSMesgQueue* siIntMsgQ, struct IrqMgr* irqMgr, OSId id, OSPri priority, void* stack);
void PadMgr_LockPadData(struct PadMgr* padmgr);
struct OSMesgQueue* PadMgr_LockSerialMesgQueue(struct PadMgr* padmgr);
void PadMgr_ProcessInputs(struct PadMgr* padmgr);
void PadMgr_RumbleControl(struct PadMgr* padmgr);
void PadMgr_RumbleReset(struct PadMgr* padmgr);
void PadMgr_RumbleSet(struct PadMgr* padmgr, u8* ctrlrRumbles);
void PadMgr_RumbleStop(struct PadMgr* padmgr);
void PadMgr_UnlockPadData(struct PadMgr* padmgr);
void PadMgr_UnlockSerialMesgQueue(struct PadMgr* padmgr, struct OSMesgQueue* ctrlrqueue);
#endif
