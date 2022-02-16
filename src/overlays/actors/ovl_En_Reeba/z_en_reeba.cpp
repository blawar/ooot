#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_REEBA_Z_EN_REEBA_C
#include "actor_common.h"

/*
 * File: z_en_reeba.c
 * Overlay: ovl_En_Reeba
 * Description: Leever
 */

#include "z_en_reeba.h"
#include "overlays/actors/ovl_En_Encount1/z_en_encount1.h"
#include "vt.h"
#include "objects/object_reeba/object_reeba.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_27)

void EnReeba_Init(Actor* thisx, GlobalContext* globalCtx);
void EnReeba_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnReeba_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnReeba_Update(Actor* thisx, GlobalContext* globalCtx);
void EnReeba_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80AE4F40(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE5054(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE5270(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE5688(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE56E0(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE538C(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE53AC(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE5E48(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE5854(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE5C38(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE5938(EnReeba* pthis, GlobalContext* globalCtx);
void func_80AE5A9C(EnReeba* pthis, GlobalContext* globalCtx);

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(2, 0xE),
    /* Slingshot     */ DMG_ENTRY(1, 0xE),
    /* Explosive     */ DMG_ENTRY(2, 0xE),
    /* Boomerang     */ DMG_ENTRY(1, 0xC),
    /* Normal arrow  */ DMG_ENTRY(2, 0xE),
    /* Hammer swing  */ DMG_ENTRY(2, 0xE),
    /* Hookshot      */ DMG_ENTRY(2, 0xD),
    /* Kokiri sword  */ DMG_ENTRY(1, 0xE),
    /* Master sword  */ DMG_ENTRY(4, 0xE),
    /* Giant's Knife */ DMG_ENTRY(6, 0xE),
    /* Fire arrow    */ DMG_ENTRY(2, 0xE),
    /* Ice arrow     */ DMG_ENTRY(4, 0x3),
    /* Light arrow   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0xE),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(4, 0x3),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(2, 0xE),
    /* Giant spin    */ DMG_ENTRY(8, 0xE),
    /* Master spin   */ DMG_ENTRY(4, 0xE),
    /* Kokiri jump   */ DMG_ENTRY(2, 0xE),
    /* Giant jump    */ DMG_ENTRY(8, 0xE),
    /* Master jump   */ DMG_ENTRY(4, 0xE),
    /* Unknown 1     */ DMG_ENTRY(0, 0x1),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

ActorInit En_Reeba_InitVars = {
    ACTOR_EN_REEBA,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_REEBA,
    sizeof(EnReeba),
    (ActorFunc)EnReeba_Init,
    (ActorFunc)EnReeba_Destroy,
    (ActorFunc)EnReeba_Update,
    (ActorFunc)EnReeba_Draw,
    (ActorFunc)EnReeba_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT5,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x08, 0x08 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 20, 40, 0, { 0, 0, 0 } },
};

void EnReeba_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnReeba* pthis = (EnReeba*)thisx;
    s32 surfaceType;

    pthis->actor.naviEnemyId = 0x47;
    pthis->actor.targetMode = 3;
    pthis->actor.gravity = -3.5f;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    SkelAnime_Init(globalCtx, &pthis->skelanime, &object_reeba_Skel_001EE8, &object_reeba_Anim_0001E4, pthis->jointTable,
                   pthis->morphTable, 18);
    pthis->actor.colChkInfo.mass = MASS_HEAVY;
    pthis->actor.colChkInfo.health = 4;
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->isBig = pthis->actor.params;
    pthis->scale = 0.04f;

    if (pthis->isBig) {
        pthis->collider.dim.radius = 35;
        pthis->collider.dim.height = 45;
        pthis->scale *= 1.5f;
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ リーバぼす登場 ☆☆☆☆☆ %f\n" VT_RST, pthis->scale);
        pthis->actor.colChkInfo.health = 20;
        pthis->collider.info.toucher.effect = 4;
        pthis->collider.info.toucher.damage = 16;
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ENEMY);
    }

    pthis->actor.shape.yOffset = pthis->unk_284 = pthis->scale * -27500.0f;
    ActorShape_Init(&pthis->actor.shape, pthis->actor.shape.yOffset, ActorShadow_DrawCircle, 0.0f);
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 35.0f, 60.0f, 60.0f, 0x1D);

    surfaceType = func_80041D4C(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);

    if ((surfaceType != 4) && (surfaceType != 7)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->actionfunc = func_80AE4F40;
}

void EnReeba_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnReeba* pthis = (EnReeba*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);

    if (pthis->actor.parent != NULL) {
        EnEncount1* spawner = (EnEncount1*)pthis->actor.parent;

        if (spawner->actor.update != NULL) {
            if (spawner->curNumSpawn > 0) {
                spawner->curNumSpawn--;
            }
            if (pthis->isBig) {
                spawner->bigLeever = NULL;
                spawner->timer = 600;
            }
        }
    }
}

void func_80AE4F40(EnReeba* pthis, GlobalContext* globalCtx) {
    f32 frames = Animation_GetLastFrame(&object_reeba_Anim_0001E4);
    Player* player = GET_PLAYER(globalCtx);
    s16 playerSpeed;

    Animation_Change(&pthis->skelanime, &object_reeba_Anim_0001E4, 2.0f, 0.0f, frames, ANIMMODE_LOOP, -10.0f);

    playerSpeed = fabsf(player->linearVelocity);
    pthis->unk_278 = 20 - playerSpeed * 2;
    if (pthis->unk_278 < 0) {
        pthis->unk_278 = 2;
    }
    if (pthis->unk_278 > 20) {
        pthis->unk_278 = 20;
    }

    pthis->actor.flags &= ~ACTOR_FLAG_27;
    pthis->actor.world.pos.y = pthis->actor.floorHeight;

    if (pthis->isBig) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIVA_BIG_APPEAR);
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIVA_APPEAR);
    }

    pthis->actionfunc = func_80AE5054;
}

void func_80AE5054(EnReeba* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 playerLinearVel;

    SkelAnime_Update(&pthis->skelanime);

    if ((globalCtx->gameplayFrames % 4) == 0) {
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, pthis->actor.shape.shadowScale, 1,
                                 8.0f, 500, 10, 1);
    }

    if (pthis->unk_278 == 0) {
        Math_ApproachF(&pthis->actor.shape.shadowScale, 12.0f, 1.0f, 1.0f);
        if (pthis->actor.shape.yOffset < 0.0f) {
            Math_ApproachZeroF(&pthis->actor.shape.yOffset, 1.0f, pthis->unk_288);
            Math_ApproachF(&pthis->unk_288, 300.0f, 1.0f, 5.0f);
        } else {
            pthis->unk_288 = 0.0f;
            pthis->actor.shape.yOffset = 0.0f;
            playerLinearVel = player->linearVelocity;

            switch (pthis->unk_280) {
                case 0:
                    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
                    break;
                case 1:
                    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer + (800.0f * playerLinearVel);
                    break;
                case 2:
                case 3:
                    pthis->actor.world.rot.y =
                        pthis->actor.yawTowardsPlayer +
                        (player->actor.shape.rot.y - pthis->actor.yawTowardsPlayer) * (playerLinearVel * 0.15f);
                    break;
                case 4:
                    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer - (800.0f * playerLinearVel);
                    break;
            }

            if (pthis->isBig) {
                pthis->actionfunc = func_80AE538C;
            } else {
                pthis->unk_272 = 130;
                pthis->actor.speedXZ = Rand_ZeroFloat(4.0f) + 6.0f;
                pthis->actionfunc = func_80AE5270;
            }
        }
    }
}

void func_80AE5270(EnReeba* pthis, GlobalContext* globalCtx) {
    s32 surfaceType;

    SkelAnime_Update(&pthis->skelanime);

    if (pthis->actor.shape.shadowScale < 12.0f) {
        Math_ApproachF(&pthis->actor.shape.shadowScale, 12.0f, 3.0f, 1.0f);
    }

    surfaceType = func_80041D4C(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);

    if ((surfaceType != 4) && (surfaceType != 7)) {
        pthis->actor.speedXZ = 0.0f;
        pthis->actionfunc = func_80AE5688;
    } else if ((pthis->unk_272 == 0) || (pthis->actor.xzDistToPlayer < 30.0f) || (pthis->actor.xzDistToPlayer > 400.0f) ||
               (pthis->actor.bgCheckFlags & 8)) {
        pthis->actionfunc = func_80AE5688;
    } else if (pthis->unk_274 == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIVA_MOVE);
        pthis->unk_274 = 10;
    }
}

void func_80AE538C(EnReeba* pthis, GlobalContext* globalCtx) {
    pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_2;
    pthis->actionfunc = func_80AE53AC;
}

void func_80AE53AC(EnReeba* pthis, GlobalContext* globalCtx) {
    f32 speed;
    s16 yawDiff;
    s16 yaw;
    s32 surfaceType;

    SkelAnime_Update(&pthis->skelanime);

    if (pthis->actor.shape.shadowScale < 12.0f) {
        Math_ApproachF(&pthis->actor.shape.shadowScale, 12.0f, 3.0f, 1.0f);
    }

    surfaceType = func_80041D4C(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);

    if (((surfaceType != 4) && (surfaceType != 7)) || (pthis->actor.xzDistToPlayer > 400.0f) ||
        (pthis->actor.bgCheckFlags & 8)) {
        pthis->actionfunc = func_80AE5688;
    } else {
        if ((pthis->actor.xzDistToPlayer < 70.0f) && (pthis->unk_270 == 0)) {
            pthis->unk_270 = 30;
        }

        speed = (pthis->actor.xzDistToPlayer - 20.0f) / ((Rand_ZeroOne() * 50.0f) + 150.0f);
        pthis->actor.speedXZ += speed * 1.8f;
        if (pthis->actor.speedXZ >= 3.0f) {
            pthis->actor.speedXZ = 3.0f;
        }
        if (pthis->actor.speedXZ < -3.0f) {
            pthis->actor.speedXZ = -3.0f;
        }

        yawDiff = (pthis->unk_270 == 0) ? pthis->actor.yawTowardsPlayer : -pthis->actor.yawTowardsPlayer;
        yawDiff -= pthis->actor.world.rot.y;
        yaw = (yawDiff > 0) ? ((yawDiff / 31.0f) + 10.0f) : ((yawDiff / 31.0f) - 10.0f);
        pthis->actor.world.rot.y += yaw * 2.0f;

        if (pthis->unk_274 == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIVA_MOVE);
            pthis->unk_274 = 20;
        }
    }
}

