#include <stdio.h>
#include <string.h>
//#include <stdarg.h>
//#include "global.h"

#include "global.h"
#include "vt.h"
//#include "ultra64/message.h"
//#include "ultra64/convert.h"
//#include "ultra64/exception.h"
//#include "ultra64/time.h"
//#include "ultra64/pi.h"
#include "ultra64/vi.h"
#include "ultra64/rcp.h"
#include <thread>
#include <chrono>
#include "../../AziAudio/AziAudio/AudioSpec.h"

HardwareRegisters hw_regs;

extern u32 osTvType;

extern OSViMode osViModePalLan1;
extern OSViMode osViModeMpalLan1;
extern OSViMode osViModeNtscLan1;

OSViMode gViConfigMode;

s8 D_80009430			= 1;
u8 gViConfigAdditionalScanLines = 0;


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

#define OS_CLOCK_RATE 62500000LL
u64 osClockRate = OS_CLOCK_RATE;

u32 osGetCount(void);
s32 osAiSetNextBuffer(void* buf, u32 size);
s32 osAiSetFrequency(u32 frequency);

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

#ifdef _MSC_VER
#include <windows.h>

OSTime osGetTime(void)
{
	return timeGetTime();
}
#else
OSTime osGetTime(void)
{
	//Don't used (uint32_t)time(NULL), it's not accurate enough for rumble!
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

s32 osEepromProbe(UNUSED OSMesgQueue* mq)
{
	return 1;
}

#define OS_READ 0  // device -> RDRAM
#define OS_WRITE 1 // device <- RDRAM
#define SRAM_SIZE 0x8000

void SsSram_ReadWrite(u32 address, void* buffer, size_t nbytes, s32 direction)
{
	if(address < 0xA8000000)
	{
		return;
	}

	address -= 0xA8000000;

	static u8 content[SRAM_SIZE] = {0};

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

	if(fopen_s(&fp, "oot.sav", "rb") != 0)
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

	if(fopen_s(&fp, "oot.sav", "wb") != 0)
	{
		return -1;
	}

	s32 ret = fwrite(content, 1, 512, fp) == 512 ? 0 : -1;
	fclose(fp);
#endif
	return ret;
}

u32 bcmp(void* s1, void* s2, u32 size)
{
	const u8* _s1 = (const u8*)s1;
	const u8* _s2 = (const u8*)s2;

	while(size > 0)
	{
		if(*_s1++ != *_s2++)
		{
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

std::wstring utf8_to_utf16(const std::string& utf8)
{
	std::vector<unsigned long> unicode;
	size_t i = 0;
	while(i < utf8.size())
	{
		unsigned long uni;
		size_t todo;
		bool error	 = false;
		unsigned char ch = utf8[i++];
		if(ch <= 0x7F)
		{
			uni  = ch;
			todo = 0;
		}
		else if(ch <= 0xBF)
		{
			throw std::logic_error("not a UTF-8 string");
		}
		else if(ch <= 0xDF)
		{
			uni  = ch & 0x1F;
			todo = 1;
		}
		else if(ch <= 0xEF)
		{
			uni  = ch & 0x0F;
			todo = 2;
		}
		else if(ch <= 0xF7)
		{
			uni  = ch & 0x07;
			todo = 3;
		}
		else
		{
			throw std::logic_error("not a UTF-8 string");
		}
		for(size_t j = 0; j < todo; ++j)
		{
			if(i == utf8.size())
				throw std::logic_error("not a UTF-8 string");
			unsigned char ch = utf8[i++];
			if(ch < 0x80 || ch > 0xBF)
				throw std::logic_error("not a UTF-8 string");
			uni <<= 6;
			uni += ch & 0x3F;
		}
		if(uni >= 0xD800 && uni <= 0xDFFF)
			throw std::logic_error("not a UTF-8 string");
		if(uni > 0x10FFFF)
			throw std::logic_error("not a UTF-8 string");
		unicode.push_back(uni);
	}
	std::wstring utf16;
	for(size_t i = 0; i < unicode.size(); ++i)
	{
		unsigned long uni = unicode[i];
		if(uni <= 0xFFFF)
		{
			utf16 += (wchar_t)uni;
		}
		else
		{
			uni -= 0x10000;
			utf16 += (wchar_t)((uni >> 10) + 0xD800);
			utf16 += (wchar_t)((uni & 0x3FF) + 0xDC00);
		}
	}
	return utf16;
}

static char buffer[0x10000];

void osSyncPrintf(const char* fmt, ...)
{
	//return; // temp disable this, because osSyncPrintf is not type safe, and globalCtx->state.frames gets passed to it as an object instead of expected int and it crashes
	memset(buffer, 0, sizeof(buffer));
	va_list arg;
	int done;
	va_start(arg, fmt);
	vsprintf(buffer, fmt, arg);
	va_end(arg);

	auto s = utf8_to_utf16(buffer);
	// OutputDebugStringA(buffer);
	OutputDebugString(s.c_str());
}

#include "jpeg_decoder.h"
#include "color.h"
#include <memory>
#include "ultra64/gbi.h"

static_assert(sizeof(Color_RGB8) == 3, "incorrect Color_RGB8 size");

s32 Jpeg_Decode(void* data, void* zbuffer, void* work, u32 workSize)
{
	auto decoder = std::make_unique<Jpeg::Decoder>((const u8*)data, SCREEN_WIDTH * SCREEN_HEIGHT * 2);

	if(decoder->GetResult() != Jpeg::Decoder::OK)
	{
		return 1;
	}

	Color_RGB8* p = (Color_RGB8*)decoder->GetImage();
	u64 sz	      = decoder->GetImageSize() / sizeof(Color_RGB8);
	u16* out      = (u16*)zbuffer;

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

#include "ultra64/rcp.h"

s32 osAiSetNextBuffer(void* buf, u32 size)
{
	static u8 D_80130500 = false;
	u32 bufAdjusted	     = (u32)buf;
	s32 status;

	if(D_80130500)
	{
		bufAdjusted = (u32)buf - 0x2000;
	}
	if((((u32)buf + size) & 0x1FFF) == 0)
	{
		D_80130500 = true;
	}
	else
	{
		D_80130500 = false;
	}

	// Originally a call to __osAiDeviceBusy
	status = hw_regs.AI_STATUS_REG;
	if(status & AI_STATUS_AI_FULL)
	{
		return -1;
	}

	// OS_K0_TO_PHYSICAL replaces osVirtualToPhysical, this replacement
	// assumes that only KSEG0 addresses are given
	hw_regs.AI_DRAM_ADDR_REG = bufAdjusted;
	hw_regs.AI_LEN_REG	      = size;
	AiLenChanged();
	return 0;
}

extern s32 osViClock;

u32 osAiGetLength()
{
	AiReadLength();
	return hw_regs.AI_LEN_REG;
}

s32 osAiSetFrequency(u32 frequency)
{
	u8 bitrate;
	f32 dacRateF = ((f32)osViClock / frequency) + 0.5f;
	u32 dacRate  = dacRateF;

	if(dacRate < 132)
	{
		return -1;
	}

	bitrate = (dacRate / 66);

	if(bitrate > 16)
	{
		bitrate = 16;
	}

	hw_regs.AI_DACRATE_REG = dacRate - 1;
	hw_regs.AI_BITRATE_REG = bitrate - 1;
	AiDacrateChanged(SYSTEM_NTSC);
	return osViClock / (s32)dacRate;
}

void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, s32 count)
{
	mq->mtqueue    = NULL;
	mq->fullqueue  = NULL;
	mq->validCount = 0;
	mq->first      = 0;
	mq->msgCount   = count;
	mq->msg	       = msg;
}

s32 osSendMesg(OSMesgQueue* mq, OSMesg mesg, s32 flag)
{
	register u32 index;

	while(mq->validCount >= mq->msgCount)
	{
		if(flag == OS_MESG_BLOCK)
		{
			int zyz = 0;
		}
		else
		{
			return -1;
		}
	}

	index	       = (mq->first + mq->validCount) % mq->msgCount;
	mq->msg[index] = mesg;
	mq->validCount++;

	if(mq->mtqueue->next != NULL)
	{
		// osStartThread(__osPopThread(&mq->mtqueue));
	}

	return 0;
}

s32 osRecvMesg(OSMesgQueue* mq, OSMesg* msg, s32 flag)
{
	while(mq->validCount == 0)
	{
		if(flag == OS_MESG_NOBLOCK)
		{
			return -1;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		/*else
		{
		    return -1; // TODO FIX HACK
		}*/
	}

	if(msg != NULL)
	{
		*msg = mq->msg[mq->first];
	}

	mq->first = (mq->first + 1) % mq->msgCount;
	mq->validCount--;

	if(mq->fullqueue->next != NULL)
	{
		// osStartThread(__osPopThread(&mq->fullqueue));
	}

	return 0;
}

uintptr_t check_pointer(uintptr_t p, u32 sz)
{
	if(IsBadReadPtr((const void*)p, sz))
	{
		return 0;
	}

	return p;
}