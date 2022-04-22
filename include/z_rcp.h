#pragma once
#include "gfx.h"

void func_80093D18(GraphicsContext* gfxCtx);
Gfx* Gfx_SetFog(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 near, s32 far);
Gfx* Gfx_SetFogWithSync(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 near, s32 far);
Gfx* Gfx_SetFog2(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 near, s32 far);
Gfx* Gfx_CallSetupDL(Gfx* gfx, u32 i);
Gfx* func_800937C0(Gfx* gfx);
Gfx* func_80093808(Gfx* gfx);
void func_800938B4(GraphicsContext* gfxCtx);
void func_8009398C(GraphicsContext* gfxCtx);
void func_80093AD0(GraphicsContext* gfxCtx);
void func_80093BA8(GraphicsContext* gfxCtx);
void func_80093C14(GraphicsContext* gfxCtx);
void func_80093C80(GlobalContext* globalCtx);
void func_80093D18(GraphicsContext* gfxCtx);
void func_80093D84(GraphicsContext* gfxCtx);
Gfx* func_80093F34(Gfx* gfx);
Gfx* func_80093F58(Gfx* gfx);
void func_80094044(GraphicsContext* gfxCtx);
void func_800940B0(GraphicsContext* gfxCtx);
void func_80094140(GraphicsContext* gfxCtx);
Gfx* func_8009411C(Gfx* gfx);
void func_800942F0(GraphicsContext* gfxCtx);
void func_8009435C(GraphicsContext* gfxCtx);
void func_800943C8(GraphicsContext* gfxCtx);
Gfx* func_800944A0(Gfx* gfx);
void func_800944C4(GraphicsContext* gfxCtx);
void func_80094520(GraphicsContext* gfxCtx);
void func_8009457C(Gfx** gfxp);
void func_800945A0(GraphicsContext* gfxCtx);
void func_8009460C(GraphicsContext* gfxCtx);
void func_80094678(GraphicsContext* gfxCtx);
Gfx* func_80094968(Gfx* gfx);
Gfx* func_800946E4(Gfx* gfx);
Gfx* func_800947AC(Gfx* gfx);
void func_800949A8(GraphicsContext* gfxCtx);
void func_80094A14(GraphicsContext* gfxCtx);
void func_80094B58(GraphicsContext* gfxCtx);
void func_80094BC4(GraphicsContext* gfxCtx);
void func_80094C50(GraphicsContext* gfxCtx);
void func_80094D28(Gfx** gfxp);
Gfx* Gfx_BranchTexScroll(Gfx** gfxp, u32 x, u32 y, s32 width, s32 height);
Gfx* func_80094E78(GraphicsContext* gfxCtx, u32 x, u32 y);
Gfx* Gfx_TexScroll(GraphicsContext* gfxCtx, u32 x, u32 y, s32 width, s32 height);
Gfx* Gfx_TwoTexScroll(GraphicsContext* gfxCtx, s32 tile1, u32 x1, u32 y1, s32 width1, s32 height1, s32 tile2, u32 x2,
    u32 y2, s32 width2, s32 height2);
Gfx* Gfx_TwoTexScrollEnvColor(GraphicsContext* gfxCtx, s32 tile1, u32 x1, u32 y1, s32 width1, s32 height1, s32 tile2,
    u32 x2, u32 y2, s32 width2, s32 height2, s32 r, s32 g, s32 b, s32 a);
Gfx* Gfx_EnvColor(GraphicsContext* gfxCtx, s32 r, s32 g, s32 b, s32 a);
void Gfx_ClearDisplay(GraphicsContext* gfxCtx, u8 r, u8 g, u8 b);
void func_80095974(GraphicsContext* gfxCtx);
