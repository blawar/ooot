#pragma once

#include "ultra64/types.h"
#include "controller.h"
#include <vector>
#include <memory>

namespace oot::hid
{
	class Driver
	{
	public:
		Driver();
		virtual ~Driver();
		virtual const u64 size() const;
		virtual Controller& controller(const u64 index);
		virtual void update();
		virtual bool updateRebind(int input);
		virtual void scan(class Controllers* controllers);
		virtual void resetBindings();
		virtual bool defaultOnly()
		{
			return false;
		}

		std::vector<std::shared_ptr<Controller>>& controllers()
		{
			return m_controllers;
		}

	protected:
		std::vector<std::shared_ptr<Controller>> m_controllers;
	};

	class Controllers
	{
	public:
		Controllers();
		virtual ~Controllers();
		const u64 size() const;
		void update();
		void scan();
		bool isRebindMode() const;
		void rebind(int input);
		void resetBindings();
		std::vector<class Driver*>& drivers()
		{
			return m_drivers;
		}

	protected:
		std::vector<class Driver*> m_drivers;
		int m_rebindInput;
	};

	Controllers& controllers();
} // namespace oot::hid