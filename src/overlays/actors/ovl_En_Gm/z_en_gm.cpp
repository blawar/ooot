#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GM_Z_EN_GM_C
#include "actor_common.h"
/*
 * File: z_en_gm.c
 * Overlay: ovl_En_Gm
 * Description: Medi-Goron
 */

#include "z_en_gm.h"
#include "objects/object_oF1d_map/object_oF1d_map.h"
#include "objects/object_gm/object_gm.h"
#include "vt.h"
#include "def/code_80097A00.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnGm_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGm_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGm_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGm_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A3D838(EnGm* pthis, GlobalContext* globalCtx);
void func_80A3DFBC(EnGm* pthis, GlobalContext* globalCtx);
void func_80A3DB04(EnGm* pthis, GlobalContext* globalCtx);
void func_80A3DC44(EnGm* pthis, GlobalContext* globalCtx);
void func_80A3DBF4(EnGm* pthis, GlobalContext* globalCtx);
void func_80A3DD7C(EnGm* pthis, GlobalContext* globalCtx);
void EnGm_ProcessChoiceIndex(EnGm* pthis, GlobalContext* globalCtx);
void func_80A3DF00(EnGm* pthis, GlobalContext* globalCtx);
void func_80A3DF60(EnGm* pthis, GlobalContext* globalCtx);

ActorInit En_Gm_InitVars = {
    ACTOR_EN_GM,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_OF1D_MAP,
    sizeof(EnGm),
    (ActorFunc)EnGm_Init,
    (ActorFunc)EnGm_Destroy,
    (ActorFunc)EnGm_Update,
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
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 100, 120, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 5, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 30, ICHAIN_STOP),
};

void EnGm_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGm* pthis = (EnGm*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);

    // "Medi Goron"
    osSyncPrintf(VT_FGCOL(GREEN) "%s[%d] : 中ゴロン[%d]" VT_RST "\n", "../z_en_gm.c", 133, pthis->actor.params);

    pthis->objGmBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GM);

    if (pthis->objGmBankIndex < 0) {
        osSyncPrintf(VT_COL(RED, WHITE));
        // "There is no model bank! !! (Medi Goron)"
        osSyncPrintf("モデル バンクが無いよ！！（中ゴロン）\n");
        osSyncPrintf(VT_RST);
        ASSERT(0, "0", "../z_en_gm.c", 145);
    }

    pthis->updateFunc = func_80A3D838;
}

void EnGm_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGm* pthis = (EnGm*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 func_80A3D7C8(void) {
    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        return 0;
    } else if (!(gBitFlags[2] & gSaveContext.inventory.equipment)) {
        return 1;
    } else if (gBitFlags[3] & gSaveContext.inventory.equipment) {
        return 2;
    } else {
        return 3;
    }
}

void func_80A3D838(EnGm* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objGmBankIndex)) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGoronSkel, NULL, pthis->jointTable, pthis->morphTable, 18);
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objGmBankIndex].vromStart.get());
        Animation_Change(&pthis->skelAnime, &object_gm_Anim_0002B8, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_gm_Anim_0002B8), ANIMMODE_LOOP, 0.0f);
        pthis->actor.draw = EnGm_Draw;
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 35.0f);
        Actor_SetScale(&pthis->actor, 0.05f);
        pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
        pthis->eyeTexIndex = 0;
        pthis->blinkTimer = 20;
        pthis->actor.textId = 0x3049;
        pthis->updateFunc = func_80A3DFBC;
        pthis->actionFunc = func_80A3DB04;
        pthis->actor.speedXZ = 0.0f;
        pthis->actor.gravity = -1.0f;
        pthis->actor.velocity.y = 0.0f;
    }
}

void EnGm_UpdateEye(EnGm* pthis) {
    if (pthis->blinkTimer != 0) {
        pthis->blinkTimer--;
    } else {
        pthis->eyeTexIndex++;

        if (pthis->eyeTexIndex >= 3) {
            pthis->eyeTexIndex = 0;
            pthis->blinkTimer = Rand_ZeroFloat(60.0f) + 20.0f;
        }
    }
}

void EnGm_SetTextID(EnGm* pthis) {
    switch (func_80A3D7C8()) {
        case 0:
            if (gSaveContext.infTable[11] & 1) {
                pthis->actor.textId = 0x304B;
            } else {
                pthis->actor.textId = 0x304A;
            }
            break;
        case 1:
            if (gSaveContext.infTable[11] & 2) {
                pthis->actor.textId = 0x304F;
            } else {
                pthis->actor.textId = 0x304C;
            }
            break;
        case 2:
            pthis->actor.textId = 0x304E;
            break;
        case 3:
            pthis->actor.textId = 0x304D;
            break;
    }
}

void func_80A3DB04(EnGm* pthis, GlobalContext* globalCtx) {
    f32 dx;
    f32 dz;
    Player* player = GET_PLAYER(globalCtx);

    dx = pthis->talkPos.x - player->actor.world.pos.x;
    dz = pthis->talkPos.z - player->actor.world.pos.z;

    if (Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        EnGm_SetTextID(pthis);
        pthis->actionFunc = func_80A3DC44;
    } else if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_80A3DBF4;
    } else if ((pthis->collider.base.ocFlags1 & OC1_HIT) || (SQ(dx) + SQ(dz)) < SQ(100.0f)) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        func_8002F2CC(&pthis->actor, globalCtx, 415.0f);
    }
}

