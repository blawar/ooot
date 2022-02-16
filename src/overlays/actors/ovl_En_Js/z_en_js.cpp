#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_JS_Z_EN_JS_C
#include "actor_common.h"
/*
 * File: z_en_js.c
 * Overlay: ovl_En_Js
 * Description: Magic Carpet Salesman
 */

#include "z_en_js.h"
#include "objects/object_js/object_js.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnJs_Init(Actor* thisx, GlobalContext* globalCtx);
void EnJs_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnJs_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnJs_Update(Actor* thisx, GlobalContext* globalCtx);
void EnJs_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A89304(EnJs* pthis, GlobalContext* globalCtx);

static Vec3f D_80A896DC_39 = { 0.0f, 0.0f, 0.0f };


ActorInit En_Js_InitVars = {
    ACTOR_EN_JS,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_JS,
    sizeof(EnJs),
    (ActorFunc)EnJs_Init,
    (ActorFunc)EnJs_Destroy,
    (ActorFunc)EnJs_Update,
    (ActorFunc)EnJs_Draw,
    (ActorFunc)EnJs_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_ENEMY,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 30, 40, 0, { 0, 0, 0 } },
};

void En_Js_SetupAction(EnJs* pthis, EnJsActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnJs_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnJs* pthis = (EnJs*)thisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0.0f, NULL, 36.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gCarpetMerchantSkel, &gCarpetMerchantSlappingKneeAnim,
                       pthis->jointTable, pthis->morphTable, 13);
    Animation_PlayOnce(&pthis->skelAnime, &gCarpetMerchantSlappingKneeAnim);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    Actor_SetScale(&pthis->actor, 0.01f);
    En_Js_SetupAction(pthis, func_80A89304);
    pthis->unk_284 = 0;
    pthis->actor.gravity = -1.0f;
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_JSJUTAN, pthis->actor.world.pos.x,
                       pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0);
}

void EnJs_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnJs* pthis = (EnJs*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

u8 func_80A88F64(EnJs* pthis, GlobalContext* globalCtx, u16 textId) {
    s16 yawDiff;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        return 1;
    } else {
        pthis->actor.textId = textId;
        yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

        if (ABS(yawDiff) <= 0x1800 && pthis->actor.xzDistToPlayer < 100.0f) {
            pthis->unk_284 |= 1;
            func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
        }
        return 0;
    }
}

void func_80A89008(EnJs* pthis) {
    En_Js_SetupAction(pthis, func_80A89304);
    Animation_Change(&pthis->skelAnime, &gCarpetMerchantSlappingKneeAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gCarpetMerchantSlappingKneeAnim), ANIMMODE_ONCE, -4.0f);
}

void func_80A89078(EnJs* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        func_80A89008(pthis);
        pthis->actor.flags &= ~ACTOR_FLAG_16;
    }
}

void func_80A890C0(EnJs* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        En_Js_SetupAction(pthis, func_80A89078);
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, 1000.0f);
    }
}

void func_80A8910C(EnJs* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actor.textId = 0x6078;
        En_Js_SetupAction(pthis, func_80A890C0);
        pthis->actor.flags |= ACTOR_FLAG_16;
    }
}

void func_80A89160(EnJs* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        En_Js_SetupAction(pthis, func_80A8910C);
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_BOMBCHUS_10, 10000.0f, 50.0f);
    }
}

void func_80A891C4(EnJs* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // yes
                if (gSaveContext.rupees < 200) {
                    Message_ContinueTextbox(globalCtx, 0x6075);
                    func_80A89008(pthis);
                } else {
                    Rupees_ChangeBy(-200);
                    En_Js_SetupAction(pthis, func_80A89160);
                }
                break;
            case 1: // no
                Message_ContinueTextbox(globalCtx, 0x6074);
                func_80A89008(pthis);
        }
    }
}

void func_80A89294(EnJs* pthis) {
    En_Js_SetupAction(pthis, func_80A891C4);
    Animation_Change(&pthis->skelAnime, &gCarpetMerchantIdleAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gCarpetMerchantIdleAnim), ANIMMODE_ONCE, -4.0f);
}

void func_80A89304(EnJs* pthis, GlobalContext* globalCtx) {
    if (func_80A88F64(pthis, globalCtx, 0x6077)) {
        func_80A89294(pthis);
    }
}

void EnJs_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnJs* pthis = (EnJs*)thisx;
    s32 pad;
    s32 pad2;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);

    if (pthis->actor.bgCheckFlags & 1) {
        if (SurfaceType_GetSfx(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId) == 1) {
            Math_ApproachF(&pthis->actor.shape.yOffset, sREG(80) + -2000.0f, 1.0f, (sREG(81) / 10.0f) + 50.0f);
        }
    } else {
        Math_ApproachZeroF(&pthis->actor.shape.yOffset, 1.0f, (sREG(81) / 10.0f) + 50.0f);
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->skelAnime.curFrame = 0.0f;
    }
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->unk_284 & 1) {
        func_80038290(globalCtx, &pthis->actor, &pthis->unk_278, &pthis->unk_27E, pthis->actor.focus.pos);
    } else {
        Math_SmoothStepToS(&pthis->unk_278.x, 0, 6, 0x1838, 0x64);
        Math_SmoothStepToS(&pthis->unk_278.y, 0, 6, 0x1838, 0x64);
        Math_SmoothStepToS(&pthis->unk_27E.x, 0, 6, 0x1838, 0x64);
        Math_SmoothStepToS(&pthis->unk_27E.y, 0, 6, 0x1838, 0x64);
    }
    pthis->unk_284 &= ~0x1;

    if (DECR(pthis->unk_288) == 0) {
        pthis->unk_288 = Rand_S16Offset(0x3C, 0x3C);
    }

    pthis->unk_286 = pthis->unk_288;

    if (pthis->unk_286 >= 3) {
        pthis->unk_286 = 0;
    }
}

s32 EnJs_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnJs* pthis = (EnJs*)thisx;

    if (limbIndex == 12) {
        rot->y -= pthis->unk_278.y;
    }
    return false;
}

void EnJs_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnJs* pthis = (EnJs*)thisx;

    if (limbIndex == 12) {
        Matrix_MultVec3f(&D_80A896DC_39, &pthis->actor.focus.pos);
    }
}
void EnJs_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnJs* pthis = (EnJs*)thisx;

    func_800943C8(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnJs_OverrideLimbDraw, EnJs_PostLimbDraw, pthis);
}

void EnJs_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    D_80A896DC_39 = { 0.0f, 0.0f, 0.0f };

    En_Js_InitVars = {
        ACTOR_EN_JS,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_JS,
        sizeof(EnJs),
        (ActorFunc)EnJs_Init,
        (ActorFunc)EnJs_Destroy,
        (ActorFunc)EnJs_Update,
        (ActorFunc)EnJs_Draw,
        (ActorFunc)EnJs_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_ENEMY,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 30, 40, 0, { 0, 0, 0 } },
    };

}
