#include "xcontroller.h"

#ifdef _WIN32
#include <fstream>
#include <unordered_map>
#include <windows.h>
#include <xinput.h>
#include "../player/players.h"
#include "controllers.h"
#include "json.h"
#include "port/options.h"

#define MAX_BUTTONS 16

enum XInputButtons
{
	GAMEPAD_DPAD_UP = 0,
	GAMEPAD_DPAD_DOWN,
	GAMEPAD_DPAD_LEFT,
	GAMEPAD_DPAD_RIGHT,
	GAMEPAD_START,
	GAMEPAD_BACK,
	GAMEPAD_LEFT_THUMB,
	GAMEPAD_RIGHT_THUMB,
	GAMEPAD_LEFT_SHOULDER,
	GAMEPAD_RIGHT_SHOULDER,
	GAMEPAD_UNKNOWN_1,
	GAMEPAD_UNKNOWN_2,
	GAMEPAD_A,
	GAMEPAD_B,
	GAMEPAD_X,
	GAMEPAD_Y,
	GAMEPAD_NONE = 0xFF
};

static XInputButtons getButtonId(const std::string& str)

{
	if(str == "GAMEPAD_DPAD_UP")
		return XInputButtons::GAMEPAD_DPAD_UP;
	if(str == "GAMEPAD_DPAD_DOWN")
		return XInputButtons::GAMEPAD_DPAD_DOWN;
	if(str == "GAMEPAD_DPAD_LEFT")
		return XInputButtons::GAMEPAD_DPAD_LEFT;
	if(str == "GAMEPAD_DPAD_RIGHT")
		return XInputButtons::GAMEPAD_DPAD_RIGHT;
	if(str == "GAMEPAD_START")
		return XInputButtons::GAMEPAD_START;
	if(str == "GAMEPAD_BACK")
		return XInputButtons::GAMEPAD_BACK;
	if(str == "GAMEPAD_LEFT_THUMB")
		return XInputButtons::GAMEPAD_LEFT_THUMB;
	if(str == "GAMEPAD_RIGHT_THUMB")
		return XInputButtons::GAMEPAD_RIGHT_THUMB;
	if(str == "GAMEPAD_LEFT_SHOULDER")
		return XInputButtons::GAMEPAD_LEFT_SHOULDER;
	if(str == "GAMEPAD_RIGHT_SHOULDER")
		return XInputButtons::GAMEPAD_RIGHT_SHOULDER;
	if(str == "GAMEPAD_UNKNOWN_1")
		return XInputButtons::GAMEPAD_UNKNOWN_1;
	if(str == "GAMEPAD_UNKNOWN_2")
		return XInputButtons::GAMEPAD_UNKNOWN_2;
	if(str == "GAMEPAD_A")
		return XInputButtons::GAMEPAD_A;
	if(str == "GAMEPAD_B")
		return XInputButtons::GAMEPAD_B;
	if(str == "GAMEPAD_X")
		return XInputButtons::GAMEPAD_X;
	if(str == "GAMEPAD_Y")
		return XInputButtons::GAMEPAD_Y;
	return XInputButtons::GAMEPAD_NONE;
}

static const char* getButtonName(XInputButtons button)
{
	switch(button)
	{
		case XInputButtons::GAMEPAD_DPAD_UP:
			return "GAMEPAD_DPAD_UP";
		case XInputButtons::GAMEPAD_DPAD_DOWN:
			return "GAMEPAD_DPAD_DOWN";
		case XInputButtons::GAMEPAD_DPAD_LEFT:
			return "GAMEPAD_DPAD_LEFT";
		case XInputButtons::GAMEPAD_DPAD_RIGHT:
			return "GAMEPAD_DPAD_RIGHT";
		case XInputButtons::GAMEPAD_START:
			return "GAMEPAD_START";
		case XInputButtons::GAMEPAD_BACK:
			return "GAMEPAD_BACK";
		case XInputButtons::GAMEPAD_LEFT_THUMB:
			return "GAMEPAD_LEFT_THUMB";
		case XInputButtons::GAMEPAD_RIGHT_THUMB:
			return "GAMEPAD_RIGHT_THUMB";
		case XInputButtons::GAMEPAD_LEFT_SHOULDER:
			return "GAMEPAD_LEFT_SHOULDER";
		case XInputButtons::GAMEPAD_RIGHT_SHOULDER:
			return "GAMEPAD_RIGHT_SHOULDER";
		case XInputButtons::GAMEPAD_UNKNOWN_1:
			return "GAMEPAD_UNKNOWN_1";
		case XInputButtons::GAMEPAD_UNKNOWN_2:
			return "GAMEPAD_UNKNOWN_2";
		case XInputButtons::GAMEPAD_A:
			return "GAMEPAD_A";
		case XInputButtons::GAMEPAD_B:
			return "GAMEPAD_B";
		case XInputButtons::GAMEPAD_X:
			return "GAMEPAD_X";
		case XInputButtons::GAMEPAD_Y:
			return "GAMEPAD_Y";
	}
	return "UNKNOWN";
}

