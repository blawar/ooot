#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_NIW_Z_EN_NIW_C
#include "actor_common.h"
/*
 * File: z_en_niw.c
 * Overlay: ovl_En_Niw
 * Description: Cucco
 */

#include "z_en_niw.h"
#include "objects/object_niw/object_niw.h"
#include "overlays/actors/ovl_En_Attack_Niw/z_en_attack_niw.h"
#include "vt.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_23)

void EnNiw_Init(Actor* thisx, GlobalContext* globalCtx);
void EnNiw_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnNiw_Update(Actor* thisx, GlobalContext* globalCtx);
void EnNiw_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnNiw_ResetAction(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB6324(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB63A8(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB6450(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB6570(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB6A38(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB6BF8(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB6D08(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB6EB4(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB70F8(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB714C(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB7204(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB7290(EnNiw* pthis, GlobalContext* globalCtx);
void func_80AB7328(EnNiw* pthis, GlobalContext* globalCtx);
void EnNiw_FeatherSpawn(EnNiw* pthis, Vec3f* pos, Vec3f* vel, Vec3f* accel, f32 scale);
void EnNiw_FeatherUpdate(EnNiw* pthis, GlobalContext* globalCtx);
void EnNiw_FeatherDraw(EnNiw* pthis, GlobalContext* globalCtx);

static s16 D_80AB85E0 = 0;

ActorInit En_Niw_InitVars = {
    ACTOR_EN_NIW,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_NIW,
    sizeof(EnNiw),
    (ActorFunc)EnNiw_Init,
    (ActorFunc)EnNiw_Destroy,
    (ActorFunc)EnNiw_Update,
    (ActorFunc)EnNiw_Draw,
};

static f32 D_80AB8604[] = {
    5000.0f,
    -5000.0f,
};

static f32 D_80AB860C[] = {
    5000.0f,
    3000.0f,
    4000.0f,
};

static Vec3f sKakarikoPosList[] = {
    { -1697.0f, 80.0f, 870.0f }, { 57.0f, 320.0f, -673.0f }, { 796.0f, 80.0f, 1639.0f }, { 1417.0f, 465.0f, 169.0f },
    { -60.0f, 0.0f, -46.0f },    { -247.0f, 80.0f, 854.0f }, { 1079.0f, 80.0f, -47.0f },
};

static s16 sKakarikoFlagList[] = {
    0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000,
};

static u8 sLowerRiverSpawned = false;

static u8 sUpperRiverSpawned = false;

static ColliderCylinderInit sCylinderInit1 = {
    {
        COLTYPE_HIT5,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON,
        OC2_TYPE_2,
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
    { 15, 25, 4, { 0, 0, 0 } },
};

static ColliderCylinderInit sCylinderInit2 = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 15, 25, 4, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 6, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -2000, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 0, ICHAIN_STOP),
};

void EnNiw_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnNiw* pthis = (EnNiw*)thisx;
    s32 pad;
    s32 i;

    if (pthis->actor.params < 0) {
        pthis->actor.params = 0;
    }

    // Cucco at at the very beginning of Zora's River
    if (pthis->actor.params == 0xB) {
        if (sLowerRiverSpawned) {
            Actor_Kill(&pthis->actor);
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ もういてる原 Ver.1 ☆☆☆☆☆ \n" VT_RST);
            return;
        }
        sLowerRiverSpawned = true;
        pthis->actor.room = -1;
    }

    // Cucco at tall platform in the first room of Zora's River
    if (pthis->actor.params == 0xC) {
        if (sUpperRiverSpawned) {
            Actor_Kill(&pthis->actor);
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ もういてる原 Ver.2 ☆☆☆☆☆ \n" VT_RST);
            return;
        }
        sUpperRiverSpawned = true;
        pthis->actor.room = -1;
    }

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.flags |= ACTOR_FLAG_0;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gCuccoSkel, &gCuccoAnim, pthis->jointTable, pthis->morphTable, 16);

    if (globalCtx->sceneNum == SCENE_SPOT01) {
        for (i = 0; i < ARRAY_COUNT(sKakarikoPosList); i++) {
            if (fabsf(pthis->actor.world.pos.x - sKakarikoPosList[i].x) < 40.0f &&
                fabsf(pthis->actor.world.pos.z - sKakarikoPosList[i].z) < 40.0f) {
                pthis->unk_2AA = i;
                osSyncPrintf(VT_FGCOL(YELLOW) " 通常鶏index %d\n" VT_RST, pthis->unk_2AA);
                if (gSaveContext.infTable[25] & sKakarikoFlagList[i]) {
                    pthis->actor.world.pos.x = 300.0f;
                    pthis->actor.world.pos.y = 100.0f;
                    pthis->actor.world.pos.z = 1530.0f;
                    pthis->actor.params = 0;
                }
            }
        }
    }

    Math_Vec3f_Copy(&pthis->unk_2AC, &pthis->actor.world.pos);
    Math_Vec3f_Copy(&pthis->unk_2B8, &pthis->actor.world.pos);
    pthis->unk_304 = 10.0f;
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->unk_2A4 = (s16)Rand_ZeroFloat(3.99f) + 5;

    if (pthis->unk_2A4 < 0) {
        pthis->unk_2A4 = 1;
    }

    switch (pthis->actor.params) {
        case 2:
            if (IS_DAY) {
                Actor_Kill(&pthis->actor);
            }
            break;
        case 1:
            if (gSaveContext.eventChkInf[1] & 0x10) {
                Actor_Kill(&pthis->actor);
            }
            break;
        case 3:
            if (!(gSaveContext.eventChkInf[1] & 0x10)) {
                Actor_Kill(&pthis->actor);
            }
            break;
        case 5:
            if (gSaveContext.eventChkInf[1] & 0x100) {
                Actor_Kill(&pthis->actor);
            }
            break;
        case 7:
            if (!(gSaveContext.eventChkInf[1] & 0x100)) {
                Actor_Kill(&pthis->actor);
            }
            break;
        case 0xD:
            pthis->actor.gravity = 0.0f;
        case 0xE:
            pthis->actor.colChkInfo.mass = 0;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            break;
        case 4:
            pthis->actor.gravity = 0.0f;
            break;
    }

    Collider_InitCylinder(globalCtx, &pthis->collider);

    switch (pthis->actor.params) {
        case 0xA:
            pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
        case 0xD:
        case 0xE:
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit2);
            if (globalCtx->sceneNum == SCENE_LINK_HOME && !(gSaveContext.eventChkInf[1] & 0x4000)) {
                Actor_Kill(&pthis->actor);
            }
            break;
        default:
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit1);
            break;
    }

    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ どんな奴？ ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params);
    osSyncPrintf("\n\n");
    pthis->actionFunc = EnNiw_ResetAction;
}

void EnNiw_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnNiw* pthis = (EnNiw*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AB5BF8(EnNiw* pthis, GlobalContext* globalCtx, s16 arg2) {
    f32 factor = 1.0f;

    if (pthis->actor.params == 0xD) {
        factor = 2.0f;
    }
    if (pthis->timer1 == 0) {
        if (arg2 == 0) {
            pthis->unk_26C[0] = 0.0f;
        } else {
            pthis->unk_26C[0] = -10000.0f * factor;
        }
        pthis->unk_298++;
        pthis->timer1 = 3;
        if (!(pthis->unk_298 & 1)) {
            pthis->unk_26C[0] = 0.0f;

            if (arg2 == 0) {
                pthis->timer1 = Rand_ZeroFloat(30.0f);
            }
        }
    }
    if (pthis->timer2 == 0) {
        pthis->unk_29C++;
        pthis->unk_29C &= 1;

        switch (arg2) {
            case 0:
                pthis->unk_26C[1] = pthis->unk_26C[2] = 0.0f;
                break;
            case 1:
                pthis->timer2 = 3;
                pthis->unk_26C[1] = pthis->unk_26C[2] = 7000.0f * factor;

                if (pthis->unk_29C == 0) {
                    pthis->unk_26C[1] = pthis->unk_26C[2] = 0.0f;
                }
                break;
            case 2:
                pthis->timer2 = 2;
                pthis->unk_26C[1] = pthis->unk_26C[2] = -10000.0f;
                pthis->unk_26C[7] = pthis->unk_26C[5] = 25000.0f;
                pthis->unk_26C[8] = pthis->unk_26C[6] = 6000.0f;

                if (pthis->unk_29C == 0) {
                    pthis->unk_26C[5] = pthis->unk_26C[7] = 8000.0f;
                }
                break;
            case 3:
                pthis->timer2 = 2;
                pthis->unk_26C[7] = pthis->unk_26C[5] = 10000.0f;

                if (pthis->unk_29C == 0) {
                    pthis->unk_26C[7] = pthis->unk_26C[5] = 3000.0f;
                }
                break;
            case 4:
                pthis->timer1 = 5;
                break;
            case 5:
                pthis->timer2 = 5;
                pthis->unk_26C[7] = pthis->unk_26C[5] = 14000.0f;
                if (pthis->unk_29C == 0) {
                    pthis->unk_26C[7] = pthis->unk_26C[5] = 10000.0f;
                }
                break;
        }
    }
    if (pthis->unk_2E0 != pthis->unk_26C[9]) {
        Math_ApproachF(&pthis->unk_2E0, pthis->unk_26C[9], 0.5f, 4000.0f);
    }
    if (pthis->unk_2DC != pthis->unk_26C[0]) {
        Math_ApproachF(&pthis->unk_2DC, pthis->unk_26C[0], 0.5f, 4000.0f);
    }
    if (pthis->unk_2C4 != pthis->unk_26C[2]) {
        Math_ApproachF(&pthis->unk_2C4, pthis->unk_26C[2], 0.8f, 7000.0f);
    }
    if (pthis->unk_2C8 != pthis->unk_26C[7]) {
        Math_ApproachF(&pthis->unk_2C8, pthis->unk_26C[7], 0.8f, 7000.0f);
    }
    if (pthis->unk_2CC != pthis->unk_26C[8]) {
        Math_ApproachF(&pthis->unk_2CC, pthis->unk_26C[8], 0.8f, 7000.0f);
    }
    if (pthis->unk_2D0 != pthis->unk_26C[1]) {
        Math_ApproachF(&pthis->unk_2D0, pthis->unk_26C[1], 0.8f, 7000.0f);
    }
    if (pthis->unk_2D4 != pthis->unk_26C[5]) {
        Math_ApproachF(&pthis->unk_2D4, pthis->unk_26C[5], 0.8f, 7000.0f);
    }
    if (pthis->unk_2D8 != pthis->unk_26C[6]) {
        Math_ApproachF(&pthis->unk_2D8, pthis->unk_26C[6], 0.8f, 7000.0f);
    }
}

void EnNiw_SpawnAttackCucco(EnNiw* pthis, GlobalContext* globalCtx) {
    f32 viewX;
    f32 viewY;
    f32 viewZ;
    Vec3f attackCuccoPos;
    Actor* attackCucco;

    if ((pthis->timer5 == 0) && (pthis->unk_296 < 7)) {
        viewX = globalCtx->view.lookAt.x - globalCtx->view.eye.x;
        viewY = globalCtx->view.lookAt.y - globalCtx->view.eye.y;
        viewZ = globalCtx->view.lookAt.z - globalCtx->view.eye.z;
        attackCuccoPos.x = ((Rand_ZeroOne() - 0.5f) * viewX) + globalCtx->view.eye.x;
        attackCuccoPos.y = Rand_CenteredFloat(0.3f) + ((globalCtx->view.eye.y + 50.0f) + (viewY * 0.5f));
        attackCuccoPos.z = ((Rand_ZeroOne() - 0.5f) * viewZ) + globalCtx->view.eye.z;
        attackCucco = Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ATTACK_NIW,
                                         attackCuccoPos.x, attackCuccoPos.y, attackCuccoPos.z, 0, 0, 0, 0);

        if (attackCucco != NULL) {
            pthis->unk_296++;
            pthis->timer5 = 10;
        } else {
            osSyncPrintf("\n\n");
            osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 発生できず  ☆☆☆☆☆ \n" VT_RST);
        }
    }
}

void func_80AB6100(EnNiw* pthis, GlobalContext* globalCtx, s32 arg2) {
    f32 factor;
    f32 targetRotY;

    if (pthis->timer4 == 0) {
        pthis->timer4 = 3;

        if (pthis->actor.bgCheckFlags & 1) {
            pthis->actor.velocity.y = 3.5f;
        }
    }
    if (pthis->timer3 == 0) {
        pthis->unk_2A0++;
        pthis->unk_2A0 &= 1;
        pthis->timer3 = 5;
    }
    if (pthis->unk_2A0 == 0) {
        factor = D_80AB860C[arg2];
    } else {
        factor = -D_80AB860C[arg2];
    }
    if (arg2 == 1) {
        if (pthis->timer6 == 0 || pthis->actor.bgCheckFlags & 8) {
            pthis->timer6 = 150;
            if (pthis->timer8 == 0) {
                pthis->timer8 = 70;
                pthis->unk_2E4 = pthis->actor.yawTowardsPlayer;
            }
        }
    }
    targetRotY = pthis->unk_2E4 + factor;
    Math_SmoothStepToS(&pthis->actor.world.rot.y, targetRotY, 3, pthis->unk_2FC, 0);
    Math_ApproachF(&pthis->unk_2FC, 3000.0f, 1.0f, 500.0f);
    func_80AB5BF8(pthis, globalCtx, 5);
}

void EnNiw_ResetAction(EnNiw* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gCuccoAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gCuccoAnim), ANIMMODE_LOOP,
                     -10.0f);

    switch (pthis->actor.params) {
        case 4:
            pthis->actionFunc = func_80AB6450;
            break;
        case 0xD:
            pthis->actionFunc = func_80AB6324;
            break;
        default:
            pthis->actionFunc = func_80AB6570;
            break;
    }
}

void func_80AB6324(EnNiw* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_308 != 0) {
        pthis->actor.velocity.y = Rand_ZeroFloat(2.0f) + 4.0f;
        pthis->actor.speedXZ = Rand_ZeroFloat(2.0f) + 3.0f;
        pthis->actionFunc = func_80AB63A8;
    }
    func_80AB5BF8(pthis, globalCtx, 1);
}

void func_80AB63A8(EnNiw* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 1 && pthis->actor.velocity.y < 0.0f) {
        pthis->unk_2AC.x = pthis->unk_2B8.x = pthis->actor.world.pos.x;
        pthis->unk_2AC.y = pthis->unk_2B8.y = pthis->actor.world.pos.y;
        pthis->unk_2AC.z = pthis->unk_2B8.z = pthis->actor.world.pos.z;
        pthis->timer5 = pthis->timer4 = pthis->unk_29E = 0;

        pthis->unk_26C[7] = pthis->unk_26C[5] = pthis->unk_26C[6] = pthis->unk_26C[8] = pthis->actor.speedXZ =
            pthis->unk_2FC = pthis->unk_300 = 0.0f;

        pthis->actionFunc = func_80AB6570;
    } else {
        func_80AB5BF8(pthis, globalCtx, 2);
    }
}

void func_80AB6450(EnNiw* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->actor.xzDistToPlayer < 30.0f && fabsf(pthis->actor.world.pos.y - player->actor.world.pos.y) < 5.0f) {
        pthis->timer6 = 100;
        pthis->actor.gravity = -2.0f;
        pthis->actionFunc = func_80AB7290;
    } else if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.gravity = -2.0f;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_M);
        pthis->sfxTimer1 = 30;
        pthis->path = 0;
        pthis->timer4 = 30;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->actor.speedXZ = 0.0f;
        pthis->actionFunc = func_80AB6BF8;
    } else {
        // GI_NONE in pthis case allows the player to lift the actor
        func_8002F434(&pthis->actor, globalCtx, GI_NONE, 25.0f, 10.0f);
        func_80AB5BF8(pthis, globalCtx, 1);
    }
}

