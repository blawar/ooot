#define MESSAGE_DATA_STATIC

#include "message_data_fmt.h"
#include "message_data_static.h"

#define DEFINE_MESSAGE(textId, type, yPos, ptMessage) \
	const char _message_##textId##_pt[sizeof(ptMessage END)] = {ptMessage END};

#include "translations/message_data_pt.enc.h"