void func_80AE561C(EnReeba* pthis, GlobalContext* globalCtx) {
    Math_ApproachZeroF(&pthis->actor.speedXZ, 1.0f, 0.3f);

    if (pthis->unk_272 == 0) {
        if (pthis->isBig) {
            pthis->actionfunc = func_80AE538C;
        } else {
            pthis->actionfunc = func_80AE5688;
        }
    }
}

void func_80AE5688(EnReeba* pthis, GlobalContext* globalCtx) {
    pthis->unk_27E = 0;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_AKINDONUTS_HIDE);
    pthis->actor.flags |= ACTOR_FLAG_27;
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
    pthis->actionfunc = func_80AE56E0;
}

void func_80AE56E0(EnReeba* pthis, GlobalContext* globalCtx) {
    Math_ApproachZeroF(&pthis->actor.shape.shadowScale, 1.0f, 0.3f);
    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.1f, 0.3f);
    SkelAnime_Update(&pthis->skelanime);

    if ((pthis->unk_284 + 10.0f) <= pthis->actor.shape.yOffset) {
        if ((globalCtx->gameplayFrames % 4) == 0) {
            Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, pthis->actor.shape.shadowScale, 1,
                                     8.0f, 500, 10, 1);
        }

        Math_ApproachF(&pthis->actor.shape.yOffset, pthis->unk_284, 1.0f, pthis->unk_288);
        Math_ApproachF(&pthis->unk_288, 300.0f, 1.0f, 5.0f);
    } else {
        Actor_Kill(&pthis->actor);
    }
}