void func_80AB6570(EnNiw* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    f32 posY = Rand_CenteredFloat(100.0f);
    f32 posZ = Rand_CenteredFloat(100.0f);
    s16 tmp;

    if (pthis->actor.params != 0xA) {
        if (Actor_HasParent(&pthis->actor, globalCtx)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_M);
            pthis->sfxTimer1 = 30;
            pthis->path = 0;
            pthis->timer4 = 30;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->actor.speedXZ = 0.0f;
            pthis->actionFunc = func_80AB6BF8;
            return;
        }
        func_8002F580(&pthis->actor, globalCtx);
    } else {
        if (pthis->path != 0) {
            pthis->unk_2A6 = 1;
            if (pthis->sfxTimer3 == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_M);
                pthis->sfxTimer3 = 100;
            }
            pthis->unk_2A0 = Rand_ZeroFloat(1.99f);
            pthis->actor.speedXZ = 4.0f;
            pthis->unk_300 = 0.0f;
            pthis->unk_2FC = 0.0f;
            pthis->actionFunc = func_80AB6A38;
            return;
        }
    }

    tmp = 0;

    if (pthis->timer5 != 0) {
        if (Rand_ZeroFloat(3.99f) < 1.0f) {
            pthis->unk_2E6++;
            pthis->unk_2E6 &= 1;
        }
        Math_ApproachF(&pthis->unk_26C[9], D_80AB8604[pthis->unk_2E6], 0.5f, 4000.0f);
    }

    if (pthis->timer5 == 0 && pthis->timer4 == 0) {
        pthis->unk_29E++;

        if (pthis->unk_29E >= 8) {
            pthis->timer5 = Rand_ZeroFloat(30.0f);
            pthis->unk_29E = Rand_ZeroFloat(3.99f);
            if (pthis->actor.params != 0xA && pthis->actor.params != 8) {
                if (posY < 0.0f) {
                    posY -= 100.0f;
                } else {
                    posY += 100.0f;
                }
                if (posZ < 0.0f) {
                    posZ -= 100.0f;
                } else {
                    posZ += 100.0f;
                }
            } else {
                posY = Rand_CenteredFloat(30.0f);
                posZ = Rand_CenteredFloat(30.0f);
                if (posY < 0.0f) {
                    posY -= 20.0f;
                } else {
                    posY += 20.0f;
                }
                if (posZ < 0.0f) {
                    if (1) {} // Required to match
                    if (1) {}
                    if (1) {}
                    if (1) {}
                    posZ -= 20.0f;
                } else {
                    posZ += 20.0f;
                }
            }
            pthis->unk_2B8.x = pthis->unk_2AC.x + posY;
            pthis->unk_2B8.z = pthis->unk_2AC.z + posZ;
        } else {
            pthis->timer4 = 4;
            if (pthis->actor.bgCheckFlags & 1) {
                pthis->actor.speedXZ = 0.0f;
                pthis->actor.velocity.y = 3.5f;
            }
        }
    }

    if (pthis->timer4 != 0) {
        Math_ApproachZeroF(&pthis->unk_26C[9], 0.5f, 4000.0f);
        tmp = 1;
        Math_ApproachF(&pthis->actor.world.pos.x, pthis->unk_2B8.x, 1.0f, pthis->unk_2FC);
        Math_ApproachF(&pthis->actor.world.pos.z, pthis->unk_2B8.z, 1.0f, pthis->unk_2FC);
        Math_ApproachF(&pthis->unk_2FC, 3.0f, 1.0f, 0.3f);
        posY = pthis->unk_2B8.x - pthis->actor.world.pos.x;
        posZ = pthis->unk_2B8.z - pthis->actor.world.pos.z;

        if (fabsf(posY) < 10.0f) {
            posY = 0.0;
        }
        if (fabsf(posZ) < 10.0f) {
            posZ = 0.0;
        }
        if (posY == 0.0f && posZ == 0.0f) {
            pthis->timer4 = 0;
            pthis->unk_29E = 7;
        }

        Math_SmoothStepToS(&pthis->actor.world.rot.y, Math_FAtan2F(posY, posZ) * (0x8000 / M_PI), 3, pthis->unk_300, 0);
        Math_ApproachF(&pthis->unk_300, 10000.0f, 1.0f, 1000.0f);
    }

    func_80AB5BF8(pthis, globalCtx, tmp);
}

