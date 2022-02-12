#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_PO_DESERT_Z_EN_PO_DESERT_C
#include "actor_common.h"
/*
 * File: z_en_po_desert.c
 * Overlay: ovl_En_Po_Desert
 * Description: Guide Poe (Haunted Wasteland)
 */

#include "z_en_po_desert.h"
#include "objects/object_po_field/object_po_field.h"
#include "def/code_800FD970.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_message_PAL.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_7 | ACTOR_FLAG_12)

void EnPoDesert_Init(Actor* thisx, GlobalContext* globalCtx);
void EnPoDesert_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnPoDesert_Update(Actor* thisx, GlobalContext* globalCtx);
void EnPoDesert_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnPoDesert_SetNextPathPoint(EnPoDesert* pthis, GlobalContext* globalCtx);
void EnPoDesert_WaitForPlayer(EnPoDesert* pthis, GlobalContext* globalCtx);
void EnPoDesert_MoveToNextPoint(EnPoDesert* pthis, GlobalContext* globalCtx);
void EnPoDesert_Disappear(EnPoDesert* pthis, GlobalContext* globalCtx);

ActorInit En_Po_Desert_InitVars = {
    ACTOR_EN_PO_DESERT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_PO_FIELD,
    sizeof(EnPoDesert),
    (ActorFunc)EnPoDesert_Init,
    (ActorFunc)EnPoDesert_Destroy,
    (ActorFunc)EnPoDesert_Update,
    (ActorFunc)EnPoDesert_Draw,
};

static ColliderCylinderInit sColliderInit = {
    {
        COLTYPE_HIT3,
        AT_NONE,
        AC_NONE,
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
    { 25, 50, 20, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x5C, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 3200, ICHAIN_STOP),
};

void EnPoDesert_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnPoDesert* pthis = (EnPoDesert*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gPoeFieldSkel, &gPoeFieldFloatAnim, pthis->jointTable, pthis->morphTable,
                   10);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sColliderInit);
    pthis->lightColor.r = 255;
    pthis->lightColor.g = 255;
    pthis->lightColor.b = 210;
    pthis->lightColor.a = 255;
    pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z,
                              255, 255, 255, 200);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 37.0f);
    pthis->currentPathPoint = 1;
    pthis->actor.params = (pthis->actor.params >> 8) & 0xFF;
    pthis->targetY = pthis->actor.world.pos.y;
    EnPoDesert_SetNextPathPoint(pthis, globalCtx);
}

void EnPoDesert_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnPoDesert* pthis = (EnPoDesert*)thisx;

    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnPoDesert_SetNextPathPoint(EnPoDesert* pthis, GlobalContext* globalCtx) {
    Path* path = &globalCtx->setupPathList[pthis->actor.params];
    Vec3s* pathPoint;

    Animation_MorphToLoop(&pthis->skelAnime, &gPoeFieldDisappearAnim, -6.0f);
    pathPoint = &((Vec3s*)SEGMENTED_TO_VIRTUAL(path->points))[pthis->currentPathPoint];
    pthis->actor.home.pos.x = pathPoint->x;
    pthis->actor.home.pos.y = pathPoint->y;
    pthis->actor.home.pos.z = pathPoint->z;
    pthis->initDistToNextPoint = Actor_WorldDistXZToPoint(&pthis->actor, &pthis->actor.home.pos);
    pthis->initDistToNextPoint = CLAMP_MIN(pthis->initDistToNextPoint, 1.0f);
    pthis->currentPathPoint++;
    pthis->yDiff = pthis->actor.home.pos.y - pthis->actor.world.pos.y;
    pthis->actor.speedXZ = 0.0f;
    if (path->count == pthis->currentPathPoint) {
        pthis->currentPathPoint = 0;
    }
    pthis->actionFunc = EnPoDesert_WaitForPlayer;
}

void EnPoDesert_SetupMoveToNextPoint(EnPoDesert* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeFieldFloatAnim, -5.0f);
    pthis->actionFunc = EnPoDesert_MoveToNextPoint;
}

void EnPoDesert_SetupDisappear(EnPoDesert* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gPoeFieldDisappearAnim, -6.0f);
    pthis->actionTimer = 16;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DISAPPEAR);
    pthis->actionFunc = EnPoDesert_Disappear;
}

void EnPoDesert_UpdateSpeedModifier(EnPoDesert* pthis) {
    if (pthis->speedModifier == 0) {
        pthis->speedModifier = 32;
    }
    if (pthis->speedModifier != 0) {
        pthis->speedModifier--;
    }
    pthis->actor.world.pos.y = Math_SinS(pthis->speedModifier * 0x800) * 13.0f + pthis->targetY;
}

void EnPoDesert_WaitForPlayer(EnPoDesert* pthis, GlobalContext* globalCtx) {
    func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
    if (pthis->actor.xzDistToPlayer < 200.0f && (pthis->currentPathPoint != 2 || globalCtx->actorCtx.unk_03)) {
        if (pthis->currentPathPoint == 2) {
            if (Gameplay_InCsMode(globalCtx)) {
                pthis->actor.shape.rot.y += 0x800;
                return;
            }
            Message_StartTextbox(globalCtx, 0x600B, NULL);
        }
        EnPoDesert_SetupMoveToNextPoint(pthis);
    } else {
        pthis->actor.shape.rot.y += 0x800;
    }
}

