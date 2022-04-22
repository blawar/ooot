#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_FWBIG_Z_BG_HIDAN_FWBIG_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_fwbig.c
 * Overlay: ovl_Bg_Hidan_Fwbig
 * Description: Large fire walls at Fire Temple (flame wall before bombable door and the one that chases the player in
 * the lava room)
 */

#include "z_bg_hidan_fwbig.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4


void BgHidanFwbig_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanFwbig_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgHidanFwbig_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanFwbig_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanFwbig_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgHidanFwbig_UpdatePosition(BgHidanFwbig* pthis);

void BgHidanFwbig_WaitForSwitch(BgHidanFwbig* pthis, GlobalContext* globalCtx);
void BgHidanFwbig_WaitForCs(BgHidanFwbig* pthis, GlobalContext* globalCtx);
void BgHidanFwbig_Lower(BgHidanFwbig* pthis, GlobalContext* globalCtx);
void BgHidanFwbig_WaitForTimer(BgHidanFwbig* pthis, GlobalContext* globalCtx);
void BgHidanFwbig_WaitForPlayer(BgHidanFwbig* pthis, GlobalContext* globalCtx);
void BgHidanFwbig_Move(BgHidanFwbig* pthis, GlobalContext* globalCtx);

ActorInit Bg_Hidan_Fwbig_InitVars = {
    ACTOR_BG_HIDAN_FWBIG,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanFwbig),
    (ActorFunc)BgHidanFwbig_Init,
    (ActorFunc)BgHidanFwbig_Destroy,
    (ActorFunc)BgHidanFwbig_Update,
    (ActorFunc)BgHidanFwbig_Draw,
    (ActorFunc)BgHidanFwbig_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x20000000, 0x01, 0x04 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 30, 130, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 1000, ICHAIN_STOP),
};

void BgHidanFwbig_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    BgHidanFwbig* pthis = (BgHidanFwbig*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->direction = (u16)(thisx->params >> 8);
    thisx->params &= 0xFF;
    if (pthis->direction != 0) {
        pthis->actor.home.pos.x = 1560.0f;
        pthis->actor.home.pos.z = 0.0f;
        if (player->actor.world.pos.z > 300.0f) {
            pthis->direction = -1;
            pthis->actor.home.rot.y = pthis->actor.shape.rot.y = -0x4E38;
        } else if (player->actor.world.pos.z < -300.0f) {
            pthis->direction = 1;
            pthis->actor.home.rot.y = pthis->actor.shape.rot.y = -0x31C8;
        } else {
            Actor_Kill(&pthis->actor);
            return;
        }
        BgHidanFwbig_UpdatePosition(pthis);
        Actor_SetScale(&pthis->actor, 0.15f);
        pthis->collider.dim.height = 230;
        pthis->actor.flags |= ACTOR_FLAG_4;
        pthis->moveState = FWBIG_MOVE;
        pthis->actionFunc = BgHidanFwbig_WaitForPlayer;
        pthis->actor.world.pos.y = pthis->actor.home.pos.y - (2400.0f * pthis->actor.scale.y);
    } else {
        Actor_SetScale(&pthis->actor, 0.1f);
        pthis->actionFunc = BgHidanFwbig_WaitForSwitch;
    }
}

void BgHidanFwbig_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHidanFwbig* pthis = (BgHidanFwbig*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void BgHidanFwbig_UpdatePosition(BgHidanFwbig* pthis) {
    s16 startAngle = pthis->actor.shape.rot.y + pthis->direction * -0x4000;

    pthis->actor.world.pos.x = (Math_SinS(startAngle) * 885.4f) + pthis->actor.home.pos.x;
    pthis->actor.world.pos.z = (Math_CosS(startAngle) * 885.4f) + pthis->actor.home.pos.z;
}

void BgHidanFwbig_WaitForSwitch(BgHidanFwbig* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        pthis->actionFunc = BgHidanFwbig_WaitForCs;
        OnePointCutscene_Init(globalCtx, 3340, -99, &pthis->actor, MAIN_CAM);
        pthis->timer = 35;
    }
}

void BgHidanFwbig_WaitForCs(BgHidanFwbig* pthis, GlobalContext* globalCtx) {
    if (pthis->timer-- == 0) {
        pthis->actionFunc = BgHidanFwbig_Lower;
    }
}

void BgHidanFwbig_Rise(BgHidanFwbig* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 10.0f)) {
        if (pthis->direction == 0) {
            Flags_UnsetSwitch(globalCtx, pthis->actor.params);
            pthis->actionFunc = BgHidanFwbig_WaitForSwitch;
        } else {
            pthis->actionFunc = BgHidanFwbig_Move;
        }
    }
}

void BgHidanFwbig_Lower(BgHidanFwbig* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y - (2400.0f * pthis->actor.scale.y), 10.0f)) {
        if (pthis->direction == 0) {
            pthis->actionFunc = BgHidanFwbig_WaitForTimer;
            pthis->timer = 150;
        } else if (pthis->moveState == FWBIG_KILL) {
            Actor_Kill(&pthis->actor);
        } else {
            if (pthis->moveState == FWBIG_MOVE) {
                pthis->actor.shape.rot.y -= (pthis->direction * 0x1800);
            } else {
                pthis->moveState = FWBIG_MOVE;
                pthis->actor.shape.rot.y = pthis->actor.home.rot.y;
            }
            BgHidanFwbig_UpdatePosition(pthis);
            pthis->actionFunc = BgHidanFwbig_Rise;
        }
    }
}

