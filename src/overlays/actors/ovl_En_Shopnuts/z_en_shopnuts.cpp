#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SHOPNUTS_Z_EN_SHOPNUTS_C
#include "actor_common.h"
#include "z_en_shopnuts.h"
#include "objects/object_shopnuts/object_shopnuts.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnShopnuts_Init(Actor* thisx, GlobalContext* globalCtx);
void EnShopnuts_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnShopnuts_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnShopnuts_Update(Actor* thisx, GlobalContext* globalCtx);
void EnShopnuts_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnShopnuts_SetupWait(EnShopnuts* pthis);
void EnShopnuts_Wait(EnShopnuts* pthis, GlobalContext* globalCtx);
void EnShopnuts_LookAround(EnShopnuts* pthis, GlobalContext* globalCtx);
void EnShopnuts_Stand(EnShopnuts* pthis, GlobalContext* globalCtx);
void EnShopnuts_ThrowNut(EnShopnuts* pthis, GlobalContext* globalCtx);
void EnShopnuts_Burrow(EnShopnuts* pthis, GlobalContext* globalCtx);
void EnShopnuts_SpawnSalesman(EnShopnuts* pthis, GlobalContext* globalCtx);

ActorInit En_Shopnuts_InitVars = {
    ACTOR_EN_SHOPNUTS,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SHOPNUTS,
    sizeof(EnShopnuts),
    (ActorFunc)EnShopnuts_Init,
    (ActorFunc)EnShopnuts_Destroy,
    (ActorFunc)EnShopnuts_Update,
    (ActorFunc)EnShopnuts_Draw,
    (ActorFunc)EnShopnuts_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT6,
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
    { 20, 40, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 1, 20, 40, 0xFE };

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x4E, ICHAIN_CONTINUE),
    ICHAIN_F32(gravity, -1, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2600, ICHAIN_STOP),
};

void EnShopnuts_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnShopnuts* pthis = (EnShopnuts*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 35.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBusinessScrubSkel, &gBusinessScrubAnim_4574, pthis->jointTable,
                       pthis->morphTable, 18);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

    if (((pthis->actor.params == 0x0002) && (gSaveContext.itemGetInf[0] & 0x800)) ||
        ((pthis->actor.params == 0x0009) && (gSaveContext.infTable[25] & 4)) ||
        ((pthis->actor.params == 0x000A) && (gSaveContext.infTable[25] & 8))) {
        Actor_Kill(&pthis->actor);
    } else {
        EnShopnuts_SetupWait(pthis);
    }
}

void EnShopnuts_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnShopnuts* pthis = (EnShopnuts*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnShopnuts_SetupWait(EnShopnuts* pthis) {
    Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gBusinessScrubAnim_139C, 0.0f);
    pthis->animFlagAndTimer = Rand_S16Offset(100, 50);
    pthis->collider.dim.height = 5;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnShopnuts_Wait;
}

void EnShopnuts_SetupLookAround(EnShopnuts* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gBusinessScrubLookAroundAnim);
    pthis->animFlagAndTimer = 2;
    pthis->actionFunc = EnShopnuts_LookAround;
}

void EnShopnuts_SetupThrowNut(EnShopnuts* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gBusinessScrubAnim_1EC);
    pthis->actionFunc = EnShopnuts_ThrowNut;
}

void EnShopnuts_SetupStand(EnShopnuts* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gBusinessScrubAnim_4574, -3.0f);
    if (pthis->actionFunc == EnShopnuts_ThrowNut) {
        pthis->animFlagAndTimer = 2 | 0x1000; // sets timer and flag
    } else {
        pthis->animFlagAndTimer = 1;
    }
    pthis->actionFunc = EnShopnuts_Stand;
}

void EnShopnuts_SetupBurrow(EnShopnuts* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBusinessScrubAnim_39C, -5.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DOWN);
    pthis->actionFunc = EnShopnuts_Burrow;
}