void func_80AE57F0(EnReeba* pthis, GlobalContext* globalCtx) {
    pthis->unk_276 = 14;
    pthis->actor.speedXZ = -8.0f;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
    pthis->actionfunc = func_80AE5854;
}

void func_80AE5854(EnReeba* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->actor.speedXZ < 0.0f) {
        pthis->actor.speedXZ += 1.0f;
    }

    if (pthis->unk_276 == 0) {
        if (pthis->isBig) {
            pthis->unk_270 = 30;
            pthis->actionfunc = func_80AE538C;
        } else {
            pthis->actionfunc = func_80AE5688;
        }
    }
}

void func_80AE58EC(EnReeba* pthis, GlobalContext* globalCtx) {
    pthis->unk_278 = 14;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    pthis->actor.speedXZ = -8.0f;
    pthis->actor.flags |= ACTOR_FLAG_27;
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
    pthis->actionfunc = func_80AE5938;
}

void func_80AE5938(EnReeba* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    f32 scale;

    if (pthis->unk_278 != 0) {
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ += 1.0f;
        }
    } else {
        pthis->actor.speedXZ = 0.0f;

        if ((pthis->unk_27E == 4) || (pthis->actor.colChkInfo.health != 0)) {
            if (pthis->unk_27E == 2) {
                pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(20.0f);
                pos.y = pthis->actor.world.pos.y + Rand_CenteredFloat(20.0f);
                pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(20.0f);
                scale = 3.0f;

                if (pthis->isBig) {
                    scale = 6.0f;
                }

                EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &pos, 150, 150, 150, 250, 235, 245, 255, scale);
            }

            pthis->unk_278 = 66;
            pthis->actionfunc = func_80AE5E48;
        } else {
            pthis->unk_278 = 30;
            pthis->actionfunc = func_80AE5A9C;
        }
    }
}

