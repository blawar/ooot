#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DODOJR_Z_EN_DODOJR_C
#include "actor_common.h"
/*
 * File: z_en_dodojr.c
 * Overlay: ovl_En_Dodojr
 * Description: Baby Dodongo
 */

#include "z_en_dodojr.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "objects/object_dodojr/object_dodojr.h"
#include "def/code_800FD970.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnDodojr_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDodojr_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDodojr_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDodojr_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809F73AC(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F7BE4(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F74C4(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F758C(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F786C(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F799C(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F78EC(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F773C(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F77AC(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F784C(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F7AB8(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F7A00(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F7B3C(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F7C48(EnDodojr* pthis, GlobalContext* globalCtx);
void func_809F768C(EnDodojr* pthis, GlobalContext* globalCtx);

ActorInit En_Dodojr_InitVars = {
    ACTOR_EN_DODOJR,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DODOJR,
    sizeof(EnDodojr),
    (ActorFunc)EnDodojr_Init,
    (ActorFunc)EnDodojr_Destroy,
    (ActorFunc)EnDodojr_Update,
    (ActorFunc)EnDodojr_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT6,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFC5FFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 18, 20, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInit = { 1, 2, 25, 25, 0xFF };

void EnDodojr_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDodojr* pthis = (EnDodojr*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, NULL, 18.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &object_dodojr_Skel_0020E0, &object_dodojr_Anim_0009D4,
                   pthis->jointTable, pthis->morphTable, 15);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(4), &sColChkInit);

    pthis->actor.naviEnemyId = 0xE;
    pthis->actor.flags &= ~ACTOR_FLAG_0;

    Actor_SetScale(&pthis->actor, 0.02f);

    pthis->actionFunc = func_809F73AC;
}

void EnDodojr_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDodojr* pthis = (EnDodojr*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_809F64D0(EnDodojr* pthis) {
    Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_BOMB_EXPLOSION);
    Actor_SetColorFilter(&pthis->actor, 0x4000, 200, 0, 8);
}

void func_809F6510(EnDodojr* pthis, GlobalContext* globalCtx, s32 count) {
    Color_RGBA8 prim = { 170, 130, 90, 255 };
    Color_RGBA8 env = { 100, 60, 20, 0 };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.3f, 0.0f };
    Vec3f pos;
    s16 angle = ((Rand_ZeroOne() - 0.5f) * 65536.0f);
    s32 i;

    pos.y = pthis->dustPos.y;

    for (i = count; i >= 0; i--, angle += (s16)(0x10000 / count)) {
        accel.x = (Rand_ZeroOne() - 0.5f) * 4.0f;
        accel.z = (Rand_ZeroOne() - 0.5f) * 4.0f;

        pos.x = (Math_SinS(angle) * 22.0f) + pthis->dustPos.x;
        pos.z = (Math_CosS(angle) * 22.0f) + pthis->dustPos.z;

        func_8002836C(globalCtx, &pos, &velocity, &accel, &prim, &env, 120, 40, 10);
    }
}

void func_809F6730(EnDodojr* pthis, GlobalContext* globalCtx, Vec3f* arg2) {
    Color_RGBA8 prim = { 170, 130, 90, 255 };
    Color_RGBA8 env = { 100, 60, 20, 0 };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.3f, 0.0f };
    Vec3f pos;
    s16 angle = ((Rand_ZeroOne() - 0.5f) * 65536.0f);

    pos.y = pthis->actor.floorHeight;

    accel.x = (Rand_ZeroOne() - 0.5f) * 2;
    accel.z = (Rand_ZeroOne() - 0.5f) * 2;

    pos.x = (Math_SinS(angle) * 11.0f) + arg2->x;
    pos.z = (Math_CosS(angle) * 11.0f) + arg2->z;

    func_8002836C(globalCtx, &pos, &velocity, &accel, &prim, &env, 100, 60, 8);
}

s32 func_809F68B0(EnDodojr* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.velocity.y >= 0.0f) {
        return 0;
    }

    if (pthis->unk_1FC == 0) {
        return 0;
    }

    if (pthis->actor.bgCheckFlags & 1) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        pthis->dustPos = pthis->actor.world.pos;
        func_809F6510(pthis, globalCtx, 10);
        pthis->actor.velocity.y = 10.0f / (4 - pthis->unk_1FC);
        pthis->unk_1FC--;

        if (pthis->unk_1FC == 0) {
            pthis->actor.velocity.y = 0.0f;
            return 1;
        }
    }

    return 0;
}

