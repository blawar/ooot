#ifndef Z64_ANIMATION_H
#define Z64_ANIMATION_H

#include "ultra64.h"
#include "z64dma.h"
#include "z64math.h"
#include "globalctx.h"

struct Actor;
struct SkelAnime;

#define LIMB_DONE 0xFF
#define ANIMATION_ENTRY_MAX 50
#define ANIM_FLAG_UPDATEY (1 << 1)
#define ANIM_FLAG_NOMOVE (1 << 4)

enum AnimationModes
{
	/* 0 */ ANIMMODE_LOOP,
	/* 1 */ ANIMMODE_LOOP_INTERP,
	/* 2 */ ANIMMODE_ONCE,
	/* 3 */ ANIMMODE_ONCE_INTERP,
	/* 4 */ ANIMMODE_LOOP_PARTIAL,
	/* 5 */ ANIMMODE_LOOP_PARTIAL_INTERP
};

enum AnimationTapers
{
	/* -1 */ ANIMTAPER_DECEL = -1,
	/*  0 */ ANIMTAPER_NONE,
	/*  1 */ ANIMTAPER_ACCEL
};

struct StandardLimb
{
	/* 0x00 */ Vec3s jointPos; // Root is position in model space, children are relative to parent
	/* 0x06 */ u8 child;
	/* 0x07 */ u8 sibling;
	/* 0x08 */ Gfx* dList;
}; // size = 0xC

struct LodLimb
{
	/* 0x00 */ Vec3s jointPos; // Root is position in model space, children are relative to parent
	/* 0x06 */ u8 child;
	/* 0x07 */ u8 sibling;
	/* 0x08 */ Gfx* dLists[2]; // Near and far
};				   // size = 0x10

struct SkinLimb
{
	/* 0x00 */ Vec3s jointPos; // Root is position in model space, children are relative to parent
	/* 0x06 */ u8 child;
	/* 0x07 */ u8 sibling;
	/* 0x08 */ s32 unk_8;	  // Type of data contained in segment
	/* 0x0C */ void* segment; // Segment address of data. Currently unclear what.
};				  // size = 0x10

struct LegacyLimb
{
	/* 0x000 */ Gfx* dList;
	/* 0x004 */ Vec3f trans;
	/* 0x010 */ Vec3s rot;
	/* 0x018 */ struct LegacyLimb* sibling;
	/* 0x01C */ struct LegacyLimb* child;
}; // size = 0x20

// Model has limbs with only rigid meshes
struct SkeletonHeader
{
	/* 0x00 */ void** segment;
	/* 0x04 */ u8 limbCount;
}; // size = 0x8

// Model has limbs with flexible meshes
struct FlexSkeletonHeader
{
	/* 0x00 */ SkeletonHeader sh;
	/* 0x08 */ u8 dListCount;
}; // size = 0xC

// Index into the frame data table.
struct JointIndex
{
	/* 0x00 */ u16 x;
	/* 0x02 */ u16 y;
	/* 0x04 */ u16 z;
}; // size = 0x06

struct AnimationHeaderCommon
{
	/* 0x00 */ s16 frameCount;
};

struct LinkAnimationHeader
{
	/* 0x00 */ AnimationHeaderCommon common;
	/* 0x04 */ void* segment;
}; // size = 0x8

struct AnimationHeader
{
	/* 0x00 */ AnimationHeaderCommon common;
	/* 0x04 */ s16* frameData;	     // "tbl"
	/* 0x08 */ JointIndex* jointIndices; // "ref_tbl"
	/* 0x0C */ u16 staticIndexMax;
}; // size = 0x10

// Unused
struct JointKey
{
	/* 0x00 */ s16 xMax;
	/* 0x02 */ s16 x;
	/* 0x04 */ s16 yMax;
	/* 0x06 */ s16 y;
	/* 0x08 */ s16 zMax;
	/* 0x0A */ s16 z;
}; // size = 0x0C

// Unused
struct LegacyAnimationHeader
{
	/* 0x00 */ s16 frameCount;
	/* 0x02 */ s16 limbCount;
	/* 0x04 */ s16* frameData;
	/* 0x08 */ JointKey* jointKey;
}; // size = 0xC

typedef s32 (*OverrideLimbDrawOpa)(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void*);

typedef void (*PostLimbDrawOpa)(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void*);

typedef s32 (*OverrideLimbDraw)(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void*, Gfx** gfx);

typedef void (*PostLimbDraw)(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void*, Gfx** gfx);

