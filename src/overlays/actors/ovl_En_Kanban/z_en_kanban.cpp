#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_KANBAN_Z_EN_KANBAN_C
#include "actor_common.h"
/*
 * File: z_en_kanban.c
 * Overlay: ovl_En_Kanban
 * Description: Cuttable square sign
 */

#include "z_en_kanban.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_kanban/object_kanban.h"
#include "vt.h"
#include "hack.h"
#include "def/code_800F7260.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

#define PART_UPPER_LEFT (1 << 0)
#define PART_LEFT_UPPER (1 << 1)
#define PART_LEFT_LOWER (1 << 2)
#define PART_RIGHT_UPPER (1 << 3)
#define PART_RIGHT_LOWER (1 << 4)
#define PART_LOWER_LEFT (1 << 5)
#define PART_UPPER_RIGHT (1 << 6)
#define PART_LOWER_RIGHT (1 << 7)
#define PART_POST_UPPER (1 << 8)
#define PART_POST_LOWER (1 << 9)
#define PART_POST_STAND (1 << 10)
#define LEFT_HALF (PART_UPPER_LEFT | PART_LEFT_UPPER | PART_LEFT_LOWER | PART_LOWER_LEFT)
#define RIGHT_HALF (PART_UPPER_RIGHT | PART_RIGHT_UPPER | PART_RIGHT_LOWER | PART_LOWER_RIGHT)
#define UPPER_HALF (PART_POST_UPPER | PART_UPPER_RIGHT | PART_RIGHT_UPPER | PART_UPPER_LEFT | PART_LEFT_UPPER)
#define UPPERLEFT_HALF (PART_POST_UPPER | PART_UPPER_RIGHT | PART_LEFT_LOWER | PART_UPPER_LEFT | PART_LEFT_UPPER)
#define UPPERRIGHT_HALF (PART_POST_UPPER | PART_UPPER_RIGHT | PART_RIGHT_UPPER | PART_UPPER_LEFT | PART_RIGHT_LOWER)
#define ALL_PARTS (LEFT_HALF | RIGHT_HALF | PART_POST_UPPER | PART_POST_LOWER)


void EnKanban_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKanban_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnKanban_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKanban_Update(Actor* thisx, GlobalContext* globalCtx);
void EnKanban_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Kanban_InitVars = {
    ACTOR_EN_KANBAN,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_KANBAN,
    sizeof(EnKanban),
    (ActorFunc)EnKanban_Init,
    (ActorFunc)EnKanban_Destroy,
    (ActorFunc)EnKanban_Update,
    (ActorFunc)EnKanban_Draw,
    (ActorFunc)EnKanban_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 50, 5, { 0, 0, 0 } },
};

static u16 sPartFlags[] = {
    PART_UPPER_LEFT,  PART_LEFT_UPPER,  PART_LEFT_LOWER, PART_RIGHT_UPPER, PART_RIGHT_LOWER, PART_LOWER_LEFT,
    PART_UPPER_RIGHT, PART_LOWER_RIGHT, PART_POST_UPPER, PART_POST_LOWER,  PART_POST_STAND,
};

static Vec3f sPieceOffsets[] = {
    /* WHOLE_SIGN   */ { 0.0f, 44.0f, 0.0f },
    /* UPPER_HALF   */ { 0.0f, 50.0f, 0.0f },
    /* LOWER_HALF   */ { 0.0f, 38.0f, 0.0f },
    /* RIGHT_HALF  */ { 10.0f, 44.0f, 0.0f },
    /* LEFT_HALF  */ { -10.0f, 44.0f, 0.0f },
    /* 2ND_QUAD   */ { -10.0f, 50.0f, 0.0f },
    /* 1ST_QUAD    */ { 10.0f, 50.0f, 0.0f },
    /* 3RD_QUAD   */ { -10.0f, 38.0f, 0.0f },
    /* 4TH_QUAD    */ { 10.0f, 38.0f, 0.0f },
    /* UPPER_LEFT  */ { -7.5f, 51.0f, 0.0f },
    /* LEFT_UPPER */ { -12.5f, 48.0f, 0.0f },
    /* LEFT_LOWER */ { -12.5f, 40.0f, 0.0f },
    /* LOWER_LEFT  */ { -7.5f, 37.0f, 0.0f },
    /* UPPER_RIGHT  */ { 7.5f, 51.0f, 0.0f },
    /* RIGHT_UPPER */ { 12.5f, 48.0f, 0.0f },
    /* RIGHT_LOWER */ { 12.5f, 40.0f, 0.0f },
    /* LOWER_RIGHT  */ { 7.5f, 37.0f, 0.0f },
    /* POST_UPPER   */ { 0.0f, 50.0f, 0.0f },
    /* POST_LOWER   */ { 0.0f, 38.0f, 0.0f },
};

