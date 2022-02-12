#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SB_Z_EN_SB_C
#include "actor_common.h"
/*
 * File: z_en_sb.c
 * Overlay: ovl_En_Sb
 * Description: Shellblade
 */

#include "z_en_sb.h"
#include "vt.h"
#include "objects/object_sb/object_sb.h"
#include "def/code_8006BA00.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnSb_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSb_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSb_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSb_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnSb_SetupWaitClosed(EnSb* pthis);

void EnSb_WaitClosed(EnSb* pthis, GlobalContext* globalCtx);
void EnSb_Open(EnSb* pthis, GlobalContext* globalCtx);
void EnSb_WaitOpen(EnSb* pthis, GlobalContext* globalCtx);
void EnSb_TurnAround(EnSb* pthis, GlobalContext* globalCtx);
void EnSb_Lunge(EnSb* pthis, GlobalContext* globalCtx);
void EnSb_Bounce(EnSb* pthis, GlobalContext* globalCtx);
void EnSb_Cooldown(EnSb* pthis, GlobalContext* globalCtx);

ActorInit En_Sb_InitVars = {
    ACTOR_EN_SB,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SB,
    sizeof(EnSb),
    (ActorFunc)EnSb_Init,
    (ActorFunc)EnSb_Destroy,
    (ActorFunc)EnSb_Update,
    (ActorFunc)EnSb_Draw,
};

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        COLSHAPE_CYLINDER,
    },
    { 0x00, { 0xFFCFFFFF, 0x04, 0x08 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
    { 30, 40, 0, { 0, 0, 0 } },
};

static DamageTable sDamageTable[] = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(0, 0x0),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0xF),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(2, 0xF),
    /* Hammer swing  */ DMG_ENTRY(2, 0xF),
    /* Hookshot      */ DMG_ENTRY(2, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(1, 0xD),
    /* Master sword  */ DMG_ENTRY(2, 0xD),
    /* Giant's Knife */ DMG_ENTRY(4, 0xD),
    /* Fire arrow    */ DMG_ENTRY(4, 0x2),
    /* Ice arrow     */ DMG_ENTRY(2, 0xF),
    /* Light arrow   */ DMG_ENTRY(2, 0xF),
    /* Unk arrow 1   */ DMG_ENTRY(4, 0xE),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0xF),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0xF),
    /* Fire magic    */ DMG_ENTRY(4, 0x2),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0xD),
    /* Giant spin    */ DMG_ENTRY(4, 0xD),
    /* Master spin   */ DMG_ENTRY(2, 0xD),
    /* Kokiri jump   */ DMG_ENTRY(2, 0xD),
    /* Giant jump    */ DMG_ENTRY(8, 0xD),
    /* Master jump   */ DMG_ENTRY(4, 0xD),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x27, ICHAIN_CONTINUE),
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 30, ICHAIN_STOP),
};

static Vec3f sFlamePosOffsets[] = {
    { 5.0f, 0.0f, 0.0f },
    { -5.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 5.0f },
    { 0.0f, 0.0f, -5.0f },
};

typedef enum {
    /* 0x00 */ SHELLBLADE_OPEN,
    /* 0x01 */ SHELLBLADE_WAIT_CLOSED,
    /* 0x02 */ SHELLBLADE_WAIT_OPEN,
    /* 0x03 */ SHELLBLADE_LUNGE,
    /* 0x04 */ SHELLBLADE_BOUNCE
} ShellbladeBehavior;

void EnSb_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnSb* pthis = (EnSb*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.colChkInfo.damageTable = sDamageTable;
    pthis->actor.colChkInfo.health = 2;
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_sb_Skel_002BF0, &object_sb_Anim_000194, NULL, NULL, 0);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->isDead = false;
    pthis->actor.colChkInfo.mass = 0;
    Actor_SetScale(&pthis->actor, 0.006f);
    pthis->actor.shape.rot.y = 0;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.gravity = -0.35f;
    pthis->fire = 0;
    pthis->hitByWindArrow = false;
    pthis->actor.velocity.y = -1.0f;
    EnSb_SetupWaitClosed(pthis);
}

