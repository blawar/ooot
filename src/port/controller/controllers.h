#pragma once
#include "ultra64/types.h"
#include "controller.h"
#include <vector>
#include <memory>



namespace oot
{
	namespace hid
	{
		enum class Button : uint32_t
		{
			NONE = 0x0000,
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
			STICK_X_LEFT = 1 << 16,
			STICK_X_RIGHT = 1 << 17,
			STICK_X_DOWN = 1 << 19,
			STICK_X_UP = 1 << 18,
			WALK_BUTTON = 1 << 20,
			OCARINA = 1 << 21,
			HOOKSHOT = 1 << 22,
			BOW_ARROW = 1 << 23,
			LENS_OF_TRUTH = 1 << 24,
			BOOTS_TOGGLE  = 1 << 25,
			SWORD_TOGGLE  = 1 << 26,
			SHIELD_TOGGLE  = 1 << 27,
			TUNIC_TOGGLE  = 1 << 28
		};


		class Device;


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
			std::vector<Device*>& drivers() { return m_drivers; }

		protected:
			std::vector<Device*> m_drivers;
			Button m_rebindInput;
		};



		class Device
		{
		public:
			Device() = default;
			virtual ~Device() {}

			virtual void scan() = 0;

			virtual const u64 size() const { return m_controllers.size(); }
			virtual Controller& controller(const u64 index);
			virtual void update();
			virtual bool updateRebind(Button input);
			virtual bool defaultOnly() { return false; }

			std::vector<std::shared_ptr<Controller>>& controllers() { return m_controllers; }

		protected:
			std::vector<std::shared_ptr<Controller>> m_controllers;
		};
	}
}