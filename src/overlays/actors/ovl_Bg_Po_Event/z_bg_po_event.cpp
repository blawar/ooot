#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_PO_EVENT_Z_BG_PO_EVENT_C
#include "actor_common.h"
/*
 * File: z_bg_po_event.c
 * Overlay: ovl_Bg_Po_Event
 * Description: Poe sisters' paintings and puzzle blocks
 */

#include "z_bg_po_event.h"
#include "objects/object_po_sisters/object_po_sisters.h"
#include "def/code_80043480.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_parameter.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgPoEvent_Init(Actor* thisx, GlobalContext* globalCtx);
void BgPoEvent_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgPoEvent_Update(Actor* thisx, GlobalContext* globalCtx);
void BgPoEvent_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgPoEvent_BlockWait(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_BlockShake(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_BlockFall(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_BlockIdle(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_BlockPush(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_BlockReset(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_BlockSolved(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_AmyWait(BgPoEvent* pthis, GlobalContext* globalCtx); // Amy is the green Poe
void BgPoEvent_AmyPuzzle(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_PaintingEmpty(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_PaintingAppear(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_PaintingPresent(BgPoEvent* pthis, GlobalContext* globalCtx);
void BgPoEvent_PaintingBurn(BgPoEvent* pthis, GlobalContext* globalCtx);

ActorInit Bg_Po_Event_InitVars = {
    ACTOR_BG_PO_EVENT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_PO_SISTERS,
    sizeof(BgPoEvent),
    (ActorFunc)BgPoEvent_Init,
    (ActorFunc)BgPoEvent_Destroy,
    (ActorFunc)BgPoEvent_Update,
    (ActorFunc)BgPoEvent_Draw,
};

static ColliderTrisElementInit sTrisElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK4,
            { 0x00000000, 0x00, 0x00 },
            { 0x0001F820, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 25.0f, 33.0f, 0.0f }, { -25.0f, 33.0f, 0.0f }, { -25.0f, -33.0f, 0.0f } } },
    },
    {
        {
            ELEMTYPE_UNK4,
            { 0x00000000, 0x00, 0x00 },
            { 0x0001F820, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 25.0f, 33.0f, 0.0f }, { -25.0f, -33.0f, 0.0f }, { 25.0f, -33.0f, 0.0f } } },
    },
};

static ColliderTrisInit sTrisInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_TRIS,
    },
    2,
    sTrisElementsInit,
};

static u8 sBlocksAtRest = 0;

static Vec3f sZeroVec = { 0.0f, 0.0f, 0.0f };

static u8 sPuzzleState;

void BgPoEvent_InitPaintings(BgPoEvent* pthis, GlobalContext* globalCtx) {
    static s16 paintingPosX[] = { -1302, -866, 1421, 985 };
    static s16 paintingPosY[] = { 1107, 1091 };
    static s16 paintingPosZ[] = { -3384, -3252 };
    ColliderTrisElementInit* item;
    Vec3f* vtxVec;
    s32 i1;
    s32 i2;
    Vec3f sp9C[3];
    f32 coss;
    f32 sins;
    f32 scaleY;
    s32 phi_t2;
    Actor* newPainting;

    sins = Math_SinS(pthis->dyna.actor.shape.rot.y);
    coss = Math_CosS(pthis->dyna.actor.shape.rot.y);
    if (pthis->type == 4) {
        sins *= 2.4f;
        scaleY = 1.818f;
        coss *= 2.4f;
    } else {
        scaleY = 1.0f;
    }
    for (i1 = 0; i1 < sTrisInit.count; i1++) {
        item = &sTrisInit.elements[i1];
        if (1) {} // This section looks like a macro of some sort.
        for (i2 = 0; i2 < 3; i2++) {
            vtxVec = &item->dim.vtx[i2];
            sp9C[i2].x = (vtxVec->x * coss) + (pthis->dyna.actor.home.pos.x + (sins * vtxVec->z));
            sp9C[i2].y = (vtxVec->y * scaleY) + pthis->dyna.actor.home.pos.y;
            sp9C[i2].z = pthis->dyna.actor.home.pos.z + (coss * vtxVec->z) - (vtxVec->x * sins);
        }
        Collider_SetTrisVertices(&pthis->collider, i1, &sp9C[0], &sp9C[1], &sp9C[2]);
    }
    if ((pthis->type != 4) && (pthis->index != 2)) {
        phi_t2 = (pthis->type == 2) ? pthis->index : pthis->index + 2;
        newPainting = Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_BG_PO_EVENT,
                                         paintingPosX[phi_t2], paintingPosY[pthis->index], paintingPosZ[pthis->index], 0,
                                         pthis->dyna.actor.shape.rot.y + 0x8000, 0,
                                         ((pthis->index + 1) << 0xC) + (pthis->type << 8) + pthis->dyna.actor.params);
        if (newPainting == NULL) {
            Actor_Kill(&pthis->dyna.actor);
            return;
        }
        if (pthis->index == 0) {
            if (pthis->dyna.actor.child->child == NULL) {
                Actor_Kill(&pthis->dyna.actor);
                return;
            }
            pthis->dyna.actor.parent = pthis->dyna.actor.child->child;
            pthis->dyna.actor.child->child->child = &pthis->dyna.actor;
        }
    }
    pthis->timer = 0;
    if (pthis->type == 4) {
        sPuzzleState = 0;
        pthis->actionFunc = BgPoEvent_AmyWait;
    } else {
        sPuzzleState = (s32)(Rand_ZeroOne() * 3.0f) % 3;
        pthis->actionFunc = BgPoEvent_PaintingEmpty;
    }
}

void BgPoEvent_InitBlocks(BgPoEvent* pthis, GlobalContext* globalCtx) {
    static s16 blockPosX[] = { 2149, 1969, 1909 };
    static s16 blockPosZ[] = { -1410, -1350, -1530 };
    Actor* newBlock;
    CollisionHeader* colHeader = NULL;
    s32 bgId;

    pthis->dyna.actor.flags |= ACTOR_FLAG_4 | ACTOR_FLAG_5;
    CollisionHeader_GetVirtual(&gPoSistersAmyBlockCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if ((pthis->type == 0) && (pthis->index != 3)) {
        newBlock = Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_BG_PO_EVENT,
                                      blockPosX[pthis->index], pthis->dyna.actor.world.pos.y, blockPosZ[pthis->index], 0,
                                      pthis->dyna.actor.shape.rot.y, pthis->dyna.actor.shape.rot.z - 0x4000,
                                      ((pthis->index + 1) << 0xC) + (pthis->type << 8) + pthis->dyna.actor.params);
        if (newBlock == NULL) {
            Actor_Kill(&pthis->dyna.actor);
            return;
        }
        if (pthis->index == 0) {
            if (pthis->dyna.actor.child->child == NULL) {
                Actor_Kill(&pthis->dyna.actor);
                return;
            }
            if (pthis->dyna.actor.child->child->child == NULL) {
                Actor_Kill(&pthis->dyna.actor);
                Actor_Kill(pthis->dyna.actor.child);
                return;
            }
            pthis->dyna.actor.parent = pthis->dyna.actor.child->child->child;
            pthis->dyna.actor.child->child->child->child = &pthis->dyna.actor;
        }
    }
    pthis->dyna.actor.world.pos.y = 833.0f;
    pthis->dyna.actor.floorHeight = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->dyna.actor.floorPoly, &bgId,
                                                               &pthis->dyna.actor, &pthis->dyna.actor.world.pos);
    pthis->actionFunc = BgPoEvent_BlockWait;
}

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

void BgPoEvent_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgPoEvent* pthis = (BgPoEvent*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);
    pthis->type = (thisx->params >> 8) & 0xF;
    pthis->index = (thisx->params >> 0xC) & 0xF;
    thisx->params &= 0x3F;

    if (pthis->type >= 2) {
        Collider_InitTris(globalCtx, &pthis->collider);
        Collider_SetTris(globalCtx, &pthis->collider, thisx, &sTrisInit, pthis->colliderItems);
        if (Flags_GetSwitch(globalCtx, thisx->params)) {
            Actor_Kill(thisx);
        } else {
            BgPoEvent_InitPaintings(pthis, globalCtx);
        }
    } else {
        DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
        if (Flags_GetSwitch(globalCtx, thisx->params)) {
            Actor_Kill(thisx);
        } else {
            BgPoEvent_InitBlocks(pthis, globalCtx);
        }
    }
}

