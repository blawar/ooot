#pragma once
#ifdef INTERNAL_SRC_CODE_Z_KANFONT_C
void Font_LoadChar(Font* font, u8 character, u16 codePointIndex);
void Font_LoadMessageBoxIcon(Font* font, u16 icon);
void Font_LoadOrderedFont(Font* font);
void func_8006EE50(Font* font, u16 arg1, u16 arg2);
#else
void Font_LoadChar(struct Font* font, u8 character, u16 codePointIndex);
void Font_LoadMessageBoxIcon(struct Font* font, u16 icon);
void Font_LoadOrderedFont(struct Font* font);
void func_8006EE50(struct Font* font, u16 arg1, u16 arg2);
#endif
