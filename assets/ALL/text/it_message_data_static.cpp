#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, itMessage) \
	const char _message_##textId##_it[sizeof(itMessage END)] = {itMessage END};

#include "translations/message_data_it.enc.h"
