#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_KO_Z_EN_KO_C
#include "actor_common.h"

#include "z64actor.h"
/*
 * File: z_en_ko.c
 * Overlay: ovl_En_Ko
 * Description: Kokiri children, and Fado
 */

#include "z_en_ko.h"
#include "objects/object_fa/object_fa.h"
#include "objects/object_os_anime/object_os_anime.h"
#include "objects/object_km1/object_km1.h"
#include "objects/object_kw1/object_kw1.h"
#include "vt.h"
#include "def/audio_bank.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera_data.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_path.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

#define ENKO_TYPE (pthis->actor.params & 0xFF)
#define ENKO_PATH ((pthis->actor.params & 0xFF00) >> 8)

void EnKo_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKo_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnKo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKo_Update(Actor* thisx, GlobalContext* globalCtx);
void EnKo_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A99048(EnKo* pthis, GlobalContext* globalCtx);
void func_80A995CC(EnKo* pthis, GlobalContext* globalCtx);
void func_80A99384(EnKo* pthis, GlobalContext* globalCtx);
void func_80A99438(EnKo* pthis, GlobalContext* globalCtx);
void func_80A99504(EnKo* pthis, GlobalContext* globalCtx);
void func_80A99560(EnKo* pthis, GlobalContext* globalCtx);

s32 func_80A98ECC(EnKo* pthis, GlobalContext* globalCtx);

ActorInit En_Ko_InitVars = {
    ACTOR_EN_KO,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnKo),
    (ActorFunc)EnKo_Init,
    (ActorFunc)EnKo_Destroy,
    (ActorFunc)EnKo_Update,
    (ActorFunc)EnKo_Draw,
    (ActorFunc)EnKo_Reset,
};

