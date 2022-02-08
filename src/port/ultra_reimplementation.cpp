#include <stdio.h>
#include <string.h>
//#include <stdarg.h>
//#include "global.h"

extern "C" {
#include "global.h"
//#include "ultra64/message.h"
//#include "ultra64/convert.h"
//#include "ultra64/exception.h"
//#include "ultra64/time.h"
//#include "ultra64/pi.h"
#include "ultra64/vi.h"
#include "ultra64/rcp.h"

extern u32 osTvType;

extern OSViMode osViModePalLan1;
extern OSViMode osViModeMpalLan1;
extern OSViMode osViModeNtscLan1;

OSViContext vi[2] = { 0 };
OSViContext* __osViCurr = &vi[0];
OSViContext* __osViNext = &vi[1];

u32 __additional_scanline = 0;//Needs to be connected to GLideN64
}

typedef u32 OSEvent;
typedef void* OSMesg;
typedef u64 OSTime;
typedef s32 OSPri;

#ifdef TARGET_WEB
#include <emscripten.h>
#endif

#if defined(__SWITCH__) && !defined(_MSC_VER)
#include "nx.h"
#endif

#define UNUSED

#define OS_CLOCK_RATE           62500000LL
u64 osClockRate = OS_CLOCK_RATE;

s32 osPiStartDma(struct OSIoMesg* mb, UNUSED s32 priority, UNUSED s32 direction, uintptr_t devAddr, void* vAddr, size_t nbytes, struct OSMesgQueue* mq)
{
	memcpy(vAddr, (const void*)devAddr, nbytes);
	return 0;
}

void osSetEventMesg(UNUSED OSEvent e, UNUSED OSMesgQueue* mq, UNUSED OSMesg msg)
{
}

s32 osJamMesg(UNUSED OSMesgQueue* mq, UNUSED OSMesg msg, UNUSED s32 flag)
{
	return 0;
}

/*s32 osSendMesg(UNUSED OSMesgQueue* mq, UNUSED OSMesg msg, UNUSED s32 flag)
{
	return 0;
}*/

extern "C" {
	uintptr_t osVirtualToPhysical(void* addr) {
		return (uintptr_t)addr;
	}

	void osCreateViManager(UNUSED OSPri pri)
	{
		/*u32 prevInt;
		OSPri newPri;
		OSPri currentPri;

		if (!__osViDevMgr.initialized) {
			__osTimerServicesInit();
			__additional_scanline = 0;
			osCreateMesgQueue(&viEventQueue, viEventBuf, 5);
			viRetraceMsg.hdr.type = OS_MESG_TYPE_VRETRACE;
			viRetraceMsg.hdr.pri = OS_MESG_PRI_NORMAL;
			viRetraceMsg.hdr.retQueue = NULL;
			viCounterMsg.hdr.type = OS_MESG_TYPE_COUNTER;
			viCounterMsg.hdr.pri = OS_MESG_PRI_NORMAL;
			viCounterMsg.hdr.retQueue = NULL;
			osSetEventMesg(OS_EVENT_VI, &viEventQueue, &viRetraceMsg);
			osSetEventMesg(OS_EVENT_COUNTER, &viEventQueue, &viCounterMsg);
			newPri = -1;
			currentPri = osGetThreadPri(NULL);
			if (currentPri < pri) {
				newPri = currentPri;
				osSetThreadPri(NULL, pri);
			}

			prevInt = __osDisableInt();
			__osViDevMgr.initialized = true;
			__osViDevMgr.mgrThread = &viThread;
			__osViDevMgr.cmdQueue = &viEventQueue;
			__osViDevMgr.eventQueue = &viEventQueue;
			__osViDevMgr.acccessQueue = NULL;
			__osViDevMgr.piDmaCallback = NULL;
			__osViDevMgr.epiDmaCallback = NULL;

			osCreateThread(&viThread, 0, &viMgrMain, &__osViDevMgr, viThreadStack + sizeof(viThreadStack), pri);
			__osViInit();
			osStartThread(&viThread);
			__osRestoreInt(prevInt);
			if (newPri != -1) {
				osSetThreadPri(NULL, newPri);
			}
		}*/
	}

	void osViSetMode(UNUSED OSViMode* mode) {
		__osViNext->modep = mode;
		__osViNext->state = 1;
		__osViNext->features = __osViNext->modep->comRegs.ctrl;
	}
}

