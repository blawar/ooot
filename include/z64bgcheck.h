#pragma once
#include "z64math.h"

struct GlobalContext;
struct Actor;
struct DynaPolyActor;

#define COLPOLY_NORMAL_FRAC (1.0f / SHT_MAX)
#define COLPOLY_SNORMAL(x) ((s16)((x) * SHT_MAX))
#define COLPOLY_GET_NORMAL(n) ((n)*COLPOLY_NORMAL_FRAC)
#define COLPOLY_VIA_FLAG_TEST(vIA, flags) ((vIA) & (((flags)&7) << 13))
#define COLPOLY_VTX_INDEX(vI) ((vI)&0x1FFF)

#define DYNAPOLY_INVALIDATE_LOOKUP (1 << 0)

#define BGACTOR_NEG_ONE -1
#define BG_ACTOR_MAX 50
#define BGCHECK_SCENE BG_ACTOR_MAX
#define BGCHECK_Y_MIN -32000.0f
#define BGCHECK_XYZ_ABSMAX 32760.0f
#define BGCHECK_SUBDIV_OVERLAP 50
#define BGCHECK_SUBDIV_MIN 150.0f

#define FUNC_80041EA4_RESPAWN 5
#define FUNC_80041EA4_MOUNT_WALL 6
#define FUNC_80041EA4_STOP 8
#define FUNC_80041EA4_VOID_OUT 12

#define WATERBOX_ROOM(p) ((p >> 13) & 0x3F)

struct ScaleRotPos {
    Vec3f scale;
    Vec3s rot;
    Vec3f pos;
};

struct CollisionPoly
{
    /* 0x00 */ u16 type;
    union {
        u16 vtxData[3];
        struct {
            /* 0x02 */ u16 flags_vIA; // 0xE000 is poly exclusion flags (xpFlags), 0x1FFF is vtxId
            /* 0x04 */ u16 flags_vIB; // 0xE000 is flags, 0x1FFF is vtxId
                                      // 0x2000 = poly IsConveyor surface
            /* 0x06 */ u16 vIC;
        };
    };
    /* 0x08 */ Vec3s normal; // Unit normal vector
                             // Value ranges from -0x7FFF to 0x7FFF, representing -1.0 to 1.0; 0x8000 is invalid

    /* 0x0E */ s16 dist; // Plane distance from origin along the normal
}; // size = 0x10

struct CamData {
    /* 0x00 */ u16 cameraSType;
    /* 0x02 */ s16 numCameras;
    /* 0x04 */ Vec3s* camPosData;
};

struct WaterBox {
    /* 0x00 */ s16 xMin;
    /* 0x02 */ s16 ySurface;
    /* 0x04 */ s16 zMin;
    /* 0x06 */ s16 xLength;
    /* 0x08 */ s16 zLength;
    /* 0x0C */ u32 properties;

    // 0x0008_0000 = ?
    // 0x0007_E000 = Room Index, 0x3F = all rooms
    // 0x0000_1F00 = Lighting Settings Index
    // 0x0000_00FF = CamData index
}; // size = 0x10

struct SurfaceType {
    u32 data[2];

    // Type 1
    // 0x0800_0000 = wall damage
};

struct CollisionHeader {
    /* 0x00 */ Vec3s minBounds; // minimum coordinates of poly bounding box
    /* 0x06 */ Vec3s maxBounds; // maximum coordinates of poly bounding box
    /* 0x0C */ u16 numVertices;
    /* 0x10 */ Vec3s* vtxList;
    /* 0x14 */ u16 numPolygons;
    /* 0x18 */ CollisionPoly* polyList;
    /* 0x1C */ SurfaceType* surfaceTypeList;
    /* 0x20 */ CamData* cameraDataList;
    /* 0x24 */ u16 numWaterBoxes;
    /* 0x28 */ WaterBox* waterBoxes;
}; // original name: BGDataInfo

struct SSNode {
    s16 polyId;
    u16 next; // next SSNode index
};

struct SSList {
    u16 head; // first SSNode index
};

struct SSNodeList {
    /* 0x00 */ u16 max;          // original name: short_slist_node_size
    /* 0x02 */ u16 count;        // original name: short_slist_node_last_index
    /* 0x04 */ SSNode* tbl;      // original name: short_slist_node_tbl
    /* 0x08 */ u8* polyCheckTbl; // points to an array of bytes, one per static poly. Zero initialized when starting a
                                 // bg check, and set to 1 if that poly has already been tested.
};

struct DynaSSNodeList {
    SSNode* tbl;
    s32 count;
    s32 max;
};

struct StaticLookup {
    SSList floor;
    SSList wall;
    SSList ceiling;
};

struct DynaLookup {
    u16 polyStartIndex;
    SSList ceiling;
    SSList wall;
    SSList floor;
};

