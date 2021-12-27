#pragma once

extern s16 gLinkObjectIds[2];
extern RomFile gObjectTable[OBJECT_ID_MAX];
extern u32 gObjectTableSize;

#ifdef INTERNAL_SRC_CODE_Z_SCENE_C
s32 Object_GetIndex(ObjectContext* objectCtx, s32 objectId);
void Object_InitBank(GlobalContext* globalCtx, ObjectContext* objectCtx);
s32 Object_IsLoaded(ObjectContext* objectCtx, s32 bankIndex);
void Object_UpdateBank(ObjectContext* objectCtx);
s32 Scene_ExecuteCommands(GlobalContext* globalCtx, SceneCmd* sceneCmd);
void TransitionActor_InitContext(GameState* state, TransitionActorContext* transiActorCtx);
void func_800981B8(ObjectContext* objectCtx);
#else
s32 Object_GetIndex(struct ObjectContext* objectCtx, s32 objectId);
void Object_InitBank(struct GlobalContext* globalCtx, struct ObjectContext* objectCtx);
s32 Object_IsLoaded(struct ObjectContext* objectCtx, s32 bankIndex);
void Object_UpdateBank(struct ObjectContext* objectCtx);
s32 Scene_ExecuteCommands(struct GlobalContext* globalCtx, SceneCmd* sceneCmd);
void TransitionActor_InitContext(struct GameState* state, struct TransitionActorContext* transiActorCtx);
void func_800981B8(struct ObjectContext* objectCtx);
#endif
