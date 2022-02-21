#define WIN32_LEAN_AND_MEAN
#define ENABLE_OPENGL
#define USE_GLIDEN64
#define DISABLE_AUDIO
#include "window.h"
#include "options.h"
#include "player/players.h"
#include "controller/tas.h"
#include "../../AziAudio/AziAudio/AudioSpec.h"
#include "ultra64/rcp.h"
#include "z64audio.h"
#include "controller/controllers.h"
#include "def/audio_rsp.h"

static std::unique_ptr<platform::window::Base> gWindow;


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

#include "nx.h"
#include "xxhash64.h"
#include "gfxapi.h"

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

				if (fopen_s(&f, entry.path().string().c_str(), "rb") == 0)
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
		sm64::log("error: unable to locate Z64 rom.\n");
	}

	if(!hasPak)
	{
		sm64::log("error: unable to locate romfs/!!base.pak\n");
	}

	free(buffer);
	return hasRom && hasPak;
}

void main_func();
void azi_init();

void main_func(void)
{
	sm64::log("initializing app\n");

#ifndef BUILD_NSO
	if(!verifyIntegrity())
	{
		return;
	}
#endif

	azi_init();

#ifdef _DEBUG//Record TAS to capture bugs and crashes
	//oot::hid::tas::playTas(true);//Uncomment to play back TAS/crash report from end-users

	if (!oot::hid::tas::isTasPlaying())
		oot::config().game().recordTas(true);
#endif

	if (!oot::config().game().isGraphicsDisabled())
		gWindow = platform::window::create("The Legend of Zelda - Ocarina of Time", false);

	if (!oot::config().game().isGraphicsDisabled())
	{
		gfx_init("THE LEGEND OF ZELDA", &osViModeNtscLan1);
		//gfx_fbe_enable(0);//Uncomment to disable frame buffer emulation
	}

	if (!oot::config().game().isGraphicsDisabled())
		gWindow->resize(-1, -1);

	oot::hid::InputDeviceManager::get().scan();

	inited = 1;

	Graph_ThreadEntry(0);

	gfx_shutdown();
}

#if(defined(_WIN32) || defined(_WIN64)) && defined(_MSC_VER)
#include <windows.h>
//#include "engine/script.h"

typedef enum PROCESS_DPI_AWARENESS {
	PROCESS_DPI_UNAWARE = 0,
	PROCESS_SYSTEM_DPI_AWARE = 1,
	PROCESS_PER_MONITOR_DPI_AWARE = 2
} PROCESS_DPI_AWARENESS;

bool SetDPIAwarness(PROCESS_DPI_AWARENESS Awarness)
{
	HRESULT(WINAPI *SetProcessDpiAwareness)(PROCESS_DPI_AWARENESS dpiAwareness) = nullptr;
	HINSTANCE shcoreLib = LoadLibrary(L"SHCORE.DLL");

	if (shcoreLib)
	{
		SetProcessDpiAwareness = (HRESULT(WINAPI*)(PROCESS_DPI_AWARENESS)) GetProcAddress(shcoreLib, "SetProcessDpiAwareness");

		if (SetProcessDpiAwareness)
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
#else
#ifdef __SWITCH__
void initialize();
#endif

extern "C"
{
	int main(int argc, char* argv[]);
}

int main(int argc, char* argv[])
{
#ifdef __SWITCH__
	initialize();
#endif
	main_func();
	return 0;
}
#endif

static bool g_isRunning = true;

extern "C" {
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
		/*for(int i=0; i < 3; i++)
		{
			auto task = getAudioTask();

			if(task)
			{
				HLEStart((AZI_OSTask*)&task->task.t);
				AiUpdate(false);
			}
		}*/
		//audio_thread();
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
}

bool isRunning()
{
	return g_isRunning;
}

void quit()
{
	g_isRunning = false;
}