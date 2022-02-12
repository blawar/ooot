#pragma once

void SsSram_Dma(void* dramAddr, size_t size, s32 direction);
void SsSram_Init(u32 addr, u8 handleType, u8 handleDomain, u8 handleLatency, u8 handlePageSize, u8 handleRelDuration, u8 handlePulse, u32 handleSpeed);
void SsSram_ReadWrite(u32 addr, void* dramAddr, size_t size, s32 direction);
