#include <algorithm>
#include <string.h>
#include "../controller/controllers.h"
#include "../options.h"
#include "players.h"

#include "padmgr.h"
#include "z64.h"

extern PadMgr gPadMgr;

namespace oot
{
	Players g_players;

	Players& players()
	{
		return g_players;
	}

	Player& player(const u64 i)
	{
		return g_players[i];
	}

	Players::Players() : m_players(), m_size(0)
	{
	}

	const u64 Players::size() const
	{
		return m_size;
	}

	void Players::update()
	{
		int i = 0;
		memset(&gPadMgr.ctrlrIsConnected[0], 0, sizeof(gPadMgr.ctrlrIsConnected));
		for(auto& player : m_players)
		{
			player.update();

			gPadMgr.inputs[i].cur.button = player.controller().state().button;
			gPadMgr.inputs[i].cur.stick_x = player.controller().state().stick_x;
			gPadMgr.inputs[i].cur.stick_y = player.controller().state().stick_y;

			gPadMgr.ctrlrIsConnected[i] = true;
			i++;
		}
		gPadMgr.nControllers = i;
	}

	void Players::attach(const std::shared_ptr<hid::Controller>& controller, const u8 playerId)
	{
		if(playerId == MAX_PLAYERS)
		{
			m_players[m_size++].attach(controller);
		}
		else
		{
			m_players[playerId].attach(controller);
			m_size = std::max((u64)playerId + 1, m_size);
		}
	}

	void Players::detach(const std::shared_ptr<hid::Controller>& controller, const u8 playerId)
	{
		m_players[playerId].detach(controller);
	}
} // namespace oot
