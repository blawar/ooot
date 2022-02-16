#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_RR_Z_EN_RR_C
#include "actor_common.h"
/*
 * File: z_en_rr.c
 * Overlay: ovl_En_Rr
 * Description: Like Like
 */

#include "z_en_rr.h"
#include "objects/object_rr/object_rr.h"
#include "vt.h"
#include "def/code_80097A00.h"
#include "def/code_800A9F30.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_10)

#define RR_MESSAGE_SHIELD (1 << 0)
#define RR_MESSAGE_TUNIC (1 << 1)
#define RR_MOUTH 4
#define RR_BASE 0


void EnRr_Init(Actor* thisx, GlobalContext* globalCtx);
void EnRr_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnRr_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnRr_Update(Actor* thisx, GlobalContext* globalCtx);
void EnRr_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnRr_InitBodySegments(EnRr* pthis, GlobalContext* globalCtx);

void EnRr_SetupDamage(EnRr* pthis);
void EnRr_SetupDeath(EnRr* pthis);

void EnRr_Approach(EnRr* pthis, GlobalContext* globalCtx);
void EnRr_Reach(EnRr* pthis, GlobalContext* globalCtx);
void EnRr_GrabPlayer(EnRr* pthis, GlobalContext* globalCtx);
void EnRr_Damage(EnRr* pthis, GlobalContext* globalCtx);
void EnRr_Death(EnRr* pthis, GlobalContext* globalCtx);
void EnRr_Retreat(EnRr* pthis, GlobalContext* globalCtx);
void EnRr_Stunned(EnRr* pthis, GlobalContext* globalCtx);

static f32 segmentHeights_51[] = { 0.0f, 500.0f, 750.0f, 1000.0f, 1000.0f };


ActorInit En_Rr_InitVars = {
    ACTOR_EN_RR,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_RR,
    sizeof(EnRr),
    (ActorFunc)EnRr_Init,
    (ActorFunc)EnRr_Destroy,
    (ActorFunc)EnRr_Update,
    (ActorFunc)EnRr_Draw,
    (ActorFunc)EnRr_Reset,
};

static const char* sDropNames[] = {
    // "type 7", "small magic jar", "arrow", "fairy", "20 rupees", "50 rupees"
    "タイプ７  ", "魔法の壷小", "矢        ", "妖精      ", "20ルピー  ", "50ルピー  ",
};

static ColliderCylinderInitType1 sCylinderInit1 = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 30, 55, 0, { 0, 0, 0 } },
};

static ColliderCylinderInitType1 sCylinderInit2 = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_ON | OC1_NO_PUSH | OC1_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 20, -10, { 0, 0, 0 } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, RR_DMG_NONE),
    /* Deku stick    */ DMG_ENTRY(2, RR_DMG_NORMAL),
    /* Slingshot     */ DMG_ENTRY(1, RR_DMG_NORMAL),
    /* Explosive     */ DMG_ENTRY(2, RR_DMG_NORMAL),
    /* Boomerang     */ DMG_ENTRY(0, RR_DMG_STUN),
    /* Normal arrow  */ DMG_ENTRY(2, RR_DMG_NORMAL),
    /* Hammer swing  */ DMG_ENTRY(2, RR_DMG_NORMAL),
    /* Hookshot      */ DMG_ENTRY(0, RR_DMG_STUN),
    /* Kokiri sword  */ DMG_ENTRY(1, RR_DMG_NORMAL),
    /* Master sword  */ DMG_ENTRY(2, RR_DMG_NORMAL),
    /* Giant's Knife */ DMG_ENTRY(4, RR_DMG_NORMAL),
    /* Fire arrow    */ DMG_ENTRY(4, RR_DMG_FIRE),
    /* Ice arrow     */ DMG_ENTRY(4, RR_DMG_ICE),
    /* Light arrow   */ DMG_ENTRY(15, RR_DMG_LIGHT_ARROW),
    /* Unk arrow 1   */ DMG_ENTRY(4, RR_DMG_WIND_ARROW),
    /* Unk arrow 2   */ DMG_ENTRY(15, RR_DMG_SHDW_ARROW),
    /* Unk arrow 3   */ DMG_ENTRY(15, RR_DMG_SPRT_ARROW),
    /* Fire magic    */ DMG_ENTRY(4, RR_DMG_FIRE),
    /* Ice magic     */ DMG_ENTRY(3, RR_DMG_ICE),
    /* Light magic   */ DMG_ENTRY(10, RR_DMG_LIGHT_MAGIC),
    /* Shield        */ DMG_ENTRY(0, RR_DMG_NONE),
    /* Mirror Ray    */ DMG_ENTRY(0, RR_DMG_NONE),
    /* Kokiri spin   */ DMG_ENTRY(1, RR_DMG_NORMAL),
    /* Giant spin    */ DMG_ENTRY(4, RR_DMG_NORMAL),
    /* Master spin   */ DMG_ENTRY(2, RR_DMG_NORMAL),
    /* Kokiri jump   */ DMG_ENTRY(2, RR_DMG_NORMAL),
    /* Giant jump    */ DMG_ENTRY(8, RR_DMG_NORMAL),
    /* Master jump   */ DMG_ENTRY(4, RR_DMG_NORMAL),
    /* Unknown 1     */ DMG_ENTRY(10, RR_DMG_SPRT_ARROW),
    /* Unblockable   */ DMG_ENTRY(0, RR_DMG_NONE),
    /* Hammer jump   */ DMG_ENTRY(0, RR_DMG_NONE),
    /* Unknown 2     */ DMG_ENTRY(0, RR_DMG_NONE),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x37, ICHAIN_CONTINUE),
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 30, ICHAIN_STOP),
};

