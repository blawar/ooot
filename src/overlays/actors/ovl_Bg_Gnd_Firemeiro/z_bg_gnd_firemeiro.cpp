#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_GND_FIREMEIRO_Z_BG_GND_FIREMEIRO_C
#include "actor_common.h"
/*
 * File: z_bg_gnd_firemeiro.c
 * Overlay: ovl_Bg_Gnd_Firemeiro
 * Description: Sinking lava platform (Ganon's Castle)
 */

#include "z_bg_gnd_firemeiro.h"
#include "objects/object_demo_kekkai/object_demo_kekkai.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgGndFiremeiro_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgGndFiremeiro_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgGndFiremeiro_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgGndFiremeiro_Draw(Actor* pthisx, GlobalContext* globalCtx);

void BgGndFiremeiro_Sink(BgGndFiremeiro* pthis, GlobalContext* globalCtx);
void BgGndFiremeiro_Shake(BgGndFiremeiro* pthis, GlobalContext* globalCtx);
void BgGndFiremeiro_Rise(BgGndFiremeiro* pthis, GlobalContext* globalCtx);

ActorInit Bg_Gnd_Firemeiro_InitVars = {
    ACTOR_BG_GND_FIREMEIRO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(BgGndFiremeiro),
    (ActorFunc)BgGndFiremeiro_Init,
    (ActorFunc)BgGndFiremeiro_Destroy,
    (ActorFunc)BgGndFiremeiro_Update,
    (ActorFunc)BgGndFiremeiro_Draw,
};

void BgGndFiremeiro_Init(Actor* pthisx, GlobalContext* globalCtx) {
    s32 pad;
    BgGndFiremeiro* pthis = (BgGndFiremeiro*)pthisx;
    CollisionHeader* colHeader = NULL;

    ActorShape_Init(&pthis->dyna.actor.shape, 0.0f, NULL, 0.0f);
    Actor_SetScale(&pthis->dyna.actor, 0.1f);
    pthis->initPos = pthis->dyna.actor.world.pos;

    if (pthis->dyna.actor.params == 0) {
        DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
        CollisionHeader_GetVirtual(&gFireTrialPlatformCol, &colHeader);
        pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
        pthis->actionFunc = BgGndFiremeiro_Rise;
    }
}

void BgGndFiremeiro_Destroy(Actor* pthisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    BgGndFiremeiro* pthis = (BgGndFiremeiro*)pthisx;

    if (pthis->dyna.actor.params == 0) {
        if (1) {}
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
}

void BgGndFiremeiro_Sink(BgGndFiremeiro* pthis, GlobalContext* globalCtx) {
    f32 sunkHeight = pthis->initPos.y - 150.0f;

    if (func_8004356C(&pthis->dyna)) {
        pthis->timer = 10;
    }

    if (sunkHeight < pthis->dyna.actor.world.pos.y) {
        pthis->dyna.actor.world.pos.y -= 0.5f;

        if (pthis->dyna.actor.world.pos.y < sunkHeight) {
            pthis->dyna.actor.world.pos.y = sunkHeight;
        }

        func_8002F948(&pthis->dyna.actor, NA_SE_EV_ROLL_STAND_2 - SFX_FLAG);
    }

    if (pthis->timer > 0) {
        pthis->timer--;
    } else {
        pthis->actionFunc = BgGndFiremeiro_Rise;
    }
}

void BgGndFiremeiro_Shake(BgGndFiremeiro* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 randSign;

    if (func_8004356C(&pthis->dyna)) { // Player standing on it
        if (pthis->timer > 0) {
            pthis->timer--;

            randSign = ((pthis->timer & 1) ? 2.0f : -2.0f);

            pthis->dyna.actor.world.pos = pthis->initPos;
            pthis->dyna.actor.world.pos.x += randSign * Math_SinS(pthis->timer * 0x2FFF);
            pthis->dyna.actor.world.pos.z += randSign * Math_CosS(pthis->timer * 0x2FFF);
            pthis->dyna.actor.world.pos.y += Math_CosS(pthis->timer * 0x7FFF);

            if (!(pthis->timer % 4)) {
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_SHAKE);
            }
        } else {
            pthis->timer = 10;
            pthis->dyna.actor.world.pos = pthis->initPos;
            pthis->actionFunc = BgGndFiremeiro_Sink;
        }
    } else {
        pthis->dyna.actor.world.pos = pthis->initPos;
        pthis->actionFunc = BgGndFiremeiro_Rise;
    }
}

void BgGndFiremeiro_Rise(BgGndFiremeiro* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Actor* pthisx = &pthis->dyna.actor;

    if ((player->currentBoots != PLAYER_BOOTS_HOVER) && func_8004356C(&pthis->dyna)) { // Player standing on it
        if (pthisx->world.pos.y < pthis->initPos.y) {
            pthis->actionFunc = BgGndFiremeiro_Sink;
            pthis->timer = 20;
        } else {
            pthis->actionFunc = BgGndFiremeiro_Shake;
            pthis->timer = 20;
        }
    } else {
        if (pthisx->world.pos.y < pthis->initPos.y) {
            pthisx->world.pos.y += 2.0f;
            if (pthis->initPos.y < pthisx->world.pos.y) {
                pthisx->world.pos.y = pthis->initPos.y;
            }
        }
    }
}

void BgGndFiremeiro_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgGndFiremeiro* pthis = (BgGndFiremeiro*)pthisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgGndFiremeiro_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_gnd_firemeiro.c", 280);
    func_800943C8(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_gnd_firemeiro.c", 282),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gFireTrialPlatformDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_gnd_firemeiro.c", 285);
}
