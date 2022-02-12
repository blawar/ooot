#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MENKURI_NISEKABE_Z_BG_MENKURI_NISEKABE_C
#include "actor_common.h"
/*
 * File: z_bg_menkuri_nisekabe.c
 * Overlay: ovl_Bg_Menkuri_Nisekabe
 * Description: False Stone Walls (Gerudo Training Grounds)
 */

#include "z_bg_menkuri_nisekabe.h"
#include "objects/object_menkuri_objects/object_menkuri_objects.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"

#define FLAGS 0

void BgMenkuriNisekabe_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMenkuriNisekabe_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMenkuriNisekabe_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMenkuriNisekabe_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Bg_Menkuri_Nisekabe_InitVars = {
    ACTOR_BG_MENKURI_NISEKABE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_MENKURI_OBJECTS,
    sizeof(BgMenkuriNisekabe),
    (ActorFunc)BgMenkuriNisekabe_Init,
    (ActorFunc)BgMenkuriNisekabe_Destroy,
    (ActorFunc)BgMenkuriNisekabe_Update,
    (ActorFunc)BgMenkuriNisekabe_Draw,
};

static Gfx* sDLists[] = { gGTGFakeWallDL, gGTGFakeCeilingDL };

void BgMenkuriNisekabe_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgMenkuriNisekabe* pthis = (BgMenkuriNisekabe*)thisx;

    Actor_SetScale(&pthis->actor, 0.1f);
}

void BgMenkuriNisekabe_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void BgMenkuriNisekabe_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgMenkuriNisekabe* pthis = (BgMenkuriNisekabe*)thisx;

    if (globalCtx->actorCtx.unk_03 != 0) {
        pthis->actor.flags |= ACTOR_FLAG_7;
    } else {
        pthis->actor.flags &= ~ACTOR_FLAG_7;
    }
}

void BgMenkuriNisekabe_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgMenkuriNisekabe* pthis = (BgMenkuriNisekabe*)thisx;
    u32 index = pthis->actor.params & 0xFF;

    if (CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7)) {
        Gfx_DrawDListXlu(globalCtx, sDLists[index]);
    } else {
        Gfx_DrawDListOpa(globalCtx, sDLists[index]);
    }
}
