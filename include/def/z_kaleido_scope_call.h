#pragma once

extern f32 gBossMarkScale;
extern PauseMapMarksData* gLoadedPauseMarkDataTable;

#ifdef INTERNAL_SRC_CODE_Z_KALEIDO_SCOPE_CALL_C
void KaleidoScopeCall_Destroy(GlobalContext* globalCtx);
void KaleidoScopeCall_Draw(GlobalContext* globalCtx);
void KaleidoScopeCall_Init(GlobalContext* globalCtx);
void KaleidoScopeCall_LoadPlayer();
void KaleidoScopeCall_Update(GlobalContext* globalCtx);
#else
void KaleidoScopeCall_Destroy(struct GlobalContext* globalCtx);
void KaleidoScopeCall_Draw(struct GlobalContext* globalCtx);
void KaleidoScopeCall_Init(struct GlobalContext* globalCtx);
void KaleidoScopeCall_LoadPlayer(void);
void KaleidoScopeCall_Update(struct GlobalContext* globalCtx);
#endif
