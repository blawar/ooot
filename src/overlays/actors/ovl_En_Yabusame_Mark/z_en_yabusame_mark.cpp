#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_YABUSAME_MARK_Z_EN_YABUSAME_MARK_C
#include "actor_common.h"
/*
 * File: z_en_yabusame_mark.c
 * Overlay: ovl_En_Yabusame_Mark
 * Description: Horseback Archery Target (arrow hitbox)
 */

#include "z_en_yabusame_mark.h"
#include "vt.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"

#define FLAGS 0

void EnYabusameMark_Init(Actor* thisx, GlobalContext* globalCtx);
void EnYabusameMark_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnYabusameMark_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnYabusameMark_Update(Actor* thisx, GlobalContext* globalCtx);
void func_80B42F74(EnYabusameMark* pthis, GlobalContext* globalCtx);

static ColliderQuadInit sQuadInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x0001F824, 0x00, 0x00 },
        TOUCH_NONE | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

ActorInit En_Yabusame_Mark_InitVars = {
    ACTOR_EN_YABUSAME_MARK,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnYabusameMark),
    (ActorFunc)EnYabusameMark_Init,
    (ActorFunc)EnYabusameMark_Destroy,
    (ActorFunc)EnYabusameMark_Update,
    NULL,
    (ActorFunc)EnYabusameMark_Reset,
};

static Vec3f sCollisionVertices[] = {
    { 70.0f, 70.0f, 0.0f },      { 70.0f, -70.0f, 0.0f },      { -70.0f, 70.0f, 0.0f },    { -70.0f, -70.0f, 0.0f },
    { 90.0f, 130.0f, -120.0f },  { -25.0f, -80.0f, -130.0f },  { 90.0f, 130.0f, 120.0f },  { -25.0f, -80.0, 130.0f },
    { 115.0f, 160.0f, -150.0f }, { -50.0f, -140.0f, -160.0f }, { 115.0f, 160.0f, 150.0f }, { -50.0f, -140.0f, 160.0f },
};

static Vec3f sTargetPos[] = {
    { 3382.0f, 1734.0f, -4946.0f }, // small, furthest from entrance
    { 3360.0f, 1734.0f, 495.0f },   // small, closest to entrance
    { 4517.0f, 1682.0f, -1779.0f }, // medium, on the right
    { 4517.0f, 1682.0f, -2813.0f }, // medium, on the left
    { 4522.0f, 1727.0f, -2296.0f }, // large in the center
};

// 0: first ring
// 1: second ring
// 2: outside edge
static f32 sRingDistance[] = {
    20.0f, 40.0f,  60.0f,  777.0f, // small
    40.0f, 80.0f,  120.0f, 777.0f, // medium
    40.0f, 120.0f, 160.0f, 777.0f, // large
};

void EnYabusameMark_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnYabusameMark* pthis = (EnYabusameMark*)thisx;

    Collider_DestroyQuad(globalCtx, &pthis->collider);
}

void EnYabusameMark_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnYabusameMark* pthis = (EnYabusameMark*)thisx;

    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ やぶさめまと ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.params);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->typeIndex = pthis->actor.params;
    pthis->actor.targetMode = 5;
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 種類インデックス \t   ☆☆☆☆☆ %d\n" VT_RST, pthis->typeIndex);
    switch (pthis->typeIndex) {
        case 0:
            pthis->subTypeIndex = 0;
            if (pthis->actor.world.pos.z > 0.0f) {
                pthis->subTypeIndex = 1;
            }
            break;
        case 1:
            pthis->subTypeIndex = 2;
            if (pthis->actor.world.pos.z < -2000.0f) {
                pthis->subTypeIndex = 3;
            }
            break;
        case 2:
            pthis->subTypeIndex = 4;
            break;
    }
    Collider_InitQuad(globalCtx, &pthis->collider);
    Collider_SetQuad(globalCtx, &pthis->collider, &pthis->actor, &sQuadInit);
    pthis->worldPos = pthis->actor.world.pos;
    pthis->actor.flags |= ACTOR_FLAG_4;
    if (gSaveContext.sceneSetupIndex != 4) {
        Actor_Kill(&pthis->actor);
        return;
    }
    osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 種類       ☆☆☆☆☆ %d\n" VT_RST, pthis->typeIndex);
    osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ さらに分類 ☆☆☆☆☆ %d\n" VT_RST, pthis->subTypeIndex);
    pthis->actionFunc = func_80B42F74;
}