void EnRr_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnRr* pthis = (EnRr*)thisx;
    s32 i;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    pthis->actor.colChkInfo.health = 4;
    Collider_InitCylinder(globalCtx, &pthis->collider1);
    Collider_SetCylinderType1(globalCtx, &pthis->collider1, &pthis->actor, &sCylinderInit1);
    Collider_InitCylinder(globalCtx, &pthis->collider2);
    Collider_SetCylinderType1(globalCtx, &pthis->collider2, &pthis->actor, &sCylinderInit2);
    Actor_SetFocus(&pthis->actor, 30.0f);
    pthis->actor.scale.y = 0.013f;
    pthis->actor.scale.x = pthis->actor.scale.z = 0.014f;
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->actor.velocity.y = pthis->actor.speedXZ = 0.0f;
    pthis->actor.gravity = -0.4f;
    pthis->actionTimer = 0;
    pthis->eatenShield = 0;
    pthis->eatenTunic = 0;
    pthis->retreat = false;
    pthis->grabTimer = 0;
    pthis->invincibilityTimer = 0;
    pthis->effectTimer = 0;
    pthis->hasPlayer = false;
    pthis->stopScroll = false;
    pthis->ocTimer = 0;
    pthis->reachState = pthis->isDead = false;
    pthis->actionFunc = EnRr_Approach;
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].height = pthis->bodySegs[i].heightTarget = pthis->bodySegs[i].scaleMod.x =
            pthis->bodySegs[i].scaleMod.y = pthis->bodySegs[i].scaleMod.z = 0.0f;
    }
    EnRr_InitBodySegments(pthis, globalCtx);
}

void EnRr_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnRr* pthis = (EnRr*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider1);
    Collider_DestroyCylinder(globalCtx, &pthis->collider2);
}

void EnRr_SetSpeed(EnRr* pthis, f32 speed) {
    pthis->actor.speedXZ = speed;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_LIKE_WALK);
}

void EnRr_SetupReach(EnRr* pthis) {
    s32 i;

    pthis->reachState = 1;
    pthis->actionTimer = 20;
    pthis->segPhaseVelTarget = 2500.0f;
    pthis->segMoveRate = 0.0f;
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].heightTarget = segmentHeights_51[i];
        pthis->bodySegs[i].scaleTarget.x = pthis->bodySegs[i].scaleTarget.z = 0.8f;
        pthis->bodySegs[i].rotTarget.x = 6000.0f;
        pthis->bodySegs[i].rotTarget.z = 0.0f;
    }
    pthis->actionFunc = EnRr_Reach;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_LIKE_UNARI);
}

void EnRr_SetupNeutral(EnRr* pthis) {
    s32 i;

    pthis->reachState = 0;
    pthis->segMoveRate = 0.0f;
    pthis->segPhaseVelTarget = 2500.0f;
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].heightTarget = 0.0f;
        pthis->bodySegs[i].rotTarget.x = pthis->bodySegs[i].rotTarget.z = 0.0f;
        pthis->bodySegs[i].scaleTarget.x = pthis->bodySegs[i].scaleTarget.z = 1.0f;
    }
    if (pthis->retreat) {
        pthis->actionTimer = 100;
        pthis->actionFunc = EnRr_Retreat;
    } else {
        pthis->actionTimer = 60;
        pthis->actionFunc = EnRr_Approach;
    }
}

void EnRr_SetupGrabPlayer(EnRr* pthis, Player* player) {
    s32 i;

    pthis->grabTimer = 100;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->ocTimer = 8;
    pthis->hasPlayer = true;
    pthis->reachState = 0;
    pthis->segMoveRate = pthis->swallowOffset = pthis->actor.speedXZ = 0.0f;
    pthis->pulseSizeTarget = 0.15f;
    pthis->segPhaseVelTarget = 5000.0f;
    pthis->wobbleSizeTarget = 512.0f;
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].heightTarget = 0.0f;
        pthis->bodySegs[i].rotTarget.x = pthis->bodySegs[i].rotTarget.z = 0.0f;
        pthis->bodySegs[i].scaleTarget.x = pthis->bodySegs[i].scaleTarget.z = 1.0f;
    }
    pthis->actionFunc = EnRr_GrabPlayer;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_LIKE_DRINK);
}

u8 EnRr_GetMessage(u8 shield, u8 tunic) {
    u8 messageIndex = 0;

    if ((shield == 1 /* Deku shield */) || (shield == 2 /* Hylian shield */)) {
        messageIndex = RR_MESSAGE_SHIELD;
    }
    if ((tunic == 2 /* Goron tunic */) || (tunic == 3 /* Zora tunic */)) {
        messageIndex |= RR_MESSAGE_TUNIC;
    }

    return messageIndex;
}

