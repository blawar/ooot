#include "controllers.h"
#include "tas.h"
#include "keyboard.h"
#include "sdl.h"
#include "xcontroller.h"
#include <stdexcept>
#include "../options.h"

namespace oot::hid
{
	static Controllers* g_controllers;

	Controllers& controllers()
	{
		if(!g_controllers)
		{
			g_controllers = new Controllers();
		}
		return *g_controllers;
	}

	Driver::Driver()
	{
	}

	Driver::~Driver()
	{
	}

	const u64 Driver::size() const
	{
		return m_controllers.size();
	}

	Controller& Driver::controller(const u64 index)
	{
		if(index >= m_controllers.size())
		{
			throw std::runtime_error("invalid controller index");
		}
		return *m_controllers[index];
	}

	bool Driver::updateRebind(int input)
	{
		bool result = 0;
		for (auto& controller : m_controllers)
		{
			controller->state().reset();
			result |= controller->updateRebind(input);
			controller->resolveInputs();
		}
		return result;
	}

	void Driver::update()
	{
		for(auto& controller : m_controllers)
		{
			controller->state().reset();
			controller->update();
			controller->resolveInputs();
		}
	}

	void Driver::scan(class Controllers* controllers)
	{
	}

	void Driver::resetBindings()
	{
		for(auto& controller : m_controllers)
		{
			controller->resetBindings();
		}
	}

	Controllers::Controllers() : m_rebindInput(0)
	{
#if defined(_MSC_VER)
		if(oot::config().controls().useXInput() && !oot::config().controls().enableGyro())
		{
			m_drivers.push_back(new hid::driver::XInput());
		}
		else
		{
			m_drivers.push_back(new SDL());
		}
#else
		m_drivers.push_back(new SDL());
#endif

#ifdef ENABLE_MOUSE
		m_drivers.push_back(new Keyboard());
#endif
		//m_drivers.push_back(new Tas());
	}

	Controllers::~Controllers()
	{
	}

	const u64 Controllers::size() const
	{
		u64 count = 0;

		for(auto& driver : m_drivers)
		{
			count += driver->size();
		}

		return count;
	}

	void Controllers::update()
	{
		if (isRebindMode())
		{
			bool result = 0;

			for (auto& driver : m_drivers)
			{
				result |= driver->updateRebind(m_rebindInput);
			}

			if (result)
			{
				m_rebindInput = 0;
			}
		}
		else
		{
			for (auto& driver : m_drivers)
			{
				driver->update();
			}
		}
	}

	void Controllers::scan()
	{
		u64 found = 0;
		for(auto& driver : m_drivers)
		{
			//if(!driver->defaultOnly() || !found)
			{
				driver->scan(this);
				found += driver->size();
			}
		}
	}

	void Controllers::resetBindings()
	{
		for(auto& driver : m_drivers)
		{
			driver->resetBindings();
		}
	}

	void Controllers::rebind(int input)
	{
		m_rebindInput = input;
	}

	bool Controllers::isRebindMode() const
	{
		return m_rebindInput > 0;
	}
} // namespace oot::hid