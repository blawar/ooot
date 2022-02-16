#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_KAKASI2_Z_EN_KAKASI2_C
#include "actor_common.h"
/*
 * File: z_en_kakasi2.c
 * Overlay: ovl_En_Kakasi2
 * Description: Pierre the Scarecrow Spawn
 */

#include "z_en_kakasi2.h"
#include "vt.h"
#include "objects/object_ka/object_ka.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_25 | ACTOR_FLAG_27)

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 20, 70, 0, { 0, 0, 0 } },
};

void EnKakasi2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKakasi2_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnKakasi2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKakasi2_Update(Actor* thisx, GlobalContext* globalCtx);
void func_80A90948(Actor* thisx, GlobalContext* globalCtx);

void func_80A9062C(EnKakasi2* pthis, GlobalContext* globalCtx);
void func_80A90264(EnKakasi2* pthis, GlobalContext* globalCtx);
void func_80A904D8(EnKakasi2* pthis, GlobalContext* globalCtx);
void func_80A90578(EnKakasi2* pthis, GlobalContext* globalCtx);
void func_80A906C4(EnKakasi2* pthis, GlobalContext* globalCtx);

ActorInit En_Kakasi2_InitVars = {
    ACTOR_EN_KAKASI2,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_KA,
    sizeof(EnKakasi2),
    (ActorFunc)EnKakasi2_Init,
    (ActorFunc)EnKakasi2_Destroy,
    (ActorFunc)EnKakasi2_Update,
    NULL,
    (ActorFunc)EnKakasi2_Reset,
};

void EnKakasi2_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi2* pthis = (EnKakasi2*)thisx;
    s32 pad;
    f32 spawnRangeY;
    f32 spawnRangeXZ;

    osSyncPrintf("\n\n");
    // "Visit Umeda"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 梅田参号見参！ ☆☆☆☆☆ \n" VT_RST);

    pthis->switchFlag = pthis->actor.params & 0x3F;
    spawnRangeY = (pthis->actor.params >> 6) & 0xFF;
    spawnRangeXZ = pthis->actor.world.rot.z;
    if (pthis->switchFlag == 0x3F) {
        pthis->switchFlag = -1;
    }
    pthis->actor.targetMode = 4;
    pthis->maxSpawnDistance.x = (spawnRangeY * 40.0f) + 40.0f;
    pthis->maxSpawnDistance.y = (spawnRangeXZ * 40.0f) + 40.0f;

    // "Former? (Argument 0)"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 元？(引数０) ☆☆☆☆ %f\n" VT_RST, spawnRangeY);
    // "Former? (Z angle)"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 元？(Ｚアングル) ☆☆ %f\n" VT_RST, spawnRangeXZ);
    // "Correction coordinates X"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 補正座標Ｘ ☆☆☆☆☆ %f\n" VT_RST, pthis->maxSpawnDistance.x);
    // "Correction coordinates Y"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 補正座標Ｙ ☆☆☆☆☆ %f\n" VT_RST, pthis->maxSpawnDistance.y);
    // "Correction coordinates Z"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 補正座標Ｚ ☆☆☆☆☆ %f\n" VT_RST, pthis->maxSpawnDistance.z);
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ SAVE       ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
    osSyncPrintf("\n\n");

    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->height = 60.0f;
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.flags |= ACTOR_FLAG_10;
    pthis->unk_198 = pthis->actor.shape.rot.y;

    if (pthis->switchFlag >= 0 && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        pthis->actor.draw = func_80A90948;
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_ka_Skel_0065B0, &object_ka_Anim_000214, NULL, NULL, 0);
        pthis->actionFunc = func_80A9062C;
    } else {
        pthis->actionFunc = func_80A90264;
        pthis->actor.shape.yOffset = -8000.0f;
    }
}

void EnKakasi2_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi2* pthis = (EnKakasi2*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
    //! @bug SkelAnime_Free is not called
}

