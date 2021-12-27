#pragma once
#ifdef INTERNAL_SRC_CODE_Z_DRAW_C
void GetItem_Draw(GlobalContext* globalCtx, s16 drawId);
#else
void GetItem_Draw(struct GlobalContext* globalCtx, s16 drawId);
#endif
