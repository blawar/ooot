#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_LIGHTSWITCH_Z_OBJ_LIGHTSWITCH_C
#include "actor_common.h"
/*
 * File: z_obj_lightswitch.c
 * Overlay: ovl_Obj_Lightswitch
 * Description: Sun Emblem Trigger (Spirit Temple)
 */

#include "z_obj_lightswitch.h"
#include "vt.h"
#include "overlays/actors/ovl_Obj_Oshihiki/z_obj_oshihiki.h"
#include "objects/object_lightswitch/object_lightswitch.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

typedef enum {
    /* 0x00 */ FACE_EYES_CLOSED,
    /* 0x01 */ FACE_EYES_OPEN,
    /* 0x02 */ FACE_EYES_OPEN_SMILING
} FaceTextureIndex;

void ObjLightswitch_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjLightswitch_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjLightswitch_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjLightswitch_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjLightswitch_SetupOff(ObjLightswitch* pthis);
void ObjLightswitch_Off(ObjLightswitch* pthis, GlobalContext* globalCtx);
void ObjLightswitch_SetupTurnOn(ObjLightswitch* pthis);
void ObjLightswitch_TurnOn(ObjLightswitch* pthis, GlobalContext* globalCtx);
void ObjLightswitch_SetupOn(ObjLightswitch* pthis);
void ObjLightswitch_On(ObjLightswitch* pthis, GlobalContext* globalCtx);
void ObjLightswitch_SetupTurnOff(ObjLightswitch* pthis);
void ObjLightswitch_TurnOff(ObjLightswitch* pthis, GlobalContext* globalCtx);
void ObjLightswitch_SetupDisappearDelay(ObjLightswitch* pthis);
void ObjLightswitch_DisappearDelay(ObjLightswitch* pthis, GlobalContext* globalCtx);
void ObjLightswitch_SetupDisappear(ObjLightswitch* pthis);
void ObjLightswitch_Disappear(ObjLightswitch* pthis, GlobalContext* globalCtx);

ActorInit Obj_Lightswitch_InitVars = {
    ACTOR_OBJ_LIGHTSWITCH,
    ACTORCAT_SWITCH,
    FLAGS,
    OBJECT_LIGHTSWITCH,
    sizeof(ObjLightswitch),
    (ActorFunc)ObjLightswitch_Init,
    (ActorFunc)ObjLightswitch_Destroy,
    (ActorFunc)ObjLightswitch_Update,
    (ActorFunc)ObjLightswitch_Draw,
};

static ColliderJntSphElementInit sColliderJntSphElementInit[] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00200000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 19 }, 100 },
    },
};
static ColliderJntSphInit sColliderJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_JNTSPH,
    },
    1,
    sColliderJntSphElementInit,
};

static CollisionCheckInfoInit sColChkInfoInit = { 0, 12, 60, MASS_IMMOVABLE };

static void* sFaceTextures[] = { object_lightswitch_Tex_000C20, object_lightswitch_Tex_000420,
                                 object_lightswitch_Tex_001420 };

static Vec3f D_80B97F68 = { -1707.0f, 843.0f, -180.0f };
static Vec3f D_80B97F74 = { 0.0f, 0.0f, 0.0f };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void ObjLightswitch_InitCollider(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    s32 pad;

    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sColliderJntSphInit, pthis->colliderItems);
    func_800D1694(pthis->actor.world.pos.x, pthis->actor.world.pos.y + (pthis->actor.shape.yOffset * pthis->actor.scale.y),
                  pthis->actor.world.pos.z, &pthis->actor.shape.rot);
    Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
    Collider_UpdateSpheres(0, &pthis->collider);
}