static ColliderCylinderInit sCylinderInit = {
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
    { 20, 46, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

static void* sFaEyes[] = { gFaEyeOpenTex, gFaEyeHalfTex, gFaEyeClosedTex, NULL };
static void* sKw1Eyes[] = { gKw1EyeOpenTex, gKw1EyeHalfTex, gKw1EyeClosedTex, NULL }; 

static EnKoHead sHead[] = {
    { OBJECT_KM1, gKm1DL, NULL },
    { OBJECT_KW1, object_kw1_DL_002C10, sKw1Eyes },
    { OBJECT_FA, gFaDL, sFaEyes },
}; 

static EnKoSkeleton sSkeleton[2] = {
    { OBJECT_KM1, &gKm1Skel },
    { OBJECT_KW1, &gKw1Skel },
};

static struct_80034EC0_Entry sOsAnimeTable[] = {
    { &gObjOsAnim_8F6C, 1.0f, 2.0f, 14.0f, ANIMMODE_LOOP_PARTIAL, 0.0f },
    { &gObjOsAnim_8F6C, 0.0f, 1.0f, 1.0f, ANIMMODE_LOOP_PARTIAL, 0.0f },
    { &gObjOsAnim_9B64, 0.0f, 0.0f, 0.0f, ANIMMODE_ONCE, 0.0f },
    { &gObjOsAnim_9B64, 0.0f, 1.0f, 1.0f, ANIMMODE_ONCE, 0.0f },
    { &gObjOsAnim_9B64, 0.0f, 2.0f, 2.0f, ANIMMODE_ONCE, 0.0f },
    { &gObjOsAnim_62DC, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_62DC, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gObjOsAnim_5808, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gObjOsAnim_7830, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_8178, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_65E0, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_879C, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_7FFC, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_80B4, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_91AC, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_6F9C, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_7064, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_7120, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_7F38, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_7D94, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_6EE0, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_98EC, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_90EC, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_982C, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_9274, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_99A4, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_9028, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_7E64, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_7454, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gObjOsAnim_8F6C, 0.0f, 1.0f, 1.0f, ANIMMODE_LOOP_PARTIAL, -8.0f },
    { &gObjOsAnim_7D94, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gObjOsAnim_879C, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gObjOsAnim_6A60, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gObjOsAnim_7830, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
};

static u8 sOsAnimeLookup[13][5] = {
    /* ENKO_TYPE_CHILD_0    */ { 0x08, 0x09, 0x09, 0x0E, 0x0B },
    /* ENKO_TYPE_CHILD_1    */ { 0x02, 0x0C, 0x02, 0x0D, 0x0D },
    /* ENKO_TYPE_CHILD_2    */ { 0x0B, 0x0B, 0x0B, 0x0F, 0x09 },
    /* ENKO_TYPE_CHILD_3    */ { 0x00, 0x10, 0x10, 0x11, 0x12 },
    /* ENKO_TYPE_CHILD_4    */ { 0x13, 0x13, 0x14, 0x0A, 0x09 },
    /* ENKO_TYPE_CHILD_5    */ { 0x03, 0x03, 0x03, 0x03, 0x03 },
    /* ENKO_TYPE_CHILD_6    */ { 0x04, 0x16, 0x16, 0x04, 0x17 },
    /* ENKO_TYPE_CHILD_7    */ { 0x18, 0x10, 0x10, 0x19, 0x10 },
    /* ENKO_TYPE_CHILD_8    */ { 0x1A, 0x0F, 0x0F, 0x1A, 0x0F },
    /* ENKO_TYPE_CHILD_9    */ { 0x03, 0x03, 0x03, 0x1B, 0x1B },
    /* ENKO_TYPE_CHILD_10   */ { 0x02, 0x02, 0x02, 0x02, 0x16 },
    /* ENKO_TYPE_CHILD_11   */ { 0x0E, 0x0E, 0x0E, 0x0E, 0x0E },
    /* ENKO_TYPE_CHILD_FADO */ { 0x05, 0x05, 0x05, 0x05, 0x05 },
};

static EnKoModelInfo sModelInfo[] = {
    /* ENKO_TYPE_CHILD_0    */ { KO_BOY, KO_BOY, { 0, 130, 70, 255 }, KO_BOY, { 110, 170, 20, 255 } },
    /* ENKO_TYPE_CHILD_1    */ { KO_GIRL, KO_GIRL, { 70, 190, 60, 255 }, KO_GIRL, { 100, 30, 0, 255 } },
    /* ENKO_TYPE_CHILD_2    */ { KO_BOY, KO_BOY, { 0, 130, 70, 255 }, KO_BOY, { 110, 170, 20, 255 } },
    /* ENKO_TYPE_CHILD_3    */ { KO_BOY, KO_BOY, { 0, 130, 70, 255 }, KO_BOY, { 110, 170, 20, 255 } },
    /* ENKO_TYPE_CHILD_4    */ { KO_BOY, KO_BOY, { 0, 130, 70, 255 }, KO_BOY, { 110, 170, 20, 255 } },
    /* ENKO_TYPE_CHILD_5    */ { KO_GIRL, KO_GIRL, { 70, 190, 60, 255 }, KO_GIRL, { 100, 30, 0, 255 } },
    /* ENKO_TYPE_CHILD_6    */ { KO_GIRL, KO_GIRL, { 70, 190, 60, 255 }, KO_GIRL, { 100, 30, 0, 255 } },
    /* ENKO_TYPE_CHILD_7    */ { KO_BOY, KO_BOY, { 0, 130, 70, 255 }, KO_BOY, { 110, 170, 20, 255 } },
    /* ENKO_TYPE_CHILD_8    */ { KO_BOY, KO_BOY, { 0, 130, 70, 255 }, KO_BOY, { 110, 170, 20, 255 } },
    /* ENKO_TYPE_CHILD_9    */ { KO_GIRL, KO_GIRL, { 70, 190, 60, 255 }, KO_GIRL, { 100, 30, 0, 255 } },
    /* ENKO_TYPE_CHILD_10   */ { KO_GIRL, KO_GIRL, { 70, 190, 60, 255 }, KO_GIRL, { 100, 30, 0, 255 } },
    /* ENKO_TYPE_CHILD_11   */ { KO_BOY, KO_BOY, { 0, 130, 70, 255 }, KO_BOY, { 110, 170, 20, 255 } },
    /* ENKO_TYPE_CHILD_FADO */ { KO_FADO, KO_GIRL, { 70, 190, 60, 255 }, KO_GIRL, { 100, 30, 0, 255 } },
}; 

static EnKoInteractInfo sInteractInfo[] = {
    /* ENKO_TYPE_CHILD_0    */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_1    */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_2    */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_3    */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_4    */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_5    */ { 1, 30.0f, 240.0f },
    /* ENKO_TYPE_CHILD_6    */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_7    */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_8    */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_9    */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_10   */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_11   */ { 6, 30.0f, 180.0f },
    /* ENKO_TYPE_CHILD_FADO */ { 6, 30.0f, 180.0f },
};

s32 EnKo_AreObjectsAvailable(EnKo* pthis, GlobalContext* globalCtx) {
    u8 headId = sModelInfo[ENKO_TYPE].headId;
    u8 bodyId = sModelInfo[ENKO_TYPE].bodyId;
    u8 legsId = sModelInfo[ENKO_TYPE].legsId;

    pthis->legsObjectBankIdx = Object_GetIndex(&globalCtx->objectCtx, sSkeleton[legsId].objectId);
    if (pthis->legsObjectBankIdx < 0) {
        return false;
    }

    pthis->bodyObjectBankIdx = Object_GetIndex(&globalCtx->objectCtx, sSkeleton[bodyId].objectId);
    if (pthis->bodyObjectBankIdx < 0) {
        return false;
    }

    pthis->headObjectBankIdx = Object_GetIndex(&globalCtx->objectCtx, sHead[headId].objectId);
    if (pthis->headObjectBankIdx < 0) {
        return false;
    }
    return true;
}

s32 EnKo_AreObjectsLoaded(EnKo* pthis, GlobalContext* globalCtx) {
    if (!Object_IsLoaded(&globalCtx->objectCtx, pthis->legsObjectBankIdx)) {
        return false;
    }
    if (!Object_IsLoaded(&globalCtx->objectCtx, pthis->bodyObjectBankIdx)) {
        return false;
    }
    if (!Object_IsLoaded(&globalCtx->objectCtx, pthis->headObjectBankIdx)) {
        return false;
    }
    return true;
}

s32 EnKo_IsOsAnimeAvailable(EnKo* pthis, GlobalContext* globalCtx) {
    pthis->osAnimeBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_OS_ANIME);
    if (pthis->osAnimeBankIndex < 0) {
        return false;
    }
    return true;
}

s32 EnKo_IsOsAnimeLoaded(EnKo* pthis, GlobalContext* globalCtx) {
    if (!Object_IsLoaded(&globalCtx->objectCtx, pthis->osAnimeBankIndex)) {
        return false;
    }
    return true;
}

u16 func_80A96FD0(GlobalContext* globalCtx, Actor* thisx) {
    EnKo* pthis = (EnKo*)thisx;
    switch (ENKO_TYPE) {
        case ENKO_TYPE_CHILD_FADO:
            if (gSaveContext.eventChkInf[4] & 1) {
                return 0x10DA;
            }
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                return 0x10D9;
            }
            return (gSaveContext.infTable[11] & 0x80) ? 0x10D8 : 0x10D7;
        case ENKO_TYPE_CHILD_0:
            if (gSaveContext.eventChkInf[4] & 1) {
                return 0x1025;
            }
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                return 0x1042;
            }
            return 0x1004;
        case ENKO_TYPE_CHILD_1:
            if (gSaveContext.eventChkInf[4] & 1) {
                return 0x1023;
            }
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                return 0x1043;
            }
            if (gSaveContext.infTable[1] & 0x4000) {
                return 0x1006;
            }
            return 0x1005;
        case ENKO_TYPE_CHILD_2:
            if (gSaveContext.eventChkInf[4] & 1) {
                return 0x1022;
            }
            return 0x1007;
        case ENKO_TYPE_CHILD_3:
            if (gSaveContext.eventChkInf[4] & 1) {
                return 0x1021;
            }
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                return 0x1044;
            }
            if (gSaveContext.infTable[2] & 4) {
                return 0x1009;
            }
            return 0x1008;
        case ENKO_TYPE_CHILD_4:
            if (gSaveContext.eventChkInf[4] & 1) {
                return 0x1097;
            }
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                return 0x1042;
            }
            if (gSaveContext.infTable[2] & 0x10) {
                return 0x100B;
            }
            return 0x100A;
        case ENKO_TYPE_CHILD_5:
            if (gSaveContext.eventChkInf[4] & 1) {
                return 0x10B0;
            }
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                return 0x1043;
            }
            if (gSaveContext.infTable[2] & 0x40) {
                return 0x100D;
            }
            return 0x100C;
        case ENKO_TYPE_CHILD_6:
            if (gSaveContext.eventChkInf[4] & 1) {
                return 0x10B5;
            }
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                return 0x1043;
            }
            if (gSaveContext.infTable[2] & 0x100) {
                return 0x1019;
            }
            return 0x100E;
        case ENKO_TYPE_CHILD_7:
            return 0x1035;
        case ENKO_TYPE_CHILD_8:
            return 0x1038;
        case ENKO_TYPE_CHILD_9:
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                return 0x104B;
            }
            return 0x103C;
        case ENKO_TYPE_CHILD_10:
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                return 0x104C;
            }
            return 0x103D;
        case ENKO_TYPE_CHILD_11:
            return 0x103E;
    }
    return 0;
}

