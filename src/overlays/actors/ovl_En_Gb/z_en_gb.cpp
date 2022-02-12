#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GB_Z_EN_GB_C
#include "actor_common.h"
/*
 * File: z_en_gb.c
 * Overlay: ovl_En_Gb
 * Description: Poe Seller
 */

#include "z_en_gb.h"
#include "objects/object_ps/object_ps.h"
#include "def/code_80043480.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnGb_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGb_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGb_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGb_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A2F83C(EnGb* pthis, GlobalContext* globalCtx);
void func_80A2FC70(EnGb* pthis, GlobalContext* globalCtx);
void func_80A2FA50(EnGb* pthis, GlobalContext* globalCtx);
void func_80A2F9C0(EnGb* pthis, GlobalContext* globalCtx);
void func_80A2F94C(EnGb* pthis, GlobalContext* globalCtx);
void func_80A2FB40(EnGb* pthis, GlobalContext* globalCtx);
void func_80A2FBB0(EnGb* pthis, GlobalContext* globalCtx);
void func_80A2FC0C(EnGb* pthis, GlobalContext* globalCtx);

void EnGb_DrawCagedSouls(EnGb* pthis, GlobalContext* globalCtx);
void EnGb_UpdateCagedSouls(EnGb* pthis, GlobalContext* globalCtx);

ActorInit En_Gb_InitVars = {
    ACTOR_EN_GB,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_PS,
    sizeof(EnGb),
    (ActorFunc)EnGb_Init,
    (ActorFunc)EnGb_Destroy,
    (ActorFunc)EnGb_Update,
    (ActorFunc)EnGb_Draw,
};

static EnGbCagedSoulInfo sCagedSoulInfo[] = {
    { { 255, 255, 170, 255 }, { 255, 200, 0, 255 }, gPoeSellerAngrySoulTex, -15 },
    { { 255, 255, 170, 255 }, { 0, 150, 0, 255 }, gPoeSellerHappySoulTex, -12 },
    { { 255, 170, 255, 255 }, { 100, 0, 150, 255 }, gPoeSellerSadSoulTex, -8 },
};

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
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
    { 40, 75, 0, { 0, 0, 0 } },
};

static ColliderCylinderInitType1 sBottlesCylindersInit[] = {
    {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
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
        { 4, 20, 0, { 0, 0, 0 } },
    },
    {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
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
        { 4, 20, 0, { 0, 0, 0 } },
    },
    {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
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
        { 10, 20, 0, { 0, 0, 0 } },
    },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 6, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2200, ICHAIN_STOP),
};

// relative positions of poe souls
static Vec3f sCagedSoulPositions[] = {
    { -8.0f, 112.0f, -8.0f },
    { -3.0f, 112.0f, 29.0f },
    { 31.0f, 112.0f, 29.0f },
    { 31.0f, 112.0f, -8.0f },
};

// relative positions of bottles
static Vec3f sBottlesPositions[] = {
    { -48.0f, 0.0f, 34.0f },
    { -55.0f, 0.0f, 49.0f },
    { -48.0f, 0.0f, 60.0f },
};

void func_80A2F180(EnGb* pthis) {
    if (gSaveContext.infTable[0xB] & 0x40) {
        pthis->textId = 0x70F5;
    } else {
        pthis->textId = 0x70F4;
    }
}

