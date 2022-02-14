#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_ARMS_HOOK_Z_ARMS_HOOK_C
#include "actor_common.h"
#include "z_arms_hook.h"
#include "framerate.h"
#include "objects/object_link_boy/object_link_boy.h"
#include "def/code_800F7260.h"
#include "def/code_800FCE80.h"
#include "def/sys_math_atan.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/graph.h" // FORCE

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void ArmsHook_Init(Actor* pthisx, GlobalContext* globalCtx);
void ArmsHook_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void ArmsHook_Update(Actor* pthisx, GlobalContext* globalCtx);
void ArmsHook_Draw(Actor* pthisx, GlobalContext* globalCtx);

void ArmsHook_Wait(ArmsHook* pthis, GlobalContext* globalCtx);
void ArmsHook_Shoot(ArmsHook* pthis, GlobalContext* globalCtx);

ActorInit Arms_Hook_InitVars = {
    ACTOR_ARMS_HOOK,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_LINK_BOY,
    sizeof(ArmsHook),
    (ActorFunc)ArmsHook_Init,
    (ActorFunc)ArmsHook_Destroy,
    (ActorFunc)ArmsHook_Update,
    (ActorFunc)ArmsHook_Draw,
};

static ColliderQuadInit sQuadInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_PLAYER,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_PLAYER,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000080, 0x00, 0x01 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_NEAREST | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static Vec3f sUnusedVec1 = { 0.0f, 0.5f, 0.0f };
static Vec3f sUnusedVec2 = { 0.0f, 0.5f, 0.0f };

static Color_RGB8 sUnusedColors[] = {
    { 255, 255, 100 },
    { 255, 255, 50 },
};

static Vec3f D_80865B70 = { 0.0f, 0.0f, 0.0f };
static Vec3f D_80865B7C = { 0.0f, 0.0f, 900.0f };
static Vec3f D_80865B88 = { 0.0f, 500.0f, -3000.0f };
static Vec3f D_80865B94 = { 0.0f, -500.0f, -3000.0f };
static Vec3f D_80865BA0 = { 0.0f, 500.0f, 1200.0f };
static Vec3f D_80865BAC = { 0.0f, -500.0f, 1200.0f };

void ArmsHook_SetupAction(ArmsHook* pthis, ArmsHookActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void ArmsHook_Init(Actor* pthisx, GlobalContext* globalCtx) {
    ArmsHook* pthis = (ArmsHook*)pthisx;

    Collider_InitQuad(globalCtx, &pthis->collider);
    Collider_SetQuad(globalCtx, &pthis->collider, &pthis->actor, &sQuadInit);
    ArmsHook_SetupAction(pthis, ArmsHook_Wait);
    pthis->unk_1E8 = pthis->actor.world.pos;
}

void ArmsHook_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    ArmsHook* pthis = (ArmsHook*)pthisx;

    if (pthis->grabbed != NULL) {
        pthis->grabbed->flags &= ~ACTOR_FLAG_13;
    }
    Collider_DestroyQuad(globalCtx, &pthis->collider);
}

void ArmsHook_Wait(ArmsHook* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.parent == NULL) {
        Player* player = GET_PLAYER(globalCtx);
        // get correct timer length for hookshot or longshot
        s32 length = ((player->heldItemActionParam == PLAYER_AP_HOOKSHOT) ? 13 : 26);

        ArmsHook_SetupAction(pthis, ArmsHook_Shoot);
        func_8002D9A4(&pthis->actor, 20.0f);
        pthis->actor.parent = &GET_PLAYER(globalCtx)->actor;
        pthis->timer = length;
    }
}

void func_80865044(ArmsHook* pthis) {
    pthis->actor.child = pthis->actor.parent;
    pthis->actor.parent->parent = &pthis->actor;
}

s32 ArmsHook_AttachToPlayer(ArmsHook* pthis, Player* player) {
    player->actor.child = &pthis->actor;
    player->heldActor = &pthis->actor;
    if (pthis->actor.child != NULL) {
        player->actor.parent = NULL;
        pthis->actor.child = NULL;
        return true;
    }
    return false;
}

void ArmsHook_DetachHookFromActor(ArmsHook* pthis) {
    if (pthis->grabbed != NULL) {
        pthis->grabbed->flags &= ~ACTOR_FLAG_13;
        pthis->grabbed = NULL;
    }
}

s32 ArmsHook_CheckForCancel(ArmsHook* pthis) {
    Player* player = (Player*)pthis->actor.parent;

    if (Player_HoldsHookshot(player)) {
        if ((player->itemActionParam != player->heldItemActionParam) || (player->actor.flags & ACTOR_FLAG_8) ||
            ((player->stateFlags1 & 0x4000080))) {
            pthis->timer = 0;
            ArmsHook_DetachHookFromActor(pthis);
            Math_Vec3f_Copy(&pthis->actor.world.pos, &player->unk_3C8);
            return 1;
        }
    }
    return 0;
}

