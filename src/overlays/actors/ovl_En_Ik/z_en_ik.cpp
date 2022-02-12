#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_IK_Z_EN_IK_C
#include "actor_common.h"
/*
 * File: z_en_ik.c
 * Overlay: ovl_En_Ik
 * Description: Iron Knuckle
 */

#include "z_en_ik.h"
#include "scenes/dungeons/jyasinboss/jyasinboss_scene.h"
#include "objects/object_ik/object_ik.h"
#include "vt.h"
#include "def/code_8006BA00.h"
#include "def/code_800A9F30.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_demo.h"
#include "def/z_eff_blure.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "def/z_skin_matrix.h"

#define FLAGS ACTOR_FLAG_4

typedef void (*EnIkDrawFunc)(struct EnIk*, GlobalContext*);

void EnIk_Init(Actor* thisx, GlobalContext* globalCtx);
void EnIk_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnIk_Update(Actor* thisx, GlobalContext* globalCtx);
void EnIk_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A74714(EnIk* pthis);
void func_80A747C0(EnIk* pthis, GlobalContext* globalCtx);
void func_80A7492C(EnIk* pthis, GlobalContext* globalCtx);
void func_80A74AAC(EnIk* pthis);
void func_80A74BA4(EnIk* pthis, GlobalContext* globalCtx);
void func_80A74E2C(EnIk* pthis);
void func_80A74EBC(EnIk* pthis, GlobalContext* globalCtx);
void func_80A7506C(EnIk* pthis);
void func_80A7510C(EnIk* pthis, GlobalContext* globalCtx);
void func_80A751C8(EnIk* pthis);
void func_80A75260(EnIk* pthis, GlobalContext* globalCtx);
void func_80A753D0(EnIk* pthis);
void func_80A7545C(EnIk* pthis, GlobalContext* globalCtx);
void func_80A754A0(EnIk* pthis);
void func_80A75530(EnIk* pthis, GlobalContext* globalCtx);
void func_80A755F0(EnIk* pthis);
void func_80A7567C(EnIk* pthis, GlobalContext* globalCtx);
void func_80A758B0(EnIk* pthis, GlobalContext* globalCtx);
void func_80A75A38(EnIk* pthis, GlobalContext* globalCtx);
void func_80A75FA0(Actor* thisx, GlobalContext* globalCtx);
void func_80A76798(Actor* thisx, GlobalContext* globalCtx);
void func_80A7748C(EnIk* pthis, GlobalContext* globalCtx);
void func_80A774BC(EnIk* pthis, GlobalContext* globalCtx);
void func_80A774F8(EnIk* pthis, GlobalContext* globalCtx);
void func_80A77844(EnIk* pthis, GlobalContext* globalCtx);
void func_80A779DC(EnIk* pthis, GlobalContext* globalCtx);
void func_80A77AEC(EnIk* pthis, GlobalContext* globalCtx);
void func_80A77B0C(EnIk* pthis, GlobalContext* globalCtx);
void func_80A77B3C(EnIk* pthis, GlobalContext* globalCtx);
void func_80A77ED0(EnIk* pthis, GlobalContext* globalCtx);
void func_80A77EDC(EnIk* pthis, GlobalContext* globalCtx);
void func_80A78160(EnIk* pthis, GlobalContext* globalCtx);
void func_80A781CC(Actor* thisx, GlobalContext* globalCtx);

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 25, 80, 0, { 0, 0, 0 } },
};

static ColliderTrisElementInit sTrisElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFC3FFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_NO_AT_INFO,
            OCELEM_NONE,
        },
        { { { -10.0f, 14.0f, 2.0f }, { -10.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFC3FFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_NO_AT_INFO,
            OCELEM_NONE,
        },
        { { { -10.0f, -6.0f, 2.0f }, { 9.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
};

static ColliderTrisInit sTrisInit = {
    {
        COLTYPE_METAL,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_TRIS,
    },
    2,
    sTrisElementsInit,
};

static ColliderQuadInit sQuadInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0x20000000, 0x00, 0x40 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0xD),
    /* Deku stick    */ DMG_ENTRY(2, 0xF),
    /* Slingshot     */ DMG_ENTRY(1, 0xE),
    /* Explosive     */ DMG_ENTRY(2, 0xF),
    /* Boomerang     */ DMG_ENTRY(0, 0xD),
    /* Normal arrow  */ DMG_ENTRY(2, 0xE),
    /* Hammer swing  */ DMG_ENTRY(2, 0xF),
    /* Hookshot      */ DMG_ENTRY(0, 0xD),
    /* Kokiri sword  */ DMG_ENTRY(1, 0xF),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
    /* Fire arrow    */ DMG_ENTRY(2, 0xE),
    /* Ice arrow     */ DMG_ENTRY(2, 0xE),
    /* Light arrow   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 3   */ DMG_ENTRY(15, 0xE),
    /* Fire magic    */ DMG_ENTRY(0, 0x6),
    /* Ice magic     */ DMG_ENTRY(0, 0x6),
    /* Light magic   */ DMG_ENTRY(0, 0x6),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0xF),
    /* Giant spin    */ DMG_ENTRY(4, 0xF),
    /* Master spin   */ DMG_ENTRY(2, 0xF),
    /* Kokiri jump   */ DMG_ENTRY(2, 0xF),
    /* Giant jump    */ DMG_ENTRY(8, 0xF),
    /* Master jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 1     */ DMG_ENTRY(10, 0xF),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

void EnIk_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* pthis = (EnIk*)thisx;

    if (Actor_FindNearby(globalCtx, &pthis->actor, ACTOR_EN_IK, ACTORCAT_ENEMY, 8000.0f) == NULL) {
        func_800F5B58();
    }

    Collider_DestroyTris(globalCtx, &pthis->shieldCollider);
    Collider_DestroyCylinder(globalCtx, &pthis->bodyCollider);
    Collider_DestroyQuad(globalCtx, &pthis->axeCollider);
}

void EnIk_SetupAction(EnIk* pthis, EnIkActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void func_80A74398(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* pthis = (EnIk*)thisx;
    s32 pad;
    EffectBlureInit1 blureInit;

    thisx->update = func_80A75FA0;
    thisx->draw = func_80A76798;
    thisx->flags |= ACTOR_FLAG_10;

    Collider_InitCylinder(globalCtx, &pthis->bodyCollider);
    Collider_SetCylinder(globalCtx, &pthis->bodyCollider, thisx, &sCylinderInit);
    Collider_InitTris(globalCtx, &pthis->shieldCollider);
    Collider_SetTris(globalCtx, &pthis->shieldCollider, thisx, &sTrisInit, pthis->shieldColliderItems);
    Collider_InitQuad(globalCtx, &pthis->axeCollider);
    Collider_SetQuad(globalCtx, &pthis->axeCollider, thisx, &sQuadInit);

    thisx->colChkInfo.damageTable = &sDamageTable;
    thisx->colChkInfo.mass = MASS_HEAVY;
    pthis->unk_2FC = 0;
    thisx->colChkInfo.health = 30;
    thisx->gravity = -1.0f;
    pthis->switchFlags = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;

    if (thisx->params == 0) {
        thisx->colChkInfo.health += 20;
        thisx->naviEnemyId = 0x34;
    } else {
        Actor_SetScale(thisx, 0.012f);
        thisx->naviEnemyId = 0x35;
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, thisx, ACTORCAT_ENEMY);
    }

    blureInit.p1StartColor[0] = blureInit.p1StartColor[1] = blureInit.p2StartColor[0] = blureInit.p2StartColor[1] =
        blureInit.p2StartColor[2] = blureInit.p1EndColor[0] = blureInit.p1EndColor[1] = blureInit.p2EndColor[0] =
            blureInit.p2EndColor[1] = blureInit.p2EndColor[2] = 255;

    blureInit.p2StartColor[3] = 64;
    blureInit.p1StartColor[3] = 200;
    blureInit.p1StartColor[2] = blureInit.p1EndColor[2] = 150;
    blureInit.p1EndColor[3] = blureInit.p2EndColor[3] = 0;

    blureInit.elemDuration = 8;
    blureInit.unkFlag = 0;
    blureInit.calcMode = 2;

    Effect_Add(globalCtx, &pthis->blureIdx, EFFECT_BLURE1, 0, 0, &blureInit);
    func_80A74714(pthis);

    if (pthis->switchFlags != 0xFF) {
        if (Flags_GetSwitch(globalCtx, pthis->switchFlags)) {
            Actor_Kill(thisx);
        }
    } else if (thisx->params != 0 && Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num)) {
        Actor_Kill(thisx);
    }
}

