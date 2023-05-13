#pragma once
struct Font;

void Font_LoadChar(Font* font, wchar_t character, u16 codePointIndex);
f32 Font_GetCharWidth(wchar_t character);
void Font_LoadMessageBoxIcon(Font* font, u16 icon);
void Font_LoadOrderedFont(Font* font);
void func_8006EE50(Font* font, u16 arg1, u16 arg2);