void func_80AB6A38(EnNiw* pthis, GlobalContext* globalCtx) {
    Path* path;
    Vec3s* pointPos;
    f32 pathDiffX;
    f32 pathDiffZ;
    s16 pathIndex = pthis->path - 1;

    if (pthis->path == 0) {
        pthis->unk_2AC.x = pthis->unk_2B8.x = pthis->actor.world.pos.x;
        pthis->unk_2AC.y = pthis->unk_2B8.y = pthis->actor.world.pos.y;
        pthis->unk_2AC.z = pthis->unk_2B8.z = pthis->actor.world.pos.z;
        pthis->timer5 = pthis->timer4 = pthis->unk_29E = 0;
        pthis->unk_26C[7] = pthis->unk_26C[5] = pthis->unk_26C[6] = pthis->unk_26C[8] = pthis->actor.speedXZ =
            pthis->unk_2FC = pthis->unk_300 = 0.0f;
        pthis->actionFunc = EnNiw_ResetAction;
    } else {
        path = &globalCtx->setupPathList[pathIndex];
        pointPos = SEGMENTED_TO_VIRTUAL(path->points);
        pointPos += pthis->waypoint;
        pathDiffX = pointPos->x - pthis->actor.world.pos.x;
        pathDiffZ = pointPos->z - pthis->actor.world.pos.z;
        pthis->unk_2E4 = Math_FAtan2F(pathDiffX, pathDiffZ) * (0x8000 / M_PI);
        func_80AB6100(pthis, globalCtx, 2);

        if (fabsf(pathDiffX) < 30.0f && fabsf(pathDiffZ) < 30.0f) {
            pthis->waypoint++;
            if (pthis->waypoint >= pthis->unk_2EC) {
                pthis->waypoint = 0;
            }
        }

        func_80AB5BF8(pthis, globalCtx, 2);
    }
}

