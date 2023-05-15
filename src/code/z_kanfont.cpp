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
 * Loads a texture from nes_font_static for the requested `character` into the character texture buffer at `codePointIndex`.
 */
void Font_LoadChar(Font* font, wchar_t character, u16 codePointIndex)
{
	for(const CharInfo& info : font_static_lut)
	{
		if(info.code == character)
		{
			Copy(&font->charTexBuf[codePointIndex], info.tex, FONT_CHAR_TEX_SIZE);
			return;
		}
	}
	Copy(&font->charTexBuf[codePointIndex], gMsgChar3FQuestionMarkTex, FONT_CHAR_TEX_SIZE);
}

f32 Font_GetCharWidth(wchar_t character)
{
	for(const CharInfo& info : font_static_lut)
	{
		if(info.code == character)
		{
			return info.width;
		}
	}
	return 10.0f;
}

/**
 * Loads a message box icon from message_static, such as the ending triangle/square or choice arrow into the
 * icon buffer.
 * The different icons are given in the MessageBoxIcon enum.
 */
void Font_LoadMessageBoxIcon(Font* font, u16 icon)
{
	Copy(font->iconBuf, message_static_lut[4 + icon], FONT_CHAR_TEX_SIZE);
}

/** Mainly used in the Title Screen and File Select Screen.
 * Loads a full set of character textures based on their ordering in font_static_lut into the font buffer.
 */
void Font_LoadOrderedFont(Font* font)
{
	int i;
	for(i = 0; i < sizeof(font_static_lut) / sizeof(CharInfo); i++)
	{
		Copy(font->fontBuf + (FONT_CHAR_TEX_SIZE * (i + 0x20)), font_static_lut[i].tex, FONT_CHAR_TEX_SIZE);
	}
}
