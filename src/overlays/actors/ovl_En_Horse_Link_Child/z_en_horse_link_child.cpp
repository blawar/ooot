#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HORSE_LINK_CHILD_Z_EN_HORSE_LINK_CHILD_C
#include "actor_common.h"
/*
 * File: z_en_horse_link_child.c
 * Overlay: ovl_En_Horse_Link_Child
 * Description: Young Epona
 */

#include "z_en_horse_link_child.h"
#include "objects/object_horse_link_child/object_horse_link_child.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_horse.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "def/z_skin.h"
#include "def/z_skin_awb.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_25)

void EnHorseLinkChild_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHorseLinkChild_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHorseLinkChild_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHorseLinkChild_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A69B7C(EnHorseLinkChild* pthis);
void func_80A69EC0(EnHorseLinkChild* pthis);
void func_80A6A4DC(EnHorseLinkChild* pthis);
void func_80A6A724(EnHorseLinkChild* pthis);

ActorInit En_Horse_Link_Child_InitVars = {
    ACTOR_EN_HORSE_LINK_CHILD,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HORSE_LINK_CHILD,
    sizeof(EnHorseLinkChild),
    (ActorFunc)EnHorseLinkChild_Init,
    (ActorFunc)EnHorseLinkChild_Destroy,
    (ActorFunc)EnHorseLinkChild_Update,
    (ActorFunc)EnHorseLinkChild_Draw,
};

static AnimationHeader* sAnimations[] = {
    &gChildEponaIdleAnim,     &gChildEponaWhinnyAnim,    &gChildEponaWalkingAnim,
    &gChildEponaTrottingAnim, &gChildEponaGallopingAnim,
};

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
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
    { 20, 100, 0, { 0, 0, 0 } },
};

static ColliderJntSphElementInit sJntSphElementInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 13, { { 0, 0, 0 }, 10 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1 | OC2_UNK1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementInit,
};

static CollisionCheckInfoInit sColCheckInfoInit = { 10, 35, 100, MASS_HEAVY };

void func_80A693D0(EnHorseLinkChild* pthis) {
    static s32 D_80A6AF5C[] = { 1, 19 };

    if ((pthis->skin.skelAnime.curFrame > D_80A6AF5C[pthis->unk_1F0]) &&
        !((pthis->unk_1F0 == 0) && (pthis->skin.skelAnime.curFrame > D_80A6AF5C[1]))) {
        Audio_PlaySoundGeneral(NA_SE_EV_KID_HORSE_WALK, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        pthis->unk_1F0++;
        if (pthis->unk_1F0 >= ARRAY_COUNT(D_80A6AF5C)) {
            pthis->unk_1F0 = 0;
        }
    }
}

void func_80A6948C(EnHorseLinkChild* pthis) {
    if (pthis->animationIdx == 2) {
        func_80A693D0(pthis);
    } else if (pthis->skin.skelAnime.curFrame == 0.0f) {
        if ((pthis->animationIdx == 3) || (pthis->animationIdx == 4)) {
            Audio_PlaySoundGeneral(NA_SE_EV_KID_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &D_801333E8);
        } else if (pthis->animationIdx == 1) {
            if (Rand_ZeroOne() > 0.5f) {
                Audio_PlaySoundGeneral(NA_SE_EV_KID_HORSE_GROAN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                       &D_801333E8);
            } else {
                Audio_PlaySoundGeneral(NA_SE_EV_KID_HORSE_NEIGH, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                       &D_801333E8);
            }
        }
    }
}

static f32 D_80A6AF64[] = { 1.0f, 1.0f, 1.5f, 1.5f, 1.5f };

f32 func_80A695A4(EnHorseLinkChild* pthis) {
    f32 result;

    if (pthis->animationIdx == 2) {
        result = D_80A6AF64[pthis->animationIdx] * pthis->actor.speedXZ * (1.0f / 2.0f);
    } else if (pthis->animationIdx == 3) {
        result = D_80A6AF64[pthis->animationIdx] * pthis->actor.speedXZ * (1.0f / 3.0f);
    } else if (pthis->animationIdx == 4) {
        result = D_80A6AF64[pthis->animationIdx] * pthis->actor.speedXZ * (1.0f / 5.0f);
    } else {
        result = D_80A6AF64[pthis->animationIdx];
    }

    return result;
}

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 1200, ICHAIN_STOP),
};