void func_80AB6BF8(EnNiw* pthis, GlobalContext* globalCtx) {
    if (pthis->timer4 == 0) {
        pthis->unk_2A6 = 2;
        pthis->timer4 = 10;
    }

    pthis->actor.shape.rot.x = Rand_CenteredFloat(5000.0f);
    pthis->actor.shape.rot.y = Rand_CenteredFloat(5000.0f);
    pthis->actor.shape.rot.z = Rand_CenteredFloat(5000.0f);

    if (Actor_HasNoParent(&pthis->actor, globalCtx)) {
        if (pthis->actor.params == 0xD) {
            pthis->sfxTimer1 = 0;
            pthis->unk_2A6 = 1;
            pthis->actionFunc = func_80AB6EB4;
            pthis->actor.velocity.y = 4.0f;
            return;
        }
        pthis->actor.shape.rot.z = 0;
        pthis->actor.shape.rot.y = pthis->actor.shape.rot.z;
        pthis->actor.shape.rot.x = pthis->actor.shape.rot.z;
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actionFunc = func_80AB6D08;
    }
    func_80AB5BF8(pthis, globalCtx, 2);
}

void func_80AB6D08(EnNiw* pthis, GlobalContext* globalCtx) {
    if (pthis->path == 0) {
        if (!(pthis->actor.bgCheckFlags & 1)) {
            return;
        }
        if (pthis->actor.params == 0xE) {
            pthis->unk_2AC.x = pthis->unk_2B8.x = pthis->actor.world.pos.x;
            pthis->unk_2AC.y = pthis->unk_2B8.y = pthis->actor.world.pos.y;
            pthis->unk_2AC.z = pthis->unk_2B8.z = pthis->actor.world.pos.z;
            pthis->timer5 = pthis->timer4 = pthis->unk_29E = 0;

            pthis->unk_26C[7] = pthis->unk_26C[5] = pthis->unk_26C[6] = pthis->unk_26C[8] = pthis->actor.speedXZ =
                pthis->unk_2FC = pthis->unk_300 = 0.0f;

            pthis->actionFunc = EnNiw_ResetAction;
            return;
        }

        pthis->path = 1;
        pthis->timer5 = 80;
        pthis->actor.speedXZ = 0.0f;
        pthis->actor.velocity.y = 4.0f;
    } else {
        if (pthis->actor.bgCheckFlags & 1) {
            pthis->sfxTimer1 = 0;
            pthis->actor.velocity.y = 4.0f;
            pthis->unk_2A6 = 1;
        }
        if (pthis->timer5 == 0) {
            pthis->timer6 = 100;
            pthis->timer4 = 0;
            pthis->path = 0;
            pthis->actionFunc = func_80AB7290;
            return;
        }
    }

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_M);
        pthis->sfxTimer1 = 30;
        pthis->path = 0;
        pthis->timer4 = 30;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->actor.speedXZ = 0.0f;
        pthis->actionFunc = func_80AB6BF8;
    } else {
        if (pthis->timer5 >= 6) {
            func_8002F580(&pthis->actor, globalCtx);
        }
        func_80AB5BF8(pthis, globalCtx, 2);
    }
}