struct BgActor {
    /* 0x00 */ struct Actor* actor;
    /* 0x04 */ CollisionHeader* colHeader;
    /* 0x08 */ DynaLookup dynaLookup;
    /* 0x10 */ u16 vtxStartIndex;
    /* 0x14 */ ScaleRotPos prevTransform;
    /* 0x34 */ ScaleRotPos curTransform;
    /* 0x54 */ Sphere16 boundingSphere;
    /* 0x5C */ f32 minY;
    /* 0x60 */ f32 maxY;
}; // size = 0x64

struct DynaCollisionContext {
    /* 0x0000 */ u8 bitFlag;
    /* 0x0004 */ BgActor bgActors[BG_ACTOR_MAX];
    /* 0x138C */ u16 bgActorFlags[BG_ACTOR_MAX]; // & 0x0008 = no dyna ceiling
    /* 0x13F0 */ CollisionPoly* polyList;
    /* 0x13F4 */ Vec3s* vtxList;
    /* 0x13F8 */ DynaSSNodeList polyNodes;
    /* 0x1404 */ s32 polyNodesMax;
    /* 0x1408 */ s32 polyListMax;
    /* 0x140C */ s32 vtxListMax;
}; // size = 0x1410

struct CollisionContext {
    /* 0x00 */ CollisionHeader* colHeader; // scene's static collision
    /* 0x04 */ Vec3f minBounds;            // minimum coordinates of collision bounding box
    /* 0x10 */ Vec3f maxBounds;            // maximum coordinates of collision bounding box
    /* 0x1C */ Vec3i subdivAmount;         // x, y, z subdivisions of the scene's static collision
    /* 0x28 */ Vec3f subdivLength;         // x, y, z subdivision worldspace lengths
    /* 0x34 */ Vec3f subdivLengthInv;      // inverse of subdivision length
    /* 0x40 */ StaticLookup* lookupTbl;    // 3d array of length subdivAmount
    /* 0x44 */ SSNodeList polyNodes;
    /* 0x50 */ DynaCollisionContext dyna;
    /* 0x1460 */ u32 memSize; // Size of all allocated memory plus CollisionContext
}; // size = 0x1464

struct DynaRaycast {
    /* 0x00 */ struct GlobalContext* globalCtx;
    /* 0x04 */ struct CollisionContext* colCtx;
    /* 0x08 */ u16 xpFlags;
    /* 0x0C */ CollisionPoly** resultPoly;
    /* 0x10 */ f32 yIntersect;
    /* 0x14 */ Vec3f* pos;
    /* 0x18 */ s32* bgId;
    /* 0x1C */ struct Actor* actor;
    /* 0x20 */ u32 unk_20;
    /* 0x24 */ f32 chkDist;
    /* 0x28 */ DynaCollisionContext* dyna;
    /* 0x2C */ SSList* ssList;
};

struct DynaLineTest {
    /* 0x00 */ struct CollisionContext* colCtx;
    /* 0x04 */ u16 xpFlags;
    /* 0x08 */ DynaCollisionContext* dyna;
    /* 0x0C */ SSList* ssList;
    /* 0x10 */ Vec3f* posA;
    /* 0x14 */ Vec3f* posB;
    /* 0x18 */ Vec3f* posResult;
    /* 0x1C */ CollisionPoly** resultPoly;
    /* 0x20 */ s32 chkOneFace; // bccFlags & 0x8
    /* 0x24 */ f32* distSq;    // distance from posA to poly squared
    /* 0x28 */ f32 chkDist;    // distance from poly
};

