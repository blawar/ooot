#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DNS_Z_EN_DNS_C
#include "actor_common.h"
/*
 * File: z_en_dns.c
 * Overlay: En_Dns
 * Description: Deku Salesman
 */

#include "z_en_dns.h"
#include "objects/object_shopnuts/object_shopnuts.h"
#include "vt.h"
#include "def/code_80097A00.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnDns_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDns_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnDns_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDns_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDns_Draw(Actor* thisx, GlobalContext* globalCtx);

u32 func_809EF5A4(EnDns* pthis);
u32 func_809EF658(EnDns* pthis);
u32 func_809EF70C(EnDns* pthis);
u32 func_809EF73C(EnDns* pthis);
u32 func_809EF800(EnDns* pthis);
u32 func_809EF854(EnDns* pthis);
u32 func_809EF8F4(EnDns* pthis);
u32 func_809EF9A4(EnDns* pthis);

void func_809EF9F8(EnDns* pthis);
void func_809EFA28(EnDns* pthis);
void func_809EFA58(EnDns* pthis);
void func_809EFA9C(EnDns* pthis);
void func_809EFACC(EnDns* pthis);
void func_809EFAFC(EnDns* pthis);
void func_809EFB40(EnDns* pthis);

void EnDns_SetupWait(EnDns* pthis, GlobalContext* globalCtx);
void EnDns_Wait(EnDns* pthis, GlobalContext* globalCtx);
void EnDns_Talk(EnDns* pthis, GlobalContext* globalCtx);
void func_809EFDD0(EnDns* pthis, GlobalContext* globalCtx);
void func_809EFEE8(EnDns* pthis, GlobalContext* globalCtx);
void func_809EFF50(EnDns* pthis, GlobalContext* globalCtx);
void func_809EFF98(EnDns* pthis, GlobalContext* globalCtx);
void func_809F008C(EnDns* pthis, GlobalContext* globalCtx);
void EnDns_SetupBurrow(EnDns* pthis, GlobalContext* globalCtx);
void EnDns_Burrow(EnDns* pthis, GlobalContext* globalCtx);

ActorInit En_Dns_InitVars = {
    ACTOR_EN_DNS,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SHOPNUTS,
    sizeof(EnDns),
    (ActorFunc)EnDns_Init,
    (ActorFunc)EnDns_Destroy,
    (ActorFunc)EnDns_Update,
    (ActorFunc)EnDns_Draw,
    (ActorFunc)EnDns_Reset,
};

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 18, 32, 0, { 0, 0, 0 } },
};

static u16 D_809F040C[] = {
    0x10A0, 0x10A1, 0x10A2, 0x10CA, 0x10CB, 0x10CC, 0x10CD, 0x10CE, 0x10CF, 0x10DC, 0x10DD,
};

// Debug text: "sells"  { "Deku Nuts",    "Deku Sticks",        "Piece of Heart",  "Deku Seeds",
//                        "Deku Shield",  "Bombs",              "Arrows",          "Red Potion",
//                        "Green Potion", "Deku Stick Upgrade", "Deku Nut Upgrade" }
static const char* D_809F0424[] = {
    "デクの実売り            ", "デクの棒売り            ", "ハートの欠片売り        ", "デクの種売り            ",
    "デクの盾売り            ", "バクダン売り            ", "矢売り                  ", "赤のくすり売り          ",
    "緑のくすり売り          ", "デクの棒持てる数を増やす", "デクの実持てる数を増やす",
};

static DnsItemEntry D_809F0450 = { 20, 5, GI_NUTS_5_2, func_809EF5A4, func_809EFA28 };

static DnsItemEntry D_809F0460 = { 15, 1, GI_STICKS_1, func_809EF658, func_809EF9F8 };

static DnsItemEntry D_809F0470 = { 10, 1, GI_HEART_PIECE, func_809EF70C, func_809EFA58 };

static DnsItemEntry D_809F0480 = { 40, 30, GI_SEEDS_30, func_809EF73C, func_809EF9F8 };

static DnsItemEntry D_809F0490 = { 50, 1, GI_SHIELD_DEKU, func_809EF800, func_809EF9F8 };

static DnsItemEntry D_809F04A0 = { 40, 5, GI_BOMBS_5, func_809EF854, func_809EFA9C };

static DnsItemEntry D_809F04B0 = { 70, 20, GI_ARROWS_LARGE, func_809EF8F4, func_809EFACC };

static DnsItemEntry D_809F04C0 = { 40, 1, GI_POTION_RED, func_809EF9A4, func_809EF9F8 };