static Vec3f sPieceSizes[] = {
    /* WHOLE_SIGN */ { 1500.0f, 1000.0f, 0.0f },
    /* UPPER_HALF */ { 1500.0f, 500.0f, 0.0f },
    /* LOWER_HALF */ { 1500.0f, 500.0f, 0.0f },
    /* RIGHT_HALF  */ { 700.0f, 1000.0f, 0.0f },
    /* LEFT_HALF   */ { 700.0f, 1000.0f, 0.0f },
    /* 2ND_QUAD    */ { 700.0f, 500.0f, 0.0f },
    /* 1ST_QUAD    */ { 700.0f, 500.0f, 0.0f },
    /* 3RD_QUAD    */ { 700.0f, 500.0f, 0.0f },
    /* 4TH_QUAD    */ { 700.0f, 500.0f, 0.0f },
    /* UPPER_LEFT  */ { 700.0f, 500.0f, 0.0f },
    /* LEFT_UPPER  */ { 700.0f, 500.0f, 0.0f },
    /* LEFT_LOWER  */ { 700.0f, 500.0f, 0.0f },
    /* LOWER_LEFT  */ { 700.0f, 500.0f, 0.0f },
    /* UPPER_RIGHT */ { 700.0f, 500.0f, 0.0f },
    /* RIGHT_UPPER */ { 700.0f, 500.0f, 0.0f },
    /* RIGHT_LOWER */ { 700.0f, 500.0f, 0.0f },
    /* LOWER_RIGHT */ { 700.0f, 500.0f, 0.0f },
    /* POST_UPPER  */ { 200.0f, 500.0f, 0.0f },
    /* POST_LOWER  */ { 200.0f, 500.0f, 0.0f },
};

static u8 sCutTypes[] = {
    /* 1H_OVER     */ CUT_VERT_L, /* 2H_OVER     */ CUT_VERT_L,
    /* 1H_COMBO    */ CUT_DIAG_R, /* 2H_COMBO    */ CUT_DIAG_R,
    /* 1H_LEFT     */ CUT_HORIZ,  /* 2H_LEFT     */ CUT_HORIZ,
    /* 1H_COMBO    */ CUT_HORIZ,  /* 2H_COMBO    */ CUT_HORIZ,
    /* 1H_RIGHT    */ CUT_HORIZ,  /* 2H_RIGHT    */ CUT_HORIZ,
    /* 1H_COMBO    */ CUT_HORIZ,  /* 2H_COMBO    */ CUT_HORIZ,
    /* 1H_STAB     */ CUT_POST,   /* 2H_STAB     */ CUT_POST,
    /* 1H_COMBO    */ CUT_POST,   /* 2H_COMBO    */ CUT_POST,
    /* FLIP_START  */ CUT_VERT_L, /* JUMP_START  */ CUT_VERT_L,
    /* FLIP_END    */ CUT_VERT_L, /* JUMP_END    */ CUT_VERT_L,
    /* BACK_LEFT   */ CUT_HORIZ,  /* BACK_RIGHT  */ CUT_HORIZ,
    /* OVER_HAMMER */ CUT_POST,   /* SIDE_HAMMER */ CUT_POST,
    /* 1H_SPIN_ATK */ CUT_POST,   /* 2H_SPIN_ATK */ CUT_POST,
    /* 1H_BIG_SPIN */ CUT_POST,   /* 2H_BIG_SPIN */ CUT_POST,
};

static u16 sCutFlags[] = {
    /* CUT_POST   */ ALL_PARTS,       /* CUT_VERT_L */ LEFT_HALF,
    /* CUT_HORIZ  */ UPPER_HALF,      /* CUT_DIAG_L */ UPPERLEFT_HALF,
    /* CUT_DIAG_R */ UPPERRIGHT_HALF, /* CUT_VERT_R */ RIGHT_HALF,
};

void EnKanban_SetFloorRot(EnKanban* pthis) {
    if (pthis->actor.floorPoly != NULL) {
        f32 nx = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.x);
        f32 ny = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.y);
        f32 nz = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.z);

        pthis->floorRot.x = -Math_FAtan2F(-nz * ny, 1.0f);
        pthis->floorRot.z = Math_FAtan2F(-nx * ny, 1.0f);
    }
}

void EnKanban_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnKanban* pthis = (EnKanban*)thisx;

    Actor_SetScale(&pthis->actor, 0.01f);
    if (pthis->actor.params != ENKANBAN_PIECE) {
        pthis->actor.targetMode = 0;
        pthis->actor.flags |= ACTOR_FLAG_0;
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
        osSyncPrintf("KANBAN ARG    %x\n", pthis->actor.params);
        if (pthis->actor.params == ENKANBAN_FISHING) {
            if (LINK_IS_CHILD) {
                pthis->actor.textId = 0x409D;
            } else {
                pthis->actor.textId = 0x4090;
            }
        } else {
            pthis->actor.textId = pthis->actor.params | 0x300;
        }
        pthis->bounceX = 1;
        pthis->partFlags = 0xFFFF;
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 50.0f, 4);
        EnKanban_SetFloorRot(pthis);
        if (LINK_IS_CHILD) {
            pthis->actor.world.pos.y -= 15.0f;
        }
    }
}

void EnKanban_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnKanban* pthis = (EnKanban*)thisx;

    if (pthis->actionState == ENKANBAN_SIGN) {
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
}

void EnKanban_Message(EnKanban* pthis, GlobalContext* globalCtx) {
    if (!pthis->msgFlag) {
        if (pthis->msgTimer == 0) {
            if (ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) < 0x2800) {
                if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
                    pthis->msgFlag = true;
                } else {
                    func_8002F2CC(&pthis->actor, globalCtx, 68.0f);
                }
            }
        } else {
            pthis->msgTimer--;
        }
    } else {
        if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
            pthis->msgFlag = false;
            pthis->msgTimer = 20;
        }
    }
}