void EnRr_SetupReleasePlayer(EnRr* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    u8 shield;
    u8 tunic;

    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->hasPlayer = false;
    pthis->ocTimer = 110;
    pthis->segMoveRate = 0.0f;
    pthis->segPhaseVelTarget = 2500.0f;
    pthis->wobbleSizeTarget = 2048.0f;
    tunic = 0;
    shield = 0;
    if (CUR_EQUIP_VALUE(EQUIP_SHIELD) != 3 /* Mirror shield */) {
        shield = Inventory_DeleteEquipment(globalCtx, EQUIP_SHIELD);
        if (shield != 0) {
            pthis->eatenShield = shield;
            pthis->retreat = true;
        }
    }
    if (CUR_EQUIP_VALUE(EQUIP_TUNIC) != 1 /* Kokiri tunic */) {
        tunic = Inventory_DeleteEquipment(globalCtx, EQUIP_TUNIC);
        if (tunic != 0) {
            pthis->eatenTunic = tunic;
            pthis->retreat = true;
        }
    }
    player->actor.parent = NULL;
    switch (EnRr_GetMessage(shield, tunic)) {
        case RR_MESSAGE_SHIELD:
            Message_StartTextbox(globalCtx, 0x305F, NULL);
            break;
        case RR_MESSAGE_TUNIC:
            Message_StartTextbox(globalCtx, 0x3060, NULL);
            break;
        case RR_MESSAGE_TUNIC | RR_MESSAGE_SHIELD:
            Message_StartTextbox(globalCtx, 0x3061, NULL);
            break;
    }
    osSyncPrintf(VT_FGCOL(YELLOW) "%s[%d] : Rr_Catch_Cancel" VT_RST "\n", "../z_en_rr.c", 650);
    func_8002F6D4(globalCtx, &pthis->actor, 4.0f, pthis->actor.shape.rot.y, 12.0f, 8);
    if (pthis->actor.colorFilterTimer == 0) {
        pthis->actionFunc = EnRr_Approach;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_LIKE_THROW);
    } else if (pthis->actor.colChkInfo.health != 0) {
        EnRr_SetupDamage(pthis);
    } else {
        EnRr_SetupDeath(pthis);
    }
}

void EnRr_SetupDamage(EnRr* pthis) {
    s32 i;

    pthis->reachState = 0;
    pthis->actionTimer = 20;
    pthis->segMoveRate = 0.0f;
    pthis->segPhaseVelTarget = 2500.0f;
    pthis->pulseSizeTarget = 0.0f;
    pthis->wobbleSizeTarget = 0.0f;
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].heightTarget = 0.0f;
        pthis->bodySegs[i].rotTarget.x = pthis->bodySegs[i].rotTarget.z = 0.0f;
        pthis->bodySegs[i].scaleTarget.x = pthis->bodySegs[i].scaleTarget.z = 1.0f;
    }
    pthis->actionFunc = EnRr_Damage;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_LIKE_DAMAGE);
}

void EnRr_SetupApproach(EnRr* pthis) {
    s32 i;

    pthis->segMoveRate = 0.0f;
    pthis->pulseSizeTarget = 0.15f;
    pthis->segPhaseVelTarget = 2500.0f;
    pthis->wobbleSizeTarget = 2048.0f;
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].heightTarget = 0.0f;
        pthis->bodySegs[i].rotTarget.x = pthis->bodySegs[i].rotTarget.z = 0.0f;
        pthis->bodySegs[i].scaleTarget.x = pthis->bodySegs[i].scaleTarget.z = 1.0f;
    }
    pthis->actionFunc = EnRr_Approach;
}

void EnRr_SetupDeath(EnRr* pthis) {
    s32 i;

    pthis->isDead = true;
    pthis->frameCount = 0;
    pthis->shrinkRate = 0.0f;
    pthis->segMoveRate = 0.0f;
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].heightTarget = 0.0f;
        pthis->bodySegs[i].rotTarget.x = pthis->bodySegs[i].rotTarget.z = 0.0f;
    }
    pthis->actionFunc = EnRr_Death;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_LIKE_DEAD);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
}

void EnRr_SetupStunned(EnRr* pthis) {
    s32 i;

    pthis->stopScroll = true;
    pthis->segMovePhase = 0;
    pthis->segPhaseVel = 0.0f;
    pthis->segPhaseVelTarget = 2500.0f;
    pthis->segPulsePhaseDiff = 0.0f;
    pthis->segWobblePhaseDiffX = 0.0f;
    pthis->segWobbleXTarget = 3.0f;
    pthis->segWobblePhaseDiffZ = 0.0f;
    pthis->segWobbleZTarget = 1.0f;
    pthis->pulseSize = 0.0f;
    pthis->pulseSizeTarget = 0.15f;
    pthis->wobbleSize = 0.0f;
    pthis->wobbleSizeTarget = 2048.0f;
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].scaleMod.y = 0.0f;
        pthis->bodySegs[i].rotTarget.x = 0.0f;
        pthis->bodySegs[i].rotTarget.y = 0.0f;
        pthis->bodySegs[i].rotTarget.z = 0.0f;
        pthis->bodySegs[i].scale.x = pthis->bodySegs[i].scale.y = pthis->bodySegs[i].scale.z =
            pthis->bodySegs[i].scaleTarget.x = pthis->bodySegs[i].scaleTarget.y = pthis->bodySegs[i].scaleTarget.z = 1.0f;
    }
    pthis->actionFunc = EnRr_Stunned;
}

