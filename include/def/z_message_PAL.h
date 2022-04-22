#pragma once
struct GlobalContext;
struct MessageContext;
struct Actor;

extern s16 gOcarinaSongItemMap[];

void Message_CloseTextbox(GlobalContext*);
void Message_ContinueTextbox(GlobalContext* globalCtx, u16 textId);
void Message_Draw(GlobalContext* globalCtx);
u8 Message_GetState(MessageContext* msgCtx);
void Message_SetTables(void);
u8 Message_ShouldAdvance(GlobalContext* globalCtx);
void Message_StartTextbox(GlobalContext* globalCtx, u16 textId, Actor* actor);
void Message_Update(GlobalContext* globalCtx);
void Message_UpdateOcarinaGame(GlobalContext* globalCtx);
void func_8010BD58(GlobalContext* globalCtx, u16 arg1);
void func_8010BD88(GlobalContext* globalCtx, u16 arg1);
