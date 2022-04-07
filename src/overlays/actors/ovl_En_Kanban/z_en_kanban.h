#pragma once
#define Z_EN_KANBAN_H

#include "ultra64.h"
#include "global.h"

struct EnKanban;


enum EnKanbanActionState {
    ENKANBAN_SIGN,
    ENKANBAN_AIR,
    ENKANBAN_UNUSED,
    ENKANBAN_GROUND,
    ENKANBAN_WATER,
    ENKANBAN_REPAIR
};


enum EnKanbanPiece {
    PIECE_WHOLE_SIGN,
    PIECE_UPPER_HALF,
    PIECE_LOWER_HALF,
    PIECE_RIGHT_HALF,
    PIECE_LEFT_HALF,
    PIECE_2ND_QUAD,
    PIECE_1ST_QUAD,
    PIECE_3RD_QUAD,
    PIECE_4TH_QUAD,
    PIECE_UPPER_LEFT,
    PIECE_LEFT_UPPER,
    PIECE_LEFT_LOWER,
    PIECE_LOWER_LEFT,
    PIECE_UPPER_RIGHT,
    PIECE_RIGHT_UPPER,
    PIECE_RIGHT_LOWER,
    PIECE_LOWER_RIGHT,
    PIECE_POST_UPPER,
    PIECE_POST_LOWER,
    PIECE_OTHER = 100
};


enum EnKanbanCutType {
    CUT_POST,
    CUT_VERT_L,
    CUT_HORIZ,
    CUT_DIAG_L, // lower left to upper right
    CUT_DIAG_R, // upper left to lower right
    CUT_VERT_R
};
struct EnKanban {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ char unk_14C[4];
    /* 0x0150 */ u8 frameCount;
    /* 0x0152 */ Timer airTimer;
    /* 0x0154 */ u8 actionState;
    /* 0x0156 */ u16 partFlags;
    /* 0x0158 */ u8 partCount;
    /* 0x015A */ Timer invincibilityTimer;
    /* 0x015C */ Vec3f offset;
    /* 0x0168 */ Vec3s spinRot;
    /* 0x016E */ Vec3s spinVel;
    /* 0x0174 */ s8 spinXFlag;
    /* 0x0175 */ s8 spinZFlag;
    /* 0x0176 */ s16 bounceX;
    /* 0x0178 */ s16 bounceZ;
    /* 0x017A */ u8 bounceCount;
    /* 0x017C */ f32 pieceWidth;
    /* 0x0180 */ f32 pieceHeight;
    /* 0x0184 */ s16 direction;
    /* 0x0188 */ Vec3f floorRot;
    /* 0x0194 */ u8 cutType;
    /* 0x0195 */ u8 pieceType;
    /* 0x0196 */ Timer cutMarkTimer;
    /* 0x0198 */ s16 cutMarkAlpha;
    /* 0x019A */ Timer zTargetTimer;
    /* 0x019C */ u8 msgFlag;
    /* 0x019D */ u8 msgTimer;
    /* 0x019E */ u8 ocarinaFlag;
    /* 0x01A0 */ ColliderCylinder collider;
}; 

#define ENKANBAN_PIECE ((s16)0xFFDD)
#define ENKANBAN_FISHING 0x300


