#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_MURE_Z_OBJ_MURE_C
#include "actor_common.h"
/*
 * File: z_obj_mure.c
 * Overlay: ovl_Obj_Mure
 * Description: Spawns Fish, Bug, Butterfly
 */

#include "z_obj_mure.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_lib.h"

#define FLAGS 0

void ObjMure_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjMure_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ObjMure_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjMure_Update(Actor* thisx, GlobalContext* globalCtx);

void ObjMure_InitialAction(ObjMure* pthis, GlobalContext* globalCtx);
void ObjMure_CulledState(ObjMure* pthis, GlobalContext* globalCtx);
void ObjMure_ActiveState(ObjMure* pthis, GlobalContext* globalCtx);

s32 ObjMure_GetMaxChildSpawns(ObjMure* pthis);

ActorInit Obj_Mure_InitVars = {
    ACTOR_OBJ_MURE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjMure),
    (ActorFunc)ObjMure_Init,
    (ActorFunc)ObjMure_Destroy,
    (ActorFunc)ObjMure_Update,
    NULL,
    (ActorFunc)ObjMure_Reset,
};

static f32 sZClip[] = { 1600.0f, 1600.0f, 1000.0f, 1000.0f, 1000.0f };

static s32 sMaxChildSpawns[] = { 12, 9, 8, 0 };

static s16 sSpawnActorIds[] = { ACTOR_EN_KUSA, 0, ACTOR_EN_FISH, ACTOR_EN_INSECT, ACTOR_EN_BUTTE };

static s16 sSpawnParams[] = { 0, 2, -1, 0, -1 };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1200, ICHAIN_STOP),
};

s32 ObjMure_SetCullingImpl(Actor* thisx, GlobalContext* globalCtx) {
    ObjMure* pthis = (ObjMure*)thisx;
    s32 result;

    switch (pthis->type) {
        case OBJMURE_TYPE_FISH:
        case OBJMURE_TYPE_BUGS:
        case OBJMURE_TYPE_BUTTERFLY:
            Actor_ProcessInitChain(&pthis->actor, sInitChain);
            result = true;
            break;
        default:
            // "Error : Culling is not set.(%s %d)(arg_data 0x%04x)"
            osSyncPrintf("Error : カリングの設定がされていません。(%s %d)(arg_data 0x%04x)\n", "../z_obj_mure.c", 204,
                         pthis->actor.params);
            return false;
    }
    return result;
}

s32 ObjMure_SetCulling(Actor* thisx, GlobalContext* globalCtx) {
    if (!ObjMure_SetCullingImpl(thisx, globalCtx)) {
        return false;
    }
    return true;
}

void ObjMure_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjMure* pthis = (ObjMure*)thisx;

    pthis->chNum = (thisx->params >> 0xC) & 0x0F;
    pthis->ptn = (thisx->params >> 8) & 0x07;
    pthis->svNum = (thisx->params >> 5) & 0x03;
    pthis->type = thisx->params & 0x1F;

    if (pthis->ptn >= 4) {
        osSyncPrintf("Error 群れな敵 (%s %d)(arg_data 0x%04x)\n", "../z_obj_mure.c", 237, thisx->params);
        Actor_Kill(&pthis->actor);
        return;
    } else if (pthis->type >= 5) {
        osSyncPrintf("Error 群れな敵 (%s %d)(arg_data 0x%04x)\n", "../z_obj_mure.c", 245, thisx->params);
        Actor_Kill(&pthis->actor);
        return;
    } else if (!ObjMure_SetCulling(thisx, globalCtx)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    pthis->actionFunc = ObjMure_InitialAction;
    osSyncPrintf("群れな敵 (arg_data 0x%04x)(chNum(%d) ptn(%d) svNum(%d) type(%d))\n", thisx->params, pthis->chNum,
                 pthis->ptn, pthis->svNum, pthis->type);
    if (ObjMure_GetMaxChildSpawns(pthis) <= 0) {
        osSyncPrintf("Warning : 個体数が設定されていません(%s %d)(arg_data 0x%04x)\n", "../z_obj_mure.c", 268,
                     thisx->params);
    }
}

void ObjMure_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

s32 ObjMure_GetMaxChildSpawns(ObjMure* pthis) {
    if (pthis->chNum == 0) {
        return sMaxChildSpawns[pthis->ptn];
    }
    return pthis->chNum;
}