//#pragma comment(lib, "Xinput.lib")
#pragma comment(lib, "Xinput9_1_0.lib")

static u8* expandButtonBits(WORD bits, u8* out)
{
	for(int i = 0; i < MAX_BUTTONS; i++)
	{
		out[i] = (bits & (1 << i)) ? 1 : 0;
	}
	return out;
}

namespace oot::hid
{
	namespace controller
	{
		class XController : public Controller
		{
			class State
			{
				friend class XController;

				public:
				bool DPad_Up() const
				{
					return wButtons & 0x0001;
				}
				bool DPad_Down() const
				{
					return wButtons & 0x0002;
				}
				bool DPad_Left() const
				{
					return wButtons & 0x0004;
				}
				bool DPad_Right() const
				{
					return wButtons & 0x0008;
				}

				bool Start() const
				{
					return wButtons & 0x0010;
				}
				bool Back() const
				{
					return wButtons & 0x0020;
				}

				bool Thumb_Left() const
				{
					return wButtons & 0x0040;
				}
				bool Thumb_Right() const
				{
					return wButtons & 0x0080;
				}

				bool Shoulder_Left() const
				{
					return wButtons & 0x0100;
				}
				bool Shoulder_Right() const
				{
					return wButtons & 0x0200;
				}

				bool Button_A() const
				{
					return wButtons & 0x1000;
				}
				bool Button_B() const
				{
					return wButtons & 0x2000;
				}
				bool Button_X() const
				{
					return wButtons & 0x4000;
				}
				bool Button_Y() const
				{
					return wButtons & 0x8000;
				}

				bool Button_A_Up() const
				{
					return wButtons_Previous & ~wButtons & 0x1000;
				}
				bool Button_B_Up() const
				{
					return wButtons_Previous & ~wButtons & 0x2000;
				}
				bool Button_X_Up() const
				{
					return wButtons_Previous & ~wButtons & 0x4000;
				}
				bool Button_Y_Up() const
				{
					return wButtons_Previous & ~wButtons & 0x8000;
				}

				bool Button_A_Down() const
				{
					return ~wButtons_Previous & wButtons & 0x1000;
				}
				bool Button_B_Down() const
				{
					return ~wButtons_Previous & wButtons & 0x2000;
				}
				bool Button_X_Down() const
				{
					return ~wButtons_Previous & wButtons & 0x4000;
				}
				bool Button_Y_Down() const
				{
					return ~wButtons_Previous & wButtons & 0x8000;
				}

				uint8_t Trigger_Left() const
				{
					return bLeftTrigger;
				}
				uint8_t Trigger_Right() const
				{
					return bRightTrigger;
				}

				int16_t Joystick_LeftX() const
				{
					return sThumbLX;
				}
				int16_t Joystick_LeftY() const
				{
					return sThumbLY;
				}

				int16_t Joystick_RightX() const
				{
					return sThumbRX;
				}
				int16_t Joystick_RightY() const
				{
					return sThumbRY;
				}

				private:
				uint16_t wButtons_Previous;
				uint16_t wButtons;
				uint8_t bLeftTrigger;
				uint8_t bRightTrigger;
				int16_t sThumbLX;
				int16_t sThumbLY;
				int16_t sThumbRX;
				int16_t sThumbRY;
			};

			public:
			XController(uint32_t ControllerID = 0) : Controller(), m_ID(ControllerID)
			{
				resetBindingsImpl();
			}

			~XController()
			{
			}

