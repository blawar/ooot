#pragma once
struct ObjectContext;
struct GlobalContext;
struct GameState;
struct TransitionActorContext;
struct RomFile;

extern s16 gLinkObjectIds[2];
extern RomFile gObjectTable[OBJECT_ID_MAX];
extern u32 gObjectTableSize;

s32 Object_GetIndex(ObjectContext* objectCtx, s32 objectId);
void Object_InitBank(GlobalContext* globalCtx, ObjectContext* objectCtx);
s32 Object_IsLoaded(ObjectContext* objectCtx, s32 bankIndex);
void Object_UpdateBank(ObjectContext* objectCtx);
s32 Scene_ExecuteCommands(GlobalContext* globalCtx, SceneCmd* sceneCmd);
void TransitionActor_InitContext(GameState* state, TransitionActorContext* transiActorCtx);
void func_800981B8(ObjectContext* objectCtx);
