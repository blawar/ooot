#pragma once

extern s16 gOcarinaSongItemMap[];

#ifdef INTERNAL_SRC_CODE_Z_MESSAGE_PAL_C
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
#else
void Message_CloseTextbox(struct GlobalContext*);
void Message_ContinueTextbox(struct GlobalContext* globalCtx, u16 textId);
void Message_Draw(struct GlobalContext* globalCtx);
u8 Message_GetState(struct MessageContext* msgCtx);
void Message_SetTables(void);
u8 Message_ShouldAdvance(struct GlobalContext* globalCtx);
void Message_StartTextbox(struct GlobalContext* globalCtx, u16 textId, struct Actor* actor);
void Message_Update(struct GlobalContext* globalCtx);
void Message_UpdateOcarinaGame(struct GlobalContext* globalCtx);
void func_8010BD58(struct GlobalContext* globalCtx, u16 arg1);
void func_8010BD88(struct GlobalContext* globalCtx, u16 arg1);
#endif
