#pragma once
struct GlobalContext;
struct MapData;

extern MapData* gMapData;

void Map_Destroy(GlobalContext* globalCtx);
void Map_Init(GlobalContext* globalCtx);
void Map_InitData(GlobalContext* globalCtx, s16 room);
void Map_InitRoomData(GlobalContext* globalCtx, s16 room);
void Map_SavePlayerInitialInfo(GlobalContext* globalCtx);
void Map_SetFloorPalettesData(GlobalContext* globalCtx, s16 floor);
void Map_Update(GlobalContext* globalCtx);
void Minimap_Draw(GlobalContext* globalCtx);
