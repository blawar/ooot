#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_SIMA_Z_BG_HIDAN_SIMA_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_sima.c
 * Overlay: ovl_Bg_Hidan_Sima
 * Description: Stone platform (Fire Temple)
 */

#include "z_bg_hidan_sima.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/cosf.h"
#include "def/graph.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgHidanSima_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanSima_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanSima_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanSima_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8088E518(BgHidanSima* pthis, GlobalContext* globalCtx);
void func_8088E5D0(BgHidanSima* pthis, GlobalContext* globalCtx);
void func_8088E6D0(BgHidanSima* pthis, GlobalContext* globalCtx);
void func_8088E760(BgHidanSima* pthis, GlobalContext* globalCtx);
void func_8088E7A8(BgHidanSima* pthis, GlobalContext* globalCtx);
void func_8088E90C(BgHidanSima* pthis);

ActorInit Bg_Hidan_Sima_InitVars = {
    ACTOR_BG_HIDAN_SIMA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanSima),
    (ActorFunc)BgHidanSima_Init,
    (ActorFunc)BgHidanSima_Destroy,
    (ActorFunc)BgHidanSima_Update,
    (ActorFunc)BgHidanSima_Draw,
};

static ColliderJntSphElementInit sJntSphElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x20000000, 0x01, 0x04 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 1, { { 0, 40, 100 }, 22 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x20000000, 0x01, 0x04 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 1, { { 0, 40, 145 }, 30 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(sJntSphElementsInit),
    sJntSphElementsInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

static void* sFireballsTexs[] = {
    gFireTempleFireball0Tex, gFireTempleFireball1Tex, gFireTempleFireball2Tex, gFireTempleFireball3Tex,
    gFireTempleFireball4Tex, gFireTempleFireball5Tex, gFireTempleFireball6Tex, gFireTempleFireball7Tex,
};

void BgHidanSima_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanSima* pthis = (BgHidanSima*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 i;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    if (pthis->dyna.actor.params == 0) {
        CollisionHeader_GetVirtual(&gFireTempleStonePlatform1Col, &colHeader);
    } else {
        CollisionHeader_GetVirtual(&gFireTempleStonePlatform2Col, &colHeader);
    }
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->dyna.actor, &sJntSphInit, pthis->elements);
    for (i = 0; i < ARRAY_COUNT(sJntSphElementsInit); i++) {
        pthis->collider.elements[i].dim.worldSphere.radius = pthis->collider.elements[i].dim.modelSphere.radius;
    }
    if (pthis->dyna.actor.params == 0) {
        pthis->actionFunc = func_8088E518;
    } else {
        pthis->actionFunc = func_8088E760;
    }
}

void BgHidanSima_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanSima* pthis = (BgHidanSima*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void func_8088E518(BgHidanSima* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 3.4f);
    if (func_8004356C(&pthis->dyna) && !(player->stateFlags1 & 0x6000)) {
        pthis->timer = 20;
        pthis->dyna.actor.world.rot.y = Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4000;
        if (pthis->dyna.actor.home.pos.y <= pthis->dyna.actor.world.pos.y) {
            pthis->actionFunc = func_8088E5D0;
        } else {
            pthis->actionFunc = func_8088E6D0;
        }
    }
}

void func_8088E5D0(BgHidanSima* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer != 0) {
        pthis->dyna.actor.world.pos.x =
            Math_SinS(pthis->dyna.actor.world.rot.y + (pthis->timer * 0x4000)) * 5.0f + pthis->dyna.actor.home.pos.x;
        pthis->dyna.actor.world.pos.z =
            Math_CosS(pthis->dyna.actor.world.rot.y + (pthis->timer * 0x4000)) * 5.0f + pthis->dyna.actor.home.pos.z;
    } else {
        pthis->actionFunc = func_8088E6D0;
        pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x;
        pthis->dyna.actor.world.pos.z = pthis->dyna.actor.home.pos.z;
    }
    if (!(pthis->timer % 4)) {
        func_800AA000(pthis->dyna.actor.xyzDistToPlayerSq, 180, 10, 100);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_SHAKE);
    }
}

void func_8088E6D0(BgHidanSima* pthis, GlobalContext* globalCtx) {
    if (func_8004356C(&pthis->dyna)) {
        pthis->timer = 20;
    } else if (pthis->timer != 0) {
        pthis->timer--;
    }
    Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y - 100.0f, 1.7f);
    if (pthis->timer == 0) {
        pthis->actionFunc = func_8088E518;
    }
}

void func_8088E760(BgHidanSima* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        pthis->dyna.actor.world.rot.y += 0x8000;
        pthis->timer = 60;
        pthis->actionFunc = func_8088E7A8;
    }
}

void func_8088E7A8(BgHidanSima* pthis, GlobalContext* globalCtx) {
    f32 temp;

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->dyna.actor.world.rot.y != pthis->dyna.actor.home.rot.y) {
        temp = (sinf(((60 - pthis->timer) * 0.01667 - 0.5) * M_PI) + 1) * 200;
    } else {
        temp = (sinf((pthis->timer * 0.01667 - 0.5) * M_PI) + 1) * -200;
    }
    pthis->dyna.actor.world.pos.x = Math_SinS(pthis->dyna.actor.world.rot.y) * temp + pthis->dyna.actor.home.pos.x;
    pthis->dyna.actor.world.pos.z = Math_CosS(pthis->dyna.actor.world.rot.y) * temp + pthis->dyna.actor.home.pos.z;
    if (pthis->timer == 0) {
        pthis->timer = 20;
        pthis->actionFunc = func_8088E760;
    }
    func_8002F974(&pthis->dyna.actor, NA_SE_EV_FIRE_PILLAR - SFX_FLAG);
}