void ArmsHook_AttachHookToActor(ArmsHook* pthis, Actor* actor) {
    actor->flags |= ACTOR_FLAG_13;
    pthis->grabbed = actor;
    Math_Vec3f_Diff(&actor->world.pos, &pthis->actor.world.pos, &pthis->grabbedDistDiff);
}

void ArmsHook_Shoot(ArmsHook* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Actor* touchedActor;
    Actor* grabbed;
    Vec3f bodyDistDiffVec;
    Vec3f newPos;
    f32 bodyDistDiff;
    f32 phi_f16;
    DynaPolyActor* dynaPolyActor;
    f32 sp94;
    f32 sp90;
    s32 pad;
    CollisionPoly* poly;
    s32 bgId;
    Vec3f sp78;
    Vec3f prevFrameDiff;
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 velocity;
    s32 pad1;

    if ((pthis->actor.parent == NULL) || (!Player_HoldsHookshot(player))) {
        ArmsHook_DetachHookFromActor(pthis);
        Actor_Kill(&pthis->actor);
        return;
    }

    func_8002F8F0(&player->actor, NA_SE_IT_HOOKSHOT_CHAIN - SFX_FLAG);
    ArmsHook_CheckForCancel(pthis);

    if ((pthis->timer != 0) && (pthis->collider.base.atFlags & AT_HIT) &&
        (pthis->collider.info.atHitInfo->elemType != ELEMTYPE_UNK4)) {
        touchedActor = pthis->collider.base.at;
        if ((touchedActor->update != NULL) && (touchedActor->flags & (ACTOR_FLAG_9 | ACTOR_FLAG_10))) {
            if (pthis->collider.info.atHitInfo->bumperFlags & BUMP_HOOKABLE) {
                ArmsHook_AttachHookToActor(pthis, touchedActor);
                if (CHECK_FLAG_ALL(touchedActor->flags, ACTOR_FLAG_10)) {
                    func_80865044(pthis);
                }
            }
        }
        pthis->timer = 0;
        Audio_PlaySoundGeneral(NA_SE_IT_ARROW_STICK_CRE, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (DECR(pthis->timer) == 0) {
        grabbed = pthis->grabbed;
        if (grabbed != NULL) {
            if ((grabbed->update == NULL) || !CHECK_FLAG_ALL(grabbed->flags, ACTOR_FLAG_13)) {
                grabbed = NULL;
                pthis->grabbed = NULL;
            } else if (pthis->actor.child != NULL) {
                sp94 = Actor_WorldDistXYZToActor(&pthis->actor, grabbed);
                sp90 = sqrtf(SQ(pthis->grabbedDistDiff.x) + SQ(pthis->grabbedDistDiff.y) + SQ(pthis->grabbedDistDiff.z));
                Math_Vec3f_Diff(&grabbed->world.pos, &pthis->grabbedDistDiff, &pthis->actor.world.pos);
                if (50.0f < (sp94 - sp90)) {
                    ArmsHook_DetachHookFromActor(pthis);
                    grabbed = NULL;
                }
            }
        }

        bodyDistDiff = Math_Vec3f_DistXYZAndStoreDiff(&player->unk_3C8, &pthis->actor.world.pos, &bodyDistDiffVec);
        if (bodyDistDiff < 30.0f) {
            velocity = 0.0f;
            phi_f16 = 0.0f;
        } else {
            if (pthis->actor.child != NULL) {
                velocity = 30.0f;
            } else if (grabbed != NULL) {
                velocity = 50.0f;
            } else {
                velocity = 200.0f;
            }
            phi_f16 = bodyDistDiff - velocity;
            if (bodyDistDiff <= velocity) {
                phi_f16 = 0.0f;
            }
            velocity = phi_f16 / bodyDistDiff;
        }

        newPos.x = bodyDistDiffVec.x * velocity;
        newPos.y = bodyDistDiffVec.y * velocity;
        newPos.z = bodyDistDiffVec.z * velocity;

        if (pthis->actor.child == NULL) {
            if ((grabbed != NULL) && (grabbed->id == ACTOR_BG_SPOT06_OBJECTS)) {
                Math_Vec3f_Diff(&grabbed->world.pos, &pthis->grabbedDistDiff, &pthis->actor.world.pos);
                phi_f16 = 1.0f;
            } else {
                Math_Vec3f_Sum(&player->unk_3C8, &newPos, &pthis->actor.world.pos);
                if (grabbed != NULL) {
                    Math_Vec3f_Sum(&pthis->actor.world.pos, &pthis->grabbedDistDiff, &grabbed->world.pos);
                }
            }
        } else {
            Math_Vec3f_Diff(&bodyDistDiffVec, &newPos, &player->actor.velocity);
            player->actor.world.rot.x =
                Math_Atan2S(sqrtf(SQ(bodyDistDiffVec.x) + SQ(bodyDistDiffVec.z)), -bodyDistDiffVec.y);
        }

        if (phi_f16 < 50.0f) {
            ArmsHook_DetachHookFromActor(pthis);
            if (phi_f16 == 0.0f) {
                ArmsHook_SetupAction(pthis, ArmsHook_Wait);
                if (ArmsHook_AttachToPlayer(pthis, player)) {
                    Math_Vec3f_Diff(&pthis->actor.world.pos, &player->actor.world.pos, &player->actor.velocity);
                    player->actor.velocity.y -= 20.0f;
                }
            }
        }
    } else {
        Actor_MoveForward(&pthis->actor);
        Math_Vec3f_Diff(&pthis->actor.world.pos, &pthis->actor.prevPos, &prevFrameDiff);
        Math_Vec3f_Sum(&pthis->unk_1E8, &prevFrameDiff, &pthis->unk_1E8);
        pthis->actor.shape.rot.x = Math_Atan2S(pthis->actor.speedXZ, -pthis->actor.velocity.y);
        sp60.x = pthis->unk_1F4.x - (pthis->unk_1E8.x - pthis->unk_1F4.x);
        sp60.y = pthis->unk_1F4.y - (pthis->unk_1E8.y - pthis->unk_1F4.y);
        sp60.z = pthis->unk_1F4.z - (pthis->unk_1E8.z - pthis->unk_1F4.z);
        if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &sp60, &pthis->unk_1E8, &sp78, &poly, true, true, true, true,
                                    &bgId) &&
            !func_8002F9EC(globalCtx, &pthis->actor, poly, bgId, &sp78)) {
            sp5C = COLPOLY_GET_NORMAL(poly->normal.x);
            sp58 = COLPOLY_GET_NORMAL(poly->normal.z);
            Math_Vec3f_Copy(&pthis->actor.world.pos, &sp78);
            pthis->actor.world.pos.x += 10.0f * sp5C;
            pthis->actor.world.pos.z += 10.0f * sp58;
            pthis->timer = 0;
            if (SurfaceType_IsHookshotSurface(&globalCtx->colCtx, poly, bgId)) {
                if (bgId != BGCHECK_SCENE) {
                    dynaPolyActor = DynaPoly_GetActor(&globalCtx->colCtx, bgId);
                    if (dynaPolyActor != NULL) {
                        ArmsHook_AttachHookToActor(pthis, &dynaPolyActor->actor);
                    }
                }
                func_80865044(pthis);
                Audio_PlaySoundGeneral(NA_SE_IT_HOOKSHOT_STICK_OBJ, &pthis->actor.projectedPos, 4, &D_801333E0,
                                       &D_801333E0, &D_801333E8);
            } else {
                CollisionCheck_SpawnShieldParticlesMetal(globalCtx, &pthis->actor.world.pos);
                Audio_PlaySoundGeneral(NA_SE_IT_HOOKSHOT_REFLECT, &pthis->actor.projectedPos, 4, &D_801333E0,
                                       &D_801333E0, &D_801333E8);
            }
        } else if (CHECK_BTN_ANY(globalCtx->state.input[0].press.button,
                                 (BTN_A | BTN_B | BTN_R | BTN_CUP | BTN_CLEFT | BTN_CRIGHT | BTN_CDOWN))) {
            pthis->timer = 0;
        }
    }
}

