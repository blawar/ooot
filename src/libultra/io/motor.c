#include "global.h"

#define BANK_ADDR 0x400
#define MOTOR_ID 0x80

//OSPifRam osPifBuffers[MAXCONTROLLERS];

s32 __osMotorAccess(struct OSPfs* pfs, u32 vibrate) {
    return 0;
}

void _MakeMotorData(s32 channel, struct OSPifRam* buf) {
}

s32 osMotorInit(struct OSMesgQueue* ctrlrqueue, struct OSPfs* pfs, s32 channel) {
    return 0; // "Recognized rumble pak"
}
