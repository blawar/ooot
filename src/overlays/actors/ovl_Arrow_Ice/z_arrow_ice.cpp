#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_ARROW_ICE_Z_ARROW_ICE_C
#include "actor_common.h"
/*
 * File: z_arrow_ice.c
 * Overlay: ovl_Arrow_Ice
 * Description: Ice Arrow. Spawned as a child of a normal arrow.
 */

#include "z_arrow_ice.h"

#include "overlays/actors/ovl_En_Arrow/z_en_arrow.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_25)

void ArrowIce_Init(Actor* pthisx, GlobalContext* globalCtx);
void ArrowIce_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void ArrowIce_Update(Actor* pthisx, GlobalContext* globalCtx);
void ArrowIce_Draw(Actor* pthisx, GlobalContext* globalCtx);

void ArrowIce_Charge(ArrowIce* pthis, GlobalContext* globalCtx);
void ArrowIce_Fly(ArrowIce* pthis, GlobalContext* globalCtx);
void ArrowIce_Hit(ArrowIce* pthis, GlobalContext* globalCtx);

#include "overlays/ovl_Arrow_Ice/ovl_Arrow_Ice.cpp"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"

ActorInit Arrow_Ice_InitVars = {
    ACTOR_ARROW_ICE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ArrowIce),
    (ActorFunc)ArrowIce_Init,
    (ActorFunc)ArrowIce_Destroy,
    (ActorFunc)ArrowIce_Update,
    (ActorFunc)ArrowIce_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_STOP),
};

void ArrowIce_SetupAction(ArrowIce* pthis, ArrowIceActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void ArrowIce_Init(Actor* pthisx, GlobalContext* globalCtx) {
    ArrowIce* pthis = (ArrowIce*)pthisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->radius = 0;
    pthis->unk_160 = 1.0f;
    ArrowIce_SetupAction(pthis, ArrowIce_Charge);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->alpha = 100;
    pthis->timer = 0;
    pthis->unk_164 = 0.0f;
}

void ArrowIce_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    func_800876C8(globalCtx);
    LOG_STRING("消滅", "../z_arrow_ice.c", 415); // "Disappearance"
}

void ArrowIce_Charge(ArrowIce* pthis, GlobalContext* globalCtx) {
    EnArrow* arrow;

    arrow = (EnArrow*)pthis->actor.parent;
    if ((arrow == NULL) || (arrow->actor.update == NULL)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->radius < 10) {
        pthis->radius += 1;
    }
    // copy position and rotation from arrow
    pthis->actor.world.pos = arrow->actor.world.pos;
    pthis->actor.shape.rot = arrow->actor.shape.rot;

    func_8002F974(&pthis->actor, NA_SE_PL_ARROW_CHARGE_ICE - SFX_FLAG);

    // if arrow has no parent, player has fired the arrow
    if (arrow->actor.parent == NULL) {
        pthis->unkPos = pthis->actor.world.pos;
        pthis->radius = 10;
        ArrowIce_SetupAction(pthis, ArrowIce_Fly);
        pthis->alpha = 255;
    }
}

void func_80867E8C(Vec3f* unkPos, Vec3f* icePos, f32 scale) {
    unkPos->x += ((icePos->x - unkPos->x) * scale);
    unkPos->y += ((icePos->y - unkPos->y) * scale);
    unkPos->z += ((icePos->z - unkPos->z) * scale);
}

void ArrowIce_Hit(ArrowIce* pthis, GlobalContext* globalCtx) {
    f32 scale;
    f32 offset;
    u16 timer;

    if (pthis->actor.projectedW < 50.0f) {
        scale = 10.0f;
    } else {
        if (950.0f < pthis->actor.projectedW) {
            scale = 310.0f;
        } else {
            scale = pthis->actor.projectedW;
            scale = ((scale - 50.0f) * (1.0f / 3.0f)) + 10.0f;
        }
    }

    timer = pthis->timer;
    if (timer != 0) {
        pthis->timer -= 1;

        if (pthis->timer >= 8) {
            offset = ((pthis->timer - 8) * (1.0f / 24.0f));
            offset = SQ(offset);
            pthis->radius = (((1.0f - offset) * scale) + 10.0f);
            pthis->unk_160 += ((2.0f - pthis->unk_160) * 0.1f);
            if (pthis->timer < 16) {
                if (1) {}
                pthis->alpha = ((pthis->timer * 0x23) - 0x118);
            }
        }
    }

    if (pthis->timer >= 9) {
        if (pthis->unk_164 < 1.0f) {
            pthis->unk_164 += 0.25f;
        }
    } else {
        if (pthis->unk_164 > 0.0f) {
            pthis->unk_164 -= 0.125f;
        }
    }

    if (pthis->timer < 8) {
        pthis->alpha = 0;
    }

    if (pthis->timer == 0) {
        pthis->timer = 255;
        Actor_Kill(&pthis->actor);
    }
}

