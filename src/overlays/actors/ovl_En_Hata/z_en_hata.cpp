#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HATA_Z_EN_HATA_C
#include "actor_common.h"
/*
 * File: z_en_hata.c
 * Overlay: ovl_En_Hata
 * Description: Wooden post with red cloth
 */

#include "z_en_hata.h"
#include "objects/object_hata/object_hata.h"
#include "def/code_80043480.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS 0

void EnHata_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHata_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnHata_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHata_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHata_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Hata_InitVars = {
    ACTOR_EN_HATA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_HATA,
    sizeof(EnHata),
    (ActorFunc)EnHata_Init,
    (ActorFunc)EnHata_Destroy,
    (ActorFunc)EnHata_Update,
    (ActorFunc)EnHata_Draw,
    (ActorFunc)EnHata_Reset,
};

// Unused Collider and CollisionCheck data
static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000080, 0x00, 0x00 },
        TOUCH_NONE | TOUCH_SFX_NORMAL,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 16, 246, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

void EnHata_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHata* pthis = (EnHata*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;
    f32 frameCount = Animation_GetLastFrame(&gFlagpoleFlapAnim);

    Actor_SetScale(&pthis->dyna.actor, 1.0f / 75.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gFlagpoleSkel, &gFlagpoleFlapAnim, NULL, NULL, 0);
    Animation_Change(&pthis->skelAnime, &gFlagpoleFlapAnim, 1.0f, 0.0f, frameCount, ANIMMODE_LOOP, 0.0f);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gFlagpoleCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->dyna.actor.uncullZoneScale = 500.0f;
    pthis->dyna.actor.uncullZoneDownward = 550.0f;
    pthis->dyna.actor.uncullZoneForward = 2200.0f;
    pthis->invScale = 6;
    pthis->maxStep = 1000;
    pthis->minStep = 1;
    pthis->unk_278 = Rand_ZeroOne() * 0xFFFF;
}

void EnHata_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHata* pthis = (EnHata*)thisx;

    SkelAnime_Free(&pthis->skelAnime, globalCtx);
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void EnHata_Update(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnHata* pthis = (EnHata*)thisx;
    s32 pitch;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    Vec3f windVec;
    f32 sin;

    SkelAnime_Update(&pthis->skelAnime);
    // Rotate to hang down by default
    pthis->limbs[FLAGPOLE_LIMB_FLAG_1_BASE].y = pthis->limbs[FLAGPOLE_LIMB_FLAG_2_BASE].y = -0x4000;
    windVec.x = globalCtx->envCtx.windDirection.x;
    windVec.y = globalCtx->envCtx.windDirection.y;
    windVec.z = globalCtx->envCtx.windDirection.z;

    if (globalCtx->envCtx.windSpeed > 255.0f) {
        globalCtx->envCtx.windSpeed = 255.0f;
    }

    if (globalCtx->envCtx.windSpeed < 0.0f) {
        globalCtx->envCtx.windSpeed = 0.0f;
    }

    if (Rand_ZeroOne() > 0.5f) {
        pthis->unk_278 += 6000;
    } else {
        pthis->unk_278 += 3000;
    }

    // Mimic varying wind gusts
    sin = Math_SinS(pthis->unk_278) * 80.0f;
    pitch = -Math_Vec3f_Pitch(&zeroVec, &windVec);
    pitch = ((s32)((15000 - pitch) * (1.0f - (globalCtx->envCtx.windSpeed / (255.0f - sin))))) + pitch;
    Math_SmoothStepToS(&pthis->limbs[FLAGPOLE_LIMB_FLAG_1_HOIST_END_BASE].y, pitch, pthis->invScale, pthis->maxStep,
                       pthis->minStep);
    pthis->limbs[FLAGPOLE_LIMB_FLAG_2_HOIST_END_BASE].y = pthis->limbs[FLAGPOLE_LIMB_FLAG_1_HOIST_END_BASE].y;
    pthis->limbs[FLAGPOLE_LIMB_FLAG_1_HOIST_END_BASE].z = -Math_Vec3f_Yaw(&zeroVec, &windVec);
    pthis->limbs[FLAGPOLE_LIMB_FLAG_2_HOIST_END_BASE].z = pthis->limbs[FLAGPOLE_LIMB_FLAG_1_HOIST_END_BASE].z;
    pthis->skelAnime.playSpeed = (Rand_ZeroFloat(1.25f) + 2.75f) * (globalCtx->envCtx.windSpeed / 255.0f);
}

s32 EnHata_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnHata* pthis = (EnHata*)thisx;
    Vec3s* limbs;

    if (limbIndex == FLAGPOLE_LIMB_FLAG_2_BASE || limbIndex == FLAGPOLE_LIMB_FLAG_1_BASE ||
        limbIndex == FLAGPOLE_LIMB_FLAG_2_HOIST_END_BASE || limbIndex == FLAGPOLE_LIMB_FLAG_1_HOIST_END_BASE) {
        limbs = pthis->limbs;
        rot->x += limbs[limbIndex].x;
        rot->y += limbs[limbIndex].y;
        rot->z += limbs[limbIndex].z;
    }
    return false;
}

void EnHata_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
}

void EnHata_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHata* pthis = (EnHata*)thisx;

    func_800943C8(globalCtx->state.gfxCtx);
    Matrix_Scale(1.0f, 1.1f, 1.0f, MTXMODE_APPLY);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnHata_OverrideLimbDraw,
                      EnHata_PostLimbDraw, pthis);
}

void EnHata_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Hata_InitVars = {
        ACTOR_EN_HATA,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_HATA,
        sizeof(EnHata),
        (ActorFunc)EnHata_Init,
        (ActorFunc)EnHata_Destroy,
        (ActorFunc)EnHata_Update,
        (ActorFunc)EnHata_Draw,
        (ActorFunc)EnHata_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000080, 0x00, 0x00 },
            TOUCH_NONE | TOUCH_SFX_NORMAL,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 16, 246, 0, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

}