void func_8088E90C(BgHidanSima* pthis) {
    ColliderJntSphElement* elem;
    s32 i;
    f32 cos = Math_CosS(pthis->dyna.actor.world.rot.y + 0x8000);
    f32 sin = Math_SinS(pthis->dyna.actor.world.rot.y + 0x8000);

    for (i = 0; i < 2; i++) {
        elem = &pthis->collider.elements[i];
        elem->dim.worldSphere.center.x = pthis->dyna.actor.world.pos.x + sin * elem->dim.modelSphere.center.z;
        elem->dim.worldSphere.center.y = (s16)pthis->dyna.actor.world.pos.y + elem->dim.modelSphere.center.y;
        elem->dim.worldSphere.center.z = pthis->dyna.actor.world.pos.z + cos * elem->dim.modelSphere.center.z;
    }
}

void BgHidanSima_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanSima* pthis = (BgHidanSima*)thisx;
    s32 pad;

    pthis->actionFunc(pthis, globalCtx);
    if (pthis->dyna.actor.params != 0) {
        s32 temp = (pthis->dyna.actor.world.rot.y == pthis->dyna.actor.shape.rot.y) ? pthis->timer : (pthis->timer + 80);

        if (pthis->actionFunc == func_8088E7A8) {
            temp += 20;
        }
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y - ((1.0f - cosf(temp * (M_PI / 20))) * 5.0f);
        if (pthis->actionFunc == func_8088E7A8) {
            func_8088E90C(pthis);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
}

Gfx* func_8088EB54(GlobalContext* globalCtx, BgHidanSima* pthis, Gfx* gfx) {
    MtxF mtxF;
    s32 phi_s5;
    s32 s3;
    s32 v0;
    f32 cos;
    f32 sin;
    s32 pad[2];

    Matrix_MtxFCopy(&mtxF, &gMtxFClear);
    cos = Math_CosS(pthis->dyna.actor.world.rot.y + 0x8000);
    sin = Math_SinS(pthis->dyna.actor.world.rot.y + 0x8000);

    phi_s5 = (60 - pthis->timer) >> 1;
    phi_s5 = CLAMP_MAX(phi_s5, 3);

    v0 = 3 - (pthis->timer >> 1);
    v0 = CLAMP_MIN(v0, 0);

    mtxF.xw = pthis->dyna.actor.world.pos.x + ((79 - ((pthis->timer % 6) * 4)) + v0 * 25) * sin;
    mtxF.zw = pthis->dyna.actor.world.pos.z + ((79 - ((pthis->timer % 6) * 4)) + v0 * 25) * cos;
    mtxF.yw = pthis->dyna.actor.world.pos.y + 40.0f;
    mtxF.zz = v0 * 0.4f + 1.0f;
    mtxF.yy = v0 * 0.4f + 1.0f;
    mtxF.xx = v0 * 0.4f + 1.0f;

    for (s3 = v0; s3 < phi_s5; s3++) {
        mtxF.xw += 25.0f * sin;
        mtxF.zw += 25.0f * cos;
        mtxF.xx += 0.4f;
        mtxF.yy += 0.4f;
        mtxF.zz += 0.4f;

        gSPSegment(gfx++, 0x09, SEGMENTED_TO_VIRTUAL(sFireballsTexs[(pthis->timer + s3) % 7]));
        gSPMatrix(gfx++,
                  Matrix_MtxFToMtx(&mtxF,
                                   (Mtx*)Graph_Alloc(globalCtx->state.gfxCtx, sizeof(Mtx))),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, gFireTempleFireballDL);
    }
    mtxF.xw = pthis->dyna.actor.world.pos.x + (phi_s5 * 25 + 80) * sin;
    mtxF.zw = pthis->dyna.actor.world.pos.z + (phi_s5 * 25 + 80) * cos;
    gSPSegment(gfx++, 0x09, SEGMENTED_TO_VIRTUAL(sFireballsTexs[(pthis->timer + s3) % 7]));
    gSPMatrix(gfx++,
              Matrix_MtxFToMtx(&mtxF,
                               (Mtx*)Graph_Alloc(globalCtx->state.gfxCtx, sizeof(Mtx))),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, gFireTempleFireballDL);
    return gfx;
}

void BgHidanSima_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanSima* pthis = (BgHidanSima*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_sima.c", 641);
    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_hidan_sima.c", 645),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    if (pthis->dyna.actor.params == 0) {
        gSPDisplayList(POLY_OPA_DISP++, gFireTempleStonePlatform1DL);
    } else {
        gSPDisplayList(POLY_OPA_DISP++, gFireTempleStonePlatform2DL);
        if (pthis->actionFunc == func_8088E7A8) {
            POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0x14);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 1, 255, 255, 0, 150);
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 255);
            POLY_XLU_DISP = func_8088EB54(globalCtx, pthis, POLY_XLU_DISP);
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_sima.c", 668);
}
