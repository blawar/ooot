#pragma once
#include <memory>
#include <vector>
#include "../controller/controller.h"
#include "ultra64/types.h"

namespace oot
{
	class Player
	{
		public:
		Player();
		virtual ~Player();

		std::vector<std::shared_ptr<hid::Controller>>& controllers()
		{
			return m_controllers;
		}
		void resetBindings();
		void attach(const std::shared_ptr<hid::Controller>& controller);
		void detach(const std::shared_ptr<hid::Controller>& controller);
		void detachControllers();
		void update();
		hid::Controller& controller()
		{
			return m_controller;
		}

		void rebind(hid::Button input);
		bool isRebindMode() const;
		void SendMotorEvent(short time, short level, u8 decay = 0);

		protected:
		std::vector<std::shared_ptr<hid::Controller>> m_controllers;
		hid::Controller m_controller;
		hid::Button m_rebindInput;
	};

} // namespace oot
