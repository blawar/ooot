#pragma once
#ifdef INTERNAL_SRC_CODE_PADUTILS_C
u32 PadUtils_CheckCur(Input* input, u16 key);
u32 PadUtils_CheckCurExact(Input* input, u16 value);
u32 PadUtils_CheckPressed(Input* input, u16 key);
u32 PadUtils_CheckReleased(Input* input, u16 key);
u16 PadUtils_GetCurButton(Input* input);
s8 PadUtils_GetCurX(Input* input);
s8 PadUtils_GetCurY(Input* input);
u16 PadUtils_GetPressButton(Input* input);
s8 PadUtils_GetRelX(Input* input);
s8 PadUtils_GetRelXImpl(Input* input);
s8 PadUtils_GetRelY(Input* input);
s8 PadUtils_GetRelYImpl(Input* input);
void PadUtils_Init(Input* input);
void PadUtils_ResetPressRel(Input* input);
void PadUtils_SetRelXY(Input* input, s32 x, s32 y);
void PadUtils_UpdateRelXY(Input* input);
void func_800FCB70(void);
#else
u32 PadUtils_CheckCur(struct Input* input, u16 key);
u32 PadUtils_CheckCurExact(struct Input* input, u16 value);
u32 PadUtils_CheckPressed(struct Input* input, u16 key);
u32 PadUtils_CheckReleased(struct Input* input, u16 key);
u16 PadUtils_GetCurButton(struct Input* input);
s8 PadUtils_GetCurX(struct Input* input);
s8 PadUtils_GetCurY(struct Input* input);
u16 PadUtils_GetPressButton(struct Input* input);
s8 PadUtils_GetRelX(struct Input* input);
s8 PadUtils_GetRelXImpl(struct Input* input);
s8 PadUtils_GetRelY(struct Input* input);
s8 PadUtils_GetRelYImpl(struct Input* input);
void PadUtils_Init(struct Input* input);
void PadUtils_ResetPressRel(struct Input* input);
void PadUtils_SetRelXY(struct Input* input, s32 x, s32 y);
void PadUtils_UpdateRelXY(struct Input* input);
void func_800FCB70(void);
#endif
