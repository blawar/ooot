#include "tas.h"
#include <stdio.h>
#include "../player/players.h"
#include "../options.h"
#include "tas.h"

static u64 g_counter = 0;
static bool g_tasPlaying = false;

using namespace hid;


bool Tas::isTasPlaying()
{
	return g_tasPlaying;
}



void Tas::playTas(bool enabled)
{
	g_tasPlaying = enabled;
}



Tas::Tas() : N64Controller()
{
	fp = fopen("last-run.tas", "rb");

	if (fp)
	{
		//fread(&oot::config(), 1, sizeof(oot::config()), fp);

#define SRAM_SIZE 0x8000//But this in ultra_reimplementation.h?

		uint8_t* sram = new uint8_t[SRAM_SIZE];
		fread(sram, sizeof(uint8_t), SRAM_SIZE, fp);

		FILE* save = nullptr;
		fopen_s(&save, "oot.sav", "wb");
		if (save)
		{
			fwrite(sram, sizeof(uint8_t), SRAM_SIZE, save);
			fclose(save);
		}

		delete[] sram;

		g_tasPlaying = true;
	}
}



Tas::~Tas()
{
	if (fp)
		fclose(fp);
}



void Tas::update()
{
	if (fp)
	{
		auto r = fread(&m_state, 1, sizeof(m_state), fp);
		if (m_state.button)
			int x = 0;
	}
}



void Tas::scan()
{
	if (!size())
	{
		auto controller = std::make_shared<Tas>();
		m_controllers.push_back(controller);
		Players::get().attach(controller, 0);
	}
}