s32 func_80A745E4(EnIk* pthis, GlobalContext* globalCtx) {
    if (((pthis->unk_2FB != 0) || (pthis->actor.params == 0)) &&
        (func_800354B4(globalCtx, &pthis->actor, 100.0f, 0x2710, 0x4000, pthis->actor.shape.rot.y) != 0) &&
        (globalCtx->gameplayFrames & 1)) {
        func_80A755F0(pthis);
        return true;
    } else {
        return false;
    }
}

Actor* func_80A74674(GlobalContext* globalCtx, Actor* actor) {
    Actor* prop = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;

    while (prop != NULL) {
        if ((prop == actor) || (prop->id != ACTOR_BG_JYA_IRONOBJ)) {
            prop = prop->next;
            continue;
        } else if (Actor_ActorAIsFacingAndNearActorB(actor, prop, 80.0f, 0x2710)) {
            return prop;
        }

        prop = prop->next;
    }

    return NULL;
}

void func_80A74714(EnIk* pthis) {
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_00CD70);
    f32 frame;

    if (pthis->actor.params >= 2) {
        frame = frames - 1.0f;
    } else {
        frame = 0.0f;
    }

    Animation_Change(&pthis->skelAnime, &object_ik_Anim_00CD70, 0.0f, frame, frames, ANIMMODE_ONCE, 0.0f);
    pthis->unk_2F8 = 3;
    pthis->actor.speedXZ = 0.0f;
    EnIk_SetupAction(pthis, func_80A747C0);
}

void func_80A747C0(EnIk* pthis, GlobalContext* globalCtx) {
    Vec3f sp24;

    if (pthis->bodyCollider.base.acFlags & AC_HIT) {
        sp24 = pthis->actor.world.pos;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_ARMOR_HIT);
        sp24.y += 30.0f;
        func_8003424C(globalCtx, &sp24);
        pthis->skelAnime.playSpeed = 1.0f;
        func_800F5ACC(NA_BGM_MINI_BOSS);
    }
    if (pthis->skelAnime.curFrame == 5.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_WAKEUP);
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_2;
        func_80A74AAC(pthis);
    }
}

void func_80A7489C(EnIk* pthis) {
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_00DD50);

    pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_2;
    pthis->unk_2F8 = 4;
    pthis->actor.speedXZ = 0.0f;
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_00DD50, 0.0f, 0.0f, frames, ANIMMODE_LOOP, 4.0f);
    EnIk_SetupAction(pthis, func_80A7492C);
}

void func_80A7492C(EnIk* pthis, GlobalContext* globalCtx) {
    s32 phi_a0 = (pthis->unk_2FB == 0) ? 0xAAA : 0x3FFC;
    s16 yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if ((ABS(yawDiff) <= phi_a0) && (pthis->actor.xzDistToPlayer < 100.0f) &&
        (ABS(pthis->actor.yDistToPlayer) < 150.0f)) {
        if ((globalCtx->gameplayFrames & 1)) {
            func_80A74E2C(pthis);
        } else {
            func_80A751C8(pthis);
        }
    } else if ((ABS(yawDiff) <= 0x4000) && (ABS(pthis->actor.yDistToPlayer) < 150.0f)) {
        func_80A74AAC(pthis);
    } else {
        func_80A74AAC(pthis);
    }
    func_80A745E4(pthis, globalCtx);
    SkelAnime_Update(&pthis->skelAnime);
}

void func_80A74AAC(EnIk* pthis) {
    pthis->unk_2F8 = 5;
    if (pthis->unk_2FB == 0) {
        Animation_Change(&pthis->skelAnime, &object_ik_Anim_00ED24, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_ik_Anim_00ED24), ANIMMODE_LOOP, -4.0f);
        pthis->actor.speedXZ = 0.9f;
    } else {
        Animation_Change(&pthis->skelAnime, &object_ik_Anim_006734, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_ik_Anim_006734), ANIMMODE_LOOP, -4.0f);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_DASH);
        pthis->actor.speedXZ = 2.5f;
    }
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnIk_SetupAction(pthis, func_80A74BA4);
}

