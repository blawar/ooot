#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_DEKUJR_Z_OBJ_DEKUJR_C
#include "actor_common.h"
/*
 * File: z_obj_dekujr.c
 * Overlay: ovl_Obj_Dekujr
 * Description: Deku Tree Sprout
 */

#include "z_obj_dekujr.h"
#include "objects/object_dekujr/object_dekujr.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void ObjDekujr_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjDekujr_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjDekujr_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjDekujr_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjDekujr_ComeUp(ObjDekujr* pthis, GlobalContext* globalCtx);

ActorInit Obj_Dekujr_InitVars = {
    ACTOR_OBJ_DEKUJR,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DEKUJR,
    sizeof(ObjDekujr),
    (ActorFunc)ObjDekujr_Init,
    (ActorFunc)ObjDekujr_Destroy,
    (ActorFunc)ObjDekujr_Update,
    (ActorFunc)ObjDekujr_Draw,
};

static ColliderCylinderInitToActor sCylinderInit = {
    {
        NULL,
        0x00,
        0x00,
        0x39,
        COLSHAPE_CYLINDER,
    },
    { 0x02, { 0x00000000, 0x00, 0x00 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
    { 60, 80, 0, { 0, 0, 0 } },
};

void ObjDekujr_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjDekujr* pthis = (ObjDekujr*)thisx;
    s32 pad;

    if (gSaveContext.cutsceneIndex < 0xFFF0) {
        if (!LINK_IS_ADULT) {
            Actor_Kill(thisx);
            return;
        }
        pthis->unk_19C = 2;
        pthis->unk_19B = 0;
    } else {
        pthis->unk_19C = 0;
        pthis->unk_19B = 1;
    }
    if (!CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
        Actor_Kill(thisx);
    } else {
        ActorShape_Init(&thisx->shape, 0.0f, NULL, 0.0f);
        Collider_InitCylinder(globalCtx, &pthis->collider);
        sCylinderInit.base.actor = thisx;
        Collider_SetCylinderToActor(globalCtx, &pthis->collider, &sCylinderInit);
        thisx->colChkInfo.mass = MASS_IMMOVABLE;
        thisx->textId = func_80037C30(globalCtx, 0xF);
        Actor_SetScale(thisx, 0.4f);
    }
}

void ObjDekujr_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void ObjDekujr_SetInitialPos(CsCmdActorAction* npcAction, Vec3f* initPos) {
    initPos->x = npcAction->startPos.x;
    initPos->y = npcAction->startPos.y;
    initPos->z = npcAction->startPos.z;
}

void ObjDekujr_SetFinalPos(CsCmdActorAction* npcAction, Vec3f* finalPos) {
    finalPos->x = npcAction->endPos.x;
    finalPos->y = npcAction->endPos.y;
    finalPos->z = npcAction->endPos.z;
}

void ObjDekujr_ComeUp(ObjDekujr* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* csCmdNPCAction;
    Vec3f initPos;
    Vec3f finalPos;
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    f32 actionLength;
    f32 gravity;

    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        pthis->unk_19C = 2;
        pthis->unk_19B = 0;
    } else {
        if (globalCtx->csCtx.frames == 351) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_COME_UP_DEKU_JR);
        }
        csCmdNPCAction = globalCtx->csCtx.npcActions[1];
        if (csCmdNPCAction != NULL) {
            ObjDekujr_SetInitialPos(csCmdNPCAction, &initPos);
            ObjDekujr_SetFinalPos(csCmdNPCAction, &finalPos);
            if (pthis->unk_19C == 0) {
                pthis->actor.world.pos = initPos;
                pthis->unk_19C = 1;
            }
            pthis->actor.shape.rot.x = csCmdNPCAction->urot.x;
            pthis->actor.shape.rot.y = csCmdNPCAction->urot.y;
            pthis->actor.shape.rot.z = csCmdNPCAction->urot.z;
            pthis->actor.velocity = velocity;
            if (globalCtx->csCtx.frames < csCmdNPCAction->endFrame) {
                actionLength = (csCmdNPCAction->endFrame - csCmdNPCAction->startFrame);
                pthis->actor.velocity.x = (finalPos.x - initPos.x) / actionLength;
                gravity = pthis->actor.gravity;
                pthis->actor.velocity.y = (finalPos.y - initPos.y) / actionLength;
                pthis->actor.velocity.y += gravity;
                if (pthis->actor.velocity.y < pthis->actor.minVelocityY) {
                    pthis->actor.velocity.y = pthis->actor.minVelocityY;
                }
                pthis->actor.velocity.z = (finalPos.z - initPos.z) / actionLength;
            }
        }
    }
}

void ObjDekujr_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjDekujr* pthis = (ObjDekujr*)thisx;
    s32 pad;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    if ((gSaveContext.cutsceneIndex >= 0xFFF0) && (pthis->unk_19B == 0)) {
        pthis->unk_19C = 0;
        pthis->unk_19B = 1;
    }
    if (pthis->unk_19B == 1) {
        ObjDekujr_ComeUp(pthis, globalCtx);
        pthis->actor.world.pos.x += pthis->actor.velocity.x;
        pthis->actor.world.pos.y += pthis->actor.velocity.y;
        pthis->actor.world.pos.z += pthis->actor.velocity.z;
    } else {
        func_80037D98(globalCtx, &pthis->actor, 0xF, &pthis->unk_1A0);
        Actor_SetFocus(&pthis->actor, 40.0f);
    }
}

void ObjDekujr_Draw(Actor* thisx, GlobalContext* globalCtx) {
	const auto& frameCount = globalCtx->state.frames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_obj_dekujr.c", 370);

    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_dekujr.c", 379),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, object_dekujr_DL_0030D0);

    gSPSegment(
        POLY_XLU_DISP++, 0x08,
        Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, frameCount % 128, 0, 32, 32, 1, frameCount % 128, 0, 32, 32));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_dekujr.c", 399),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, object_dekujr_DL_0032D8);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_obj_dekujr.c", 409);
}
