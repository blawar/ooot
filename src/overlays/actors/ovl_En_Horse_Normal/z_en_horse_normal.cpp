#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HORSE_NORMAL_Z_EN_HORSE_NORMAL_C
#include "actor_common.h"
/*
 * File: z_en_horse_normal.c
 * Overlay: ovl_En_Horse_Normal
 * Description: Non-rideable horses (Lon Lon Ranch and Stable)
 */

#include "z_en_horse_normal.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_horse_normal/object_horse_normal.h"
#include "def/audio_bank.h"
#include "def/math_float.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "def/z_skin.h"
#include "def/z_skin_awb.h"
#include "def/z_skin_matrix.h"

#define FLAGS 0


void EnHorseNormal_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHorseNormal_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnHorseNormal_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHorseNormal_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHorseNormal_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A6B91C(EnHorseNormal* pthis, GlobalContext* globalCtx);
void func_80A6BC48(EnHorseNormal* pthis);
void func_80A6BCEC(EnHorseNormal* pthis);
void func_80A6C4CC(EnHorseNormal* pthis);
void func_80A6C6B0(EnHorseNormal* pthis);

static s32 D_80A6D4C0_50[] = { 0, 16 };

static f32 D_80A6D4C8_51[] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.5f, 1.5f, 1.5f, 1.5f, 1.0f };

static s32 D_80A6D4F4_62[] = { 0, 1, 4, 5, 6, 2, 3 };

static s32 D_80A6D510_62[] = { 0, 0, 2, 2, 1, 1, 1, 3, 3 };


ActorInit En_Horse_Normal_InitVars = {
    ACTOR_EN_HORSE_NORMAL,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HORSE_NORMAL,
    sizeof(EnHorseNormal),
    (ActorFunc)EnHorseNormal_Init,
    (ActorFunc)EnHorseNormal_Destroy,
    (ActorFunc)EnHorseNormal_Update,
    (ActorFunc)EnHorseNormal_Draw,
    (ActorFunc)EnHorseNormal_Reset,
};

static AnimationHeader* sAnimations[] = {
    &gHorseNormalIdleAnim,      &gHorseNormalWhinnyAnim,  &gHorseNormalRefuseAnim,
    &gHorseNormalRearingAnim,   &gHorseNormalWalkingAnim, &gHorseNormalTrottingAnim,
    &gHorseNormalGallopingAnim, &gHorseNormalJumpingAnim, &gHorseNormalJumpingHighAnim,
};

static ColliderCylinderInit sCylinderInit1 = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 40, 100, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sCylinderInit2 = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 60, 100, 0, { 0, 0, 0 } },
};

static ColliderJntSphElementInit sJntSphElementsInit[] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 11, { { 0, 0, 0 }, 20 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(sJntSphElementsInit),
    sJntSphElementsInit,
};

static CollisionCheckInfoInit sColChkInfoInit = { 10, 35, 100, MASS_HEAVY };

// Unused
static EnHorseNormalUnkStruct1 D_80A6D428[] = {
    { { 1058, 1, 384 }, 7 },    { { 1653, 39, -381 }, 6 }, { { 1606, 1, -1048 }, 6 }, { { 1053, 1, -1620 }, 6 },
    { { -1012, 1, -1633 }, 7 }, { { -1655, 1, -918 }, 6 }, { { -1586, 1, -134 }, 6 }, { { -961, 1, 403 }, 7 },
};

// Unused
static EnHorseNormalUnkStruct2 D_80A6D468 = { ARRAY_COUNT(D_80A6D428), D_80A6D428 };

// Unused
static EnHorseNormalUnkStruct1 D_80A6D470[] = {
    { { 88, 0, 2078 }, 10 },       { { 2482, 376, 4631 }, 7 },    { { 2228, -28, 6605 }, 12 },
    { { 654, -100, 8864 }, 7 },    { { -297, -500, 10667 }, 12 }, { { -5303, -420, 10640 }, 10 },
    { { -6686, -500, 7760 }, 10 }, { { -5260, 100, 5411 }, 7 },   { { -3573, -269, 3893 }, 10 },
};

