#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_WONDER_ITEM_Z_EN_WONDER_ITEM_C
#include "actor_common.h"
/*
 * File: z_en_wonder_item.c
 * Overlay: ovl_En_Wonder_Item
 * Description: Invisible Collectable; Used in MQ to create "Cow" switches
 */

#include "z_en_wonder_item.h"
#include "vt.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"

#define FLAGS 0

void EnWonderItem_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWonderItem_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWonderItem_Update(Actor* thisx, GlobalContext* globalCtx);

void EnWonderItem_MultitagFree(EnWonderItem* pthis, GlobalContext* globalCtx);
void EnWonderItem_ProximityDrop(EnWonderItem* pthis, GlobalContext* globalCtx);
void EnWonderItem_InteractSwitch(EnWonderItem* pthis, GlobalContext* globalCtx);
void EnWonderItem_ProximitySwitch(EnWonderItem* pthis, GlobalContext* globalCtx);
void EnWonderItem_MultitagOrdered(EnWonderItem* pthis, GlobalContext* globalCtx);
void EnWonderItem_BombSoldier(EnWonderItem* pthis, GlobalContext* globalCtx);
void EnWonderItem_RollDrop(EnWonderItem* pthis, GlobalContext* globalCtx);

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 20, 30, 0, { 0, 0, 0 } },
};

ActorInit En_Wonder_Item_InitVars = {
    ACTOR_EN_WONDER_ITEM,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnWonderItem),
    (ActorFunc)EnWonderItem_Init,
    (ActorFunc)EnWonderItem_Destroy,
    (ActorFunc)EnWonderItem_Update,
    NULL,
};

static Vec3f sTagPointsFree[9];
static Vec3f sTagPointsOrdered[9];

void EnWonderItem_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnWonderItem* pthis = (EnWonderItem*)thisx;

    if ((pthis->collider.dim.radius != 0) || (pthis->collider.dim.height != 0)) {
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
}

void EnWonderItem_DropCollectible(EnWonderItem* pthis, GlobalContext* globalCtx, s32 autoCollect) {
    static s16 dropTable[] = {
        ITEM00_NUTS,        ITEM00_HEART_PIECE,  ITEM00_MAGIC_LARGE,   ITEM00_MAGIC_SMALL,
        ITEM00_HEART,       ITEM00_ARROWS_SMALL, ITEM00_ARROWS_MEDIUM, ITEM00_ARROWS_LARGE,
        ITEM00_RUPEE_GREEN, ITEM00_RUPEE_BLUE,   ITEM00_RUPEE_RED,     ITEM00_FLEXIBLE,
    };
    s32 i;
    s32 randomDrop;

    func_80078884(NA_SE_SY_GET_ITEM);

    if (pthis->dropCount == 0) {
        pthis->dropCount++;
    }
    for (i = pthis->dropCount; i > 0; i--) {
        if (pthis->itemDrop < WONDERITEM_DROP_RANDOM) {
            if ((pthis->itemDrop == WONDERITEM_DROP_FLEXIBLE) || !autoCollect) {
                Item_DropCollectible(globalCtx, &pthis->actor.world.pos, dropTable[pthis->itemDrop]);
            } else {
                Item_DropCollectible(globalCtx, &pthis->actor.world.pos, dropTable[pthis->itemDrop] | 0x8000);
            }
        } else {
            randomDrop = pthis->itemDrop - WONDERITEM_DROP_RANDOM;
            if (!autoCollect) {
                Item_DropCollectibleRandom(globalCtx, NULL, &pthis->actor.world.pos, randomDrop);
            } else {
                Item_DropCollectibleRandom(globalCtx, NULL, &pthis->actor.world.pos, randomDrop | 0x8000);
            }
        }
    }
    if (pthis->switchFlag >= 0) {
        Flags_SetSwitch(globalCtx, pthis->switchFlag);
    }
    Actor_Kill(&pthis->actor);
}

