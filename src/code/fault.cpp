#define INTERNAL_SRC_CODE_FAULT_C
#include "global.h"
#include "vt.h"
#include "alloca.h"
#include "padmgr.h"
#include "n64fault.h"
#include "ultra64/convert.h"
#include "ultra64/exception.h"
#include "ultra64/rcp.h"
#include "def/fault.h"
#include "def/sleep.h"

// data
const char* sExceptionNames[] = {
    "Interrupt",
    "TLB modification",
    "TLB exception on load",
    "TLB exception on store",
    "Address error on load",
    "Address error on store",
    "Bus error on inst.",
    "Bus error on data",
    "System call exception",
    "Breakpoint exception",
    "Reserved instruction",
    "Coprocessor unusable",
    "Arithmetic overflow",
    "Trap exception",
    "Virtual coherency on inst.",
    "Floating point exception",
    "Watchpoint exception",
    "Virtual coherency on data",
    "Unimplemented operation",
    "Invalid operation",
    "Division by zero",
    "Overflow",
    "Underflow",
    "Inexact operation",
};

// bss
static FaultThreadStruct* sFaultStructPtr;
static u8 sFaultIsWaitingForInput;
static char sFaultStack[0x600];
static StackEntry sFaultThreadInfo;
FaultThreadStruct gFaultStruct;

void Fault_SleepImpl(u32 duration) {
    u64 value = (duration * OS_CPU_COUNTER) / 1000ull;

    Sleep_Cycles(value);
}

void Fault_ClientProcessThread(void* arg) {
}

void Fault_ProcessClientContext(FaultClientContext* ctx) {
}

u32 Fault_ProcessClient(u32 callback, u32 param0, u32 param1) {
    return 0;
}

void Fault_AddClient(FaultClient* client, void* callback, void* param0, void* param1) {
}

void Fault_RemoveClient(FaultClient* client) {
}

void Fault_AddAddrConvClient(FaultAddrConvClient* client, void* callback, void* param) {
}

void Fault_RemoveAddrConvClient(FaultAddrConvClient* client) {
}

u32 Fault_ConvertAddress(FaultAddrConvClient* client) {
    return 0;
}

void Fault_Sleep(u32 duration) {
    Fault_SleepImpl(duration);
}

void Fault_PadCallback(Input* input) {
    //! @bug This function is not called correctly and thus will crash from reading a bad pointer at 0x800C7E4C
}

void Fault_UpdatePadImpl() {
}

u32 Fault_WaitForInputImpl() {
    return 0;
}

void Fault_WaitForInput() {
}

void Fault_DrawRec(s32 x, s32 y, s32 w, s32 h, u16 color) {
}

void Fault_FillScreenBlack() {
}

void Fault_FillScreenRed() {
}

void Fault_DrawCornerRec(u16 color) {
}

void Fault_PrintFReg(s32 idx, f32* value) {
}

void Fault_LogFReg(s32 idx, f32* value) {
}

void Fault_PrintFPCR(u32 value) {
}

void Fault_LogFPCR(u32 value) {
}

void Fault_PrintThreadContext(OSThread* t) {
}

void Fault_LogThreadContext(OSThread* t) {
}

OSThread* Fault_FindFaultedThread() {
    return NULL;
}

void Fault_Wait5Seconds(void) {
}

void Fault_WaitForButtonCombo() {
}

void Fault_DrawMemDumpPage(const char* title, u32* addr, u32 param_3) {
}

void Fault_DrawMemDump(u32 pc, u32 sp, u32 unk0, u32 unk1) {
}

void Fault_WalkStack(u32* spPtr, u32* pcPtr, u32* raPtr) {
}

void Fault_DrawStackTrace(OSThread* thread, s32 x, s32 y, s32 height) {
}

void Fault_LogStackTrace(OSThread* thread, s32 height) {
}

void Fault_ResumeThread(OSThread* t) {
}

void Fault_CommitFB() {
}

void Fault_ProcessClients(void) {
}

void Fault_UpdatePad() {
}

void Fault_ThreadEntry(void* arg) {
}

void Fault_SetFB(void* fb, u16 w, u16 h) {
}

void Fault_Init(void) {
}

void Fault_HangupFaultClient(const char* arg0, const char* arg1) {
}

void Fault_AddHungupAndCrashImpl(const char* arg0, const char* arg1) {
}

void Fault_AddHungupAndCrash(const char* filename, u32 line) {
}

