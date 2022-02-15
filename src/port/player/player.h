#pragma once
#include "ultra64/types.h"
#include "../controller/controller.h"
#include <vector>
#include <memory>



namespace hid
{
	class Player
	{
	public:
		Player() : m_rebindInput(0) {}
		virtual ~Player() {}

		std::vector<std::shared_ptr<N64Controller> >& controllers() {
			return m_controllers;
		}
		void attach(const std::shared_ptr<N64Controller>& controller);
		void detachControllers() { m_controllers.resize(0); }
		void update();
		N64Controller& controller() {
			return m_controller;
		}

		void rebind(int input) { m_rebindInput = input; }
		bool isRebindMode() const { return m_rebindInput > 0; }

	protected:
		std::vector<std::shared_ptr<N64Controller> > m_controllers;
		N64Controller m_controller;
		int m_rebindInput;
	};
}