void EnGb_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGb* pthis = (EnGb*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 i;
    f32 rand;
    Vec3f focusOffset;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gPoeSellerCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gPoeSellerSkel, &gPoeSellerIdleAnim, pthis->jointTable,
                       pthis->morphTable, 12);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->dyna.actor, &sCylinderInit);

    for (i = 0; i < ARRAY_COUNT(sBottlesCylindersInit); i++) {
        Collider_InitCylinder(globalCtx, &pthis->bottlesColliders[i]);
        Collider_SetCylinderType1(globalCtx, &pthis->bottlesColliders[i], &pthis->dyna.actor, &sBottlesCylindersInit[i]);
    }

    pthis->light = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->dyna.actor.home.pos.x, pthis->dyna.actor.home.pos.y,
                              pthis->dyna.actor.home.pos.z, 255, 255, 255, 200);

    ActorShape_Init(&pthis->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 35.0f);
    Actor_SetScale(&pthis->dyna.actor, 0.01f);
    pthis->dyna.actor.colChkInfo.mass = 0xFF;
    pthis->dyna.actor.speedXZ = 0.0f;
    pthis->dyna.actor.velocity.y = 0.0f;
    pthis->dyna.actor.gravity = -1.0f;
    pthis->actionTimer = (s16)Rand_ZeroFloat(100.0f) + 100;

    for (i = 0; i < ARRAY_COUNT(sCagedSoulPositions); i++) {
        pthis->cagedSouls[i].infoIdx = (s32)Rand_ZeroFloat(30.0f) % 3;
        pthis->cagedSouls[i].unk_14.x = pthis->cagedSouls[i].translation.x =
            sCagedSoulPositions[i].x + pthis->dyna.actor.world.pos.x;
        pthis->cagedSouls[i].unk_14.y = pthis->cagedSouls[i].translation.y =
            sCagedSoulPositions[i].y + pthis->dyna.actor.world.pos.y;
        pthis->cagedSouls[i].unk_14.z = pthis->cagedSouls[i].translation.z =
            sCagedSoulPositions[i].z + pthis->dyna.actor.world.pos.z;
        pthis->cagedSouls[i].unk_1 = 1;
        pthis->cagedSouls[i].unk_3 = pthis->cagedSouls[i].unk_2 = 0;
        pthis->cagedSouls[i].unk_20 = pthis->cagedSouls[i].unk_24 = 0.0f;
        pthis->cagedSouls[i].unk_6 = Rand_ZeroFloat(40.0f);
        pthis->cagedSouls[i].rotate180 = pthis->cagedSouls[i].unk_6 & 1;
        pthis->cagedSouls[i].unk_28 = 0.2f;
    }

    rand = Rand_ZeroOne();
    pthis->lightColor.r = (s8)(rand * 30.0f) + 225;
    pthis->lightColor.g = (s8)(rand * 100.0f) + 155;
    pthis->lightColor.b = (s8)(rand * 160.0f) + 95;
    pthis->lightColor.a = 200;
    Matrix_Translate(pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateZYX(pthis->dyna.actor.world.rot.x, pthis->dyna.actor.world.rot.y, pthis->dyna.actor.world.rot.z,
                     MTXMODE_APPLY);
    focusOffset.x = focusOffset.y = 0.0f;
    focusOffset.z = 44.0f;
    Matrix_MultVec3f(&focusOffset, &pthis->dyna.actor.focus.pos);
    pthis->dyna.actor.focus.pos.y += 62.5f;
    func_80A2F180(pthis);
    pthis->actionFunc = func_80A2F83C;
}

void EnGb_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGb* pthis = (EnGb*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->light);
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80A2F608(EnGb* pthis) {
    s32 i;
    Vec3f sp48;
    Vec3f sp3C;

    Matrix_Translate(pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateZYX(pthis->dyna.actor.world.rot.x, pthis->dyna.actor.world.rot.y, pthis->dyna.actor.world.rot.z,
                     MTXMODE_APPLY);
    sp48.x = sp48.y = 0.0f;
    sp48.z = 25.0f;
    Matrix_MultVec3f(&sp48, &sp3C);
    pthis->collider.dim.pos.x = sp3C.x;
    pthis->collider.dim.pos.y = sp3C.y;
    pthis->collider.dim.pos.z = sp3C.z;

    for (i = 0; i < ARRAY_COUNT(sBottlesPositions); i++) {
        Matrix_Translate(pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z,
                         MTXMODE_NEW);
        Matrix_RotateZYX(pthis->dyna.actor.world.rot.x, pthis->dyna.actor.world.rot.y, pthis->dyna.actor.world.rot.z,
                         MTXMODE_APPLY);
        Matrix_MultVec3f(&sBottlesPositions[i], &sp3C);
        pthis->bottlesColliders[i].dim.pos.x = sp3C.x;
        pthis->bottlesColliders[i].dim.pos.y = sp3C.y;
        pthis->bottlesColliders[i].dim.pos.z = sp3C.z;
    }
}

s32 func_80A2F760(EnGb* pthis) {
    s32 i;
    for (i = 0; i < ARRAY_COUNT(pthis->cagedSouls); i++) {
        if (pthis->cagedSouls[i].unk_3) {
            return 1;
        }
    }
    return 0;
}

void func_80A2F7C0(EnGb* pthis) {
    Animation_Change(&pthis->skelAnime, &gPoeSellerSwingStickAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gPoeSellerSwingStickAnim), ANIMMODE_ONCE, 0.0f);
    Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_NALE_MAGIC);
    pthis->actionFunc = func_80A2FC70;
}