void ArrowIce_Fly(ArrowIce* pthis, GlobalContext* globalCtx) {
    EnArrow* arrow;
    f32 distanceScaled;
    s32 pad;

    arrow = (EnArrow*)pthis->actor.parent;
    if ((arrow == NULL) || (arrow->actor.update == NULL)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    // copy position and rotation from arrow
    pthis->actor.world.pos = arrow->actor.world.pos;
    pthis->actor.shape.rot = arrow->actor.shape.rot;
    distanceScaled = Math_Vec3f_DistXYZ(&pthis->unkPos, &pthis->actor.world.pos) * (1.0f / 24.0f);
    pthis->unk_160 = distanceScaled;
    if (distanceScaled < 1.0f) {
        pthis->unk_160 = 1.0f;
    }
    func_80867E8C(&pthis->unkPos, &pthis->actor.world.pos, 0.05f);

    if (arrow->hitFlags & 1) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_EXPLOSION_ICE);
        ArrowIce_SetupAction(pthis, ArrowIce_Hit);
        pthis->timer = 32;
        pthis->alpha = 255;
    } else if (arrow->timer < 34) {
        if (pthis->alpha < 35) {
            Actor_Kill(&pthis->actor);
        } else {
            pthis->alpha -= 0x19;
        }
    }
}

void ArrowIce_Update(Actor* pthisx, GlobalContext* globalCtx) {
    ArrowIce* pthis = (ArrowIce*)pthisx;

    if (globalCtx->msgCtx.msgMode == MSGMODE_OCARINA_CORRECT_PLAYBACK ||
        globalCtx->msgCtx.msgMode == MSGMODE_SONG_PLAYED) {
        Actor_Kill(&pthis->actor);
    } else {
        pthis->actionFunc(pthis, globalCtx);
    }
}

void ArrowIce_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    ArrowIce* pthis = (ArrowIce*)pthisx;
    s32 pad;
    Actor* tranform;
    const auto& stateFrames = globalCtx->state.frames;
    EnArrow* arrow = (EnArrow*)pthis->actor.parent;

    if (1) {}

    if ((arrow != NULL) && (arrow->actor.update != NULL) && (pthis->timer < 255)) {
        if (1) {}
        tranform = (arrow->hitFlags & 2) ? &pthis->actor : &arrow->actor;

        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_arrow_ice.c", 610);

        Matrix_Translate(tranform->world.pos.x, tranform->world.pos.y, tranform->world.pos.z, MTXMODE_NEW);
        Matrix_RotateY(tranform->shape.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);
        Matrix_RotateX(tranform->shape.rot.x * (M_PI / 0x8000), MTXMODE_APPLY);
        Matrix_RotateZ(tranform->shape.rot.z * (M_PI / 0x8000), MTXMODE_APPLY);
        Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);

        // Draw blue effect over the screen when arrow hits
        if (pthis->unk_164 > 0) {
            POLY_XLU_DISP = func_800937C0(POLY_XLU_DISP);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, (s32)(10.0f * pthis->unk_164) & 0xFF,
                            (s32)(50.0f * pthis->unk_164) & 0xFF, (s32)(150.0f * pthis->unk_164) & 0xFF);
            gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_DISABLE);
            gDPSetColorDither(POLY_XLU_DISP++, G_CD_DISABLE);
            gDPFillRectangle(POLY_XLU_DISP++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
        }

        // Draw ice on the arrow
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 170, 255, 255, pthis->alpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 255, 128);
        Matrix_RotateZYX(0x4000, 0x0, 0x0, MTXMODE_APPLY);
        if (pthis->timer != 0) {
            Matrix_Translate(0.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        } else {
            Matrix_Translate(0.0f, 1500.0f, 0.0f, MTXMODE_APPLY);
        }
        Matrix_Scale(pthis->radius * 0.2f, pthis->unk_160 * 3.0f, pthis->radius * 0.2f, MTXMODE_APPLY);
        Matrix_Translate(0.0f, -700.0f, 0.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_arrow_ice.c", 660),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, sMaterialDL);
        gSPDisplayList(POLY_XLU_DISP++,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 511 - (stateFrames * 5) % 512, 0, 128, 32, 1,
                                        511 - (stateFrames * 10) % 512, 511 - (stateFrames * 10) % 512, 4, 16));
        gSPDisplayList(POLY_XLU_DISP++, sModelDL);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_arrow_ice.c", 676);
    }
}
