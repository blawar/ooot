#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BUTTE_Z_EN_BUTTE_C
#include "actor_common.h"
/*
 * File: z_en_butte.c
 * Overlay: ovl_En_Butte
 * Description: Butterfly
 */

#include "z_en_butte.h"
#include "overlays/actors/ovl_En_Elf/z_en_elf.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/sinf.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS 0

void EnButte_Init(Actor* thisx, GlobalContext* globalCtx);
void EnButte_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnButte_Update(Actor* thisx, GlobalContext* globalCtx);
void EnButte_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnButte_SetupFlyAround(EnButte* pthis);
void EnButte_FlyAround(EnButte* pthis, GlobalContext* globalCtx);
void EnButte_SetupFollowLink(EnButte* pthis);
void EnButte_FollowLink(EnButte* pthis, GlobalContext* globalCtx);
void EnButte_SetupTransformIntoFairy(EnButte* pthis);
void EnButte_TransformIntoFairy(EnButte* pthis, GlobalContext* globalCtx);
void EnButte_SetupWaitToDie(EnButte* pthis);
void EnButte_WaitToDie(EnButte* pthis, GlobalContext* globalCtx);

static ColliderJntSphElementInit sJntSphElementsInit[] = {
    { {
          ELEMTYPE_UNK0,
          { 0x00000000, 0x00, 0x00 },
          { 0xFFCFFFFF, 0x000, 0x00 },
          TOUCH_NONE,
          BUMP_NONE,
          OCELEM_ON,
      },
      { 0, { { 0, 0, 0 }, 5 }, 100 } },
};
static ColliderJntSphInit sColliderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER | OC1_TYPE_1,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

ActorInit En_Butte_InitVars = {
    ACTOR_EN_BUTTE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(EnButte),
    (ActorFunc)EnButte_Init,
    (ActorFunc)EnButte_Destroy,
    (ActorFunc)EnButte_Update,
    (ActorFunc)EnButte_Draw,
};

typedef struct {
    /* 0x00 */ s16 minTime;
    /* 0x02 */ s16 maxTime;
    /* 0x04 */ f32 speedXZTarget;
    /* 0x08 */ f32 speedXZScale;
    /* 0x0C */ f32 speedXZStep;
    /* 0x10 */ s16 rotYStep;
} EnButteFlightParams; // size = 0x14

static EnButteFlightParams sFlyAroundParams[] = {
    { 5, 35, 0.0f, 0.1f, 0.5f, 0 },
    { 10, 45, 1.1f, 0.1f, 0.25f, 1000 },
    { 10, 40, 1.5f, 0.1f, 0.3f, 2000 },
};
static EnButteFlightParams sFollowLinkParams[] = {
    { 3, 3, 0.8f, 0.1f, 0.2f, 0 },
    { 10, 20, 2.0f, 0.3f, 1.0f, 0 },
    { 10, 20, 2.4f, 0.3f, 1.0f, 0 },
};

void EnButte_SelectFlightParams(EnButte* pthis, EnButteFlightParams* flightParams) {
    if (pthis->flightParamsIdx == 0) {
        if (Rand_ZeroOne() < 0.6f) {
            pthis->flightParamsIdx = 1;
        } else {
            pthis->flightParamsIdx = 2;
        }
    } else {
        pthis->flightParamsIdx = 0;
    }

    pthis->timer = Rand_S16Offset(flightParams->minTime, flightParams->maxTime);
}

static f32 sTransformationEffectScale = 0.0f;
static s16 sTransformationEffectAlpha = 0;

void EnButte_ResetTransformationEffect(void) {
    sTransformationEffectScale = 0.0f;
    sTransformationEffectAlpha = 0;
}

void EnButte_UpdateTransformationEffect(void) {
    sTransformationEffectScale += 0.003f;
    sTransformationEffectAlpha += 4000;
}

void EnButte_DrawTransformationEffect(EnButte* pthis, GlobalContext* globalCtx) {
    static Vec3f D_809CE3C4 = { 0.0f, 0.0f, -3.0f };
    Vec3f sp5C;
    s32 alpha;
    Vec3s camDir;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_choo.c", 295);

    func_80093C14(globalCtx->state.gfxCtx);

    alpha = Math_SinS(sTransformationEffectAlpha) * 250;
    alpha = CLAMP(alpha, 0, 255);

    Camera_GetCamDir(&camDir, GET_ACTIVE_CAM(globalCtx));
    Matrix_RotateY(camDir.y * (M_PI / 0x8000), MTXMODE_NEW);
    Matrix_RotateX(camDir.x * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_RotateZ(camDir.z * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_MultVec3f(&D_809CE3C4, &sp5C);
    func_800D1694(pthis->actor.focus.pos.x + sp5C.x, pthis->actor.focus.pos.y + sp5C.y, pthis->actor.focus.pos.z + sp5C.z,
                  &camDir);
    Matrix_Scale(sTransformationEffectScale, sTransformationEffectScale, sTransformationEffectScale, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_choo.c", 317),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 200, 200, 180, alpha);
    gDPSetEnvColor(POLY_XLU_DISP++, 200, 200, 210, 255);
    gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gEffFlash1DL));

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_choo.c", 326);
}

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 700, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 20, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 600, ICHAIN_STOP),
};

