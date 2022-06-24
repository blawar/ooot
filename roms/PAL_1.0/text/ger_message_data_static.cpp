#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, gerMessage) \
    const char _message_##textId##_ger[sizeof(gerMessage END)] = { gerMessage END };

#include "translations/message_data_de.enc.h"
