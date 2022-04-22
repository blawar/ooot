#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_ITEM_SHIELD_Z_ITEM_SHIELD_C
#include "actor_common.h"
/*
 * File: z_item_shield.c
 * Overlay: ovl_Item_Shield
 * Description: Deku Shield
 */

#include "vt.h"
#include "z_item_shield.h"
#include "objects/object_link_child/object_link_child.h"
#include "def/sys_math_atan.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void ItemShield_Init(Actor* thisx, GlobalContext* globalCtx);
void ItemShield_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ItemShield_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ItemShield_Update(Actor* thisx, GlobalContext* globalCtx);
void ItemShield_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B86F68(ItemShield* pthis, GlobalContext* globalCtx);
void func_80B86BC8(ItemShield* pthis, GlobalContext* globalCtx);

static Vec3f D_80B871F4_31 = { 0.0f, 0.0f, 0.0f };

static f32 D_80B87200_31[] = { 0.3f, 0.6f,  0.9f, 1.0f,  1.0f, 1.0f,  1.0f, 1.0f,
                            1.0f, 0.85f, 0.7f, 0.55f, 0.4f, 0.25f, 0.1f, 0.0f };

static f32 D_80B87240_31[] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.8f,
                            0.6f, 0.4f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };


static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000004, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 15, 15, 0, { 0, 0, 0 } },
};

ActorInit Item_Shield_InitVars = {
    ACTOR_ITEM_SHIELD,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_LINK_CHILD,
    sizeof(ItemShield),
    (ActorFunc)ItemShield_Init,
    (ActorFunc)ItemShield_Destroy,
    (ActorFunc)ItemShield_Update,
    (ActorFunc)ItemShield_Draw,
    (ActorFunc)ItemShield_Reset,
};

static Color_RGBA8 unused = { 255, 255, 0, 255 };
static Color_RGBA8 unused2 = { 255, 0, 0, 255 };

void ItemShield_SetupAction(ItemShield* pthis, ItemShieldActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void ItemShield_Init(Actor* thisx, GlobalContext* globalCtx) {
    ItemShield* pthis = (ItemShield*)thisx;
    s32 i;

    pthis->timer = 0;
    pthis->unk_19C = 0;

    switch (pthis->actor.params) {
        case 0:
            ActorShape_Init(&pthis->actor.shape, 1400.0f, NULL, 0.0f);
            pthis->actor.shape.rot.x = 0x4000;
            ItemShield_SetupAction(pthis, func_80B86BC8);
            break;

        case 1:
            ActorShape_Init(&pthis->actor.shape, 0.0f, NULL, 0.0f);
            ItemShield_SetupAction(pthis, func_80B86F68);
            pthis->unk_19C |= 2;
            for (i = 0; i < 8; i++) {
                pthis->unk_19E[i] = 1 + 2 * i;
                pthis->unk_1A8[i].x = Rand_CenteredFloat(10.0f);
                pthis->unk_1A8[i].y = Rand_CenteredFloat(10.0f);
                pthis->unk_1A8[i].z = Rand_CenteredFloat(10.0f);
            }
            break;
    }

    Actor_SetScale(&pthis->actor, 0.01f);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    osSyncPrintf(VT_FGCOL(GREEN) "Item_Shild %d \n" VT_RST, pthis->actor.params);
}

void ItemShield_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ItemShield* pthis = (ItemShield*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80B86AC8(ItemShield* pthis, GlobalContext* globalCtx) {
    Actor_MoveForward(&pthis->actor);
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    func_8002F434(&pthis->actor, globalCtx, GI_SHIELD_DEKU, 30.0f, 50.0f);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 0.0f, 5);
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->timer--;
        if (pthis->timer < 60) {
            if (pthis->timer & 1) {
                pthis->unk_19C |= 2;
            } else {
                pthis->unk_19C &= ~2;
            }
        }
        if (pthis->timer == 0) {
            Actor_Kill(&pthis->actor);
        }
    }
}