enum AnimationType
{
	ANIMENTRY_LOADFRAME,
	ANIMENTRY_COPYALL,
	ANIMENTRY_INTERP,
	ANIMENTRY_COPYTRUE,
	ANIMENTRY_COPYFALSE,
	ANIMENTRY_MOVEACTOR
};

struct AnimEntryLoadFrame
{
	/* 0x000 */ DmaRequest req;
	/* 0x020 */ OSMesgQueue msgQueue;
	/* 0x038 */ OSMesg msg;
}; // size = 0x3C

struct AnimEntryCopyAll
{
	/* 0x000 */ u8 queueFlag;
	/* 0x001 */ u8 vecCount;
	/* 0x004 */ Vec3s* dst;
	/* 0x008 */ Vec3s* src;
}; // size = 0xC

struct AnimEntryInterp
{
	/* 0x000 */ u8 queueFlag;
	/* 0x001 */ u8 vecCount;
	/* 0x004 */ Vec3s* base;
	/* 0x008 */ Vec3s* mod;
	/* 0x00C */ f32 weight;
}; // size = 0x10

struct AnimEntryCopyTrue
{
	/* 0x000 */ u8 queueFlag;
	/* 0x001 */ u8 vecCount;
	/* 0x004 */ Vec3s* dst;
	/* 0x008 */ Vec3s* src;
	/* 0x00C */ const u8* copyFlag;
}; // size = 0x10

struct AnimEntryCopyFalse
{
	/* 0x000 */ u8 queueFlag;
	/* 0x001 */ u8 vecCount;
	/* 0x004 */ Vec3s* dst;
	/* 0x008 */ Vec3s* src;
	/* 0x00C */ const u8* copyFlag;
}; // size = 0x10

struct AnimEntryMoveActor
{
	/* 0x000 */ struct Actor* actor;
	/* 0x004 */ struct SkelAnime* skelAnime;
	/* 0x008 */ f32 unk_08;
}; // size = 0xC

union AnimationEntryData
{
	AnimEntryLoadFrame load;
	AnimEntryCopyAll copy;
	AnimEntryInterp interp;
	AnimEntryCopyTrue copy1;
	AnimEntryCopyFalse copy0;
	AnimEntryMoveActor move;
}; // size = 0x3C

struct AnimationEntry
{
	/* 0x00 */ u8 type;
	/* 0x04 */ AnimationEntryData data;
}; // size = 0x40

struct AnimationContext
{
	s16 animationCount;
	AnimationEntry entries[ANIMATION_ENTRY_MAX];
}; // size = 0xC84

typedef void (*AnimationEntryCallback)(GlobalContext* globalCtx, AnimationEntryData* data);

// fcurve_skelanime structs
struct TransformData
{
	/* 0x0000 */ u16 unk_00; // appears to be flags
	/* 0x0002 */ s16 unk_02;
	/* 0x0004 */ s16 unk_04;
	/* 0x0006 */ s16 unk_06;
	/* 0x0008 */ f32 unk_08;
}; // size = 0xC

struct TransformUpdateIndex
{
	/* 0x0000 */ u8* refIndex;
	/* 0x0004 */ TransformData* transformData;
	/* 0x0008 */ s16* copyValues;
	/* 0x000C */ s16 unk_0C;
	/* 0x000E */ s16 unk_0E;
}; // size = 0x10

struct SkelCurveLimb
{
	/* 0x0000 */ u8 firstChildIdx;
	/* 0x0001 */ u8 nextLimbIdx;
	/* 0x0004 */ Gfx* dList[2];
}; // size = 0xC

struct SkelCurveLimbList
{
	/* 0x0000 */ SkelCurveLimb** limbs;
	/* 0x0004 */ u8 limbCount;
}; // size = 0x8

struct LimbTransform
{
	/* 0x0000 */ Vec3s scale;
	/* 0x0006 */ Vec3s rot;
	/* 0x000C */ Vec3s pos;
}; // size = 0x12

struct SkelAnimeCurve
{
	/* 0x0000 */ u8 limbCount;
	/* 0x0004 */ SkelCurveLimb** limbList;
	/* 0x0008 */ TransformUpdateIndex* transUpdIdx;
	/* 0x000C */ f32 unk_0C; // seems to be unused
	/* 0x0010 */ f32 animFinalFrame;
	/* 0x0014 */ f32 animSpeed;
	/* 0x0018 */ f32 animCurFrame;
	/* 0x001C */ LimbTransform* transforms;
}; // size = 0x20

