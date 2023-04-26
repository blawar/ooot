#include "../options.h"
#include "player.h"

namespace oot
{
	Player::Player() : m_rebindInput(hid::Button::EMPTY_BUTTON)
	{
	}

	Player::~Player()
	{
	}

	void Player::attach(const std::shared_ptr<hid::Controller>& controller)
	{
		m_controllers.push_back(controller);
	}

	void Player::detach(const std::shared_ptr<hid::Controller>& controller)
	{
		for(auto it = m_controllers.begin(); it != m_controllers.end(); it++)
		{
			if(*it == controller)
			{
				m_controllers.erase(it);
				return;
			}
		}
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

		if(isRebindMode())
		{
			bool result = 0;

			for(auto& controller : m_controllers)
			{
				result |= controller->updateRebind(m_rebindInput);
			}

			if(result)
			{
				m_rebindInput = (hid::Button)-10;
			}
		}
		else if((s64)m_rebindInput < 0)
		{
			m_rebindInput = (hid::Button)((s64)m_rebindInput + 1);
		}
		else
		{
			for(auto& controller : m_controllers)
			{
				controller->state().reset();
				controller->update();

				m_controller.merge(*controller);
			}
			if(m_controllers.size() > 2 && !config().game().forceMouse())
			{
				m_controller.state().has_mouse = false;
			}
		}
		m_controller.resolveInputs();
	}

	void Player::rebind(hid::Button input)
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
