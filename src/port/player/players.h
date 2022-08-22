#pragma once
#include <vector>
#include "player.h"
#include "ultra64/types.h"

namespace oot
{
	static const u8 MAX_PLAYERS = 0xFF;
	class Players
	{
		public:
		static const u32 MAX_PLAYERS = 1;

		Players();
		const u64 size() const;
		void update();
		Player& operator[](u32 i)
		{
			return m_players[i];
		}
		void attach(const std::shared_ptr<hid::Controller>& controller, const u8 playerId = MAX_PLAYERS);
		void detach(const std::shared_ptr<hid::Controller>& controller, const u8 playerId = MAX_PLAYERS);

		protected:
		Player m_players[MAX_PLAYERS];
		u64 m_size;
	};

	Players& players();
	Player& player(const u64 i);
} // namespace oot