void EnSb_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnSb* pthis = (EnSb*)thisx;
    SkelAnime_Free(&pthis->skelAnime, globalCtx);
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnSb_SpawnBubbles(GlobalContext* globalCtx, EnSb* pthis) {
    s32 i;

    if (pthis->actor.yDistToWater > 0) {
        for (i = 0; i < 10; i++) {
            EffectSsBubble_Spawn(globalCtx, &pthis->actor.world.pos, 10.0f, 10.0f, 30.0f, 0.25f);
        }
    }
}

void EnSb_SetupWaitClosed(EnSb* pthis) {
    Animation_Change(&pthis->skelAnime, &object_sb_Anim_00004C, 1.0f, 0, Animation_GetLastFrame(&object_sb_Anim_00004C),
                     ANIMMODE_ONCE, 0.0f);
    pthis->behavior = SHELLBLADE_WAIT_CLOSED;
    pthis->actionFunc = EnSb_WaitClosed;
}

void EnSb_SetupOpen(EnSb* pthis) {
    Animation_Change(&pthis->skelAnime, &object_sb_Anim_000194, 1.0f, 0, Animation_GetLastFrame(&object_sb_Anim_000194),
                     ANIMMODE_ONCE, 0.0f);
    pthis->behavior = SHELLBLADE_OPEN;
    pthis->actionFunc = EnSb_Open;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHELL_MOUTH);
}

void EnSb_SetupWaitOpen(EnSb* pthis) {
    Animation_Change(&pthis->skelAnime, &object_sb_Anim_002C8C, 1.0f, 0, Animation_GetLastFrame(&object_sb_Anim_002C8C),
                     ANIMMODE_LOOP, 0.0f);
    pthis->behavior = SHELLBLADE_WAIT_OPEN;
    pthis->actionFunc = EnSb_WaitOpen;
}

void EnSb_SetupLunge(EnSb* pthis) {
    f32 frameCount = Animation_GetLastFrame(&object_sb_Anim_000124);
    f32 playbackSpeed = pthis->actor.yDistToWater > 0.0f ? 1.0f : 0.0f;

    Animation_Change(&pthis->skelAnime, &object_sb_Anim_000124, playbackSpeed, 0.0f, frameCount, ANIMMODE_ONCE, 0);
    pthis->behavior = SHELLBLADE_LUNGE;
    pthis->actionFunc = EnSb_Lunge;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHELL_MOUTH);
}

void EnSb_SetupBounce(EnSb* pthis) {
    Animation_Change(&pthis->skelAnime, &object_sb_Anim_0000B4, 1.0f, 0, Animation_GetLastFrame(&object_sb_Anim_0000B4),
                     ANIMMODE_ONCE, 0.0f);
    pthis->behavior = SHELLBLADE_BOUNCE;
    pthis->actionFunc = EnSb_Bounce;
}

void EnSb_SetupCooldown(EnSb* pthis, s32 changeSpeed) {
    f32 frameCount = Animation_GetLastFrame(&object_sb_Anim_00004C);

    if (pthis->behavior != SHELLBLADE_WAIT_CLOSED) {
        Animation_Change(&pthis->skelAnime, &object_sb_Anim_00004C, 1.0f, 0, frameCount, ANIMMODE_ONCE, 0.0f);
    }
    pthis->behavior = SHELLBLADE_WAIT_CLOSED;
    if (changeSpeed) {
        if (pthis->actor.yDistToWater > 0.0f) {
            pthis->actor.speedXZ = -5.0f;
            if (pthis->actor.velocity.y < 0.0f) {
                pthis->actor.velocity.y = 2.1f;
            }
        } else {
            pthis->actor.speedXZ = -6.0f;
            if (pthis->actor.velocity.y < 0.0f) {
                pthis->actor.velocity.y = 1.4f;
            }
        }
    }
    pthis->timer = 60;
    pthis->actionFunc = EnSb_Cooldown;
}