u16 func_80A97338(GlobalContext* globalCtx, Actor* thisx) {
    Player* player = GET_PLAYER(globalCtx);
    EnKo* pthis = (EnKo*)thisx;

    switch (ENKO_TYPE) {
        case ENKO_TYPE_CHILD_FADO:
            player->exchangeItemId = EXCH_ITEM_ODD_POTION;
            return 0x10B9;
        case ENKO_TYPE_CHILD_0:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x1072;
            }
            if (gSaveContext.infTable[4] & 2) {
                return 0x1056;
            }
            return 0x1055;
        case ENKO_TYPE_CHILD_1:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x1073;
            }
            return 0x105A;
        case ENKO_TYPE_CHILD_2:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x1074;
            }
            if (gSaveContext.infTable[4] & 0x80) {
                return 0x105E;
            }
            return 0x105D;
        case ENKO_TYPE_CHILD_3:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x1075;
            }
            return 0x105B;
        case ENKO_TYPE_CHILD_4:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x1076;
            }
            return 0x105F;
        case ENKO_TYPE_CHILD_5:
            return 0x1057;
        case ENKO_TYPE_CHILD_6:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x1077;
            }
            if (gSaveContext.infTable[5] & 2) {
                return 0x1059;
            }
            return 0x1058;
        case ENKO_TYPE_CHILD_7:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x1079;
            }
            return 0x104E;
        case ENKO_TYPE_CHILD_8:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x107A;
            }
            if (gSaveContext.infTable[5] & 0x200) {
                return 0x1050;
            }
            return 0x104F;
        case ENKO_TYPE_CHILD_9:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x107B;
            }
            return 0x1051;
        case ENKO_TYPE_CHILD_10:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x107C;
            }
            return 0x1052;
        case ENKO_TYPE_CHILD_11:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                return 0x107C;
            }
            if (gSaveContext.infTable[6] & 2) {
                return 0x1054;
            }
            return 0x1053;
        default:
            return 0;
    }
}

u16 func_80A97610(GlobalContext* globalCtx, Actor* thisx) {
    u16 faceReaction;
    EnKo* pthis = (EnKo*)thisx;

    if (ENKO_TYPE == ENKO_TYPE_CHILD_0 || ENKO_TYPE == ENKO_TYPE_CHILD_2 || ENKO_TYPE == ENKO_TYPE_CHILD_3 ||
        ENKO_TYPE == ENKO_TYPE_CHILD_4 || ENKO_TYPE == ENKO_TYPE_CHILD_7 || ENKO_TYPE == ENKO_TYPE_CHILD_8 ||
        ENKO_TYPE == ENKO_TYPE_CHILD_11) {
        faceReaction = Text_GetFaceReaction(globalCtx, 0x13);
    }
    if (ENKO_TYPE == ENKO_TYPE_CHILD_1 || ENKO_TYPE == ENKO_TYPE_CHILD_5 || ENKO_TYPE == ENKO_TYPE_CHILD_6 ||
        ENKO_TYPE == ENKO_TYPE_CHILD_9 || ENKO_TYPE == ENKO_TYPE_CHILD_10) {
        faceReaction = Text_GetFaceReaction(globalCtx, 0x14);
    }
    if (ENKO_TYPE == ENKO_TYPE_CHILD_FADO) {
        faceReaction = Text_GetFaceReaction(globalCtx, 0x12);
    }
    if (faceReaction != 0) {
        return faceReaction;
    }
    if (LINK_IS_ADULT) {
        return func_80A97338(globalCtx, thisx);
    }
    return func_80A96FD0(globalCtx, thisx);
}

s16 func_80A97738(GlobalContext* globalCtx, Actor* thisx) {
    EnKo* pthis = (EnKo*)thisx;

    switch (Message_GetState(&globalCtx->msgCtx)) {
        case TEXT_STATE_CLOSING:
            switch (pthis->actor.textId) {
                case 0x1005:
                    gSaveContext.infTable[1] |= 0x4000;
                    break;
                case 0x1008:
                    gSaveContext.infTable[2] |= 0x4;
                    break;
                case 0x100A:
                    gSaveContext.infTable[2] |= 0x10;
                    break;
                case 0x100C:
                    gSaveContext.infTable[2] |= 0x40;
                    break;
                case 0x100E:
                    gSaveContext.infTable[2] |= 0x100;
                    break;
                case 0x104F:
                    gSaveContext.infTable[5] |= 0x200;
                    break;
                case 0x1053:
                    gSaveContext.infTable[6] |= 2;
                    break;
                case 0x1055:
                    gSaveContext.infTable[4] |= 2;
                    break;
                case 0x1058:
                    gSaveContext.infTable[5] |= 2;
                    break;
                case 0x105D:
                    gSaveContext.infTable[4] |= 0x80;
                    break;
                case 0x10D7:
                    gSaveContext.infTable[11] |= 0x80;
                    break;
                case 0x10BA:
                    return 1;
            }
            return 0;
        case TEXT_STATE_DONE_FADING:
            switch (pthis->actor.textId) {
                case 0x10B7:
                case 0x10B8:
                    if (pthis->unk_210 == 0) {
                        Audio_PlaySoundGeneral(NA_SE_SY_TRE_BOX_APPEAR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0,
                                               &gReverbAdd2);
                        pthis->unk_210 = 1;
                    }
            }
            return 1;
        case TEXT_STATE_CHOICE:
            if (Message_ShouldAdvance(globalCtx)) {
                switch (pthis->actor.textId) {
                    case 0x1035:
                        pthis->actor.textId = (globalCtx->msgCtx.choiceIndex == 0) ? 0x1036 : 0x1037;
                        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                        break;
                    case 0x1038:
                        pthis->actor.textId = (globalCtx->msgCtx.choiceIndex != 0)
                                                 ? (globalCtx->msgCtx.choiceIndex == 1) ? 0x103A : 0x103B
                                                 : 0x1039;
                        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                        break;
                    case 0x103E:
                        pthis->actor.textId = (globalCtx->msgCtx.choiceIndex == 0) ? 0x103F : 0x1040;
                        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                        break;
                    case 0x10B7:
                        gSaveContext.infTable[11] |= 0x1000;

                    case 0x10B8:
                        pthis->actor.textId = (globalCtx->msgCtx.choiceIndex == 0) ? 0x10BA : 0x10B9;
                        return (globalCtx->msgCtx.choiceIndex == 0) ? 2 : 1;
                }
                return 1;
            }
            break;
        case TEXT_STATE_DONE:
            if (Message_ShouldAdvance(globalCtx)) {
                return 3;
            }
    }
    return 1;
}