void EnPoDesert_MoveToNextPoint(EnPoDesert* pthis, GlobalContext* globalCtx) {
    f32 temp_f20;

    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    temp_f20 = sinf(pthis->actionTimer * (M_PI / 20.0f)) * 5.0f;
    pthis->actor.world.pos.x += temp_f20 * Math_CosS(pthis->actor.shape.rot.y);
    pthis->actor.world.pos.z += temp_f20 * Math_SinS(pthis->actor.shape.rot.y);
    if (pthis->actionTimer == 0) {
        pthis->actionTimer = 40;
    }
    temp_f20 = Actor_WorldDistXZToPoint(&pthis->actor, &pthis->actor.home.pos);
    pthis->actor.world.rot.y = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos);
    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.y + 0x8000, 5, 0x400);
    pthis->actor.speedXZ = sinf(pthis->speedModifier * (M_PI / 32.0f)) * 2.5f + 5.5f;
    func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
    pthis->targetY = pthis->actor.home.pos.y - ((temp_f20 * pthis->yDiff) / pthis->initDistToNextPoint);
    if (temp_f20 < 40.0f) {
        if (pthis->currentPathPoint != 0) {
            EnPoDesert_SetNextPathPoint(pthis, globalCtx);
        } else {
            EnPoDesert_SetupDisappear(pthis);
        }
    }
}

void EnPoDesert_Disappear(EnPoDesert* pthis, GlobalContext* globalCtx) {
    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    pthis->actor.shape.rot.y += 0x2000;
    pthis->lightColor.a = pthis->actionTimer * 15.9375f;
    pthis->actor.shape.shadowAlpha = pthis->lightColor.a;
    if (pthis->actionTimer == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnPoDesert_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnPoDesert* pthis = (EnPoDesert*)thisx;
    s32 pad;

    SkelAnime_Update(&pthis->skelAnime);
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    EnPoDesert_UpdateSpeedModifier(pthis);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 27.0f, 60.0f, 4);
    Actor_SetFocus(&pthis->actor, 42.0f);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    if (globalCtx->actorCtx.unk_03) {
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_7;
        pthis->actor.shape.shadowDraw = ActorShadow_DrawCircle;
    } else {
        pthis->actor.shape.shadowDraw = NULL;
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_7);
    }
}

s32 EnPoDesert_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx, Gfx** gfxP) {
    EnPoDesert* pthis = (EnPoDesert*)thisx;
    f32 mtxScale;

    if (pthis->actionFunc == EnPoDesert_Disappear && limbIndex == 7) {
        mtxScale = pthis->actionTimer / 16.0f;
        Matrix_Scale(mtxScale, mtxScale, mtxScale, MTXMODE_APPLY);
    }
    if (!CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7)) {
        *dList = NULL;
    }
    return false;
}

void EnPoDesert_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx,
                             Gfx** gfxP) {
    static Vec3f baseLightPos = { 0.0f, 1400.0f, 0.0f };

    EnPoDesert* pthis = (EnPoDesert*)thisx;
    f32 rand;
    Color_RGBA8 color;
    Vec3f lightPos;

    if (limbIndex == 7) {
        Matrix_MultVec3f(&baseLightPos, &lightPos);
        rand = Rand_ZeroOne();
        color.r = (s16)(rand * 30.0f) + 225;
        color.g = (s16)(rand * 100.0f) + 155;
        color.b = (s16)(rand * 160.0f) + 95;
        if (CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7)) {
            gDPPipeSync((*gfxP)++);
            gDPSetEnvColor((*gfxP)++, color.r, color.g, color.b, 255);
            gSPMatrix((*gfxP)++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_po_desert.c", 523),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList((*gfxP)++, gPoeFieldLanternDL);
            gSPDisplayList((*gfxP)++, gPoeFieldLanternTopDL);
            gDPPipeSync((*gfxP)++);
            gDPSetEnvColor((*gfxP)++, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b, pthis->lightColor.a);
        }
        Lights_PointNoGlowSetInfo(&pthis->lightInfo, lightPos.x, lightPos.y, lightPos.z, color.r, color.g, color.b, 200);
    }
}

void EnPoDesert_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnPoDesert* pthis = (EnPoDesert*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_po_desert.c", 559);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x0A, Gfx_EnvColor(globalCtx->state.gfxCtx, 255, 85, 0, 255));
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_EnvColor(globalCtx->state.gfxCtx, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b,
                            pthis->lightColor.a));
    if (pthis->actionFunc == EnPoDesert_Disappear) {
        gSPSegment(POLY_XLU_DISP++, 0x0C, D_80116280);
    } else {
        gSPSegment(POLY_XLU_DISP++, 0x0C, D_80116280 + 2);
    }
    POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                   EnPoDesert_OverrideLimbDraw, EnPoDesert_PostLimbDraw, &pthis->actor, POLY_XLU_DISP);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_po_desert.c", 597);
}