void func_80A90264(EnKakasi2* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_194++;

    if ((BREG(1) != 0) && (pthis->actor.xzDistToPlayer < pthis->maxSpawnDistance.x) &&
        (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < pthis->maxSpawnDistance.y)) {

        pthis->actor.draw = func_80A90948;
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_ka_Skel_0065B0, &object_ka_Anim_000214, NULL, NULL, 0);
        OnePointCutscene_Attention(globalCtx, &pthis->actor);
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_27;

        func_80078884(NA_SE_SY_CORRECT_CHIME);
        if (pthis->switchFlag >= 0) {
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
        }

        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ SAVE 終了 ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
        pthis->actionFunc = func_80A904D8;
    } else if ((pthis->actor.xzDistToPlayer < pthis->maxSpawnDistance.x) &&
               (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < pthis->maxSpawnDistance.y) &&
               (gSaveContext.eventChkInf[9] & 0x1000)) {

        pthis->unk_194 = 0;
        if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_0B) {
            if (pthis->switchFlag >= 0) {
                Flags_SetSwitch(globalCtx, pthis->switchFlag);
            }
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ SAVE 終了 ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
            globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
            pthis->actor.draw = func_80A90948;
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_ka_Skel_0065B0, &object_ka_Anim_000214, NULL, NULL,
                               0);
            OnePointCutscene_Attention(globalCtx, &pthis->actor);
            func_80078884(NA_SE_SY_CORRECT_CHIME);

            pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_27;
            pthis->actionFunc = func_80A904D8;
        }
    }
}

void func_80A904D8(EnKakasi2* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&object_ka_Anim_000214);

    Animation_Change(&pthis->skelAnime, &object_ka_Anim_000214, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_COME_UP_DEKU_JR);
    pthis->actionFunc = func_80A90578;
}

void func_80A90578(EnKakasi2* pthis, GlobalContext* globalCtx) {
    s16 currentFrame;

    SkelAnime_Update(&pthis->skelAnime);

    currentFrame = pthis->skelAnime.curFrame;
    if (currentFrame == 11 || currentFrame == 17) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_KAKASHI_SWING);
    }

    pthis->actor.shape.rot.y += 0x800;
    Math_ApproachZeroF(&pthis->actor.shape.yOffset, 0.5f, 500.0f);

    if (pthis->actor.shape.yOffset > -100.0f) {
        pthis->actionFunc = func_80A9062C;
        pthis->actor.shape.yOffset = 0.0f;
    }
}

void func_80A9062C(EnKakasi2* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&object_ka_Anim_000214);

    Animation_Change(&pthis->skelAnime, &object_ka_Anim_000214, 0.0f, 0.0f, (s16)frameCount, ANIMMODE_ONCE, -10.0f);
    pthis->actionFunc = func_80A906C4;
}

void func_80A906C4(EnKakasi2* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.curFrame != 0) {
        Math_ApproachZeroF(&pthis->skelAnime.curFrame, 0.5f, 1.0f);
    }
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->unk_198, 5, 0xBB8, 0);
    SkelAnime_Update(&pthis->skelAnime);
}

void EnKakasi2_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnKakasi2* pthis = (EnKakasi2*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    pthis->actor.world.rot = pthis->actor.shape.rot;
    Actor_SetFocus(&pthis->actor, pthis->height);
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);

    if (pthis->actor.shape.yOffset == 0.0f) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void func_80A90948(Actor* thisx, GlobalContext* globalCtx) {
    EnKakasi2* pthis = (EnKakasi2*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, pthis);
}

void EnKakasi2_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 20, 70, 0, { 0, 0, 0 } },
    };

    En_Kakasi2_InitVars = {
        ACTOR_EN_KAKASI2,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_KA,
        sizeof(EnKakasi2),
        (ActorFunc)EnKakasi2_Init,
        (ActorFunc)EnKakasi2_Destroy,
        (ActorFunc)EnKakasi2_Update,
        NULL,
        (ActorFunc)EnKakasi2_Reset,
    };

}
