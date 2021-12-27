#pragma once
#ifdef INTERNAL_SRC_CODE_GFXPRINT_C
Gfx* GfxPrint_Close(GfxPrint* this);
void GfxPrint_Destroy(GfxPrint* this);
void GfxPrint_Init(GfxPrint* this);
void GfxPrint_Open(GfxPrint* this, Gfx* dList);
s32 GfxPrint_Printf(GfxPrint* this, const char* fmt, ...);
void GfxPrint_SetBasePosPx(GfxPrint* this, s32 x, s32 y);
void GfxPrint_SetColor(GfxPrint* this, u32 r, u32 g, u32 b, u32 a);
void GfxPrint_SetPos(GfxPrint* this, s32 x, s32 y);
void GfxPrint_SetPosPx(GfxPrint* this, s32 x, s32 y);
#else
Gfx* GfxPrint_Close(struct GfxPrint* this);
void GfxPrint_Destroy(struct GfxPrint* this);
void GfxPrint_Init(struct GfxPrint* this);
void GfxPrint_Open(struct GfxPrint* this, Gfx* dList);
s32 GfxPrint_Printf(struct GfxPrint* this, const char* fmt, ...);
void GfxPrint_SetBasePosPx(struct GfxPrint* this, s32 x, s32 y);
void GfxPrint_SetColor(struct GfxPrint* this, u32 r, u32 g, u32 b, u32 a);
void GfxPrint_SetPos(struct GfxPrint* this, s32 x, s32 y);
void GfxPrint_SetPosPx(struct GfxPrint* this, s32 x, s32 y);
#endif
