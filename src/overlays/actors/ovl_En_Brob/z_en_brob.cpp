#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BROB_Z_EN_BROB_C
#include "actor_common.h"
/*
 * File: z_en_brob.c
 * Overlay: ovl_En_Brob
 * Description: Flobbery Muscle Block (Jabu-Jabu's Belly)
 */

#include "z_en_brob.h"
#include "objects/object_brob/object_brob.h"
#include "def/code_80043480.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnBrob_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBrob_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBrob_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBrob_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBrob_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809CADDC(EnBrob* pthis, GlobalContext* globalCtx);
void func_809CB054(EnBrob* pthis, GlobalContext* globalCtx);
void func_809CB114(EnBrob* pthis, GlobalContext* globalCtx);
void func_809CB218(EnBrob* pthis, GlobalContext* globalCtx);
void func_809CB2B8(EnBrob* pthis, GlobalContext* globalCtx);
void func_809CB354(EnBrob* pthis, GlobalContext* globalCtx);
void func_809CB458(EnBrob* pthis, GlobalContext* globalCtx);

static Color_RGBA8 primColor_44 = { 255, 255, 255, 255 };

static Color_RGBA8 envColor_44 = { 200, 255, 255, 255 };


ActorInit En_Brob_InitVars = {
    ACTOR_EN_BROB,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BROB,
    sizeof(EnBrob),
    (ActorFunc)EnBrob_Init,
    (ActorFunc)EnBrob_Destroy,
    (ActorFunc)EnBrob_Update,
    (ActorFunc)EnBrob_Draw,
    (ActorFunc)EnBrob_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT0,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK1,
        { 0xFFCFFFFF, 0x03, 0x08 },
        { 0xFFCFFFFF, 0x01, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 8000, 11000, -5000, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 0, 60, 120, MASS_IMMOVABLE };

void EnBrob_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnBrob* pthis = (EnBrob*)thisx;
    CollisionHeader* colHeader = NULL;

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_brob_Skel_0015D8, &object_brob_Anim_001750,
                       pthis->jointTable, pthis->morphTable, 10);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&object_brob_Col_001A70, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    Collider_InitCylinder(globalCtx, &pthis->colliders[0]);
    Collider_SetCylinder(globalCtx, &pthis->colliders[0], &pthis->dyna.actor, &sCylinderInit);
    Collider_InitCylinder(globalCtx, &pthis->colliders[1]);
    Collider_SetCylinder(globalCtx, &pthis->colliders[1], &pthis->dyna.actor, &sCylinderInit);
    CollisionCheck_SetInfo(&thisx->colChkInfo, NULL, &sColChkInfoInit);
    if (((thisx->params >> 8) & 0xFF) == 0) {
        Actor_SetScale(&pthis->dyna.actor, 0.01f);
        thisx->params &= 0xFF;
        if (thisx->params != 0xFF) {
            thisx->scale.y *= (thisx->params & 0xFF) * (1.0f / 30.0f);
        }
    } else {
        Actor_SetScale(&pthis->dyna.actor, 0.005f);
        thisx->params &= 0xFF;
        if (thisx->params != 0xFF) {
            thisx->scale.y *= (thisx->params & 0xFF) * (2.0f / 30.0f);
        }
    }
    pthis->colliders[0].dim.radius *= thisx->scale.x;
    pthis->colliders[0].dim.height = thisx->scale.y * 12000.0f;
    pthis->colliders[0].dim.yShift = 0;
    pthis->colliders[1].dim.radius *= thisx->scale.x;
    pthis->colliders[1].dim.height *= thisx->scale.y;
    pthis->colliders[1].dim.yShift *= thisx->scale.y;
    pthis->actionFunc = NULL;
    thisx->flags &= ~ACTOR_FLAG_0;
    func_809CADDC(pthis, globalCtx);
}

void EnBrob_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnBrob* pthis = (EnBrob*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyCylinder(globalCtx, &pthis->colliders[0]);
    Collider_DestroyCylinder(globalCtx, &pthis->colliders[1]);
}

void func_809CADDC(EnBrob* pthis, GlobalContext* globalCtx) {
    func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    pthis->timer = pthis->actionFunc == func_809CB2B8 ? 200 : 0;
    pthis->unk_1AE = 0;
    pthis->actionFunc = func_809CB054;
}

