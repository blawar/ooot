#pragma once
#include "ultra64/types.h"
#include "ultra64/printf.h"
#include "ultra64/gbi.h"
#include "ultra64/message.h"
#include "ultra64/sched.h"
#include "color.h"


struct FrameBufferSwap {
    /* 0x0000 */ u16* curBuffer;
    /* 0x0004 */ u16* nextBuffer;
};

struct TwoHeadArena {
    /* 0x0000 */ u32 size;
    /* 0x0004 */ void* bufp;
    /* 0x0008 */ void* head;
    /* 0x000C */ void* tail;
}; // size = 0x10

struct TwoHeadGfxArena {
    /* 0x0000 */ u32 size;
    /* 0x0004 */ Gfx* bufp;
    /* 0x0008 */ Gfx* p;
    /* 0x000C */ Gfx* d;
}; // size = 0x10

struct GraphicsContext {
    /* 0x0000 */ Gfx* polyOpaBuffer; // Pointer to "Zelda 0"
    /* 0x0004 */ Gfx* polyXluBuffer; // Pointer to "Zelda 1"
    /* 0x0008 */ char unk_008[0x08]; // Unused, could this be pointers to "Zelda 2" / "Zelda 3"
    /* 0x0010 */ Gfx* overlayBuffer; // Pointer to "Zelda 4"
    /* 0x0014 */ u32 unk_014;
    /* 0x0018 */ char unk_018[0x20];
    /* 0x0038 */ OSMesg msgBuff[0x08];
    /* 0x0058 */ OSMesgQueue* schedMsgQ;
    /* 0x005C */ OSMesgQueue queue;
    /* 0x0074 */ char unk_074[0x04];
    /* 0x0078 */ OSScTask task; // size of OSScTask might be wrong
    /* 0x00D0 */ char unk_0D0[0xE0];
    /* 0x01B0 */ Gfx* workBuffer;
    /* 0x01B4 */ TwoHeadGfxArena work;
    /* 0x01C4 */ char unk_01C4[0xC0];
    /* 0x0284 */ struct OSViMode* viMode;
    /* 0x0288 */ char unk_0288[0x20];     // Unused, could this be Zelda 2/3 ?
    /* 0x02A8 */ TwoHeadGfxArena overlay; // "Zelda 4"
    /* 0x02B8 */ TwoHeadGfxArena polyOpa; // "Zelda 0"
    /* 0x02C8 */ TwoHeadGfxArena polyXlu; // "Zelda 1"
    /* 0x02D8 */ u32 gfxPoolIdx;
    /* 0x02DC */ u16* curFrameBuffer;
    /* 0x02E0 */ char unk_2E0[0x04];
    /* 0x02E4 */ u32 viFeatures;
    /* 0x02E8 */ s32 fbIdx;
    /* 0x02EC */ void (*callback)(struct GraphicsContext*, void*);
    /* 0x02F0 */ void* callbackParam;
    /* 0x02F4 */ f32 xScale;
    /* 0x02F8 */ f32 yScale;
    /* 0x02FC */ char unk_2FC[0x04];
}; // size = 0x300

struct GfxPool {
    /* 0x00000 */ u16 headMagic; // GFXPOOL_HEAD_MAGIC
    /* 0x00008 */ Gfx polyOpaBuffer[0x17E0*2]; // TODO FIX HACK
    /* 0x0BF08 */ Gfx polyXluBuffer[0x800*2]; // TODO FIX HACK
    /* 0x0FF08 */ Gfx overlayBuffer[0x400*2]; // TODO FIX HACK
    /* 0x11F08 */ Gfx workBuffer[0x80*2]; // TODO FIX HACK
    /* 0x12408 */ u16 tailMagic; // GFXPOOL_TAIL_MAGIC
};                       // size = 0x12410


struct GfxPrint {
    /* 0x00 */ PrintCallback callback;
    /* 0x04 */ Gfx* dList;
    /* 0x08 */ u16 posX;
    /* 0x0A */ u16 posY;
    /* 0x0C */ u16 baseX;
    /* 0x0E */ u8 baseY;
    /* 0x0F */ u8 flags;
    /* 0x10 */ Color_RGBA8 color;
    /* 0x14 */ char unk_14[0x1C]; // unused
};                       // size = 0x30

/*
void Graph_InitTHGA(struct GraphicsContext* gfxCtx);
struct GameStateOverlay* Graph_GetNextGameState(struct GameState* gameState);
void Graph_Init(struct GraphicsContext* gfxCtx);
void Graph_Destroy(struct GraphicsContext* gfxCtx);
void Graph_TaskSet00(struct GraphicsContext* gfxCtx);
void Graph_Update(struct GraphicsContext* gfxCtx, struct GameState* gameState);
void Graph_ThreadEntry(void*);
void* Graph_Alloc(struct GraphicsContext* gfxCtx, size_t size);
void* Graph_Alloc2(struct GraphicsContext* gfxCtx, size_t size);
void Graph_OpenDisps(Gfx** dispRefs, struct GraphicsContext* gfxCtx, const char* file, s32 line);
void Graph_CloseDisps(Gfx** dispRefs, struct GraphicsContext* gfxCtx, const char* file, s32 line);
Gfx* Graph_GfxPlusOne(Gfx* gfx);
Gfx* Graph_BranchDlist(Gfx* gfx, Gfx* dst);
void* Graph_DlistAlloc(Gfx** gfx, u32 size);
*/

extern GraphicsContext* __gfxCtx;
extern u16 gZBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];
extern GfxPool gGfxPools[2];
extern u8 gGfxSPTaskStack[0x400];
extern u8 gGfxSPTaskYieldBuffer[OS_YIELD_DATA_SIZE];
extern u64 gGfxSPTaskOutputBuffer[0x3000];