s32 EnKo_GetForestQuestState(EnKo* pthis) {
    s32 result;

    if (!LINK_IS_ADULT) {
        // Obtained Zelda's Letter
        if (gSaveContext.eventChkInf[4] & 1) {
            return ENKO_FQS_CHILD_SARIA;
        }
        if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
            return ENKO_FQS_CHILD_STONE;
        }
        return ENKO_FQS_CHILD_START;
    }

    if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
        result = ENKO_FQS_ADULT_SAVED;
    } else {
        result = ENKO_FQS_ADULT_ENEMY;
    }
    return result;
}

f32 func_80A97BC0(EnKo* pthis) {
    f32 D_80A9A62C[13][5] = {
        /* ENKO_TYPE_CHILD_0    */ { 0.0f, 0.0f, 0.0f, -30.0f, -20.0f },
        /* ENKO_TYPE_CHILD_1    */ { 0.0f, 0.0f, 0.0f, -20.0f, -10.0f },
        /* ENKO_TYPE_CHILD_2    */ { 0.0f, 0.0f, 0.0f, -30.0f, -20.0f },
        /* ENKO_TYPE_CHILD_3    */ { -10.0f, 10.0f, 10.0f, -10.0f, -30.0f },
        /* ENKO_TYPE_CHILD_4    */ { 0.0f, 0.0f, 0.0f, -10.0f, -20.0f },
        /* ENKO_TYPE_CHILD_5    */ { 0.0f, 0.0f, 0.0f, -20.0f, -20.0f },
        /* ENKO_TYPE_CHILD_6    */ { 0.0f, 0.0f, 0.0f, -10.0f, -20.0f },
        /* ENKO_TYPE_CHILD_7    */ { 10.0f, 10.0f, 10.0f, -60.0f, -20.0f },
        /* ENKO_TYPE_CHILD_8    */ { -10.0f, -10.0f, -20.0f, -30.0f, -30.0f },
        /* ENKO_TYPE_CHILD_9    */ { -10.0f, -10.0f, -10.0f, -40.0f, -40.0f },
        /* ENKO_TYPE_CHILD_10   */ { 0.0f, 0.0f, 0.0f, -10.0f, -20.0f },
        /* ENKO_TYPE_CHILD_11   */ { -10.0f, -10.0f, -20.0f, -30.0f, -30.0f },
        /* ENKO_TYPE_CHILD_FADO */ { 0.0f, 0.0f, 0.0f, -20.0f, -20.0f },
    };

    if (LINK_IS_ADULT && ENKO_TYPE == ENKO_TYPE_CHILD_FADO) {
        return -20.0f;
    }
    return D_80A9A62C[ENKO_TYPE][EnKo_GetForestQuestState(pthis)];
}

u8 func_80A97C7C(EnKo* pthis) {
    u8 D_80A9A730[13][5] = {
        /* ENKO_TYPE_CHILD_0    */ { 1, 1, 1, 0, 1 },
        /* ENKO_TYPE_CHILD_1    */ { 1, 1, 1, 1, 1 },
        /* ENKO_TYPE_CHILD_2    */ { 1, 1, 1, 0, 1 },
        /* ENKO_TYPE_CHILD_3    */ { 1, 1, 1, 0, 1 },
        /* ENKO_TYPE_CHILD_4    */ { 1, 1, 1, 0, 1 },
        /* ENKO_TYPE_CHILD_5    */ { 0, 0, 0, 0, 0 },
        /* ENKO_TYPE_CHILD_6    */ { 1, 1, 1, 1, 1 },
        /* ENKO_TYPE_CHILD_7    */ { 1, 1, 1, 0, 1 },
        /* ENKO_TYPE_CHILD_8    */ { 0, 0, 0, 0, 0 },
        /* ENKO_TYPE_CHILD_9    */ { 0, 0, 0, 0, 0 },
        /* ENKO_TYPE_CHILD_10   */ { 1, 1, 1, 1, 1 },
        /* ENKO_TYPE_CHILD_11   */ { 0, 0, 0, 0, 0 },
        /* ENKO_TYPE_CHILD_FADO */ { 1, 1, 1, 1, 1 },
    };

    return D_80A9A730[ENKO_TYPE][EnKo_GetForestQuestState(pthis)];
}

