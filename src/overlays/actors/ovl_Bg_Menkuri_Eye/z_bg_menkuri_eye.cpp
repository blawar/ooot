#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MENKURI_EYE_Z_BG_MENKURI_EYE_C
#include "actor_common.h"
/*
 * File: z_bg_menkuri_eye.c
 * Overlay: ovl_Bg_Menkuri_Eye
 * Description: Eye platform eye switches
 */

#include "z_bg_menkuri_eye.h"
#include "objects/object_menkuri_objects/object_menkuri_objects.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_5

void BgMenkuriEye_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMenkuriEye_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgMenkuriEye_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMenkuriEye_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMenkuriEye_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Bg_Menkuri_Eye_InitVars = {
    ACTOR_BG_MENKURI_EYE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MENKURI_OBJECTS,
    sizeof(BgMenkuriEye),
    (ActorFunc)BgMenkuriEye_Init,
    (ActorFunc)BgMenkuriEye_Destroy,
    (ActorFunc)BgMenkuriEye_Update,
    (ActorFunc)BgMenkuriEye_Draw,
    (ActorFunc)BgMenkuriEye_Reset,
};

static s32 D_8089C1A0;

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK4,
            { 0x00000000, 0x00, 0x00 },
            { 0x0001F820, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 1, { { 0, 0, 0 }, 14 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgMenkuriEye_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgMenkuriEye* pthis = (BgMenkuriEye*)thisx;
    ColliderJntSphElement* colliderList;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItems);
    pthis->collider.elements[0].dim.worldSphere.center.x = pthis->actor.world.pos.x;
    pthis->collider.elements[0].dim.worldSphere.center.y = pthis->actor.world.pos.y;
    pthis->collider.elements[0].dim.worldSphere.center.z = pthis->actor.world.pos.z;
    colliderList = pthis->collider.elements;
    colliderList->dim.worldSphere.radius = colliderList->dim.modelSphere.radius;
    if (!Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        D_8089C1A0 = 0;
    }
    pthis->framesUntilDisable = -1;
}

void BgMenkuriEye_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgMenkuriEye* pthis = (BgMenkuriEye*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void BgMenkuriEye_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgMenkuriEye* pthis = (BgMenkuriEye*)thisx;

    if (!Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        if (pthis->framesUntilDisable != -1) {
            if (pthis->framesUntilDisable != 0) {
                pthis->framesUntilDisable -= 1;
            }
            if (pthis->framesUntilDisable == 0) {
                pthis->framesUntilDisable = -1;
                D_8089C1A0 -= 1;
            }
        }
    }
    if ((pthis->collider.base.acFlags & AC_HIT) &&
        (ABS((s16)(pthis->collider.base.ac->world.rot.y - pthis->actor.shape.rot.y)) > 0x5000)) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        if (pthis->framesUntilDisable == -1) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_AMOS_DAMAGE);
            D_8089C1A0 += 1;
            D_8089C1A0 = CLAMP_MAX(D_8089C1A0, 4);
        }
        pthis->framesUntilDisable = 416;
        if (D_8089C1A0 == 4) {
            Flags_SetSwitch(globalCtx, pthis->actor.params);
            func_80078884(NA_SE_SY_CORRECT_CHIME);
        }
    }
    if (pthis->framesUntilDisable == -1) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
    Actor_SetFocus(&pthis->actor, 0.0f);
}

void BgMenkuriEye_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgMenkuriEye* pthis = (BgMenkuriEye*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_menkuri_eye.c", 292);
    func_80093D84(globalCtx->state.gfxCtx);
    if (Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        gDPSetEnvColor(POLY_XLU_DISP++, 200, 0, 0, 255);
    } else if (pthis->framesUntilDisable == -1) {
        gDPSetEnvColor(POLY_XLU_DISP++, 200, 0, 0, 0);
    } else {
        gDPSetEnvColor(POLY_XLU_DISP++, 200, 0, 0, 255);
    }
    Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
    Matrix_RotateZYX(pthis->actor.world.rot.x, pthis->actor.world.rot.y, pthis->actor.world.rot.z, MTXMODE_APPLY);
    Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_menkuri_eye.c", 331),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_XLU_DISP++, gGTGEyeStatueEyeDL);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_menkuri_eye.c", 335);
}

void BgMenkuriEye_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Menkuri_Eye_InitVars = {
        ACTOR_BG_MENKURI_EYE,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_MENKURI_OBJECTS,
        sizeof(BgMenkuriEye),
        (ActorFunc)BgMenkuriEye_Init,
        (ActorFunc)BgMenkuriEye_Destroy,
        (ActorFunc)BgMenkuriEye_Update,
        (ActorFunc)BgMenkuriEye_Draw,
        (ActorFunc)BgMenkuriEye_Reset,
    };

    D_8089C1A0 = 0;

    sJntSphInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphElementsInit,
    };

}