void ObjMure_GetSpawnPos(Vec3f* outPos, Vec3f* inPos, s32 ptn, s32 idx) {
    if (ptn >= 4) {
        osSyncPrintf("おかしなの (%s %d)\n", "../z_obj_mure.c", 307);
    }
    *outPos = *inPos;
}

void ObjMure_SpawnActors0(ObjMure* pthis, GlobalContext* globalCtx) {
    ActorContext* ac;
    s32 i;
    Vec3f pos;
    s32 pad;
    s32 maxChildren = ObjMure_GetMaxChildSpawns(pthis);

    for (i = 0; i < maxChildren; i++) {
        if (pthis->children[i] != NULL) {
            // "Error: I already have a child(%s %d)(arg_data 0x%04x)"
            osSyncPrintf("Error : 既に子供がいる(%s %d)(arg_data 0x%04x)\n", "../z_obj_mure.c", 333,
                         pthis->actor.params);
        }
        switch (pthis->childrenStates[i]) {
            case OBJMURE_CHILD_STATE_1:
                break;
            case OBJMURE_CHILD_STATE_2:
                ac = &globalCtx->actorCtx;
                ObjMure_GetSpawnPos(&pos, &pthis->actor.world.pos, pthis->ptn, i);
                pthis->children[i] =
                    Actor_Spawn(ac, globalCtx, sSpawnActorIds[pthis->type], pos.x, pos.y, pos.z, pthis->actor.world.rot.x,
                                pthis->actor.world.rot.y, pthis->actor.world.rot.z, sSpawnParams[pthis->type]);
                if (pthis->children[i] != NULL) {
                    pthis->children[i]->flags |= ACTOR_FLAG_11;
                    pthis->children[i]->room = pthis->actor.room;
                } else {
                    osSyncPrintf("warning 発生失敗 (%s %d)\n", "../z_obj_mure.c", 359);
                }
                break;
            default:
                ac = &globalCtx->actorCtx;
                ObjMure_GetSpawnPos(&pos, &pthis->actor.world.pos, pthis->ptn, i);
                pthis->children[i] =
                    Actor_Spawn(ac, globalCtx, sSpawnActorIds[pthis->type], pos.x, pos.y, pos.z, pthis->actor.world.rot.x,
                                pthis->actor.world.rot.y, pthis->actor.world.rot.z, sSpawnParams[pthis->type]);
                if (pthis->children[i] != NULL) {
                    pthis->children[i]->room = pthis->actor.room;
                } else {
                    osSyncPrintf("warning 発生失敗 (%s %d)\n", "../z_obj_mure.c", 382);
                }
                break;
        }
    }
}

void ObjMure_SpawnActors1(ObjMure* pthis, GlobalContext* globalCtx) {
    ActorContext* ac = (ActorContext*)globalCtx; // fake match
    Actor* actor = &pthis->actor;
    Vec3f spawnPos;
    s32 maxChildren = ObjMure_GetMaxChildSpawns(pthis);
    s32 i;

    for (i = 0; i < maxChildren; i++) {
        if (pthis->children[i] != NULL) {
            osSyncPrintf("Error : 既に子供がいる(%s %d)(arg_data 0x%04x)\n", "../z_obj_mure.c", 407, actor->params);
        }
        ac = &globalCtx->actorCtx;
        ObjMure_GetSpawnPos(&spawnPos, &actor->world.pos, pthis->ptn, i);
        pthis->children[i] = Actor_Spawn(ac, globalCtx, sSpawnActorIds[pthis->type], spawnPos.x, spawnPos.y, spawnPos.z,
                                        actor->world.rot.x, actor->world.rot.y, actor->world.rot.z,
                                        (pthis->type == 4 && i == 0) ? 1 : sSpawnParams[pthis->type]);
        if (pthis->children[i] != NULL) {
            pthis->childrenStates[i] = OBJMURE_CHILD_STATE_0;
            pthis->children[i]->room = actor->room;
        } else {
            pthis->childrenStates[i] = OBJMURE_CHILD_STATE_1;
            osSyncPrintf("warning 発生失敗 (%s %d)\n", "../z_obj_mure.c", 438);
        }
    }
}

