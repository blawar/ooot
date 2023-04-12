#define WIN32_LEAN_AND_MEAN
#define ENABLE_OPENGL
#define USE_GLIDEN64
#define DISABLE_AUDIO
#include "../../AziAudio/AziAudio/AudioSpec.h"
#include "controller/controllers.h"
#include "controller/tas.h"
#include "options.h"
#include "player/players.h"
#include "state.h"
#include "ultra64/rcp.h"
#include "window.h"
#include "z64audio.h"
#include "def/audioMgr.h"
#include "def/audio_rsp.h"

#ifndef MULTI_THREADED_GFX
#ifndef SINGLE_THREADED_GFX
//#define MULTI_THREADED_GFX
#endif
#endif

#ifdef MULTI_THREADED_GFX
#include <thread>
#include <mutex>

static std::mutex g_gfxMutex;
#endif

namespace oot
{
	State state;
}

#ifndef _MSC_VER
#define fopen_s(pFile, filename, mode) ((*(pFile)) = fopen((filename), (mode))) == NULL
#endif

static std::unique_ptr<platform::window::Base> gWindow;
static OSTask_t* g_currentTask = nullptr;

//#define _WINGDI_

#include "global.h"
#include "ultra64/vi.h"
//#include "sched.h"
#include "gfx.h"
#include "framerate.h"
#include "def/graph.h"
extern OSViMode osViModeNtscLan1;

#include <stdlib.h>
//#include "gfx/fast64.h"

//#include "gfx/renderer.h"

#include "configfile.h"
#include "debug.h"

//#include <cstdio>
#include <filesystem>

#include "gfxapi.h"
#include "nx.h"
#include "xxhash64.h"

extern "C"
{
	void gfx_highres_enable(bool enable);
	void gfx_switch_to_htc(bool enable);
}

OSMesg D_80339BEC;
OSMesgQueue gSIEventMesgQueue;

s8 gResetTimer;
s8 D_8032C648;

static uint8_t inited = 0;

bool verifyIntegrity()
{
	return true; // TODO FIX
	const static u64 ROM_SIZE = 0x800000;
	bool hasRom = false, hasPak = false;
	auto buffer = malloc(ROM_SIZE);

	if(!buffer)
	{
		return false;
	}

	for(const auto& entry : std::filesystem::directory_iterator("."))
	{
		if(entry.is_regular_file())
		{
			if(!hasRom && entry.path().extension() == ".z64" && entry.file_size() == ROM_SIZE)
			{
				FILE* f = nullptr;

				if(fopen_s(&f, entry.path().string().c_str(), "rb") == 0)
				{
					fread(buffer, 1, ROM_SIZE, f);
					fclose(f);

					if(XXHash64::hash(buffer, ROM_SIZE, 0) == 0xdaf4de8a170fdcbb)
					{
						hasRom = true;
						break;
					}
				}
			}
		}
	}

	for(const auto& entry : std::filesystem::directory_iterator("romfs"))
	{
		if(entry.is_regular_file())
		{
			if(entry.path().filename().string() == "!!base.pak")
			{
				hasPak = true;
				break;
			}
		}
	}

	if(!hasRom)
	{
		oot::log("error: unable to locate Z64 rom.\n");
	}

	if(!hasPak)
	{
		oot::log("error: unable to locate romfs/!!base.pak\n");
	}

	free(buffer);
	return hasRom && hasPak;
}

void main_func();
void azi_init();

static bool exists(const char* path)
{
	FILE* f;

	if(fopen_s(&f, "THE LEGEND OF ZELDA_HIRESTEXTURES.hts", "r") == 0)
	{
		fclose(f);
		return true;
	}
	return false;
}

