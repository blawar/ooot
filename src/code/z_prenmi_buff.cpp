#define INTERNAL_SRC_CODE_Z_PRENMI_BUFF_C
#include "global.h"
#include "z_prenmi_buff.h"
#include "def/gettime.h"
#include "def/z_prenmi_buff.h"

#define COLD_RESET 0
#define NMI 1

void PreNmiBuff_Init(PreNmiBuff* pthis) {
    pthis->resetting = false;

    pthis->resetCount = 0;
    pthis->duration = 0;

    pthis->resetTime = 0;
}

void PreNmiBuff_SetReset(PreNmiBuff* pthis) {
    pthis->resetting = true;
    pthis->resetTime = osGetTime();
}

u32 PreNmiBuff_IsResetting(PreNmiBuff* pthis) {
    return pthis->resetting;
}
