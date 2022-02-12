#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_VM_Z_EN_VM_C
#include "actor_common.h"
/*
 * File: z_en_vm.c
 * Overlay: ovl_En_Vm
 * Description: Beamos
 */

#include "z_en_vm.h"
#include "objects/object_vm/object_vm.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_4)

void EnVm_Init(Actor* thisx, GlobalContext* globalCtx);
void EnVm_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnVm_Update(Actor* thisx, GlobalContext* globalCtx);
void EnVm_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnVm_SetupWait(EnVm* pthis);
void EnVm_Wait(EnVm* pthis, GlobalContext* globalCtx);
void EnVm_SetupAttack(EnVm* pthis);
void EnVm_Attack(EnVm* pthis, GlobalContext* globalCtx);
void EnVm_Stun(EnVm* pthis, GlobalContext* globalCtx);
void EnVm_Die(EnVm* pthis, GlobalContext* globalCtx);

ActorInit En_Vm_InitVars = {
    ACTOR_EN_VM,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_VM,
    sizeof(EnVm),
    (ActorFunc)EnVm_Init,
    (ActorFunc)EnVm_Destroy,
    (ActorFunc)EnVm_Update,
    (ActorFunc)EnVm_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_METAL,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
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
    { 25, 70, 0, { 0, 0, 0 } },
};