void BgPoEvent_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgPoEvent* pthis = (BgPoEvent*)thisx;

    if (pthis->type >= 2) {
        Collider_DestroyTris(globalCtx, &pthis->collider);
    } else {
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        if ((pthis->type == 1) && (gSaveContext.timer1Value > 0)) {
            gSaveContext.timer1State = 0xA;
        }
    }
}

void BgPoEvent_BlockWait(BgPoEvent* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.world.pos.y = 833.0f;
    if (sPuzzleState == 0x3F) {
        if (pthis->type == 1) {
            OnePointCutscene_Init(globalCtx, 3150, 65, NULL, MAIN_CAM);
        }
        pthis->timer = 45;
        pthis->actionFunc = BgPoEvent_BlockShake;
    } else if (pthis->dyna.actor.xzDistToPlayer > 50.0f) {
        if (pthis->type != 1) {
            sPuzzleState |= (1 << pthis->index);
        } else {
            sPuzzleState |= 0x10;
        }
    } else if (pthis->type != 1) {
        sPuzzleState &= ~(1 << pthis->index);
    } else {
        sPuzzleState &= ~0x10;
    }
}

void BgPoEvent_BlockShake(BgPoEvent* pthis, GlobalContext* globalCtx) {
    DECR(pthis->timer);
    if (pthis->timer < 15) {
        pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x + 2.0f * ((pthis->timer % 3) - 1);
        if (!(pthis->timer % 4)) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_SHAKE);
        }
    }
    if (pthis->timer == 0) {
        pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x;
        sPuzzleState = 0;
        pthis->timer = 60;
        pthis->actionFunc = BgPoEvent_BlockFall;
    }
}