void func_80AE5A9C(EnReeba* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    f32 scale;

    if (pthis->unk_278 != 0) {
        if ((pthis->unk_27E == 2) && ((pthis->unk_278 & 0xF) == 0)) {
            pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(20.0f);
            pos.y = pthis->actor.world.pos.y + Rand_CenteredFloat(20.0f);
            pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(20.0f);

            scale = 3.0f;
            if (pthis->isBig) {
                scale = 6.0f;
            }

            EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &pos, 150, 150, 150, 250, 235, 245, 255, scale);
        }
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIVA_DEAD);
        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
        pthis->actionfunc = func_80AE5C38;
    }
}

void func_80AE5BC4(EnReeba* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = -8.0f;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
    pthis->unk_278 = 14;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionfunc = func_80AE5C38;
}

void func_80AE5C38(EnReeba* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };

    if (pthis->unk_278 != 0) {
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ += 1.0f;
        }
    } else {
        pthis->actor.speedXZ = 0.0f;
        Math_ApproachZeroF(&pthis->scale, 0.1f, 0.01f);

        if (pthis->scale < 0.01f) {
            pos.x = pthis->actor.world.pos.x;
            pos.y = pthis->actor.world.pos.y;
            pos.z = pthis->actor.world.pos.z;

            velocity.y = 4.0f;

            EffectSsDeadDb_Spawn(globalCtx, &pos, &velocity, &accel, 120, 0, 255, 255, 255, 255, 255, 0, 0, 1, 9, true);

            if (!pthis->isBig) {
                Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pos, 0xE0);
            } else {
                Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pos, 0xC0);
            }

            if (pthis->actor.parent != NULL) {
                EnEncount1* spawner = (EnEncount1*)pthis->actor.parent;

                if ((spawner->actor.update != NULL) && !pthis->isBig) {
                    if (spawner->killCount < 10) {
                        spawner->killCount++;
                    }
                    // "How many are dead?"
                    osSyncPrintf("\n\n");
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 何匹ＤＥＡＤ？ ☆☆☆☆☆%d\n" VT_RST, spawner->killCount);
                    osSyncPrintf("\n\n");
                }

                Actor_Kill(&pthis->actor);
            }
        }
    }
}

