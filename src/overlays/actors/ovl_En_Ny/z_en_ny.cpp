#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_NY_Z_EN_NY_C
#include "actor_common.h"
#include "z_en_ny.h"
#include "objects/object_ny/object_ny.h"
#include "def/code_800FCE80.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnNy_Init(Actor* thisx, GlobalContext* globalCtx);
void EnNy_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnNy_Update(Actor* thisx, GlobalContext* globalCtx);
void EnNy_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnNy_UpdateUnused(Actor* thisx, GlobalContext* globalCtx);
void EnNy_Move(EnNy* pthis, GlobalContext* globalCtx);
void EnNy_Die(EnNy* pthis, GlobalContext* globalCtx);
void func_80ABCD40(EnNy* pthis);
void func_80ABCDBC(EnNy* pthis);
void EnNy_TurnToStone(EnNy* pthis, GlobalContext* globalCtx);
void func_80ABD11C(EnNy* pthis, GlobalContext* globalCtx);
void func_80ABCE50(EnNy* pthis, GlobalContext* globalCtx);
void func_80ABCE90(EnNy* pthis, GlobalContext* globalCtx);
void func_80ABCEEC(EnNy* pthis, GlobalContext* globalCtx);
void EnNy_UpdateDeath(Actor* thisx, GlobalContext* GlobalContext);
void EnNy_SetupDie(EnNy* pthis, GlobalContext* globalCtx);
void EnNy_DrawDeathEffect(Actor* thisx, GlobalContext* GlobalContext);
void func_80ABD3B8(EnNy* pthis, f32, f32);

ActorInit En_Ny_InitVars = {
    ACTOR_EN_NY,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_NY,
    sizeof(EnNy),
    (ActorFunc)EnNy_Init,
    (ActorFunc)EnNy_Destroy,
    (ActorFunc)EnNy_Update,
    (ActorFunc)EnNy_Draw,
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x04, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 15 }, 100 },
    },
};

