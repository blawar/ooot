#pragma once
struct GlobalContext;
struct Vec3f;
struct EnItem00;
struct Actor;

EnItem00* Item_DropCollectible(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
EnItem00* Item_DropCollectible2(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
void Item_DropCollectibleRandom(GlobalContext* globalCtx, Actor* fromActor, Vec3f* spawnPos, s16 params);