void EnWonderItem_Init(Actor* thisx, GlobalContext* globalCtx) {
    static u32 collisionTypes[] = {
        0x00000702 /* sword slash */, 0x0001F820 /* arrow */,     0x00000040 /* hammer */,   0x00000008 /* bomb */,
        0x00000004 /* slingshot */,   0x00000010 /* boomerang */, 0x00000080 /* hookshot */,
    };
    s32 pad;
    s16 colTypeIndex;
    EnWonderItem* pthis = (EnWonderItem*)thisx;
    s16 rotZover10;
    s16 tagIndex;

    osSyncPrintf("\n\n");
    // "Mysterious mystery, very mysterious"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 不思議不思議まか不思議 \t   ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.params);
    pthis->actor.flags &= ~ACTOR_FLAG_0;

    pthis->wonderMode = (pthis->actor.params >> 0xB) & 0x1F;
    pthis->itemDrop = (pthis->actor.params >> 6) & 0x1F;
    pthis->switchFlag = pthis->actor.params & 0x3F;
    if (pthis->switchFlag == 0x3F) {
        pthis->switchFlag = -1;
    }
    pthis->actor.targetMode = 1;
    if ((pthis->switchFlag >= 0) && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ Ｙｏｕ ａｒｅ Ｓｈｏｃｋ！  ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
        Actor_Kill(&pthis->actor);
        return;
    }
    switch (pthis->wonderMode) {
        case WONDERITEM_MULTITAG_FREE:
            pthis->numTagPoints = pthis->actor.world.rot.z & 0xF;
            rotZover10 = 0;
            if (pthis->actor.world.rot.z >= 10) {
                rotZover10 = pthis->actor.world.rot.z / 10;
                pthis->timerMod = rotZover10 * 20;
            }
            pthis->numTagPoints = pthis->actor.world.rot.z - rotZover10 * 10;
            // i.e timerMod = rot.z / 10 seconds, numTagPoints = rot.z % 10
            pthis->updateFunc = EnWonderItem_MultitagFree;
            break;
        case WONDERITEM_TAG_POINT_FREE:
            tagIndex = pthis->actor.world.rot.z & 0xFF;
            sTagPointsFree[tagIndex] = pthis->actor.world.pos;
            Actor_Kill(&pthis->actor);
            break;
        case WONDERITEM_PROXIMITY_DROP:
            pthis->dropCount = pthis->actor.world.rot.z & 0xFF;
            pthis->updateFunc = EnWonderItem_ProximityDrop;
            break;
        case WONDERITEM_INTERACT_SWITCH:
            colTypeIndex = pthis->actor.world.rot.z & 0xFF;
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
            pthis->collider.info.bumper.dmgFlags = collisionTypes[colTypeIndex];
            pthis->collider.dim.radius = 20;
            pthis->collider.dim.height = 30;
            pthis->updateFunc = EnWonderItem_InteractSwitch;
            break;
        case WONDERITEM_UNUSED:
            break;
        case WONDERITEM_MULTITAG_ORDERED:
            pthis->numTagPoints = pthis->actor.world.rot.z & 0xF;
            rotZover10 = 0;
            if (pthis->actor.world.rot.z >= 10) {
                rotZover10 = pthis->actor.world.rot.z / 10;
                pthis->timerMod = rotZover10 * 20;
            }
            pthis->numTagPoints = pthis->actor.world.rot.z - rotZover10 * 10;
            // i.e timerMod = rot.z / 10 seconds, numTagPoints = rot.z % 10
            pthis->updateFunc = EnWonderItem_MultitagOrdered;
            break;
        case WONDERITEM_TAG_POINT_ORDERED:
            tagIndex = pthis->actor.world.rot.z & 0xFF;
            sTagPointsOrdered[tagIndex] = pthis->actor.world.pos;
            Actor_Kill(&pthis->actor);
            break;
        case WONDERITEM_PROXIMITY_SWITCH:
            pthis->updateFunc = EnWonderItem_ProximitySwitch;
            break;
        case WONDERITEM_BOMB_SOLDIER:
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
            pthis->collider.info.bumper.dmgFlags = 0x00000004; // slingshot
            pthis->unkPos = pthis->actor.world.pos;
            pthis->collider.dim.radius = 35;
            pthis->collider.dim.height = 75;
            pthis->updateFunc = EnWonderItem_BombSoldier;
            break;
        case WONDERITEM_ROLL_DROP:
            pthis->dropCount = pthis->actor.world.rot.z & 0xFF;
            pthis->updateFunc = EnWonderItem_RollDrop;
            break;
        default:
            Actor_Kill(&pthis->actor);
            break;
    }
}

void EnWonderItem_MultitagFree(EnWonderItem* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 prevTagFlags = pthis->tagFlags;
    s32 i;
    s32 mask;

    for (i = 0, mask = 1; i < pthis->numTagPoints; i++, mask <<= 1) {
        if (!(prevTagFlags & mask)) {
            f32 dx = player->actor.world.pos.x - sTagPointsFree[i].x;
            f32 dy = player->actor.world.pos.y - sTagPointsFree[i].y;
            f32 dz = player->actor.world.pos.z - sTagPointsFree[i].z;

            if (sqrtf(SQ(dx) + SQ(dy) + SQ(dz)) < 50.0f) {
                pthis->tagFlags |= mask;
                pthis->tagCount++;
                pthis->timer = pthis->timerMod + 81;
                return;
            }
        }
    }
    if (pthis->timer == 1) {
        Actor_Kill(&pthis->actor);
        return;
    }
    if (pthis->tagCount == pthis->numTagPoints) {
        if (pthis->switchFlag >= 0) {
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
        }
        EnWonderItem_DropCollectible(pthis, globalCtx, true);
    }
}