void func_80AB6EB4(EnNiw* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.world.pos.y > 400.0f) {
        Actor_Kill(&pthis->actor);
    }

    func_80AB5BF8(pthis, globalCtx, 2);
}

void func_80AB6F04(EnNiw* pthis, GlobalContext* globalCtx) {
    Vec3f pos;

    if (pthis->unk_2A8 != 0) {
        EnNiw_SpawnAttackCucco(pthis, globalCtx);
    }

    pthis->actor.speedXZ = 2.0f;

    if (pthis->actor.bgCheckFlags & 0x20) {
        pthis->actor.gravity = 0.0f;

        if (pthis->actor.yDistToWater > 15.0f) {
            pthis->actor.world.pos.y += 2.0f;
        }
        if (pthis->timer4 == 0) {
            pthis->timer4 = 30;
            Math_Vec3f_Copy(&pos, &pthis->actor.world.pos);
            pos.y += pthis->actor.yDistToWater;
            EffectSsGRipple_Spawn(globalCtx, &pos, 100, 500, 30);
        }
        if (pthis->actor.bgCheckFlags & 8) {
            pthis->actor.velocity.y = 10.0f;
            pthis->actor.speedXZ = 1.0f;
        }
    } else {
        pthis->actor.gravity = -2.0f;

        if (pthis->actor.bgCheckFlags & 8) {
            pthis->actor.velocity.y = 10.0f;
            pthis->actor.speedXZ = 1.0f;
            pthis->actor.gravity = 0.0f;
        } else {
            pthis->actor.speedXZ = 4.0f;
        }
        if (pthis->actor.bgCheckFlags & 1) {
            pthis->actor.gravity = -2.0f;
            pthis->timer6 = 100;
            pthis->timer4 = 0;
            pthis->actor.velocity.y = 0.0f;
            if (pthis->unk_2A8 == 0) {
                pthis->actionFunc = func_80AB7290;
            } else {
                pthis->actionFunc = func_80AB7204;
            }
        }
    }

    func_80AB5BF8(pthis, globalCtx, 2);
}

void func_80AB70A0(EnNiw* pthis, GlobalContext* globalCtx) {
    OnePointCutscene_Init(globalCtx, 2290, -99, &pthis->actor, MAIN_CAM);
    pthis->timer5 = 100;
    pthis->unk_2A2 = 1;
    pthis->actionFunc = func_80AB70F8;
}

void func_80AB70F8(EnNiw* pthis, GlobalContext* globalCtx) {
    pthis->sfxTimer1 = 100;

    if (pthis->timer5 == 0) {
        pthis->timer5 = 60;
        pthis->timer1 = 10;
        pthis->unk_2A2 = 4;
        pthis->actionFunc = func_80AB714C;
    }

    func_80AB5BF8(pthis, globalCtx, pthis->unk_2A2);
}

void func_80AB714C(EnNiw* pthis, GlobalContext* globalCtx) {
    pthis->sfxTimer1 = 100;

    if (pthis->timer5 == 40) {
        pthis->unk_26C[0] = 10000.0f;
        pthis->unk_26C[7] = 14000.0f;
        pthis->unk_26C[5] = 14000.0f;
        pthis->unk_26C[6] = 0.0f;
        pthis->unk_26C[8] = 0.0f;
        pthis->unk_26C[1] = 0.0f;
        pthis->unk_26C[2] = 0.0f;
        pthis->timer1 = 10;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_M);
    }
    if (pthis->timer5 == 0) {
        pthis->timer7 = 10;
        pthis->unk_2E4 = pthis->actor.yawTowardsPlayer;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->actionFunc = func_80AB7204;
    }

    func_80AB5BF8(pthis, globalCtx, pthis->unk_2A2);
}

