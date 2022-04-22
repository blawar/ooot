#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BIRD_Z_EN_BIRD_C
#include "actor_common.h"
/*
 * File: z_en_bird.c
 * Overlay: ovl_En_Bird
 * Description: An unused brown bird
 */

#include "z_en_bird.h"
#include "objects/object_bird/object_bird.h"
#include "def/sinf.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_skelanime.h"

#define FLAGS 0

void EnBird_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBird_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBird_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBird_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBird_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809C1E00(EnBird* pthis, s16 params);
void func_809C1E40(EnBird* pthis, GlobalContext* globalCtx);
void func_809C1D60(EnBird* pthis, GlobalContext* globalCtx);
void func_809C1CAC(EnBird* pthis, s16 params);

ActorInit En_Bird_InitVars = {
    ACTOR_EN_BIRD,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_BIRD,
    sizeof(EnBird),
    (ActorFunc)EnBird_Init,
    (ActorFunc)EnBird_Destroy,
    (ActorFunc)EnBird_Update,
    (ActorFunc)EnBird_Draw,
    (ActorFunc)EnBird_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 5600, ICHAIN_STOP),
};

void EnBird_SetupAction(EnBird* pthis, EnBirdActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnBird_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnBird* pthis = (EnBird*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Actor_SetScale(&pthis->actor, 0.01);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gBirdSkel, &gBirdFlyAnim, NULL, NULL, 0);
    ActorShape_Init(&pthis->actor.shape, 5500, ActorShadow_DrawCircle, 4);
    pthis->unk_194 = 0;
    pthis->unk_198 = 0;
    pthis->unk_1C0 = 0x9C4;
    pthis->actor.colChkInfo.mass = 0;
    pthis->unk_1A8 = 1.5f;
    pthis->unk_1AC = 0.5f;
    pthis->unk_1A0 = 0.0f;
    pthis->unk_1A4 = 0.0f;
    pthis->unk_1B8 = 0.0f;
    pthis->unk_1B0 = 40.0f;
    pthis->unk_1BC = 70.0f;
    func_809C1CAC(pthis, pthis->actor.params);
}

void EnBird_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void func_809C1CAC(EnBird* pthis, s16 params) {
    f32 frameCount = Animation_GetLastFrame(&gBirdFlyAnim);
    f32 playbackSpeed = pthis->unk_19C ? 0.0f : 1.0f;
    AnimationHeader* anim = &gBirdFlyAnim;

    pthis->unk_198 = Rand_S16Offset(5, 0x23);
    Animation_Change(&pthis->skelAnime, anim, playbackSpeed, 0.0f, frameCount, ANIMMODE_LOOP, 0.0f);
    EnBird_SetupAction(pthis, func_809C1D60);
}

void func_809C1D60(EnBird* pthis, GlobalContext* globalCtx) {
    f32 fVar2 = sinf(pthis->unk_1B4);

    pthis->actor.shape.yOffset = pthis->actor.shape.yOffset + fVar2 * pthis->unk_1A0;
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.1f, 0.5f, 0.0f);

    if (pthis->unk_19C != 0) {
        pthis->skelAnime.playSpeed = pthis->actor.speedXZ + pthis->actor.speedXZ;
    }

    SkelAnime_Update(&pthis->skelAnime);
    pthis->unk_198 -= 1;

    if (pthis->unk_198 <= 0) {
        func_809C1E00(pthis, pthis->actor.params);
    }
}

void func_809C1E00(EnBird* pthis, s16 params) {
    pthis->unk_198 = Rand_S16Offset(0x14, 0x2D);
    EnBird_SetupAction(pthis, func_809C1E40);
}

void func_809C1E40(EnBird* pthis, GlobalContext* globalCtx) {
    f32 fVar4 = sinf(pthis->unk_1B4);

    pthis->actor.shape.yOffset += fVar4 * pthis->unk_1A0;
    Math_SmoothStepToF(&pthis->actor.speedXZ, pthis->unk_1A8, 0.1f, pthis->unk_1AC, 0.0f);

    if (pthis->unk_1B0 < Math_Vec3f_DistXZ(&pthis->actor.world.pos, &pthis->actor.home.pos) || pthis->unk_198 < 4) {
        Math_StepToAngleS(&pthis->actor.world.rot.y, Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos),
                          pthis->unk_1C0);
    } else {
        fVar4 = sinf(pthis->unk_1B4);
        pthis->actor.world.rot.y += (s16)(fVar4 * pthis->unk_1A4);
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    SkelAnime_Update(&pthis->skelAnime);
    pthis->unk_198 -= 1;
    if (pthis->unk_198 < 0) {
        func_809C1CAC(pthis, pthis->actor.params);
    }
}

void EnBird_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnBird* pthis = (EnBird*)thisx;

    pthis->unk_1B4 += pthis->unk_1B8;
    pthis->actionFunc(pthis, globalCtx);
}

void EnBird_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnBird* pthis = (EnBird*)thisx;

    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL, NULL, NULL);
}

void EnBird_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Bird_InitVars = {
        ACTOR_EN_BIRD,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_BIRD,
        sizeof(EnBird),
        (ActorFunc)EnBird_Init,
        (ActorFunc)EnBird_Destroy,
        (ActorFunc)EnBird_Update,
        (ActorFunc)EnBird_Draw,
        (ActorFunc)EnBird_Reset,
    };

}
