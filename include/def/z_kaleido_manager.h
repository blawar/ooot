#pragma once
struct KaleidoMgrOverlay;
struct GlobalContext;

extern u8 gBossMarkState;
extern KaleidoMgrOverlay* gKaleidoMgrCurOvl;
extern KaleidoMgrOverlay gKaleidoMgrOverlayTable[KALEIDO_OVL_MAX];

void KaleidoManager_ClearOvl(KaleidoMgrOverlay* ovl);
void KaleidoManager_Destroy();
void* KaleidoManager_GetRamAddr(void* vram);
void KaleidoManager_Init(GlobalContext* globalCtx);
void KaleidoManager_LoadOvl(KaleidoMgrOverlay* ovl);