void func_809CAE44(EnBrob* pthis, GlobalContext* globalCtx) {
    Animation_PlayOnce(&pthis->skelAnime, &object_brob_Anim_001750);
    func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    pthis->unk_1AE = 1000;
    pthis->actionFunc = func_809CB114;
}

void func_809CAEA0(EnBrob* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &object_brob_Anim_001958, -5.0f);
    pthis->unk_1AE = 8000;
    pthis->timer = 1200;
    pthis->actionFunc = func_809CB218;
}

void func_809CAEF4(EnBrob* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_brob_Anim_000290, -5.0f);
    pthis->unk_1AE -= 125.0f;
    Actor_SetColorFilter(&pthis->dyna.actor, 0, 0xFF, 0, 0x50);
    Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->actionFunc = func_809CB2B8;
}

void func_809CAF88(EnBrob* pthis) {
    Animation_Change(&pthis->skelAnime, &object_brob_Anim_001750, -1.0f,
                     Animation_GetLastFrame(&object_brob_Anim_001750), 0.0f, ANIMMODE_ONCE, -5.0f);
    pthis->unk_1AE = 8250;
    pthis->actionFunc = func_809CB354;
}

void func_809CB008(EnBrob* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &object_brob_Anim_001678, -5.0f);
    pthis->timer = 10;
    pthis->actionFunc = func_809CB458;
}

void func_809CB054(EnBrob* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        if (func_8004356C(&pthis->dyna) != 0) {
            func_8002F71C(globalCtx, &pthis->dyna.actor, 5.0f, pthis->dyna.actor.yawTowardsPlayer, 1.0f);
            func_809CAE44(pthis, globalCtx);
        } else if (pthis->dyna.actor.xzDistToPlayer < 300.0f) {
            func_809CAE44(pthis, globalCtx);
        }
    } else if (pthis->timer >= 81) {
        pthis->dyna.actor.colorFilterTimer = 80;
    }
}

void func_809CB114(EnBrob* pthis, GlobalContext* globalCtx) {
    f32 curFrame;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        func_809CAEA0(pthis);
    } else {
        curFrame = pthis->skelAnime.curFrame;
        if (curFrame < 8.0f) {
            pthis->unk_1AE += 1000.0f;
        } else if (curFrame < 12.0f) {
            pthis->unk_1AE += 250.0f;
        } else {
            pthis->unk_1AE -= 250.0f;
        }
    }
}

void func_809CB218(EnBrob* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 6.0f) || Animation_OnFrame(&pthis->skelAnime, 15.0f)) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_BROB_WAVE);
    }
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if ((pthis->timer == 0) && (pthis->dyna.actor.xzDistToPlayer > 500.0f)) {
        func_809CAF88(pthis);
    }
}

void func_809CB2B8(EnBrob* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        func_809CADDC(pthis, globalCtx);
    } else if (pthis->skelAnime.curFrame < 8.0f) {
        pthis->unk_1AE -= 1250.0f;
    }
    pthis->dyna.actor.colorFilterTimer = 0x50;
}

void func_809CB354(EnBrob* pthis, GlobalContext* globalCtx) {
    f32 curFrame;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        func_809CADDC(pthis, globalCtx);
    } else {
        curFrame = pthis->skelAnime.curFrame;
        if (curFrame < 8.0f) {
            pthis->unk_1AE -= 1000.0f;
        } else if (curFrame < 12.0f) {
            pthis->unk_1AE -= 250.0f;
        } else {
            pthis->unk_1AE += 250.0f;
        }
    }
}

void func_809CB458(EnBrob* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    f32 dist1;
    f32 dist2;
    s32 i;

    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0) && (pthis->timer != 0)) {
        pthis->timer--;
    }

    dist1 = globalCtx->gameplayFrames % 2 ? 0.0f : pthis->dyna.actor.scale.x * 5500.0f;
    dist2 = pthis->dyna.actor.scale.x * 5500.0f;

    for (i = 0; i < 4; i++) {

        if (i % 2) {
            pos.x = pthis->dyna.actor.world.pos.x + dist1;
            pos.z = pthis->dyna.actor.world.pos.z + dist2;
        } else {
            pos.x = pthis->dyna.actor.world.pos.x + dist2;
            pos.z = pthis->dyna.actor.world.pos.z + dist1;
            dist1 = -dist1;
            dist2 = -dist2;
        }
        pos.y = (((Rand_ZeroOne() * 15000.0f) + 1000.0f) * pthis->dyna.actor.scale.y) + pthis->dyna.actor.world.pos.y;
        EffectSsLightning_Spawn(globalCtx, &pos, &primColor_44, &envColor_44, pthis->dyna.actor.scale.y * 8000.0f,
                                Rand_ZeroOne() * 65536.0f, 4, 1);
    }

    if (pthis->timer == 0) {
        func_809CAEA0(pthis);
    }
}

