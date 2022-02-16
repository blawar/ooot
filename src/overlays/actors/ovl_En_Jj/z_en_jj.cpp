#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_JJ_Z_EN_JJ_C
#include "actor_common.h"
/*
 * File: z_en_jj.c
 * Overlay: ovl_En_Jj
 * Description: Lord Jabu-Jabu
 */

#include "z_en_jj.h"
#include "objects/object_jj/object_jj.h"
#include "overlays/actors/ovl_Eff_Dust/z_eff_dust.h"
#include "def/code_80043480.h"
#include "def/cosf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)


void EnJj_Init(Actor* thisx, GlobalContext* globalCtx);
void EnJj_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnJj_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnJj_Update(Actor* thisx, GlobalContext* globalCtx);
void EnJj_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnJj_UpdateStaticCollision(Actor* thisx, GlobalContext* globalCtx);
void EnJj_WaitToOpenMouth(EnJj* pthis, GlobalContext* globalCtx);
void EnJj_WaitForFish(EnJj* pthis, GlobalContext* globalCtx);
void EnJj_BeginCutscene(EnJj* pthis, GlobalContext* globalCtx);
void EnJj_RemoveDust(EnJj* pthis, GlobalContext* globalCtx);

static Vec3f feedingSpot_45 = { -1589.0f, 53.0f, -43.0f };

static void* eyeTextures_51[] = { gJabuJabuEyeOpenTex, gJabuJabuEyeHalfTex, gJabuJabuEyeClosedTex };


ActorInit En_Jj_InitVars = {
    ACTOR_EN_JJ,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_JJ,
    sizeof(EnJj),
    (ActorFunc)EnJj_Init,
    (ActorFunc)EnJj_Destroy,
    (ActorFunc)EnJj_Update,
    (ActorFunc)EnJj_Draw,
    (ActorFunc)EnJj_Reset,
};

static s32 sUnused = 0;

#include "z_en_jj_cutscene_data.cpp" EARLY

static s32 sUnused2[] = { 0, 0 };

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000004, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 170, 150, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 87, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 3300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1100, ICHAIN_STOP),
};

void EnJj_SetupAction(EnJj* pthis, EnJjActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnJj_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnJj* pthis = (EnJj*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    ActorShape_Init(&pthis->dyna.actor.shape, 0.0f, NULL, 0.0f);

    switch (pthis->dyna.actor.params) {
        case JABUJABU_MAIN:
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gJabuJabuSkel, &gJabuJabuAnim, pthis->jointTable,
                               pthis->morphTable, 22);
            Animation_PlayLoop(&pthis->skelAnime, &gJabuJabuAnim);
            pthis->unk_30A = 0;
            pthis->eyeIndex = 0;
            pthis->blinkTimer = 0;
            pthis->extraBlinkCounter = 0;
            pthis->extraBlinkTotal = 0;

            if (gSaveContext.eventChkInf[3] & 0x400) { // Fish given
                EnJj_SetupAction(pthis, EnJj_WaitToOpenMouth);
            } else {
                EnJj_SetupAction(pthis, EnJj_WaitForFish);
            }

            pthis->bodyCollisionActor = (DynaPolyActor*)Actor_SpawnAsChild(
                &globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_EN_JJ, pthis->dyna.actor.world.pos.x - 10.0f,
                pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z, 0, pthis->dyna.actor.world.rot.y, 0,
                JABUJABU_COLLISION);
            DynaPolyActor_Init(&pthis->dyna, 0);
            CollisionHeader_GetVirtual(&gJabuJabuHeadCol, &colHeader);
            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->dyna.actor, &sCylinderInit);
            pthis->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
            break;

        case JABUJABU_COLLISION:
            DynaPolyActor_Init(&pthis->dyna, 0);
            CollisionHeader_GetVirtual(&gJabuJabuBodyCol, &colHeader);
            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
            func_8003ECA8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
            pthis->dyna.actor.update = EnJj_UpdateStaticCollision;
            pthis->dyna.actor.draw = NULL;
            Actor_SetScale(&pthis->dyna.actor, 0.087f);
            break;

        case JABUJABU_UNUSED_COLLISION:
            DynaPolyActor_Init(&pthis->dyna, 0);
            CollisionHeader_GetVirtual(&gJabuJabuUnusedCol, &colHeader);
            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
            pthis->dyna.actor.update = EnJj_UpdateStaticCollision;
            pthis->dyna.actor.draw = NULL;
            Actor_SetScale(&pthis->dyna.actor, 0.087f);
            break;
    }
}

void EnJj_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnJj* pthis = (EnJj*)thisx;

    switch (pthis->dyna.actor.params) {
        case JABUJABU_MAIN:
            DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
            Collider_DestroyCylinder(globalCtx, &pthis->collider);
            break;

        case JABUJABU_COLLISION:
        case JABUJABU_UNUSED_COLLISION:
            DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
            break;
    }
}

/**
 * Blink routine. Blinks at the end of each randomised blinkTimer cycle. If extraBlinkCounter is not zero, blink that
 * many more times before resuming random blinkTimer cycles. extraBlinkTotal can be set to a positive number to blink
 * that many extra times at the end of every blinkTimer cycle, but the actor always sets it to zero, so only one
 * multiblink happens when extraBlinkCounter is nonzero.
 */
void EnJj_Blink(EnJj* pthis) {
    if (pthis->blinkTimer > 0) {
        pthis->blinkTimer--;
    } else {
        pthis->eyeIndex++;
        if (pthis->eyeIndex >= JABUJABU_EYE_MAX) {
            pthis->eyeIndex = JABUJABU_EYE_OPEN;
            if (pthis->extraBlinkCounter > 0) {
                pthis->extraBlinkCounter--;
            } else {
                pthis->blinkTimer = Rand_S16Offset(20, 20);
                pthis->extraBlinkCounter = pthis->extraBlinkTotal;
            }
        }
    }
}

