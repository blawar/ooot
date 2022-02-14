#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DY_EXTRA_Z_EN_DY_EXTRA_C
#include "actor_common.h"
/*
 * File: z_en_dy_extra.c
 * Overlay: ovl_En_Dy_Extra
 * Description: Spiral Beams (Great Fairy Fountains)
 */

#include "z_en_dy_extra.h"
#include "objects/object_dy_obj/object_dy_obj.h"
#include "vt.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnDyExtra_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDyExtra_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDyExtra_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDyExtra_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDyExtra_WaitForTrigger(EnDyExtra* pthis, GlobalContext* globalCtx);
void EnDyExtra_FallAndKill(EnDyExtra* pthis, GlobalContext* globalCtx);

ActorInit En_Dy_Extra_InitVars = {
    ACTOR_EN_DY_EXTRA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DY_OBJ,
    sizeof(EnDyExtra),
    (ActorFunc)EnDyExtra_Init,
    (ActorFunc)EnDyExtra_Destroy,
    (ActorFunc)EnDyExtra_Update,
    (ActorFunc)EnDyExtra_Draw,
};

void EnDyExtra_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnDyExtra_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDyExtra* pthis = (EnDyExtra*)thisx;

    osSyncPrintf("\n\n");
    // "Big fairy effect"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 大妖精効果 ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params);
    pthis->type = pthis->actor.params;
    pthis->scale.x = 0.025f;
    pthis->scale.y = 0.039f;
    pthis->scale.z = 0.025f;
    pthis->unk_168 = pthis->actor.world.pos;
    pthis->actor.gravity = -0.2f;
    pthis->unk_158 = 1.0f;
    pthis->timer = 60;
    pthis->actionFunc = EnDyExtra_WaitForTrigger;
}

void EnDyExtra_WaitForTrigger(EnDyExtra* pthis, GlobalContext* globalCtx) {
    Math_ApproachF(&pthis->actor.gravity, 0.0f, 0.1f, 0.005f);
    if (pthis->actor.world.pos.y < -55.0f) {
        pthis->actor.velocity.y = 0.0f;
    }
    if (pthis->timer == 0 && pthis->trigger != 0) {
        pthis->timer = 200;
        pthis->actionFunc = EnDyExtra_FallAndKill;
    }
}

void EnDyExtra_FallAndKill(EnDyExtra* pthis, GlobalContext* globalCtx) {
    Math_ApproachF(&pthis->actor.gravity, 0.0f, 0.1f, 0.005f);
    if (pthis->timer == 0 || pthis->unk_158 < 0.02f) {
        Actor_Kill(&pthis->actor);
        return;
    }
    Math_ApproachZeroF(&pthis->unk_158, 0.03f, 0.05f);
    if (pthis->actor.world.pos.y < -55.0f) {
        pthis->actor.velocity.y = 0.0f;
    }
}

void EnDyExtra_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDyExtra* pthis = (EnDyExtra*)thisx;

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    pthis->actor.scale.x = pthis->scale.x;
    pthis->actor.scale.y = pthis->scale.y;
    pthis->actor.scale.z = pthis->scale.z;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_PL_SPIRAL_HEAL_BEAM - SFX_FLAG);
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
}

void EnDyExtra_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Color_RGBA8 primColors[] = { { 255, 255, 170, 255 }, { 255, 255, 170, 255 } };
    static Color_RGBA8 envColors[] = { { 255, 100, 255, 255 }, { 100, 255, 255, 255 } };
    static u8 D_809FFC50[] = { 0x02, 0x01, 0x01, 0x02, 0x00, 0x00, 0x02, 0x01, 0x00, 0x02, 0x01, 0x00, 0x02,
                               0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x01, 0x00, 0x01, 0x02 };
    EnDyExtra* pthis = (EnDyExtra*)thisx;
    s32 pad;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    Vtx* vertices = SEGMENTED_TO_VIRTUAL(gGreatFairySpiralBeamVtx);
    s32 i;
    u8 unk[3];

    unk[0] = 0.0f;
    unk[1] = (s8)(pthis->unk_158 * 240.0f);
    unk[2] = (s8)(pthis->unk_158 * 255.0f);

    for (i = 0; i < 27; i++) {
        if (D_809FFC50[i]) {
            vertices[i].v.cn[3] = unk[D_809FFC50[i]];
        }
    }

    OPEN_DISPS(gfxCtx, "../z_en_dy_extra.c", 294);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (globalCtx->state.frames * 2).whole(), 0, 0x20, 0x40, 1,
                                globalCtx->state.frames.whole(), (globalCtx->state.frames * -8).whole(), 0x10, 0x10));
    gDPPipeSync(POLY_XLU_DISP++);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dy_extra.c", 307),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, primColors[pthis->type].r, primColors[pthis->type].g,
                    primColors[pthis->type].b, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, envColors[pthis->type].r, envColors[pthis->type].g, envColors[pthis->type].b, 128);
    gSPDisplayList(POLY_XLU_DISP++, gGreatFairySpiralBeamDL);

    CLOSE_DISPS(gfxCtx, "../z_en_dy_extra.c", 325);
}