void func_80AB7204(EnNiw* pthis, GlobalContext* globalCtx) {
    EnNiw_SpawnAttackCucco(pthis, globalCtx);

    if (pthis->timer7 < 2) {
        if (pthis->timer7 == 1) {
            pthis->actor.speedXZ = 3.0f;
            pthis->unk_2A0 = Rand_ZeroFloat(1.99f);
            pthis->timer1 = pthis->timer2 = pthis->timer3 = pthis->timer4 = 0;
        } else {
            func_80AB6100(pthis, globalCtx, 1);
        }
    }
}

void func_80AB7290(EnNiw* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gCuccoAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gCuccoAnim), ANIMMODE_LOOP,
                     -10.0f);
    pthis->unk_2A0 = Rand_ZeroFloat(1.99f);
    pthis->actor.speedXZ = 4.0f;
    pthis->actionFunc = func_80AB7328;
}

void func_80AB7328(EnNiw* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->timer6 == 0) {
        pthis->unk_2AC.x = pthis->unk_2B8.x = pthis->actor.world.pos.x;
        pthis->unk_2AC.y = pthis->unk_2B8.y = pthis->actor.world.pos.y;
        pthis->unk_2AC.z = pthis->unk_2B8.z = pthis->actor.world.pos.z;
        pthis->timer5 = pthis->timer4 = pthis->unk_29E = 0;
        pthis->unk_26C[7] = pthis->unk_26C[5] = pthis->unk_26C[6] = pthis->unk_26C[8] = pthis->actor.speedXZ =
            pthis->unk_2FC = pthis->unk_300 = 0.0f;
        if (pthis->actor.params == 4) {
            pthis->actor.params = 0;
        }
        pthis->actionFunc = EnNiw_ResetAction;
    } else {
        pthis->unk_2E4 = Math_FAtan2F(pthis->actor.world.pos.x - player->actor.world.pos.x,
                                     pthis->actor.world.pos.z - player->actor.world.pos.z) *
                        (0x8000 / M_PI);
        func_80AB6100(pthis, globalCtx, 0);
        func_80AB5BF8(pthis, globalCtx, 2);
    }
}

void func_80AB7420(EnNiw* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->unk_2A4 = (s16)Rand_ZeroFloat(3.99f) + 5;
        pthis->actionFunc = EnNiw_ResetAction;
    }
}

void func_80AB747C(EnNiw* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_2A8 == 0 && pthis->actor.params != 0xA && pthis->actionFunc != func_80AB6450 &&
        pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        pthis->sfxTimer1 = 30;
        if (pthis->unk_2A4 > 0 && D_80AB85E0 == 0) {
            pthis->unk_2A4--;
        }
        pthis->unk_2A6 = 1;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_M);
        pthis->timer6 = 100;
        pthis->path = 0;
        pthis->actionFunc = func_80AB7290;
    }
}

