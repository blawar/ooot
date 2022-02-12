#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ARROW_Z_EN_ARROW_C
#include "actor_common.h"
/*
 * File: z_en_arrow.c
 * Overlay: ovl_En_Arrow
 * Description: Arrow, Deku Seed, and Deku Nut Projectile
 */

#include "z_en_arrow.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/sys_math_atan.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_eff_blure.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnArrow_Init(Actor* thisx, GlobalContext* globalCtx);
void EnArrow_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnArrow_Update(Actor* thisx, GlobalContext* globalCtx);
void EnArrow_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnArrow_Shoot(EnArrow* pthis, GlobalContext* globalCtx);
void EnArrow_Fly(EnArrow* pthis, GlobalContext* globalCtx);
void func_809B45E0(EnArrow* pthis, GlobalContext* globalCtx);
void func_809B4640(EnArrow* pthis, GlobalContext* globalCtx);

ActorInit En_Arrow_InitVars = {
    ACTOR_EN_ARROW,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnArrow),
    (ActorFunc)EnArrow_Init,
    (ActorFunc)EnArrow_Destroy,
    (ActorFunc)EnArrow_Update,
    (ActorFunc)EnArrow_Draw,
};

static ColliderQuadInit sColliderInit = {
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
        { 0x00000020, 0x00, 0x01 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_NEAREST | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(minVelocityY, -150, ICHAIN_STOP),
};

void EnArrow_SetupAction(EnArrow* pthis, EnArrowActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnArrow_Init(Actor* thisx, GlobalContext* globalCtx) {
    static EffectBlureInit2 blureNormal = {
        0, 4, 0, { 0, 255, 200, 255 },   { 0, 255, 255, 255 }, { 0, 255, 200, 0 }, { 0, 255, 255, 0 }, 16,
        0, 1, 0, { 255, 255, 170, 255 }, { 0, 150, 0, 0 },
    };
    static EffectBlureInit2 blureFire = {
        0, 4, 0, { 0, 255, 200, 255 }, { 0, 255, 255, 255 }, { 0, 255, 200, 0 }, { 0, 255, 255, 0 }, 16,
        0, 1, 0, { 255, 200, 0, 255 }, { 255, 0, 0, 0 },
    };
    static EffectBlureInit2 blureIce = {
        0, 4, 0, { 0, 255, 200, 255 },   { 0, 255, 255, 255 }, { 0, 255, 200, 0 }, { 0, 255, 255, 0 }, 16,
        0, 1, 0, { 170, 255, 255, 255 }, { 0, 100, 255, 0 },
    };
    static EffectBlureInit2 blureLight = {
        0, 4, 0, { 0, 255, 200, 255 },   { 0, 255, 255, 255 }, { 0, 255, 200, 0 }, { 0, 255, 255, 0 }, 16,
        0, 1, 0, { 255, 255, 170, 255 }, { 255, 255, 0, 0 },
    };
    static u32 dmgFlags[] = {
        0x00000800, 0x00000020, 0x00000020, 0x00000800, 0x00001000,
        0x00002000, 0x00010000, 0x00004000, 0x00008000, 0x00000004,
    };
    EnArrow* pthis = (EnArrow*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);

    if (pthis->actor.params == ARROW_CS_NUT) {
        pthis->isCsNut = true;
        pthis->actor.params = ARROW_NUT;
    }

    if (pthis->actor.params <= ARROW_SEED) {

        if (pthis->actor.params <= ARROW_0E) {
            SkelAnime_Init(globalCtx, &pthis->skelAnime, &gArrowSkel, &gArrow2Anim, NULL, NULL, 0);
        }

        if (pthis->actor.params <= ARROW_NORMAL) {
            if (pthis->actor.params == ARROW_NORMAL_HORSE) {
                blureNormal.elemDuration = 4;
            } else {
                blureNormal.elemDuration = 16;
            }

            Effect_Add(globalCtx, &pthis->effectIndex, EFFECT_BLURE2, 0, 0, &blureNormal);

        } else if (pthis->actor.params == ARROW_FIRE) {

            Effect_Add(globalCtx, &pthis->effectIndex, EFFECT_BLURE2, 0, 0, &blureFire);

        } else if (pthis->actor.params == ARROW_ICE) {

            Effect_Add(globalCtx, &pthis->effectIndex, EFFECT_BLURE2, 0, 0, &blureIce);

        } else if (pthis->actor.params == ARROW_LIGHT) {

            Effect_Add(globalCtx, &pthis->effectIndex, EFFECT_BLURE2, 0, 0, &blureLight);
        }

        Collider_InitQuad(globalCtx, &pthis->collider);
        Collider_SetQuad(globalCtx, &pthis->collider, &pthis->actor, &sColliderInit);

        if (pthis->actor.params <= ARROW_NORMAL) {
            pthis->collider.info.toucherFlags &= ~0x18;
            pthis->collider.info.toucherFlags |= 0;
        }

        if (pthis->actor.params < 0) {
            pthis->collider.base.atFlags = (AT_ON | AT_TYPE_ENEMY);
        } else if (pthis->actor.params <= ARROW_SEED) {
            pthis->collider.info.toucher.dmgFlags = dmgFlags[pthis->actor.params];
            LOG_HEX("pthis->at_info.cl_elem.at_btl_info.at_type", pthis->collider.info.toucher.dmgFlags,
                    "../z_en_arrow.c", 707);
        }
    }

    EnArrow_SetupAction(pthis, EnArrow_Shoot);
}

void EnArrow_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnArrow* pthis = (EnArrow*)thisx;

    if (pthis->actor.params <= ARROW_LIGHT) {
        Effect_Delete(globalCtx, pthis->effectIndex);
    }

    SkelAnime_Free(&pthis->skelAnime, globalCtx);
    Collider_DestroyQuad(globalCtx, &pthis->collider);

    if ((pthis->hitActor != NULL) && (pthis->hitActor->update != NULL)) {
        pthis->hitActor->flags &= ~ACTOR_FLAG_15;
    }
}

void EnArrow_Shoot(EnArrow* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->actor.parent == NULL) {
        if ((pthis->actor.params != ARROW_NUT) && (player->unk_A73 == 0)) {
            Actor_Kill(&pthis->actor);
            return;
        }

        switch (pthis->actor.params) {
            case ARROW_SEED:
                func_8002F7DC(&player->actor, NA_SE_IT_SLING_SHOT);
                break;

            case ARROW_NORMAL_LIT:
            case ARROW_NORMAL_HORSE:
            case ARROW_NORMAL:
                func_8002F7DC(&player->actor, NA_SE_IT_ARROW_SHOT);
                break;

            case ARROW_FIRE:
            case ARROW_ICE:
            case ARROW_LIGHT:
                func_8002F7DC(&player->actor, NA_SE_IT_MAGIC_ARROW_SHOT);
                break;
        }

        EnArrow_SetupAction(pthis, EnArrow_Fly);
        Math_Vec3f_Copy(&pthis->unk_210, &pthis->actor.world.pos);

        if (pthis->actor.params >= ARROW_SEED) {
            func_8002D9A4(&pthis->actor, 80.0f);
            pthis->timer = 15;
            pthis->actor.shape.rot.x = pthis->actor.shape.rot.y = pthis->actor.shape.rot.z = 0;
        } else {
            func_8002D9A4(&pthis->actor, 150.0f);
            pthis->timer = 12;
        }
    }
}

