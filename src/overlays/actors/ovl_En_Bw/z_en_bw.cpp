#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BW_Z_EN_BW_C
#include "actor_common.h"
/*
 * File: z_en_bw.c
 * Overlay: ovl_En_Bw
 * Description: Torch slug
 */

#include "z_en_bw.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_bw/object_bw.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_math.h"
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

void EnBw_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBw_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBw_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBw_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809CE884(EnBw* pthis, GlobalContext* globalCtx);
void func_809CE9A8(EnBw* pthis);
void func_809CEA24(EnBw* pthis, GlobalContext* globalCtx);
void func_809CF72C(EnBw* pthis);
void func_809CF7AC(EnBw* pthis, GlobalContext* globalCtx);
void func_809CF8F0(EnBw* pthis);
void func_809CF984(EnBw* pthis, GlobalContext* globalCtx);
void func_809CFBA8(EnBw* pthis);
void func_809CFC4C(EnBw* pthis, GlobalContext* globalCtx);
void func_809CFF10(EnBw* pthis);
void func_809CFF98(EnBw* pthis, GlobalContext* globalCtx);
void func_809D00F4(EnBw* pthis);
void func_809D014C(EnBw* pthis, GlobalContext* globalCtx);
void func_809D01CC(EnBw* pthis);
void func_809D0268(EnBw* pthis, GlobalContext* globalCtx);
void func_809D03CC(EnBw* pthis);
void func_809D0424(EnBw* pthis, GlobalContext* globalCtx);

ActorInit En_Bw_InitVars = {
    ACTOR_EN_BW,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BW,
    sizeof(EnBw),
    (ActorFunc)EnBw_Init,
    (ActorFunc)EnBw_Destroy,
    (ActorFunc)EnBw_Update,
    (ActorFunc)EnBw_Draw,
};