// Unused
static EnHorseNormalUnkStruct2 D_80A6D4B8 = { ARRAY_COUNT(D_80A6D470), D_80A6D470 };

void func_80A6B250(EnHorseNormal* pthis) {

    if (D_80A6D4C0_50[pthis->unk_200] < pthis->skin.skelAnime.curFrame &&
        ((pthis->unk_200 != 0) || !(D_80A6D4C0_50[1] < pthis->skin.skelAnime.curFrame))) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_WALK, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &gReverbAdd2);
        pthis->unk_200++;
        if (pthis->unk_200 >= ARRAY_COUNT(D_80A6D4C0_50)) {
            pthis->unk_200 = 0;
        }
    }
}

f32 func_80A6B30C(EnHorseNormal* pthis) {
    f32 result;

    if (pthis->animationIdx == 4) {
        result = D_80A6D4C8_51[pthis->animationIdx] * pthis->actor.speedXZ * (1 / 2.0f);
    } else if (pthis->animationIdx == 5) {
        result = D_80A6D4C8_51[pthis->animationIdx] * pthis->actor.speedXZ * (1 / 3.0f);
    } else if (pthis->animationIdx == 6) {
        result = D_80A6D4C8_51[pthis->animationIdx] * pthis->actor.speedXZ * (1 / 5.0f);
    } else {
        result = D_80A6D4C8_51[pthis->animationIdx];
    }

    return result;
}

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 300, ICHAIN_STOP),
};

void EnHorseNormal_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseNormal* pthis = (EnHorseNormal*)thisx;
    s32 pad;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.gravity = -3.5f;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawHorse, 20.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 70.0f;
    pthis->action = HORSE_CYCLE_ANIMATIONS;
    pthis->animationIdx = 0;
    Collider_InitCylinder(globalCtx, &pthis->bodyCollider);
    Collider_SetCylinder(globalCtx, &pthis->bodyCollider, &pthis->actor, &sCylinderInit1);
    Collider_InitJntSph(globalCtx, &pthis->headCollider);
    Collider_SetJntSph(globalCtx, &pthis->headCollider, &pthis->actor, &sJntSphInit, pthis->headElements);
    Collider_InitCylinder(globalCtx, &pthis->cloneCollider);
    Collider_SetCylinder(globalCtx, &pthis->cloneCollider, &pthis->actor, &sCylinderInit2);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    if (globalCtx->sceneNum == SCENE_SPOT20) {
        if (pthis->actor.world.rot.z == 0 || gSaveContext.nightFlag) {
            Actor_Kill(&pthis->actor);
            return;
        }
        if (!LINK_IS_ADULT) {
            if (Flags_GetEventChkInf(0x14)) {
                if (pthis->actor.world.rot.z != 3) {
                    Actor_Kill(&pthis->actor);
                    return;
                }
            } else if (pthis->actor.world.rot.z != 1) {
                Actor_Kill(&pthis->actor);
                return;
            }
        } else if (Flags_GetEventChkInf(0x18) || (DREG(1) != 0)) {
            if (pthis->actor.world.rot.z != 7) {
                Actor_Kill(&pthis->actor);
                return;
            }
        } else if (pthis->actor.world.rot.z != 5) {
            Actor_Kill(&pthis->actor);
            return;
        }
        pthis->actor.home.rot.z = pthis->actor.world.rot.z = pthis->actor.shape.rot.z = 0;
        func_800A663C(globalCtx, &pthis->skin, &gHorseNormalSkel, &gHorseNormalIdleAnim);
        Animation_PlayOnce(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx]);
        if ((pthis->actor.world.pos.x == -730.0f && pthis->actor.world.pos.y == 0.0f &&
             pthis->actor.world.pos.z == -1100.0f) ||
            (pthis->actor.world.pos.x == 880.0f && pthis->actor.world.pos.y == 0.0f &&
             pthis->actor.world.pos.z == -1170.0f)) {
            func_80A6C6B0(pthis);
            return;
        }
    } else if (globalCtx->sceneNum == SCENE_MALON_STABLE) {
        if (IS_DAY) {
            Actor_Kill(&pthis->actor);
            return;
        } else {
            func_800A663C(globalCtx, &pthis->skin, &gHorseNormalSkel, &gHorseNormalIdleAnim);
            Animation_PlayOnce(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx]);
            func_80A6C6B0(pthis);
            return;
        }
    } else if (globalCtx->sceneNum == SCENE_SPOT12) {
        if (pthis->actor.world.pos.x == 3707.0f && pthis->actor.world.pos.y == 1413.0f &&
            pthis->actor.world.pos.z == -665.0f) {
            func_800A663C(globalCtx, &pthis->skin, &gHorseNormalSkel, &gHorseNormalIdleAnim);
            Animation_PlayOnce(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx]);
            func_80A6C4CC(pthis);
            return;
        }
        func_800A663C(globalCtx, &pthis->skin, &gHorseNormalSkel, &gHorseNormalIdleAnim);
        Animation_PlayOnce(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx]);
    } else {
        func_800A663C(globalCtx, &pthis->skin, &gHorseNormalSkel, &gHorseNormalIdleAnim);
        Animation_PlayOnce(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx]);
    }
    if ((pthis->actor.params & 0xF0) == 0x10 && (pthis->actor.params & 0xF) != 0xF) {
        func_80A6B91C(pthis, globalCtx);
    } else {
        func_80A6BC48(pthis);
    }
}

