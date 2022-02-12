#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SI_Z_EN_SI_C
#include "actor_common.h"
/*
 * File: z_en_si.c
 * Overlay: En_Si
 * Description: Gold Skulltula token
 */

#include "z_en_si.h"
#include "def/code_800EC960.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_draw.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_player_lib.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_9)

void EnSi_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSi_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSi_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSi_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 func_80AFB748(EnSi* pthis, GlobalContext* globalCtx);
void func_80AFB768(EnSi* pthis, GlobalContext* globalCtx);
void func_80AFB89C(EnSi* pthis, GlobalContext* globalCtx);
void func_80AFB950(EnSi* pthis, GlobalContext* globalCtx);

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_NO_PUSH | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000090, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 20, 18, 2, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 D_80AFBADC = { 0, 0, 0, 0, MASS_IMMOVABLE };

ActorInit En_Si_InitVars = {
    ACTOR_EN_SI,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_ST,
    sizeof(EnSi),
    (ActorFunc)EnSi_Init,
    (ActorFunc)EnSi_Destroy,
    (ActorFunc)EnSi_Update,
    (ActorFunc)EnSi_Draw,
};

void EnSi_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnSi* pthis = (EnSi*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, NULL, &D_80AFBADC);
    Actor_SetScale(&pthis->actor, 0.025f);
    pthis->unk_19C = 0;
    pthis->actionFunc = func_80AFB768;
    pthis->actor.shape.yOffset = 42.0f;
}

void EnSi_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnSi* pthis = (EnSi*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 func_80AFB748(EnSi* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
    }
    return 0;
}

void func_80AFB768(EnSi* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_13)) {
        pthis->actionFunc = func_80AFB89C;
    } else {
        Math_SmoothStepToF(&pthis->actor.scale.x, 0.25f, 0.4f, 1.0f, 0.0f);
        Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
        pthis->actor.shape.rot.y += 0x400;

        if (!Player_InCsMode(globalCtx)) {
            func_80AFB748(pthis, globalCtx);

            if (pthis->collider.base.ocFlags2 & OC2_HIT_PLAYER) {
                pthis->collider.base.ocFlags2 &= ~OC2_HIT_PLAYER;
                Item_Give(globalCtx, ITEM_SKULL_TOKEN);
                player->actor.freezeTimer = 10;
                Message_StartTextbox(globalCtx, 0xB4, NULL);
                Audio_PlayFanfare(NA_BGM_SMALL_ITEM_GET);
                pthis->actionFunc = func_80AFB950;
            } else {
                Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }
        }
    }
}

void func_80AFB89C(EnSi* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToF(&pthis->actor.scale.x, 0.25f, 0.4f, 1.0f, 0.0f);
    Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
    pthis->actor.shape.rot.y += 0x400;

    if (!CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_13)) {
        Item_Give(globalCtx, ITEM_SKULL_TOKEN);
        player->actor.freezeTimer = 10;
        Message_StartTextbox(globalCtx, 0xB4, NULL);
        Audio_PlayFanfare(NA_BGM_SMALL_ITEM_GET);
        pthis->actionFunc = func_80AFB950;
    }
}

void func_80AFB950(EnSi* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (Message_GetState(&globalCtx->msgCtx) != TEXT_STATE_CLOSING) {
        player->actor.freezeTimer = 10;
    } else {
        SET_GS_FLAGS((pthis->actor.params & 0x1F00) >> 8, pthis->actor.params & 0xFF);
        Actor_Kill(&pthis->actor);
    }
}

void EnSi_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnSi* pthis = (EnSi*)thisx;

    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    pthis->actionFunc(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, 16.0f);
}

void EnSi_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnSi* pthis = (EnSi*)thisx;

    if (pthis->actionFunc != func_80AFB950) {
        func_8002ED80(&pthis->actor, globalCtx, 0);
        func_8002EBCC(&pthis->actor, globalCtx, 0);
        GetItem_Draw(globalCtx, GID_SKULL_TOKEN_2);
    }
}
