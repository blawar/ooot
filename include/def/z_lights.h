#pragma once
struct GlobalContext;
struct LightContext;
struct LightInfo;
struct LightNode;
struct GraphicsContext;
struct Lights;
struct Vec3f;

void LightContext_DestroyList(GlobalContext* globalCtx, LightContext* lightCtx);
void LightContext_Init(GlobalContext* globalCtx, LightContext* lightCtx);
void LightContext_InitList(GlobalContext* globalCtx, LightContext* lightCtx);
LightNode* LightContext_InsertLight(GlobalContext* globalCtx, LightContext* lightCtx, LightInfo* info);
Lights* LightContext_NewLights(LightContext* lightCtx, GraphicsContext* gfxCtx);
void LightContext_RemoveLight(GlobalContext* globalCtx, LightContext* lightCtx, LightNode* node);
void LightContext_SetAmbientColor(LightContext* lightCtx, u8 r, u8 g, u8 b);
void LightContext_SetFog(LightContext* lightCtx, u8 arg1, u8 arg2, u8 arg3, s16 numLights, s16 arg5);
void Lights_BindAll(Lights* lights, LightNode* listHead, Vec3f* vec);
void Lights_DirectionalSetInfo(LightInfo* info, s8 x, s8 y, s8 z, u8 r, u8 g, u8 b);
void Lights_Draw(Lights* lights, GraphicsContext* gfxCtx);
void Lights_DrawGlow(GlobalContext* globalCtx);
void Lights_GlowCheck(GlobalContext* globalCtx);
Lights* Lights_New(GraphicsContext* gfxCtx, u8 ambientR, u8 ambientG, u8 ambientB);
Lights* Lights_NewAndDraw(GraphicsContext* gfxCtx, u8 ambientR, u8 ambientG, u8 ambientB, u8 numLights, u8 r, u8 g, u8 b, s8 x, s8 y, s8 z);
void Lights_PointGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Lights_PointNoGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Lights_PointSetColorAndRadius(LightInfo* info, u8 r, u8 g, u8 b, s16 radius);
void Lights_PointSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius, s32 type);
void Lights_Reset(Lights* lights, u8 ambentR, u8 ambentG, u8 ambentB);