void EnHorseNormal_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseNormal* pthis = (EnHorseNormal*)thisx;

    func_800A6888(globalCtx, &pthis->skin);
    Collider_DestroyCylinder(globalCtx, &pthis->bodyCollider);
    Collider_DestroyCylinder(globalCtx, &pthis->cloneCollider);
    Collider_DestroyJntSph(globalCtx, &pthis->headCollider);
}

void func_80A6B91C(EnHorseNormal* pthis, GlobalContext* globalCtx) {
    pthis->actor.flags |= ACTOR_FLAG_4;
    pthis->action = HORSE_FOLLOW_PATH;
    pthis->animationIdx = 6;
    pthis->waypoint = 0;
    pthis->actor.speedXZ = 7.0f;
    Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                     Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
}

void EnHorseNormal_FollowPath(EnHorseNormal* pthis, GlobalContext* globalCtx) {
    Path* path = &globalCtx->setupPathList[pthis->actor.params & 0xF];
    Vec3s* pointPos = SEGMENTED_TO_VIRTUAL(path->points);
    f32 dx;
    f32 dz;
    s32 pad;

    pointPos += pthis->waypoint;
    dx = pointPos->x - pthis->actor.world.pos.x;
    dz = pointPos->z - pthis->actor.world.pos.z;
    Math_SmoothStepToS(&pthis->actor.world.rot.y, Math_FAtan2F(dx, dz) * (0x8000 / M_PI), 0xA, 0x7D0, 1);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    if (SQ(dx) + SQ(dz) < 600.0f) {
        pthis->waypoint++;
        if (pthis->waypoint >= path->count) {
            pthis->waypoint = 0;
        }
    }
    pthis->skin.skelAnime.playSpeed = func_80A6B30C(pthis);
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                         Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
        func_80A6BCEC(pthis);
    }
}

void EnHorseNormal_NextAnimation(EnHorseNormal* pthis) {
    pthis->action = HORSE_CYCLE_ANIMATIONS;
    pthis->animationIdx++;

    if (pthis->animationIdx >= ARRAY_COUNT(sAnimations)) {
        pthis->animationIdx = 0;
    }

    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx]);
}

void EnHorseNormal_CycleAnimations(EnHorseNormal* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 0.0f;

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        EnHorseNormal_NextAnimation(pthis);
    }
}

void func_80A6BC48(EnHorseNormal* pthis) {
    pthis->action = HORSE_WANDER;
    pthis->animationIdx = 0;
    pthis->unk_21C = 0;
    pthis->unk_21E = 0;
    pthis->actor.speedXZ = 0.0f;
    pthis->unk_218 = 0.0f;
    Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                     Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
}

void func_80A6BCEC(EnHorseNormal* pthis) {
    if (pthis->animationIdx == 5) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (pthis->animationIdx == 6) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    }
}