static ColliderQuadInit sQuadInit1 = {
    {
        COLTYPE_METAL,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x10 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static ColliderQuadInit sQuadInit2 = {
    {
        COLTYPE_METAL,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static Vec3f D_80B2EAEC = { 0.0f, 0.0f, 0.0f };

static Vec3f D_80B2EAF8 = { 0.0f, 0.0f, 0.0f };

static Vec3f D_80B2EB04 = { 500.0f, 0.0f, 0.0f };

static Vec3f D_80B2EB10 = { -500.0f, 0.0f, 0.0f };

static Vec3f D_80B2EB1C = { 0.0f, 0.0f, 0.0f };

static Vec3f D_80B2EB28 = { 0.0f, 0.0f, 1600.0f };

static Vec3f D_80B2EB34 = { 1000.0f, 700.0f, 2000.0f };

static Vec3f D_80B2EB40 = { 1000.0f, -700.0f, 2000.0f };

static Vec3f D_80B2EB4C = { -1000.0f, 700.0f, 1500.0f };

static Vec3f D_80B2EB58 = { -1000.0f, -700.0f, 1500.0f };

static Vec3f D_80B2EB64 = { 500.0f, 0.0f, 0.0f };

static Vec3f D_80B2EB70 = { -500.0f, 0.0f, 0.0f };

static Vec3f D_80B2EB7C = { 0.4f, 0.4f, 0.4f };

static void* D_80B2EB88[] = {
    gEffEnemyDeathFlame1Tex, gEffEnemyDeathFlame2Tex,  gEffEnemyDeathFlame3Tex, gEffEnemyDeathFlame4Tex,
    gEffEnemyDeathFlame5Tex, gEffEnemyDeathFlame6Tex,  gEffEnemyDeathFlame7Tex, gEffEnemyDeathFlame8Tex,
    gEffEnemyDeathFlame9Tex, gEffEnemyDeathFlame10Tex,
};

void EnVm_SetupAction(EnVm* pthis, EnVmActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnVm_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnVm* pthis = (EnVm*)thisx;

    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gBeamosSkel, &gBeamosAnim, pthis->jointTable, pthis->morphTable, 11);
    ActorShape_Init(&thisx->shape, 0.0f, NULL, 0.0f);
    Collider_InitCylinder(globalCtx, &pthis->colliderCylinder);
    Collider_SetCylinder(globalCtx, &pthis->colliderCylinder, thisx, &sCylinderInit);
    Collider_InitQuad(globalCtx, &pthis->colliderQuad1);
    Collider_SetQuad(globalCtx, &pthis->colliderQuad1, thisx, &sQuadInit1);
    Collider_InitQuad(globalCtx, &pthis->colliderQuad2);
    Collider_SetQuad(globalCtx, &pthis->colliderQuad2, thisx, &sQuadInit2);
    pthis->beamSightRange = (thisx->params >> 8) * 40.0f;
    thisx->params &= 0xFF;
    thisx->naviEnemyId = 0x39;

    if (thisx->params == BEAMOS_LARGE) {
        thisx->colChkInfo.health = 2;
        Actor_SetScale(thisx, 0.014f);
    } else {
        thisx->colChkInfo.health = 1;
        Actor_SetScale(thisx, 0.01f);
    }

    EnVm_SetupWait(pthis);
}

void EnVm_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnVm* pthis = (EnVm*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->colliderCylinder);
}

void EnVm_SetupWait(EnVm* pthis) {
    f32 frameCount = Animation_GetLastFrame(&gBeamosAnim);

    Animation_Change(&pthis->skelAnime, &gBeamosAnim, 1.0f, frameCount, frameCount, ANIMMODE_ONCE, 0.0f);
    pthis->unk_25E = pthis->unk_260 = 0;
    pthis->unk_21C = 0;
    pthis->timer = 10;
    EnVm_SetupAction(pthis, EnVm_Wait);
}

void EnVm_Wait(EnVm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 dist;
    s16 headRot;
    s16 pad;
    s16 pitch;

    switch (pthis->unk_25E) {
        case 0:
            Math_SmoothStepToS(&pthis->beamRot.x, 0, 10, 1500, 0);
            headRot = pthis->actor.yawTowardsPlayer - pthis->headRotY - pthis->actor.shape.rot.y;
            pitch = Math_Vec3f_Pitch(&pthis->beamPos1, &player->actor.world.pos);

            if (pitch > 0x1B91) {
                pitch = 0x1B91;
            }

            dist = pthis->beamSightRange - pthis->actor.xzDistToPlayer;

            if (pthis->actor.xzDistToPlayer <= pthis->beamSightRange && ABS(headRot) <= 0x2710 && pitch >= 0xE38 &&
                pthis->actor.yDistToPlayer <= 80.0f && pthis->actor.yDistToPlayer >= -160.0f) {
                Math_SmoothStepToS(&pthis->beamRot.x, pitch, 10, 0xFA0, 0);
                if (Math_SmoothStepToS(&pthis->headRotY, pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y, 1,
                                       (ABS((s16)(dist * 180.0f)) / 3) + 0xFA0, 0) <= 5460) {
                    pthis->timer--;
                    if (pthis->timer == 0) {
                        pthis->unk_25E++;
                        pthis->skelAnime.curFrame = 0.0f;
                        pthis->skelAnime.startFrame = 0.0f;
                        pthis->skelAnime.playSpeed = 2.0f;
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BIMOS_AIM);
                    }
                }
            } else {
                pthis->headRotY -= 0x1F4;
            }

            SkelAnime_Update(&pthis->skelAnime);
            return;
        case 1:
            break;
        default:
            return;
    }

    Math_SmoothStepToS(&pthis->headRotY, pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y, 1, 0x1F40, 0);

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->unk_260++;
        pthis->skelAnime.curFrame = 0.0f;
    }

    if (pthis->unk_260 == 2) {
        pthis->beamRot.y = pthis->actor.yawTowardsPlayer;
        pthis->beamRot.x = Math_Vec3f_Pitch(&pthis->beamPos1, &player->actor.world.pos);

        if (pthis->beamRot.x > 0x1B91) {
            pthis->beamRot.x = 0x1B91;
        }

        if (pthis->beamRot.x < 0xAAA) {
            pthis->skelAnime.startFrame = pthis->skelAnime.curFrame = pthis->skelAnime.endFrame;
            pthis->unk_25E = pthis->unk_260 = 0;
            pthis->timer = 10;
            pthis->skelAnime.playSpeed = 1.0f;
        } else {
            pthis->skelAnime.curFrame = 6.0f;
            EffectSsDeadDd_Spawn(globalCtx, &pthis->beamPos2, &D_80B2EAEC, &D_80B2EAEC, 150, -25, 0, 0, 255, 0, 255, 255,
                                 255, 16, 20);
            EnVm_SetupAttack(pthis);
        }
    }
}

void EnVm_SetupAttack(EnVm* pthis) {
    Animation_Change(&pthis->skelAnime, &gBeamosAnim, 3.0f, 3.0f, 7.0f, ANIMMODE_ONCE, 0.0f);
    pthis->timer = 305;
    pthis->beamScale.x = 0.6f;
    pthis->beamSpeed = 40.0f;
    pthis->unk_21C = 1;
    pthis->colliderQuad1.base.atFlags &= ~AT_HIT;
    EnVm_SetupAction(pthis, EnVm_Attack);
}