void EnHorseLinkChild_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseLinkChild* pthis = (EnHorseLinkChild*)thisx;
    s32 pad;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Actor_SetScale(&pthis->actor, 0.005f);
    pthis->actor.gravity = -3.5f;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawHorse, 20.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->action = 1;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 70.0f;
    func_800A663C(globalCtx, &pthis->skin, &gChildEponaSkel, &gChildEponaGallopingAnim);
    pthis->animationIdx = 0;
    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimations[0]);
    Collider_InitCylinder(globalCtx, &pthis->bodyCollider);
    Collider_SetCylinderType1(globalCtx, &pthis->bodyCollider, &pthis->actor, &sCylinderInit);
    Collider_InitJntSph(globalCtx, &pthis->headCollider);
    Collider_SetJntSph(globalCtx, &pthis->headCollider, &pthis->actor, &sJntSphInit, pthis->headElements);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColCheckInfoInit);
    pthis->unk_1F0 = 0;
    pthis->eyeTexIndex = 0;

    if (gSaveContext.sceneSetupIndex > 3) {
        func_80A69EC0(pthis);
    } else if (globalCtx->sceneNum == SCENE_SPOT20) {
        if (!Flags_GetEventChkInf(0x14)) {
            Actor_Kill(&pthis->actor);
            return;
        }
        pthis->unk_2A0 = gSaveContext.eventChkInf[1] & 0x40;
        func_80A69EC0(pthis);
    } else {
        func_80A69EC0(pthis);
    }

    pthis->actor.home.rot.z = pthis->actor.world.rot.z = pthis->actor.shape.rot.z = 0;
}

void EnHorseLinkChild_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseLinkChild* pthis = (EnHorseLinkChild*)thisx;

    func_800A6888(globalCtx, &pthis->skin);
    Collider_DestroyCylinder(globalCtx, &pthis->bodyCollider);
    Collider_DestroyJntSph(globalCtx, &pthis->headCollider);
}

void func_80A6988C(EnHorseLinkChild* pthis) {
    pthis->action = 0;
    pthis->animationIdx++;
    if (pthis->animationIdx >= ARRAY_COUNT(sAnimations)) {
        pthis->animationIdx = 0;
    }

    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx]);
    pthis->skin.skelAnime.playSpeed = func_80A695A4(pthis);
}

void func_80A698F4(EnHorseLinkChild* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 0.0f;
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        func_80A6988C(pthis);
    }
}

void func_80A6993C(EnHorseLinkChild* pthis, s32 newAnimationIdx) {
    pthis->action = 2;
    pthis->actor.speedXZ = 0.0f;

    if (!((newAnimationIdx == 0) || (newAnimationIdx == 1))) {
        newAnimationIdx = 0;
    }

    if (pthis->animationIdx != newAnimationIdx) {
        pthis->animationIdx = newAnimationIdx;
        Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                         Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -5.0f);
    }
}

void func_80A699FC(EnHorseLinkChild* pthis, GlobalContext* globalCtx) {
    f32 distFromLink;
    s32 newAnimationIdx;

    distFromLink = Actor_WorldDistXZToActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        if ((distFromLink < 1000.0f) && (distFromLink > 70.0f)) {
            func_80A69B7C(pthis);
        } else {
            newAnimationIdx = pthis->animationIdx == 1 ? 0 : 1;
            if (pthis->animationIdx != newAnimationIdx) {
                pthis->animationIdx = newAnimationIdx;
                Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                                 Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -5.0f);
            } else {
                Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                                 Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0);
            }
        }
    }
}

void func_80A69B7C(EnHorseLinkChild* pthis) {
    pthis->action = 1;
    pthis->animationIdx = 0;
    pthis->actor.speedXZ = 0.0f;
    Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                     Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -5.0f);
}

