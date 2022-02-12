#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_AROW_TRAP_Z_EN_AROW_TRAP_C
#include "actor_common.h"
/*
 * File: z_en_arow_trap.c
 * Overlay: ovl_En_Arow_Trap
 * Description: An unused trap that reflects arrows.
 */

#include "z_en_arow_trap.h"
#include "overlays/actors/ovl_En_Arrow/z_en_arrow.h"
#include "def/z_actor.h"
#define FLAGS ACTOR_FLAG_4

void EnArowTrap_Init(Actor* thisx, GlobalContext* globalCtx);
void EnArowTrap_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnArowTrap_Update(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Arow_Trap_InitVars = {
    ACTOR_EN_AROW_TRAP,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnArowTrap),
    (ActorFunc)EnArowTrap_Init,
    (ActorFunc)EnArowTrap_Destroy,
    (ActorFunc)EnArowTrap_Update,
    NULL,
};

void EnArowTrap_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnArowTrap* pthis = (EnArowTrap*)thisx;

    Actor_SetScale(&pthis->actor, 0.01);
    pthis->unk_14C = 0;
    pthis->attackTimer = 80;
    pthis->actor.focus.pos = pthis->actor.world.pos;
}

void EnArowTrap_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnArowTrap_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnArowTrap* pthis = (EnArowTrap*)thisx;

    if (pthis->actor.xzDistToPlayer <= 400) {
        pthis->attackTimer--;

        if (pthis->attackTimer == 0) {
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ARROW, pthis->actor.world.pos.x,
                        pthis->actor.world.pos.y, pthis->actor.world.pos.z, pthis->actor.shape.rot.x,
                        pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, ARROW_NORMAL_SILENT);
            pthis->attackTimer = 80;
        }
    }
}