void ObjLightswitch_SetSwitchFlag(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    Actor* thisx = &pthis->actor; // required
    s32 type;

    if (!Flags_GetSwitch(globalCtx, pthis->actor.params >> 8 & 0x3F)) {
        type = pthis->actor.params >> 4 & 3;

        Flags_SetSwitch(globalCtx, pthis->actor.params >> 8 & 0x3F);

        if (type == OBJLIGHTSWITCH_TYPE_1) {
            OnePointCutscene_AttentionSetSfx(globalCtx, thisx, NA_SE_SY_TRE_BOX_APPEAR);
        } else if (type == OBJLIGHTSWITCH_TYPE_BURN) {
            OnePointCutscene_AttentionSetSfx(globalCtx, thisx, NA_SE_SY_ERROR);
        } else {
            OnePointCutscene_AttentionSetSfx(globalCtx, thisx, NA_SE_SY_CORRECT_CHIME);
        }
    }
}

void ObjLightswitch_ClearSwitchFlag(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->actor.params >> 8 & 0x3F)) {
        Flags_UnsetSwitch(globalCtx, pthis->actor.params >> 8 & 0x3F);

        if ((pthis->actor.params >> 4 & 3) == OBJLIGHTSWITCH_TYPE_1) {
            OnePointCutscene_AttentionSetSfx(globalCtx, &pthis->actor, NA_SE_SY_TRE_BOX_APPEAR);
        }
    }
}

void ObjLightswitch_SpawnDisappearEffects(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    f32 s = Math_SinS(pthis->actor.shape.rot.y);
    f32 c = Math_CosS(pthis->actor.shape.rot.y);
    f32 x;
    f32 y;
    f32 z;
    s32 pad;

    if (pthis->alpha >= (100 << 6)) {
        x = (CLAMP_MAX((1.0f - 1.0f / (255 << 6) * pthis->alpha) * 400.0f, 60.0f) - 30.0f + 30.0f) * Rand_ZeroOne();
        y = x - 30.0f;
        if (x > 30.0f) {
            x = 30.0f;
        } else {
            x = 900.0f - (y * y);
            if (x < 100.0f) {
                x = 100.0f;
            }
            x = sqrtf(x);
        }
        x = 2.0f * (x * (Rand_ZeroOne() - 0.5f));
        z = (30.0f - fabsf(x)) * 0.5f + 10.0f * Rand_ZeroOne();
        pos.x = pthis->actor.world.pos.x + ((z * s) + (x * c));
        pos.y = pthis->actor.world.pos.y + y + 10.0f;
        pos.z = pthis->actor.world.pos.z + ((z * c) - (x * s));
        EffectSsDeadDb_Spawn(globalCtx, &pos, &D_80B97F74, &D_80B97F74, 100, 0, 255, 255, 160, 160, 255, 0, 0, 1, 9,
                             true);
    }
}

void ObjLightswitch_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjLightswitch* pthis = (ObjLightswitch*)thisx;
    s32 switchFlagSet = Flags_GetSwitch(globalCtx, pthis->actor.params >> 8 & 0x3F);
    s32 removeSelf = false;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Actor_SetFocus(&pthis->actor, 0.0f);
    if (switchFlagSet) {
        if ((pthis->actor.params >> 4 & 3) == OBJLIGHTSWITCH_TYPE_BURN) {
            removeSelf = true;
        } else {
            ObjLightswitch_SetupOn(pthis);
        }
    } else {
        ObjLightswitch_SetupOff(pthis);
    }
    if ((pthis->actor.params & 1) == 1) {
        if (switchFlagSet) {
            Math_Vec3f_Copy(&pthis->actor.world.pos, &D_80B97F68);
            Math_Vec3f_Copy(&pthis->actor.home.pos, &D_80B97F68);
        }
        pthis->actor.shape.rot.x = -0x4000;
        pthis->actor.shape.rot.z = 0;
        pthis->actor.world.rot.x = pthis->actor.home.rot.x = pthis->actor.shape.rot.x;
        pthis->actor.world.rot.z = pthis->actor.home.rot.z = pthis->actor.shape.rot.z;
        pthis->actor.flags |= ACTOR_FLAG_5;
        if (Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_OBJ_OSHIHIKI,
                               pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z, 0,
                               pthis->actor.home.rot.y, 0, (0xFF << 8) | PUSHBLOCK_SMALL_START_ON) == NULL) {
            osSyncPrintf(VT_COL(RED, WHITE));
            // "Push-pull block occurrence failure"
            osSyncPrintf("押引ブロック発生失敗(%s %d)(arg_data 0x%04x)\n", "../z_obj_lightswitch.c", 452,
                         pthis->actor.params);
            osSyncPrintf(VT_RST);
            removeSelf = true;
        }
    }
    ObjLightswitch_InitCollider(pthis, globalCtx);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    if (removeSelf) {
        Actor_Kill(&pthis->actor);
    }
    // "Light switch"
    osSyncPrintf("(光スイッチ)(arg_data 0x%04x)\n", pthis->actor.params);
}

