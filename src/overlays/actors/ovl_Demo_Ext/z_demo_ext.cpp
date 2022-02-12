#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DEMO_EXT_Z_DEMO_EXT_C
#include "actor_common.h"
/*
 * File: z_demo_ext.c
 * Overlay: Demo_Ext
 * Description: Magic Vortex in Silver Gauntlets Cutscene
 */

#include "z_demo_ext.h"
#include "vt.h"
#include "objects/object_fhg/object_fhg.h"
#include "def/code_800F7260.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

typedef enum {
    /* 0x00 */ EXT_WAIT,
    /* 0x01 */ EXT_MAINTAIN,
    /* 0x02 */ EXT_DISPELL
} DemoExtAction;

typedef enum {
    /* 0x00 */ EXT_DRAW_NOTHING,
    /* 0x01 */ EXT_DRAW_VORTEX
} DemoExtDrawMode;

void DemoExt_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoExt_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoExt_Update(Actor* thisx, GlobalContext* globalCtx);
void DemoExt_Draw(Actor* thisx, GlobalContext* globalCtx);

void DemoExt_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void DemoExt_Init(Actor* thisx, GlobalContext* globalCtx) {
    DemoExt* pthis = (DemoExt*)thisx;

    pthis->scrollIncr[0] = 25;
    pthis->scrollIncr[1] = 40;
    pthis->scrollIncr[2] = 5;
    pthis->scrollIncr[3] = 30;
    pthis->primAlpha = kREG(28) + 255;
    pthis->envAlpha = kREG(32) + 255;
    pthis->scale.x = kREG(19) + 400.0f;
    pthis->scale.y = kREG(20) + 100.0f;
    pthis->scale.z = kREG(21) + 400.0f;
}

void DemoExt_PlayVortexSFX(DemoExt* pthis) {
    if (pthis->alphaTimer <= (kREG(35) + 40.0f) - 15.0f) {
        Audio_PlaySoundGeneral(NA_SE_EV_FANTOM_WARP_L - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0,
                               &D_801333E0, &D_801333E8);
    }
}

CsCmdActorAction* DemoExt_GetNpcAction(GlobalContext* globalCtx, s32 npcActionIndex) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        return globalCtx->csCtx.npcActions[npcActionIndex];
    }
    return NULL;
}

void DemoExt_SetupWait(DemoExt* pthis) {
    pthis->action = EXT_WAIT;
    pthis->drawMode = EXT_DRAW_NOTHING;
}

void DemoExt_SetupMaintainVortex(DemoExt* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction = DemoExt_GetNpcAction(globalCtx, 5);

    if (npcAction != NULL) {
        pthis->actor.world.pos.x = npcAction->startPos.x;
        pthis->actor.world.pos.y = npcAction->startPos.y;
        pthis->actor.world.pos.z = npcAction->startPos.z;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = npcAction->rot.y;
    }
    pthis->action = EXT_MAINTAIN;
    pthis->drawMode = EXT_DRAW_VORTEX;
}

void DemoExt_SetupDispellVortex(DemoExt* pthis) {
    pthis->action = EXT_DISPELL;
    pthis->drawMode = EXT_DRAW_VORTEX;
}

void DemoExt_FinishClosing(DemoExt* pthis) {
    pthis->alphaTimer += 1.0f;
    if ((kREG(35) + 40.0f) <= pthis->alphaTimer) {
        Actor_Kill(&pthis->actor);
    }
}

