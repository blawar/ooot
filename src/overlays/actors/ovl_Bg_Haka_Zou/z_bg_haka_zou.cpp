#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HAKA_ZOU_Z_BG_HAKA_ZOU_C
#include "actor_common.h"
/*
 * File: z_bg_haka_zou.c
 * Overlay: ovl_Bg_Haka_Zou
 * Description: Statue and Wall (Shadow Temple)
 */

#include "z_bg_haka_zou.h"
#include "objects/object_hakach_objects/object_hakach_objects.h"
#include "objects/object_haka_objects/object_haka_objects.h"
#include "def/code_80043480.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_scene.h"

#define FLAGS ACTOR_FLAG_4

typedef enum {
    /* 0x0 */ STA_GIANT_BIRD_STATUE,
    /* 0x1 */ STA_BOMBABLE_SKULL_WALL,
    /* 0x2 */ STA_BOMBABLE_RUBBLE,
    /* 0x3 */ STA_UNKNOWN
} ShadowTempleAssetsType;

void BgHakaZou_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaZou_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaZou_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaZou_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgHakaZou_Wait(BgHakaZou* pthis, GlobalContext* globalCtx);
void func_80882BDC(BgHakaZou* pthis, GlobalContext* globalCtx);
void func_80883000(BgHakaZou* pthis, GlobalContext* globalCtx);
void func_80883104(BgHakaZou* pthis, GlobalContext* globalCtx);
void func_80883144(BgHakaZou* pthis, GlobalContext* globalCtx);
void func_80883254(BgHakaZou* pthis, GlobalContext* globalCtx);
void func_80883328(BgHakaZou* pthis, GlobalContext* globalCtx);
void func_808834D8(BgHakaZou* pthis, GlobalContext* globalCtx);
void BgHakaZou_DoNothing(BgHakaZou* pthis, GlobalContext* globalCtx);

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000008, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 5, 60, 0, { 0, 0, 0 } },
};

static Vec3f sZeroVec = { 0.0f, 0.0f, 0.0f };

ActorInit Bg_Haka_Zou_InitVars = {
    ACTOR_BG_HAKA_ZOU,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgHakaZou),
    (ActorFunc)BgHakaZou_Init,
    (ActorFunc)BgHakaZou_Destroy,
    (ActorFunc)BgHakaZou_Update,
    NULL,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32_DIV1000(gravity, -1000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHakaZou_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHakaZou* pthis = (BgHakaZou*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);

    pthis->switchFlag = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;

    if (thisx->params == STA_UNKNOWN) {
        Actor_SetScale(thisx, (Rand_ZeroOne() * 0.005f) + 0.025f);

        thisx->speedXZ = Rand_ZeroOne();
        thisx->world.rot.y = thisx->shape.rot.y * ((Rand_ZeroOne() < 0.5f) ? -1 : 1) + Rand_CenteredFloat(0x1000);
        pthis->timer = 20;
        thisx->world.rot.x = Rand_S16Offset(0x100, 0x300) * ((Rand_ZeroOne() < 0.5f) ? -1 : 1);
        thisx->world.rot.z = Rand_S16Offset(0x400, 0x800) * ((Rand_ZeroOne() < 0.5f) ? -1 : 1);
    } else {
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sCylinderInit);
        Collider_UpdateCylinder(thisx, &pthis->collider);

        DynaPolyActor_Init(&pthis->dyna, 0);

        if (thisx->params == STA_GIANT_BIRD_STATUE) {
            thisx->uncullZoneForward = 2000.0f;
            thisx->uncullZoneScale = 3000.0f;
            thisx->uncullZoneDownward = 3000.0f;
        }
    }

    pthis->requiredObjBankIndex = (thisx->params == STA_BOMBABLE_RUBBLE)
                                     ? Object_GetIndex(&globalCtx->objectCtx, OBJECT_HAKACH_OBJECTS)
                                     : Object_GetIndex(&globalCtx->objectCtx, OBJECT_HAKA_OBJECTS);

    if (pthis->requiredObjBankIndex < 0) {
        Actor_Kill(thisx);
    } else if ((thisx->params != STA_UNKNOWN) && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        if (thisx->params != STA_GIANT_BIRD_STATUE) {
            Actor_Kill(thisx);
        } else {
            thisx->shape.rot.x = -0x4000;
            thisx->world.pos.z -= 80.0f;
            thisx->world.pos.y -= 54.0f;
        }
    }

    pthis->actionFunc = BgHakaZou_Wait;
}

void BgHakaZou_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaZou* pthis = (BgHakaZou*)thisx;

    if (pthis->dyna.actor.params != STA_UNKNOWN) {
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
}

