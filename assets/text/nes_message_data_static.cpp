#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, nesMessage, gerMessage, fraMessage) \
    const char _message_##textId##_nes[sizeof(nesMessage END)] = { nesMessage END };

#define DEFINE_MESSAGE_FFFC

#include "assets/text/message_data.enc.h"


#undef DEFINE_MESSAGE_FFFC