void func_80A74BA4(EnIk* pthis, GlobalContext* globalCtx) {
    s16 temp_t0;
    s16 temp_a1;
    s16 yawDiff;
    s16 sp30;
    s16 sp2E;
    s16 phi_a3;

    if (pthis->unk_2FB == 0) {
        temp_t0 = 0xAAA;
        phi_a3 = 0x320;
        sp30 = 0;
        sp2E = 0x10;
    } else {
        temp_t0 = 0x3FFC;
        phi_a3 = 0x4B0;
        sp30 = 2;
        sp2E = 9;
    }
    temp_a1 = pthis->actor.wallYaw - pthis->actor.shape.rot.y;
    if ((pthis->actor.bgCheckFlags & 8) && (ABS(temp_a1) >= 0x4000)) {
        temp_a1 = (pthis->actor.yawTowardsPlayer > 0) ? pthis->actor.wallYaw - 0x4000 : pthis->actor.wallYaw + 0x4000;
        Math_SmoothStepToS(&pthis->actor.world.rot.y, temp_a1, 1, phi_a3, 0);
    } else {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, phi_a3, 0);
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    if ((ABS(yawDiff) <= temp_t0) && (pthis->actor.xzDistToPlayer < 100.0f)) {
        if (ABS(pthis->actor.yDistToPlayer) < 150.0f) {
            if ((globalCtx->gameplayFrames & 1)) {
                func_80A74E2C(pthis);
            } else {
                func_80A751C8(pthis);
            }
        }
    }
    if (func_80A74674(globalCtx, &pthis->actor) != NULL) {
        func_80A751C8(pthis);
        pthis->unk_2FC = 1;
    } else {
        temp_t0 = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
        if (ABS(temp_t0) > 0x4000) {
            pthis->unk_300--;
            if (pthis->unk_300 == 0) {
                func_80A754A0(pthis);
            }
        } else {
            pthis->unk_300 = 0x28;
        }
    }
    func_80A745E4(pthis, globalCtx);
    SkelAnime_Update(&pthis->skelAnime);
    if ((sp30 == (s16)pthis->skelAnime.curFrame) || (sp2E == (s16)pthis->skelAnime.curFrame)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_WALK);
    }
}

void func_80A74E2C(EnIk* pthis) {
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_001C28);

    pthis->unk_2FF = 1;
    pthis->unk_2F8 = 6;
    pthis->actor.speedXZ = 0.0f;
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_001C28, 1.5f, 0.0f, frames, ANIMMODE_ONCE, -4.0f);
    EnIk_SetupAction(pthis, func_80A74EBC);
}

void func_80A74EBC(EnIk* pthis, GlobalContext* globalCtx) {
    Vec3f sp2C;

    if (pthis->skelAnime.curFrame == 15.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_SWING_AXE);
    } else if (pthis->skelAnime.curFrame == 21.0f) {
        sp2C.x = pthis->actor.world.pos.x + Math_SinS(pthis->actor.shape.rot.y + 0x6A4) * 70.0f;
        sp2C.z = pthis->actor.world.pos.z + Math_CosS(pthis->actor.shape.rot.y + 0x6A4) * 70.0f;
        sp2C.y = pthis->actor.world.pos.y;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_HIT_GND);
        Camera_AddQuake(&globalCtx->mainCamera, 2, 0x19, 5);
        func_800AA000(pthis->actor.xzDistToPlayer, 0xFF, 0x14, 0x96);
        CollisionCheck_SpawnShieldParticles(globalCtx, &sp2C);
    }

    if ((pthis->skelAnime.curFrame > 17.0f) && (pthis->skelAnime.curFrame < 23.0f)) {
        pthis->unk_2FE = 1;
    } else {
        if ((pthis->unk_2FB != 0) && (pthis->skelAnime.curFrame < 10.0f)) {
            Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x5DC, 0);
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        }
        pthis->unk_2FE = 0;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        func_80A7506C(pthis);
    }
}

void func_80A7506C(EnIk* pthis) {
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_0029FC);

    pthis->unk_2FE = 0;
    pthis->unk_2F9 = (s8)frames;
    pthis->unk_2F8 = 7;
    pthis->unk_2FF = pthis->unk_2FE;
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_0029FC, 1.0f, 0.0f, frames, ANIMMODE_LOOP, -4.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_PULLOUT);
    EnIk_SetupAction(pthis, func_80A7510C);
}

void func_80A7510C(EnIk* pthis, GlobalContext* globalCtx) {
    f32 frames;

    if (SkelAnime_Update(&pthis->skelAnime) || (--pthis->unk_2F9 == 0)) {
        if (pthis->unk_2F8 == 8) {
            func_80A7489C(pthis);
        } else {
            frames = Animation_GetLastFrame(&object_ik_Anim_002538);
            pthis->unk_2F8 = 8;
            Animation_Change(&pthis->skelAnime, &object_ik_Anim_002538, 1.5f, 0.0f, frames, ANIMMODE_ONCE_INTERP, -4.0f);
        }
    }
}

void func_80A751C8(EnIk* pthis) {
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_0033C4);

    pthis->unk_2FF = 2;
    pthis->unk_300 = 0;
    pthis->unk_2F8 = 6;
    pthis->actor.speedXZ = 0.0f;
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_0033C4, 0.0f, 0.0f, frames, ANIMMODE_ONCE_INTERP, -6.0f);
    pthis->unk_2FC = 0;
    EnIk_SetupAction(pthis, func_80A75260);
}

void func_80A75260(EnIk* pthis, GlobalContext* globalCtx) {
    f32 temp_f0;

    pthis->unk_300 += 0x1C2;
    temp_f0 = Math_SinS(pthis->unk_300);
    pthis->skelAnime.playSpeed = ABS(temp_f0);

    if (pthis->skelAnime.curFrame > 11.0f) {
        pthis->unk_2FF = 3;
    }
    if (((pthis->skelAnime.curFrame > 1.0f) && (pthis->skelAnime.curFrame < 9.0f)) ||
        ((pthis->skelAnime.curFrame > 13.0f) && (pthis->skelAnime.curFrame < 18.0f))) {
        if ((pthis->unk_2FC == 0) && (pthis->unk_2FB != 0) && (pthis->skelAnime.curFrame < 10.0f)) {
            Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x5DC, 0);
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        }
        if (pthis->unk_2FE < 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_SWING_AXE);
        }
        pthis->unk_2FE = 1;
    } else {
        pthis->unk_2FE = 0;
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        func_80A753D0(pthis);
    }
}

void func_80A753D0(EnIk* pthis) {
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_003DBC);

    pthis->unk_2FF = pthis->unk_2FE = 0;
    pthis->unk_2F8 = 8;
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_003DBC, 1.5f, 0.0f, frames, ANIMMODE_ONCE_INTERP, -4.0f);
    EnIk_SetupAction(pthis, func_80A7545C);
}

void func_80A7545C(EnIk* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        func_80A7489C(pthis);
        func_80A745E4(pthis, globalCtx);
    }
}

void func_80A754A0(EnIk* pthis) {
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_0033C4);

    pthis->unk_2F8 = 1;
    pthis->unk_2FF = 3;
    pthis->actor.speedXZ = 0.0f;
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_0033C4, 0.5f, 13.0f, frames, ANIMMODE_ONCE_INTERP, -4.0f);
    EnIk_SetupAction(pthis, func_80A75530);
}