void EnSb_WaitClosed(EnSb* pthis, GlobalContext* globalCtx) {
    // always face toward link
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0xA, 0x7D0, 0x0);

    if ((pthis->actor.xzDistToPlayer <= 160.0f) && (pthis->actor.xzDistToPlayer > 40.0f)) {
        EnSb_SetupOpen(pthis);
    }
}

void EnSb_Open(EnSb* pthis, GlobalContext* globalCtx) {
    f32 currentFrame = pthis->skelAnime.curFrame;

    if (Animation_GetLastFrame(&object_sb_Anim_000194) <= currentFrame) {
        pthis->timer = 15;
        EnSb_SetupWaitOpen(pthis);
    } else {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0xA, 0x7D0, 0x0);
        if ((pthis->actor.xzDistToPlayer > 160.0f) || (pthis->actor.xzDistToPlayer <= 40.0f)) {
            EnSb_SetupWaitClosed(pthis);
        }
    }
}

void EnSb_WaitOpen(EnSb* pthis, GlobalContext* globalCtx) {
    s16 timer = pthis->timer;

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0xA, 0x7D0, 0x0);

    if ((pthis->actor.xzDistToPlayer > 160.0f) || (pthis->actor.xzDistToPlayer <= 40.0f)) {
        EnSb_SetupWaitClosed(pthis);
    }

    if (timer != 0) {
        pthis->timer = timer - 1;
    } else {
        pthis->timer = 0;
        pthis->attackYaw = pthis->actor.yawTowardsPlayer;
        pthis->actionFunc = EnSb_TurnAround;
    }
}

void EnSb_TurnAround(EnSb* pthis, GlobalContext* globalCtx) {
    s16 invertedYaw;

    invertedYaw = pthis->attackYaw + 0x8000;
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, invertedYaw, 0x1, 0x1F40, 0xA);

    if (pthis->actor.shape.rot.y == invertedYaw) {
        pthis->actor.world.rot.y = pthis->attackYaw;
        if (pthis->actor.yDistToWater > 0.0f) {
            pthis->actor.velocity.y = 3.0f;
            pthis->actor.speedXZ = 5.0f;
            pthis->actor.gravity = -0.35f;
        } else {
            pthis->actor.velocity.y = 2.0f;
            pthis->actor.speedXZ = 6.0f;
            pthis->actor.gravity = -2.0f;
        }
        EnSb_SpawnBubbles(globalCtx, pthis);
        pthis->bouncesLeft = 3;
        EnSb_SetupLunge(pthis);
        // "Attack!!"
        osSyncPrintf("アタァ〜ック！！\n");
    }
}

void EnSb_Lunge(EnSb* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.2f);
    if ((pthis->actor.velocity.y <= -0.1f) || ((pthis->actor.bgCheckFlags & 2))) {
        if (!(pthis->actor.yDistToWater > 0.0f)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        }
        pthis->actor.bgCheckFlags = pthis->actor.bgCheckFlags & ~2;
        EnSb_SetupBounce(pthis);
    }
}

