#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_HAMSTEP_Z_BG_HIDAN_HAMSTEP_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_hamstep.c
 * Overlay: ovl_Bg_Hidan_Hamstep
 * Description: Stone Steps and Platforms (Fire Temple)
 */

#include "z_bg_hidan_hamstep.h"
#include "framerate.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_quake.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgHidanHamstep_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanHamstep_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanHamstep_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanHamstep_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808887C4(BgHidanHamstep* pthis, GlobalContext* globalCtx);
void func_80888860(BgHidanHamstep* pthis, GlobalContext* globalCtx);
void func_808889B8(BgHidanHamstep* pthis, GlobalContext* globalCtx);
void func_80888A58(BgHidanHamstep* pthis, GlobalContext* globalCtx);
void BgHidanHamstep_DoNothing(BgHidanHamstep* pthis, GlobalContext* globalCtx);

static f32 sYPosOffsets[] = {
    -20.0f, -120.0f, -220.0f, -320.0f, -420.0f,
};

static ColliderTrisElementInit sTrisElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x40000040, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { -20.0f, 3.0f, -20.0f }, { -20.0f, 3.0f, 20.0f }, { 20.0f, 3.0f, 20.0f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x40000040, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 20.0f, 3.0f, 20.0f }, { 20.0f, 3.0f, -20.0f }, { -20.0f, 3.0f, -20.0f } } },
    },
};

static ColliderTrisInit sTrisInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_TRIS,
    },
    2,
    sTrisElementsInit,
};

ActorInit Bg_Hidan_Hamstep_InitVars = {
    ACTOR_BG_HIDAN_HAMSTEP,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanHamstep),
    (ActorFunc)BgHidanHamstep_Init,
    (ActorFunc)BgHidanHamstep_Destroy,
    (ActorFunc)BgHidanHamstep_Update,
    (ActorFunc)BgHidanHamstep_Draw,
};

