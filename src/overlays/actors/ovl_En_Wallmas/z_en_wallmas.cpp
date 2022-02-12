#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_WALLMAS_Z_EN_WALLMAS_C
#include "actor_common.h"
/*
 * File: z_en_wallmas
 * Overlay: En_Wallmas
 * Description: Wallmaster (Ceiling monster)
 */

#include "z_en_wallmas.h"
#include "objects/object_wallmaster/object_wallmaster.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800F7260.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)

#define TIMER_SCALE ((f32)OS_CLOCK_RATE / 10000000000)
#define DEGREE_60_RAD (60.0f * M_PI / 180.0f)
#define DEGREE_15_RAD (15.0f * M_PI / 180.0f)

#define DAMAGE_EFFECT_BURN 2
#define DAMAGE_EFFECT_STUN_WHITE 4
#define DAMAGE_EFFECT_STUN_BLUE 1

void EnWallmas_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWallmas_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWallmas_Update(Actor* thisx, GlobalContext* globalCtx);
void EnWallmas_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnWallmas_TimerInit(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_ProximityOrSwitchInit(EnWallmas* pthis);
void EnWallmas_WaitToDrop(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_Drop(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_Land(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_Stand(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_JumpToCeiling(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_ReturnToCeiling(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_TakeDamage(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_Cooldown(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_Die(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_TakePlayer(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_WaitForProximity(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_WaitForSwitchFlag(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_Stun(EnWallmas* pthis, GlobalContext* globalCtx);
void EnWallmas_Walk(EnWallmas* pthis, GlobalContext* globalCtx);

ActorInit En_Wallmas_InitVars = {
    ACTOR_EN_WALLMAS,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_WALLMASTER,
    sizeof(EnWallmas),
    (ActorFunc)EnWallmas_Init,
    (ActorFunc)EnWallmas_Destroy,
    (ActorFunc)EnWallmas_Update,
    (ActorFunc)EnWallmas_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
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
    { 30, 40, 0, { 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 4, 30, 40, 150 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x1),
    /* Normal arrow  */ DMG_ENTRY(2, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(4, 0x2),
    /* Ice arrow     */ DMG_ENTRY(2, 0x0),
    /* Light arrow   */ DMG_ENTRY(4, 0x4),
    /* Unk arrow 1   */ DMG_ENTRY(4, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
    /* Fire magic    */ DMG_ENTRY(4, 0x2),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(4, 0x4),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
    /* Giant spin    */ DMG_ENTRY(4, 0x0),
    /* Master spin   */ DMG_ENTRY(2, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
    /* Giant jump    */ DMG_ENTRY(8, 0x0),
    /* Master jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x30, 1),
    ICHAIN_F32(targetArrowOffset, 5500, 1),
    ICHAIN_F32_DIV1000(gravity, -1500, 0),
};

void EnWallmas_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnWallmas* pthis = (EnWallmas*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);
    ActorShape_Init(&thisx->shape, 0, NULL, 0.5f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gWallmasterSkel, &gWallmasterWaitAnim, pthis->jointTable,
                       pthis->morphTable, 25);

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sCylinderInit);
    CollisionCheck_SetInfo(&thisx->colChkInfo, &sDamageTable, &sColChkInfoInit);
    pthis->switchFlag = (u8)(thisx->params >> 0x8);
    thisx->params = thisx->params & 0xFF;

    if (thisx->params == WMT_FLAG) {
        if (Flags_GetSwitch(globalCtx, pthis->switchFlag) != 0) {
            Actor_Kill(thisx);
            return;
        }

        EnWallmas_ProximityOrSwitchInit(pthis);
    } else if (thisx->params == WMT_PROXIMITY) {
        EnWallmas_ProximityOrSwitchInit(pthis);
    } else {
        EnWallmas_TimerInit(pthis, globalCtx);
    }
}

void EnWallmas_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnWallmas* pthis = (EnWallmas*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnWallmas_TimerInit(EnWallmas* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.flags |= ACTOR_FLAG_5;
    pthis->timer = 0x82;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.world.pos.y = player->actor.world.pos.y;
    pthis->actor.floorHeight = player->actor.floorHeight;
    pthis->actor.draw = EnWallmas_Draw;
    pthis->actionFunc = EnWallmas_WaitToDrop;
}

void EnWallmas_SetupDrop(EnWallmas* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    AnimationHeader* objSegChangee = &gWallmasterLungeAnim;

    Animation_Change(&pthis->skelAnime, objSegChangee, 0.0f, 20.0f, Animation_GetLastFrame(&gWallmasterLungeAnim),
                     ANIMMODE_ONCE, 0.0f);

    pthis->yTarget = player->actor.world.pos.y;
    pthis->actor.world.pos.y = player->actor.world.pos.y + 300.0f;
    pthis->actor.world.rot.y = player->actor.shape.rot.y + 0x8000;
    pthis->actor.floorHeight = player->actor.floorHeight;
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actor.flags &= ~ACTOR_FLAG_5;
    pthis->actionFunc = EnWallmas_Drop;
}

void EnWallmas_SetupLand(EnWallmas* pthis, GlobalContext* globalCtx) {
    AnimationHeader* objSegFrameCount = &gWallmasterJumpAnim;
    AnimationHeader* objSegChangee = &gWallmasterJumpAnim;

    Animation_Change(&pthis->skelAnime, objSegChangee, 1.0f, 41.0f, Animation_GetLastFrame(objSegFrameCount),
                     ANIMMODE_ONCE, -3.0f);

    Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 15.0f, 6, 20.0f, 0x12C, 0x64, 1);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_LAND);
    pthis->actionFunc = EnWallmas_Land;
}

void EnWallmas_SetupStand(EnWallmas* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gWallmasterStandUpAnim);
    pthis->actionFunc = EnWallmas_Stand;
}

void EnWallmas_SetupWalk(EnWallmas* pthis) {
    Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gWallmasterWalkAnim, 3.0f);
    pthis->actionFunc = EnWallmas_Walk;
    pthis->actor.speedXZ = 3.0f;
}

void EnWallmas_SetupJumpToCeiling(EnWallmas* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gWallmasterStopWalkAnim);
    pthis->actionFunc = EnWallmas_JumpToCeiling;
    pthis->actor.speedXZ = 0.0f;
}
void EnWallmas_SetupReturnToCeiling(EnWallmas* pthis) {
    AnimationHeader* objSegFrameCount = &gWallmasterJumpAnim;
    AnimationHeader* objSegChangee = &gWallmasterJumpAnim;

    pthis->timer = 0;
    pthis->actor.speedXZ = 0.0f;

    Animation_Change(&pthis->skelAnime, objSegChangee, 3.0f, 0.0f, Animation_GetLastFrame(objSegFrameCount),
                     ANIMMODE_ONCE, -3.0f);

    pthis->actionFunc = EnWallmas_ReturnToCeiling;
}

void EnWallmas_SetupTakeDamage(EnWallmas* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gWallmasterDamageAnim, -3.0f);
    if (pthis->collider.info.acHitInfo->toucher.dmgFlags & 0x0001F824) {
        pthis->actor.world.rot.y = pthis->collider.base.ac->world.rot.y;
    } else {
        pthis->actor.world.rot.y = Actor_WorldYawTowardActor(&pthis->actor, pthis->collider.base.ac) + 0x8000;
    }

    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0x14);
    pthis->actionFunc = EnWallmas_TakeDamage;
    pthis->actor.speedXZ = 5.0f;
    pthis->actor.velocity.y = 10.0f;
}

void EnWallmas_SetupCooldown(EnWallmas* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gWallmasterRecoverFromDamageAnim);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actionFunc = EnWallmas_Cooldown;
}

void EnWallmas_SetupDie(EnWallmas* pthis, GlobalContext* globalCtx) {
    static Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;

    EffectSsDeadDb_Spawn(globalCtx, &pthis->actor.world.pos, &zeroVec, &zeroVec, 250, -10, 255, 255, 255, 255, 0, 0, 255,
                         1, 9, true);

    Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xC0);
    pthis->actionFunc = EnWallmas_Die;
}

void EnWallmas_SetupTakePlayer(EnWallmas* pthis, GlobalContext* globalCtx) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gWallmasterHoverAnim, -5.0f);
    pthis->timer = -0x1E;
    pthis->actionFunc = EnWallmas_TakePlayer;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;

    pthis->yTarget = pthis->actor.yDistToPlayer;
    func_8002DF38(globalCtx, &pthis->actor, 0x25);
    OnePointCutscene_Init(globalCtx, 9500, 9999, &pthis->actor, MAIN_CAM);
}

void EnWallmas_ProximityOrSwitchInit(EnWallmas* pthis) {
    pthis->timer = 0;
    pthis->actor.draw = NULL;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    if (pthis->actor.params == WMT_PROXIMITY) {
        pthis->actionFunc = EnWallmas_WaitForProximity;
    } else {
        pthis->actionFunc = EnWallmas_WaitForSwitchFlag;
    }
}

void EnWallmas_SetupStun(EnWallmas* pthis) {
    Animation_Change(&pthis->skelAnime, &gWallmasterJumpAnim, 1.5f, 0, 20.0f, ANIMMODE_ONCE, -3.0f);

    pthis->actor.speedXZ = 0.0f;
    if (pthis->actor.colChkInfo.damageEffect == 4) {
        Actor_SetColorFilter(&pthis->actor, -0x8000, 0xFF, 0, 0x50);
    } else {
        Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 0x50);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    }

    pthis->timer = 0x50;
    pthis->actionFunc = EnWallmas_Stun;
}

void EnWallmas_WaitToDrop(EnWallmas* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f* playerPos = &player->actor.world.pos;

    pthis->actor.world.pos = *playerPos;
    pthis->actor.floorHeight = player->actor.floorHeight;
    pthis->actor.floorPoly = player->actor.floorPoly;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if ((player->stateFlags1 & 0x100000) || (player->stateFlags1 & 0x8000000) || !(player->actor.bgCheckFlags & 1) ||
        ((pthis->actor.params == 1) && (320.0f < Math_Vec3f_DistXZ(&pthis->actor.home.pos, playerPos)))) {
        Audio_StopSfxById(NA_SE_EN_FALL_AIM);
        pthis->timer = 0x82;
    }

    if (pthis->timer == 0x50) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_AIM);
    }

    if (pthis->timer == 0) {
        EnWallmas_SetupDrop(pthis, globalCtx);
    }
}

void EnWallmas_Drop(EnWallmas* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (!Player_InCsMode(globalCtx) && !(player->stateFlags2 & 0x10) && (player->invincibilityTimer >= 0) &&
        (pthis->actor.xzDistToPlayer < 30.0f) && (pthis->actor.yDistToPlayer < -5.0f) &&
        (-(f32)(player->cylinder.dim.height + 10) < pthis->actor.yDistToPlayer)) {
        EnWallmas_SetupTakePlayer(pthis, globalCtx);
    }
}

void EnWallmas_Land(EnWallmas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        EnWallmas_SetupStand(pthis);
    }
}

void EnWallmas_Stand(EnWallmas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        EnWallmas_SetupWalk(pthis);
    }

    Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer + 0x8000, 0xB6);
}

void EnWallmas_Walk(EnWallmas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        EnWallmas_SetupJumpToCeiling(pthis);
    }

    Math_ScaledStepToS(&pthis->actor.world.rot.y, (s16)((s32)pthis->actor.yawTowardsPlayer + 0x8000), 0xB6);

    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 12.0f) ||
        Animation_OnFrame(&pthis->skelAnime, 24.0f) || Animation_OnFrame(&pthis->skelAnime, 36.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_WALK);
    }
}

void EnWallmas_JumpToCeiling(EnWallmas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        EnWallmas_SetupReturnToCeiling(pthis);
    }
}

void EnWallmas_ReturnToCeiling(EnWallmas* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->skelAnime.curFrame > 20.0f) {
        pthis->timer += 9;
        pthis->actor.world.pos.y = pthis->actor.world.pos.y + 30.0f;
    }

    if (Animation_OnFrame(&pthis->skelAnime, 20.0f) != 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_UP);
    }

    if (pthis->actor.yDistToPlayer < -900.0f) {
        if (pthis->actor.params == WMT_FLAG) {
            Actor_Kill(&pthis->actor);
            return;
        }

        if (pthis->actor.params == WMT_TIMER ||
            Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) < 200.0f) {
            EnWallmas_TimerInit(pthis, globalCtx);
        } else {
            EnWallmas_ProximityOrSwitchInit(pthis);
        }
    }
}

void EnWallmas_TakeDamage(EnWallmas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        if (pthis->actor.colChkInfo.health == 0) {
            EnWallmas_SetupDie(pthis, globalCtx);
        } else {
            EnWallmas_SetupCooldown(pthis);
        }
    }
    if (Animation_OnFrame(&pthis->skelAnime, 13.0f) != 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
    }

    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.2f);
}

void EnWallmas_Cooldown(EnWallmas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        EnWallmas_SetupReturnToCeiling(pthis);
    }
}

void EnWallmas_Die(EnWallmas* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->actor.scale.x, 0.0f, 0.0015) != 0) {
        Actor_SetScale(&pthis->actor, 0.01f);
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xC0);
        Actor_Kill(&pthis->actor);
    }
    pthis->actor.scale.z = pthis->actor.scale.x;
    pthis->actor.scale.y = pthis->actor.scale.x;
}

void EnWallmas_TakePlayer(EnWallmas* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (Animation_OnFrame(&pthis->skelAnime, 1.0f) != 0) {
        if (!LINK_IS_ADULT) {
            func_8002F7DC(&pthis->actor, NA_SE_VO_LI_DAMAGE_S_KID);
        } else {
            func_8002F7DC(&pthis->actor, NA_SE_VO_LI_DAMAGE_S);
        }

        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_CATCH);
    }
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        player->actor.world.pos.x = pthis->actor.world.pos.x;
        player->actor.world.pos.z = pthis->actor.world.pos.z;

        if (pthis->timer < 0) {
            pthis->actor.world.pos.y = pthis->actor.world.pos.y + 2.0f;
        } else {
            pthis->actor.world.pos.y = pthis->actor.world.pos.y + 10.0f;
        }

        if (!LINK_IS_ADULT) {
            player->actor.world.pos.y = pthis->actor.world.pos.y - 30.0f;
        } else {
            player->actor.world.pos.y = pthis->actor.world.pos.y - 50.0f;
        }

        if (pthis->timer == -0x1E) {
            if (!LINK_IS_ADULT) {
                func_8002F7DC(&pthis->actor, NA_SE_VO_LI_TAKEN_AWAY_KID);
            } else {
                func_8002F7DC(&pthis->actor, NA_SE_VO_LI_TAKEN_AWAY);
            }
        }
        if (pthis->timer == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_UP);
        }

        pthis->timer = pthis->timer + 2;
    } else {
        Math_StepToF(&pthis->actor.world.pos.y, player->actor.world.pos.y + (!LINK_IS_ADULT ? 30.0f : 50.0f), 5.0f);
    }

    Math_StepToF(&pthis->actor.world.pos.x, player->actor.world.pos.x, 3.0f);
    Math_StepToF(&pthis->actor.world.pos.z, player->actor.world.pos.z, 3.0f);

    if (pthis->timer == 0x1E) {
        func_80078884(NA_SE_OC_ABYSS);
        Gameplay_TriggerRespawn(globalCtx);
    }
}

void EnWallmas_WaitForProximity(EnWallmas* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    if (Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) < 200.0f) {
        EnWallmas_TimerInit(pthis, globalCtx);
    }
}

void EnWallmas_WaitForSwitchFlag(EnWallmas* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->switchFlag) != 0) {
        EnWallmas_TimerInit(pthis, globalCtx);
        pthis->timer = 0x51;
    }
}

void EnWallmas_Stun(EnWallmas* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        if (pthis->actor.colChkInfo.health == 0) {
            EnWallmas_SetupDie(pthis, globalCtx);
        } else {
            EnWallmas_SetupReturnToCeiling(pthis);
        }
    }
}

void EnWallmas_ColUpdate(EnWallmas* pthis, GlobalContext* globalCtx) {
    if ((pthis->collider.base.acFlags & AC_HIT) != 0) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);
        if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
            if (Actor_ApplyDamage(&pthis->actor) == 0) {
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_DEAD);
                pthis->actor.flags &= ~ACTOR_FLAG_0;
            } else {
                if (pthis->actor.colChkInfo.damage != 0) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_DAMAGE);
                }
            }

            if ((pthis->actor.colChkInfo.damageEffect == DAMAGE_EFFECT_STUN_WHITE) ||
                (pthis->actor.colChkInfo.damageEffect == DAMAGE_EFFECT_STUN_BLUE)) {
                if (pthis->actionFunc != EnWallmas_Stun) {
                    EnWallmas_SetupStun(pthis);
                }
            } else {
                if (pthis->actor.colChkInfo.damageEffect == DAMAGE_EFFECT_BURN) {
                    EffectSsFCircle_Spawn(globalCtx, &pthis->actor, &pthis->actor.world.pos, 40, 40);
                }

                EnWallmas_SetupTakeDamage(pthis);
            }
        }
    }
}

void EnWallmas_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnWallmas* pthis = (EnWallmas*)thisx;
    char pad[4];

    EnWallmas_ColUpdate(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);

    if ((pthis->actionFunc == EnWallmas_WaitToDrop) || (pthis->actionFunc == EnWallmas_WaitForProximity) ||
        (pthis->actionFunc == EnWallmas_TakePlayer) || (pthis->actionFunc == EnWallmas_WaitForSwitchFlag)) {
        return;
    }

    if ((pthis->actionFunc != EnWallmas_ReturnToCeiling) && (pthis->actionFunc != EnWallmas_TakePlayer)) {
        Actor_MoveForward(&pthis->actor);
    }

    if (pthis->actionFunc != EnWallmas_Drop) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 25.0f, 0.0f, 0x1D);
    } else if (pthis->actor.world.pos.y <= pthis->yTarget) {
        pthis->actor.world.pos.y = pthis->yTarget;
        pthis->actor.velocity.y = 0.0f;
        EnWallmas_SetupLand(pthis, globalCtx);
    }

    if ((pthis->actionFunc != EnWallmas_Die) && (pthis->actionFunc != EnWallmas_Drop)) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

        if ((pthis->actionFunc != EnWallmas_TakeDamage) && (pthis->actor.bgCheckFlags & 1) != 0 &&
            (pthis->actor.freezeTimer == 0)) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }

    Actor_SetFocus(&pthis->actor, 25.0f);

    if (pthis->actionFunc == EnWallmas_TakeDamage) {
        return;
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnWallmas_DrawXlu(EnWallmas* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 xzScale;
    MtxF mf;

    if ((pthis->actor.floorPoly == NULL) || ((pthis->timer >= 0x51) && (pthis->actionFunc != EnWallmas_Stun))) {
        return;
    }

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_wallmas.c", 1386);

    func_80094044(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, 255);

    func_80038A28(pthis->actor.floorPoly, pthis->actor.world.pos.x, pthis->actor.floorHeight, pthis->actor.world.pos.z,
                  &mf);
    Matrix_Mult(&mf, MTXMODE_NEW);

    if ((pthis->actionFunc != EnWallmas_WaitToDrop) && (pthis->actionFunc != EnWallmas_ReturnToCeiling) &&
        (pthis->actionFunc != EnWallmas_TakePlayer) && (pthis->actionFunc != EnWallmas_WaitForSwitchFlag)) {
        xzScale = pthis->actor.scale.x * 50.0f;
    } else {
        xzScale = ((0x50 - pthis->timer) >= 0x51 ? 0x50 : (0x50 - pthis->timer)) * TIMER_SCALE;
    }

    Matrix_Scale(xzScale, 1.0f, xzScale, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_wallmas.c", 1421), G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, gCircleShadowDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_wallmas.c", 1426);
}

s32 EnWallMas_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                               void* thisx) {
    EnWallmas* pthis = (EnWallmas*)thisx;

    if (limbIndex == 1) {
        if (pthis->actionFunc != EnWallmas_TakePlayer) {
            pos->z -= 1600.0f;
        } else {
            pos->z -= ((1600.0f * (pthis->skelAnime.endFrame - pthis->skelAnime.curFrame)) / pthis->skelAnime.endFrame);
        }
    }
    return false;
}

void EnWallMas_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    if (limbIndex == 2) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_wallmas.c", 1478);

        Matrix_Push();
        Matrix_Translate(1600.0f, -700.0f, -1700.0f, MTXMODE_APPLY);
        Matrix_RotateY(DEGREE_60_RAD, MTXMODE_APPLY);
        Matrix_RotateZ(DEGREE_15_RAD, MTXMODE_APPLY);
        Matrix_Scale(2.0f, 2.0f, 2.0f, MTXMODE_APPLY);

        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_wallmas.c", 1489), G_MTX_LOAD);
        gSPDisplayList(POLY_OPA_DISP++, gWallmasterFingerDL);

        Matrix_Pop();

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_wallmas.c", 1495);
    }
}

void EnWallmas_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnWallmas* pthis = (EnWallmas*)thisx;

    if (pthis->actionFunc != EnWallmas_WaitToDrop) {
        func_80093D18(globalCtx->state.gfxCtx);
        SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                              pthis->skelAnime.dListCount, EnWallMas_OverrideLimbDraw, EnWallMas_PostLimbDraw, pthis);
    }

    EnWallmas_DrawXlu(pthis, globalCtx);
}
