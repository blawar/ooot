#pragma once
#include "framerate.h"
#include "globalctx.h"
struct CutsceneContext;

extern Counter D_8015FCC0;
extern Counter D_8015FCC2;
extern Counter D_8015FCC4;
extern u8 D_8015FCC8;

void Cutscene_HandleConditionalTriggers(GlobalContext* globalCtx);
void Cutscene_HandleEntranceTriggers(GlobalContext* globalCtx);
void Cutscene_SetSegment(GlobalContext* globalCtx, void* segment);
void Cutscene_Stop(GlobalContext* globalCtx, CutsceneContext* csCtx);
void Cutscene_SetUnskipableInitNoLinkAction(GlobalContext* globalCtx, CutsceneContext* csCtx);
void Cutscene_SetUnskipableInitIfNotExec(GlobalContext* globalCtx, CutsceneContext* csCtx);
void Cutscene_CallStateHandler(GlobalContext* globalCtx, CutsceneContext* csCtx);
void Cinema_Update(GlobalContext* globalCtx, CutsceneContext* csCtx);