void func_809B3CEC(GlobalContext* globalCtx, EnArrow* pthis) {
    EnArrow_SetupAction(pthis, func_809B4640);
    Animation_PlayOnce(&pthis->skelAnime, &gArrow1Anim);
    pthis->actor.world.rot.y += (s32)(24576.0f * (Rand_ZeroOne() - 0.5f)) + 0x8000;
    pthis->actor.velocity.y += (pthis->actor.speedXZ * (0.4f + (0.4f * Rand_ZeroOne())));
    pthis->actor.speedXZ *= (0.04f + 0.3f * Rand_ZeroOne());
    pthis->timer = 50;
    pthis->actor.gravity = -1.5f;
}

void EnArrow_CarryActor(EnArrow* pthis, GlobalContext* globalCtx) {
    CollisionPoly* hitPoly;
    Vec3f posDiffLastFrame;
    Vec3f actorNextPos;
    Vec3f hitPos;
    f32 temp_f12;
    f32 scale;
    s32 bgId;

    Math_Vec3f_Diff(&pthis->actor.world.pos, &pthis->unk_210, &posDiffLastFrame);

    temp_f12 = ((pthis->actor.world.pos.x - pthis->hitActor->world.pos.x) * posDiffLastFrame.x) +
               ((pthis->actor.world.pos.y - pthis->hitActor->world.pos.y) * posDiffLastFrame.y) +
               ((pthis->actor.world.pos.z - pthis->hitActor->world.pos.z) * posDiffLastFrame.z);

    if (!(temp_f12 < 0.0f)) {
        scale = Math3D_Vec3fMagnitudeSq(&posDiffLastFrame);

        if (!(scale < 1.0f)) {
            scale = temp_f12 / scale;
            Math_Vec3f_Scale(&posDiffLastFrame, scale);
            Math_Vec3f_Sum(&pthis->hitActor->world.pos, &posDiffLastFrame, &actorNextPos);

            if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &pthis->hitActor->world.pos, &actorNextPos, &hitPos,
                                        &hitPoly, true, true, true, true, &bgId)) {
                pthis->hitActor->world.pos.x = hitPos.x + ((actorNextPos.x <= hitPos.x) ? 1.0f : -1.0f);
                pthis->hitActor->world.pos.y = hitPos.y + ((actorNextPos.y <= hitPos.y) ? 1.0f : -1.0f);
                pthis->hitActor->world.pos.z = hitPos.z + ((actorNextPos.z <= hitPos.z) ? 1.0f : -1.0f);
            } else {
                Math_Vec3f_Copy(&pthis->hitActor->world.pos, &actorNextPos);
            }
        }
    }
}