void func_809F6994(EnDodojr* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&object_dodojr_Anim_000860);

    Animation_Change(&pthis->skelAnime, &object_dodojr_Anim_000860, 1.8f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP, -10.0f);
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.speedXZ = 2.6f;
    pthis->actor.gravity = -0.8f;
}

void func_809F6A20(EnDodojr* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&object_dodojr_Anim_0004A0);

    Animation_Change(&pthis->skelAnime, &object_dodojr_Anim_0004A0, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, -10.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.x = 0.0f;
    pthis->actor.velocity.z = 0.0f;
    pthis->actor.gravity = -0.8f;

    if (pthis->unk_1FC == 0) {
        pthis->unk_1FC = 3;
        pthis->actor.velocity.y = 10.0f;
    }
}

void func_809F6AC4(EnDodojr* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&object_dodojr_Anim_0005F0);

    Animation_Change(&pthis->skelAnime, &object_dodojr_Anim_0005F0, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP, 0.0f);
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = -0.8f;
}

void func_809F6B38(EnDodojr* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&object_dodojr_Anim_000724);

    Animation_Change(&pthis->skelAnime, &object_dodojr_Anim_000724, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP, -10.0f);
    pthis->actor.gravity = -0.8f;
    pthis->unk_1FC = 3;
    pthis->actor.velocity.y = 10.0f;
}

void func_809F6BBC(EnDodojr* pthis) {
    pthis->actor.shape.shadowDraw = NULL;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.home.pos = pthis->actor.world.pos;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.gravity = -0.8f;
    pthis->timer3 = 30;
    pthis->dustPos = pthis->actor.world.pos;
}

void func_809F6C24(EnDodojr* pthis) {
    Animation_Change(&pthis->skelAnime, &object_dodojr_Anim_000724, 1.0f, 8.0f, 12.0f, ANIMMODE_ONCE, 0.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_EAT);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.x = 0.0f;
    pthis->actor.velocity.z = 0.0f;
    pthis->actor.gravity = -0.8f;
}

s32 func_809F6CA4(EnDodojr* pthis, GlobalContext* globalCtx) {
    Actor* bomb;
    Vec3f unkVec = { 99999.0f, 99999.0f, 99999.0f };
    s32 retVar = 0;
    f32 xDist;
    f32 yDist;
    f32 zDist;

    bomb = globalCtx->actorCtx.actorLists[ACTORCAT_EXPLOSIVE].head;
    pthis->bomb = NULL;

    while (bomb != NULL) {
        if ((bomb->params != 0) || (bomb->parent != NULL) || (bomb->update == NULL)) {
            bomb = bomb->next;
            continue;
        }

        if (bomb->id != ACTOR_EN_BOM) {
            bomb = bomb->next;
            continue;
        }

        xDist = bomb->world.pos.x - pthis->actor.world.pos.x;
        yDist = bomb->world.pos.y - pthis->actor.world.pos.y;
        zDist = bomb->world.pos.z - pthis->actor.world.pos.z;

        if ((fabsf(xDist) >= fabsf(unkVec.x)) || (fabsf(yDist) >= fabsf(unkVec.y)) ||
            (fabsf(zDist) >= fabsf(unkVec.z))) {
            bomb = bomb->next;
            continue;
        }

        pthis->bomb = bomb;
        unkVec = bomb->world.pos;
        retVar = 1;
        bomb = bomb->next;
    }

    return retVar;
}

s32 func_809F6DD0(EnDodojr* pthis) {
    if (pthis->bomb == NULL) {
        return 0;
    } else if (pthis->bomb->parent != NULL) {
        return 0;
    } else if (Math_Vec3f_DistXYZ(&pthis->actor.world.pos, &pthis->bomb->world.pos) > 30.0f) {
        return 0;
    } else {
        pthis->bomb->parent = &pthis->actor;
        return 1;
    }
}

