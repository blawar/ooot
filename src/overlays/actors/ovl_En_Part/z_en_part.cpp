#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_PART_Z_EN_PART_C
#include "actor_common.h"
/*
 * File: z_en_part.c
 * Overlay: ovl_En_Part
 * Description: Effect spawner for enemies' death
 */

#include "z_en_part.h"
#include "objects/object_tite/object_tite.h"
#include "objects/object_ik/object_ik.h"
#include "def/code_800FD970.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void EnPart_Init(Actor* thisx, GlobalContext* globalCtx);
void EnPart_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnPart_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnPart_Update(Actor* thisx, GlobalContext* globalCtx);
void EnPart_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Part_InitVars = {
    ACTOR_EN_PART,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnPart),
    (ActorFunc)EnPart_Init,
    (ActorFunc)EnPart_Destroy,
    (ActorFunc)EnPart_Update,
    (ActorFunc)EnPart_Draw,
    (ActorFunc)EnPart_Reset,
};

void EnPart_Init(Actor* thisx, GlobalContext* globalCtx) {
}

void EnPart_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void func_80ACDDE8(EnPart* pthis, GlobalContext* globalCtx) {
    f32 sign = 1.0f;

    pthis->action = 1;
    pthis->actor.world.rot.y = Rand_ZeroOne() * 20000.0f;

    switch (pthis->actor.params) {
        case 0:
            pthis->actor.velocity.y = 0.0f;
            pthis->actor.gravity = -0.3f - Rand_ZeroOne() * 0.5f;
            pthis->rotZSpeed = 0.3f;
            pthis->timer = 25;
            pthis->actor.speedXZ = (Rand_ZeroOne() - 0.5f) * 2.0f;
            break;
        case 13:
            pthis->timer = 400;
        case 12:
            pthis->actor.speedXZ = Rand_CenteredFloat(6.0f);
            pthis->actor.home.pos = pthis->actor.world.pos;
            pthis->timer += 60;
            pthis->actor.velocity.y = Rand_ZeroOne() * 5.0f + 4.0f;
            pthis->actor.gravity = -0.6f - Rand_ZeroOne() * 0.5f;
            pthis->rotZSpeed = 0.15f;
            break;
        case 14:
            EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &pthis->actor.world.pos, 40, 0x8001, 0, -1);
        case 1:
        case 4:
        case 9:
        case 10:
            pthis->timer += (s16)(Rand_ZeroOne() * 17.0f) + 5;
        case 2:
            pthis->actor.velocity.y = Rand_ZeroOne() * 5.0f + 4.0f;
            pthis->actor.gravity = -0.6f - Rand_ZeroOne() * 0.5f;
            pthis->rotZSpeed = 0.15f;
            break;
        case 11:
            EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &pthis->actor.world.pos, 40, 0x8001, 0, -1);
        case 3:
            pthis->actor.speedXZ = (Rand_ZeroOne() - 0.5f) * 3.0f;
            pthis->timer = (s16)(Rand_ZeroOne() * 17.0f) + 10;
            pthis->actor.velocity.y = Rand_ZeroOne() * 3.0f + 8.0f;
            pthis->actor.gravity = -0.6f - Rand_ZeroOne() * 0.3f;
            pthis->rotZSpeed = 0.15f;
            break;
        case 5:
        case 6:
        case 7:
        case 8:
            pthis->actor.world.rot.y = pthis->actor.parent->shape.rot.y;
            if (pthis->displayList == object_ik_DL_015380) {
                sign = -1.0f;
            }
            pthis->actor.velocity.y = 0.0f;
            pthis->actor.speedXZ = 6.0f * sign;
            pthis->actor.gravity = -1.2f;
            pthis->rotZSpeed = 0.15f * sign;
            ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
            pthis->timer = 18;
            break;
    }
}

