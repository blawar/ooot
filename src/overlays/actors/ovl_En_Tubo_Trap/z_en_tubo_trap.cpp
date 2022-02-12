#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_TUBO_TRAP_Z_EN_TUBO_TRAP_C
#include "actor_common.h"
/*
 * File: z_en_tubo_trap.c
 * Overlay: ovl_En_Tubo_Trap
 * Description: Flying pot enemy
 */

#include "z_en_tubo_trap.h"
#include "objects/gameplay_dangeon_keep/gameplay_dangeon_keep.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "vt.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_4

void EnTuboTrap_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTuboTrap_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTuboTrap_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTuboTrap_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnTuboTrap_WaitForProximity(EnTuboTrap* pthis, GlobalContext* globalCtx);
void EnTuboTrap_Levitate(EnTuboTrap* pthis, GlobalContext* globalCtx);
void EnTuboTrap_Fly(EnTuboTrap* pthis, GlobalContext* globalCtx);

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x04 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 9, 23, 0, { 0 } },
};

ActorInit En_Tubo_Trap_InitVars = {
    ACTOR_EN_TUBO_TRAP,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(EnTuboTrap),
    (ActorFunc)EnTuboTrap_Init,
    (ActorFunc)EnTuboTrap_Destroy,
    (ActorFunc)EnTuboTrap_Update,
    (ActorFunc)EnTuboTrap_Draw,
};

void EnTuboTrap_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnTuboTrap* pthis = (EnTuboTrap*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 2.0f);
    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 壷トラップ ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.params); // "Urn Trap"
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    Actor_SetScale(&pthis->actor, 0.1f);
    pthis->actionFunc = EnTuboTrap_WaitForProximity;
}

void EnTuboTrap_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnTuboTrap* pthis = (EnTuboTrap*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnTuboTrap_DropCollectible(EnTuboTrap* pthis, GlobalContext* globalCtx) {
    s16 params = pthis->actor.params;
    s16 param3FF = (params >> 6) & 0x3FF;

    if (param3FF >= 0 && param3FF < 0x1A) {
        Item_DropCollectible(globalCtx, &pthis->actor.world.pos, param3FF | ((params & 0x3F) << 8));
    }
}

void EnTuboTrap_SpawnEffectsOnLand(EnTuboTrap* pthis, GlobalContext* globalCtx) {
    f32 rand;
    f32 cos;
    f32 sin;
    Vec3f pos;
    Vec3f velocity;
    s16 var;
    s32 arg5;
    s32 i;
    Vec3f* actorPos = &pthis->actor.world.pos;

    for (i = 0, var = 0; i < 15; i++, var += 20000) {
        sin = Math_SinS(var);
        cos = Math_CosS(var);
        pos.x = sin * 8.0f;
        pos.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        pos.z = cos * 8.0f;

        velocity.x = pos.x * 0.23f;
        velocity.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        velocity.z = pos.z * 0.23f;

        pos.x += actorPos->x;
        pos.y += actorPos->y;
        pos.z += actorPos->z;

        rand = Rand_ZeroOne();
        if (rand < 0.2f) {
            arg5 = 96;
        } else if (rand < 0.6f) {
            arg5 = 64;
        } else {
            arg5 = 32;
        }

        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, actorPos, -240, arg5, 10, 10, 0,
                             (Rand_ZeroOne() * 65.0f) + 15.0f, 0, 32, 60, KAKERA_COLOR_NONE,
                             OBJECT_GAMEPLAY_DANGEON_KEEP, gPotFragmentDL);
    }

    func_80033480(globalCtx, actorPos, 30.0f, 4, 20, 50, 0);
}

void EnTuboTrap_SpawnEffectsInWater(EnTuboTrap* pthis, GlobalContext* globalCtx) {
    f32 rand;
    f32 cos;
    f32 sin;
    Vec3f pos;
    Vec3f velocity;
    s16 var;
    s32 arg5;
    s32 i;
    Vec3f* actorPos = &pthis->actor.world.pos;

    pos = *actorPos;
    pos.y += pthis->actor.yDistToWater;

    EffectSsGSplash_Spawn(globalCtx, &pos, 0, 0, 0, 400);

    for (i = 0, var = 0; i < 15; i++, var += 20000) {
        sin = Math_SinS(var);
        cos = Math_CosS(var);
        pos.x = sin * 8.0f;
        pos.y = (Rand_ZeroOne() * 5.0f) + 2.0f;
        pos.z = cos * 8.0f;

        velocity.x = pos.x * 0.20f;
        velocity.y = (Rand_ZeroOne() * 4.0f) + 2.0f;
        velocity.z = pos.z * 0.20f;

        pos.x += actorPos->x;
        pos.y += actorPos->y;
        pos.z += actorPos->z;

        rand = Rand_ZeroOne();
        if (rand < 0.2f) {
            arg5 = 64;
        } else {
            arg5 = 32;
        }

        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, actorPos, -180, arg5, 30, 30, 0,
                             (Rand_ZeroOne() * 65.0f) + 15.0f, 0, 32, 70, KAKERA_COLOR_NONE,
                             OBJECT_GAMEPLAY_DANGEON_KEEP, gPotFragmentDL);
    }
}

