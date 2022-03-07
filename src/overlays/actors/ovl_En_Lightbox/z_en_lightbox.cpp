#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_LIGHTBOX_Z_EN_LIGHTBOX_C
#include "actor_common.h"
/*
 * File: z_en_lightbox.c
 * Overlay: ovl_En_Lightbox
 * Description:
 */

#include "z_en_lightbox.h"
#include "objects/object_lightbox/object_lightbox.h"
#include "def/audio_bank.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_4

void EnLightbox_Init(Actor* thisx, GlobalContext* globalCtx);
void EnLightbox_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnLightbox_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnLightbox_Update(Actor* thisx, GlobalContext* globalCtx);
void EnLightbox_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Lightbox_InitVars = {
    ACTOR_EN_LIGHTBOX,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_LIGHTBOX,
    sizeof(EnLightbox),
    (ActorFunc)EnLightbox_Init,
    (ActorFunc)EnLightbox_Destroy,
    (ActorFunc)EnLightbox_Update,
    (ActorFunc)EnLightbox_Draw,
    (ActorFunc)EnLightbox_Reset,
};

void EnLightbox_Init(Actor* thisx, GlobalContext* globalCtx) {
    CollisionHeader* colHeader = NULL;
    EnLightbox* pthis = (EnLightbox*)thisx;
    s32 pad[4];

    switch (thisx->params) {
        case 0:
            Actor_SetScale(thisx, 0.025f);
            break;
        case 1:
            Actor_SetScale(thisx, 0.05f);
            break;
        case 2:
            Actor_SetScale(thisx, 0.075f);
            break;
        case 3:
            Actor_SetScale(thisx, 0.1f);
        default:
            break;
    }

    thisx->focus.pos = thisx->world.pos;
    thisx->colChkInfo.cylRadius = 30;
    thisx->colChkInfo.cylHeight = 50;
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 6.0f);
    pthis->dyna.unk_160 = 0;
    pthis->dyna.unk_15C = 0;
    thisx->targetMode = 0;
    thisx->gravity = -2.0f;
    CollisionHeader_GetVirtual(&object_lightbox_Col_001F10, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
}

void EnLightbox_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnLightbox* pthis = (EnLightbox*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void EnLightbox_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnLightbox* pthis = (EnLightbox*)thisx;

    if (pthis->dyna.unk_162 != 0) {
        if (Actor_HasNoParent(thisx, globalCtx)) {
            pthis->dyna.unk_162 = 0;
        }
    } else {
        if (Actor_HasParent(thisx, globalCtx)) {
            pthis->dyna.unk_162++;
        } else {
            if (thisx->speedXZ) {
                if (thisx->bgCheckFlags & 8) {
                    thisx->world.rot.y = (thisx->world.rot.y + thisx->wallYaw) - thisx->world.rot.y;
                    Audio_PlaySoundGeneral(NA_SE_EV_BOMB_BOUND, &thisx->projectedPos, 4, &D_801333E0, &D_801333E0,
                                           &gReverbAdd2);
                    thisx->speedXZ *= 0.7f;
                    thisx->bgCheckFlags &= ~0x8;
                }
            }

            if ((thisx->bgCheckFlags & 1) == 0) {
                Math_StepToF(&thisx->speedXZ, 0, IREG(57) / 100.0f);
            } else {
                Math_StepToF(&thisx->speedXZ, 0, IREG(58) / 100.0f);
                if ((thisx->bgCheckFlags & 2) && (thisx->velocity.y < IREG(59) / 100.0f)) {
                    Audio_PlaySoundGeneral(NA_SE_EV_BOMB_BOUND, &thisx->projectedPos, 4, &D_801333E0, &D_801333E0,
                                           &gReverbAdd2);
                    thisx->velocity.y *= IREG(60) / 100.0f;
                    thisx->bgCheckFlags &= ~0x1;
                } else {
                    func_8002F580(thisx, globalCtx);
                }
            }
        }
    }
    Actor_MoveForward(thisx);
    Actor_UpdateBgCheckInfo(globalCtx, thisx, thisx->colChkInfo.cylHeight, thisx->colChkInfo.cylRadius,
                            thisx->colChkInfo.cylRadius, 0x1D);
    thisx->focus.pos = thisx->world.pos;
}

void EnLightbox_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, object_lightbox_DL_000B70);
}

void EnLightbox_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Lightbox_InitVars = {
        ACTOR_EN_LIGHTBOX,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_LIGHTBOX,
        sizeof(EnLightbox),
        (ActorFunc)EnLightbox_Init,
        (ActorFunc)EnLightbox_Destroy,
        (ActorFunc)EnLightbox_Update,
        (ActorFunc)EnLightbox_Draw,
        (ActorFunc)EnLightbox_Reset,
    };

}