void func_80ACE13C(EnPart* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f pos;
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    if ((pthis->actor.params == 12) || (pthis->actor.params == 13)) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 15.0f, 0.0f, 0x1D);

        if ((pthis->actor.bgCheckFlags & 1) || (pthis->actor.world.pos.y <= pthis->actor.floorHeight)) {
            pthis->action = 4;
            pthis->actor.speedXZ = 0.0f;
            pthis->actor.gravity = 0.0f;
            pthis->actor.velocity.y = 0.0f;
        }

        if ((pthis->actor.params == 13) && (pthis->actor.parent != NULL) && (pthis->actor.parent->update == NULL)) {
            pthis->actor.parent = NULL;
        }
    } else if (pthis->timer <= 0) {
        switch (pthis->actor.params) {
            case 1:
            case 9:
            case 10:
            case 14:
                EffectSsDeadDb_Spawn(globalCtx, &pthis->actor.world.pos, &zeroVec, &zeroVec,
                                     (s16)(pthis->actor.scale.y * 100.0f) * 40, 7, 255, 255, 255, 255, 0, 255, 0, 1, 9,
                                     true);
                break;
            case 3:
            case 11:
                EffectSsDeadDb_Spawn(globalCtx, &pthis->actor.world.pos, &zeroVec, &zeroVec,
                                     (s16)(pthis->actor.scale.y * 100.0f) * 40, 7, 255, 255, 255, 255, 0, 0, 255, 1, 9,
                                     true);
                break;
            case 4:
                for (i = 7; i >= 0; i--) {
                    pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(60.0f);
                    pos.y = pthis->actor.world.pos.y + pthis->actor.shape.yOffset * pthis->actor.scale.y +
                            Rand_CenteredFloat(50.0f);
                    pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(60.0f);
                    velocity.y = Rand_ZeroOne() + 1.0f;
                    EffectSsDtBubble_SpawnColorProfile(globalCtx, &pos, &velocity, &accel, Rand_S16Offset(80, 100), 25,
                                                       0, true);
                }
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                for (i = 4; i >= 0; i--) {
                    pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(25.0f);
                    pos.y = pthis->actor.world.pos.y + Rand_CenteredFloat(40.0f);
                    pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(25.0f);
                    EffectSsDeadDb_Spawn(globalCtx, &pos, &zeroVec, &zeroVec, 40, 7, 255, 255, 255, 255, 0, 0, 255, 1,
                                         9, true);
                }
                break;
        }

        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->timer--;
    pthis->rotZ += pthis->rotZSpeed;
}

void func_80ACE5B8(EnPart* pthis, GlobalContext* globalCtx) {
    pthis->action = 3;
}

void func_80ACE5C8(EnPart* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->timer--;
    if (pthis->timer == 0) {
        Actor_Kill(&pthis->actor);
    } else {
        Vec3f velocity = { 0.0f, 8.0f, 0.0f };
        Vec3f accel = { 0.0f, -1.5f, 0.0f };

        if (sqrt(pthis->actor.xyzDistToPlayerSq) <= 40.0f) {
            u8 prevInvincibilityTimer = player->invincibilityTimer;

            if (player->invincibilityTimer <= 0) {
                if (player->invincibilityTimer <= -40) {
                    player->invincibilityTimer = 0;
                } else {
                    player->invincibilityTimer = 0;
                    globalCtx->damagePlayer(globalCtx, -8);
                }
            }
            func_8002F71C(globalCtx, pthis->actor.parent, (650.0f - pthis->actor.parent->xzDistToPlayer) * 0.04f + 4.0f,
                          pthis->actor.parent->world.rot.y, 8.0f);
            player->invincibilityTimer = prevInvincibilityTimer;
            pthis->timer = 1;
        }

        func_80033480(globalCtx, &pthis->actor.world.pos, 0.0f, 1, 300, 150, 1);
        velocity.x = Rand_CenteredFloat(16.0f);
        EffectSsHahen_Spawn(globalCtx, &pthis->actor.world.pos, &velocity, &accel, 20,
                            (s32)((Rand_ZeroOne() * 5.0f + 12.0f) * 2), -1, 10, NULL);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MONBLIN_GNDWAVE - SFX_FLAG);
    }
}

void func_80ACE7E8(EnPart* pthis, GlobalContext* globalCtx) {
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    if ((pthis->actor.parent == NULL) || (pthis->actor.parent->update == NULL)) {
        EffectSsDeadDb_Spawn(globalCtx, &pthis->actor.world.pos, &zeroVec, &zeroVec,
                             (s16)(pthis->actor.scale.y * 100.0f) * 40, 7, 255, 255, 255, 255, 0, 255, 0, 1, 9, true);
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->timer == 0) {
        f32 diffsSum = Math_SmoothStepToF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x, 1.0f, 5.0f, 0.0f);

        diffsSum += Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 1.0f, 5.0f, 0.0f);
        diffsSum += Math_SmoothStepToF(&pthis->actor.world.pos.z, pthis->actor.home.pos.z, 1.0f, 5.0f, 0.0f);
        diffsSum += Math_SmoothStepToF(&pthis->rotZ, 0.0f, 1.0f, 0.25f, 0.0f);
        if (diffsSum == 0.0f) {
            pthis->actor.parent->home.rot.x--;
            pthis->timer--;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_DAMAGE);
        }
    } else if (pthis->timer > 0) {
        pthis->timer--;
    }

    if (pthis->actor.parent->colChkInfo.health != 0) {
        Actor_Kill(&pthis->actor);
    }
}