void EnRr_CollisionCheck(EnRr* pthis, GlobalContext* globalCtx) {
    Vec3f hitPos;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->collider2.base.acFlags & AC_HIT) {
        pthis->collider2.base.acFlags &= ~AC_HIT;
        // "Kakin" (not sure what pthis means)
        osSyncPrintf(VT_FGCOL(GREEN) "カキン(%d)！！" VT_RST "\n", pthis->frameCount);
        hitPos.x = pthis->collider2.info.bumper.hitPos.x;
        hitPos.y = pthis->collider2.info.bumper.hitPos.y;
        hitPos.z = pthis->collider2.info.bumper.hitPos.z;
        CollisionCheck_SpawnShieldParticlesMetal2(globalCtx, &hitPos);
    } else {
        if (pthis->collider1.base.acFlags & AC_HIT) {
            u8 dropType = RR_DROP_RANDOM_RUPEE;

            pthis->collider1.base.acFlags &= ~AC_HIT;
            if (pthis->actor.colChkInfo.damageEffect != 0) {
                hitPos.x = pthis->collider1.info.bumper.hitPos.x;
                hitPos.y = pthis->collider1.info.bumper.hitPos.y;
                hitPos.z = pthis->collider1.info.bumper.hitPos.z;
                CollisionCheck_BlueBlood(globalCtx, NULL, &hitPos);
            }
            switch (pthis->actor.colChkInfo.damageEffect) {
                case RR_DMG_LIGHT_ARROW:
                    dropType++; // purple rupee
                case RR_DMG_SHDW_ARROW:
                    dropType++; // flexible
                case RR_DMG_WIND_ARROW:
                    dropType++; // arrow
                case RR_DMG_SPRT_ARROW:
                    dropType++; // magic jar
                case RR_DMG_NORMAL:
                    // "ouch"
                    osSyncPrintf(VT_FGCOL(RED) "いてっ( %d : LIFE %d : DAMAGE %d : %x )！！" VT_RST "\n",
                                 pthis->frameCount, pthis->actor.colChkInfo.health, pthis->actor.colChkInfo.damage,
                                 pthis->actor.colChkInfo.damageEffect);
                    pthis->stopScroll = false;
                    Actor_ApplyDamage(&pthis->actor);
                    pthis->invincibilityTimer = 40;
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, pthis->invincibilityTimer);
                    if (pthis->hasPlayer) {
                        EnRr_SetupReleasePlayer(pthis, globalCtx);
                    } else if (pthis->actor.colChkInfo.health != 0) {
                        EnRr_SetupDamage(pthis);
                    } else {
                        pthis->dropType = dropType;
                        EnRr_SetupDeath(pthis);
                    }
                    return;
                case RR_DMG_FIRE: // Fire Arrow and Din's Fire
                    Actor_ApplyDamage(&pthis->actor);
                    if (pthis->actor.colChkInfo.health == 0) {
                        pthis->dropType = RR_DROP_RANDOM_RUPEE;
                    }
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, 0x50);
                    pthis->effectTimer = 20;
                    EnRr_SetupStunned(pthis);
                    return;
                case RR_DMG_ICE: // Ice Arrow and unused ice magic
                    Actor_ApplyDamage(&pthis->actor);
                    if (pthis->actor.colChkInfo.health == 0) {
                        pthis->dropType = RR_DROP_RANDOM_RUPEE;
                    }
                    if (pthis->actor.colorFilterTimer == 0) {
                        pthis->effectTimer = 20;
                        Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0x2000, 0x50);
                    }
                    EnRr_SetupStunned(pthis);
                    return;
                case RR_DMG_LIGHT_MAGIC: // Unused light magic
                    Actor_ApplyDamage(&pthis->actor);
                    if (pthis->actor.colChkInfo.health == 0) {
                        pthis->dropType = RR_DROP_RUPEE_RED;
                    }
                    Actor_SetColorFilter(&pthis->actor, -0x8000, 0xFF, 0x2000, 0x50);
                    EnRr_SetupStunned(pthis);
                    return;
                case RR_DMG_STUN: // Boomerang and Hookshot
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
                    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0x2000, 0x50);
                    EnRr_SetupStunned(pthis);
                    return;
            }
        }
        if ((pthis->ocTimer == 0) && (pthis->actor.colorFilterTimer == 0) && (player->invincibilityTimer == 0) &&
            !(player->stateFlags2 & 0x80) &&
            ((pthis->collider1.base.ocFlags1 & OC1_HIT) || (pthis->collider2.base.ocFlags1 & OC1_HIT))) {
            pthis->collider1.base.ocFlags1 &= ~OC1_HIT;
            pthis->collider2.base.ocFlags1 &= ~OC1_HIT;
            // "catch"
            osSyncPrintf(VT_FGCOL(GREEN) "キャッチ(%d)！！" VT_RST "\n", pthis->frameCount);
            if (globalCtx->grabPlayer(globalCtx, player)) {
                player->actor.parent = &pthis->actor;
                pthis->stopScroll = false;
                EnRr_SetupGrabPlayer(pthis, player);
            }
        }
    }
}