static BgHidanHamstepActionFunc sActionFuncs[] = {
    func_808887C4, func_80888860, func_808889B8, func_80888A58, BgHidanHamstep_DoNothing,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

static f32 sEffectPositions[][2] = {
    { -100.0f, 40.0f },  { 100.0f, 40.0f }, { -100.0f, 0.0f },   { 100.0f, 0.0f },
    { -100.0f, -40.0f }, { 100.0f, 40.0f }, { -100.0f, -80.0f }, { -50.0f, -80.0f },
    { 0.0f, -80.0f },    { 50.0f, -80.0f }, { 100.0f, -80.0f },
};

void BgHidanHamstep_SetupAction(BgHidanHamstep* pthis, s32 action) {
    pthis->action = action;
    pthis->actionFunc = sActionFuncs[action];
}

s32 BgHidanHamstep_SpawnChildren(BgHidanHamstep* pthis, GlobalContext* globalCtx2) {
    BgHidanHamstep* step = pthis;
    s32 i;
    Vec3f pos;
    f32 sin;
    f32 cos;
    s16 params;
    GlobalContext* globalCtx = globalCtx2;

    pos.y = pthis->dyna.actor.home.pos.y - 100.0f;
    sin = Math_SinS(pthis->dyna.actor.shape.rot.y + 0x8000);
    cos = Math_CosS(pthis->dyna.actor.shape.rot.y + 0x8000);

    for (i = 0; i < 5; i++) {
        pos.x = (((i * 160.0f) + 60.0f) * sin) + pthis->dyna.actor.home.pos.x;
        pos.z = (((i * 160.0f) + 60.0f) * cos) + pthis->dyna.actor.home.pos.z;

        params = (i + 1) & 0xFF;
        params |= (pthis->dyna.actor.params & 0xFF00);

        step = (BgHidanHamstep*)Actor_SpawnAsChild(
            &globalCtx->actorCtx, &step->dyna.actor, globalCtx, ACTOR_BG_HIDAN_HAMSTEP, pos.x, pos.y, pos.z,
            pthis->dyna.actor.world.rot.x, pthis->dyna.actor.world.rot.y, pthis->dyna.actor.world.rot.z, params);

        if (step == NULL) {
            return 0;
        }
    }
    return 1;
}

void BgHidanHamstep_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanHamstep* pthis = (BgHidanHamstep*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;
    Vec3f sp48[3];
    s32 i;
    s32 i2;
    BgHidanHamstep* step;

    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);

    if ((pthis->dyna.actor.params & 0xFF) == 0) {
        Collider_InitTris(globalCtx, &pthis->collider);
        Collider_SetTris(globalCtx, &pthis->collider, &pthis->dyna.actor, &sTrisInit, pthis->colliderItems);

        for (i = 0; i < 2; i++) {
            for (i2 = 0; i2 < 3; i2++) {
                sp48[i2].x = sTrisInit.elements[i].dim.vtx[i2].x + pthis->dyna.actor.home.pos.x;
                sp48[i2].y = sTrisInit.elements[i].dim.vtx[i2].y + pthis->dyna.actor.home.pos.y;
                sp48[i2].z = sTrisInit.elements[i].dim.vtx[i2].z + pthis->dyna.actor.home.pos.z;
            }
            Collider_SetTrisVertices(&pthis->collider, i, &sp48[0], &sp48[1], &sp48[2]);
        }
    }

    if ((pthis->dyna.actor.params & 0xFF) == 0) {
        CollisionHeader_GetVirtual(&gFireTempleStoneStep1Col, &colHeader);
    } else {
        CollisionHeader_GetVirtual(&gFireTempleStoneStep2Col, &colHeader);
    }

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0xFF)) {
        if ((pthis->dyna.actor.params & 0xFF) == 0) {
            pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + (-20.0f);
            BgHidanHamstep_SetupAction(pthis, 4);
        } else {
            pthis->dyna.actor.world.pos.y =
                sYPosOffsets[(pthis->dyna.actor.params & 0xFF) - 1] + pthis->dyna.actor.home.pos.y;
            BgHidanHamstep_SetupAction(pthis, 4);
        }
    } else if ((pthis->dyna.actor.params & 0xFF) == 0) {
        BgHidanHamstep_SetupAction(pthis, 0);
    } else {
        BgHidanHamstep_SetupAction(pthis, 2);
    }

    pthis->dyna.actor.gravity = -1.2f;
    pthis->dyna.actor.minVelocityY = -12.0f;

    if ((pthis->dyna.actor.params & 0xFF) == 0) {
        // "Fire Temple Object [Hammer Step] appears"
        osSyncPrintf("◯◯◯炎の神殿オブジェクト【ハンマーステップ】出現\n");
        if (BgHidanHamstep_SpawnChildren(pthis, globalCtx) == 0) {
            step = pthis;

            // "[Hammer Step] I can't create a step!"
            osSyncPrintf("【ハンマーステップ】 足場産れない！！\n");
            osSyncPrintf("%s %d\n", "../z_bg_hidan_hamstep.c", 425);

            while (step != NULL) {
                Actor_Kill(&step->dyna.actor);
                step = (BgHidanHamstep*)step->dyna.actor.child;
            }
        }
    }
}

void BgHidanHamstep_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanHamstep* pthis = (BgHidanHamstep*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);

    if ((pthis->dyna.actor.params & 0xFF) == 0) {
        Collider_DestroyTris(globalCtx, &pthis->collider);
    }
}