void main_func(void)
{
	oot::log("initializing app\n");

	// Check if texture packs exist
	if(exists("THE LEGEND OF ZELDA_HIRESTEXTURES.hts"))
	{
		gfx_switch_to_htc(false);
		gfx_highres_enable(true);
	}
	else if(exists("THE LEGEND OF ZELDA_HIRESTEXTURES.htc"))
	{
		gfx_switch_to_htc(true);
		gfx_highres_enable(false);
	}
	else
	{
		gfx_switch_to_htc(false);
		gfx_highres_enable(false);
	}

#ifndef BUILD_NSO
	if(!verifyIntegrity())
	{
		return;
	}
#endif

	azi_init();

#ifdef _DEBUG // Record TAS to capture bugs and crashes
	      // oot::hid::tas::playTas(true);//Uncomment to play back TAS/crash report from end-users

	/*if (!oot::hid::tas::isTasPlaying()) TODO FIX
		oot::config().game().recordTas(true);*/
#endif

	if(oot::config().game().graphicsEnabled())
	{
		gWindow = platform::window::create("The Legend of Zelda - Ocarina of Time", oot::config().game().fullscreen());
		gfx_init("THE LEGEND OF ZELDA", &osViModeNtscLan1);
		gWindow->resize(-1, -1);
	}

	oot::hid::controllers().scan();

	inited = 1;

#ifdef MULTI_THREADED_GFX
	std::thread gameLoopThread([]() { Graph_ThreadEntry(0); });

	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	
	while(gameLoopThread.joinable())
	{
		gWindow->handle_events();

		if(g_currentTask != nullptr)
		{
			gfx_run(g_currentTask, sizeof(*g_currentTask));
			{
				const std::lock_guard<std::mutex> lock(g_gfxMutex);
				g_currentTask = nullptr;
			}
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
#else
	Graph_ThreadEntry(0);
#endif

	AudioMgr_Shutdown();

	gfx_shutdown();
}

#if(defined(_WIN32) || defined(_WIN64)) && defined(_MSC_VER)
#include <windows.h>
#include <AziAudio/AziAudio/SoundDriver.h>
//#include "engine/script.h"

typedef enum PROCESS_DPI_AWARENESS
{
	PROCESS_DPI_UNAWARE = 0,
	PROCESS_SYSTEM_DPI_AWARE = 1,
	PROCESS_PER_MONITOR_DPI_AWARE = 2
} PROCESS_DPI_AWARENESS;

bool SetDPIAwarness(PROCESS_DPI_AWARENESS Awarness)
{
	HRESULT(WINAPI * SetProcessDpiAwareness)(PROCESS_DPI_AWARENESS dpiAwareness) = nullptr;
	HINSTANCE shcoreLib = LoadLibrary(L"SHCORE.DLL");

	if(shcoreLib)
	{
		SetProcessDpiAwareness = (HRESULT(WINAPI*)(PROCESS_DPI_AWARENESS))GetProcAddress(shcoreLib, "SetProcessDpiAwareness");

		if(SetProcessDpiAwareness)
			return SetProcessDpiAwareness(Awarness) == S_OK;
	}
	return false;
}
void run();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	SetDPIAwarness(PROCESS_SYSTEM_DPI_AWARE);
	run();
	return 0;
}
#endif

#ifdef __SWITCH__
void initialize();
#endif

extern "C"
{
	int main(int argc, char* argv[]);
}

int main2(int argc, char** argv);

int main(int argc, char* argv[])
{
#ifdef __SWITCH__
	initialize();
#endif

	main2(argc, argv);
	return 0;
}


static bool g_isRunning = true;

extern "C"
{
	bool gfx_busy()
	{
#ifdef MULTI_THREADED_GFX
		const std::lock_guard<std::mutex> lock(g_gfxMutex);
		return g_currentTask != nullptr;
#else
		return false;
#endif
	}

	void gfx_wait_ready()
	{
#ifdef MULTI_THREADED_GFX
		while(gfx_busy())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
#endif
	}

	bool gfx_schedule(OSTask_t* task, u32 sz)
	{
#ifdef MULTI_THREADED_GFX
		if(!gfx_busy())
		{
			const std::lock_guard<std::mutex> lock(g_gfxMutex);
			g_currentTask = task;
			return true;
		}
		return false;
#else
		gfx_run(task, sz);
		return true;
#endif
	}

	bool gfx_start_frame()
	{
		if(gWindow)
		{
			return gWindow->begin_frame();
		}
		return false;
	}

	void gfx_end_frame()
	{
		if(gWindow)
		{
			gWindow->setTargetFrameRate(FRAMERATE_MAX / frameRateDivisor());
			gWindow->end_frame();
		}
#ifdef SINGLE_THREADED_AUDIO
		for(int i = 0; i < 3; i++)
		{
			auto task = getAudioTask();

			if(task)
			{
				HLEStart((AZI_OSTask*)&task->task.t);
				AiUpdate(false);
			}
		}
#endif
	}

	float gfx_ar_ratio()
	{
		if(gWindow)
		{
			return gWindow->ar_ratio();
		}
		return 1.0f;
	}

	float gfx_ar()
	{
		if(gWindow)
		{
			return gWindow->ar();
		}
		return 1.0f;
	}

	void set_fullscreen(bool value)
	{
		gWindow->set_fullscreen(value, false);
	}

	u64 get_display_refresh_rate()
	{
		u64 r = 1000000 / gWindow->refreshInterval().count();

		if(r < 60)
		{
			r = 60;
		}

		return r;
	}
}

bool isRunning()
{
	return g_isRunning;
}

void quit()
{
	g_isRunning = false;
	AudioMgr_Shutdown();
}
