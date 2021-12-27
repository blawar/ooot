#pragma once

extern EntranceInfo gEntranceTable[1556];
extern SceneTableEntry gSceneTable[SCENE_ID_MAX];

#ifdef INTERNAL_SRC_CODE_Z_SCENE_TABLE_C
void Scene_Draw(GlobalContext* globalCtx);
void func_800994A0(GlobalContext* globalCtx);
#else
void Scene_Draw(struct GlobalContext* globalCtx);
void func_800994A0(struct GlobalContext* globalCtx);
#endif
