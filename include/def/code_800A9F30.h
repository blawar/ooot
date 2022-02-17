#pragma once
struct PadMgr;

void Rumble_Init(PadMgr*, s32);
void Rumble_Shake2(f32, u8, u8, u8);
void Rumble_Shake(f32, u8, u8, u8);
void Rumble_Reset();
void Rumble_Destroy(void);
u32 Rumble_IsEnabled();
void Rumble_Stop();
void Rumble_Clear();
void Rumble_Enable(u32);