void ObjLightswitch_Destroy(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    ObjLightswitch* pthis = (ObjLightswitch*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void ObjLightswitch_SetupOff(ObjLightswitch* pthis) {
    pthis->actionFunc = ObjLightswitch_Off;
    pthis->faceTextureIndex = FACE_EYES_CLOSED;
    pthis->color[0] = 155 << 6;
    pthis->color[1] = 125 << 6;
    pthis->color[2] = 255 << 6;
    pthis->alpha = 255 << 6;
}

void ObjLightswitch_Off(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    switch (pthis->actor.params >> 4 & 3) {
        case OBJLIGHTSWITCH_TYPE_STAY_ON:
        case OBJLIGHTSWITCH_TYPE_2:
            if (pthis->collider.base.acFlags & AC_HIT) {
                ObjLightswitch_SetupTurnOn(pthis);
                ObjLightswitch_SetSwitchFlag(pthis, globalCtx);
            }
            break;
        case OBJLIGHTSWITCH_TYPE_1:
            if ((pthis->collider.base.acFlags & AC_HIT) && !(pthis->prevFrameACflags & AC_HIT)) {
                ObjLightswitch_SetupTurnOn(pthis);
                ObjLightswitch_SetSwitchFlag(pthis, globalCtx);
            }
            break;
        case OBJLIGHTSWITCH_TYPE_BURN:
            if (pthis->collider.base.acFlags & AC_HIT) {
                ObjLightswitch_SetupDisappearDelay(pthis);
                ObjLightswitch_SetSwitchFlag(pthis, globalCtx);
            }
            break;
    }
}

void ObjLightswitch_SetupTurnOn(ObjLightswitch* pthis) {
    pthis->actionFunc = ObjLightswitch_TurnOn;
    pthis->toggleDelay = 100;
    pthis->timer = 0;
    pthis->faceTextureIndex = FACE_EYES_CLOSED;
}

void ObjLightswitch_TurnOn(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    if (func_8005B198() == pthis->actor.category || pthis->toggleDelay <= 0) {
        if (pthis->timer == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_TRIFORCE_FLASH);
        }

        pthis->timer++;

        Math_StepToS(&pthis->flameRingRotSpeed, -0xAA, 0xA);
        pthis->flameRingRot += pthis->flameRingRotSpeed;

        pthis->color[0] = pthis->timer * (((255 - 155) << 6) / 20) + (155 << 6);
        pthis->color[1] = pthis->timer * (((255 - 125) << 6) / 20) + (125 << 6);

        if (pthis->timer >= 20) {
            ObjLightswitch_SetupOn(pthis);
        } else if (pthis->timer == 15) {
            pthis->faceTextureIndex = FACE_EYES_OPEN;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FOOT_SWITCH);
        }
    }
}

void ObjLightswitch_SetupOn(ObjLightswitch* pthis) {
    pthis->actionFunc = ObjLightswitch_On;
    pthis->faceTextureIndex = FACE_EYES_OPEN_SMILING;

    pthis->color[0] = 255 << 6;
    pthis->color[1] = 255 << 6;
    pthis->color[2] = 255 << 6;
    pthis->alpha = 255 << 6;

    pthis->flameRingRotSpeed = -0xAA;
    pthis->timer = 0;
}