typedef s32 (*OverrideCurveLimbDraw)(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, s32 limbIndex, void*);
typedef void (*PostCurveLimbDraw)(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, s32 limbIndex, void*);

typedef s32 (*AnimUpdateFunc)();

struct SkelAnime
{
	/* 0x00 */ u8 limbCount;			      // Number of limbs in the skeleton
	/* 0x01 */ u8 mode;				      // 0: loop, 2: play once, 4: partial loop. +1 to interpolate between frames.
	/* 0x02 */ u8 dListCount;			      // Number of display lists in a flexible skeleton
	/* 0x03 */ s8 taper;				      // Tapering to use when morphing between animations. Only used by Door_Warp1.
	/* 0x04 */ void** skeleton;			      // An array of pointers to limbs. Can be StandardLimb, LodLimb, or SkinLimb.
	/* 0x08 */ void* animation;			      // Can be an AnimationHeader or LinkAnimationHeader.
	/* 0x0C */ f32 startFrame;			      // In mode 4, start of partial loop.
	/* 0x10 */ f32 endFrame;			      // In mode 2, Update returns true when curFrame is equal to this. In mode 4, end of partial loop.
	/* 0x14 */ f32 animLength;			      // Total number of frames in the current animation's file.
	/* 0x18 */ f32 curFrame;			      // Current frame in the animation
	/* 0x1C */ f32 playSpeed;			      // Multiplied by R_UPDATE_RATE / 3 to get the animation's frame rate.
	/* 0x20 */ Vec3s* jointTable;			      // Current translation of model and rotations of all limbs
	/* 0x24 */ Vec3s* morphTable;			      // Table of values used to morph between animations
	/* 0x28 */ f32 morphWeight;			      // Weight of the current animation morph as a fraction in [0,1]
	/* 0x2C */ f32 morphRate;			      // Reciprocal of the number of frames in the morph
	/* 0x30 */ s32 (*update)(GlobalContext*, SkelAnime*); // Can be Loop, Partial loop, Play once, Morph, or Tapered morph. Link only has Loop, Play once, and Morph
	/* 0x34 */ s8 initFlags;			      // Flags used when initializing Link's skeleton
	/* 0x35 */ u8 moveFlags;			      // Flags used for animations that move the actor in worldspace.
	/* 0x36 */ s16 prevRot;				      // Previous rotation in worldspace.
	/* 0x38 */ Vec3s prevTransl;			      // Previous modelspace translation.
	/* 0x3E */ Vec3s baseTransl;			      // Base modelspace translation.
};							      // size = 0x44

struct Struct_800A57C0
{
	/* 0x000 */ u16 unk_0;
	/* 0x002 */ s16 unk_2;
	/* 0x004 */ s16 unk_4;
	/* 0x006 */ s8 unk_6;
	/* 0x007 */ s8 unk_7;
	/* 0x008 */ s8 unk_8;
	/* 0x009 */ u8 unk_9;
}; // size = 0xA

struct Struct_800A598C_2
{
	/* 0x000 */ u8 unk_0;
	/* 0x002 */ s16 x;
	/* 0x004 */ s16 y;
	/* 0x006 */ s16 z;
	/* 0x008 */ u8 unk_8;
}; // size = 0xA

struct Struct_800A598C
{
	/* 0x000 */ u16 unk_0;
	/* 0x002 */ u16 unk_2;
	/* 0x004 */ u16 unk_4;
	/* 0x008 */ Struct_800A57C0* unk_8;
	/* 0x00C */ Struct_800A598C_2* unk_C;
}; // size = 0x10

struct Struct_800A5E28
{
	/* 0x000 */ u16 unk_0;
	/* 0x002 */ u16 unk_2;
	/* 0x004 */ Struct_800A598C* unk_4;
	/* 0x008 */ Gfx* unk_8;
}; // size = 0xC

struct SkinAvb
{
	/* 0x000 */ u8 unk_0;
	/* 0x004 */ Vtx* buf[2];
}; // size = 0xC

struct PSkinAwb
{
	/* 0x000 */ SkeletonHeader* skeletonHeader;
	/* 0x004 */ MtxF mtx;
	/* 0x044 */ s32 avbCount;
	/* 0x048 */ SkinAvb* avbTbl;
	/* 0x04C */ SkelAnime skelAnime;
}; // size = 0x90

typedef void (*SkinCallback)(struct Actor*, GlobalContext*, PSkinAwb*);
typedef s32 (*SkinCallback2)(struct Actor*, GlobalContext*, s32, PSkinAwb*);

#endif
