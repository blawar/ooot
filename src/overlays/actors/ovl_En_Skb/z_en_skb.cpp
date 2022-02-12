#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SKB_Z_EN_SKB_C
#include "actor_common.h"
#include "z_en_skb.h"
#include "overlays/actors/ovl_En_Encount1/z_en_encount1.h"
#include "objects/object_skb/object_skb.h"
#include "def/code_800FD970.h"
#include "def/sys_math.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)

void EnSkb_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSkb_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSkb_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSkb_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80AFCD60(EnSkb* pthis);
void func_80AFCDF8(EnSkb* pthis);
void func_80AFCE5C(EnSkb* pthis, GlobalContext* globalCtx);
void func_80AFCF48(EnSkb* pthis);
void func_80AFCFF0(EnSkb* pthis, GlobalContext* globalCtx);
void func_80AFD0A4(EnSkb* pthis);
void EnSkb_Advance(EnSkb* pthis, GlobalContext* globalCtx);
void func_80AFD33C(EnSkb* pthis);
void EnSkb_SetupAttack(EnSkb* pthis, GlobalContext* globalCtx);
void func_80AFD47C(EnSkb* pthis);
void func_80AFD508(EnSkb* pthis, GlobalContext* globalCtx);
void EnSkb_SetupStunned(EnSkb* pthis);
void func_80AFD59C(EnSkb* pthis, GlobalContext* globalCtx);
void func_80AFD6CC(EnSkb* pthis, GlobalContext* globalCtx);
void func_80AFD7B4(EnSkb* pthis, GlobalContext* globalCtx);
void func_80AFD880(EnSkb* pthis, GlobalContext* globalCtx);
void func_80AFD968(EnSkb* pthis, GlobalContext* globalCtx);