void func_809F6E54(EnDodojr* pthis, GlobalContext* globalCtx) {
    f32 angles[] = { 0.0f, 210.0f, 60.0f, 270.0f, 120.0f, 330.0f, 180.0f, 30.0f, 240.0f, 90.0f, 300.0f, 150.0f };
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f pos;
    s16 angleIndex;

    if ((pthis->bomb == NULL) || (pthis->bomb->update == NULL) ||
        ((pthis->bomb != NULL) && (pthis->bomb->parent != NULL))) {
        func_809F6CA4(pthis, globalCtx);
    }

    if (pthis->bomb != NULL) {
        pos = pthis->bomb->world.pos;
    } else {
        pos = player->actor.world.pos;
    }

    if (Math_Vec3f_DistXYZ(&pthis->actor.world.pos, &pos) > 80.0f) {
        angleIndex = (s16)(pthis->actor.home.pos.x + pthis->actor.home.pos.y + pthis->actor.home.pos.z +
                           globalCtx->state.frames.whole() / 30) % 12;
        angleIndex = ABS(angleIndex);
        pos.x += 80.0f * sinf(angles[angleIndex]);
        pos.z += 80.0f * cosf(angles[angleIndex]);
    }

    Math_SmoothStepToS(&pthis->actor.world.rot.y, Math_Vec3f_Yaw(&pthis->actor.world.pos, &pos), 10, 1000, 1);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

s32 func_809F706C(EnDodojr* pthis) {
    if (pthis->actor.xzDistToPlayer > 40.0f) {
        return 0;
    } else {
        return 1;
    }
}

void func_809F709C(EnDodojr* pthis) {
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_DEAD);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    func_809F6A20(pthis);
    pthis->actionFunc = func_809F7AB8;
}

s32 func_809F70E8(EnDodojr* pthis, GlobalContext* globalCtx) {
    if ((pthis->actionFunc == func_809F773C) || (pthis->actionFunc == func_809F77AC) ||
        (pthis->actionFunc == func_809F784C) || (pthis->actionFunc == func_809F7A00) ||
        (pthis->actionFunc == func_809F7AB8) || (pthis->actionFunc == func_809F7B3C) ||
        (pthis->actionFunc == func_809F7BE4)) {
        return 0;
    }

    if (globalCtx->actorCtx.unk_02 != 0) {
        if (pthis->actionFunc != func_809F73AC) {
            if (pthis->actionFunc == func_809F74C4) {
                pthis->actor.shape.shadowDraw = ActorShadow_DrawCircle;
            }

            func_809F709C(pthis);
        }
        return 0;
    }

    if (!(pthis->collider.base.acFlags & 2)) {
        return 0;
    } else {
        pthis->collider.base.acFlags &= ~2;

        if ((pthis->actionFunc == func_809F73AC) || (pthis->actionFunc == func_809F74C4)) {
            pthis->actor.shape.shadowDraw = ActorShadow_DrawCircle;
        }

        if ((pthis->actor.colChkInfo.damageEffect == 0) && (pthis->actor.colChkInfo.damage != 0)) {
            Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
            pthis->timer2 = 2;
            pthis->actionFunc = func_809F7C48;
            return 1;
        }

        if ((pthis->actor.colChkInfo.damageEffect == 1) && (pthis->actionFunc != func_809F78EC) &&
            (pthis->actionFunc != func_809F786C)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
            pthis->timer1 = 120;
            Actor_SetColorFilter(&pthis->actor, 0, 200, 0, 120);
            func_809F6A20(pthis);
            pthis->actionFunc = func_809F786C;
        }

        return 0;
    }
}

void func_809F72A4(EnDodojr* pthis, GlobalContext* globalCtx) {
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

    if ((pthis->actionFunc != func_809F73AC) && (pthis->actionFunc != func_809F7BE4)) {
        if ((pthis->actionFunc == func_809F74C4) || (pthis->actionFunc == func_809F758C) ||
            (pthis->actionFunc == func_809F799C)) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }

        if ((pthis->actionFunc == func_809F74C4) || (pthis->actionFunc == func_809F758C) ||
            (pthis->actionFunc == func_809F786C) || (pthis->actionFunc == func_809F78EC) ||
            (pthis->actionFunc == func_809F799C)) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }

        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void func_809F73AC(EnDodojr* pthis, GlobalContext* globalCtx) {
    f32 lastFrame = Animation_GetLastFrame(&object_dodojr_Anim_000860);
    Player* player = GET_PLAYER(globalCtx);
    f32 dist;

    if (!(pthis->actor.xzDistToPlayer >= 320.0f)) {
        dist = pthis->actor.world.pos.y - player->actor.world.pos.y;

        if (!(dist >= 40.0f)) {
            Animation_Change(&pthis->skelAnime, &object_dodojr_Anim_000860, 1.8f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP,
                             -10.0f);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_UP);
            pthis->actor.world.pos.y -= 60.0f;
            pthis->actor.flags |= ACTOR_FLAG_0;
            pthis->actor.world.rot.x -= 0x4000;
            pthis->actor.shape.rot.x = pthis->actor.world.rot.x;
            pthis->dustPos = pthis->actor.world.pos;
            pthis->dustPos.y = pthis->actor.floorHeight;
            pthis->actionFunc = func_809F74C4;
        }
    }
}