void BgPoEvent_CheckBlock(BgPoEvent* pthis) {
    s32 phi_v1;
    s32 phi_a1;
    s32 phi_t0;
    s32 phi_a3;

    if ((pthis->index == 3) || (pthis->index == 1)) {
        phi_v1 = pthis->dyna.actor.world.pos.z;
        phi_a1 = pthis->dyna.actor.child->world.pos.z;
        if (pthis->index == 3) {
            phi_a3 = pthis->dyna.actor.world.pos.x;
            phi_t0 = pthis->dyna.actor.child->world.pos.x;
        } else { // pthis->index == 1
            phi_a3 = pthis->dyna.actor.child->world.pos.x;
            phi_t0 = pthis->dyna.actor.world.pos.x;
        }
    } else {
        phi_v1 = pthis->dyna.actor.world.pos.x;
        phi_a1 = pthis->dyna.actor.child->world.pos.x;
        if (pthis->index == 0) {
            phi_a3 = pthis->dyna.actor.world.pos.z;
            phi_t0 = pthis->dyna.actor.child->world.pos.z;
        } else { // pthis->index == 2
            phi_a3 = pthis->dyna.actor.child->world.pos.z;
            phi_t0 = pthis->dyna.actor.world.pos.z;
        }
    }
    if ((phi_v1 == phi_a1) && ((phi_t0 - phi_a3) == 60)) {
        sPuzzleState |= (1 << pthis->index);
    } else {
        sPuzzleState &= ~(1 << pthis->index);
    }
}

void BgPoEvent_BlockFall(BgPoEvent* pthis, GlobalContext* globalCtx) {
    static s32 firstFall = 0;

    pthis->dyna.actor.velocity.y++;
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, 433.0f, pthis->dyna.actor.velocity.y)) {
        pthis->dyna.actor.flags &= ~ACTOR_FLAG_5;
        pthis->dyna.actor.velocity.y = 0.0f;
        sBlocksAtRest++;
        if (pthis->type != 1) {
            BgPoEvent_CheckBlock(pthis);
        } else {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONE_BOUND);
            func_80033E88(&pthis->dyna.actor, globalCtx, 5, 5);
            func_80088B34(pthis->timer);
            if (firstFall == 0) {
                firstFall = 1;
            } else {
                func_8002DF54(globalCtx, &GET_PLAYER(globalCtx)->actor, 7);
            }
        }
        pthis->direction = 0;
        pthis->actionFunc = BgPoEvent_BlockIdle;
    }
}

