#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_DODOAGO_Z_BG_DODOAGO_C
#include "actor_common.h"
/*
 * File: z_bg_dodoago.c
 * Overlay: ovl_Bg_Dodoago
 * Description: Dodongo Head Statue in Dodongo's Cavern
 */

#include "z_bg_dodoago.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "objects/object_ddan_objects/object_ddan_objects.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/code_800F7260.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgDodoago_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgDodoago_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgDodoago_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgDodoago_Draw(Actor* pthisx, GlobalContext* globalCtx);

void BgDodoago_WaitExplosives(BgDodoago* pthis, GlobalContext* globalCtx);
void BgDodoago_OpenJaw(BgDodoago* pthis, GlobalContext* globalCtx);
void BgDodoago_DoNothing(BgDodoago* pthis, GlobalContext* globalCtx);
void BgDodoago_LightOneEye(BgDodoago* pthis, GlobalContext* globalCtx);

ActorInit Bg_Dodoago_InitVars = {
    ACTOR_BG_DODOAGO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_DDAN_OBJECTS,
    sizeof(BgDodoago),
    (ActorFunc)BgDodoago_Init,
    (ActorFunc)BgDodoago_Destroy,
    (ActorFunc)BgDodoago_Update,
    (ActorFunc)BgDodoago_Draw,
};

static ColliderCylinderInit sColCylinderInitMain = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_ALL,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 80, 30, 80, { 0, 0, 0 } },
};

static ColliderCylinderInit sColCylinderInitLeftRight = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_NO_PUSH | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 50, 60, 280, { 0, 0, 0 } },
};

static s16 sFirstExplosiveFlag = false;

static u8 sDisableBombCatcher;

static u8 sUnused[90]; // unknown length

static s32 sTimer;

void BgDodoago_SetupAction(BgDodoago* pthis, BgDodoagoActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgDodoago_SpawnSparkles(Vec3f* meanPos, GlobalContext* globalCtx) {
    Vec3f pos;
    Color_RGBA8 primColor = { 100, 100, 100, 0 };
    Color_RGBA8 envColor = { 40, 40, 40, 0 };
    static Vec3f velocity = { 0.0f, -1.5f, 0.0f };
    static Vec3f acceleration = { 0.0f, -0.2f, 0.0f };
    s32 i;

    for (i = 4; i > 0; i--) {
        pos.x = Rand_CenteredFloat(20.0f) + meanPos->x;
        pos.y = Rand_CenteredFloat(10.0f) + meanPos->y;
        pos.z = Rand_CenteredFloat(20.0f) + meanPos->z;
        EffectSsKiraKira_SpawnSmall(globalCtx, &pos, &velocity, &acceleration, &primColor, &envColor);
    }
}

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 5000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 800, ICHAIN_STOP),
};

void BgDodoago_Init(Actor* pthisx, GlobalContext* globalCtx) {
    BgDodoago* pthis = (BgDodoago*)pthisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gDodongoLowerJawCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    ActorShape_Init(&pthis->dyna.actor.shape, 0.0f, NULL, 0.0f);

    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
        BgDodoago_SetupAction(pthis, BgDodoago_DoNothing);
        pthis->dyna.actor.shape.rot.x = 0x1333;
        globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_LEFT] = globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_RIGHT] = 255;
        return;
    }

    Collider_InitCylinder(globalCtx, &pthis->colliderMain);
    Collider_InitCylinder(globalCtx, &pthis->colliderLeft);
    Collider_InitCylinder(globalCtx, &pthis->colliderRight);
    Collider_SetCylinder(globalCtx, &pthis->colliderMain, &pthis->dyna.actor, &sColCylinderInitMain);
    Collider_SetCylinder(globalCtx, &pthis->colliderLeft, &pthis->dyna.actor, &sColCylinderInitLeftRight);
    Collider_SetCylinder(globalCtx, &pthis->colliderRight, &pthis->dyna.actor, &sColCylinderInitLeftRight);

    BgDodoago_SetupAction(pthis, BgDodoago_WaitExplosives);
    sDisableBombCatcher = false;
}

