#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, seMessage) \
	const char _message_##textId##_se[sizeof(seMessage END)] = {seMessage END};

#include "translations/message_data_sv-SE.enc.h"
