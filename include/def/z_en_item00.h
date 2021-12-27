#pragma once
#ifdef INTERNAL_SRC_CODE_Z_EN_ITEM00_C
EnItem00* Item_DropCollectible(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
EnItem00* Item_DropCollectible2(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
void Item_DropCollectibleRandom(GlobalContext* globalCtx, Actor* fromActor, Vec3f* spawnPos, s16 params);
#else
struct EnItem00* Item_DropCollectible(struct GlobalContext* globalCtx, struct Vec3f* spawnPos, s16 params);
struct EnItem00* Item_DropCollectible2(struct GlobalContext* globalCtx, struct Vec3f* spawnPos, s16 params);
void Item_DropCollectibleRandom(struct GlobalContext* globalCtx, struct Actor* fromActor, struct Vec3f* spawnPos, s16 params);
#endif