static DnsItemEntry D_809F04D0 = { 40, 1, GI_POTION_GREEN, func_809EF9A4, func_809EF9F8 };

static DnsItemEntry D_809F04E0 = { 40, 1, GI_STICK_UPGRADE_20, func_809EF70C, func_809EFAFC };

static DnsItemEntry D_809F04F0 = { 40, 1, GI_NUT_UPGRADE_30, func_809EF70C, func_809EFB40 };

static DnsItemEntry* sItemEntries[] = {
    &D_809F0450, &D_809F0460, &D_809F0470, &D_809F0480, &D_809F0490, &D_809F04A0,
    &D_809F04B0, &D_809F04C0, &D_809F04D0, &D_809F04E0, &D_809F04F0,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x4E, ICHAIN_CONTINUE),
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 30, ICHAIN_STOP),
};

struct DnsAnimInfo {
    /* 0x00 */ AnimationHeader* anim;
    /* 0x04 */ u8 mode;
    /* 0x08 */ f32 transitionRate;
}; 

static DnsAnimInfo sAnimInfo[] = {
    { &gBusinessScrubNervousIdleAnim, ANIMMODE_LOOP, 0.0f },
    { &gBusinessScrubAnim_4404, ANIMMODE_ONCE, 0.0f },
    { &gBusinessScrubNervousTransitionAnim, ANIMMODE_ONCE, 0.0f },
};

void EnDns_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDns* pthis = (EnDns*)thisx;

    if (pthis->actor.params < 0) {
        // "Function Error (Deku Salesman)"
        osSyncPrintf(VT_FGCOL(RED) "引数エラー（売りナッツ）[ arg_data = %d ]" VT_RST "\n", pthis->actor.params);
        Actor_Kill(&pthis->actor);
        return;
    }
    // Sell Seeds instead of Arrows if Link is child
    if ((pthis->actor.params == 0x0006) && (LINK_AGE_IN_YEARS == YEARS_CHILD)) {
        pthis->actor.params = 0x0003;
    }
    // "Deku Salesman"
    osSyncPrintf(VT_FGCOL(GREEN) "◆◆◆ 売りナッツ『%s』 ◆◆◆" VT_RST "\n", D_809F0424[pthis->actor.params],
                 pthis->actor.params);
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBusinessScrubSkel, &gBusinessScrubNervousTransitionAnim,
                       pthis->jointTable, pthis->morphTable, 18);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 35.0f);
    pthis->actor.textId = D_809F040C[pthis->actor.params];
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->maintainCollider = 1;
    pthis->standOnGround = 1;
    pthis->dropCollectible = 0;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = -1.0f;
    pthis->dnsItemEntry = sItemEntries[pthis->actor.params];
    pthis->actionFunc = EnDns_SetupWait;
}

