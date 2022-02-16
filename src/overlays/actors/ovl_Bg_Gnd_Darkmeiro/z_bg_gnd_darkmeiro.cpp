#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_GND_DARKMEIRO_Z_BG_GND_DARKMEIRO_C
#include "actor_common.h"
/*
 * File: z_bg_gnd_darkmeiro.c
 * Overlay: ovl_Bg_Gnd_Darkmeiro
 * Description: Shadow trial actors (invisible path, clear block, and timer)
 */

#include "z_bg_gnd_darkmeiro.h"
#include "objects/object_demo_kekkai/object_demo_kekkai.h"
#include "def/code_800F7260.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgGndDarkmeiro_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgGndDarkmeiro_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgGndDarkmeiro_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgGndDarkmeiro_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgGndDarkmeiro_DrawInvisiblePath(Actor* pthisx, GlobalContext* globalCtx);
void BgGndDarkmeiro_DrawSwitchBlock(Actor* pthisx, GlobalContext* globalCtx);
void BgGndDarkmeiro_DrawStaticBlock(Actor* pthisx, GlobalContext* globalCtx);

void BgGndDarkmeiro_Noop(BgGndDarkmeiro* pthis, GlobalContext* globalCtx);
void BgGndDarkmeiro_UpdateBlockTimer(BgGndDarkmeiro* pthis, GlobalContext* globalCtx);
void BgGndDarkmeiro_UpdateStaticBlock(BgGndDarkmeiro* pthis, GlobalContext* globalCtx);
void BgGndDarkmeiro_UpdateSwitchBlock(BgGndDarkmeiro* pthis, GlobalContext* globalCtx);

ActorInit Bg_Gnd_Darkmeiro_InitVars = {
    ACTOR_BG_GND_DARKMEIRO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(BgGndDarkmeiro),
    (ActorFunc)BgGndDarkmeiro_Init,
    (ActorFunc)BgGndDarkmeiro_Destroy,
    (ActorFunc)BgGndDarkmeiro_Update,
    NULL,
    (ActorFunc)BgGndDarkmeiro_Reset,
};

void BgGndDarkmeiro_ToggleBlock(BgGndDarkmeiro* pthis, GlobalContext* globalCtx) {
    if (pthis->actionFlags & 2) {
        if (pthis->timer1 == 0) {
            func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
            pthis->actionFlags &= ~2;
        }
    } else if (pthis->timer1 != 0) {
        func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        pthis->actionFlags |= 2;
    }
}

void BgGndDarkmeiro_Init(Actor* pthisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    CollisionHeader* colHeader = NULL;
    BgGndDarkmeiro* pthis = (BgGndDarkmeiro*)pthisx;

    pthis->updateFunc = BgGndDarkmeiro_Noop;
    Actor_SetScale(&pthis->dyna.actor, 0.1f);
    switch (pthis->dyna.actor.params & 0xFF) {
        case DARKMEIRO_INVISIBLE_PATH:
            pthis->dyna.actor.draw = BgGndDarkmeiro_DrawInvisiblePath;
            pthis->dyna.actor.flags |= ACTOR_FLAG_7;
            break;
        case DARKMEIRO_CLEAR_BLOCK:
            CollisionHeader_GetVirtual(&gClearBlockCol, &colHeader);
            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
            if (((pthis->dyna.actor.params >> 8) & 0x3F) == 0x3F) {
                pthis->updateFunc = BgGndDarkmeiro_UpdateStaticBlock;
                pthis->dyna.actor.draw = BgGndDarkmeiro_DrawStaticBlock;
            } else {
                pthis->actionFlags = pthis->timer1 = pthis->timer2 = 0;
                pthisx->draw = BgGndDarkmeiro_DrawSwitchBlock;
                pthis->updateFunc = BgGndDarkmeiro_UpdateSwitchBlock;
                if (!Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
                    func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
                } else {
                    pthis->timer1 = 64;
                    pthis->actionFlags |= 2;
                }
            }
            break;
        case DARKMEIRO_BLOCK_TIMER:
            pthis->actionFlags = pthis->timer1 = pthis->timer2 = 0;
            pthis->updateFunc = BgGndDarkmeiro_UpdateBlockTimer;
            pthisx->draw = NULL;
            if (Flags_GetSwitch(globalCtx, ((pthis->dyna.actor.params >> 8) & 0x3F) + 1)) {
                pthis->timer1 = 64;
                pthis->actionFlags |= 4;
            }
            if (Flags_GetSwitch(globalCtx, ((pthis->dyna.actor.params >> 8) & 0x3F) + 2)) {
                pthis->timer2 = 64;
                pthis->actionFlags |= 8;
            }
            if ((pthis->timer1 != 0) || (pthis->timer2 != 0)) {
                Flags_SetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F);
            } else {
                Flags_UnsetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F);
            }
            break;
    }
}

