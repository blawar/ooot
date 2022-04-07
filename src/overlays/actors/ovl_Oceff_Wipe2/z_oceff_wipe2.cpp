#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OCEFF_WIPE2_Z_OCEFF_WIPE2_C
#include "actor_common.h"
/*
 * File: z_oceff_wipe2.c
 * Overlay: ovl_Oceff_Wipe2
 * Description: Epona's Song Effect
 */

#include "z_oceff_wipe2.h"
#include "vt.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "gfx_align.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_25)

void OceffWipe2_Init(Actor* thisx, GlobalContext* globalCtx);
void OceffWipe2_Reset(Actor* pthisx, GlobalContext* globalCtx);
void OceffWipe2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void OceffWipe2_Update(Actor* thisx, GlobalContext* globalCtx);
void OceffWipe2_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Oceff_Wipe2_InitVars = {
    ACTOR_OCEFF_WIPE2,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(OceffWipe2),
    (ActorFunc)OceffWipe2_Init,
    (ActorFunc)OceffWipe2_Destroy,
    (ActorFunc)OceffWipe2_Update,
    (ActorFunc)OceffWipe2_Draw,
    (ActorFunc)OceffWipe2_Reset,
};

void OceffWipe2_Init(Actor* thisx, GlobalContext* globalCtx) {
    OceffWipe2* pthis = (OceffWipe2*)thisx;

    Actor_SetScale(&pthis->actor, 0.1f);
    pthis->timer = 0;
    pthis->actor.world.pos = GET_ACTIVE_CAM(globalCtx)->eye;
    osSyncPrintf(VT_FGCOL(CYAN) " WIPE2 arg_data = %d\n" VT_RST, pthis->actor.params);
}

void OceffWipe2_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    OceffWipe2* pthis = (OceffWipe2*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    func_800876C8(globalCtx);
    if (gSaveContext.nayrusLoveTimer != 0) {
        player->stateFlags3 |= 0x40;
    }
}

void OceffWipe2_Update(Actor* thisx, GlobalContext* globalCtx) {
    OceffWipe2* pthis = (OceffWipe2*)thisx;

    pthis->actor.world.pos = GET_ACTIVE_CAM(globalCtx)->eye;
    if (pthis->timer < 100) {
        pthis->timer++;
    } else {
        Actor_Kill(&pthis->actor);
    }
}

#include "overlays/ovl_Oceff_Wipe2/ovl_Oceff_Wipe2.cpp"

void OceffWipe2_Draw(Actor* thisx, GlobalContext* globalCtx) {
    u32 scroll = globalCtx->state.frames & 0xFF;
    OceffWipe2* pthis = (OceffWipe2*)thisx;
    f32 z;
    u8 alpha;
    s32 pad[2];
    Vec3f eye;
    Vtx* vtxPtr;
    Vec3f vec;

    eye = GET_ACTIVE_CAM(globalCtx)->eye;
    Camera_GetSkyboxOffset(&vec, GET_ACTIVE_CAM(globalCtx));
    if (pthis->timer < 32) {
        z = Math_SinS(pthis->timer << 9) * 1330;
    } else {
        z = 1330;
    }

    vtxPtr = sFrustumVtx;
    if (pthis->timer >= 80) {
        alpha = 12 * (100 - pthis->timer);
    } else {
        alpha = 255;
    }

    vtxPtr[1].v.cn[3] = vtxPtr[3].v.cn[3] = vtxPtr[5].v.cn[3] = vtxPtr[7].v.cn[3] = vtxPtr[9].v.cn[3] =
        vtxPtr[11].v.cn[3] = vtxPtr[13].v.cn[3] = vtxPtr[15].v.cn[3] = vtxPtr[16].v.cn[3] = vtxPtr[18].v.cn[3] =
            vtxPtr[20].v.cn[3] = alpha;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_oceff_wipe2.c", 390);

    func_80093D84(globalCtx->state.gfxCtx);

    Matrix_Translate(eye.x + vec.x, eye.y + vec.y, eye.z + vec.z, MTXMODE_NEW);
    const float correction_factor = (gfx_width() * 3.0f) / (gfx_height() * 4.0f); // Should be 1 on a 4:3 display
    Matrix_Scale(0.1f * correction_factor, 0.1f, 0.1f, MTXMODE_APPLY);
    func_800D1FD4(&globalCtx->billboardMtxF);
    Matrix_Translate(0.0f, 0.0f, -z, MTXMODE_APPLY);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_oceff_wipe2.c", 400),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 170, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 100, 0, 128);
    gSPDisplayList(POLY_XLU_DISP++, sMaterialDL);
    gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, scroll * 6, scroll * (-6), 64, 64, 1,
                                                     scroll * (-6), 0, 64, 64));
    gSPDisplayList(POLY_XLU_DISP++, sFrustumDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_oceff_wipe2.c", 417);
}

void OceffWipe2_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Oceff_Wipe2_InitVars = {
        ACTOR_OCEFF_WIPE2,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(OceffWipe2),
        (ActorFunc)OceffWipe2_Init,
        (ActorFunc)OceffWipe2_Destroy,
        (ActorFunc)OceffWipe2_Update,
        (ActorFunc)OceffWipe2_Draw,
        (ActorFunc)OceffWipe2_Reset,
    };

}
