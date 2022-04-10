#pragma once
#include "globalctx.h"

extern f32 gBossMarkScale;
extern PauseMapMarksData* gLoadedPauseMarkDataTable;

void KaleidoScopeCall_Destroy(GlobalContext* globalCtx);
void KaleidoScopeCall_Draw(GlobalContext* globalCtx);
void KaleidoScopeCall_Init(GlobalContext* globalCtx);
void KaleidoScopeCall_LoadPlayer();
void KaleidoScopeCall_Update(GlobalContext* globalCtx);