void BgPoEvent_BlockIdle(BgPoEvent* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Actor* amy;

    if (sPuzzleState == 0xF) {
        pthis->actionFunc = BgPoEvent_BlockSolved;
        if ((pthis->type == 0) && (pthis->index == 0)) {
            amy =
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_PO_SISTERS, pthis->dyna.actor.world.pos.x + 30.0f,
                            pthis->dyna.actor.world.pos.y - 30.0f, pthis->dyna.actor.world.pos.z + 30.0f, 0,
                            pthis->dyna.actor.shape.rot.y, 0, pthis->dyna.actor.params + 0x300);
            if (amy != NULL) {
                OnePointCutscene_Init(globalCtx, 3170, 30, amy, MAIN_CAM);
            }
            func_80078884(NA_SE_SY_CORRECT_CHIME);
            gSaveContext.timer1State = 0xA;
        }
    } else {
        if ((gSaveContext.timer1Value == 0) && (sBlocksAtRest == 5)) {
            player->stateFlags2 &= ~0x10;
            sPuzzleState = 0x10;
            sBlocksAtRest = 0;
        }
        if ((sPuzzleState == 0x40) || ((sPuzzleState == 0x10) && !Player_InCsMode(globalCtx))) {
            pthis->dyna.actor.world.rot.z = pthis->dyna.actor.shape.rot.z;
            pthis->actionFunc = BgPoEvent_BlockReset;
            if (sPuzzleState == 0x10) {
                sPuzzleState = 0x40;
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_RISING);
                func_8002DF54(globalCtx, &player->actor, 8);
            }
        } else if (pthis->dyna.unk_150 != 0.0f) {
            if (pthis->direction == 0) {
                if (func_800435D8(globalCtx, &pthis->dyna, 0x1E, 0x32, -0x14) != 0) {
                    sBlocksAtRest--;
                    pthis->direction = (pthis->dyna.unk_150 >= 0.0f) ? 1.0f : -1.0f;
                    pthis->actionFunc = BgPoEvent_BlockPush;
                } else {
                    player->stateFlags2 &= ~0x10;
                    pthis->dyna.unk_150 = 0.0f;
                }
            } else {
                player->stateFlags2 &= ~0x10;
                pthis->dyna.unk_150 = 0.0f;
                DECR(pthis->direction);
            }
        } else {
            pthis->direction = 0;
        }
    }
}

void BgPoEvent_BlockPush(BgPoEvent* pthis, GlobalContext* globalCtx) {
    static f32 blockPushDist = 0.0f;
    f32 displacement;
    s32 blockStop;
    Player* player = GET_PLAYER(globalCtx);

    pthis->dyna.actor.speedXZ += 0.1f;
    pthis->dyna.actor.speedXZ = CLAMP_MAX(pthis->dyna.actor.speedXZ, 2.0f);
    blockStop = Math_StepToF(&blockPushDist, 20.0f, pthis->dyna.actor.speedXZ);
    displacement = pthis->direction * blockPushDist;
    pthis->dyna.actor.world.pos.x = (Math_SinS(pthis->dyna.unk_158) * displacement) + pthis->dyna.actor.home.pos.x;
    pthis->dyna.actor.world.pos.z = (Math_CosS(pthis->dyna.unk_158) * displacement) + pthis->dyna.actor.home.pos.z;
    if (blockStop) {
        player->stateFlags2 &= ~0x10;
        if ((pthis->dyna.unk_150 > 0.0f) && (func_800435D8(globalCtx, &pthis->dyna, 0x1E, 0x32, -0x14) == 0)) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        }
        pthis->dyna.unk_150 = 0.0f;
        pthis->dyna.actor.home.pos.x = pthis->dyna.actor.world.pos.x;
        pthis->dyna.actor.home.pos.z = pthis->dyna.actor.world.pos.z;
        blockPushDist = 0.0f;
        pthis->dyna.actor.speedXZ = 0.0f;
        pthis->direction = 5;
        sBlocksAtRest++;
        pthis->actionFunc = BgPoEvent_BlockIdle;
        if (pthis->type == 1) {
            return;
        }
        BgPoEvent_CheckBlock(pthis);
        BgPoEvent_CheckBlock((BgPoEvent*)pthis->dyna.actor.parent);
    }
    func_8002F974(&pthis->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
}

void BgPoEvent_BlockReset(BgPoEvent* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->dyna.unk_150 != 0.0f) {
        player->stateFlags2 &= ~0x10;
        pthis->dyna.unk_150 = 0.0f;
    }
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, 493.0f, 1.0f) &&
        Math_ScaledStepToS(&pthis->dyna.actor.shape.rot.z, pthis->dyna.actor.world.rot.z - 0x4000, 0x400)) {

        pthis->index = (pthis->index + 1) % 4;
        pthis->actionFunc = BgPoEvent_BlockFall;
        sPuzzleState = 0;
        if (pthis->type == 1) {
            pthis->timer += 10;
            pthis->timer = CLAMP_MAX(pthis->timer, 120);
        }
    }
}

