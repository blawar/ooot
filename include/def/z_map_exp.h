#pragma once

//extern MapData* gMapData;

#ifdef INTERNAL_SRC_CODE_Z_MAP_EXP_C
void Map_Destroy(GlobalContext* globalCtx);
void Map_Init(GlobalContext* globalCtx);
void Map_InitData(GlobalContext* globalCtx, s16 room);
void Map_InitRoomData(GlobalContext* globalCtx, s16 room);
void Map_SavePlayerInitialInfo(GlobalContext* globalCtx);
void Map_SetFloorPalettesData(GlobalContext* globalCtx, s16 floor);
void Map_Update(GlobalContext* globalCtx);
void Minimap_Draw(GlobalContext* globalCtx);
#else
void Map_Destroy(struct GlobalContext* globalCtx);
void Map_Init(struct GlobalContext* globalCtx);
void Map_InitData(struct GlobalContext* globalCtx, s16 room);
void Map_InitRoomData(struct GlobalContext* globalCtx, s16 room);
void Map_SavePlayerInitialInfo(struct GlobalContext* globalCtx);
void Map_SetFloorPalettesData(struct GlobalContext* globalCtx, s16 floor);
void Map_Update(struct GlobalContext* globalCtx);
void Minimap_Draw(struct GlobalContext* globalCtx);
#endif