void EnTuboTrap_HandleImpact(EnTuboTrap* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Player* player2 = GET_PLAYER(globalCtx);

    if ((pthis->actor.bgCheckFlags & 0x20) && (pthis->actor.yDistToWater > 15.0f)) {
        EnTuboTrap_SpawnEffectsInWater(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_BOMB_DROP_WATER);
        EnTuboTrap_DropCollectible(pthis, globalCtx);
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->collider.base.atFlags & AT_BOUNCED) {
        pthis->collider.base.atFlags &= ~AT_BOUNCED;
        EnTuboTrap_SpawnEffectsOnLand(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_IT_SHIELD_REFLECT_SW);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_POT_BROKEN);
        EnTuboTrap_DropCollectible(pthis, globalCtx);
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        EnTuboTrap_SpawnEffectsOnLand(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_EXPLOSION);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_POT_BROKEN);
        EnTuboTrap_DropCollectible(pthis, globalCtx);
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        if (pthis->collider.base.at == &player->actor) {
            EnTuboTrap_SpawnEffectsOnLand(pthis, globalCtx);
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_POT_BROKEN);
            Audio_PlaySoundAtPosition(globalCtx, &player2->actor.world.pos, 40, NA_SE_PL_BODY_HIT);
            EnTuboTrap_DropCollectible(pthis, globalCtx);
            Actor_Kill(&pthis->actor);
            return;
        }
    }

    if ((pthis->actor.bgCheckFlags & 8) || (pthis->actor.bgCheckFlags & 1)) {
        EnTuboTrap_SpawnEffectsOnLand(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_POT_BROKEN);
        EnTuboTrap_DropCollectible(pthis, globalCtx);
        Actor_Kill(&pthis->actor);
        return;
    }
}

void EnTuboTrap_WaitForProximity(EnTuboTrap* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 targetHeight;

    if (BREG(2) != 0) {
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ わて     ☆☆☆☆☆ %f\n" VT_RST, pthis->actor.world.pos.y);   // "You"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ おいどん ☆☆☆☆☆ %f\n" VT_RST, player->actor.world.pos.y); // "Me"
        osSyncPrintf("\n\n");
    }

    if (pthis->actor.xzDistToPlayer < 200.0f && pthis->actor.world.pos.y <= player->actor.world.pos.y) {
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ENEMY);
        pthis->actor.flags |= ACTOR_FLAG_0;
        targetHeight = 40.0f + -10.0f * gSaveContext.linkAge;

        pthis->targetY = player->actor.world.pos.y + targetHeight;
        if (pthis->targetY < pthis->actor.world.pos.y) {
            pthis->targetY = pthis->actor.world.pos.y + targetHeight;
        }

        pthis->originPos = pthis->actor.world.pos;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_POT_MOVE_START);
        pthis->actionFunc = EnTuboTrap_Levitate;
    }
}

void EnTuboTrap_Levitate(EnTuboTrap* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.rot.y += 5000;
    Math_ApproachF(&pthis->actor.world.pos.y, pthis->targetY, 0.8f, 3.0f);

    if (fabsf(pthis->actor.world.pos.y - pthis->targetY) < 10.0f) {
        pthis->actor.speedXZ = 10.0f;
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actionFunc = EnTuboTrap_Fly;
    }
}

void EnTuboTrap_Fly(EnTuboTrap* pthis, GlobalContext* globalCtx) {
    f32 dx = pthis->originPos.x - pthis->actor.world.pos.x;
    f32 dy = pthis->originPos.y - pthis->actor.world.pos.y;
    f32 dz = pthis->originPos.z - pthis->actor.world.pos.z;

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TUBOOCK_FLY - SFX_FLAG);

    if (240.0f < sqrtf(SQ(dx) + SQ(dy) + SQ(dz))) {
        Math_ApproachF(&pthis->actor.gravity, -3.0f, 0.2f, 0.5f);
    }

    pthis->actor.shape.rot.y += 5000;
    EnTuboTrap_HandleImpact(pthis, globalCtx);
}

void EnTuboTrap_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnTuboTrap* pthis = (EnTuboTrap*)thisx;
    s32 pad;

    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 20.0f, 0x1D);
    Actor_SetFocus(&pthis->actor, 0.0f);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnTuboTrap_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gPotDL);
}
