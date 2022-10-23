#pragma once
struct GfxPrint;

Gfx* GfxPrint_Close(GfxPrint* pthis);
void GfxPrint_Destroy(GfxPrint* pthis);
void GfxPrint_Init(GfxPrint* pthis);
void GfxPrint_Open(GfxPrint* pthis, Gfx* dList);
s32 GfxPrint_Printf(GfxPrint* pthis, const char* fmt, ...);
void GfxPrint_SetBasePosPx(GfxPrint* pthis, s32 x, s32 y, u8 multiplier = 4);
void GfxPrint_SetColor(GfxPrint* pthis, u8 r, u8 g, u8 b, u8 a);
void GfxPrint_SetPos(GfxPrint* pthis, s32 x, s32 y);
void GfxPrint_SetPosPx(GfxPrint* pthis, s32 x, s32 y);

#ifdef DEBUG_PRINT
void Debug_Clear();
void Debug_Print(const char* String);
void Debug_Draw(GraphicsContext* gfxCtx);
#endif