#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, nesMessage) \
    const char _message_##textId##_nes[sizeof(nesMessage END)] = { nesMessage END };

#define DEFINE_MESSAGE_FFFC

#include "translations/message_data_en.enc.h"

#ifdef DEFINE_MESSAGE_FFFC
DEFINE_MESSAGE(0xFFFC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"0123456789"
"ABCDEFGHIJKLMN"
"OPQRSTUVWXYZ"
"abcdefghijklmn"
"opqrstuvwxyz"
" -."
)
#endif

DEFINE_MESSAGE(0xFFFD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE, "")

#undef DEFINE_MESSAGE_FFFC