void EnRr_InitBodySegments(EnRr* pthis, GlobalContext* globalCtx) {
    s32 i;

    pthis->segMovePhase = 0;
    pthis->segPhaseVel = 0.0f;
    pthis->segPhaseVelTarget = 2500.0f;
    pthis->segPulsePhaseDiff = 0.0f;
    pthis->segWobblePhaseDiffX = 0.0f;
    pthis->segWobbleXTarget = 3.0f;
    pthis->segWobblePhaseDiffZ = 0.0f;
    pthis->segWobbleZTarget = 1.0f;
    pthis->pulseSize = 0.0f;
    pthis->pulseSizeTarget = 0.15f;
    pthis->wobbleSize = 0.0f;
    pthis->wobbleSizeTarget = 2048.0f;
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].scaleMod.y = 0.0f;
        pthis->bodySegs[i].rotTarget.x = 0.0f;
        pthis->bodySegs[i].rotTarget.y = 0.0f;
        pthis->bodySegs[i].rotTarget.z = 0.0f;
        pthis->bodySegs[i].scale.x = pthis->bodySegs[i].scale.y = pthis->bodySegs[i].scale.z =
            pthis->bodySegs[i].scaleTarget.x = pthis->bodySegs[i].scaleTarget.y = pthis->bodySegs[i].scaleTarget.z = 1.0f;
    }
    for (i = 0; i < 5; i++) {
        pthis->bodySegs[i].scaleMod.x = pthis->bodySegs[i].scaleMod.z =
            Math_CosS(i * (u32)(s16)pthis->segPulsePhaseDiff * 0x1000) * pthis->pulseSize;
    }
    for (i = 1; i < 5; i++) {
        pthis->bodySegs[i].rotTarget.x = Math_CosS(i * (u32)(s16)pthis->segWobblePhaseDiffX * 0x1000) * pthis->wobbleSize;
        pthis->bodySegs[i].rotTarget.z = Math_SinS(i * (u32)(s16)pthis->segWobblePhaseDiffZ * 0x1000) * pthis->wobbleSize;
    }
}

void EnRr_UpdateBodySegments(EnRr* pthis, GlobalContext* globalCtx) {
    s32 i;
    s16 phase = pthis->segMovePhase;

    if (!pthis->isDead) {
        for (i = 0; i < 5; i++) {
            pthis->bodySegs[i].scaleMod.x = pthis->bodySegs[i].scaleMod.z =
                Math_CosS(phase + i * (s16)pthis->segPulsePhaseDiff * 0x1000) * pthis->pulseSize;
        }
        phase = pthis->segMovePhase;
        if (!pthis->isDead && (pthis->reachState == 0)) {
            for (i = 1; i < 5; i++) {
                pthis->bodySegs[i].rotTarget.x =
                    Math_CosS(phase + i * (s16)pthis->segWobblePhaseDiffX * 0x1000) * pthis->wobbleSize;
                pthis->bodySegs[i].rotTarget.z =
                    Math_SinS(phase + i * (s16)pthis->segWobblePhaseDiffZ * 0x1000) * pthis->wobbleSize;
            }
        }
    }
    if (!pthis->stopScroll) {
        pthis->segMovePhase += (s16)pthis->segPhaseVel;
    }
}

void EnRr_Approach(EnRr* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0xA, 0x1F4, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    if ((pthis->actionTimer == 0) && (pthis->actor.xzDistToPlayer < 160.0f)) {
        EnRr_SetupReach(pthis);
    } else if ((pthis->actor.xzDistToPlayer < 400.0f) && (pthis->actor.speedXZ == 0.0f)) {
        EnRr_SetSpeed(pthis, 2.0f);
    }
}

void EnRr_Reach(EnRr* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0xA, 0x1F4, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    switch (pthis->reachState) {
        case REACH_EXTEND:
            if (pthis->actionTimer == 0) {
                pthis->reachState = REACH_STOP;
            }
            break;
        case REACH_STOP:
            if (pthis->actionTimer == 0) {
                pthis->actionTimer = 5;
                pthis->bodySegs[RR_MOUTH].scaleTarget.x = pthis->bodySegs[RR_MOUTH].scaleTarget.z = 1.5f;
                pthis->reachState = REACH_OPEN;
            }
            break;
        case REACH_OPEN:
            if (pthis->actionTimer == 0) {
                pthis->actionTimer = 2;
                pthis->bodySegs[RR_MOUTH].heightTarget = 2000.0f;
                pthis->reachState = REACH_GAPE;
            }
            break;
        case REACH_GAPE:
            if (pthis->actionTimer == 0) {
                pthis->actionTimer = 20;
                pthis->bodySegs[RR_MOUTH].scaleTarget.x = pthis->bodySegs[RR_MOUTH].scaleTarget.z = 0.8f;
                pthis->reachState = REACH_CLOSE;
            }
            break;
        case REACH_CLOSE:
            if (pthis->actionTimer == 0) {
                EnRr_SetupNeutral(pthis);
            }
            break;
    }
}

void EnRr_GrabPlayer(EnRr* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    func_800AA000(pthis->actor.xyzDistToPlayerSq, 120, 2, 120);
    if ((pthis->frameCount % 8) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_LIKE_EAT);
    }
    pthis->ocTimer = 8;
    if ((pthis->grabTimer == 0) || !(player->stateFlags2 & 0x80)) {
        EnRr_SetupReleasePlayer(pthis, globalCtx);
    } else {
        Math_ApproachF(&player->actor.world.pos.x, pthis->mouthPos.x, 1.0f, 30.0f);
        Math_ApproachF(&player->actor.world.pos.y, pthis->mouthPos.y + pthis->swallowOffset, 1.0f, 30.0f);
        Math_ApproachF(&player->actor.world.pos.z, pthis->mouthPos.z, 1.0f, 30.0f);
        Math_ApproachF(&pthis->swallowOffset, -55.0f, 1.0f, 5.0f);
    }
}

