#pragma once
#ifdef INTERNAL_SRC_CODE_Z_ROOM_C
void Room_Draw(GlobalContext* globalCtx, Room* room, u32 flags);
void func_80095AA0(GlobalContext* globalCtx, Room* room, Input* arg2, UNK_TYPE arg3);
void func_8009638C(Gfx** displayList, void* source, void* tlut, u16 width, u16 height, u8 fmt, u8 siz, u16 mode0, u16 tlutCount, f32 frameX, f32 frameY);
void func_80096FD4(GlobalContext* globalCtx, Room* room);
u32 func_80096FE8(GlobalContext* globalCtx, RoomContext* roomCtx);
s32 func_8009728C(GlobalContext* globalCtx, RoomContext* roomCtx, s32 roomNum);
s32 func_800973FC(GlobalContext* globalCtx, RoomContext* roomCtx);
void func_80097534(GlobalContext* globalCtx, RoomContext* roomCtx);
#else
void Room_Draw(struct GlobalContext* globalCtx, struct Room* room, u32 flags);
void func_80095AA0(struct GlobalContext* globalCtx, struct Room* room, struct Input* arg2, UNK_TYPE arg3);
void func_8009638C(Gfx** displayList, void* source, void* tlut, u16 width, u16 height, u8 fmt, u8 siz, u16 mode0, u16 tlutCount, f32 frameX, f32 frameY);
void func_80096FD4(struct GlobalContext* globalCtx, struct Room* room);
u32 func_80096FE8(struct GlobalContext* globalCtx, struct RoomContext* roomCtx);
s32 func_8009728C(struct GlobalContext* globalCtx, struct RoomContext* roomCtx, s32 roomNum);
s32 func_800973FC(struct GlobalContext* globalCtx, struct RoomContext* roomCtx);
void func_80097534(struct GlobalContext* globalCtx, struct RoomContext* roomCtx);
#endif