s32 EnKo_IsWithinTalkAngle(EnKo* pthis) {
    s16 yawDiff;
    s16 yawDiffAbs;
    s32 result;

    yawDiff = pthis->actor.yawTowardsPlayer - (f32)pthis->actor.shape.rot.y;
    yawDiffAbs = ABS(yawDiff);

    if (yawDiffAbs < 0x3FFC) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

s32 func_80A97D68(EnKo* pthis, GlobalContext* globalCtx) {
    s16 arg3;

    if (pthis->unk_1E8.unk_00 != 0) {
        if ((pthis->skelAnime.animation == &gObjOsAnim_6A60) == false) {
            func_80034EC0(&pthis->skelAnime, sOsAnimeTable, 0x20);
        }
        arg3 = 2;
    } else {
        if ((pthis->skelAnime.animation == &gObjOsAnim_7830) == false) {
            func_80034EC0(&pthis->skelAnime, sOsAnimeTable, 0x21);
        }
        arg3 = 1;
    }
    func_80034A14(&pthis->actor, &pthis->unk_1E8, 2, arg3);
    return EnKo_IsWithinTalkAngle(pthis);
}

s32 func_80A97E18(EnKo* pthis, GlobalContext* globalCtx) {
    s16 arg3;

    func_80034F54(globalCtx, pthis->unk_2E4, pthis->unk_304, 16);
    if (EnKo_IsWithinTalkAngle(pthis) == true) {
        arg3 = 2;
    } else {
        arg3 = 1;
    }
    if (pthis->unk_1E8.unk_00 != 0) {
        arg3 = 4;
    } else if (pthis->lookDist < pthis->actor.xzDistToPlayer) {
        arg3 = 1;
    }
    func_80034A14(&pthis->actor, &pthis->unk_1E8, 2, arg3);
    return 1;
}

s32 func_80A97EB0(EnKo* pthis, GlobalContext* globalCtx) {
    s16 arg3;
    s32 result;

    func_80034F54(globalCtx, pthis->unk_2E4, pthis->unk_304, 16);
    result = EnKo_IsWithinTalkAngle(pthis);
    arg3 = (result == true) ? 2 : 1;
    func_80034A14(&pthis->actor, &pthis->unk_1E8, 2, arg3);
    return result;
}

s32 func_80A97F20(EnKo* pthis, GlobalContext* globalCtx) {
    func_80034F54(globalCtx, pthis->unk_2E4, pthis->unk_304, 16);
    func_80034A14(&pthis->actor, &pthis->unk_1E8, 2, 4);
    return 1;
}

s32 func_80A97F70(EnKo* pthis, GlobalContext* globalCtx) {
    s16 arg3;

    if (pthis->unk_1E8.unk_00 != 0) {
        if ((pthis->skelAnime.animation == &gObjOsAnim_8F6C) == false) {
            func_80034EC0(&pthis->skelAnime, sOsAnimeTable, 0x1D);
        }
        func_80034F54(globalCtx, pthis->unk_2E4, pthis->unk_304, 16);
        arg3 = 2;
    } else {
        if ((pthis->skelAnime.animation == &gObjOsAnim_7D94) == false) {
            func_80034EC0(&pthis->skelAnime, sOsAnimeTable, 0x1E);
        }
        arg3 = 1;
    }
    func_80034A14(&pthis->actor, &pthis->unk_1E8, 5, arg3);
    return EnKo_IsWithinTalkAngle(pthis);
}

s32 func_80A98034(EnKo* pthis, GlobalContext* globalCtx) {
    s16 arg3;
    s32 result;

    if (pthis->unk_1E8.unk_00 != 0) {
        if ((pthis->skelAnime.animation == &gObjOsAnim_8F6C) == false) {
            func_80034EC0(&pthis->skelAnime, sOsAnimeTable, 0x1D);
        }
        func_80034F54(globalCtx, pthis->unk_2E4, pthis->unk_304, 16);
        result = EnKo_IsWithinTalkAngle(pthis);
        arg3 = (result == true) ? 2 : 1;
    } else {
        if ((pthis->skelAnime.animation == &gObjOsAnim_879C) == false) {
            func_80034EC0(&pthis->skelAnime, sOsAnimeTable, 0x1F);
        }
        arg3 = 1;
        result = EnKo_IsWithinTalkAngle(pthis);
    }
    func_80034A14(&pthis->actor, &pthis->unk_1E8, 5, arg3);
    return result;
}

// Same as func_80A97F20
s32 func_80A98124(EnKo* pthis, GlobalContext* globalCtx) {
    func_80034F54(globalCtx, pthis->unk_2E4, pthis->unk_304, 16);
    func_80034A14(&pthis->actor, &pthis->unk_1E8, 2, 4);
    return 1;
}

s32 func_80A98174(EnKo* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1E8.unk_00 != 0) {
        if (Animation_OnFrame(&pthis->skelAnime, 18.0f)) {
            pthis->skelAnime.playSpeed = 0.0f;
        }
    } else if (pthis->skelAnime.playSpeed != 1.0f) {
        pthis->skelAnime.playSpeed = 1.0f;
    }
    if (pthis->skelAnime.playSpeed == 0.0f) {
        func_80034F54(globalCtx, pthis->unk_2E4, pthis->unk_304, 16);
    }
    func_80034A14(&pthis->actor, &pthis->unk_1E8, 2, (pthis->skelAnime.playSpeed == 0.0f) ? 2 : 1);
    return EnKo_IsWithinTalkAngle(pthis);
}

s32 EnKo_ChildStart(EnKo* pthis, GlobalContext* globalCtx) {
    switch (ENKO_TYPE) {
        case ENKO_TYPE_CHILD_0:
            return func_80A97D68(pthis, globalCtx);
        case ENKO_TYPE_CHILD_1:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_2:
            return func_80A98034(pthis, globalCtx);
        case ENKO_TYPE_CHILD_3:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_4:
            return func_80A97F70(pthis, globalCtx);
        case ENKO_TYPE_CHILD_5:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_6:
            return func_80A97F20(pthis, globalCtx);
        case ENKO_TYPE_CHILD_7:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_8:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_9:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_10:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_11:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_FADO:
            return func_80A97E18(pthis, globalCtx);
    }
    return 0;
}

s32 EnKo_ChildStone(EnKo* pthis, GlobalContext* globalCtx) {
    switch (ENKO_TYPE) {
        case ENKO_TYPE_CHILD_0:
            return func_80A98124(pthis, globalCtx);
        case ENKO_TYPE_CHILD_1:
            return func_80A98124(pthis, globalCtx);
        case ENKO_TYPE_CHILD_2:
            return func_80A98034(pthis, globalCtx);
        case ENKO_TYPE_CHILD_3:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_4:
            return func_80A97F70(pthis, globalCtx);
        case ENKO_TYPE_CHILD_5:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_6:
            return func_80A97F20(pthis, globalCtx);
        case ENKO_TYPE_CHILD_7:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_8:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_9:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_10:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_11:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_FADO:
            return func_80A97E18(pthis, globalCtx);
    }
    return 0;
}

s32 EnKo_ChildSaria(EnKo* pthis, GlobalContext* globalCtx) {
    switch (ENKO_TYPE) {
        case ENKO_TYPE_CHILD_0:
            return func_80A98124(pthis, globalCtx);
        case ENKO_TYPE_CHILD_1:
            return func_80A98124(pthis, globalCtx);
        case ENKO_TYPE_CHILD_2:
            return func_80A98034(pthis, globalCtx);
        case ENKO_TYPE_CHILD_3:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_4:
            return func_80A98174(pthis, globalCtx);
        case ENKO_TYPE_CHILD_5:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_6:
            return func_80A97F20(pthis, globalCtx);
        case ENKO_TYPE_CHILD_7:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_8:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_9:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_10:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_11:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_FADO:
            return func_80A97E18(pthis, globalCtx);
    }
    return 0;
}

s32 EnKo_AdultEnemy(EnKo* pthis, GlobalContext* globalCtx) {
    switch (ENKO_TYPE) {
        case ENKO_TYPE_CHILD_0:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_1:
            return func_80A98124(pthis, globalCtx);
        case ENKO_TYPE_CHILD_2:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_3:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_4:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_5:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_6:
            return func_80A97F20(pthis, globalCtx);
        case ENKO_TYPE_CHILD_7:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_8:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_9:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_10:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_11:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_FADO:
            return func_80A97E18(pthis, globalCtx);
    }
    return 0;
}