void func_80AE5E48(EnReeba* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_278 < 37) {
        pthis->actor.shape.rot.x = Rand_CenteredFloat(3000.0f);
        pthis->actor.shape.rot.z = Rand_CenteredFloat(3000.0f);

        if (pthis->unk_278 == 0) {
            if (pthis->isBig) {
                pthis->actionfunc = func_80AE538C;
            } else {
                pthis->actionfunc = func_80AE5688;
            }
        }
    }
}

void func_80AE5EDC(EnReeba* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;

        if ((pthis->actionfunc != func_80AE5C38) && (pthis->actionfunc != func_80AE5854)) {
            pthis->actor.shape.rot.x = pthis->actor.shape.rot.z = 0;
            pthis->unk_27E = 0;

            switch (pthis->actor.colChkInfo.damageEffect) {
                case 11: // none
                case 12: // boomerang
                    if ((pthis->actor.colChkInfo.health > 1) && (pthis->unk_27E != 4)) {
                        pthis->unk_27E = 4;
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
                        Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 0x50);
                        pthis->actionfunc = func_80AE58EC;
                        break;
                    }
                case 13: // hookshot/longshot
                    if ((pthis->actor.colChkInfo.health > 2) && (pthis->unk_27E != 4)) {
                        pthis->unk_27E = 4;
                        Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 0x50);
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
                        pthis->actionfunc = func_80AE58EC;
                        break;
                    }
                case 14:
                    pthis->unk_27C = 6;
                    Actor_ApplyDamage(&pthis->actor);
                    if (pthis->actor.colChkInfo.health == 0) {
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIVA_DEAD);
                        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                        pthis->actionfunc = func_80AE5BC4;
                    } else {
                        if (pthis->actionfunc == func_80AE5E48) {
                            pthis->actor.shape.rot.x = pthis->actor.shape.rot.z = 0;
                        }
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIVA_DAMAGE);
                        pthis->actionfunc = func_80AE57F0;
                    }
                    break;
                case 3: // ice arrows/ice magic
                    Actor_ApplyDamage(&pthis->actor);
                    pthis->unk_27C = 2;
                    pthis->unk_27E = 2;
                    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 80);
                    pthis->actionfunc = func_80AE58EC;
                    break;
                case 1: // unknown
                    if (pthis->unk_27E != 4) {
                        pthis->unk_27E = 4;
                        Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 80);
                        pthis->actionfunc = func_80AE58EC;
                    }
                    break;
            }
        }
    }
}

void EnReeba_Update(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnReeba* pthis = (EnReeba*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    func_80AE5EDC(pthis, globalCtx);
    pthis->actionfunc(pthis, globalCtx);
    Actor_SetScale(&pthis->actor, pthis->scale);

    if (pthis->unk_270 != 0) {
        pthis->unk_270--;
    }

    if (pthis->unk_272 != 0) {
        pthis->unk_272--;
    }

    if (pthis->unk_278 != 0) {
        pthis->unk_278--;
    }

    if (pthis->unk_274 != 0) {
        pthis->unk_274--;
    }

    if (pthis->unk_276 != 0) {
        pthis->unk_276--;
    }

    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 35.0f, 60.0f, 60.0f, 0x1D);

    if (pthis->collider.base.atFlags & AT_BOUNCED) {
        pthis->collider.base.atFlags &= ~AT_BOUNCED;

        if ((pthis->actionfunc == func_80AE5270) || (pthis->actionfunc == func_80AE53AC)) {
            pthis->actor.speedXZ = 8.0f;
            pthis->actor.world.rot.y *= -1.0f;
            pthis->unk_272 = 14;
            pthis->actionfunc = func_80AE561C;
            return;
        }
    }

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        if ((pthis->collider.base.at == &player->actor) && !pthis->isBig && (pthis->actionfunc != func_80AE56E0)) {
            pthis->actionfunc = func_80AE5688;
        }
    }

    pthis->actor.focus.pos = pthis->actor.world.pos;

    if (!pthis->isBig) {
        pthis->actor.focus.pos.y += 15.0f;
    } else {
        pthis->actor.focus.pos.y += 30.0f;
    }

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

    if ((pthis->actor.shape.yOffset >= -700.0f) && (pthis->actor.colChkInfo.health > 0) &&
        (pthis->actionfunc != func_80AE56E0)) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

        if (!(pthis->actor.shape.yOffset < 0.0f)) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

            if ((pthis->actionfunc == func_80AE5270) || (pthis->actionfunc == func_80AE53AC)) {
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }
        }
    }
}

