#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EFC_ERUPC_Z_EFC_ERUPC_C
#include "actor_common.h"
#include "z_efc_erupc.h"
#include "objects/object_efc_erupc/object_efc_erupc.h"
#include "def/code_800EC960.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EfcErupc_Init(Actor* thisx, GlobalContext* globalCtx);
void EfcErupc_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EfcErupc_Update(Actor* thisx, GlobalContext* globalCtx);
void EfcErupc_Draw(Actor* thisx, GlobalContext* globalCtx);

void EfcErupc_UpdateAction(EfcErupc* pthis, GlobalContext* globalCtx);
void EfcErupc_DrawParticles(EfcErupcParticles* particles, GlobalContext* globalCtx);
void EfcErupc_UpdateParticles(EfcErupc* pthis, GlobalContext* globalCtx);
void EfcErupc_AddParticle(EfcErupcParticles* particles, Vec3f* pos, Vec3f* vel, Vec3f* accel, f32 scaleFactor);
void EfcErupc_InitParticles(EfcErupcParticles* particles);

ActorInit Efc_Erupc_InitVars = {
    ACTOR_EFC_ERUPC,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_EFC_ERUPC,
    sizeof(EfcErupc),
    (ActorFunc)EfcErupc_Init,
    (ActorFunc)EfcErupc_Destroy,
    (ActorFunc)EfcErupc_Update,
    (ActorFunc)EfcErupc_Draw,
};

void EfcErupc_SetupAction(EfcErupc* pthis, EfcErupcActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EfcErupc_Init(Actor* thisx, GlobalContext* globalCtx) {
    EfcErupc* pthis = (EfcErupc*)thisx;

    EfcErupc_SetupAction(pthis, EfcErupc_UpdateAction);
    Actor_SetScale(&pthis->actor, 1.0f);
    EfcErupc_InitParticles(pthis->particles);
    pthis->unk14C = pthis->unk14E = pthis->unk150 = 0;
    pthis->unk152 = 5;
    pthis->unk154 = -100;
}

void EfcErupc_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EfcErupc_UpdateAction(EfcErupc* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f vel;
    Vec3f accel;
    s32 i;

    if (globalCtx->csCtx.state != 0) {
        if (globalCtx->csCtx.npcActions[1] != NULL) {
            if (globalCtx->csCtx.npcActions[1]->action == 2) {
                if (pthis->unk150 == 30) {
                    func_800788CC(NA_SE_IT_EARTHQUAKE);
                }
                if (pthis->unk150 <= 64) {
                    if (pthis->unk154 < 200) {
                        pthis->unk154 += 10;
                    }
                } else {
                    if (pthis->unk154 > -100) {
                        pthis->unk154 -= 10;
                    }
                }
                pthis->unk150++;
            } else {
                if (pthis->unk154 > -100) {
                    pthis->unk154 -= 10;
                }
            }
        }
    }
    if (globalCtx->csCtx.state != 0) {
        if (globalCtx->csCtx.npcActions[2] != NULL) {
            switch (globalCtx->csCtx.npcActions[2]->action) {
                case 2:
                    if (pthis->unk14E == 0) {
                        func_800F3F3C(6);
                        gSaveContext.eventChkInf[2] |= 0x8000;
                    }
                    pthis->unk14E++;
                    break;
                case 3:
                    pthis->unk14E = 30;
            }
            pthis->unk14C++;
        }
    }
    accel.z = 0.0f;
    accel.x = 0.0f;
    pos.y = pthis->actor.world.pos.y + 300.0f;
    for (i = 0; i < pthis->unk152; i++) {
        pos.x = Rand_CenteredFloat(100.0f) + pthis->actor.world.pos.x;
        pos.z = Rand_CenteredFloat(100.0f) + pthis->actor.world.pos.z;
        vel.x = Rand_CenteredFloat(100.0f);
        vel.y = Rand_ZeroFloat(100.0f);
        vel.z = Rand_CenteredFloat(100.0f);
        accel.y = pthis->unk154 * 0.1f;
        EfcErupc_AddParticle(pthis->particles, &pos, &vel, &accel, 80.0f);
    }
}

void EfcErupc_Update(Actor* thisx, GlobalContext* globalCtx) {
    EfcErupc* pthis = (EfcErupc*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    EfcErupc_UpdateParticles(pthis, globalCtx);
}

void EfcErupc_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EfcErupc* pthis = (EfcErupc*)thisx;
    u16 csAction;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_efc_erupc.c", 282);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, pthis->unk14C * 1, pthis->unk14E * -4, 32, 64, 1,
                                pthis->unk14C * 4, pthis->unk14E * -20, 64, 64));

    gSPSegment(
        POLY_XLU_DISP++, 0x09,
        Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, pthis->unk150 * -4, 16, 128, 1, 0, pthis->unk150 * 12, 32, 32));

    gSPSegment(
        POLY_XLU_DISP++, 0x0A,
        Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, pthis->unk150 * -4, 16, 128, 1, 0, pthis->unk150 * 12, 32, 32));

    Matrix_Push();
    Matrix_Scale(0.8f, 0.8f, 0.8f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_efc_erupc.c", 321),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (globalCtx->csCtx.state != 0) {
        if ((globalCtx->csCtx.npcActions[1] != 0) && (globalCtx->csCtx.npcActions[1]->action == 2)) {
            gSPDisplayList(POLY_XLU_DISP++, object_efc_erupc_DL_002570);
        }
    }
    Matrix_Pop();
    Matrix_Scale(3.4f, 3.4f, 3.4f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_efc_erupc.c", 333),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    if (globalCtx->csCtx.state != 0) {
        CsCmdActorAction* csActorAction = globalCtx->csCtx.npcActions[2];
        if (csActorAction != 0) {
            csAction = csActorAction->action;
            if ((csAction == 2) || (csAction == 3)) {
                gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 200, 255);
                gDPSetEnvColor(POLY_XLU_DISP++, 100, 0, 0, 255);
                gSPDisplayList(POLY_XLU_DISP++, object_efc_erupc_DL_001720);
            }
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_efc_erupc.c", 356);
    EfcErupc_DrawParticles(pthis->particles, globalCtx);
}