void EnButte_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnButte* pthis = (EnButte*)thisx;

    if (pthis->actor.params == -1) {
        pthis->actor.params = 0;
    }

    Actor_ProcessInitChain(&pthis->actor, sInitChain);

    if ((pthis->actor.params & 1) == 1) {
        pthis->actor.uncullZoneScale = 200.0f;
    }

    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gButterflySkel, &gButterflyAnim, pthis->jointTable, pthis->morphTable,
                   8);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sColliderInit, pthis->colliderItems);
    pthis->actor.colChkInfo.mass = 0;
    pthis->unk_25C = Rand_ZeroOne() * 0xFFFF;
    pthis->unk_25E = Rand_ZeroOne() * 0xFFFF;
    pthis->unk_260 = Rand_ZeroOne() * 0xFFFF;
    Animation_Change(&pthis->skelAnime, &gButterflyAnim, 1.0f, 0.0f, 0.0f, ANIMMODE_LOOP_INTERP, 0.0f);
    EnButte_SetupFlyAround(pthis);
    pthis->actor.shape.rot.x -= 0x2320;
    pthis->drawSkelAnime = true;
    // "field keep butterfly"
    osSyncPrintf("(field keep 蝶)(%x)(arg_data 0x%04x)\n", pthis, pthis->actor.params);
}

