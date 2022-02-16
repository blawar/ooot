#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_BDAN_SWITCH_Z_BG_BDAN_SWITCH_C
#include "actor_common.h"
/*
 * File: z_bg_bdan_switch.c
 * Overlay: ovl_Bg_Bdan_Switch
 * Description: Switches Inside Lord Jabu-Jabu
 */

#include "z_bg_bdan_switch.h"
#include "objects/object_bdan_objects/object_bdan_objects.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_player_lib.h"

#define FLAGS ACTOR_FLAG_4

void BgBdanSwitch_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgBdanSwitch_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgBdanSwitch_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgBdanSwitch_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgBdanSwitch_Draw(Actor* pthisx, GlobalContext* globalCtx);

void func_8086D5C4(BgBdanSwitch* pthis);
void func_8086D5E0(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086D67C(BgBdanSwitch* pthis);
void func_8086D694(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086D730(BgBdanSwitch* pthis);
void func_8086D754(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086D7FC(BgBdanSwitch* pthis);
void func_8086D80C(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086D86C(BgBdanSwitch* pthis);
void func_8086D888(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086D8BC(BgBdanSwitch* pthis);
void func_8086D8CC(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086D95C(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086D9F8(BgBdanSwitch* pthis);
void func_8086DA1C(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086DAB4(BgBdanSwitch* pthis);
void func_8086DAC4(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086DB24(BgBdanSwitch* pthis);
void func_8086DB40(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086DB4C(BgBdanSwitch* pthis);
void func_8086DB68(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086DC30(BgBdanSwitch* pthis);
void func_8086DC48(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086DCCC(BgBdanSwitch* pthis);
void func_8086DCE8(BgBdanSwitch* pthis, GlobalContext* globalCtx);
void func_8086DDA8(BgBdanSwitch* pthis);
void func_8086DDC0(BgBdanSwitch* pthis, GlobalContext* globalCtx);

ActorInit Bg_Bdan_Switch_InitVars = {
    ACTOR_BG_BDAN_SWITCH,
    ACTORCAT_SWITCH,
    FLAGS,
    OBJECT_BDAN_OBJECTS,
    sizeof(BgBdanSwitch),
    (ActorFunc)BgBdanSwitch_Init,
    (ActorFunc)BgBdanSwitch_Destroy,
    (ActorFunc)BgBdanSwitch_Update,
    (ActorFunc)BgBdanSwitch_Draw,
    (ActorFunc)BgBdanSwitch_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xEFC1FFFE, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, 120, 0 }, 370 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 1400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1200, ICHAIN_STOP),
};

static Vec3f D_8086E0E0 = { 0.0f, 140.0f, 0.0f };

void BgBdanSwitch_InitDynaPoly(BgBdanSwitch* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 flag) {
    s16 pad1;
    CollisionHeader* colHeader = NULL;
    s16 pad2;

    DynaPolyActor_Init(&pthis->dyna, flag);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_bdan_switch.c", 325,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void BgBdanSwitch_InitCollision(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    Actor* actor = &pthis->dyna.actor;
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, actor, &sJntSphInit, pthis->colliderItems);
}

void func_8086D0EC(BgBdanSwitch* pthis) {
    if (pthis->unk_1CC > 0) {
        pthis->unk_1CC += 0x5DC;
    } else {
        pthis->unk_1CC += 0xFA0;
    }

    switch (pthis->dyna.actor.params & 0xFF) {
        case BLUE:
        case YELLOW_HEAVY:
        case YELLOW:
            pthis->unk_1D4 = ((Math_CosS(pthis->unk_1CC) * 0.5f) + (53.000004f / 6.0f)) * 0.012f;
            pthis->unk_1D0 = ((Math_CosS(pthis->unk_1CC) * 0.5f) + 20.5f) * (pthis->unk_1C8 * 0.0050000004f);
            pthis->dyna.actor.scale.y = pthis->unk_1C8 * 0.1f;
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            pthis->unk_1D4 = ((Math_CosS(pthis->unk_1CC) * 0.5f) + (43.0f / 6.0f)) * 0.0075000003f;
            pthis->unk_1D0 = ((Math_CosS(pthis->unk_1CC) * 0.5f) + 20.5f) * (pthis->unk_1C8 * 0.0050000004f);
            pthis->dyna.actor.scale.y = pthis->unk_1C8 * 0.1f;
    }
    pthis->dyna.actor.shape.yOffset = 1.2f / pthis->unk_1D0;
}

void BgBdanSwitch_Init(Actor* pthisx, GlobalContext* globalCtx) {
    BgBdanSwitch* pthis = (BgBdanSwitch*)pthisx;
    s32 pad;
    s16 type;
    s32 flag;

    type = pthis->dyna.actor.params & 0xFF;
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    if (type == YELLOW_TALL_1 || type == YELLOW_TALL_2) {
        pthis->dyna.actor.scale.z = 0.05f;
        pthis->dyna.actor.scale.x = 0.05f;
    } else {
        pthis->dyna.actor.scale.z = 0.1f;
        pthis->dyna.actor.scale.x = 0.1f;
    }
    pthis->dyna.actor.scale.y = 0.0f;
    Actor_SetFocus(&pthis->dyna.actor, 10.0f);

    switch (type) {
        case BLUE:
        case YELLOW_HEAVY:
        case YELLOW:
            BgBdanSwitch_InitDynaPoly(pthis, globalCtx, &gJabuFloorSwitchCol, DPM_PLAYER);
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            BgBdanSwitch_InitCollision(pthis, globalCtx);
            pthis->dyna.actor.flags |= ACTOR_FLAG_0;
            pthis->dyna.actor.targetMode = 4;
            break;
    }

    flag = Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F);

    switch (type) {
        case BLUE:
        case YELLOW:
            if (flag) {
                func_8086D730(pthis);
            } else {
                func_8086D5C4(pthis);
            }
            break;
        case YELLOW_HEAVY:
            if (flag) {
                func_8086DB24(pthis);
            } else {
                func_8086D86C(pthis);
            }
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            if (flag) {
                func_8086DCCC(pthis);
            } else {
                func_8086DB4C(pthis);
            }
            break;
        default:
            osSyncPrintf("不正な ARG_DATA(arg_data 0x%04x)(%s %d)\n", pthis->dyna.actor.params, "../z_bg_bdan_switch.c",
                         454);
            Actor_Kill(&pthis->dyna.actor);
            return;
    }
    osSyncPrintf("(巨大魚ダンジョン 専用スイッチ)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
}

void BgBdanSwitch_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgBdanSwitch* pthis = (BgBdanSwitch*)pthisx;

    switch (pthis->dyna.actor.params & 0xFF) {
        case BLUE:
        case YELLOW_HEAVY:
        case YELLOW:
            DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            Collider_DestroyJntSph(globalCtx, &pthis->collider);
            break;
    }
}

void func_8086D4B4(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 type;

    if (!Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
        type = pthis->dyna.actor.params & 0xFF;
        Flags_SetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F);
        if (type == BLUE || type == YELLOW_TALL_2) {
            OnePointCutscene_AttentionSetSfx(globalCtx, &pthis->dyna.actor, NA_SE_SY_TRE_BOX_APPEAR);
        } else {
            OnePointCutscene_AttentionSetSfx(globalCtx, &pthis->dyna.actor, NA_SE_SY_CORRECT_CHIME);
        }
    }
}

void func_8086D548(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
        Flags_UnsetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F);
        if ((pthis->dyna.actor.params & 0xFF) == YELLOW_TALL_2) {
            OnePointCutscene_AttentionSetSfx(globalCtx, &pthis->dyna.actor, NA_SE_SY_TRE_BOX_APPEAR);
        }
    }
}

void func_8086D5C4(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086D5E0;
    pthis->unk_1C8 = 1.0f;
}

void func_8086D5E0(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    switch (pthis->dyna.actor.params & 0xFF) {
        case BLUE:
            if (func_800435B4(&pthis->dyna)) {
                func_8086D67C(pthis);
                func_8086D4B4(pthis, globalCtx);
            }
            break;
        case YELLOW:
            if (func_8004356C(&pthis->dyna)) {
                func_8086D67C(pthis);
                func_8086D4B4(pthis, globalCtx);
            }
            break;
    }
}

void func_8086D67C(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086D694;
    pthis->unk_1DA = 0x64;
}

void func_8086D694(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    if ((func_8005B198() == pthis->dyna.actor.category) || (pthis->unk_1DA <= 0)) {
        pthis->unk_1C8 -= 0.2f;
        if (pthis->unk_1C8 <= 0.1f) {
            func_8086D730(pthis);
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
            func_800AA000(pthis->dyna.actor.xyzDistToPlayerSq, 0x78, 0x14, 0xA);
        }
    }
}

void func_8086D730(BgBdanSwitch* pthis) {
    pthis->unk_1C8 = 0.1f;
    pthis->actionFunc = func_8086D754;
    pthis->unk_1D8 = 6;
}

void func_8086D754(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    switch (pthis->dyna.actor.params & 0xFF) {
        case BLUE:
            if (!func_800435B4(&pthis->dyna)) {
                if (pthis->unk_1D8 <= 0) {
                    func_8086D7FC(pthis);
                    func_8086D548(pthis, globalCtx);
                }
            } else {
                pthis->unk_1D8 = 6;
            }
            break;
        case YELLOW:
            if (!Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
                func_8086D7FC(pthis);
            }
            break;
    }
}

void func_8086D7FC(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086D80C;
}

void func_8086D80C(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    pthis->unk_1C8 += 0.2f;
    if (pthis->unk_1C8 >= 1.0f) {
        func_8086D5C4(pthis);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
    }
}

void func_8086D86C(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086D888;
    pthis->unk_1C8 = 1.0f;
}

void func_8086D888(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    if (func_8004356C(&pthis->dyna)) {
        func_8086D8BC(pthis);
    }
}

void func_8086D8BC(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086D8CC;
}

void func_8086D8CC(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    pthis->unk_1C8 -= 0.2f;
    if (pthis->unk_1C8 <= 0.6f) {
        func_8086D9F8(pthis);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
        func_800AA000(pthis->dyna.actor.xyzDistToPlayerSq, 0x78, 0x14, 0xA);
    }
}

void func_8086D944(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086D95C;
    pthis->unk_1DA = 0x64;
}

void func_8086D95C(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    if ((func_8005B198() == pthis->dyna.actor.category) || (pthis->unk_1DA <= 0)) {
        pthis->unk_1C8 -= 0.2f;
        if (pthis->unk_1C8 <= 0.1f) {
            func_8086DB24(pthis);
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
            func_800AA000(pthis->dyna.actor.xyzDistToPlayerSq, 0x78, 0x14, 0xA);
        }
    }
}

void func_8086D9F8(BgBdanSwitch* pthis) {
    pthis->unk_1C8 = 0.6f;
    pthis->actionFunc = func_8086DA1C;
    pthis->unk_1D8 = 6;
}

void func_8086DA1C(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    Actor* heldActor = GET_PLAYER(globalCtx)->heldActor;

    if (func_8004356C(&pthis->dyna)) {
        if (heldActor != NULL && heldActor->id == ACTOR_EN_RU1) {
            if (pthis->unk_1D8 <= 0) {
                func_8086D944(pthis);
                func_8086D4B4(pthis, globalCtx);
            }
        } else {
            pthis->unk_1D8 = 6;
        }
    } else {
        if (pthis->unk_1D8 <= 0) {
            func_8086DAB4(pthis);
        }
    }
}

void func_8086DAB4(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086DAC4;
}

void func_8086DAC4(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    pthis->unk_1C8 += 0.2f;
    if (pthis->unk_1C8 >= 1.0f) {
        func_8086D86C(pthis);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
    }
}

void func_8086DB24(BgBdanSwitch* pthis) {
    pthis->unk_1C8 = 0.1f;
    pthis->actionFunc = func_8086DB40;
}

void func_8086DB40(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
}

void func_8086DB4C(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086DB68;
    pthis->unk_1C8 = 2.0f;
}

void func_8086DB68(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    switch (pthis->dyna.actor.params & 0xFF) {
        default:
            return;
        case YELLOW_TALL_1:
            if (((pthis->collider.base.acFlags & AC_HIT) != 0) && pthis->unk_1D8 <= 0) {
                pthis->unk_1D8 = 0xA;
                func_8086DC30(pthis);
                func_8086D4B4(pthis, globalCtx);
            }
            break;
        case YELLOW_TALL_2:
            if (((pthis->collider.base.acFlags & AC_HIT) != 0) && ((pthis->unk_1DC & 2) == 0) && pthis->unk_1D8 <= 0) {
                pthis->unk_1D8 = 0xA;
                func_8086DC30(pthis);
                func_8086D4B4(pthis, globalCtx);
            }
            break;
    }
}

void func_8086DC30(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086DC48;
    pthis->unk_1DA = 0x64;
}

void func_8086DC48(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    if ((func_8005B198() == pthis->dyna.actor.category) || (pthis->unk_1DA <= 0)) {
        pthis->unk_1C8 -= 0.3f;
        if (pthis->unk_1C8 <= 1.0f) {
            func_8086DCCC(pthis);
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
        }
    }
}

void func_8086DCCC(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086DCE8;
    pthis->unk_1C8 = 1.0f;
}

void func_8086DCE8(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    switch (pthis->dyna.actor.params & 0xFF) {
        case YELLOW_TALL_1:
            if (!Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
                func_8086DDA8(pthis);
            }
            break;
        case YELLOW_TALL_2:
            if (((pthis->collider.base.acFlags & AC_HIT) != 0) && ((pthis->unk_1DC & 2) == 0) && (pthis->unk_1D8 <= 0)) {
                pthis->unk_1D8 = 0xA;
                func_8086DDA8(pthis);
                func_8086D548(pthis, globalCtx);
            }
            break;
    }
}

void func_8086DDA8(BgBdanSwitch* pthis) {
    pthis->actionFunc = func_8086DDC0;
    pthis->unk_1DA = 0x64;
}

void func_8086DDC0(BgBdanSwitch* pthis, GlobalContext* globalCtx) {
    if ((((pthis->dyna.actor.params & 0xFF) != YELLOW_TALL_2) || (func_8005B198() == pthis->dyna.actor.category)) ||
        (pthis->unk_1DA <= 0)) {
        pthis->unk_1C8 += 0.3f;
        if (pthis->unk_1C8 >= 2.0f) {
            func_8086DB4C(pthis);
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_FOOT_SWITCH);
        }
    }
}

void BgBdanSwitch_Update(Actor* pthisx, GlobalContext* globalCtx) {
    s32 pad;
    BgBdanSwitch* pthis = (BgBdanSwitch*)pthisx;
    s32 type;

    if (pthis->unk_1DA > 0) {
        pthis->unk_1DA--;
    }
    pthis->actionFunc(pthis, globalCtx);
    func_8086D0EC(pthis);
    type = pthis->dyna.actor.params & 0xFF;
    if (type != 3 && type != 4) {
        pthis->unk_1D8--;
    } else {
        if (!Player_InCsMode(globalCtx) && pthis->unk_1D8 > 0) {
            pthis->unk_1D8--;
        }
        pthis->unk_1DC = pthis->collider.base.acFlags;
        pthis->collider.base.acFlags &= ~AC_HIT;
        pthis->collider.elements[0].dim.modelSphere.radius = pthis->unk_1D4 * 370.0f;
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void func_8086DF58(BgBdanSwitch* pthis, GlobalContext* globalCtx, Gfx* dlist) {
    func_800D1694(pthis->dyna.actor.world.pos.x,
                  pthis->dyna.actor.world.pos.y + (pthis->dyna.actor.shape.yOffset * pthis->unk_1D0),
                  pthis->dyna.actor.world.pos.z, &pthis->dyna.actor.shape.rot);
    Matrix_Scale(pthis->unk_1D4, pthis->unk_1D0, pthis->unk_1D4, MTXMODE_APPLY);
    Gfx_DrawDListOpa(globalCtx, dlist);
}

void BgBdanSwitch_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    BgBdanSwitch* pthis = (BgBdanSwitch*)pthisx;

    switch (pthis->dyna.actor.params & 0xFF) {
        case YELLOW_HEAVY:
        case YELLOW:
            func_8086DF58(pthis, globalCtx, gJabuYellowFloorSwitchDL);
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            func_8086DF58(pthis, globalCtx, gJabuYellowFloorSwitchDL);
            Collider_UpdateSpheres(0, &pthis->collider);
            Matrix_MultVec3f(&D_8086E0E0, &pthis->dyna.actor.focus.pos);
            break;
        case BLUE:
            func_8086DF58(pthis, globalCtx, gJabuBlueFloorSwitchDL);
            break;
    }
}

void BgBdanSwitch_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Bdan_Switch_InitVars = {
        ACTOR_BG_BDAN_SWITCH,
        ACTORCAT_SWITCH,
        FLAGS,
        OBJECT_BDAN_OBJECTS,
        sizeof(BgBdanSwitch),
        (ActorFunc)BgBdanSwitch_Init,
        (ActorFunc)BgBdanSwitch_Destroy,
        (ActorFunc)BgBdanSwitch_Update,
        (ActorFunc)BgBdanSwitch_Draw,
        (ActorFunc)BgBdanSwitch_Reset,
    };

    sJntSphInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphElementsInit,
    };

    D_8086E0E0 = { 0.0f, 140.0f, 0.0f };

}