void EnBrob_Update(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnBrob* pthis = (EnBrob*)thisx;
    s32 i;
    s32 acHits[2];

    acHits[0] = (pthis->colliders[0].base.acFlags & AC_HIT) != 0;
    acHits[1] = (pthis->colliders[1].base.acFlags & AC_HIT) != 0;
    if ((acHits[0] && (pthis->colliders[0].info.acHitInfo->toucher.dmgFlags & 0x10)) ||
        (acHits[1] && (pthis->colliders[1].info.acHitInfo->toucher.dmgFlags & 0x10))) {

        for (i = 0; i < 2; i++) {
            pthis->colliders[i].base.atFlags &= ~(AT_HIT | AT_BOUNCED);
            pthis->colliders[i].base.acFlags &= ~AC_HIT;
        }

        func_809CAEF4(pthis);
    } else if ((pthis->colliders[0].base.atFlags & AT_HIT) || (pthis->colliders[1].base.atFlags & AT_HIT) ||
               (acHits[0] && (pthis->colliders[0].info.acHitInfo->toucher.dmgFlags & 0x100)) ||
               (acHits[1] && (pthis->colliders[1].info.acHitInfo->toucher.dmgFlags & 0x100))) {

        if (pthis->actionFunc == func_809CB114 && !(pthis->colliders[0].base.atFlags & AT_BOUNCED) &&
            !(pthis->colliders[1].base.atFlags & AT_BOUNCED)) {
            func_8002F71C(globalCtx, &pthis->dyna.actor, 5.0f, pthis->dyna.actor.yawTowardsPlayer, 1.0f);
        } else if (pthis->actionFunc != func_809CB114) {
            func_809CB008(pthis);
        }

        for (i = 0; i < 2; i++) {
            pthis->colliders[i].base.atFlags &= ~(AT_HIT | AT_BOUNCED);
            pthis->colliders[i].base.acFlags &= ~AC_HIT;
        }
    }
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->actionFunc != func_809CB054 && pthis->actionFunc != func_809CB354) {
        if (pthis->actionFunc != func_809CB2B8) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliders[0].base);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliders[1].base);
            if (pthis->actionFunc != func_809CB114) {
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliders[0].base);
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliders[1].base);
            }
        }
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliders[0].base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliders[1].base);
    }
}

void EnBrob_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnBrob* pthis = (EnBrob*)thisx;
    MtxF mtx;

    Matrix_Get(&mtx);
    if (limbIndex == 3) {
        pthis->colliders[0].dim.pos.x = mtx.xw;
        pthis->colliders[0].dim.pos.y = mtx.yw;
        pthis->colliders[0].dim.pos.z = mtx.zw;
    } else if (limbIndex == 8) {
        pthis->colliders[1].dim.pos.x = mtx.xw;
        pthis->colliders[1].dim.pos.y = (mtx.yw + 7.0f);
        pthis->colliders[1].dim.pos.z = mtx.zw;
    }
}

void EnBrob_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnBrob* pthis = (EnBrob*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    Matrix_Translate(0.0f, pthis->unk_1AE, 0.0f, MTXMODE_APPLY);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, EnBrob_PostLimbDraw, pthis);
}

void EnBrob_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    primColor_44 = { 255, 255, 255, 255 };

    envColor_44 = { 200, 255, 255, 255 };

    En_Brob_InitVars = {
        ACTOR_EN_BROB,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_BROB,
        sizeof(EnBrob),
        (ActorFunc)EnBrob_Init,
        (ActorFunc)EnBrob_Destroy,
        (ActorFunc)EnBrob_Update,
        (ActorFunc)EnBrob_Draw,
        (ActorFunc)EnBrob_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_HIT0,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK1,
            { 0xFFCFFFFF, 0x03, 0x08 },
            { 0xFFCFFFFF, 0x01, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 8000, 11000, -5000, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 0, 60, 120, MASS_IMMOVABLE };

}