void ObjLightswitch_On(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    switch (pthis->actor.params >> 4 & 3) {
        case OBJLIGHTSWITCH_TYPE_STAY_ON:
            if (!Flags_GetSwitch(globalCtx, pthis->actor.params >> 8 & 0x3F)) {
                ObjLightswitch_SetupTurnOff(pthis);
            }
            break;
        case OBJLIGHTSWITCH_TYPE_1:
            if (pthis->collider.base.acFlags & AC_HIT && !(pthis->prevFrameACflags & AC_HIT)) {
                ObjLightswitch_SetupTurnOff(pthis);
                ObjLightswitch_ClearSwitchFlag(pthis, globalCtx);
            }
            break;
        case OBJLIGHTSWITCH_TYPE_2:
            if (!(pthis->collider.base.acFlags & AC_HIT)) {
                if (pthis->timer >= 7) {
                    ObjLightswitch_SetupTurnOff(pthis);
                    ObjLightswitch_ClearSwitchFlag(pthis, globalCtx);
                } else {
                    pthis->timer++;
                }
            } else {
                pthis->timer = 0;
            }
            break;
    }
    pthis->flameRingRot += pthis->flameRingRotSpeed;
}

void ObjLightswitch_SetupTurnOff(ObjLightswitch* pthis) {
    pthis->actionFunc = ObjLightswitch_TurnOff;
    pthis->toggleDelay = 100;
    pthis->timer = 20;
    pthis->faceTextureIndex = FACE_EYES_OPEN;
}

void ObjLightswitch_TurnOff(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    if ((pthis->actor.params >> 4 & 3) != OBJLIGHTSWITCH_TYPE_1 || func_8005B198() == pthis->actor.category ||
        pthis->toggleDelay <= 0) {
        pthis->timer--;

        Math_StepToS(&pthis->flameRingRotSpeed, 0, 0xA);
        pthis->flameRingRot += pthis->flameRingRotSpeed;

        pthis->color[0] = pthis->timer * (((255 - 155) << 6) / 20) + (155 << 6);
        pthis->color[1] = pthis->timer * (((255 - 125) << 6) / 20) + (125 << 6);

        if (pthis->timer <= 0) {
            ObjLightswitch_SetupOff(pthis);
        } else if (pthis->timer == 15) {
            pthis->faceTextureIndex = FACE_EYES_CLOSED;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FOOT_SWITCH);
        }
    }
}

void ObjLightswitch_SetupDisappearDelay(ObjLightswitch* pthis) {
    pthis->actionFunc = ObjLightswitch_DisappearDelay;
    pthis->toggleDelay = 100;
}

void ObjLightswitch_DisappearDelay(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    if (func_8005B198() == pthis->actor.category || pthis->toggleDelay <= 0) {
        ObjLightswitch_SetupDisappear(pthis);
    }
}

void ObjLightswitch_SetupDisappear(ObjLightswitch* pthis) {
    pthis->actionFunc = ObjLightswitch_Disappear;
    pthis->alpha = 255 << 6;
}

void ObjLightswitch_Disappear(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    pthis->alpha -= 200;
    ObjLightswitch_SpawnDisappearEffects(pthis, globalCtx);
    if (pthis->alpha < 0) {
        Actor_Kill(&pthis->actor);
    }
}