void func_80A75530(EnIk* pthis, GlobalContext* globalCtx) {
    Math_StepUntilS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 0x7D0);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    if ((pthis->skelAnime.curFrame > 13.0f) && (pthis->skelAnime.curFrame < 18.0f)) {
        if (pthis->unk_2FE < 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_SWING_AXE);
        }
        pthis->unk_2FE = 1;
    } else {
        pthis->unk_2FE = 0;
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        func_80A753D0(pthis);
        func_80A745E4(pthis, globalCtx);
    }
}

void func_80A755F0(EnIk* pthis) {
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_00485C);

    pthis->unk_2FE = 0;
    pthis->unk_2F8 = 9;
    pthis->actor.speedXZ = 0.0f;
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_00485C, 1.0f, 0.0f, frames, ANIMMODE_ONCE_INTERP, -4.0f);
    EnIk_SetupAction(pthis, func_80A7567C);
}

void func_80A7567C(EnIk* pthis, GlobalContext* globalCtx) {
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->shieldCollider.base);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if ((ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) <= 0x4000) &&
            (pthis->actor.xzDistToPlayer < 100.0f) && (ABS(pthis->actor.yDistToPlayer) < 150.0f)) {
            if ((globalCtx->gameplayFrames & 1)) {
                func_80A74E2C(pthis);
            } else {
                func_80A751C8(pthis);
            }
        } else {
            func_80A7489C(pthis);
        }
    }
}

void func_80A75790(EnIk* pthis) {
    s16 yaw;
    s16 yawDiff;

    yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->bodyCollider.base.ac->world.pos);
    pthis->unk_2F8 = 0;
    yawDiff = yaw - pthis->actor.shape.rot.y;
    if (ABS(yawDiff) <= 0x4000) {
        Animation_Change(&pthis->skelAnime, &object_ik_Anim_006194, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_ik_Anim_006194), ANIMMODE_ONCE, -4.0f);
        pthis->actor.speedXZ = -6.0f;
    } else {
        Animation_Change(&pthis->skelAnime, &object_ik_Anim_0045BC, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_ik_Anim_0045BC), ANIMMODE_ONCE, -4.0f);
        pthis->actor.speedXZ = 6.0f;
    }
    pthis->unk_2FE = 0;
    EnIk_SetupAction(pthis, func_80A758B0);
}

void func_80A758B0(EnIk* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 1.0f, 0.0f);
    if (BodyBreak_SpawnParts(&pthis->actor, &pthis->bodyBreak, globalCtx, pthis->actor.params + 4)) {
        pthis->bodyBreak.val = BODYBREAK_STATUS_FINISHED;
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) <= 0x4000) {
            func_80A7489C(pthis);
            func_80A745E4(pthis, globalCtx);
        } else {
            func_80A754A0(pthis);
        }
    }
}

void func_80A7598C(EnIk* pthis) {
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_005944);

    pthis->unk_2FE = 0;
    pthis->unk_2F8 = 2;
    pthis->actor.speedXZ = 0.0f;
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_005944, 1.0f, 0.0f, frames, ANIMMODE_ONCE, -4.0f);
    pthis->unk_2F9 = 0x18;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_DEAD);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_CUTBODY);
    EnIk_SetupAction(pthis, func_80A75A38);
}

void func_80A75A38(EnIk* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if ((pthis->actor.colChkInfo.health == 0) && (pthis->unk_2F9 != 0)) {
            s32 i;
            Vec3f pos;
            Vec3f sp7C = { 0.0f, 0.5f, 0.0f };

            pthis->unk_2F9--;

            for (i = 0xC - (pthis->unk_2F9 >> 1); i >= 0; i--) {
                pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(120.0f);
                pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(120.0f);
                pos.y = pthis->actor.world.pos.y + 20.0f + Rand_CenteredFloat(50.0f);
                EffectSsDeadDb_Spawn(globalCtx, &pos, &sp7C, &sp7C, 100, 0, 255, 255, 255, 255, 0, 0, 255, 1, 9, true);
            }
            if (pthis->unk_2F9 == 0) {
                Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xB0);
                if (pthis->switchFlags != 0xFF) {
                    Flags_SetSwitch(globalCtx, pthis->switchFlags);
                }
                Actor_Kill(&pthis->actor);
            }
        }
    } else if (pthis->skelAnime.curFrame == 23.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_WALK);
    }
}

void func_80A75C38(EnIk* pthis, GlobalContext* globalCtx) {
    f32 temp_f0;
    u8 pad;
    u8 pad2;
    u8 prevHealth;
    s32 temp_v0_3;
    Vec3f sp38;

    if ((pthis->unk_2F8 == 3) || (pthis->unk_2F8 == 2)) {
        return;
    }
    if (pthis->shieldCollider.base.acFlags & AC_BOUNCED) {
        temp_f0 = Animation_GetLastFrame(&object_ik_Anim_00485C) - 2.0f;
        if (pthis->skelAnime.curFrame < temp_f0) {
            pthis->skelAnime.curFrame = temp_f0;
        }
        pthis->shieldCollider.base.acFlags &= ~AC_BOUNCED;
        pthis->bodyCollider.base.acFlags &= ~AC_HIT;
        return;
    }
    if (!(pthis->bodyCollider.base.acFlags & AC_HIT)) {
        return;
    }
    sp38 = pthis->actor.world.pos;
    sp38.y += 50.0f;
    Actor_SetDropFlag(&pthis->actor, &pthis->bodyCollider.info, 1);
    temp_v0_3 = pthis->actor.colChkInfo.damageEffect;
    pthis->unk_2FD = temp_v0_3 & 0xFF;
    pthis->bodyCollider.base.acFlags &= ~AC_HIT;

    if (1) {}

    if ((pthis->unk_2FD == 0) || (pthis->unk_2FD == 0xD) || ((pthis->unk_2FB == 0) && (pthis->unk_2FD == 0xE))) {
        if (pthis->unk_2FD != 0) {
            CollisionCheck_SpawnShieldParticlesMetal(globalCtx, &sp38);
        }
        return;
    }
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0xC);
    prevHealth = pthis->actor.colChkInfo.health;
    Actor_ApplyDamage(&pthis->actor);
    if (pthis->actor.params != 0) {
        if ((prevHealth > 10) && (pthis->actor.colChkInfo.health <= 10)) {
            pthis->unk_2FB = 1;
            BodyBreak_Alloc(&pthis->bodyBreak, 3, globalCtx);
        }
    } else if (pthis->actor.colChkInfo.health <= 10) {
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_BOSS);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EN_LAST_DAMAGE);
        if (pthis->switchFlags != 0xFF) {
            Flags_SetSwitch(globalCtx, pthis->switchFlags);
        }
        return;
    } else if (prevHealth == 50) {
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ENEMY);
    }

    if (pthis->actor.colChkInfo.health == 0) {
        func_80A7598C(pthis);
        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
        return;
    }
    Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x7D0, 0);
    if ((pthis->actor.params == 0) && (Rand_ZeroOne() < 0.5f)) {
        if (ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) > 0x4000) {
            func_80A754A0(pthis);
        }
    }
    if ((pthis->actor.params != 0) && (pthis->unk_2FB != 0)) {
        if ((prevHealth > 10) && (pthis->actor.colChkInfo.health <= 10)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_ARMOR_OFF_DEMO);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_DAMAGE);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_CUTBODY);
        }
        func_80A75790(pthis);
        return;
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_ARMOR_HIT);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_IRONNACK_DAMAGE);
    CollisionCheck_SpawnShieldParticles(globalCtx, &sp38);
}