void ArmsHook_Update(Actor* pthisx, GlobalContext* globalCtx) {
    ArmsHook* pthis = (ArmsHook*)pthisx;

    pthis->actionFunc(pthis, globalCtx);
    pthis->unk_1F4 = pthis->unk_1E8;
}

void ArmsHook_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    s32 pad;
    ArmsHook* pthis = (ArmsHook*)pthisx;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f sp78;
    Vec3f sp6C;
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;

    if ((player->actor.draw != NULL) && (player->rightHandType == 15)) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_arms_hook.c", 850);

        if ((ArmsHook_Shoot != pthis->actionFunc) || (pthis->timer <= 0)) {
            Matrix_MultVec3f(&D_80865B70, &pthis->unk_1E8);
            Matrix_MultVec3f(&D_80865B88, &sp6C);
            Matrix_MultVec3f(&D_80865B94, &sp60);
            pthis->hookInfo.active = 0;
        } else {
            Matrix_MultVec3f(&D_80865B7C, &pthis->unk_1E8);
            Matrix_MultVec3f(&D_80865BA0, &sp6C);
            Matrix_MultVec3f(&D_80865BAC, &sp60);
        }

        func_80090480(globalCtx, &pthis->collider, &pthis->hookInfo, &sp6C, &sp60);
        func_80093D18(globalCtx->state.gfxCtx);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_arms_hook.c", 895),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gLinkAdultHookshotTipDL);
        Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
        Math_Vec3f_Diff(&player->unk_3C8, &pthis->actor.world.pos, &sp78);
        sp58 = SQ(sp78.x) + SQ(sp78.z);
        sp5C = sqrtf(sp58);
        Matrix_RotateY(Math_FAtan2F(sp78.x, sp78.z), MTXMODE_APPLY);
        Matrix_RotateX(Math_FAtan2F(-sp78.y, sp5C), MTXMODE_APPLY);
        Matrix_Scale(0.015f, 0.015f, sqrtf(SQ(sp78.y) + sp58) * 0.01f, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_arms_hook.c", 910),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gLinkAdultHookshotChainDL);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_arms_hook.c", 913);
    }
}