void func_80B42F74(EnYabusameMark* pthis, GlobalContext* globalCtx) {
    Vec3f effectAccel = { 0.0f, 0.0f, 0.0f };
    Vec3f effectVelocity = { 0.0f, 0.0f, 0.0f };
    Vec3f arrowHitPos;
    Vec3f distanceFromCenter;
    s32 pad;
    s32 scoreIndex;
    f32 scoreDistance100;
    f32 scoreDistance60;
    f32 scoreDistance30;

    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;

        arrowHitPos.x = pthis->collider.info.bumper.hitPos.x;
        arrowHitPos.y = pthis->collider.info.bumper.hitPos.y;
        arrowHitPos.z = pthis->collider.info.bumper.hitPos.z;

        effectVelocity.y = 15.0f;

        EffectSsHitMark_SpawnCustomScale(globalCtx, 0, 700, &arrowHitPos);

        scoreIndex = 2;

        scoreDistance100 = sRingDistance[pthis->typeIndex * 4 + 0];
        scoreDistance60 = sRingDistance[pthis->typeIndex * 4 + 1];
        scoreDistance30 = sRingDistance[pthis->typeIndex * 4 + 2];

        distanceFromCenter.x = fabsf(sTargetPos[pthis->subTypeIndex].x - arrowHitPos.x);
        distanceFromCenter.y = fabsf(sTargetPos[pthis->subTypeIndex].y - arrowHitPos.y);
        distanceFromCenter.z = fabsf(sTargetPos[pthis->subTypeIndex].z - arrowHitPos.z);

        if (distanceFromCenter.x > scoreDistance100 || distanceFromCenter.y > scoreDistance100 ||
            distanceFromCenter.z > scoreDistance100) {
            scoreIndex = 1;
            if (distanceFromCenter.x > scoreDistance60 || distanceFromCenter.y > scoreDistance60 ||
                distanceFromCenter.z > scoreDistance60) {
                scoreIndex = 0;
            }
            if (distanceFromCenter.x > scoreDistance30 || distanceFromCenter.y > scoreDistance30 ||
                distanceFromCenter.z > scoreDistance30) {
                return;
            }
        }

        osSyncPrintf("\n\n");
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ posＸ ☆☆☆☆☆ %f\n" VT_RST, arrowHitPos.x);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ posＹ ☆☆☆☆☆ %f\n" VT_RST, arrowHitPos.y);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ posＺ ☆☆☆☆☆ %f\n" VT_RST, arrowHitPos.z);
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ hitＸ ☆☆☆☆☆ %f\n" VT_RST, sTargetPos[pthis->subTypeIndex].x);
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ hitＹ ☆☆☆☆☆ %f\n" VT_RST, sTargetPos[pthis->subTypeIndex].y);
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ hitＺ ☆☆☆☆☆ %f\n" VT_RST, sTargetPos[pthis->subTypeIndex].z);
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 小    ☆☆☆☆☆ %f\n" VT_RST, scoreDistance100);
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 大    ☆☆☆☆☆ %f\n" VT_RST, scoreDistance60);
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ point ☆☆☆☆☆ %d\n" VT_RST, scoreIndex);
        osSyncPrintf("\n\n");

        if (scoreIndex == 2) {
            Audio_PlayFanfare(NA_BGM_ITEM_GET | 0x900);
        }
        if (scoreIndex == 1) {
            Audio_StopSfxById(NA_SE_SY_TRE_BOX_APPEAR);
            Common_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
        }
        if (scoreIndex == 0) {
            Common_PlaySfx(NA_SE_SY_DECIDE);
        }
        EffectSsExtra_Spawn(globalCtx, &arrowHitPos, &effectVelocity, &effectAccel, 5, scoreIndex);
    }
}

void EnYabusameMark_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnYabusameMark* pthis = (EnYabusameMark*)thisx;
    Vec3f* vertexArray;
    u32 arrayIndex;

    pthis->actionFunc(pthis, globalCtx);
    arrayIndex = pthis->typeIndex * 4;
    vertexArray = &sCollisionVertices[arrayIndex];

    pthis->vertexA.x = vertexArray[0].x + pthis->actor.world.pos.x;
    pthis->vertexA.y = vertexArray[0].y + pthis->actor.world.pos.y;
    pthis->vertexA.z = vertexArray[0].z + pthis->actor.world.pos.z;

    pthis->vertexB.x = vertexArray[1].x + pthis->actor.world.pos.x;
    pthis->vertexB.y = vertexArray[1].y + pthis->actor.world.pos.y;
    pthis->vertexB.z = vertexArray[1].z + pthis->actor.world.pos.z;

    pthis->vertexC.x = vertexArray[2].x + pthis->actor.world.pos.x;
    pthis->vertexC.y = vertexArray[2].y + pthis->actor.world.pos.y;
    pthis->vertexC.z = vertexArray[2].z + pthis->actor.world.pos.z;

    pthis->vertexD.x = vertexArray[3].x + pthis->actor.world.pos.x;
    pthis->vertexD.y = vertexArray[3].y + pthis->actor.world.pos.y;
    pthis->vertexD.z = vertexArray[3].z + pthis->actor.world.pos.z;

    Collider_SetQuadVertices(&pthis->collider, &pthis->vertexA, &pthis->vertexB, &pthis->vertexC, &pthis->vertexD);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnYabusameMark_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sQuadInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_QUAD,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x0001F824, 0x00, 0x00 },
            TOUCH_NONE | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
    };

    En_Yabusame_Mark_InitVars = {
        ACTOR_EN_YABUSAME_MARK,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnYabusameMark),
        (ActorFunc)EnYabusameMark_Init,
        (ActorFunc)EnYabusameMark_Destroy,
        (ActorFunc)EnYabusameMark_Update,
        NULL,
        (ActorFunc)EnYabusameMark_Reset,
    };

}