void osViSetEvent(UNUSED OSMesgQueue* mq, UNUSED OSMesg msg, UNUSED u32 retraceCount)
{
}

extern "C" {
	void __osViSwapContext(void) {
		register OSViMode* viMode;
		register OSViContext* viNext;
		u32 origin;
		u32 hStart;
		u32 vstart;
		u32 sp34;
		u32 field;
		register u32 s2;

		field = 0;
		viNext = __osViNext;
		viMode = viNext->modep;
		field = HW_REG(VI_V_CURRENT_LINE_REG, u32) & 1;
		s2 = osVirtualToPhysical(viNext->buffer);
		origin = (viMode->fldRegs[field].origin) + s2;
		if (viNext->state & 2) {
			viNext->x.scale |= viMode->comRegs.xScale & ~0xFFF;
		}
		else {
			viNext->x.scale = viMode->comRegs.xScale;
		}
		if (viNext->state & 4) {
			sp34 = (u32)(viMode->fldRegs[field].yScale & 0xFFF);
			viNext->y.scale = viNext->y.factor * sp34;
			viNext->y.scale |= viMode->fldRegs[field].yScale & ~0xFFF;
		}
		else {
			viNext->y.scale = viMode->fldRegs[field].yScale;
		}

		vstart = (viMode->fldRegs[field].vStart - (__additional_scanline << 0x10)) + __additional_scanline;
		hStart = viMode->comRegs.hStart;

		if (viNext->state & 0x20) {
			hStart = 0;
		}
		if (viNext->state & 0x40) {
			viNext->y.scale = 0;
			origin = osVirtualToPhysical(viNext->buffer);
		}
		if (viNext->state & 0x80) {
			viNext->y.scale = (viNext->y.offset << 0x10) & 0x3FF0000;
			origin = osVirtualToPhysical(viNext->buffer);
		}
		HW_REG(VI_ORIGIN_REG, u32) = origin;
		HW_REG(VI_WIDTH_REG, u32) = viMode->comRegs.width;
		HW_REG(VI_BURST_REG, u32) = viMode->comRegs.burst;
		HW_REG(VI_V_SYNC_REG, u32) = viMode->comRegs.vSync;
		HW_REG(VI_H_SYNC_REG, u32) = viMode->comRegs.hSync;
		HW_REG(VI_LEAP_REG, u32) = viMode->comRegs.leap;
		HW_REG(VI_H_START_REG, u32) = hStart;
		HW_REG(VI_V_START_REG, u32) = vstart;
		HW_REG(VI_V_BURST_REG, u32) = viMode->fldRegs[field].vBurst;
		HW_REG(VI_INTR_REG, u32) = viMode->fldRegs[field].vIntr;
		HW_REG(VI_X_SCALE_REG, u32) = viNext->x.scale;
		HW_REG(VI_Y_SCALE_REG, u32) = viNext->y.scale;
		HW_REG(VI_CONTROL_REG, u32) = viNext->features;
		__osViNext = __osViCurr;
		__osViCurr = viNext;
		*__osViNext = *__osViCurr;
	}

	void __osViInit(void) {
		bzero(vi, sizeof(vi));
		__osViCurr = &vi[0];
		__osViNext = &vi[1];

		__osViNext->retraceCount = 1;
		__osViCurr->retraceCount = 1;
		__osViNext->buffer = (void*)0x80000000;
		__osViCurr->buffer = (void*)0x80000000;

		if (osTvType == OS_TV_PAL) {
			__osViNext->modep = &osViModePalLan1;
		}
		else if (osTvType == OS_TV_MPAL) {
			__osViNext->modep = &osViModeMpalLan1;
		}
		else {
			__osViNext->modep = &osViModeNtscLan1;
		}

		__osViNext->state = 0x20;
		__osViNext->features = __osViNext->modep->comRegs.ctrl;


		HW_REG(VI_CONTROL_REG, u32) = 0;
		__osViSwapContext();
	}

	void osViBlack(u8 active) {
		if (active) {
			__osViNext->state |= 0x20;
		}
		else {
			__osViNext->state &= ~0x20;
		}
	}

	void osViExtendVStart(u32 arg0) {
		__additional_scanline = arg0;
	}

	void osViSetSpecialFeatures(UNUSED u32 func) {
		if (func & OS_VI_GAMMA_ON) {
			__osViNext->features |= OS_VI_GAMMA;
		}
		if (func & OS_VI_GAMMA_OFF) {
			__osViNext->features &= ~OS_VI_GAMMA;
		}
		if (func & OS_VI_GAMMA_DITHER_ON) {
			__osViNext->features |= OS_VI_GAMMA_DITHER;
		}
		if (func & OS_VI_GAMMA_DITHER_OFF) {
			__osViNext->features &= ~OS_VI_GAMMA_DITHER;
		}
		if (func & OS_VI_DIVOT_ON) {
			__osViNext->features |= OS_VI_DIVOT;
		}
		if (func & OS_VI_DIVOT_OFF) {
			__osViNext->features &= ~OS_VI_DIVOT;
		}
		if (func & OS_VI_DITHER_FILTER_ON) {
			__osViNext->features |= OS_VI_DITHER_FILTER;
			__osViNext->features &= ~(OS_VI_UNK200 | OS_VI_UNK100);
		}
		if (func & OS_VI_DITHER_FILTER_OFF) {
			__osViNext->features &= ~OS_VI_DITHER_FILTER;
			__osViNext->features |= __osViNext->modep->comRegs.ctrl & (OS_VI_UNK200 | OS_VI_UNK100);
		}
		__osViNext->state |= 8;
	}

	void osViSetXScale(f32 value) {
		register u32 nomValue;

		__osViNext->x.factor = value;
		__osViNext->state |= 0x2;

		nomValue = __osViNext->modep->comRegs.xScale & 0xFFF;
		__osViNext->x.scale = (u32)(__osViNext->x.factor * nomValue) & 0xFFF;
	}

	void osViSetYScale(f32 scale) {
		__osViNext->y.factor = scale;
		__osViNext->state |= 4;
	}
	
	void osViSwapBuffer(void* vaddr) {
		__osViNext->buffer = vaddr;
		__osViNext->state |= 0x10; // TODO: figure out what this flag means
	}
}

