#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DHA_Z_EN_DHA_C
#include "actor_common.h"
/*
 * File: z_en_dha.c
 * Overlay: ovl_En_Dha
 * Description: Dead Hand's Hand
 */

#include "z_en_dha.h"
#include "overlays/actors/ovl_En_Dh/z_en_dh.h"
#include "objects/object_dh/object_dh.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)

void EnDha_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDha_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnDha_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDha_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDha_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDha_SetupWait(EnDha* pthis);
void EnDha_Wait(EnDha* pthis, GlobalContext* globalCtx);
void EnDha_SetupTakeDamage(EnDha* pthis);
void EnDha_TakeDamage(EnDha* pthis, GlobalContext* globalCtx);
void EnDha_SetupDeath(EnDha* pthis);
void EnDha_Die(EnDha* pthis, GlobalContext* globalCtx);
void EnDha_UpdateHealth(EnDha* pthis, GlobalContext* globalCtx);

ActorInit En_Dha_InitVars = {
    ACTOR_EN_DHA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DH,
    sizeof(EnDha),
    (ActorFunc)EnDha_Init,
    (ActorFunc)EnDha_Destroy,
    (ActorFunc)EnDha_Update,
    (ActorFunc)EnDha_Draw,
    (ActorFunc)EnDha_Reset,
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(2, 0xF),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(0, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(0, 0x0),
    /* Hammer swing  */ DMG_ENTRY(0, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(2, 0xF),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
    /* Fire arrow    */ DMG_ENTRY(0, 0x0),
    /* Ice arrow     */ DMG_ENTRY(0, 0x0),
    /* Light arrow   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(2, 0xF),
    /* Giant spin    */ DMG_ENTRY(4, 0xF),
    /* Master spin   */ DMG_ENTRY(2, 0xF),
    /* Kokiri jump   */ DMG_ENTRY(4, 0xF),
    /* Giant jump    */ DMG_ENTRY(8, 0xF),
    /* Master jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static ColliderJntSphElementInit sJntSphElementsInit[] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 1, { { 0, 0, 0 }, 12 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 2, { { 3200, 0, 0 }, 10 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 3, { { 1200, 0, 0 }, 10 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 4, { { 2700, 0, 0 }, 10 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 5, { { 1200, 0, 0 }, 10 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT6,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER | OC1_TYPE_1,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    5,
    sJntSphElementsInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x2E, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_STOP),
};

void EnDha_SetupAction(EnDha* pthis, EnDhaActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnDha_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDha* pthis = (EnDha*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_dh_Skel_000BD8, &object_dh_Anim_0015B0, pthis->jointTable,
                       pthis->morphTable, 4);
    ActorShape_Init(&pthis->actor.shape, 0, ActorShadow_DrawFeet, 90.0f);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 50.0f;
    pthis->actor.colChkInfo.mass = MASS_HEAVY;
    pthis->actor.colChkInfo.health = 8;
    pthis->limbAngleX[0] = -0x4000;
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItem);
    pthis->actor.flags &= ~ACTOR_FLAG_0;

    EnDha_SetupWait(pthis);
}

void EnDha_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDha* pthis = (EnDha*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnDha_SetupWait(EnDha* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &object_dh_Anim_0015B0);
    pthis->unk_1C0 = 0;
    pthis->actionTimer = ((Rand_ZeroOne() * 10.0f) + 5.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actor.home.rot.z = 1;
    EnDha_SetupAction(pthis, EnDha_Wait);
}

void EnDha_Wait(EnDha* pthis, GlobalContext* globalCtx) {
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f }; // unused
    Vec3f armPosMultiplier1 = { 0.0f, 0.0f, 55.0f };
    Vec3f armPosMultiplier2 = { 0.0f, 0.0f, -54.0f };
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    s32 pad2;
    Vec3f playerPos = player->actor.world.pos;
    Vec3s angle;
    s16 yaw;

    playerPos.x += Math_SinS(player->actor.shape.rot.y) * -5.0f;
    playerPos.z += Math_CosS(player->actor.shape.rot.y) * -5.0f;

    if (!LINK_IS_ADULT) {
        playerPos.y += 38.0f;
    } else {
        playerPos.y += 56.0f;
    }

    if (pthis->actor.xzDistToPlayer <= 100.0f) {
        pthis->handAngle.y = pthis->handAngle.x = pthis->limbAngleY = 0;

        if (Math_Vec3f_DistXYZ(&playerPos, &pthis->handPos[0]) <= 12.0f) {
            if (pthis->unk_1CC == 0) {
                if (globalCtx->grabPlayer(globalCtx, player)) {
                    pthis->timer = 0;
                    pthis->unk_1CC++;

                    if (pthis->actor.parent != NULL) {
                        pthis->actor.parent->params = ENDH_START_ATTACK_GRAB;
                    }

                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_GRIP);
                }
            } else {
                pthis->timer += 0x1194;
                pthis->limbAngleY = Math_SinS(pthis->timer) * 1820.0f;

                if (!(player->stateFlags2 & 0x80)) {
                    pthis->unk_1CC = 0;
                    EnDha_SetupTakeDamage(pthis);
                    return;
                }

                if (pthis->timer < -0x6E6B) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_GRIP);
                }
            }

            func_80035844(&pthis->handPos[1], &playerPos, &pthis->handAngle, 0);
            pthis->handAngle.y -= pthis->actor.shape.rot.y + pthis->limbAngleY;
            pthis->handAngle.x -= pthis->actor.shape.rot.x + pthis->limbAngleX[0] + pthis->limbAngleX[1];
        } else {
            if ((player->stateFlags2 & 0x80) && (&pthis->actor == player->actor.parent)) {
                player->stateFlags2 &= ~0x80;
                player->actor.parent = NULL;
                player->unk_850 = 200;
            }

            if (pthis->actor.home.rot.z != 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_HAND_AT);
                pthis->actor.home.rot.z = 0;
            }
        }

        pthis->actor.shape.rot.y = Math_Vec3f_Yaw(&pthis->actor.world.pos, &playerPos);

        Math_SmoothStepToF(&pthis->handPos[0].x, playerPos.x, 1.0f, 16.0f, 0.0f);
        Math_SmoothStepToF(&pthis->handPos[0].y, playerPos.y, 1.0f, 16.0f, 0.0f);
        Math_SmoothStepToF(&pthis->handPos[0].z, playerPos.z, 1.0f, 16.0f, 0.0f);

        func_80035844(&pthis->armPos, &pthis->handPos[0], &angle, 0);
        Matrix_Translate(pthis->handPos[0].x, pthis->handPos[0].y, pthis->handPos[0].z, MTXMODE_NEW);
        Matrix_RotateZYX(angle.x, angle.y, 0, MTXMODE_APPLY);
        Matrix_MultVec3f(&armPosMultiplier2, &pthis->armPos);
        Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
        func_80035844(&pthis->actor.world.pos, &pthis->armPos, &angle, 0);
        Matrix_RotateZYX(angle.x, angle.y, 0, MTXMODE_APPLY);
        Matrix_MultVec3f(&armPosMultiplier1, &pthis->armPos);
        pthis->limbAngleX[0] = Math_Vec3f_Pitch(&pthis->actor.world.pos, &pthis->armPos);
        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->armPos) - pthis->actor.shape.rot.y;

        if (ABS(yaw) >= 0x4000) {
            pthis->limbAngleX[0] = -0x8000 - pthis->limbAngleX[0];
        }

        pthis->limbAngleX[1] = (Math_Vec3f_Pitch(&pthis->armPos, &pthis->handPos[0]) - pthis->limbAngleX[0]);

        if (pthis->limbAngleX[1] < 0) {
            pthis->limbAngleX[0] += pthis->limbAngleX[1] * 2;
            pthis->limbAngleX[1] *= -2;
        }
    } else {
        if ((player->stateFlags2 & 0x80) && (&pthis->actor == player->actor.parent)) {
            player->stateFlags2 &= ~0x80;
            player->actor.parent = NULL;
            player->unk_850 = 200;
        }

        pthis->actor.home.rot.z = 1;
        Math_SmoothStepToS(&pthis->limbAngleX[1], 0, 1, 0x3E8, 0);
        Math_SmoothStepToS(&pthis->limbAngleX[0], -0x4000, 1, 0x3E8, 0);
        SkelAnime_Update(&pthis->skelAnime);
    }
}

void EnDha_SetupTakeDamage(EnDha* pthis) {
    pthis->actionTimer = 15;
    EnDha_SetupAction(pthis, EnDha_TakeDamage);
}

void EnDha_TakeDamage(EnDha* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((player->stateFlags2 & 0x80) && (&pthis->actor == player->actor.parent)) {
        player->stateFlags2 &= ~0x80;
        player->actor.parent = NULL;
        player->unk_850 = 200;
    }

    Math_SmoothStepToS(&pthis->limbAngleX[1], 0, 1, 2000, 0);
    Math_SmoothStepToS(&pthis->limbAngleY, 0, 1, 600, 0);
    Math_SmoothStepToS(&pthis->limbAngleX[0], -0x4000, 1, 2000, 0);
    SkelAnime_Update(&pthis->skelAnime);
    pthis->actionTimer--;

    if (pthis->actionTimer == 0) {
        EnDha_SetupWait(pthis);
    }
}

void EnDha_SetupDeath(EnDha* pthis) {
    pthis->unk_1C0 = 8;
    pthis->actionTimer = 300;

    if (pthis->actor.parent != NULL) {
        if (pthis->actor.parent->params != ENDH_DEATH) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_HAND_DEAD);
        }
        if (pthis->actor.parent->params <= ENDH_WAIT_UNDERGROUND) {
            pthis->actor.parent->params--;
        }
    }

    EnDha_SetupAction(pthis, EnDha_Die);
}

void EnDha_Die(EnDha* pthis, GlobalContext* globalCtx) {
    s16 angle;
    Vec3f vec;
    Player* player = GET_PLAYER(globalCtx);

    if ((player->stateFlags2 & 0x80) && (&pthis->actor == player->actor.parent)) {
        player->stateFlags2 &= ~0x80;
        player->actor.parent = NULL;
        player->unk_850 = 200;
    }

    Math_SmoothStepToS(&pthis->limbAngleX[1], 0, 1, 0x7D0, 0);
    angle = Math_SmoothStepToS(&pthis->limbAngleX[0], -0x4000, 1, 0x7D0, 0);
    SkelAnime_Update(&pthis->skelAnime);

    if (angle == 0) {
        vec = pthis->actor.world.pos;

        if (pthis->actionTimer != 0) {
            if (-12000.0f < pthis->actor.shape.yOffset) {
                pthis->actor.shape.yOffset -= 1000.0f;
                func_80033480(globalCtx, &vec, 7.0f, 1, 0x5A, 0x14, 1);
            } else {
                pthis->actionTimer--;

                if ((pthis->actor.parent != NULL) && (pthis->actor.parent->params == ENDH_DEATH)) {
                    Actor_Kill(&pthis->actor);
                }
            }
        } else {
            pthis->actor.shape.yOffset += 500.0f;
            func_80033480(globalCtx, &vec, 7.0f, 1, 0x5A, 0x14, 1);

            if (pthis->actor.shape.yOffset == 0.0f) {
                EnDha_SetupWait(pthis);
            }
        }
    }
}

void EnDha_UpdateHealth(EnDha* pthis, GlobalContext* globalCtx) {
    if (!((pthis->unk_1C0 >= 8) || !(pthis->collider.base.acFlags & AC_HIT))) {
        pthis->collider.base.acFlags &= ~AC_HIT;

        if (pthis->actor.colChkInfo.damageEffect == 0 || pthis->actor.colChkInfo.damageEffect == 6) {
            return;
        } else {
            Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
            if (Actor_ApplyDamage(&pthis->actor) == 0) {
                EnDha_SetupDeath(pthis);
                pthis->actor.colChkInfo.health = 8;
                Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xE0);
            } else {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_DAMAGE);
                pthis->unk_1C0 = 9;
                EnDha_SetupTakeDamage(pthis);
            }
        }
    }

    if ((pthis->actor.parent != NULL) && (pthis->actor.parent->params == ENDH_DEATH)) {
        EnDha_SetupDeath(pthis);
    }
}

void EnDha_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDha* pthis = (EnDha*)thisx;

    if (pthis->actor.parent == NULL) {
        pthis->actor.parent = Actor_FindNearby(globalCtx, &pthis->actor, ACTOR_EN_DH, ACTORCAT_ENEMY, 10000.0f);
    }

    EnDha_UpdateHealth(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

s32 EnDha_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnDha* pthis = (EnDha*)thisx;

    if (limbIndex == 1) {
        rot->y = -(s16)(pthis->limbAngleX[0] + 0x4000);
        rot->z += pthis->limbAngleY;
    } else if (limbIndex == 2) {
        rot->z = pthis->limbAngleX[1];
        rot->y -= pthis->limbAngleY;
    } else if (limbIndex == 3) {
        rot->y = -pthis->handAngle.y;
        rot->z = -pthis->handAngle.x;
    }

    return false;
}

void EnDha_OverridePostDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    Vec3f handVec = { 1100.0f, 0.0f, 0.0f };
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    EnDha* pthis = (EnDha*)thisx;

    switch (limbIndex) {
        case 1:
            Collider_UpdateSpheres(2, &pthis->collider);
            Collider_UpdateSpheres(3, &pthis->collider);
            break;
        case 2:
            Collider_UpdateSpheres(4, &pthis->collider);
            Collider_UpdateSpheres(5, &pthis->collider);
            Matrix_MultVec3f(&zeroVec, &pthis->armPos);
            break;
        case 3:
            Collider_UpdateSpheres(1, &pthis->collider);
            Matrix_MultVec3f(&handVec, &pthis->handPos[0]);
            Matrix_MultVec3f(&zeroVec, &pthis->handPos[1]);
            break;
    }
}

void EnDha_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDha* pthis = (EnDha*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnDha_OverrideLimbDraw, EnDha_OverridePostDraw, pthis);
}

void EnDha_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Dha_InitVars = {
        ACTOR_EN_DHA,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_DH,
        sizeof(EnDha),
        (ActorFunc)EnDha_Init,
        (ActorFunc)EnDha_Destroy,
        (ActorFunc)EnDha_Update,
        (ActorFunc)EnDha_Draw,
        (ActorFunc)EnDha_Reset,
    };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, 0x0),
        /* Deku stick    */ DMG_ENTRY(2, 0xF),
        /* Slingshot     */ DMG_ENTRY(0, 0x0),
        /* Explosive     */ DMG_ENTRY(0, 0x0),
        /* Boomerang     */ DMG_ENTRY(0, 0x0),
        /* Normal arrow  */ DMG_ENTRY(0, 0x0),
        /* Hammer swing  */ DMG_ENTRY(0, 0x0),
        /* Hookshot      */ DMG_ENTRY(0, 0x0),
        /* Kokiri sword  */ DMG_ENTRY(2, 0xF),
        /* Master sword  */ DMG_ENTRY(2, 0xF),
        /* Giant's Knife */ DMG_ENTRY(4, 0xF),
        /* Fire arrow    */ DMG_ENTRY(0, 0x0),
        /* Ice arrow     */ DMG_ENTRY(0, 0x0),
        /* Light arrow   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
        /* Fire magic    */ DMG_ENTRY(0, 0x0),
        /* Ice magic     */ DMG_ENTRY(0, 0x0),
        /* Light magic   */ DMG_ENTRY(0, 0x0),
        /* Shield        */ DMG_ENTRY(0, 0x0),
        /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
        /* Kokiri spin   */ DMG_ENTRY(2, 0xF),
        /* Giant spin    */ DMG_ENTRY(4, 0xF),
        /* Master spin   */ DMG_ENTRY(2, 0xF),
        /* Kokiri jump   */ DMG_ENTRY(4, 0xF),
        /* Giant jump    */ DMG_ENTRY(8, 0xF),
        /* Master jump   */ DMG_ENTRY(4, 0xF),
        /* Unknown 1     */ DMG_ENTRY(0, 0x0),
        /* Unblockable   */ DMG_ENTRY(0, 0x0),
        /* Hammer jump   */ DMG_ENTRY(4, 0xF),
        /* Unknown 2     */ DMG_ENTRY(0, 0x0),
    };

    sJntSphInit = {
        {
            COLTYPE_HIT6,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_PLAYER | OC1_TYPE_1,
            OC2_TYPE_1,
            COLSHAPE_JNTSPH,
        },
        5,
        sJntSphElementsInit,
    };

}
