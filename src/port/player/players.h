#pragma once
#include "ultra64/types.h"
#include "player.h"
#include <vector>


static const u8 MAX_PLAYERS = 0xFF;


class Players
{
public:
	static const u32 MAX_PLAYERS = 1;

	Players() = default;
	const u64 size() const { return m_size; }
	void update();
	void attach(const std::shared_ptr<N64Controller>& controller, const u8 playerId = MAX_PLAYERS);

	Player& operator[](u32 i) { return m_players[i]; }

private:
	Player m_players[MAX_PLAYERS];
	u64 m_size = 0;
};