void func_80A2F83C(EnGb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (!func_80A2F760(pthis)) {
        if (pthis->actionTimer != 0) {
            pthis->actionTimer--;
        } else {
            func_80A2F7C0(pthis);
            return;
        }
    }
    if (Actor_ProcessTalkRequest(&pthis->dyna.actor, globalCtx)) {
        switch (func_8002F368(globalCtx)) {
            case EXCH_ITEM_NONE:
                func_80A2F180(pthis);
                pthis->actionFunc = func_80A2F94C;
                break;
            case EXCH_ITEM_POE:
                player->actor.textId = 0x70F6;
                pthis->actionFunc = func_80A2F9C0;
                break;
            case EXCH_ITEM_BIG_POE:
                player->actor.textId = 0x70F7;
                pthis->actionFunc = func_80A2FA50;
                break;
        }
        return;
    }
    if (pthis->dyna.actor.xzDistToPlayer < 100.0f) {
        func_8002F298(&pthis->dyna.actor, globalCtx, 100.0f, EXCH_ITEM_POE);
    }
}

void func_80A2F94C(EnGb* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        if (!(gSaveContext.infTable[0xB] & 0x40)) {
            gSaveContext.infTable[0xB] |= 0x40;
        }
        func_80A2F180(pthis);
        pthis->actionFunc = func_80A2F83C;
    }
}

void func_80A2F9C0(EnGb* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        if (!(gSaveContext.infTable[0xB] & 0x40)) {
            gSaveContext.infTable[0xB] |= 0x40;
        }
        func_80A2F180(pthis);
        Player_UpdateBottleHeld(globalCtx, GET_PLAYER(globalCtx), ITEM_BOTTLE, PLAYER_AP_BOTTLE);
        Rupees_ChangeBy(10);
        pthis->actionFunc = func_80A2F83C;
    }
}

void func_80A2FA50(EnGb* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        if (!(gSaveContext.infTable[0xB] & 0x40)) {
            gSaveContext.infTable[0xB] |= 0x40;
        }
        func_80A2F180(pthis);
        Player_UpdateBottleHeld(globalCtx, GET_PLAYER(globalCtx), ITEM_BOTTLE, PLAYER_AP_BOTTLE);
        Rupees_ChangeBy(50);
        HIGH_SCORE(HS_POE_POINTS) += 100;
        if (HIGH_SCORE(HS_POE_POINTS) != 1000) {
            if (HIGH_SCORE(HS_POE_POINTS) > 1100) {
                HIGH_SCORE(HS_POE_POINTS) = 1100;
            }
            pthis->actionFunc = func_80A2F83C;
        } else {
            Player* player = GET_PLAYER(globalCtx);

            player->exchangeItemId = EXCH_ITEM_NONE;
            pthis->textId = 0x70F8;
            Message_ContinueTextbox(globalCtx, pthis->textId);
            pthis->actionFunc = func_80A2FB40;
        }
    }
}

void func_80A2FB40(EnGb* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        func_8002F434(&pthis->dyna.actor, globalCtx, GI_BOTTLE, 100.0f, 10.0f);
        pthis->actionFunc = func_80A2FBB0;
    }
}

void func_80A2FBB0(EnGb* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->dyna.actor, globalCtx)) {
        pthis->dyna.actor.parent = NULL;
        pthis->actionFunc = func_80A2FC0C;
    } else {
        func_8002F434(&pthis->dyna.actor, globalCtx, GI_BOTTLE, 100.0f, 10.0f);
    }
}

void func_80A2FC0C(EnGb* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        Actor_ProcessTalkRequest(&pthis->dyna.actor, globalCtx);
        func_80A2F180(pthis);
        pthis->actionFunc = func_80A2F83C;
    }
}