void func_808828F4(BgHakaZou* pthis, GlobalContext* globalCtx) {
    Vec3f effectPos;
    Vec3f effectVelocity;
    f32 rand;
    s32 i;

    effectVelocity.x = 0.0f;
    effectVelocity.y = 1.0f;
    effectVelocity.z = 2.0f;

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            effectPos.x = pthis->dyna.actor.world.pos.x - (Rand_CenteredFloat(10.0f) + 112.0f);
        } else {
            effectPos.x = Rand_CenteredFloat(10.0f) + pthis->dyna.actor.world.pos.x;
        }

        rand = Rand_ZeroOne();
        effectPos.y = pthis->dyna.actor.world.pos.y + (60.0f * rand);
        effectPos.z = pthis->dyna.actor.world.pos.z + (112.0f * rand);

        func_800286CC(globalCtx, &effectPos, &effectVelocity, &sZeroVec, (Rand_ZeroOne() * 200.0f) + 1000.0f, 100);
    }
}

void BgHakaZou_Wait(BgHakaZou* pthis, GlobalContext* globalCtx) {
    CollisionHeader* colHeader;

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->requiredObjBankIndex)) {
        pthis->dyna.actor.objBankIndex = pthis->requiredObjBankIndex;
        pthis->dyna.actor.draw = BgHakaZou_Draw;

        if (pthis->dyna.actor.params == STA_UNKNOWN) {
            pthis->actionFunc = func_80882BDC;
        } else {
            Actor_SetObjectDependency(globalCtx, &pthis->dyna.actor);

            colHeader = NULL;

            if (pthis->dyna.actor.params == STA_GIANT_BIRD_STATUE) {
                CollisionHeader_GetVirtual(&object_haka_objects_Col_006F70, &colHeader);
                pthis->collider.dim.radius = 80;
                pthis->collider.dim.height = 100;
                pthis->collider.dim.yShift = -30;
                pthis->collider.dim.pos.x -= 56;
                pthis->collider.dim.pos.z += 56;
                pthis->dyna.actor.uncullZoneScale = 1500.0f;
            } else if (pthis->dyna.actor.params == STA_BOMBABLE_SKULL_WALL) {
                CollisionHeader_GetVirtual(&object_haka_objects_Col_005E30, &colHeader);
                pthis->collider.dim.yShift = -50;
            } else {
                CollisionHeader_GetVirtual(&gBotwBombSpotCol, &colHeader);
                pthis->collider.dim.radius = 55;
                pthis->collider.dim.height = 20;
            }

            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

            if ((pthis->dyna.actor.params == STA_GIANT_BIRD_STATUE) && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->actionFunc = BgHakaZou_DoNothing;
            } else {
                pthis->actionFunc = func_80883000;
            }
        }
    }
}
void func_80882BDC(BgHakaZou* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->dyna.actor.shape.rot.x += pthis->dyna.actor.world.rot.x;
    pthis->dyna.actor.shape.rot.z += pthis->dyna.actor.world.rot.z;

    if (pthis->dyna.actor.bgCheckFlags & 2) {
        if (pthis->dyna.actor.velocity.y < -8.0f) {
            pthis->dyna.actor.velocity.y *= -0.6f;
            pthis->dyna.actor.velocity.y = CLAMP_MAX(pthis->dyna.actor.velocity.y, 10.0f);
            pthis->dyna.actor.bgCheckFlags &= ~3;
            pthis->dyna.actor.speedXZ = 2.0f;
        } else {
            Actor_Kill(&pthis->dyna.actor);
        }
    }

    if (pthis->timer == 0) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void func_80882CC4(BgHakaZou* pthis, GlobalContext* globalCtx) {
    s32 i;
    s32 j;
    Vec3f actorSpawnPos;
    f32 sin;
    f32 cos;
    s32 pad;

    sin = Math_SinS(pthis->dyna.actor.shape.rot.y - 0x4000) * 40.0f;
    cos = Math_CosS(pthis->dyna.actor.shape.rot.y - 0x4000) * 40.0f;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            actorSpawnPos.x = pthis->dyna.actor.world.pos.x + (j - 1) * sin;
            actorSpawnPos.z = pthis->dyna.actor.world.pos.z + (j - 1) * cos;
            actorSpawnPos.y = pthis->dyna.actor.world.pos.y + (i - 1) * 55;

            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BG_HAKA_ZOU, actorSpawnPos.x, actorSpawnPos.y,
                        actorSpawnPos.z, 0, pthis->dyna.actor.shape.rot.y, 0, pthis->dyna.actor.params + 2);
            func_800286CC(globalCtx, &actorSpawnPos, &sZeroVec, &sZeroVec, 1000, 50);
        }
    }
}

void func_80882E54(BgHakaZou* pthis, GlobalContext* globalCtx) {
    Vec3f fragmentPos;
    s32 i;
    s32 j;
    s32 num = 25;

    fragmentPos.x = pthis->collider.dim.pos.x;
    fragmentPos.y = pthis->collider.dim.pos.y;
    fragmentPos.z = pthis->collider.dim.pos.z;

    EffectSsHahen_SpawnBurst(globalCtx, &fragmentPos, 10.0f, 0, 10, 10, 4, 141, 40, gBotwBombSpotDL);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            fragmentPos.x = pthis->collider.dim.pos.x + (((j * 2) - 1) * num);
            fragmentPos.z = pthis->collider.dim.pos.z + (((i * 2) - 1) * num);
            EffectSsHahen_SpawnBurst(globalCtx, &fragmentPos, 10.0f, 0, 10, 10, 4, 141, 40, gBotwBombSpotDL);
            func_800286CC(globalCtx, &fragmentPos, &sZeroVec, &sZeroVec, 1000, 50);
        }
    }
}