void func_80A75FA0(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* pthis = (EnIk*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    u8 prevInvincibilityTimer;

    pthis->unk_2FA = pthis->unk_2FB;
    func_80A75C38(pthis, globalCtx);
    if ((pthis->actor.params == 0) && (pthis->actor.colChkInfo.health <= 10)) {
        func_80A781CC(&pthis->actor, globalCtx);
        return;
    }
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->axeCollider.base.atFlags & AT_HIT) {
        pthis->axeCollider.base.atFlags &= ~AT_HIT;
        if (&player->actor == pthis->axeCollider.base.at) {
            prevInvincibilityTimer = player->invincibilityTimer;
            if (player->invincibilityTimer <= 0) {
                if (player->invincibilityTimer < -39) {
                    player->invincibilityTimer = 0;
                } else {
                    player->invincibilityTimer = 0;
                    globalCtx->damagePlayer(globalCtx, -64);
                    pthis->unk_2FE = 0;
                }
            }
            func_8002F71C(globalCtx, &pthis->actor, 8.0f, pthis->actor.yawTowardsPlayer, 8.0f);
            player->invincibilityTimer = prevInvincibilityTimer;
        }
    }
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 0x1D);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 45.0f;
    Collider_UpdateCylinder(&pthis->actor, &pthis->bodyCollider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
    if ((pthis->actor.colChkInfo.health > 0) && (pthis->actor.colorFilterTimer == 0) && (pthis->unk_2F8 >= 2)) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
    }
    if (pthis->unk_2FE > 0) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->axeCollider.base);
    }
    if (pthis->unk_2F8 == 9) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->shieldCollider.base);
    }
}

Gfx* func_80A761B0(GraphicsContext* gfxCtx, u8 primR, u8 primG, u8 primB, u8 envR, u8 envG, u8 envB) {
    Gfx* displayList;
    Gfx* displayListHead;

    displayList = (Gfx*)Graph_Alloc(gfxCtx, 4 * sizeof(Gfx));
    displayListHead = displayList;

    gDPPipeSync(displayListHead++);
    gDPSetPrimColor(displayListHead++, 0, 0, primR, primG, primB, 255);
    gDPSetEnvColor(displayListHead++, envR, envG, envB, 255);
    gSPEndDisplayList(displayListHead++);

    return displayList;
}

s32 EnIk_OverrideLimbDraw3(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnIk* pthis = (EnIk*)thisx;

    if (limbIndex == 12) {
        if (pthis->actor.params != 0) {
            *dList = object_ik_DL_018E78;
        }
    } else if (limbIndex == 13) {
        if (pthis->actor.params != 0) {
            *dList = object_ik_DL_019100;
        }
    } else if ((limbIndex == 26) || (limbIndex == 27)) {
        if ((pthis->unk_2FA & 1)) {
            *dList = NULL;
        }
    } else if ((limbIndex == 28) || (limbIndex == 29)) {
        if (!(pthis->unk_2FA & 1)) {
            *dList = NULL;
        }
    }
    return false;
}

// unused
static Vec3f D_80A78470 = { 300.0f, 0.0f, 0.0f };

static Vec3f D_80A7847C[] = {
    { 800.0f, -200.0f, -5200.0f },
    { 0.0f, 0.0f, 0.0f },
    { -200.0f, -2200.0f, -200.0f },
    { -6000.0f, 2000.0f, -3000.0f },
};

static Vec3f D_80A784AC[] = {
    { -3000.0, -700.0, -5000.0 },
    { -3000.0, -700.0, 2000.0 },
    { 4000.0, -700.0, 2000.0 },
};

static Vec3f D_80A784D0[] = {
    { 4000.0, -700.0, 2000.0 },
    { 4000.0, -700.0, -5000.0 },
    { -3000.0, -700.0, -5000.0 },
};

void EnIk_PostLimbDraw3(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    Vec3f spF4;
    Vec3f spE8;
    EnIk* pthis = (EnIk*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1201);

    if (pthis->unk_2FB & 1) {
        BodyBreak_SetInfo(&pthis->bodyBreak, limbIndex, 26, 27, 28, dList, BODYBREAK_OBJECT_DEFAULT);
    }
    if (limbIndex == 12) {
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1217),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (pthis->actor.params != 0) {
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_019E08);
        } else {
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016D88);
        }
    } else if (limbIndex == 17) {
        s32 i;
        Vec3f sp9C[3];
        Vec3f sp78[3];

        Matrix_MultVec3f(&D_80A7847C[0], &pthis->axeCollider.dim.quad[1]);
        Matrix_MultVec3f(&D_80A7847C[1], &pthis->axeCollider.dim.quad[0]);
        Matrix_MultVec3f(&D_80A7847C[2], &pthis->axeCollider.dim.quad[3]);
        Matrix_MultVec3f(&D_80A7847C[3], &pthis->axeCollider.dim.quad[2]);
        Collider_SetQuadVertices(&pthis->axeCollider, &pthis->axeCollider.dim.quad[0], &pthis->axeCollider.dim.quad[1],
                                 &pthis->axeCollider.dim.quad[2], &pthis->axeCollider.dim.quad[3]);
        Matrix_MultVec3f(&D_80A7847C[0], &spF4);
        Matrix_MultVec3f(&D_80A7847C[1], &spE8);
        if (pthis->unk_2FE > 0) {
            EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->blureIdx), &spF4, &spE8);
        } else if (pthis->unk_2FE == 0) {
            EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->blureIdx));
            pthis->unk_2FE = -1;
        }
        if (pthis->unk_2F8 == 9) {
            for (i = 0; i < ARRAY_COUNT(sp78); i++) {
                Matrix_MultVec3f(&D_80A784AC[i], &sp9C[i]);
                Matrix_MultVec3f(&D_80A784D0[i], &sp78[i]);
            }

            Collider_SetTrisVertices(&pthis->shieldCollider, 0, &sp9C[0], &sp9C[1], &sp9C[2]);
            Collider_SetTrisVertices(&pthis->shieldCollider, 1, &sp78[0], &sp78[1], &sp78[2]);
        }
    }

    switch (limbIndex) {
        case 22:
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1270),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016F88);
            break;
        case 24:
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1275),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016EE8);
            break;
        case 26:
            if (!(pthis->unk_2FA & 1)) {
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1281),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016BE0);
            }
            break;
        case 27:
            if (!(pthis->unk_2FA & 1)) {
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1288),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016CD8);
            }
            break;
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1294);
}

