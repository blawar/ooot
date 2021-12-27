#pragma once
#ifdef INTERNAL_SRC_CODE_Z_CHEAP_PROC_C
void Gfx_DrawDListOpa(GlobalContext* globalCtx, Gfx* dlist);
void Gfx_DrawDListXlu(GlobalContext* globalCtx, Gfx* dlist);
#else
void Gfx_DrawDListOpa(struct GlobalContext* globalCtx, Gfx* dlist);
void Gfx_DrawDListXlu(struct GlobalContext* globalCtx, Gfx* dlist);
#endif