void EnNiw_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad1;
    EnNiw* pthis = (EnNiw*)thisx;
    Player* player = GET_PLAYER(globalCtx);
    s16 i;
    s16 featherCount;
    Vec3f zeroVec1 = { 0.0f, 0.0f, 0.0f };
    Vec3f zeroVec2 = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;
    Vec3f vel;
    Vec3f accel;
    s32 pad2;
    f32 scale;
    Vec3f cam;
    f32 dist;
    f32 camResult;
    s32 pad3[10];

    if (1) {} // Required to match
    if (1) {}
    if (1) {}

    pthis->unk_294++;

    if (pthis->actionFunc != func_80AB6570) {
        pthis->unk_26C[9] = 0.0f;
    }
    if (pthis->unk_2A6) {
        featherCount = 20;

        if (pthis->unk_2A6 == 2) {
            featherCount = 4;
        }

        for (i = 0; i < featherCount; i++) {
            pos.x = Rand_CenteredFloat(10.0f) + thisx->world.pos.x;
            pos.y = Rand_CenteredFloat(10.0f) + (thisx->world.pos.y + pthis->unk_304);
            pos.z = Rand_CenteredFloat(10.0f) + thisx->world.pos.z;
            scale = Rand_ZeroFloat(6.0f) + 6.0f;

            if (pthis->unk_2A6 == 2 && pthis->unk_304 != 0) {
                pos.y += 10;
            }
            if (pthis->unk_304 == 0) {
                scale = Rand_ZeroFloat(2.0f) + 2;
            }

            vel.x = Rand_CenteredFloat(3.0f);
            vel.y = (Rand_ZeroFloat(2.0f) * 0.5f) + 2.0f;
            vel.z = Rand_CenteredFloat(3.0f);
            accel.x = 0.0f;
            accel.y = -0.15f;
            accel.z = 0.0f;
            EnNiw_FeatherSpawn(pthis, &pos, &vel, &accel, scale);
        }

        pthis->unk_2A6 = 0;
    }

    EnNiw_FeatherUpdate(pthis, globalCtx);
    if (pthis->timer1 != 0) {
        pthis->timer1--;
    }
    if (pthis->timer2 != 0) {
        pthis->timer2--;
    }
    if (pthis->timer3 != 0) {
        pthis->timer3--;
    }
    if (pthis->timer4 != 0) {
        pthis->timer4--;
    }
    if (pthis->timer5 != 0) {
        pthis->timer5--;
    }
    if (pthis->timer7 != 0) {
        pthis->timer7--;
    }
    if (pthis->timer6 != 0) {
        pthis->timer6--;
    }
    if (pthis->sfxTimer1 != 0) {
        pthis->sfxTimer1--;
    }
    if (pthis->sfxTimer2 != 0) {
        pthis->sfxTimer2--;
    }
    if (pthis->sfxTimer3 != 0) {
        pthis->sfxTimer3--;
    }
    if (pthis->timer8 != 0) {
        pthis->timer8--;
    }
    if (pthis->timer9 != 0) {
        pthis->timer9--;
    }
    thisx->shape.rot = thisx->world.rot;
    thisx->shape.shadowScale = 15.0f;
    pthis->actionFunc(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, pthis->unk_304);
    Actor_MoveForward(&pthis->actor);

    if (pthis->actionFunc != func_80AB6EB4 && pthis->actionFunc != func_80AB6450 && globalCtx->sceneNum != SCENE_SPOT03) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 60.0f, 31);
    }
    if (globalCtx->sceneNum == SCENE_SPOT03) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 60.0f, 29);
    }
    if (thisx->floorHeight <= BGCHECK_Y_MIN || thisx->floorHeight >= 32000.0f) {
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 上下？ ☆☆☆☆☆ %f\n" VT_RST, thisx->floorHeight);
        cam.x = globalCtx->view.lookAt.x - globalCtx->view.eye.x;
        cam.y = globalCtx->view.lookAt.y - globalCtx->view.eye.y;
        cam.z = globalCtx->view.lookAt.z - globalCtx->view.eye.z;
        camResult = cam.y / sqrtf(SQ(cam.x) + SQ(cam.y) + SQ(cam.z));
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ 範囲外Ｘ！ ☆☆☆☆☆ %f\n" VT_RST, thisx->world.pos.x);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ 範囲外Ｙ！ ☆☆☆☆☆ %f\n" VT_RST, thisx->world.pos.y);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ 範囲外Ｚ！ ☆☆☆☆☆ %f\n" VT_RST, thisx->world.pos.z);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ セットＸ！ ☆☆☆☆☆ %f\n" VT_RST, thisx->home.pos.x);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ セットＹ！ ☆☆☆☆☆ %f\n" VT_RST, thisx->home.pos.y);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ セットＺ！ ☆☆☆☆☆ %f\n" VT_RST, thisx->home.pos.z);
        thisx->world.pos.x = thisx->home.pos.x;
        thisx->world.pos.z = thisx->home.pos.z;
        thisx->world.pos.y = ((thisx->home.pos.y + globalCtx->view.eye.y) + (camResult * 160.0f));

        if (thisx->world.pos.y < thisx->home.pos.y) {
            thisx->world.pos.y = thisx->home.pos.y + 300.0f;
        }

        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 修整後Ｘ！ ☆☆☆☆☆ %f\n" VT_RST, thisx->world.pos.x);
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 修整後Ｙ！ ☆☆☆☆☆ %f\n" VT_RST, thisx->world.pos.y);
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 修整後Ｚ！ ☆☆☆☆☆ %f\n" VT_RST, thisx->world.pos.z);
        osSyncPrintf("\n\n");
        thisx->speedXZ = 0.0f;
        thisx->gravity = -2.0f;
        Math_Vec3f_Copy(&pthis->unk_2AC, &thisx->home.pos);
        Math_Vec3f_Copy(&pthis->unk_2B8, &thisx->home.pos);
        pthis->unk_300 = 0.0f;
        pthis->unk_2FC = 0.0f;
        pthis->unk_2F0.z = 0.0f;
        pthis->unk_2F0.y = 0.0f;
        pthis->unk_2F0.x = 0.0f;
        pthis->unk_2D8 = 0.0f;
        pthis->unk_2D4 = 0.0f;
        pthis->unk_2D0 = 0.0f;
        pthis->unk_2CC = 0.0f;
        pthis->unk_2C8 = 0.0f;
        pthis->unk_2C4 = 0.0f;
        pthis->unk_2DC = 0.0f;
        pthis->unk_2E0 = 0.0f;
        pthis->unk_2A8 = pthis->unk_294 = pthis->unk_298 = pthis->unk_2A6 = pthis->unk_29E = pthis->unk_2A0 = pthis->unk_2A2 =
            0;

        for (i = 0; i < ARRAY_COUNT(pthis->unk_26C); i++) {
            pthis->unk_26C[i] = 0;
        }

        pthis->unk_2A8 = 0;
        pthis->actionFunc = func_80AB7420;
        return;
    }

    if (thisx->bgCheckFlags & 0x20 && thisx->yDistToWater > 15.0f && pthis->actionFunc != func_80AB6F04 &&
        thisx->params != 0xD && thisx->params != 0xE && thisx->params != 0xA) {
        thisx->velocity.y = 0.0f;
        thisx->gravity = 0.0f;
        Math_Vec3f_Copy(&pos, &thisx->world.pos);
        pos.y += thisx->yDistToWater;
        pthis->timer4 = 30;
        EffectSsGSplash_Spawn(globalCtx, &pos, 0, 0, 0, 400);
        pthis->timer5 = 0;
        osSyncPrintf("\n\n");
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ ぶくぶく ☆☆☆☆☆ \n" VT_RST);
        osSyncPrintf("\n\n");
        pthis->actionFunc = func_80AB6F04;
        return;
    }

    if (D_80AB85E0 == 0 && pthis->unk_2A4 <= 0 && thisx->params != 0xD && thisx->params != 0xE && thisx->params != 0xA) {
        pthis->timer6 = 100;

        if (thisx->xzDistToPlayer > 10.0f) {
            D_80AB85E0 = 1;
            pthis->timer5 = pthis->timer4 = pthis->unk_29E = 0;
            thisx->speedXZ = 0.0f;
            pthis->unk_2FC = 0.0f;
            pthis->unk_300 = 0.0f;
            pthis->unk_26C[7] = 0.0f;
            pthis->unk_26C[5] = 0.0f;
            pthis->unk_26C[6] = 0.0f;
            pthis->unk_26C[8] = 0.0f;
            pthis->sfxTimer1 = 10000;
            pthis->unk_2A8 = 1;
            pthis->unk_2AC.x = pthis->unk_2B8.x = thisx->world.pos.x;
            pthis->unk_2AC.y = pthis->unk_2B8.y = thisx->world.pos.y;
            pthis->unk_2AC.z = pthis->unk_2B8.z = thisx->world.pos.z;
            pthis->actionFunc = func_80AB70A0;
            return;
        }
    }

    dist = 20.0f;

    if (pthis->unk_2A8 != 0 && thisx->xyzDistToPlayerSq < SQ(dist) && player->invincibilityTimer == 0) {
        func_8002F6D4(globalCtx, &pthis->actor, 2.0f, thisx->world.rot.y, 0.0f, 0x10);
    }

    func_80AB747C(pthis, globalCtx);

    if (pthis->sfxTimer2 == 0 && pthis->actionFunc == func_80AB6BF8) {
        pthis->sfxTimer2 = 7;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_WAKEUP);
    }
    if (pthis->sfxTimer1 == 0) {
        if (pthis->actionFunc != func_80AB6570) {
            pthis->sfxTimer1 = 30;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_A);
        } else {
            pthis->sfxTimer1 = 300;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_N);
        }
    }
    if (pthis->unk_2A8 == 0) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

        if (thisx->params != 0xA && thisx->params != 0xD && thisx->params != 0xE && thisx->params != 4) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        if (pthis->actionFunc != func_80AB6BF8 && pthis->actionFunc != func_80AB6D08 &&
            pthis->actionFunc != func_80AB6324 && pthis->actionFunc != func_80AB63A8 &&
            pthis->actionFunc != func_80AB6450) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
}