void func_80A69C18(EnHorseLinkChild* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;
    f32 distFromLink;
    s32 newAnimationIdx;

    if ((pthis->animationIdx == 4) || (pthis->animationIdx == 3) || (pthis->animationIdx == 2)) {
        yawDiff = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) - pthis->actor.world.rot.y;

        if (yawDiff > 0x12C) {
            pthis->actor.world.rot.y += 0x12C;
        } else if (yawDiff < -0x12C) {
            pthis->actor.world.rot.y -= 0x12C;
        } else {
            pthis->actor.world.rot.y += yawDiff;
        }

        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        distFromLink = Actor_WorldDistXZToActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);

        if (distFromLink > 1000.0f) {
            func_80A6993C(pthis, 0);
            return;
        } else if ((distFromLink < 1000.0f) && (distFromLink >= 300.0f)) {
            newAnimationIdx = 4;
            pthis->actor.speedXZ = 6.0f;
        } else if ((distFromLink < 300.0f) && (distFromLink >= 150.0f)) {
            newAnimationIdx = 3;
            pthis->actor.speedXZ = 4.0f;
        } else if ((distFromLink < 150.0f) && (distFromLink >= 70.0f)) {
            newAnimationIdx = 2;
            pthis->actor.speedXZ = 2.0f;
            pthis->unk_1F0 = 0;
        } else {
            func_80A6993C(pthis, 1);
            return;
        }

        if (pthis->animationIdx != newAnimationIdx) {
            pthis->animationIdx = newAnimationIdx;
            Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                             Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -5.0f);
        } else {
            Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                             Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
        }
    }
}

void func_80A69EC0(EnHorseLinkChild* pthis) {
    pthis->action = 3;
    pthis->animationIdx = 0;
    pthis->actor.speedXZ = 0.0f;
    Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                     Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -5.0f);
}

void func_80A69F5C(EnHorseLinkChild* pthis, GlobalContext* globalCtx) {
    Player* player;
    s16 yawDiff;
    s32 yawSign;
    s32 yawOffset;

    if ((pthis->animationIdx == 4) || (pthis->animationIdx == 3) || (pthis->animationIdx == 2)) {
        player = GET_PLAYER(globalCtx);

        if (Math3D_Vec3f_DistXYZ(&player->actor.world.pos, &pthis->actor.home.pos) < 250.0f) {
            yawDiff = player->actor.shape.rot.y;
            yawSign = Actor_WorldYawTowardActor(&pthis->actor, &player->actor) > 0 ? 1 : -1;
            yawOffset = yawSign << 0xE;
            yawDiff += yawOffset;
        } else {
            yawDiff = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos) - pthis->actor.world.rot.y;
        }

        if (yawDiff > 0x12C) {
            pthis->actor.world.rot.y += 0x12C;
        } else if (yawDiff < -0x12C) {
            pthis->actor.world.rot.y -= 0x12C;
        } else {
            pthis->actor.world.rot.y += yawDiff;
        }

        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    }
}

void func_80A6A068(EnHorseLinkChild* pthis, GlobalContext* globalCtx) {
    Player* player;
    f32 distFromLink;
    s32 animationEnded;
    s32 newAnimationIdx;
    f32 distFromHome;
    f32 distLinkFromHome;

    func_80A69F5C(pthis, globalCtx);
    player = GET_PLAYER(globalCtx);
    distFromLink = Actor_WorldDistXZToActor(&pthis->actor, &player->actor);

    if (gSaveContext.entranceIndex == 0x2AE) {
        Audio_PlaySoundGeneral(NA_SE_EV_KID_HORSE_NEIGH, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        func_80A6A724(pthis);
        return;
    }

    if (((gSaveContext.eventChkInf[1] & 0x40) && (DREG(53) != 0)) ||
        ((globalCtx->sceneNum == SCENE_SPOT20) && (gSaveContext.cutsceneIndex == 0xFFF1))) {
        func_80A6A4DC(pthis);
    } else {
        pthis->unk_2A0 = gSaveContext.eventChkInf[1] & 0x40;
    }

    newAnimationIdx = pthis->animationIdx;
    animationEnded = SkelAnime_Update(&pthis->skin.skelAnime);
    if (animationEnded || (pthis->animationIdx == 1) || (pthis->animationIdx == 0)) {
        if (gSaveContext.eventChkInf[1] & 0x20) {
            distFromHome = Math3D_Vec3f_DistXYZ(&pthis->actor.world.pos, &pthis->actor.home.pos);
            distLinkFromHome = Math3D_Vec3f_DistXYZ(&player->actor.world.pos, &pthis->actor.home.pos);
            if (distLinkFromHome > 250.0f) {
                if (distFromHome >= 300.0f) {
                    newAnimationIdx = 4;
                    pthis->actor.speedXZ = 6.0f;
                } else if ((distFromHome < 300.0f) && (distFromHome >= 150.0f)) {
                    newAnimationIdx = 3;
                    pthis->actor.speedXZ = 4.0f;
                } else if ((distFromHome < 150.0f) && (distFromHome >= 70.0f)) {
                    newAnimationIdx = 2;
                    pthis->actor.speedXZ = 2.0f;
                    pthis->unk_1F0 = 0;
                } else {
                    pthis->actor.speedXZ = 0.0f;
                    if (pthis->animationIdx == 0) {
                        newAnimationIdx = animationEnded == true ? 1 : 0;
                    } else {
                        newAnimationIdx = animationEnded == true ? 0 : 1;
                    }
                }
            } else {
                if (distFromLink < 200.0f) {
                    newAnimationIdx = 4;
                    pthis->actor.speedXZ = 6.0f;
                } else if (distFromLink < 300.0f) {
                    newAnimationIdx = 3;
                    pthis->actor.speedXZ = 4.0f;
                } else if (distFromLink < 400.0f) {
                    newAnimationIdx = 2;
                    pthis->actor.speedXZ = 2.0f;
                    pthis->unk_1F0 = 0;
                } else {
                    pthis->actor.speedXZ = 0.0f;
                    if (pthis->animationIdx == 0) {
                        newAnimationIdx = animationEnded == true ? 1 : 0;
                    } else {
                        newAnimationIdx = animationEnded == true ? 0 : 1;
                    }
                }
            }
        } else {
            pthis->actor.speedXZ = 0.0f;
            if (pthis->animationIdx == 0) {
                newAnimationIdx = animationEnded == true ? 1 : 0;
            } else {
                newAnimationIdx = animationEnded == true ? 0 : 1;
            }
        }
    }

    if ((pthis->animationIdx != newAnimationIdx) || (animationEnded == true)) {
        pthis->animationIdx = newAnimationIdx;
        Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                         Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -5.0f);
    } else {
        Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis),
                         pthis->skin.skelAnime.curFrame, Animation_GetLastFrame(sAnimations[pthis->animationIdx]), 2,
                         0.0f);
    }
}

