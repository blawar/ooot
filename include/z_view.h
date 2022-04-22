#pragma once

View* View_New(GraphicsContext* gfxCtx);
void View_Free(View* view);
void View_Init(View*, GraphicsContext*);
void func_800AA358(View* view, Vec3f* eye, Vec3f* lookAt, Vec3f* up);
void func_800AA3F0(View* view, Vec3f* eye, Vec3f* lookAt, Vec3f* up);
void View_SetScale(View* view, f32 scale);
void View_GetScale(View* view, f32* scale);
void func_800AA460(View* view, f32 fovy, f32 near, f32 far);
void func_800AA48C(View* view, f32* fovy, f32* near, f32* far);
void func_800AA4A8(View* view, f32 fovy, f32 near, f32 far);
void func_800AA4E0(View* view, f32* fovy, f32* near, f32* far);
void View_SetViewport(View* view, Viewport* viewport);
void View_GetViewport(View* view, Viewport* viewport);
void func_800AA76C(View* view, f32 arg1, f32 arg2, f32 arg3);
void func_800AA78C(View* view, f32 arg1, f32 arg2, f32 arg3);
s32 func_800AA7AC(View* view, f32 arg1);
void func_800AA7B8(View* view);
void func_800AA814(View* view);
void func_800AA840(View* view, Vec3f vec1, Vec3f vec2, f32 arg3);
s32 func_800AA890(View* view, Mtx* mtx);
void func_800AAA50(View* view, s32 arg1);
s32 func_800AAA9C(View* view);
s32 func_800AB0A8(View* view);
s32 func_800AB2C4(View* view);
s32 func_800AB560(View* view);
s32 func_800AB944(View* view);
s32 func_800AB9EC(View* view, s32 arg1, Gfx** p);
s32 func_800ABE74(f32 eyeX, f32 eyeY, f32 eyeZ);