void func_80A6BD7C(EnHorseNormal* pthis) {
    f32 frame = pthis->skin.skelAnime.curFrame;

    if (pthis->animationIdx == 0 && frame > 28.0f && !(pthis->unk_1E4 & 1)) {
        pthis->unk_1E4 |= 1;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_SANDDUST, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &gReverbAdd2);
    } else if (pthis->animationIdx == 3 && frame > 25.0f && !(pthis->unk_1E4 & 2)) {
        pthis->unk_1E4 |= 2;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND2, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &gReverbAdd2);
    }
}

void EnHorseNormal_Wander(EnHorseNormal* pthis, GlobalContext* globalCtx) {
    s32 phi_t0 = pthis->animationIdx;
    s32 pad;

    switch (D_80A6D510_62[pthis->animationIdx]) {
        case 0:
            func_80A6BD7C(pthis);
            pthis->actor.speedXZ = 0.0f;
            pthis->unk_218 = 0.0f;
            break;
        case 1:
            if (Rand_ZeroOne() < 0.1f) {
                pthis->unk_218 = 2.0f * Rand_ZeroOne() - 1.0f;
            }
            pthis->actor.speedXZ += pthis->unk_218;
            if (pthis->actor.speedXZ <= 0.0f) {
                pthis->actor.speedXZ = 0.0f;
                pthis->unk_218 = 0.0f;
                phi_t0 = 0;
            } else if (pthis->actor.speedXZ < 3.0f) {
                func_80A6B250(pthis);
                phi_t0 = 4;
            } else if (pthis->actor.speedXZ < 6.0f) {
                phi_t0 = 5;
            } else if (pthis->actor.speedXZ < 8.0f) {
                phi_t0 = 6;
            } else {
                pthis->actor.speedXZ = 8.0f;
                phi_t0 = 6;
            }
            if (Rand_ZeroOne() < 0.1f || (pthis->unk_21E == 0 && ((pthis->actor.bgCheckFlags & 8) ||
                                                                 (pthis->bodyCollider.base.ocFlags1 & OC1_HIT) ||
                                                                 (pthis->headCollider.base.ocFlags1 & OC1_HIT)))) {
                pthis->unk_21E += (Rand_ZeroOne() * 30.0f) - 15.0f;
                if (pthis->unk_21E > 50) {
                    pthis->unk_21E = 50;
                } else if (pthis->unk_21E < -50) {
                    pthis->unk_21E = -50;
                }
            }
            pthis->unk_21C += pthis->unk_21E;
            if (pthis->unk_21C < -300) {
                pthis->unk_21C = -300;
            } else if (pthis->unk_21C > 300) {
                pthis->unk_21C = 300;
            } else if (Rand_ZeroOne() < 0.25f && fabsf(pthis->unk_21C) < 100.0f) {
                pthis->unk_21C = 0;
                pthis->unk_21E = 0;
            }
            pthis->actor.world.rot.y += pthis->unk_21C;
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
            break;
        case 2:
        case 3:
            break;
    }

    if (phi_t0 != pthis->animationIdx || SkelAnime_Update(&pthis->skin.skelAnime)) {
        if (phi_t0 != pthis->animationIdx) {
            pthis->animationIdx = phi_t0;
            pthis->unk_1E4 &= ~1;
            pthis->unk_1E4 &= ~2;
            if (phi_t0 == 1) {
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_GROAN, &pthis->unk_204, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            } else if (phi_t0 == 3) {
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_204, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            } else {
                func_80A6BCEC(pthis);
            }
            Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                             Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
        } else {
            switch (D_80A6D510_62[pthis->animationIdx]) {
                case 0:
                    if (Rand_ZeroOne() < 0.25f) {
                        pthis->unk_218 = 1.0f;
                        phi_t0 = 4;
                    } else {
                        phi_t0 = D_80A6D4F4_62[(s32)(Rand_ZeroOne() * 2)];
                        pthis->actor.speedXZ = 0.0f;
                        pthis->unk_218 = 0.0f;
                    }
                    break;
                case 1:
                case 2:
                case 3:
                    break;
            }

            pthis->unk_1E4 &= ~1;
            pthis->unk_1E4 &= ~2;
            if (phi_t0 == 1) {
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_GROAN, &pthis->unk_204, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            } else if (phi_t0 == 3) {
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_204, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            } else {
                func_80A6BCEC(pthis);
            }
            if (phi_t0 != pthis->animationIdx) {
                pthis->animationIdx = phi_t0;
                Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                                 Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
            } else {
                Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                                 Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
            }
        }
    }
}

