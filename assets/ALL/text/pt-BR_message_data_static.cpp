#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, brMessage) \
    const char _message_##textId##_br[sizeof(brMessage END)] = { brMessage END };

#include "translations/message_data_pt-BR.enc.h"