void ObjLightswitch_Update(Actor* thisx, GlobalContext* globalCtx2) {
    ObjLightswitch* pthis = (ObjLightswitch*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    if (pthis->toggleDelay > 0) {
        pthis->toggleDelay--;
    }

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->actor.update != NULL) {
        if ((pthis->actor.params & 1) == 1) {
            pthis->actor.world.pos.x = pthis->actor.child->world.pos.x;
            pthis->actor.world.pos.y = pthis->actor.child->world.pos.y + 60.0f;
            pthis->actor.world.pos.z = pthis->actor.child->world.pos.z;
            Actor_SetFocus(&pthis->actor, 0.0f);
        }

        pthis->prevFrameACflags = pthis->collider.base.acFlags;
        pthis->collider.base.acFlags &= ~AC_HIT;
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void ObjLightswitch_DrawOpa(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    Actor* child;
    Vec3f pos;
    Vec3s rot;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 809);
    func_80093D18(globalCtx->state.gfxCtx);

    gDPSetEnvColor(POLY_OPA_DISP++, (u8)(pthis->color[0] >> 6), (u8)(pthis->color[1] >> 6), (u8)(pthis->color[2] >> 6),
                   (u8)(pthis->alpha >> 6));
    gSPSegment(POLY_OPA_DISP++, 0x09, &D_80116280[2]);

    if ((pthis->actor.params & 1) == 1) {
        child = pthis->actor.child;
        pthis->actor.world.pos.x = child->world.pos.x;
        pthis->actor.world.pos.y = child->world.pos.y + 60.0f;
        pthis->actor.world.pos.z = child->world.pos.z;
        Math_Vec3f_Copy(&pos, &pthis->actor.world.pos);
        func_800D1694(pos.x, pos.y, pos.z, &pthis->actor.shape.rot);
        Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
    } else {
        pos.x = pthis->actor.world.pos.x;
        pos.y = pthis->actor.world.pos.y + pthis->actor.shape.yOffset * pthis->actor.scale.y;
        pos.z = pthis->actor.world.pos.z;
    }

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 841),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sFaceTextures[pthis->faceTextureIndex]));
    gSPDisplayList(POLY_OPA_DISP++, object_lightswitch_DL_000260);

    rot.x = pthis->actor.shape.rot.x;
    rot.y = pthis->actor.shape.rot.y;
    rot.z = pthis->actor.shape.rot.z + pthis->flameRingRot;
    func_800D1694(pos.x, pos.y, pos.z, &rot);
    Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 859),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, object_lightswitch_DL_000398);

    rot.z = pthis->actor.shape.rot.z - pthis->flameRingRot;
    func_800D1694(pos.x, pos.y, pos.z, &rot);
    Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 873),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, object_lightswitch_DL_000408);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 878);
}

void ObjLightswitch_DrawXlu(ObjLightswitch* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f sp68;
    Vec3s sp60;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 890);
    func_80093D84(globalCtx->state.gfxCtx);

    gDPSetEnvColor(POLY_XLU_DISP++, (u8)(pthis->color[0] >> 6), (u8)(pthis->color[1] >> 6), (u8)(pthis->color[2] >> 6),
                   (u8)(pthis->alpha >> 6));
    gSPSegment(POLY_XLU_DISP++, 0x09, D_80116280);

    sp68.x = pthis->actor.world.pos.x;
    sp68.y = pthis->actor.world.pos.y + (pthis->actor.shape.yOffset * pthis->actor.scale.y);
    sp68.z = pthis->actor.world.pos.z;

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 912),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sFaceTextures[pthis->faceTextureIndex]));
    gSPDisplayList(POLY_XLU_DISP++, object_lightswitch_DL_000260);

    sp60.x = pthis->actor.shape.rot.x;
    sp60.y = pthis->actor.shape.rot.y;
    sp60.z = pthis->actor.shape.rot.z + pthis->flameRingRot;

    func_800D1694(sp68.x, sp68.y, sp68.z, &sp60);
    Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 930),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, object_lightswitch_DL_000398);

    sp60.z = pthis->actor.shape.rot.z - pthis->flameRingRot;
    func_800D1694(sp68.x, sp68.y, sp68.z, &sp60);
    Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 944),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, object_lightswitch_DL_000408);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_obj_lightswitch.c", 949);
}

void ObjLightswitch_Draw(Actor* thisx, GlobalContext* globalCtx) {
    ObjLightswitch* pthis = (ObjLightswitch*)thisx;
    s32 alpha = pthis->alpha >> 6 & 0xFF;

    if ((pthis->actor.params & 1) == 1) {
        Collider_UpdateSpheres(0, &pthis->collider);
    }

    if ((pthis->actor.params >> 4 & 3) == OBJLIGHTSWITCH_TYPE_BURN && (alpha > 0 || alpha < 255)) {
        ObjLightswitch_DrawXlu(pthis, globalCtx);
    } else {
        ObjLightswitch_DrawOpa(pthis, globalCtx);
    }
}