s32 EnKo_AdultSaved(EnKo* pthis, GlobalContext* globalCtx) {
    switch (ENKO_TYPE) {
        case ENKO_TYPE_CHILD_0:
            return func_80A98034(pthis, globalCtx);
        case ENKO_TYPE_CHILD_1:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_2:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_3:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_4:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_5:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_6:
            return func_80A97F20(pthis, globalCtx);
        case ENKO_TYPE_CHILD_7:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_8:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_9:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_10:
            return func_80A97E18(pthis, globalCtx);
        case ENKO_TYPE_CHILD_11:
            return func_80A97EB0(pthis, globalCtx);
        case ENKO_TYPE_CHILD_FADO:
            return func_80A97E18(pthis, globalCtx);
    }
    return 0;
}
void func_80A9877C(EnKo* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((globalCtx->csCtx.state != 0) || (gDbgCamEnabled != 0)) {
        pthis->unk_1E8.unk_18 = globalCtx->view.eye;
        pthis->unk_1E8.unk_14 = 40.0f;
        if (ENKO_TYPE != ENKO_TYPE_CHILD_0) {
            func_80034A14(&pthis->actor, &pthis->unk_1E8, 2, 2);
        }
    } else {
        pthis->unk_1E8.unk_18 = player->actor.world.pos;
        pthis->unk_1E8.unk_14 = func_80A97BC0(pthis);
        if ((func_80A98ECC(pthis, globalCtx) == 0) && (pthis->unk_1E8.unk_00 == 0)) {
            return;
        }
    }
    if (func_800343CC(globalCtx, &pthis->actor, &pthis->unk_1E8.unk_00, pthis->lookDist, func_80A97610, func_80A97738) &&
        ENKO_TYPE == ENKO_TYPE_CHILD_FADO && globalCtx->sceneNum == SCENE_SPOT10) {
        pthis->actor.textId = INV_CONTENT(ITEM_TRADE_ADULT) > ITEM_ODD_POTION ? 0x10B9 : 0x10DF;

        if (func_8002F368(globalCtx) == ENKO_TYPE_CHILD_9) {
            pthis->actor.textId = (gSaveContext.infTable[11] & 0x1000) ? 0x10B8 : 0x10B7;
            pthis->unk_210 = 0;
        }
        player->actor.textId = pthis->actor.textId;
    }
}

// Checks if the Kokiri should spawn based on quest progress
s32 EnKo_CanSpawn(EnKo* pthis, GlobalContext* globalCtx) {
    switch (globalCtx->sceneNum) {
        case SCENE_SPOT04:
            if (ENKO_TYPE >= ENKO_TYPE_CHILD_7 && ENKO_TYPE != ENKO_TYPE_CHILD_FADO) {
                return false;
            }
            if (!CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST) && LINK_IS_ADULT) {
                return false;
            }
            return true;
        case SCENE_KOKIRI_HOME:
            if (ENKO_TYPE != ENKO_TYPE_CHILD_7 && ENKO_TYPE != ENKO_TYPE_CHILD_8 && ENKO_TYPE != ENKO_TYPE_CHILD_11) {
                return false;
            } else {
                return true;
            }
        case SCENE_KOKIRI_HOME3:
            if (LINK_IS_ADULT && !CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                if (ENKO_TYPE != ENKO_TYPE_CHILD_1 && ENKO_TYPE != ENKO_TYPE_CHILD_9) {
                    return false;
                } else {
                    return true;
                }
            }
            if (ENKO_TYPE != ENKO_TYPE_CHILD_9) {
                return false;
            } else {
                return true;
            }
        case SCENE_KOKIRI_HOME4:
            if (LINK_IS_ADULT && !CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                if (ENKO_TYPE != ENKO_TYPE_CHILD_0 && ENKO_TYPE != ENKO_TYPE_CHILD_4) {
                    return false;
                } else {
                    return true;
                }
            } else {
                return false;
            }
        case SCENE_KOKIRI_HOME5:
            if (LINK_IS_ADULT && !CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                if (ENKO_TYPE != ENKO_TYPE_CHILD_6) {
                    return false;
                } else {
                    return true;
                }
            } else {
                return false;
            }

        case SCENE_KOKIRI_SHOP:
            if (LINK_IS_ADULT && !CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                if (ENKO_TYPE != ENKO_TYPE_CHILD_5 && ENKO_TYPE != ENKO_TYPE_CHILD_10) {
                    return false;
                } else {
                    return true;
                }
            } else if (ENKO_TYPE != ENKO_TYPE_CHILD_10) {
                return false;
            } else {
                return true;
            }

        case SCENE_SPOT10:
            return (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_ODD_POTION) ? true : false;
        default:
            return false;
    }
}

void EnKo_Blink(EnKo* pthis) {
    void** eyeTextures;
    s32 headId;

    if (DECR(pthis->blinkTimer) == 0) {
        headId = sModelInfo[ENKO_TYPE].headId;
        pthis->eyeTextureIndex++;
        eyeTextures = sHead[headId].eyeTextures;
        if (eyeTextures != NULL && eyeTextures[pthis->eyeTextureIndex] == NULL) {
            pthis->blinkTimer = Rand_S16Offset(30, 30);
            pthis->eyeTextureIndex = 0;
        }
    }
}

void func_80A98CD8(EnKo* pthis) {
    s32 type = ENKO_TYPE;
    EnKoInteractInfo* info = &sInteractInfo[type];

    pthis->actor.targetMode = info->targetMode;
    pthis->lookDist = info->lookDist;
    pthis->lookDist += pthis->collider.dim.radius;
    pthis->appearDist = info->appearDist;
}

// Used to fetch actor animation?
s32 EnKo_GetForestQuestState2(EnKo* pthis) {
    if (LINK_IS_ADULT) {
        return CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST) ? ENKO_FQS_ADULT_SAVED : ENKO_FQS_ADULT_ENEMY;
    }
    if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
        return (gSaveContext.eventChkInf[4] & 1) ? ENKO_FQS_CHILD_SARIA : ENKO_FQS_CHILD_STONE;
    }
    return ENKO_FQS_CHILD_START;
}

void func_80A98DB4(EnKo* pthis, GlobalContext* globalCtx) {
    f32 dist;

    if (globalCtx->sceneNum != SCENE_SPOT10 && globalCtx->sceneNum != SCENE_SPOT04) {
        pthis->modelAlpha = 255.0f;
        return;
    }
    if (globalCtx->csCtx.state != 0 || gDbgCamEnabled != 0) {
        dist = Math_Vec3f_DistXYZ(&pthis->actor.world.pos, &globalCtx->view.eye) * 0.25f;
    } else {
        dist = pthis->actor.xzDistToPlayer;
    }

    Math_SmoothStepToF(&pthis->modelAlpha, (pthis->appearDist < dist) ? 0.0f : 255.0f, 0.3f, 40.0f, 1.0f);
    if (pthis->modelAlpha < 10.0f) {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    } else {
        pthis->actor.flags |= ACTOR_FLAG_0;
    }
}