void DemoExt_CheckCsMode(DemoExt* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* csCmdNPCAction = DemoExt_GetNpcAction(globalCtx, 5);
    s32 csAction;
    s32 previousCsAction;

    if (csCmdNPCAction != NULL) {
        csAction = csCmdNPCAction->action;
        previousCsAction = pthis->previousCsAction;

        if (csAction != previousCsAction) {
            switch (csAction) {
                case 1:
                    DemoExt_SetupWait(pthis);
                    break;
                case 2:
                    DemoExt_SetupMaintainVortex(pthis, globalCtx);
                    break;
                case 3:
                    DemoExt_SetupDispellVortex(pthis);
                    break;
                default:
                    // "Demo_Ext_Check_DemoMode: there is no such action!"
                    osSyncPrintf("Demo_Ext_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
                    break;
            }
            pthis->previousCsAction = csAction;
        }
    }
}

void DemoExt_SetScrollAndRotation(DemoExt* pthis) {
    s16* scrollIncr = pthis->scrollIncr;
    s16* curScroll = pthis->curScroll;
    s32 i;

    for (i = 3; i != 0; i--) {
        curScroll[i] += scrollIncr[i];
    }
    pthis->rotationPitch += (s16)(kREG(34) + 1000);
}

void DemoExt_SetColorsAndScales(DemoExt* pthis) {
    Vec3f* scale = &pthis->scale;
    f32 shrinkFactor;

    shrinkFactor = ((kREG(35) + 40.0f) - pthis->alphaTimer) / (kREG(35) + 40.0f);
    if (shrinkFactor < 0.0f) {
        shrinkFactor = 0.0f;
    }

    pthis->primAlpha = (u32)(kREG(28) + 255) * shrinkFactor;
    pthis->envAlpha = (u32)(kREG(32) + 255) * shrinkFactor;
    scale->x = (kREG(19) + 400.0f) * shrinkFactor;
    scale->y = (kREG(20) + 100.0f) * shrinkFactor;
    scale->z = (kREG(21) + 400.0f) * shrinkFactor;
}

void DemoExt_Wait(DemoExt* pthis, GlobalContext* globalCtx) {
    DemoExt_CheckCsMode(pthis, globalCtx);
}

void DemoExt_MaintainVortex(DemoExt* pthis, GlobalContext* globalCtx) {
    DemoExt_PlayVortexSFX(pthis);
    DemoExt_SetScrollAndRotation(pthis);
    DemoExt_CheckCsMode(pthis, globalCtx);
}

void DemoExt_DispellVortex(DemoExt* pthis, GlobalContext* globalCtx) {
    DemoExt_PlayVortexSFX(pthis);
    DemoExt_SetScrollAndRotation(pthis);
    DemoExt_SetColorsAndScales(pthis);
    DemoExt_FinishClosing(pthis);
}

static DemoExtActionFunc sActionFuncs[] = {
    DemoExt_Wait,
    DemoExt_MaintainVortex,
    DemoExt_DispellVortex,
};

void DemoExt_Update(Actor* thisx, GlobalContext* globalCtx) {
    DemoExt* pthis = (DemoExt*)thisx;

    if ((pthis->action < EXT_WAIT) || (pthis->action > EXT_DISPELL) || sActionFuncs[pthis->action] == NULL) {
        // "Main mode is abnormal!"
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
    } else {
        sActionFuncs[pthis->action](pthis, globalCtx);
    }
}

void DemoExt_DrawNothing(Actor* thisx, GlobalContext* globalCtx) {
}

void DemoExt_DrawVortex(Actor* thisx, GlobalContext* globalCtx) {
    DemoExt* pthis = (DemoExt*)thisx;
    Mtx* mtx;
    GraphicsContext* gfxCtx;
    s16* curScroll;
    Vec3f* scale;

    scale = &pthis->scale;
    gfxCtx = globalCtx->state.gfxCtx;
    mtx = (Mtx*)Graph_Alloc(gfxCtx, sizeof(Mtx));

    OPEN_DISPS(gfxCtx, "../z_demo_ext.c", 460);
    Matrix_Push();
    Matrix_Scale(scale->x, scale->y, scale->z, MTXMODE_APPLY);
    Matrix_RotateZYX((s16)(kREG(16) + 0x4000), pthis->rotationPitch, kREG(18), MTXMODE_APPLY);
    Matrix_Translate(kREG(22), kREG(23), kREG(24), MTXMODE_APPLY);
    Matrix_ToMtx(mtx, "../z_demo_ext.c", 476);
    Matrix_Pop();
    func_80093D84(gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, kREG(33) + 128, kREG(25) + 140, kREG(26) + 80, kREG(27) + 140, pthis->primAlpha);
    gDPSetEnvColor(POLY_XLU_DISP++, kREG(29) + 90, kREG(30) + 50, kREG(31) + 95, pthis->envAlpha);

    curScroll = pthis->curScroll;
    gSPSegment(
        POLY_XLU_DISP++, 0x08,
        Gfx_TwoTexScroll(gfxCtx, 0, curScroll[0], curScroll[1], 0x40, 0x40, 1, curScroll[2], curScroll[3], 0x40, 0x40));

    gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gPhantomWarpDL);
    gSPPopMatrix(POLY_XLU_DISP++, G_MTX_MODELVIEW);

    CLOSE_DISPS(gfxCtx, "../z_demo_ext.c", 512);
}

static DemoExtDrawFunc sDrawFuncs[] = {
    DemoExt_DrawNothing,
    DemoExt_DrawVortex,
};

void DemoExt_Draw(Actor* thisx, GlobalContext* globalCtx) {
    DemoExt* pthis = (DemoExt*)thisx;

    if ((pthis->drawMode < EXT_DRAW_NOTHING) || (pthis->drawMode > EXT_DRAW_VORTEX) ||
        sDrawFuncs[pthis->drawMode] == NULL) {
        // "Draw mode is abnormal!"
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
    } else {
        sDrawFuncs[pthis->drawMode](thisx, globalCtx);
    }
}

ActorInit Demo_Ext_InitVars = {
    ACTOR_DEMO_EXT,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_FHG,
    sizeof(DemoExt),
    (ActorFunc)DemoExt_Init,
    (ActorFunc)DemoExt_Destroy,
    (ActorFunc)DemoExt_Update,
    (ActorFunc)DemoExt_Draw,
};
