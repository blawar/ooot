#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_BOM_GUARD_Z_BG_BOM_GUARD_C
#include "actor_common.h"
/*
 * File: z_bg_bom_guard.c
 * Overlay: Bg_Bom_Guard
 * Description: Bombchu Bowling Alley Walls
 */

#include "z_bg_bom_guard.h"
#include "overlays/actors/ovl_En_Bom_Bowl_Man/z_en_bom_bowl_man.h"
#include "objects/object_bowl/object_bowl.h"
#include "vt.h"
#include "def/code_80043480.h"
#include "def/z_bgcheck.h"

#define FLAGS ACTOR_FLAG_4

void BgBomGuard_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgBomGuard_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgBomGuard_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgBomGuard_Update(Actor* pthisx, GlobalContext* globalCtx);

void func_8086E638(BgBomGuard* pthis, GlobalContext* globalCtx);

ActorInit Bg_Bom_Guard_InitVars = {
    ACTOR_BG_BOM_GUARD,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_BOWL,
    sizeof(BgBomGuard),
    (ActorFunc)BgBomGuard_Init,
    (ActorFunc)BgBomGuard_Destroy,
    (ActorFunc)BgBomGuard_Update,
    NULL,
    (ActorFunc)BgBomGuard_Reset,
};

void BgBomGuard_SetupAction(BgBomGuard* pthis, BgBomGuardActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgBomGuard_Init(Actor* pthisx, GlobalContext* globalCtx) {
    BgBomGuard* pthis = (BgBomGuard*)pthisx;
    s32 pad[2];
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gBowlingDefaultCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, pthisx, colHeader);

    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 透明ガード出現 ☆☆☆☆☆ \n" VT_RST);

    pthisx->scale.x = 1.0f;
    pthisx->scale.y = 1.0f;
    pthisx->scale.z = 1.0f;
    pthis->unk_16C = pthisx->world.pos;
    BgBomGuard_SetupAction(pthis, func_8086E638);
}

void BgBomGuard_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgBomGuard* pthis = (BgBomGuard*)pthisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_8086E638(BgBomGuard* pthis, GlobalContext* globalCtx) {
    Actor* it = globalCtx->actorCtx.actorLists[ACTORCAT_NPC].head;
    Actor* pthisx = &pthis->dyna.actor;

    pthis->unk_168 = 0;

    while (it != 0) {
        if (it->id == ACTOR_EN_BOM_BOWL_MAN) {
            if ((((EnBomBowlMan*)it)->minigamePlayStatus != 0) && (fabsf(globalCtx->view.eye.x) > -20.0f) &&
                (fabsf(globalCtx->view.eye.y) > 110.0f)) {
                pthis->unk_168 = 1;
            }
            break;
        }
        it = it->next;
    }

    if (pthis->unk_168 == 0) {
        pthisx->world.pos.y = sREG(64) + -200.0f;
    } else {
        pthisx->world.pos.y = 0.0f;
    }
}

void BgBomGuard_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgBomGuard* pthis = (BgBomGuard*)pthisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgBomGuard_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Bom_Guard_InitVars = {
        ACTOR_BG_BOM_GUARD,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_BOWL,
        sizeof(BgBomGuard),
        (ActorFunc)BgBomGuard_Init,
        (ActorFunc)BgBomGuard_Destroy,
        (ActorFunc)BgBomGuard_Update,
        NULL,
        (ActorFunc)BgBomGuard_Reset,
    };

}
