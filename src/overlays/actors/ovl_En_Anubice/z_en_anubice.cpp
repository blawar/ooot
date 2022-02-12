#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ANUBICE_Z_EN_ANUBICE_C
#include "actor_common.h"
/*
 * File: z_en_anubice.c
 * Overlay: ovl_En_Anubice
 * Description: Anubis Body
 */

#include "z_en_anubice.h"
#include "objects/object_anubice/object_anubice.h"
#include "overlays/actors/ovl_En_Anubice_Tag/z_en_anubice_tag.h"
#include "overlays/actors/ovl_Bg_Hidan_Curtain/z_bg_hidan_curtain.h"
#include "vt.h"
#include "def/code_800FCE80.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)

void EnAnubice_Init(Actor* thisx, GlobalContext* globalCtx);
void EnAnubice_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnAnubice_Update(Actor* thisx, GlobalContext* globalCtx);
void EnAnubice_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnAnubice_FindFlameCircles(EnAnubice* pthis, GlobalContext* globalCtx);
void EnAnubice_SetupIdle(EnAnubice* pthis, GlobalContext* globalCtx);
void EnAnubice_Idle(EnAnubice* pthis, GlobalContext* globalCtx);
void EnAnubice_GoToHome(EnAnubice* pthis, GlobalContext* globalCtx);
void EnAnubis_SetupShootFireball(EnAnubice* pthis, GlobalContext* globalCtx);
void EnAnubis_ShootFireball(EnAnubice* pthis, GlobalContext* globalCtx);
void EnAnubice_Die(EnAnubice* pthis, GlobalContext* globalCtx);

ActorInit En_Anubice_InitVars = {
    ACTOR_EN_ANUBICE,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_ANUBICE,
    sizeof(EnAnubice),
    (ActorFunc)EnAnubice_Init,
    (ActorFunc)EnAnubice_Destroy,
    (ActorFunc)EnAnubice_Update,
    (ActorFunc)EnAnubice_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 29, 103, 0, { 0, 0, 0 } },
};

