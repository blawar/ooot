#pragma once
struct PreRender;

void PreRender_Calc(PreRender* pthis);
void PreRender_Destroy(PreRender* pthis);
void PreRender_Init(PreRender* pthis);
void PreRender_SetValues(PreRender* pthis, u32 width, u32 height, void* fbuf, void* zbuf);
void PreRender_SetValuesSave(PreRender* pthis, u32 width, u32 height, void* fbuf, void* zbuf, void* cvg);
void func_800C0F28(PreRender* pthis, Gfx** gfxp, void* buf, void* bufSave);
void func_800C1258(PreRender* pthis, Gfx** gfxp);
void func_800C170C(PreRender* pthis, Gfx** gfxp, void* fbuf, void* fbufSave, u32 r, u32 g, u32 b, u32 a);
void func_800C1AE8(PreRender* pthis, Gfx** gfxp, void* fbuf, void* fbufSave);
void func_800C1B24(PreRender* pthis, Gfx** gfxp, void* fbuf, void* cvgSave);
void func_800C1E9C(PreRender* pthis, Gfx** gfxp);
void func_800C1F20(PreRender* pthis, Gfx** gfxp);
void func_800C1FA4(PreRender* pthis, Gfx** gfxp);
void func_800C20B4(PreRender* pthis, Gfx** gfxp);
void func_800C2118(PreRender* pthis, Gfx** gfxp);
void func_800C213C(PreRender* pthis, Gfx** gfxp);
void func_800C24BC(PreRender* pthis, Gfx** gfxp);
void func_800C24E0(PreRender* pthis, Gfx** gfxp);
void func_800C2500(PreRender* pthis, s32 x, s32 y);
void func_800C2FE4(PreRender* pthis);
