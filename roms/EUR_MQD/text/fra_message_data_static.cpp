#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, fraMessage) \
    const char _message_##textId##_fra[sizeof(fraMessage END)] = { fraMessage END };

#include "translations/message_data_fr.enc.h"