void BgPoEvent_BlockSolved(BgPoEvent* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->dyna.unk_150 != 0.0f) {
        player->stateFlags2 &= ~0x10;
    }
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, 369.0f, 2.0f)) {
        sPuzzleState = 0x20;
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgPoEvent_AmyWait(BgPoEvent* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        sPuzzleState |= 0x20;
        pthis->timer = 5;
        Actor_SetColorFilter(&pthis->dyna.actor, 0x4000, 0xFF, 0, 5);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_PO_LAUGH2);
        pthis->actionFunc = BgPoEvent_AmyPuzzle;
    }
}

void BgPoEvent_AmyPuzzle(BgPoEvent* pthis, GlobalContext* globalCtx) {
    Vec3f pos;

    if (sPuzzleState == 0xF) {
        pos.x = pthis->dyna.actor.world.pos.x - 5.0f;
        pos.y = Rand_CenteredFloat(120.0f) + pthis->dyna.actor.world.pos.y;
        pos.z = Rand_CenteredFloat(120.0f) + pthis->dyna.actor.world.pos.z;
        EffectSsDeadDb_Spawn(globalCtx, &pos, &sZeroVec, &sZeroVec, 170, 0, 200, 255, 100, 170, 0, 255, 0, 1, 9, true);
    } else if (sPuzzleState == 0x20) {
        Actor_Kill(&pthis->dyna.actor);
    } else {
        DECR(pthis->timer);
    }
}

s32 BgPoEvent_NextPainting(BgPoEvent* pthis) {
    if ((pthis->dyna.actor.parent != NULL) && (pthis->dyna.actor.child != NULL)) {
        if (Rand_ZeroOne() < 0.5f) {
            sPuzzleState = ((BgPoEvent*)pthis->dyna.actor.parent)->index;
        } else {
            sPuzzleState = ((BgPoEvent*)pthis->dyna.actor.child)->index;
        }
    } else if (pthis->dyna.actor.parent != NULL) {
        sPuzzleState = ((BgPoEvent*)pthis->dyna.actor.parent)->index;
    } else if (pthis->dyna.actor.child != NULL) {
        sPuzzleState = ((BgPoEvent*)pthis->dyna.actor.child)->index;
    } else {
        return false;
    }
    return true;
}

void BgPoEvent_PaintingEmpty(BgPoEvent* pthis, GlobalContext* globalCtx) {
    if (sPuzzleState == pthis->index) {
        pthis->timer = 255;
        pthis->actionFunc = BgPoEvent_PaintingAppear;
    }
}

void BgPoEvent_PaintingAppear(BgPoEvent* pthis, GlobalContext* globalCtx) {
    pthis->timer -= 20;
    if (pthis->timer <= 0) {
        pthis->timer = 1000;
        pthis->actionFunc = BgPoEvent_PaintingPresent;
    }
}

void BgPoEvent_PaintingVanish(BgPoEvent* pthis, GlobalContext* globalCtx) {
    pthis->timer += 20;
    if (pthis->timer >= 255) {
        BgPoEvent_NextPainting(pthis);
        pthis->actionFunc = BgPoEvent_PaintingEmpty;
    }
}

