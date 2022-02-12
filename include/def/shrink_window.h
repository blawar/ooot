#pragma once

void ShrinkWindow_Destroy(void);
u32 ShrinkWindow_GetCurrentVal(void);
u32 ShrinkWindow_GetVal(void);
void ShrinkWindow_Init(void);
void ShrinkWindow_SetCurrentVal(s32 nowVal);
void ShrinkWindow_SetVal(s32 value);
void ShrinkWindow_Update(s32 updateRate);