void EfcErupc_DrawParticles(EfcErupcParticles* particles, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s16 i;
    s32 pad;

    OPEN_DISPS(gfxCtx, "../z_efc_erupc.c", 368);
    for (i = 0; i < EFC_ERUPC_NUM_PARTICLES; i++, particles++) {
        if (particles->isActive) {
            func_80093D84(globalCtx->state.gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, object_efc_erupc_DL_002760);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, particles->color.r, particles->color.g, particles->color.b,
                            particles->alpha);
            gDPSetEnvColor(POLY_XLU_DISP++, 150, 0, 0, 0);
            gDPPipeSync(POLY_XLU_DISP++);
            Matrix_Translate(particles->pos.x, particles->pos.y, particles->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(particles->scale, particles->scale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_efc_erupc.c", 393),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_efc_erupc_DL_0027D8);
        }
    }
    CLOSE_DISPS(gfxCtx, "../z_efc_erupc.c", 399);
}

static Color_RGB8 D_8099D770[] = {
    { 255, 128, 0 },
    { 255, 0, 0 },
    { 255, 255, 0 },
    { 255, 0, 0 },
};

void EfcErupc_UpdateParticles(EfcErupc* pthis, GlobalContext* globalCtx) {
    s16 i;
    s16 index;
    Color_RGB8 particleColors[] = {
        { 255, 128, 0 },
        { 255, 0, 0 },
        { 0, 0, 0 },
        { 100, 0, 0 },
    };
    Color_RGB8* color;
    EfcErupcParticles* cur = pthis->particles;

    for (i = 0; i < EFC_ERUPC_NUM_PARTICLES; i++, cur++) {
        if (cur->isActive) {
            cur->pos.x += cur->vel.x;
            cur->pos.y += cur->vel.y;
            cur->pos.z += cur->vel.z;
            cur->vel.x += cur->accel.x;
            cur->vel.y += cur->accel.y;
            cur->vel.z += cur->accel.z;
            cur->animTimer += 1;
            index = cur->animTimer % 4;
            color = &particleColors[index];
            cur->color.r = color->r;
            cur->color.g = color->g;
            cur->color.b = color->b;
            cur->alpha -= 20;
            if (cur->alpha <= 0) {
                cur->alpha = 0;
                cur->isActive = false;
            }
        }
    }
}

void EfcErupc_AddParticle(EfcErupcParticles* particles, Vec3f* pos, Vec3f* vel, Vec3f* accel, f32 scaleFactor) {
    s16 i;

    for (i = 0; i < EFC_ERUPC_NUM_PARTICLES; i++, particles++) {
        if (!particles->isActive) {
            particles->isActive = true;
            particles->pos = *pos;
            particles->vel = *vel;
            particles->accel = *accel;
            particles->scale = scaleFactor / 1000.0f;
            particles->alpha = 255;
            particles->animTimer = (s16)Rand_ZeroFloat(10.0f);
            return;
        }
    }
}

void EfcErupc_InitParticles(EfcErupcParticles* particles) {
    s16 i;

    for (i = 0; i < EFC_ERUPC_NUM_PARTICLES; i++, particles++) {
        particles->isActive = false;
    }
}