void EnShopnuts_SetupSpawnSalesman(EnShopnuts* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBusinessScrubRotateAnim, -3.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DAMAGE);
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnShopnuts_SpawnSalesman;
}

void EnShopnuts_Wait(EnShopnuts* pthis, GlobalContext* globalCtx) {
    s32 hasSlowPlaybackSpeed = false;

    if (pthis->skelAnime.playSpeed < 0.5f) {
        hasSlowPlaybackSpeed = true;
    }
    if (hasSlowPlaybackSpeed && (pthis->animFlagAndTimer != 0)) {
        pthis->animFlagAndTimer--;
    }
    if (Animation_OnFrame(&pthis->skelAnime, 9.0f)) {
        pthis->collider.base.acFlags |= AC_ON;
    } else if (Animation_OnFrame(&pthis->skelAnime, 8.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
    }

    pthis->collider.dim.height = ((CLAMP(pthis->skelAnime.curFrame, 9.0f, 13.0f) - 9.0f) * 9.0f) + 5.0f;
    if (!hasSlowPlaybackSpeed && (pthis->actor.xzDistToPlayer < 120.0f)) {
        EnShopnuts_SetupBurrow(pthis);
    } else if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.xzDistToPlayer < 120.0f) {
            EnShopnuts_SetupBurrow(pthis);
        } else if ((pthis->animFlagAndTimer == 0) && (pthis->actor.xzDistToPlayer > 320.0f)) {
            EnShopnuts_SetupLookAround(pthis);
        } else {
            EnShopnuts_SetupStand(pthis);
        }
    }
    if (hasSlowPlaybackSpeed &&
        ((pthis->actor.xzDistToPlayer > 160.0f) && (fabsf(pthis->actor.yDistToPlayer) < 120.0f)) &&
        ((pthis->animFlagAndTimer == 0) || (pthis->actor.xzDistToPlayer < 480.0f))) {
        pthis->skelAnime.playSpeed = 1.0f;
    }
}

void EnShopnuts_LookAround(EnShopnuts* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && (pthis->animFlagAndTimer != 0)) {
        pthis->animFlagAndTimer--;
    }
    if ((pthis->actor.xzDistToPlayer < 120.0f) || (pthis->animFlagAndTimer == 0)) {
        EnShopnuts_SetupBurrow(pthis);
    }
}

void EnShopnuts_Stand(EnShopnuts* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && (pthis->animFlagAndTimer != 0)) {
        pthis->animFlagAndTimer--;
    }
    if (!(pthis->animFlagAndTimer & 0x1000)) {
        Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
    }
    if ((pthis->actor.xzDistToPlayer < 120.0f) || (pthis->animFlagAndTimer == 0x1000)) {
        EnShopnuts_SetupBurrow(pthis);
    } else if (pthis->animFlagAndTimer == 0) {
        EnShopnuts_SetupThrowNut(pthis);
    }
}

void EnShopnuts_ThrowNut(EnShopnuts* pthis, GlobalContext* globalCtx) {
    Vec3f spawnPos;

    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
    if (pthis->actor.xzDistToPlayer < 120.0f) {
        EnShopnuts_SetupBurrow(pthis);
    } else if (SkelAnime_Update(&pthis->skelAnime)) {
        EnShopnuts_SetupStand(pthis);
    } else if (Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
        spawnPos.x = pthis->actor.world.pos.x + (Math_SinS(pthis->actor.shape.rot.y) * 23.0f);
        spawnPos.y = pthis->actor.world.pos.y + 12.0f;
        spawnPos.z = pthis->actor.world.pos.z + (Math_CosS(pthis->actor.shape.rot.y) * 23.0f);
        if (Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_NUTSBALL, spawnPos.x, spawnPos.y, spawnPos.z,
                        pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, 2) != NULL) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_THROW);
        }
    }
}

