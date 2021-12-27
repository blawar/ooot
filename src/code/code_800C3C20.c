#define INTERNAL_SRC_CODE_CODE_800C3C20_C
#include "global.h"
#include "z64math.h"
#include "z64audio.h"
#include "def/code_800C3C20.h"
#include "def/code_800F7260.h"

u8 D_8012D200[] = {
    0, 1, 2, 3, 4, 5, 6,
};

void func_800C3C20(void) {
    s32 i;

    for (i = 0; (i < ARRAY_COUNT(D_8012D200)) & 0xFFFFFFFF; i++) {
        Audio_StopSfxByBank(D_8012D200[i]);
    }
}
