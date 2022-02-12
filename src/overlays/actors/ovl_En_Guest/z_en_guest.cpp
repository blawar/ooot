#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GUEST_Z_EN_GUEST_C
#include "actor_common.h"
/*
 * File: z_en_guest.c
 * Overlay: ovl_En_Guest
 * Description: Happy Mask Shop Customer
 */

#include "z_en_guest.h"
#include "objects/object_os_anime/object_os_anime.h"
#include "objects/object_boj/object_boj.h"
#include "vt.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnGuest_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGuest_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGuest_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGuest_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A50518(EnGuest* pthis, GlobalContext* globalCtx);
void func_80A5057C(EnGuest* pthis, GlobalContext* globalCtx);
void func_80A505CC(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Guest_InitVars = {
    ACTOR_EN_GUEST,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_BOJ,
    sizeof(EnGuest),
    (ActorFunc)EnGuest_Init,
    (ActorFunc)EnGuest_Destroy,
    (ActorFunc)EnGuest_Update,
    NULL,
};

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        COLSHAPE_CYLINDER,
    },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
    { 10, 60, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 6, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 500, ICHAIN_STOP),
};

void EnGuest_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGuest* pthis = (EnGuest*)thisx;

    if (gSaveContext.infTable[7] & 0x40) {
        Actor_Kill(&pthis->actor);
    } else {
        pthis->osAnimeBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_OS_ANIME);
        if (pthis->osAnimeBankIndex < 0) {
            osSyncPrintf(VT_COL(RED, WHITE));
            // "No such bank!!"
            osSyncPrintf("%s[%d] : バンクが無いよ！！\n", "../z_en_guest.c", 129);
            osSyncPrintf(VT_RST);
            ASSERT(0, "0", "../z_en_guest.c", 132);
        }
    }
}

void EnGuest_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGuest* pthis = (EnGuest*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnGuest_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnGuest* pthis = (EnGuest*)thisx;
    s32 pad;

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->osAnimeBankIndex) != 0) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        Actor_ProcessInitChain(&pthis->actor, sInitChain);

        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_boj_Skel_0000F0, NULL, pthis->jointTable,
                           pthis->morphTable, 16);
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->osAnimeBankIndex].vromStart.get());
        Animation_Change(&pthis->skelAnime, &gObjOsAnim_42AC, 1.0f, 0.0f, Animation_GetLastFrame(&gObjOsAnim_42AC),
                         ANIMMODE_LOOP, 0.0f);

        pthis->actor.draw = EnGuest_Draw;
        pthis->actor.update = func_80A505CC;

        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);

        Actor_SetFocus(&pthis->actor, 60.0f);

        pthis->unk_30E = 0;
        pthis->unk_30D = 0;
        pthis->unk_2CA = 0;
        pthis->actor.textId = 0x700D;
        pthis->actionFunc = func_80A50518;
    }
}

void func_80A5046C(EnGuest* pthis) {
    if (pthis->unk_30D == 0) {
        if (pthis->unk_2CA != 0) {
            pthis->unk_2CA--;
        } else {
            pthis->unk_30D = 1;
        }
    } else {
        if (pthis->unk_2CA != 0) {
            pthis->unk_2CA--;
        } else {
            pthis->unk_30E += 1;
            if (pthis->unk_30E >= 3) {
                pthis->unk_30E = 0;
                pthis->unk_30D = 0;
                pthis->unk_2CA = (s32)Rand_ZeroFloat(60.0f) + 20;
            } else {
                pthis->unk_2CA = 1;
            }
        }
    }
}

void func_80A50518(EnGuest* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_80A5057C;
    } else if (pthis->actor.xzDistToPlayer < 100.0f) {
        func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
    }
}

void func_80A5057C(EnGuest* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        pthis->actionFunc = func_80A50518;
    }
}

void func_80A505CC(Actor* thisx, GlobalContext* globalCtx) {
    EnGuest* pthis = (EnGuest*)thisx;
    s32 pad;
    Player* player;

    player = GET_PLAYER(globalCtx);
    pthis->unk_2C8++;

    func_80A5046C(pthis);
    pthis->actionFunc(pthis, globalCtx);

    pthis->unk_2A0.unk_18 = player->actor.world.pos;
    if (LINK_IS_ADULT) {
        pthis->unk_2A0.unk_14 = 10.0f;
    } else {
        pthis->unk_2A0.unk_14 = 20.0f;
    }
    func_80034A14(&pthis->actor, &pthis->unk_2A0, 6, 2);

    func_80034F54(globalCtx, pthis->unk_2CC, pthis->unk_2EC, 16);

    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->osAnimeBankIndex].vromStart.get());

    SkelAnime_Update(&pthis->skelAnime);
    Actor_SetFocus(&pthis->actor, 60.0f);

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

Gfx* func_80A50708(GraphicsContext* gfxCtx, u8 r, u8 g, u8 b, u8 a) {
    Gfx* dlist;

    dlist = (Gfx*)Graph_Alloc(gfxCtx, 2 * sizeof(Gfx));
    gDPSetEnvColor(dlist, r, g, b, a);
    gSPEndDisplayList(dlist + 1);

    return dlist;
}

s32 EnGuest_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                             void* thisx) {
    EnGuest* pthis = (EnGuest*)thisx;
    Vec3s sp3C;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_guest.c", 352);

    if (limbIndex == 15) {
        *dList = object_boj_DL_0059B0;
        Matrix_Translate(1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        sp3C = pthis->unk_2A0.unk_08;
        Matrix_RotateX((sp3C.y / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateZ((sp3C.x / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_Translate(-1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    }

    if (limbIndex == 8) {
        sp3C = pthis->unk_2A0.unk_0E;
        Matrix_RotateX((-sp3C.y / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateZ((sp3C.x / 32768.0f) * M_PI, MTXMODE_APPLY);
    }

    if (limbIndex == 8 || limbIndex == 9 || limbIndex == 12) {
        rot->y += Math_SinS(pthis->unk_2CC[limbIndex]) * 200.0f;
        rot->z += Math_CosS(pthis->unk_2EC[limbIndex]) * 200.0f;
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_guest.c", 388);

    return false;
}

void EnGuest_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* D_80A50BA4[] = {
        object_boj_Tex_0005FC,
        object_boj_Tex_0006FC,
        object_boj_Tex_0007FC,
    };
    EnGuest* pthis = (EnGuest*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_guest.c", 404);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, func_80A50708(globalCtx->state.gfxCtx, 0xFF, 0xFF, 0xFF, 0xFF));
    gSPSegment(POLY_OPA_DISP++, 0x09, func_80A50708(globalCtx->state.gfxCtx, 0xA0, 0x3C, 0xDC, 0xFF));
    gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(D_80A50BA4[pthis->unk_30E]));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnGuest_OverrideLimbDraw, NULL, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_guest.c", 421);
}
