#pragma once

void ShrinkWindow_SetVal(s32 value);
u32 ShrinkWindow_GetVal(void);
void ShrinkWindow_SetCurrentVal(s32 nowVal);
u32 ShrinkWindow_GetCurrentVal(void);
void ShrinkWindow_Init(void);
void ShrinkWindow_Destroy(void);
void ShrinkWindow_Update(s32 updateRate);

