#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, nesMessage) \
	const char _message_##textId##_nes[sizeof(nesMessage END)] = { nesMessage END };

#include "translations/message_data_en.enc.h"
