#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OCEFF_SPOT_Z_OCEFF_SPOT_C
#include "actor_common.h"
#include "z_kankyo.h"
/*
 * File: z_oceff_spot.c
 * Overlay: ovl_Oceff_Spot
 * Description: Sun's Song Effect
 */

#include "z_oceff_spot.h"
#include "vt.h"
#include "def/cosf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_25)

void OceffSpot_Init(Actor* thisx, GlobalContext* globalCtx);
void OceffSpot_Reset(Actor* pthisx, GlobalContext* globalCtx);
void OceffSpot_Destroy(Actor* thisx, GlobalContext* globalCtx);
void OceffSpot_Update(Actor* thisx, GlobalContext* globalCtx);
void OceffSpot_Draw(Actor* thisx, GlobalContext* globalCtx);

void OceffSpot_GrowCylinder(OceffSpot* pthis, GlobalContext* globalCtx);

ActorInit Oceff_Spot_InitVars = {
    ACTOR_OCEFF_SPOT,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(OceffSpot),
    (ActorFunc)OceffSpot_Init,
    (ActorFunc)OceffSpot_Destroy,
    (ActorFunc)OceffSpot_Update,
    (ActorFunc)OceffSpot_Draw,
    (ActorFunc)OceffSpot_Reset,
};

#include "overlays/ovl_Oceff_Spot/ovl_Oceff_Spot.cpp"

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 0, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1500, ICHAIN_STOP),
};

void OceffSpot_SetupAction(OceffSpot* pthis, OceffSpotActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void OceffSpot_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    OceffSpot* pthis = (OceffSpot*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    OceffSpot_SetupAction(pthis, OceffSpot_GrowCylinder);

    Lights_PointNoGlowSetInfo(&pthis->lightInfo1, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                              pthis->actor.world.pos.z, 0, 0, 0, 0);
    pthis->lightNode1 = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo1);

    Lights_PointNoGlowSetInfo(&pthis->lightInfo2, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                              pthis->actor.world.pos.z, 0, 0, 0, 0);
    pthis->lightNode2 = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo2);
    if (YREG(15)) {
        pthis->actor.scale.y = 2.4f;
    } else {
        pthis->actor.scale.y = 0.3f;
    }

    pthis->unk_174 = 0.0f;
}

void OceffSpot_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    OceffSpot* pthis = (OceffSpot*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode1);
    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode2);
    func_800876C8(globalCtx);
    if ((gSaveContext.nayrusLoveTimer != 0) && (globalCtx->actorCtx.actorLists[ACTORCAT_PLAYER].length != 0)) {
        player->stateFlags3 |= 0x40;
    }
}

void OceffSpot_End(OceffSpot* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_174 > 0.0f) {
        pthis->unk_174 -= 0.05f;
    } else {
        Actor_Kill(&pthis->actor);
        if (gTimeIncrement != 400 && globalCtx->msgCtx.unk_E40E == 0 && (gSaveContext.eventInf[0] & 0xF) != 1) {
            if (globalCtx->msgCtx.ocarinaAction != OCARINA_ACTION_CHECK_NOWARP_DONE ||
                globalCtx->msgCtx.ocarinaMode != OCARINA_MODE_08) {
                gSaveContext.sunsSongState = SUNSSONG_START;
                osSyncPrintf(VT_FGCOL(YELLOW));
                // "Sun's Song Flag"
                osSyncPrintf("z_oceff_spot  太陽の歌フラグ\n");
                osSyncPrintf(VT_RST);
            }
        } else {
            globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
            osSyncPrintf(VT_FGCOL(YELLOW));
            // "Ocarina End"
            osSyncPrintf("z_oceff_spot  オカリナ終了\n");
            osSyncPrintf(VT_RST);
        }
    }
}

void OceffSpot_Wait(OceffSpot* pthis, GlobalContext* globalCtx) {
    if (pthis->timer > 0) {
        pthis->timer--;
    } else {
        OceffSpot_SetupAction(pthis, OceffSpot_End);
    }
}

void OceffSpot_GrowCylinder(OceffSpot* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_174 < 1.0f) {
        pthis->unk_174 += 0.05f;
    } else {
        OceffSpot_SetupAction(pthis, OceffSpot_Wait);
        pthis->timer = 60;
    }
}

void OceffSpot_Update(Actor* thisx, GlobalContext* globalCtx) {
    OceffSpot* pthis = (OceffSpot*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    f32 temp;

    temp = (1.0f - cosf(pthis->unk_174 * M_PI)) * 0.5f;
    pthis->actionFunc(pthis, globalCtx);

    pthis->actor.scale.z = 0.42f * temp;
    pthis->actor.scale.x = 0.42f * temp;

    pthis->actor.world.pos = player->actor.world.pos;
    pthis->actor.world.pos.y += 5.0f;

    temp = (2.0f - pthis->unk_174) * pthis->unk_174;
    Environment_AdjustLights(globalCtx, temp * 0.5F, 880.0f, 0.2f, 0.9f);

    Lights_PointNoGlowSetInfo(&pthis->lightInfo1, (s16)pthis->actor.world.pos.x, (s16)pthis->actor.world.pos.y + 55.0f,
                              (s16)pthis->actor.world.pos.z, (s32)(255.0f * temp), (s32)(255.0f * temp),
                              (s32)(200.0f * temp), (s16)(100.0f * temp));

    Lights_PointNoGlowSetInfo(&pthis->lightInfo2,
                              (s16)pthis->actor.world.pos.x + Math_SinS(player->actor.shape.rot.y) * 20.0f,
                              (s16)pthis->actor.world.pos.y + 20.0f,
                              (s16)pthis->actor.world.pos.z + Math_CosS(player->actor.shape.rot.y) * 20.0f,
                              (s32)(255.0f * temp), (s32)(255.0f * temp), (s32)(200.0f * temp), (s16)(100.0f * temp));
}

void OceffSpot_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OceffSpot* pthis = (OceffSpot*)thisx;
    u32 scroll = globalCtx->state.frames & 0xFFFF;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_oceff_spot.c", 466);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_oceff_spot.c", 469),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, sCylinderMaterialDL);
    gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, scroll * 2, scroll * (-2), 32, 32, 1,
                                                     0, scroll * (-8), 32, 32));
    gSPDisplayList(POLY_XLU_DISP++, sCylinderModelDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_oceff_spot.c", 485);
}

void OceffSpot_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Oceff_Spot_InitVars = {
        ACTOR_OCEFF_SPOT,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(OceffSpot),
        (ActorFunc)OceffSpot_Init,
        (ActorFunc)OceffSpot_Destroy,
        (ActorFunc)OceffSpot_Update,
        (ActorFunc)OceffSpot_Draw,
        (ActorFunc)OceffSpot_Reset,
    };

}