s32 func_80A98ECC(EnKo* pthis, GlobalContext* globalCtx) {
    if (globalCtx->sceneNum == SCENE_SPOT10 && ENKO_TYPE == ENKO_TYPE_CHILD_FADO) {
        return func_80A97E18(pthis, globalCtx);
    }
    switch (EnKo_GetForestQuestState(pthis)) {
        case ENKO_FQS_CHILD_START:
            return EnKo_ChildStart(pthis, globalCtx);
        case ENKO_FQS_CHILD_STONE:
            return EnKo_ChildStone(pthis, globalCtx);
        case ENKO_FQS_CHILD_SARIA:
            return EnKo_ChildSaria(pthis, globalCtx);
        case ENKO_FQS_ADULT_ENEMY:
            return EnKo_AdultEnemy(pthis, globalCtx);
        case ENKO_FQS_ADULT_SAVED:
            return EnKo_AdultSaved(pthis, globalCtx);
    }
    return 0;
}

void EnKo_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnKo* pthis = (EnKo*)thisx;

    if (ENKO_TYPE >= ENKO_TYPE_CHILD_MAX /*|| !EnKo_IsOsAnimeAvailable(pthis, globalCtx) ||
        !EnKo_AreObjectsAvailable(pthis, globalCtx)*/) {
        Actor_Kill(thisx);
    }
    if (!EnKo_CanSpawn(pthis, globalCtx)) {
        Actor_Kill(thisx);
    }
    pthis->actionFunc = func_80A99048;
}

void EnKo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnKo* pthis = (EnKo*)thisx;
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80A99048(EnKo* pthis, GlobalContext* globalCtx) {
    if (EnKo_IsOsAnimeLoaded(pthis, globalCtx) && EnKo_AreObjectsLoaded(pthis, globalCtx)) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        pthis->actor.objBankIndex = pthis->legsObjectBankIdx;
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->actor.objBankIndex].vromStart.get());
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, sSkeleton[sModelInfo[ENKO_TYPE].legsId].flexSkeletonHeader,
                           NULL, pthis->jointTable, pthis->morphTable, 16);
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 18.0f);
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->osAnimeBankIndex].vromStart.get());
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
        CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
        if (ENKO_TYPE == ENKO_TYPE_CHILD_7) {
            // "Angle Z"
            osSyncPrintf(VT_BGCOL(BLUE) "  アングルＺ->(%d)\n" VT_RST, pthis->actor.shape.rot.z);
            if (LINK_IS_ADULT && !CHECK_QUEST_ITEM(QUEST_MEDALLION_FOREST)) {
                if (pthis->actor.shape.rot.z != 1) {
                    Actor_Kill(&pthis->actor);
                    return;
                }
            } else if (pthis->actor.shape.rot.z != 0) {
                Actor_Kill(&pthis->actor);
                return;
            }
        }
        if (ENKO_TYPE == ENKO_TYPE_CHILD_5) {
            pthis->collider.base.ocFlags1 |= 0x40;
        }
        pthis->forestQuestState = EnKo_GetForestQuestState2(pthis);
        func_80034EC0(&pthis->skelAnime, sOsAnimeTable, sOsAnimeLookup[ENKO_TYPE][pthis->forestQuestState]);
        Actor_SetScale(&pthis->actor, 0.01f);
        func_80A98CD8(pthis);
        pthis->modelAlpha = 0.0f;
        pthis->path = Path_GetByIndex(globalCtx, ENKO_PATH, 0xFF);
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ELF, pthis->actor.world.pos.x,
                           pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 3);
        if (ENKO_TYPE == ENKO_TYPE_CHILD_3) {
            if (!CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
                pthis->collider.dim.height += 200;
                pthis->actionFunc = func_80A995CC;
                return;
            }
            Path_CopyLastPoint(pthis->path, &pthis->actor.world.pos);
        }
        pthis->actionFunc = func_80A99384;
    }
}

void func_80A99384(EnKo* pthis, GlobalContext* globalCtx) {
    if (ENKO_TYPE == ENKO_TYPE_CHILD_FADO && pthis->unk_1E8.unk_00 != 0 && pthis->actor.textId == 0x10B9) {
        func_80034EC0(&pthis->skelAnime, sOsAnimeTable, 7);
        pthis->actionFunc = func_80A99438;
    } else if (ENKO_TYPE == ENKO_TYPE_CHILD_FADO && pthis->unk_1E8.unk_00 == 2) {
        pthis->actionFunc = func_80A99504;
        globalCtx->msgCtx.stateTimer = 4;
        globalCtx->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
    }
}

void func_80A99438(EnKo* pthis, GlobalContext* globalCtx) {
    if (ENKO_TYPE == ENKO_TYPE_CHILD_FADO && pthis->unk_1E8.unk_00 == 2) {
        func_80034EC0(&pthis->skelAnime, sOsAnimeTable, 6);
        pthis->actionFunc = func_80A99504;
        globalCtx->msgCtx.stateTimer = 4;
        globalCtx->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
    } else if (pthis->unk_1E8.unk_00 == 0 || pthis->actor.textId != 0x10B9) {
        func_80034EC0(&pthis->skelAnime, sOsAnimeTable, 6);
        pthis->actionFunc = func_80A99384;
    }
}

void func_80A99504(EnKo* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = func_80A99560;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_SAW, 120.0f, 10.0f);
    }
}

void func_80A99560(EnKo* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1E8.unk_00 == 3) {
        pthis->actor.textId = 0x10B9;
        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
        pthis->unk_1E8.unk_00 = 1;
        gSaveContext.itemGetInf[3] |= 2;
        pthis->actionFunc = func_80A99384;
    }
}

void func_80A995CC(EnKo* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 temp_f2;
    f32 phi_f0;
    s16 homeYawToPlayer = Math_Vec3f_Yaw(&pthis->actor.home.pos, &player->actor.world.pos);

    pthis->actor.world.pos.x = pthis->actor.home.pos.x;
    pthis->actor.world.pos.x += 80.0f * Math_SinS(homeYawToPlayer);
    pthis->actor.world.pos.z = pthis->actor.home.pos.z;
    pthis->actor.world.pos.z += 80.0f * Math_CosS(homeYawToPlayer);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

    if (pthis->unk_1E8.unk_00 == 0 || !pthis->actor.isTargeted) {
        temp_f2 = fabsf((f32)pthis->actor.yawTowardsPlayer - homeYawToPlayer) * 0.001f * 3.0f;
        if (temp_f2 < 1.0f) {
            pthis->skelAnime.playSpeed = 1.0f;
        } else {
            phi_f0 = CLAMP_MAX(temp_f2, 3.0f);
            pthis->skelAnime.playSpeed = phi_f0;
        }
    } else {
        pthis->skelAnime.playSpeed = 1.0f;
    }
}