void EnDns_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDns* pthis = (EnDns*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnDns_Change(EnDns* pthis, u8 arg1) {
    s16 frameCount;

    frameCount = Animation_GetLastFrame(sAnimInfo[arg1].anim);
    pthis->unk_2BA = arg1; // Not used anywhere else?
    Animation_Change(&pthis->skelAnime, sAnimInfo[arg1].anim, 1.0f, 0.0f, (f32)frameCount, sAnimInfo[arg1].mode,
                     sAnimInfo[arg1].transitionRate);
}

/* Item give checking functions */

u32 func_809EF5A4(EnDns* pthis) {
    if ((CUR_CAPACITY(UPG_NUTS) != 0) && (AMMO(ITEM_NUT) >= CUR_CAPACITY(UPG_NUTS))) {
        return 1;
    }
    if (gSaveContext.rupees < pthis->dnsItemEntry->itemPrice) {
        return 0;
    }
    if (Item_CheckObtainability(ITEM_NUT) == ITEM_NONE) {
        return 2;
    }
    return 4;
}

u32 func_809EF658(EnDns* pthis) {
    if ((CUR_CAPACITY(UPG_STICKS) != 0) && (AMMO(ITEM_STICK) >= CUR_CAPACITY(UPG_STICKS))) {
        return 1;
    }
    if (gSaveContext.rupees < pthis->dnsItemEntry->itemPrice) {
        return 0;
    }
    if (Item_CheckObtainability(ITEM_STICK) == ITEM_NONE) {
        return 2;
    }
    return 4;
}

u32 func_809EF70C(EnDns* pthis) {
    if (gSaveContext.rupees < pthis->dnsItemEntry->itemPrice) {
        return 0;
    }
    return 4;
}

u32 func_809EF73C(EnDns* pthis) {
    if (INV_CONTENT(ITEM_SLINGSHOT) == ITEM_NONE) {
        return 3;
    }
    if (AMMO(ITEM_SLINGSHOT) >= CUR_CAPACITY(UPG_BULLET_BAG)) {
        return 1;
    }
    if (gSaveContext.rupees < pthis->dnsItemEntry->itemPrice) {
        return 0;
    }
    if (Item_CheckObtainability(ITEM_SEEDS) == ITEM_NONE) {
        return 2;
    }
    return 4;
}

u32 func_809EF800(EnDns* pthis) {
    if (gBitFlags[4] & gSaveContext.inventory.equipment) {
        return 1;
    }
    if (gSaveContext.rupees < pthis->dnsItemEntry->itemPrice) {
        return 0;
    }
    return 4;
}

u32 func_809EF854(EnDns* pthis) {
    if (!CHECK_QUEST_ITEM(QUEST_GORON_RUBY)) {
        return 3;
    }
    if (AMMO(ITEM_BOMB) >= CUR_CAPACITY(UPG_BOMB_BAG)) {
        return 1;
    }
    if (gSaveContext.rupees < pthis->dnsItemEntry->itemPrice) {
        return 0;
    }
    return 4;
}

u32 func_809EF8F4(EnDns* pthis) {
    if (Item_CheckObtainability(ITEM_BOW) == ITEM_NONE) {
        return 3;
    }
    if (AMMO(ITEM_BOW) >= CUR_CAPACITY(UPG_QUIVER)) {
        return 1;
    }
    if (gSaveContext.rupees < pthis->dnsItemEntry->itemPrice) {
        return 0;
    }
    return 4;
}

u32 func_809EF9A4(EnDns* pthis) {
    if (!Inventory_HasEmptyBottle()) {
        return 1;
    }
    if (gSaveContext.rupees < pthis->dnsItemEntry->itemPrice) {
        return 0;
    }
    return 4;
}

/* Paying and flagging functions */

void func_809EF9F8(EnDns* pthis) {
    Rupees_ChangeBy(-pthis->dnsItemEntry->itemPrice);
}

void func_809EFA28(EnDns* pthis) {
    Rupees_ChangeBy(-pthis->dnsItemEntry->itemPrice);
}

void func_809EFA58(EnDns* pthis) {
    gSaveContext.itemGetInf[0] |= 0x800;
    Rupees_ChangeBy(-pthis->dnsItemEntry->itemPrice);
}

void func_809EFA9C(EnDns* pthis) {
    Rupees_ChangeBy(-pthis->dnsItemEntry->itemPrice);
}

void func_809EFACC(EnDns* pthis) {
    Rupees_ChangeBy(-pthis->dnsItemEntry->itemPrice);
}

void func_809EFAFC(EnDns* pthis) {
    gSaveContext.infTable[25] |= 0x4;
    Rupees_ChangeBy(-pthis->dnsItemEntry->itemPrice);
}

void func_809EFB40(EnDns* pthis) {
    gSaveContext.infTable[25] |= 0x8;
    Rupees_ChangeBy(-pthis->dnsItemEntry->itemPrice);
}

void EnDns_SetupWait(EnDns* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.curFrame == pthis->skelAnime.endFrame) {
        pthis->actionFunc = EnDns_Wait;
        EnDns_Change(pthis, 0);
    }
}

void EnDns_Wait(EnDns* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 2000, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnDns_Talk;
    } else {
        if ((pthis->collider.base.ocFlags1 & OC1_HIT) || pthis->actor.isTargeted) {
            pthis->actor.flags |= ACTOR_FLAG_16;
        } else {
            pthis->actor.flags &= ~ACTOR_FLAG_16;
        }
        if (pthis->actor.xzDistToPlayer < 130.0f) {
            func_8002F2F4(&pthis->actor, globalCtx);
        }
    }
}

void EnDns_Talk(EnDns* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // OK
                switch (pthis->dnsItemEntry->purchaseableCheck(pthis)) {
                    case 0:
                        Message_ContinueTextbox(globalCtx, 0x10A5);
                        pthis->actionFunc = func_809F008C;
                        break;
                    case 1:
                        Message_ContinueTextbox(globalCtx, 0x10A6);
                        pthis->actionFunc = func_809F008C;
                        break;
                    case 3:
                        Message_ContinueTextbox(globalCtx, 0x10DE);
                        pthis->actionFunc = func_809F008C;
                        break;
                    case 2:
                    case 4:
                        Message_ContinueTextbox(globalCtx, 0x10A7);
                        pthis->actionFunc = func_809EFEE8;
                        break;
                }
                break;
            case 1: // No way
                Message_ContinueTextbox(globalCtx, 0x10A4);
                pthis->actionFunc = func_809F008C;
        }
    }
}

