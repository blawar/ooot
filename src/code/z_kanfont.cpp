#define INTERNAL_SRC_CODE_Z_KANFONT_C
#include "global.h"
#include "message_data_static.h"
#include "segment_symbols.h"
#include "textures/message_static/message_static.h"
#include "textures/nes_font_static/nes_font_static.h"
#include "z64message.h"
#include "def/z_kanfont.h"
#include "def/z_std_dma.h"

void func_8006EE50(Font* font, u16 arg1, u16 arg2)
{
}

/**
 * Loads a texture from nes_font_static for the requested `character` into the character texture buffer
 * at `codePointIndex`. The value of `character` is the ASCII codepoint subtract ' '/0x20.
 */
void Font_LoadChar(Font* font, u8 character, u16 codePointIndex)
{
	DmaMgr_SendRequest1(&font->charTexBuf[codePointIndex], nes_font_static_lut[character], FONT_CHAR_TEX_SIZE, "../z_kanfont.c", 93);
}

/**
 * Loads a message box icon from message_static, such as the ending triangle/square or choice arrow into the
 * icon buffer.
 * The different icons are given in the MessageBoxIcon enum.
 */
void Font_LoadMessageBoxIcon(Font* font, u16 icon)
{
	DmaMgr_SendRequest1(font->iconBuf, message_static_lut[4 + icon], FONT_CHAR_TEX_SIZE, "../z_kanfont.c", 100);
}

/**
 * Loads a full set of character textures based on their ordering in nes_font_static_lut into the font buffer.
 */
void Font_LoadOrderedFont(Font* font)
{
	int i;
	for(i = 0; i < sizeof(nes_font_static_lut) / sizeof(char*); i++)
	{
		memcpy(font->fontBuf + (FONT_CHAR_TEX_SIZE * (i + 0x20)), nes_font_static_lut[i], FONT_CHAR_TEX_SIZE);
	}
}