void EnKo_Update(Actor* thisx, GlobalContext* globalCtx) {
    ColliderCylinder* collider;
    EnKo* pthis = (EnKo*)thisx;
    s32 pad;

    if (pthis->actionFunc != func_80A99048) {
        if ((s32)pthis->modelAlpha != 0) {
            gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->osAnimeBankIndex].vromStart.get());
            SkelAnime_Update(&pthis->skelAnime);
            func_80A98DB4(pthis, globalCtx);
            EnKo_Blink(pthis);
        } else {
            func_80A98DB4(pthis, globalCtx);
        }
    }
    if (pthis->unk_1E8.unk_00 == 0) {
        Actor_MoveForward(&pthis->actor);
    }
    if (func_80A97C7C(pthis)) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
        pthis->actor.gravity = -1.0f;
    } else {
        pthis->actor.gravity = 0.0f;
    }
    pthis->actionFunc(pthis, globalCtx);
    func_80A9877C(pthis, globalCtx);
    collider = &pthis->collider;
    Collider_UpdateCylinder(&pthis->actor, collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &collider->base);
}

s32 EnKo_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                          Gfx** gfx) {
    EnKo* pthis = (EnKo*)thisx;
    void* eyeTexture;
    Vec3s sp40;
    u8 headId;
    s32 pad;

    if (limbIndex == 15) {
        gSPSegment((*gfx)++, 0x06, gObjectTable[pthis->headObjectBankIdx].vromStart.get());
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->headObjectBankIdx].vromStart.get());

        headId = sModelInfo[ENKO_TYPE].headId;
        *dList = sHead[headId].dList;
        if (sHead[headId].eyeTextures != NULL) {
            eyeTexture = sHead[headId].eyeTextures[pthis->eyeTextureIndex];
            gSPSegment((*gfx)++, 0x0A, SEGMENTED_TO_VIRTUAL(eyeTexture));
        }
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->legsObjectBankIdx].vromStart.get());
    }
    if (limbIndex == 8) {
        sp40 = pthis->unk_1E8.unk_0E;
        Matrix_RotateX(BINANG_TO_RAD(-sp40.y), MTXMODE_APPLY);
        Matrix_RotateZ(BINANG_TO_RAD(sp40.x), MTXMODE_APPLY);
    }
    if (limbIndex == 15) {
        Matrix_Translate(1200.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        sp40 = pthis->unk_1E8.unk_08;
        Matrix_RotateX(BINANG_TO_RAD(sp40.y), MTXMODE_APPLY);
        Matrix_RotateZ(BINANG_TO_RAD(sp40.x), MTXMODE_APPLY);
        Matrix_Translate(-1200.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    }
    if (limbIndex == 8 || limbIndex == 9 || limbIndex == 12) {
        rot->y += Math_SinS(pthis->unk_2E4[limbIndex]) * 200.0f;
        rot->z += Math_CosS(pthis->unk_304[limbIndex]) * 200.0f;
    }
    return false;
}

void EnKo_PostLimbDraw(GlobalContext* globalCtx2, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    GlobalContext* globalCtx = globalCtx2;
    EnKo* pthis = (EnKo*)thisx;
    Vec3f D_80A9A774 = { 0.0f, 0.0f, 0.0f };

    if (limbIndex == 7) {
        gSPSegment((*gfx)++, 0x06, gObjectTable[pthis->bodyObjectBankIdx].vromStart.get());
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->bodyObjectBankIdx].vromStart.get());
    }
    if (limbIndex == 15) {
        Matrix_MultVec3f(&D_80A9A774, &pthis->actor.focus.pos);
    }
}

Gfx* EnKo_SetEnvColor(GraphicsContext* gfxCtx, u8 r, u8 g, u8 b, u8 a) {
    Gfx* dList = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx) * 2);

    gDPSetEnvColor(dList, r, g, b, a);
    gSPEndDisplayList(dList + 1);
    return dList;
}

void EnKo_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnKo* pthis = (EnKo*)thisx;
    Color_RGBA8 tunicColor = sModelInfo[ENKO_TYPE].tunicColor;
    Color_RGBA8 bootsColor = sModelInfo[ENKO_TYPE].bootsColor;

    pthis->actor.shape.shadowAlpha = pthis->modelAlpha;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ko.c", 2095);
    if ((s16)pthis->modelAlpha == 255) {
        gSPSegment(POLY_OPA_DISP++, 0x08,
                   EnKo_SetEnvColor(globalCtx->state.gfxCtx, tunicColor.r, tunicColor.g, tunicColor.b, 255));
        gSPSegment(POLY_OPA_DISP++, 0x09,
                   EnKo_SetEnvColor(globalCtx->state.gfxCtx, bootsColor.r, bootsColor.g, bootsColor.b, 255));
        func_80034BA0(globalCtx, &pthis->skelAnime, EnKo_OverrideLimbDraw, EnKo_PostLimbDraw, &pthis->actor,
                      pthis->modelAlpha);
    } else if ((s16)pthis->modelAlpha != 0) {
        tunicColor.a = pthis->modelAlpha;
        bootsColor.a = pthis->modelAlpha;
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   EnKo_SetEnvColor(globalCtx->state.gfxCtx, tunicColor.r, tunicColor.g, tunicColor.b, tunicColor.a));
        gSPSegment(POLY_XLU_DISP++, 0x09,
                   EnKo_SetEnvColor(globalCtx->state.gfxCtx, bootsColor.r, bootsColor.g, bootsColor.b, bootsColor.a));
        func_80034CC4(globalCtx, &pthis->skelAnime, EnKo_OverrideLimbDraw, EnKo_PostLimbDraw, &pthis->actor,
                      pthis->modelAlpha);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ko.c", 2136);
}

void EnKo_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Ko_InitVars = {
        ACTOR_EN_KO,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnKo),
        (ActorFunc)EnKo_Init,
        (ActorFunc)EnKo_Destroy,
        (ActorFunc)EnKo_Update,
        (ActorFunc)EnKo_Draw,
        (ActorFunc)EnKo_Reset,
    };

    sCylinderInit = {
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
        { 20, 46, 0, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

}