void func_80A3DBF4(EnGm* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        pthis->actionFunc = func_80A3DB04;
    }
}

void func_80A3DC44(EnGm* pthis, GlobalContext* globalCtx) {
    f32 dx;
    f32 dz;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);

    EnGm_SetTextID(pthis);

    dx = pthis->talkPos.x - player->actor.world.pos.x;
    dz = pthis->talkPos.z - player->actor.world.pos.z;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        switch (func_80A3D7C8()) {
            case 0:
                gSaveContext.infTable[11] |= 1;
            case 3:
                pthis->actionFunc = func_80A3DD7C;
                return;
            case 1:
                gSaveContext.infTable[11] |= 2;
            case 2:
                pthis->actionFunc = EnGm_ProcessChoiceIndex;
            default:
                return;
        }

        pthis->actionFunc = EnGm_ProcessChoiceIndex;
    }
    if ((pthis->collider.base.ocFlags1 & OC1_HIT) || (SQ(dx) + SQ(dz)) < SQ(100.0f)) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        func_8002F2CC(&pthis->actor, globalCtx, 415.0f);
    }
}

void func_80A3DD7C(EnGm* pthis, GlobalContext* globalCtx) {
    u8 dialogState = Message_GetState(&globalCtx->msgCtx);

    if ((dialogState == TEXT_STATE_DONE || dialogState == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        pthis->actionFunc = func_80A3DC44;
        if (dialogState == TEXT_STATE_EVENT) {
            globalCtx->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
            globalCtx->msgCtx.stateTimer = 4;
        }
    }
}

void EnGm_ProcessChoiceIndex(EnGm* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // yes
                if (gSaveContext.rupees < 200) {
                    Message_ContinueTextbox(globalCtx, 0xC8);
                    pthis->actionFunc = func_80A3DD7C;
                } else {
                    func_8002F434(&pthis->actor, globalCtx, GI_SWORD_KNIFE, 415.0f, 10.0f);
                    pthis->actionFunc = func_80A3DF00;
                }
                break;
            case 1: // no
                Message_ContinueTextbox(globalCtx, 0x3050);
                pthis->actionFunc = func_80A3DD7C;
                break;
        }
    }
}

void func_80A3DF00(EnGm* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = func_80A3DF60;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_SWORD_KNIFE, 415.0f, 10.0f);
    }
}

void func_80A3DF60(EnGm* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        Rupees_ChangeBy(-200);
        pthis->actionFunc = func_80A3DC44;
    }
}

void func_80A3DFBC(EnGm* pthis, GlobalContext* globalCtx) {
    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objGmBankIndex].vromStart.get());
    pthis->timer++;
    pthis->actionFunc(pthis, globalCtx);
    pthis->actor.focus.rot.x = pthis->actor.world.rot.x;
    pthis->actor.focus.rot.y = pthis->actor.world.rot.y;
    pthis->actor.focus.rot.z = pthis->actor.world.rot.z;
    EnGm_UpdateEye(pthis);
    SkelAnime_Update(&pthis->skelAnime);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnGm_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnGm* pthis = (EnGm*)thisx;

    pthis->updateFunc(pthis, globalCtx);
}

void func_80A3E090(EnGm* pthis) {
    Vec3f vec1;
    Vec3f vec2;

    Matrix_Push();
    Matrix_Translate(0.0f, 0.0f, 2600.0f, MTXMODE_APPLY);
    Matrix_RotateZYX(pthis->actor.world.rot.x, pthis->actor.world.rot.y, pthis->actor.world.rot.z, MTXMODE_APPLY);
    vec1.x = vec1.y = vec1.z = 0.0f;
    Matrix_MultVec3f(&vec1, &vec2);
    pthis->collider.dim.pos.x = vec2.x;
    pthis->collider.dim.pos.y = vec2.y;
    pthis->collider.dim.pos.z = vec2.z;
    Matrix_Pop();
    Matrix_Push();
    Matrix_Translate(0.0f, 0.0f, 4300.0f, MTXMODE_APPLY);
    Matrix_RotateZYX(pthis->actor.world.rot.x, pthis->actor.world.rot.y, pthis->actor.world.rot.z, MTXMODE_APPLY);
    vec1.x = vec1.y = vec1.z = 0.0f;
    Matrix_MultVec3f(&vec1, &pthis->talkPos);
    Matrix_Pop();
    Matrix_Translate(0.0f, 0.0f, 3800.0f, MTXMODE_APPLY);
    Matrix_RotateZYX(pthis->actor.world.rot.x, pthis->actor.world.rot.y, pthis->actor.world.rot.z, MTXMODE_APPLY);
    vec1.x = vec1.y = vec1.z = 0.0f;
    Matrix_MultVec3f(&vec1, &pthis->actor.focus.pos);
    pthis->actor.focus.pos.y += 100.0f;
}

void EnGm_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* eyeTextures[] = { gGoronCsEyeOpenTex, gGoronCsEyeHalfTex, gGoronCsEyeClosedTex };
    EnGm* pthis = (EnGm*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_gm.c", 613);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->eyeTexIndex]));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(gGoronCsMouthNeutralTex));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, &pthis->actor);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_gm.c", 629);

    func_80A3E090(pthis);
}