void BgGndDarkmeiro_Destroy(Actor* pthisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    BgGndDarkmeiro* pthis = (BgGndDarkmeiro*)pthisx;

    if ((pthis->dyna.actor.params & 0xFF) == 1) {
        if (1) {}
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
}

void BgGndDarkmeiro_Noop(BgGndDarkmeiro* pthis, GlobalContext* globalCtx) {
}

void BgGndDarkmeiro_UpdateBlockTimer(BgGndDarkmeiro* pthis, GlobalContext* globalCtx) {
    s16 timeLeft;

    if (Flags_GetSwitch(globalCtx, ((pthis->dyna.actor.params >> 8) & 0x3F) + 1)) {
        if (pthis->actionFlags & 4) {
            if (pthis->timer1 > 0) {
                pthis->timer1--;
            } else {
                Flags_UnsetSwitch(globalCtx, ((pthis->dyna.actor.params >> 8) & 0x3F) + 1);
                pthis->actionFlags &= ~4;
            }
        } else {
            pthis->actionFlags |= 4;
            pthis->timer1 = 304;
            Audio_PlaySoundGeneral(NA_SE_EV_RED_EYE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    }

    if (Flags_GetSwitch(globalCtx, ((pthis->dyna.actor.params >> 8) & 0x3F) + 2)) {
        if (pthis->actionFlags & 8) {
            if (pthis->timer2 > 0) {
                pthis->timer2--;
            } else {
                Flags_UnsetSwitch(globalCtx, ((pthis->dyna.actor.params >> 8) & 0x3F) + 2);
                pthis->actionFlags &= ~8;
            }
        } else {
            pthis->actionFlags |= 8;
            pthis->timer2 = 304;
            Audio_PlaySoundGeneral(NA_SE_EV_RED_EYE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    }

    timeLeft = CLAMP_MIN(pthis->timer1, pthis->timer2);
    if (timeLeft > 0) {
        func_8002F994(&pthis->dyna.actor, timeLeft);
    }
    if ((pthis->timer1 >= 64) || (pthis->timer2 >= 64)) {
        Flags_SetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F);
    } else {
        Flags_UnsetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F);
    }
}

void BgGndDarkmeiro_UpdateStaticBlock(BgGndDarkmeiro* pthis, GlobalContext* globalCtx) {
}

void BgGndDarkmeiro_UpdateSwitchBlock(BgGndDarkmeiro* pthis, GlobalContext* globalCtx) {
    if (pthis->timer1 > 0) {
        pthis->timer1--;
    }

    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
        pthis->timer1 = 64;
    }

    BgGndDarkmeiro_ToggleBlock(pthis, globalCtx);
}

void BgGndDarkmeiro_Update(Actor* pthisx, GlobalContext* globalCtx2) {
    BgGndDarkmeiro* pthis = (BgGndDarkmeiro*)pthisx;
    GlobalContext* globalCtx = globalCtx2;

    pthis->updateFunc(pthis, globalCtx2);
}

void BgGndDarkmeiro_DrawInvisiblePath(Actor* pthisx, GlobalContext* globalCtx) {
    Gfx_DrawDListXlu(globalCtx, gShadowTrialPathDL);
}

void BgGndDarkmeiro_DrawSwitchBlock(Actor* pthisx, GlobalContext* globalCtx) {
    BgGndDarkmeiro* pthis = (BgGndDarkmeiro*)pthisx;
    s16 vanishTimer;

    vanishTimer = pthis->timer1;
    if (vanishTimer != 0) {
        if (vanishTimer > 64) {
            pthis->timer2 = (pthis->timer2 < 120) ? pthis->timer2 + 8 : 127;
        } else if (vanishTimer > 16) {
            pthis->timer2 = (Math_CosS((u16)pthis->timer1 * 0x1000) * 64.0f) + 127.0f;
            if (pthis->timer2 > 127) {
                pthis->timer2 = 127;
            }
        } else {
            pthis->timer2 = vanishTimer * 8;
        }

        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_gnd_darkmeiro.c", 378);
        //! @bug Due to a bug in the display list, the transparency data is not used.
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 198, 202, 208, pthis->timer2);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_gnd_darkmeiro.c", 380);

        Gfx_DrawDListXlu(globalCtx, gClearBlockDL);
    }
}

void BgGndDarkmeiro_DrawStaticBlock(Actor* pthisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_gnd_darkmeiro.c", 391);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 198, 202, 208, 255);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_gnd_darkmeiro.c", 393);

    Gfx_DrawDListXlu(globalCtx, gClearBlockDL);
}

void BgGndDarkmeiro_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Gnd_Darkmeiro_InitVars = {
        ACTOR_BG_GND_DARKMEIRO,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_DEMO_KEKKAI,
        sizeof(BgGndDarkmeiro),
        (ActorFunc)BgGndDarkmeiro_Init,
        (ActorFunc)BgGndDarkmeiro_Destroy,
        (ActorFunc)BgGndDarkmeiro_Update,
        NULL,
        (ActorFunc)BgGndDarkmeiro_Reset,
    };

}