void BgDodoago_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgDodoago* pthis = (BgDodoago*)pthisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyCylinder(globalCtx, &pthis->colliderMain);
    Collider_DestroyCylinder(globalCtx, &pthis->colliderLeft);
    Collider_DestroyCylinder(globalCtx, &pthis->colliderRight);
}

void BgDodoago_WaitExplosives(BgDodoago* pthis, GlobalContext* globalCtx) {
    Actor* explosive = Actor_GetCollidedExplosive(globalCtx, &pthis->colliderMain.base);

    if (explosive != NULL) {
        pthis->state =
            (Math_Vec3f_Yaw(&pthis->dyna.actor.world.pos, &explosive->world.pos) >= pthis->dyna.actor.shape.rot.y)
                ? BGDODOAGO_EYE_RIGHT
                : BGDODOAGO_EYE_LEFT;

        if (((globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_LEFT] == 255) && (pthis->state == BGDODOAGO_EYE_RIGHT)) ||
            ((globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_RIGHT] == 255) && (pthis->state == BGDODOAGO_EYE_LEFT))) {
            Flags_SetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);
            pthis->state = 0;
            Audio_PlaySoundGeneral(NA_SE_SY_CORRECT_CHIME, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            BgDodoago_SetupAction(pthis, BgDodoago_OpenJaw);
            OnePointCutscene_Init(globalCtx, 3380, 160, &pthis->dyna.actor, MAIN_CAM);
        } else if (globalCtx->roomCtx.unk_74[pthis->state] == 0) {
            OnePointCutscene_Init(globalCtx, 3065, 40, &pthis->dyna.actor, MAIN_CAM);
            BgDodoago_SetupAction(pthis, BgDodoago_LightOneEye);
            Audio_PlaySoundGeneral(NA_SE_SY_CORRECT_CHIME, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        } else {
            OnePointCutscene_Init(globalCtx, 3065, 20, &pthis->dyna.actor, MAIN_CAM);
            Audio_PlaySoundGeneral(NA_SE_SY_ERROR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            sTimer += 30;
            return;
        }

        // the flag is never set back to false, so pthis only runs once
        if (!sFirstExplosiveFlag) {
            // pthis disables the bomb catcher (see BgDodoago_Update) for a few seconds
            pthis->dyna.actor.parent = explosive;
            sFirstExplosiveFlag = true;
            sTimer = 50;
        }
    } else if (Flags_GetEventChkInf(0xB0)) {
        Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->colliderMain);
        Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->colliderLeft);
        Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->colliderRight);

        pthis->colliderMain.dim.pos.z += 200;

        pthis->colliderLeft.dim.pos.z += 215;
        pthis->colliderLeft.dim.pos.x += 90;

        pthis->colliderRight.dim.pos.z += 215;
        pthis->colliderRight.dim.pos.x -= 90;

        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderMain.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderLeft.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderRight.base);
    }
}