void func_80A6C4CC(EnHorseNormal* pthis) {
    pthis->action = HORSE_WAIT;
    pthis->animationIdx = 0;
    pthis->unk_21C = 0;
    pthis->unk_21E = 0;
    pthis->actor.speedXZ = 0.0f;
    pthis->unk_218 = 0.0f;
    Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                     Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
}

void EnHorseNormal_Wait(EnHorseNormal* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        f32 rand = Rand_ZeroOne();

        if (rand < 0.4f) {
            pthis->animationIdx = 0;
        } else if (rand < 0.8f) {
            pthis->animationIdx = 1;
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_GROAN, &pthis->unk_204, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        } else {
            pthis->animationIdx = 3;
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_204, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        }

        Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                         Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
    }
}

void func_80A6C6B0(EnHorseNormal* pthis) {
    pthis->action = HORSE_WAIT_CLONE;
    pthis->animationIdx = 0;
    pthis->unk_21C = 0;
    pthis->unk_21E = 0;
    pthis->actor.flags |= ACTOR_FLAG_4 | ACTOR_FLAG_5;
    pthis->actor.speedXZ = 0.0f;
    pthis->unk_218 = 0.0f;
    Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                     Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
}

void EnHorseNormal_WaitClone(EnHorseNormal* pthis, GlobalContext* globalCtx) {
    func_80A6BD7C(pthis);

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        f32 rand = Rand_ZeroOne();

        if (rand < 0.4f) {
            pthis->animationIdx = 0;
        } else if (rand < 0.8f) {
            pthis->animationIdx = 1;
            pthis->unk_1E4 |= 0x20;
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_GROAN, &pthis->unk_204, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        } else {
            pthis->animationIdx = 3;
            pthis->unk_1E4 |= 0x20;
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_204, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        }

        Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A6B30C(pthis), 0.0f,
                         Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);

        pthis->unk_1E4 &= ~1;
        pthis->unk_1E4 &= ~2;
        pthis->unk_1E4 &= ~8;
        pthis->unk_1E4 &= ~0x10;
    }
}

void func_80A6C8E0(EnHorseNormal* pthis, GlobalContext* globalCtx) {
    s32 pad;
    CollisionPoly* sp38;
    s32 pad2;
    Vec3f sp28;
    s32 sp24;

    sp28.x = (Math_SinS(pthis->actor.shape.rot.y) * 30.0f) + pthis->actor.world.pos.x;
    sp28.y = pthis->actor.world.pos.y + 60.0f;
    sp28.z = (Math_CosS(pthis->actor.shape.rot.y) * 30.0f) + pthis->actor.world.pos.z;
    pthis->unk_220 = BgCheck_EntityRaycastFloor3(&globalCtx->colCtx, &sp38, &sp24, &sp28);
    pthis->actor.shape.rot.x = Math_FAtan2F(pthis->actor.world.pos.y - pthis->unk_220, 30.0f) * (0x8000 / M_PI);
}

static EnHorseNormalActionFunc sActionFuncs[] = {
    EnHorseNormal_CycleAnimations, EnHorseNormal_Wander,     EnHorseNormal_Wait,
    EnHorseNormal_WaitClone,       EnHorseNormal_FollowPath,
};

void EnHorseNormal_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseNormal* pthis = (EnHorseNormal*)thisx;
    s32 pad;

    sActionFuncs[pthis->action](pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 35.0f, 100.0f, 0x1D);
    if (globalCtx->sceneNum == SCENE_SPOT20 && pthis->actor.world.pos.z < -2400.0f) {
        pthis->actor.world.pos.z = -2400.0f;
    }
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 70.0f;
    pthis->unk_204 = pthis->actor.projectedPos;
    pthis->unk_204.y += 120.0f;
    Collider_UpdateCylinder(&pthis->actor, &pthis->bodyCollider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
    if (pthis->actor.speedXZ == 0.0f) {
        pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    } else {
        pthis->actor.colChkInfo.mass = MASS_HEAVY;
    }
}