void EnKanban_Update(Actor* thisx, GlobalContext* globalCtx2) {
    u8 bounced = false;
    GlobalContext* globalCtx = globalCtx2;
    EnKanban* pthis = (EnKanban*)thisx;
    EnKanban* signpost;
    EnKanban* piece;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f offset;

    pthis->frameCount++;
    switch (pthis->actionState) {
        case ENKANBAN_SIGN:
            if (pthis->invincibilityTimer != 0) {
                pthis->invincibilityTimer--;
            }
            if (pthis->zTargetTimer != 0) {
                pthis->zTargetTimer--;
            }
            if (pthis->zTargetTimer == 1) {
                pthis->actor.flags &= ~ACTOR_FLAG_0;
            }
            if (pthis->partFlags == 0xFFFF) {
                EnKanban_Message(pthis, globalCtx);
            }
            if ((pthis->invincibilityTimer == 0) && (pthis->collider.base.acFlags & AC_HIT)) {
                pthis->collider.base.acFlags &= ~AC_HIT;
                pthis->invincibilityTimer = 6;
                piece = (EnKanban*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_KANBAN,
                                                      pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                                                      pthis->actor.world.pos.z, pthis->actor.shape.rot.x,
                                                      pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, ENKANBAN_PIECE);
                if (piece != NULL) {
                    ColliderInfo* hitItem = pthis->collider.info.acHitInfo;
                    s16 yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
                    u8 i;

                    if (hitItem->toucher.dmgFlags & 0x700) {
                        pthis->cutType = sCutTypes[player->swordAnimation];
                    } else {
                        pthis->cutType = CUT_POST;
                    }
                    if (ABS(yawDiff) > 0x4000) {
                        if (pthis->cutType == CUT_DIAG_R) {
                            pthis->cutType = CUT_DIAG_L;
                        } else if (pthis->cutType == CUT_VERT_L) {
                            pthis->cutType = CUT_VERT_R;
                        }
                    }
                    piece->partFlags = sCutFlags[pthis->cutType] & pthis->partFlags;
                    if (piece->partFlags == 0) {
                        Actor_Kill(&piece->actor);
                        return;
                    }
                    piece->partCount = 0;
                    for (i = 0; i < ARRAY_COUNT(sPartFlags); i++) {
                        if (sPartFlags[i] & piece->partFlags) {
                            piece->partCount++;
                        }
                    }
                    pthis->partFlags &= ~sCutFlags[pthis->cutType];
                    if (!(pthis->partFlags & ALL_PARTS)) {
                        pthis->zTargetTimer = 10;
                    }
                    if ((piece->partFlags & PART_UPPER_LEFT) && (piece->partFlags & PART_LOWER_RIGHT)) {
                        piece->pieceType = PIECE_WHOLE_SIGN;
                    } else if ((piece->partFlags & PART_LEFT_UPPER) && (piece->partFlags & PART_RIGHT_UPPER)) {
                        piece->pieceType = PIECE_UPPER_HALF;
                    } else if ((piece->partFlags & PART_LEFT_LOWER) && (piece->partFlags & PART_RIGHT_LOWER)) {
                        piece->pieceType = PIECE_LOWER_HALF;
                    } else if ((piece->partFlags & PART_UPPER_RIGHT) && (piece->partFlags & PART_LOWER_RIGHT)) {
                        piece->pieceType = PIECE_RIGHT_HALF;
                    } else if ((piece->partFlags & PART_UPPER_LEFT) && (piece->partFlags & PART_LOWER_LEFT)) {
                        piece->pieceType = PIECE_LEFT_HALF;
                    } else if ((piece->partFlags & PART_UPPER_LEFT) && (piece->partFlags & PART_LEFT_UPPER)) {
                        piece->pieceType = PIECE_2ND_QUAD;
                    } else if ((piece->partFlags & PART_UPPER_RIGHT) && (piece->partFlags & PART_RIGHT_UPPER)) {
                        piece->pieceType = PIECE_1ST_QUAD;
                    } else if ((piece->partFlags & PART_LEFT_LOWER) && (piece->partFlags & PART_LOWER_LEFT)) {
                        piece->pieceType = PIECE_3RD_QUAD;
                    } else if ((piece->partFlags & PART_RIGHT_LOWER) && (piece->partFlags & PART_LOWER_RIGHT)) {
                        piece->pieceType = PIECE_4TH_QUAD;
                    } else if (piece->partFlags & PART_UPPER_LEFT) {
                        piece->pieceType = PIECE_UPPER_LEFT;
                    } else if (piece->partFlags & PART_LEFT_UPPER) {
                        piece->pieceType = PIECE_LEFT_UPPER;
                    } else if (piece->partFlags & PART_LEFT_LOWER) {
                        piece->pieceType = PIECE_LEFT_LOWER;
                    } else if (piece->partFlags & PART_LOWER_LEFT) {
                        piece->pieceType = PIECE_LOWER_LEFT;
                    } else if (piece->partFlags & PART_UPPER_RIGHT) {
                        piece->pieceType = PIECE_UPPER_RIGHT;
                    } else if (piece->partFlags & PART_RIGHT_UPPER) {
                        piece->pieceType = PIECE_RIGHT_UPPER;
                    } else if (piece->partFlags & PART_RIGHT_LOWER) {
                        piece->pieceType = PIECE_RIGHT_LOWER;
                    } else if (piece->partFlags & PART_LOWER_RIGHT) {
                        piece->pieceType = PIECE_LOWER_RIGHT;
                    } else if (piece->partFlags & PART_POST_UPPER) {
                        piece->pieceType = PIECE_POST_UPPER;
                    } else if (piece->partFlags & PART_POST_LOWER) {
                        piece->pieceType = PIECE_POST_LOWER;
                    } else {
                        piece->pieceType = PIECE_OTHER;
                    }
                    if (piece->pieceType == 100) {
                        piece->pieceType = PIECE_WHOLE_SIGN;
                    }

                    Matrix_RotateY((pthis->actor.shape.rot.y / (f32)0x8000) * M_PI, MTXMODE_NEW);
                    Matrix_MultVec3f(&sPieceOffsets[piece->pieceType], &offset);
                    piece->actor.world.pos.x += offset.x;
                    piece->actor.world.pos.y += offset.y;
                    piece->actor.world.pos.z += offset.z;
                    piece->offset.x = -sPieceOffsets[piece->pieceType].x / pthis->actor.scale.x;
                    piece->offset.y = -sPieceOffsets[piece->pieceType].y / pthis->actor.scale.x;
                    piece->offset.z = -sPieceOffsets[piece->pieceType].z / pthis->actor.scale.x;
                    piece->pieceWidth = sPieceSizes[piece->pieceType].x;
                    piece->pieceHeight = sPieceSizes[piece->pieceType].y;
                    piece->actor.gravity = -1.0f;
                    piece->actionState = ENKANBAN_AIR;
                    piece->actor.world.rot.y = (s16)Rand_CenteredFloat(0x3000) + pthis->actor.yawTowardsPlayer + 0x8000;
                    piece->actor.velocity.y = Rand_ZeroFloat(2.0f) + 3.0f;
                    piece->actor.speedXZ = Rand_ZeroFloat(2.0f) + 3.0f;
                    if (piece->partCount >= 4) {
                        piece->bounceX = (s16)Rand_ZeroFloat(10.0f) + 6;
                        piece->bounceZ = (s16)Rand_ZeroFloat(10.0f) + 6;
                    } else {
                        piece->bounceX = (s16)Rand_ZeroFloat(7.0f) + 3;
                        piece->bounceZ = (s16)Rand_ZeroFloat(7.0f) + 3;
                    }
                    piece->spinVel.y = Rand_CenteredFloat(0x1800);
                    if (Rand_ZeroOne() < 0.5f) {
                        piece->direction = 1;
                    } else {
                        piece->direction = -1;
                    }
                    piece->airTimer = 100;
                    piece->actor.flags &= ~ACTOR_FLAG_0;
                    piece->actor.flags |= ACTOR_FLAG_25;
                    pthis->cutMarkTimer = 5;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_SWORD_STRIKE);
                }
            }
            pthis->actor.focus.pos = pthis->actor.world.pos;
            pthis->actor.focus.pos.y += 44.0f;
            Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            if (pthis->actor.xzDistToPlayer > 500.0f) {
                pthis->actor.flags |= ACTOR_FLAG_0;
                pthis->partFlags = 0xFFFF;
            }
            if (pthis->cutMarkTimer != 0) {
                if (pthis->cutMarkTimer >= 5) {
                    pthis->cutMarkAlpha += 255;
                    if (pthis->cutMarkAlpha > 255) {
                        pthis->cutMarkAlpha = 255;
                    }
                } else {
                    pthis->cutMarkAlpha -= 65;
                    if (pthis->cutMarkAlpha < 0) {
                        pthis->cutMarkAlpha = 0;
                    }
                }
                pthis->cutMarkTimer--;
            }
            break;
        case ENKANBAN_AIR:
        case ENKANBAN_UNUSED: {
            u16 tempBgFlags;
            f32 tempX;
            f32 tempY;
            f32 tempZ;
            f32 tempYDistToWater;
            u8 onGround;

            Actor_MoveForward(&pthis->actor);
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 30.0f, 30.0f, 50.0f, 5);

            tempX = pthis->actor.world.pos.x;
            tempY = pthis->actor.world.pos.y;
            tempZ = pthis->actor.world.pos.z;
            tempBgFlags = pthis->actor.bgCheckFlags;
            tempYDistToWater = pthis->actor.yDistToWater;

            pthis->actor.world.pos.z += ((pthis->actor.world.pos.y - pthis->actor.floorHeight) * -50.0f) / 100.0f;
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 50.0f, 4);
            EnKanban_SetFloorRot(pthis);

            pthis->actor.world.pos.x = tempX;
            pthis->actor.world.pos.y = tempY;
            pthis->actor.world.pos.z = tempZ;
            pthis->actor.bgCheckFlags = tempBgFlags;
            pthis->actor.yDistToWater = tempYDistToWater;

            osSyncPrintf(VT_RST);
            onGround = (pthis->actor.bgCheckFlags & 1);
            if (pthis->spinXFlag) {
                pthis->spinRot.x += pthis->spinVel.x;
                pthis->spinVel.x -= 0x800;
                if ((pthis->spinRot.x <= 0) && onGround) {
                    pthis->spinRot.x = 0;
                    pthis->spinVel.x = 0;
                }
            } else {
                pthis->spinRot.x -= pthis->spinVel.x;
                pthis->spinVel.x -= 0x800;
                if ((pthis->spinRot.x >= 0) && onGround) {
                    pthis->spinRot.x = 0;
                    pthis->spinVel.x = 0;
                }
            }
            if (pthis->spinVel.x < -0xC00) {
                pthis->spinVel.x = -0xC00;
            }
            if (pthis->spinZFlag) {
                pthis->spinRot.z += pthis->spinVel.z;
                pthis->spinVel.z -= 0x800;
                if ((pthis->spinRot.z <= 0) && onGround) {
                    pthis->spinRot.z = 0;
                    pthis->spinVel.z = 0;
                }
            } else {
                pthis->spinRot.z -= pthis->spinVel.z;
                pthis->spinVel.z -= 0x800;
                if ((pthis->spinRot.z >= 0) && onGround) {
                    pthis->spinRot.z = 0;
                    pthis->spinVel.z = 0;
                }
            }
            if (pthis->spinVel.z < -0xC00) {
                pthis->spinVel.z = -0xC00;
            }
            if (pthis->actor.bgCheckFlags & 8) {
                pthis->actor.speedXZ *= -0.5f;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_WOODPLATE_BOUND);
            }
            if (pthis->actor.bgCheckFlags & 0x40) {
                pthis->actionState = ENKANBAN_WATER;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_BOMB_DROP_WATER);
                pthis->bounceX = pthis->bounceZ = 0;
                pthis->actor.world.pos.y += pthis->actor.yDistToWater;
                EffectSsGSplash_Spawn(globalCtx, &pthis->actor.world.pos, NULL, NULL, 0, (pthis->partCount * 20) + 300);
                EffectSsGRipple_Spawn(globalCtx, &pthis->actor.world.pos, 150, 650, 0);
                EffectSsGRipple_Spawn(globalCtx, &pthis->actor.world.pos, 300, 800, 5);
                pthis->actor.velocity.y = 0.0f;
                pthis->actor.gravity = 0.0f;
                osSyncPrintf(" WAT  Y  = %f\n", pthis->actor.yDistToWater);
                osSyncPrintf(" POS  Y  = %f\n", pthis->actor.world.pos.y);
                osSyncPrintf(" GROUND Y  = %f\n", pthis->actor.floorHeight);
                break;
            }

            if (onGround) {
                if (pthis->bounceCount <= 0) {
                    pthis->bounceCount++;
                    pthis->actor.velocity.y *= -0.3f;
                    pthis->actor.world.rot.y += (s16)Rand_CenteredFloat(16384.0f);
                } else {
                    pthis->actor.velocity.y = 0.0f;
                }
                pthis->actor.speedXZ *= 0.7f;
                if ((pthis->spinRot.x == 0) && (pthis->bounceX != 0)) {
                    pthis->spinVel.x = pthis->bounceX * 0x200;
                    if (pthis->bounceX != 0) {
                        pthis->bounceX -= 5;
                        if (pthis->bounceX <= 0) {
                            pthis->bounceX = 0;
                        }
                    }
                    if (Rand_ZeroOne() < 0.5f) {
                        pthis->spinXFlag = true;
                    } else {
                        pthis->spinXFlag = false;
                    }
                    bounced = true;
                }
                if ((pthis->spinRot.z == 0) && (pthis->bounceZ != 0)) {
                    pthis->spinVel.z = pthis->bounceZ * 0x200;
                    if (pthis->bounceZ != 0) {
                        pthis->bounceZ -= 5;
                        if (pthis->bounceZ <= 0) {
                            pthis->bounceZ = 0;
                        }
                    }
                    if (Rand_ZeroOne() < 0.5f) {
                        pthis->spinZFlag = true;
                    } else {
                        pthis->spinZFlag = false;
                    }
                    bounced = true;
                }
                Math_ApproachS(&pthis->actor.shape.rot.x, pthis->direction * 0x4000, 1, 0x2000);
            } else {
                pthis->actor.shape.rot.y += pthis->spinVel.y;
                pthis->actor.shape.rot.x += pthis->direction * 0x7D0;
            }
            if (bounced) {
                s16 dustCount;
                s16 j;
                Vec3f velocity = { 0.0f, 0.0f, 0.0f };
                Vec3f accel;
                Vec3f pos;

                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_WOODPLATE_BOUND);
                accel.x = 0.0f;
                accel.y = 0.1f;
                accel.z = 0.0f;
                pos.y = pthis->actor.floorHeight + 3.0f;
                dustCount = pthis->partCount * 0.5f;
                for (j = 0; j < dustCount + 3; j++) {
                    pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat((pthis->partCount * 0.5f) + 20.0f);
                    pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat((pthis->partCount * 0.5f) + 20.0f);
                    func_800286CC(globalCtx, &pos, &velocity, &accel, 100, 5);
                }
            }
            if (DECR(pthis->airTimer) == 0) {
                pthis->actionState = ENKANBAN_GROUND;
            }
        }
        case ENKANBAN_GROUND:
        case ENKANBAN_WATER:
            signpost = (EnKanban*)pthis->actor.parent;

            if (signpost->partFlags == 0xFFFF) {
                Actor_Kill(&pthis->actor);
            }
            Math_ApproachF(&pthis->actor.shape.yOffset, 100.0f, 1.0f, 5.0f);
            if (pthis->actionState == ENKANBAN_WATER) {
                s32 rippleDelay;
                s32 rippleScale;

                if ((player->actor.speedXZ > 0.0f) && (player->actor.world.pos.y < pthis->actor.world.pos.y) &&
                    (pthis->actor.xyzDistToPlayerSq < 2500.0f)) {
                    Math_ApproachF(&pthis->actor.speedXZ, player->actor.speedXZ, 1.0f, 0.2f);
                    if (pthis->actor.speedXZ > 1.0f) {
                        pthis->actor.speedXZ = 1.0f;
                    }
                    if (Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer + 0x8000, 1, 0x1000,
                                           0) > 0) {
                        pthis->spinVel.y = pthis->actor.speedXZ * 1000.0f;
                    } else {
                        pthis->spinVel.y = pthis->actor.speedXZ * -1000.0f;
                    }
                }
                if (pthis->actor.bgCheckFlags & 1) {
                    pthis->actor.speedXZ = 0.0f;
                }
                Actor_MoveForward(&pthis->actor);
                if (pthis->actor.speedXZ != 0.0f) {
                    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 50.0f, 5);
                    if (pthis->actor.bgCheckFlags & 8) {
                        pthis->actor.speedXZ *= -0.5f;
                        if (pthis->spinVel.y > 0) {
                            pthis->spinVel.y = -0x7D0;
                        } else {
                            pthis->spinVel.y = 0x7D0;
                        }
                    }
                    Math_ApproachZeroF(&pthis->actor.speedXZ, 1.0f, 0.15f);
                }
                pthis->actor.shape.rot.y += pthis->spinVel.y;
                Math_ApproachS(&pthis->spinVel.y, 0, 1, 0x3A);
                Math_ApproachS(&pthis->actor.shape.rot.x, pthis->direction * 0x4000, 2, 0x1000);
                Math_ApproachS(&pthis->spinRot.x, Math_SinS(2500 * pthis->frameCount) * 500.0f, 2, 0x1000);
                Math_ApproachS(&pthis->spinRot.z, Math_CosS(3000 * pthis->frameCount) * 500.0f, 2, 0x1000);
                Math_ApproachZeroF(&pthis->floorRot.x, 0.5f, 0.2f);
                Math_ApproachZeroF(&pthis->floorRot.z, 0.5f, 0.2f);
                if (fabsf(pthis->actor.speedXZ) > 1.0f) {
                    rippleDelay = 0;
                } else if (fabsf(pthis->actor.speedXZ) > 0.5f) {
                    rippleDelay = 3;
                } else {
                    rippleDelay = 7;
                }
                if (!(pthis->frameCount & rippleDelay)) {
                    if (pthis->partCount < 3) {
                        rippleScale = 0;
                    } else if (pthis->partCount < 6) {
                        rippleScale = 100;
                    } else {
                        rippleScale = 200;
                    }
                    EffectSsGRipple_Spawn(globalCtx, &pthis->actor.world.pos, rippleScale, rippleScale + 500, 0);
                }
            } else if ((globalCtx->actorCtx.unk_02 != 0) && (pthis->actor.xyzDistToPlayerSq < SQ(100.0f))) {
                f32 hammerStrength = (100.0f - sqrtf(pthis->actor.xyzDistToPlayerSq)) * 0.05f;

                pthis->actionState = ENKANBAN_AIR;
                pthis->actor.gravity = -1.0f;
                pthis->actor.world.rot.y = Rand_CenteredFloat(0x10000);
                if (pthis->partCount >= 4) {
                    pthis->bounceX = (s16)Rand_ZeroFloat(10.0f) + 6;
                    pthis->bounceZ = (s16)Rand_ZeroFloat(10.0f) + 6;
                    pthis->actor.velocity.y = 2.0f + hammerStrength;
                    pthis->actor.speedXZ = Rand_ZeroFloat(1.0f);
                } else {
                    pthis->bounceX = (s16)Rand_ZeroFloat(7.0f) + 3;
                    pthis->bounceZ = (s16)Rand_ZeroFloat(7.0f) + 3;
                    pthis->actor.velocity.y = 3.0f + hammerStrength;
                    pthis->actor.speedXZ = Rand_ZeroFloat(1.5f);
                }
                pthis->spinVel.y = Rand_CenteredFloat(0x1800);
                if (Rand_ZeroOne() < 0.5f) {
                    pthis->direction = 1;
                } else {
                    pthis->direction = -1;
                }
                pthis->airTimer = 70;
            }
            if (pthis->bounceX == 0) {
                Actor* bomb = globalCtx->actorCtx.actorLists[ACTORCAT_EXPLOSIVE].head;
                f32 dx;
                f32 dy;
                f32 dz;

                while (bomb != NULL) {
                    if (bomb->params != 1) {
                        bomb = bomb->next;
                        continue;
                    }
                    dx = pthis->actor.world.pos.x - bomb->world.pos.x;
                    dy = pthis->actor.world.pos.y - bomb->world.pos.y;
                    dz = pthis->actor.world.pos.z - bomb->world.pos.z;
                    if (sqrtf(SQ(dx) + SQ(dy) + SQ(dz)) < 100.0f) {
                        f32 bombStrength = (100.0f - sqrtf(SQ(dx) + SQ(dy) + SQ(dz))) * 0.05f;

                        pthis->actionState = ENKANBAN_AIR;
                        pthis->actor.gravity = -1.0f;
                        pthis->actor.world.rot.y = Math_FAtan2F(dx, dz) * (0x8000 / M_PI);
                        if (pthis->partCount >= 4) {
                            pthis->bounceX = (s16)Rand_ZeroFloat(10.0f) + 6;
                            pthis->bounceZ = (s16)Rand_ZeroFloat(10.0f) + 6;
                            pthis->actor.velocity.y = 2.5f + bombStrength;
                            pthis->actor.speedXZ = 3.0f + bombStrength;
                        } else {
                            pthis->bounceX = (s16)Rand_ZeroFloat(7.0f) + 3;
                            pthis->bounceZ = (s16)Rand_ZeroFloat(7.0f) + 3;
                            pthis->actor.velocity.y = 5.0f + bombStrength;
                            pthis->actor.speedXZ = 4.0f + bombStrength;
                        }
                        pthis->spinVel.y = Rand_CenteredFloat(0x1800);
                        if (Rand_ZeroOne() < 0.5f) {
                            pthis->direction = 1;
                        } else {
                            pthis->direction = -1;
                        }
                        pthis->airTimer = 70;
                    }
                    bomb = bomb->next;
                }
            }
            osSyncPrintf(VT_FGCOL(GREEN));
            osSyncPrintf("OCARINA_MODE %d\n", globalCtx->msgCtx.ocarinaMode);
            osSyncPrintf(VT_RST);
            switch (pthis->ocarinaFlag) {
                case 0:
                    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_01) {
                        pthis->ocarinaFlag = 1;
                    }
                    break;
                case 1:
                    if ((globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04) &&
                        (globalCtx->msgCtx.unk_E3F2 == OCARINA_SONG_LULLABY)) {
                        pthis->actionState = ENKANBAN_REPAIR;
                        pthis->bounceX = 1;
                        Audio_PlaySoundGeneral(NA_SE_SY_TRE_BOX_APPEAR, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                               &D_801333E8);
                    }
                    break;
            }
            break;
        case ENKANBAN_REPAIR: {
            f32 distX;
            f32 distY;
            f32 distZ;
            s16 pDiff;
            s16 yDiff;
            s16 rDiff;
            signpost = (EnKanban*)pthis->actor.parent;

            if (signpost->partFlags == 0xFFFF) {
                Actor_Kill(&pthis->actor);
            }

            Matrix_RotateY((signpost->actor.shape.rot.y / (f32)0x8000) * M_PI, MTXMODE_NEW);
            Matrix_MultVec3f(&sPieceOffsets[pthis->pieceType], &offset);
            distX =
                Math_SmoothStepToF(&pthis->actor.world.pos.x, signpost->actor.world.pos.x + offset.x, 1.0f, 3.0f, 0.0f);
            distY =
                Math_SmoothStepToF(&pthis->actor.world.pos.y, signpost->actor.world.pos.y + offset.y, 1.0f, 3.0f, 0.0f);
            distZ =
                Math_SmoothStepToF(&pthis->actor.world.pos.z, signpost->actor.world.pos.z + offset.z, 1.0f, 3.0f, 0.0f);
            pDiff = Math_SmoothStepToS(&pthis->actor.shape.rot.x, signpost->actor.shape.rot.x, 1, 0x200, 0);
            yDiff = Math_SmoothStepToS(&pthis->actor.shape.rot.y, signpost->actor.shape.rot.y, 1, 0x200, 0);
            rDiff = Math_SmoothStepToS(&pthis->actor.shape.rot.z, signpost->actor.shape.rot.z, 1, 0x200, 0);
            Math_ApproachS(&pthis->spinRot.x, 0, 1, 0x200);
            Math_ApproachS(&pthis->spinRot.z, 0, 1, 0x200);
            Math_ApproachZeroF(&pthis->floorRot.x, 1.0f, 0.05f);
            Math_ApproachZeroF(&pthis->floorRot.z, 1.0f, 0.05f);
            Math_ApproachZeroF(&pthis->actor.shape.yOffset, 1.0f, 2.0f);
            if (((distX + distY + distZ) == 0.0f) &&
                ((pDiff + yDiff + rDiff + pthis->spinRot.x + pthis->spinRot.z) == 0) && (pthis->floorRot.x == 0.0f) &&
                (pthis->floorRot.z == 0.0f)) {
                signpost->partFlags |= pthis->partFlags;
                signpost->actor.flags |= ACTOR_FLAG_0;
                Actor_Kill(&pthis->actor);
            }
        } break;
    }
}

