#pragma once
struct SkelAnimeCurve;
struct GlobalContext;
struct Actor;
struct SkelCurveLimbList;
struct TransformUpdateIndex;

void SkelCurve_Clear(SkelAnimeCurve* skelCurve);
void SkelCurve_Destroy(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve);
void SkelCurve_Draw(Actor* actor, GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, OverrideCurveLimbDraw overrideLimbDraw, PostCurveLimbDraw postLimbDraw, s32 lod, void* data);
s32 SkelCurve_Init(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, SkelCurveLimbList* limbListSeg, TransformUpdateIndex* transUpdIdx);
void SkelCurve_SetAnim(SkelAnimeCurve* skelCurve, TransformUpdateIndex* transUpdIdx, f32 arg2, f32 animFinalFrame, f32 animCurFrame, f32 animSpeed);
s32 SkelCurve_Update(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve);