/*
struct DynaSSNodeList;

u16 DynaSSNodeList_GetNextNodeIdx(DynaSSNodeList*);
void func_80038A28(CollisionPoly* poly, f32 tx, f32 ty, f32 tz, MtxF* dest);
f32 CollisionPoly_GetPointDistanceFromPlane(CollisionPoly* poly, Vec3f* point);
void CollisionPoly_GetVerticesByBgId(CollisionPoly* poly, s32 bgId, CollisionContext* colCtx, Vec3f* dest);
s32 BgCheck_CheckStaticCeiling(StaticLookup* lookup, u16 xpFlags, CollisionContext* colCtx, f32* outY, Vec3f* pos,
                               f32 checkHeight, CollisionPoly** outPoly);
s32 BgCheck_CheckLineAgainstSSList(SSList* headNodeId, CollisionContext* colCtx, u16 xpFlags1, u16 xpFlags2,
                                   Vec3f* posA, Vec3f* posB, Vec3f* outPos, CollisionPoly** outPoly, f32* outDistSq,
                                   f32 chkDist, s32 bccFlags);
void BgCheck_GetStaticLookupIndicesFromPos(CollisionContext* colCtx, Vec3f* pos, Vec3i* arg2);
void BgCheck_Allocate(CollisionContext* colCtx, struct GlobalContext* globalCtx, CollisionHeader* colHeader);
s32 BgCheck_PosInStaticBoundingBox(CollisionContext* colCtx, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor1(CollisionContext* colCtx, CollisionPoly** outPoly, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor2(struct GlobalContext* globalCtx, CollisionContext* colCtx, CollisionPoly** outPoly,
                                Vec3f* pos);
f32 BgCheck_EntityRaycastFloor3(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor4(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, struct Actor* actor,
                                Vec3f* arg4);
f32 BgCheck_EntityRaycastFloor5(struct GlobalContext* globalCtx, CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId,
                                struct Actor* actor, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor6(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, struct Actor* actor, Vec3f* pos,
                                f32 chkDist);
f32 BgCheck_EntityRaycastFloor7(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, struct Actor* actor, Vec3f* pos);
f32 BgCheck_AnyRaycastFloor1(CollisionContext* colCtx, CollisionPoly* outPoly, Vec3f* pos);
f32 BgCheck_AnyRaycastFloor2(CollisionContext* colCtx, CollisionPoly* outPoly, s32* bgId, Vec3f* pos);
f32 BgCheck_CameraRaycastFloor2(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor8(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, struct Actor* actor, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor9(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Vec3f* pos);
s32 BgCheck_CheckWallImpl(CollisionContext* colCtx, u16 xpFlags, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev,
                          f32 radius, CollisionPoly** outPoly, s32* outBgId, struct Actor* actor, f32 checkHeight, u8 argA);
s32 BgCheck_EntitySphVsWall1(CollisionContext* colCtx, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev, f32 radius,
                             CollisionPoly** outPoly, f32 checkHeight);
s32 BgCheck_EntitySphVsWall2(CollisionContext* colCtx, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev, f32 radius,
                             CollisionPoly** outPoly, s32* outBgId, f32 checkHeight);
s32 BgCheck_EntitySphVsWall3(CollisionContext* colCtx, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev, f32 radius,
                             CollisionPoly** outPoly, s32* outBgId, struct Actor* actor, f32 checkHeight);
s32 BgCheck_EntitySphVsWall4(CollisionContext* colCtx, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev, f32 radius,
                             CollisionPoly** outPoly, s32* outBgId, struct Actor* actor, f32 checkHeight);
s32 BgCheck_AnyCheckCeiling(CollisionContext* colCtx, f32* outY, Vec3f* pos, f32 checkHeight);
s32 BgCheck_EntityCheckCeiling(CollisionContext* colCtx, f32* arg1, Vec3f* arg2, f32 arg3, CollisionPoly** outPoly,
                               s32* outBgId, struct Actor* actor);
s32 BgCheck_CheckLineImpl(CollisionContext* colCtx, u16 xpFlags1, u16 xpFlags2, Vec3f* posA, Vec3f* posB,
                          Vec3f* posResult, CollisionPoly** outPoly, s32* bgId, struct Actor* actor, f32 chkDist,
                          u32 bccFlags);
s32 BgCheck_CameraLineTest1(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId);
s32 BgCheck_CameraLineTest2(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId);
s32 BgCheck_EntityLineTest1(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId);
s32 BgCheck_EntityLineTest2(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId,
                            struct Actor* actor);
s32 BgCheck_EntityLineTest3(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId,
                            struct Actor* actor, f32 chkDist);
s32 BgCheck_ProjectileLineTest(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                               CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace,
                               s32* bgId);
s32 BgCheck_AnyLineTest1(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult, CollisionPoly** outPoly,
                         s32 chkOneFace);
s32 BgCheck_AnyLineTest2(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult, CollisionPoly** outPoly,
                         s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace);
s32 BgCheck_AnyLineTest3(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult, CollisionPoly** outPoly,
                         s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId);
s32 BgCheck_SphVsFirstPoly(CollisionContext* colCtx, Vec3f* center, f32 radius);
void SSNodeList_Initialize(SSNodeList*);
void SSNodeList_Alloc(struct GlobalContext* globalCtx, SSNodeList* thiss, s32 tblMax, s32 numPolys);
u16 SSNodeList_GetNextNodeIdx(SSNodeList* thiss);
s32 DynaPoly_IsBgIdBgActor(s32 bgId);
void DynaPoly_Init(struct GlobalContext* globalCtx, DynaCollisionContext* dyna);
void DynaPoly_Alloc(struct GlobalContext* globalCtx, DynaCollisionContext* dyna);
void func_8003EBF8(struct GlobalContext* globalCtx, DynaCollisionContext* dyna, s32 bgId);
void func_8003EC50(struct GlobalContext* globalCtx, DynaCollisionContext* dyna, s32 bgId);
void func_8003ECA8(struct GlobalContext* globalCtx, DynaCollisionContext* dyna, s32 bgId);
s32 DynaPoly_SetBgActor(struct GlobalContext* globalCtx, DynaCollisionContext* dyna, struct Actor* actor, CollisionHeader* colHeader);
struct DynaPolyActor* DynaPoly_GetActor(CollisionContext* colCtx, s32 bgId);
void DynaPoly_DeleteBgActor(struct GlobalContext* globalCtx, DynaCollisionContext* dyna, s32 bgId);
void func_8003EE6C(struct GlobalContext* globalCtx, DynaCollisionContext* dyna);
void func_8003F8EC(struct GlobalContext* globalCtx, DynaCollisionContext* dyna, struct Actor* actor);
void DynaPoly_Setup(struct GlobalContext* globalCtx, DynaCollisionContext* dyna);
void DynaPoly_UpdateBgActorTransforms(struct GlobalContext* globalCtx, DynaCollisionContext* dyna);
f32 BgCheck_RaycastFloorDyna(DynaRaycast* dynaRaycast);
s32 BgCheck_SphVsDynaWall(CollisionContext* colCtx, u16 xpFlags, f32* outX, f32* outZ, Vec3f* pos, f32 radius,
                          CollisionPoly** outPoly, s32* outBgId, struct Actor* actor);
s32 BgCheck_CheckDynaCeiling(CollisionContext* colCtx, u16 xpFlags, f32* outY, Vec3f* pos, f32 chkDist,
                             CollisionPoly** outPoly, s32* outBgId, struct Actor* actor);
s32 BgCheck_CheckLineAgainstDyna(CollisionContext* colCtx, u16 xpFlags, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                                 CollisionPoly** outPoly, f32* distSq, s32* outBgId, struct Actor* actor, f32 chkDist,
                                 s32 bccFlags);
s32 BgCheck_SphVsFirstDynaPoly(CollisionContext* colCtx, u16 xpFlags, CollisionPoly** outPoly, s32* outBgId,
                               Vec3f* center, f32 radius, struct Actor* actor, u16 bciFlags);
void CollisionHeader_GetVirtual(void* colHeader, CollisionHeader** dest);
void func_800418D0(CollisionContext* colCtx, struct GlobalContext* globalCtx);
void BgCheck_ResetPolyCheckTbl(SSNodeList* nodeList, s32 numPolys);
u32 SurfaceType_GetCamDataIndex(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u16 func_80041A4C(CollisionContext* colCtx, u32 camId, s32 bgId);
u16 SurfaceType_GetCameraSType(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u16 SurfaceType_GetNumCameras(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
Vec3s* func_80041C10(CollisionContext* colCtx, s32 camId, s32 bgId);
Vec3s* SurfaceType_GetCamPosData(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetSceneExitIndex(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041D4C(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041D70(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 func_80041DB8(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 func_80041DE4(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 func_80041E18(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 func_80041E4C(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041EA4(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041EC8(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_IsHorseBlocked(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041F10(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u16 SurfaceType_GetSfx(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetSlope(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetLightSettingIndex(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetEcho(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_IsHookshotSurface(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 SurfaceType_IsIgnoredByEntities(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 SurfaceType_IsIgnoredByProjectiles(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 SurfaceType_IsConveyor(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetConveyorSpeed(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetConveyorDirection(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_IsWallDamage(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 WaterBox_GetSurface1(struct GlobalContext* globalCtx, CollisionContext* colCtx, f32 x, f32 z, f32* ySurface,
                         WaterBox** outWaterBox);
s32 WaterBox_GetSurface2(struct GlobalContext* globalCtx, CollisionContext* colCtx, Vec3f* pos, f32 surfaceChkDist,
                         WaterBox** outWaterBox);
s32 WaterBox_GetSurfaceImpl(struct GlobalContext* globalCtx, CollisionContext* colCtx, f32 x, f32 z, f32* ySurface,
                            WaterBox** outWaterBox);
u32 WaterBox_GetCamDataIndex(CollisionContext* colCtx, WaterBox* waterBox);
u16 WaterBox_GetCameraSType(CollisionContext* colCtx, WaterBox* waterBox);
u32 WaterBox_GetLightSettingIndex(CollisionContext* colCtx, WaterBox* waterBox);
s32 func_80042708(CollisionPoly* polyA, CollisionPoly* polyB, Vec3f* point, Vec3f* closestPoint);
s32 func_800427B4(CollisionPoly* polyA, CollisionPoly* polyB, Vec3f* pointA, Vec3f* pointB, Vec3f* closestPoint);
void BgCheck_DrawDynaCollision(struct GlobalContext*, CollisionContext*);
void BgCheck_DrawStaticCollision(struct GlobalContext*, CollisionContext*);
*/

