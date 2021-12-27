#pragma once
#ifdef INTERNAL_SRC_CODE_Z_MAP_MARK_C
void MapMark_ClearPointers(GlobalContext* globalCtx);
void MapMark_Draw(GlobalContext* globalCtx);
void MapMark_Init(GlobalContext* globalCtx);
#else
void MapMark_ClearPointers(struct GlobalContext* globalCtx);
void MapMark_Draw(struct GlobalContext* globalCtx);
void MapMark_Init(struct GlobalContext* globalCtx);
#endif