static ColliderJntSphInit sColliderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(0, 0x0),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0xF),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(2, 0xF),
    /* Hammer swing  */ DMG_ENTRY(2, 0xF),
    /* Hookshot      */ DMG_ENTRY(2, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(0, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
    /* Fire arrow    */ DMG_ENTRY(4, 0x2),
    /* Ice arrow     */ DMG_ENTRY(2, 0xF),
    /* Light arrow   */ DMG_ENTRY(2, 0xF),
    /* Unk arrow 1   */ DMG_ENTRY(4, 0xE),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(4, 0x2),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(0, 0x0),
    /* Giant spin    */ DMG_ENTRY(4, 0xF),
    /* Master spin   */ DMG_ENTRY(2, 0xF),
    /* Kokiri jump   */ DMG_ENTRY(0, 0x0),
    /* Giant jump    */ DMG_ENTRY(8, 0xF),
    /* Master jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x28, ICHAIN_CONTINUE),
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 30, ICHAIN_STOP),
};

void EnNy_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnNy* pthis = (EnNy*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    pthis->actor.colChkInfo.health = 2;
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sColliderInit, pthis->elements);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 20.0f);
    pthis->unk_1CA = 0;
    pthis->unk_1D0 = 0;
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.shape.rot.y = 0;
    pthis->actor.gravity = -0.4f;
    pthis->hitPlayer = 0;
    pthis->unk_1CE = 2;
    pthis->actor.velocity.y = 0.0f;
    pthis->unk_1D4 = 0xFF;
    pthis->unk_1D8 = 0;
    pthis->unk_1E8 = 0.0f;
    pthis->unk_1E0 = 0.25f;
    if (pthis->actor.params == 0) {
        // "New initials"
        osSyncPrintf("ニュウ イニシャル[ %d ] ！！\n", pthis->actor.params);
        pthis->actor.colChkInfo.mass = 0;
        pthis->unk_1D4 = 0;
        pthis->unk_1D8 = 0xFF;
        pthis->unk_1E0 = 1.0f;
        func_80ABCDBC(pthis);
    } else {
        // This mode is unused in the final game
        // "Dummy new initials"
        osSyncPrintf("ダミーニュウ イニシャル[ %d ] ！！\n", pthis->actor.params);
        osSyncPrintf("En_Ny_actor_move2[ %x ] ！！\n", EnNy_UpdateUnused);
        pthis->actor.colChkInfo.mass = 0xFF;
        pthis->collider.base.colType = COLTYPE_METAL;
        pthis->actor.update = EnNy_UpdateUnused;
    }
}

void EnNy_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnNy* pthis = (EnNy*)thisx;
    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void func_80ABCD40(EnNy* pthis) {
    f32 temp;

    temp = (pthis->actor.yDistToWater > 0.0f) ? 0.7f : 1.0f;
    pthis->unk_1E8 = 2.8f * temp;
}

void func_80ABCD84(EnNy* pthis) {
    pthis->actionFunc = func_80ABCE50;
}

void func_80ABCD94(EnNy* pthis) {
    pthis->stoneTimer = 0x14;
    pthis->actionFunc = func_80ABCE90;
}

void func_80ABCDAC(EnNy* pthis) {
    pthis->actionFunc = func_80ABCEEC;
}

void func_80ABCDBC(EnNy* pthis) {
    pthis->unk_1F4 = 0.0f;
    func_80ABCD40(pthis);
    pthis->stoneTimer = 180;
    pthis->actionFunc = EnNy_Move;
}

void EnNy_SetupTurnToStone(EnNy* pthis) {
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NYU_HIT_STOP);
    pthis->actionFunc = EnNy_TurnToStone;
    pthis->unk_1E8 = 0.0f;
}

void func_80ABCE38(EnNy* pthis) {
    pthis->stoneTimer = 0x3C;
    pthis->actionFunc = func_80ABD11C;
}

void func_80ABCE50(EnNy* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.xyzDistToPlayerSq <= 25600.0f) {
        func_80ABCD94(pthis);
    }
}

void func_80ABCE90(EnNy* pthis, GlobalContext* globalCtx) {
    s32 phi_v1;
    s32 phi_v0;

    phi_v1 = pthis->unk_1D4 - 0x40;
    phi_v0 = pthis->unk_1D8 + 0x40;
    if (phi_v0 >= 0xFF) {
        phi_v1 = 0;
        phi_v0 = 0xFF;
        func_80ABCDAC(pthis);
    }
    pthis->unk_1D4 = phi_v1;
    pthis->unk_1D8 = phi_v0;
}

void func_80ABCEEC(EnNy* pthis, GlobalContext* globalCtx) {
    f32 phi_f0;

    phi_f0 = pthis->unk_1E0;
    phi_f0 += 2.0f;
    if (phi_f0 >= 1.0f) {
        phi_f0 = 1.0f;
        func_80ABCDBC(pthis);
    }
    pthis->unk_1E0 = phi_f0;
}

void EnNy_Move(EnNy* pthis, GlobalContext* globalCtx) {
    f32 yawDiff;
    s32 stoneTimer;

    if (!(pthis->unk_1F0 < pthis->actor.yDistToWater)) {
        func_8002F974(&pthis->actor, NA_SE_EN_NYU_MOVE - SFX_FLAG);
    }
    func_80ABCD40(pthis);
    stoneTimer = pthis->stoneTimer;
    pthis->stoneTimer--;
    if ((stoneTimer <= 0) || (pthis->hitPlayer != false)) {
        EnNy_SetupTurnToStone(pthis);
    } else {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0xA, pthis->unk_1F4, 0);
        Math_ApproachF(&pthis->unk_1F4, 2000.0f, 1.0f, 100.0f);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        yawDiff = Math_FAtan2F(pthis->actor.yDistToPlayer, pthis->actor.xzDistToPlayer);
        pthis->actor.speedXZ = fabsf(cosf(yawDiff) * pthis->unk_1E8);
        if (pthis->unk_1F0 < pthis->actor.yDistToWater) {
            pthis->unk_1EC = sinf(yawDiff) * pthis->unk_1E8;
        }
    }
}

void EnNy_TurnToStone(EnNy* pthis, GlobalContext* globalCtx) {
    f32 phi_f0;

    phi_f0 = pthis->unk_1E0;
    phi_f0 -= 2.0f;
    if (phi_f0 <= 0.25f) {
        phi_f0 = 0.25f;
        if (pthis->actor.bgCheckFlags & 2) {
            if (!(pthis->unk_1F0 < pthis->actor.yDistToWater)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
            }
            pthis->actor.bgCheckFlags &= ~2;
            pthis->actor.speedXZ = 0.0f;
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
            func_80ABCE38(pthis);
        }
    }
    pthis->unk_1E0 = phi_f0;
}

void func_80ABD11C(EnNy* pthis, GlobalContext* globalCtx) {
    s32 phi_v0;
    s32 phi_v1;

    phi_v0 = pthis->unk_1D4;
    phi_v0 += 0x40;
    phi_v1 = pthis->unk_1D8;
    phi_v1 -= 0x40;
    if (phi_v0 >= 0xFF) {
        phi_v0 = 0xFF;
        phi_v1 = 0;
        if (pthis->stoneTimer != 0) {
            pthis->stoneTimer--;
        } else {
            func_80ABCD84(pthis);
        }
    }
    pthis->unk_1D4 = phi_v0;
    pthis->unk_1D8 = phi_v1;
}

s32 EnNy_CollisionCheck(EnNy* pthis, GlobalContext* globalCtx) {
    u8 sp3F;
    Vec3f effectPos;

    sp3F = 0;
    pthis->hitPlayer = 0;
    if (pthis->collider.base.atFlags & 4) {
        pthis->collider.base.atFlags &= ~4;
        pthis->hitPlayer = 1;
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actor.speedXZ = -4.0f;
        return 0;
    }
    if (pthis->collider.base.atFlags & 2) {
        pthis->collider.base.atFlags &= ~2;
        pthis->hitPlayer = 1;
        return 0;
    } else {
        if (pthis->collider.base.acFlags & 2) {
            pthis->collider.base.acFlags &= ~2;
            effectPos.x = pthis->collider.elements[0].info.bumper.hitPos.x;
            effectPos.y = pthis->collider.elements[0].info.bumper.hitPos.y;
            effectPos.z = pthis->collider.elements[0].info.bumper.hitPos.z;
            if ((pthis->unk_1E0 == 0.25f) && (pthis->unk_1D4 == 0xFF)) {
                switch (pthis->actor.colChkInfo.damageEffect) {
                    case 0xE:
                        sp3F = 1;
                    case 0xF:
                        Actor_ApplyDamage(&pthis->actor);
                        Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, 0x50);
                        break;
                    case 1:
                        Actor_ApplyDamage(&pthis->actor);
                        Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, 0x50);
                        break;
                    case 2:
                        pthis->unk_1CA = 4;
                        Actor_ApplyDamage(&pthis->actor);
                        Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, 0x50);
                        break;
                }
            }
            pthis->stoneTimer = 0;
            if (pthis->actor.colChkInfo.health == 0) {
                pthis->actor.shape.shadowAlpha = 0;
                pthis->actor.flags &= ~ACTOR_FLAG_0;
                pthis->unk_1D0 = sp3F;
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                return 1;
            }
            EffectSsHitMark_SpawnFixedScale(globalCtx, 0, &effectPos);
            return 0;
        }
    }
    return 0;
}

void func_80ABD3B8(EnNy* pthis, f32 arg1, f32 arg2) {
    if (pthis->unk_1E8 == 0.0f) {
        pthis->actor.gravity = -0.4f;
    } else if (!(arg1 < pthis->actor.yDistToWater)) {
        pthis->actor.gravity = -0.4f;
    } else if (arg2 < pthis->actor.yDistToWater) {
        pthis->actor.gravity = 0.0;
        if (pthis->unk_1EC < pthis->actor.velocity.y) {
            pthis->actor.velocity.y -= 0.4f;
            if (pthis->actor.velocity.y < pthis->unk_1EC) {
                pthis->actor.velocity.y = pthis->unk_1EC;
            }
        } else if (pthis->actor.velocity.y < pthis->unk_1EC) {
            pthis->actor.velocity.y += 0.4f;
            if (pthis->unk_1EC < pthis->actor.velocity.y) {
                pthis->actor.velocity.y = pthis->unk_1EC;
            }
        }
    }
}

void EnNy_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnNy* pthis = (EnNy*)thisx;
    f32 temp_f20;
    f32 temp_f22;
    s32 i;

    pthis->timer++;
    temp_f20 = pthis->unk_1E0 - 0.25f;
    if (pthis->unk_1CA != 0) {
        pthis->unk_1CA--;
    }
    Actor_SetFocus(&pthis->actor, 0.0f);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->collider.elements[0].dim.scale = 1.33f * temp_f20 + 1.0f;
    temp_f22 = (24.0f * temp_f20) + 12.0f;
    pthis->actor.shape.rot.x += (s16)(pthis->unk_1E8 * 1000.0f);
    func_80ABD3B8(pthis, temp_f22 + 10.0f, temp_f22 - 10.0f);
    Actor_MoveForward(&pthis->actor);
    Math_StepToF(&pthis->unk_1E4, pthis->unk_1E8, 0.1f);
    pthis->actionFunc(pthis, globalCtx);
    pthis->actor.prevPos.y -= temp_f22;
    pthis->actor.world.pos.y -= temp_f22;
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 60.0f, 7);
    pthis->unk_1F0 = temp_f22;
    pthis->actor.world.pos.y += temp_f22;
    if (EnNy_CollisionCheck(pthis, globalCtx) != 0) {
        for (i = 0; i < 8; i++) {
            pthis->unk_1F8[i].x = (Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x);
            pthis->unk_1F8[i].y = (Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.y);
            pthis->unk_1F8[i].z = (Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z);
        }
        pthis->timer = 0;
        pthis->actor.update = EnNy_UpdateDeath;
        pthis->actor.draw = EnNy_DrawDeathEffect;
        pthis->actionFunc = EnNy_SetupDie;
        return;
    }
    if (pthis->unk_1E0 > 0.25f) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnNy_SetupDie(EnNy* pthis, GlobalContext* globalCtx) {
    s32 effectScale;
    s32 i;
    Vec3f effectPos;
    Vec3f effectVelocity = { 0.0f, 0.0f, 0.0f };
    Vec3f effectAccel = { 0.0f, 0.1f, 0.0f };

    if (pthis->timer >= 2) {
        if (pthis->actor.yDistToWater > 0.0f) {
            for (i = 0; i < 10; i++) {
                effectPos.x = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.x;
                effectPos.y = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.y;
                effectPos.z = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.z;
                effectScale = Rand_S16Offset(0x50, 0x64);
                EffectSsDtBubble_SpawnColorProfile(globalCtx, &effectPos, &effectVelocity, &effectAccel, effectScale,
                                                   25, 0, 1);
            }
            for (i = 0; i < 0x14; i++) {
                effectPos.x = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.x;
                effectPos.y = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.y;
                effectPos.z = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.z;
                EffectSsBubble_Spawn(globalCtx, &effectPos, 10.0f, 10.0f, 30.0f, 0.25f);
            }
        }
        for (i = 0; i < 8; i++) {
            pthis->unk_1F8[i + 8].x = Rand_CenteredFloat(10.0f);
            pthis->unk_1F8[i + 8].z = Rand_CenteredFloat(10.0f);
            pthis->unk_1F8[i + 8].y = Rand_ZeroFloat(4.0f) + 4.0f;
        }
        pthis->timer = 0;
        if (pthis->unk_1D0 == 0) {
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xA0);
        } else {
            Item_DropCollectible(globalCtx, &pthis->actor.world.pos, 8);
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NYU_DEAD);
        pthis->actionFunc = EnNy_Die;
    }
}

void EnNy_Die(EnNy* pthis, GlobalContext* globalCtx) {
    s32 i;

    if (pthis->actor.yDistToWater > 0.0f) {
        for (i = 0; i < 8; i += 1) {
            pthis->unk_1F8[i].x += pthis->unk_1F8[i + 8].x;
            pthis->unk_1F8[i].y += pthis->unk_1F8[i + 8].y;
            pthis->unk_1F8[i].z += pthis->unk_1F8[i + 8].z;
            Math_StepToF(&pthis->unk_1F8[i + 8].x, 0.0f, 0.1f);
            Math_StepToF(&pthis->unk_1F8[i + 8].y, -1.0f, 0.4f);
            Math_StepToF(&pthis->unk_1F8[i + 8].z, 0.0f, 0.1f);
        }
        if (pthis->timer >= 0x1F) {
            Actor_Kill(&pthis->actor);
            return;
        }
    } else {
        for (i = 0; i < 8; i += 1) {
            pthis->unk_1F8[i].x += pthis->unk_1F8[i + 8].x;
            pthis->unk_1F8[i].y += pthis->unk_1F8[i + 8].y;
            pthis->unk_1F8[i].z += pthis->unk_1F8[i + 8].z;
            Math_StepToF(&pthis->unk_1F8[i + 8].x, 0.0f, 0.15f);
            Math_StepToF(&pthis->unk_1F8[i + 8].y, -1.0f, 0.6f);
            Math_StepToF(&pthis->unk_1F8[i + 8].z, 0.0f, 0.15f);
        }
        if (pthis->timer >= 0x10) {
            Actor_Kill(&pthis->actor);
            return;
        }
    }
}

void EnNy_UpdateDeath(Actor* thisx, GlobalContext* globalCtx) {
    EnNy* pthis = (EnNy*)thisx;

    pthis->timer++;
    if (pthis->unk_1CA != 0) {
        pthis->unk_1CA--;
    }
    pthis->actionFunc(pthis, globalCtx);
}

void EnNy_UpdateUnused(Actor* thisx, GlobalContext* globalCtx2) {
    EnNy* pthis = (EnNy*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    f32 sp3C;
    f32 temp_f0;

    sp3C = pthis->unk_1E0 - 0.25f;
    pthis->timer++;
    Actor_SetFocus(&pthis->actor, 0.0f);
    Actor_SetScale(&pthis->actor, 0.01f);
    temp_f0 = (24.0f * sp3C) + 12.0f;
    pthis->actor.prevPos.y -= temp_f0;
    pthis->actor.world.pos.y -= temp_f0;

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 60.0f, 7);
    pthis->unk_1F0 = temp_f0;
    pthis->actor.world.pos.y += temp_f0;

    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_MoveForward(&pthis->actor);
    Math_StepToF(&pthis->unk_1E4, pthis->unk_1E8, 0.1f);
}
static Vec3f sFireOffsets[] = {
    { 5.0f, 0.0f, 0.0f },
    { -5.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 5.0f },
    { 0.0f, 0.0f, -5.0f },
};

void EnNy_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnNy* pthis = (EnNy*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ny.c", 837);
    Collider_UpdateSpheres(0, &pthis->collider);
    func_8002ED80(&pthis->actor, globalCtx, 1);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ny.c", 845),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetRenderMode(POLY_XLU_DISP++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->unk_1D8);
    gSPDisplayList(POLY_XLU_DISP++, gEnNyMetalBodyDL);
    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetRenderMode(POLY_XLU_DISP++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->unk_1D4);
    gSPDisplayList(POLY_XLU_DISP++, gEnNyRockBodyDL);
    if (pthis->unk_1E0 > 0.25f) {
        Matrix_Scale(pthis->unk_1E0, pthis->unk_1E0, pthis->unk_1E0, MTXMODE_APPLY);
        func_8002EBCC(&pthis->actor, globalCtx, 1);
        func_80093D18(globalCtx->state.gfxCtx);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ny.c", 868),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gEnNySpikeDL);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ny.c", 872);
    if (pthis->unk_1CA != 0) {
        Vec3f tempVec;
        Vec3f* fireOffset;
        s16 temp;

        temp = pthis->unk_1CA - 1;
        pthis->actor.colorFilterTimer++;
        if (temp == 0) {
            fireOffset = &sFireOffsets[temp & 3];
            tempVec.x = Rand_CenteredFloat(5.0f) + (pthis->actor.world.pos.x + fireOffset->x);
            tempVec.y = Rand_CenteredFloat(5.0f) + (pthis->actor.world.pos.y + fireOffset->y);
            tempVec.z = Rand_CenteredFloat(5.0f) + (pthis->actor.world.pos.z + fireOffset->z);
            EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &tempVec, 100, 0, 0, -1);
        }
    }
}

void EnNy_DrawDeathEffect(Actor* thisx, GlobalContext* globalCtx) {
    EnNy* pthis = (EnNy*)thisx;
    Vec3f* temp;
    f32 scale;
    s32 i;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ny.c", 900);
    func_80093D18(globalCtx->state.gfxCtx);
    gDPSetEnvColor(POLY_OPA_DISP++, 0x00, 0x00, 0x00, 0xFF);
    gDPSetRenderMode(POLY_OPA_DISP++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);
    gDPPipeSync(POLY_OPA_DISP++);
    for (i = 0; i < 8; i++) {
        if (pthis->timer < (i + 22)) {
            temp = &pthis->unk_1F8[i];
            Matrix_Translate(temp->x, temp->y, temp->z, MTXMODE_NEW);
            scale = pthis->actor.scale.x * 0.4f * (1.0f + (i * 0.04f));
            Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ny.c", 912),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gEnNyRockBodyDL);
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ny.c", 919);
    if (pthis->unk_1CA != 0) {
        Vec3f tempVec;
        Vec3f* fireOffset;
        s16 fireOffsetIndex;

        fireOffsetIndex = pthis->unk_1CA - 1;
        pthis->actor.colorFilterTimer++;
        if ((fireOffsetIndex & 1) == 0) {
            fireOffset = &sFireOffsets[fireOffsetIndex & 3];
            tempVec.x = Rand_CenteredFloat(5.0f) + (pthis->actor.world.pos.x + fireOffset->x);
            tempVec.y = Rand_CenteredFloat(5.0f) + (pthis->actor.world.pos.y + fireOffset->y);
            tempVec.z = Rand_CenteredFloat(5.0f) + (pthis->actor.world.pos.z + fireOffset->z);
            EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &tempVec, 100, 0, 0, -1);
        }
    }
}
