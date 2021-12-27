#pragma once
#include "ultra64/types.h"
#include "../controller/controller.h"
#include <vector>
#include <memory>

namespace sm64
{
	class Player
	{
		public:
		Player();
		virtual ~Player();

		std::vector<std::shared_ptr<hid::Controller> >& controllers()
		{
			return m_controllers;
		}
		void attach(const std::shared_ptr<hid::Controller>& controller);
		void detachControllers();
		void update();
		hid::Controller& controller()
		{
			return m_controller;
		}

		void rebind(int input);
		bool isRebindMode() const;

		protected:
		std::vector<std::shared_ptr<hid::Controller> > m_controllers;
		hid::Controller m_controller;
		int m_rebindInput;
	};

} // namespace sm64
