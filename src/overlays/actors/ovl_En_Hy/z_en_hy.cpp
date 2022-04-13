#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HY_Z_EN_HY_C
#include "actor_common.h"

/*
 * File: z_en_hy.c
 * Overlay: ovl_En_Hy
 * Description: Hylian NPCs
 */

#include "z_en_hy.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_path.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"
#include "objects/object_ahg/object_ahg.h"
#include "objects/object_aob/object_aob.h"
#include "objects/object_bba/object_bba.h"
#include "objects/object_bji/object_bji.h"
#include "objects/object_bob/object_bob.h"
#include "objects/object_boj/object_boj.h"
#include "objects/object_cne/object_cne.h"
#include "objects/object_cob/object_cob.h"
#include "objects/object_os_anime/object_os_anime.h"

#define FLAGS (ACTOR_FLAG_VISIBLE | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnHy_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHy_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnHy_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHy_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHy_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnHy_InitImpl(EnHy* pthis, GlobalContext* globalCtx);
void func_80A7134C(EnHy* pthis, GlobalContext* globalCtx);
void func_80A71530(EnHy* pthis, GlobalContext* globalCtx);
void func_80A711B4(EnHy* pthis, GlobalContext* globalCtx);
void func_80A712C0(EnHy* pthis, GlobalContext* globalCtx);
void func_80A710F8(EnHy* pthis, GlobalContext* globalCtx);
void func_80A7127C(EnHy* pthis, GlobalContext* globalCtx);
void EnHy_DoNothing(EnHy* pthis, GlobalContext* globalCtx);
void func_80A714C4(EnHy* pthis, GlobalContext* globalCtx);

ActorInit En_Hy_InitVars = {
    ACTOR_EN_HY, ACTORCAT_NPC, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(EnHy), (ActorFunc)EnHy_Init, (ActorFunc)EnHy_Destroy, (ActorFunc)EnHy_Update, (ActorFunc)EnHy_Draw, (ActorFunc)EnHy_Reset,
};

static ColliderCylinderInit sColCylInit = {
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
	{0x00000000, 0x00, 0x00},
	{0x00000000, 0x00, 0x00},
	TOUCH_NONE,
	BUMP_NONE,
	OCELEM_ON,
    },
    {20, 46, 0, {0, 0, 0}},
};

static CollisionCheckInfoInit2 sColChkInfoInit = {0, 0, 0, 0, MASS_IMMOVABLE};

// NULL-terminated arrays of eye textures
static void* sEyeTexturesAOB[] = {gDogLadyEyeOpenTex, gDogLadyEyeHalfTex, gDogLadyEyeClosedTex, NULL};
static void* sEyeTexturesAHG7[] = {object_ahg_Tex_00057C, object_ahg_Tex_00067C, object_ahg_Tex_00077C, NULL};
static void* sEyeTexturesBBA[] = {object_bba_Tex_0004C8, NULL};
static void* sEyeTexturesBJI13[] = {object_bji_Tex_0005FC, object_bji_Tex_0009FC, object_bji_Tex_000DFC, NULL};
static void* sEyeTexturesBOJ2[] = {object_boj_Tex_0005FC, object_boj_Tex_0006FC, object_boj_Tex_0007FC, NULL};
static void* sEyeTexturesBOB[] = {object_bob_Tex_0007C8, object_bob_Tex_000FC8, object_bob_Tex_0017C8, NULL};

static EnHyHeadInfo sHeadInfo[] = {
    /* ENHY_HEAD_AOB */ {OBJECT_AOB, gDogLadyHeadDL, sEyeTexturesAOB},
    /* ENHY_HEAD_BOB */ {OBJECT_BOB, object_bob_DL_003B78, sEyeTexturesBOB},
    /* ENHY_HEAD_BOJ_2 */ {OBJECT_BOJ, object_boj_DL_0026F0, sEyeTexturesBOJ2},
    /* ENHY_HEAD_BOJ_3 */ {OBJECT_BOJ, object_boj_DL_0052E0, NULL},
    /* ENHY_HEAD_BOJ_4 */ {OBJECT_BOJ, object_boj_DL_005528, NULL},
    /* ENHY_HEAD_BOJ_5 */ {OBJECT_BOJ, object_boj_DL_005738, NULL},
    /* ENHY_HEAD_BOJ_6 */ {OBJECT_BOJ, object_boj_DL_0059B0, NULL},
    /* ENHY_HEAD_AHG_7 */ {OBJECT_AHG, object_ahg_DL_0030F0, sEyeTexturesAHG7},
    /* ENHY_HEAD_AHG_8 */ {OBJECT_AHG, object_ahg_DL_005508, NULL},
    /* ENHY_HEAD_AHG_9 */ {OBJECT_AHG, object_ahg_DL_005728, NULL},
    /* ENHY_HEAD_BBA */ {OBJECT_BBA, object_bba_DL_002948, sEyeTexturesBBA},
    /* ENHY_HEAD_CNE_11 */ {OBJECT_CNE, object_cne_DL_001300, NULL},
    /* ENHY_HEAD_CNE_12 */ {OBJECT_CNE, object_cne_DL_002860, NULL},
    /* ENHY_HEAD_BJI_13 */ {OBJECT_BJI, object_bji_DL_002560, sEyeTexturesBJI13},
    /* ENHY_HEAD_BJI_14 */ {OBJECT_BJI, object_bji_DL_003F68, NULL},
    /* ENHY_HEAD_COB */ {OBJECT_COB, object_cob_DL_001300, NULL},
};

static EnHySkeletonInfo sSkeletonInfo[] = {
    /* ENHY_SKEL_AOB */ {OBJECT_AOB, &gDogLadySkel},
    /* ENHY_SKEL_BOB */ {OBJECT_BOB, &object_bob_Skel_0000F0},
    /* ENHY_SKEL_BOJ */ {OBJECT_BOJ, &object_boj_Skel_0000F0},
    /* ENHY_SKEL_AHG */ {OBJECT_AHG, &object_ahg_Skel_0000F0},
    /* ENHY_SKEL_BBA */ {OBJECT_BBA, &object_bba_Skel_0000F0},
    /* ENHY_SKEL_CNE */ {OBJECT_CNE, &object_cne_Skel_0000F0},
    /* ENHY_SKEL_BJI */ {OBJECT_BJI, &object_bji_Skel_0000F0},
    /* ENHY_SKEL_COB */ {OBJECT_COB, &object_cob_Skel_0021F8},
};