			void resetBindingsImpl() // dont want to call virtual functions from constructor
			{
				m_keyBindings.clear();
				m_keyBindings[GAMEPAD_START] = START_BUTTON;
				m_keyBindings[GAMEPAD_LEFT_SHOULDER] = Z_TRIG;
				m_keyBindings[GAMEPAD_RIGHT_SHOULDER] = R_TRIG;
				m_keyBindings[GAMEPAD_A] = A_BUTTON;
				m_keyBindings[GAMEPAD_X] = B_BUTTON;
				m_keyBindings[GAMEPAD_B] = A_BUTTON;
				m_keyBindings[GAMEPAD_Y] = B_BUTTON;
				if(config().controls().cButtonsOnRightStick()){
					m_keyBindings[GAMEPAD_DPAD_LEFT] = L_JPAD;
					m_keyBindings[GAMEPAD_DPAD_RIGHT] = R_JPAD;
					m_keyBindings[GAMEPAD_DPAD_UP] = U_JPAD;
					m_keyBindings[GAMEPAD_DPAD_DOWN] = D_JPAD;
				}
				else{
					m_keyBindings[GAMEPAD_DPAD_LEFT] = L_CBUTTONS;
					m_keyBindings[GAMEPAD_DPAD_RIGHT] = R_CBUTTONS;
					m_keyBindings[GAMEPAD_DPAD_UP] = U_CBUTTONS;
					m_keyBindings[GAMEPAD_DPAD_DOWN] = D_CBUTTONS;
				}
			}

			void resetBindings() override
			{
				resetBindingsImpl();
			}

			bool canRebind(XInputButtons button, hid::Button input)
			{
				if(m_keyBindings.count(button) == 0)
				{
					return true;
				}

				auto replacingInput = m_keyBindings[button];
				u64 count = 0;

				if(replacingInput != START_BUTTON && replacingInput != A_BUTTON && replacingInput != B_BUTTON)
				{
					return true;
				}

				if(replacingInput == input)
				{
					return true;
				}

				for(auto i : m_keyBindings)
				{
					if(i.second == replacingInput)
					{
						count++;
					}
				}

				if(count == 1)
				{
					return false;
				}
				return count != 1;
			}

			bool updateRebind(hid::Button input) override
			{
				u8 state[MAX_BUTTONS];
				XINPUT_STATE xstate;
				XInputGetState(m_ID, &xstate);
				expandButtonBits(xstate.Gamepad.wButtons, state);

				for(int i = 0; i < MAX_BUTTONS; i++)
				{
					bool newState = state[i];
					state[i] = (m_lastKeyState[i] ^ newState) & newState;
					m_lastKeyState[i] = newState;
				}

				for(int i = 0; i < MAX_BUTTONS; i++)
				{
					if(state[i] && canRebind((XInputButtons)i, input))
					{
						m_keyBindings[(XInputButtons)i] = (Button)input;
						saveKeyBindings();
						return true;
					}
				}

				return false;
			}

			void loadKeyBindings()
			{
				try
				{
					std::ifstream ifs("xinput1.bindings.json", std::ifstream::in);

					if(ifs.is_open())
					{
						rapidjson::IStreamWrapper isw(ifs);
						rapidjson::Document d;
						d.ParseStream(isw);

						if(d.IsObject())
						{
							for(auto itr = d.MemberBegin(); itr != d.MemberEnd(); ++itr)
							{
								if(itr->name.IsString() && itr->value.IsString())
								{
									auto key = getButtonId(itr->name.GetString());
									auto value = getInputValue(itr->value.GetString());

									if(key != XInputButtons::GAMEPAD_NONE && value)
									{
										m_keyBindings[key] = value;
									}
									else
									{
										// oot::log("could not bind key: \"%s\" -> \"%s\"\n", itr->value.GetString(), itr->name.GetString());
									}
								}
							}
						}
					}
				}
				catch(...)
				{
				}
			}

			void saveKeyBindings()
			{
				try
				{
					rapidjson::Document d;
					d.SetObject();

					rapidjson::Document::AllocatorType& allocator = d.GetAllocator();

					for(const auto i : m_keyBindings)
					{
						rapidjson::Value value(getInputName((oot::hid::Button)i.second), allocator);
						rapidjson::Value key(getButtonName(i.first), allocator);
						d.AddMember(key, value, allocator);
					}

					json::save(d, "xinput1.bindings.json");
				}
				catch(...)
				{
				}
			}

			bool IsConnected() const
			{
				XINPUT_STATE state;
				return XInputGetState(m_ID, &state) == ERROR_SUCCESS;
			}