void EnVm_Attack(EnVm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 pitch = Math_Vec3f_Pitch(&pthis->beamPos1, &player->actor.world.pos);
    f32 dist;
    Vec3f playerPos;

    if (pitch > 0x1B91) {
        pitch = 0x1B91;
    }

    if (pthis->colliderQuad1.base.atFlags & AT_HIT) {
        pthis->colliderQuad1.base.atFlags &= ~AT_HIT;
        pthis->timer = 0;

        if (pthis->beamScale.x > 0.1f) {
            pthis->beamScale.x = 0.1f;
        }
    }

    if (pthis->beamRot.x < 0xAAA || pthis->timer == 0) {
        Math_SmoothStepToF(&pthis->beamScale.x, 0.0f, 1.0f, 0.03f, 0.0f);
        pthis->unk_260 = 0;

        if (pthis->beamScale.x == 0.0f) {
            pthis->beamScale.y = pthis->beamScale.z = 0.0f;
            EnVm_SetupWait(pthis);
        }
    } else {
        if (--pthis->timer > 300) {
            return;
        }

        Math_SmoothStepToS(&pthis->headRotY, -pthis->actor.shape.rot.y + pthis->actor.yawTowardsPlayer, 10, 0xDAC, 0);
        Math_SmoothStepToS(&pthis->beamRot.y, pthis->actor.yawTowardsPlayer, 10, 0xDAC, 0);
        Math_SmoothStepToS(&pthis->beamRot.x, pitch, 10, 0xDAC, 0);
        playerPos = player->actor.world.pos;

        if (player->actor.floorHeight > BGCHECK_Y_MIN) {
            playerPos.y = player->actor.floorHeight;
        }

        dist = Math_Vec3f_DistXYZ(&pthis->beamPos1, &playerPos);
        Math_SmoothStepToF(&pthis->beamScale.z, dist, 1.0f, pthis->beamSpeed, 0.0f);
        Math_SmoothStepToF(&pthis->beamScale.x, 0.1f, 1.0f, 0.12f, 0.0f);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BIMOS_LAZER - SFX_FLAG);

        if (pthis->unk_260 > 2) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderQuad1.base);
        }

        pthis->unk_260 = 3;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->skelAnime.curFrame = pthis->skelAnime.startFrame;
    }
}

void EnVm_SetupStun(EnVm* pthis) {
    Animation_Change(&pthis->skelAnime, &gBeamosAnim, -1.0f, Animation_GetLastFrame(&gBeamosAnim), 0.0f, ANIMMODE_ONCE,
                     0.0f);
    pthis->unk_260 = 0;
    pthis->timer = 180;
    pthis->unk_25E = pthis->unk_260;
    pthis->unk_21C = 2;
    pthis->beamScale.z = 0.0f;
    pthis->beamScale.y = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    EnVm_SetupAction(pthis, EnVm_Stun);
}

void EnVm_Stun(EnVm* pthis, GlobalContext* globalCtx) {
    if (pthis->timer == 0) {
        if (SkelAnime_Update(&pthis->skelAnime)) {
            pthis->unk_25E++;
            if (pthis->unk_25E == 3) {
                EnVm_SetupWait(pthis);
            } else if (pthis->unk_25E == 1) {
                Animation_Change(&pthis->skelAnime, &gBeamosAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gBeamosAnim),
                                 ANIMMODE_ONCE, 0.0f);
            } else {
                pthis->timer = 10;
                pthis->skelAnime.curFrame = 0.0f;
                pthis->skelAnime.playSpeed = 2.0f;
            }
        }
    } else {
        Math_SmoothStepToS(&pthis->beamRot.x, 0, 10, 0x5DC, 0);
        pthis->timer--;
        SkelAnime_Update(&pthis->skelAnime);
    }
}

void EnVm_SetupDie(EnVm* pthis) {
    Animation_Change(&pthis->skelAnime, &gBeamosAnim, -1.0f, Animation_GetLastFrame(&gBeamosAnim), 0.0f, ANIMMODE_ONCE,
                     0.0f);
    pthis->timer = 33;
    pthis->unk_25E = pthis->unk_260 = 0;
    pthis->unk_21C = 3;
    pthis->beamScale.z = 0.0f;
    pthis->beamScale.y = 0.0f;
    pthis->actor.shape.yOffset = -5000.0f;
    pthis->actor.world.pos.y += 5000.0f * pthis->actor.scale.y;
    pthis->actor.velocity.y = 8.0f;
    pthis->actor.gravity = -0.5f;
    pthis->actor.speedXZ = Rand_ZeroOne() + 1.0f;
    pthis->actor.world.rot.y = Rand_CenteredFloat(65535.0f);
    EnVm_SetupAction(pthis, EnVm_Die);
}

