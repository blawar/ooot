#pragma once
struct GlobalContext;
struct CutsceneContext;

extern u16 D_8015FCC0;
extern u16 D_8015FCC2;
extern u16 D_8015FCC4;
extern u8 D_8015FCC8;

void Cutscene_HandleConditionalTriggers(GlobalContext* globalCtx);
void Cutscene_HandleEntranceTriggers(GlobalContext* globalCtx);
void Cutscene_SetSegment(GlobalContext* globalCtx, void* segment);
void func_8006450C(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064520(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064534(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064558(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_800645A0(GlobalContext* globalCtx, CutsceneContext* csCtx);