void func_80A76798(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* pthis = (EnIk*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1309);

    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);

    if (pthis->actor.params == 0) {
        gSPSegment(POLY_OPA_DISP++, 0x08, func_80A761B0(globalCtx->state.gfxCtx, 245, 225, 155, 30, 30, 0));
        gSPSegment(POLY_OPA_DISP++, 0x09, func_80A761B0(globalCtx->state.gfxCtx, 255, 40, 0, 40, 0, 0));
        gSPSegment(POLY_OPA_DISP++, 0x0A, func_80A761B0(globalCtx->state.gfxCtx, 255, 255, 255, 20, 40, 30));
    } else if (pthis->actor.params == 1) {
        gSPSegment(POLY_OPA_DISP++, 0x08, func_80A761B0(globalCtx->state.gfxCtx, 245, 255, 205, 30, 35, 0));
        gSPSegment(POLY_OPA_DISP++, 0x09, func_80A761B0(globalCtx->state.gfxCtx, 185, 135, 25, 20, 20, 0));
        gSPSegment(POLY_OPA_DISP++, 0x0A, func_80A761B0(globalCtx->state.gfxCtx, 255, 255, 255, 30, 40, 20));
    } else if (pthis->actor.params == 2) {
        gSPSegment(POLY_OPA_DISP++, 0x08, func_80A761B0(globalCtx->state.gfxCtx, 55, 65, 55, 0, 0, 0));
        gSPSegment(POLY_OPA_DISP++, 0x09, func_80A761B0(globalCtx->state.gfxCtx, 205, 165, 75, 25, 20, 0));
        gSPSegment(POLY_OPA_DISP++, 0x0A, func_80A761B0(globalCtx->state.gfxCtx, 205, 165, 75, 25, 20, 0));
    } else {
        gSPSegment(POLY_OPA_DISP++, 0x08, func_80A761B0(globalCtx->state.gfxCtx, 255, 255, 255, 180, 180, 180));
        gSPSegment(POLY_OPA_DISP++, 0x09, func_80A761B0(globalCtx->state.gfxCtx, 225, 205, 115, 25, 20, 0));
        gSPSegment(POLY_OPA_DISP++, 0x0A, func_80A761B0(globalCtx->state.gfxCtx, 225, 205, 115, 25, 20, 0));
    }
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnIk_OverrideLimbDraw3, EnIk_PostLimbDraw3, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1351);
}

void EnIk_StartMusic(void) {
    func_800F5ACC(NA_BGM_MINI_BOSS);
}

