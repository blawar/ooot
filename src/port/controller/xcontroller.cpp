#include "xcontroller.h"

#ifdef _WIN32
#include <windows.h>
#include <xinput.h>
#include "controllers.h"
#include "../player/players.h"
#include <unordered_map>

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
GAMEPAD_Y
};

//#pragma comment(lib, "Xinput.lib")
#pragma comment(lib, "Xinput9_1_0.lib")
#endif

static inline int8_t convertToByte(int value, int max)
{
	int8_t result = value * 0x7F / max;

	return result;
}

static inline int8_t invert(const int8_t value)
{
	if(value <= -128)
	{
		return 127;
	}

	return -value;
}

static u8* expandButtonBits(WORD  bits, u8* out)
{
	for(int i=0; i < MAX_BUTTONS; i++)
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
				m_keyBindings[GAMEPAD_DPAD_LEFT] = L_CBUTTONS;
				m_keyBindings[GAMEPAD_DPAD_RIGHT] = R_CBUTTONS;
				m_keyBindings[GAMEPAD_DPAD_UP] = U_CBUTTONS;
				m_keyBindings[GAMEPAD_DPAD_DOWN] = D_CBUTTONS;
			}

			void resetBindings() override
			{
				resetBindingsImpl();
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

				m_state.stick_x = convertToByte(xstate.Gamepad.sThumbLX, 0xFFFF);
				m_state.stick_y = convertToByte(xstate.Gamepad.sThumbLY, 0xFFFF);

				m_state.r_stick_x = convertToByte(xstate.Gamepad.sThumbRX, 0xFFFF);
				m_state.r_stick_y = convertToByte(xstate.Gamepad.sThumbRY, 0xFFFF);

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

				uint32_t magnitude_sq = (uint32_t)(m_state.stick_x * m_state.stick_x) + (uint32_t)(m_state.stick_y * m_state.stick_y);

				if(magnitude_sq < (uint32_t)(DEADZONE * DEADZONE))
				{
					m_state.stick_x = 0;
					m_state.stick_y = 0;
				}

				magnitude_sq = (uint32_t)(m_state.r_stick_x * m_state.r_stick_x) + (uint32_t)(m_state.r_stick_y * m_state.r_stick_y);

				if(magnitude_sq < (uint32_t)(RDEADZONE * RDEADZONE))
				{
					m_state.r_stick_x = 0;
					m_state.r_stick_y = 0;
				}

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

			std::unordered_map<XInputButtons, int> m_keyBindings;
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