void func_80A6CAFC(Actor* thisx, GlobalContext* globalCtx, PSkinAwb* skin) {
    Vec3f sp4C;
    Vec3f sp40;
    EnHorseNormal* pthis = (EnHorseNormal*)thisx;
    s32 i;

    for (i = 0; i < pthis->headCollider.count; i++) {
        sp4C.x = pthis->headCollider.elements[i].dim.modelSphere.center.x;
        sp4C.y = pthis->headCollider.elements[i].dim.modelSphere.center.y;
        sp4C.z = pthis->headCollider.elements[i].dim.modelSphere.center.z;
        func_800A6408(skin, pthis->headCollider.elements[i].dim.limb, &sp4C, &sp40);
        pthis->headCollider.elements[i].dim.worldSphere.center.x = sp40.x;
        pthis->headCollider.elements[i].dim.worldSphere.center.y = sp40.y;
        pthis->headCollider.elements[i].dim.worldSphere.center.z = sp40.z;
        pthis->headCollider.elements[i].dim.worldSphere.radius =
            pthis->headCollider.elements[i].dim.modelSphere.radius * pthis->headCollider.elements[i].dim.scale;
    }

    //! @bug see relevant comment in `EnHorse_SkinCallback1`
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->headCollider.base);
}

void func_80A6CC88(GlobalContext* globalCtx, EnHorseNormal* pthis, Vec3f* arg2) {
    f32 curFrame = pthis->skin.skelAnime.curFrame;
    f32 wDest;

    SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->viewProjectionMtxF, arg2, &pthis->unk_1E8, &wDest);
    pthis->unk_1F4 = pthis->unk_1E8;
    pthis->unk_1F4.y += 120.0f;

    if (pthis->animationIdx == 0 && curFrame > 28.0f && !(pthis->unk_1E4 & 8)) {
        pthis->unk_1E4 |= 8;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_SANDDUST, &pthis->unk_1E8, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (pthis->animationIdx == 3 && curFrame > 25.0f && !(pthis->unk_1E4 & 0x10)) {
        pthis->unk_1E4 |= 0x10;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND2, &pthis->unk_1E8, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (pthis->animationIdx == 3 && pthis->unk_1E4 & 0x20) {
        pthis->unk_1E4 &= ~0x20;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_1F4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    } else if (pthis->animationIdx == 1 && pthis->unk_1E4 & 0x20) {
        pthis->unk_1E4 &= ~0x20;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_GROAN, &pthis->unk_1F4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    }
}

void EnHorseNormal_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseNormal* pthis = (EnHorseNormal*)thisx;
    Mtx* mtx2;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_horse_normal.c", 2224);

    if (globalCtx->sceneNum != SCENE_SPOT20 || globalCtx->sceneNum != SCENE_MALON_STABLE) {
        func_80A6C8E0(pthis, globalCtx);
    }
    func_80093D18(globalCtx->state.gfxCtx);
    func_800A6330(&pthis->actor, globalCtx, &pthis->skin, func_80A6CAFC, 1);

    if (pthis->action == HORSE_WAIT_CLONE) {
        MtxF skinMtx;
        Mtx* mtx1;
        Vec3f clonePos = { 0.0f, 0.0f, 0.0f };
        s16 cloneRotY;
        f32 distFromGround = pthis->actor.world.pos.y - pthis->actor.floorHeight;
        f32 temp_f0_4;

        if (globalCtx->sceneNum == SCENE_MALON_STABLE) {
            if (pthis->actor.world.pos.x == 355.0f && pthis->actor.world.pos.y == 0.0f &&
                pthis->actor.world.pos.z == -245.0f) {
                clonePos.x = 235.0f;
                clonePos.y = 0.0f;
                clonePos.z = 100.0f;
                cloneRotY = 0x7FFF;
            } else if (pthis->actor.world.pos.x == 238.0f && pthis->actor.world.pos.y == 0.0f &&
                       pthis->actor.world.pos.z == -245.0f) {
                clonePos.x = 478.0f;
                clonePos.y = 0.0f;
                clonePos.z = 100.0f;
                cloneRotY = 0x7FFF;
            }
        } else if (globalCtx->sceneNum == SCENE_SPOT20) {
            if (pthis->actor.world.pos.x == -730.0f && pthis->actor.world.pos.y == 0.0f &&
                pthis->actor.world.pos.z == -1100.0f) {
                clonePos.x = 780.0f;
                clonePos.y = 0.0f;
                clonePos.z = -80.0f;
                cloneRotY = 0;
            } else if (pthis->actor.world.pos.x == 880.0f && pthis->actor.world.pos.y == 0.0f &&
                       pthis->actor.world.pos.z == -1170.0f) {
                clonePos.x = -1000.0f;
                clonePos.y = 0.0f;
                clonePos.z = -70.0f;
                cloneRotY = 0;
            }
        }
        func_80A6CC88(globalCtx, pthis, &clonePos);
        SkinMatrix_SetTranslateRotateYXZScale(&skinMtx, pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z,
                                              pthis->actor.shape.rot.x, cloneRotY, pthis->actor.shape.rot.z, clonePos.x,
                                              (pthis->actor.shape.yOffset * pthis->actor.scale.y) + clonePos.y,
                                              clonePos.z);
        mtx1 = SkinMatrix_MtxFToNewMtx(globalCtx->state.gfxCtx, &skinMtx);
        if (mtx1 == NULL) {
            return;
        }
        gSPMatrix(POLY_OPA_DISP++, &gMtxClear, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPMatrix(POLY_OPA_DISP++, mtx1, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_800A63CC(&pthis->actor, globalCtx, &pthis->skin, NULL, NULL, 1, 0, 3);
        pthis->cloneCollider.dim.pos.x = clonePos.x;
        pthis->cloneCollider.dim.pos.y = clonePos.y;
        pthis->cloneCollider.dim.pos.z = clonePos.z;
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->cloneCollider.base);
        func_80094044(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, 255);
        Matrix_Translate(clonePos.x, clonePos.y, clonePos.z, MTXMODE_NEW);
        temp_f0_4 = (1.0f - (distFromGround * 0.01f)) * pthis->actor.shape.shadowScale;
        Matrix_Scale(pthis->actor.scale.x * temp_f0_4, 1.0f, pthis->actor.scale.z * temp_f0_4, MTXMODE_APPLY);
        Matrix_RotateY(cloneRotY * (2.0f * M_PI / 0x10000), MTXMODE_APPLY);
        mtx2 = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_horse_normal.c", 2329);
        if (mtx2 != NULL) {
            gSPMatrix(POLY_XLU_DISP++, mtx2, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gHorseShadowDL);
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_horse_normal.c", 2339);
}

void EnHorseNormal_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Horse_Normal_InitVars = {
        ACTOR_EN_HORSE_NORMAL,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_HORSE_NORMAL,
        sizeof(EnHorseNormal),
        (ActorFunc)EnHorseNormal_Init,
        (ActorFunc)EnHorseNormal_Destroy,
        (ActorFunc)EnHorseNormal_Update,
        (ActorFunc)EnHorseNormal_Draw,
        (ActorFunc)EnHorseNormal_Reset,
    };

    sCylinderInit1 = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 40, 100, 0, { 0, 0, 0 } },
    };

    sCylinderInit2 = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 60, 100, 0, { 0, 0, 0 } },
    };

    sJntSphInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_JNTSPH,
        },
        ARRAY_COUNT(sJntSphElementsInit),
        sJntSphElementsInit,
    };

    sColChkInfoInit = { 10, 35, 100, MASS_HEAVY };

    D_80A6D468 = { ARRAY_COUNT(D_80A6D428), D_80A6D428 };

    D_80A6D4B8 = { ARRAY_COUNT(D_80A6D470), D_80A6D470 };

}
