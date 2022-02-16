#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ANUBICE_TAG_Z_EN_ANUBICE_TAG_C
#include "actor_common.h"
/*
 * File: z_en_anubice_tag.c
 * Overlay: ovl_En_Anubice_Tag
 * Description: Spawns and manages the Anubis enemy
 */

#include "z_en_anubice_tag.h"
#include "vt.h"
#include "def/z_actor.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_4

void EnAnubiceTag_Init(Actor* thisx, GlobalContext* globalCtx);
void EnAnubiceTag_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnAnubiceTag_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnAnubiceTag_Update(Actor* thisx, GlobalContext* globalCtx);
void EnAnubiceTag_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnAnubiceTag_SpawnAnubis(EnAnubiceTag* pthis, GlobalContext* globalCtx);
void EnAnubiceTag_ManageAnubis(EnAnubiceTag* pthis, GlobalContext* globalCtx);

ActorInit En_Anubice_Tag_InitVars = {
    ACTOR_EN_ANUBICE_TAG,
    ACTORCAT_SWITCH,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnAnubiceTag),
    (ActorFunc)EnAnubiceTag_Init,
    (ActorFunc)EnAnubiceTag_Destroy,
    (ActorFunc)EnAnubiceTag_Update,
    (ActorFunc)EnAnubiceTag_Draw,
    (ActorFunc)EnAnubiceTag_Reset,
};

void EnAnubiceTag_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnAnubiceTag* pthis = (EnAnubiceTag*)thisx;

    osSyncPrintf("\n\n");
    // "Anubis control tag generated"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ アヌビス制御タグ発生 ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params);

    if (pthis->actor.params < -1) {
        pthis->actor.params = 0;
    }
    if (pthis->actor.params != 0) {
        pthis->triggerRange = pthis->actor.params * 40.0f;
    }
    pthis->actionFunc = EnAnubiceTag_SpawnAnubis;
}

void EnAnubiceTag_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnAnubiceTag_SpawnAnubis(EnAnubiceTag* pthis, GlobalContext* globalCtx) {
    pthis->anubis = (EnAnubice*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ANUBICE,
                                                  pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                                                  pthis->actor.world.pos.z, 0, pthis->actor.yawTowardsPlayer, 0, 0);

    if (pthis->anubis != NULL) {
        pthis->actionFunc = EnAnubiceTag_ManageAnubis;
    }
}

void EnAnubiceTag_ManageAnubis(EnAnubiceTag* pthis, GlobalContext* globalCtx) {
    EnAnubice* anubis;
    Vec3f offset;

    if (pthis->anubis != NULL) {
        anubis = pthis->anubis;
        if (anubis->actor.update == NULL) {
            return;
        }
    } else {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (anubis->deathTimer != 0) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->actor.xzDistToPlayer < (200.0f + pthis->triggerRange)) {
        if (!anubis->isLinkOutOfRange) {
            if (!anubis->isKnockedback) {
                anubis->isMirroringLink = true;
                offset.x = -Math_SinS(pthis->actor.yawTowardsPlayer) * pthis->actor.xzDistToPlayer;
                offset.z = -Math_CosS(pthis->actor.yawTowardsPlayer) * pthis->actor.xzDistToPlayer;
                Math_ApproachF(&anubis->actor.world.pos.x, (pthis->actor.world.pos.x + offset.x), 0.3f, 10.0f);
                Math_ApproachF(&anubis->actor.world.pos.z, (pthis->actor.world.pos.z + offset.z), 0.3f, 10.0f);
                return;
            }
        }
    } else {
        if (anubis->isMirroringLink) {
            anubis->isLinkOutOfRange = true;
        }
    }
}

void EnAnubiceTag_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnAnubiceTag* pthis = (EnAnubiceTag*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void EnAnubiceTag_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnAnubiceTag* pthis = (EnAnubiceTag*)thisx;
}

void EnAnubiceTag_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Anubice_Tag_InitVars = {
        ACTOR_EN_ANUBICE_TAG,
        ACTORCAT_SWITCH,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnAnubiceTag),
        (ActorFunc)EnAnubiceTag_Init,
        (ActorFunc)EnAnubiceTag_Destroy,
        (ActorFunc)EnAnubiceTag_Update,
        (ActorFunc)EnAnubiceTag_Draw,
        (ActorFunc)EnAnubiceTag_Reset,
    };

}