void EnShopnuts_Burrow(EnShopnuts* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnShopnuts_SetupWait(pthis);
    } else {
        pthis->collider.dim.height = ((4.0f - CLAMP_MAX(pthis->skelAnime.curFrame, 4.0f)) * 10.0f) + 5.0f;
    }
    if (Animation_OnFrame(&pthis->skelAnime, 4.0f)) {
        pthis->collider.base.acFlags &= ~AC_ON;
    }
}

void EnShopnuts_SpawnSalesman(EnShopnuts* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_DNS, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                    pthis->actor.world.pos.z, pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, pthis->actor.shape.rot.z,
                    pthis->actor.params);
        Actor_Kill(&pthis->actor);
    } else {
        Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
    }
}

void EnShopnuts_ColliderCheck(EnShopnuts* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);
        EnShopnuts_SetupSpawnSalesman(pthis);
    } else if (globalCtx->actorCtx.unk_02 != 0) {
        EnShopnuts_SetupSpawnSalesman(pthis);
    }
}

void EnShopnuts_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnShopnuts* pthis = (EnShopnuts*)thisx;

    EnShopnuts_ColliderCheck(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, pthis->collider.dim.radius, pthis->collider.dim.height, 4);
    if (pthis->collider.base.acFlags & AC_ON) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    if (pthis->actionFunc == EnShopnuts_Wait) {
        Actor_SetFocus(&pthis->actor, pthis->skelAnime.curFrame);
    } else if (pthis->actionFunc == EnShopnuts_Burrow) {
        Actor_SetFocus(&pthis->actor,
                       20.0f - ((pthis->skelAnime.curFrame * 20.0f) / Animation_GetLastFrame(&gBusinessScrubAnim_39C)));
    } else {
        Actor_SetFocus(&pthis->actor, 20.0f);
    }
}

s32 EnShopnuts_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx) {
    EnShopnuts* pthis = (EnShopnuts*)thisx;

    if ((limbIndex == 9) && (pthis->actionFunc == EnShopnuts_ThrowNut)) {
        *dList = NULL;
    }
    return 0;
}

void EnShopnuts_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnShopnuts* pthis = (EnShopnuts*)thisx;

    f32 curFrame;
    f32 x;
    f32 y;
    f32 z;

    if ((limbIndex == 9) && (pthis->actionFunc == EnShopnuts_ThrowNut)) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_shopnuts.c", 682);
        curFrame = pthis->skelAnime.curFrame;
        if (curFrame <= 6.0f) {
            y = 1.0f - (curFrame * 0.0833f);
            x = z = (curFrame * 0.1167f) + 1.0f;
        } else if (curFrame <= 7.0f) {
            curFrame -= 6.0f;
            y = 0.5f + curFrame;
            x = z = 1.7f - (curFrame * 0.7f);
        } else if (curFrame <= 10.0f) {
            y = 1.5f - ((curFrame - 7.0f) * 0.1667f);
            x = z = 1.0f;
        } else {
            x = y = z = 1.0f;
        }

        Matrix_Scale(x, y, z, MTXMODE_APPLY);
        if (1) {}
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_shopnuts.c", 714),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gBusinessScrubNoseDL);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_shopnuts.c", 717);
    }
}

void EnShopnuts_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnShopnuts* pthis = (EnShopnuts*)thisx;

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnShopnuts_OverrideLimbDraw, EnShopnuts_PostLimbDraw, pthis);
}

void EnShopnuts_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Shopnuts_InitVars = {
        ACTOR_EN_SHOPNUTS,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_SHOPNUTS,
        sizeof(EnShopnuts),
        (ActorFunc)EnShopnuts_Init,
        (ActorFunc)EnShopnuts_Destroy,
        (ActorFunc)EnShopnuts_Update,
        (ActorFunc)EnShopnuts_Draw,
        (ActorFunc)EnShopnuts_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_HIT6,
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
        { 20, 40, 0, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 1, 20, 40, 0xFE };

}
