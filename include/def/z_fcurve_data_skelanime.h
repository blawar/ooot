#pragma once
#ifdef INTERNAL_SRC_CODE_Z_FCURVE_DATA_SKELANIME_C
void SkelCurve_Clear(SkelAnimeCurve* skelCurve);
void SkelCurve_Destroy(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve);
void SkelCurve_Draw(Actor* actor, GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, OverrideCurveLimbDraw overrideLimbDraw, PostCurveLimbDraw postLimbDraw, s32 lod, void* data);
s32 SkelCurve_Init(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, SkelCurveLimbList* limbListSeg, TransformUpdateIndex* transUpdIdx);
void SkelCurve_SetAnim(SkelAnimeCurve* skelCurve, TransformUpdateIndex* transUpdIdx, f32 arg2, f32 animFinalFrame, f32 animCurFrame, f32 animSpeed);
s32 SkelCurve_Update(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve);
#else
void SkelCurve_Clear(struct SkelAnimeCurve* skelCurve);
void SkelCurve_Destroy(struct GlobalContext* globalCtx, struct SkelAnimeCurve* skelCurve);
void SkelCurve_Draw(struct Actor* actor, struct GlobalContext* globalCtx, struct SkelAnimeCurve* skelCurve, OverrideCurveLimbDraw overrideLimbDraw, PostCurveLimbDraw postLimbDraw, s32 lod, void* data);
s32 SkelCurve_Init(struct GlobalContext* globalCtx, struct SkelAnimeCurve* skelCurve, struct SkelCurveLimbList* limbListSeg, struct TransformUpdateIndex* transUpdIdx);
void SkelCurve_SetAnim(struct SkelAnimeCurve* skelCurve, struct TransformUpdateIndex* transUpdIdx, f32 arg2, f32 animFinalFrame, f32 animCurFrame, f32 animSpeed);
s32 SkelCurve_Update(struct GlobalContext* globalCtx, struct SkelAnimeCurve* skelCurve);
#endif
