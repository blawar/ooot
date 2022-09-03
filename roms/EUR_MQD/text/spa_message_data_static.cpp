#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, spaMessage) \
    const char _message_##textId##_spa[sizeof(spaMessage END)] = { spaMessage END };

#include "translations/message_data_es.enc.h"