void func_809F74C4(EnDodojr* pthis, GlobalContext* globalCtx) {
    f32 sp2C;

    Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0, 4, 0x3E8, 0x64);
    sp2C = pthis->actor.shape.rot.x;
    sp2C /= 16384.0f;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + (60.0f * sp2C);
    func_809F6510(pthis, globalCtx, 3);

    if (sp2C == 0.0f) {
        pthis->actor.shape.shadowDraw = ActorShadow_DrawCircle;
        pthis->actor.world.rot.x = pthis->actor.shape.rot.x;
        pthis->actor.speedXZ = 2.6f;
        pthis->actionFunc = func_809F758C;
    }
}

void func_809F758C(EnDodojr* pthis, GlobalContext* globalCtx) {
    func_8002D868(&pthis->actor);
    func_809F6730(pthis, globalCtx, &pthis->actor.world.pos);

    if (DECR(pthis->timer4) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_MOVE);
        pthis->timer4 = 5;
    }

    if (func_809F6DD0(pthis) != 0) {
        func_809F6C24(pthis);
        pthis->actionFunc = func_809F768C;
        return;
    }

    func_809F6E54(pthis, globalCtx);

    if (func_809F706C(pthis) != 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_CRY);
        func_809F6B38(pthis);
        pthis->actionFunc = func_809F799C;
    }

    if (pthis->actor.bgCheckFlags & 8) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_DOWN);
        func_809F6BBC(pthis);
        pthis->actionFunc = func_809F7A00;
    }
}

void func_809F768C(EnDodojr* pthis, GlobalContext* globalCtx) {
    EnBom* bomb;

    if (((s16)pthis->skelAnime.curFrame - 8) < 4) {
        bomb = (EnBom*)pthis->bomb;
        bomb->timer++;
        pthis->bomb->world.pos = pthis->headPos;
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_K_DRINK);
        Actor_Kill(pthis->bomb);
        pthis->timer3 = 24;
        pthis->unk_1FC = 0;
        pthis->actionFunc = func_809F773C;
    }
}

void func_809F773C(EnDodojr* pthis, GlobalContext* globalCtx) {
    if (DECR(pthis->timer3) == 0) {
        func_809F64D0(pthis);
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        func_809F6A20(pthis);
        pthis->actionFunc = func_809F77AC;
    }
}

void func_809F77AC(EnDodojr* pthis, GlobalContext* globalCtx) {
    pthis->rootScale = 1.2f;
    pthis->rootScale *= ((f32)pthis->actor.colorFilterTimer / 8);
    func_8002D868(&pthis->actor);

    if (func_809F68B0(pthis, globalCtx) != 0) {
        pthis->timer3 = 60;
        func_809F6AC4(pthis);
        pthis->unk_1FC = 7;
        pthis->actionFunc = func_809F784C;
    }
}

void func_809F784C(EnDodojr* pthis, GlobalContext* globalCtx) {
    func_809F7B3C(pthis, globalCtx);
}

void func_809F786C(EnDodojr* pthis, GlobalContext* globalCtx) {
    func_8002D868(&pthis->actor);

    if (func_809F68B0(pthis, globalCtx) != 0) {
        func_809F6AC4(pthis);
        pthis->actionFunc = func_809F78EC;
    }

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, 0, 4, 1000, 10);
    pthis->actor.world.rot.x = pthis->actor.shape.rot.x;
    pthis->actor.colorFilterTimer = pthis->timer1;
}