			void update() override
			{
				XINPUT_STATE xstate;
				XInputGetState(m_ID, &xstate);

				if(m_LastPacketNum == xstate.dwPacketNumber)
				{
					return;
				}

				if(xstate.Gamepad.bLeftTrigger > 0x7F)
					m_state.button |= Z_TRIG;
				if(xstate.Gamepad.bRightTrigger > 0x7F)
					m_state.button |= R_TRIG;

				int deadzone = oot::config().controls().stickLeftDeadzone() * 0x7F;
				int value = xstate.Gamepad.sThumbLX;
				if(value < -deadzone)
					value += deadzone;
				else if(value > deadzone)
					value -= deadzone;
				else
					value = 0;
				m_state.stick_x = convertToByte(value, 0x7FFF - deadzone);

				value = xstate.Gamepad.sThumbLY;
				if(value < -deadzone)
					value += deadzone;
				else if(value > deadzone)
					value -= deadzone;
				else
					value = 0;
				m_state.stick_y = convertToByte(value, 0x7FFF - deadzone);

				value = xstate.Gamepad.sThumbRX;
				if(value < -deadzone)
					value += deadzone;
				else if(value > deadzone)
					value -= deadzone;
				else
					value = 0;
				m_state.r_stick_x = convertToByte(value, 0x7FFF - deadzone);

				value = xstate.Gamepad.sThumbRY;
				if(value < -deadzone)
					value += deadzone;
				else if(value > deadzone)
					value -= deadzone;
				else
					value = 0;
				m_state.r_stick_y = convertToByte(value, 0x7FFF - deadzone);

				u8 state[MAX_BUTTONS];
				expandButtonBits(xstate.Gamepad.wButtons, state);

				for(const auto& [scancode, input] : m_keyBindings)
				{
					if(state[scancode])
					{
						processKey(input);
					}

					if(m_lastKeyState[scancode] ^ state[scancode])
					{
						if(state[scancode])
						{
							processKeyDown(input);
						}
						else
						{
							processKeyUp(input);
						}
					}
				}

				/*uint32_t magnitude_sq = (uint32_t)(m_state.stick_x * m_state.stick_x) + (uint32_t)(m_state.stick_y * m_state.stick_y);

				if(magnitude_sq < (uint32_t)(oot::config().controls().stickLeftDeadzone() * oot::config().controls().stickLeftDeadzone()))
				{
					m_state.stick_x = 0;
					m_state.stick_y = 0;
				}

				magnitude_sq = (uint32_t)(m_state.r_stick_x * m_state.r_stick_x) + (uint32_t)(m_state.r_stick_y * m_state.r_stick_y);

				if(magnitude_sq < (uint32_t)(oot::config().controls().stickRightDeadzone() * oot::config().controls().stickRightDeadzone()))
				{
					m_state.r_stick_x = 0;
					m_state.r_stick_y = 0;
				}*/

				memcpy(m_lastKeyState, state, MAX_BUTTONS);
				rumble();
			}

			void vibrate() override
			{
				XINPUT_VIBRATION vibration;
				vibration.wLeftMotorSpeed = 0;
				vibration.wRightMotorSpeed = m_rumbleStrengh / 255.0f * 0xFFFF;

				XInputSetState(m_ID, &vibration);
			}

			protected:
			uint32_t m_ID;
			uint32_t m_LastPacketNum = 0;

			std::unordered_map<XInputButtons, Button> m_keyBindings;
			u8 m_lastKeyState[MAX_BUTTONS];
		};
	} // namespace controller

	namespace driver
	{
		XInput::XInput()
		{
		}

		XInput::~XInput()
		{
		}

		void XInput::scan(class Controllers* controllers)
		{
			DWORD dwResult;
			for(DWORD i = 0; i < XUSER_MAX_COUNT; i++)
			{
				XINPUT_STATE state;
				ZeroMemory(&state, sizeof(XINPUT_STATE));

				// Simply get the xstate of the controller from XInput.
				dwResult = XInputGetState(i, &state);

				if(dwResult != ERROR_SUCCESS)
				{
					continue;
				}

				auto controller = std::make_shared<controller::XController>(i);
				m_controllers.push_back(controller);
				players().attach(controller, 0);
			}
		}
	} // namespace driver
} // namespace oot::hid

#endif