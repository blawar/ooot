#pragma once
#include "ultra64/types.h"
#include "controller.h"
#include <vector>
#include <memory>



namespace hid
{
	enum class Button : uint32_t
	{
		NONE   = 0x0000,
		CONT_A = 0x8000,
		CONT_B = 0x4000,
		CONT_G = 0x2000,
		CONT_START = 0x1000,
		CONT_UP = 0x0800,
		CONT_DOWN = 0x0400,
		CONT_LEFT = 0x0200,
		CONT_RIGHT = 0x0100,
		CONT_L = 0x0020,
		CONT_R = 0x0010,
		CONT_E = 0x0008,
		CONT_D = 0x0004,
		CONT_C = 0x0002,
		CONT_F = 0x0001,

		A_BUTTON = CONT_A,
		B_BUTTON = CONT_B,
		L_TRIG = CONT_L,
		R_TRIG = CONT_R,
		Z_TRIG = CONT_G,
		START_BUTTON = CONT_START,
		U_JPAD = CONT_UP,
		L_JPAD = CONT_LEFT,
		R_JPAD = CONT_RIGHT,
		D_JPAD = CONT_DOWN,
		U_CBUTTONS = CONT_E,
		L_CBUTTONS = CONT_C,
		R_CBUTTONS = CONT_F,
		D_CBUTTONS = CONT_D,
		STICK_X_LEFT = 0x10000,
		STICK_X_RIGHT = 0x20000,
		STICK_X_DOWN = 0x80000,
		STICK_X_UP = 0x40000,
		WALK_BUTTON = 0x100000
	};


	class InputDevice;


	class InputDeviceManager
	{
	public:
		static InputDeviceManager& get();

		InputDeviceManager();
		virtual ~InputDeviceManager() {}
		const u64 size() const;
		void update();
		void scan();
		bool isRebindMode() const { return m_rebindInput != Button::NONE; }
		void rebind(Button input) { m_rebindInput = input; }
		std::vector<InputDevice*>& drivers() { return m_drivers; }

	protected:
		std::vector<InputDevice*> m_drivers;
		Button m_rebindInput;
	};



	class InputDevice
	{
	public:
		InputDevice() = default;
		virtual ~InputDevice() {}

		virtual void scan() = 0;

		virtual const u64 size() const { return m_controllers.size(); }
		virtual N64Controller& controller(const u64 index);
		virtual void update();
		virtual bool updateRebind(Button input);
		virtual bool defaultOnly() { return false; }

		std::vector<std::shared_ptr<N64Controller>>& controllers() { return m_controllers; }

	protected:
		std::vector<std::shared_ptr<N64Controller>> m_controllers;
	};
}