void EnJj_OpenMouth(EnJj* pthis, GlobalContext* globalCtx) {
    DynaPolyActor* bodyCollisionActor = pthis->bodyCollisionActor;

    if (pthis->mouthOpenAngle >= -5200) {
        pthis->mouthOpenAngle -= 102;

        if (pthis->mouthOpenAngle < -2600) {
            func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, bodyCollisionActor->bgId);
        }
    }
}

void EnJj_WaitToOpenMouth(EnJj* pthis, GlobalContext* globalCtx) {
    if (pthis->dyna.actor.xzDistToPlayer < 300.0f) {
        EnJj_SetupAction(pthis, EnJj_OpenMouth);
    }
}

void EnJj_WaitForFish(EnJj* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((Math_Vec3f_DistXZ(&feedingSpot_45, &player->actor.world.pos) < 300.0f) &&
        globalCtx->isPlayerDroppingFish(globalCtx)) {
        pthis->cutsceneCountdownTimer = 100;
        EnJj_SetupAction(pthis, EnJj_BeginCutscene);
    }

    pthis->collider.dim.pos.x = -1245;
    pthis->collider.dim.pos.y = 20;
    pthis->collider.dim.pos.z = -48;
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnJj_BeginCutscene(EnJj* pthis, GlobalContext* globalCtx) {
    DynaPolyActor* bodyCollisionActor = pthis->bodyCollisionActor;

    if (pthis->cutsceneCountdownTimer > 0) {
        pthis->cutsceneCountdownTimer--;
    } else {
        EnJj_SetupAction(pthis, EnJj_RemoveDust);
        globalCtx->csCtx.segment = &D_80A88164;
        gSaveContext.cutsceneTrigger = 1;
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, bodyCollisionActor->bgId);
        func_8005B1A4(GET_ACTIVE_CAM(globalCtx));
        gSaveContext.eventChkInf[3] |= 0x400;
        func_80078884(NA_SE_SY_CORRECT_CHIME);
    }
}

void EnJj_CutsceneUpdate(EnJj* pthis, GlobalContext* globalCtx) {
    switch (globalCtx->csCtx.npcActions[2]->action) {
        case 1:
            if (pthis->unk_30A & 2) {
                pthis->eyeIndex = 0;
                pthis->blinkTimer = Rand_S16Offset(20, 20);
                pthis->extraBlinkCounter = 0;
                pthis->extraBlinkTotal = 0;
                pthis->unk_30A ^= 2;
            }
            break;

        case 2:
            pthis->unk_30A |= 1;

            if (!(pthis->unk_30A & 8)) {
                pthis->dust = Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_EFF_DUST,
                                                -1100.0f, 105.0f, -27.0f, 0, 0, 0, EFF_DUST_TYPE_0);
                pthis->unk_30A |= 8;
            }
            break;

        case 3:
            if (!(pthis->unk_30A & 2)) {
                pthis->eyeIndex = 0;
                pthis->blinkTimer = 0;
                pthis->extraBlinkCounter = 1;
                pthis->extraBlinkTotal = 0;
                pthis->unk_30A |= 2;
            }
            break;
    }

    if (pthis->unk_30A & 1) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_JABJAB_BREATHE - SFX_FLAG);

        if (pthis->mouthOpenAngle >= -5200) {
            pthis->mouthOpenAngle -= 102;
        }
    }
}

void EnJj_RemoveDust(EnJj* pthis, GlobalContext* globalCtx) {
    Actor* dust;

    if (!(pthis->unk_30A & 4)) {
        pthis->unk_30A |= 4;
        dust = pthis->dust;

        if (dust != NULL) {
            Actor_Kill(dust);
            pthis->dyna.actor.child = NULL;
        }
    }
}

void EnJj_UpdateStaticCollision(Actor* thisx, GlobalContext* globalCtx) {
}

void EnJj_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnJj* pthis = (EnJj*)thisx;

    if ((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[2] != NULL)) {
        EnJj_CutsceneUpdate(pthis, globalCtx);
    } else {
        pthis->actionFunc(pthis, globalCtx);

        if (pthis->skelAnime.curFrame == 41.0f) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_JABJAB_GROAN);
        }
    }

    EnJj_Blink(pthis);
    SkelAnime_Update(&pthis->skelAnime);
    Actor_SetScale(&pthis->dyna.actor, 0.087f);

    // Head
    pthis->skelAnime.jointTable[10].z = pthis->mouthOpenAngle;
}

void EnJj_Draw(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnJj* pthis = (EnJj*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_jj.c", 879);

    func_800943C8(globalCtx->state.gfxCtx);
    Matrix_Translate(0.0f, (cosf(pthis->skelAnime.curFrame * (M_PI / 41.0f)) * 10.0f) - 10.0f, 0.0f, MTXMODE_APPLY);
    Matrix_Scale(10.0f, 10.0f, 10.0f, MTXMODE_APPLY);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures_51[pthis->eyeIndex]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_jj.c", 898);
}

void EnJj_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    feedingSpot_45 = { -1589.0f, 53.0f, -43.0f };

    En_Jj_InitVars = {
        ACTOR_EN_JJ,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_JJ,
        sizeof(EnJj),
        (ActorFunc)EnJj_Init,
        (ActorFunc)EnJj_Destroy,
        (ActorFunc)EnJj_Update,
        (ActorFunc)EnJj_Draw,
        (ActorFunc)EnJj_Reset,
    };

    sUnused = 0;

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000004, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 170, 150, 0, { 0, 0, 0 } },
    };

}