void func_808884C8(BgHidanHamstep* step, GlobalContext* globalCtx) {
    Vec3f pos = step->dyna.actor.world.pos;
    s32 i;
    f32 sin;
    f32 cos;

    pos.y -= 20.0f;

    func_80033480(globalCtx, &pos, 0.0f, 0, 600, 300, 0);

    sin = Math_SinS(step->dyna.actor.shape.rot.y + 0x8000);
    cos = Math_CosS(step->dyna.actor.shape.rot.y + 0x8000);

    pos.y = step->dyna.actor.world.pos.y;

    for (i = 0; i < ARRAY_COUNT(sEffectPositions); i++) {
        pos.x = (sEffectPositions[i][1] * sin) + (sEffectPositions[i][0] * cos) + step->dyna.actor.world.pos.x;
        pos.z = ((sEffectPositions[i][1] * cos) - (sEffectPositions[i][0] * sin)) + step->dyna.actor.world.pos.z;
        func_80033480(globalCtx, &pos, 0.0f, 0, 150, 150, 0);
    }
}

void func_80888638(BgHidanHamstep* pthis, GlobalContext* globalCtx) {
    BgHidanHamstep* child = (BgHidanHamstep*)pthis->dyna.actor.child;

    while (child != NULL) {
        if ((child->dyna.actor.params & 0xFF) != 0) {
            func_808884C8(child, globalCtx);
        }
        child = (BgHidanHamstep*)child->dyna.actor.child;
    }
}

void func_80888694(BgHidanHamstep* pthis, BgHidanHamstep* parent) {
    BgHidanHamstep* child;

    if ((pthis->dyna.actor.params & 0xFF) >= 2) {
        if (parent->dyna.actor.world.pos.y < pthis->dyna.actor.world.pos.y) {
            pthis->dyna.actor.world.pos.y = parent->dyna.actor.world.pos.y;
        } else if ((pthis->dyna.actor.world.pos.y - parent->dyna.actor.world.pos.y) < -100.0f) {
            pthis->dyna.actor.world.pos.y = parent->dyna.actor.world.pos.y - 100.0f;
        }
    }

    child = (BgHidanHamstep*)pthis->dyna.actor.child;

    while (child != NULL) {
        if (pthis->dyna.actor.world.pos.y < child->dyna.actor.world.pos.y) {
            child->dyna.actor.world.pos.y = pthis->dyna.actor.world.pos.y;
        }
        child = (BgHidanHamstep*)child->dyna.actor.child;
    }
}

void func_80888734(BgHidanHamstep* pthis) {
    BgHidanHamstep* parent = (BgHidanHamstep*)pthis->dyna.actor.parent;
    f32 frameDivisor = FRAMERATE_ANIM_SCALER;

    if (parent != NULL) {
        pthis->dyna.actor.velocity.y = parent->dyna.actor.velocity.y;

        if ((pthis->dyna.actor.params & 0xFF) == 1) {
            pthis->dyna.actor.world.pos.y = parent->dyna.actor.world.pos.y - 100.0f;
        } else {
            pthis->dyna.actor.world.pos.y += (pthis->dyna.actor.velocity.y * frameDivisor);
        }

        func_80888694(pthis, parent);
    }
}