void EnArrow_Fly(EnArrow* pthis, GlobalContext* globalCtx) {
    CollisionPoly* hitPoly;
    s32 bgId;
    Vec3f hitPoint;
    Vec3f posCopy;
    s32 atTouched;
    u16 sfxId;
    Actor* hitActor;
    Vec3f sp60;
    Vec3f sp54;

    if (DECR(pthis->timer) == 0) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->timer < 7.2000003f) {
        pthis->actor.gravity = -0.4f;
    }

    atTouched = (pthis->actor.params != ARROW_NORMAL_LIT) && (pthis->actor.params <= ARROW_SEED) &&
                (pthis->collider.base.atFlags & AT_HIT);

    if (atTouched || pthis->touchedPoly) {
        if (pthis->actor.params >= ARROW_SEED) {
            if (atTouched) {
                pthis->actor.world.pos.x = (pthis->actor.world.pos.x + pthis->actor.prevPos.x) * 0.5f;
                pthis->actor.world.pos.y = (pthis->actor.world.pos.y + pthis->actor.prevPos.y) * 0.5f;
                pthis->actor.world.pos.z = (pthis->actor.world.pos.z + pthis->actor.prevPos.z) * 0.5f;
            }

            if (pthis->actor.params == ARROW_NUT) {
                iREG(50) = -1;
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_M_FIRE1, pthis->actor.world.pos.x,
                            pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0);
                sfxId = NA_SE_IT_DEKU;
            } else {
                sfxId = NA_SE_IT_SLING_REFLECT;
            }

            EffectSsStone1_Spawn(globalCtx, &pthis->actor.world.pos, 0);
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, sfxId);
            Actor_Kill(&pthis->actor);
        } else {
            EffectSsHitMark_SpawnCustomScale(globalCtx, 0, 150, &pthis->actor.world.pos);

            if (atTouched && (pthis->collider.info.atHitInfo->elemType != ELEMTYPE_UNK4)) {
                hitActor = pthis->collider.base.at;

                if ((hitActor->update != NULL) && (!(pthis->collider.base.atFlags & AT_BOUNCED)) &&
                    (hitActor->flags & ACTOR_FLAG_14)) {
                    pthis->hitActor = hitActor;
                    EnArrow_CarryActor(pthis, globalCtx);
                    Math_Vec3f_Diff(&hitActor->world.pos, &pthis->actor.world.pos, &pthis->unk_250);
                    hitActor->flags |= ACTOR_FLAG_15;
                    pthis->collider.base.atFlags &= ~AT_HIT;
                    pthis->actor.speedXZ /= 2.0f;
                    pthis->actor.velocity.y /= 2.0f;
                } else {
                    pthis->hitFlags |= 1;
                    pthis->hitFlags |= 2;

                    if (pthis->collider.info.atHitInfo->bumperFlags & 2) {
                        pthis->actor.world.pos.x = pthis->collider.info.atHitInfo->bumper.hitPos.x;
                        pthis->actor.world.pos.y = pthis->collider.info.atHitInfo->bumper.hitPos.y;
                        pthis->actor.world.pos.z = pthis->collider.info.atHitInfo->bumper.hitPos.z;
                    }

                    func_809B3CEC(globalCtx, pthis);
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_ARROW_STICK_CRE);
                }
            } else if (pthis->touchedPoly) {
                EnArrow_SetupAction(pthis, func_809B45E0);
                Animation_PlayOnce(&pthis->skelAnime, &gArrow2Anim);

                if (pthis->actor.params >= ARROW_NORMAL_LIT) {
                    pthis->timer = 60;
                } else {
                    pthis->timer = 20;
                }

                Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_ARROW_STICK_OBJ);
                pthis->hitFlags |= 1;
            }
        }
    } else {
        Math_Vec3f_Copy(&pthis->unk_210, &pthis->actor.world.pos);
        Actor_MoveForward(&pthis->actor);

        if ((pthis->touchedPoly =
                 BgCheck_ProjectileLineTest(&globalCtx->colCtx, &pthis->actor.prevPos, &pthis->actor.world.pos, &hitPoint,
                                            &pthis->actor.wallPoly, true, true, true, true, &bgId))) {
            func_8002F9EC(globalCtx, &pthis->actor, pthis->actor.wallPoly, bgId, &hitPoint);
            Math_Vec3f_Copy(&posCopy, &pthis->actor.world.pos);
            Math_Vec3f_Copy(&pthis->actor.world.pos, &hitPoint);
        }

        if (pthis->actor.params <= ARROW_0E) {
            pthis->actor.shape.rot.x = Math_Atan2S(pthis->actor.speedXZ, -pthis->actor.velocity.y);
        }
    }

    if (pthis->hitActor != NULL) {
        if (pthis->hitActor->update != NULL) {
            Math_Vec3f_Sum(&pthis->unk_210, &pthis->unk_250, &sp60);
            Math_Vec3f_Sum(&pthis->actor.world.pos, &pthis->unk_250, &sp54);

            if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &sp60, &sp54, &hitPoint, &hitPoly, true, true, true, true,
                                        &bgId)) {
                pthis->hitActor->world.pos.x = hitPoint.x + ((sp54.x <= hitPoint.x) ? 1.0f : -1.0f);
                pthis->hitActor->world.pos.y = hitPoint.y + ((sp54.y <= hitPoint.y) ? 1.0f : -1.0f);
                pthis->hitActor->world.pos.z = hitPoint.z + ((sp54.z <= hitPoint.z) ? 1.0f : -1.0f);
                Math_Vec3f_Diff(&pthis->hitActor->world.pos, &pthis->actor.world.pos, &pthis->unk_250);
                pthis->hitActor->flags &= ~ACTOR_FLAG_15;
                pthis->hitActor = NULL;
            } else {
                Math_Vec3f_Sum(&pthis->actor.world.pos, &pthis->unk_250, &pthis->hitActor->world.pos);
            }

            if (pthis->touchedPoly && (pthis->hitActor != NULL)) {
                pthis->hitActor->flags &= ~ACTOR_FLAG_15;
                pthis->hitActor = NULL;
            }
        } else {
            pthis->hitActor = NULL;
        }
    }
}