void EnVm_Die(EnVm* pthis, GlobalContext* globalCtx) {
    EnBom* bomb;

    pthis->beamRot.x += 0x5DC;
    pthis->headRotY += 0x9C4;
    Actor_MoveForward(&pthis->actor);

    if (--pthis->timer == 0) {
        bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pthis->actor.world.pos.x,
                                   pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0x6FF, BOMB_BODY);

        if (bomb != NULL) {
            bomb->timer = 0;
        }

        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xA0);
        Actor_Kill(&pthis->actor);
    }
}

void EnVm_CheckHealth(EnVm* pthis, GlobalContext* globalCtx) {
    EnBom* bomb;

    if (Actor_GetCollidedExplosive(globalCtx, &pthis->colliderCylinder.base) != NULL) {
        pthis->actor.colChkInfo.health--;
        osSyncPrintf("hp down %d\n", pthis->actor.colChkInfo.health);
    } else {
        if (!(pthis->colliderQuad2.base.acFlags & AC_HIT) || pthis->unk_21C == 2) {
            return;
        }
        pthis->colliderQuad2.base.acFlags &= ~AC_HIT;
    }

    if (pthis->actor.colChkInfo.health != 0) {
        Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
        EnVm_SetupStun(pthis);
    } else {
        bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pthis->actor.world.pos.x,
                                   pthis->actor.world.pos.y + 20.0f, pthis->actor.world.pos.z, 0, 0, 0x601, BOMB_BODY);

        if (bomb != NULL) {
            bomb->timer = 0;
        }

        EnVm_SetupDie(pthis);
    }
}

void EnVm_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnVm* pthis = (EnVm*)thisx;
    CollisionCheckContext* colChkCtx = &globalCtx->colChkCtx;

    if (pthis->actor.colChkInfo.health != 0) {
        EnVm_CheckHealth(pthis, globalCtx);
    }

    if (pthis->unk_260 == 4) {
        EffectSsDeadDs_SpawnStationary(globalCtx, &pthis->beamPos3, 20, -1, 255, 20);
        func_80033480(globalCtx, &pthis->beamPos3, 6.0f, 1, 120, 20, 1);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BIMOS_LAZER_GND - SFX_FLAG);
    }

    pthis->actionFunc(pthis, globalCtx);
    pthis->beamTexScroll += 0xC;

    if (pthis->actor.colChkInfo.health != 0 && pthis->unk_21C != 2) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BIMOS_ROLL_HEAD - SFX_FLAG);
    }

    Collider_UpdateCylinder(&pthis->actor, &pthis->colliderCylinder);
    CollisionCheck_SetOC(globalCtx, colChkCtx, &pthis->colliderCylinder.base);

    if (pthis->actor.colorFilterTimer == 0 && pthis->actor.colChkInfo.health != 0) {
        CollisionCheck_SetAC(globalCtx, colChkCtx, &pthis->colliderCylinder.base);
    }

    CollisionCheck_SetAC(globalCtx, colChkCtx, &pthis->colliderQuad2.base);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += (6500.0f + pthis->actor.shape.yOffset) * pthis->actor.scale.y;
}

s32 EnVm_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnVm* pthis = (EnVm*)thisx;

    if (limbIndex == 2) {
        rot->x += pthis->beamRot.x;
        rot->y += pthis->headRotY;
    } else if (limbIndex == 10) {
        if (pthis->unk_21C == 3) {
            *dList = NULL;
        }
    }

    return false;
}

