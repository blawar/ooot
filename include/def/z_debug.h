#pragma once
struct Input;
struct GraphicsContext;
struct GameInfo;

extern GameInfo* gGameInfo;

void func_800636C0(void);
void func_8006375C(s32 arg0, s32 arg1, const char* text);
void func_8006376C(u8 x, u8 y, u8 colorId, const char* text);
void func_8006390C(Input* input);
void func_80063D7C(GraphicsContext* gfxCtx);
