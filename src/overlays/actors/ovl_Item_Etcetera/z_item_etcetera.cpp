#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_ITEM_ETCETERA_Z_ITEM_ETCETERA_C
#include "actor_common.h"
/*
 * File: z_item_etcetera.c
 * Overlay: ovl_Item_Etcetera
 * Description: Collectible Items
 */

#include "z_item_etcetera.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_draw.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_scene.h"

#define FLAGS ACTOR_FLAG_4

void ItemEtcetera_Init(Actor* thisx, GlobalContext* globalCtx);
void ItemEtcetera_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ItemEtcetera_Update(Actor* thisx, GlobalContext* globalCtx);
void ItemEtcetera_DrawThroughLens(Actor* thisx, GlobalContext* globalCtx);
void ItemEtcetera_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B857D0(ItemEtcetera* pthis, GlobalContext* globalCtx);
void func_80B85824(ItemEtcetera* pthis, GlobalContext* globalCtx);
void func_80B858B4(ItemEtcetera* pthis, GlobalContext* globalCtx);
void ItemEtcetera_SpawnSparkles(ItemEtcetera* pthis, GlobalContext* globalCtx);
void ItemEtcetera_MoveFireArrowDown(ItemEtcetera* pthis, GlobalContext* globalCtx);
void func_80B85B28(ItemEtcetera* pthis, GlobalContext* globalCtx);
void ItemEtcetera_UpdateFireArrow(ItemEtcetera* pthis, GlobalContext* globalCtx);

ActorInit Item_Etcetera_InitVars = {
    ACTOR_ITEM_ETCETERA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ItemEtcetera),
    (ActorFunc)ItemEtcetera_Init,
    (ActorFunc)ItemEtcetera_Destroy,
    (ActorFunc)ItemEtcetera_Update,
    NULL,
};

static s16 sObjectIds[] = {
    OBJECT_GI_BOTTLE, OBJECT_GI_BOTTLE_LETTER, OBJECT_GI_SHIELD_2, OBJECT_GI_ARROWCASE, OBJECT_GI_SCALE,
    OBJECT_GI_SCALE,  OBJECT_GI_KEY,           OBJECT_GI_M_ARROW,  OBJECT_GI_RUPY,      OBJECT_GI_RUPY,
    OBJECT_GI_RUPY,   OBJECT_GI_RUPY,          OBJECT_GI_HEARTS,   OBJECT_GI_KEY,
};

// Indexes passed to the item table in z_draw.c
static s16 sDrawItemIndexes[] = {
    GID_BOTTLE,       GID_LETTER_RUTO,  GID_SHIELD_HYLIAN, GID_QUIVER_40,   GID_SCALE_SILVER,
    GID_SCALE_GOLDEN, GID_KEY_SMALL,    GID_ARROW_FIRE,    GID_RUPEE_GREEN, GID_RUPEE_BLUE,
    GID_RUPEE_RED,    GID_RUPEE_PURPLE, GID_HEART_PIECE,   GID_KEY_SMALL,
};

static s16 sGetItemIds[] = {
    GI_BOTTLE,     GI_LETTER_RUTO, GI_SHIELD_HYLIAN, GI_QUIVER_40, GI_SCALE_SILVER, GI_SCALE_GOLD, GI_KEY_SMALL,
    GI_ARROW_FIRE, GI_NONE,        GI_NONE,          GI_NONE,      GI_NONE,         GI_NONE,       GI_NONE,
};

void ItemEtcetera_SetupAction(ItemEtcetera* pthis, ItemEtceteraActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void ItemEtcetera_Init(Actor* thisx, GlobalContext* globalCtx) {
    ItemEtcetera* pthis = (ItemEtcetera*)thisx;
    s32 pad;
    s32 type;
    s32 objBankIndex;

    type = pthis->actor.params & 0xFF;
    osSyncPrintf("no = %d\n", type);
    objBankIndex = Object_GetIndex(&globalCtx->objectCtx, sObjectIds[type]);
    osSyncPrintf("bank_ID = %d\n", objBankIndex);
    if (objBankIndex < 0) {
        ASSERT(0, "0", "../z_item_etcetera.c", 241);
    } else {
        pthis->objBankIndex = objBankIndex;
    }
    pthis->giDrawId = sDrawItemIndexes[type];
    pthis->getItemId = sGetItemIds[type];
    pthis->futureActionFunc = func_80B85824;
    pthis->drawFunc = ItemEtcetera_Draw;
    Actor_SetScale(&pthis->actor, 0.25f);
    ItemEtcetera_SetupAction(pthis, func_80B857D0);
    switch (type) {
        case ITEM_ETC_LETTER:
            Actor_SetScale(&pthis->actor, 0.5f);
            pthis->futureActionFunc = func_80B858B4;
            if (gSaveContext.eventChkInf[3] & 2) {
                Actor_Kill(&pthis->actor);
            }
            break;
        case ITEM_ETC_ARROW_FIRE:
            pthis->futureActionFunc = ItemEtcetera_UpdateFireArrow;
            Actor_SetScale(&pthis->actor, 0.5f);
            pthis->actor.draw = NULL;
            pthis->actor.shape.yOffset = 50.0f;
            break;
        case ITEM_ETC_RUPEE_GREEN_CHEST_GAME:
        case ITEM_ETC_RUPEE_BLUE_CHEST_GAME:
        case ITEM_ETC_RUPEE_RED_CHEST_GAME:
        case ITEM_ETC_RUPEE_PURPLE_CHEST_GAME:
        case ITEM_ETC_HEART_PIECE_CHEST_GAME:
        case ITEM_ETC_KEY_SMALL_CHEST_GAME:
            Actor_SetScale(&pthis->actor, 0.5f);
            pthis->futureActionFunc = func_80B85B28;
            pthis->drawFunc = ItemEtcetera_DrawThroughLens;
            pthis->actor.world.pos.y += 15.0f;
            break;
    }
}

void ItemEtcetera_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void func_80B857D0(ItemEtcetera* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex)) {
        pthis->actor.objBankIndex = pthis->objBankIndex;
        pthis->actor.draw = pthis->drawFunc;
        pthis->actionFunc = pthis->futureActionFunc;
    }
}

