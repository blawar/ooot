#include "player.h"
#include "../options.h"

namespace oot
{
	Player::Player() : m_rebindInput(0)
	{
	}

	Player::~Player()
	{
	}

	void Player::attach(const std::shared_ptr<hid::Controller>& controller)
	{
		m_controllers.push_back(controller);
	}

	void Player::detachControllers()
	{
		m_controllers.resize(0);
	}

	void Player::resetBindings()
	{
		for(auto& controller : m_controllers)
		{
			controller->resetBindings();
		}
	}

	void Player::update()
	{
		m_controller.state().reset();

		if (isRebindMode())
		{
			bool result = 0;

			for (auto& controller : m_controllers)
			{
				result |= controller->updateRebind(m_rebindInput);
			}

			if (result)
			{
				m_rebindInput = -10;
			}
		}
		else if (m_rebindInput < 0)
		{
			m_rebindInput++;
		}
		else
		{
			for (auto& controller : m_controllers)
			{
				controller->state().reset();
				controller->update();

				m_controller.merge(*controller);
			}
			if (m_controllers.size() > 2 && !config().game().forceMouse())
			{
				m_controller.state().has_mouse = false;
			}
		}
		m_controller.resolveInputs();
	}

	void Player::rebind(int input)
	{
		m_rebindInput = input;
	}

	bool Player::isRebindMode() const
	{
		return m_rebindInput > 0;
	}

	void Player::SendMotorEvent(short time, short level, u8 decay)
	{
		for(auto& controller : m_controllers)
		{
			controller->SendMotorEvent(time, level, decay);
		}
	}
} // namespace oot
