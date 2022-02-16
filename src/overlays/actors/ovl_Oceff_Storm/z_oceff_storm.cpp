#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OCEFF_STORM_Z_OCEFF_STORM_C
#include "actor_common.h"
/*
 * File: z_oceff_storm.c
 * Overlay: ovl_Oceff_Storm
 * Description: Song of Storms Effect
 */

#include "z_oceff_storm.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_common_data.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_25)

void OceffStorm_Init(Actor* thisx, GlobalContext* globalCtx);
void OceffStorm_Reset(Actor* pthisx, GlobalContext* globalCtx);
void OceffStorm_Destroy(Actor* thisx, GlobalContext* globalCtx);
void OceffStorm_Update(Actor* thisx, GlobalContext* globalCtx);
void OceffStorm_Draw(Actor* thisx, GlobalContext* globalCtx);

void OceffStorm_Draw2(Actor* thisx, GlobalContext* globalCtx);

void OceffStorm_DefaultAction(OceffStorm* pthis, GlobalContext* globalCtx);
void OceffStorm_UnkAction(OceffStorm* pthis, GlobalContext* globalCtx);

ActorInit Oceff_Storm_InitVars = {
    ACTOR_OCEFF_STORM,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(OceffStorm),
    (ActorFunc)OceffStorm_Init,
    (ActorFunc)OceffStorm_Destroy,
    (ActorFunc)OceffStorm_Update,
    (ActorFunc)OceffStorm_Draw,
    (ActorFunc)OceffStorm_Reset,
};

void OceffStorm_SetupAction(OceffStorm* pthis, OceffStormActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void OceffStorm_Init(Actor* thisx, GlobalContext* globalCtx) {
    OceffStorm* pthis = (OceffStorm*)thisx;
    OceffStorm_SetupAction(pthis, OceffStorm_DefaultAction);
    pthis->posYOffAdd = 0;
    pthis->counter = 0;
    pthis->primColorAlpha = 0;
    pthis->vtxAlpha = 0;
    pthis->actor.scale.y = 0.0f;
    pthis->actor.scale.z = 0.0f;
    pthis->actor.scale.x = 0.0f;
    pthis->posYOff = pthis->posYOffAdd;

    if (pthis->actor.params == 1) {
        OceffStorm_SetupAction(pthis, OceffStorm_UnkAction);
        pthis->actor.draw = OceffStorm_Draw2;
    } else {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_OKARINA_EFFECT, pthis->actor.world.pos.x,
                    pthis->actor.world.pos.y - 30.0f, pthis->actor.world.pos.z, 0, 0, 0, 1);
    }
}

void OceffStorm_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    OceffStorm* pthis = (OceffStorm*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    func_800876C8(globalCtx);
    if (gSaveContext.nayrusLoveTimer != 0) {
        player->stateFlags3 |= 0x40;
    }
}

void OceffStorm_DefaultAction(OceffStorm* pthis, GlobalContext* globalCtx) {
    if (pthis->counter < 20) {
        pthis->primColorAlpha = (s8)(pthis->counter * 5.0f);
    } else if (pthis->counter > 80) {
        pthis->primColorAlpha = (s8)((100 - pthis->counter) * 5.0f);
    } else {
        pthis->primColorAlpha = 100;
    }

    if (pthis->counter < 10 || pthis->counter >= 90) {
        pthis->vtxAlpha = 0;
    } else {
        if (pthis->counter <= 65) {
            if (pthis->vtxAlpha <= 200) {
                pthis->vtxAlpha += 10;
            }
            pthis->actor.scale.x = pthis->actor.scale.z = 0.4f;
            pthis->actor.scale.y = 0.3f;
        } else if (pthis->counter > 65) {
            pthis->vtxAlpha = (90 - pthis->counter) * 10;
        } else {
            pthis->vtxAlpha = 255;
            pthis->actor.scale.x = pthis->actor.scale.z = 0.4f;
        }
    }

    if (pthis->counter > 60) {
        pthis->actor.world.pos.y += pthis->posYOff * 0.01f;
        pthis->posYOff += pthis->posYOffAdd;
        pthis->posYOffAdd += 10;
    }

    if (pthis->counter < 100) {
        pthis->counter++;
    } else {
        Actor_Kill(&pthis->actor);
    }
}

