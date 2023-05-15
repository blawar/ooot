#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, frMessage) \
	const char _message_##textId##_fr[sizeof(frMessage END)] = {frMessage END};

#include "translations/message_data_fr.enc.h"
