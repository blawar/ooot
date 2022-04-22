#ifndef Z_KALEIDO_SCOPE_H
#define Z_KALEIDO_SCOPE_H

#include "global.h"
#include "kaleido_macros.h"
#include "ultra64.h"

extern u8 gAmmoItems[];
extern s16 D_8082AAEC[];
extern s16 D_8082AB2C[];
extern u8 gSlotAgeReqs[];
extern u8 gEquipAgeReqs[][4];
extern u8 gAreaGsFlags[];

void KaleidoScope_DrawQuestStatus(GlobalContext* globalCtx, GraphicsContext* gfxCtx, oot::pause::Page* page);
s32 KaleidoScope_UpdateQuestStatusPoint(oot::pause::Page* page, s32 point);
void KaleidoScope_DrawDebugEditor(GlobalContext* globalCtx);
void KaleidoScope_DrawPlayerWork(GlobalContext* globalCtx);
void KaleidoScope_DrawEquipment(GlobalContext* globalCtx, oot::pause::Page* page);
void KaleidoScope_DrawController(GlobalContext* globalCtx, oot::pause::Page* page);
void KaleidoScope_SetCursorVtx(PauseContext* pauseCtx, u16 index, Vtx* vtx);
void KaleidoScope_DrawItemSelect(GlobalContext* globalCtx, oot::pause::Page* page);
void KaleidoScope_UpdateItemEquip(GlobalContext* globalCtx, Vtx* itemVtx);
void KaleidoScope_DrawDungeonMap(GlobalContext* globalCtx, GraphicsContext* gfxCtx, oot::pause::Page* page);
void KaleidoScope_DrawWorldMap(GlobalContext* globalCtx, GraphicsContext* gfxCtx, oot::pause::Page* page);
void KaleidoScope_UpdatePrompt(GlobalContext* globalCtx);
Gfx* KaleidoScope_QuadTextureIA4(Gfx* gfx, void* texture, s16 width, s16 height, u16 point);
Gfx* KaleidoScope_QuadTextureIA8(Gfx* gfx, void* texture, s16 width, s16 height, u16 point);
Gfx* KaleidoScope_QuadTextureRGBA16(Gfx* gfx, void* texture, s16 width, s16 height, u16 point);
Gfx* KaleidoScope_QuadTextureRGBA32(Gfx* gfx, void* texture, s16 width, s16 height, u16 point);
void KaleidoScope_MoveCursorToSpecialPos(GlobalContext* globalCtx, u16 specialPos);
void KaleidoScope_DrawQuadTextureRGBA32(GraphicsContext* gfxCtx, void* texture, u16 width, u16 height, u16 point);
void KaleidoScope_ProcessPlayerPreRender();
void KaleidoScope_SetupPlayerPreRender(GlobalContext* globalCtx);
void KaleidoScope_DrawCursor(GlobalContext* globalCtx, oot::pause::Page* page);
void KaleidoScope_UpdateDungeonMap(GlobalContext* globalCtx);

void PauseMapMark_Draw(GlobalContext* globalCtx);

#endif
