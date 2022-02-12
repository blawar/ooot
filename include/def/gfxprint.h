#pragma once
struct GfxPrint;

Gfx* GfxPrint_Close(GfxPrint* pthis);
void GfxPrint_Destroy(GfxPrint* pthis);
void GfxPrint_Init(GfxPrint* pthis);
void GfxPrint_Open(GfxPrint* pthis, Gfx* dList);
s32 GfxPrint_Printf(GfxPrint* pthis, const char* fmt, ...);
void GfxPrint_SetBasePosPx(GfxPrint* pthis, s32 x, s32 y);
void GfxPrint_SetColor(GfxPrint* pthis, u32 r, u32 g, u32 b, u32 a);
void GfxPrint_SetPos(GfxPrint* pthis, s32 x, s32 y);
void GfxPrint_SetPosPx(GfxPrint* pthis, s32 x, s32 y);
