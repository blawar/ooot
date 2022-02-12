#pragma once
#include "ultra64/types.h"

void TransitionCircle_Start(void* thissx);
void* TransitionCircle_Init(void* thissx);
void TransitionCircle_Destroy(void* thissx);
void TransitionCircle_Update(void* thissx, s32 updateRate);
void TransitionCircle_Draw(void* thissx, Gfx** gfxP);
s32 TransitionCircle_IsDone(void* thissx);
void TransitionCircle_SetType(void* thissx, s32 type);
void TransitionCircle_SetColor(void* thissx, u32 color);
void TransitionCircle_SetEnvColor(void* thissx, u32 color);

void TransitionTriforce_Start(void* thiss);
void* TransitionTriforce_Init(void* thiss);
void TransitionTriforce_Destroy(void* thiss);
void TransitionTriforce_Update(void* thiss, s32 updateRate);
void TransitionTriforce_SetColor(void* thiss, u32 color);
void TransitionTriforce_SetType(void* thiss, s32 type);
void TransitionTriforce_Draw(void* thiss, Gfx** gfxP);
s32 TransitionTriforce_IsDone(void* thiss);

void TransitionWipe_Start(void* thiss);
void* TransitionWipe_Init(void* thiss);
void TransitionWipe_Destroy(void* thiss);
void TransitionWipe_Update(void* thiss, s32 updateRate);
void TransitionWipe_Draw(void* thiss, Gfx** gfxP);
s32 TransitionWipe_IsDone(void* thiss);
void TransitionWipe_SetType(void* thiss, s32 type);
void TransitionWipe_SetColor(void* thiss, u32 color);

void TransitionFade_Start(void* thiss);
void* TransitionFade_Init(void* thiss);
void TransitionFade_Destroy(void* thiss);
void TransitionFade_Update(void* thiss, s32 updateRate);
void TransitionFade_Draw(void* thiss, Gfx** gfxP);
s32 TransitionFade_IsDone(void* thiss);
void TransitionFade_SetColor(void* thiss, u32 color);
void TransitionFade_SetType(void* thiss, s32 type);