static struct_80034EC0_Entry sAnimationInfo[] = {
    /* ENHY_ANIM_0 */ {&gObjOsAnim_092C, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_1 */ {&gObjOsAnim_0228, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_2 */ {&gObjOsAnim_4CF4, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_3 */ {&gObjOsAnim_16EC, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_4 */ {&gObjOsAnim_265C, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_5 */ {&gObjOsAnim_42AC, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_6 */ {&gObjOsAnim_28DC, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_7 */ {&gObjOsAnim_2160, 1.0f, 0.0f, -1.0f, 0x00, -10.0f},
    /* ENHY_ANIM_8 */ {&gObjOsAnim_265C, 1.0f, 0.0f, -1.0f, 0x00, -10.0f},
    /* ENHY_ANIM_9 */ {&gObjOsAnim_4E90, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_10 */ {&gObjOsAnim_1E7C, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_11 */ {&gObjOsAnim_0170, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_12 */ {&gObjOsAnim_00B4, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_13 */ {&gObjOsAnim_3D84, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_14 */ {&gObjOsAnim_41F8, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_15 */ {&gObjOsAnim_300C, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_16 */ {&gObjOsAnim_31B0, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_17 */ {&gObjOsAnim_31B0, 1.0f, 0.0f, -1.0f, 0x00, -8.0f},
    /* ENHY_ANIM_18 */ {&gObjOsAnim_2D0C, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_19 */ {&gObjOsAnim_2DC0, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_20 */ {&gObjOsAnim_4408, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_21 */ {&gObjOsAnim_1F18, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_22 */ {&gObjOsAnim_4F28, 1.0f, 0.0f, -1.0f, 0x00, 0.0f},
    /* ENHY_ANIM_23 */ {&gObjOsAnim_33B4, 1.0f, 0.0f, -1.0f, 0x00, -8.0f},
    /* ENHY_ANIM_24 */ {&gObjOsAnim_12E8, 1.0f, 0.0f, -1.0f, 0x00, -8.0f},
    /* ENHY_ANIM_25 */ {&gObjOsAnim_0FE4, 1.0f, 0.0f, -1.0f, 0x00, -8.0f},
    /* ENHY_ANIM_26 */ {&gObjOsAnim_0BFC, 1.0f, 0.0f, -1.0f, 0x00, -8.0f},
};

static EnHyModelInfo sModelInfo[] = {
    /* ENHY_TYPE_AOB */
    {ENHY_HEAD_AOB, ENHY_SKEL_AOB, {255, 255, 255, 255}, ENHY_SKEL_AOB, {255, 255, 255, 255}, ENHY_ANIM_0},
    /* ENHY_TYPE_COB */
    {ENHY_HEAD_COB, ENHY_SKEL_COB, {255, 255, 255, 255}, ENHY_SKEL_COB, {255, 255, 255, 255}, ENHY_ANIM_22},
    /* ENHY_TYPE_AHG_2 */
    {ENHY_HEAD_AHG_7, ENHY_SKEL_AHG, {255, 255, 255, 255}, ENHY_SKEL_AHG, {255, 255, 255, 255}, ENHY_ANIM_1},
    /* ENHY_TYPE_BOJ_3 */
    {ENHY_HEAD_BOJ_3, ENHY_SKEL_BOJ, {255, 255, 255, 0}, ENHY_SKEL_BOJ, {55, 55, 255, 0}, ENHY_ANIM_15},
    /* ENHY_TYPE_AHG_4 */
    {ENHY_HEAD_AHG_8, ENHY_SKEL_AHG, {0, 0, 0, 0}, ENHY_SKEL_AHG, {255, 0, 0, 0}, ENHY_ANIM_11},
    /* ENHY_TYPE_BOJ_5 */
    {ENHY_HEAD_BOJ_4, ENHY_SKEL_BOJ, {50, 80, 0, 0}, ENHY_SKEL_BOJ, {50, 80, 0, 0}, ENHY_ANIM_16},
    /* ENHY_TYPE_BBA */
    {ENHY_HEAD_BBA, ENHY_SKEL_BBA, {255, 255, 255, 255}, ENHY_SKEL_BBA, {255, 255, 255, 255}, ENHY_ANIM_10},
    /* ENHY_TYPE_BJI_7 */
    {ENHY_HEAD_BJI_13, ENHY_SKEL_BJI, {0, 50, 160, 0}, ENHY_SKEL_BJI, {255, 255, 255, 0}, ENHY_ANIM_4},
    /* ENHY_TYPE_CNE_8 */
    {ENHY_HEAD_CNE_11, ENHY_SKEL_CNE, {160, 180, 255, 0}, ENHY_SKEL_CNE, {160, 180, 255, 0}, ENHY_ANIM_9},
    /* ENHY_TYPE_BOJ_9 */
    {ENHY_HEAD_BOJ_2, ENHY_SKEL_BOJ, {220, 0, 80, 0}, ENHY_SKEL_BOJ, {255, 255, 255, 0}, ENHY_ANIM_13},
    /* ENHY_TYPE_BOJ_10 */
    {ENHY_HEAD_BOJ_2, ENHY_SKEL_BOJ, {0, 130, 220, 0}, ENHY_SKEL_BOJ, {255, 255, 255, 0}, ENHY_ANIM_14},
    /* ENHY_TYPE_CNE_11 */
    {ENHY_HEAD_CNE_12, ENHY_SKEL_CNE, {70, 160, 230, 0}, ENHY_SKEL_CNE, {255, 255, 100, 0}, ENHY_ANIM_20},
    /* ENHY_TYPE_BOJ_12 */
    {ENHY_HEAD_BOJ_5, ENHY_SKEL_BOJ, {150, 60, 90, 0}, ENHY_SKEL_BOJ, {255, 240, 150, 0}, ENHY_ANIM_18},
    /* ENHY_TYPE_AHG_13 */
    {ENHY_HEAD_AHG_9, ENHY_SKEL_AHG, {200, 180, 255, 0}, ENHY_SKEL_AHG, {200, 180, 255, 0}, ENHY_ANIM_12},
    /* ENHY_TYPE_BOJ_14 */
    {ENHY_HEAD_BOJ_6, ENHY_SKEL_BOJ, {140, 255, 110, 0}, ENHY_SKEL_BOJ, {255, 255, 255, 0}, ENHY_ANIM_19},
    /* ENHY_TYPE_BJI_15 */
    {ENHY_HEAD_BJI_14, ENHY_SKEL_BJI, {130, 70, 20, 0}, ENHY_SKEL_BJI, {130, 180, 255, 0}, ENHY_ANIM_21},
    /* ENHY_TYPE_BOJ_16 */
    {ENHY_HEAD_BOJ_2, ENHY_SKEL_BOJ, {255, 255, 255, 255}, ENHY_SKEL_BOJ, {255, 255, 255, 255}, ENHY_ANIM_5},
    /* ENHY_TYPE_AHG_17 */
    {ENHY_HEAD_AHG_8, ENHY_SKEL_AHG, {90, 100, 20, 255}, ENHY_SKEL_AHG, {100, 140, 50, 255}, ENHY_ANIM_11},
    /* ENHY_TYPE_BOB_18 */
    {ENHY_HEAD_BOB, ENHY_SKEL_BOB, {255, 255, 255, 255}, ENHY_SKEL_BOB, {255, 255, 255, 255}, ENHY_ANIM_6},
    /* ENHY_TYPE_BJI_19 */
    {ENHY_HEAD_BJI_14, ENHY_SKEL_BJI, {160, 0, 100, 0}, ENHY_SKEL_BJI, {70, 130, 210, 0}, ENHY_ANIM_21},
    /* ENHY_TYPE_AHG_20 */
    {ENHY_HEAD_AHG_9, ENHY_SKEL_AHG, {160, 230, 0, 0}, ENHY_SKEL_AHG, {0, 150, 110, 0}, ENHY_ANIM_12},
};

static EnHyColliderInfo sColliderInfo[] = {
    /* ENHY_TYPE_AOB */ {{0, 0, 4}, 24, 70},
    /* ENHY_TYPE_COB */ {{0, 0, 8}, 28, 62},
    /* ENHY_TYPE_AHG_2 */ {{0, 0, 4}, 20, 60},
    /* ENHY_TYPE_BOJ_3 */ {{0, 0, 2}, 20, 60},
    /* ENHY_TYPE_AHG_4 */ {{0, 0, -2}, 20, 60},
    /* ENHY_TYPE_BOJ_5 */ {{0, 0, 8}, 24, 40},
    /* ENHY_TYPE_BBA */ {{0, 0, 10}, 26, 40},
    /* ENHY_TYPE_BJI_7 */ {{0, 0, 12}, 26, 58},
    /* ENHY_TYPE_CNE_8 */ {{0, 0, 2}, 18, 68},
    /* ENHY_TYPE_BOJ_9 */ {{0, 0, 4}, 20, 60},
    /* ENHY_TYPE_BOJ_10 */ {{0, 0, 4}, 20, 60},
    /* ENHY_TYPE_CNE_11 */ {{0, 0, 6}, 20, 64},
    /* ENHY_TYPE_BOJ_12 */ {{0, 0, 0}, 18, 60},
    /* ENHY_TYPE_AHG_13 */ {{0, 0, 0}, 16, 60},
    /* ENHY_TYPE_BOJ_14 */ {{0, 0, 0}, 16, 64},
    /* ENHY_TYPE_BJI_15 */ {{0, 0, 8}, 20, 58},
    /* ENHY_TYPE_BOJ_16 */ {{4, 0, 0}, 18, 62},
    /* ENHY_TYPE_AHG_17 */ {{4, 0, 0}, 18, 62},
    /* ENHY_TYPE_BOB_18 */ {{0, 0, 8}, 28, 62},
    /* ENHY_TYPE_BJI_19 */ {{0, 0, 0}, 16, 60},
    /* ENHY_TYPE_AHG_20 */ {{0, 0, 8}, 20, 58},
};

static EnHyInit1Info sInit1Info[] = {
    /* ENHY_TYPE_AOB */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_COB */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_AHG_2 */ {0x07, 40.0f, 20.0f},
    /* ENHY_TYPE_BOJ_3 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_AHG_4 */ {0x07, 40.0f, 20.0f},
    /* ENHY_TYPE_BOJ_5 */ {0x08, 0.0f, -20.0f},
    /* ENHY_TYPE_BBA */ {0x09, 20.0f, 0.0f},
    /* ENHY_TYPE_BJI_7 */ {0x09, 20.0f, 0.0f},
    /* ENHY_TYPE_CNE_8 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_BOJ_9 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_BOJ_10 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_CNE_11 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_BOJ_12 */ {0x00, 0.0f, 0.0f},
    /* ENHY_TYPE_AHG_13 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_BOJ_14 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_BJI_15 */ {0x0A, 20.0f, 0.0f},
    /* ENHY_TYPE_BOJ_16 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_AHG_17 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_BOB_18 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_BJI_19 */ {0x06, 20.0f, 10.0f},
    /* ENHY_TYPE_AHG_20 */ {0x0A, 20.0f, 0.0f},
};

static EnHyInit2Info sInit2Info[] = {
    /* ENHY_TYPE_AOB */ {36.0f, {0.0f, 0.0f, 600.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_COB */ {40.0f, {-100.0f, 0.0f, 400.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_AHG_2 */ {22.0f, {0.0f, 0.0f, -200.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BOJ_3 */ {20.0f, {-100.0f, 0.0f, 0.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_AHG_4 */ {22.0f, {0.0f, 0.0f, 0.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BOJ_5 */ {21.0f, {0.0f, 0.0f, 0.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BBA */ {25.0f, {-100.0f, 0.0f, 600.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BJI_7 */ {28.0f, {-100.0f, 0.0f, 800.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_CNE_8 */ {17.0f, {0.0f, 0.0f, 700.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BOJ_9 */ {18.0f, {0.0f, 0.0f, 100.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BOJ_10 */ {18.0f, {0.0f, 0.0f, -200.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_CNE_11 */ {17.0f, {0.0f, 0.0f, 700.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BOJ_12 */ {21.0f, {0.0f, 0.0f, -300.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_AHG_13 */ {20.0f, {0.0f, 0.0f, -200.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BOJ_14 */ {18.0f, {-200.0f, 0.0f, -200.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BJI_15 */ {27.0f, {-100.0f, 0.0f, 800.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BOJ_16 */ {19.0f, {400.0f, 0.0f, 0.0f}, 0.01f, 0x04, 30.0f},
    /* ENHY_TYPE_AHG_17 */ {19.0f, {400.0f, 0.0f, 0.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BOB_18 */ {40.0f, {-100.0f, 0.0f, 400.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_BJI_19 */ {17.0f, {0.0f, 0.0f, 700.0f}, 0.01f, 0x06, 30.0f},
    /* ENHY_TYPE_AHG_20 */ {20.0f, {0.0f, 0.0f, -200.0f}, 0.01f, 0x06, 30.0f},
};

s32 EnHy_FindSkelAndHeadObjects(EnHy* pthis, GlobalContext* globalCtx)
{
	u8 headInfoIndex = sModelInfo[pthis->actor.params & 0x7F].headInfoIndex;
	u8 skelInfoIndex2 = sModelInfo[pthis->actor.params & 0x7F].skelInfoIndex2;
	u8 skelInfoIndex1 = sModelInfo[pthis->actor.params & 0x7F].skelInfoIndex1;

	pthis->objBankIndexSkel1 = Object_GetIndex(&globalCtx->objectCtx, sSkeletonInfo[skelInfoIndex1].objectId);
	if(pthis->objBankIndexSkel1 < 0)
	{
		return false;
	}

	pthis->objBankIndexSkel2 = Object_GetIndex(&globalCtx->objectCtx, sSkeletonInfo[skelInfoIndex2].objectId);
	if(pthis->objBankIndexSkel2 < 0)
	{
		return false;
	}

	pthis->objBankIndexHead = Object_GetIndex(&globalCtx->objectCtx, sHeadInfo[headInfoIndex].objectId);
	if(pthis->objBankIndexHead < 0)
	{
		return false;
	}

	return true;
}

s32 EnHy_AreSkelAndHeadObjectsLoaded(EnHy* pthis, GlobalContext* globalCtx)
{
	if(!Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndexSkel1))
	{
		return false;
	}

	if(!Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndexSkel2))
	{
		return false;
	}

	if(!Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndexHead))
	{
		return false;
	}

	return true;
}

s32 EnHy_FindOsAnimeObject(EnHy* pthis, GlobalContext* globalCtx)
{
	pthis->objBankIndexOsAnime = Object_GetIndex(&globalCtx->objectCtx, OBJECT_OS_ANIME);

	if(pthis->objBankIndexOsAnime < 0)
	{
		return false;
	}

	return true;
}

s32 EnHy_IsOsAnimeObjectLoaded(EnHy* pthis, GlobalContext* globalCtx)
{
	if(!Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndexOsAnime))
	{
		return false;
	}

	return true;
}

void func_80A6F7CC(EnHy* pthis, GlobalContext* globalCtx, s32 getItemId)
{
	pthis->unkGetItemId = getItemId;
	func_8002F434(&pthis->actor, globalCtx, getItemId, pthis->actor.xzDistToPlayer + 1.0f, fabsf(pthis->actor.yDistToPlayer) + 1.0f);
}

u16 func_80A6F810(GlobalContext* globalCtx, Actor* thisx)
{
	Player* player = GET_PLAYER(globalCtx);
	EnHy* pthis = (EnHy*)thisx;
	u16 textId = Text_GetFaceReaction(globalCtx, (pthis->actor.params & 0x7F) + 37);

	if(textId != 0)
	{
		if((pthis->actor.params & 0x7F) == ENHY_TYPE_BOJ_5)
		{
			player->exchangeItemId = EXCH_ITEM_BLUE_FIRE;
		}
		return textId;
	}

	switch(pthis->actor.params & 0x7F)
	{
		case ENHY_TYPE_AOB:
			if(globalCtx->sceneNum == SCENE_KAKARIKO)
			{
				return (pthis->unk_330 & 0x800) ? 0x508D : ((gSaveContext.infTable[12] & 0x800) ? 0x508C : 0x508B);
			}
			else if(globalCtx->sceneNum == SCENE_MARKET_DAY)
			{
				return (gSaveContext.eventInf[3] & 1) ? 0x709B : 0x709C;
			}
			else if(gSaveContext.dogIsLost)
			{
				s16 followingDog = (gSaveContext.dogParams & 0xF00) >> 8;

				if(followingDog != 0)
				{
					pthis->unk_215 = false;
					return (followingDog == 1) ? 0x709F : 0x709E;
				}
				else
				{
					return 0x709D;
				}
			}
			else
			{
				return 0x70A0;
			}
		case ENHY_TYPE_COB:
			if(gSaveContext.eventChkInf[8] & 1)
			{
				return (gSaveContext.infTable[12] & 2) ? 0x7017 : 0x7045;
			}
			else
			{
				return (gSaveContext.infTable[12] & 1) ? 0x7017 : 0x7016;
			}
		case ENHY_TYPE_AHG_2:
			if(globalCtx->sceneNum == SCENE_KAKARIKO)
			{
				return 0x5086;
			}
			else if(globalCtx->sceneNum == SCENE_SPOT01)
			{
				return 0x5085;
			}
			else if(gSaveContext.eventChkInf[8] & 1)
			{
				return (gSaveContext.infTable[12] & 8) ? 0x701A : 0x7047;
			}
			else if(gSaveContext.eventChkInf[1] & 0x10)
			{
				return 0x701A;
			}
			else if(gSaveContext.eventChkInf[1] & 1)
			{
				return 0x701B;
			}
			else if(gSaveContext.infTable[12] & 4)
			{
				return 0x701C;
			}
			else
			{
				return 0x701A;
			}
		case ENHY_TYPE_BOJ_3:
			return (gSaveContext.eventChkInf[8] & 1) ? ((gSaveContext.infTable[12] & 0x10) ? 0x7001 : 0x70EB) : 0x7001;
		case ENHY_TYPE_AHG_4:
			return (gSaveContext.eventChkInf[8] & 1) ? 0x704B : ((gSaveContext.infTable[12] & 0x20) ? 0x7024 : 0x7023);
		case ENHY_TYPE_BOJ_5:
			player->exchangeItemId = EXCH_ITEM_BLUE_FIRE;
			return 0x700C;
		case ENHY_TYPE_BBA:
			return (gSaveContext.eventChkInf[8] & 1) ? 0x704A : ((gSaveContext.infTable[12] & 0x40) ? 0x7022 : 0x7021);
		case ENHY_TYPE_BJI_7:
			if(globalCtx->sceneNum == SCENE_KAKARIKO)
			{
				return 0x5088;
			}
			else if(globalCtx->sceneNum == SCENE_SPOT01)
			{
				return 0x5087;
			}
			else
			{
				return (gSaveContext.eventChkInf[8] & 1) ? 0x704D : ((gSaveContext.infTable[12] & 0x80) ? 0x7028 : 0x7027);
			}
		case ENHY_TYPE_CNE_8:
			if(gSaveContext.eventChkInf[8] & 1)
			{
				return (gSaveContext.infTable[12] & 0x200) ? 0x701E : 0x7048;
			}
			else
			{
				return (gSaveContext.infTable[12] & 0x100) ? 0x701E : 0x701D;
			}
		case ENHY_TYPE_BOJ_9:
			if(globalCtx->sceneNum == SCENE_KAKARIKO)
			{
				return (gSaveContext.eventChkInf[10] & 0x400) ? 0x5082 : 0x5081;
			}
			else if(globalCtx->sceneNum == SCENE_SPOT01)
			{
				return CHECK_QUEST_ITEM(QUEST_MEDALLION_SHADOW) ? 0x5080 : 0x507F;
			}
			else
			{
				return (gSaveContext.eventChkInf[8] & 1) ? 0x7049 : ((gSaveContext.infTable[12] & 0x400) ? 0x7020 : 0x701F);
			}
		case ENHY_TYPE_BOJ_10:
			if(globalCtx->sceneNum == SCENE_LABO)
			{
				return (gSaveContext.eventChkInf[10] & 0x400) ? 0x507E : 0x507D;
			}
			else if(globalCtx->sceneNum == SCENE_SPOT01)
			{
				return CHECK_QUEST_ITEM(QUEST_MEDALLION_SHADOW) ? 0x507C : 0x507B;
			}
			else
			{
				return (gSaveContext.eventChkInf[8] & 1) ? 0x7046 : ((gSaveContext.infTable[12] & 0x2000) ? 0x7019 : 0x7018);
			}
		case ENHY_TYPE_CNE_11:
			return (gSaveContext.infTable[8] & 0x800) ? ((gSaveContext.infTable[12] & 0x1000) ? 0x7014 : 0x70A4) : 0x7014;
		case ENHY_TYPE_BOJ_12:
			if(globalCtx->sceneNum == SCENE_SPOT01)
			{
				return !IS_DAY ? 0x5084 : 0x5083;
			}
			else
			{
				return (gSaveContext.eventChkInf[8] & 1) ? 0x7044 : 0x7015;
			}
		case ENHY_TYPE_AHG_13:
			return 0x7055;
		case ENHY_TYPE_BOJ_14:
			return 0x7089;
		case ENHY_TYPE_BJI_15:
			return 0x708A;
		case ENHY_TYPE_BOJ_16:
			return 0x700E;
		case ENHY_TYPE_AHG_17:
			if(!LINK_IS_ADULT)
			{
				if(IS_DAY)
				{
					return (gSaveContext.infTable[22] & 1) ? 0x5058 : 0x5057;
				}
				else
				{
					return (gSaveContext.infTable[22] & 2) ? 0x505A : 0x5059;
				}
			}
			else if(IS_DAY)
			{
				return (gSaveContext.infTable[22] & 4) ? 0x505C : 0x505B;
			}
			else
			{
				return 0x5058;
			}
		case ENHY_TYPE_BOB_18:
			if(!LINK_IS_ADULT)
			{
				return (gSaveContext.eventChkInf[8] & 1) ? 0x505F : ((gSaveContext.infTable[22] & 8) ? 0x505E : 0x505D);
			}
			else
			{
				return (pthis->unk_330 & 0x800) ? 0x5062 : ((gSaveContext.infTable[22] & 0x10) ? 0x5061 : 0x5060);
			}
		case ENHY_TYPE_BJI_19:
			return 0x7120;
		case ENHY_TYPE_AHG_20:
			return 0x7121;
		default:
			return 0;
	}
}

s16 func_80A70058(GlobalContext* globalCtx, Actor* thisx)
{
	EnHy* pthis = (EnHy*)thisx;
	s16 beggarItems[] = {ITEM_BLUE_FIRE, ITEM_FISH, ITEM_BUG, ITEM_FAIRY};
	s16 beggarRewards[] = {150, 100, 50, 25};

	switch(Message_GetState(&globalCtx->msgCtx))
	{
		case TEXT_STATE_NONE:
		case TEXT_STATE_DONE_HAS_NEXT:
		case TEXT_STATE_CHOICE:
		case TEXT_STATE_DONE:
		case TEXT_STATE_SONG_DEMO_DONE:
		case TEXT_STATE_8:
		case TEXT_STATE_9:
			return 1;
		case TEXT_STATE_DONE_FADING:
			switch(pthis->actor.textId)
			{
				case 0x709E:
				case 0x709F:
					if(!pthis->unk_215)
					{
						Audio_PlaySoundGeneral(pthis->actor.textId == 0x709F ? NA_SE_SY_CORRECT_CHIME : NA_SE_SY_ERROR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
						pthis->unk_215 = true;
					}
					break;
				case 0x70F0:
				case 0x70F1:
				case 0x70F2:
				case 0x70F3:
					if(pthis->skelAnime.animation != &gObjOsAnim_33B4)
					{
						func_80034EC0(&pthis->skelAnime, sAnimationInfo, ENHY_ANIM_23);
						Audio_PlayFanfare(NA_BGM_ITEM_GET | 0x900);
					}
					break;
			}
			return 1;
		case TEXT_STATE_CLOSING:
			switch(pthis->actor.textId)
			{
				case 0x70F0:
				case 0x70F1:
				case 0x70F2:
				case 0x70F3:
					Rupees_ChangeBy(beggarRewards[pthis->actor.textId - 0x70F0]);
					func_80034EC0(&pthis->skelAnime, sAnimationInfo, ENHY_ANIM_17);
					Player_UpdateBottleHeld(globalCtx, GET_PLAYER(globalCtx), ITEM_BOTTLE, PLAYER_AP_BOTTLE);
					break;
				case 0x7016:
					gSaveContext.infTable[12] |= 1;
					break;
				case 0x7045:
					gSaveContext.infTable[12] |= 2;
					break;
				case 0x701B:
					gSaveContext.infTable[12] |= 4;
					break;
				case 0x7047:
					gSaveContext.infTable[12] |= 8;
					break;
				case 0x70EB:
					gSaveContext.infTable[12] |= 0x10;
					break;
				case 0x7023:
					gSaveContext.infTable[12] |= 0x20;
					break;
				case 0x7021:
					gSaveContext.infTable[12] |= 0x40;
					break;
				case 0x7027:
					gSaveContext.infTable[12] |= 0x80;
					break;
				case 0x701D:
					gSaveContext.infTable[12] |= 0x100;
					break;
				case 0x7048:
					gSaveContext.infTable[12] |= 0x200;
					break;
				case 0x701F:
					gSaveContext.infTable[12] |= 0x400;
					break;
				case 0x7018:
					gSaveContext.infTable[12] |= 0x2000;
					break;
				case 0x70A4:
					gSaveContext.infTable[12] |= 0x1000;
					break;
				case 0x5057:
					gSaveContext.infTable[22] |= 1;
					break;
				case 0x5059:
					gSaveContext.infTable[22] |= 2;
					break;
				case 0x505B:
					gSaveContext.infTable[22] |= 4;
					break;
				case 0x505D:
					gSaveContext.infTable[22] |= 8;
					break;
				case 0x5060:
					gSaveContext.infTable[22] |= 0x10;
					break;
				case 0x508B:
					gSaveContext.infTable[12] |= 0x800;
					break;
				case 0x709E:
					gSaveContext.dogParams = 0;
					break;
				case 0x709F:
					func_80A6F7CC(pthis, globalCtx, (gSaveContext.infTable[25] & 2) ? GI_RUPEE_BLUE : GI_HEART_PIECE);
					pthis->actionFunc = func_80A714C4;
					break;
			}
			return 0;
		case TEXT_STATE_EVENT:
			if(!Message_ShouldAdvance(globalCtx))
			{
				return 1;
			}
			else
			{
				return 2;
			}
	}

	return 1;
}

void EnHy_UpdateEyes(EnHy* pthis)
{
	if(DECR(pthis->nextEyeIndexTimer) == 0)
	{
		u8 headInfoIndex = sModelInfo[pthis->actor.params & 0x7F].headInfoIndex;

		pthis->curEyeIndex++;
		if((sHeadInfo[headInfoIndex].eyeTextures != NULL) && (sHeadInfo[headInfoIndex].eyeTextures[pthis->curEyeIndex] == NULL))
		{
			pthis->nextEyeIndexTimer = Rand_S16Offset(30, 30);
			pthis->curEyeIndex = 0;
		}
	}
}

void EnHy_InitCollider(EnHy* pthis)
{
	u8 type = pthis->actor.params & 0x7F;

	pthis->collider.dim.radius = sColliderInfo[type].radius;
	pthis->collider.dim.height = sColliderInfo[type].height;
}

void EnHy_InitSetProperties(EnHy* pthis)
{
	u8 type = pthis->actor.params & 0x7F;

	pthis->actor.shape.shadowScale = sInit2Info[type].shadowScale;
	Actor_SetScale(&pthis->actor, sInit2Info[type].scale);
	pthis->actor.targetMode = sInit2Info[type].targetMode;
	pthis->modelOffset = sInit2Info[type].modelOffset;
	pthis->unkRange = sInit2Info[type].unkRange;
	pthis->unkRange += pthis->collider.dim.radius;
}

void EnHy_UpdateCollider(EnHy* pthis, GlobalContext* globalCtx)
{
	Vec3s pos;

	pos.x = pthis->actor.world.pos.x;
	pos.y = pthis->actor.world.pos.y;
	pos.z = pthis->actor.world.pos.z;
	pos.x += sColliderInfo[pthis->actor.params & 0x7F].offset.x;
	pos.y += sColliderInfo[pthis->actor.params & 0x7F].offset.y;
	pos.z += sColliderInfo[pthis->actor.params & 0x7F].offset.z;
	pthis->collider.dim.pos = pos;
	CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void func_80A70834(EnHy* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);

	if((pthis->actor.params & 0x7F) == ENHY_TYPE_BOJ_5)
	{
		if(!Inventory_HasSpecificBottle(ITEM_BLUE_FIRE) && !Inventory_HasSpecificBottle(ITEM_BUG) && !Inventory_HasSpecificBottle(ITEM_FISH))
		{
			switch(func_8002F368(globalCtx))
			{
				case EXCH_ITEM_POE:
				case EXCH_ITEM_BIG_POE:
				case EXCH_ITEM_LETTER_RUTO:
					pthis->actor.textId = 0x70EF;
					break;
				default:
					if(Player_GetMask(globalCtx) == PLAYER_MASK_NONE)
					{
						pthis->actor.textId = 0x70ED;
					}
					break;
			}
		}
		else
		{
			switch(func_8002F368(globalCtx))
			{
				case EXCH_ITEM_BLUE_FIRE:
					pthis->actor.textId = 0x70F0;
					break;
				case EXCH_ITEM_FISH:
					pthis->actor.textId = 0x70F1;
					break;
				case EXCH_ITEM_BUG:
					pthis->actor.textId = 0x70F2;
					break;
				default:
					if(Player_GetMask(globalCtx) == PLAYER_MASK_NONE)
					{
						pthis->actor.textId = 0x700C;
					}
					break;
			}
		}

		player->actor.textId = pthis->actor.textId;
	}
}

void func_80A70978(EnHy* pthis, GlobalContext* globalCtx)
{
	Player* player = GET_PLAYER(globalCtx);
	s16 phi_a3;

	switch(pthis->actor.params & 0x7F)
	{
		case ENHY_TYPE_BOJ_3:
		case ENHY_TYPE_BJI_7:
		case ENHY_TYPE_BOJ_9:
		case ENHY_TYPE_BOJ_10:
			phi_a3 = (pthis->unk_1E8.unk_00 == 0) ? 1 : 2;
			break;
		case ENHY_TYPE_BOJ_12:
			phi_a3 = 1;
			break;
		case ENHY_TYPE_AHG_2:
		case ENHY_TYPE_AHG_17:
			phi_a3 = 4;
			break;
		case ENHY_TYPE_AOB:
		case ENHY_TYPE_BOB_18:
			phi_a3 = (pthis->unk_1E8.unk_00 == 0) ? 2 : 4;
			break;
		default:
			phi_a3 = 2;
			break;
	}

	pthis->unk_1E8.position = player->actor.world.pos;

	if(LINK_IS_ADULT)
	{
		pthis->unk_1E8.height = sInit1Info[pthis->actor.params & 0x7F].unkValueAdult;
	}
	else
	{
		pthis->unk_1E8.height = sInit1Info[pthis->actor.params & 0x7F].unkValueChild;
	}

	func_80034A14(&pthis->actor, &pthis->unk_1E8, sInit1Info[pthis->actor.params & 0x7F].unkPresetIndex, phi_a3);

	if(func_800343CC(globalCtx, &pthis->actor, &pthis->unk_1E8.unk_00, pthis->unkRange, func_80A6F810, func_80A70058))
	{
		func_80A70834(pthis, globalCtx);
	}
}

s32 EnHy_ShouldSpawn(EnHy* pthis, GlobalContext* globalCtx)
{
	switch(globalCtx->sceneNum)
	{
		case SCENE_SPOT01:
			if(!((pthis->actor.params & 0x7F) == ENHY_TYPE_BOJ_9 || (pthis->actor.params & 0x7F) == ENHY_TYPE_BOJ_10 || (pthis->actor.params & 0x7F) == ENHY_TYPE_BOJ_12 || (pthis->actor.params & 0x7F) == ENHY_TYPE_AHG_2 ||
			     (pthis->actor.params & 0x7F) == ENHY_TYPE_BJI_7))
			{
				return true;
			}
			else if(!LINK_IS_ADULT)
			{
				return true;
			}
			else if((pthis->actor.params & 0x7F) != ENHY_TYPE_BOJ_12 && IS_NIGHT)
			{
				return false;
			}
			else
			{
				return true;
			}
		case SCENE_LABO:
			if((pthis->actor.params & 0x7F) != ENHY_TYPE_BOJ_10)
			{
				return true;
			}
			else if(LINK_IS_CHILD)
			{
				return false;
			}
			else if((pthis->actor.params & 0x7F) == ENHY_TYPE_BOJ_10 && IS_DAY)
			{
				return false;
			}
			else
			{
				return true;
			}
		case SCENE_IMPA:
			if((pthis->actor.params & 0x7F) != ENHY_TYPE_AOB)
			{
				return true;
			}
			else if(IS_DAY)
			{
				return false;
			}
			else
			{
				return true;
			}
		case SCENE_KAKARIKO:
			if((pthis->actor.params & 0x7F) == ENHY_TYPE_AOB)
			{
				return !LINK_IS_ADULT ? false : true;
			}
			else if(!((pthis->actor.params & 0x7F) == ENHY_TYPE_BOJ_9 || (pthis->actor.params & 0x7F) == ENHY_TYPE_AHG_2 || (pthis->actor.params & 0x7F) == ENHY_TYPE_BJI_7))
			{
				return true;
			}
			else if(IS_DAY)
			{
				return false;
			}
			else if(LINK_IS_CHILD)
			{
				return false;
			}
			else
			{
				return true;
			}
		case SCENE_MARKET_ALLEY:
		case SCENE_MARKET_ALLEY_N:
			if((pthis->actor.params & 0x7F) != ENHY_TYPE_BOJ_14)
			{
				return true;
			}
			else if(IS_NIGHT)
			{
				return false;
			}
			else if((gSaveContext.eventChkInf[8] & 1) && !(gSaveContext.eventChkInf[4] & 0x20))
			{
				return false;
			}
			else
			{
				return true;
			}
		default:
			switch(pthis->actor.params & 0x7F)
			{
				case ENHY_TYPE_BJI_19:
				case ENHY_TYPE_AHG_20:
					if(LINK_IS_ADULT)
					{
						return false;
					}
			}
			return true;
	}
}

void EnHy_Init(Actor* thisx, GlobalContext* globalCtx)
{
	EnHy* pthis = (EnHy*)thisx;

	if((pthis->actor.params & 0x7F) >= ENHY_TYPE_MAX || !EnHy_FindOsAnimeObject(pthis, globalCtx) || !EnHy_FindSkelAndHeadObjects(pthis, globalCtx))
	{
		Actor_Kill(&pthis->actor);
	}

	if(!EnHy_ShouldSpawn(pthis, globalCtx))
	{
		Actor_Kill(&pthis->actor);
	}

	pthis->actionFunc = EnHy_InitImpl;
}

void EnHy_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	EnHy* pthis = (EnHy*)thisx;

	Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnHy_InitImpl(EnHy* pthis, GlobalContext* globalCtx)
{
	if(EnHy_IsOsAnimeObjectLoaded(pthis, globalCtx) && EnHy_AreSkelAndHeadObjectsLoaded(pthis, globalCtx))
	{
		pthis->actor.objBankIndex = pthis->objBankIndexSkel1;
		gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->actor.objBankIndex].vromStart.get());
		SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, sSkeletonInfo[sModelInfo[pthis->actor.params & 0x7F].skelInfoIndex1].skeleton, NULL, pthis->jointTable, pthis->morphTable, 16);
		ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
		gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objBankIndexOsAnime].vromStart.get());
		Collider_InitCylinder(globalCtx, &pthis->collider);
		Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sColCylInit);
		EnHy_InitCollider(pthis);
		CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
		func_80034EC0(&pthis->skelAnime, sAnimationInfo, sModelInfo[pthis->actor.params & 0x7F].animInfoIndex);

		if((globalCtx->sceneNum == SCENE_MARKET_ALLEY) || (globalCtx->sceneNum == SCENE_MARKET_DAY))
		{
			pthis->actor.flags &= ~ACTOR_FLAG_4;
			pthis->actor.uncullZoneScale = 0.0f;
		}

		if(globalCtx->sceneNum == SCENE_KAKARIKO)
		{
			pthis->unk_330 = gSaveContext.eventChkInf[6];
		}

		EnHy_InitSetProperties(pthis);
		pthis->path = Path_GetByIndex(globalCtx, (pthis->actor.params & 0x780) >> 7, 15);

		switch(pthis->actor.params & 0x7F)
		{
			case ENHY_TYPE_BOJ_3:
				if(pthis->path != NULL)
				{
					pthis->actor.speedXZ = 3.0f;
				}
				pthis->actionFunc = func_80A711B4;
				break;
			case ENHY_TYPE_BJI_7:
				pthis->pathReverse = false;
				pthis->actionFunc = func_80A712C0;
				break;
			case ENHY_TYPE_AOB:
				if(globalCtx->sceneNum == SCENE_MARKET_DAY)
				{
					pthis->actionFunc = func_80A710F8;
					break;
				}
				// fall-through
			case ENHY_TYPE_COB:
			case ENHY_TYPE_AHG_2:
			case ENHY_TYPE_AHG_4:
			case ENHY_TYPE_BBA:
			case ENHY_TYPE_CNE_8:
			case ENHY_TYPE_AHG_13:
			case ENHY_TYPE_BOJ_14:
			case ENHY_TYPE_BJI_15:
			case ENHY_TYPE_BOJ_16:
			case ENHY_TYPE_AHG_17:
			case ENHY_TYPE_BOB_18:
			case ENHY_TYPE_BJI_19:
			case ENHY_TYPE_AHG_20:
				pthis->actionFunc = func_80A7127C;
				break;
			case ENHY_TYPE_BOJ_5:
			case ENHY_TYPE_BOJ_9:
			case ENHY_TYPE_BOJ_10:
			case ENHY_TYPE_CNE_11:
			case ENHY_TYPE_BOJ_12:
				pthis->actionFunc = EnHy_DoNothing;
				break;
			default:
				Actor_Kill(&pthis->actor);
				break;
		}
	}
}

void func_80A710F8(EnHy* pthis, GlobalContext* globalCtx)
{
	if(pthis->unk_1E8.unk_00 != 0)
	{
		if(pthis->skelAnime.animation != &gObjOsAnim_0BFC)
		{
			func_80034EC0(&pthis->skelAnime, sAnimationInfo, ENHY_ANIM_26);
		}
	}
	else if(gSaveContext.eventInf[3] & 1)
	{
		if(pthis->skelAnime.animation != &gObjOsAnim_0FE4)
		{
			func_80034EC0(&pthis->skelAnime, sAnimationInfo, ENHY_ANIM_25);
		}
	}
	else if(pthis->skelAnime.animation != &gObjOsAnim_12E8)
	{
		func_80034EC0(&pthis->skelAnime, sAnimationInfo, ENHY_ANIM_24);
	}
}

void func_80A711B4(EnHy* pthis, GlobalContext* globalCtx)
{
	s16 yaw;
	f32 distSq;

	distSq = Path_OrientAndGetDistSq(&pthis->actor, pthis->path, pthis->waypoint, &yaw);
	Math_SmoothStepToS(&pthis->actor.world.rot.y, yaw, 10, 1000, 1);
	pthis->actor.shape.rot = pthis->actor.world.rot;

	if((distSq > 0.0f) && (distSq < 1000.0f))
	{
		pthis->waypoint++;
		if(pthis->waypoint > (pthis->path->count - 1))
		{
			pthis->waypoint = 0;
		}
	}
}

void func_80A7127C(EnHy* pthis, GlobalContext* globalCtx)
{
	func_80034F54(globalCtx, pthis->unk_21C, pthis->unk_23C, 16);
}

void EnHy_DoNothing(EnHy* pthis, GlobalContext* globalCtx)
{
}

void func_80A712C0(EnHy* pthis, GlobalContext* globalCtx)
{
	if((pthis->actor.xzDistToPlayer <= 100.0f) && (pthis->path != NULL))
	{
		func_80034EC0(&pthis->skelAnime, sAnimationInfo, ENHY_ANIM_7);
		pthis->actor.speedXZ = 0.4f;
		pthis->actionFunc = func_80A7134C;
	}

	func_80034F54(globalCtx, pthis->unk_21C, pthis->unk_23C, 16);
}

void func_80A7134C(EnHy* pthis, GlobalContext* globalCtx)
{
	s16 yaw;
	f32 distSq;

	if((pthis->skelAnime.animation == &gObjOsAnim_2160) && (pthis->unk_1E8.unk_00 != 0))
	{
		func_80034EC0(&pthis->skelAnime, sAnimationInfo, ENHY_ANIM_8);
	}

	if((pthis->skelAnime.animation == &gObjOsAnim_265C) && (pthis->unk_1E8.unk_00 == 0))
	{
		func_80034EC0(&pthis->skelAnime, sAnimationInfo, ENHY_ANIM_7);
	}

	pthis->actor.speedXZ = 0.4f;
	distSq = Path_OrientAndGetDistSq(&pthis->actor, pthis->path, pthis->waypoint, &yaw);
	Math_SmoothStepToS(&pthis->actor.world.rot.y, yaw, 10, 1000, 1);
	pthis->actor.shape.rot = pthis->actor.world.rot;

	if(!(distSq <= 0.0f) && !(distSq >= 1000.0f))
	{
		if(!pthis->pathReverse)
		{
			pthis->waypoint++;
			if(pthis->waypoint > (pthis->path->count - 1))
			{
				pthis->pathReverse = true;
				pthis->waypoint = pthis->path->count - 2;
			}
		}
		else
		{
			pthis->waypoint--;
			if(pthis->waypoint < 0)
			{
				pthis->pathReverse = false;
				pthis->waypoint = 1;
			}
		}
	}
}

void func_80A714C4(EnHy* pthis, GlobalContext* globalCtx)
{
	if(Actor_HasParent(&pthis->actor, globalCtx))
	{
		pthis->actionFunc = func_80A71530;
	}
	else
	{
		func_8002F434(&pthis->actor, globalCtx, pthis->unkGetItemId, pthis->actor.xzDistToPlayer + 1.0f, fabsf(pthis->actor.yDistToPlayer) + 1.0f);
	}
}

void func_80A71530(EnHy* pthis, GlobalContext* globalCtx)
{
	if((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx))
	{
		switch(pthis->unkGetItemId)
		{
			case GI_HEART_PIECE:
				gSaveContext.dogParams = 0;
				gSaveContext.dogIsLost = false;
				gSaveContext.infTable[25] |= 2;
				break;
			case GI_RUPEE_BLUE:
				Rupees_ChangeBy(5);
				gSaveContext.dogParams = 0;
				gSaveContext.dogIsLost = false;
				break;
		}

		pthis->actionFunc = func_80A7127C;
	}
}

void EnHy_Update(Actor* thisx, GlobalContext* globalCtx)
{
	EnHy* pthis = (EnHy*)thisx;

	if(pthis->actionFunc != EnHy_InitImpl)
	{
		gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objBankIndexOsAnime].vromStart.get());
		SkelAnime_Update(&pthis->skelAnime);
		EnHy_UpdateEyes(pthis);

		if(pthis->unk_1E8.unk_00 == 0)
		{
			Actor_MoveForward(&pthis->actor);
		}

		Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
	}

	pthis->actionFunc(pthis, globalCtx);
	func_80A70978(pthis, globalCtx);
	EnHy_UpdateCollider(pthis, globalCtx);
}

s32 EnHy_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx)
{
	EnHy* pthis = (EnHy*)thisx;
	s32 pad;
	Vec3s sp48;
	u8 i;
	UNK_PTR ptr;

	if(1)
	{
	}

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_hy.c", 2170);

	if(limbIndex == 15)
	{
		gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->objBankIndexHead].vromStart.get());
		gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objBankIndexHead].vromStart.get());
		i = sModelInfo[pthis->actor.params & 0x7F].headInfoIndex;
		*dList = sHeadInfo[i].headDList;

		if(sHeadInfo[i].eyeTextures != NULL)
		{
			ptr = sHeadInfo[i].eyeTextures[pthis->curEyeIndex];
			gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(ptr));
		}

		gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objBankIndexSkel1].vromStart.get());
	}

	if(limbIndex == 15)
	{
		Matrix_Translate(1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
		sp48 = pthis->unk_1E8.unk_08;
		Matrix_RotateX((sp48.y / (f32)0x8000) * M_PI, MTXMODE_APPLY);
		Matrix_RotateZ((sp48.x / (f32)0x8000) * M_PI, MTXMODE_APPLY);
		Matrix_Translate(-1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
	}

	if(limbIndex == 8)
	{
		sp48 = pthis->unk_1E8.unk_0E;
		Matrix_RotateX((-sp48.y / (f32)0x8000) * M_PI, MTXMODE_APPLY);
		Matrix_RotateZ((sp48.x / (f32)0x8000) * M_PI, MTXMODE_APPLY);
	}

	if((limbIndex == 8) || (limbIndex == 9) || (limbIndex == 12))
	{
		rot->y += Math_SinS(pthis->unk_21C[limbIndex]) * 200.0f;
		rot->z += Math_CosS(pthis->unk_23C[limbIndex]) * 200.0f;
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_hy.c", 2228);

	return false;
}

void EnHy_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx)
{
	EnHy* pthis = (EnHy*)thisx;
	s32 pad;
	Vec3f sp3C = {400.0f, 0.0f, 0.0f};

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_hy.c", 2255);

	if(limbIndex == 7)
	{
		gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->objBankIndexSkel2].vromStart.get());
		gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objBankIndexSkel2].vromStart.get());
	}

	if((pthis->actor.params & 0x7F) == ENHY_TYPE_BOJ_3 && limbIndex == 8)
	{
		gSPDisplayList(POLY_OPA_DISP++, object_boj_DL_005BC8);
	}

	if(limbIndex == 15)
	{
		Matrix_MultVec3f(&sp3C, &pthis->actor.focus.pos);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_hy.c", 2281);
}

Gfx* EnHy_SetEnvColor(GraphicsContext* globalCtx, u8 envR, u8 envG, u8 envB, u8 envA)
{
	Gfx* dList = (Gfx*)Graph_Alloc(globalCtx, 2 * sizeof(Gfx));
	gDPSetEnvColor(dList, envR, envG, envB, envA);
	gSPEndDisplayList(dList + 1);

	return dList;
}

void EnHy_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	EnHy* pthis = (EnHy*)thisx;
	Color_RGBA8 envColorSeg8;
	Color_RGBA8 envColorSeg9;
	Color_RGBA8 envColorSeg10;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_en_hy.c", 2318);

	if(pthis->actionFunc != EnHy_InitImpl)
	{
		func_80093D18(globalCtx->gfxCtx);
		Matrix_Translate(pthis->modelOffset.x, pthis->modelOffset.y, pthis->modelOffset.z, MTXMODE_APPLY);
		envColorSeg8 = sModelInfo[pthis->actor.params & 0x7F].envColorSeg8;
		envColorSeg9 = sModelInfo[pthis->actor.params & 0x7F].envColorSeg9;

		switch(pthis->actor.params & 0x7F)
		{
			// ENHY_TYPE_AOB
			// ENHY_TYPE_COB
			case ENHY_TYPE_AHG_2:
			case ENHY_TYPE_BOJ_3:
			case ENHY_TYPE_AHG_4:
			case ENHY_TYPE_BOJ_5:
			// ENHY_TYPE_BBA
			case ENHY_TYPE_BJI_7:
			case ENHY_TYPE_CNE_8:
			case ENHY_TYPE_BOJ_9:
			case ENHY_TYPE_BOJ_10:
			case ENHY_TYPE_CNE_11:
			case ENHY_TYPE_BOJ_12:
			case ENHY_TYPE_AHG_13:
			case ENHY_TYPE_BOJ_14:
			case ENHY_TYPE_BJI_15:
			case ENHY_TYPE_BOJ_16:
			case ENHY_TYPE_AHG_17:
			// ENHY_TYPE_BOB_18
			case ENHY_TYPE_BJI_19:
			case ENHY_TYPE_AHG_20:
				gSPSegment(POLY_OPA_DISP++, 0x08, EnHy_SetEnvColor(globalCtx->gfxCtx, envColorSeg8.r, envColorSeg8.g, envColorSeg8.b, envColorSeg8.a));
				gSPSegment(POLY_OPA_DISP++, 0x09, EnHy_SetEnvColor(globalCtx->gfxCtx, envColorSeg9.r, envColorSeg9.g, envColorSeg9.b, envColorSeg9.a));

				if((pthis->actor.params & 0x7F) == ENHY_TYPE_CNE_8 || (pthis->actor.params & 0x7F) == ENHY_TYPE_CNE_11)
				{
					if((pthis->actor.params & 0x7F) == ENHY_TYPE_CNE_8)
					{
						envColorSeg10 = envColorSeg8;
					}
					if((pthis->actor.params & 0x7F) == ENHY_TYPE_CNE_11)
					{
						envColorSeg10.r = envColorSeg10.g = envColorSeg10.b = 255;
						envColorSeg10.a = 0;
					}
					gSPSegment(POLY_OPA_DISP++, 0x0A, EnHy_SetEnvColor(globalCtx->gfxCtx, envColorSeg10.r, envColorSeg10.g, envColorSeg10.b, envColorSeg10.a));
				}
				break;
		}

		SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount, EnHy_OverrideLimbDraw, EnHy_PostLimbDraw, &pthis->actor);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_en_hy.c", 2388);
}

void EnHy_Reset(Actor* pthisx, GlobalContext* globalCtx)
{
	En_Hy_InitVars = {
	    ACTOR_EN_HY, ACTORCAT_NPC, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(EnHy), (ActorFunc)EnHy_Init, (ActorFunc)EnHy_Destroy, (ActorFunc)EnHy_Update, (ActorFunc)EnHy_Draw, (ActorFunc)EnHy_Reset,
	};

	sColCylInit = {
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
		{0x00000000, 0x00, 0x00},
		{0x00000000, 0x00, 0x00},
		TOUCH_NONE,
		BUMP_NONE,
		OCELEM_ON,
	    },
	    {20, 46, 0, {0, 0, 0}},
	};

	sColChkInfoInit = {0, 0, 0, 0, MASS_IMMOVABLE};
}