void EnRr_Damage(EnRr* pthis, GlobalContext* globalCtx) {
    s32 i;

    if (pthis->actor.colorFilterTimer == 0) {
        EnRr_SetupApproach(pthis);
    } else if ((pthis->actor.colorFilterTimer & 8) != 0) {
        for (i = 1; i < 5; i++) {
            pthis->bodySegs[i].rotTarget.z = 5000.0f;
        }
    } else {
        for (i = 1; i < 5; i++) {
            pthis->bodySegs[i].rotTarget.z = -5000.0f;
        }
    }
}

void EnRr_Death(EnRr* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 i;

    if (pthis->frameCount < 40) {
        for (i = 0; i < 5; i++) {
            Math_ApproachF(&pthis->bodySegs[i].heightTarget, i + 59 - (pthis->frameCount * 25.0f), 1.0f, 50.0f);
            pthis->bodySegs[i].scaleTarget.x = pthis->bodySegs[i].scaleTarget.z =
                (SQ(4 - i) * (f32)pthis->frameCount * 0.003f) + 1.0f;
        }
    } else if (pthis->frameCount >= 95) {
        Vec3f dropPos;

        dropPos.x = pthis->actor.world.pos.x;
        dropPos.y = pthis->actor.world.pos.y;
        dropPos.z = pthis->actor.world.pos.z;
        switch (pthis->eatenShield) {
            case 1:
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_SHIELD_DEKU);
                break;
            case 2:
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_SHIELD_HYLIAN);
                break;
        }
        switch (pthis->eatenTunic) {
            case 2:
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_TUNIC_GORON);
                break;
            case 3:
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_TUNIC_ZORA);
                break;
        }
        // "dropped"
        osSyncPrintf(VT_FGCOL(GREEN) "「%s」が出た！！" VT_RST "\n", sDropNames[pthis->dropType]);
        switch (pthis->dropType) {
            case RR_DROP_MAGIC:
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_MAGIC_SMALL);
                break;
            case RR_DROP_ARROW:
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_ARROWS_SINGLE);
                break;
            case RR_DROP_FLEXIBLE:
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_FLEXIBLE);
                break;
            case RR_DROP_RUPEE_PURPLE:
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_RUPEE_PURPLE);
                break;
            case RR_DROP_RUPEE_RED:
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_RUPEE_RED);
                break;
            case RR_DROP_RANDOM_RUPEE:
            default:
                Item_DropCollectibleRandom(globalCtx, &pthis->actor, &dropPos, 12 << 4);
                break;
        }
        Actor_Kill(&pthis->actor);
    } else if (pthis->frameCount == 88) {
        Vec3f pos;
        Vec3f vel;
        Vec3f accel;

        pos.x = pthis->actor.world.pos.x;
        pos.y = pthis->actor.world.pos.y + 20.0f;
        pos.z = pthis->actor.world.pos.z;
        vel.x = 0.0f;
        vel.y = 0.0f;
        vel.z = 0.0f;
        accel.x = 0.0f;
        accel.y = 0.0f;
        accel.z = 0.0f;

        EffectSsDeadDb_Spawn(globalCtx, &pos, &vel, &accel, 100, 0, 255, 255, 255, 255, 255, 0, 0, 1, 9, true);
    } else {
        Math_ApproachF(&pthis->actor.scale.x, 0.0f, 1.0f, pthis->shrinkRate);
        Math_ApproachF(&pthis->shrinkRate, 0.001f, 1.0f, 0.00001f);
        pthis->actor.scale.z = pthis->actor.scale.x;
    }
}

void EnRr_Retreat(EnRr* pthis, GlobalContext* globalCtx) {
    if (pthis->actionTimer == 0) {
        pthis->retreat = false;
        pthis->actionFunc = EnRr_Approach;
    } else {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer + 0x8000, 0xA, 0x3E8, 0);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        if (pthis->actor.speedXZ == 0.0f) {
            EnRr_SetSpeed(pthis, 2.0f);
        }
    }
}

void EnRr_Stunned(EnRr* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.colorFilterTimer == 0) {
        pthis->stopScroll = false;
        if (pthis->hasPlayer) {
            EnRr_SetupReleasePlayer(pthis, globalCtx);
        } else if (pthis->actor.colChkInfo.health != 0) {
            pthis->actionFunc = EnRr_Approach;
        } else {
            EnRr_SetupDeath(pthis);
        }
    }
}