void BgPoEvent_PaintingPresent(BgPoEvent* pthis, GlobalContext* globalCtx) {
    Actor* thisx = &pthis->dyna.actor;
    Player* player = GET_PLAYER(globalCtx);

    DECR(pthis->timer);

    if (((pthis->timer == 0) || ((thisx->xzDistToPlayer < 150.0f) && (thisx->yDistToPlayer < 50.0f)) ||
         (func_8002DD78(player) && (thisx->xzDistToPlayer < 320.0f) &&
          ((pthis->index != 2) ? (thisx->yDistToPlayer < 100.0f) : (thisx->yDistToPlayer < 0.0f)) &&
          Player_IsFacingActor(thisx, 0x2000, globalCtx))) &&
        ((thisx->parent != NULL) || (thisx->child != NULL))) {
        /*The third condition in the || is checking if
            1) Link is holding a ranged weapon
            2) Link is too close in the xz plane
            3) Link is too close in the y direction. The painting
               under the balcony allows him to be closer.
            4) Link is within 45 degrees of facing the painting. */
        pthis->timer = 0;
        Audio_PlayActorSound2(thisx, NA_SE_EN_PO_LAUGH);
        pthis->actionFunc = BgPoEvent_PaintingVanish;
    } else if (pthis->collider.base.acFlags & AC_HIT) {
        if (!BgPoEvent_NextPainting(pthis)) {
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_PO_SISTERS, thisx->world.pos.x,
                        thisx->world.pos.y - 40.0f, thisx->world.pos.z, 0, thisx->shape.rot.y, 0,
                        thisx->params + ((pthis->type - 1) << 8));
            OnePointCutscene_Init(globalCtx, 3160, 80, thisx, MAIN_CAM);
            func_80078884(NA_SE_SY_CORRECT_CHIME);

        } else {
            Audio_PlayActorSound2(thisx, NA_SE_EN_PO_LAUGH2);
            OnePointCutscene_Init(globalCtx, 3160, 35, thisx, MAIN_CAM);
        }
        if (thisx->parent != NULL) {
            thisx->parent->child = NULL;
            thisx->parent = NULL;
        }
        if (thisx->child != NULL) {
            thisx->child->parent = NULL;
            thisx->child = NULL;
        }
        pthis->timer = 20;
        pthis->actionFunc = BgPoEvent_PaintingBurn;
    }
}

void BgPoEvent_PaintingBurn(BgPoEvent* pthis, GlobalContext* globalCtx) {
    Vec3f sp54;

    pthis->timer--;
    sp54.x = (Math_SinS(pthis->dyna.actor.shape.rot.y) * 5.0f) + pthis->dyna.actor.world.pos.x;
    sp54.y = Rand_CenteredFloat(66.0f) + pthis->dyna.actor.world.pos.y;
    sp54.z = Rand_CenteredFloat(50.0f) + pthis->dyna.actor.world.pos.z;
    if (pthis->timer >= 0) {
        if (pthis->type == 2) {
            EffectSsDeadDb_Spawn(globalCtx, &sp54, &sZeroVec, &sZeroVec, 100, 0, 255, 255, 150, 170, 255, 0, 0, 1, 9,
                                 true);
        } else {
            EffectSsDeadDb_Spawn(globalCtx, &sp54, &sZeroVec, &sZeroVec, 100, 0, 200, 255, 255, 170, 50, 100, 255, 1, 9,
                                 true);
        }
    }
    if (pthis->timer == 0) {
        pthis->dyna.actor.draw = NULL;
    }
    if (pthis->timer < -60) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgPoEvent_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgPoEvent* pthis = (BgPoEvent*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    if ((pthis->actionFunc == BgPoEvent_AmyWait) || (pthis->actionFunc == BgPoEvent_PaintingPresent)) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void BgPoEvent_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Gfx* displayLists[] = {
        gPoSistersAmyBlockDL,     gPoSistersAmyBethBlockDL, gPoSistersJoellePaintingDL,
        gPoSistersBethPaintingDL, gPoSistersAmyPaintingDL,
    };
    s32 pad;
    BgPoEvent* pthis = (BgPoEvent*)thisx;
    u8 alpha;
    Vec3f sp58;
    Vec3f sp4C;
    f32 sp48;
    s32 pad2;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_po_event.c", 1481);
    func_80093D18(globalCtx->state.gfxCtx);
    if ((pthis->type == 3) || (pthis->type == 2)) {
        if (pthis->actionFunc == BgPoEvent_PaintingEmpty) {
            alpha = 255;
        } else if (pthis->actionFunc == BgPoEvent_PaintingPresent) {
            alpha = 0;
        } else {
            alpha = pthis->timer;
        }
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, alpha);
    }
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_po_event.c", 1501),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, displayLists[pthis->type]);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_po_event.c", 1508);

    if ((pthis->type == 0) || (pthis->type == 1)) {
        sp48 = (833.0f - pthis->dyna.actor.world.pos.y) * 0.0025f;
        if (!(sp48 > 1.0f)) {
            sp58.x = pthis->dyna.actor.world.pos.x;
            sp58.y = pthis->dyna.actor.world.pos.y - 30.0f;
            sp58.z = pthis->dyna.actor.world.pos.z;
            sp4C.y = 1.0f;
            sp4C.x = sp4C.z = (sp48 * 0.3f) + 0.4f;
            func_80033C30(&sp58, &sp4C, (u8)(155.0f + sp48 * 100.0f), globalCtx);
        }
    }
}