void EnButte_Destroy(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnButte* pthis = (EnButte*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void func_809CD56C(EnButte* pthis) {
    static f32 D_809CE3E0[] = { 50.0f, 80.0f, 100.0f };
    static f32 D_809CE3EC[] = { 30.0f, 40.0f, 50.0f };

    pthis->actor.shape.yOffset += Math_SinS(pthis->unk_25C) * D_809CE3E0[pthis->flightParamsIdx] +
                                 Math_SinS(pthis->unk_25E) * D_809CE3EC[pthis->flightParamsIdx];
    pthis->actor.shape.yOffset = CLAMP(pthis->actor.shape.yOffset, -2000.0f, 2000.0f);
}

void func_809CD634(EnButte* pthis) {
    static f32 D_809CE3F8[] = { 15.0f, 20.0f, 25.0f };
    static f32 D_809CE404[] = { 7.5f, 10.0f, 12.5f };

    pthis->actor.shape.yOffset += Math_SinS(pthis->unk_25C) * D_809CE3F8[pthis->flightParamsIdx] +
                                 Math_SinS(pthis->unk_25E) * D_809CE404[pthis->flightParamsIdx];
    pthis->actor.shape.yOffset = CLAMP(pthis->actor.shape.yOffset, -500.0f, 500.0f);
}

void EnButte_Turn(EnButte* pthis) {
    s16 target = pthis->actor.world.rot.y + 0x8000;
    s16 diff = target - pthis->actor.shape.rot.y;

    Math_ScaledStepToS(&pthis->actor.shape.rot.y, target, ABS(diff) >> 3);
    pthis->actor.shape.rot.x = (s16)(sinf(pthis->unk_260) * 600.0f) - 0x2320;
}

void EnButte_SetupFlyAround(EnButte* pthis) {
    EnButte_SelectFlightParams(pthis, &sFlyAroundParams[pthis->flightParamsIdx]);
    pthis->actionFunc = EnButte_FlyAround;
}

void EnButte_FlyAround(EnButte* pthis, GlobalContext* globalCtx) {
    EnButteFlightParams* flightParams = &sFlyAroundParams[pthis->flightParamsIdx];
    s16 yaw;
    Player* player = GET_PLAYER(globalCtx);
    f32 distSqFromHome;
    f32 maxDistSqFromHome;
    f32 minAnimSpeed;
    f32 animSpeed;
    s16 rotStep;

    distSqFromHome = Math3D_Dist2DSq(pthis->actor.world.pos.x, pthis->actor.world.pos.z, pthis->actor.home.pos.x,
                                     pthis->actor.home.pos.z);
    func_809CD56C(pthis);
    Math_SmoothStepToF(&pthis->actor.speedXZ, flightParams->speedXZTarget, flightParams->speedXZScale,
                       flightParams->speedXZStep, 0.0f);

    if (pthis->unk_257 == 1) {
        maxDistSqFromHome = SQ(100.0f);
        rotStep = 1000;
    } else {
        maxDistSqFromHome = SQ(35.0f);
        rotStep = 600;
    }

    minAnimSpeed = 0.0f;
    pthis->posYTarget = pthis->actor.home.pos.y;

    if ((pthis->flightParamsIdx != 0) && ((distSqFromHome > maxDistSqFromHome) || (pthis->timer < 4))) {
        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
        if (Math_ScaledStepToS(&pthis->actor.world.rot.y, yaw, flightParams->rotYStep) == 0) {
            minAnimSpeed = 0.5f;
        }
    } else if ((pthis->unk_257 == 0) && (pthis->actor.child != NULL) && (pthis->actor.child != &pthis->actor)) {
        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.child->world.pos);
        if (Math_ScaledStepToS(&pthis->actor.world.rot.y, yaw, rotStep) == 0) {
            minAnimSpeed = 0.3f;
        }
    } else if (pthis->unk_257 == 1) {
        yaw = pthis->actor.yawTowardsPlayer + 0x8000 + (s16)((Rand_ZeroOne() - 0.5f) * 0x6000);
        if (Math_ScaledStepToS(&pthis->actor.world.rot.y, yaw, rotStep) == 0) {
            minAnimSpeed = 0.4f;
        }
    } else {
        pthis->actor.world.rot.y += (s16)(sinf(pthis->unk_25C) * 100.0f);
    }

    EnButte_Turn(pthis);

    animSpeed = pthis->actor.speedXZ / 2.0f + Rand_ZeroOne() * 0.2f + (1.0f - Math_SinS(pthis->unk_260)) * 0.15f +
                (1.0f - Math_SinS(pthis->unk_25E)) * 0.3f + minAnimSpeed;
    pthis->skelAnime.playSpeed = CLAMP(animSpeed, 0.2f, 1.5f);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer <= 0) {
        EnButte_SelectFlightParams(pthis, &sFlyAroundParams[pthis->flightParamsIdx]);
    }

    if (((pthis->actor.params & 1) == 1) && (player->heldItemActionParam == PLAYER_AP_STICK) &&
        (pthis->swordDownTimer <= 0) &&
        ((Math3D_Dist2DSq(player->actor.world.pos.x, player->actor.world.pos.z, pthis->actor.home.pos.x,
                          pthis->actor.home.pos.z) < SQ(120.0f)) ||
         (pthis->actor.xzDistToPlayer < 60.0f))) {
        EnButte_SetupFollowLink(pthis);
        pthis->unk_257 = 2;
    } else if (pthis->actor.xzDistToPlayer < 120.0) {
        pthis->unk_257 = 1;
    } else {
        pthis->unk_257 = 0;
    }
}

void EnButte_SetupFollowLink(EnButte* pthis) {
    EnButte_SelectFlightParams(pthis, &sFollowLinkParams[pthis->flightParamsIdx]);
    pthis->actionFunc = EnButte_FollowLink;
}