static EnPartActionFunc sActionFuncs[] = {
    func_80ACDDE8, func_80ACE13C, func_80ACE5B8, func_80ACE5C8, func_80ACE7E8,
};

void EnPart_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnPart* pthis = (EnPart*)thisx;

    Actor_MoveForward(&pthis->actor);

    if ((pthis->actor.params > 4 && pthis->actor.params < 9) || pthis->actor.params < 0) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 15.0f, 0.0f, 5);
        if (pthis->actor.params >= 0) {
            Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
            if (thisx->bgCheckFlags & 1) {
                thisx->bgCheckFlags &= ~1;
                thisx->velocity.y = 6.0f;
            }
        }
    }

    sActionFuncs[pthis->action](pthis, globalCtx);
}

Gfx* func_80ACEAC0(GraphicsContext* gfxCtx, u8 primR, u8 primG, u8 primB, u8 envR, u8 envG, u8 envB) {
    Gfx* dList;
    Gfx* dListHead;

    dList = (Gfx*)Graph_Alloc(gfxCtx, 4 * sizeof(Gfx));
    dListHead = dList;

    gDPPipeSync(dListHead++);
    gDPSetPrimColor(dListHead++, 0, 0, primR, primG, primB, 255);
    gDPSetEnvColor(dListHead++, envR, envG, envB, 255);
    gSPEndDisplayList(dListHead++);

    return dList;
}

void EnPart_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnPart* pthis = (EnPart*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_part.c", 647);

    if (thisx->params > 0) {
        Matrix_RotateZ(pthis->rotZ, MTXMODE_APPLY);
    }

    func_80093D18(globalCtx->state.gfxCtx);
    func_8002EBCC(thisx, globalCtx, 0);

    if (thisx->params == 5) {
        gSPSegment(POLY_OPA_DISP++, 0x08, func_80ACEAC0(globalCtx->state.gfxCtx, 245, 255, 205, 30, 35, 0));
        gSPSegment(POLY_OPA_DISP++, 0x09, func_80ACEAC0(globalCtx->state.gfxCtx, 185, 135, 25, 20, 20, 0));
        gSPSegment(POLY_OPA_DISP++, 0x0A, func_80ACEAC0(globalCtx->state.gfxCtx, 255, 255, 255, 30, 40, 20));
    } else if (thisx->params == 6) {
        gSPSegment(POLY_OPA_DISP++, 0x08, func_80ACEAC0(globalCtx->state.gfxCtx, 55, 65, 55, 0, 0, 0));
        gSPSegment(POLY_OPA_DISP++, 0x09, func_80ACEAC0(globalCtx->state.gfxCtx, 205, 165, 75, 25, 20, 0));
        gSPSegment(POLY_OPA_DISP++, 0x0A, func_80ACEAC0(globalCtx->state.gfxCtx, 205, 165, 75, 25, 20, 0));
    } else if (thisx->params == 7) {
        gSPSegment(POLY_OPA_DISP++, 0x08, func_80ACEAC0(globalCtx->state.gfxCtx, 255, 255, 255, 180, 180, 180));
        gSPSegment(POLY_OPA_DISP++, 0x09, func_80ACEAC0(globalCtx->state.gfxCtx, 225, 205, 115, 25, 20, 0));
        gSPSegment(POLY_OPA_DISP++, 0x0A, func_80ACEAC0(globalCtx->state.gfxCtx, 225, 205, 115, 25, 20, 0));
    } else if ((thisx->params == 9) && (pthis->displayList == object_tite_DL_002FF0)) {
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(object_tite_Tex_001300));
        gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(object_tite_Tex_001700));
        gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(object_tite_Tex_001900));
    } else if ((thisx->params == 10) && (pthis->displayList == object_tite_DL_002FF0)) {
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(object_tite_Tex_001B00));
        gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(object_tite_Tex_001F00));
        gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(object_tite_Tex_002100));
    }

    if (pthis->displayList != NULL) {
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_part.c", 696),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, pthis->displayList);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_part.c", 700);
}

void EnPart_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Part_InitVars = {
        ACTOR_EN_PART,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnPart),
        (ActorFunc)EnPart_Init,
        (ActorFunc)EnPart_Destroy,
        (ActorFunc)EnPart_Update,
        (ActorFunc)EnPart_Draw,
        (ActorFunc)EnPart_Reset,
    };

}