void func_809B45E0(EnArrow* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (DECR(pthis->timer) == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void func_809B4640(EnArrow* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Actor_MoveForward(&pthis->actor);

    if (DECR(pthis->timer) == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnArrow_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnArrow* pthis = (EnArrow*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->isCsNut || ((pthis->actor.params >= ARROW_NORMAL_LIT) && (player->unk_A73 != 0)) ||
        !Player_InBlockingCsMode(globalCtx, player)) {
        pthis->actionFunc(pthis, globalCtx);
    }

    if ((pthis->actor.params >= ARROW_FIRE) && (pthis->actor.params <= ARROW_0E)) {
        s16 elementalActorIds[] = { ACTOR_ARROW_FIRE, ACTOR_ARROW_ICE,  ACTOR_ARROW_LIGHT,
                                    ACTOR_ARROW_FIRE, ACTOR_ARROW_FIRE, ACTOR_ARROW_FIRE };

        if (pthis->actor.child == NULL) {
            Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, elementalActorIds[pthis->actor.params - 3],
                               pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0);
        }
    } else if (pthis->actor.params == ARROW_NORMAL_LIT) {
        static Vec3f velocity = { 0.0f, 0.5f, 0.0f };
        static Vec3f accel = { 0.0f, 0.5f, 0.0f };
        static Color_RGBA8 primColor = { 255, 255, 100, 255 };
        static Color_RGBA8 envColor = { 255, 50, 0, 0 };
        // spawn dust for the flame
        func_8002836C(globalCtx, &pthis->unk_21C, &velocity, &accel, &primColor, &envColor, 100, 0, 8);
    }
}

void func_809B4800(EnArrow* pthis, GlobalContext* globalCtx) {
    static Vec3f D_809B4E88 = { 0.0f, 400.0f, 1500.0f };
    static Vec3f D_809B4E94 = { 0.0f, -400.0f, 1500.0f };
    static Vec3f D_809B4EA0 = { 0.0f, 0.0f, -300.0f };
    Vec3f sp44;
    Vec3f sp38;
    s32 addBlureVertex;

    Matrix_MultVec3f(&D_809B4EA0, &pthis->unk_21C);

    if (EnArrow_Fly == pthis->actionFunc) {
        Matrix_MultVec3f(&D_809B4E88, &sp44);
        Matrix_MultVec3f(&D_809B4E94, &sp38);

        if (pthis->actor.params <= ARROW_SEED) {
            addBlureVertex = pthis->actor.params <= ARROW_LIGHT;

            if (pthis->hitActor == NULL) {
                addBlureVertex &= func_80090480(globalCtx, &pthis->collider, &pthis->weaponInfo, &sp44, &sp38);
            } else {
                if (addBlureVertex) {
                    if ((sp44.x == pthis->weaponInfo.tip.x) && (sp44.y == pthis->weaponInfo.tip.y) &&
                        (sp44.z == pthis->weaponInfo.tip.z) && (sp38.x == pthis->weaponInfo.base.x) &&
                        (sp38.y == pthis->weaponInfo.base.y) && (sp38.z == pthis->weaponInfo.base.z)) {
                        addBlureVertex = false;
                    }
                }
            }

            if (addBlureVertex) {
                EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->effectIndex), &sp44, &sp38);
            }
        }
    }
}

