#ifndef MESSAGE_DATA_STATIC_H
#define MESSAGE_DATA_STATIC_H

#include "global.h"
#include "message_data_fmt.h"

enum TextBoxType
{
	TEXTBOX_TYPE_BLACK,
	TEXTBOX_TYPE_WOODEN,
	TEXTBOX_TYPE_BLUE,
	TEXTBOX_TYPE_OCARINA,
	TEXTBOX_TYPE_NONE_BOTTOM,
	TEXTBOX_TYPE_NONE_NO_SHADOW,
	TEXTBOX_TYPE_CREDITS = 11
};

enum TextBoxBackground
{
	TEXTBOX_BG_CROSS
};

enum TextBoxPosition
{
	TEXTBOX_POS_VARIABLE,
	TEXTBOX_POS_TOP,
	TEXTBOX_POS_MIDDLE,
	TEXTBOX_POS_BOTTOM
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

#define DEFINE_MESSAGE(textId, type, yPos, enMessage, deMessage, frMessage, esMessage, ptMessage, brMessage, itMessage, seMessage) \
	extern "C" const char _message_##textId##_en[]; \
	extern "C" const char _message_##textId##_de[]; \
	extern "C" const char _message_##textId##_fr[]; \
	extern "C" const char _message_##textId##_es[]; \
	extern "C" const char _message_##textId##_pt[]; \
	extern "C" const char _message_##textId##_br[]; \
	extern "C" const char _message_##textId##_it[]; \
	extern "C" const char _message_##textId##_se[];

#include "translations/message_data_en.h"

#undef DEFINE_MESSAGE

#endif