void EnVm_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnVm* pthis = (EnVm*)thisx;
    Vec3f sp80 = D_80B2EAF8;
    Vec3f sp74 = D_80B2EB04;
    Vec3f sp68 = D_80B2EB10;
    s32 pad;
    Vec3f posResult;
    CollisionPoly* poly;
    s32 bgId;
    f32 dist;

    if (limbIndex == 2) {
        Matrix_MultVec3f(&D_80B2EB1C, &pthis->beamPos1);
        Matrix_MultVec3f(&D_80B2EB28, &pthis->beamPos2);

        if (pthis->unk_260 >= 3) {
            poly = NULL;
            sp80.z = (pthis->beamScale.z + 500.0f) * (pthis->actor.scale.y * 10000.0f);
            Matrix_MultVec3f(&sp80, &pthis->beamPos3);

            if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &pthis->beamPos1, &pthis->beamPos3, &posResult, &poly, true,
                                        true, false, true, &bgId) == true) {
                pthis->beamScale.z = Math_Vec3f_DistXYZ(&pthis->beamPos1, &posResult) - 5.0f;
                pthis->unk_260 = 4;
                pthis->beamPos3 = posResult;
            }
            if (pthis->beamScale.z != 0.0f) {
                dist = 100.0f;
                if (pthis->actor.scale.y > 0.01f) {
                    dist = 70.0f;
                }
                sp74.z = sp68.z = Math_Vec3f_DistXYZ(&pthis->beamPos1, &pthis->beamPos3) * dist;
                Matrix_MultVec3f(&D_80B2EB64, &pthis->colliderQuad1.dim.quad[3]);
                Matrix_MultVec3f(&D_80B2EB70, &pthis->colliderQuad1.dim.quad[2]);
                Matrix_MultVec3f(&sp74, &pthis->colliderQuad1.dim.quad[1]);
                Matrix_MultVec3f(&sp68, &pthis->colliderQuad1.dim.quad[0]);
                Collider_SetQuadVertices(&pthis->colliderQuad1, &pthis->colliderQuad1.dim.quad[0],
                                         &pthis->colliderQuad1.dim.quad[1], &pthis->colliderQuad1.dim.quad[2],
                                         &pthis->colliderQuad1.dim.quad[3]);
            }
        }
        Matrix_MultVec3f(&D_80B2EB34, &pthis->colliderQuad2.dim.quad[1]);
        Matrix_MultVec3f(&D_80B2EB40, &pthis->colliderQuad2.dim.quad[0]);
        Matrix_MultVec3f(&D_80B2EB4C, &pthis->colliderQuad2.dim.quad[3]);
        Matrix_MultVec3f(&D_80B2EB58, &pthis->colliderQuad2.dim.quad[2]);
        Collider_SetQuadVertices(&pthis->colliderQuad2, &pthis->colliderQuad2.dim.quad[0],
                                 &pthis->colliderQuad2.dim.quad[1], &pthis->colliderQuad2.dim.quad[2],
                                 &pthis->colliderQuad2.dim.quad[3]);
    }
}

void EnVm_Draw(Actor* thisx, GlobalContext* globalCtx2) {
    EnVm* pthis = (EnVm*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    Vec3f actorPos;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_vm.c", 1014);

    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnVm_OverrideLimbDraw,
                      EnVm_PostLimbDraw, pthis);
    actorPos = pthis->actor.world.pos;
    func_80033C30(&actorPos, &D_80B2EB7C, 255, globalCtx);

    if (pthis->unk_260 >= 3) {
        Matrix_Translate(pthis->beamPos3.x, pthis->beamPos3.y + 10.0f, pthis->beamPos3.z, MTXMODE_NEW);
        Matrix_Scale(0.8f, 0.8f, 0.8f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vm.c", 1033),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 168);
        func_80094BC4(globalCtx->state.gfxCtx);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 255, 0);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(D_80B2EB88[globalCtx->gameplayFrames % 8]));
        gSPDisplayList(POLY_XLU_DISP++, gEffEnemyDeathFlameDL);
        Matrix_RotateY(32767.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vm.c", 1044),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(D_80B2EB88[(globalCtx->gameplayFrames + 4) % 8]));
        gSPDisplayList(POLY_XLU_DISP++, gEffEnemyDeathFlameDL);
    }
    gSPSegment(POLY_OPA_DISP++, 0x08, func_80094E78(globalCtx->state.gfxCtx, 0, pthis->beamTexScroll));
    Matrix_Translate(pthis->beamPos1.x, pthis->beamPos1.y, pthis->beamPos1.z, MTXMODE_NEW);
    Matrix_RotateZYX(pthis->beamRot.x, pthis->beamRot.y, pthis->beamRot.z, MTXMODE_APPLY);
    Matrix_Scale(pthis->beamScale.x * 0.1f, pthis->beamScale.x * 0.1f, pthis->beamScale.z * 0.0015f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vm.c", 1063),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gBeamosLaserDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_vm.c", 1068);
}
