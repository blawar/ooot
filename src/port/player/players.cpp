#include <algorithm>
#include "players.h"
#include "../controller/controllers.h"

#include "z64.h";
#include "padmgr.h"

extern PadMgr gPadMgr;

Players g_players;

extern "C" {
void hid_init() {
    controllers().scan();
}

void hid_update() {
	g_players.update();
}
}




void Players::update()
{
    memset(&gPadMgr.ctrlrIsConnected[0], 0, sizeof(gPadMgr.ctrlrIsConnected));

	int i = 0;
	for (auto& player : m_players)
	{
		player.update();

		gPadMgr.inputs[i].cur.button  = player.controller().state().button;
		gPadMgr.inputs[i].cur.stick_x = player.controller().state().stick_x;
		gPadMgr.inputs[i].cur.stick_y = player.controller().state().stick_y;

		gPadMgr.ctrlrIsConnected[i] = true;
		i++;
	}

	gPadMgr.nControllers = i;
}



void Players::attach(const std::shared_ptr<N64Controller>& controller, const u8 playerId)
{
	if (playerId == MAX_PLAYERS)
		m_players[m_size++].attach(controller);
	else
	{
		m_players[playerId].attach(controller);
		m_size = std::max((u64)playerId + 1, m_size);
	}
}