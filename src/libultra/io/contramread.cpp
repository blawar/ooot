#define INTERNAL_SRC_LIBULTRA_IO_CONTRAMREAD_C
#include "global.h"
#include "def/contramread.h"

#define BLOCKSIZE 32

s32 __osPfsLastChannel = -1;

s32 __osContRamRead(struct OSMesgQueue* ctrlrqueue, s32 channel, u16 addr, u8* data) {
	return 0;
}
