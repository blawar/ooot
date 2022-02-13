#define INTERNAL_SRC_CODE_SYS_UCODE_C
#include "global.h"
#include "rsp.h"
#include "def/sys_ucode.h"

u64* D_8012DBA0 = (u64*)&rspF3DZEXText;
u64* D_8012DBA4 = (u64*)&rspF3DZEXData;

u64* SysUcode_GetUCodeBoot(void) {
    return &rspBootText;
}

u64 SysUcode_GetUCodeBootSize(void) {
    return sizeof(rspBootText);
}

u64* SysUcode_GetUCode(void) {
    return D_8012DBA0;
}

u64 SysUcode_GetUCodeSize(void) {
    return sizeof(rspF3DZEXText);
}

u64* SysUcode_GetUCodeData(void) {
    return D_8012DBA4;
}

u64 SysUcode_GetUCodeDataSize(void) {
    return sizeof(rspF3DZEXData);
}