void EnRr_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnRr* pthis = (EnRr*)thisx;
    s32 i;

    pthis->frameCount++;
    if (!pthis->stopScroll) {
        pthis->scrollTimer++;
    }
    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    if (pthis->grabTimer != 0) {
        pthis->grabTimer--;
    }
    if (pthis->ocTimer != 0) {
        pthis->ocTimer--;
    }
    if (pthis->invincibilityTimer != 0) {
        pthis->invincibilityTimer--;
    }
    if (pthis->effectTimer != 0) {
        pthis->effectTimer--;
    }

    Actor_SetFocus(&pthis->actor, 30.0f);
    EnRr_UpdateBodySegments(pthis, globalCtx);
    if (!pthis->isDead && ((pthis->actor.colorFilterTimer == 0) || !(pthis->actor.colorFilterParams & 0x4000))) {
        EnRr_CollisionCheck(pthis, globalCtx);
    }

    pthis->actionFunc(pthis, globalCtx);
    if (pthis->hasPlayer == 0x3F80) { // checks if 1.0f has been stored to hasPlayer's address
        ASSERT(0, "0", "../z_en_rr.c", 1355);
    }

    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.1f);
    Actor_MoveForward(&pthis->actor);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider1);
    pthis->collider2.dim.pos.x = pthis->mouthPos.x;
    pthis->collider2.dim.pos.y = pthis->mouthPos.y;
    pthis->collider2.dim.pos.z = pthis->mouthPos.z;
    if (!pthis->isDead && (pthis->invincibilityTimer == 0)) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider1.base);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider2.base);
        if (pthis->ocTimer == 0) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider1.base);
        }
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider2.base);
    } else {
        pthis->collider2.base.ocFlags1 &= ~OC1_HIT;
        pthis->collider2.base.acFlags &= ~AC_HIT;
        pthis->collider1.base.ocFlags1 &= ~OC1_HIT;
        pthis->collider1.base.acFlags &= ~AC_HIT;
    }
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 30.0f, 20.0f, 7);
    if (!pthis->stopScroll) {
        Math_ApproachF(&pthis->segPhaseVel, pthis->segPhaseVelTarget, 1.0f, 50.0f);
        Math_ApproachF(&pthis->segPulsePhaseDiff, 4.0f, 1.0f, 5.0f);
        Math_ApproachF(&pthis->segWobblePhaseDiffX, pthis->segWobbleXTarget, 1.0f, 0.04f);
        Math_ApproachF(&pthis->segWobblePhaseDiffZ, pthis->segWobbleZTarget, 1.0f, 0.01f);
        Math_ApproachF(&pthis->pulseSize, pthis->pulseSizeTarget, 1.0f, 0.0015f);
        Math_ApproachF(&pthis->wobbleSize, pthis->wobbleSizeTarget, 1.0f, 20.0f);
        for (i = 0; i < 5; i++) {
            Math_SmoothStepToS(&pthis->bodySegs[i].rot.x, pthis->bodySegs[i].rotTarget.x, 5, pthis->segMoveRate * 1000.0f,
                               0);
            Math_SmoothStepToS(&pthis->bodySegs[i].rot.z, pthis->bodySegs[i].rotTarget.z, 5, pthis->segMoveRate * 1000.0f,
                               0);
            Math_ApproachF(&pthis->bodySegs[i].scale.x, pthis->bodySegs[i].scaleTarget.x, 1.0f, pthis->segMoveRate * 0.2f);
            pthis->bodySegs[i].scale.z = pthis->bodySegs[i].scale.x;
            Math_ApproachF(&pthis->bodySegs[i].height, pthis->bodySegs[i].heightTarget, 1.0f, pthis->segMoveRate * 300.0f);
        }
        Math_ApproachF(&pthis->segMoveRate, 1.0f, 1.0f, 0.2f);
    }
}

static Vec3f sEffectOffsets[] = {
    { 25.0f, 0.0f, 0.0f },
    { -25.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 25.0f },
    { 0.0f, 0.0f, -25.0f },
};

void EnRr_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f zeroVec;
    EnRr* pthis = (EnRr*)thisx;
    s32 i;
    Mtx* segMtx = (Mtx*)Graph_Alloc(globalCtx->state.gfxCtx, 4 * sizeof(Mtx));

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_rr.c", 1478);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x0C, segMtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (pthis->scrollTimer * 0) & 0x7F,
                                (pthis->scrollTimer * 0) & 0x3F, 32, 16, 1, (pthis->scrollTimer * 0) & 0x3F,
                                (pthis->scrollTimer * -6) & 0x7F, 32, 16));
    Matrix_Push();

    Matrix_Scale((1.0f + pthis->bodySegs[RR_BASE].scaleMod.x) * pthis->bodySegs[RR_BASE].scale.x,
                 (1.0f + pthis->bodySegs[RR_BASE].scaleMod.y) * pthis->bodySegs[RR_BASE].scale.y,
                 (1.0f + pthis->bodySegs[RR_BASE].scaleMod.z) * pthis->bodySegs[RR_BASE].scale.z, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_rr.c", 1501),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    Matrix_Pop();
    zeroVec.x = 0.0f;
    zeroVec.y = 0.0f;
    zeroVec.z = 0.0f;
    for (i = 1; i < 5; i++) {
        Matrix_Translate(0.0f, pthis->bodySegs[i].height + 1000.0f, 0.0f, MTXMODE_APPLY);

        Matrix_RotateZYX(pthis->bodySegs[i].rot.x, pthis->bodySegs[i].rot.y, pthis->bodySegs[i].rot.z, MTXMODE_APPLY);
        Matrix_Push();
        Matrix_Scale((1.0f + pthis->bodySegs[i].scaleMod.x) * pthis->bodySegs[i].scale.x,
                     (1.0f + pthis->bodySegs[i].scaleMod.y) * pthis->bodySegs[i].scale.y,
                     (1.0f + pthis->bodySegs[i].scaleMod.z) * pthis->bodySegs[i].scale.z, MTXMODE_APPLY);
        Matrix_ToMtx(segMtx, "../z_en_rr.c", 1527);
        Matrix_Pop();
        segMtx++;
        Matrix_MultVec3f(&zeroVec, &pthis->effectPos[i]);
    }
    pthis->effectPos[0] = pthis->actor.world.pos;
    Matrix_MultVec3f(&zeroVec, &pthis->mouthPos);
    gSPDisplayList(POLY_XLU_DISP++, gLikeLikeDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_rr.c", 1551);
    if (pthis->effectTimer != 0) {
        Vec3f effectPos;
        s16 effectTimer = pthis->effectTimer - 1;

        pthis->actor.colorFilterTimer++;
        if ((effectTimer & 1) == 0) {
            s32 segIndex = 4 - (effectTimer >> 2);
            s32 offIndex = (effectTimer >> 1) & 3;

            effectPos.x = pthis->effectPos[segIndex].x + sEffectOffsets[offIndex].x + Rand_CenteredFloat(10.0f);
            effectPos.y = pthis->effectPos[segIndex].y + sEffectOffsets[offIndex].y + Rand_CenteredFloat(10.0f);
            effectPos.z = pthis->effectPos[segIndex].z + sEffectOffsets[offIndex].z + Rand_CenteredFloat(10.0f);
            if (pthis->actor.colorFilterParams & 0x4000) {
                EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &effectPos, 100, 0, 0, -1);
            } else {
                EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &effectPos, 150, 150, 150, 250, 235, 245, 255,
                                               3.0f);
            }
        }
    }
}

