#pragma once
#ifdef INTERNAL_SRC_CODE_Z_EFFECT_C
void Effect_Add(GlobalContext* globalCtx, s32* pIndex, s32 type, u8 arg3, u8 arg4, void* initParams);
void Effect_Delete(GlobalContext* globalCtx, s32 index);
void Effect_DeleteAll(GlobalContext* globalCtx);
void Effect_DrawAll(GraphicsContext* gfxCtx);
void* Effect_GetByIndex(s32 index);
GlobalContext* Effect_GetGlobalCtx(void);
void Effect_InitContext(GlobalContext* globalCtx);
void Effect_UpdateAll(GlobalContext* globalCtx);
#else
void Effect_Add(struct GlobalContext* globalCtx, s32* pIndex, s32 type, u8 arg3, u8 arg4, void* initParams);
void Effect_Delete(struct GlobalContext* globalCtx, s32 index);
void Effect_DeleteAll(struct GlobalContext* globalCtx);
void Effect_DrawAll(struct GraphicsContext* gfxCtx);
void* Effect_GetByIndex(s32 index);
struct GlobalContext* Effect_GetGlobalCtx(void);
void Effect_InitContext(struct GlobalContext* globalCtx);
void Effect_UpdateAll(struct GlobalContext* globalCtx);
#endif