void func_80A76C14(EnIk* pthis) {
    if (Animation_OnFrame(&pthis->skelAnime, 1.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_WAKEUP, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (Animation_OnFrame(&pthis->skelAnime, 33.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_WALK, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (Animation_OnFrame(&pthis->skelAnime, 68.0f) || Animation_OnFrame(&pthis->skelAnime, 80.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_ARMOR_DEMO, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (Animation_OnFrame(&pthis->skelAnime, 107.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_FINGER_DEMO, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (Animation_OnFrame(&pthis->skelAnime, 156.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_ARMOR_DEMO, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (Animation_OnFrame(&pthis->skelAnime, 188.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_WAVE_DEMO, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    }
}

void func_80A76DDC(EnIk* pthis, GlobalContext* globalCtx, Vec3f* pos) {
    Audio_PlaySoundGeneral(NA_SE_EN_TWINROBA_TRANSFORM, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                           &D_801333E8);
}

void func_80A76E2C(EnIk* pthis, GlobalContext* globalCtx, Vec3f* pos) {
    static Vec3f D_80A78514[] = {
        { 1000.0, -1000.0, 1000.0 },  { 0.0, -1000.0, 0.0 },        { -1000.0, -5000.0, -4000.0 },
        { 1000.0, -5000.0, -3000.0 }, { -1000.0, 1000.0, -6000.0 }, { -1000.0, 3000.0, -5000.0 },
        { -800.0, 1000.0, -3000.0 },  { 0.0, -4000.0, -2000.0 },    { -1000.0, -2000.0, -6000.0 },
        { 1000.0, -3000.0, 0.0 },     { 2000.0, -2000.0, -4000.0 }, { -1000.0, 0.0, -6000.0 },
        { 1000.0, -2000.0, -2000.0 }, { 0.0, -2000.0, 2100.0 },     { 0.0, 0.0, 0.0 },
        { 1000.0, -1000.0, -6000.0 }, { 2000.0, 0.0, -3000.0 },     { -1000.0, -1000.0, -4000.0 },
        { 900.0, -800.0, 2700.0 },    { 720.0f, 900.0f, 2500.0f },
    };

    if (pthis->unk_4D4 == 0) {
        s32 pad;
        Vec3f effectVelocity = { 0.0f, 0.0f, 0.0f };
        Vec3f effectAccel = { 0.0f, 0.3f, 0.0f };
        s32 i;

        for (i = ARRAY_COUNT(D_80A78514) - 1; i >= 0; i--) {
            Color_RGBA8 primColor = { 200, 200, 200, 255 };
            Color_RGBA8 envColor = { 150, 150, 150, 0 };
            s32 temp_v0;
            Vec3f effectPos;

            Matrix_MultVec3f(&D_80A78514[i], &effectPos);
            temp_v0 = (Rand_ZeroOne() * 20.0f) - 10.0f;
            primColor.r += temp_v0;
            primColor.g += temp_v0;
            primColor.b += temp_v0;
            envColor.r += temp_v0;
            envColor.g += temp_v0;
            envColor.b += temp_v0;
            func_8002829C(globalCtx, &effectPos, &effectVelocity, &effectAccel, &primColor, &envColor,
                          (Rand_ZeroOne() * 60.0f) + 300.0f, 0);
        }

        pthis->unk_4D4 = 1;
        func_80A76DDC(pthis, globalCtx, pos);
    }
}

void func_80A77034(EnIk* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 5);
}

s32 func_80A7707C(EnIk* pthis) {
    return SkelAnime_Update(&pthis->skelAnime);
}

CsCmdActorAction* EnIk_GetNpcAction(GlobalContext* globalCtx, s32 actionIdx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        return globalCtx->csCtx.npcActions[actionIdx];
    } else {
        return NULL;
    }
}

void func_80A770C0(EnIk* pthis, GlobalContext* globalCtx, s32 actionIdx) {
    CsCmdActorAction* npcAction = EnIk_GetNpcAction(globalCtx, actionIdx);

    if (npcAction != NULL) {
        pthis->actor.world.pos.x = npcAction->startPos.x;
        pthis->actor.world.pos.y = npcAction->startPos.y;
        pthis->actor.world.pos.z = npcAction->startPos.z;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = npcAction->rot.y;
    }
}

f32 EnIk_curFrame(Actor* thisx) {
    EnIk* pthis = (EnIk*)thisx;

    return pthis->skelAnime.curFrame;
}

void func_80A77148(EnIk* pthis) {
    pthis->action = 0;
    pthis->drawMode = 0;
    pthis->actor.shape.shadowAlpha = 0;
}

void func_80A77158(EnIk* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_00C114, 1.0f, 0.0f,
                     Animation_GetLastFrame(&object_ik_Anim_00C114), ANIMMODE_ONCE, 0.0f);
    func_80A770C0(pthis, globalCtx, 4);
    pthis->action = 1;
    pthis->drawMode = 1;
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void func_80A771E4(EnIk* pthis) {
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_00C114, 1.0f, 0.0f,
                     Animation_GetLastFrame(&object_ik_Anim_00C114), ANIMMODE_ONCE, 0.0f);
    pthis->action = 2;
    pthis->drawMode = 1;
    pthis->unk_4D4 = 0;
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void func_80A77264(EnIk* pthis, GlobalContext* globalCtx, s32 arg2) {
    if ((arg2 != 0) && (EnIk_GetNpcAction(globalCtx, 4) != NULL)) {
        func_80A78160(pthis, globalCtx);
    }
}

void func_80A772A4(EnIk* pthis) {
    Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_STAGGER_DEMO, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                           &D_801333E8);
}

void func_80A772EC(EnIk* pthis, GlobalContext* globalCtx) {
    static Vec3f D_80A78FA0;
    s32 pad[2];
    f32 wDest;

    SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->viewProjectionMtxF, &pthis->actor.world.pos, &D_80A78FA0, &wDest);
    Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_DEAD, &D_80A78FA0, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_80A7735C(EnIk* pthis, GlobalContext* globalCtx) {
    s32 pad[3];
    f32 frames = Animation_GetLastFrame(&object_ik_Anim_0203D8);

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_ik_Skel_0205C0, NULL, pthis->jointTable, pthis->morphTable,
                       30);
    Animation_Change(&pthis->skelAnime, &object_ik_Anim_0203D8, 1.0f, 0.0f, frames, ANIMMODE_ONCE, 0.0f);
    pthis->action = 3;
    pthis->drawMode = 2;
    func_80A770C0(pthis, globalCtx, 4);
    func_80A772EC(pthis, globalCtx);
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void func_80A77434(EnIk* pthis, GlobalContext* globalCtx) {
    pthis->action = 4;
    pthis->drawMode = 2;
    func_80A772A4(pthis);
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void func_80A77474(EnIk* pthis, GlobalContext* globalCtx) {
    pthis->action = 5;
    pthis->drawMode = 0;
    pthis->actor.shape.shadowAlpha = 0;
}

void func_80A7748C(EnIk* pthis, GlobalContext* globalCtx) {
    func_80A77034(pthis, globalCtx);
    func_80A779DC(pthis, globalCtx);
}

void func_80A774BC(EnIk* pthis, GlobalContext* globalCtx) {
    func_80A7707C(pthis);
    func_80A77034(pthis, globalCtx);
    func_80A779DC(pthis, globalCtx);
}

void func_80A774F8(EnIk* pthis, GlobalContext* globalCtx) {
    if (EnIk_GetNpcAction(globalCtx, 4) == NULL) {
        Actor_Kill(&pthis->actor);
    }
}

s32 EnIk_OverrideLimbDraw2(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnIk* pthis = (EnIk*)thisx;

    if ((limbIndex == 13) || (limbIndex == 26) || (limbIndex == 27)) {
        if (EnIk_curFrame(&pthis->actor) >= 30.0f) {
            *dList = NULL;
        }
    }

    return 0;
}

void EnIk_PostLimbDraw2(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(gfxCtx, "../z_en_ik_inAwake.c", 207);

    switch (limbIndex) {
        case 13: {
            EnIk* pthis = (EnIk*)thisx;

            if (EnIk_curFrame(&pthis->actor) < 30.0f) {
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inAwake.c", 267),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016D88);
            }
        } break;
        case 22:
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inAwake.c", 274),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016F88);
            break;
        case 24:
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inAwake.c", 280),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016EE8);
            break;
        case 26: {
            EnIk* pthis = (EnIk*)thisx;

            if (EnIk_curFrame(&pthis->actor) < 30.0f) {
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inAwake.c", 288),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016BE0);
            }
        } break;
        case 27: {
            EnIk* pthis = (EnIk*)thisx;

            if (EnIk_curFrame(&pthis->actor) < 30.0f) {
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inAwake.c", 297),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016CD8);
            }
        } break;
    }
    CLOSE_DISPS(gfxCtx, "../z_en_ik_inAwake.c", 304);
}

void func_80A77844(EnIk* pthis, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    SkelAnime* skelAnime = &pthis->skelAnime;
    s32 pad[2];

    OPEN_DISPS(gfxCtx, "../z_en_ik_inAwake.c", 322);

    func_8002EBCC(&pthis->actor, globalCtx, 0);
    func_80093D18(gfxCtx);
    func_80093D84(gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, func_80A761B0(gfxCtx, 245, 225, 155, 30, 30, 0));
    gSPSegment(POLY_OPA_DISP++, 0x09, func_80A761B0(gfxCtx, 255, 40, 0, 40, 0, 0));
    gSPSegment(POLY_OPA_DISP++, 0x0A, func_80A761B0(gfxCtx, 255, 255, 255, 20, 40, 30));
    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                          EnIk_OverrideLimbDraw2, EnIk_PostLimbDraw2, pthis);

    CLOSE_DISPS(gfxCtx, "../z_en_ik_inAwake.c", 345);
}

void func_80A779DC(EnIk* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction = EnIk_GetNpcAction(globalCtx, 4);
    u32 action;
    u32 currentNpcAction;

    if (npcAction != NULL) {
        action = npcAction->action;
        currentNpcAction = pthis->npcAction;
        if (action != currentNpcAction) {
            switch (action) {
                case 1:
                    func_80A77148(pthis);
                    break;
                case 2:
                    func_80A77158(pthis, globalCtx);
                    break;
                case 3:
                    func_80A771E4(pthis);
                    break;
                case 4:
                    func_80A78160(pthis, globalCtx);
                    break;
                case 5:
                    func_80A7735C(pthis, globalCtx);
                    break;
                case 6:
                    func_80A77434(pthis, globalCtx);
                    break;
                case 7:
                    func_80A77474(pthis, globalCtx);
                    break;
                default:
                    osSyncPrintf("En_Ik_inConfrontion_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }

            pthis->npcAction = action;
        }
    }
}

void func_80A77AEC(EnIk* pthis, GlobalContext* globalCtx) {
    func_80A779DC(pthis, globalCtx);
}

void func_80A77B0C(EnIk* pthis, GlobalContext* globalCtx) {
    func_80A77034(pthis, globalCtx);
    func_80A779DC(pthis, globalCtx);
}

void func_80A77B3C(EnIk* pthis, GlobalContext* globalCtx) {
    s32 sp24;

    sp24 = func_80A7707C(pthis);
    func_80A76C14(pthis);
    func_80A77034(pthis, globalCtx);
    func_80A779DC(pthis, globalCtx);
    func_80A77264(pthis, globalCtx, sp24);
}

static EnIkActionFunc sActionFuncs[] = {
    func_80A77AEC, func_80A77B0C, func_80A77B3C, func_80A7748C, func_80A774BC, func_80A774F8,
};

void EnIk_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* pthis = (EnIk*)thisx;

    if (pthis->action < 0 || pthis->action >= ARRAY_COUNT(sActionFuncs) || sActionFuncs[pthis->action] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }

    sActionFuncs[pthis->action](pthis, globalCtx);
}

s32 EnIk_OverrideLimbDraw1(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnIk* pthis = (EnIk*)thisx;
    f32 curFrame;

    switch (limbIndex) {
        case 17:
            curFrame = pthis->skelAnime.curFrame;
            if (curFrame < 120.0f) {
                *dList = NULL;
            } else {
                func_80A76E2C(pthis, globalCtx, pos);
            }
            break;
        case 29:
        case 30:
            *dList = NULL;
            break;
    }

    return 0;
}

void EnIk_PostLimbDraw1(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(gfxCtx, "../z_en_ik_inConfrontion.c", 571);

    switch (limbIndex) {
        case 12:
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inConfrontion.c", 575),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016D88);
            break;
        case 22:
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inConfrontion.c", 581),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016F88);
            break;
        case 24:
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inConfrontion.c", 587),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016EE8);
            break;
        case 26:
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inConfrontion.c", 593),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016BE0);
            break;
        case 27:
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_ik_inConfrontion.c", 599),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016CD8);
            break;
    }

    CLOSE_DISPS(gfxCtx, "../z_en_ik_inConfrontion.c", 604);
}

void func_80A77ED0(EnIk* pthis, GlobalContext* globalCtx) {
}

void func_80A77EDC(EnIk* pthis, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    SkelAnime* skelAnime = &pthis->skelAnime;
    s32 pad[2];

    OPEN_DISPS(gfxCtx, "../z_en_ik_inConfrontion.c", 630);

    func_8002EBCC(&pthis->actor, globalCtx, 0);
    func_80093D18(gfxCtx);
    func_80093D84(gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, func_80A761B0(gfxCtx, 245, 225, 155, 30, 30, 0));
    gSPSegment(POLY_OPA_DISP++, 0x09, func_80A761B0(gfxCtx, 255, 40, 0, 40, 0, 0));
    gSPSegment(POLY_OPA_DISP++, 0x0A, func_80A761B0(gfxCtx, 255, 255, 255, 20, 40, 30));
    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                          EnIk_OverrideLimbDraw1, EnIk_PostLimbDraw1, pthis);

    CLOSE_DISPS(gfxCtx, "../z_en_ik_inConfrontion.c", 653);
}

static EnIkDrawFunc sDrawFuncs[] = { func_80A77ED0, func_80A77EDC, func_80A77844 };

void EnIk_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* pthis = (EnIk*)thisx;

    if (pthis->drawMode < 0 || pthis->drawMode >= ARRAY_COUNT(sDrawFuncs) || sDrawFuncs[pthis->drawMode] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }

    sDrawFuncs[pthis->drawMode](pthis, globalCtx);
}

void func_80A780D0(EnIk* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.params == 0) {
        if (!(gSaveContext.eventChkInf[3] & 0x800)) {
            pthis->actor.update = EnIk_Update;
            pthis->actor.draw = EnIk_Draw;
            Actor_SetScale(&pthis->actor, 0.01f);
        } else {
            func_80A78160(pthis, globalCtx);
            EnIk_StartMusic();
        }
    }
    osSyncPrintf("En_Ik_inConfrontion_Init : %d !!!!!!!!!!!!!!!!\n", pthis->actor.params);
}

void func_80A78160(EnIk* pthis, GlobalContext* globalCtx) {
    pthis->actor.update = func_80A75FA0;
    pthis->actor.draw = func_80A76798;
    pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_2;
    gSaveContext.eventChkInf[3] |= 0x800;
    Actor_SetScale(&pthis->actor, 0.012f);
    func_80A7489C(pthis);
}

void func_80A781CC(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* pthis = (EnIk*)thisx;

    if (!Gameplay_InCsMode(globalCtx)) {
        pthis->actor.update = EnIk_Update;
        pthis->actor.draw = EnIk_Draw;
        Cutscene_SetSegment(globalCtx, gSpiritBossNabooruKnuckleDefeatCs);
        gSaveContext.cutsceneTrigger = 1;
        Actor_SetScale(&pthis->actor, 0.01f);
        gSaveContext.eventChkInf[3] |= 0x1000;
        func_80A7735C(pthis, globalCtx);
    }
}

void EnIk_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* pthis = (EnIk*)thisx;
    s32 flag = pthis->actor.params & 0xFF00;

    if (((pthis->actor.params & 0xFF) == 0 && (gSaveContext.eventChkInf[3] & 0x1000)) ||
        (flag != 0 && Flags_GetSwitch(globalCtx, flag >> 8))) {
        Actor_Kill(&pthis->actor);
    } else {
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_ik_Skel_01E178, &object_ik_Anim_00C114,
                           pthis->jointTable, pthis->morphTable, 30);
        func_80A74398(&pthis->actor, globalCtx);
        func_80A780D0(pthis, globalCtx);
    }
}

ActorInit En_Ik_InitVars = {
    ACTOR_EN_IK,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_IK,
    sizeof(EnIk),
    (ActorFunc)EnIk_Init,
    (ActorFunc)EnIk_Destroy,
    (ActorFunc)EnIk_Update,
    (ActorFunc)EnIk_Draw,
};