void func_80A6A4DC(EnHorseLinkChild* pthis) {
    pthis->action = 5;
    pthis->animationIdx = Rand_ZeroOne() > 0.5f ? 0 : 1;
    DREG(53) = 0;
    Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                     Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
}

void func_80A6A5A4(EnHorseLinkChild* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;

    if (DREG(53) != 0) {
        DREG(53) = 0;
        Audio_PlaySoundGeneral(NA_SE_EV_KID_HORSE_NEIGH, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        func_80A6A724(pthis);
    } else {
        pthis->actor.speedXZ = 0.0f;
        yawDiff = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) - pthis->actor.world.rot.y;
        // 0.7071 = cos(pi/4)
        if ((Math_CosS(yawDiff) < 0.7071f) && (pthis->animationIdx == 2)) {
            func_8006DD9C(&pthis->actor, &GET_PLAYER(globalCtx)->actor.world.pos, 300);
        }

        if (SkelAnime_Update(&pthis->skin.skelAnime)) {
            if (Math_CosS(yawDiff) < 0.0f) {
                pthis->animationIdx = 2;
                Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], D_80A6AF64[pthis->animationIdx],
                                 0.0f, Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -5.0f);
            } else {
                func_80A6A4DC(pthis);
            }
        }
    }
}

void func_80A6A724(EnHorseLinkChild* pthis) {
    pthis->timer = 0;
    pthis->action = 4;
    pthis->animationIdx = 2;
    pthis->unk_1E8 = false;
    pthis->actor.speedXZ = 2.0f;
    Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                     Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -5.0f);
}

void func_80A6A7D0(EnHorseLinkChild* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 dist;
    s32 newAnimationIdx;

    pthis->timer++;
    if (pthis->timer > 300) {
        pthis->unk_1E8 = true;
    }

    if ((pthis->animationIdx == 4) || (pthis->animationIdx == 3) || (pthis->animationIdx == 2)) {
        if (!pthis->unk_1E8) {
            func_8006DD9C(&pthis->actor, &player->actor.world.pos, 300);
        } else {
            func_8006DD9C(&pthis->actor, &pthis->actor.home.pos, 300);
        }
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        if (!pthis->unk_1E8) {
            dist = Actor_WorldDistXZToActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);
        } else {
            dist = Math3D_Vec3f_DistXYZ(&pthis->actor.world.pos, &pthis->actor.home.pos);
        }

        if (!pthis->unk_1E8) {
            if (dist >= 300.0f) {
                newAnimationIdx = 4;
                pthis->actor.speedXZ = 6.0f;
            } else if (dist >= 150.0f) {
                newAnimationIdx = 3;
                pthis->actor.speedXZ = 4.0f;
            } else {
                newAnimationIdx = 2;
                pthis->actor.speedXZ = 2.0f;
                pthis->unk_1F0 = 0;
            }
        } else {
            if (dist >= 300.0f) {
                newAnimationIdx = 4;
                pthis->actor.speedXZ = 6.0f;
            } else if (dist >= 150.0f) {
                newAnimationIdx = 3;
                pthis->actor.speedXZ = 4.0f;
            } else if (dist >= 70.0f) {
                newAnimationIdx = 2;
                pthis->actor.speedXZ = 2.0f;
                pthis->unk_1F0 = 0;
            } else {
                func_80A6A4DC(pthis);
                return;
            }
        }

        if (pthis->animationIdx != newAnimationIdx) {
            pthis->animationIdx = newAnimationIdx;
            Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                             Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, -5.0f);
        } else {
            Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->animationIdx], func_80A695A4(pthis), 0.0f,
                             Animation_GetLastFrame(sAnimations[pthis->animationIdx]), ANIMMODE_ONCE, 0.0f);
        }
    }
}

