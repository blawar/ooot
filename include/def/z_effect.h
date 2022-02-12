#pragma once
struct GlobalContext;
struct GraphicsContext;

void Effect_Add(GlobalContext* globalCtx, s32* pIndex, s32 type, u8 arg3, u8 arg4, void* initParams);
void Effect_Delete(GlobalContext* globalCtx, s32 index);
void Effect_DeleteAll(GlobalContext* globalCtx);
void Effect_DrawAll(GraphicsContext* gfxCtx);
void* Effect_GetByIndex(s32 index);
GlobalContext* Effect_GetGlobalCtx(void);
void Effect_InitContext(GlobalContext* globalCtx);
void Effect_UpdateAll(GlobalContext* globalCtx);