#ifdef _MSC_VER
#include <windows.h>

OSTime osGetTime(void) {
    return GetTickCount64();
}
#else
OSTime osGetTime(void)
{
	return 0;
}
#endif

void osWritebackDCacheAll(void)
{
}

void osWritebackDCache(UNUSED void* a, UNUSED size_t b)
{
}

void osInvalDCache(UNUSED void* a, UNUSED size_t b)
{
}

u32 osGetCount(void)
{
	static u32 counter;
	return counter++;
}

s32 osAiSetFrequency(u32 freq)
{
	u32 a1;
	s32 a2;
	u32 D_8033491C;

	D_8033491C = 0x02E6D354;

	a1 = D_8033491C / (float)freq + .5f;

	if(a1 < 0x84)
	{
		return -1;
	}

	a2 = (a1 / 66) & 0xff;
	if(a2 > 16)
	{
		a2 = 16;
	}

	return D_8033491C / (s32)a1;
}

s32 osEepromProbe(UNUSED OSMesgQueue* mq)
{
	return 1;
}

#define OS_READ     0 // device -> RDRAM
#define OS_WRITE    1 // device <- RDRAM
#define SRAM_SIZE 0x8000

extern "C" {
	void SsSram_ReadWrite(u32 address, void* buffer, size_t nbytes, s32 direction)
	{
		if(address < 0xA8000000)
		{
			return;
		}

		address -= 0xA8000000;

		static u8 content[SRAM_SIZE] = { 0 };

		if(direction == OS_READ)
		{
			s32 ret = -1;

#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
			mountSaveData();

			FILE* fp = fopen("sv:/oot.sav", "rb");
			if(fp == NULL)
			{
				fp = fopen("sdmc:/oot.sav", "rb");

				if(fp == NULL)
				{
					unmountSaveData();
					return -1;
				}
			}

			if(fread(content, 1, SRAM_SIZE, fp) == SRAM_SIZE)
			{
				memcpy(buffer, content + address, nbytes);
				ret = 0;
			}
			fclose(fp);
			unmountSaveData();
#else
			FILE* fp = nullptr;

			if(fopen_s(&fp, "oot.sav", "rb") != 0)
			{
				return;
			}
			if(fread(content, 1, SRAM_SIZE, fp) == SRAM_SIZE)
			{
				memcpy(buffer, content + address, nbytes);
				ret = 0;
			}
			fclose(fp);
#endif
		}
		else if(direction == OS_WRITE)
		{
			memcpy(content + address, buffer, nbytes);

#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
			mountSaveData();
			FILE* fp = fopen("sv:/oot.sav", "wb");

			if(fp == NULL)
			{
				fp = fopen("sdmc:/oot.sav", "wb");

				if(fp == NULL)
				{
					return -1;
				}
			}

			s32 ret = fwrite(content, 1, SRAM_SIZE, fp) == SRAM_SIZE ? 0 : -1;
			fclose(fp);
			commitSave();
			unmountSaveData();
#else
			FILE* fp = nullptr;

			if(fopen_s(&fp, "oot.sav", "wb") != 0)
			{
				return;
			}

			s32 ret = fwrite(content, 1, SRAM_SIZE, fp) == SRAM_SIZE ? 0 : -1;
			fclose(fp);
#endif
		}
	}
}

