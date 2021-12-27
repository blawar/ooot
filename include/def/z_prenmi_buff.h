#pragma once
#ifdef INTERNAL_SRC_CODE_Z_PRENMI_BUFF_C
void PreNmiBuff_Init(PreNmiBuff* this);
u32 PreNmiBuff_IsResetting(PreNmiBuff* this);
void PreNmiBuff_SetReset(PreNmiBuff* this);
#else
void PreNmiBuff_Init(struct PreNmiBuff* this);
u32 PreNmiBuff_IsResetting(struct PreNmiBuff* this);
void PreNmiBuff_SetReset(struct PreNmiBuff* this);
#endif