void func_808887C4(BgHidanHamstep* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        OnePointCutscene_Init(globalCtx, 3310, 100, &pthis->dyna.actor, MAIN_CAM);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_HAMMER_SWITCH);
        pthis->collider.base.acFlags = AC_NONE;
        BgHidanHamstep_SetupAction(pthis, 1);
        Flags_SetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0xFF);
    } else {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void func_80888860(BgHidanHamstep* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 pad2;
    s32 quakeIndex;

    Actor_MoveForward(&pthis->dyna.actor);

    if (((pthis->dyna.actor.world.pos.y - pthis->dyna.actor.home.pos.y) < (-20.0f - pthis->dyna.actor.minVelocityY)) &&
        (pthis->dyna.actor.velocity.y <= 0.0f)) {
        pthis->unk_244++;

        if (pthis->unk_244 >= 7) {
            pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + -20.0f;
            BgHidanHamstep_SetupAction(pthis, 4);
        } else {
            pthis->dyna.actor.velocity.y *= -0.24f;

            if (1) {}

            if (pthis->unk_244 == 1) {
                quakeIndex = Quake_Add(GET_ACTIVE_CAM(globalCtx), 3);
                Quake_SetSpeed(quakeIndex, -15536);
                Quake_SetQuakeValues(quakeIndex, 0, 0, 500, 0);
                Quake_SetCountdown(quakeIndex, 20);
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
                func_800AA000(pthis->dyna.actor.xyzDistToPlayerSq, 255, 20, 150);
                func_80888638(pthis, globalCtx);
                osSyncPrintf("A(%d)\n", pthis->dyna.actor.params);
            }
        }
    }
}

void func_808889B8(BgHidanHamstep* pthis, GlobalContext* globalCtx) {
    s32 pad;
    BgHidanHamstep* parent = (BgHidanHamstep*)pthis->dyna.actor.parent;

    func_80888734(pthis);

    if ((parent->action == 4) || ((parent->action == 3) && (parent->unk_244 >= 5))) {
        if ((pthis->dyna.actor.params & 0xFF) == 1) {
            pthis->dyna.actor.world.pos.y =
                sYPosOffsets[(pthis->dyna.actor.params & 0xFF) - 1] + pthis->dyna.actor.home.pos.y;
            BgHidanHamstep_SetupAction(pthis, 4);
        } else {
            BgHidanHamstep_SetupAction(pthis, 3);
        }
    }
}

void func_80888A58(BgHidanHamstep* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 pad2;
    s32 quakeIndex;

    Actor_MoveForward(&pthis->dyna.actor);
    func_80888694(pthis, (BgHidanHamstep*)pthis->dyna.actor.parent);

    if (((pthis->dyna.actor.params & 0xFF) <= 0) || ((pthis->dyna.actor.params & 0xFF) >= 6)) {
        // "[Hammer Step] arg_data strange (arg_data = %d)"
        osSyncPrintf("【ハンマーステップ】 arg_data おかしい (arg_data = %d)", pthis->dyna.actor.params);
        osSyncPrintf("%s %d\n", "../z_bg_hidan_hamstep.c", 696);
    }

    if (((pthis->dyna.actor.world.pos.y - pthis->dyna.actor.home.pos.y) <=
         sYPosOffsets[(pthis->dyna.actor.params & 0xFF) - 1]) &&
        (pthis->dyna.actor.velocity.y <= 0.0f)) {
        pthis->unk_244++;

        if (pthis->unk_244 >= 7) {
            pthis->dyna.actor.world.pos.y =
                sYPosOffsets[(pthis->dyna.actor.params & 0xFF) - 1] + pthis->dyna.actor.home.pos.y;
            BgHidanHamstep_SetupAction(pthis, 3);
        } else {
            pthis->dyna.actor.velocity.y *= -0.24f;

            if (1) {}

            if (pthis->unk_244 == 1) {
                quakeIndex = Quake_Add(GET_ACTIVE_CAM(globalCtx), 3);
                Quake_SetSpeed(quakeIndex, -15536);
                Quake_SetQuakeValues(quakeIndex, 20, 1, 0, 0);
                Quake_SetCountdown(quakeIndex, 7);

                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
                func_800AA000(10000.0f, 255, 20, 150);
                func_808884C8(pthis, globalCtx);

                if ((pthis->dyna.actor.params & 0xFF) == 5) {
                    func_80078884(NA_SE_SY_CORRECT_CHIME);
                }

                osSyncPrintf("B(%d)\n", pthis->dyna.actor.params);
            }
        }
    }
}

void BgHidanHamstep_DoNothing(BgHidanHamstep* pthis, GlobalContext* globalCtx) {
}

void BgHidanHamstep_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanHamstep* pthis = (BgHidanHamstep*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgHidanHamstep_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_hamstep.c", 782);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_hidan_hamstep.c", 787),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if ((thisx->params & 0xFF) == 0) {
        gSPDisplayList(POLY_OPA_DISP++, gFireTempleStoneStep1DL);
    } else {
        gSPDisplayList(POLY_OPA_DISP++, gFireTempleStoneStep2DL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_hamstep.c", 796);
}
