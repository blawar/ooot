#pragma once
#include "z64game.h"
#include "view.h"

typedef struct {
    /* 0x0000 */ GameState state;
    /* 0x00A4 */ u8* staticSegment;
    /* 0x00A8 */ View view;
} SampleContext; // size = 0x1D0

Vec3s* func_80041C10(struct CollisionContext* colCtx, s32 camId, s32 bgId);
