#pragma once

s32 Overlay_Load(Pointer vRomStart, Pointer vRomEnd, Pointer vRamStart, Pointer vRamEnd, Pointer allocatedVRamAddress);
void SystemHeap_Init(void* start, u32 size);
