#pragma once
#ifdef INTERNAL_SRC_CODE_Z_KALEIDO_SETUP_C
void KaleidoSetup_Destroy(GlobalContext* globalCtx);
void KaleidoSetup_Init(GlobalContext* globalCtx);
void KaleidoSetup_Update(GlobalContext* globalCtx);
#else
void KaleidoSetup_Destroy(struct GlobalContext* globalCtx);
void KaleidoSetup_Init(struct GlobalContext* globalCtx);
void KaleidoSetup_Update(struct GlobalContext* globalCtx);
#endif
