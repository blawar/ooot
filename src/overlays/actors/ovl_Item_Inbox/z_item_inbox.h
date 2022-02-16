#pragma once
#define Z_ITEM_INBOX_H

#include "ultra64.h"
#include "global.h"

struct ItemInbox;

typedef void (*ItemInboxActionFunc)(struct ItemInbox*, GlobalContext*);


struct ItemInbox {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ ItemInboxActionFunc actionFunc;
}; 


