#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_VASE_Z_EN_VASE_C
#include "actor_common.h"
/*
 * File: z_en_vase.c
 * Overlay: ovl_En_Vase
 * Description: An unused, orange pot based on ALTTP. Lacks collision.
 */

#include "z_en_vase.h"
#include "objects/object_vase/object_vase.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"

#define FLAGS ACTOR_FLAG_4

void EnVase_Init(Actor* thisx, GlobalContext* globalCtx);
void EnVase_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnVase_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnVase_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Vase_InitVars = {
    ACTOR_EN_VASE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_VASE,
    sizeof(EnVase),
    (ActorFunc)EnVase_Init,
    (ActorFunc)EnVase_Destroy,
    (ActorFunc)Actor_Noop,
    (ActorFunc)EnVase_Draw,
    (ActorFunc)EnVase_Reset,
};

void EnVase_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnVase* pthis = (EnVase*)thisx;

    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 6.0f);
}

void EnVase_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnVase_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gUnusedVaseDL);
}

void EnVase_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Vase_InitVars = {
        ACTOR_EN_VASE,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_VASE,
        sizeof(EnVase),
        (ActorFunc)EnVase_Init,
        (ActorFunc)EnVase_Destroy,
        (ActorFunc)Actor_Noop,
        (ActorFunc)EnVase_Draw,
        (ActorFunc)EnVase_Reset,
    };

}