void func_80B86BC8(ItemShield* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    func_8002F434(&pthis->actor, globalCtx, GI_SHIELD_DEKU, 30.0f, 50.0f);
    if (pthis->collider.base.acFlags & AC_HIT) {
        ItemShield_SetupAction(pthis, func_80B86AC8);
        pthis->actor.velocity.y = 4.0f;
        pthis->actor.minVelocityY = -4.0f;
        pthis->actor.gravity = -0.8f;
        pthis->actor.speedXZ = 0.0f;
        pthis->timer = 160;
    } else {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void func_80B86CA8(ItemShield* pthis, GlobalContext* globalCtx) {
    s32 i;
    s32 temp;

    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 0.0f, 5);
    pthis->actor.shape.yOffset = ABS(Math_SinS(pthis->actor.shape.rot.x)) * 1500.0f;

    for (i = 0; i < 8; i++) {
        temp = 15 - pthis->unk_19E[i];
        D_80B871F4_31.x = pthis->unk_1A8[i].x;
        D_80B871F4_31.y = pthis->unk_1A8[i].y + (pthis->actor.shape.yOffset * 0.01f) + (D_80B87200_31[temp] * -10.0f * 0.2f);
        D_80B871F4_31.z = pthis->unk_1A8[i].z;
        EffectSsFireTail_SpawnFlame(globalCtx, &pthis->actor, &D_80B871F4_31, D_80B87200_31[temp] * 0.2f, -1,
                                    D_80B87240_31[temp]);
        if (pthis->unk_19E[i] != 0) {
            pthis->unk_19E[i]--;
        } else if (pthis->timer > 16) {
            pthis->unk_19E[i] = 15;
            pthis->unk_1A8[i].x = Rand_CenteredFloat(15.0f);
            pthis->unk_1A8[i].y = Rand_CenteredFloat(10.0f);
            pthis->unk_1A8[i].z = Rand_CenteredFloat(15.0f);
        }
    }
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->unk_198 -= pthis->actor.shape.rot.x >> 1;
        pthis->unk_198 -= pthis->unk_198 >> 2;
        pthis->actor.shape.rot.x += pthis->unk_198;
        if ((pthis->timer >= 8) && (pthis->timer < 24)) {
            Actor_SetScale(&pthis->actor, (pthis->timer - 8) * 0.000625f);
        }
        if (pthis->timer != 0) {
            pthis->timer--;
        } else {
            Actor_Kill(&pthis->actor);
        }
    }
}

void func_80B86F68(ItemShield* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    MtxF* shield = &player->shieldMf;

    pthis->actor.world.pos.x = shield->xw;
    pthis->actor.world.pos.y = shield->yw;
    pthis->actor.world.pos.z = shield->zw;
    pthis->unk_19C &= ~2;

    pthis->actor.shape.rot.y = Math_Atan2S(-shield->zz, -shield->xz);
    pthis->actor.shape.rot.x = Math_Atan2S(-shield->yz, sqrtf(shield->zz * shield->zz + shield->xz * shield->xz));

    if (ABS(pthis->actor.shape.rot.x) > 0x4000) {
        pthis->unk_19C |= 1;
    }

    ItemShield_SetupAction(pthis, func_80B86CA8);

    pthis->actor.velocity.y = 4.0;
    pthis->actor.minVelocityY = -4.0;
    pthis->actor.gravity = -0.8;
    pthis->unk_198 = 0;
    pthis->timer = 70;
    pthis->actor.speedXZ = 0;
}

void ItemShield_Update(Actor* thisx, GlobalContext* globalCtx) {
    ItemShield* pthis = (ItemShield*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void ItemShield_Draw(Actor* thisx, GlobalContext* globalCtx) {
    ItemShield* pthis = (ItemShield*)thisx;

    if (!(pthis->unk_19C & 2)) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_item_shield.c", 457);
        func_80093D18(globalCtx->state.gfxCtx);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_item_shield.c", 460),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, SEGMENTED_TO_VIRTUAL(gLinkChildDekuShieldDL));
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_item_shield.c", 465);
    }
}

void ItemShield_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    D_80B871F4_31 = { 0.0f, 0.0f, 0.0f };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000004, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 15, 15, 0, { 0, 0, 0 } },
    };

    Item_Shield_InitVars = {
        ACTOR_ITEM_SHIELD,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_LINK_CHILD,
        sizeof(ItemShield),
        (ActorFunc)ItemShield_Init,
        (ActorFunc)ItemShield_Destroy,
        (ActorFunc)ItemShield_Update,
        (ActorFunc)ItemShield_Draw,
        (ActorFunc)ItemShield_Reset,
    };

    unused = { 255, 255, 0, 255 };

    unused2 = { 255, 0, 0, 255 };

}
