#define INTERNAL_SRC_CODE_Z_PRENMI_BUFF_C
#include "global.h"
#include "z_prenmi_buff.h"
#include "def/gettime.h"
#include "def/z_prenmi_buff.h"

#define COLD_RESET 0
#define NMI 1

void PreNmiBuff_Init(PreNmiBuff* this) {
    this->resetting = false;

    this->resetCount = 0;
    this->duration = 0;

    this->resetTime = 0;
}

void PreNmiBuff_SetReset(PreNmiBuff* this) {
    this->resetting = true;
    this->resetTime = osGetTime();
}

u32 PreNmiBuff_IsResetting(PreNmiBuff* this) {
    return this->resetting;
}