void func_80A2FC70(EnGb* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.curFrame == Animation_GetLastFrame(&gPoeSellerSwingStickAnim)) {
        Animation_Change(&pthis->skelAnime, &gPoeSellerIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gPoeSellerIdleAnim),
                         ANIMMODE_LOOP, 0.0f);
        pthis->actionFunc = func_80A2F83C;
    } else if (pthis->skelAnime.curFrame == 18.0f) {
        pthis->cagedSouls[1].unk_1 = 3;
        pthis->cagedSouls[1].unk_3 = 1;
        pthis->cagedSouls[2].unk_1 = 3;
        pthis->cagedSouls[2].unk_3 = 1;
        pthis->cagedSouls[3].unk_1 = 3;
        pthis->cagedSouls[3].unk_3 = 1;
        if (pthis->actionFunc) {} // these ifs cannot just contain a constant
        pthis->cagedSouls[0].unk_1 = 3;
        pthis->cagedSouls[0].unk_3 = 1;
        if (pthis->actionFunc) {}
        pthis->actionTimer = (s16)Rand_ZeroFloat(600.0f) + 600;
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_WOOD_HIT);
    }
}

void EnGb_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnGb* pthis = (EnGb*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    s32 i;
    f32 rand;

    pthis->frameTimer++;
    SkelAnime_Update(&pthis->skelAnime);
    pthis->actionFunc(pthis, globalCtx);
    pthis->dyna.actor.textId = pthis->textId;
    func_80A2F608(pthis);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

    for (i = 0; i < ARRAY_COUNT(pthis->bottlesColliders); i++) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->bottlesColliders[i].base);
    }

    rand = Rand_ZeroOne();
    pthis->lightColor.r = (s8)(rand * 30.0f) + 225;
    pthis->lightColor.g = (s8)(rand * 100.0f) + 155;
    pthis->lightColor.b = (s8)(rand * 160.0f) + 95;
    pthis->lightColor.a = 200;
    EnGb_UpdateCagedSouls(pthis, globalCtx);
}

void EnGb_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnGb* pthis = (EnGb*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_gb.c", 763);

    func_80093D18(globalCtx->state.gfxCtx);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b, 255);

    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y,
                              pthis->dyna.actor.world.pos.z, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b,
                              pthis->lightColor.a);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, &pthis->dyna.actor);
    EnGb_DrawCagedSouls(pthis, globalCtx);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_gb.c", 796);
}