s32 osEepromLongRead(UNUSED OSMesgQueue* mq, u8 address, u8* buffer, int nbytes)
{
	u8 content[512];
	s32 ret = -1;

#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
	mountSaveData();

	FILE* fp = fopen("sv:/oot.sav", "rb");
	if(fp == NULL)
	{
		fp = fopen("sdmc:/oot.sav", "rb");

		if(fp == NULL)
		{
			unmountSaveData();
			return -1;
		}
	}

	if(fread(content, 1, 512, fp) == 512)
	{
		memcpy(buffer, content + address * 8, nbytes);
		ret = 0;
	}
	fclose(fp);
	unmountSaveData();
#else
    FILE* fp = nullptr; 

    if (fopen_s(&fp, "oot.sav", "rb") != 0)
	{
		return -1;
	}
	if(fread(content, 1, 512, fp) == 512)
	{
		memcpy(buffer, content + address * 8, nbytes);
		ret = 0;
	}
	fclose(fp);
#endif
	return ret;
}

s32 osEepromLongWrite(UNUSED OSMesgQueue* mq, u8 address, u8* buffer, int nbytes)
{
	u8 content[512] = {0};
	if(address != 0 || nbytes != 512)
	{
		osEepromLongRead(mq, 0, content, 512);
	}
	memcpy(content + address * 8, buffer, nbytes);

#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
	mountSaveData();
	FILE* fp = fopen("sv:/oot.sav", "wb");

	if(fp == NULL)
	{
		fp = fopen("sdmc:/oot.sav", "wb");

		if(fp == NULL)
		{
			return -1;
		}
	}

	s32 ret = fwrite(content, 1, 512, fp) == 512 ? 0 : -1;
	fclose(fp);
	commitSave();
	unmountSaveData();
#else
    FILE* fp = nullptr;

	if (fopen_s(&fp, "oot.sav", "wb") != 0)
	{
		return -1;
	}

	s32 ret = fwrite(content, 1, 512, fp) == 512 ? 0 : -1;
	fclose(fp);
#endif
	return ret;
}

