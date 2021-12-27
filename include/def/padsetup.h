#pragma once
#ifdef INTERNAL_SRC_CODE_PADSETUP_C
s32 PadSetup_Init(OSMesgQueue* mq, u8* outMask, OSContStatus* status);
#else
s32 PadSetup_Init(struct OSMesgQueue* mq, u8* outMask, struct OSContStatus* status);
#endif
