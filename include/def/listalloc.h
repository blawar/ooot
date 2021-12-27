#pragma once
#ifdef INTERNAL_SRC_CODE_LISTALLOC_C
void* ListAlloc_Alloc(ListAlloc* this, u32 size);
void ListAlloc_Free(ListAlloc* this, void* data);
void ListAlloc_FreeAll(ListAlloc* this);
ListAlloc* ListAlloc_Init(ListAlloc* this);
#else
void* ListAlloc_Alloc(struct ListAlloc* this, u32 size);
void ListAlloc_Free(struct ListAlloc* this, void* data);
void ListAlloc_FreeAll(struct ListAlloc* this);
struct ListAlloc* ListAlloc_Init(struct ListAlloc* this);
#endif
