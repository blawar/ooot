#define INTERNAL_SRC_CODE_SYS_UCODE_C
#include "global.h"
#include "rsp.h"
#include "def/sys_ucode.h"

u64* D_8012DBA0 = (u64*)&D_80155F50;
u64* D_8012DBA4 = (u64*)&D_80157580;

u64* SysUcode_GetUCodeBoot(void) {
    return (u64*)&D_80009320;
}

u64 SysUcode_GetUCodeBootSize(void) {
    return sizeof(D_80009320);
}

u64* SysUcode_GetUCode(void) {
    return D_8012DBA0;
}

u64 SysUcode_GetUCodeSize(void) {
    return sizeof(D_80155F50);
}

u64* SysUcode_GetUCodeData(void) {
    return D_8012DBA4;
}

u64 SysUcode_GetUCodeDataSize(void) {
    return sizeof(D_80157580);
}