s32 EnNiw_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnNiw* pthis = (EnNiw*)thisx;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    if (limbIndex == 13) {
        rot->y += (s16)pthis->unk_2DC;
    }
    if (limbIndex == 15) {
        rot->y += (s16)pthis->unk_2E0;
    }
    if (limbIndex == 11) {
        rot->x += (s16)pthis->unk_2D8;
        rot->y += (s16)pthis->unk_2D4;
        rot->z += (s16)pthis->unk_2D0;
    }
    if (limbIndex == 7) {
        rot->x += (s16)pthis->unk_2CC;
        rot->y += (s16)pthis->unk_2C8;
        rot->z += (s16)pthis->unk_2C4;
    }

    return false;
}

void EnNiw_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnNiw* pthis = (EnNiw*)thisx;
    Vec3f scale = { 0.15f, 0.15f, 0.15f };
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnNiw_OverrideLimbDraw, NULL, pthis);

    if (pthis->actionFunc == func_80AB6450) {
        func_80033C30(&pthis->actor.world.pos, &scale, 255, globalCtx);
    }

    EnNiw_FeatherDraw(pthis, globalCtx);
}

void EnNiw_FeatherSpawn(EnNiw* pthis, Vec3f* pos, Vec3f* vel, Vec3f* accel, f32 scale) {
    s16 i;
    EnNiwFeather* feather = pthis->feathers;

    for (i = 0; i < ARRAY_COUNT(pthis->feathers); i++, feather++) {
        if (feather->type == 0) {
            feather->type = 1;
            feather->pos = *pos;
            feather->vel = *vel;
            feather->accel = *accel;
            feather->timer = 0;
            feather->scale = scale / 1000.0f;
            feather->life = (s16)Rand_ZeroFloat(20.0f) + 40;
            feather->unk_2A = Rand_ZeroFloat(1000.0f);
            break;
        }
    }
}

void EnNiw_FeatherUpdate(EnNiw* pthis, GlobalContext* globalCtx) {
    s16 i;
    EnNiwFeather* feather = pthis->feathers;

    for (i = 0; i < ARRAY_COUNT(pthis->feathers); i++, feather++) {
        if (feather->type != 0) {
            feather->timer++;
            feather->pos.x += feather->vel.x;
            feather->pos.y += feather->vel.y;
            feather->pos.z += feather->vel.z;
            feather->vel.x += feather->accel.x;
            feather->vel.y += feather->accel.y;
            feather->vel.z += feather->accel.z;
            if (feather->type == 1) {
                feather->unk_2A++;
                Math_ApproachF(&feather->vel.x, 0.0f, 1.0f, 0.05f);
                Math_ApproachF(&feather->vel.z, 0.0f, 1.0f, 0.05f);
                if (feather->vel.y < -0.5f) {
                    feather->vel.y = -0.5f;
                }

                feather->unk_30 = Math_SinS(feather->unk_2A * 0xBB8) * M_PI * 0.2f;

                if (feather->life < feather->timer) {
                    feather->type = 0;
                }
            }
        }
    }
}

void EnNiw_FeatherDraw(EnNiw* pthis, GlobalContext* globalCtx) {
    u8 flag = 0;
    s16 i;
    s32 pad;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    EnNiwFeather* feather = &pthis->feathers[0];

    OPEN_DISPS(gfxCtx, "../z_en_niw.c", 1897);

    func_80093D84(globalCtx->state.gfxCtx);

    for (i = 0; i < ARRAY_COUNT(pthis->feathers); i++, feather++) {
        if (feather->type == 1) {
            if (!flag) {
                gSPDisplayList(POLY_XLU_DISP++, gCuccoParticleAppearDL);
                flag++;
            }
            Matrix_Translate(feather->pos.x, feather->pos.y, feather->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(feather->scale, feather->scale, 1.0f, MTXMODE_APPLY);
            Matrix_RotateZ(feather->unk_30, MTXMODE_APPLY);
            Matrix_Translate(0.0f, -1000.0f, 0.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_niw.c", 1913),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gCuccoParticleAliveDL);
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_en_niw.c", 1919);
}