void BgHidanFwbig_WaitForTimer(BgHidanFwbig* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        pthis->actionFunc = BgHidanFwbig_Rise;
    }
    func_8002F994(&pthis->actor, pthis->timer);
}

void BgHidanFwbig_WaitForPlayer(BgHidanFwbig* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (player->actor.world.pos.x < 1150.0f) {
        pthis->actionFunc = BgHidanFwbig_Rise;
        OnePointCutscene_Init(globalCtx, 3290, -99, &pthis->actor, MAIN_CAM);
    }
}

void BgHidanFwbig_Move(BgHidanFwbig* pthis, GlobalContext* globalCtx) {
    if (!Player_InCsMode(globalCtx)) {
        if (Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y + (pthis->direction * 0x6390), 0x20)) {
            pthis->moveState = FWBIG_RESET;
            pthis->actionFunc = BgHidanFwbig_Lower;
        } else {
            BgHidanFwbig_UpdatePosition(pthis);
        }
    }
}

void BgHidanFwbig_MoveCollider(BgHidanFwbig* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f projPos;
    f32 cs;
    f32 sn;

    func_8002DBD0(&pthis->actor, &projPos, &player->actor.world.pos);
    projPos.z = ((projPos.z >= 0.0f) ? 1.0f : -1.0f) * 25.0f * -1.0f;
    if (pthis->direction == 0) {
        projPos.x = CLAMP(projPos.x, -360.0f, 360.0f);
    } else {
        projPos.x = CLAMP(projPos.x, -500.0f, 500.0f);
    }

    sn = Math_SinS(pthis->actor.shape.rot.y);
    cs = Math_CosS(pthis->actor.shape.rot.y);
    pthis->collider.dim.pos.x = pthis->actor.world.pos.x + (projPos.x * cs) + (projPos.z * sn);
    pthis->collider.dim.pos.z = pthis->actor.world.pos.z - (projPos.x * sn) + (projPos.z * cs);
    pthis->collider.dim.pos.y = pthis->actor.world.pos.y;

    pthis->actor.world.rot.y = (projPos.z < 0.0f) ? pthis->actor.shape.rot.y : pthis->actor.shape.rot.y + 0x8000;
}

void BgHidanFwbig_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHidanFwbig* pthis = (BgHidanFwbig*)thisx;

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        func_8002F71C(globalCtx, &pthis->actor, 5.0f, pthis->actor.world.rot.y, 1.0f);
        if (pthis->direction != 0) {
            pthis->actionFunc = BgHidanFwbig_Lower;
        }
    }
    if ((pthis->direction != 0) && (globalCtx->roomCtx.prevRoom.num == pthis->actor.room)) {
        pthis->moveState = FWBIG_KILL;
        pthis->actionFunc = BgHidanFwbig_Lower;
    }

    pthis->actionFunc(pthis, globalCtx);

    if ((pthis->actor.home.pos.y - 200.0f) < pthis->actor.world.pos.y) {
        if (gSaveContext.sceneSetupIndex < 4) {
            func_8002F974(&pthis->actor, NA_SE_EV_BURNING - SFX_FLAG);
        } else if ((s16)pthis->actor.world.pos.x == -513) {
            func_8002F974(&pthis->actor, NA_SE_EV_FLAME_OF_FIRE - SFX_FLAG);
        }
        BgHidanFwbig_MoveCollider(pthis, globalCtx);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void BgHidanFwbig_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    f32 height;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_fwbig.c", 630);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(gEffUnknown4Tex));

    gSPSegment(POLY_XLU_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(gEffUnknown5Tex));

    height = thisx->scale.y * 2400.0f;
    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 220, 0,
                    ((height - (thisx->home.pos.y - thisx->world.pos.y)) * 255.0f) / height);

    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, globalCtx->gameplayFrames % 0x80, 0, 0x20, 0x40, 1, 0,
                                (u8)(globalCtx->gameplayFrames * -15), 0x20, 0x40));

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_hidan_fwbig.c", 660),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_XLU_DISP++, gFireTempleBigFireWallDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_fwbig.c", 664);
}

void BgHidanFwbig_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Hidan_Fwbig_InitVars = {
        ACTOR_BG_HIDAN_FWBIG,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_HIDAN_OBJECTS,
        sizeof(BgHidanFwbig),
        (ActorFunc)BgHidanFwbig_Init,
        (ActorFunc)BgHidanFwbig_Destroy,
        (ActorFunc)BgHidanFwbig_Update,
        (ActorFunc)BgHidanFwbig_Draw,
        (ActorFunc)BgHidanFwbig_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_NONE,
            OC1_ON | OC1_TYPE_PLAYER,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x20000000, 0x01, 0x04 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 30, 130, 0, { 0, 0, 0 } },
    };

}
