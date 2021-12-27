#define INTERNAL_SRC_BOOT_LOGUTILS_C
#include "global.h"
#include "vt.h"
#include "def/logutils.h"

f32 LogUtils_CheckFloatRange(const char* exp, s32 line, const char* valueName, f32 value, const char* minName, f32 min,
                             const char* maxName, f32 max) {
    return value;
}

s32 LogUtils_CheckIntRange(const char* exp, s32 line, const char* valueName, s32 value, const char* minName, s32 min,
                           const char* maxName, s32 max) {
    return value;
}

void LogUtils_LogHexDump(void* ptr, s32 size0) {
}

void LogUtils_LogPointer(s32 value, u32 max, void* ptr, const char* name, const char* file, s32 line) {
}

void LogUtils_CheckBoundary(const char* name, s32 value, s32 unk, const char* file, s32 line) {
}

void LogUtils_CheckNullPointer(const char* exp, void* ptr, const char* file, s32 line) {
}

void LogUtils_CheckValidPointer(const char* exp, void* ptr, const char* file, s32 line) {
}

void LogUtils_LogThreadId(const char* name, s32 line) {
}

void LogUtils_HungupThread(const char* name, s32 line) {
}

void LogUtils_ResetHungup(void) {
}