void func_809EFDD0(EnDns* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.params == 0x9) {
        if (CUR_UPG_VALUE(UPG_STICKS) < 2) {
            func_8002F434(&pthis->actor, globalCtx, GI_STICK_UPGRADE_20, 130.0f, 100.0f);
        } else {
            func_8002F434(&pthis->actor, globalCtx, GI_STICK_UPGRADE_30, 130.0f, 100.0f);
        }
    } else if (pthis->actor.params == 0xA) {
        if (CUR_UPG_VALUE(UPG_NUTS) < 2) {
            func_8002F434(&pthis->actor, globalCtx, GI_NUT_UPGRADE_30, 130.0f, 100.0f);
        } else {
            func_8002F434(&pthis->actor, globalCtx, GI_NUT_UPGRADE_40, 130.0f, 100.0f);
        }
    } else {
        func_8002F434(&pthis->actor, globalCtx, pthis->dnsItemEntry->getItemId, 130.0f, 100.0f);
    }
}

void func_809EFEE8(EnDns* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        func_809EFDD0(pthis, globalCtx);
        pthis->actionFunc = func_809EFF50;
    }
}

void func_809EFF50(EnDns* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = func_809EFF98;
    } else {
        func_809EFDD0(pthis, globalCtx);
    }
}

void func_809EFF98(EnDns* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (player->stateFlags1 & 0x400) {
        if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
            pthis->dnsItemEntry->setRupeesAndFlags(pthis);
            pthis->dropCollectible = 1;
            pthis->maintainCollider = 0;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            EnDns_Change(pthis, 1);
            pthis->actionFunc = EnDns_SetupBurrow;
        }
    } else {
        pthis->dnsItemEntry->setRupeesAndFlags(pthis);
        pthis->dropCollectible = 1;
        pthis->maintainCollider = 0;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        EnDns_Change(pthis, 1);
        pthis->actionFunc = EnDns_SetupBurrow;
    }
}

void func_809F008C(EnDns* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        pthis->maintainCollider = 0;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        EnDns_Change(pthis, 1);
        pthis->actionFunc = EnDns_SetupBurrow;
    }
}

void EnDns_SetupBurrow(EnDns* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gBusinessScrubAnim_4404);

    if (pthis->skelAnime.curFrame == frameCount) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_AKINDONUTS_HIDE);
        pthis->actionFunc = EnDns_Burrow;
        pthis->standOnGround = 0;
        pthis->yInitPos = pthis->actor.world.pos.y;
    }
}

void EnDns_Burrow(EnDns* pthis, GlobalContext* globalCtx) {
    f32 depth;
    Vec3f initPos;
    s32 i;

    depth = pthis->yInitPos - pthis->actor.world.pos.y;
    if ((pthis->dustTimer & 3) == 0) {
        initPos.x = pthis->actor.world.pos.x;
        initPos.y = pthis->yInitPos;
        initPos.z = pthis->actor.world.pos.z;
        func_80028990(globalCtx, 20.0f, &initPos);
    }
    pthis->actor.shape.rot.y += 0x2000;
    // Drops only if you bought its item
    if (depth > 400.0f) {
        if (pthis->dropCollectible) {
            initPos.x = pthis->actor.world.pos.x;
            initPos.y = pthis->yInitPos;
            initPos.z = pthis->actor.world.pos.z;
            for (i = 0; i < 3; i++) {
                Item_DropCollectible(globalCtx, &initPos, ITEM00_HEART);
            }
        }
        Actor_Kill(&pthis->actor);
    }
}

void EnDns_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDns* pthis = (EnDns*)thisx;
    s16 pad;

    pthis->dustTimer++;
    pthis->actor.textId = D_809F040C[pthis->actor.params];
    Actor_SetFocus(&pthis->actor, 60.0f);
    Actor_SetScale(&pthis->actor, 0.01f);
    SkelAnime_Update(&pthis->skelAnime);
    Actor_MoveForward(&pthis->actor);
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->standOnGround) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 20.0f, 4);
    }
    if (pthis->maintainCollider) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void EnDns_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDns* pthis = (EnDns*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, &pthis->actor);
}


void EnDns_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Dns_InitVars = {
        ACTOR_EN_DNS,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_SHOPNUTS,
        sizeof(EnDns),
        (ActorFunc)EnDns_Init,
        (ActorFunc)EnDns_Destroy,
        (ActorFunc)EnDns_Update,
        (ActorFunc)EnDns_Draw,
        (ActorFunc)EnDns_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 18, 32, 0, { 0, 0, 0 } },
    };

}