void EnSb_Bounce(EnSb* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 currentFrame;
    f32 frameCount;

    currentFrame = pthis->skelAnime.curFrame;
    frameCount = Animation_GetLastFrame(&object_sb_Anim_0000B4);
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.2f);

    if (currentFrame == frameCount) {
        if (pthis->bouncesLeft != 0) {
            pthis->bouncesLeft--;
            pthis->timer = 1;
            if (pthis->actor.yDistToWater > 0.0f) {
                pthis->actor.velocity.y = 3.0f;
                pthis->actor.speedXZ = 5.0f;
                pthis->actor.gravity = -0.35f;
            } else {
                pthis->actor.velocity.y = 2.0f;
                pthis->actor.speedXZ = 6.0f;
                pthis->actor.gravity = -2.0f;
            }
            EnSb_SpawnBubbles(globalCtx, pthis);
            EnSb_SetupLunge(pthis);
        } else if (pthis->actor.bgCheckFlags & 1) {
            pthis->actor.bgCheckFlags &= ~2;
            pthis->actor.speedXZ = 0.0f;
            pthis->timer = 1;
            EnSb_SetupWaitClosed(pthis);
            osSyncPrintf(VT_FGCOL(RED) "攻撃終了！！" VT_RST "\n"); // "Attack Complete!"
        }
    }
}

void EnSb_Cooldown(EnSb* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
        if (pthis->actor.bgCheckFlags & 1) {
            pthis->actor.bgCheckFlags &= ~1;
            pthis->actor.speedXZ = 0.0f;
        }
    } else {
        if (pthis->actor.bgCheckFlags & 1) {
            pthis->actor.bgCheckFlags &= ~1;
            pthis->actionFunc = EnSb_WaitClosed;
            pthis->actor.speedXZ = 0.0f;
        }
    }
}

s32 EnSb_IsVulnerable(EnSb* pthis) {
    switch (pthis->behavior) {
        case SHELLBLADE_OPEN:
            if ((pthis->skelAnime.curFrame >= 2.0f) && (pthis->skelAnime.curFrame <= 5.0f)) {
                return true;
            }
            break;
        case SHELLBLADE_WAIT_CLOSED:
            if ((pthis->skelAnime.curFrame >= 0.0f) && (pthis->skelAnime.curFrame <= 1.0f)) {
                return true;
            }
            break;
        case SHELLBLADE_WAIT_OPEN:
            if ((pthis->skelAnime.curFrame >= 0.0f) && (pthis->skelAnime.curFrame <= 19.0f)) {
                return true;
            }
            break;
        case SHELLBLADE_LUNGE:
            if (pthis->skelAnime.curFrame == 0.0f) {
                return true;
            }
            break;
        case SHELLBLADE_BOUNCE:
            if ((pthis->skelAnime.curFrame >= 3.0f) && (pthis->skelAnime.curFrame <= 5.0f)) {
                return true;
            }
            break;
    }
    return false;
}

s32 EnSb_UpdateDamage(EnSb* pthis, GlobalContext* globalCtx) {
    Vec3f hitPoint;
    f32 hitY;
    s16 yawDiff;
    s32 tookDamage;
    u8 hitByWindArrow;

    // hit box collided, switch to cool down
    if ((pthis->collider.base.atFlags & AT_HIT)) {
        EnSb_SetupCooldown(pthis, 1);
        return 1;
    }

    // hurt box collided, take damage if appropriate
    if ((pthis->collider.base.acFlags & AC_HIT)) {
        hitByWindArrow = false;
        tookDamage = false;
        pthis->collider.base.acFlags &= ~AC_HIT;

        switch (pthis->actor.colChkInfo.damageEffect) {
            case 14: // wind arrow
                hitByWindArrow = true;
            case 15: // explosions, arrow, hammer, ice arrow, light arrow, spirit arrow, shadow arrow
                if (EnSb_IsVulnerable(pthis)) {
                    hitY = pthis->collider.info.bumper.hitPos.y - pthis->actor.world.pos.y;
                    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
                    if ((hitY < 30.0f) && (hitY > 10.0f) && (yawDiff >= -0x1FFF) && (yawDiff < 0x2000)) {
                        Actor_ApplyDamage(&pthis->actor);
                        Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, 0x50);
                        tookDamage = true;
                    }
                }
                break;
            case 2: // fire arrow, dins fire
                pthis->fire = 4;
                Actor_ApplyDamage(&pthis->actor);
                Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, 0x50);
                tookDamage = true;
                break;
            case 1:  // hookshot/longshot
            case 13: // all sword damage
                if (EnSb_IsVulnerable(pthis)) {
                    hitY = pthis->collider.info.bumper.hitPos.y - pthis->actor.world.pos.y;
                    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
                    if ((hitY < 30.0f) && (hitY > 10.0f) && (yawDiff >= -0x1FFF) && (yawDiff < 0x2000)) {
                        Actor_ApplyDamage(&pthis->actor);
                        Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, 0x50);
                        tookDamage = true;
                        EnSb_SetupCooldown(pthis, 0);
                    }
                }
                break;
            default:
                break;
        }
        if (pthis->actor.colChkInfo.health == 0) {
            pthis->hitByWindArrow = hitByWindArrow;
            BodyBreak_Alloc(&pthis->bodyBreak, 8, globalCtx);
            pthis->isDead = true;
            Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EN_SHELL_DEAD);
            return 1;
        }

        // if player attack didn't do damage, play recoil sound and spawn sparks
        if (!tookDamage) {
            hitPoint.x = pthis->collider.info.bumper.hitPos.x;
            hitPoint.y = pthis->collider.info.bumper.hitPos.y;
            hitPoint.z = pthis->collider.info.bumper.hitPos.z;
            CollisionCheck_SpawnShieldParticlesMetal2(globalCtx, &hitPoint);
        }
    }

    return 0;
}