void EnArrow_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnArrow* pthis = (EnArrow*)thisx;
    u8 alpha;
    f32 scale;

    if (pthis->actor.params <= ARROW_0E) {
        func_80093D18(globalCtx->state.gfxCtx);
        SkelAnime_DrawLod(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL, NULL, pthis,
                          (pthis->actor.projectedPos.z < MREG(95)) ? 0 : 1);
    } else if (pthis->actor.speedXZ != 0.0f) {
        alpha = (Math_CosS(pthis->timer * 5000) * 127.5f) + 127.5f;

        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_arrow.c", 1346);

        func_80093C14(globalCtx->state.gfxCtx);

        if (pthis->actor.params == ARROW_SEED) {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
            gDPSetEnvColor(POLY_XLU_DISP++, 0, 255, 255, alpha);
            scale = 50.0f;
        } else {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 12, 0, 0, 255);
            gDPSetEnvColor(POLY_XLU_DISP++, 250, 250, 0, alpha);
            scale = 150.0f;
        }

        Matrix_Push();
        Matrix_Mult(&globalCtx->billboardMtxF, MTXMODE_APPLY);
        // redundant check because pthis is contained in an if block for non-zero speed
        Matrix_RotateZ((pthis->actor.speedXZ == 0.0f) ? 0.0f
                                                     : ((globalCtx->gameplayFrames & 0xFF) * 4000) * (M_PI / 0x8000),
                       MTXMODE_APPLY);
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_arrow.c", 1374),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gEffSparklesDL);
        Matrix_Pop();
        Matrix_RotateY(pthis->actor.world.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_arrow.c", 1381);
    }

    func_809B4800(pthis, globalCtx);
}
