#pragma once
#define Z_ITEM_INBOX_H

#include "global.h"
#include "ultra64.h"

struct ItemInbox;

typedef void (*ItemInboxActionFunc)(struct ItemInbox*, GlobalContext*);

struct ItemInbox
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ItemInboxActionFunc actionFunc;
};