void func_80883000(BgHakaZou* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        Flags_SetSwitch(globalCtx, pthis->switchFlag);

        if (pthis->dyna.actor.params == STA_GIANT_BIRD_STATUE) {
            pthis->timer = 20;
            pthis->actionFunc = func_80883144;
            OnePointCutscene_Init(globalCtx, 3400, 999, &pthis->dyna.actor, MAIN_CAM);
        } else if (pthis->dyna.actor.params == 2) {
            func_80882E54(pthis, globalCtx);
            pthis->dyna.actor.draw = NULL;
            pthis->timer = 1;
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_EXPLOSION);
            pthis->actionFunc = func_80883104;
        } else {
            func_80882CC4(pthis, globalCtx);
            pthis->timer = 1;
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_WALL_BROKEN);
            pthis->actionFunc = func_80883104;
        }
    } else {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void func_80883104(BgHakaZou* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void func_80883144(BgHakaZou* pthis, GlobalContext* globalCtx) {
    Vec3f explosionPos;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (!(pthis->timer % 4)) {
        explosionPos.x = Rand_CenteredFloat(200.0f) + (pthis->dyna.actor.world.pos.x - 56.0f);
        explosionPos.y = (Rand_ZeroOne() * 80.0f) + pthis->dyna.actor.world.pos.y;
        explosionPos.z = Rand_CenteredFloat(200.0f) + (pthis->dyna.actor.world.pos.z + 56.0f);

        EffectSsBomb2_SpawnLayered(globalCtx, &explosionPos, &sZeroVec, &sZeroVec, 150, 70);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_IT_BOMB_EXPLOSION);
    }

    if (pthis->timer == 0) {
        pthis->timer = 20;
        pthis->actionFunc = func_80883254;
    }
}

void func_80883254(BgHakaZou* pthis, GlobalContext* globalCtx) {
    f32 moveDist = (Rand_ZeroOne() * 0.5f) + 0.5f;

    Math_StepToF(&pthis->dyna.actor.world.pos.z, pthis->dyna.actor.home.pos.z - 80.0f, 2.0f * moveDist);

    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y - 40.0f, moveDist)) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer == 0) {
            pthis->timer = 60;
            pthis->dyna.actor.world.rot.x = 8;
            pthis->actionFunc = func_80883328;
        }
    } else {
        func_808828F4(pthis, globalCtx);
    }
}

void func_80883328(BgHakaZou* pthis, GlobalContext* globalCtx) {
    Vec3f effectPos;
    s32 i;
    s32 j;

    pthis->dyna.actor.world.rot.x += pthis->dyna.actor.world.rot.x / 8.0f;

    if (Math_ScaledStepToS(&pthis->dyna.actor.shape.rot.x, -0x4000, pthis->dyna.actor.world.rot.x)) {
        effectPos.x = pthis->dyna.actor.world.pos.x;
        effectPos.y = pthis->dyna.actor.world.pos.y;

        for (j = 0; j < 2; j++) {
            effectPos.z = pthis->dyna.actor.world.pos.z;

            for (i = 0; i < 4; i++) {
                effectPos.z -= (i == 2) ? 550.0f : 50.0f;
                func_800286CC(globalCtx, &effectPos, &sZeroVec, &sZeroVec, (Rand_ZeroOne() * 200.0f) + 1000.0f, 200);
            }

            effectPos.x -= 112.0f;
        }

        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONE_BOUND);
        pthis->timer = 25;
        pthis->actionFunc = func_808834D8;
    }
}

void func_808834D8(BgHakaZou* pthis, GlobalContext* globalCtx) {
    f32 moveDist;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    moveDist = (pthis->timer % 2) ? 15.0f : -15.0f;
    pthis->dyna.actor.world.pos.y += ((pthis->timer & 0xFE) * 0.04f * moveDist);

    if (pthis->timer == 0) {
        pthis->actionFunc = BgHakaZou_DoNothing;
    }
}

void BgHakaZou_DoNothing(BgHakaZou* pthis, GlobalContext* globalCtx) {
}

void BgHakaZou_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaZou* pthis = (BgHakaZou*)thisx;

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->dyna.actor.params == 3) {
        Actor_MoveForward(&pthis->dyna.actor);
    }
}

void BgHakaZou_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Gfx* dLists[] = {
        object_haka_objects_DL_0064E0,
        object_haka_objects_DL_005CE0,
        gBotwBombSpotDL,
        object_haka_objects_DL_005CE0,
    };

    Gfx_DrawDListOpa(globalCtx, dLists[thisx->params]);
}
