#include "controllers.h"
#include "tas.h"
#include "keyboard.h"
#include "sdl.h"
#include <stdexcept>
#include "../options.h"


static InputDeviceManager* g_controllers;

InputDeviceManager& controllers()
{
	if (!g_controllers)
		g_controllers = new InputDeviceManager();
	return *g_controllers;
}



N64Controller& InputDevice::controller(const u64 index)
{
	if (index >= m_controllers.size())
		throw std::runtime_error("invalid controller index");
	return *m_controllers[index];
}



bool InputDevice::updateRebind(int input)
{
	bool result = 0;
	for (auto& controller : m_controllers)
	{
		controller->state().reset();
		//result |= controller->updateRebind(input);
		controller->resolveInputs();
	}
	return result;
}


void InputDevice::update()
{
	for(auto& controller : m_controllers)
	{
		controller->state().reset();
		controller->update();
		controller->resolveInputs();
	}
}



InputDeviceManager::InputDeviceManager() : m_rebindInput(0)
{
	m_drivers.push_back(new Joypad());

#ifdef ENABLE_MOUSE
	m_drivers.push_back(new Keyboard());
#endif
	//m_drivers.push_back(new Tas());
}



const u64 InputDeviceManager::size() const
{
	u64 count = 0;

	for (auto& driver : m_drivers)
		count += driver->size();

	return count;
}



void InputDeviceManager::update()
{
	if (isRebindMode())
	{
		bool result = 0;

		for (auto& driver : m_drivers)
			result |= driver->updateRebind(m_rebindInput);

		if (result)
			m_rebindInput = 0;
	}
	else
	{
		for (auto& driver : m_drivers)
			driver->update();
	}
}



void InputDeviceManager::scan()
{
	for (auto& driver : m_drivers)
	{
		//if(!driver->defaultOnly() || !found)
			driver->scan();
	}
}