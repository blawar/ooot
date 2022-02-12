#define INTERNAL_SRC_CODE_Z_EN_A_KEEP_C
#include "global.h"
#include "vt.h"
#include "z64global.h"
#include "sfx.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/graph.h" // FORCE

#define FLAGS ACTOR_FLAG_4

void EnAObj_Init(Actor* pthisx, GlobalContext* globalCtx);
void EnAObj_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void EnAObj_Update(Actor* pthisx, GlobalContext* globalCtx);
void EnAObj_Draw(Actor* pthisx, GlobalContext* globalCtx);

void EnAObj_WaitFinishedTalking(EnAObj* pthis, GlobalContext* globalCtx);
void EnAObj_WaitTalk(EnAObj* pthis, GlobalContext* globalCtx);
void EnAObj_BlockRot(EnAObj* pthis, GlobalContext* globalCtx);
void EnAObj_BoulderFragment(EnAObj* pthis, GlobalContext* globalCtx);
void EnAObj_Block(EnAObj* pthis, GlobalContext* globalCtx);

void EnAObj_SetupWaitTalk(EnAObj* pthis, s16 type);
void EnAObj_SetupBlockRot(EnAObj* pthis, s16 type);
void EnAObj_SetupBoulderFragment(EnAObj* pthis, s16 type);
void EnAObj_SetupBlock(EnAObj* pthis, s16 type);

ActorInit En_A_Obj_InitVars = {
    ACTOR_EN_A_OBJ,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnAObj),
    (ActorFunc)EnAObj_Init,
    (ActorFunc)EnAObj_Destroy,
    (ActorFunc)EnAObj_Update,
    (ActorFunc)EnAObj_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_ALL,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 25, 60, 0, { 0, 0, 0 } },
};

static CollisionHeader D_06000730; // gHookshotTargetCol ?

static CollisionHeader* sColHeaders[] = {
    &gLargerCubeCol,       // A_OBJ_GRASS_CLUMP, A_OBJ_TREE_STUMP
    &gLargerCubeCol,       // A_OBJ_BLOCK_LARGE, A_OBJ_BLOCK_HUGE
    &gSmallerFlatBlockCol, // unused
    &gLargerFlatBlockCol,  // A_OBJ_BLOCK_SMALL_ROT, A_OBJ_BLOCK_LARGE_ROT
    &gSmallerCubeCol,      // unused
    &D_06000730,           // A_OBJ_UNKNOWN_6
};

static Gfx* sDLists[] = {
    gFlatBlockDL,
    gFlatBlockDL,
    gFlatBlockDL,
    gFlatRotBlockDL,
    gFlatRotBlockDL,
    gSmallCubeDL,
    /* gHookshotPostDL ? */ (Gfx*)0x06000211,
    gGrassBladesDL,
    gTreeStumpDL,
    gSignRectangularDL,
    gSignDirectionalDL,
    gBoulderFragmentsDL,
};

