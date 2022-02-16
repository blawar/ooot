#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_GND_NISEKABE_Z_BG_GND_NISEKABE_C
#include "actor_common.h"
/*
 * File: z_bg_gnd_nisekabe.c
 * Overlay: ovl_Bg_Gnd_Nisekabe
 * Description: Ganon's Castle Fake Wall
 */

#include "z_bg_gnd_nisekabe.h"
#include "objects/object_demo_kekkai/object_demo_kekkai.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"

#define FLAGS ACTOR_FLAG_4

void BgGndNisekabe_Init(Actor* thisx, GlobalContext* globalCtx);
void BgGndNisekabe_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgGndNisekabe_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgGndNisekabe_Update(Actor* thisx, GlobalContext* globalCtx);
void BgGndNisekabe_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Bg_Gnd_Nisekabe_InitVars = {
    ACTOR_BG_GND_NISEKABE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(BgGndNisekabe),
    (ActorFunc)BgGndNisekabe_Init,
    (ActorFunc)BgGndNisekabe_Destroy,
    (ActorFunc)BgGndNisekabe_Update,
    (ActorFunc)BgGndNisekabe_Draw,
    (ActorFunc)BgGndNisekabe_Reset,
};

static Gfx* dLists[] = {
    gLightTrialFakeWallDL,
    gGanonsCastleUnusedFakeWallDL,
    gGanonsCastleScrubsFakeWallDL,
};

void BgGndNisekabe_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgGndNisekabe* pthis = (BgGndNisekabe*)thisx;

    Actor_SetScale(&pthis->actor, 0.1);
    pthis->actor.uncullZoneForward = 3000.0;
}

void BgGndNisekabe_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void BgGndNisekabe_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgGndNisekabe* pthis = (BgGndNisekabe*)thisx;

    if (globalCtx->actorCtx.unk_03 != 0) {
        pthis->actor.flags |= ACTOR_FLAG_7;
    } else {
        pthis->actor.flags &= ~ACTOR_FLAG_7;
    }
}

void BgGndNisekabe_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgGndNisekabe* pthis = (BgGndNisekabe*)thisx;
    u32 index = pthis->actor.params & 0xFF;

    if (CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7)) {
        Gfx_DrawDListXlu(globalCtx, dLists[index]);
    } else {
        Gfx_DrawDListOpa(globalCtx, dLists[index]);
    }
}

void BgGndNisekabe_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Gnd_Nisekabe_InitVars = {
        ACTOR_BG_GND_NISEKABE,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_DEMO_KEKKAI,
        sizeof(BgGndNisekabe),
        (ActorFunc)BgGndNisekabe_Init,
        (ActorFunc)BgGndNisekabe_Destroy,
        (ActorFunc)BgGndNisekabe_Update,
        (ActorFunc)BgGndNisekabe_Draw,
        (ActorFunc)BgGndNisekabe_Reset,
    };

}
