#pragma once
#ifdef INTERNAL_SRC_CODE_Z_PATH_C
void Path_CopyLastPoint(Path* path, Vec3f* dest);
Path* Path_GetByIndex(GlobalContext* globalCtx, s16 index, s16 max);
f32 Path_OrientAndGetDistSq(Actor* actor, Path* path, s16 waypoint, s16* yaw);
#else
void Path_CopyLastPoint(struct Path* path, struct Vec3f* dest);
struct Path* Path_GetByIndex(struct GlobalContext* globalCtx, s16 index, s16 max);
f32 Path_OrientAndGetDistSq(struct Actor* actor, struct Path* path, s16 waypoint, s16* yaw);
#endif