void EnGb_UpdateCagedSouls(EnGb* pthis, GlobalContext* globalCtx) {
    f32 temp_f20;
    s16 rot;
    s32 i;

    for (i = 0; i < 4; i++) {
        switch (pthis->cagedSouls[i].unk_1) {
            case 0:
                Math_ApproachF(&pthis->cagedSouls[i].unk_20, 1.0f, 0.02f, pthis->cagedSouls[i].unk_24);
                Math_ApproachF(&pthis->cagedSouls[i].unk_24, 1.0f, 0.001f, 1.0f);
                if ((pthis->cagedSouls[i].unk_28 - .01f) <= pthis->cagedSouls[i].unk_20) {
                    pthis->cagedSouls[i].unk_20 = pthis->cagedSouls[i].unk_28;
                    pthis->cagedSouls[i].unk_24 = 0.0f;
                    pthis->cagedSouls[i].unk_1 = 1;
                    pthis->cagedSouls[i].unk_2 = 2;
                    pthis->cagedSouls[i].unk_6 = 0;
                }
                break;
            case 1:
                if (pthis->cagedSouls[i].unk_6 != 0) {
                    pthis->cagedSouls[i].unk_6--;
                } else {
                    pthis->cagedSouls[i].unk_3 = 0;
                    pthis->cagedSouls[i].unk_24 = 0.0f;
                    pthis->cagedSouls[i].unk_1 = pthis->cagedSouls[i].unk_2;
                }
                break;
            case 2:
                Math_ApproachF(&pthis->cagedSouls[i].unk_20, 0.0f, 0.02f, pthis->cagedSouls[i].unk_24);
                Math_ApproachF(&pthis->cagedSouls[i].unk_24, 1.0f, 0.001f, 1.0f);
                if (pthis->cagedSouls[i].unk_20 <= 0.01f) {
                    pthis->cagedSouls[i].unk_28 = pthis->cagedSouls[i].unk_28 + 0.2f;
                    if (pthis->cagedSouls[i].unk_28 > 1.0f) {
                        pthis->cagedSouls[i].unk_28 = 1.0f;
                    }
                    pthis->cagedSouls[i].unk_20 = 0.0f;
                    pthis->cagedSouls[i].unk_24 = 0.0f;
                    pthis->cagedSouls[i].unk_1 = 1;
                    pthis->cagedSouls[i].unk_2 = 0;
                    pthis->cagedSouls[i].unk_6 = 0;
                }
                break;
            case 3:
                Math_ApproachF(&pthis->cagedSouls[i].unk_20, 0.0f, 0.5f, 1.0f);
                if (pthis->cagedSouls[i].unk_20 <= 0.01f) {
                    pthis->cagedSouls[i].unk_28 = 0.2f;
                    pthis->cagedSouls[i].unk_20 = 0.0f;
                    pthis->cagedSouls[i].unk_24 = 0.0f;
                    pthis->cagedSouls[i].unk_1 = 1;
                    pthis->cagedSouls[i].unk_2 = 0;
                    pthis->cagedSouls[i].unk_6 = (s16)Rand_ZeroFloat(60.0f) + 60;
                }
                break;
        }

        temp_f20 = pthis->cagedSouls[i].unk_20 * 60.0f;
        if ((i == 0) || (i == 3)) {
            pthis->cagedSouls[i].translation.x = pthis->cagedSouls[i].unk_14.x;
            pthis->cagedSouls[i].translation.y = pthis->cagedSouls[i].unk_14.y + temp_f20;
            pthis->cagedSouls[i].translation.z = pthis->cagedSouls[i].unk_14.z;
        } else if (i == 1) {
            rot = pthis->dyna.actor.world.rot.y - 0x4000;
            pthis->cagedSouls[i].translation.x = pthis->cagedSouls[i].unk_14.x + Math_SinS(rot) * temp_f20;
            pthis->cagedSouls[i].translation.z = pthis->cagedSouls[i].unk_14.z + Math_CosS(rot) * temp_f20;
            pthis->cagedSouls[i].translation.y = pthis->cagedSouls[i].unk_14.y;
        } else {
            rot = pthis->dyna.actor.world.rot.y + 0x4000;
            pthis->cagedSouls[i].translation.x = pthis->cagedSouls[i].unk_14.x + Math_SinS(rot) * temp_f20;
            pthis->cagedSouls[i].translation.z = pthis->cagedSouls[i].unk_14.z + Math_CosS(rot) * temp_f20;
            pthis->cagedSouls[i].translation.y = pthis->cagedSouls[i].unk_14.y;
        }
    }
}

void EnGb_DrawCagedSouls(EnGb* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 i;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_gb.c", 914);

    func_80093D84(globalCtx->state.gfxCtx);

    for (i = 0; i < 4; i++) {
        s32 idx = pthis->cagedSouls[i].infoIdx;

        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0,
                                    (u32)(sCagedSoulInfo[idx].timerMultiplier * pthis->frameTimer) % 512, 32, 128));
        gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sCagedSoulInfo[idx].texture));
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, sCagedSoulInfo[idx].prim.r, sCagedSoulInfo[idx].prim.g,
                        sCagedSoulInfo[idx].prim.b, sCagedSoulInfo[idx].prim.a);
        gDPSetEnvColor(POLY_XLU_DISP++, sCagedSoulInfo[idx].env.r, sCagedSoulInfo[idx].env.g, sCagedSoulInfo[idx].env.b,
                       sCagedSoulInfo[idx].env.a);

        Matrix_Push();
        Matrix_Translate(pthis->cagedSouls[i].translation.x, pthis->cagedSouls[i].translation.y,
                         pthis->cagedSouls[i].translation.z, MTXMODE_NEW);
        func_800D1FD4(&globalCtx->billboardMtxF);

        if (pthis->cagedSouls[i].rotate180) {
            Matrix_RotateZYX(0, -0x8000, 0, MTXMODE_APPLY);
        }
        Matrix_Scale(0.007f, 0.007f, 1.0f, MTXMODE_APPLY);

        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_gb.c", 955),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gPoeSellerCagedSoulDL);

        Matrix_Pop();
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_gb.c", 962);
}