static ColliderCylinderInit sCylinderInit1 = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x01, 0x08 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { 30, 65, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sCylinderInit2 = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
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
    { 30, 35, 0, { 0, 0, 0 } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(0, 0x0),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0xF),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(2, 0xF),
    /* Hammer swing  */ DMG_ENTRY(2, 0xF),
    /* Hookshot      */ DMG_ENTRY(0, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(0, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
    /* Fire arrow    */ DMG_ENTRY(2, 0xF),
    /* Ice arrow     */ DMG_ENTRY(4, 0xE),
    /* Light arrow   */ DMG_ENTRY(2, 0xF),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0xF),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0xF),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0xF),
    /* Fire magic    */ DMG_ENTRY(0, 0x6),
    /* Ice magic     */ DMG_ENTRY(3, 0xE),
    /* Light magic   */ DMG_ENTRY(0, 0x6),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0xF),
    /* Giant spin    */ DMG_ENTRY(4, 0xF),
    /* Master spin   */ DMG_ENTRY(2, 0xF),
    /* Kokiri jump   */ DMG_ENTRY(2, 0xF),
    /* Giant jump    */ DMG_ENTRY(8, 0xF),
    /* Master jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static s32 sSlugGroup = 0;

void EnBw_SetupAction(EnBw* pthis, EnBwActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnBw_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnBw* pthis = (EnBw*)thisx;

    Actor_SetScale(&pthis->actor, 0.012999999f);
    pthis->actor.naviEnemyId = 0x23;
    pthis->actor.gravity = -2.0f;
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &object_bw_Skel_0020F0, &object_bw_Anim_000228, pthis->jointTable,
                   pthis->morphTable, 12);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 40.0f);
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    pthis->actor.colChkInfo.health = 6;
    pthis->actor.colChkInfo.mass = MASS_HEAVY;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    func_809CE9A8(pthis);
    pthis->color1.a = pthis->color1.r = 255;
    pthis->color1.g = pthis->color1.b = 0;
    pthis->unk_248 = 0.6f;
    pthis->unk_221 = 3;
    Collider_InitCylinder(globalCtx, &pthis->collider1);
    //! pthis->collider2 should have Init called on it, but it doesn't matter since the heap is zeroed before use.
    Collider_SetCylinder(globalCtx, &pthis->collider1, &pthis->actor, &sCylinderInit1);
    Collider_SetCylinder(globalCtx, &pthis->collider2, &pthis->actor, &sCylinderInit2);
    pthis->unk_236 = pthis->actor.world.rot.y;
    pthis->actor.params = sSlugGroup;
    sSlugGroup = (sSlugGroup + 1) & 3;
}

void EnBw_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnBw* pthis = (EnBw*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider1);
    Collider_DestroyCylinder(globalCtx, &pthis->collider2);
}

void func_809CE884(EnBw* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
    pthis->unk_222 -= 250;
    pthis->actor.scale.x = 0.013f + Math_SinF(pthis->unk_222 * 0.001f) * 0.0069999998f;
    pthis->actor.scale.y = 0.013f - Math_SinF(pthis->unk_222 * 0.001f) * 0.0069999998f;
    pthis->actor.scale.z = 0.013f + Math_SinF(pthis->unk_222 * 0.001f) * 0.0069999998f;
    if (pthis->unk_222 == 0) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        func_809CE9A8(pthis);
    }
}

void func_809CE9A8(EnBw* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &object_bw_Anim_000228, -2.0f);
    pthis->unk_220 = 2;
    pthis->unk_222 = Rand_ZeroOne() * 200.0f + 200.0f;
    pthis->unk_232 = 0;
    pthis->actor.speedXZ = 0.0f;
    EnBw_SetupAction(pthis, func_809CEA24);
}

void func_809CEA24(EnBw* pthis, GlobalContext* globalCtx) {
    CollisionPoly* sp74 = NULL;
    Vec3f sp68;
    u32 sp64 = 0;
    s16 sp62;
    s16 sp60;
    f32 sp5C;
    f32 sp58;
    Player* player = GET_PLAYER(globalCtx);
    Player* player2 = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    pthis->unk_244 = pthis->unk_250 + 0.1f;
    sp58 = Math_CosF(pthis->unk_240);
    pthis->unk_240 += pthis->unk_244;
    if (pthis->unk_24C < 0.8f) {
        pthis->unk_24C += 0.1f;
    }
    pthis->actor.scale.x = 0.013f - Math_SinF(pthis->unk_240) * (pthis->unk_24C * 0.004f);
    pthis->actor.scale.y = 0.013f - Math_SinF(pthis->unk_240) * (pthis->unk_24C * 0.004f);
    pthis->actor.scale.z = 0.013f + Math_SinF(pthis->unk_240) * (pthis->unk_24C * 0.004f);
    sp5C = Math_CosF(pthis->unk_240);
    if (pthis->unk_232 == 0) {
        if (ABS(sp58) < ABS(sp5C)) {
            pthis->unk_232++;
        }
    } else {
        if (ABS(sp58) > ABS(sp5C)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLEWALK_WALK);
            pthis->unk_232 = 0;
        }
    }
    sp5C *= pthis->unk_24C * (10.0f * pthis->unk_244);
    pthis->actor.speedXZ = ABS(sp5C);
    if (pthis->unk_221 != 1) {
        sp58 = Math_SinF(pthis->unk_240);
        sp60 = ABS(sp58) * 85.0f;
        pthis->color1.g = sp60;
    }
    if ((((globalCtx->gameplayFrames % 4) == (u32)pthis->actor.params) && (pthis->actor.speedXZ != 0.0f) &&
         (sp64 = BgCheck_AnyLineTest2(&globalCtx->colCtx, &pthis->actor.world.pos, &pthis->unk_264, &sp68, &sp74, 1, 0, 0,
                                      1))) ||
        (pthis->unk_222 == 0)) {
        if (sp74 != NULL) {
            sp74 = SEGMENTED_TO_VIRTUAL(sp74);
            sp62 = Math_FAtan2F(sp74->normal.x, sp74->normal.z) * ((f32)0x8000 / M_PI);
        } else {
            sp62 = pthis->actor.world.rot.y + 0x8000;
        }
        if ((pthis->unk_236 != sp62) || (sp64 == 0)) {
            if (BgCheck_AnyLineTest2(&globalCtx->colCtx, &pthis->unk_270, &pthis->unk_288, &sp68, &sp74, 1, 0, 0, 1)) {
                sp64 |= 2;
            }
            if (BgCheck_AnyLineTest2(&globalCtx->colCtx, &pthis->unk_270, &pthis->unk_27C, &sp68, &sp74, 1, 0, 0, 1)) {
                sp64 |= 4;
            }
            switch (sp64) {
                case 0:
                    pthis->unk_236 += pthis->unk_238;
                case 1:
                    if (pthis->unk_221 == 3) {
                        if (globalCtx->gameplayFrames & 2) {
                            pthis->unk_238 = 0x4000;
                        } else {
                            pthis->unk_238 = -0x4000;
                        }
                    } else {
                        if ((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y) >= 0.0f) {
                            pthis->unk_238 = 0x4000;
                        } else {
                            pthis->unk_238 = -0x4000;
                        }
                        if (pthis->unk_221 == 1) {
                            pthis->unk_238 = -pthis->unk_238;
                        }
                    }
                    break;
                case 2:
                    pthis->unk_236 += pthis->unk_238;
                case 3:
                    pthis->unk_238 = 0x4000;
                    break;
                case 4:
                    pthis->unk_236 += pthis->unk_238;
                case 5:
                    pthis->unk_238 = -0x4000;
                    break;
                case 7:
                    pthis->unk_238 = 0;
                    break;
            }
            if (sp64 != 6) {
                pthis->unk_236 = sp62;
            }
            pthis->unk_222 = (Rand_ZeroOne() * 200.0f) + 200.0f;
        }
    } else if ((pthis->actor.speedXZ != 0.0f) && (pthis->actor.bgCheckFlags & 8)) {
        if (pthis->unk_236 != pthis->actor.wallYaw) {
            sp64 = 1;
            pthis->unk_236 = pthis->actor.wallYaw;
            if (pthis->unk_221 == 3) {
                if (globalCtx->gameplayFrames & 0x20) {
                    pthis->unk_238 = 0x4000;
                } else {
                    pthis->unk_238 = -0x4000;
                }
                pthis->actor.bgCheckFlags &= ~8;
                pthis->unk_222 = (Rand_ZeroOne() * 20.0f) + 160.0f;
            } else {
                if ((s16)(pthis->actor.yawTowardsPlayer - pthis->unk_236) >= 0) {
                    pthis->unk_238 = 0x4000;
                } else {
                    pthis->unk_238 = -0x4000;
                }
                if (pthis->unk_221 == 1) {
                    pthis->unk_238 = -pthis->unk_238;
                }
            }
        } else if (pthis->unk_221 == 0) {
            sp64 = BgCheck_AnyLineTest2(&globalCtx->colCtx, &pthis->actor.world.pos, &player->actor.world.pos, &sp68,
                                        &sp74, 1, 0, 0, 1);
            if (sp64 != 0) {
                sp74 = SEGMENTED_TO_VIRTUAL(sp74);
                sp60 = Math_FAtan2F(sp74->normal.x, sp74->normal.z) * ((f32)0x8000 / M_PI);
                if (pthis->unk_236 != sp60) {
                    if ((s16)(pthis->actor.yawTowardsPlayer - sp60) >= 0) {
                        pthis->unk_238 = 0x4000;
                    } else {
                        pthis->unk_238 = -0x4000;
                    }
                    pthis->unk_236 = sp60;
                }
            }
        }
    }
    pthis->unk_222--;
    if (pthis->unk_224 != 0) {
        pthis->unk_224--;
    }
    if ((pthis->unk_234 == 0) &&
        !Actor_TestFloorInDirection(&pthis->actor, globalCtx, 50.0f, pthis->unk_236 + pthis->unk_238)) {
        if (pthis->unk_238 != 0x4000) {
            pthis->unk_238 = 0x4000;
        } else {
            pthis->unk_238 = -0x4000;
        }
    }
    switch (pthis->unk_221) {
        case 3:
            Math_SmoothStepToF(&pthis->unk_248, 0.6f, 1.0f, 0.05f, 0.0f);
            if ((pthis->unk_224 == 0) && (pthis->actor.xzDistToPlayer < 200.0f) &&
                (ABS(pthis->actor.yDistToPlayer) < 50.0f) && Actor_IsFacingPlayer(&pthis->actor, 0x1C70)) {
                func_809CF72C(pthis);
            } else {
                Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_236 + pthis->unk_238, 1,
                                   pthis->actor.speedXZ * 1000.0f, 0);
            }
            break;
        case 0:
            Math_SmoothStepToF(&pthis->unk_248, 0.6f, 1.0f, 0.05f, 0.0f);
            if (sp64 == 0) {
                Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1,
                                   pthis->actor.speedXZ * 1000.0f, 0);
                if ((pthis->actor.xzDistToPlayer < 90.0f) && (pthis->actor.yDistToPlayer < 50.0f) &&
                    Actor_IsFacingPlayer(&pthis->actor, 0x1554) &&
                    Actor_TestFloorInDirection(&pthis->actor, globalCtx, 71.24802f, pthis->actor.yawTowardsPlayer)) {
                    func_809CF8F0(pthis);
                }
            } else {
                Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_236 + pthis->unk_238, 1,
                                   pthis->actor.speedXZ * 1000.0f, 0);
            }
            if ((pthis->unk_224 == 0) || (ABS(pthis->actor.yDistToPlayer) > 60.0f) || (player2->stateFlags1 & 0x6000)) {
                pthis->unk_221 = 3;
                pthis->unk_224 = 150;
                pthis->unk_250 = 0.0f;
            }
            break;
        case 1:
            if (((sp64 == 0) && !(pthis->actor.bgCheckFlags & 8)) || Actor_IsFacingPlayer(&pthis->actor, 0x1C70)) {
                if (Actor_IsFacingPlayer(&pthis->actor, 0x1C70)) {
                    pthis->unk_238 = -pthis->unk_238;
                }
                Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer - 0x8000, 1,
                                   pthis->actor.speedXZ * 1000.0f, 0);
            } else {
                Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_236 + pthis->unk_238, 1,
                                   pthis->actor.speedXZ * 1000.0f, 0);
            }
            if (pthis->unk_224 <= 200) {
                sp60 = Math_SinS(pthis->unk_224 * (0x960 - pthis->unk_224)) * 55.0f;
                pthis->color1.r = 255 - ABS(sp60);
                sp60 = Math_SinS(pthis->unk_224 * (0x960 - pthis->unk_224)) * 115.0f;
                pthis->color1.g = ABS(sp60) + 85;
                sp60 = Math_SinS(0x960 - pthis->unk_224) * 255.0f;
                pthis->color1.b = ABS(sp60);
                if (pthis->unk_224 == 0) {
                    pthis->unk_221 = 3;
                    pthis->unk_250 = 0.0f;
                }
            }
            break;
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void func_809CF72C(EnBw* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_bw_Anim_0021A0, -2.0f);
    pthis->unk_220 = 3;
    pthis->unk_221 = 0;
    pthis->unk_250 = 0.6f;
    pthis->unk_222 = 20;
    pthis->unk_224 = 0xBB8;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLEWALK_AIM);
    EnBw_SetupAction(pthis, func_809CF7AC);
}

void func_809CF7AC(EnBw* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->unk_222 > 0) {
            pthis->unk_222--;
        } else {
            pthis->unk_222 = 100;
        }
    }
    if (pthis->unk_222 >= 20) {
        pthis->unk_224 -= 250;
    }
    pthis->actor.scale.x = 0.013f - Math_SinF(pthis->unk_224 * 0.001f) * 0.0034999999f;
    pthis->actor.scale.y = 0.013f + Math_SinF(pthis->unk_224 * 0.001f) * 0.0245f;
    pthis->actor.scale.z = 0.013f - Math_SinF(pthis->unk_224 * 0.001f) * 0.0034999999f;
    if (pthis->unk_224 == 0) {
        func_809CE9A8(pthis);
        pthis->unk_224 = 200;
    }
}

void func_809CF8F0(EnBw* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_bw_Anim_002250, -1.0f);
    pthis->actor.speedXZ = 7.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    pthis->unk_220 = 4;
    pthis->unk_222 = 1000;
    pthis->actor.velocity.y = 11.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
    pthis->actor.flags |= ACTOR_FLAG_24;
    EnBw_SetupAction(pthis, func_809CF984);
}

void func_809CF984(EnBw* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 floorPolyType;

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
    pthis->unk_222 += 250;
    pthis->actor.scale.x = 0.013f - Math_SinF(pthis->unk_222 * 0.001f) * 0.0034999999f;
    pthis->actor.scale.y = 0.013f + Math_SinF(pthis->unk_222 * 0.001f) * 0.0245f;
    pthis->actor.scale.z = 0.013f - Math_SinF(pthis->unk_222 * 0.001f) * 0.0034999999f;
    if (pthis->collider1.base.atFlags & AT_HIT) {
        pthis->collider1.base.atFlags &= ~AT_HIT;
        pthis->actor.speedXZ = -6.0f;
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        if ((&player->actor == pthis->collider1.base.at) && !(pthis->collider1.base.atFlags & AT_BOUNCED)) {
            Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
        }
    }
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actor.bgCheckFlags & 3) {
        floorPolyType = func_80041D4C(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);
        if ((floorPolyType == 2) || (floorPolyType == 3) || (floorPolyType == 9)) {
            Actor_Kill(&pthis->actor);
            return;
        }
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 30.0f, 0xB, 4.0f, 0, 0, 0);
        pthis->unk_222 = 3000;
        pthis->actor.flags &= ~ACTOR_FLAG_24;
        pthis->actor.speedXZ = 0.0f;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        EnBw_SetupAction(pthis, func_809CE884);
    }
}

void func_809CFBA8(EnBw* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &object_bw_Anim_002250, -1.0f);
    pthis->unk_220 = 5;
    pthis->unk_222 = 1000;
    pthis->unk_260 = 0.0f;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 11.0f;
    pthis->unk_25C = Rand_ZeroOne() * 0.25f + 1.0f;
    pthis->unk_224 = 0xBB8;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLEWALK_REVERSE);
    EnBw_SetupAction(pthis, func_809CFC4C);
}

void func_809CFC4C(EnBw* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.z, 0x7FFF, 1, 0xFA0, 0);
    Math_SmoothStepToF(&pthis->unk_248, 0.0f, 1.0f, 0.05f, 0.0f);
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actor.bgCheckFlags & 3) {
        if ((globalCtx->gameplayFrames % 0x80) == 0) {
            pthis->unk_25C = (Rand_ZeroOne() * 0.25f) + 0.7f;
        }
        pthis->unk_221 = 4;
        pthis->unk_258 += pthis->unk_25C;
        Math_SmoothStepToF(&pthis->unk_260, 0.075f, 1.0f, 0.005f, 0.0f);
        if (pthis->actor.bgCheckFlags & 2) {
            Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 30.0f, 0xB, 4.0f, 0, 0, 0);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        }
        if (pthis->unk_224 != 0) {
            pthis->unk_224 -= 250;
            pthis->actor.scale.x = 0.013f + Math_SinF(pthis->unk_224 * 0.001f) * 0.0069999998f;
            pthis->actor.scale.y = 0.013f - Math_SinF(pthis->unk_224 * 0.001f) * 0.0069999998f;
            pthis->actor.scale.z = 0.013f + Math_SinF(pthis->unk_224 * 0.001f) * 0.0069999998f;
        }
        pthis->unk_222--;
        if (pthis->unk_222 == 0) {
            func_809CFF10(pthis);
        }
    } else {
        pthis->color1.r -= 8;
        pthis->color1.g += 32;
        if (pthis->color1.r < 200) {
            pthis->color1.r = 200;
        }
        if (pthis->color1.g > 200) {
            pthis->color1.g = 200;
        }
        if (pthis->color1.b > 235) {
            pthis->color1.b = 255;
        } else {
            pthis->color1.b += 40;
        }
        if (pthis->actor.shape.yOffset < 1000.0f) {
            pthis->actor.shape.yOffset += 200.0f;
        }
    }
}

void func_809CFF10(EnBw* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &object_bw_Anim_002250, -1.0f);
    pthis->unk_220 = 6;
    pthis->unk_222 = 1000;
    pthis->unk_221 = 3;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 11.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLEWALK_REVERSE);
    pthis->actor.bgCheckFlags &= ~1;
    EnBw_SetupAction(pthis, func_809CFF98);
}

void func_809CFF98(EnBw* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.z, 0, 1, 0xFA0, 0);
    Math_SmoothStepToF(&pthis->unk_248, 0.6f, 1.0f, 0.05f, 0.0f);
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actor.bgCheckFlags & 3) {
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 30.0f, 0xB, 4.0f, 0, 0, 0);
        pthis->unk_222 = 0xBB8;
        pthis->unk_250 = 0.0f;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        EnBw_SetupAction(pthis, func_809CE884);
    }
    if (pthis->color1.r < 247) {
        pthis->color1.r += 8;
    } else {
        pthis->color1.r = 255;
    }
    if (pthis->color1.g < 32) {
        pthis->color1.g = 0;
    } else {
        pthis->color1.g -= 32;
    }
    if (pthis->color1.b < 40) {
        pthis->color1.b = 0;
    } else {
        pthis->color1.b -= 40;
    }
    if (pthis->actor.shape.yOffset > 0.0f) {
        pthis->actor.shape.yOffset -= 200.0f;
    }
}

void func_809D00F4(EnBw* pthis) {
    pthis->unk_220 = 0;
    pthis->unk_222 = 40;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLEWALK_DEAD);
    EnBw_SetupAction(pthis, func_809D014C);
}

void func_809D014C(EnBw* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_230) {
        pthis->actor.scale.x += 0.0002f;
        pthis->actor.scale.y -= 0.0002f;
        pthis->actor.scale.z += 0.0002f;
    }
    pthis->actor.shape.shadowAlpha = pthis->color1.a -= 6;
    pthis->unk_222--;
    if (pthis->unk_222 <= 0) {
        Actor_Kill(&pthis->actor);
    }
}

void func_809D01CC(EnBw* pthis) {
    pthis->unk_220 = 1;
    pthis->actor.speedXZ = 0.0f;
    pthis->unk_25C = (Rand_ZeroOne() * 0.25f) + 1.0f;
    pthis->unk_260 = 0.0f;
    if (pthis->damageEffect == 0xE) {
        pthis->iceTimer = 0x50;
    }
    pthis->unk_222 = (pthis->actor.colorFilterParams & 0x4000) ? 25 : 80;
    EnBw_SetupAction(pthis, func_809D0268);
}

void func_809D0268(EnBw* pthis, GlobalContext* globalCtx) {
    pthis->color1.r -= 1;
    pthis->color1.g += 4;
    pthis->color1.b += 5;
    if (pthis->color1.r < 200) {
        pthis->color1.r = 200;
    }
    if (pthis->color1.g > 200) {
        pthis->color1.g = 200;
    }
    if (pthis->color1.b > 230) {
        pthis->color1.b = 230;
    }
    if (pthis->actor.colorFilterParams & 0x4000) {
        if ((globalCtx->gameplayFrames % 0x80) == 0) {
            pthis->unk_25C = 0.5f + Rand_ZeroOne() * 0.25f;
        }
        pthis->unk_258 += pthis->unk_25C;
        Math_SmoothStepToF(&pthis->unk_260, 0.075f, 1.0f, 0.005f, 0.0f);
    }
    pthis->unk_222--;
    if (pthis->unk_222 == 0) {
        func_809CE9A8(pthis);
        pthis->color1.r = pthis->color1.g = 200;
        pthis->color1.b = 255;
        pthis->unk_224 = 0x258;
        pthis->unk_221 = 1;
        pthis->unk_250 = 0.7f;
        pthis->unk_236++;
    }
}

void func_809D03CC(EnBw* pthis) {
    pthis->actor.speedXZ = 0.0f;
    if (pthis->damageEffect == 0xE) {
        pthis->iceTimer = 32;
    }
    pthis->unk_23C = pthis->actor.colorFilterTimer;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    EnBw_SetupAction(pthis, func_809D0424);
}

void func_809D0424(EnBw* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.colorFilterTimer == 0) {
        pthis->unk_23C = 0;
        if (pthis->actor.colChkInfo.health != 0) {
            if ((pthis->unk_220 != 5) && (pthis->unk_220 != 6)) {
                func_809CE9A8(pthis);
                pthis->color1.r = pthis->color1.g = 200;
                pthis->color1.b = 255;
                pthis->unk_224 = 0x258;
                pthis->unk_221 = 1;
                pthis->unk_250 = 0.7f;
                pthis->unk_236++;
            } else if (pthis->unk_220 != 5) {
                EnBw_SetupAction(pthis, func_809CFF98);
            } else {
                func_809CFF10(pthis);
            }
        } else {
            if (func_800355E4(globalCtx, &pthis->collider2.base)) {
                pthis->unk_230 = 0;
                pthis->actor.scale.y -= 0.009f;
                Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 30.0f, 0xB, 4.0f, 0, 0, 0);
            } else {
                pthis->unk_230 = 1;
            }
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x90);
            func_809D00F4(pthis);
        }
    }
}

void func_809D0584(EnBw* pthis, GlobalContext* globalCtx) {
    if ((pthis->actor.bgCheckFlags & 0x10) && (pthis->actor.bgCheckFlags & 1)) {
        pthis->unk_230 = 0;
        pthis->actor.scale.y -= 0.009f;
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 30.0f, 0xB, 4.0f, 0, 0, 0);
        func_809D00F4(pthis);
    } else {
        if (pthis->collider2.base.acFlags & AC_HIT) {
            pthis->collider2.base.acFlags &= ~AC_HIT;
            if ((pthis->actor.colChkInfo.damageEffect == 0) || (pthis->unk_220 == 6)) {
                return;
            }
            pthis->damageEffect = pthis->actor.colChkInfo.damageEffect;
            Actor_SetDropFlag(&pthis->actor, &pthis->collider2.info, 0);
            if ((pthis->damageEffect == 1) || (pthis->damageEffect == 0xE)) {
                if (pthis->unk_23C == 0) {
                    Actor_ApplyDamage(&pthis->actor);
                    Actor_SetColorFilter(&pthis->actor, 0, 0x78, 0, 0x50);
                    func_809D03CC(pthis);
                    pthis->unk_248 = 0.0f;
                }
                return;
            }
            if (pthis->unk_248 == 0.0f) {
                Actor_ApplyDamage(&pthis->actor);
            }
            if (((pthis->unk_221 == 1) || (pthis->unk_221 == 4)) && (pthis->actor.colChkInfo.health == 0)) {
                if (pthis->unk_220 != 0) {
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
                    if (func_800355E4(globalCtx, &pthis->collider2.base)) {
                        pthis->unk_230 = 0;
                        pthis->actor.scale.y -= 0.009f;
                        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 30.0f, 0xB, 4.0f, 0,
                                                 0, 0);
                    } else {
                        pthis->unk_230 = 1;
                    }
                    Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x90);
                    func_809D00F4(pthis);
                }
            } else if ((pthis->unk_220 != 1) && (pthis->unk_220 != 6)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLEWALK_DAMAGE);
                Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
                if (pthis->unk_220 != 5) {
                    func_809D01CC(pthis);
                }
                pthis->unk_248 = 0.0f;
            }
        }
        if ((globalCtx->actorCtx.unk_02 != 0) && (pthis->actor.xzDistToPlayer <= 400.0f) &&
            (pthis->actor.bgCheckFlags & 1)) {
            if (pthis->unk_220 == 5) {
                pthis->unk_23C = 0;
                func_809CFF10(pthis);
            } else if (pthis->unk_220 != 0) {
                pthis->unk_23C = 0;
                func_809CFBA8(pthis);
            }
        }
    }
}

void EnBw_Update(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnBw* pthis = (EnBw*)thisx;
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    s32 pad[3]; // probably an unused Vec3f
    Color_RGBA8 sp50 = { 255, 200, 0, 255 };
    Color_RGBA8 sp4C = { 255, 80, 0, 255 };
    Color_RGBA8 sp48 = { 0, 0, 0, 255 };
    Color_RGBA8 sp44 = { 0, 0, 0, 220 };

    func_809D0584(pthis, globalCtx);
    if (thisx->colChkInfo.damageEffect != 6) {
        pthis->actionFunc(pthis, globalCtx);
        if (pthis->unk_23C == 0) {
            pthis->unk_23A = (pthis->unk_23A + 4) & 0x7F;
        }
        if ((globalCtx->gameplayFrames & pthis->unk_221) == 0) {
            accel.y = -3.0f;
            velocity.x = Rand_CenteredFloat(pthis->unk_248 * 24.0f);
            velocity.y = pthis->unk_248 * 30.0f;
            velocity.z = Rand_CenteredFloat(pthis->unk_248 * 24.0f);
            accel.x = velocity.x * -0.075f;
            accel.z = velocity.z * -0.075f;
            func_8002836C(globalCtx, &thisx->world.pos, &velocity, &accel, &sp50, &sp4C, 0x3C, 0, 0x14);
        }
        if (pthis->unk_248 <= 0.4f) {
            pthis->collider1.info.toucher.effect = 0;
            if (((globalCtx->gameplayFrames & 1) == 0) && (pthis->unk_220 < 5) && (pthis->unk_23C == 0)) {
                accel.y = -0.1f;
                velocity.x = Rand_CenteredFloat(4.0f);
                velocity.y = Rand_CenteredFloat(2.0f) + 6.0f;
                velocity.z = Rand_CenteredFloat(4.0f);
                accel.x = velocity.x * -0.1f;
                accel.z = velocity.z * -0.1f;
                Rand_CenteredFloat(4.0f);
                Rand_CenteredFloat(4.0f);
                sp48.a = pthis->color1.a;
                if (sp48.a >= 30) {
                    sp44.a = sp48.a - 30;
                } else {
                    sp44.a = 0;
                }
                func_8002836C(globalCtx, &thisx->world.pos, &velocity, &accel, &sp48, &sp44, 0xB4, 0x28,
                              20.0f - (pthis->unk_248 * 40.0f));
            }
        } else {
            pthis->collider1.info.toucher.effect = 1;
        }

        pthis->unk_234 = Actor_TestFloorInDirection(thisx, globalCtx, 50.0f, thisx->world.rot.y);
        if ((pthis->unk_220 == 4) || (pthis->unk_220 == 6) || (pthis->unk_220 == 5) || (pthis->unk_220 == 1) ||
            (pthis->unk_234 != 0)) {
            Actor_MoveForward(thisx);
        }
        Actor_UpdateBgCheckInfo(globalCtx, thisx, 20.0f, 30.0f, 21.0f, 0x1F);
    }
    Collider_UpdateCylinder(thisx, &pthis->collider2);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider2.base);
    if ((pthis->unk_220 != 0) && ((thisx->colorFilterTimer == 0) || !(thisx->colorFilterParams & 0x4000))) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider2.base);
    }
    if ((pthis->unk_221 != 1) && (pthis->unk_220 < 5) && (pthis->unk_248 > 0.4f)) {
        Collider_UpdateCylinder(thisx, &pthis->collider1);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider1.base);
    }
    thisx->focus.pos = thisx->world.pos;
    thisx->focus.pos.y += 5.0f;
}

s32 EnBw_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                          Gfx** gfx) {
    EnBw* pthis = (EnBw*)thisx;

    if (limbIndex == 1) {
        gSPSegment((*gfx)++, 0x09,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x20, 1, 0, pthis->unk_23A, 0x20, 0x20));
        if ((pthis->unk_220 == 1) || (pthis->unk_220 == 5)) {
            Matrix_Push();
            Matrix_Scale(1.0f, 1.0f, 1.0f, MTXMODE_APPLY);
            Matrix_RotateX(pthis->unk_258 * 0.115f, MTXMODE_APPLY);
            Matrix_RotateY(pthis->unk_258 * 0.13f, MTXMODE_APPLY);
            Matrix_RotateZ(pthis->unk_258 * 0.1f, MTXMODE_APPLY);
            Matrix_Scale(1.0f - pthis->unk_260, 1.0f + pthis->unk_260, 1.0f - pthis->unk_260, MTXMODE_APPLY);
            Matrix_RotateZ(-(pthis->unk_258 * 0.1f), MTXMODE_APPLY);
            Matrix_RotateY(-(pthis->unk_258 * 0.13f), MTXMODE_APPLY);
            Matrix_RotateX(-(pthis->unk_258 * 0.115f), MTXMODE_APPLY);
            gSPMatrix((*gfx)++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_bw.c", 1388),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList((*gfx)++, *dList);
            Matrix_Pop();
            return 1;
        }
    }
    return 0;
}

static Vec3f sIceOffsets[] = {
    { 20.0f, 10.0f, 0.0f },  { -20.0f, 10.0f, 0.0f }, { 0.0f, 10.0f, -25.0f }, { 10.0f, 0.0f, 15.0f },
    { 10.0f, 0.0f, -15.0f }, { 0.0f, 10.0f, 25.0f },  { -10.0f, 0.0f, 15.0f }, { -10.0f, 0.0f, -15.0f },
};

void EnBw_Draw(Actor* thisx, GlobalContext* globalCtx2) {
    Vec3f spAC = { 0.0f, 0.0f, 0.0f };
    GlobalContext* globalCtx = globalCtx2;
    EnBw* pthis = (EnBw*)thisx;
    Vec3f icePos;
    s32 iceIndex;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_bw.c", 1423);

    if (pthis->color1.a == 0xFF) {
        func_80093D18(globalCtx->state.gfxCtx);
        gDPSetEnvColor(POLY_OPA_DISP++, pthis->color1.r, pthis->color1.g, pthis->color1.b, pthis->color1.a);
        gSPSegment(POLY_OPA_DISP++, 0x08, &D_80116280[2]);
        POLY_OPA_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                       EnBw_OverrideLimbDraw, NULL, pthis, POLY_OPA_DISP);
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 0, 0, 0, pthis->color1.a);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->color1.r, pthis->color1.g, pthis->color1.b, pthis->color1.a);
        gSPSegment(POLY_XLU_DISP++, 0x08, &D_80116280[0]);
        POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                       EnBw_OverrideLimbDraw, NULL, pthis, POLY_XLU_DISP);
    }

    if (((globalCtx->gameplayFrames + 1) % 4) == (u32)thisx->params) {
        spAC.z = thisx->scale.z * 375000.0f;
        Matrix_MultVec3f(&spAC, &pthis->unk_264);
        spAC.z = thisx->scale.z * 150000.0f;
        Matrix_MultVec3f(&spAC, &pthis->unk_270);
        spAC.x = thisx->scale.x * 550000.0f;
        Matrix_MultVec3f(&spAC, &pthis->unk_288);
        spAC.x = -spAC.x;
        Matrix_MultVec3f(&spAC, &pthis->unk_27C);
    }

    Matrix_Translate(thisx->world.pos.x, thisx->world.pos.y + ((thisx->scale.y - 0.013f) * 1000.0f), thisx->world.pos.z,
                     MTXMODE_NEW);
    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                (globalCtx->gameplayFrames * -20) % 0x200, 0x20, 0x80));
    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 0, 255);
    Matrix_Scale(pthis->unk_248 * 0.01f, pthis->unk_248 * 0.01f, pthis->unk_248 * 0.01f, MTXMODE_APPLY);
    func_800D1FD4(&globalCtx->billboardMtxF);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_bw.c", 1500),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);

    if (pthis->iceTimer != 0) {
        thisx->colorFilterTimer++;
        pthis->iceTimer--;
        if ((pthis->iceTimer.whole() & 3) == 0) {
            iceIndex = pthis->iceTimer.whole() >> 2;

            icePos.x = sIceOffsets[iceIndex].x + thisx->world.pos.x;
            icePos.y = sIceOffsets[iceIndex].y + thisx->world.pos.y;
            icePos.z = sIceOffsets[iceIndex].z + thisx->world.pos.z;
            EffectSsEnIce_SpawnFlyingVec3f(globalCtx, thisx, &icePos, 0x96, 0x96, 0x96, 0xFA, 0xEB, 0xF5, 0xFF, 1.3f);
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_bw.c", 1521);
}
