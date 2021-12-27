#pragma once

extern u16 D_8015FCC0;
extern u16 D_8015FCC2;
extern u16 D_8015FCC4;
extern u8 D_8015FCC8;

#ifdef INTERNAL_SRC_CODE_Z_DEMO_C
void Cutscene_HandleConditionalTriggers(GlobalContext* globalCtx);
void Cutscene_HandleEntranceTriggers(GlobalContext* globalCtx);
void Cutscene_SetSegment(GlobalContext* globalCtx, void* segment);
void func_8006450C(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064520(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064534(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064558(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_800645A0(GlobalContext* globalCtx, CutsceneContext* csCtx);
#else
void Cutscene_HandleConditionalTriggers(struct GlobalContext* globalCtx);
void Cutscene_HandleEntranceTriggers(struct GlobalContext* globalCtx);
void Cutscene_SetSegment(struct GlobalContext* globalCtx, void* segment);
void func_8006450C(struct GlobalContext* globalCtx, struct CutsceneContext* csCtx);
void func_80064520(struct GlobalContext* globalCtx, struct CutsceneContext* csCtx);
void func_80064534(struct GlobalContext* globalCtx, struct CutsceneContext* csCtx);
void func_80064558(struct GlobalContext* globalCtx, struct CutsceneContext* csCtx);
void func_800645A0(struct GlobalContext* globalCtx, struct CutsceneContext* csCtx);
#endif
