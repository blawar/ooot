#pragma once
struct ListAlloc;

void* ListAlloc_Alloc(ListAlloc* pthis, u32 size);
void ListAlloc_Free(ListAlloc* pthis, void* data);
void ListAlloc_FreeAll(ListAlloc* pthis);
ListAlloc* ListAlloc_Init(ListAlloc* pthis);