void ObjMure_SpawnActors(ObjMure* pthis, GlobalContext* globalCtx) {
    switch (pthis->svNum) {
        case 0:
            ObjMure_SpawnActors0(pthis, globalCtx);
            break;
        case 1:
            ObjMure_SpawnActors1(pthis, globalCtx);
            break;
    }
}

void ObjMure_KillActorsImpl(ObjMure* pthis, GlobalContext* globalCtx) {
    s32 maxChildren = ObjMure_GetMaxChildSpawns(pthis);
    s32 i;

    for (i = 0; i < maxChildren; i++) {
        switch (pthis->childrenStates[i]) {
            case OBJMURE_CHILD_STATE_1:
                pthis->children[i] = NULL;
                break;
            case OBJMURE_CHILD_STATE_2:
                if (pthis->children[i] != NULL) {
                    Actor_Kill(pthis->children[i]);
                    pthis->children[i] = NULL;
                }
                break;
            default:
                if (pthis->children[i] != NULL) {
                    if (Actor_HasParent(pthis->children[i], globalCtx)) {
                        pthis->children[i] = NULL;
                    } else {
                        Actor_Kill(pthis->children[i]);
                        pthis->children[i] = NULL;
                    }
                }
                break;
        }
    }
}

void ObjMure_KillActors(ObjMure* pthis, GlobalContext* globalCtx) {
    ObjMure_KillActorsImpl(pthis, globalCtx);
}

void ObjMure_CheckChildren(ObjMure* pthis, GlobalContext* globalCtx) {
    s32 maxChildren = ObjMure_GetMaxChildSpawns(pthis);
    s32 i;

    for (i = 0; i < maxChildren; i++) {
        if (pthis->children[i] != NULL) {
            if (pthis->childrenStates[i] == OBJMURE_CHILD_STATE_0) {
                if (pthis->children[i]->update != NULL) {
                    if (pthis->children[i]->flags & ACTOR_FLAG_11) {
                        pthis->childrenStates[i] = OBJMURE_CHILD_STATE_2;
                    }
                } else {
                    pthis->childrenStates[i] = OBJMURE_CHILD_STATE_1;
                    pthis->children[i] = NULL;
                }
            } else if (pthis->childrenStates[i] == OBJMURE_CHILD_STATE_2 && pthis->children[i]->update == NULL) {
                pthis->childrenStates[i] = OBJMURE_CHILD_STATE_1;
                pthis->children[i] = NULL;
            }
        }
    }
}

void ObjMure_InitialAction(ObjMure* pthis, GlobalContext* globalCtx) {
    pthis->actionFunc = ObjMure_CulledState;
}

void ObjMure_CulledState(ObjMure* pthis, GlobalContext* globalCtx) {
    if (fabsf(pthis->actor.projectedPos.z) < sZClip[pthis->type]) {
        pthis->actionFunc = ObjMure_ActiveState;
        pthis->actor.flags |= ACTOR_FLAG_4;
        ObjMure_SpawnActors(pthis, globalCtx);
    }
}

void ObjMure_SetFollowTargets(ObjMure* pthis, f32 randMax) {
    s32 index;
    s32 maxChildren = ObjMure_GetMaxChildSpawns(pthis);
    s32 i;

    for (i = 0; i < maxChildren; i++) {
        if (pthis->children[i] != NULL) {
            pthis->children[i]->child = NULL;
            if (Rand_ZeroOne() <= randMax) {
                index = Rand_ZeroOne() * (maxChildren - 0.5f);
                if (i != index) {
                    pthis->children[i]->child = pthis->children[index];
                }
            }
        }
    }
}

/**
 * Selects a child that will follow after the player
 * `idx1` is the index + 1 of the child that will follow the player. If `idx1` is zero, no actor will follow the player
 */
void ObjMure_SetChildToFollowPlayer(ObjMure* pthis, s32 idx1) {
    s32 maxChildren = ObjMure_GetMaxChildSpawns(pthis);
    s32 i;
    s32 i2;
    s32 j;

    for (i = 0, i2 = 0; i < maxChildren; i++) {
        if (pthis->children[i] != NULL) {
            if (i2 < idx1) {
                i2++;
                pthis->children[i]->child = pthis->children[i];
                for (j = 0; j < maxChildren; j++) {
                    if (i != j && pthis->children[j]->child == pthis->children[i]) {
                        pthis->children[j]->child = NULL;
                    }
                }
            } else if (pthis->children[i]->child == pthis->children[i]) {
                pthis->children[i]->child = NULL;
            }
        }
    }
}