void EnAObj_SetupAction(EnAObj* pthis, EnAObjActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnAObj_Init(Actor* pthisx, GlobalContext* globalCtx) {
    CollisionHeader* colHeader = NULL;
    s32 pad;
    EnAObj* pthis = (EnAObj*)pthisx;
    f32 shadowScale = 6.0f;

    pthis->textId = (pthisx->params >> 8) & 0xFF;
    pthisx->params &= 0xFF;

    switch (pthisx->params) {
        case A_OBJ_BLOCK_SMALL:
            Actor_SetScale(pthisx, 0.025f);
            break;
        case A_OBJ_BLOCK_LARGE:
            Actor_SetScale(pthisx, 0.05f);
            break;
        case A_OBJ_BLOCK_HUGE:
        case A_OBJ_CUBE_SMALL:
        case A_OBJ_UNKNOWN_6:
            Actor_SetScale(pthisx, 0.1f);
            break;
        case A_OBJ_BLOCK_SMALL_ROT:
            Actor_SetScale(pthisx, 0.005f);
            break;
        case A_OBJ_BLOCK_LARGE_ROT:
        default:
            Actor_SetScale(pthisx, 0.01f);
            break;
    }

    if (pthisx->params >= A_OBJ_SIGNPOST_OBLONG) {
        shadowScale = 12.0f;
    }

    ActorShape_Init(&pthisx->shape, 0.0f, ActorShadow_DrawCircle, shadowScale);

    pthisx->focus.pos = pthisx->world.pos;
    pthis->dyna.bgId = BGACTOR_NEG_ONE;
    pthis->dyna.unk_160 = 0;
    pthis->dyna.unk_15C = DPM_UNK;
    pthisx->uncullZoneDownward = 1200.0f;
    pthisx->uncullZoneScale = 200.0f;

    switch (pthisx->params) {
        case A_OBJ_BLOCK_LARGE:
        case A_OBJ_BLOCK_HUGE:
            pthis->dyna.bgId = 1;
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, pthisx, ACTORCAT_BG);
            EnAObj_SetupBlock(pthis, pthisx->params);
            break;
        case A_OBJ_BLOCK_SMALL_ROT:
        case A_OBJ_BLOCK_LARGE_ROT:
            pthis->dyna.bgId = 3;
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, pthisx, ACTORCAT_BG);
            EnAObj_SetupBlockRot(pthis, pthisx->params);
            break;
        case A_OBJ_UNKNOWN_6:
            // clang-format off
            pthisx->flags |= ACTOR_FLAG_0; pthis->dyna.bgId = 5; pthis->focusYoffset = 10.0f;
            // clang-format on
            pthisx->gravity = -2.0f;
            EnAObj_SetupWaitTalk(pthis, pthisx->params);
            break;
        case A_OBJ_GRASS_CLUMP:
        case A_OBJ_TREE_STUMP:
            pthis->dyna.bgId = 0;
            EnAObj_SetupWaitTalk(pthis, pthisx->params);
            break;
        case A_OBJ_SIGNPOST_OBLONG:
        case A_OBJ_SIGNPOST_ARROW:
            pthisx->textId = (pthis->textId & 0xFF) | 0x300;
            // clang-format off
            pthisx->flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3; pthisx->targetArrowOffset = 500.0f;
            // clang-format on
            pthis->focusYoffset = 45.0f;
            EnAObj_SetupWaitTalk(pthis, pthisx->params);
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, pthisx, &sCylinderInit);
            pthisx->colChkInfo.mass = MASS_IMMOVABLE;
            pthisx->targetMode = 0;
            break;
        case A_OBJ_BOULDER_FRAGMENT:
            pthisx->gravity = -1.5f;
            EnAObj_SetupBoulderFragment(pthis, pthisx->params);
            break;
        default:
            pthisx->gravity = -2.0f;
            EnAObj_SetupWaitTalk(pthis, pthisx->params);
            break;
    }

    if (pthisx->params <= A_OBJ_BLOCK_LARGE_ROT) { // A_OBJ_BLOCK_*
        pthisx->colChkInfo.mass = MASS_IMMOVABLE;
    }

    if (pthis->dyna.bgId != BGACTOR_NEG_ONE) {
        CollisionHeader_GetVirtual(sColHeaders[pthis->dyna.bgId], &colHeader);
        pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, pthisx, colHeader);
    }
}

void EnAObj_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    EnAObj* pthis = (EnAObj*)pthisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);

    switch (pthis->dyna.actor.params) {
        case A_OBJ_SIGNPOST_OBLONG:
        case A_OBJ_SIGNPOST_ARROW:
            Collider_DestroyCylinder(globalCtx, &pthis->collider);
            break;
    }
}

void EnAObj_WaitFinishedTalking(EnAObj* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->dyna.actor, globalCtx)) {
        EnAObj_SetupWaitTalk(pthis, pthis->dyna.actor.params);
    }
}

void EnAObj_SetupWaitTalk(EnAObj* pthis, s16 type) {
    EnAObj_SetupAction(pthis, EnAObj_WaitTalk);
}

void EnAObj_WaitTalk(EnAObj* pthis, GlobalContext* globalCtx) {
    s16 relYawTowardsPlayer;

    if (pthis->dyna.actor.textId != 0) {
        relYawTowardsPlayer = pthis->dyna.actor.yawTowardsPlayer - pthis->dyna.actor.shape.rot.y;
        if (ABS(relYawTowardsPlayer) < 0x2800 ||
            (pthis->dyna.actor.params == A_OBJ_SIGNPOST_ARROW && ABS(relYawTowardsPlayer) > 0x5800)) {
            if (Actor_ProcessTalkRequest(&pthis->dyna.actor, globalCtx)) {
                EnAObj_SetupAction(pthis, EnAObj_WaitFinishedTalking);
            } else {
                func_8002F2F4(&pthis->dyna.actor, globalCtx);
            }
        }
    }
}

void EnAObj_SetupBlockRot(EnAObj* pthis, s16 type) {
    pthis->rotateState = 0;
    pthis->rotateWaitTimer = 10;
    pthis->dyna.actor.world.rot.y = 0;
    pthis->dyna.actor.shape.rot = pthis->dyna.actor.world.rot;
    EnAObj_SetupAction(pthis, EnAObj_BlockRot);
}

