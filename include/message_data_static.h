#ifndef MESSAGE_DATA_STATIC_H
#define MESSAGE_DATA_STATIC_H

#include "global.h"
#include "message_data_fmt.h"

enum TextBoxType
{
	/*  0 */ TEXTBOX_TYPE_BLACK,
	/*  1 */ TEXTBOX_TYPE_WOODEN,
	/*  2 */ TEXTBOX_TYPE_BLUE,
	/*  3 */ TEXTBOX_TYPE_OCARINA,
	/*  4 */ TEXTBOX_TYPE_NONE_BOTTOM,
	/*  5 */ TEXTBOX_TYPE_NONE_NO_SHADOW,
	/* 11 */ TEXTBOX_TYPE_CREDITS = 11
};

enum TextBoxBackground
{
	/* 0 */ TEXTBOX_BG_CROSS
};

enum TextBoxPosition
{
	/* 0 */ TEXTBOX_POS_VARIABLE,
	/* 1 */ TEXTBOX_POS_TOP,
	/* 2 */ TEXTBOX_POS_MIDDLE,
	/* 3 */ TEXTBOX_POS_BOTTOM
};

struct MessageTableEntry
{
	u16 textId;
	u8 typePos;
	const char* segment;
	u32 length;
};

/*
 *  Message Symbol Declarations
 */

#define DEFINE_MESSAGE(textId, type, yPos, staffMessage) extern "C" const char _message_##textId##_staff[];

#include "text/message_data_staff.h"

#undef DEFINE_MESSAGE

#define DEFINE_MESSAGE(textId, type, yPos, nesMessage, gerMessage, fraMessage, esMessage, ptMessage, brMessage, itMessage, seMessage) \
	extern "C" const char _message_##textId##_nes[]; \
	extern "C" const char _message_##textId##_ger[]; \
	extern "C" const char _message_##textId##_fra[]; \
	extern "C" const char _message_##textId##_es[]; \
	extern "C" const char _message_##textId##_pt[]; \
	extern "C" const char _message_##textId##_br[]; \
	extern "C" const char _message_##textId##_it[]; \
	extern "C" const char _message_##textId##_se[];

#include "translations/message_data_en.h"

#undef DEFINE_MESSAGE

#endif
