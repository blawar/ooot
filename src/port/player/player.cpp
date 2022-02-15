#include "player.h"
#include "../options.h"



using namespace hid;


void Player::attach(const std::shared_ptr<N64Controller>& controller)
{
	m_controllers.push_back(controller);
}



void Player::update()
{
	m_controller.state().reset();

	if (isRebindMode())
	{
		bool result = false;

		//for (auto& controller : m_controllers)
			//result |= controller->updateRebind(m_rebindInput);

		if (result)
			m_rebindInput = -10;
	}
	else if (m_rebindInput < 0)
		m_rebindInput++;
	else
	{
		for (auto& controller : m_controllers)
		{
			controller->state().reset();
			controller->update();

			m_controller.merge(*controller);
		}
		if (m_controllers.size() > 2 && !oot::config().game().forceMouse())
			m_controller.state().has_mouse = false;
	}

	m_controller.resolveInputs();
}