#pragma once
struct GraphicsContext;
struct GlobalContext;

DebugDispObject* DebugDisplay_AddObject(f32 posX, f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ, f32 scaleX, f32 scaleY, f32 scaleZ, u8 red, u8 green, u8 blue, u8 alpha, s16 type, GraphicsContext* gfxCtx);
void DebugDisplay_DrawObjects(GlobalContext* globalCtx);
void DebugDisplay_Init(void);