void EnWonderItem_ProximityDrop(EnWonderItem* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((pthis->actor.xzDistToPlayer < 50.0f) && (fabsf(pthis->actor.world.pos.y - player->actor.world.pos.y) < 30.0f)) {
        EnWonderItem_DropCollectible(pthis, globalCtx, true);
    }
}

void EnWonderItem_InteractSwitch(EnWonderItem* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        EnWonderItem_DropCollectible(pthis, globalCtx, false);
    }
}

void EnWonderItem_ProximitySwitch(EnWonderItem* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((pthis->actor.xzDistToPlayer < 50.0f) && (fabsf(pthis->actor.world.pos.y - player->actor.world.pos.y) < 30.0f)) {
        if (pthis->switchFlag >= 0) {
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
        }
        Actor_Kill(&pthis->actor);
    }
}

void EnWonderItem_MultitagOrdered(EnWonderItem* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 prevTagFlags = pthis->tagFlags;
    s32 i;
    s32 mask;

    for (i = 0, mask = 1; i < pthis->numTagPoints; i++, mask <<= 1) {
        if (!(prevTagFlags & mask)) {
            f32 dx = player->actor.world.pos.x - sTagPointsOrdered[i].x;
            f32 dy = player->actor.world.pos.y - sTagPointsOrdered[i].y;
            f32 dz = player->actor.world.pos.z - sTagPointsOrdered[i].z;

            if (sqrtf(SQ(dx) + SQ(dy) + SQ(dz)) < 50.0f) {
                if (prevTagFlags & mask) {
                    return;
                } else if (i == pthis->nextTag) {
                    pthis->tagFlags |= mask;
                    pthis->tagCount++;
                    pthis->nextTag++;
                    pthis->timer = pthis->timerMod + 81;
                    return;
                } else {
                    Actor_Kill(&pthis->actor);
                    return;
                }
            }
        }
    }
    if (pthis->timer == 1) {
        Actor_Kill(&pthis->actor);
        return;
    }
    if (pthis->tagCount == pthis->numTagPoints) {
        EnWonderItem_DropCollectible(pthis, globalCtx, true);
    }
}

void EnWonderItem_BombSoldier(EnWonderItem* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        if (Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_HEISHI2, pthis->actor.world.pos.x,
                        pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, pthis->actor.yawTowardsPlayer, 0,
                        9) != NULL) {
            // "Careless soldier spawned"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ うっかり兵セット完了 ☆☆☆☆☆ \n" VT_RST);
        }
        if (pthis->switchFlag >= 0) {
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
        }
        Actor_Kill(&pthis->actor);
    }
}

void EnWonderItem_RollDrop(EnWonderItem* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((pthis->actor.xzDistToPlayer < 50.0f) && (player->invincibilityTimer < 0) &&
        (fabsf(pthis->actor.world.pos.y - player->actor.world.pos.y) < 30.0f)) {
        EnWonderItem_DropCollectible(pthis, globalCtx, true);
    }
}

void EnWonderItem_Update(Actor* thisx, GlobalContext* globalCtx) {
    static s16 debugArrowColors[] = {
        255, 255, 0,   255, 0,   255, 0,   255, 255, 255, 0,   0, 0, 255, 0,   0, 0, 255, 128, 128,
        128, 128, 128, 0,   128, 0,   128, 0,   128, 0,   128, 0, 0, 0,   128, 0, 0, 0,   128,
    }; // These seem to be mistyped. Logically they should be s16[13][3] and be indexed as [colorIndex][i]
    s32 pad;
    EnWonderItem* pthis = (EnWonderItem*)thisx;
    s32 colorIndex;

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    pthis->updateFunc(pthis, globalCtx);

    if (pthis->wonderMode == WONDERITEM_UNUSED) {
        Actor_SetFocus(&pthis->actor, pthis->unkHeight);
    }
    if ((pthis->wonderMode == WONDERITEM_INTERACT_SWITCH) || (pthis->wonderMode == WONDERITEM_BOMB_SOLDIER)) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    colorIndex = pthis->wonderMode;
    if (pthis->wonderMode > 12) {
        colorIndex = 0;
    }
}
