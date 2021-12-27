#define INTERNAL_SRC_CODE_MEMPAK_C
#include "global.h"
#include "ultra64/message.h"
#include "ultra64/pfs.h"
#include "padmgr.h"
#include "def/mempak.h"
#include "def/padmgr.h"
#include "def/pfsallocatefile.h"
#include "def/pfsdeletefile.h"
#include "def/pfsfilestate.h"
#include "def/pfsfindfile.h"
#include "def/pfsfreeblocks.h"
#include "def/pfsinitpak.h"
#include "def/pfsreadwritefile.h"

OSPfs sMempakPfsHandle;
s32 sMempakFreeBytes;
s32 sMempakFiles[10];

u16 sMempakCompanyCode = 1;
u32 sMempakGameCode = 1;

// "ZELDA DEMO TOOL "
u8 sMempakGameName[0x10] = { 0x33, 0x1E, 0x25, 0x1D, 0x1A, 0x0F, 0x1D, 0x1E,
                             0x26, 0x28, 0x0F, 0x2D, 0x28, 0x28, 0x25, 0x0F };
u8 sMempakExtName[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

s32 Mempak_Init(s32 controllerNb) {
    return 0;
}

s32 Mempak_GetFreeBytes(s32 controllerNb) {
    return sMempakFreeBytes;
}

s32 Mempak_FindFile(s32 controllerNb, char start, char end) {
    return 0;
}

s32 Mempak_Write(s32 controllerNb, char idx, void* buffer, s32 offset, s32 size) {
    return 0;
}

s32 Mempak_Read(s32 controllerNb, char idx, void* buffer, s32 offset, s32 size) {
    return 0;
}

s32 Mempak_Alloc(s32 controllerNb, char* idx, s32 size) {
    return 0;
}

s32 Mempak_DeleteFile(s32 controllerNb, char idx) {
    return 0;
}

s32 Mempak_GetFileSize(s32 controllerNb, char idx) {
    return 0;
}
