#pragma once
#ifdef INTERNAL_SRC_CODE_CODE_800FC620_C
s32 Overlay_Load(u32 vRomStart, u32 vRomEnd, void* vRamStart, void* vRamEnd, void* allocatedVRamAddress);
void SystemHeap_Init(void* start, u32 size);
#else
s32 Overlay_Load(u32 vRomStart, u32 vRomEnd, void* vRamStart, void* vRamEnd, void* allocatedVRamAddress);
void SystemHeap_Init(void* start, u32 size);
#endif
