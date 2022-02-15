#include "tas.h"
#include <stdio.h>
#include "../player/players.h"
#include "../options.h"
#include "tas.h"

static u64 g_counter = 0;
static  bool g_tasPlaying = false;

extern Players g_players;


bool Tas::isTasPlaying()
{
	return g_tasPlaying;
}



Tas::Tas() : N64Controller()
{
	fp = fopen("cont.tas", "rb");

	if (fp != NULL)
	{
		fread(&oot::config(), 1, sizeof(oot::config()), fp);
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
		g_players.attach(controller, 0);
	}
}