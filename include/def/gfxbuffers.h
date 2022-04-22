#pragma once
struct GfxPool;

extern GfxPool gGfxPools[2];
extern u64 gGfxSPTaskOutputBuffer[0x3000];
extern u8 gGfxSPTaskStack[0x400];
extern u8 gGfxSPTaskYieldBuffer[OS_YIELD_DATA_SIZE];