void func_809F78EC(EnDodojr* pthis, GlobalContext* globalCtx) {
    if (DECR(pthis->timer1) != 0) {
        if (pthis->timer1 < 30) {
            if ((pthis->timer1 & 1) != 0) {
                pthis->actor.world.pos.x += 1.5f;
                pthis->actor.world.pos.z += 1.5f;
            } else {
                pthis->actor.world.pos.x -= 1.5f;
                pthis->actor.world.pos.z -= 1.5f;
            }

            return;
        }
    } else {
        func_809F6994(pthis);
        pthis->actionFunc = func_809F758C;
    }
}

void func_809F799C(EnDodojr* pthis, GlobalContext* globalCtx) {
    pthis->actor.flags |= ACTOR_FLAG_24;
    func_8002D868(&pthis->actor);

    if (func_809F68B0(pthis, globalCtx) != 0) {
        func_809F6994(pthis);
        pthis->actionFunc = func_809F758C;
    }
}

void func_809F7A00(EnDodojr* pthis, GlobalContext* globalCtx) {
    f32 tmp;

    Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0x4000, 4, 1000, 100);

    if (DECR(pthis->timer3) != 0) {
        tmp = (30 - pthis->timer3) / 30.0f;
        pthis->actor.world.pos.y = pthis->actor.home.pos.y - (60.0f * tmp);
    } else {
        Actor_Kill(&pthis->actor);
    }

    func_809F6510(pthis, globalCtx, 3);
}

void func_809F7AB8(EnDodojr* pthis, GlobalContext* globalCtx) {
    func_8002D868(&pthis->actor);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, 0, 4, 1000, 10);
    pthis->actor.world.rot.x = pthis->actor.shape.rot.x;

    if (func_809F68B0(pthis, globalCtx) != 0) {
        pthis->timer3 = 60;
        func_809F6AC4(pthis);
        pthis->unk_1FC = 7;
        pthis->actionFunc = func_809F7B3C;
    }
}

void func_809F7B3C(EnDodojr* pthis, GlobalContext* globalCtx) {
    EnBom* bomb;

    if (pthis->unk_1FC != 0) {
        if (pthis->actor.colorFilterTimer == 0) {
            Actor_SetColorFilter(&pthis->actor, 0x4000, 200, 0, pthis->unk_1FC);
            pthis->unk_1FC--;
        }
    } else {
        bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pthis->actor.world.pos.x,
                                   pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, BOMB_BODY);

        if (bomb != NULL) {
            bomb->timer = 0;
        }

        pthis->timer3 = 8;
        pthis->actionFunc = func_809F7BE4;
    }
}

void func_809F7BE4(EnDodojr* pthis, GlobalContext* globalCtx) {
    if (DECR(pthis->timer3) == 0) {
        Item_DropCollectibleRandom(globalCtx, NULL, &pthis->actor.world.pos, 0x40);
        Actor_Kill(&pthis->actor);
    }
}

void func_809F7C48(EnDodojr* pthis, GlobalContext* globalCtx) {
    if (DECR(pthis->timer2) == 0) {
        func_809F709C(pthis);
    }
}

void EnDodojr_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDodojr* pthis = (EnDodojr*)thisx;

    SkelAnime_Update(&pthis->skelAnime);
    Actor_MoveForward(&pthis->actor);
    func_809F70E8(pthis, globalCtx);

    if (pthis->actionFunc != func_809F73AC) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, pthis->collider.dim.radius, pthis->collider.dim.height, 0.0f, 5);
    }

    pthis->actionFunc(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, 10.0f);
    func_809F72A4(pthis, globalCtx);
}

s32 func_809F7D50(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnDodojr* pthis = (EnDodojr*)thisx;
    Vec3f D_809F7F64 = { 480.0f, 620.0f, 0.0f };

    if (limbIndex == 1) {
        Matrix_Scale((pthis->rootScale * 0.5f) + 1.0f, pthis->rootScale + 1.0f, (pthis->rootScale * 0.5f) + 1.0f,
                     MTXMODE_APPLY);
    }

    if (limbIndex == 4) {
        Matrix_MultVec3f(&D_809F7F64, &pthis->headPos);
    }

    return false;
}

void func_809F7DFC(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
}

void EnDodojr_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDodojr* pthis = (EnDodojr*)thisx;

    if ((pthis->actionFunc != func_809F73AC) && (pthis->actionFunc != func_809F7BE4)) {
        func_80093D18(globalCtx->state.gfxCtx);
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, func_809F7D50, func_809F7DFC,
                          &pthis->actor);
    }
}
