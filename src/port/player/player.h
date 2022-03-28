#pragma once
#include "ultra64/types.h"
#include "../controller/controller.h"
#include <vector>
#include <memory>



namespace oot
{
	namespace hid
	{
		class Player
		{
		public:
			Player() : m_rebindInput(0) {}
			virtual ~Player() {}

			std::vector<std::shared_ptr<Controller> >& controllers() {
				return m_controllers;
			}
			void attach(const std::shared_ptr<Controller>& controller);
			void detachControllers() { m_controllers.resize(0); }
			void update();
			Controller& controller() {
				return m_controller;
			}

			void rebind(int input) { m_rebindInput = input; }
			bool isRebindMode() const { return m_rebindInput > 0; }

		protected:
			std::vector<std::shared_ptr<Controller> > m_controllers;
			Controller m_controller;
			int m_rebindInput;
		};
	}
}