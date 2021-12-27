#pragma once

void* THA_GetHead(struct TwoHeadArena** tha);
void THA_SetHead(struct TwoHeadArena** tha, void* start);
void* THA_GetTail(struct TwoHeadArena** tha);
void* THA_AllocStart(struct TwoHeadArena** tha, u32 size);
void* THA_AllocStart1(struct TwoHeadArena** tha);
void* THA_AllocEnd(struct TwoHeadArena** tha, u32 size);
void* THA_AllocEndAlign16(struct TwoHeadArena** tha, u32 size);
void* THA_AllocEndAlign(struct TwoHeadArena** tha, u32 size, uintptr_t mask);
s32 THA_GetSize(struct TwoHeadArena** tha);
u32 THA_IsCrash(struct TwoHeadArena** tha);
void THA_Init(struct TwoHeadArena** tha);
void THA_Ct(struct TwoHeadArena** tha, void* ptr, u32 size);
void THA_Dt(struct TwoHeadArena** tha);