void EnButte_FollowLink(EnButte* pthis, GlobalContext* globalCtx) {
    static s32 D_809CE410 = 1500;
    EnButteFlightParams* flightParams = &sFollowLinkParams[pthis->flightParamsIdx];
    Player* player = GET_PLAYER(globalCtx);
    f32 distSqFromHome;
    Vec3f swordTip;
    f32 animSpeed;
    f32 minAnimSpeed;
    f32 distSqFromSword;
    s16 yaw;

    func_809CD634(pthis);
    Math_SmoothStepToF(&pthis->actor.speedXZ, flightParams->speedXZTarget, flightParams->speedXZScale,
                       flightParams->speedXZStep, 0.0f);
    minAnimSpeed = 0.0f;

    if ((pthis->flightParamsIdx != 0) && (pthis->timer < 12)) {
        swordTip.x = player->swordInfo[0].tip.x + Math_SinS(player->actor.shape.rot.y) * 10.0f;
        swordTip.y = player->swordInfo[0].tip.y;
        swordTip.z = player->swordInfo[0].tip.z + Math_CosS(player->actor.shape.rot.y) * 10.0f;

        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &swordTip) + (s16)(Rand_ZeroOne() * D_809CE410);
        if (Math_ScaledStepToS(&pthis->actor.world.rot.y, yaw, 2000) != 0) {
            if (globalCtx->gameplayFrames % 2) {
                pthis->actor.world.rot.y += (s16)(sinf(pthis->unk_25C) * 60.0f);
            }
        } else {
            minAnimSpeed = 0.3f;
        }
    }

    pthis->posYTarget = MAX(player->actor.world.pos.y + 30.0f, player->swordInfo[0].tip.y);

    EnButte_Turn(pthis);

    animSpeed = pthis->actor.speedXZ / 2.0f + Rand_ZeroOne() * 0.2f + (1.0f - Math_SinS(pthis->unk_260)) * 0.15f +
                (1.0f - Math_SinS(pthis->unk_25E)) * 0.3f + minAnimSpeed;
    pthis->skelAnime.playSpeed = CLAMP(animSpeed, 0.2f, 1.5f);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer <= 0) {
        EnButte_SelectFlightParams(pthis, &sFollowLinkParams[pthis->flightParamsIdx]);
        D_809CE410 = -D_809CE410;
    }

    distSqFromHome = Math3D_Dist2DSq(pthis->actor.world.pos.x, pthis->actor.world.pos.z, pthis->actor.home.pos.x,
                                     pthis->actor.home.pos.z);
    if (!((player->heldItemActionParam == PLAYER_AP_STICK) && (fabsf(player->actor.speedXZ) < 1.8f) &&
          (pthis->swordDownTimer <= 0) && (distSqFromHome < SQ(320.0f)))) {
        EnButte_SetupFlyAround(pthis);
    } else if (distSqFromHome > SQ(240.0f)) {
        distSqFromSword = Math3D_Dist2DSq(player->swordInfo[0].tip.x, player->swordInfo[0].tip.z,
                                          pthis->actor.world.pos.x, pthis->actor.world.pos.z);
        if (distSqFromSword < SQ(60.0f)) {
            EnButte_SetupTransformIntoFairy(pthis);
        }
    }
}

void EnButte_SetupTransformIntoFairy(EnButte* pthis) {
    pthis->timer = 9;
    pthis->actor.flags |= ACTOR_FLAG_4;
    pthis->skelAnime.playSpeed = 1.0f;
    EnButte_ResetTransformationEffect();
    pthis->actionFunc = EnButte_TransformIntoFairy;
}

void EnButte_TransformIntoFairy(EnButte* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    EnButte_UpdateTransformationEffect();

    if (pthis->timer == 5) {
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 60, NA_SE_EV_BUTTERFRY_TO_FAIRY);
    } else if (pthis->timer == 4) {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ELF, pthis->actor.focus.pos.x, pthis->actor.focus.pos.y,
                    pthis->actor.focus.pos.z, 0, pthis->actor.shape.rot.y, 0, FAIRY_HEAL_TIMED);
        pthis->drawSkelAnime = false;
    } else if (pthis->timer <= 0) {
        EnButte_SetupWaitToDie(pthis);
    }
}

void EnButte_SetupWaitToDie(EnButte* pthis) {
    pthis->timer = 64;
    pthis->actionFunc = EnButte_WaitToDie;
    pthis->actor.draw = NULL;
}

void EnButte_WaitToDie(EnButte* pthis, GlobalContext* globalCtx) {
    if (pthis->timer <= 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnButte_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnButte* pthis = (EnButte*)thisx;

    if ((pthis->actor.child != NULL) && (pthis->actor.child->update == NULL) && (pthis->actor.child != &pthis->actor)) {
        pthis->actor.child = NULL;
    }

    if (pthis->timer > 0) {
        pthis->timer--;
    }

    pthis->unk_25C += 0x222;
    pthis->unk_25E += 0x1000;
    pthis->unk_260 += 0x600;

    if ((pthis->actor.params & 1) == 1) {
        if (GET_PLAYER(globalCtx)->swordState == 0) {
            if (pthis->swordDownTimer > 0) {
                pthis->swordDownTimer--;
            }
        } else {
            pthis->swordDownTimer = 80;
        }
    }

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->actor.update != NULL) {
        Actor_MoveForward(&pthis->actor);
        Math_StepToF(&pthis->actor.world.pos.y, pthis->posYTarget, 0.6f);
        if (pthis->actor.xyzDistToPlayerSq < 5000.0f) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        Actor_SetFocus(&pthis->actor, pthis->actor.shape.yOffset * pthis->actor.scale.y);
    }
}

void EnButte_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnButte* pthis = (EnButte*)thisx;

    if (pthis->drawSkelAnime) {
        func_80093D18(globalCtx->state.gfxCtx);
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL, NULL, NULL);
        Collider_UpdateSpheres(0, &pthis->collider);
    }

    if (((pthis->actor.params & 1) == 1) && (pthis->actionFunc == EnButte_TransformIntoFairy)) {
        EnButte_DrawTransformationEffect(pthis, globalCtx);
    }
}