// Fish, Bugs
void ObjMure_GroupBehavior0(ObjMure* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1A4 <= 0) {
        if (pthis->unk_1A6) {
            pthis->unk_1A6 = false;
            ObjMure_SetFollowTargets(pthis, (Rand_ZeroOne() * 0.5f) + 0.1f);
            if (pthis->actor.xzDistToPlayer < 60.0f) {
                pthis->unk_1A4 = (s16)(Rand_ZeroOne() * 5.5f) + 4;
            } else {
                pthis->unk_1A4 = (s16)(Rand_ZeroOne() * 40.5f) + 4;
            }
        } else {
            pthis->unk_1A6 = true;
            if (pthis->actor.xzDistToPlayer < 60.0f) {
                pthis->unk_1A4 = (s16)(Rand_ZeroOne() * 10.5f) + 4;
                ObjMure_SetFollowTargets(pthis, (Rand_ZeroOne() * 0.2f) + 0.8f);
            } else {
                pthis->unk_1A4 = (s16)(Rand_ZeroOne() * 10.5f) + 4;
                ObjMure_SetFollowTargets(pthis, (Rand_ZeroOne() * 0.2f) + 0.6f);
            }
        }
    }
    if (pthis->actor.xzDistToPlayer < 120.0f) {
        pthis->unk_1A8++;
    } else {
        pthis->unk_1A8 = 0;
    }
    if (pthis->unk_1A8 >= 80) {
        ObjMure_SetChildToFollowPlayer(pthis, 1);
    } else {
        ObjMure_SetChildToFollowPlayer(pthis, 0);
    }
}

// Butterflies
void ObjMure_GroupBehavior1(ObjMure* pthis, GlobalContext* globalCtx) {
    s32 maxChildren;
    s32 i;

    if (pthis->unk_1A4 <= 0) {
        if (pthis->unk_1A6) {
            pthis->unk_1A6 = false;
            ObjMure_SetFollowTargets(pthis, Rand_ZeroOne() * 0.2f);
            if (pthis->actor.xzDistToPlayer < 60.0f) {
                pthis->unk_1A4 = (s16)(Rand_ZeroOne() * 5.5f) + 4;
            } else {
                pthis->unk_1A4 = (s16)(Rand_ZeroOne() * 40.5f) + 4;
            }
        } else {
            pthis->unk_1A6 = true;
            ObjMure_SetFollowTargets(pthis, Rand_ZeroOne() * 0.7f);
            pthis->unk_1A4 = (s16)(Rand_ZeroOne() * 10.5f) + 4;
        }
    }

    maxChildren = ObjMure_GetMaxChildSpawns(pthis);
    for (i = 0; i < maxChildren; i++) {
        if (pthis->children[i] != NULL) {
            if (pthis->children[i]->child != NULL && pthis->children[i]->child->update == NULL) {
                pthis->children[i]->child = NULL;
            }
        }
    }
}

static ObjMureActionFunc sTypeGroupBehaviorFunc[] = {
    NULL, NULL, ObjMure_GroupBehavior0, ObjMure_GroupBehavior0, ObjMure_GroupBehavior1,
};

void ObjMure_ActiveState(ObjMure* pthis, GlobalContext* globalCtx) {
    ObjMure_CheckChildren(pthis, globalCtx);
    if (sZClip[pthis->type] + 40.0f <= fabsf(pthis->actor.projectedPos.z)) {
        pthis->actionFunc = ObjMure_CulledState;
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        ObjMure_KillActors(pthis, globalCtx);
    } else if (sTypeGroupBehaviorFunc[pthis->type] != NULL) {
        sTypeGroupBehaviorFunc[pthis->type](pthis, globalCtx);
    }
}

void ObjMure_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjMure* pthis = (ObjMure*)thisx;

    if (pthis->unk_1A4 > 0) {
        pthis->unk_1A4--;
    }
    pthis->actionFunc(pthis, globalCtx);
}

void ObjMure_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Obj_Mure_InitVars = {
        ACTOR_OBJ_MURE,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(ObjMure),
        (ActorFunc)ObjMure_Init,
        (ActorFunc)ObjMure_Destroy,
        (ActorFunc)ObjMure_Update,
        NULL,
        (ActorFunc)ObjMure_Reset,
    };

}
