#define INTERNAL_SRC_CODE_Z_FCURVE_DATA_SKELANIME_C
#include "global.h"
#include "z64global.h"
#include "framerate.h"
#include "z64animation.h"
#include "def/code_8006C510.h"
#include "def/graph.h" // FORCE
#include "def/sys_matrix.h"
#include "def/z_fcurve_data_skelanime.h"
#include "def/z_malloc.h"

void SkelCurve_Clear(SkelAnimeCurve* skelCurve)
{
	skelCurve->limbCount = 0;
	skelCurve->limbList = NULL;
	skelCurve->transUpdIdx = NULL;
	skelCurve->animCurFrame = 0.0f;
	skelCurve->animSpeed = 0.0f;
	skelCurve->animFinalFrame = 0.0f;
	skelCurve->transforms = NULL;
	skelCurve->unk_0C = 0.0f;
}

s32 SkelCurve_Init(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, SkelCurveLimbList* limbListSeg, TransformUpdateIndex* transUpdIdx)
{
	SkelCurveLimb** limbs;
	SkelCurveLimbList* limbList = (SkelCurveLimbList*)SEGMENTED_TO_VIRTUAL(limbListSeg);

	skelCurve->limbCount = limbList->limbCount;
	skelCurve->limbList = (SkelCurveLimb**)SEGMENTED_TO_VIRTUAL(limbList->limbs);

	skelCurve->transforms = (LimbTransform*)ZeldaArena_MallocDebug(sizeof(*skelCurve->transforms) * skelCurve->limbCount, "../z_fcurve_data_skelanime.c", 125);
	ASSERT(skelCurve->transforms != NULL, "this->now_joint != NULL", "../z_fcurve_data_skelanime.c", 127);
	skelCurve->animCurFrame = 0.0f;
	return 1;
}

void SkelCurve_Destroy(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve)
{
	if(skelCurve->transforms != NULL)
	{
		ZeldaArena_FreeDebug(skelCurve->transforms, "../z_fcurve_data_skelanime.c", 146);
	}
}

void SkelCurve_SetAnim(SkelAnimeCurve* skelCurve, TransformUpdateIndex* transUpdIdx, f32 arg2, f32 animFinalFrame, f32 animCurFrame, f32 animSpeed)
{
	skelCurve->unk_0C = arg2 - skelCurve->animSpeed;
	skelCurve->animFinalFrame = animFinalFrame;
	skelCurve->animCurFrame = animCurFrame;
	skelCurve->animSpeed = animSpeed;
	skelCurve->transUpdIdx = transUpdIdx;
}

s32 SkelCurve_Update(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve)
{
	s16* transforms;
	u8* transformRefIdx;
	TransformUpdateIndex* transformIndex;
	u16* transformCopyValues;
	s32 i;
	s32 ret = 0;
	s32 k;
	TransformData* transData;
	f32 transformValue;
	s32 j;

	transformIndex = (TransformUpdateIndex*)SEGMENTED_TO_VIRTUAL(skelCurve->transUpdIdx);
	transformRefIdx = (u8*)SEGMENTED_TO_VIRTUAL(transformIndex->refIndex);
	transData = (TransformData*)SEGMENTED_TO_VIRTUAL(transformIndex->transformData);
	transformCopyValues = (u16*)SEGMENTED_TO_VIRTUAL(transformIndex->copyValues);
	transforms = (s16*)skelCurve->transforms;

	skelCurve->animCurFrame += skelCurve->animSpeed * FRAMERATE_ANIM_SCALER;

	if((skelCurve->animSpeed >= 0.0f && skelCurve->animCurFrame > skelCurve->animFinalFrame) || (skelCurve->animSpeed < 0.0f && skelCurve->animCurFrame < skelCurve->animFinalFrame))
	{
		skelCurve->animCurFrame = skelCurve->animFinalFrame;
		ret = 1;
	}

	for(i = 0; i < skelCurve->limbCount; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 3; k++, transformRefIdx++, transforms++)
			{
				if(*transformRefIdx == 0)
				{
					transformValue = *transformCopyValues;
					*transforms = transformValue;
					transformCopyValues++;
				}
				else
				{
					transformValue = func_8006C5A8(skelCurve->animCurFrame, transData, *transformRefIdx);
					transData += *transformRefIdx;
					if(j == 0)
					{
						*transforms = transformValue * 1024.0f;
					}
					else if(j == 1)
					{
						*transforms = transformValue * (32768.0f / 180.0f);
					}
					else
					{
						*transforms = transformValue * 100.0f;
					}
				}
			}
		}
	}

	return ret;
}