static ColliderJntSphElementInit sJntSphElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x04 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 15, { { 0, 0, 0 }, 10 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 1, { { 0, 0, 0 }, 20 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT6,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    2,
    sJntSphElementsInit,
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(2, 0xF),
    /* Slingshot     */ DMG_ENTRY(1, 0xF),
    /* Explosive     */ DMG_ENTRY(2, 0xF),
    /* Boomerang     */ DMG_ENTRY(0, 0x1),
    /* Normal arrow  */ DMG_ENTRY(2, 0xF),
    /* Hammer swing  */ DMG_ENTRY(2, 0xF),
    /* Hookshot      */ DMG_ENTRY(0, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(1, 0xE),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
    /* Fire arrow    */ DMG_ENTRY(4, 0x7),
    /* Ice arrow     */ DMG_ENTRY(2, 0xF),
    /* Light arrow   */ DMG_ENTRY(2, 0xF),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0xF),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(4, 0x7),
    /* Ice magic     */ DMG_ENTRY(0, 0x6),
    /* Light magic   */ DMG_ENTRY(3, 0xD),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0xD),
    /* Giant spin    */ DMG_ENTRY(4, 0xF),
    /* Master spin   */ DMG_ENTRY(2, 0xF),
    /* Kokiri jump   */ DMG_ENTRY(2, 0xF),
    /* Giant jump    */ DMG_ENTRY(8, 0xF),
    /* Master jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

ActorInit En_Skb_InitVars = {
    ACTOR_EN_SKB,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SKB,
    sizeof(EnSkb),
    (ActorFunc)EnSkb_Init,
    (ActorFunc)EnSkb_Destroy,
    (ActorFunc)EnSkb_Update,
    (ActorFunc)EnSkb_Draw,
};

void EnSkb_SetupAction(EnSkb* pthis, EnSkbActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnSkb_SpawnDebris(GlobalContext* globalCtx, EnSkb* pthis, Vec3f* spawnPos) {
    Vec3f pos;
    Vec3f vel = { 0.0f, 8.0f, 0.0f };
    Vec3f accel = { 0.0f, -1.5f, 0.0f };
    f32 spreadAngle;
    f32 scale;

    spreadAngle = (Rand_ZeroOne() - 0.5f) * 6.28f;
    pos.y = pthis->actor.floorHeight;
    pos.x = (Math_SinF(spreadAngle) * 15.0f) + spawnPos->x;
    pos.z = (Math_CosF(spreadAngle) * 15.0f) + spawnPos->z;
    accel.x = Rand_CenteredFloat(1.0f);
    accel.z = Rand_CenteredFloat(1.0f);
    vel.y += (Rand_ZeroOne() - 0.5f) * 4.0f;
    scale = (Rand_ZeroOne() * 5.0f) + 12.0f;
    EffectSsHahen_Spawn(globalCtx, &pos, &vel, &accel, 2, scale * 0.8f, -1, 10, 0);
    func_80033480(globalCtx, &pos, 10.0f, 1, 150, 0, 1);
}

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -2000, ICHAIN_STOP),
};

void EnSkb_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnSkb* pthis = (EnSkb*)thisx;
    s16 paramOffsetBody;
    s16 paramOffsetArm;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.colChkInfo.mass = 0xFE;
    pthis->actor.colChkInfo.health = 2;
    pthis->actor.shape.yOffset = -8000.0f;
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gStalchildSkel, &gStalchildUncurlingAnim, pthis->jointTable,
                   pthis->morphTable, 20);
    pthis->actor.naviEnemyId = 0x55;

    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItem);
    Actor_SetScale(&pthis->actor, ((pthis->actor.params * 0.1f) + 1.0f) * 0.01f);

    paramOffsetBody = pthis->actor.params + 0xA;
    pthis->collider.elements[0].dim.worldSphere.radius = paramOffsetBody;
    pthis->collider.elements[0].dim.modelSphere.radius = paramOffsetBody;
    if (1) {};
    paramOffsetArm = (pthis->actor.params * 2) + 0x14;
    pthis->collider.elements[1].dim.worldSphere.radius = paramOffsetArm;
    pthis->collider.elements[1].dim.modelSphere.radius = paramOffsetArm;
    pthis->actor.home.pos = pthis->actor.world.pos;
    pthis->actor.floorHeight = pthis->actor.world.pos.y;
    func_80AFCDF8(pthis);
}

void EnSkb_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnSkb* pthis = (EnSkb*)thisx;

    if (pthis->actor.parent != NULL) {
        EnEncount1* spawner = (EnEncount1*)pthis->actor.parent;

        if (spawner->actor.update != NULL) {
            if (spawner->curNumSpawn > 0) {
                spawner->curNumSpawn--;
            }
        }
    }
    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void func_80AFCD60(EnSkb* pthis) {
    if (IS_DAY) {
        func_80AFCF48(pthis);
    } else if (Actor_IsFacingPlayer(&pthis->actor, 0x11C7) &&
               (pthis->actor.xzDistToPlayer < (60.0f + (pthis->actor.params * 6.0f)))) {
        func_80AFD33C(pthis);
    } else {
        func_80AFD0A4(pthis);
    }
}

void func_80AFCDF8(EnSkb* pthis) {
    Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gStalchildUncurlingAnim, 1.0f);
    pthis->unk_280 = 0;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIVA_APPEAR);
    EnSkb_SetupAction(pthis, func_80AFCE5C);
}

void func_80AFCE5C(EnSkb* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.curFrame < 4.0f) {
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    } else {
        pthis->actor.flags |= ACTOR_FLAG_0;
    }
    Math_SmoothStepToF(&pthis->actor.shape.yOffset, 0.0f, 1.0f, 800.0f, 0.0f);
    Math_SmoothStepToF(&pthis->actor.shape.shadowScale, 25.0f, 1.0f, 2.5f, 0.0f);
    if ((globalCtx->gameplayFrames & 1) != 0) {
        EnSkb_SpawnDebris(globalCtx, pthis, &pthis->actor.world.pos);
    }
    if ((SkelAnime_Update(&pthis->skelAnime) != 0) && (0.0f == pthis->actor.shape.yOffset)) {
        func_80AFCD60(pthis);
    }
}

void func_80AFCF48(EnSkb* pthis) {
    Animation_Change(&pthis->skelAnime, &gStalchildUncurlingAnim, -1.0f,
                     Animation_GetLastFrame(&gStalchildUncurlingAnim), 0.0f, ANIMMODE_ONCE, -4.0f);
    pthis->unk_280 = 0;
    pthis->unk_281 = 0;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_AKINDONUTS_HIDE);
    EnSkb_SetupAction(pthis, func_80AFCFF0);
}

void func_80AFCFF0(EnSkb* pthis, GlobalContext* globalCtx) {
    if ((Math_SmoothStepToF(&pthis->actor.shape.yOffset, -8000.0f, 1.0f, 500.0f, 0.0f) != 0.0f) &&
        (globalCtx->gameplayFrames & 1)) {
        EnSkb_SpawnDebris(globalCtx, pthis, &pthis->actor.world.pos);
    }
    Math_SmoothStepToF(&pthis->actor.shape.shadowScale, 0.0f, 1.0f, 2.5f, 0.0f);
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        Actor_Kill(&pthis->actor);
    }
}

void func_80AFD0A4(EnSkb* pthis) {
    Animation_Change(&pthis->skelAnime, &gStalchildWalkingAnim, 0.96000004f, 0.0f,
                     Animation_GetLastFrame(&gStalchildWalkingAnim), ANIMMODE_LOOP, -4.0f);
    pthis->unk_280 = 4;
    pthis->unk_288 = 0;
    pthis->actor.speedXZ = pthis->actor.scale.y * 160.0f;
    EnSkb_SetupAction(pthis, EnSkb_Advance);
}

void EnSkb_Advance(EnSkb* pthis, GlobalContext* globalCtx) {
    s32 thisKeyFrame;
    s32 prevKeyFrame;
    f32 playSpeed;
    Player* player = GET_PLAYER(globalCtx);

    if ((pthis->unk_283 != 0) && ((globalCtx->gameplayFrames & 0xF) == 0)) {
        pthis->unk_288 = Rand_CenteredFloat(50000.0f);
    }
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, (pthis->actor.yawTowardsPlayer + pthis->unk_288), 1, 0x2EE, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    thisKeyFrame = pthis->skelAnime.curFrame;
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->skelAnime.playSpeed >= 0.0f) {
        playSpeed = pthis->skelAnime.playSpeed;
    } else {
        playSpeed = -pthis->skelAnime.playSpeed;
    }
    prevKeyFrame = (pthis->skelAnime.curFrame - playSpeed);
    if (pthis->skelAnime.playSpeed >= 0.0f) {
        playSpeed = pthis->skelAnime.playSpeed;
    } else {
        playSpeed = -pthis->skelAnime.playSpeed;
    }
    if (thisKeyFrame != (s32)pthis->skelAnime.curFrame) {
        if (((prevKeyFrame < 9) && (((s32)playSpeed + thisKeyFrame) >= 8)) ||
            !((prevKeyFrame >= 16) || (((s32)playSpeed + thisKeyFrame) < 15))) {

            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALKID_WALK);
        }
    }
    if (Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) > 800.0f || IS_DAY) {
        func_80AFCF48(pthis);
    } else if (Actor_IsFacingPlayer(&pthis->actor, 0x11C7) &&
               (pthis->actor.xzDistToPlayer < (60.0f + (pthis->actor.params * 6.0f)))) {
        func_80AFD33C(pthis);
    }
}

void func_80AFD33C(EnSkb* pthis) {
    Animation_Change(&pthis->skelAnime, &gStalchildAttackingAnim, 0.6f, 0.0f,
                     Animation_GetLastFrame(&gStalchildAttackingAnim), ANIMMODE_ONCE_INTERP, 4.0f);
    pthis->collider.base.atFlags &= ~4;
    pthis->unk_280 = 3;
    pthis->actor.speedXZ = 0.0f;
    EnSkb_SetupAction(pthis, EnSkb_SetupAttack);
}

void EnSkb_SetupAttack(EnSkb* pthis, GlobalContext* globalCtx) {
    s32 frameData;

    frameData = pthis->skelAnime.curFrame;
    if (frameData == 3) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALKID_ATTACK);
        pthis->unk_281 = 1;
    } else if (frameData == 6) {
        pthis->unk_281 = 0;
    }
    if (pthis->collider.base.atFlags & 4) {
        pthis->collider.base.atFlags &= ~6;
        func_80AFD47C(pthis);
    } else if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        func_80AFCD60(pthis);
    }
}

void func_80AFD47C(EnSkb* pthis) {
    Animation_Change(&pthis->skelAnime, &gStalchildAttackingAnim, -0.4f, pthis->skelAnime.curFrame - 1.0f, 0.0f,
                     ANIMMODE_ONCE_INTERP, 0.0f);
    pthis->collider.base.atFlags &= ~4;
    pthis->unk_280 = 5;
    pthis->unk_281 = 0;
    EnSkb_SetupAction(pthis, func_80AFD508);
}

void func_80AFD508(EnSkb* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        func_80AFCD60(pthis);
    }
}

void EnSkb_SetupStunned(EnSkb* pthis) {
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.speedXZ = 0.0f;
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->unk_281 = 0;
    pthis->unk_280 = 6;
    EnSkb_SetupAction(pthis, func_80AFD59C);
}

void func_80AFD59C(EnSkb* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 2) {
        pthis->actor.speedXZ = 0.0f;
    }
    if (pthis->actor.bgCheckFlags & 1) {
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ += 0.05f;
        }
    }
    if ((pthis->actor.colorFilterTimer == 0) && (pthis->actor.bgCheckFlags & 1)) {
        if (pthis->actor.colChkInfo.health == 0) {
            func_80AFD7B4(pthis, globalCtx);
        } else {
            func_80AFCD60(pthis);
        }
    }
}

void func_80AFD644(EnSkb* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gStalchildDamagedAnim, -4.0f);
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.speedXZ = -4.0f;
    }
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STALKID_DAMAGE);
    pthis->unk_280 = 2;
    EnSkb_SetupAction(pthis, func_80AFD6CC);
}

void func_80AFD6CC(EnSkb* pthis, GlobalContext* globalCtx) {
    // pthis cast is likely not real, but allows for a match
    u8* new_var;

    new_var = &pthis->unk_283;
    if ((pthis->unk_283 != 1) || BodyBreak_SpawnParts(&pthis->actor, &pthis->bodyBreak, globalCtx, 1)) {
        if ((*new_var) != 0) {
            pthis->unk_283 = (*new_var) | 2;
        }
        if (pthis->actor.bgCheckFlags & 2) {
            pthis->actor.speedXZ = 0;
        }
        if (pthis->actor.bgCheckFlags & 1) {
            if (pthis->actor.speedXZ < 0.0f) {
                pthis->actor.speedXZ += 0.05f;
            }
        }

        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x1194, 0);
        if (SkelAnime_Update(&pthis->skelAnime) && (pthis->actor.bgCheckFlags & 1)) {
            func_80AFCD60(pthis);
        }
    }
}

void func_80AFD7B4(EnSkb* pthis, GlobalContext* globalCtx) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gStalchildDyingAnim, -4.0f);
    pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.speedXZ = -6.0f;
    }
    pthis->unk_280 = 1;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    BodyBreak_Alloc(&pthis->bodyBreak, 18, globalCtx);
    pthis->unk_283 |= 4;
    EffectSsDeadSound_SpawnStationary(globalCtx, &pthis->actor.projectedPos, NA_SE_EN_STALKID_DEAD, 1, 1, 0x28);
    EnSkb_SetupAction(pthis, func_80AFD880);
}

void func_80AFD880(EnSkb* pthis, GlobalContext* globalCtx) {
    if (BodyBreak_SpawnParts(&pthis->actor, &pthis->bodyBreak, globalCtx, 1)) {
        if (pthis->actor.scale.x == 0.01f) {
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x10);
        } else if (pthis->actor.scale.x <= 0.015f) {
            Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_RUPEE_BLUE);
        } else {
            Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_RUPEE_RED);
            Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_RUPEE_RED);
            Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_RUPEE_RED);
        }

        pthis->unk_283 |= 8;
        Actor_Kill(&pthis->actor);
    }
}

void func_80AFD968(EnSkb* pthis, GlobalContext* globalCtx) {
    s16 pad;
    s32 i;
    Vec3f flamePos;
    s16 scale;
    s16 phi_v1;
    Player* player;

    if ((pthis->unk_280 != 1) && (pthis->actor.bgCheckFlags & 0x60) && (pthis->actor.yDistToWater >= 40.0f)) {
        pthis->actor.colChkInfo.health = 0;
        pthis->unk_281 = 0;
        func_80AFD7B4(pthis, globalCtx);
    } else if (pthis->unk_280 >= 3) {
        if ((pthis->collider.base.acFlags & 2) != 0) {
            pthis->collider.base.acFlags &= ~2;
            if (pthis->actor.colChkInfo.damageEffect != 6) {
                pthis->unk_282 = pthis->actor.colChkInfo.damageEffect;
                Actor_SetDropFlag(&pthis->actor, &pthis->collider.elements[1].info, 1);
                pthis->unk_281 = 0;
                if (pthis->actor.colChkInfo.damageEffect == 1) {
                    if (pthis->unk_280 != 6) {
                        Actor_SetColorFilter(&pthis->actor, 0, 0x78, 0, 0x50);
                        Actor_ApplyDamage(&pthis->actor);
                        EnSkb_SetupStunned(pthis);
                    }
                } else {
                    phi_v1 = 8;
                    if (pthis->actor.colChkInfo.damageEffect == 7) {
                        scale = pthis->actor.scale.y * 7500.0f;
                        for (i = 4; i >= 0; i--) {
                            flamePos = pthis->actor.world.pos;
                            flamePos.x += Rand_CenteredFloat(20.0f);
                            flamePos.z += Rand_CenteredFloat(20.0f);
                            flamePos.y += (Rand_ZeroOne() * 25.0f);
                            EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &flamePos, scale, 0, 0, -1);
                        }
                        phi_v1 = 25;
                    }
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, phi_v1);
                    if (!Actor_ApplyDamage(&pthis->actor)) {
                        func_80AFD7B4(pthis, globalCtx);
                        return;
                    }
                    player = GET_PLAYER(globalCtx);
                    if (pthis->unk_283 == 0) {
                        if ((pthis->actor.colChkInfo.damageEffect == 0xD) ||
                            ((pthis->actor.colChkInfo.damageEffect == 0xE) &&
                             ((player->swordAnimation >= 4 && player->swordAnimation <= 11) ||
                              (player->swordAnimation == 20 || player->swordAnimation == 21)))) {
                            BodyBreak_Alloc(&pthis->bodyBreak, 2, globalCtx);
                            pthis->unk_283 = 1;
                        }
                    }
                    func_80AFD644(pthis);
                }
            }
        }
    }
}

void EnSkb_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnSkb* pthis = (EnSkb*)thisx;
    s32 pad;

    func_80AFD968(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 15.0f, 30.0f, 60.0f, 0x1D);
    pthis->actionFunc(pthis, globalCtx);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += (3000.0f * pthis->actor.scale.y);
    if (pthis->unk_281 != 0) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    if (pthis->unk_280 >= 3) {
        if ((pthis->actor.colorFilterTimer == 0) || ((pthis->actor.colorFilterParams & 0x4000) == 0)) {

            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

s32 EnSkb_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnSkb* pthis = (EnSkb*)thisx;
    s16 color;
    s16 pad[2];

    if (limbIndex == 11) {
        if ((pthis->unk_283 & 2) == 0) {
            OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_skb.c", 972);
            color = ABS((s16)(Math_SinS((globalCtx->gameplayFrames * 0x1770)) * 95.0f)) + 160;
            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetEnvColor(POLY_OPA_DISP++, color, color, color, 255);
            CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_skb.c", 978);
        } else {
            *dList = NULL;
        }
    } else if ((limbIndex == 12) && ((pthis->unk_283 & 2) != 0)) {
        *dList = NULL;
    }
    return 0;
}

void EnSkb_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnSkb* pthis = (EnSkb*)thisx;

    Collider_UpdateSpheres(limbIndex, &pthis->collider);

    if ((pthis->unk_283 ^ 1) == 0) {
        BodyBreak_SetInfo(&pthis->bodyBreak, limbIndex, 11, 12, 18, dList, BODYBREAK_OBJECT_DEFAULT);
    } else if ((pthis->unk_283 ^ (pthis->unk_283 | 4)) == 0) {
        BodyBreak_SetInfo(&pthis->bodyBreak, limbIndex, 0, 18, 18, dList, BODYBREAK_OBJECT_DEFAULT);
    }
}

void EnSkb_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnSkb* pthis = (EnSkb*)thisx;
    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnSkb_OverrideLimbDraw,
                      EnSkb_PostLimbDraw, &pthis->actor);
}