void EnRr_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Rr_InitVars = {
        ACTOR_EN_RR,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_RR,
        sizeof(EnRr),
        (ActorFunc)EnRr_Init,
        (ActorFunc)EnRr_Destroy,
        (ActorFunc)EnRr_Update,
        (ActorFunc)EnRr_Draw,
        (ActorFunc)EnRr_Reset,
    };

    sCylinderInit1 = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_PLAYER,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 30, 55, 0, { 0, 0, 0 } },
    };

    sCylinderInit2 = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_ON | OC1_NO_PUSH | OC1_TYPE_PLAYER,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 20, 20, -10, { 0, 0, 0 } },
    };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, RR_DMG_NONE),
        /* Deku stick    */ DMG_ENTRY(2, RR_DMG_NORMAL),
        /* Slingshot     */ DMG_ENTRY(1, RR_DMG_NORMAL),
        /* Explosive     */ DMG_ENTRY(2, RR_DMG_NORMAL),
        /* Boomerang     */ DMG_ENTRY(0, RR_DMG_STUN),
        /* Normal arrow  */ DMG_ENTRY(2, RR_DMG_NORMAL),
        /* Hammer swing  */ DMG_ENTRY(2, RR_DMG_NORMAL),
        /* Hookshot      */ DMG_ENTRY(0, RR_DMG_STUN),
        /* Kokiri sword  */ DMG_ENTRY(1, RR_DMG_NORMAL),
        /* Master sword  */ DMG_ENTRY(2, RR_DMG_NORMAL),
        /* Giant's Knife */ DMG_ENTRY(4, RR_DMG_NORMAL),
        /* Fire arrow    */ DMG_ENTRY(4, RR_DMG_FIRE),
        /* Ice arrow     */ DMG_ENTRY(4, RR_DMG_ICE),
        /* Light arrow   */ DMG_ENTRY(15, RR_DMG_LIGHT_ARROW),
        /* Unk arrow 1   */ DMG_ENTRY(4, RR_DMG_WIND_ARROW),
        /* Unk arrow 2   */ DMG_ENTRY(15, RR_DMG_SHDW_ARROW),
        /* Unk arrow 3   */ DMG_ENTRY(15, RR_DMG_SPRT_ARROW),
        /* Fire magic    */ DMG_ENTRY(4, RR_DMG_FIRE),
        /* Ice magic     */ DMG_ENTRY(3, RR_DMG_ICE),
        /* Light magic   */ DMG_ENTRY(10, RR_DMG_LIGHT_MAGIC),
        /* Shield        */ DMG_ENTRY(0, RR_DMG_NONE),
        /* Mirror Ray    */ DMG_ENTRY(0, RR_DMG_NONE),
        /* Kokiri spin   */ DMG_ENTRY(1, RR_DMG_NORMAL),
        /* Giant spin    */ DMG_ENTRY(4, RR_DMG_NORMAL),
        /* Master spin   */ DMG_ENTRY(2, RR_DMG_NORMAL),
        /* Kokiri jump   */ DMG_ENTRY(2, RR_DMG_NORMAL),
        /* Giant jump    */ DMG_ENTRY(8, RR_DMG_NORMAL),
        /* Master jump   */ DMG_ENTRY(4, RR_DMG_NORMAL),
        /* Unknown 1     */ DMG_ENTRY(10, RR_DMG_SPRT_ARROW),
        /* Unblockable   */ DMG_ENTRY(0, RR_DMG_NONE),
        /* Hammer jump   */ DMG_ENTRY(0, RR_DMG_NONE),
        /* Unknown 2     */ DMG_ENTRY(0, RR_DMG_NONE),
    };

}