void SkelCurve_DrawLimb(GlobalContext* globalCtx, s32 limbIndex, SkelAnimeCurve* skelCurve, OverrideCurveLimbDraw overrideLimbDraw, PostCurveLimbDraw postLimbDraw, s32 lod, void* data)
{
	SkelCurveLimb* limb = (SkelCurveLimb*)SEGMENTED_TO_VIRTUAL(skelCurve->limbList[limbIndex]);

	OPEN_DISPS(globalCtx->gfxCtx, "../z_fcurve_data_skelanime.c", 279);

	Matrix_Push();

	if(overrideLimbDraw == NULL || (overrideLimbDraw != NULL && overrideLimbDraw(globalCtx, skelCurve, limbIndex, data)))
	{
		Vec3f scale;
		Vec3s rot;
		Vec3f pos;
		Gfx* dList;
		Vec3s* transform = (Vec3s*)&skelCurve->transforms[limbIndex];

		scale.x = transform->x / 1024.0f;
		scale.y = transform->y / 1024.0f;
		scale.z = transform->z / 1024.0f;
		transform++;
		rot.x = transform->x;
		rot.y = transform->y;
		rot.z = transform->z;
		transform++;
		pos.x = transform->x;
		pos.y = transform->y;
		pos.z = transform->z;

		Matrix_TranslateRotateZYX(&pos, &rot);
		Matrix_Scale(scale.x, scale.y, scale.z, MTXMODE_APPLY);

		if(lod == 0)
		{
			s32 pad1;

			dList = limb->dList[0];
			if(dList != NULL)
			{
				gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_fcurve_data_skelanime.c", 321), G_MTX_LOAD | G_MTX_NOPUSH | G_MTX_MODELVIEW);
				gSPDisplayList(POLY_OPA_DISP++, dList);
			}
		}
		else if(lod == 1)
		{
			s32 pad2;

			dList = limb->dList[0];
			if(dList != NULL)
			{
				gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_fcurve_data_skelanime.c", 332), G_MTX_LOAD | G_MTX_NOPUSH | G_MTX_MODELVIEW);
				gSPDisplayList(POLY_OPA_DISP++, dList);
			}
			dList = limb->dList[1];
			if(dList != NULL)
			{
				gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_fcurve_data_skelanime.c", 338), G_MTX_LOAD | G_MTX_NOPUSH | G_MTX_MODELVIEW);
				gSPDisplayList(POLY_XLU_DISP++, dList);
			}
		}
		else
		{
			// "FcSkeletonInfo_draw_child (): Not supported"
			osSyncPrintf("FcSkeletonInfo_draw_child():未対応\n");
		}
	}

	if(postLimbDraw != NULL)
	{
		postLimbDraw(globalCtx, skelCurve, limbIndex, data);
	}

	if(limb->firstChildIdx != LIMB_DONE)
	{
		SkelCurve_DrawLimb(globalCtx, limb->firstChildIdx, skelCurve, overrideLimbDraw, postLimbDraw, lod, data);
	}

	Matrix_Pop();

	if(limb->nextLimbIdx != LIMB_DONE)
	{
		SkelCurve_DrawLimb(globalCtx, limb->nextLimbIdx, skelCurve, overrideLimbDraw, postLimbDraw, lod, data);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_fcurve_data_skelanime.c", 371);
}

void SkelCurve_Draw(Actor* actor, GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, OverrideCurveLimbDraw overrideLimbDraw, PostCurveLimbDraw postLimbDraw, s32 lod, void* data)
{
	if(skelCurve->transforms != NULL)
	{
		SkelCurve_DrawLimb(globalCtx, 0, skelCurve, overrideLimbDraw, postLimbDraw, lod, data);
	}
}