u32 bcmp(void* s1, void* s2, u32 size) {
    const u8* _s1 = (const u8*)s1;
    const u8* _s2 = (const u8*)s2;

    while (size > 0) {
        if (*_s1++ != *_s2++) {
            return 1;
        }
        size--;
    }

    return 0;
}

#include <stdio.h>
#include <string>
#include <vector>
#include <stdexcept>

std::wstring utf8_to_utf16(const std::string& utf8) {
    std::vector<unsigned long> unicode;
    size_t i = 0;
    while (i < utf8.size()) {
        unsigned long uni;
        size_t todo;
        bool error = false;
        unsigned char ch = utf8[i++];
        if (ch <= 0x7F) {
            uni = ch;
            todo = 0;
        } else if (ch <= 0xBF) {
            throw std::logic_error("not a UTF-8 string");
        } else if (ch <= 0xDF) {
            uni = ch & 0x1F;
            todo = 1;
        } else if (ch <= 0xEF) {
            uni = ch & 0x0F;
            todo = 2;
        } else if (ch <= 0xF7) {
            uni = ch & 0x07;
            todo = 3;
        } else {
            throw std::logic_error("not a UTF-8 string");
        }
        for (size_t j = 0; j < todo; ++j) {
            if (i == utf8.size())
                throw std::logic_error("not a UTF-8 string");
            unsigned char ch = utf8[i++];
            if (ch < 0x80 || ch > 0xBF)
                throw std::logic_error("not a UTF-8 string");
            uni <<= 6;
            uni += ch & 0x3F;
        }
        if (uni >= 0xD800 && uni <= 0xDFFF)
            throw std::logic_error("not a UTF-8 string");
        if (uni > 0x10FFFF)
            throw std::logic_error("not a UTF-8 string");
        unicode.push_back(uni);
    }
    std::wstring utf16;
    for (size_t i = 0; i < unicode.size(); ++i) {
        unsigned long uni = unicode[i];
        if (uni <= 0xFFFF) {
            utf16 += (wchar_t)uni;
        } else {
            uni -= 0x10000;
            utf16 += (wchar_t)((uni >> 10) + 0xD800);
            utf16 += (wchar_t)((uni & 0x3FF) + 0xDC00);
        }
    }
    return utf16;
}

static char buffer[0x10000];

void osSyncPrintf(const char* fmt, ...) {
    memset(buffer, 0, sizeof(buffer));
    va_list arg;
    int done;
    va_start(arg, fmt);
    vsprintf(buffer, fmt, arg);
    va_end(arg);

	auto s = utf8_to_utf16(buffer);
	//OutputDebugStringA(buffer);
	OutputDebugString(s.c_str());
}

#include "jpeg_decoder.h"
#include "color.h"
#include <memory>
#include "ultra64/gbi.h"

static_assert(sizeof(Color_RGB8) == 3, "incorrect Color_RGB8 size");

extern "C" {
	s32 Jpeg_Decode(void* data, void* zbuffer, void* work, u32 workSize)
	{
		auto decoder = std::make_unique<Jpeg::Decoder>((const u8*)data, SCREEN_WIDTH * SCREEN_HEIGHT * 2);

		if(decoder->GetResult() != Jpeg::Decoder::OK)
		{
			return 1;
		}

		Color_RGB8* p = (Color_RGB8*)decoder->GetImage();
		u64 sz = decoder->GetImageSize() / sizeof(Color_RGB8);
		u16* out = (u16*)zbuffer;

		for(u64 i = 0; i < sz; i++, p++, out++)
		{
			u8 r = p->r / 8;
			u8 g = p->g / 8;
			u8 b = p->b / 8;
			*out = BE16((r << 11) + (g << 6) + (b << 1) + 1);
			//*out = BE16(1);
		}

		return 0;
	}
}