static EnHorseLinkChildActionFunc sActionFuncs[] = {
    func_80A698F4, func_80A69C18, func_80A699FC, func_80A6A068, func_80A6A7D0, func_80A6A5A4,
};

static void* sEyeTextures[] = { gChildEponaEyeOpenTex, gChildEponaEyeHalfTex, gChildEponaEyeCloseTex };
static u8 sEyeIndexOrder[] = { 0, 1, 2, 1 };

void EnHorseLinkChild_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseLinkChild* pthis = (EnHorseLinkChild*)thisx;
    s32 pad;

    sActionFuncs[pthis->action](pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 55.0f, 100.0f, 0x1D);

    if ((globalCtx->sceneNum == SCENE_SPOT20) && (pthis->actor.world.pos.z < -2400.0f)) {
        pthis->actor.world.pos.z = -2400.0f;
    }

    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 70.0f;

    if ((Rand_ZeroOne() < 0.025f) && (pthis->eyeTexIndex == 0)) {
        pthis->eyeTexIndex++;
    } else if (pthis->eyeTexIndex > 0) {
        pthis->eyeTexIndex++;
        if (pthis->eyeTexIndex >= ARRAY_COUNT(sEyeIndexOrder)) {
            pthis->eyeTexIndex = 0;
        }
    }

    Collider_UpdateCylinder(&pthis->actor, &pthis->bodyCollider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
    func_80A6948C(pthis);
}

void func_80A6ABF8(Actor* thisx, GlobalContext* globalCtx, PSkinAwb* skin) {
    Vec3f center;
    Vec3f newCenter;
    EnHorseLinkChild* pthis = (EnHorseLinkChild*)thisx;
    s32 i;

    for (i = 0; i < pthis->headCollider.count; i++) {
        center.x = pthis->headCollider.elements[i].dim.modelSphere.center.x;
        center.y = pthis->headCollider.elements[i].dim.modelSphere.center.y;
        center.z = pthis->headCollider.elements[i].dim.modelSphere.center.z;
        func_800A6408(skin, pthis->headCollider.elements[i].dim.limb, &center, &newCenter);
        pthis->headCollider.elements[i].dim.worldSphere.center.x = newCenter.x;
        pthis->headCollider.elements[i].dim.worldSphere.center.y = newCenter.y;
        pthis->headCollider.elements[i].dim.worldSphere.center.z = newCenter.z;
        pthis->headCollider.elements[i].dim.worldSphere.radius =
            pthis->headCollider.elements[i].dim.modelSphere.radius * pthis->headCollider.elements[i].dim.scale;
    }

    //! @bug see relevant comment in `EnHorse_SkinCallback1`
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->headCollider.base);
}

s32 func_80A6AD84(Actor* thisx, GlobalContext* globalCtx, s32 arg2, PSkinAwb* arg3) {
    EnHorseLinkChild* pthis = (EnHorseLinkChild*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_horse_link_child.c", 1467);

    if (arg2 == 0xD) {
        u8 index = sEyeIndexOrder[pthis->eyeTexIndex];

        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures[index]));
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_horse_link_child.c", 1479);

    return 1;
}

void EnHorseLinkChild_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseLinkChild* pthis = (EnHorseLinkChild*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    func_800A6360(&pthis->actor, globalCtx, &pthis->skin, func_80A6ABF8, func_80A6AD84, 1);
}