void EnAObj_BlockRot(EnAObj* pthis, GlobalContext* globalCtx) {
    if (pthis->rotateState == 0) {
        if (pthis->dyna.unk_160 != 0) {
            pthis->rotateState++;
            pthis->rotateForTimer = 20;

            if ((s16)(pthis->dyna.actor.yawTowardsPlayer + 0x4000) < 0) {
                pthis->rotSpeedX = -0x3E8;
            } else {
                pthis->rotSpeedX = 0x3E8;
            }

            if (pthis->dyna.actor.yawTowardsPlayer < 0) {
                pthis->rotSpeedY = -pthis->rotSpeedX;
            } else {
                pthis->rotSpeedY = pthis->rotSpeedX;
            }
        }
    } else {
        if (pthis->rotateWaitTimer != 0) {
            pthis->rotateWaitTimer--;
        } else {
            pthis->dyna.actor.shape.rot.y += pthis->rotSpeedY;
            pthis->dyna.actor.shape.rot.x += pthis->rotSpeedX;
            pthis->rotateForTimer--;
            pthis->dyna.actor.gravity = -1.0f;

            if (pthis->rotateForTimer == 0) {
                pthis->dyna.actor.world.pos = pthis->dyna.actor.home.pos;
                pthis->rotateState = 0;
                pthis->rotateWaitTimer = 10;
                pthis->dyna.actor.velocity.y = 0.0f;
                pthis->dyna.actor.gravity = 0.0f;
                pthis->dyna.actor.shape.rot = pthis->dyna.actor.world.rot;
            }
        }
    }
}

void EnAObj_SetupBoulderFragment(EnAObj* pthis, s16 type) {
    EnAObj_SetupAction(pthis, EnAObj_BoulderFragment);
}

void EnAObj_BoulderFragment(EnAObj* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->dyna.actor.speedXZ, 1.0f, 1.0f, 0.5f, 0.0f);
    pthis->dyna.actor.shape.rot.x += pthis->dyna.actor.world.rot.x >> 1;
    pthis->dyna.actor.shape.rot.z += pthis->dyna.actor.world.rot.z >> 1;

    if (pthis->dyna.actor.speedXZ != 0.0f && pthis->dyna.actor.bgCheckFlags & 0x8) {
        pthis->dyna.actor.world.rot.y =
            pthis->dyna.actor.wallYaw - pthis->dyna.actor.world.rot.y + pthis->dyna.actor.wallYaw - 0x8000;
        if (1) {}
        pthis->dyna.actor.bgCheckFlags &= ~0x8;
    }

    if (pthis->dyna.actor.bgCheckFlags & 0x2) {
        if (pthis->dyna.actor.velocity.y < -8.0f) {
            pthis->dyna.actor.velocity.y *= -0.6f;
            pthis->dyna.actor.speedXZ *= 0.6f;
            pthis->dyna.actor.bgCheckFlags &= ~0x3;
        } else {
            Actor_Kill(&pthis->dyna.actor);
        }
    }
}

void EnAObj_SetupBlock(EnAObj* pthis, s16 type) {
    pthis->dyna.actor.uncullZoneDownward = 1200.0f;
    pthis->dyna.actor.uncullZoneScale = 720.0f;
    EnAObj_SetupAction(pthis, EnAObj_Block);
}

void EnAObj_Block(EnAObj* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.speedXZ += pthis->dyna.unk_150;
    pthis->dyna.actor.world.rot.y = pthis->dyna.unk_158;
    pthis->dyna.actor.speedXZ = CLAMP(pthis->dyna.actor.speedXZ, -2.5f, 2.5f);

    Math_SmoothStepToF(&pthis->dyna.actor.speedXZ, 0.0f, 1.0f, 1.0f, 0.0f);

    if (pthis->dyna.actor.speedXZ != 0.0f) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
    }

    pthis->dyna.unk_154 = 0.0f;
    pthis->dyna.unk_150 = 0.0f;
}

void EnAObj_Update(Actor* pthisx, GlobalContext* globalCtx) {
    EnAObj* pthis = (EnAObj*)pthisx;

    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->dyna.actor);

    if (pthis->dyna.actor.gravity != 0.0f) {
        if (pthis->dyna.actor.params != A_OBJ_BOULDER_FRAGMENT) {
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 5.0f, 40.0f, 0.0f, 0x1D);
        } else {
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 5.0f, 20.0f, 0.0f, 0x1D);
        }
    }

    pthis->dyna.actor.focus.pos = pthis->dyna.actor.world.pos;
    pthis->dyna.actor.focus.pos.y += pthis->focusYoffset;

    switch (pthis->dyna.actor.params) {
        case A_OBJ_SIGNPOST_OBLONG:
        case A_OBJ_SIGNPOST_ARROW:
            Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->collider);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            break;
    }
}

void EnAObj_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    s32 type = pthisx->params;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_a_keep.c", 701);

    func_80093D18(globalCtx->state.gfxCtx);

    if (type >= A_OBJ_MAX) {
        type = A_OBJ_BOULDER_FRAGMENT;
    }

    if (pthisx->params == A_OBJ_BOULDER_FRAGMENT) {
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 1, 60, 60, 60, 50);
    }

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_a_keep.c", 712),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDLists[type]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_a_keep.c", 715);
}