void func_80B85824(ItemEtcetera* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        if ((pthis->actor.params & 0xFF) == 1) {
            gSaveContext.eventChkInf[3] |= 2;
            Flags_SetSwitch(globalCtx, 0xB);
        }
        Actor_Kill(&pthis->actor);
    } else {
        func_8002F434(&pthis->actor, globalCtx, pthis->getItemId, 30.0f, 50.0f);
    }
}

void func_80B858B4(ItemEtcetera* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        if ((pthis->actor.params & 0xFF) == 1) {
            gSaveContext.eventChkInf[3] |= 2;
            Flags_SetSwitch(globalCtx, 0xB);
        }
        Actor_Kill(&pthis->actor);
    } else {
        if (0) {} // Necessary to match
        func_8002F434(&pthis->actor, globalCtx, pthis->getItemId, 30.0f, 50.0f);
        if ((globalCtx->gameplayFrames & 0xD) == 0) {
            EffectSsBubble_Spawn(globalCtx, &pthis->actor.world.pos, 0.0f, 0.0f, 10.0f, 0.13f);
        }
    }
}

void ItemEtcetera_SpawnSparkles(ItemEtcetera* pthis, GlobalContext* globalCtx) {
    static Vec3f velocity = { 0.0f, 0.2f, 0.0f };
    static Vec3f accel = { 0.0f, 0.05f, 0.0f };
    static Color_RGBA8 primColor = { 255, 255, 255, 0 };
    static Color_RGBA8 envColor = { 255, 50, 50, 0 };
    Vec3f pos;

    velocity.x = Rand_CenteredFloat(3.0f);
    velocity.z = Rand_CenteredFloat(3.0f);
    velocity.y = -0.05f;
    accel.y = -0.025f;
    pos.x = Rand_CenteredFloat(12.0f) + pthis->actor.world.pos.x;
    pos.y = (Rand_ZeroOne() * 6.0f) + pthis->actor.world.pos.y;
    pos.z = Rand_CenteredFloat(12.0f) + pthis->actor.world.pos.z;
    EffectSsKiraKira_SpawnDispersed(globalCtx, &pos, &velocity, &accel, &primColor, &envColor, 5000, 16);
}

void ItemEtcetera_MoveFireArrowDown(ItemEtcetera* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 0.0f, 5);
    Actor_MoveForward(&pthis->actor);
    if (!(pthis->actor.bgCheckFlags & 1)) {
        ItemEtcetera_SpawnSparkles(pthis, globalCtx);
    }
    pthis->actor.shape.rot.y += 0x400;
    func_80B85824(pthis, globalCtx);
}

void func_80B85B28(ItemEtcetera* pthis, GlobalContext* globalCtx) {
    if (Flags_GetTreasure(globalCtx, (pthis->actor.params >> 8) & 0x1F)) {
        Actor_Kill(&pthis->actor);
    }
}

void ItemEtcetera_UpdateFireArrow(ItemEtcetera* pthis, GlobalContext* globalCtx) {
    if ((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[0] != NULL)) {
        LOG_NUM("(game_play->demo_play.npcdemopnt[0]->dousa)", globalCtx->csCtx.npcActions[0]->action,
                "../z_item_etcetera.c", 441);
        if (globalCtx->csCtx.npcActions[0]->action == 2) {
            pthis->actor.draw = ItemEtcetera_Draw;
            pthis->actor.gravity = -0.1f;
            pthis->actor.minVelocityY = -4.0f;
            pthis->actionFunc = ItemEtcetera_MoveFireArrowDown;
        }
    } else {
        pthis->actor.gravity = -0.1f;
        pthis->actor.minVelocityY = -4.0f;
        pthis->actionFunc = ItemEtcetera_MoveFireArrowDown;
    }
}

void ItemEtcetera_Update(Actor* thisx, GlobalContext* globalCtx) {
    ItemEtcetera* pthis = (ItemEtcetera*)thisx;
    pthis->actionFunc(pthis, globalCtx);
}

void ItemEtcetera_DrawThroughLens(Actor* thisx, GlobalContext* globalCtx) {
    ItemEtcetera* pthis = (ItemEtcetera*)thisx;
    if (globalCtx->actorCtx.unk_03 != 0) {
        func_8002EBCC(&pthis->actor, globalCtx, 0);
        func_8002ED80(&pthis->actor, globalCtx, 0);
        GetItem_Draw(globalCtx, pthis->giDrawId);
    }
}

void ItemEtcetera_Draw(Actor* thisx, GlobalContext* globalCtx) {
    ItemEtcetera* pthis = (ItemEtcetera*)thisx;

    func_8002EBCC(&pthis->actor, globalCtx, 0);
    func_8002ED80(&pthis->actor, globalCtx, 0);
    GetItem_Draw(globalCtx, pthis->giDrawId);
}
