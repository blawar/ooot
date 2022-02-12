#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_ITEM_INBOX_Z_ITEM_INBOX_C
#include "actor_common.h"
/*
 * File: z_item_inbox.c
 * Overlay: ovl_Item_Inbox
 * Description: Zelda's magic effect when opening gates in castle collapse
 */

#include "z_item_inbox.h"
#include "def/z_actor.h"
#include "def/z_draw.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void ItemInbox_Init(Actor* thisx, GlobalContext* globalCtx);
void ItemInbox_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ItemInbox_Update(Actor* thisx, GlobalContext* globalCtx);
void ItemInbox_Draw(Actor* thisx, GlobalContext* globalCtx);

void ItemInbox_Wait(ItemInbox* pthis, GlobalContext* globalCtx);

ActorInit Item_Inbox_InitVars = {
    ACTOR_ITEM_INBOX,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ItemInbox),
    (ActorFunc)ItemInbox_Init,
    (ActorFunc)ItemInbox_Destroy,
    (ActorFunc)ItemInbox_Update,
    (ActorFunc)ItemInbox_Draw,
};

void ItemInbox_Init(Actor* thisx, GlobalContext* globalCtx) {
    ItemInbox* pthis = (ItemInbox*)thisx;

    pthis->actionFunc = ItemInbox_Wait;
    Actor_SetScale(&pthis->actor, 0.2);
}

void ItemInbox_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void ItemInbox_Wait(ItemInbox* pthis, GlobalContext* globalCtx) {
    if (Flags_GetTreasure(globalCtx, (pthis->actor.params >> 8) & 0x1F)) {
        Actor_Kill(&pthis->actor);
    }
}

void ItemInbox_Update(Actor* thisx, GlobalContext* globalCtx) {
    ItemInbox* pthis = (ItemInbox*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void ItemInbox_Draw(Actor* thisx, GlobalContext* globalCtx) {
    ItemInbox* pthis = (ItemInbox*)thisx;

    func_8002EBCC(&pthis->actor, globalCtx, 0);
    func_8002ED80(&pthis->actor, globalCtx, 0);
    GetItem_Draw(globalCtx, pthis->actor.params & 0xFF);
}
