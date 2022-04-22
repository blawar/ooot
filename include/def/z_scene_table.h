#pragma once
struct GlobalContext;
struct EntranceInfo;
struct SceneTableEntry;

extern EntranceInfo gEntranceTable[1556];
extern SceneTableEntry gSceneTable[SCENE_ID_MAX];

void Scene_Draw(GlobalContext* globalCtx);
void func_800994A0(GlobalContext* globalCtx);
