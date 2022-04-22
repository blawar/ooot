#pragma once
struct Path;
struct Vec3f;
struct GlobalContext;
struct Actor;

void Path_CopyLastPoint(Path* path, Vec3f* dest);
Path* Path_GetByIndex(GlobalContext* globalCtx, s16 index, s16 max);
f32 Path_OrientAndGetDistSq(Actor* actor, Path* path, s16 waypoint, s16* yaw);
