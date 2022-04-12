#pragma once
#define Z_ELF_MSG_H

#include "global.h"
#include "ultra64.h"
#include "z64actor.h"

struct ElfMsg;

typedef void (*ElfMsgActionFunc)(struct ElfMsg*, GlobalContext*);

struct ElfMsg
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ElfMsgActionFunc actionFunc;
};