void OceffStorm_UnkAction(OceffStorm* pthis, GlobalContext* globalCtx) {
    if (pthis->primColorAlpha < 100) {
        pthis->primColorAlpha += 5;
    }
    //! @bug Actor_Kill is never called so the actor will stay alive forever
}

void OceffStorm_Update(Actor* thisx, GlobalContext* globalCtx) {
    OceffStorm* pthis = (OceffStorm*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    pthis->actor.world.pos = player->actor.world.pos;
    pthis->actor.shape.rot.y = Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx));
    pthis->actionFunc(pthis, globalCtx);
}

#include "overlays/ovl_Oceff_Storm/ovl_Oceff_Storm.cpp"

void OceffStorm_Draw2(Actor* thisx, GlobalContext* globalCtx) {
    u32 scroll = globalCtx->state.frames & 0xFFF;
    OceffStorm* pthis = (OceffStorm*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_oceff_storm.c", 449);

    gDPPipeSync(POLY_XLU_DISP++);

    if (1) {}

    POLY_XLU_DISP = func_80093F34(POLY_XLU_DISP);
    gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_NOISE);
    gDPSetColorDither(POLY_XLU_DISP++, G_CD_NOISE);
    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 200, 200, 150, pthis->primColorAlpha);
    gSPDisplayList(POLY_XLU_DISP++, sMaterialDL);
    gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, scroll * 8, scroll * 4, 64, 64, 1,
                                                     scroll * 4, scroll * 4, 64, 64));
    gSPTextureRectangle(POLY_XLU_DISP++, 0, 0, (SCREEN_WIDTH << 2), (SCREEN_HEIGHT << 2), G_TX_RENDERTILE, 0, 0, 140,
                        (1 << 15) | (31 << 10) | 884);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_oceff_storm.c", 477);
}

void OceffStorm_Draw(Actor* thisx, GlobalContext* globalCtx) {
    u32 scroll = globalCtx->state.frames & 0xFFF;
    OceffStorm* pthis = (OceffStorm*)thisx;
    Vtx* vtxPtr = sCylinderVtx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_oceff_storm.c", 486);

    func_80093D84(globalCtx->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 200, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 150, 150, 0, 128);
    gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_NOISE);
    gDPSetColorDither(POLY_XLU_DISP++, G_CD_NOISE);

    vtxPtr[0].v.cn[3] = vtxPtr[6].v.cn[3] = vtxPtr[16].v.cn[3] = vtxPtr[25].v.cn[3] = pthis->vtxAlpha >> 1;
    vtxPtr[10].v.cn[3] = vtxPtr[22].v.cn[3] = pthis->vtxAlpha;

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_oceff_storm.c", 498),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_XLU_DISP++, sCylinderMaterialDL);
    gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, scroll * 4, (0 - scroll) * 8, 32, 32,
                                                     1, scroll * 8, (0 - scroll) * 12, 32, 32));
    gSPDisplayList(POLY_XLU_DISP++, sCylinderModelDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_oceff_storm.c", 512);

    OceffStorm_Draw2(&pthis->actor, globalCtx);
}

void OceffStorm_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Oceff_Storm_InitVars = {
        ACTOR_OCEFF_STORM,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(OceffStorm),
        (ActorFunc)OceffStorm_Init,
        (ActorFunc)OceffStorm_Destroy,
        (ActorFunc)OceffStorm_Update,
        (ActorFunc)OceffStorm_Draw,
        (ActorFunc)OceffStorm_Reset,
    };

}