void EnReeba_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnReeba* pthis = (EnReeba*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_reeba.c", 1062);

    func_80093D18(globalCtx->state.gfxCtx);

    if (pthis->isBig) {
        gDPSetPrimColor(POLY_OPA_DISP++, 0x0, 0x01, 155, 55, 255, 255);
    } else {
        gDPSetPrimColor(POLY_OPA_DISP++, 0x0, 0x01, 255, 255, 255, 255);
    }

    SkelAnime_DrawOpa(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable, NULL, NULL, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_reeba.c", 1088);
}

void EnReeba_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, 0x0),
        /* Deku stick    */ DMG_ENTRY(2, 0xE),
        /* Slingshot     */ DMG_ENTRY(1, 0xE),
        /* Explosive     */ DMG_ENTRY(2, 0xE),
        /* Boomerang     */ DMG_ENTRY(1, 0xC),
        /* Normal arrow  */ DMG_ENTRY(2, 0xE),
        /* Hammer swing  */ DMG_ENTRY(2, 0xE),
        /* Hookshot      */ DMG_ENTRY(2, 0xD),
        /* Kokiri sword  */ DMG_ENTRY(1, 0xE),
        /* Master sword  */ DMG_ENTRY(4, 0xE),
        /* Giant's Knife */ DMG_ENTRY(6, 0xE),
        /* Fire arrow    */ DMG_ENTRY(2, 0xE),
        /* Ice arrow     */ DMG_ENTRY(4, 0x3),
        /* Light arrow   */ DMG_ENTRY(2, 0xE),
        /* Unk arrow 1   */ DMG_ENTRY(2, 0xE),
        /* Unk arrow 2   */ DMG_ENTRY(2, 0xE),
        /* Unk arrow 3   */ DMG_ENTRY(2, 0xE),
        /* Fire magic    */ DMG_ENTRY(0, 0x0),
        /* Ice magic     */ DMG_ENTRY(4, 0x3),
        /* Light magic   */ DMG_ENTRY(0, 0x0),
        /* Shield        */ DMG_ENTRY(0, 0x0),
        /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
        /* Kokiri spin   */ DMG_ENTRY(2, 0xE),
        /* Giant spin    */ DMG_ENTRY(8, 0xE),
        /* Master spin   */ DMG_ENTRY(4, 0xE),
        /* Kokiri jump   */ DMG_ENTRY(2, 0xE),
        /* Giant jump    */ DMG_ENTRY(8, 0xE),
        /* Master jump   */ DMG_ENTRY(4, 0xE),
        /* Unknown 1     */ DMG_ENTRY(0, 0x1),
        /* Unblockable   */ DMG_ENTRY(0, 0x0),
        /* Hammer jump   */ DMG_ENTRY(0, 0x0),
        /* Unknown 2     */ DMG_ENTRY(0, 0x0),
    };

    En_Reeba_InitVars = {
        ACTOR_EN_REEBA,
        ACTORCAT_MISC,
        FLAGS,
        OBJECT_REEBA,
        sizeof(EnReeba),
        (ActorFunc)EnReeba_Init,
        (ActorFunc)EnReeba_Destroy,
        (ActorFunc)EnReeba_Update,
        (ActorFunc)EnReeba_Draw,
        (ActorFunc)EnReeba_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_HIT5,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x08, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 20, 40, 0, { 0, 0, 0 } },
    };

}