static DamageTable sDamageTable[] = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(0, 0xF),
    /* Slingshot     */ DMG_ENTRY(0, 0xF),
    /* Explosive     */ DMG_ENTRY(0, 0xF),
    /* Boomerang     */ DMG_ENTRY(0, 0xF),
    /* Normal arrow  */ DMG_ENTRY(0, 0xF),
    /* Hammer swing  */ DMG_ENTRY(1, 0xF),
    /* Hookshot      */ DMG_ENTRY(2, 0xF),
    /* Kokiri sword  */ DMG_ENTRY(0, 0xF),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(6, 0xF),
    /* Fire arrow    */ DMG_ENTRY(2, 0x2),
    /* Ice arrow     */ DMG_ENTRY(0, 0xF),
    /* Light arrow   */ DMG_ENTRY(0, 0xF),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0xF),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0xF),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0xF),
    /* Fire magic    */ DMG_ENTRY(3, 0x2),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(0, 0xF),
    /* Giant spin    */ DMG_ENTRY(6, 0xF),
    /* Master spin   */ DMG_ENTRY(2, 0xF),
    /* Kokiri jump   */ DMG_ENTRY(0, 0xF),
    /* Giant jump    */ DMG_ENTRY(12, 0xF),
    /* Master jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

void EnAnubice_Hover(EnAnubice* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->hoverVelocityTimer += 1500.0f;
    pthis->targetHeight = player->actor.world.pos.y + pthis->playerHeightOffset;
    Math_ApproachF(&pthis->actor.world.pos.y, pthis->targetHeight, 0.1f, 10.0f);
    Math_ApproachF(&pthis->playerHeightOffset, 10.0f, 0.1f, 0.5f);
    pthis->actor.velocity.y = Math_SinS(pthis->hoverVelocityTimer);
}

void EnAnubice_SetFireballRot(EnAnubice* pthis, GlobalContext* globalCtx) {
    f32 xzdist;
    f32 x;
    f32 y;
    f32 z;
    Player* player = GET_PLAYER(globalCtx);

    x = player->actor.world.pos.x - pthis->fireballPos.x;
    y = player->actor.world.pos.y + 10.0f - pthis->fireballPos.y;
    z = player->actor.world.pos.z - pthis->fireballPos.z;
    xzdist = sqrtf(SQ(x) + SQ(z));

    pthis->fireballRot.x = -RADF_TO_BINANG(Math_FAtan2F(y, xzdist));
    pthis->fireballRot.y = RADF_TO_BINANG(Math_FAtan2F(x, z));
}

void EnAnubice_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnAnubice* pthis = (EnAnubice*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 20.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gAnubiceSkel, &gAnubiceIdleAnim, pthis->jointTable, pthis->morphTable,
                   16);

    osSyncPrintf("\n\n");
    // "☆☆☆☆☆ Anubis occurence ☆☆☆☆☆"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ アヌビス発生 ☆☆☆☆☆ \n" VT_RST);

    pthis->actor.naviEnemyId = 0x3A;

    Collider_InitCylinder(globalCtx, &pthis->col);
    Collider_SetCylinder(globalCtx, &pthis->col, &pthis->actor, &sCylinderInit);

    Actor_SetScale(&pthis->actor, 0.015f);

    pthis->actor.colChkInfo.damageTable = sDamageTable;
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->actor.shape.yOffset = -4230.0f;
    pthis->focusHeightOffset = 0.0f;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->home = pthis->actor.world.pos;
    pthis->actor.targetMode = 3;
    pthis->actionFunc = EnAnubice_FindFlameCircles;
}

void EnAnubice_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnAnubice* pthis = (EnAnubice*)thisx;
    EnAnubiceTag* temp_v1;

    Collider_DestroyCylinder(globalCtx, &pthis->col);

    if (pthis->actor.params != 0) {
        if (pthis->actor.parent) {}

        temp_v1 = (EnAnubiceTag*)pthis->actor.parent;
        if (temp_v1 != NULL && temp_v1->actor.update != NULL) {
            temp_v1->anubis = NULL;
        }
    }
}

void EnAnubice_FindFlameCircles(EnAnubice* pthis, GlobalContext* globalCtx) {
    Actor* currentProp;
    s32 flameCirclesFound;

    if (pthis->isMirroringLink) {
        if (!pthis->hasSearchedForFlameCircles) {
            flameCirclesFound = 0;
            currentProp = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;
            while (currentProp != NULL) {
                if (currentProp->id != ACTOR_BG_HIDAN_CURTAIN) {
                    currentProp = currentProp->next;
                } else {
                    pthis->flameCircles[flameCirclesFound] = (BgHidanCurtain*)currentProp;
                    // "☆☆☆☆☆ How many fires? ☆☆☆☆☆"
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 火は幾つ？ ☆☆☆☆☆ %d\n" VT_RST, flameCirclesFound);
                    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 火は幾つ？ ☆☆☆☆☆ %x\n" VT_RST,
                                 pthis->flameCircles[flameCirclesFound]);
                    if (flameCirclesFound < 4) {
                        flameCirclesFound++;
                    }
                    currentProp = currentProp->next;
                }
            }
            pthis->hasSearchedForFlameCircles = true;
        }
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actionFunc = EnAnubice_SetupIdle;
    }
}

void EnAnubice_SetupIdle(EnAnubice* pthis, GlobalContext* globalCtx) {
    f32 lastFrame = Animation_GetLastFrame(&gAnubiceIdleAnim);

    Animation_Change(&pthis->skelAnime, &gAnubiceIdleAnim, 1.0f, 0.0f, (s16)lastFrame, ANIMMODE_LOOP, -10.0f);

    pthis->actionFunc = EnAnubice_Idle;
    pthis->actor.velocity.x = pthis->actor.velocity.z = pthis->actor.gravity = 0.0f;
}

void EnAnubice_Idle(EnAnubice* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    Math_ApproachZeroF(&pthis->actor.shape.yOffset, 0.5f, 300.0f);
    Math_ApproachF(&pthis->focusHeightOffset, 70.0f, 0.5f, 5.0f);

    if (!pthis->isKnockedback) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 3000, 0);
    }

    if (pthis->actor.shape.yOffset > -2.0f) {
        pthis->actor.shape.yOffset = 0.0f;

        if (player->swordState != 0) {
            pthis->actionFunc = EnAnubis_SetupShootFireball;
        } else if (pthis->isLinkOutOfRange) {
            pthis->actor.velocity.y = 0.0f;
            pthis->actor.gravity = -1.0f;
            pthis->actionFunc = EnAnubice_GoToHome;
        }
    }
}

void EnAnubice_GoToHome(EnAnubice* pthis, GlobalContext* globalCtx) {
    f32 xzdist;
    f32 xRatio;
    f32 zRatio;
    f32 x;
    f32 z;

    SkelAnime_Update(&pthis->skelAnime);
    Math_ApproachF(&pthis->actor.shape.yOffset, -4230.0f, 0.5f, 300.0f);
    Math_ApproachZeroF(&pthis->focusHeightOffset, 0.5f, 5.0f);

    if (!pthis->isKnockedback) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 3000, 0);
    }

    if (fabsf(pthis->home.x - pthis->actor.world.pos.x) > 3.0f && fabsf(pthis->home.z - pthis->actor.world.pos.z) > 3.0f) {
        x = pthis->home.x - pthis->actor.world.pos.x;
        z = pthis->home.z - pthis->actor.world.pos.z;
        xzdist = sqrtf(SQ(x) + SQ(z));
        xRatio = ((x) / xzdist);
        zRatio = ((z) / xzdist);
        pthis->actor.world.pos.x += (xRatio * 8);
        pthis->actor.world.pos.z += (zRatio * 8.0f);
    } else if (pthis->actor.shape.yOffset < -4220.0f) {
        pthis->actor.shape.yOffset = -4230.0f;
        pthis->isMirroringLink = pthis->isLinkOutOfRange = false;
        pthis->actionFunc = EnAnubice_FindFlameCircles;
        pthis->actor.gravity = 0.0f;
    }
}

void EnAnubis_SetupShootFireball(EnAnubice* pthis, GlobalContext* globalCtx) {
    f32 lastFrame = Animation_GetLastFrame(&gAnubiceAttackingAnim);

    pthis->animLastFrame = lastFrame;
    Animation_Change(&pthis->skelAnime, &gAnubiceAttackingAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, -10.0f);
    pthis->actionFunc = EnAnubis_ShootFireball;
    pthis->actor.velocity.x = pthis->actor.velocity.z = 0.0f;
}

void EnAnubis_ShootFireball(EnAnubice* pthis, GlobalContext* globalCtx) {
    f32 curFrame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);

    if (!pthis->isKnockedback) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 3000, 0);
    }

    EnAnubice_SetFireballRot(pthis, globalCtx);

    if (curFrame == 12.0f) {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ANUBICE_FIRE, pthis->fireballPos.x,
                    pthis->fireballPos.y + 15.0f, pthis->fireballPos.z, pthis->fireballRot.x, pthis->fireballRot.y, 0, 0);
    }

    if (pthis->animLastFrame <= curFrame) {
        pthis->actionFunc = EnAnubice_SetupIdle;
    }
}

void EnAnubice_SetupDie(EnAnubice* pthis, GlobalContext* globalCtx) {
    f32 lastFrame = Animation_GetLastFrame(&gAnubiceFallDownAnim);

    pthis->animLastFrame = lastFrame;
    Animation_Change(&pthis->skelAnime, &gAnubiceFallDownAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, -20.0f);

    pthis->unk_256 = false;
    pthis->unk_258 = 0;
    pthis->deathTimer = 20;
    pthis->actor.velocity.x = pthis->actor.velocity.z = 0.0f;
    pthis->actor.gravity = -1.0f;

    if (BgCheck_SphVsFirstPoly(&globalCtx->colCtx, &pthis->fireballPos, 70.0f)) {
        pthis->unk_256 = true;
        pthis->unk_258 = pthis->actor.shape.rot.x - 0x7F00;
    }

    pthis->actionFunc = EnAnubice_Die;
}

void EnAnubice_Die(EnAnubice* pthis, GlobalContext* globalCtx) {
    f32 curFrame;
    f32 phi_f2;
    Vec3f sp4C = { 0.0f, 0.0f, 0.0f };
    Vec3f fireEffectPos = { 0.0f, 0.0f, 0.0f };
    s32 pad;

    SkelAnime_Update(&pthis->skelAnime);
    Math_ApproachZeroF(&pthis->actor.shape.shadowScale, 0.4f, 0.25f);

    if (pthis->unk_256) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->unk_258, 1, 10000, 0);
        if (fabsf(pthis->actor.shape.rot.y - pthis->unk_258) < 100.0f) {
            pthis->unk_256 = false;
        }
    }

    curFrame = pthis->skelAnime.curFrame;
    phi_f2 = curFrame * -3000.0f;
    phi_f2 = CLAMP_MIN(phi_f2, -11000.0f);

    Matrix_RotateY(BINANG_TO_RAD(pthis->actor.shape.rot.y), MTXMODE_NEW);
    Matrix_RotateX(BINANG_TO_RAD(phi_f2), MTXMODE_APPLY);
    sp4C.y = Rand_CenteredFloat(10.0f) + 30.0f;
    Matrix_MultVec3f(&sp4C, &fireEffectPos);
    fireEffectPos.x += pthis->actor.world.pos.x + Rand_CenteredFloat(40.0f);
    fireEffectPos.y += pthis->actor.world.pos.y + Rand_CenteredFloat(40.0f);
    fireEffectPos.z += pthis->actor.world.pos.z + Rand_CenteredFloat(30.0f);
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0x80, 0, 8);
    EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &fireEffectPos, 100, 0, 0, -1);

    if (pthis->animLastFrame <= curFrame && (pthis->actor.bgCheckFlags & 1)) {
        Math_ApproachF(&pthis->actor.shape.yOffset, -4230.0f, 0.5f, 300.0f);
        if (pthis->actor.shape.yOffset < -2000.0f) {
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xC0);
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnAnubice_Update(Actor* thisx, GlobalContext* globalCtx) {
    f32 zero;
    BgHidanCurtain* flameCircle;
    s32 i;
    Vec3f sp48;
    Vec3f sp3C;
    EnAnubice* pthis = (EnAnubice*)thisx;

    if (pthis->actionFunc != EnAnubice_SetupDie && pthis->actionFunc != EnAnubice_Die &&
        pthis->actor.shape.yOffset == 0.0f) {
        EnAnubice_Hover(pthis, globalCtx);
        for (i = 0; i < 5; i++) {
            flameCircle = pthis->flameCircles[i];

            if (flameCircle != NULL && fabsf(flameCircle->actor.world.pos.x - pthis->actor.world.pos.x) < 60.0f &&
                fabsf(pthis->flameCircles[i]->actor.world.pos.z - pthis->actor.world.pos.z) < 60.0f &&
                flameCircle->timer != 0) {
                Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
                pthis->actor.flags &= ~ACTOR_FLAG_0;
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_ANUBIS_DEAD);
                pthis->actionFunc = EnAnubice_SetupDie;
                return;
            }
        }

        if (pthis->col.base.acFlags & 2) {
            pthis->col.base.acFlags &= ~2;
            if (pthis->actor.colChkInfo.damageEffect == 2) {
                Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
                pthis->actor.flags &= ~ACTOR_FLAG_0;
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_ANUBIS_DEAD);
                pthis->actionFunc = EnAnubice_SetupDie;
                return;
            }

            if (!pthis->isKnockedback) {
                pthis->knockbackTimer = 10;
                pthis->isKnockedback = true;

                sp48.x = 0.0f;
                sp48.y = 0.0f;
                sp48.z = -10.0f;
                sp3C.x = 0.0f;
                sp3C.y = 0.0f;
                sp3C.z = 0.0f;

                Matrix_RotateY(BINANG_TO_RAD(pthis->actor.shape.rot.y), MTXMODE_NEW);
                Matrix_MultVec3f(&sp48, &sp3C);

                pthis->actor.velocity.x = sp3C.x;
                pthis->actor.velocity.z = sp3C.z;
                pthis->knockbackRecoveryVelocity.x = -sp3C.x;
                pthis->knockbackRecoveryVelocity.z = -sp3C.z;

                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_CUTBODY);
            }
        }

        if (pthis->isKnockedback) {
            pthis->actor.shape.rot.y += 6500;
            Math_ApproachF(&pthis->actor.velocity.x, pthis->knockbackRecoveryVelocity.x, 0.3f, 1.0f);
            Math_ApproachF(&pthis->actor.velocity.z, pthis->knockbackRecoveryVelocity.z, 0.3f, 1.0f);

            zero = 0.0f;
            if (zero) {}

            if (pthis->knockbackTimer == 0) {
                pthis->actor.velocity.x = pthis->actor.velocity.z = 0.0f;
                pthis->knockbackRecoveryVelocity.x = pthis->knockbackRecoveryVelocity.z = 0.0f;
                pthis->isKnockedback = false;
            }
        }
    }

    pthis->timeAlive++;

    if (pthis->knockbackTimer != 0) {
        pthis->knockbackTimer--;
    }

    if (pthis->deathTimer != 0) {
        pthis->deathTimer--;
    }

    pthis->actionFunc(pthis, globalCtx);

    pthis->actor.velocity.y += pthis->actor.gravity;
    func_8002D7EC(&pthis->actor);

    if (!pthis->isLinkOutOfRange) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 5.0f, 10.0f, 0x1D);
    } else {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 5.0f, 10.0f, 0x1C);
    }

    if (pthis->actionFunc != EnAnubice_SetupDie && pthis->actionFunc != EnAnubice_Die) {
        Actor_SetFocus(&pthis->actor, pthis->focusHeightOffset);
        Collider_UpdateCylinder(&pthis->actor, &pthis->col);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->col.base);

        if (!pthis->isKnockedback && pthis->actor.shape.yOffset == 0.0f) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->col.base);
        }
    }
}

s32 EnAnubis_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                              void* thisx) {
    EnAnubice* pthis = (EnAnubice*)thisx;

    if (limbIndex == 13) {
        rot->z += pthis->unk_278;
    }

    return false;
}

void EnAnubis_PostLimbDraw(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnAnubice* pthis = (EnAnubice*)thisx;
    Vec3f pos = { 0.0f, 0.0f, 0.0f };

    if (limbIndex == 13) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_anubice.c", 853);

        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_anubice.c", 856),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gAnubiceEyesDL);
        Matrix_MultVec3f(&pos, &pthis->fireballPos);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_anubice.c", 868);
    }
}

void EnAnubice_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnAnubice* pthis = (EnAnubice*)thisx;

    func_80093D84(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnAnubis_OverrideLimbDraw,
                      EnAnubis_PostLimbDraw, pthis);
}
