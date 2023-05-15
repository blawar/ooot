#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, enMessage) \
	const char _message_##textId##_en[sizeof(enMessage END)] = {enMessage END};

#include "translations/message_data_en.enc.h"