void BgDodoago_OpenJaw(BgDodoago* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f dustOffsets[] = {
        { 0.0f, -200.0f, 430.0f },   { 20.0f, -200.0f, 420.0f }, { -20.0f, -200.0f, 420.0f },
        { 40.0, -200.0f, 380.0f },   { -40.0, -200.0f, 380.0f }, { 50.0, -200.0f, 350.0f },
        { -50.0f, -200.0f, 350.0f }, { 60.0f, -200.0f, 320.0f }, { -60.0f, -200.0f, 320.0f },
        { 70.0f, -200.0f, 290.0f },  { -70.0, -200.0f, 290.0f },
    };
    s32 i;

    // make both eyes red (one already is)
    if (globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_LEFT] < 255) {
        globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_LEFT] += 5;
    }
    if (globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_RIGHT] < 255) {
        globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_RIGHT] += 5;
    }

    if (globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_LEFT] != 255 || globalCtx->roomCtx.unk_74[BGDODOAGO_EYE_RIGHT] != 255) {
        sTimer--;
        return;
    }

    if (sTimer == 108) {
        for (i = ARRAY_COUNT(dustOffsets) - 1; i >= 0; i--) {
            pos.x = dustOffsets[i].x + pthis->dyna.actor.world.pos.x;
            pos.y = dustOffsets[i].y + pthis->dyna.actor.world.pos.y;
            pos.z = dustOffsets[i].z + pthis->dyna.actor.world.pos.z;
            func_80033480(globalCtx, &pos, 2.0f, 3, 200, 75, 1);
        }
    }

    pos.x = pthis->dyna.actor.world.pos.x + 200.0f;
    pos.y = pthis->dyna.actor.world.pos.y - 20.0f;
    pos.z = pthis->dyna.actor.world.pos.z + 100.0f;
    BgDodoago_SpawnSparkles(&pos, globalCtx);

    pos.x = pthis->dyna.actor.world.pos.x - 200.0f;
    pos.y = pthis->dyna.actor.world.pos.y - 20.0f;
    pos.z = pthis->dyna.actor.world.pos.z + 100.0f;
    BgDodoago_SpawnSparkles(&pos, globalCtx);

    Math_StepToS(&pthis->state, 100, 3);
    func_800AA000(500.0f, 0x78, 0x14, 0xA);

    if (Math_SmoothStepToS(&pthis->dyna.actor.shape.rot.x, 0x1333, 110 - pthis->state, 0x3E8, 0x32) == 0) {
        BgDodoago_SetupAction(pthis, BgDodoago_DoNothing);
        Audio_PlaySoundGeneral(NA_SE_EV_STONE_BOUND, &pthis->dyna.actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else {
        Audio_PlaySoundGeneral(NA_SE_EV_STONE_STATUE_OPEN - SFX_FLAG, &pthis->dyna.actor.projectedPos, 4, &D_801333E0,
                               &D_801333E0, &D_801333E8);
    }
}

void BgDodoago_DoNothing(BgDodoago* pthis, GlobalContext* globalCtx) {
}

void BgDodoago_LightOneEye(BgDodoago* pthis, GlobalContext* globalCtx) {
    globalCtx->roomCtx.unk_74[pthis->state] += 5;

    if (globalCtx->roomCtx.unk_74[pthis->state] == 255) {
        BgDodoago_SetupAction(pthis, BgDodoago_WaitExplosives);
    }
}

void BgDodoago_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgDodoago* pthis = (BgDodoago*)pthisx;
    Actor* actor;
    EnBom* bomb;

    if (pthis->dyna.actor.parent == NULL) {
        // pthis is a "bomb catcher", it kills the XZ speed and sets the timer for bombs that are dropped through the
        // holes in the bridge above the skull
        if ((pthis->colliderLeft.base.ocFlags1 & OC1_HIT) || (pthis->colliderRight.base.ocFlags1 & OC1_HIT)) {

            if (pthis->colliderLeft.base.ocFlags1 & OC1_HIT) {
                actor = pthis->colliderLeft.base.oc;
            } else {
                actor = pthis->colliderRight.base.oc;
            }
            pthis->colliderLeft.base.ocFlags1 &= ~OC1_HIT;
            pthis->colliderRight.base.ocFlags1 &= ~OC1_HIT;

            if (actor->category == ACTORCAT_EXPLOSIVE && actor->id == ACTOR_EN_BOM && actor->params == 0) {
                bomb = (EnBom*)actor;
                // disable the bomb catcher for a few seconds
                pthis->dyna.actor.parent = &bomb->actor;
                bomb->timer = 50;
                bomb->actor.speedXZ = 0.0f;
                sTimer = 0;
            }
        }
    } else {
        sTimer++;
        Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);
        if (!sDisableBombCatcher && sTimer > 140) {
            if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
                // pthis prevents clearing the actor's parent pointer, effectively disabling the bomb catcher
                sDisableBombCatcher++;
            } else {
                pthis->dyna.actor.parent = NULL;
            }
        }
    }
    pthis->actionFunc(pthis, globalCtx);
}

void BgDodoago_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_dodoago.c", 672);

    if (Flags_GetEventChkInf(0xB0)) {
        func_80093D18(globalCtx->state.gfxCtx);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_dodoago.c", 677),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gDodongoLowerJawDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_dodoago.c", 681);
}
