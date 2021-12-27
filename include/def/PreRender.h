#pragma once
#ifdef INTERNAL_SRC_CODE_PRERENDER_C
void PreRender_Calc(PreRender* this);
void PreRender_Destroy(PreRender* this);
void PreRender_Init(PreRender* this);
void PreRender_SetValues(PreRender* this, u32 width, u32 height, void* fbuf, void* zbuf);
void PreRender_SetValuesSave(PreRender* this, u32 width, u32 height, void* fbuf, void* zbuf, void* cvg);
void func_800C0F28(PreRender* this, Gfx** gfxp, void* buf, void* bufSave);
void func_800C1258(PreRender* this, Gfx** gfxp);
void func_800C170C(PreRender* this, Gfx** gfxp, void* fbuf, void* fbufSave, u32 r, u32 g, u32 b, u32 a);
void func_800C1AE8(PreRender* this, Gfx** gfxp, void* fbuf, void* fbufSave);
void func_800C1B24(PreRender* this, Gfx** gfxp, void* fbuf, void* cvgSave);
void func_800C1E9C(PreRender* this, Gfx** gfxp);
void func_800C1F20(PreRender* this, Gfx** gfxp);
void func_800C1FA4(PreRender* this, Gfx** gfxp);
void func_800C20B4(PreRender* this, Gfx** gfxp);
void func_800C2118(PreRender* this, Gfx** gfxp);
void func_800C213C(PreRender* this, Gfx** gfxp);
void func_800C24BC(PreRender* this, Gfx** gfxp);
void func_800C24E0(PreRender* this, Gfx** gfxp);
void func_800C2500(PreRender* this, s32 x, s32 y);
void func_800C2FE4(PreRender* this);
#else
void PreRender_Calc(struct PreRender* this);
void PreRender_Destroy(struct PreRender* this);
void PreRender_Init(struct PreRender* this);
void PreRender_SetValues(struct PreRender* this, u32 width, u32 height, void* fbuf, void* zbuf);
void PreRender_SetValuesSave(struct PreRender* this, u32 width, u32 height, void* fbuf, void* zbuf, void* cvg);
void func_800C0F28(struct PreRender* this, Gfx** gfxp, void* buf, void* bufSave);
void func_800C1258(struct PreRender* this, Gfx** gfxp);
void func_800C170C(struct PreRender* this, Gfx** gfxp, void* fbuf, void* fbufSave, u32 r, u32 g, u32 b, u32 a);
void func_800C1AE8(struct PreRender* this, Gfx** gfxp, void* fbuf, void* fbufSave);
void func_800C1B24(struct PreRender* this, Gfx** gfxp, void* fbuf, void* cvgSave);
void func_800C1E9C(struct PreRender* this, Gfx** gfxp);
void func_800C1F20(struct PreRender* this, Gfx** gfxp);
void func_800C1FA4(struct PreRender* this, Gfx** gfxp);
void func_800C20B4(struct PreRender* this, Gfx** gfxp);
void func_800C2118(struct PreRender* this, Gfx** gfxp);
void func_800C213C(struct PreRender* this, Gfx** gfxp);
void func_800C24BC(struct PreRender* this, Gfx** gfxp);
void func_800C24E0(struct PreRender* this, Gfx** gfxp);
void func_800C2500(struct PreRender* this, s32 x, s32 y);
void func_800C2FE4(struct PreRender* this);
#endif