void EnSb_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnSb* pthis = (EnSb*)thisx;
    s32 pad;

    if (pthis->isDead) {
        if (pthis->actor.yDistToWater > 0.0f) {
            pthis->actor.params = 4;
        } else {
            pthis->actor.params = 1;
        }
        if (BodyBreak_SpawnParts(&pthis->actor, &pthis->bodyBreak, globalCtx, pthis->actor.params)) {
            if (!pthis->hitByWindArrow) {
                Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x80);
            } else {
                Item_DropCollectible(globalCtx, &pthis->actor.world.pos, 8);
            }
            Actor_Kill(&pthis->actor);
        }
    } else {
        Actor_SetFocus(&pthis->actor, 20.0f);
        Actor_SetScale(&pthis->actor, 0.006f);
        Actor_MoveForward(&pthis->actor);
        pthis->actionFunc(pthis, globalCtx);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 20.0f, 5);
        EnSb_UpdateDamage(pthis, globalCtx);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        SkelAnime_Update(&pthis->skelAnime);
    }
}

void EnSb_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnSb* pthis = (EnSb*)thisx;

    BodyBreak_SetInfo(&pthis->bodyBreak, limbIndex, 0, 6, 8, dList, BODYBREAK_OBJECT_DEFAULT);
}

void EnSb_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnSb* pthis = (EnSb*)thisx;
    Vec3f flamePos;
    Vec3f* offset;
    s16 fireDecr;

    func_8002EBCC(&pthis->actor, globalCtx, 1);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, EnSb_PostLimbDraw, pthis);
    if (pthis->fire != 0) {
        pthis->actor.colorFilterTimer++;
        fireDecr = pthis->fire - 1;
        // pthis is intended to draw flames after being burned, but the condition is never met to run pthis code
        // fire gets set to 4 when burned, decrements to 3 and fails the "& 1" check and never stores the decrement
        if ((fireDecr & 1) == 0) {
            offset = &sFlamePosOffsets[(fireDecr & 3)];
            flamePos.x = Rand_CenteredFloat(5.0f) + (pthis->actor.world.pos.x + offset->x);
            flamePos.y = Rand_CenteredFloat(5.0f) + (pthis->actor.world.pos.y + offset->y);
            flamePos.z = Rand_CenteredFloat(5.0f) + (pthis->actor.world.pos.z + offset->z);
            EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &flamePos, 100, 0, 0, -1);
        }
    }
}