static Gfx* sDisplayLists[] = {
    object_kanban_DL_000CB0, object_kanban_DL_000DB8, object_kanban_DL_000E78, object_kanban_DL_000F38,
    object_kanban_DL_000FF8, object_kanban_DL_0010B8, object_kanban_DL_0011C0, object_kanban_DL_0012C8,
    object_kanban_DL_0013D0, object_kanban_DL_001488, object_kanban_DL_001540,
};

#include "z_en_kanban_gfx.cpp"

static f32 sCutAngles[] = {
    /* CUT_POST   */ 0.50f * M_PI,
    /* CUT_VERT_L */ 0.00f * M_PI,
    /* CUT_HORIZ  */ 0.50f * M_PI,
    /* CUT_DIAG_L */ 0.66f * M_PI,
    /* CUT_DIAG_R */ 0.34f * M_PI,
    /* CUT_VERT_R */ 0.00f * M_PI,
};

static s32 sUnused[] = { 0, 0, 0 }; // Unused zero vector?

#include "overlays/ovl_En_Kanban/ovl_En_Kanban.cpp"

void EnKanban_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnKanban* pthis = (EnKanban*)thisx;
    f32 zShift;
    f32 zShift2;
    s16 i;
    u8* shadowTex = (u8*)Graph_Alloc(globalCtx->state.gfxCtx, 0x400);

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_kanban.c", 1659);
    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, object_kanban_DL_000C30);
    if (pthis->actionState != ENKANBAN_SIGN) {
        Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
        Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
        Matrix_RotateX(pthis->floorRot.x, MTXMODE_APPLY);
        Matrix_RotateZ(pthis->floorRot.z, MTXMODE_APPLY);
        Matrix_Translate(0.0f, pthis->actor.shape.yOffset, 0.0f, MTXMODE_APPLY);
        Matrix_RotateY((pthis->actor.shape.rot.y / (f32)0x8000) * M_PI, MTXMODE_APPLY);
        Matrix_RotateX((pthis->actor.shape.rot.x / (f32)0x8000) * M_PI, MTXMODE_APPLY);
        zShift = fabsf(Math_SinS(pthis->spinRot.x) * pthis->pieceHeight);
        zShift2 = fabsf(Math_SinS(pthis->spinRot.z) * pthis->pieceWidth);
        zShift = MAX(zShift2, zShift);
        zShift *= -(f32)pthis->direction;
        Matrix_Translate(0.0f, 0.0f, zShift, MTXMODE_APPLY);
        Matrix_RotateX((pthis->spinRot.x / (f32)0x8000) * M_PI, MTXMODE_APPLY);
        Matrix_RotateY((pthis->spinRot.z / (f32)0x8000) * M_PI, MTXMODE_APPLY);
        Matrix_Translate(pthis->offset.x, pthis->offset.y, pthis->offset.z - 100.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_kanban.c", 1715),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        for (i = 0; i < ARRAY_COUNT(sPartFlags); i++) {
            if (sPartFlags[i] & pthis->partFlags) {
                gSPDisplayList(POLY_OPA_DISP++, sDisplayLists[i]);
            }
        }
    } else {
        Matrix_Translate(0.0f, 0.0f, -100.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_kanban.c", 1725),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (pthis->partFlags == 0xFFFF) {
            gSPDisplayList(POLY_OPA_DISP++, gSignRectangularDL);
        } else {
            for (i = 0; i < ARRAY_COUNT(sPartFlags); i++) {
                if (sPartFlags[i] & pthis->partFlags) {
                    gSPDisplayList(POLY_OPA_DISP++, sDisplayLists[i]);
                }
            }
        }
        if (pthis->cutMarkAlpha != 0) {
            f32 cutOffset = (pthis->cutType == CUT_POST) ? -1200.0f : 0.0f;

            Matrix_Translate(0.0f, 4400.0f + cutOffset, 200.0f, MTXMODE_APPLY);
            Matrix_RotateZ(sCutAngles[pthis->cutType], MTXMODE_APPLY);
            Matrix_Scale(0.0f, 10.0f, 2.0f, MTXMODE_APPLY);
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, 255, 255, 255, pthis->cutMarkAlpha);
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 150, 0);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_kanban.c", 1773),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, object_kanban_DL_001630);
        }
    }
    if ((pthis->actor.projectedPos.z <= 400.0f) && (pthis->actor.projectedPos.z > 0.0f) &&
        (pthis->actor.floorHeight > -3000.0f)) {
        if ((pthis->bounceX != 0) || (pthis->bounceZ != 0)) {
            u16 dayTime = gSaveContext.dayTime;
            f32 shadowAlpha;

            if (dayTime >= 0x8000) {
                dayTime = 0xFFFF - dayTime;
            }
            shadowAlpha = (dayTime * 0.00275f) + 10.0f;
            if (pthis->actor.projectedPos.z > 300.0f) {
                shadowAlpha *= ((400.0f - pthis->actor.projectedPos.z) * 0.01f);
            }
            gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, 0, 0, 0, (s8)shadowAlpha);

            if ((pthis->actionState == ENKANBAN_SIGN) && LINK_IS_CHILD) {
                zShift = 0.0f;
            } else {
                zShift = ((pthis->actor.world.pos.y - pthis->actor.floorHeight) * -50.0f) / 100.0f;
            }

            Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.floorHeight, pthis->actor.world.pos.z + zShift,
                             MTXMODE_NEW);
            Matrix_RotateX(pthis->floorRot.x, MTXMODE_APPLY);
            Matrix_RotateZ(pthis->floorRot.z, MTXMODE_APPLY);
            Matrix_Scale(pthis->actor.scale.x, 0.0f, pthis->actor.scale.z, MTXMODE_APPLY);
            if (pthis->actionState == ENKANBAN_SIGN) {
                Matrix_RotateX(-M_PI / 5, MTXMODE_APPLY);
            }
            Matrix_RotateY((pthis->actor.shape.rot.y / (f32)0x8000) * M_PI, MTXMODE_APPLY);
            Matrix_RotateX((pthis->actor.shape.rot.x / (f32)0x8000) * M_PI, MTXMODE_APPLY);
            Matrix_RotateX((pthis->spinRot.x / (f32)0x8000) * M_PI, MTXMODE_APPLY);
            Matrix_RotateY((pthis->spinRot.z / (f32)0x8000) * M_PI, MTXMODE_APPLY);
            Matrix_Translate(pthis->offset.x, pthis->offset.y, pthis->offset.z, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_kanban.c", 1833),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            for (i = 0; i < 0x400; i++) {
                if (sShadowTexFlags[i] & pthis->partFlags) {
                    shadowTex[i] = 0xFF;
                } else {
                    shadowTex[i] = 0;
                }
            }
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(shadowTex));
            gSPDisplayList(POLY_XLU_DISP++, sShadowDL);
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_kanban.c", 1857);
}

void EnKanban_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Kanban_InitVars = {
        ACTOR_EN_KANBAN,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_KANBAN,
        sizeof(EnKanban),
        (ActorFunc)EnKanban_Init,
        (ActorFunc)EnKanban_Destroy,
        (ActorFunc)EnKanban_Update,
        (ActorFunc)EnKanban_Draw,
        (ActorFunc)EnKanban_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 20, 50, 5, { 0, 0, 0 } },
    };

}
