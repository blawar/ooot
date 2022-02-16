#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BLKOBJ_Z_EN_BLKOBJ_C
#include "actor_common.h"
/*
 * File: z_en_blkobj.c
 * Overlay: ovl_En_Blkobj
 * Description: Dark Link's Illusion Room
 */

#include "z_en_blkobj.h"
#include "objects/object_blkobj/object_blkobj.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnBlkobj_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBlkobj_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBlkobj_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBlkobj_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBlkobj_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnBlkobj_Wait(EnBlkobj* pthis, GlobalContext* globalCtx);
void EnBlkobj_SpawnDarkLink(EnBlkobj* pthis, GlobalContext* globalCtx);
void EnBlkobj_DarkLinkFight(EnBlkobj* pthis, GlobalContext* globalCtx);
void EnBlkobj_DoNothing(EnBlkobj* pthis, GlobalContext* globalCtx);

ActorInit En_Blkobj_InitVars = {
    ACTOR_EN_BLKOBJ,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_BLKOBJ,
    sizeof(EnBlkobj),
    (ActorFunc)EnBlkobj_Init,
    (ActorFunc)EnBlkobj_Destroy,
    (ActorFunc)EnBlkobj_Update,
    (ActorFunc)EnBlkobj_Draw,
    (ActorFunc)EnBlkobj_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F(scale, 1, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 300, ICHAIN_STOP),
};

static Gfx sSetupOpaDL[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPEndDisplayList(),
};

static Gfx sSetupXluDL[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsSPEndDisplayList(),
};

void EnBlkobj_SetupAction(EnBlkobj* pthis, EnBlkobjActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
    pthis->timer = 0;
}

void EnBlkobj_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnBlkobj* pthis = (EnBlkobj*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    if (Flags_GetClear(globalCtx, pthis->dyna.actor.room)) {
        pthis->alpha = 255;
        EnBlkobj_SetupAction(pthis, EnBlkobj_DoNothing);
    } else {
        CollisionHeader_GetVirtual(&gIllusionRoomCol, &colHeader);
        pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
        EnBlkobj_SetupAction(pthis, EnBlkobj_Wait);
    }
}

void EnBlkobj_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnBlkobj* pthis = (EnBlkobj*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void EnBlkobj_Wait(EnBlkobj* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->dyna.actor.xzDistToPlayer < 120.0f) {
        EnBlkobj_SetupAction(pthis, EnBlkobj_SpawnDarkLink);
    }
    player->stateFlags2 |= 0x04000000;
}

void EnBlkobj_SpawnDarkLink(EnBlkobj* pthis, GlobalContext* globalCtx) {
    if (!(pthis->dyna.actor.flags & ACTOR_FLAG_UNCULLED)) {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_TORCH2, pthis->dyna.actor.world.pos.x,
                    pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z, 0, pthis->dyna.actor.yawTowardsPlayer, 0,
                    0);
        EnBlkobj_SetupAction(pthis, EnBlkobj_DarkLinkFight);
    }
}

void EnBlkobj_DarkLinkFight(EnBlkobj* pthis, GlobalContext* globalCtx) {
    s32 alphaMod;

    if (pthis->timer == 0) {
        if (Actor_Find(&globalCtx->actorCtx, ACTOR_EN_TORCH2, ACTORCAT_BOSS) == NULL) {
            Flags_SetClear(globalCtx, pthis->dyna.actor.room);
            pthis->timer++;
        }
    } else if (pthis->timer++ > 100) {
        alphaMod = (pthis->timer - 100) >> 2;
        if (alphaMod > 5) {
            alphaMod = 5;
        }
        pthis->alpha += alphaMod;
        if (pthis->alpha > 255) {
            pthis->alpha = 255;
            EnBlkobj_SetupAction(pthis, EnBlkobj_DoNothing);
            DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        }
    }
}

void EnBlkobj_DoNothing(EnBlkobj* pthis, GlobalContext* globalCtx) {
}

void EnBlkobj_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnBlkobj* pthis = (EnBlkobj*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void EnBlkobj_DrawAlpha(GlobalContext* globalCtx, Gfx* dList, s32 alpha) {
    Gfx* segment;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_blkobj.c", 322);

    if (alpha == 255) {
        segment = sSetupOpaDL;
    } else {
        segment = sSetupXluDL;
    }

    gSPSegment(POLY_XLU_DISP++, 0x08, segment);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, alpha);
    gSPDisplayList(POLY_XLU_DISP++, dList);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_blkobj.c", 330);
}

void EnBlkobj_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnBlkobj* pthis = (EnBlkobj*)thisx;
    s32 illusionAlpha;
    u32 gameplayFrames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_blkobj.c", 349);

    func_80093D84(globalCtx->state.gfxCtx);

    gameplayFrames = globalCtx->gameplayFrames % 128;

    gSPSegment(POLY_XLU_DISP++, 0x0D,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, gameplayFrames, 0, 32, 32, 1, gameplayFrames, 0, 32, 32));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_blkobj.c", 363),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (pthis->alpha != 0) {
        EnBlkobj_DrawAlpha(globalCtx, gIllusionRoomNormalDL, pthis->alpha);
    }
    illusionAlpha = 255 - pthis->alpha;
    if (illusionAlpha != 0) {
        EnBlkobj_DrawAlpha(globalCtx, gIllusionRoomIllusionDL, illusionAlpha);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_blkobj.c", 375);
}

void EnBlkobj_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Blkobj_InitVars = {
        ACTOR_EN_BLKOBJ,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_BLKOBJ,
        sizeof(EnBlkobj),
        (ActorFunc)EnBlkobj_Init,
        (ActorFunc)EnBlkobj_Destroy,
        (ActorFunc)EnBlkobj_Update,
        (ActorFunc)EnBlkobj_Draw,
        (ActorFunc)EnBlkobj_Reset,
    };

}
